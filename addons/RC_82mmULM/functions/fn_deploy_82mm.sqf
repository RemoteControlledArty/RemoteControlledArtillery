params ["_unit"];

if ((secondaryWeapon _unit != "RC_82mm_ULM_Bag") || !(local _unit) || !(isPlayer _unit) || (vehicle player != player)) exitwith {};

if (weaponLowered _unit) then {_unit switchMove "amovpercmstpslowwrfldnon"};

private _dir = getDir _unit;
private _height = (getPos _unit) select 2;
private _pos = _unit getPos [0.1, _dir];
private _mortar = "RC_82mm_ULM_Vic" createVehicle _pos;


[_mortar, _pos] call RC_82mmULM_fnc_setPosAGLS;
_mortar setDir _dir;
if ((getPosATL _unit) isEqualTo (getPos _unit)) then {
	_mortar setVectorUp (surfaceNormal _pos)
} else {
	_mortar setVectorUp (vectorUp _unit)
};
_mortar setVariable ["ace_mk6mortar_exclude", true];	//???


_unit assignAsGunner _mortar;
_unit moveInGunner _mortar;


private _magazines = magazines _unit;
private _HECount = {_x == "RC_ULM_1Rnd_82mm_Mo_shells"} count _magazines;
private _HEABCount = {_x == "RC_ULM_1Rnd_82mm_Mo_HEAB"} count _magazines;
private _smokeCount = {_x == "RC_ULM_1Rnd_82mm_Mo_Smoke"} count _magazines;

private _MpMgCount = {_x == "RC_ULM_1Rnd_82mm_Mo_MultiGuided"} count _magazines;
private _MpLgCount = {_x == "RC_ULM_1Rnd_82mm_Mo_LaserGuided"} count _magazines;
private _MpLgDfCount = {_x == "RC_ULM_1Rnd_82mm_Mo_LG_DelayedFuse"} count _magazines;
//_MpLgDfCount = {_x == "RC_ULM_1Rnd_MP_NLOS_Nano"} count _magazines;

private _mineCount = {_x == "RC_ULM_1Rnd_82mm_Mo_mine"} count _magazines;
private _ATmineCount = {_x == "RC_ULM_1Rnd_82mm_Mo_AT_mine"} count _magazines;
private _IllumCount = {_x == "RC_ULM_1Rnd_82mm_Mo_Illum"} count _magazines;
private _loadedMag = (secondaryWeaponMagazine _unit) select 0;


switch (_loadedMag) do
{
	case "RC_ULM_1Rnd_82mm_Mo_shells": {_HECount = _HECount + 1};
	case "RC_ULM_1Rnd_82mm_Mo_HEAB": {_HEABCount = _HEABCount + 1};
	case "RC_ULM_1Rnd_82mm_Mo_Smoke": {_smokeCount = _smokeCount + 1};

	case "RC_ULM_1Rnd_82mm_Mo_MultiGuided": {_MpMgCount = _MpMgCount + 1};
	case "RC_ULM_1Rnd_82mm_Mo_LaserGuided": {_MpLgCount = _MpLgCount + 1};
	case "RC_ULM_1Rnd_82mm_Mo_LG_DelayedFuse": {_MpLgDfCount = _MpLgDfCount + 1};
	//case "RC_ULM_1Rnd_MP_NLOS_Nano": {_MpLgDfCount = _MpLgDfCount + 1};

	case "RC_ULM_1Rnd_82mm_Mo_mine": {_mineCount = _mineCount + 1};
	case "RC_ULM_1Rnd_82mm_Mo_AT_mine": {_ATmineCount = _mineCount + 1};
	case "RC_ULM_1Rnd_82mm_Mo_Illum": {_IllumCount = _IllumCount + 1};
	default {};
};


for "_i" from 1 to _HECount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_shells", [0]];};
for "_i" from 1 to _HEABCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_HEAB", [0]];};
for "_i" from 1 to _smokeCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_Smoke", [0]];};

for "_i" from 1 to _MpMgCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_MultiGuided", [0]];};
for "_i" from 1 to _MpLgCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_LaserGuided", [0]];};
for "_i" from 1 to _MpLgDfCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_LG_DelayedFuse", [0]];};
//for "_i" from 1 to _MpLgDfCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_MP_NLOS_Nano", [0]];};

for "_i" from 1 to _mineCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_mine", [0]];};
for "_i" from 1 to _ATmineCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_AT_mine", [0]];};
for "_i" from 1 to _IllumCount do {_mortar addMagazineTurret ["RC_ULM_1Rnd_82mm_Mo_Illum", [0]];};


if !(isNil "_loadedMag") then {
	private _mass = getNumber (configFile >> "CfgMagazines" >> _loadedMag >> "mass");

		if (((1 - loadVest _unit) * (getContainerMaxLoad vest _unit) > _mass)
		or ((1 - loadBackpack _unit) * (getContainerMaxLoad backpack _unit) > _mass)
		or ((1 - loadUniform _unit) * (getContainerMaxLoad uniform _unit) > _mass)) then {

		_unit addMagazine [_loadedMag, 1];
	} else {
		_mortar setVariable ["RC_82mm_ULM_LoadedMag", _loadedMag, true];
	};
};


_unit removeWeapon "RC_82mm_ULM_Bag";


/*
switch (true) do
	{
		//original, idk if it makes more or less sence
		case ((1- loadVest _unit) * (getContainerMaxLoad vest _unit) > _mass);
		case ((1- loadBackpack _unit) * (getContainerMaxLoad backpack _unit) > _mass);
		case ((1- loadUniform _unit) * (getContainerMaxLoad uniform _unit) > _mass): {_unit addMagazine [_loadedMag, 1];};

		default {_mortar setVariable ["RC_60mm_ULM_LoadedMag", _loadedMag, true];
			//_weaponHolder = "GroundWeaponHolder_Scripted" createVehicle _pos;
			//_weaponHolder addMagazineCargo [_loadedMag, 1];
		};
	};
*/

/*
_unit selectWeapon [weapon, muzzle, firemode];

_unit action ["SWITCHWEAPON", _mortar, _mortar, 3]
*/

/*
_weapon = currentWeapon player;
_ammo = player ammo _weapon;
player setAmmo [_weapon, 0];
player forceWeaponFire [_weapon, "FullAuto"];
player setAmmo [_weapon, _ammo];
*/