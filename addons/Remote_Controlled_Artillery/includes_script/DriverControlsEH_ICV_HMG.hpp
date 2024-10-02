getin=
"params ['_vehicle']; \
if (isPlayer (_vehicle turretUnit [1])) then { \
	(group (driver _vehicle)) setGroupOwner (owner (_vehicle turretUnit [1])); \
	_vehicle setOwner (owner (_vehicle turretUnit [1])); \
	_vehicle setEffectiveCommander (_vehicle turretUnit [1]); \
} else { \
	if (isPlayer (_vehicle turretUnit [0])) then { \
		(group (driver _vehicle)) setGroupOwner (owner (_vehicle turretUnit [0])); \
		_vehicle setOwner (owner (_vehicle turretUnit [0])); \
		_vehicle setEffectiveCommander (_vehicle turretUnit [0]); \
	} \
};";

getout=
"params ['_vehicle']; \
if (isPlayer (_vehicle turretUnit [1])) then { \
	(group (driver _vehicle)) setGroupOwner (owner (_vehicle turretUnit [1])); \
	_vehicle setOwner (owner (_vehicle turretUnit [1])); \
	_vehicle setEffectiveCommander (_vehicle turretUnit [1]); \
} else { \
	if (isPlayer (_vehicle turretUnit [0])) then { \
		(group (driver _vehicle)) setGroupOwner (owner (_vehicle turretUnit [0])); \
		_vehicle setOwner (owner (_vehicle turretUnit [0])); \
		_vehicle setEffectiveCommander (_vehicle turretUnit [0]); \
	} \
};";

seatswitched=
"params ['_vehicle']; \
if (isPlayer (_vehicle turretUnit [1])) then { \
	(group (driver _vehicle)) setGroupOwner (owner (_vehicle turretUnit [1])); \
	_vehicle setOwner (owner (_vehicle turretUnit [1])); \
	_vehicle setEffectiveCommander (_vehicle turretUnit [1]); \
} else { \
	if (isPlayer (_vehicle turretUnit [0])) then { \
		(group (driver _vehicle)) setGroupOwner (owner (_vehicle turretUnit [0])); \
		_vehicle setOwner (owner (_vehicle turretUnit [0])); \
		_vehicle setEffectiveCommander (_vehicle turretUnit [0]); \
	} \
};";