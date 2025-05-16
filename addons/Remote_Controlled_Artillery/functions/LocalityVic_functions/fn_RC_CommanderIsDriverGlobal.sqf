params ['_vic'];
if (isPlayer (commander _vic)) then {
	(group (driver _vic)) setGroupOwner (owner (commander _vic));
	_vic setEffectiveCommander (commander _vic);
};