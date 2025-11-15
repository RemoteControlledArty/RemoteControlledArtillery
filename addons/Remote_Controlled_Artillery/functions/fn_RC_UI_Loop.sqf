#include "script_component.hpp"
/*
	This Code is held together by Duct Tape and Hope
	Author: Fluffy, Ascent, Eric

	Description:
	Main Loop to Handle the Calculation and UI of RC Artillery Units
*/

// Need to exit early if we aren't a client
if (!hasInterface) exitWith {};

//general hashmaps
RC_isAceLoadedHash = createHashMap;

//vehicle hashmaps
//RC_localizeHash = createHashMap;	//not yet used
RC_isRCArtyHash = createHashMap;
RC_artyTypeHash = createHashMap;
RC_isAceMortarHash = createHashMap;
RC_barrelAGLHash = createHashMap;
RC_barrelLenghtHash = createHashMap;
RC_barrelExtendsHash = createHashMap;

//weapon hashmaps
RC_weaponConfig = createHashMap;
RC_fireModes = createHashMap;

//magazine hashmaps
RC_magSpeedHash = createHashMap;
RC_advisedTrajectoryHash = createHashMap;
RC_requiresLockHash = createHashMap;
RC_terrainWarningHash = createHashMap;
RC_aimAboveHeightHash = createHashMap;

