getin=
"'GetIn' remoteExec ['systemChat',0]; \
params ['_vehicle']; [ \
	if (isPlayer (gunner _vehicle)) then { \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} else { \
		if (isPlayer (commander _vehicle)) then { \
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
			_vehicle setOwner (owner (commander _vehicle)); \
			_vehicle setEffectiveCommander (commander _vehicle); \
		} \
	} \
] remoteExec ['spawn', 2];";

getout=
"'GetOut' remoteExec ['systemChat',0]; \
params ['_vehicle']; [ \
	if (isPlayer (gunner _vehicle)) then { \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} else { \
		if (isPlayer (commander _vehicle)) then { \
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
			_vehicle setOwner (owner (commander _vehicle)); \
			_vehicle setEffectiveCommander (commander _vehicle); \
		} \
	} \
] remoteExec ['spawn', 2];";

seatswitched=
"'SeatSwitched' remoteExec ['systemChat',0]; \
params ['_vehicle']; [ \
	if (isPlayer (gunner _vehicle)) then { \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} else { \
		if (isPlayer (commander _vehicle)) then { \
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
			_vehicle setOwner (owner (commander _vehicle)); \
			_vehicle setEffectiveCommander (commander _vehicle); \
		} \
	} \
] remoteExec ['spawn', 2];";