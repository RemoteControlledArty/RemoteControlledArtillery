params ["_vic"];

private _com = commander _vic;
//_comID = owner _com;
[_vic, _com] remoteExec ['setEffectiveCommander', 0];

private _crew = (crew _vic) select {isPlayer _x};
['commander took drive controls'] remoteExec ['systemChat', _crew];