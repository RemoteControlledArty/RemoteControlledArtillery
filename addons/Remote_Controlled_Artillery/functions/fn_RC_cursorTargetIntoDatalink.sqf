[] spawn {
    waitUntil { !isNull findDisplay 46 };
    ["DatalinkHotkeyMonitor", "onEachFrame", {
        if ((inputAction "lockTarget") > 0.5) then {
			private _vehicle = vehicle player;
			if (_vehicle != player) then {
				private _currentMag = _vehicle currentMagazineTurret (_vehicle unitTurret player);
				if ((_currentMag find 'HEAB' == -1) and (_currentMag find 'MPAB' == -1)) exitWith {};
				private _target = cursorTarget;
				if (!isNull _target && alive _target && _target isKindOf "Man") then {
					private _side = side player;
					_side reportRemoteTarget [_target, 8];
					_target confirmSensorTarget [_side, true];
				};
			};
			if (isRemoteControlling player) then {
				private _target = cursorTarget;
				if (!isNull _target && alive _target && _target isKindOf "Man") then {
					private _side = side player;
					_side reportRemoteTarget [_target, 8];
					_target confirmSensorTarget [_side, true];
				};
			};
		};
    }] call BIS_fnc_addStackedEventHandler;
};