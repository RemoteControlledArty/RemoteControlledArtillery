getin=
"params ['_vehicle']; \
if (isPlayer (gunner _vehicle)) then { \
	(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
	_vehicle setEffectiveCommander (gunner _vehicle); \
};";

getout=
"params ['_vehicle']; \
if (isPlayer (gunner _vehicle)) then { \
	(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
	_vehicle setEffectiveCommander (gunner _vehicle); \
};";

seatswitched=
"params ['_vehicle']; \
if (isPlayer (gunner _vehicle)) then { \
	(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
	_vehicle setEffectiveCommander (gunner _vehicle); \
};";