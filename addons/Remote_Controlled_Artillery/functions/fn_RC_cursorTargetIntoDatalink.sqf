[] spawn {
    waitUntil { !isNull findDisplay 46 };
    ["DatalinkHotkeyMonitor", "onEachFrame", {
        if ((inputAction "lockTarget") > 0.5) then {
			private _vehicle = vehicle player;
			if (_vehicle != player) then {
				private _currentMag = _vehicle currentMagazineTurret (_vehicle unitTurret player);
				if ((_currentMag find 'HEAB' != -1) or (_currentMag find 'MPAB' != -1)) then {
					private _target = cursorTarget;
					private _distance = _target distance _vehicle;	//make dependant on zoom and target type
					if (!isNull _target && alive _target && (_distance <= 4000)) then {
						private _side = side player;
						if (_target isKindOf "StaticWeapon" && RC_AB_StaticConfirming) then {
							[_side,[_target, 180]] remoteExec ["reportRemoteTarget", _side];
						} else {
							if (_target isKindOf "Man" && RC_AB_InfConfirming) then {
								[_side,[_target, 8]] remoteExec ["reportRemoteTarget", _side];
							} else {
								[_side,[_target, 12]] remoteExec ["reportRemoteTarget", _side];
							};
						};
					};
				};
			};
			if (isRemoteControlling player) then {
				private _uav = getConnectedUAV player;
				if ((_uav isKindOf 'RC_UAV_base') or (_uav isKindOf 'RC_GrenadeDropper_Base') or (_uav isKindOf 'B_Crocus_MP_Base') or (_uav isKindOf 'RC_FPV_Mothership_Base')) then {
					private _target = cursorTarget;
					private _distance = _target distance _vehicle;	//make dependant on zoom and target type
					if (!isNull _target && alive _target && (_distance <= 4000)) then {
						private _side = side player;
						private _targetSide = side _target;
						if (_target isKindOf "StaticWeapon" && RC_UAV_StaticReporting) then {
							[_side,[_target, 180]] remoteExec ["reportRemoteTarget", _side];
							if (([_targetSide, _side] call BIS_fnc_sideIsEnemy) && (_targetSide != civilian)) then {
								[_target, [_side, true]] remoteExec ["confirmSensorTarget", _side];
							};
						} else {
							if (_target isKindOf "Man" && RC_UAV_InfReporting) then {
								[_side,[_target, 8]] remoteExec ["reportRemoteTarget", _side];
								if (([_targetSide, _side] call BIS_fnc_sideIsEnemy) && (_targetSide != civilian)) then {
									[_target, [_side, true]] remoteExec ["confirmSensorTarget", _side];
								};
							} else {
								[_side,[_target, 12]] remoteExec ["reportRemoteTarget", _side];
								if (([_targetSide, _side] call BIS_fnc_sideIsEnemy) && (_targetSide != civilian)) then {
									[_target, [_side, true]] remoteExec ["confirmSensorTarget", _side];
								};
							};
						};
					};
				};
				private _currentMag = _uav currentMagazineTurret (_uav unitTurret gunner _uav);
				if ((_currentMag find 'HEAB' != -1) or (_currentMag find 'MPAB' != -1)) then {
					private _target = cursorTarget;
					private _distance = _target distance _vehicle;	//make dependant on zoom and target type
					if (!isNull _target && alive _target && (_distance <= 4000)) then {
						private _side = side player;
						if (_target isKindOf "StaticWeapon" && RC_AB_StaticConfirming) then {
							[_side,[_target, 180]] remoteExec ["reportRemoteTarget", _side];
						} else {
							if (_target isKindOf "Man" && RC_AB_InfConfirming) then {
								[_side,[_target, 8]] remoteExec ["reportRemoteTarget", _side];
							} else {
								[_side,[_target, 12]] remoteExec ["reportRemoteTarget", _side];
							};
						};
					};
				};
			};
		};
    }] call BIS_fnc_addStackedEventHandler;
};