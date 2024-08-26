ControlsShifted="params ['_vehicle', '_activeCoPilot', '_oldController']; \
if ((isPlayer _oldController) && (_oldController isEqualTo commander _vehicle)) then { \
	systemChat 'ControlsShifted Commander'; \
	(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
	_vehicle setOwner (owner (commander _vehicle)); \
	_vehicle setEffectiveCommander (commander _vehicle); \
} else { \
	if (_activeCoPilot isEqualTo gunner _vehicle) then { \
		systemChat 'ControlsShifted Gunner'; \
		(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
		_vehicle setOwner (owner (gunner _vehicle)); \
		_vehicle setEffectiveCommander (gunner _vehicle); \
	} \
};";
