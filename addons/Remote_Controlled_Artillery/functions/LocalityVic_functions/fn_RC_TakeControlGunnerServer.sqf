params ["_vic"];

_vicGunner = gunner _vic;
_vicGunnerID = owner _vicGunner;
_driverGroup = group (driver _vic);
//[_vic, 'gunner took drive controls'] remoteExec ['vehicleChat', 0];
private _crew = (crew _vic) select {isPlayer _x};
[_vic, 'gunner took drive controls'] remoteExec ['systemChat', _crew];
_driverGroup setGroupOwner _vicGunnerID;
[_vic, _vicGunner] remoteExec ['setEffectiveCommander', 0];