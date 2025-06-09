params ["_uav"];

if (isNull _uav) exitWith {};

private _pos = getPos _uav;
private _posZ = (_pos select 2) - 15;

private _spawnPos = +_pos;
_spawnPos set [2, _posZ];

if ((_spawnPos select 2) > 1000) then {
    _spawnPos set [2, 1000];
};

private _spawnArray = [_spawnPos, direction _uav, 'B_Crocus_MP_TI', west];
[_spawnArray, BIS_fnc_spawnVehicle] remoteExec ['call', 2];