RC_fnc_calculateAB = {
    //doublecheck function name doubling
    if (isNull _target || (!alive _target) || (side _target == side _gunner)) exitWith {};
    systemChat "target valid";
    systemchat str time;

    private _maxSpeed = 4800;
    private _triggerDistance = 7;
    private _triggerDistanceBackup = 12;
    [_projectile, _triggerDistance, _triggerDistanceBackup, _maxSpeed, _target] spawn {
        params ["_p", "_d", "_b", "_m", "_t"];
        waitUntil { sleep 0.01; !isNull _p && alive _p };
        systemchat "proj alive";

        private _previousDistance = _p distance _t;
        sleep 0.005;

        private _dS = (_d * ((speed _p) / _m)) max 3;
        systemchat str _dS;
        
        while { alive _p } do {
            private _currentDistance = _p distance _t;
            if ((_currentDistance < _b && _currentDistance > _previousDistance) || (_currentDistance <= _dS)) exitWith {
                triggerAmmo _p;
                systemchat str time;
                systemchat "BOOM";
            };
            _previousDistance = _currentDistance;
            sleep 0.001;
        };
    };
};