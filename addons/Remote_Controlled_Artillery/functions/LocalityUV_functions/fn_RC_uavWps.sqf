params ["_uav", "_prevWpsCount", "_prevWpPos1"];

private _currentWpPos1 = waypointPosition [_uav, 1];
if (((_currentWpPos1 select 1) != (_prevWpPos1 select 1))) then {

    [_uav] call RC_fnc_RC_uavChangeLocality;

    _prevWpPos1 = _currentWpPos1;
};

private _currentWpsCount = count (waypoints _uav);
if (_currentWpsCount != _prevWpsCount) then {

    [_uav] call RC_fnc_RC_uavChangeLocality;

    _prevWpsCount = _currentWpsCount;
};