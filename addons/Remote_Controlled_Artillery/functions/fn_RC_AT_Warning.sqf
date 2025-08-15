/*
	Author: Ascent

	Description:
	AT_Warning
*/

//params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
params ["_unit", "_projectile"];

private _AT_Warning_AliveAmount = ({alive _x} count RC_AT_Warning_Array);
if (_AT_Warning_AliveAmount <= 0) exitwith {};

//cleans up AT_Warning arrays
RC_AT_Warning_Array = RC_AT_Warning_Array - [objNull];
publicVariable "RC_AT_Warning_Array";

private _source = _unit;

{
	private _vic = _x;
	private _opposedTo = [side _source, side _vic] call BIS_fnc_sideIsEnemy;

	if (_opposedTo) then {
		[_vic, _projectile] call RC_fnc_RC_APS_Activate;
		[_vic, _source] call RC_fnc_RC_AT_Warning_Activate;
	};

} forEach RC_AT_Warning_Array;