params ["_vehicle"];

if (!isServer) exitwith {};
_vicGunner = gunner _vehicle;
_vicGunnerID = owner _vicGunner;
_driverGroup = group (driver _vehicle);
[_vehicle, 'gunner took drive controls'] remoteExec ['vehicleChat', 0];
_driverGroup setGroupOwner _vicGunnerID;
[_vehicle, _vicGunner] remoteExec ['setEffectiveCommander', 0];