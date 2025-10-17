params ["_vic","_name"];

/*
private _grp = grpNull;

if (!isNull (driver _vic)) then {
	_grp = group (driver _vic);
} else {
	_grp = group (gunner _vic);
};
*/

private _grp = group _vic;
private _uniqueName = [_name] call RC_fnc_RC_getUniqueGroupName;
_grp setGroupIdGlobal [_uniqueName];