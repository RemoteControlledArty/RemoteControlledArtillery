/*
	Author: Ascent

	Description:
	AT_Warning
*/

//params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
params ["_unit", "_projectile"];

if (!local _projectile) exitwith {};
//if (!isServer) exitwith {};

//maybe use single array but add radar side check, as that could prevent post spawn side change issues
//checks for opposing AT_Warning vehicles
private _AT_Warning_AliveAmount_B = ({alive _x} count RC_AT_Warning_Array_B);
private _AT_Warning_AliveAmount_O = ({alive _x} count RC_AT_Warning_Array_O);
private _AT_Warning_AliveAmount_I = ({alive _x} count RC_AT_Warning_Array_I);

private _AT_Warning_AliveAmount = _AT_Warning_AliveAmount_B + _AT_Warning_AliveAmount_O + _AT_Warning_AliveAmount_I;
if (!(_AT_Warning_AliveAmount > 0)) exitwith {};


//cleans up AT_Warning arrays
RC_AT_Warning_Array_B = RC_AT_Warning_Array_B - [objNull];
RC_AT_Warning_Array_O = RC_AT_Warning_Array_O - [objNull];
RC_AT_Warning_Array_I = RC_AT_Warning_Array_I - [objNull];

//checks side of the unit which fired
private _unitSide_B = (side _unit == west);
private _unitSide_O = (side _unit == east);
private _unitSide_I = (side _unit == resistance);

//checks opposing sides
private _opposedTo_B = [side _unit, west] call BIS_fnc_sideIsEnemy;
private _opposedTo_O = [side _unit, east] call BIS_fnc_sideIsEnemy;
private _opposedTo_I = [side _unit, resistance] call BIS_fnc_sideIsEnemy;


if (_opposedTo_B and (_AT_Warning_AliveAmount_B > 0)) then {
	{
		private _target = _x;
		[_target, _projectile] call RC_fnc_RC_APS_Activate;
		[_target, _unit] call RC_fnc_RC_AT_Warning_Activate;
		
	} forEach RC_AT_Warning_Array_B;
};
if (_opposedTo_O and (_AT_Warning_AliveAmount_O > 0)) then {
	{
		private _target = _x;
		[_target, _projectile] call RC_fnc_RC_APS_Activate;
		[_target, _unit] call RC_fnc_RC_AT_Warning_Activate;
		
	} forEach RC_AT_Warning_Array_O;
};
if (_opposedTo_I and (_AT_Warning_AliveAmount_I > 0)) then {
	{
		private _target = _x;
		[_target, _projectile] call RC_fnc_RC_APS_Activate;
		[_target, _unit] call RC_fnc_RC_AT_Warning_Activate;
		
	} forEach RC_AT_Warning_Array_I;
};


/*
private _lastTime = _vehicle getVariable "ArtySourceTime";
private _timeSinceLast = time - _lastTime;

if (_timeSinceLast > RC_IgnoreTime_F1) then {
	_vehicle setVariable ["ArtySourceTime", time, true];
};
*/