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
			
			_display = uiNamespace getVariable ["RC_Artillery", displayNull]; // Display
			
			// Look Vector relative to the Camera
			_lookVector = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL (positionCameraToWorld [0,0,1]));
			_weaponDir = _uav weaponDirection (currentWeapon _uav); // Weapon direction as a Relative Vector3
			
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
		
			// Show all the controls
			{
				_ctrl = _display displayCtrl _x;
				_ctrl ctrlShow true;	
			} forEach [1001,1002,1003,1004,1005,1006,1007,1008]; 

			// Get Weapon Elevation
			_realElevation = asin (_weaponDir select 2);
			
			// Some sort of Fix for Mortars having some weird Elevation numbers
			// Dunno what it does, ask the ACE Team
			if (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "ace_artillerytables_showGunLaying") == 2) then {
				private _turretCfg = [_uavClass, _turret] call CBA_fnc_getTurret;
    			private _turretAnimBody = getText (_turretCfg >> "animationSourceBody");
				private _currentTraverseRad = _uav animationSourcePhase _turretAnimBody;
				if (isNil "_currentTraverseRad") then { _currentTraverseRad = _uav animationPhase _turretAnimBody; };
				// Get turret roatation around it's z axis, then calc weapon elev in it's projection
				private _turretRot = [vectorDir _uav, vectorUp _uav, deg _currentTraverseRad] call CBA_fnc_vectRotate3D;
				_realElevation = (acos ((_turretRot vectorCos _weaponDir) min 1)) + ((_turretRot call CBA_fnc_vect2polar) select 2);
				if (_realElevation > 90) then { _realElevation = 180 - _realElevation; };
			};

			// Declare some Variables
			_realAzimuth = 0;
			_highAngleSol = 0;
			_travelTimeHigh = 0;
			_lowAngleSol = 0;
			_travelTimeLow = 0;

			// If we are looking into the Sky
			if (_rangeText isEqualTo "--") then {
				// Use the Weapon Dir
				_realAzimuth = ((_weaponDir select 0) atan2 (_weaponDir select 1));
			} else {
				// Else use the Look Vector
				_realAzimuth = ((_lookVector select 0) atan2 (_lookVector select 1));
			};
			// Thank the ACE Team for the Above!

			// Wrap around
			if (_realAzimuth < 0) then { _realAzimuth = _realAzimuth + 360; };

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
				


				_targetPos = markerPos (RC_Current_Target select 1);
				_artyPos = getPosASL _uav;

				_targetDistance = round(_targetPos distance _artyPos);
				
				_Difference = 0;

				if RC_Arty_EL_Diff then {
					_Difference = ((AGLToASL _targetPos) select 2) - (_artyPos select 2);
				} else {
					_Difference = (_artyPos select 2) - ((AGLToASL _targetPos) select 2);
				};

				_targetVector = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL _targetPos);
				_targetAzimuth = ((_targetVector select 0) atan2 (_targetVector select 1));
				if (_targetAzimuth < 0) then { _targetAzimuth = _targetAzimuth + 360; };

				// Super Long Line to get the Velocity of the Round
				_roundVelocity = getNumber (_weaponConfig >> _currentFireMode >> "artilleryCharge") * getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "initSpeed");

				// High Angle
				_calcHigh = (atan((_roundVelocity^2+SQRT(_roundVelocity^4-9.80*(9.80*(_targetDistance^2)+2*_realElevation*(_roundVelocity^2))))/(9.80*_targetDistance)));
				_calcHigh = round (_calcHigh * (10 ^ 2)) / (10 ^2); //fix to 2 decimal places
				_highAngleSol = (3200*atan(((_roundVelocity^2)+sqrt((_roundVelocity^4)-(9.8*((2*(_roundVelocity^2)*_Difference)+(9.8*(_targetDistance^2))))))/(9.8*_targetDistance)))/pi/57.30;
				//_highAngleSol = (3200*(atan((_roundVelocity^2+sqrt(_roundVelocity^4-9.8*(2*_roundVelocity^2*0+9.8*_targetDistance^2)))/(9.8*_targetDistance))))/pi;
				_travelTimeHigh = round(((2*_roundVelocity)*(SIN(_calcHigh)))/9.80); // Calculate the Travel Time in Seconds
				
				// Low Angle
				_calcLow = (atan((_roundVelocity^2-SQRT(_roundVelocity^4-9.80*(9.80*(_targetDistance^2)+2*_realElevation*(_roundVelocity^2))))/(9.80*_targetDistance)));
				_calcLow = round (_calcLow * (10 ^ 2)) / (10 ^2); //fix to 2 decimal places
				//_lowAngleSol = (3200*(atan((_roundVelocity^2-sqrt(_roundVelocity^4-9.8*(2*_roundVelocity^2*0+9.8*_targetDistance^2)))/(9.8*_targetDistance))))/pi;
				_lowAngleSol = (3200*atan(((_roundVelocity^2)-sqrt((_roundVelocity^4)-(9.8*((2*(_roundVelocity^2)*_Difference)+(9.8*(_targetDistance^2))))))/(9.8*_targetDistance)))/pi/57.30;
				_travelTimeLow = round(((2*_roundVelocity)*(SIN(_calcLow)))/9.80); // Calculate the Travel Time in Seconds
	
				//hintsilent format["High: %1, ETA: %2\nLow: %3, ETA: %4", _highAngleSol, _travelTimeHigh, _lowAngleSol, _calcLow];

				_ctrlDistance ctrlSetText Format ["DIST: %1", [_targetDistance, 4, 0] call CBA_fnc_formatNumber];
				_ctrlTarget ctrlSetText Format ["T: %1", [RC_Current_Target select 0, 2, 0] call CBA_fnc_formatNumber];
				_ctrlTargetAzimuth ctrlSetText Format ["T AZ: %1", [17.7777778 * _targetAzimuth, 4, 0] call CBA_fnc_formatNumber];
				_ctrlDifference ctrlSetText Format ["DIF: %1", [_Difference, 4, 0] call CBA_fnc_formatNumber];
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
			};

			_ctrlCharge ctrlSetText Format ["CH: %1", _realCharge];
			_ctrlAzimuth ctrlSetText Format ["AZ: %1", [17.7777778 * _realAzimuth, 4, 0] call CBA_fnc_formatNumber];
			_ctrlElevation ctrlSetText Format ["EL: %1", [17.7777778 * _realElevation, 4, 0] call CBA_fnc_formatNumber];		
			_ctrlHighSol ctrlSetText Format ["H SOL: %1", [parseNumber str(_highAngleSol), 4, 0] call CBA_fnc_formatNumber];		
			_ctrlLowSol ctrlSetText Format ["L SOL: %1", [parseNumber str(_lowAngleSol), 4, 0] call CBA_fnc_formatNumber];		
			_ctrlHighETA ctrlSetText Format ["ETA: %1", [parseNumber str(_travelTimeHigh), 3, 0] call CBA_fnc_formatNumber];		
			_ctrlLowETA ctrlSetText Format ["ETA: %1", [parseNumber str(_travelTimeLow), 3, 0] call CBA_fnc_formatNumber];		

		} else {
			// UI Shouldn't be Shown so we cut it
			"RC_Artillery" cutFadeOut 0;
			RC_InUI = false;
		};
	};
};
