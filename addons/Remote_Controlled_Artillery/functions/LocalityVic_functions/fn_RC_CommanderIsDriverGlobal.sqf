params ['_vic'];

private _com = commander _vic;

if (isPlayer _com) then {
	(group (driver _vic)) setGroupOwner (owner _com);
	_vic setEffectiveCommander _com;
};