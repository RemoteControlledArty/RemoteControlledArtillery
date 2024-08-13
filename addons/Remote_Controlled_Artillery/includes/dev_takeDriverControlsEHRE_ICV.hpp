ControlsShifted="params ['_vehicle', '_activeCoPilot', '_oldController']; [ \
	if ((_oldController == gunner _vehicle)) then { \
		systemChat 'ControlsShifted Gunner'; \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} else { \
		if ((_oldController _vehicle == commander _vehicle)) then { \
			systemChat 'ControlsShifted Commander'; \
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
			_vehicle setOwner (owner (commander _vehicle)); \
			_vehicle setEffectiveCommander (commander _vehicle); \
		} \
	} \
] remoteExec ['spawn', 2];";