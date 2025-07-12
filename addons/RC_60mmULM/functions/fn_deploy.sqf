params ["_unit"];

if ((secondaryWeapon _unit != "RC_60mm_ULM_Bag") || !(local _unit) || !(isPlayer _unit) || (vehicle player != player)) exitwith {};
//if ((secondaryWeapon _unit != "twc_2inch_bag") || !(local _unit) || !(isPlayer _unit) || (vehicle player != player)) exitwith {};

if (weaponLowered _unit) then {_unit switchMove "amovpercmstpslowwrfldnon"};

_dir = getDir _unit;
_height = (getPos _unit) select 2;
_pos = _unit getPos [0.1, _dir];

_KK_fnc_setPosAGLS = {
	params ["_obj", "_pos", "_offset"];
	_offset = _pos select 2;
	if (isNil "_offset") then {_offset = 0};
	_pos set [2, worldSize]; 
	_obj setPosASL _pos;
	_pos set [2, vectorMagnitude (_pos vectorDiff getPosVisual _obj) + _offset];
	_obj setPosASL _pos;
};


_mortar = "RC_60mm_ULM_Vic" createVehicle _pos;
//_mortar = "twc_2inch_vehicle" createVehicle _pos;
[_mortar, _pos] call _KK_fnc_setPosAGLS;
_mortar setDir _dir;
if ((getPosATL _unit) isEqualTo (getPos _unit)) then {_mortar setVectorUp (surfaceNormal _pos)} else {_mortar setVectorUp (vectorUp _unit)};
_mortar setVariable ["ace_mk6mortar_exclude", true];

_unit assignAsGunner _mortar;
_unit moveInGunner _mortar;

/*
_magazines = magazines _unit;
_HECount = {_x == "RC_1Rnd_60mm_Mo_shells_ULM"} count _magazines;
_HEABCount = {_x == "RC_1Rnd_60mm_Mo_HEAB_ULM"} count _magazines;
_HEABbackupCount = {_x == "RC_1Rnd_60mm_Mo_backupHEAB_ULM"} count _magazines;
_smokeCount = {_x == "RC_1Rnd_60mm_Mo_Smoke_white_ULM"} count _magazines;

_MpMgCount = {_x == "RC_1Rnd_60mm_Mo_MultiGuided_ULM"} count _magazines;
_MpLgCount = {_x == "RC_1Rnd_60mm_Mo_LaserGuided_ULM"} count _magazines;
_MpLgDfCount = {_x == "RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM"} count _magazines;

_mineCount = {_x == "RC_1Rnd_60mm_Mo_mine_ULM"} count _magazines;
_IllumCount = {_x == "RC_1Rnd_60mm_Mo_Flare_white_ULM"} count _magazines;
_loadedMag = (secondaryWeaponMagazine _unit) select 0;


switch (_loadedMag) do
{
	case "RC_1Rnd_60mm_Mo_shells_ULM": {_HECount = _HECount + 1};
	case "RC_1Rnd_60mm_Mo_HEAB_ULM": {_HEABCount = _HEABCount + 1};
	case "RC_1Rnd_60mm_Mo_backupHEAB_ULM": {_HEABbackupCount = _HEABbackupCount + 1};
	case "RC_1Rnd_60mm_Mo_Smoke_white_ULM": {_smokeCount = _smokeCount + 1};

	case "RC_1Rnd_60mm_Mo_MultiGuided_ULM": {_MpMgCount = _MpMgCount + 1};
	case "RC_1Rnd_60mm_Mo_LaserGuided_ULM": {_MpLgCount = _MpLgCount + 1};
	case "RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM": {_MpLgDfCount = _MpLgDfCount + 1};

	case "RC_1Rnd_60mm_Mo_mine_ULM": {_mineCount = _mineCount + 1};
	case "RC_1Rnd_60mm_Mo_Flare_white_ULM": {_IllumCount = _IllumCount + 1};
	default {};
};


for "_i" from 1 to _HECount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_shells_ULM", [0]];
};
for "_i" from 1 to _HEABCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_HEAB_ULM", [0]];
};
for "_i" from 1 to _HEABbackupCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_backupHEAB_ULM", [0]];
};
for "_i" from 1 to _smokeCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_Smoke_white_ULM", [0]];
};


for "_i" from 1 to _MpMgCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_MultiGuided_ULM", [0]];
};
for "_i" from 1 to _MpLgCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_LaserGuided_ULM", [0]];
};
for "_i" from 1 to _MpLgDfCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM", [0]];
};


for "_i" from 1 to _mineCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_mine_ULM", [0]];
};
for "_i" from 1 to _IllumCount do {
	_mortar addMagazineTurret ["RC_1Rnd_60mm_Mo_Flare_white_ULM", [0]];
};


if !(isNil "_loadedMag") then {
	_mass = getNumber (configFile >> "CfgMagazines" >> _loadedMag >> "mass");
	switch (true) do
	{
		case ((1- loadVest _unit) * (getContainerMaxLoad vest _unit) > _mass);
		case ((1- loadBackpack _unit) * (getContainerMaxLoad backpack _unit) > _mass);
		case ((1- loadUniform _unit) * (getContainerMaxLoad uniform _unit) > _mass): {_unit addMagazine [_loadedMag, 1];};
		default {_mortar setVariable ["RC_60mm_ULM_LoadedMag", _loadedMag, true];
			//_weaponHolder = "GroundWeaponHolder_Scripted" createVehicle _pos;
			//_weaponHolder addMagazineCargo [_loadedMag, 1];
		};
	};
};
*/

_unit removeWeapon "RC_60mm_ULM_Bag";
//_unit removeWeapon "twc_2inch_bag";