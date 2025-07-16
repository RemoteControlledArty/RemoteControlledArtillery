#include "\Remote_Controlled_Artillery\script_component.hpp"
/*
	This Code is held together by Duct Tape and Hope
	Author: Fluffy, Ascent, Eric

	Description:
	Main Loop to Handle the Calculation and UI of RC Artillery Units
*/

// Need to exit early if we aren't a client
if (!hasInterface) exitWith {};
RC_isULMHash = createHashMap;

/*
//hashmaps already created in mod it depends onBriefingGear


//general hashmaps
RC_isAceLoadedHash = createHashMap;

//vehicle hashmaps
//RC_localizeHash = createHashMap;	//not yet used
RC_ArtyTypeHash = createHashMap;
RC_isAceMortarHash = createHashMap;
RC_BarrelAGLHash = createHashMap;
RC_BarrelLenghtHash = createHashMap;
RC_BarrelExtendsHash = createHashMap;

//magazine hashmaps
RC_advisedTrajectoryHash = createHashMap;
RC_requiresLockHash = createHashMap;
RC_terrainWarningHash = createHashMap;
RC_aimAboveHeightHash = createHashMap;
*/

RC_ULM_UI = [] spawn {
	while { true } do {
		sleep 0.1;

		_player = player;
		_vicPlayer = vehicle player;

		/*
		private _inOptics = false;
		if (cameraOn == _uav && cameraView == "Internal") then	{
			_inOptics = true;
		};
		*/

		if ((_vicPlayer isEqualTo _player) || (cameraView != "GUNNER")) then {
			// UI Shouldn't be Shown so we cut it
			"RC_ULM_Rsc" cutFadeOut 0;
			RC_ULM_InUI = false;
			continue;
		};
		//systemchat "_vicPlayer isNotEqualTo _player";

		// UAV
		_uav = _vicPlayer;
		// UAV ClassName
		_uavClass = typeOf _uav;
		// See if the vehicle has the isULM property
		private _isULM = RC_isULMHash get _uavClass;

		if (isNil "_isULM") then {
			_isULM = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "isULM") == 1;
			RC_isULMHash set [_uavClass, _isULM];
		};

		// If it's of Artillery or Mortar Type do da thing
		if (_isULM) then {
			
			// We are in the UI now
			RC_ULM_InUI = true;
			
			// If our UAV is Autonomous we want to make it not
			// We need to remote exec it since setAutonomous is of Local Effect so it needs to be where the UAV is Local
			//if (isAutonomous _uav) then {[_uav, false] remoteExec ["setAutonomous", _uav];};
			
			// Check if the Display for the UI Exists if not Create it
			if (isNull (uiNamespace getVariable ["RC_ULM_Rsc", displayNull])) then { "RC_ULM_Rsc" cutRsc ["RC_ULM_Rsc", "PLAIN", 0, false] };
			
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
			_display = uiNamespace getVariable ["RC_ULM_Rsc", displayNull];

			//weapon informations like charges and current charge
			#include "\Remote_Controlled_Artillery\functions\UILoop_includes\weapon_info.sqf"

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
			/*
			private _terrainWarning = RC_TerrainWarningHash get _currentMag;
			if (isNil "_terrainWarning") then {
				_terrainWarning = (getNumber (configFile >> "CfgMagazines" >> _currentMag >> "RC_TerrainWarning"))==1;
				RC_TerrainWarningHash set [_currentMag, _terrainWarning];
			};
			*/

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
			private _highAngleSol = 0;
			private _travelTimeHigh = 0;
			private _lowAngleSol = 0;
			private _travelTimeLow = 0;

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
				_targetPos = [0, 0, 0];
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

				//velocity of the round
				_roundVelocity = getNumber (_weaponConfig >> _currentFireMode >> "artilleryCharge") * getNumber (configFile >> "CfgMagazines" >> _currentMag >> "initSpeed");

				//displayed target
				_ctrlDistance ctrlSetText Format ["DIST: %1", [_targetDistance, 4, 0] call CBA_fnc_formatNumber];
				if (_hasTargetSelected && (_selectedTargetDistance >= MIN_SELECTED_TARGET_DISTANCE)) then {
					_ctrlTarget ctrlSetText "T: Datalink";
				} else {
					_ctrlTarget ctrlSetText Format ["T: %1", [RC_currentTargetMarker select 0, 2, 0] call CBA_fnc_formatNumber];
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

				// AZ/EL coloring when close to firing solution
				#include "\RC_60mmULM\functions\temporary_coloring_workaround_ULM.sqf"
				//#include "\Remote_Controlled_Artillery\functions\UILoop_includes\MIL_coloring.sqf"
				
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

					default {
						_ctrlMessage ctrlSetTextColor [1,0,0,1];
						_ctrlMessage ctrlSetPositionX (0.909967 * safezoneW + safezoneX);
						_ctrlMessage ctrlSetText "NOT ALIGNED";
					};
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
				#include "\Remote_Controlled_Artillery\functions\UILoop_includes\notarget_display.sqf"
			};
			_ctrlHighSol ctrlShow true;
			_ctrlLowSol ctrlShow true;
			_ctrlHighETA ctrlShow true;
			_ctrlLowETA ctrlShow true;

			//greys out not-advised trajectory depending on round
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
