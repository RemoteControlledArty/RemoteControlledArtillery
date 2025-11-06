/*
params ["_player", "_mortarVeh"];

if (!(_mortarVeh isKindOf "RC_60mm_ULM_Vic")) exitWith {};

[{
	_display = uiNamespace getVariable ["twc_2inch_RscWeaponRangeArtillery", displayNull];
	_precalcArray = [] call RC_ULM_fnc_rangetable;
	{
		(_display displayCtrl 4215) lnbAddRow _x;
	} forEach _precalcArray;
}, "", 0.5] call CBA_fnc_waitAndExecute;

_handle = [
{
	params ["_args", "_handle"];
	_args params ["_player", "_mortarVeh"];

	if ((vehicle _player) != _mortarVeh) exitWith {[_handle] call CBA_fnc_removePerFrameHandler;};

	_lookVector  = (AGLtoASL (positionCameraToWorld [0,0,0])) vectorFromTo (AGLtoASL (positionCameraToWorld [0,0,1]));
	_weaponDir = _mortarVeh weaponDirection (currentWeapon _mortarVeh);
	_dir = (_lookVector select 0) atan2 (_lookVector select 1);
	_elev = asin (_weaponDir select 2);
	if (_dir < 0) then {_dir = 360 + _dir};
	_dir = round _dir;
	_elev = round(_elev * 6400 / 360);

	_display = uiNamespace getVariable ["twc_2inch_RscWeaponRangeArtillery", displayNull];
	(_display displayCtrl 4213) ctrlSetText str _elev;
	(_display displayCtrl 4214) ctrlSetText str _dir;
}, 0, [_player, _mortarVeh]] call CBA_fnc_addPerFrameHandler;
*/