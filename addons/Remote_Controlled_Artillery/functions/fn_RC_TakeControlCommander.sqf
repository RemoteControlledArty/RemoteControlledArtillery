params ["_vehicle"];

_vicCommander = commander _vehicle;
_vicCommanderID = clientOwner;
_driverGroup = group (driver _vehicle);
[_vehicle, 'commander took drive controls'] remoteExec ['vehicleChat', _vicCommanderID];
[_driverGroup, _vicCommanderID] remoteExec ['setGroupOwner', 2];
[_vehicle, _vicCommander] remoteExec ['setEffectiveCommander', 0];


/*
player getEventHandlerInfo ["Control", 0]

private _vehicle = _this;

private _vicOwnerID = owner _vehicle;
private _driverGroup = group (driver _vehicle);

private _vicCommander = commander _vehicle;
private _vicCommanderID = owner _vicCommander;

private _vicGunner = gunner _vehicle;
private _vicGunnerID = owner _vicGunner;

private _strVicOwnerID = str _vicOwnerID;
private _strVicCommander = str _vicCommander;
private _strVicCommanderID = str _vicCommanderID;
private _strVicGunner = str _vicGunnerID;
private _strVicGunnerID = str _vicGunnerID;
private _strDriverGroup = str _driverGroup;
[_vehicle, 'ownerID: ' + _strVicOwnerID] remoteExec ['vehicleChat', _vicCommanderID];

[_vehicle, 'ownerID: ' + _strVicOwnerID] remoteExec ['vehicleChat', 0];
[_vehicle, 'owner: ' + _strVicCommander] remoteExec ['vehicleChat', 0];
[_vehicle, 'ownerID: ' + _strVicCommanderID] remoteExec ['vehicleChat', 0];
[_vehicle, 'owner: ' + _strVicGunner] remoteExec ['vehicleChat', 0];
[_vehicle, 'ownerID: ' + _strVicGunnerID] remoteExec ['vehicleChat', 0];


[_vehicle] remoteExec ['owner', 2];

private _vehicle = _this;
private _vicOwnerID = clientOwner _vehicle;
private _strVicOwnerID = str _vicOwnerID;
[_vehicle, 'ownerID: ' + _strVicOwnerID] remoteExec ['globalChat', 0];


if (!isServer) exitwith {};
private _vehicle = _this;
private _vicOwnerID = owner _vehicle;
private _strVicOwnerID = str _vicOwnerID;
[_vehicle, 'ownerID: ' + _strVicOwnerID] remoteExec ['globalChat', 0];


if (!isServer) exitwith {};
private _vehicle = _this;
private _vicOwnerID = owner _vehicle;
private _driverGroup = group (driver _vehicle);

private _vicCommander = commander _vehicle;
private _vicCommanderID = owner _vicCommander;

private _vicGunner = gunner _vehicle;
private _vicGunnerID = owner _vicGunner;

private _strVicOwnerID = str _vicOwnerID;
private _strVicCommander = str _vicCommander;
private _strVicCommanderID = str _vicCommanderID;
private _strVicGunner = str _vicGunnerID;
private _strVicGunnerID = str _vicGunnerID;
private _strDriverGroup = str _driverGroup;

[_vehicle, 'ownerID: ' + _strVicOwnerID] remoteExec ['vehicleChat', _vicCommanderID];
[_vehicle, 'ownerID: ' + _strVicOwnerID] remoteExec ['vehicleChat', 0];
[_vehicle, 'owner: ' + _strVicCommander] remoteExec ['vehicleChat', 0];
[_vehicle, 'ownerID: ' + _strVicCommanderID] remoteExec ['vehicleChat', 0];
[_vehicle, 'owner: ' + _strVicGunner] remoteExec ['vehicleChat', 0];
[_vehicle, 'ownerID: ' + _strVicGunnerID] remoteExec ['vehicleChat', 0];

[_driverGroup, _vicCommanderID] remoteExec ['setGroupOwner', 0];
[_vehicle, _vicCommander] remoteExec ['setEffectiveCommander', 0];

[_driverGroup, _vicGunnerID] remoteExec ['setGroupOwner', 0];
[_vehicle, _vicGunner] remoteExec ['setEffectiveCommander', 0];

private _vehicle = _this;
[_vehicle, 'meow'] remoteExec ['globalChat', 0];

[_vehicle, 'ownerID: ' + _strVicOwnerID] remoteExec ['vehicleChat', 0];
[_vehicle, 'owner: ' + _strVicCommander] remoteExec ['vehicleChat', 0];
[_vehicle, 'ownerID: ' + _strVicCommanderID] remoteExec ['vehicleChat', 0];
[_vehicle, 'owner: ' + _strVicGunner] remoteExec ['vehicleChat', 0];
[_vehicle, 'ownerID: ' + _strVicGunnerID] remoteExec ['vehicleChat', 0];
[_vehicle, 'driverGroup: ' + _strDriverGroup] remoteExec ['vehicleChat', 0];
*/