params ["_vic"];

private _com = commander _vic;


if ((driver _vic) isNotEqualTo objNull) then {
	_vic deleteVehicleCrew (driver _vic);
};
private _driver = createAgent [(typeOf _com), [0,0,0], [], 0, "NONE"];
_driver allowDamage false;
//_driver hideObjectGlobal true;
_driver moveInDriver _vic;
//_driver setBehaviour "COMBAT";


_vic setOwner (owner _com);
[_vic, _com] remoteExec ['setEffectiveCommander', 0];

private _crew = (crew _vic) select {isPlayer _x};
['commander took drive controls'] remoteExec ['systemChat', _crew];