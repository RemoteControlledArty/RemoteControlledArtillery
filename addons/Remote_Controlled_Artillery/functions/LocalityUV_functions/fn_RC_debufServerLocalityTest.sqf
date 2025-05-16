if (_repeats == 2) then {
    private _uav = getConnectedUAV player;
    private _driverGroupServer = group (driver _uav);
    [_driverGroupServer, 2] remoteExec ['setGroupOwner', 2];
    [player, "SERVER locality"] remoteExec ['globalChat', clientOwner];
};
if (_repeats == 4) then {
    private _uav = getConnectedUAV player;
    private _driverGroupServer = group (driver _uav);
    [_driverGroupServer, 2] remoteExec ['setGroupOwner', 2];
    [player, "SERVER locality"] remoteExec ['globalChat', clientOwner];
};