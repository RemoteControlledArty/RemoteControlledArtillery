params ["_veh", "_classFPV", "_sidePlayer"];

if (isNull _veh) exitWith {};
//_uav selectWeaponTurret ["RC_target_confirmer_datalink", [0]];   //to prevent accidental trigger

private _pos = getPos _veh;
/*
private _posZ = (_pos select 2) + 500;

//private _spawnPos = _uav modelToWorld [0, -3, 0];
private _spawnPos = +_pos;
_spawnPos set [2, _posZ];
*/

//[_spawnArray, BIS_fnc_spawnVehicle] remoteExec ['call', 2];
systemchat _classFPV;
private _uavSpawn = [_pos, direction _veh, _classFPV, _sidePlayer] call BIS_fnc_spawnVehicle;
private _uavNew = _uavSpawn select 0;

[_uavNew] spawn {
	params ["_uavNew"];

	sleep 3;
	player connectTerminalToUAV _uavNew;
	[_uavNew] call RC_fnc_RC_uavChangeLocality;
	player action ["UAVTerminalOpen", player];
	//driver _uavNew switchCamera "Internal";
	//player remoteControl driver _uavNew;
};