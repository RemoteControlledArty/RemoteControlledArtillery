ControlsShifted="params ['_vehicle', '_activeCoPilot', '_oldController']; \
if ((isPlayer _activeCoPilot) && _activeCoPilot isEqualTo gunner _vehicle) then { \
	systemChat 'ControlsShifted Gunner'; \
	call fn_RC_TakeControls; \
} else { \
	if ((isPlayer _activeCoPilot) && (_activeCoPilot isEqualTo commander _vehicle)) then { \
	systemChat 'ControlsShifted Commander'; \	
	call fn_RC_TakeControls; \
	} \
};";
