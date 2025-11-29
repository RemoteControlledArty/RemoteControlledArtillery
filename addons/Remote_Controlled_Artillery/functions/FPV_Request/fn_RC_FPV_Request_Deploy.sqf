params ["_veh", "_classFPV", "_sidePlayer"];

if (isNull _veh) exitWith {};

private _pos = getPos _veh;
private _posZ = (_pos select 2) + 7;
private _spawnPos = +_pos;
_spawnPos set [2, _posZ];

//systemchat _classFPV;
private _uavArray = [_pos, direction _veh, _classFPV, _sidePlayer];

[_uavArray, _spawnPos] spawn {
	params ["_uavArray", "_spawnPos"];

	sleep 9.7;
	private _uavSpawn = _uavArray call BIS_fnc_spawnVehicle;
	private _uavNew = _uavSpawn select 0;
	_uavNew setPos _spawnPos;

	player connectTerminalToUAV _uavNew;
	[_uavNew] call RC_fnc_RC_uavChangeLocality;

	sleep 0.3;
	player action ["UAVTerminalOpen", player];
	//driver _uavNew switchCamera "Internal";
	//player remoteControl driver _uavNew;
};