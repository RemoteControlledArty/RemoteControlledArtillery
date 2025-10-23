//MPKilled
Killed=
"params ['_unit']; \
if (!local _unit) exitwith {}; \
(_unit) spawn { \
	sleep 3; \
	player remoteControl objNull; \
	systemChat 'lost connection to OM-H'; \
};";