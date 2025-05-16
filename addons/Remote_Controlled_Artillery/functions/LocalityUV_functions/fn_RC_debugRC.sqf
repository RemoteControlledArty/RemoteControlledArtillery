params ["_uav"];

[player, "remote controlling"] remoteExec ['globalChat', clientOwner];

private _driverGroup = group (driver _uav);
private _playerID = clientOwner;
[_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

[player, "changed locality (rc): " + str time] remoteExec ['globalChat', clientOwner];