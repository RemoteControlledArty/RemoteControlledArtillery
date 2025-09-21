params ['_vic'];

private _gun = gunner _vic;

if (isPlayer _gun) then {
	(group (driver _vic)) setGroupOwner (owner _gun);
	_vic setEffectiveCommander _gun;
};