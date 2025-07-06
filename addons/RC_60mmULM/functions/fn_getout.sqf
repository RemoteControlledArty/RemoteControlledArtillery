params ["_vehicle", "_role", "_unit", "_turret"];

if !(local _vehicle) exitWith {};

_loadedMag = _vehicle getVariable ["TWC_2inch_LoadedMag", ""];

_magazines = magazines [_vehicle, false];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_shells_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_HEAB_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_Smoke_white_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_Flare_white_ULM", [0]];

_unit removeMagazines "RC_1Rnd_60mm_Mo_shells_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_HEAB_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_Smoke_white_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_Flare_white_ULM";
{
	_unit addMagazine [_x, 1];
} forEach _magazines;

deleteVehicle _vehicle;

//_unit addWeapon "RC_60mm_ULM_Bag";
_unit addWeapon "twc_2inch_bag";
if (_loadedMag != "") then {
	_unit addMagazine [_loadedMag, 1];
};