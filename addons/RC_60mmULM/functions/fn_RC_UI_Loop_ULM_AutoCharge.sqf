#include "\Remote_Controlled_Artillery\script_component.hpp"
/*
	This Code is held together by Duct Tape and Hope
	Author: Fluffy, Ascent, Eric

	Description:
	Main Loop to Handle the Calculation and UI of RC Artillery Units
*/

// Need to exit early if we aren't a client
if (!hasInterface) exitWith {};
RC_isULM_AC_Hash = createHashMap;
//other hashmaps already created in mod it depends on


RC_ULM_AC_UI = [] spawn {
	while { true } do {
		sleep 0.1;

		_player = player;
		_vicPlayer = vehicle player;

		if ((_vicPlayer isEqualTo _player) || (cameraView != "GUNNER")) then {
			// UI Shouldn't be Shown so we cut it
			"RC_ULM_AC_Rsc" cutFadeOut 0;
			RC_ULM_AC_InUI = false;
			continue;
		};

		// UAV
		_uav = _vicPlayer;
		// UAV ClassName
		_uavClass = typeOf _uav;
		// See if the vehicle has the isULM property
		private _isULM = RC_isULM_AC_Hash get _uavClass;

		//2 is automatic charge system, venting excess gas to reduce velocity, allowing to always shoot at 45deg
		if (isNil "_isULM") then {
			_isULM = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isULM") == 2;
			RC_isULM_AC_Hash set [_uavClass, _isULM];
		};

		// If it's of Artillery or Mortar Type do da thing
		if (_isULM) then {

			// We are in the UI now
			RC_ULM_AC_InUI = true;
			
			// If our UAV is Autonomous we want to make it not
			// We need to remote exec it since setAutonomous is of Local Effect so it needs to be where the UAV is Local
			//if (isAutonomous _uav) then {[_uav, false] remoteExec ["setAutonomous", _uav];};
			
			// Check if the Display for the UI Exists if not Create it
			if (isNull (uiNamespace getVariable ["RC_ULM_AC_Rsc", displayNull])) then { "RC_ULM_AC_Rsc" cutRsc ["RC_ULM_AC_Rsc", "PLAIN", 0, false] };
			
			disableSerialization;	//what effect does this have again, maybe change location futher down?

			// Get the UI so we can see if it has Distance or not
			_AceUI = uiNamespace getVariable ["ACE_dlgArtillery", displayNull];
			_RCAUI = uiNamespace getVariable ["RCA_ArtyUI", displayNull];
			
			// CBA Option for Allowing the Artillery Computer in RC Artillery UGVs, without ACE its stays on for Mortars (as they dont work manually without ACE atm)
			// Remote Execute this to make it Multiplayer Compatible
			private _ArtyType = RC_ArtyTypeHash get _uavClass;
			if (isNil "_ArtyType") then {
				_ArtyType = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_ArtyType");
				RC_ArtyTypeHash set [_uavClass, _ArtyType];
			};

			//_isAceLoaded = isClass (configFile >> "CfgPatches" >> "ace_main");
			private _isAceLoaded = RC_isAceLoadedHash get _uavClass;
			if (isNil "_isAceLoaded") then {
				_isAceLoaded = isClass (configFile >> "CfgPatches" >> "ace_main");
				RC_isAceLoadedHash set [_uavClass, _isAceLoaded];
			};

			if (shownArtilleryComputer) then {
				if (_isAceLoaded) then {
					if (_ArtyType == 1) then {
						if (!RC_allowPortableMortarComputer) then {
							closeDialog 0;
							hintSilent "vanilla artillery computer disabled by mod settings";
							sleep 2;
							hintSilent "";
						};
					};
				};
			};

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
			
			// Display
			_display = uiNamespace getVariable ["RC_ULM_AC_Rsc", displayNull];

			//weapon informations like charges and current charge
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\weapon_info.sqf"
			private _mediumAngleSol = parseNumber ((_currentFireMode splitString "MIL") select 0);
			private _mediumAngleSol_Deg = (_mediumAngleSol * 360) / 6400;
			private _mediumAngleSol_DegStr = str _mediumAngleSol_Deg;

			// Get Weapon Elevation
			_realElevationOriginal = asin (_weaponDir select 2);
			_realElevation = SLANT_ANGLE * _realElevationOriginal;
	
			// fixes barrel elevation value for static mortars if used on UNEVEN ground
			private _isAceMortar = RC_isAceMortarHash get _uavClass;
			if (isNil "_isAceMortar") then {
				_isAceMortar = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "ace_artillerytables_showGunLaying");
				RC_isAceMortarHash set [_uavClass, _isAceMortar];
			};
			if (_isAceMortar == 2) then {
				//systemchat "_isAceMortar == 2";
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

			//ctrl display, hotkey display, ace adjustable scope hotkey overlap warning
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\ctrl_display.sqf"
			_ctrlMediumSol = _display displayCtrl IDC_MEDSOL;
			_ctrlMediumETA = _display displayCtrl IDC_MEDETA;
			_ctrlMediumMV = _display displayCtrl IDC_MEDMV;

			// checks if shell requires lock before firing to activate guidance
			_currentMag = currentMagazine _uav;
			private _requiresLock = RC_RequiresLockHash get _currentMag;
			if (isNil "_requiresLock") then {
				_requiresLock = (getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_RequiresLock"))==1;
				RC_RequiresLockHash set [_currentMag, _requiresLock];
			};

			//UV Pos
			_artyPos = getPosASL _uav;
			//checks if datalink target is too close (mortar attached to vehicle would not show target markers otherwise, and no lock requirement warning would show for guided)
			_selectedTargetDistance = 1;
			if (cursorTarget isNotEqualto objNull) then { _selectedTargetDistance = (getPosASL cursorTarget) distance2d _artyPos };
			_noTargetOrTargetTooClose = (cursorTarget isEqualto objNull) || (_selectedTargetDistance <= MIN_SELECTED_TARGET_DISTANCE);

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
				//{ (_display displayCtrl _x) ctrlShow _terrainWarning } forEach [1013, 1014];
				{ (_display displayCtrl _x) ctrlShow false } forEach [1013, 1014];
				// Show Lock Requirement Warning when having no Target selected
				{ (_display displayCtrl _x) ctrlShow (_requiresLock && _noTargetOrTargetTooClose) } forEach [1015, 1016];
			};

			// Wrap around
			_realAzimuth = [_realAzimuth mod 360, 360 + _realAzimuth] select (_realAzimuth < 0);
			_realAzimuth = SLANT_ANGLE * _realAzimuth;
			
			/* Declare vars */
			private _travelTimeMedium = 0;
			private _adjustedVelocity = 0;

			// If we actually have a Target (thats not too close)
			if (((cursorTarget isNotEqualto objNull) && { _selectedTargetDistance >= MIN_SELECTED_TARGET_DISTANCE }) || !(RC_Artillery_Markers isEqualTo [])) then {
				if !(RC_Artillery_Markers isEqualTo []) then {

					RC_currentTargetMarker = RC_Artillery_Markers select RC_Current_Index;	//moved from scroll solution to here, to still update when marker name was edited

					if (isNil "RC_currentTargetMarker" || RC_currentTargetMarker isEqualTo []) then {
						RC_currentTargetMarker = RC_Artillery_Markers select 0;
					};
					// Try to see if the Current Target Exists
					_targetExists = RC_Artillery_Markers findIf {
						(_x select 0) == (RC_currentTargetMarker select 0);
					};
					// If the Target can't be found we reset the current target
					if (_targetExists == -1) then {
						RC_Current_Index = 0;
					};
				};

				//ElDiff additions, like muzzle position, and rounds aim above value (airburst & topdown guided)
				#include "\Remote_Controlled_Artillery\functions\UILoop_includes\eldiff_additions.sqf"

				//find if datalink target is selected
				_targetPos = [0,0,0];
				_hasTargetSelected = (cursorTarget isNotEqualto objNull);

				//UV Pos
				_artyPos = getPosASL _uav;
				//Target Pos
				if (_hasTargetSelected && !(_noTargetOrTargetTooClose)) then {
					//_targetPos = getpos cursorTarget;
					_targetPos = getposASL cursorTarget;
				} else {
    				_targetPos = AGLtoASL (markerPos [(RC_currentTargetMarker select 1), true]);
					/*
					_targetPos = markerPos (RC_currentTargetMarker select 1);
					_newTargetASL = getTerrainHeightASL _targetPos;
					_targetPos set [2, _newTargetASL];
					*/
				};

				//Barrel End to Target Distance
				_muzzleFromCenterEstimate = 0;
				
				private _BarrelExtends = RC_BarrelExtendsHash get _uavClass;
				if (isNil "_BarrelExtends") then {
					_BarrelExtends = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelExtends") == 1;
					RC_BarrelExtendsHash set [_uavClass, _BarrelExtends];
				};

				if (_BarrelExtends) then { _muzzleFromCenterEstimate = _BarrelLenght * (cos (_WeaponDirection * 90)) };
				_targetDistance = (round ((_targetPos distance2d _artyPos) - _muzzleFromCenterEstimate)) max 1;

				_Difference = 0;
				//_Difference = ((AGLToASL _targetPos) select 2) + _aimAboveHeight - ((_artyPos select 2) + _muzzleHeightEstimate);
				_Difference = (_targetPos select 2) + _aimAboveHeight - ((_artyPos select 2) + _muzzleHeightEstimate);

				//how ElDiff is shown based on cba settings
				_shownDifference = [-_Difference, _Difference] select RC_Arty_EL_Diff;

				//_targetVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (AGLtoASL _targetPos);
				_targetVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (_targetPos);
				_targetAzimuth = ((_targetVector select 0) atan2 (_targetVector select 1));
				_targetAzimuth = [_targetAzimuth mod 360, 360 + _targetAzimuth] select (_targetAzimuth < 0);
				_targetAzimuth = SLANT_ANGLE * _targetAzimuth;

				//displayed target
				_ctrlDistance ctrlSetText Format ["DIST: %1", [_targetDistance, 4, 0] call CBA_fnc_formatNumber];
				if (_hasTargetSelected && (_selectedTargetDistance >= MIN_SELECTED_TARGET_DISTANCE)) then {
					_ctrlTarget ctrlSetText "T: Datalink";
				} else {
					_ctrlTarget ctrlSetText Format ["T: %1", [RC_currentTargetMarker select 0, 2, 0] call CBA_fnc_formatNumber];
				};
				_ctrlTargetAzimuth ctrlSetText Format ["T AZ: %1", [_targetAzimuth, 4, 0] call CBA_fnc_formatNumber];
				_ctrlDifference ctrlSetText Format ["DIF: %1", [_shownDifference, 4, 0] call CBA_fnc_formatNumber];


				//calulate required velocity to hit target
				private _tanA = tan _mediumAngleSol_Deg;
				private _cosA = cos _mediumAngleSol_Deg;
				private _cosA2 = _cosA * _cosA;

				private _numerator = GRAVITY * (_targetDistance * _targetDistance);
				private _den = (_targetDistance * _tanA) - _difference;
				private _denFactor = 2 * _cosA2 * _den;

				private _insideSqrt = _numerator / _denFactor;
				if (_den > 0 && _denFactor > 0 && _insideSqrt > 0) then {
					_adjustedVelocity = sqrt _insideSqrt;
				};
				//to limit max range
				_roundVelocity = getNumber (configFile >> "CfgMagazines" >> _currentMag >> "initSpeed");
				if (_adjustedVelocity > _roundVelocity) then {
					_adjustedVelocity = -1;
				};
				RC_ULM_Velocity = _adjustedVelocity;	//used for fired EH to adjust velocity (automatic gas vent adjuster)

				/*
				hintSilent format [
					"Debug ballistic calc\n\nR: %1\nh: %2\nangleMils: %3\nangleRad: %4\n tan(angle): %5\n cos^2(angle): %6\n\nnumerator (g*R^2): %7\n_den (R*tan - h): %8\n_denFactor (2*cos^2*_den): %9\ninsideSqrt: %10\ncomputed v: %11",
					_targetDistance, _difference, 800, 45, _tanA, _cosA2,
					_numerator, _den, _denFactor, _insideSqrt, _roundVelocity
				];
				*/

				private _ETA = -1;
				if (_adjustedVelocity > 0) then {

					// Horizontal velocity
					private _vX = _adjustedVelocity * cos _mediumAngleSol_Deg;	
					private _vY = _adjustedVelocity * sin _mediumAngleSol_Deg;

					// Horizontal-only ETA (simpler, if _Difference==0)
					private _ETA_h = _targetDistance / _vX;

					// Full quadratic solution
					private _discriminant = (_vY * _vY) - (2 * GRAVITY * _difference);

					if (_discriminant >= 0) then {
						_ETA = (_vY + sqrt(_discriminant)) / GRAVITY;  // first impact
					};

					// Optional: fallback to horizontal-only if h=0
					if (_difference == 0) then { _ETA = _ETA_h; };
				};
				_travelTimeMedium = _ETA;
				RC_ULM_ETA = _ETA;

				
				// AZ/EL coloring when close to firing solution
				#include "\RC_60mmULM\functions\temporary_coloring_workaround_ULM_AutoCharge.sqf"
				//#include "\Remote_Controlled_Artillery\functions\UILoop_includes\MIL_coloring.sqf"
				
				// shows if its not, almost, or fully aligned
				switch (true) do {
					case(
						(_realElevation < (_mediumAngleSol + 0.5)) and
						(_realElevation > (_mediumAngleSol - 0.5)) and
						(_realAzimuth < (_targetAzimuth + 0.5)) and
						(_realAzimuth > (_targetAzimuth - 0.5))
					): {
						_ctrlMessage ctrlSetTextColor [0,1,0,1];
						_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "ALIGNED";
					};

					case(
						(_realElevation < (_mediumAngleSol + 0.75)) and
						(_realElevation > (_mediumAngleSol - 0.75)) and
						(_realAzimuth < (_targetAzimuth + 0.75)) and
						(_realAzimuth > (_targetAzimuth - 0.75))
					): {
						_ctrlMessage ctrlSetTextColor [1,0.5,0,1];
						_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "NOT ALIGNED";
					};

					default {
						_ctrlMessage ctrlSetTextColor [1,0,0,1];
						_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "NOT ALIGNED";
					};
				};
				
				// Parse these back to Numbers incase they are NaN
				_mediumAngleSol = parseNumber str _mediumAngleSol;
				_travelTimeMedium = parseNumber str _travelTimeMedium;
				_adjustedVelocity = parseNumber str _adjustedVelocity;
	
				// If they were NaN then make them Zero
				if (_mediumAngleSol < 0) then {
					_mediumAngleSol = 0;
					_travelTimeMedium = 0;
					_adjustedVelocity = 0;
				};
			} else {
				//display if no target is available/selected
				//#include "\Remote_Controlled_Artillery\functions\UILoop_includes\notarget_display.sqf"

				// If we don't have any Valid Targets
				_ctrlAzimuth ctrlSetTextColor [1, 1, 1, 1];
				_ctrlElevation ctrlSetTextColor [1, 1, 1, 1];

				_ctrlDistance ctrlSetText "DIST: 0000";
				_ctrlTarget ctrlSetText "T: 0";
				_ctrlTargetAzimuth ctrlSetText "T AZ: 0000";
				_ctrlDifference ctrlSetText "DIF: 0000" ;
				_ctrlMediumSol ctrlSetText "med EL: 0000";
				_ctrlMediumETA ctrlSetText "ETA: 000";
				_ctrlMediumMV ctrlSetText "m/s: 000";

				// If we have no Targets
				_ctrlMessage ctrlSetTextColor [1, 0, 0, 1];
				_ctrlMessage ctrlSetPositionX (0.868267 * safezoneW + safezoneX);
				_ctrlMessage ctrlSetText format ["ADD MAP MARKER: %1%2", RC_Marker_Prefix, "1-99 / gps"];
			};
			_ctrlMediumSol ctrlShow true;
			_ctrlMediumETA ctrlShow true;
			_ctrlMediumMV ctrlShow true;

			_ctrlMediumSol ctrlSetTextColor [1, 1, 1, 1];
			_ctrlMediumETA ctrlSetTextColor [1, 1, 1, 1];
			_ctrlMediumMV ctrlSetTextColor [1, 1, 1, 1];

			_ctrlCharge ctrlSetText Format ["A: %1", _mediumAngleSol_DegStr + "°"];
			//_ctrlCharge ctrlSetText Format ["CH: %1", _realCharge];
			_ctrlAzimuth ctrlSetText Format ["AZ: %1", [_realAzimuth, 4, 0] call CBA_fnc_formatNumber];
			_ctrlElevation ctrlSetText Format ["EL: %1", [_realElevation, 4, 0] call CBA_fnc_formatNumber];

			if (_mediumAngleSol isEqualType 0) then {
				_ctrlMediumSol ctrlSetText Format ["med EL: %1", [_mediumAngleSol, 4, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlMediumSol ctrlSetText Format ["med EL: 0000%1"];
			};

			if (_travelTimeMedium isEqualType 0) then {
				_ctrlMediumETA ctrlSetText Format ["ETA: %1", [_travelTimeMedium, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlMediumETA ctrlSetText Format ["ETA: 000%1"];
			};

			if (_adjustedVelocity isEqualType 0) then {
				_ctrlMediumMV ctrlSetText Format ["m/s: %1", [_adjustedVelocity, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlMediumMV ctrlSetText Format ["m/s: 000%1"];
			};
		};
	};
};
