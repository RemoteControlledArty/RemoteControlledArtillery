params ["_vehicle"];

_vicGunner = gunner _vehicle;
_vicGunnerID = clientOwner;
_driverGroup = group (driver _vehicle);
[_vehicle, 'gunner took drive controls'] remoteExec ['vehicleChat', _vicGunnerID];
[_driverGroup, _vicGunnerID] remoteExec ['setGroupOwner', 2];
[_vehicle, _vicGunner] remoteExec ['setEffectiveCommander', 0];