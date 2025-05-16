params ["_uav"];

private _driverGroup = group (driver _uav);
private _playerID = clientOwner;
[_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];