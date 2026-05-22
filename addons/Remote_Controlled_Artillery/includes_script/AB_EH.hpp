init = "params ['_p']; \
if (!local _p) exitwith {}; \
[_p] spawn { \
	params ['_p']; \
	sleep 0.024; \
	while { alive _p } do { \
		if ((nearestObjects [_p, ['Air','LaserTarget'], 5]) isNotEqualTo []) exitWith { \
			triggerAmmo _p; \
		}; \
	}; \
};";