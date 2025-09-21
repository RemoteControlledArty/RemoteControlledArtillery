params ['_vic'];

private _gun = gunner _vic;
private _com = commander _vic;

if (isPlayer _gun && (!(isplayer _com))) then {
	(group (driver _vic)) setGroupOwner (owner _gun);
	_vic setEffectiveCommander _gun;
} else {
	if (isPlayer _com && (!(isplayer _gun))) then {
		(group (driver _vic)) setGroupOwner (owner _com);
		_vic setEffectiveCommander _com;
	}
};