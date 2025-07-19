params ["_uav", "_weapon"];

if (isNull _uav) exitWith {};
if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};
//_uav selectWeaponTurret ["RC_target_confirmer_datalink", [0]];   //to prevent accidental trigger

private _pos = getPos _uav;
private _posZ = (_pos select 2) + 500;

//private _spawnPos = _uav modelToWorld [0, -3, 0];
private _spawnPos = +_pos;
_spawnPos set [2, _posZ];

private _side = side _uav;
private _version = 'B_Crocus_MP_TI';
if (side _uav == east) then {_version = 'O_Crocus_MP_TI';};
if (side _uav == resistance) then {_version = 'I_Crocus_MP_TI';};

//[_spawnArray, BIS_fnc_spawnVehicle] remoteExec ['call', 2];
private _uavSpawn = [_spawnPos, direction _uav, _version, _side] call BIS_fnc_spawnVehicle;
private _uavNew = _uavSpawn select 0;

[_uavNew] spawn {
	params ["_uavNew"];

	sleep 3;
	player connectTerminalToUAV _uavNew;
	player action ["UAVTerminalOpen", player];
	//driver _uavNew switchCamera "Internal";
	//player remoteControl driver _uavNew;
};