RC_Artillery_UI = [] spawn {
	while { true } do {
		sleep 0.1;

		if !(isRemoteControlling player) then {
			// UI shouldn't be shown so we cut it
			"RC_Artillery" cutFadeOut 0;
			RC_InUI = false;
			continue;
		};

		// UAV
		private _uav = getConnectedUAV player;
		// UAV className
		private _uavClass = typeOf _uav;
		// see if the vehicle has the isRCArty property
		private _isRCArty = RC_isRCArtyHash get _uavClass;
		if (isNil "_isRCArty") then {
			_isRCArty = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isRCArty") == 1;
			RC_isRCArtyHash set [_uavClass, _isRCArty];
		};

		// if it's of artillery or mortar type do da thing
		if (_isRCArty) then {
			
			// We are in the UI now
			RC_InUI = true;
			
			// if our UAV is autonomous we want to make it not for the barrel alignment not to reset when releasing control
			// we need to remote exec it since setAutonomous is of local effect so it needs to be where the UAV is local
			// isAutonomous check fixed my prior performance concerns
			if (isAutonomous _uav) then {[_uav, false] remoteExec ["setAutonomous", _uav];};
			
			// check if the Display for the UI Exists if not create it
			if (isNull (uiNamespace getVariable ["RC_Artillery", displayNull])) then { "RC_Artillery" cutRsc ["RC_Artillery", "PLAIN", 0, false] };
			
			disableSerialization;	//what effect does this have again, maybe change location futher down?

			// get the UI so we can see if it has Distance or not
			private _AceUI = uiNamespace getVariable ["ACE_dlgArtillery", displayNull];
			private _RCAUI = uiNamespace getVariable ["RCA_ArtyUI", displayNull];
			
			// CBA Option for Allowing the Artillery Computer in RC Artillery UGVs, without ACE its stays on for Mortars (as they dont work manually without ACE atm)
			// Remote Execute this to make it Multiplayer Compatible
			private _ArtyType = RC_artyTypeHash get _uavClass;
			if (isNil "_ArtyType") then {
				_ArtyType = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_ArtyType");
				RC_artyTypeHash set [_uavClass, _ArtyType];
			};

			//_isAceLoaded = isClass (configFile >> "CfgPatches" >> "ace_main");
			private _isAceLoaded = RC_isAceLoadedHash get _uavClass;
			if (isNil "_isAceLoaded") then {
				_isAceLoaded = isClass (configFile >> "CfgPatches" >> "ace_main");
				RC_isAceLoadedHash set [_uavClass, _isAceLoaded];
			};

			if (shownArtilleryComputer) then {
				if (_isAceLoaded) then {
					switch (true) do {
						case(_ArtyType == 1): {
							if (!RC_allowPortableMortarComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};
						case(_ArtyType == 2): {
							if (!RC_allowVehicleMortarComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};
						case(_ArtyType == 3): {
							if (!RC_allowHowitzerComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};
						case(_ArtyType == 4): {
							if (!RC_allowMLRSComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};

						//default {};
					};
				} else {
					switch (true) do {
						//mortars dont work correctly without ace
						/*
						case(_ArtyType == 1): {
							if (RC_allowPortableMortarComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};
						case(_ArtyType == 2): {
							if (RC_allowVehicleMortarComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};
						*/
						case(_ArtyType == 3): {
							if (!RC_allowHowitzerComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};
						case(_ArtyType == 4): {
							if (!RC_allowMLRSComputer) then {
								closeDialog 0;
								hintSilent "vanilla artillery computer disabled by mod settings";
								sleep 2;
								hintSilent "";
							};
						};

						//default {};
					};
				};
			};

			private _RCA_CurrentArtyDisplay = displayNull;
			// If our one is Null we use theirs
			_RCA_CurrentArtyDisplay = [_RCAUI, _AceUI] select (isNull _RCAUI);

			// This is the Range Text
			private _rangeText = ctrlText (_RCA_CurrentArtyDisplay displayCtrl 173);

			// Look Vector relative to the Camera
			private _lookVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (AGLtoASL (positionCameraToWorld [0, 0, 1]));
			private _weaponDir = _uav weaponDirection (currentWeapon _uav); // Weapon direction as a Relative Vector3
			
			// Fallback if we are using the Mortar and the Display isn't working
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
			
			// Display
			private _display = uiNamespace getVariable ["RC_Artillery", displayNull];

			//weapon informations like charges and current charge
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\weapon_info.sqf"

			// Get Weapon Elevation
			private _realElevationOriginal = asin (_weaponDir select 2);
			private _realElevation = SLANT_ANGLE * _realElevationOriginal;
	
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

			//changes magazine to backup airburst if EL is too low for conventional airburst
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\AB_magchange.sqf"

			//ctrl display, hotkey display, ace adjustable scope hotkey overlap warning
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\ctrl_display.sqf"

			// checks if shell requires lock before firing to activate guidance
			private _requiresLock = RC_RequiresLockHash get _currentMag;
			if (isNil "_requiresLock") then {
				_requiresLock = (getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_RequiresLock"))==1;
				RC_RequiresLockHash set [_currentMag, _requiresLock];
			};
			
			// checks if camera needs to be raised into sky to not deploy submunitions too early
			private _terrainWarning = RC_TerrainWarningHash get _currentMag;
			if (isNil "_terrainWarning") then {
				_terrainWarning = (getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_TerrainWarning"))==1;
				RC_TerrainWarningHash set [_currentMag, _terrainWarning];
			};

			//UV Pos
			private _artyPos = getPosASL _uav;
			//checks if datalink target is too close (mortar attached to vehicle would not show target markers otherwise, and no lock requirement warning would show for guided)
			private _selectedTargetDistance = 1;
			if (cursorTarget isNotEqualto objNull) then { _selectedTargetDistance = (getPosASL cursorTarget) distance2d _artyPos };
			private _noTargetOrTargetTooClose = (cursorTarget isEqualto objNull) || (_selectedTargetDistance <= MIN_SELECTED_TARGET_DISTANCE);

			// If we are looking into the Sky
			private _realAzimuth = 0; //previously private "_realAzimuth";
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
			
			// declare vars
			private _highAngleSol = 0;
			private _travelTimeHigh = 0;
			private _lowAngleSol = 0;
			private _travelTimeLow = 0;

			// if we actually have a target (thats not too close)
			if (((cursorTarget isNotEqualto objNull) && { _selectedTargetDistance >= MIN_SELECTED_TARGET_DISTANCE }) || !(RC_Artillery_Markers isEqualTo [])) then {
				if !(RC_Artillery_Markers isEqualTo []) then {

					RC_currentTargetMarker = RC_Artillery_Markers select RC_Current_Index;	//moved from scroll solution to here, to still update when marker name was edited

					if (isNil "RC_currentTargetMarker" || RC_currentTargetMarker isEqualTo []) then {
						RC_currentTargetMarker = RC_Artillery_Markers select 0;
					};
					// try to see if the current target exists
					_targetExists = RC_Artillery_Markers findIf {
						(_x select 0) == (RC_currentTargetMarker select 0);
					};
					// if the target can't be found we reset the current target
					if (_targetExists == -1) then {
						RC_Current_Index = 0;
					};
				};

				// ElDiff additions, like muzzle position, and rounds aim above value (airburst & topdown guided)
				#include "\Remote_Controlled_Artillery\functions\UILoop_includes\eldiff_additions.sqf"

				// find if datalink target is selected
				private _targetPos = [0, 0, 0];
				private _hasTargetSelected = (cursorTarget isNotEqualto objNull);

				// target pos
				if (_hasTargetSelected && !(_noTargetOrTargetTooClose)) then {
					_targetPos = getposASL cursorTarget;
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
				
				private _barrelExtends = RC_barrelExtendsHash get _uavClass;
				if (isNil "_barrelExtends") then {
					_barrelExtends = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_BarrelExtends") == 1;
					RC_barrelExtendsHash set [_uavClass, _barrelExtends];
				};

				if (_barrelExtends) then { _muzzleFromCenterEstimate = _barrelLenght * (cos (_weaponDirection * 90)) };
				private _distance = (round ((_targetPos distance2d _artyPos) - _muzzleFromCenterEstimate)) max 1;

				private _difference = 0;
				_difference = (_targetPos select 2) + _aimAboveHeight - ((_artyPos select 2) + _muzzleHeightEstimate);

				// how ElDiff is shown based on cba settings
				private _shownDifference = [-_difference, _difference] select RC_Arty_EL_Diff;

				// _targetVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (AGLtoASL _targetPos);
				private _targetVector = (AGLtoASL (positionCameraToWorld [0, 0, 0])) vectorFromTo (_targetPos);
				private _targetAzimuth = ((_targetVector select 0) atan2 (_targetVector select 1));
				_targetAzimuth = [_targetAzimuth mod 360, 360 + _targetAzimuth] select (_targetAzimuth < 0);
				_targetAzimuth = SLANT_ANGLE * _targetAzimuth;

				// speed of the round
				private _magSpeed = RC_magSpeedHash get (typeOf _currentMag);
				if (isNil "_magSpeed") then {
					_magSpeed = getNumber (configFile >> "CfgMagazines" >> _uavClass >> "initSpeed");
					RC_magSpeedHash set [_uavClass, _magSpeed];
				};
				private _speed = _magSpeed * (getNumber (_weaponConfig >> _currentFireMode >> "artilleryCharge"));

				// displayed target
				_ctrlDistance ctrlSetText Format ["DIST: %1", [_distance, 4, 0] call CBA_fnc_formatNumber];
				if (_hasTargetSelected && (_selectedTargetDistance >= MIN_SELECTED_TARGET_DISTANCE)) then {
					_ctrlTarget ctrlSetText "T: Datalink";
				} else {
					_ctrlTarget ctrlSetText Format ["T: %1", [RC_currentTargetMarker select 0, 2, 0] call CBA_fnc_formatNumber];
				};
				_ctrlTargetAzimuth ctrlSetText Format ["T AZ: %1", [_targetAzimuth, 4, 0] call CBA_fnc_formatNumber];
				_ctrlDifference ctrlSetText Format ["DIF: %1", [_shownDifference, 4, 0] call CBA_fnc_formatNumber];


				// precalculation
				_privatePreSol = sqrt (_speed^2 * (_speed^2 - 2 * GRAVITY * _difference) - GRAVITY^2 * _distance^2);	//((_speed^4) - (GRAVITY * ((2 * (_speed^2) * _difference) + (GRAVITY * (_distance^2)))));

				// required launch angles to hit target (aka firing solution), in degrees
				_highAngleSolDeg = atan(((_speed^2) + _privatePreSol) / (GRAVITY * _distance));
				_lowAngleSolDeg  = atan(((_speed^2) - _privatePreSol) / (GRAVITY * _distance));

				// travel time using degrees
				_travelTimeHigh = _distance / (_speed * cos _highAngleSolDeg);
				_travelTimeLow  = _distance / (_speed * cos _lowAngleSolDeg);

				// degree to MIL conversion, with horizontal being 0
				_highAngleSol = _highAngleSolDeg * (6400/360);
				_lowAngleSol = _lowAngleSolDeg * (6400/360);

				/*
				_debugStr = format [
					"%1 m/s   %2 mHor   %3 mVer   %4 m/s  /  %5 Deg   %6 MIL   %7 s  /  %8 Deg   %9 MIL   %10 s",
					round _speed, round _distance, round _difference, round GRAVITY,
					_highAngleSolDeg, _highAngleSol, round _travelTimeHigh,
					_lowAngleSolDeg, _lowAngleSol, round _travelTimeLow
				];
				systemChat _debugStr;
				*/

				// set backup guided trigger timer, used in fired EH
				private _lockedGuided = _requiresLock && _hasTargetSelected && !_noTargetOrTargetTooClose;
				if (_lockedGuided) then {
					if ((abs (_realElevation - _lowAngleSol)) < (abs (_realElevation -_highAngleSol))) then {
						RC_GuidedTriggerTime = _travelTimeLow;
					};
				};


				// AZ/EL coloring when close to firing solution
				//#include "\Remote_Controlled_Artillery\functions\UILoop_includes\temporary_coloring_workaround.sqf"
				#include "\Remote_Controlled_Artillery\functions\UILoop_includes\MIL_coloring.sqf"
				
				// shows if its not, almost, or fully aligned
				switch (true) do {
					case(
						(_realElevation < (_highAngleSol + 0.3)) and
						(_realElevation > (_highAngleSol - 0.3)) and
						(_realAzimuth < (_targetAzimuth + 0.3)) and
						(_realAzimuth > (_targetAzimuth - 0.3))
					): {
						_ctrlMessage ctrlSetTextColor [0,1,0,1];
						_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "ALIGNED";
					};

					case(
						(_realElevation < (_lowAngleSol + 0.3)) and
						(_realElevation > (_lowAngleSol - 0.3)) and
						(_realAzimuth < (_targetAzimuth + 0.3)) and
						(_realAzimuth > (_targetAzimuth - 0.3))
					): {
						_ctrlMessage ctrlSetTextColor [0,1,0,1];
						_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "ALIGNED";
					};

					case(
						(_realElevation < (_highAngleSol + 0.75)) and
						(_realElevation > (_highAngleSol - 0.75)) and
						(_realAzimuth < (_targetAzimuth + 0.75)) and
						(_realAzimuth > (_targetAzimuth - 0.75))
					): {
						_ctrlMessage ctrlSetTextColor [1,0.5,0,1];
						_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "NOT ALIGNED";
					};

					case(
						(_realElevation < (_lowAngleSol + 0.75)) and
						(_realElevation > (_lowAngleSol - 0.75)) and
						(_realAzimuth < (_targetAzimuth + 0.75)) and
						(_realAzimuth > (_targetAzimuth - 0.75))
					): {
						_ctrlMessage ctrlSetTextColor [1,0.5,0,1];
						_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "NOT ALIGNED";
					};

					case(
						(_lockedGuided) and
						(_realElevation < (_highAngleSol + 3)) and
						(_realElevation > (_highAngleSol - 3)) and
						(_realAzimuth < (_targetAzimuth + 3)) and
						(_realAzimuth > (_targetAzimuth - 3))
					): {
						_ctrlMessage ctrlSetTextColor [0,1,0,1];
						_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "ALIGNED";
					};

					case(
						(_lockedGuided) and
						(_realElevation < (_lowAngleSol + 3)) and
						(_realElevation > (_lowAngleSol - 3)) and
						(_realAzimuth < (_targetAzimuth + 3)) and
						(_realAzimuth > (_targetAzimuth - 3))
					): {
						_ctrlMessage ctrlSetTextColor [0,1,0,1];
						_ctrlMessage ctrlSetPositionX (0.906267 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "ALIGNED";
					};

					default {
						_ctrlMessage ctrlSetTextColor [1,0,0,1];
						_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "NOT ALIGNED";
					};
				};
				
				// parse these back to numbers incase they are NaN
				_highAngleSol = parseNumber str _highAngleSol;
				_lowAngleSol = parseNumber str _lowAngleSol;
				_travelTimeHigh = parseNumber str _travelTimeHigh;
				_travelTimeLow = parseNumber str _travelTimeLow;
	
				// if they were NaN then make them zero
				if (_highAngleSol < 0) then {
					_highAngleSol = 0;
					_lowAngleSol = 0;
					_travelTimeHigh = 0;
					_travelTimeLow = 0;
				};
			} else {
				// display if no target is available/selected
				#include "\Remote_Controlled_Artillery\functions\UILoop_includes\notarget_display.sqf"
			};
			_ctrlHighSol ctrlShow true;
			_ctrlLowSol ctrlShow true;
			_ctrlHighETA ctrlShow true;
			_ctrlLowETA ctrlShow true;

			// greys out not-advised trajectory depending on round
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\advised_trajectory.sqf"

			_ctrlCharge ctrlSetText Format ["CH: %1", _realCharge];
			_ctrlAzimuth ctrlSetText Format ["AZ: %1", [_realAzimuth, 4, 0] call CBA_fnc_formatNumber];
			_ctrlElevation ctrlSetText Format ["EL: %1", [_realElevation, 4, 0] call CBA_fnc_formatNumber];

			if (_highAngleSol isEqualType 0) then {
				_ctrlHighSol ctrlSetText Format ["high EL: %1", [_highAngleSol, 4, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlHighSol ctrlSetText Format ["high EL: 0000%1"];
			};

			if (_lowAngleSol isEqualType 0) then {
				_ctrlLowSol ctrlSetText Format ["low EL: %1", [_lowAngleSol, 4, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlLowSol ctrlSetText Format ["low EL: 0000%1"];
			};

			if (_travelTimeHigh isEqualType 0) then {
				_ctrlHighETA ctrlSetText Format ["ETA: %1", [_travelTimeHigh, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlHighETA ctrlSetText Format ["ETA: 000%1"];
			};

			if (_travelTimeLow isEqualType 0) then {
				_ctrlLowETA ctrlSetText Format ["ETA: %1", [_travelTimeLow, 3, 0] call CBA_fnc_formatNumber];
			} else {
				_ctrlLowETA ctrlSetText Format ["ETA: 000%1"];
			};
		};
	};
};
