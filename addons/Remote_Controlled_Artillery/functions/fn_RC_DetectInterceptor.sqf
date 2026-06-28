/*
	Author: Ascent

	Description:
	DetectInterceptor
*/

//params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
params ["_source", "_proj", "_mag"];

if (({alive _x} count RC_DetectInterceptor_Array) <= 0) exitwith {};

//cleans up DetectInterceptor arrays
RC_DetectInterceptor_Array = RC_DetectInterceptor_Array - [objNull];
publicVariable "RC_DetectInterceptor_Array";

{
	private _vic = _x;
	private _opposedTo = [side _source, side _vic] call BIS_fnc_sideIsEnemy;

	if (_opposedTo) then {

		[_vic, _source, _proj, _mag] call RC_fnc_RC_DetectInterceptor_Activate;
	};

} forEach RC_DetectInterceptor_Array;