/*
	Author: Ascent

	Description:
	Dazzler
*/

params ["_vic", "_proj"];

//systemchat "Dazzler start";	//debug

private _hasDazzler = {_x isEqualTo "RC_1Rnd_Dazzler_M"} count (_vic magazinesTurret [-1]);

if (_hasDazzler > 0) then {

	//systemchat "_hasDazzler true";	//debug

	private _isMissile = (getText (configFile >> "CfgAmmo" >> typeOf _proj >> "simulation")) isEqualTo "shotMissile";

	if (_isMissile) then {
		[_vic, _proj] remoteExec ["RC_fnc_RC_Dazzler_Server", 2];
	};
};