/*
	This Code is held together by Duct Tape and Hope
	Author: Fluffy, Ascent

	Description:
	Main Loop to Handle the Calculation and UI of RC Artillery Units
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_Artillery_UI = [] spawn {

	while {true} do {
		sleep 0.1;

		_uav = (getConnectedUAV player); // UAV
		_uavClass = typeOf _uav; // UAV ClassName
		_inDrone = ((UAVControl _uav) select 1) in ["DRIVER", "GUNNER", "COMMANDER"];	// If the Player is currently controlling the UAV
		//_inDrone = ((UAVControl _uav) select 1) isEqualTo ["DRIVER", "GUNNER"];
		//_inDrone = isRemoteControlling player;
		
		// See if the vehicle has the isRCArty property
		_isRCArty = (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isRCArty") == 1);

		// If it's of Artillery or Mortar Type do da thing
		if (_isRCArty && _inDrone && (_uav isNotEqualto objNull)) then {
			
			RC_InUI = true; // We are in the UI now
			
			// If our UAV is Autonomous we want to make it not
			// We need to remote exec it since setAutonomous is of Local Effect so it needs to be
			// where the UAV is Local
			if (isAutonomous _uav) then {[_uav, false] remoteExec ["setAutonomous", _uav];};
			
			// Check if the Display for the UI Exists if not Create it
			if (isNull (uiNamespace getVariable ["RC_Artillery", displayNull])) then {"RC_Artillery" cutRsc ["RC_Artillery", "PLAIN", 0, false];};
			
			disableSerialization;

			// Get the UI so we can see if it has Distance or not
			_AceUI = uiNamespace getVariable ["ACE_dlgArtillery", displayNull];
			_RCAUI = uiNamespace getVariable ["RCA_ArtyUI", displayNull];

			// CBA Option for Allowing the Artillery Computer in RC Artillery UGVs, without ACE its stays on for Mortars (as they dont work manually without ACE atm)
			// Remote Execute this to make it Multiplayer Compatible
			if (!RC_Allow_Vanilla_Arty_Computer) then {
				_isMortar = false;
				if (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCisMortar") == 1) then {_isMortar = true;};
				if (isNull _AceUI && _isMortar) then {[true] remoteExec ["enableEngineArtillery", _uav];} else {[false] remoteExec ["enableEngineArtillery", _uav]};
			} else {
				[true] remoteExec ["enableEngineArtillery", _uav];
			};

			_RCA_CurrentArtyDisplay = displayNull;
			// If our one is Null we use theirs
			if (!isNull _RCAUI) then {_RCA_CurrentArtyDisplay = _RCAUI;} else {_RCA_CurrentArtyDisplay = _AceUI;};

			// This is the Range Text
			_rangeText = ctrlText (_RCA_CurrentArtyDisplay displayCtrl 173);

			// Look Vector relative to the Camera
			_lookVector = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL (positionCameraToWorld [0,0,1]));
			_weaponDir = _uav weaponDirection (currentWeapon _uav); // Weapon direction as a Relative Vector3
			
			// Fallback if we are using the Mortar and the Display isn't working
			if (isNull _RCA_CurrentArtyDisplay) then {
				
				private _testSeekerPosASL = AGLtoASL (positionCameraToWorld [0,0,0]);
				private _testPoint = _testSeekerPosASL vectorAdd (_lookVector vectorMultiply viewDistance);
    			_lookingAtGround = !((terrainIntersectASL [_testSeekerPosASL, _testPoint]) || {lineIntersects [_testSeekerPosASL, _testPoint, _uav]});
				
				if _lookingAtGround then {
					_rangeText = "--";
				} else {
					_rangeText = "0";
				};
			};
			
			_display = uiNamespace getVariable ["RC_Artillery", displayNull]; // Display
			_turret = (_uav unitTurret gunner _uav); // Current Turret of UAV Gunner
			_currentFireMode = currentWeaponMode (gunner _uav); // Current Fire mode of the UAV Gunner
			_weaponsTurret = _uav weaponsTurret _turret; // All of the Turrets Weapons
			_weapon = _weaponsTurret param [0, ""]; // Weapon
			_weaponConfig = configFile >> "CfgWeapons" >> _weapon; // Weapon Config

			// Get all Firemodes of the UAV Weapon
			_fireModes = getArray (configFile >> "CfgWeapons" >> _weapon >> "modes");
			// Get all the Firemodes the Players can use
			_fireModes = (_fireModes apply {configFile >> "CfgWeapons" >> _weapon >> _x}) select {1 == getNumber (_x >> "showToPlayer")};
			// If the Firemodes have 'artilleryCharge' as a value
			_fireModes = _fireModes apply {[getNumber (_x >> "artilleryCharge"), configName _x]};
			_fireModes sort true; // Basic Sort in Ascending order
			// Grab only the names of the Firemodes 
			_fireModes = _fireModes apply {_x select 1};
			// Find the Current charge
			_realCharge = _fireModes find _currentFireMode;

			// Get Weapon Elevation
			_realElevationOriginal = asin (_weaponDir select 2);
			_realElevation = (17.7777778 * _realElevationOriginal);
	
			// Some sort of Fix for Mortars having some weird Elevation numbers
			// Dunno what it does, ask the ACE Team
			if (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "ace_artillerytables_showGunLaying") == 2) then {
				private _turretCfg = [_uavClass, _turret] call CBA_fnc_getTurret;
				private _turretAnimBody = getText (_turretCfg >> "animationSourceBody");
				private _currentTraverseRad = _uav animationSourcePhase _turretAnimBody;
				if (isNil "_currentTraverseRad") then {_currentTraverseRad = _uav animationPhase _turretAnimBody;};
				// Get turret roatation around it's z axis, then calc weapon elev in it's projection
				private _turretRot = [vectorDir _uav, vectorUp _uav, deg _currentTraverseRad] call CBA_fnc_vectRotate3D;
				_realElevationOriginal = (acos ((_turretRot vectorCos _weaponDir) min 1)) + ((_turretRot call CBA_fnc_vect2polar) select 2);
				if (_realElevationOriginal > 90) then {_realElevationOriginal = 180 - _realElevationOriginal;};
				_realElevation = (17.7777778 * _realElevationOriginal);
			};

			//script to disable airburst when turret is too low for it, and reenable it when high enough
			_currentMag = currentMagazine _uav;

			if (_realElevation <= 50) then
			{
				if (_currentMag regexMatch ".*_HEAB.*") then
				{
					_currentWeapon = currentWeapon _uav;
					_currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
					_replacementMag = _currentMag regexReplace ["_HEAB", "_backupHEAB"];
					_uav addMagazineTurret [_replacementMag, [0]];
					_uav loadMagazine [[0], _currentWeapon, _replacementMag];
					_uav removeMagazineTurret [_currentMag, [0]];
					_uav setAmmo [_currentWeapon, _currentAmmoCount];
				};
				if (_currentMag regexMatch ".*_lowHEAB.*") then
				{
					_currentWeapon = currentWeapon _uav;
					_currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
					_replacementMag = _currentMag regexReplace ["_lowHEAB", "_backuplowHEAB"];
					_uav addMagazineTurret [_replacementMag, [0]];
					_uav loadMagazine [[0], _currentWeapon, _replacementMag];
					_uav removeMagazineTurret [_currentMag, [0]];
					_uav setAmmo [_currentWeapon, _currentAmmoCount];
				};
			}
			else
			{
				if (_currentMag regexMatch ".*_backupHEAB.*") then
				{
					_currentWeapon = currentWeapon _uav;
					_currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
					_replacementMag = _currentMag regexReplace ["_backupHEAB", "_HEAB"];
					_uav addMagazineTurret [_replacementMag, [0]];
					_uav loadMagazine [[0], _currentWeapon, _replacementMag];
					_uav removeMagazineTurret [_currentMag, [0]];
					_uav setAmmo [_currentWeapon, _currentAmmoCount];
				};
				if (_currentMag regexMatch ".*_backuplowHEAB.*") then
				{
					_currentWeapon = currentWeapon _uav;
					_currentAmmoCount = parseNumber (((((currentMagazineDetail _uav) splitString "(") select 1) splitString "/") select 0);
					_replacementMag = _currentMag regexReplace ["_backuplowHEAB", "_lowHEAB"];
					_uav addMagazineTurret [_replacementMag, [0]];
					_uav loadMagazine [[0], _currentWeapon, _replacementMag];
					_uav removeMagazineTurret [_currentMag, [0]];
					_uav setAmmo [_currentWeapon, _currentAmmoCount];
				};
			};

			// Declare some Variables
			_realAzimuth = 0;
			_highAngleSol = 0;
			_travelTimeHigh = 0;
			_lowAngleSol = 0;
			_travelTimeLow = 0;

			// All the Different Controls
			_ctrlCharge = _display displayCtrl 1001;
			_ctrlAzimuth = _display displayCtrl 1002;
			_ctrlElevation = _display displayCtrl 1003;
			_ctrlDistance = _display displayCtrl 1004;
			_ctrlTarget = _display displayCtrl 1005;
			_ctrlTargetAzimuth = _display displayCtrl 1006;
			_ctrlDifference = _display displayCtrl 1007;
			_ctrlHighSol = _display displayCtrl 1008;
			_ctrlLowSol = _display displayCtrl 1009;
			_ctrlHighETA = _display displayCtrl 1010;
			_ctrlLowETA = _display displayCtrl 1011;
			_ctrlMessage = _display displayCtrl 1012;

			//Keybind Display
			//if (RC_Show_Keybinds) then {
			_ctrlKeySelect = _display displayCtrl 1017;
			_ctrlKeyUnselect = _display displayCtrl 1018;
			_ctrlKeyMarkersF = _display displayCtrl 1019;
			_ctrlKeyMarkersB = _display displayCtrl 1020;
			_ctrlKeyCharges = _display displayCtrl 1021;
			_ctrlKeyElUp = _display displayCtrl 1022;
			_ctrlKeyElDown = _display displayCtrl 1023;
			_ctrlKeyElSlow = _display displayCtrl 1024;

			_ctrlKeySelect ctrlSetText format ["select DL target: %1%2", ((actionKeysNamesArray "vehLockTargets") select 0), " / aim at"];
			_ctrlKeyUnselect ctrlSetText format ["unselect DL target: %1%2", ((actionKeysNamesArray "lockTarget") select 0)];

			_ArrayMarkersF = ["Remote Controlled Artillery", "RC_Scroll_Targets_Forwards"] call CBA_fnc_getKeybind;
			_KeyMarkersF = (((_ArrayMarkersF select 8) select 0) select 0) call BIS_fnc_keyCode;
			if (!isNil "_KeyMarkersF") then {_ctrlKeyMarkersF ctrlSetText format ["cycle markers ->: %1%2", _KeyMarkersF];};

			_ArrayMarkersB = ["Remote Controlled Artillery", "RC_Scroll_Targets_Backwards"] call CBA_fnc_getKeybind;
			_KeyMarkersB = (((_ArrayMarkersB select 8) select 0) select 0) call BIS_fnc_keyCode;
			if (!isNil "_KeyMarkersB") then {_ctrlKeyMarkersB ctrlSetText format ["cycle markers <-: %1%2", _KeyMarkersB];};

			_ctrlKeyCharges ctrlSetText format ["cycle charges: %1%2", ((actionKeysNamesArray "nextWeapon") select 0)];
			_ctrlKeyElUp ctrlSetText format ["elevation up: %1%2", ((actionKeysNamesArray "gunElevUp") select 0)];
			_ctrlKeyElDown ctrlSetText format ["elevation down: %1%2", ((actionKeysNamesArray "gunElevDown") select 0)];
			_ctrlKeyElSlow ctrlSetText format ["slow elevation: %1%2", ((actionKeysNamesArray "gunElevSlow") select 0)];
			//};

			//if ace installed, warning that ace adjustable scopes prevent gun elevation when hotkeys overlap
			if (isNull _AceUI) then {
				if (RC_ace_hotkey_warning) then {
					{{{(_display displayCtrl _x) ctrlShow true} forEach [1025,1026,1027];} else {{(_display displayCtrl _x) ctrlShow false} forEach [1025,1026,1027];};};
				};
			};

			// checks if shell requires lock before firing
			_requiresLock=(getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_RequiresLock"))==1;
			_terrainWarning=(getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_TerrainWarning"))==1;
			//UV Pos
			_artyPos = getPosASL _uav;
			//checks if datalink target is too close (mortar attached to vehicle would not show target markers otherwise, and no lock requirement warning would show for guided)
			_selectedTargetDistance=1;
			if (cursorTarget isNotEqualto objNull) then {_selectedTargetDistance=(getpos cursorTarget) distance2d _artyPos};
			_noTargetOrTargetTooClose=false;
			if ((cursorTarget isEqualto objNull) or (_selectedTargetDistance <=20)) then {_noTargetOrTargetTooClose=true;};

			// If we are looking into the Sky
			if (_rangeText isEqualTo "--") then {
				// Use the Weapon Dir
				_realAzimuth = ((_weaponDir select 0) atan2 (_weaponDir select 1));
				// Hide Submunition Warning when looking at the Sky
				{(_display displayCtrl _x) ctrlShow false} forEach [1013,1014];
				// Show Lock Requirement Warning when having no Target selected
				if (_requiresLock && _noTargetOrTargetTooClose) then {{(_display displayCtrl _x) ctrlShow true} forEach [1015,1016];} else {{(_display displayCtrl _x) ctrlShow false} forEach [1015,1016];};
			} else {
				// Else use the Look Vector
				_realAzimuth = ((_lookVector select 0) atan2 (_lookVector select 1));
				// Show Submunition Warning when looking at Terrain
				if (_terrainWarning) then {{(_display displayCtrl _x) ctrlShow true} forEach [1013,1014];} else {{(_display displayCtrl _x) ctrlShow false} forEach [1013,1014];};
				// Show Lock Requirement Warning when having no Target selected
				if (_requiresLock && _noTargetOrTargetTooClose) then {{(_display displayCtrl _x) ctrlShow true} forEach [1015,1016];} else {{(_display displayCtrl _x) ctrlShow false} forEach [1015,1016];};
			};

			// Wrap around
			if (_realAzimuth < 0) then {_realAzimuth = _realAzimuth + 360;};
			_realAzimuth = (17.7777778 * _realAzimuth);
			
			// If we actually have a Target (thats not too close)
			if (((cursorTarget isNotEqualto objNull) && (_selectedTargetDistance >= 20)) or !(RC_Artillery_Markers isEqualTo [])) then
			{
				if !(RC_Artillery_Markers isEqualTo []) then
				{
					if (isNil "RC_Current_Target" || RC_Current_Target isEqualTo []) then {
						RC_Current_Target = RC_Artillery_Markers select 0;
					};
					// Try to see if the Current Target Exists
					_targetExists = RC_Artillery_Markers findIf {
						(_x select 0) == (RC_Current_Target select 0);
					};
					// If the Target can't be found we reset the current target
					if (_targetExists == -1) then {
						RC_Current_Index = 0;
					};
				};

				//ElDiff for formula
				_aimAboveHeight = 0;
				_aimAboveHeight = getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_AimAboveHeight");	//for airburst and illum point of aim adjust
				
				_BarrelAGL = 0;
				_BarrelLenght = 0;
				_WeaponDirection = 0;
				_muzzleHeight = 0;
				_BarrelAGL = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelAGL");
				_BarrelLenght = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelLenght");
				_WeaponDirection = ((_uav weaponDirection currentWeapon _uav) select 2);
				_muzzleHeightEstimate = _BarrelLenght * (sin (_WeaponDirection*90)) + _BarrelAGL;

				//find if datalink target is selected
				_targetPos = [0,0,0];
				_hasTargetSelected=false;
				if (cursorTarget isNotEqualto objNull) then {_hasTargetSelected=true};

				//UV Pos
				_artyPos = getPosASL _uav;
				//Target Pos
				if (_hasTargetSelected && !(_noTargetOrTargetTooClose)) then {_targetPos = getpos cursorTarget} else {_targetPos = markerPos (RC_Current_Target select 1)};
				//Barrel End to Target Distance
				_muzzleFromCenterEstimate = 0;
				if ((getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelExtends"))==1) then {_muzzleFromCenterEstimate = _BarrelLenght * (cos (_WeaponDirection*90));};
				_targetDistance = round((_targetPos distance2d _artyPos)-_muzzleFromCenterEstimate);
				if (_targetDistance <= 1) then {_targetDistance=1};	//to prevent zero devider error

				_Difference = 0;
				_Difference = ((AGLToASL _targetPos) select 2) + _aimAboveHeight - ((_artyPos select 2) + _muzzleHeightEstimate);

				//how ElDiff is shown based on cba settings
				_shownDifference = 0;
				if RC_Arty_EL_Diff then {_shownDifference = _Difference;} else {_shownDifference = -_Difference;};

				_targetVector = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL _targetPos);
				_targetAzimuth = ((_targetVector select 0) atan2 (_targetVector select 1));
				if (_targetAzimuth < 0) then { _targetAzimuth = _targetAzimuth + 360; };
				_targetAzimuth = (17.7777778 * _targetAzimuth);

				_gravity=9.807;

				// Velocity of the Round
				_roundVelocity = getNumber (_weaponConfig >> _currentFireMode >> "artilleryCharge") * getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "initSpeed");

				_ctrlDistance ctrlSetText Format ["DIST: %1", [_targetDistance, 4, 0] call CBA_fnc_formatNumber];
				if (_hasTargetSelected && (_selectedTargetDistance >= 20)) then {_ctrlTarget ctrlSetText "T: Datalink";} else {_ctrlTarget ctrlSetText Format ["T: %1", [RC_Current_Target select 0, 2, 0] call CBA_fnc_formatNumber];};
				_ctrlTargetAzimuth ctrlSetText Format ["T AZ: %1", [_targetAzimuth, 4, 0] call CBA_fnc_formatNumber];
				_ctrlDifference ctrlSetText Format ["DIF: %1", [_shownDifference, 4, 0] call CBA_fnc_formatNumber];

				// If we have Solution Calculator Turned on do da Math
				if (RC_Solution_Calculator_On) then {
					
					// Marker High Angle
					_calcHigh = (atan((_roundVelocity^2+SQRT(_roundVelocity^4-_gravity*(_gravity*(_targetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_targetDistance)));
					_calcHigh = round (_calcHigh * (10^2)) / (10^2);
					_highAngleSol = (3200*atan(((_roundVelocity^2)+sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_Difference)+(_gravity*(_targetDistance^2))))))/(_gravity*_targetDistance)))/pi/57.30;
					_travelTimeHigh = round(((2*_roundVelocity)*(SIN(_calcHigh)))/_gravity);
					//_peakASLHigh = (_roundVelocity**2*(sin(_calcHigh*0.0174533))*(sin(_calcHigh*0.0174533)))/(2*_gravity);
					
					// Marker Low Angle
					_calcLow = (atan((_roundVelocity^2-SQRT(_roundVelocity^4-_gravity*(_gravity*(_targetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_targetDistance)));
					_calcLow = round (_calcLow * (10^2)) / (10^2);
					_lowAngleSol = (3200*atan(((_roundVelocity^2)-sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_Difference)+(_gravity*(_targetDistance^2))))))/(_gravity*_targetDistance)))/pi/57.30;
					_travelTimeLow = round(((2*_roundVelocity)*(SIN(_calcLow)))/_gravity);
					//_peakASLLow = (_roundVelocity**2*(sin**2)*(_calcLow*0.0174533))/(2*_gravity);
					//_peakASLLow = (_roundVelocity**2*(sin(_calcLow*0.0174533))*(sin(_calcLow*0.0174533)))/(2*_gravity);

					switch (true) do {
						// If Elevation is close/correct change the Elevation text color
						case((_realElevation < (_lowAngleSol + 0.25)) and (_realElevation > (_lowAngleSol - 0.25))): {_ctrlElevation ctrlSetTextColor [0,1,0,1];};
						case((_realElevation < (_highAngleSol + 0.25)) and (_realElevation > (_highAngleSol - 0.25))): {_ctrlElevation ctrlSetTextColor [0,1,0,1];};

						case((_realElevation < (_lowAngleSol + 0.5)) and (_realElevation > (_lowAngleSol - 0.5))): {_ctrlElevation ctrlSetTextColor [0.725,1,0.5,1];};
						case((_realElevation < (_highAngleSol + 0.5)) and (_realElevation > (_highAngleSol - 0.5))): {_ctrlElevation ctrlSetTextColor [0.725,1,0.5,1];};
						
						case((_realElevation < (_lowAngleSol + 1)) and (_realElevation > (_lowAngleSol - 1))): {_ctrlElevation ctrlSetTextColor [0.8,1,0.5,1];};
						case((_realElevation < (_highAngleSol + 1)) and (_realElevation > (_highAngleSol - 1))): {_ctrlElevation ctrlSetTextColor [0.8,1,0.5,1];};

						case((_realElevation < (_lowAngleSol + 2)) and (_realElevation > (_lowAngleSol - 2))): {_ctrlElevation ctrlSetTextColor [0.85,1,0.5,1];};
						case((_realElevation < (_highAngleSol + 2)) and (_realElevation > (_highAngleSol - 2))): {_ctrlElevation ctrlSetTextColor [0.85,1,0.5,1];};

						case((_realElevation < (_lowAngleSol + 3)) and (_realElevation > (_lowAngleSol - 3))): {_ctrlElevation ctrlSetTextColor [0.9,1,0.5,1];};
						case((_realElevation < (_highAngleSol + 3)) and (_realElevation > (_highAngleSol - 3))): {_ctrlElevation ctrlSetTextColor [0.9,1,0.5,1];};

						case((_realElevation < (_lowAngleSol + 4)) and (_realElevation > (_lowAngleSol - 4))): {_ctrlElevation ctrlSetTextColor [0.95,1,0.5,1];};
						case((_realElevation < (_highAngleSol + 4)) and (_realElevation > (_highAngleSol - 4))): {_ctrlElevation ctrlSetTextColor [0.95,1,0.5,1];};

						case((_realElevation < (_lowAngleSol + 5)) and (_realElevation > (_lowAngleSol - 5))): {_ctrlElevation ctrlSetTextColor [1,1,0.5,1];};
						case((_realElevation < (_highAngleSol + 5)) and (_realElevation > (_highAngleSol - 5))): {_ctrlElevation ctrlSetTextColor [1,1,0.5,1];};

						case((_realElevation < (_highAngleSol + 6)) and (_realElevation > (_highAngleSol - 6))): {_ctrlElevation ctrlSetTextColor [1,0.95,0.5,1];};
						case((_realElevation < (_lowAngleSol + 6)) and (_realElevation > (_lowAngleSol - 6))): {_ctrlElevation ctrlSetTextColor [1,0.95,0.5,1];};

						case((_realElevation < (_highAngleSol + 8)) and (_realElevation > (_highAngleSol - 8))): {_ctrlElevation ctrlSetTextColor [1,0.9,0.5,1];};
						case((_realElevation < (_lowAngleSol + 8)) and (_realElevation > (_lowAngleSol - 8))): {_ctrlElevation ctrlSetTextColor [1,0.9,0.5,1];};

						case((_realElevation < (_highAngleSol + 9)) and (_realElevation > (_highAngleSol - 9))): {_ctrlElevation ctrlSetTextColor [1,0.85,0.5,1];};
						case((_realElevation < (_lowAngleSol + 9)) and (_realElevation > (_lowAngleSol - 9))): {_ctrlElevation ctrlSetTextColor [1,0.85,0.5,1];};

						case((_realElevation < (_highAngleSol + 10)) and (_realElevation > (_highAngleSol - 10))): {_ctrlElevation ctrlSetTextColor [1,0.8,0.5,1];};
						case((_realElevation < (_lowAngleSol + 10)) and (_realElevation > (_lowAngleSol - 10))): {_ctrlElevation ctrlSetTextColor [1,0.8,0.5,1];};

						// If neither then set it to White again
						default {
							_ctrlElevation ctrlSetTextColor [1,1,1,1];
						};
					};
				} else {
					// Turn off Ready to Fire Message
					_ctrlMessage ctrlShow false;
				};

				switch (true) do {
						// If Azimuth is close/correct change the Azimuth text color
						case((_realAzimuth < (_targetAzimuth + 0.25)) and (_realAzimuth > (_targetAzimuth - 0.5))): {_ctrlAzimuth ctrlSetTextColor [0,1,0,1];};
						case((_realAzimuth < (_targetAzimuth + 1)) and (_realAzimuth > (_targetAzimuth - 1))): {_ctrlAzimuth ctrlSetTextColor [0.725,1,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 2)) and (_realAzimuth > (_targetAzimuth - 2))): {_ctrlAzimuth ctrlSetTextColor [0.8,1,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 3)) and (_realAzimuth > (_targetAzimuth - 3))): {_ctrlAzimuth ctrlSetTextColor [0.85,1,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 4)) and (_realAzimuth > (_targetAzimuth - 4))): {_ctrlAzimuth ctrlSetTextColor [0.9,1,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 5)) and (_realAzimuth > (_targetAzimuth - 5))): {_ctrlAzimuth ctrlSetTextColor [0.95,1,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 6)) and (_realAzimuth > (_targetAzimuth - 6))): {_ctrlAzimuth ctrlSetTextColor [1,1,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 9)) and (_realAzimuth > (_targetAzimuth - 9))): {_ctrlAzimuth ctrlSetTextColor [1,0.95,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 11)) and (_realAzimuth > (_targetAzimuth - 11))): {_ctrlAzimuth ctrlSetTextColor [1,0.9,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 15)) and (_realAzimuth > (_targetAzimuth - 15))): {_ctrlAzimuth ctrlSetTextColor [1,0.85,0.5,1];};
						case((_realAzimuth < (_targetAzimuth + 20)) and (_realAzimuth > (_targetAzimuth - 20))): {_ctrlAzimuth ctrlSetTextColor [1,0.8,0.5,1];};
						// If neither then set it to White again
						default {
							_ctrlAzimuth ctrlSetTextColor [1,1,1,1];
						};
					};
				
				// If both are Green we show ready to fire
				if (((ctrlTextColor _ctrlElevation) isEqualTo [0,1,0,1]) and ((ctrlTextColor _ctrlAzimuth) isEqualTo [0,1,0,1])) then {
					_ctrlMessage ctrlSetTextColor [0,1,0,1];
					_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
					_ctrlMessage ctrlSetText "ALIGNED";
				} else {
					_ctrlMessage ctrlSetTextColor [1,0,0,1];
					_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
					_ctrlMessage ctrlSetText "NOT ALIGNED";
				};
				
				// Parse these back to Numbers incase they are NaN
				_highAngleSol = parseNumber str(_highAngleSol);
				_lowAngleSol = parseNumber str(_lowAngleSol);
				_travelTimeHigh = parseNumber str(_travelTimeHigh);
				_travelTimeLow = parseNumber str(_travelTimeLow);
	
				// If they were NaN then make them Zero
				if (_highAngleSol < 0) then {
					_highAngleSol = 0;
					_lowAngleSol = 0;
					_travelTimeHigh = 0;
					_travelTimeLow = 0;
				};
			} else {
				// If we don't have any Valid Targets
				_ctrlAzimuth ctrlSetTextColor [1,1,1,1];
				_ctrlElevation ctrlSetTextColor [1,1,1,1];

				_ctrlDistance ctrlSetText "DIST: 0000";
				_ctrlTarget ctrlSetText "T: 0";
				_ctrlTargetAzimuth ctrlSetText "T AZ: 0000";
				_ctrlDifference ctrlSetText "DIF: 0000" ;
				_ctrlHighSol ctrlSetText "H SOL: 0000";
    			_ctrlLowSol ctrlSetText "L SOL: 0000";
    			_ctrlHighETA ctrlSetText "ETA: 000";
    			_ctrlLowETA ctrlSetText "ETA: 000";
				
				// If we have no Targets
				_ctrlMessage ctrlSetTextColor [1,0,0,1];
				_ctrlMessage ctrlSetPositionX (0.868267 * safezoneW + safezoneX);
				//_ctrlMessage ctrlSetText format ["NO TARGET ADD MAP MARKER: %1%2", RC_Marker_Prefix, "1-99"];
				//_ctrlMessage ctrlSetText format ["ADD MAP MARKER: %1%2", RC_Marker_Prefix, "1-99 /", RC_GPS_Prefix];	//doesnt show "gps"?
				_ctrlMessage ctrlSetText format ["ADD MAP MARKER: %1%2", RC_Marker_Prefix, "1-99 / gps"];
			};

			// If we have the Solution Calculating turned off we hide the UI
			if !(RC_Solution_Calculator_On) then {
				_ctrlHighSol ctrlShow false;
            	_ctrlLowSol ctrlShow false;
            	_ctrlHighETA ctrlShow false;
            	_ctrlLowETA ctrlShow false;
			} else {
				_ctrlHighSol ctrlShow true;
            	_ctrlLowSol ctrlShow true;
            	_ctrlHighETA ctrlShow true;
            	_ctrlLowETA ctrlShow true;
			};

			_ctrlCharge ctrlSetText Format ["CH: %1", _realCharge];
			_ctrlAzimuth ctrlSetText Format ["AZ: %1", [_realAzimuth, 4, 0] call CBA_fnc_formatNumber];
			_ctrlElevation ctrlSetText Format ["EL: %1", [_realElevation, 4, 0] call CBA_fnc_formatNumber];
			_ctrlHighSol ctrlSetText Format ["H SOL: %1", [_highAngleSol, 4, 0] call CBA_fnc_formatNumber];
			_ctrlLowSol ctrlSetText Format ["L SOL: %1", [_lowAngleSol, 4, 0] call CBA_fnc_formatNumber];
			_ctrlHighETA ctrlSetText Format ["ETA: %1", [_travelTimeHigh, 3, 0] call CBA_fnc_formatNumber];
			_ctrlLowETA ctrlSetText Format ["ETA: %1", [_travelTimeLow, 3, 0] call CBA_fnc_formatNumber];
		} else {
			// UI Shouldn't be Shown so we cut it
			"RC_Artillery" cutFadeOut 0;
			RC_InUI = false;
		};
	};
};
