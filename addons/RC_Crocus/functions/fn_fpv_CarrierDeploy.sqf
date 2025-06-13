params ["_uav", "_weapon"];

if (isNull _uav) exitWith {};
if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};
_uav selectWeaponTurret ["RC_target_confirmer_datalink", [0]];   //to prevent accidental trigger

private _pos = getPos _uav;
private _posY = (_pos select 1) + 3;

private _spawnPos = +_pos;
_spawnPos set [1, _posY];

private _side = side _uav;
private _version = 'B_Crocus_MP_TI';
if (side _uav == east) then {_version = 'O_Crocus_MP_TI';};
if (side _uav == resistance) then {_version = 'I_Crocus_MP_TI';};

//[_spawnArray, BIS_fnc_spawnVehicle] remoteExec ['call', 2];
private _uavSpawn = [_spawnPos, direction _uav, _version, _side] call BIS_fnc_spawnVehicle;
private _uavNew = _uavSpawn select 0;
//_uavNew setVectorDirAndUp [[0,0,-1], [0,1,0]];    //freezes it for unknown reason
player connectTerminalToUAV _uavNew;
driver _uavNew switchCamera "Internal";
player remoteControl driver _uavNew;