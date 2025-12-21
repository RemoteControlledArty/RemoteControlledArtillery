#include "\Remote_Controlled_Artillery\script_component.hpp"
/*
	This code is held together by duct tape and hope.

	Author: Fluffy, Ascent, Eric

	Description: Main loop to handle the calculation and UI of RC Artillery Units.

	Public: No.
*/

// need to exit early if we aren't a client
if (!hasInterface) exitWith {};

// predefine for fired EH if not yet calulated
RC_ULM_Velocity= 0;
RC_ULM_ETA = 0;

// hashmap to prevent config check spam, other hashmaps already created in mod it depends on
RC_isULM_Hash = createHashMap;

RC_ULM_UI = [] spawn {
	//for gas vent servo sound
	private _prevVelocity = 0;

	while { true } do {
		sleep 0.1;

		private _player = player;
		private _vicPlayer = vehicle player;

		if (_vicPlayer isEqualTo _player) then {
			// UI Shouldn't be Shown so we cut it
			"RC_ULM_Rsc" cutFadeOut 0;
			RC_ULM_InUI = false;
			continue;
		};

		// only named UAV to be more compatible with main mod script components
		private _uav = _vicPlayer;
		// UAV className
		private _uavClass = typeOf _uav;
		// see if the vehicle has the isULM property, 2 is automatic gas vent, altering velocity, allowing to always shoot at 45deg
		private _isULM = RC_isULM_Hash get _uavClass;
		if (isNil "_isULM") then {
			_isULM = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isULM") == 2;
			RC_isULM_Hash set [_uavClass, _isULM];
		};

		if (_isULM && shownArtilleryComputer) then {
			closeDialog 0;
			hintSilent "asset cannot use vanilla artillery computer";
			sleep 2;
			hintSilent "";
		};

		if (cameraView != "GUNNER") then {
			// UI Shouldn't be Shown so we cut it
			"RC_ULM_Rsc" cutFadeOut 0;
			RC_ULM_InUI = false;
			continue;
		};

		// If it's of Artillery or Mortar Type do da thing
		if (_isULM) then {

			// We are in the UI now
			RC_ULM_InUI = true;
			
			// Check if the Display for the UI Exists if not Create it
			if (isNull (uiNamespace getVariable ["RC_ULM_Rsc", displayNull])) then { "RC_ULM_Rsc" cutRsc ["RC_ULM_Rsc", "PLAIN", 0, false] };
			
			// makes script able to use more data types like UI
			disableSerialization;

			// get the UI so we can see if it has distance or not
			private _AceUI = uiNamespace getVariable ["ACE_dlgArtillery", displayNull];
			private _RCAUI = uiNamespace getVariable ["RCA_ArtyUI", displayNull];

			private _RCA_CurrentArtyDisplay = displayNull;
			// if our one is null we use theirs
			_RCA_CurrentArtyDisplay = [_RCAUI, _AceUI] select (isNull _RCAUI);

			// this is the range text
			private _rangeText = ctrlText (_RCA_CurrentArtyDisplay displayCtrl 173);

			// look vector relative to the Camera
			private _lookVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (AGLtoASL (positionCameraToWorld [0, 0, 1]));
			// weapon direction as a relative vector3
			private _weaponDir = _uav weaponDirection (currentWeapon _uav);
			
			// fallback if we are using the mortar and the display isn't working
			if (isNull _RCA_CurrentArtyDisplay) then {
				private _testSeekerPosASL = AGLtoASL (positionCameraToWorld [0,0,0]);
				private _testPoint = _testSeekerPosASL vectorAdd (_lookVector vectorMultiply viewDistance);
    			private _lookingAtGround = !((terrainIntersectASL [_testSeekerPosASL, _testPoint]) || { lineIntersects [_testSeekerPosASL, _testPoint, _uav] });
				
				if (_lookingAtGround) then {
					_rangeText = "--";
				} else {
					_rangeText = "0";
				};
			};
			
			// display
			private _display = uiNamespace getVariable ["RC_ULM_Rsc", displayNull];

			// weapon informations
			#include "\RC_60mmULM\functions\weapon_info_ULM.sqf"

			private _highAngleSol = 1200;
			private _mediumAngleSol = 800;
			private _highAngleSolDeg = (_highAngleSol * 360) / 6400;
			private _mediumAngleSolDeg = (_mediumAngleSol * 360) / 6400;

			// get weapon elevation
			private _realElevationDeg = asin (_weaponDir select 2);
			// degree to MIL
			private _realElevation = SLANT_ANGLE * _realElevationDeg;
	
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
				_realElevationDeg = (acos ((_turretRot vectorCos _weaponDir) min 1)) + ((_turretRot call CBA_fnc_vect2polar) select 2);
				if (_realElevationDeg > 90) then { _realElevationDeg = 180 - _realElevationDeg };
				_realElevation = (SLANT_ANGLE * _realElevationDeg);
			};

			private _currentMag = currentMagazine _uav;

			// ctrl display, hotkey display, ace adjustable scope hotkey overlap warning
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\ctrl_display.sqf"
			_ctrlMediumSol = _display displayCtrl IDC_MEDSOL;
			_ctrlHighSol = _display displayCtrl IDC_HIGHSOL;
			_ctrlMediumETA = _display displayCtrl IDC_MEDETA;
			_ctrlHighETA = _display displayCtrl IDC_HIGHETA;
			_ctrlHighMV = _display displayCtrl IDC_HIGHMV;
			_ctrlMediumMV = _display displayCtrl IDC_MEDMV;
			_ctrlNewTarget = _display displayCtrl IDC_NEWTARGET;

			// checks if shell requires lock before firing to activate guidance
			private _requiresLock = RC_requiresLockHash get _currentMag;
			if (isNil "_requiresLock") then {
				_requiresLock = (getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_RequiresLock"))==1;
				RC_requiresLockHash set [_currentMag, _requiresLock];
			};

			// UV pos (above sea level)
			private _artyPos = getPosASL _uav;
			// checks if datalink target is too close (mortar attached to vehicle would not show target markers otherwise, and no lock requirement warning would show for guided)
			private _selectedTargetDistance = 1;
			private _lockedTarget = playerTargetLock#0;
			private _ULM_minDist = 20;

			if (_lockedTarget isNotEqualto objNull) then { _selectedTargetDistance = (getPosASL _lockedTarget) distance2d _artyPos };
			private _noTargetOrTargetTooClose = (_lockedTarget isEqualto objNull) || (_selectedTargetDistance <= _ULM_minDist);

			// if we are looking into the sky
			private _realAzimuth = 0;
			if (_rangeText isEqualTo "--") then {
				// use the weapon dir
				_realAzimuth = ((_weaponDir select 0) atan2 (_weaponDir select 1));
				// hide submunition warning when looking at the sky
				{ (_display displayCtrl _x) ctrlShow false } forEach [1013, 1014];
				// show lock requirement warning when having no target selected
				{ (_display displayCtrl _x) ctrlShow (_requiresLock && _noTargetOrTargetTooClose) } forEach [1015,1016];
			} else {
				// else use the look vector
				_realAzimuth = ((_lookVector select 0) atan2 (_lookVector select 1));
				// show submunition warning when looking at terrain
				//{ (_display displayCtrl _x) ctrlShow _terrainWarning } forEach [1013, 1014];	//not needed for ULM ammo
				{ (_display displayCtrl _x) ctrlShow false } forEach [1013, 1014];
				// show lock requirement warning when having no target selected
				{ (_display displayCtrl _x) ctrlShow (_requiresLock && _noTargetOrTargetTooClose) } forEach [1015, 1016];
			};

			// wrap around
			_realAzimuth = [_realAzimuth mod 360, 360 + _realAzimuth] select (_realAzimuth < 0);
			// degree to MIL
			_realAzimuth = SLANT_ANGLE * _realAzimuth;
			
			// declare vars
			private _travelTimeMedium = 0;
			private _travelTimeHigh = 0;
			private _adjustedVelocity = 0;
			private _adjustedVelocityMedium = 0;
			private _adjustedVelocityHigh = 0;

			// if we actually have a target (thats not too close)
			if (((_lockedTarget isNotEqualto objNull) && { _selectedTargetDistance >= _ULM_minDist }) || !(RC_Artillery_Markers isEqualTo [])) then {
				if !(RC_Artillery_Markers isEqualTo []) then {

					RC_currentTargetMarker = RC_Artillery_Markers select RC_Current_Index;	//moved from scroll solution to here, to still update when marker name was edited

					if (isNil "RC_currentTargetMarker" || RC_currentTargetMarker isEqualTo []) then {
						RC_currentTargetMarker = RC_Artillery_Markers select 0;
					};
					// try to see if the current target exists
					private _targetExists = RC_Artillery_Markers findIf {
						(_x select 0) == (RC_currentTargetMarker select 0);
					};
					// if the target can't be found we reset the current target
					if (_targetExists == -1) then {
						RC_Current_Index = 0;
					};
				};

				// ElDiff additions, like muzzle position, and rounds aim above value (airburst, topdown guided, illum)
				//#include "\Remote_Controlled_Artillery\functions\UILoop_includes\eldiff_additions.sqf"
				private _muzzleHeightEstimate = 0.5;
				private _aimAboveHeight = RC_aimAboveHeightHash get _currentMag;
				if (isNil "_aimAboveHeight") then {
					_aimAboveHeight = getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_AimAboveHeight");
					RC_aimAboveHeightHash set [_currentMag, _aimAboveHeight];
				};

				// find if datalink target is selected
				private _targetPos = [0,0,0];
				private _hasTargetSelected = (_lockedTarget isNotEqualto objNull);

				// UV pos (above sea level)
				private _artyPos = getPosASL _uav;
				// target pos (above sea level)
				if (_hasTargetSelected && !(_noTargetOrTargetTooClose)) then {
					_targetPos = getposASL _lockedTarget;
				} else {
    				_targetPos = AGLtoASL (markerPos [(RC_currentTargetMarker select 1), true]);
					/*
					_targetPos = markerPos (RC_currentTargetMarker select 1);
					_newTargetASL = getTerrainHeightASL _targetPos;
					_targetPos set [2, _newTargetASL];
					*/
				};

				// barrel end to target distance
				private _muzzleFromCenterEstimate = 0;
				
				/*
				private _BarrelExtends = RC_barrelExtendsHash get _uavClass;
				if (isNil "_BarrelExtends") then {
					_BarrelExtends = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelExtends") == 1;
					RC_barrelExtendsHash set [_uavClass, _BarrelExtends];
				};

				if (_BarrelExtends) then { _muzzleFromCenterEstimate = _BarrelLenght * (cos (_WeaponDirection * 90)) };
				_distance = (round ((_targetPos distance2d _artyPos) - _muzzleFromCenterEstimate)) max 1;
				*/

				// distance from of UV muzzle and target
				private _distance = (round (_targetPos distance2d _artyPos)) max 1;

				// height difference of UV muzzle to aimpoint
				private _difference = 0;
				_difference = (_targetPos select 2) + _aimAboveHeight - ((_artyPos select 2) + _muzzleHeightEstimate);
				//how ElDiff is shown based on cba settings
				private _shownDifference = [-_difference, _difference] select RC_Arty_EL_Diff;

				// turret azimuth
				private _targetVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (_targetPos);
				private _targetAzimuth = ((_targetVector select 0) atan2 (_targetVector select 1));
				_targetAzimuth = [_targetAzimuth mod 360, 360 + _targetAzimuth] select (_targetAzimuth < 0);
				_targetAzimuth = SLANT_ANGLE * _targetAzimuth;

				// displayed target
				_ctrlDistance ctrlSetText Format ["DIST: %1", [_distance, 4, 0] call CBA_fnc_formatNumber];
				if (_hasTargetSelected && (_selectedTargetDistance >= _ULM_minDist)) then {
					_ctrlNewTarget ctrlSetText "T: Datalink";
				} else {
					_ctrlNewTarget ctrlSetText Format ["T: %1", [RC_currentTargetMarker select 0, 2, 0] call CBA_fnc_formatNumber];
				};
				_ctrlTargetAzimuth ctrlSetText Format ["T AZ: %1", [_targetAzimuth, 4, 0] call CBA_fnc_formatNumber];
				_ctrlDifference ctrlSetText Format ["DIF: %1", [_shownDifference, 4, 0] call CBA_fnc_formatNumber];


				// speed of the round, defines max range
				private _magSpeed = RC_magSpeedHash get _currentMag;
				if (isNil "_magSpeed") then {
					_magSpeed = getNumber (configFile >> "CfgMagazines" >> _currentMag >> "initSpeed");
					RC_magSpeedHash set [_currentMag, _magSpeed];
				};
				private _speed = _magSpeed;		//private _speed = _magSpeed * (getNumber (_weaponConfig >> _currentFireMode >> "artilleryCharge"));	//maybe more modular?

				// calulate required velocity to hit target using medium angle
				private _tanA_M = tan _mediumAngleSolDeg;
				private _cosA_M = cos _mediumAngleSolDeg;
				private _cosA2_M = _cosA_M * _cosA_M;

				private _numerator_M = GRAVITY * (_distance * _distance);
				private _den_M = (_distance * _tanA_M) - _difference;
				private _denFactor_M = 2 * _cosA2_M * _den_M;

				private _insideSqrt_M = _numerator_M / _denFactor_M;
				if (_den_M > 0 && _denFactor_M > 0 && _insideSqrt_M > 0) then {
					_adjustedVelocityMedium = sqrt _insideSqrt_M;
				};
				// to limit max range
				if (_adjustedVelocityMedium > _speed) then {
					_adjustedVelocityMedium = 0;
				};

				// calulate required velocity to hit target using high angle
				private _tanA_H = tan _highAngleSolDeg;
				private _cosA_H = cos _highAngleSolDeg;
				private _cosA2_H = _cosA_H * _cosA_H;

				private _numerator_H = GRAVITY * (_distance * _distance);
				private _den_H = (_distance * _tanA_H) - _difference;
				private _denFactor_H = 2 * _cosA2_H * _den_H;

				private _insideSqrt_H = _numerator_H / _denFactor_H;
				if (_den_H > 0 && _denFactor_H > 0 && _insideSqrt_H > 0) then {
					_adjustedVelocityHigh = sqrt _insideSqrt_H;
				};
				// to limit max range
				if (_adjustedVelocityHigh > _speed) then {
					_adjustedVelocityHigh = 0;
				};

				/*
				hintSilent format [
					"Debug ballistic calc\n\nR: %1\nh: %2\nangleMils: %3\nangleRad: %4\n tan(angle): %5\n cos^2(angle): %6\n\nnumerator (g*R^2): %7\n_den (R*tan - h): %8\n_denFactor (2*cos^2*_den): %9\ninsideSqrt: %10\ncomputed v: %11",
					_distance, _difference, 800, 45, _tanA, _cosA2,
					_numerator, _den, _denFactor, _insideSqrt, _speed
				];
				*/

				// ETA				
				//"_diff is needed if the target is higher or lower than the height already IMPLIED by the given angle, or if the given angle is arbitrary."
				//"_diff exists to handle targets at different heights than the given angle already IMPLIES."
				if (_adjustedVelocityMedium > 0) then {

					// horizontal velocity
					private _vX = _adjustedVelocityMedium * cos _mediumAngleSolDeg;	
					private _vY = _adjustedVelocityMedium * sin _mediumAngleSolDeg;

					// horizontal-only ETA (simpler, if _difference==0)
					private _travelTimeMedium_h = _distance / _vX;

					// full quadratic solution
					private _discriminant = (_vY * _vY) - (2 * GRAVITY * _difference);

					if (_discriminant >= 0) then {
						_travelTimeMedium = (_vY + sqrt(_discriminant)) / GRAVITY;  // first impact
					};

					// optional: fallback to horizontal-only if h=0
					if (_difference == 0) then { _travelTimeMedium = _travelTimeMedium_h; };
				};

				if (_adjustedVelocityHigh > 0) then {

					private _vX = _adjustedVelocityHigh * cos _highAngleSolDeg;	
					private _vY = _adjustedVelocityHigh * sin _highAngleSolDeg;

					private _travelTimeHigh_h = _distance / _vX;

					private _discriminant = (_vY * _vY) - (2 * GRAVITY * _difference);

					if (_discriminant >= 0) then {
						_travelTimeHigh = (_vY + sqrt(_discriminant)) / GRAVITY;  // first impact
					};

					if (_difference == 0) then { _travelTimeHigh = _travelTimeHigh_h; };
				};

				/*
				// ETA, correct formula but somehow display result jitters from correct to wrong
				if (_adjustedVelocityMedium > 0) then {
					_travelTimeMedium = _distance / (_speed * cos _mediumAngleSolDeg);
				};
				if (_adjustedVelocityHigh > 0) then {
					_travelTimeHigh = _distance / (_speed * cos _highAngleSolDeg);
				};
				*/

				// decides based on angle which velocity adjustment is used
				private _usingMediumAngle = (abs (_realElevation - _mediumAngleSol)) < (abs (_realElevation - _highAngleSol));
				if (_usingMediumAngle) then {
					// used for fired EH to adjust velocity (automatic gas vent adjuster)
					RC_ULM_Velocity = _adjustedVelocityMedium;
					// used for fired EH for ETA message
					RC_ULM_ETA = _travelTimeMedium;

					// gas vent servo sound if new target selected
					if ((_adjustedVelocityMedium != 0) && (RC_ULM_Velocity != _prevVelocity)) then {
						//fix for MP
						//playSound3D ["a3\sounds_f_enoch\assets\vehicles\ugv_02\ugv_02_servo_01.wss", _uav, false, getPosASL _uav, 5, 1.75, 6, 23.5, true];
						_prevVelocity = RC_ULM_Velocity;
					};
				} else {
					RC_ULM_Velocity = _adjustedVelocityHigh;
					RC_ULM_ETA = _travelTimeHigh;

					if ((_adjustedVelocityHigh != 0) && (RC_ULM_Velocity != _prevVelocity)) then {
						//fix for MP
						//playSound3D ["a3\sounds_f_enoch\assets\vehicles\ugv_02\ugv_02_servo_01.wss", _uav, false, getPosASL _uav, 5, 1.75, 6, 23.5, true];
						_prevVelocity = RC_ULM_Velocity;
					};
				};

				// set backup guided trigger timer, used in fired EH, calculated by actually used elevation not recommended one
				private _lockedGuided = false;
				_lockedGuided = _requiresLock && _hasTargetSelected && (!(_noTargetOrTargetTooClose));
				//private _triggerDistance = 0;
				
				if (_lockedGuided) then {
					// checks if horizontal velocity > 0 to prevent division by 0
					private _horVel = (RC_ULM_Velocity * cos _realElevationDeg);

					if (_horVel > 0) then {
						RC_GuidedTriggerTime = _distance / _horVel;
					} else {
						//ignored by fired EH
						RC_GuidedTriggerTime = 0;
					};

					/*
					// get triggerDistance to warn in aligned_coloring if too close
					_triggerDistance = RC_triggerDistanceHash get _currentMag;
					if (isNil "_triggerDistance") then {
						_triggerDistance = getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_triggerDistance");
						RC_triggerDistanceHash set [_currentMag, _triggerDistance];
					};
					*/
				} else {
					RC_GuidedTriggerTime = 0;
				};
				
				// AZ/EL coloring when close to firing solution
				#include "\RC_60mmULM\functions\MIL_coloring_ULM.sqf"
				// shows if its not, almost, or fully aligned
				#include "\RC_60mmULM\functions\aligned_coloring_ULM.sqf"
				
				// parse these back to numbers incase they are NaN
				_travelTimeMedium = parseNumber str _travelTimeMedium;
				_travelTimeHigh = parseNumber str _travelTimeHigh;
				_adjustedVelocityHigh = parseNumber str _adjustedVelocityHigh;
				_adjustedVelocityMedium = parseNumber str _adjustedVelocityMedium;
				
			} else {
				// display if no target is available/selected
				#include "\RC_60mmULM\functions\notarget_display_ULM.sqf"
			};
			_ctrlHighSol ctrlShow true;
			_ctrlMediumSol ctrlShow true;
			_ctrlHighETA ctrlShow true;
			_ctrlMediumETA ctrlShow true;
			_ctrlHighMV ctrlShow true;
			_ctrlMediumMV ctrlShow true;

			if (_adjustedVelocityHigh > 0) then {
				_ctrlHighSol ctrlSetTextColor [1, 1, 1, 1]; 
				_ctrlHighETA ctrlSetTextColor [1, 1, 1, 1]; 
				_ctrlHighMV ctrlSetTextColor [1, 1, 1, 1];
			} else {
				_ctrlHighSol ctrlSetTextColor [0.5, 0.5, 0.5, 0.5]; 
				_ctrlHighETA ctrlSetTextColor [0.5, 0.5, 0.5, 0.5]; 
				_ctrlHighMV ctrlSetTextColor [0.5, 0.5, 0.5, 0.5];
			};
			
			if (_adjustedVelocityMedium > 0) then {
				_ctrlMediumSol ctrlSetTextColor [1, 1, 1, 1]; 
				_ctrlMediumETA ctrlSetTextColor [1, 1, 1, 1]; 
				_ctrlMediumMV ctrlSetTextColor [1, 1, 1, 1];
			} else {
				_ctrlMediumSol ctrlSetTextColor [0.5, 0.5, 0.5, 0.5]; 
				_ctrlMediumETA ctrlSetTextColor [0.5, 0.5, 0.5, 0.5]; 
				_ctrlMediumMV ctrlSetTextColor [0.5, 0.5, 0.5, 0.5];
			};

			// wrong check?
			if (_adjustedVelocityHigh isEqualType 0) then {
				_ctrlHighMV ctrlSetText Format ["MV: %1", [_adjustedVelocityHigh, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlHighMV ctrlSetText Format ["MV: 000%1"];
			};
			if (_adjustedVelocityMedium isEqualType 0) then {
				_ctrlMediumMV ctrlSetText Format ["MV: %1", [_adjustedVelocityMedium, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlMediumMV ctrlSetText Format ["MV: 000%1"];
			};

			_ctrlAzimuth ctrlSetText Format ["AZ: %1", [_realAzimuth, 4, 0] call CBA_fnc_formatNumber];
			_ctrlElevation ctrlSetText Format ["EL: %1", [_realElevation, 4, 0] call CBA_fnc_formatNumber];

			if (_mediumAngleSol isEqualType 0) then {
				_ctrlMediumSol ctrlSetText Format ["med EL: %1", [_mediumAngleSol, 4, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlMediumSol ctrlSetText Format ["med EL: 0000%1"];
			};
			if (_highAngleSol isEqualType 0) then {
				_ctrlHighSol ctrlSetText Format ["high EL: %1", [_highAngleSol, 4, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlHighSol ctrlSetText Format ["high EL: 0000%1"];
			};

			if (_travelTimeMedium isEqualType 0) then {
				_ctrlMediumETA ctrlSetText Format ["ETA: %1", [_travelTimeMedium, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlMediumETA ctrlSetText Format ["ETA: 000%1"];
			};
			if (_travelTimeHigh isEqualType 0) then {
				_ctrlHighETA ctrlSetText Format ["ETA: %1", [_travelTimeHigh, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlHighETA ctrlSetText Format ["ETA: 000%1"];
			};
		};
	};
};