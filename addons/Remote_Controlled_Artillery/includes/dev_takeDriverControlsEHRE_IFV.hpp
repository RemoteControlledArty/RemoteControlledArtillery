ControlsShifted="params ['_vehicle', '_activeCoPilot', '_oldController']; [ \
	if ((_activeCoPilot == gunner _vehicle)) then { \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} else { \
		if ((_activeCoPilot _vehicle == commander _vehicle)) then { \
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
			_vehicle setOwner (owner (commander _vehicle)); \
			_vehicle setEffectiveCommander (commander _vehicle); \
		} \
	} \
] remoteExec ['spawn', 2];";