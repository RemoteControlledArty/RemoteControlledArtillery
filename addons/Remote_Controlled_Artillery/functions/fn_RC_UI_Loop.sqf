/*
	This Code is held together by Duct Tape and Hope
	Author: Fluffy

	Description:
	Main Loop to Handle the Calculation and UI of RC Artillery Units
*/

// Need to exit early if we aren't a client
if !hasInterface exitWith {};
RC_Artillery_UI = [] spawn {


	while {true} do {
		sleep 0.1;

		_uav = (getConnectedUAV player); // UAV

		// If we don't have a UAV connected, Start at the top
		if (_uav isEqualTo objNull) then {
			continue;
		};

		// If the Player is currently controlling the UAV
		_inDrone = ((UAVControl _uav) select 1) isEqualTo "GUNNER"; 
		
		_uavClass = typeOf _uav; // UAV ClassName
		
		// See if the vehicle has the isRCArty property
		_isRCArty = (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isRCArty") == 1);

		// If seats have been disabled in the Config we handle that here
		_disableSeats = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCDisableSeats");
		// If we have the Property Defined
		if (_disableSeats != 0) then {
			switch (_disableSeats) do {
				// Locks only the Driver Seat
				case 1: {
					if !(_uav lockedTurret [0,0]) then {_uav lockTurret [[0,0], true]}
				};
				// Locks both the Driver seat and Commander
				case 2: {
					if !(lockedDriver _uav) then {_uav lockDriver true};
					if !(_uav lockedTurret [0,0]) then {_uav lockTurret [[0,0], true]};
				};
				// Specific Case for if the Commander seat is at [0] instead of [0,0]
				case 3: {
					if !(_uav lockedTurret [0]) then {_uav lockTurret [[0], true]};
				};
				default {hint "Something Went Wrong!"};
			};
		};


		// If it's of Artillery or Mortar Type do da thing
		if (_isRCArty && _inDrone) then {
			
			RC_InUI = true; // We are in the UI now
			
			// If our UAV is Autonomous we want to make it not
			if (isAutonomous _uav) then {
				// We need to remote exec it since setAutonomous is of Local Effect so it needs to be
				// where the UAV is Local
				[_uav, false] remoteExec ["setAutonomous", _uav];
			};

			// CBA Option for Allowing the Artillery Computer in RC Artillery UAVs
			if (!RC_Arty_Computer_On) then {
				// Remote Execute this to make it Multiplayer Compatible
				[false] remoteExec ["enableEngineArtillery", _uav];
			} else {
				// Remote Execute this to make it Multiplayer Compatible
				[true] remoteExec ["enableEngineArtillery", _uav];
			};
			
			// Check if the Display for the UI Exists if not Create it
			if (isNull (uiNamespace getVariable ["RC_Artillery", displayNull])) then {
				"RC_Artillery" cutRsc ["RC_Artillery", "PLAIN", 0, false];
			};
			
			disableSerialization;

			// Get the UI so we can see if it has Distance or not
			_AceUI = uiNamespace getVariable ["ACE_dlgArtillery", displayNull];
			_RCAUI = uiNamespace getVariable ["RCA_ArtyUI", displayNull];

			_RCA_CurrentArtyDisplay = displayNull;
			// If our one is Null we  use theirs
			if (!isNull _RCAUI) then {
				_RCA_CurrentArtyDisplay = _RCAUI;
			} else {
				_RCA_CurrentArtyDisplay = _AceUI;
			};

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

			// If we are looking into the Sky
			if (_rangeText isEqualTo "--") then {
				// Use the Weapon Dir
				_realAzimuth = ((_weaponDir select 0) atan2 (_weaponDir select 1));
				// Hide Submunition Warning
				{(_display displayCtrl _x) ctrlShow false} forEach [1013,1014];
			} else {
				// Else use the Look Vector
				_realAzimuth = ((_lookVector select 0) atan2 (_lookVector select 1));
				// Show Submunition Warning
				{(_display displayCtrl _x) ctrlShow true} forEach [1013,1014];
			};
			// Thank the ACE Team for the Above!

			// Wrap around
			if (_realAzimuth < 0) then {_realAzimuth = _realAzimuth + 360;};
			_realAzimuth = (17.7777778 * _realAzimuth);
			
			// If we actually have Target Markers
			if !(RC_Artillery_Markers isEqualTo []) then {

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

				//ElDiff for formula
				_aimAboveHeight = 0;
				_aimAboveHeight = getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_AimAboveHeight");	//for airburst and illum point of aim adjust
				
				_BarrelAGL = 0;
				_BarrelLenght = 0;
				_WeaponDirection = 0;
				_muzzleHeight = 0;
				_BarrelAGL = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelStartHeight");
				_BarrelLenght = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelLenght");
				_WeaponDirection = ((_uav weaponDirection currentWeapon _uav) select 2);
				_muzzleHeightEstimate = _BarrelLenght * (sin (_WeaponDirection*90)) + _BarrelAGL;

				//Target/UV Pos
				_targetPos = markerPos (RC_Current_Target select 1);
				_artyPos = getPosASL _uav;
				_muzzleFromCenterEstimate = 0;
				if ((getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelExtends"))==1) then {_muzzleFromCenterEstimate = _BarrelLenght * (cos (_WeaponDirection*90));};
				_targetDistance = (round(_targetPos distance2d _artyPos))-_muzzleFromCenterEstimate;

				//how ElDiff is shown based on cba settings
				_shownDifference = 0;
				if RC_Arty_EL_Diff then {
					_shownDifference = ((AGLToASL _targetPos) select 2) - (_artyPos select 2);
				} else {
					_shownDifference = (_artyPos select 2) - ((AGLToASL _targetPos) select 2);
				};

				_Difference = 0;
				_Difference = ((AGLToASL _targetPos) select 2) + _aimAboveHeight - ((_artyPos select 2) + _muzzleHeightEstimate);
				//_Difference = ((AGLToASL _targetPos) select 2) - (_artyPos select 2);		//outdated

				_targetVector = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL _targetPos);
				_targetAzimuth = ((_targetVector select 0) atan2 (_targetVector select 1));
				if (_targetAzimuth < 0) then { _targetAzimuth = _targetAzimuth + 360; };
				_targetAzimuth = (17.7777778 * _targetAzimuth);

				_gravity=9.8066;

				// Super Long Line to get the Velocity of the Round
				_roundVelocity = getNumber (_weaponConfig >> _currentFireMode >> "artilleryCharge") * getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "initSpeed");

				_ctrlDistance ctrlSetText Format ["DIST: %1", [_targetDistance, 4, 0] call CBA_fnc_formatNumber];
				_ctrlTarget ctrlSetText Format ["T: %1", [RC_Current_Target select 0, 2, 0] call CBA_fnc_formatNumber];
				_ctrlTargetAzimuth ctrlSetText Format ["T AZ: %1", [_targetAzimuth, 4, 0] call CBA_fnc_formatNumber];
				_ctrlDifference ctrlSetText Format ["DIF: %1", [_shownDifference, 4, 0] call CBA_fnc_formatNumber];

				// If we have Solution Calculator Turned on do da Math
				if (RC_Solution_Calculator_On) then {
					
					// Marker High Angle
					//(atan((_finalVel^2+sqrt(_finalVel^4-GRAVITY*(GRAVITY*(_distance^2)+2*_zDiff*_finalVel^2)))/(GRAVITY*_distance)));
					_calcHigh = (atan((_roundVelocity^2+SQRT(_roundVelocity^4-_gravity*(_gravity*(_targetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_targetDistance)));
					_calcHigh = round (_calcHigh * (10^2)) / (10^2);
					_highAngleSol = (3200*atan(((_roundVelocity^2)+sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_Difference)+(_gravity*(_targetDistance^2))))))/(_gravity*_targetDistance)))/pi/57.30;
					_travelTimeHigh = round(((2*_roundVelocity)*(SIN(_calcHigh)))/_gravity);
					//_peakASLHigh = (_roundVelocity**2*(sin(_calcHigh*0.0174533))*(sin(_calcHigh*0.0174533)))/(2*_gravity)
					//private _tof = round ((2*_finalVel*sin(_elev))/GRAVITY);
					
					// Marker Low Angle
					//"original" missing? _calcLow = (atan((_roundVelocity^2-SQRT(_roundVelocity^4-_gravity*(_gravity*(_targetDistance^2)+2*_realElevation*(_roundVelocity^2))))/(_gravity*_targetDistance)));
					_calcLow = (atan((_roundVelocity^2-SQRT(_roundVelocity^4-_gravity*(_gravity*(_targetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_targetDistance)));
					_calcLow = round (_calcLow * (10^2)) / (10^2);
					_lowAngleSol = (3200*atan(((_roundVelocity^2)-sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_Difference)+(_gravity*(_targetDistance^2))))))/(_gravity*_targetDistance)))/pi/57.30;
					_travelTimeLow = round(((2*_roundVelocity)*(SIN(_calcLow)))/_gravity);
					//_peakASLLow = (_roundVelocity**2*(sin**2)*(_calcLow*0.0174533))/(2*_gravity)
					//_peakASLLow = (_roundVelocity**2*(sin(_calcLow*0.0174533))*(sin(_calcLow*0.0174533)))/(2*_gravity)

					switch (true) do {
						// If Elevation is correct for Low solution turn the Elevation text Green
						case((_realElevation < (_lowAngleSol + 1)) and (_realElevation > (_lowAngleSol - 1))): {
							_ctrlElevation ctrlSetTextColor [0,1,0,1];
						};
						
						// If Elevation is correct for High solution turn the Elevation text Green
						case((_realElevation < (_highAngleSol + 1)) and (_realElevation > (_highAngleSol - 1))): {
							_ctrlElevation ctrlSetTextColor [0,1,0,1];
						};

						// If neither then set it to White again
						default {
							_ctrlElevation ctrlSetTextColor [1,1,1,1];
						};
					};
				} else {
					// Turn off Ready to Fire Message
					_ctrlMessage ctrlShow false;
				};
				
				// Make the Azimuth Text Green if the Azimuth is aligned with the Target Azimuth
				if ((_realAzimuth < (_targetAzimuth + 1)) and (_realAzimuth > (_targetAzimuth - 1))) then {
					_ctrlAzimuth ctrlSetTextColor [0,1,0,1];
				} else {
					_ctrlAzimuth ctrlSetTextColor [1,1,1,1];
				};

				// If both are Green we show ready to fire
				if (((ctrlTextColor _ctrlElevation) isEqualTo [0,1,0,1]) and ((ctrlTextColor _ctrlAzimuth) isEqualTo [0,1,0,1])) then {
					_ctrlMessage ctrlSetTextColor [0,1,0,1];
					_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
					_ctrlMessage ctrlSetText "READY TO FIRE";
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
				_ctrlMessage ctrlSetText format ["NO TARGET ADD MAP MARKER: %1%2", RC_Marker_Prefix, "1-99"];
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


			//prepared formulas

				/*
				// laser datalink target
				_DatalinkTargets = getSensorTargets _uav;
				_targetIndex = _DatalinkTargets findif {(_x select 3) findif {_x isequalto "laser"} > -1};	//how to find specific, like closest laser?
				_laserTarget = _DatalinkTargets select _targetIndex;
				_laserTargetPos = getpos (_laserTarget select 0);
				_laserTargetDistance = round(_laserTargetPos distance _artyPos);
				_laserTargetDifference = ((AGLToASL _laserTargetPos) select 2) - (_artyPos select 2);
				_laserTargetVector = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL _laserTargetPos);
				_laserTargetAzimuth = ((_laserTargetVector select 0) atan2 (_laserTargetVector select 1));
				if (_laserTargetAzimuth < 0) then {_laserTargetAzimuth = _laserTargetAzimuth + 360;};
				_laserTargetAzimuth = (17.7777778 * _laserTargetAzimuth);

				// Laser High Angle
				_laserCalcHigh = (atan((_roundVelocity^2+SQRT(_roundVelocity^4-_gravity*(_gravity*(_laserTargetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_laserTargetDistance)));
				_laserCalcHigh = round (_laserCalcHigh * (10^2)) / (10^2); //fix to 2 decimal places
				_laserHighAngleSol = (3200*atan(((_roundVelocity^2)+sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_laserTargetDifference)+(_gravity*(_laserTargetDistance^2))))))/(_gravity*_laserTargetDistance)))/pi/57.30;
				_laserTravelTimeHigh = round(((2*_roundVelocity)*(SIN(_laserCalcHigh)))/_gravity); // Calculate the Travel Time in Seconds
				
				// Laser Low Angle
				_laserCalcLow = (atan((_roundVelocity^2-SQRT(_roundVelocity^4-_gravity*(_gravity*(_laserTargetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_laserTargetDistance)));
				_laserCalcLow = round (_laserCalcLow * (10^2)) / (10^2);
				_laserLowAngleSol = (3200*atan(((_roundVelocity^2)-sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_laserTargetDifference)+(_gravity*(_laserTargetDistance^2))))))/(_gravity*_laserTargetDistance)))/pi/57.30;
				_laserTravelTimeLow = round(((2*_roundVelocity)*(SIN(_laserCalcLow)))/_gravity);


				// selected datalink target
				_selectedTarget = cursorTarget;
				_selectedTargetPos = getpos _selectedTarget;
				_selectedTargetDistance = round(_selectedTargetPos distance _artyPos);
				_selectedTargetDifference = ((AGLToASL _selectedTargetPos) select 2) - (_artyPos select 2);
				_selectedDifference = 0;
				_selectedDifference = ((AGLToASL _selectedTargetPos) select 2) - (_artyPos select 2);
				_selectedTargetVector = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL _selectedTargetPos);
				_selectedTargetAzimuth = ((_selectedTargetVector select 0) atan2 (_selectedTargetVector select 1));
				if (_selectedTargetAzimuth < 0) then {_selectedTargetAzimuth = _selectedTargetAzimuth + 360;};
				_selectedtargetAzimuth = (17.7777778 * _selectedTargetAzimuth);
				//_targetAzimuth = round((_artyPos getDir _targetPos)*17.777778); 	//test, is inaccurate

				// selected High Angle
				_selectedCalcHigh = (atan((_roundVelocity^2+SQRT(_roundVelocity^4-_gravity*(_gravity*(_selectedTargetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_selectedTargetDistance)));
				_selectedCalcHigh = round (_selectedCalcHigh * (10^2)) / (10^2);
				_curserHighAngleSol = (3200*atan(((_roundVelocity^2)+sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_selectedTargetDifference)+(_gravity*(_selectedTargetDistance^2))))))/(_gravity*_selectedTargetDistance)))/pi/57.30;
				_curserTravelTimeHigh = round(((2*_roundVelocity)*(SIN(_selectedCalcHigh)))/_gravity);
				
				// selected Low Angle
				_selectedCalcLow = (atan((_roundVelocity^2-SQRT(_roundVelocity^4-_gravity*(_gravity*(_selectedTargetDistance^2)+2*_realElevationOriginal*(_roundVelocity^2))))/(_gravity*_selectedTargetDistance)));
				_selectedCalcLow = round (_selectedCalcLow * (10^2)) / (10^2);
				_curserLowAngleSol = (3200*atan(((_roundVelocity^2)-sqrt((_roundVelocity^4)-(_gravity*((2*(_roundVelocity^2)*_selectedTargetDifference)+(_gravity*(_selectedTargetDistance^2))))))/(_gravity*_selectedTargetDistance)))/pi/57.30;
				_curserTravelTimeLow = round(((2*_roundVelocity)*(SIN(_selectedCalcLow)))/_gravity);
				*/

			/*
			_uav = (getConnectedUAV player);
			_artyPos = getPosASL _uav;

			//only direct laser of the vehicle
			//_laserTarget = laserTarget _uav;
			//_laserTargetPos = getpos _laserTarget;
			//_laserTargetPos
			*/

			//automated firing, too easy and only high angle, but interesting option, only works when not controlling, so it would work with laser or locket target of UAV
			/*
			Howitzer doArtilleryFire [getpos man, currentMagazine Howitzer, 1];
			Howitzer doArtilleryFire [getpos vehicle, currentMagazine Howitzer, 1];
			Howitzer doArtilleryFire [vehicle, currentMagazine Howitzer, 1];
			Howitzer doArtilleryFire [getpos laserTarget player, currentMagazine Howitzer, 1];
			Howitzer doArtilleryFire [laserTarget player, currentMagazine Howitzer, 1];
			Howitzer doArtilleryFire [getpos cursorTarget, currentMagazine Howitzer, 1];	//UAV integrated targeting
			*/
		} else {
			// UI Shouldn't be Shown so we cut it
			"RC_Artillery" cutFadeOut 0;
			RC_InUI = false;
		};
	};
};
