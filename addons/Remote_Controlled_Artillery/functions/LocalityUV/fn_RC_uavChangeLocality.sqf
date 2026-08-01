params ["_uav"];

private _driverGroup = group (driver _uav);
private _playerID = clientOwner;
[_driverGroup, _playerID] remoteExec ['setGroupOwner', 2];

//prevent locality issues like headless client stealing locality of UV's
_uav setVariable ["acex_headless_blacklist", true];