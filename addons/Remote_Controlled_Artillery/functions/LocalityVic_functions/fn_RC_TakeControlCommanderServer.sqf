params ["_vic"];

_vicCmdr = commander _vic;
_vicCmdrID = owner _vicCmdr;
_driverGroup = group (driver _vic);
//[_vic, 'commander took drive controls'] remoteExec ['vehicleChat', 0];
private _crew = (crew _vic) select {isPlayer _x};
[_vic, 'commander took drive controls'] remoteExec ['systemChat', _crew];
_driverGroup setGroupOwner _vicCmdrID;
[_vic, _vicCmdr] remoteExec ['setEffectiveCommander', 0];