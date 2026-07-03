/*
	Author: Ascent

	Description:
	DetectInterceptor
*/

//params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
params ["_source", "_proj", "_mag"];


//simplified version until better method is found, cant be bothered to add it to all vehicle cfgEH's and performance might decrease
[_proj] spawn
{
	params ["_proj"];
	while {alive _proj} do {

		if (count (attachedObjects _proj) > 0) exitWith {

			private _target = (attachedObjects _proj)#0;

			//private _side = side _source;
			private _duration = getNumber (configFile >> "CfgAmmo" >> typeOf _proj >> "timeToLive");

			[west, [_target, _duration]] remoteExec ['reportRemoteTarget', west];
			[east, [_target, _duration]] remoteExec ['reportRemoteTarget', east];
			[resistance, [_target, _duration]] remoteExec ['reportRemoteTarget', resistance];

			[_target, [west, true]] remoteExec ['confirmSensorTarget', west];
			[_target, [east, true]] remoteExec ['confirmSensorTarget', east];
			[_target, [resistance, true]] remoteExec ['confirmSensorTarget', resistance];
		};
	};
};


/*
RC_DetectInterceptor_Array + RC_AT_Warning_Array;
_result = _myArray arrayIntersect _myArray;
_combinedArray = arrayUnique (_array1 + _array2);
*/

/*
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
*/