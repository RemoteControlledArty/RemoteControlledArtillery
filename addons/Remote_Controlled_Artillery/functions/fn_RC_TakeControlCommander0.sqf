params ["_vehicle"];

if (!isServer) exitwith {};
_vicCommander = commander _vehicle;
_vicCommanderID = owner _vicCommander;
_driverGroup = group (driver _vehicle);
[_vehicle, 'commander took drive controls'] remoteExec ['vehicleChat', 0];
_driverGroup setGroupOwner _vicCommanderID;
[_vehicle, _vicCommander] remoteExec ['setEffectiveCommander', 0];