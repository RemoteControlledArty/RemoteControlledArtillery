params ["_uav", "_weapon"];

if (isNull _uav) exitWith {};
if (_weapon isNotEqualTo "RC_Crocus_Deployer") exitWith {};

private _pos = getPos _uav;
private _posZ = (_pos select 2) - 15;

private _spawnPos = +_pos;
_spawnPos set [2, _posZ];

if ((_spawnPos select 2) > 1000) then {
    _spawnPos set [2, 1000];
};

private _side = side _uav;
private _version = 'B_Crocus_MP_TI';
if (side _uav == east) then {_version = 'O_Crocus_MP_TI';};
if (side _uav == resistance) then {_version = 'I_Crocus_MP_TI';};

private _spawnArray = [_spawnPos, direction _uav, _version, _side];
[_spawnArray, BIS_fnc_spawnVehicle] remoteExec ['call', 2];