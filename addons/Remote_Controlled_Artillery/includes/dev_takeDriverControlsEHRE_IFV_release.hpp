ControlsShifted="params ['_vehicle', '_activeCoPilot', '_oldController']; [ \
	if ((isPlayer _activeCoPilot) && _activeCoPilot isEqualTo gunner _vehicle) then { \
		systemChat 'ControlsShifted Gunner'; \
		_activeCoPilot action ['SuspendVehicleControl', _vehicle]; \
	} else { \
		if ((isPlayer _activeCoPilot) && (_activeCoPilot isEqualTo commander _vehicle)) then { \
		systemChat 'ControlsShifted Commander'; \	
		_activeCoPilot action ['SuspendVehicleControl', _vehicle]; \
		} \
	} \
] remoteExec ['spawn', 2];";