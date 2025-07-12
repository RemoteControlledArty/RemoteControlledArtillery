params ["_vehicle", "_role", "_unit", "_turret"];

if !(local _vehicle) exitWith {};

_loadedMag = _vehicle getVariable ["RC_60mm_ULM_LoadedMag", ""];


_magazines = magazines [_vehicle, false];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_shells_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_HEAB_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_backupHEAB_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_Smoke_white_ULM", [0]];

_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_MultiGuided_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_LaserGuided_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM", [0]];

_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_mine_ULM", [0]];
_vehicle removeMagazinesTurret ["RC_1Rnd_60mm_Mo_Flare_white_ULM", [0]];


_unit removeMagazines "RC_1Rnd_60mm_Mo_shells_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_HEAB_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_backupHEAB_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_Smoke_white_ULM";

_unit removeMagazines "RC_1Rnd_60mm_Mo_MultiGuided_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_LaserGuided_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM";

_unit removeMagazines "RC_1Rnd_60mm_Mo_mine_ULM";
_unit removeMagazines "RC_1Rnd_60mm_Mo_Flare_white_ULM";


{
	_unit addMagazine [_x, 1];
} forEach _magazines;


deleteVehicle _vehicle;
_unit addWeapon "RC_60mm_ULM_Bag";
//_unit addWeapon "twc_2inch_bag";
if (_loadedMag != "") then {
	_unit addMagazine [_loadedMag, 1];
};