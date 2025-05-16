RC_fnc_uavWps =
{
    params ["_uav", "_prevWpsCount", "_prevWpPos1", "_prevWpPos2", "_prevWpPos3"];

    [player, "terminal open"] remoteExec ['globalChat', clientOwner];

    private _currentWpPos1 = waypointPosition [_uav, 1];
    private _currentWpPos2 = waypointPosition [_uav, 2];
    private _currentWpPos3 = waypointPosition [_uav, 3];
    if (((_currentWpPos1 select 1) != (_prevWpPos1 select 1)) or
    ((_currentWpPos2 select 1) != (_prevWpPos2 select 1)) or
    ((_currentWpPos3 select 1) != (_prevWpPos3 select 1))) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        private _player = player;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "changed locality (wpPos)"] remoteExec ['globalChat', clientOwner];

        _prevWpPos1 = _currentWpPos1;
        _prevWpPos2 = _currentWpPos2;
        _prevWpPos3 = _currentWpPos3;
    };

    private _currentWpsCount = count (waypoints _uav);
    if (_currentWpsCount != _prevWpsCount) then {

        private _driverGroup = group (driver _uav);
        private _playerID = clientOwner;
        private _player = player;
        [_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

        [player, "changed locality (wpCount)"] remoteExec ['globalChat', clientOwner];
        
        _prevWpsCount = _currentWpsCount;
    };
};