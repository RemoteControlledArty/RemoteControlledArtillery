[] spawn {
    waitUntil { !isNull findDisplay 46 };
    ["DatalinkHotkeyMonitor", "onEachFrame", {
        if ((inputAction "lockTarget") > 0.5) then {
			private _vehicle = vehicle player;
			if (_vehicle != player) then {
				private _currentMag = _vehicle currentMagazineTurret (_vehicle unitTurret player);
				if ((_currentMag find 'HEAB' != -1) or (_currentMag find 'MPAB' != -1)) then {
					private _target = cursorTarget;
					if (!isNull _target && alive _target) then {
						if (_target isKindOf "Man") then {
							private _side = side player;
							_side reportRemoteTarget [_target, 8];
							_target confirmSensorTarget [_side, true];
						};
						if (_target isKindOf "StaticWeapon") then {
							private _side = side player;
							_side reportRemoteTarget [_target, 180];
							_target confirmSensorTarget [_side, true];
						};
					};
				};
			};
			if (isRemoteControlling player) then {
				private _uav = getConnectedUAV player;
				if (_uav isKindOf 'RC_UAV_base') then {
					private _target = cursorTarget;
					if (!isNull _target && alive _target) then {
						if (_target isKindOf "Man") then {
							private _side = side player;
							_side reportRemoteTarget [_target, 10];
							_target confirmSensorTarget [_side, true];
						};
						if (_target isKindOf "StaticWeapon") then {
							private _side = side player;
							_side reportRemoteTarget [_target, 180];
							_target confirmSensorTarget [_side, true];
						};
					};
				};
				private _currentMag = _uav currentMagazineTurret (_uav unitTurret gunner _uav);
				if ((_currentMag find 'HEAB' != -1) or (_currentMag find 'MPAB' != -1)) then {
					private _target = cursorTarget;
					if (!isNull _target && alive _target) then {
						if (_target isKindOf "Man") then {
							private _side = side player;
							_side reportRemoteTarget [_target, 8];
							_target confirmSensorTarget [_side, true];
						};
						if (_target isKindOf "StaticWeapon") then {
							private _side = side player;
							_side reportRemoteTarget [_target, 180];
							_target confirmSensorTarget [_side, true];
						};
					};
				};
			};
		};
    }] call BIS_fnc_addStackedEventHandler;
};