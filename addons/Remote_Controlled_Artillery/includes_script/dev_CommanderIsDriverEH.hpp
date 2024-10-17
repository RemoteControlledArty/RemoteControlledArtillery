getin=
"'GetIn' remoteExec ['systemChat',0]; \
params ['_vehicle']; \
if (isPlayer (commander _vehicle)) then { \
	(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
	_vehicle setOwner (owner (commander _vehicle)); \
	_vehicle setEffectiveCommander (commander _vehicle); \
} else { \
	if (isPlayer (gunner _vehicle)) then { \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} \
};";

getout=
"'GetOut' remoteExec ['systemChat',0]; \
params ['_vehicle']; \
if (isPlayer (commander _vehicle)) then { \
	(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
	_vehicle setOwner (owner (commander _vehicle)); \
	_vehicle setEffectiveCommander (commander _vehicle); \
} else { \
	if (isPlayer (gunner _vehicle)) then { \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} \
};";

seatswitched=
"'SeatSwitched' remoteExec ['systemChat',0]; \
params ['_vehicle']; \
if (isPlayer (commander _vehicle)) then { \
	(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
	_vehicle setOwner (owner (commander _vehicle)); \
	_vehicle setEffectiveCommander (commander _vehicle); \
} else { \
	if (isPlayer (gunner _vehicle)) then { \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} \
};";