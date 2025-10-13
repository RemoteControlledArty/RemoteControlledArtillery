params ["_vic","_name"];

private _grp = group _vic;
//_grp = group (driver _vic);
_grp setGroupIdGlobal [_name];