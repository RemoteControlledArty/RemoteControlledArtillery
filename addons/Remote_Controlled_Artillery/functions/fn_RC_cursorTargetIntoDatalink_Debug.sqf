[] spawn {
    waitUntil { !isNull findDisplay 46 };
    ["DatalinkHotkeyMonitor", "onEachFrame", {
        if ((inputAction "lockTarget") > 0.5) then {
			private _vehicle = vehicle player;
			systemChat str "selected target";
			if (_vehicle != player) then {
				systemChat str "passed vehicle check";
				private _currentMag = _vehicle currentMagazineTurret (_vehicle unitTurret player);
				systemChat str _currentMag;
				if ((_currentMag find 'HEAB' == -1) and (_currentMag find 'MPAB' == -1)) exitWith {};
				systemChat "found AB";
				private _target = cursorTarget;
				systemChat str _target;
				if (!isNull _target && alive _target && _target isKindOf "Man") then {
					systemChat "target !isNull & alive & man";
					systemChat str time;
					private _side = side player;
					_side reportRemoteTarget [_target, 8];
					_target confirmSensorTarget [_side, true];
				};
			};
			if (isRemoteControlling player) then {
				systemChat str "passed ugv check";
				private _target = cursorTarget;
				systemChat str _target;
				if (!isNull _target && alive _target && _target isKindOf "Man") then {
					systemChat "target !isNull & alive & man";
					systemChat str time;
					private _side = side player;
					_side reportRemoteTarget [_target, 8];
					_target confirmSensorTarget [_side, true];
				};
			};
		};
    }] call BIS_fnc_addStackedEventHandler;
};