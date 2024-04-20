#include "script_component.hpp"
/*
	This Code is held together by Duct Tape and Hope
	Author: Fluffy, Ascent

	Description:
	Main Loop to Handle the Calculation and UI of RC Artillery Units
*/

// Need to exit early if we aren't a client
if (!hasInterface) exitWith {};
RC_Artillery_UI = [] spawn {
	while { true } do {
		sleep 0.1;

		_uav = getConnectedUAV player; // UAV
		_uavClass = typeOf _uav; // UAV ClassName
		_inDrone = ((UAVControl _uav) select 1) in ["DRIVER", "GUNNER", "COMMANDER"];	// If the Player is currently controlling the UAV
		
		// See if the vehicle has the isRCArty property
		_isRCArty = (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isRCArty") == 1);


		/*
		//performance improvement, implement when the UI itself works again

		if (isRemoteControlling player) then {
			// If it's of Artillery or Mortar Type do da thing
			if (_isRCArty) then {
				// UAV ClassName
				_uavClass = typeOf _uav;
				// See if the vehicle has the isRCArty property
				_isRCArty = (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isRCArty") == 1);

		if ({_inDrone && {(_uav isNotEqualto objNull)}}) then {
			// If it's of Artillery or Mortar Type do da thing
			if (_isRCArty) then {
				// UAV ClassName
				_uavClass = typeOf _uav;
				// See if the vehicle has the isRCArty property
				_isRCArty = (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isRCArty") == 1);
		*/


		// If it's of Artillery or Mortar Type do da thing
		if (_isRCArty && { _inDrone && { (_uav isNotEqualto objNull) } }) then {
			
			RC_InUI = true; // We are in the UI now
			
			// If our UAV is Autonomous we want to make it not
			// We need to remote exec it since setAutonomous is of Local Effect so it needs to be where the UAV is Local
			if (isAutonomous _uav) then {[_uav, false] remoteExec ["setAutonomous", _uav];};
			
			// Check if the Display for the UI Exists if not Create it
			if (isNull (uiNamespace getVariable ["RC_Artillery", displayNull])) then { "RC_Artillery" cutRsc ["RC_Artillery", "PLAIN", 0, false] };
			
			disableSerialization;	//could this cause problems?

			// Get the UI so we can see if it has Distance or not
			_AceUI = uiNamespace getVariable ["ACE_dlgArtillery", displayNull];
			_RCAUI = uiNamespace getVariable ["RCA_ArtyUI", displayNull];

			// CBA Option for Allowing the Artillery Computer in RC Artillery UGVs, without ACE its stays on for Mortars (as they dont work manually without ACE atm)
			// Remote Execute this to make it Multiplayer Compatible
			_isMortar = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RCisMortar") isEqualTo 1;
			_aceLoaded = isClass (configFile >> "CfgPatches" >> "ace_main");

			[(!RC_Allow_Vanilla_Arty_Computer && { !_aceLoaded && { _isMortar } })] remoteExec ["enableEngineArtillery", _uav];

			_RCA_CurrentArtyDisplay = displayNull;
			// If our one is Null we use theirs
			_RCA_CurrentArtyDisplay = [_RCAUI, _AceUI] select (isNull _RCAUI);

			// This is the Range Text
			_rangeText = ctrlText (_RCA_CurrentArtyDisplay displayCtrl 173);

			// Look Vector relative to the Camera
			_lookVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (AGLtoASL (positionCameraToWorld [0, 0, 1]));
			_weaponDir = _uav weaponDirection (currentWeapon _uav); // Weapon direction as a Relative Vector3
			
			// Fallback if we are using the Mortar and the Display isn't working
			if (isNull _RCA_CurrentArtyDisplay) then {
				private _testSeekerPosASL = AGLtoASL (positionCameraToWorld [0,0,0]);
				private _testPoint = _testSeekerPosASL vectorAdd (_lookVector vectorMultiply viewDistance);
    			_lookingAtGround = !((terrainIntersectASL [_testSeekerPosASL, _testPoint]) || { lineIntersects [_testSeekerPosASL, _testPoint, _uav] });
				
				if _lookingAtGround then {
					_rangeText = "--";
				} else {
					_rangeText = "0";
				};
			};
			
			_display = uiNamespace getVariable ["RC_Artillery", displayNull]; // Display

			//weapon informations like charges and current charge
			//#include "functions\UILoop_includes\weapon_info.sqf"
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\weapon_info.sqf"

			// Get Weapon Elevation
			_realElevationOriginal = asin (_weaponDir select 2);
			_realElevation = SLANT_ANGLE * _realElevationOriginal;
	
			// Some sort of Fix for Mortars having some weird Elevation numbers
			// Dunno what it does, ask the ACE Team
			if (getNumber (configFile >> "CfgVehicles" >> _uavClass >> "ace_artillerytables_showGunLaying") == 2) then {
				private _turretCfg = [_uavClass, _turret] call CBA_fnc_getTurret;
				private _turretAnimBody = getText (_turretCfg >> "animationSourceBody");
				private _currentTraverseRad = _uav animationSourcePhase _turretAnimBody;
				if (isNil "_currentTraverseRad") then { _currentTraverseRad = _uav animationPhase _turretAnimBody };
				// Get turret roatation around it's z axis, then calc weapon elev in it's projection
				private _turretRot = [vectorDir _uav, vectorUp _uav, deg _currentTraverseRad] call CBA_fnc_vectRotate3D;
				_realElevationOriginal = (acos ((_turretRot vectorCos _weaponDir) min 1)) + ((_turretRot call CBA_fnc_vect2polar) select 2);
				if (_realElevationOriginal > 90) then { _realElevationOriginal = 180 - _realElevationOriginal };
				_realElevation = (SLANT_ANGLE * _realElevationOriginal);
			};

			//changes magazine to backup airburst if EL is too low for conventional airburst
			//#include "functions\UILoop_includes\AB_magchange.sqf"
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\AB_magchange.sqf"

			//ctrl display, hotkey display, ace adjustable scope hotkey overlap warning
			//#include "functions\UILoop_includes\ctrl_display.sqf"
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\ctrl_display.sqf"

			// checks if shell requires lock before firing
			_requiresLock = (getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_RequiresLock"))==1;
			_terrainWarning = (getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "RC_TerrainWarning"))==1;
			//UV Pos
			_artyPos = getPosASL _uav;
			//checks if datalink target is too close (mortar attached to vehicle would not show target markers otherwise, and no lock requirement warning would show for guided)
			_selectedTargetDistance = 1;
			if (cursorTarget isNotEqualto objNull) then { _selectedTargetDistance=(getpos cursorTarget) distance2d _artyPos };
			_noTargetOrTargetTooClose = (cursorTarget isEqualto objNull) || (_selectedTargetDistance <=20);

			// If we are looking into the Sky
			private "_realAzimuth";
			if (_rangeText isEqualTo "--") then {
				// Use the Weapon Dir
				_realAzimuth = ((_weaponDir select 0) atan2 (_weaponDir select 1));
				// Hide Submunition Warning when looking at the Sky
				{ (_display displayCtrl _x) ctrlShow false } forEach [1013, 1014];
				// Show Lock Requirement Warning when having no Target selected
				{ (_display displayCtrl _x) ctrlShow (_requiresLock && _noTargetOrTargetTooClose) } forEach [1015,1016];
			} else {
				// Else use the Look Vector
				_realAzimuth = ((_lookVector select 0) atan2 (_lookVector select 1));
				// Show Submunition Warning when looking at Terrain
				{ (_display displayCtrl _x) ctrlShow _terrainWarning } forEach [1013, 1014];
				// Show Lock Requirement Warning when having no Target selected
				{ (_display displayCtrl _x) ctrlShow (_requiresLock && _noTargetOrTargetTooClose) } forEach [1015, 1016];
			};

			// Wrap around
			_realAzimuth = [_realAzimuth mod 360, 360 + _realAzimuth] select (_realAzimuth < 0);
			_realAzimuth = SLANT_ANGLE * _realAzimuth;
			
			/* Declare vars */
			private _highAngleSol = 0;
			private _travelTimeHigh = 0;
			private _lowAngleSol = 0;
			private _travelTimeLow = 0;

			// If we actually have a Target (thats not too close)
			if (((cursorTarget isNotEqualto objNull) && { _selectedTargetDistance >= 20 }) || !(RC_Artillery_Markers isEqualTo [])) then {
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
				};

				//ElDiff additions, like muzzle position, and rounds aim above value (airburst & topdown guided)
				//#include "functions\UILoop_includes\eldiff_additions.sqf"
				#include "\Remote_Controlled_Artillery\functions\UILoop_includes\eldiff_additions.sqf"

				//find if datalink target is selected
				_targetPos = [0, 0, 0];
				_hasTargetSelected = (cursorTarget isNotEqualto objNull);

				//UV Pos
				_artyPos = getPosASL _uav;
				//Target Pos
				if (_hasTargetSelected && !(_noTargetOrTargetTooClose)) then {
					_targetPos = getpos cursorTarget;
				} else {
					_targetPos = markerPos (RC_Current_Target select 1);
				};

				//Barrel End to Target Distance
				_muzzleFromCenterEstimate = 0;
				if ((getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelExtends")) isEqualTo 1) then { _muzzleFromCenterEstimate = _BarrelLenght * (cos (_WeaponDirection * 90)) };
				_targetDistance = (round ((_targetPos distance2d _artyPos) - _muzzleFromCenterEstimate)) max 1;

				_Difference = 0;
				_Difference = ((AGLToASL _targetPos) select 2) + _aimAboveHeight - ((_artyPos select 2) + _muzzleHeightEstimate);

				//how ElDiff is shown based on cba settings
				_shownDifference = [-_Difference, _Difference] select RC_Arty_EL_Diff;

				_targetVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (AGLtoASL _targetPos);
				_targetAzimuth = ((_targetVector select 0) atan2 (_targetVector select 1));
				_targetAzimuth = [_targetAzimuth mod 360, 360 + _targetAzimuth] select (_targetAzimuth < 0);
				_targetAzimuth = SLANT_ANGLE * _targetAzimuth;

				// Velocity of the Round
				_roundVelocity = getNumber (_weaponConfig >> _currentFireMode >> "artilleryCharge") * getNumber (configFile >> "CfgMagazines" >> (currentMagazine _uav) >> "initSpeed");

				_ctrlDistance ctrlSetText Format ["DIST: %1", [_targetDistance, 4, 0] call CBA_fnc_formatNumber];
				if (_hasTargetSelected && (_selectedTargetDistance >= 20)) then {
					_ctrlTarget ctrlSetText "T: Datalink";
				} else {
					_ctrlTarget ctrlSetText Format ["T: %1", [RC_Current_Target select 0, 2, 0] call CBA_fnc_formatNumber];
				};

				_ctrlTargetAzimuth ctrlSetText Format ["T AZ: %1", [_targetAzimuth, 4, 0] call CBA_fnc_formatNumber];
				_ctrlDifference ctrlSetText Format ["DIF: %1", [_shownDifference, 4, 0] call CBA_fnc_formatNumber];

				/* Calculate angles */
				_preAngle = sqrt ((_roundVelocity^4) - GRAVITY * (GRAVITY * (_targetDistance^2) + 2 * _realElevationOriginal * _roundVelocity^2));
				_preSol = sqrt ((_roundVelocity^4) - (GRAVITY * ((2 * (_roundVelocity^2) * _Difference) + (GRAVITY * (_targetDistance^2)))));

				/* Calculate Marker High Angle */
				_calcHigh = atan (((_roundVelocity^2) + _preAngle) / (GRAVITY * _targetDistance));
				_calcHigh = round (_calcHigh * 100) / 100;
				_highAngleSol = (3200 * atan (((_roundVelocity^2) + _preSol) / (GRAVITY * _targetDistance))) / pi / MAGIC_CONSTANT;
				_travelTimeHigh = round ((2 * _roundVelocity) * (sin _calcHigh)) / GRAVITY;
				
				/* Calculate Marker Low Angle */
				_calcLow = atan (((_roundVelocity^2) - _preAngle) / (GRAVITY * _targetDistance));
				_calcLow = round (_calcLow * 100) / 100;
				_lowAngleSol = (3200 * atan (((_roundVelocity^2) - _preSol) / (GRAVITY * _targetDistance))) / pi / MAGIC_CONSTANT;
				_travelTimeLow = round (((2 * _roundVelocity) * (sin _calcLow)) / GRAVITY);
				
				/* Set color for elevation ctrl */
				private _differenceHighAngle = abs (_highAngleSol - _realElevation);
				private _differenceLowAngle = abs (_lowAngleSol - _realElevation);
				private _color = [COLOR_ON_TARGET, COLOR_CLOSE_TARGET, 0.12, (_differenceHighAngle min _differenceLowAngle) min 10] call BIS_fnc_interpolateVector;
				_ctrlElevation ctrlSetTextColor ([[1, 1, 1, 1], _color] select ((_differenceHighAngle min _differenceLowAngle) <= 10.0));

				/* Set color for azimuth ctrl */
				private _difference = abs (_targetAzimuth - _realAzimuth);
				private _color = [COLOR_ON_TARGET, COLOR_CLOSE_TARGET, 0.057, _difference min 20] call BIS_fnc_interpolateVector;
				_ctrlAzimuth ctrlSetTextColor ([[1, 1, 1, 1], _color] select (_difference <= 20.0));
				
				// If both are Green we show ready to fire
				if (((ctrlTextColor _ctrlElevation) isEqualTo [0, 1, 0, 1]) and ((ctrlTextColor _ctrlAzimuth) isEqualTo [0, 1, 0, 1])) then {
					_ctrlMessage ctrlSetTextColor [0, 1, 0, 1];
					_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
					_ctrlMessage ctrlSetText "ALIGNED";
				} else {
					_ctrlMessage ctrlSetTextColor [1, 0, 0, 1];
					_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
					_ctrlMessage ctrlSetText "NOT ALIGNED";
				};
				
				// Parse these back to Numbers incase they are NaN
				_highAngleSol = parseNumber str _highAngleSol;
				_lowAngleSol = parseNumber str _lowAngleSol;
				_travelTimeHigh = parseNumber str _travelTimeHigh;
				_travelTimeLow = parseNumber str _travelTimeLow;
	
				// If they were NaN then make them Zero
				if (_highAngleSol < 0) then {
					_highAngleSol = 0;
					_lowAngleSol = 0;
					_travelTimeHigh = 0;
					_travelTimeLow = 0;
				};
			} else {
				//display if no target is available/selected
				//#include "functions\UILoop_includes\notarget_display.sqf"
				#include "\Remote_Controlled_Artillery\functions\UILoop_includes\notarget_display.sqf"
			};
			_ctrlHighSol ctrlShow true;
			_ctrlLowSol ctrlShow true;
			_ctrlHighETA ctrlShow true;
			_ctrlLowETA ctrlShow true;

			//greys out not-advised trajectory for depending on round
			//#include "functions\UILoop_includes\ctrl_display.sqf"
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\ctrl_display.sqf"

			_ctrlCharge ctrlSetText Format ["CH: %1", _realCharge];
			_ctrlAzimuth ctrlSetText Format ["AZ: %1", [_realAzimuth, 4, 0] call CBA_fnc_formatNumber];
			_ctrlElevation ctrlSetText Format ["EL: %1", [_realElevation, 4, 0] call CBA_fnc_formatNumber];
			_ctrlHighSol ctrlSetText Format ["high EL: %1", [_highAngleSol, 4, 0] call CBA_fnc_formatNumber];
			_ctrlLowSol ctrlSetText Format ["low EL: %1", [_lowAngleSol, 4, 0] call CBA_fnc_formatNumber];
			_ctrlHighETA ctrlSetText Format ["ETA: %1", [_travelTimeHigh, 3, 0] call CBA_fnc_formatNumber];
			_ctrlLowETA ctrlSetText Format ["ETA: %1", [_travelTimeLow, 3, 0] call CBA_fnc_formatNumber];
		} else {
			// UI Shouldn't be Shown so we cut it
			"RC_Artillery" cutFadeOut 0;
			RC_InUI = false;
		};
	};
};
