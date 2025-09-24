params ["_vic"];

private _gun = gunner _vic;


_vic deleteVehicleCrew (driver _vic);
private _driver = createAgent [(typeOf _gun), [0,0,0], [], 0, "NONE"];
_driver allowDamage false;
//_driver hideObjectGlobal true;
_driver moveInDriver _vic;
//_driver setBehaviour "COMBAT";


_vic setOwner (owner _gun);
[_vic, _gun] remoteExec ['setEffectiveCommander', 0];

private _crew = (crew _vic) select {isPlayer _x};
['gunner took drive controls'] remoteExec ['systemChat', _crew];