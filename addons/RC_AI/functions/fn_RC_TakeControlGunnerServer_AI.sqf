params ["_vic"];

private _gun = gunner _vic;
//private _gunID = owner _gun;
[_vic, _gun] remoteExec ['setEffectiveCommander', 0];

private _crew = (crew _vic) select {isPlayer _x};
['gunner took drive controls'] remoteExec ['systemChat', _crew];