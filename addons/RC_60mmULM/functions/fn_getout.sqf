//systemchat "getout";

params ["_vehicle", "_role", "_unit", "_turret"];

if !(local _vehicle) exitWith {};

_loadedMag = _vehicle getVariable ["RC_60mm_ULM_LoadedMag", ""];


_magazines = magazines [_vehicle, false];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_shells", [0]];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_HEAB", [0]];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_backupHEAB", [0]];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_Smoke", [0]];

_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_MultiGuided", [0]];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_LaserGuided", [0]];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse", [0]];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_MP_NLOS_Nano", [0]];

_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_mine", [0]];
_vehicle removeMagazinesTurret ["RC_ULM_1Rnd_60mm_Mo_Illum", [0]];


_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_shells";
_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_HEAB";
_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_backupHEAB";
_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_Smoke";

_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_MultiGuided";
_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_LaserGuided";
_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse";
_unit removeMagazines "RC_ULM_1Rnd_MP_NLOS_Nano";

_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_mine";
_unit removeMagazines "RC_ULM_1Rnd_60mm_Mo_Illum";

//systemchat "mags removed";


{
	_unit addMagazine [_x, 1];
} forEach _magazines;


//RC_ULM_currentFireMode = currentWeaponMode (gunner _vehicle);


deleteVehicle _vehicle;
_unit addWeapon "RC_60mm_ULM_Bag";
if (_loadedMag != "") then {
	_unit addMagazine [_loadedMag, 1];
};