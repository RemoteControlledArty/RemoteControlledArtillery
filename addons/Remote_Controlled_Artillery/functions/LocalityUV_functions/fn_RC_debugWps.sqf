params ["_uav", "_prevWpsCount", "_prevWpPos1"];

[player, "terminal open"] remoteExec ['globalChat', clientOwner];

private _currentWpPos1 = waypointPosition [_uav, 1];
if (((_currentWpPos1 select 1) != (_prevWpPos1 select 1))) then {

    private _driverGroup = group (driver _uav);
    private _playerID = clientOwner;
    [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

    [player, "changed locality (wpPos)"] remoteExec ['globalChat', clientOwner];

    _prevWpPos1 = _currentWpPos1;
};

private _currentWpsCount = count (waypoints _uav);
if (_currentWpsCount != _prevWpsCount) then {

    private _driverGroup = group (driver _uav);
    private _playerID = clientOwner;
    [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

    [player, "changed locality (wpCount)"] remoteExec ['globalChat', clientOwner];
    
    _prevWpsCount = _currentWpsCount;
};