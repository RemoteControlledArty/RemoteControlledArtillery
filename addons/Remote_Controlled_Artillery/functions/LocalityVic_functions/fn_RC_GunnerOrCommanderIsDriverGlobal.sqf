params ['_vic'];
if (isPlayer (gunner _vic) && (!(isplayer (commander _vic)))) then {
	(group (driver _vic)) setGroupOwner (owner (gunner _vic));
	_vic setEffectiveCommander (gunner _vic);
} else {
	if (isPlayer (commander _vic) && (!(isplayer (gunner _vic)))) then {
		(group (driver _vic)) setGroupOwner (owner (commander _vic));
		_vic setEffectiveCommander (commander _vic);
	}
};