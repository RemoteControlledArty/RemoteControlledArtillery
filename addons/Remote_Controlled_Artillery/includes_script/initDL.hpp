init=
"if (!local (_this select 0)) exitwith {}; \
(_this select 0) spawn { \
	while {true} do { \
		_speedCheck1 = false; \
		_speedCheck2 = false; \
		if ((speed _this <= 0.1) and (speed _this >= -0.1)) then { \
			_speedCheck1 = true \
		} else { \
			_speedCheck1 = false \
		}; \
		sleep 6; \
		if ((speed _this <= 0.1) and (speed _this >= -0.1)) then { \
			_speedCheck2 = true \
		} else { \
			_speedCheck2 = false \
		}; \
		if ((_speedCheck1) and (_speedCheck2)) then { \
			[_this engineOn false] remoteExec ['spawn', 2] \
		}; \
	}; \
};	\
(_this select 0) setHitPointDamage ['Light_L', 1]; \
(_this select 0) setHitPointDamage ['Light_R', 1]; \
";