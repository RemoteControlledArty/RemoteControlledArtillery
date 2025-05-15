/*
	Author: Ascent

	Description:
	Fixes multiplayer locality of this mods UAV's/UGV's.
*/

/*
_this addEventHandler ["OpticsSwitch", {

	params ["_unit", "_isADS"];
	[_unit, 'OpticsSwitch'] remoteExec ['globalChat', 0];
	
	private _uav = (getConnectedUAV _unit);

	private _driverGroup = group (driver _uav);
	private _playerID = clientOwner;

	private _strPlayerID = str _playerID;
	[_unit, 'clientOwnerID: ' + _strPlayerID] remoteExec ['globalChat', 0];

	[_driverGroup, _playerID] remoteExec ['setGroupOwner', 0];
	[_uav, _unit] remoteExec ['setEffectiveCommander', 0];
}];


_unit = _this;
private _uav = (getConnectedUAV _unit);

private _driverGroup = group (driver _uav);
private _playerID = clientOwner;

private _strPlayerID = str _playerID;
[_unit, 'clientOwnerID: ' + _strPlayerID] remoteExec ['globalChat', 0];

[_driverGroup, _playerID] remoteExec ['setGroupOwner', 0];
[_uav, _unit] remoteExec ['setEffectiveCommander', 0];




private _uav = (getConnectedUAV player);
[player, str _uav] remoteExec ['globalChat', 0];

private _playerID = clientOwner;
[player, str _playerID] remoteExec ['globalChat', 0];


_unit = _this;
private _uav = (getConnectedUAV _unit);
private _driverGroup = group (driver _uav);

private _playerID = clientOwner _unit;

private _strPlayerID = str _playerID;
[_unit, 'clientOwnerID: ' + _strPlayerID] remoteExec ['globalChat', 0];

[_driverGroup, _playerID] remoteExec ['setGroupOwner', 0];
[_uav, _unit] remoteExec ['setEffectiveCommander', 0];


_this addEventHandler ["OpticsModeChanged", {
	params ["_unit", "_opticsClass", "_newMode", "_oldMode", "_isADS"];

	[_unit, 'OpticsModeChanged'] remoteExec ['globalChat', 0];
}];

_this addEventHandler ["Engine", {
	params ["_vehicle", "_engineState"];

	_player = ((UAVControl _vehicle) select 1);
	[_player, 'Engine'] remoteExec ['globalChat', 0];
}];

_this addEventHandler ["OpticsSwitch", {

	params ["_unit", "_isADS"];
	[_unit, 'OpticsSwitch'] remoteExec ['globalChat', 0];
}];


_this addEventHandler ["OpticsSwitch", {

	params ["_unit", "_isADS"];
	[_unit, 'OpticsSwitch'] remoteExec ['globalChat', 0];

	_uav = (getConnectedUAV player);
	private _strUAV = str _uav;
	[_unit, 'ownerID: ' + _strUAV] remoteExec ['globalChat', 0];
}];


_pos = position _this;
private _array = [_pos, 180, "RC_cUAS_UGV_WD", west];
[_array, BIS_fnc_spawnVehicle] remoteExec ['call', 2];


_pos = position _this;
private _array = [_pos, 180, "RC_IFV_3_A_Test0", west];
[_array, BIS_fnc_spawnVehicle] remoteExec ['call', 2];


[_pos, 180, "RC_cUAS_UGV_WD", west] call BIS_fnc_spawnVehicle;
*/