params ['_vic'];
if (isPlayer (gunner _vic)) then {
	(group (driver _vic)) setGroupOwner (owner (gunner _vic));
	_vic setEffectiveCommander (gunner _vic);
};