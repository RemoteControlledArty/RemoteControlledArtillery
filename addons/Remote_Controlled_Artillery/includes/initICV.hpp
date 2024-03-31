init=
"(_this select 0) spawn { \
	{_this animate [_x, 1]} forEach ['HideHull','HideTurret']; \
}; \
if (!local (_this select 0)) exitwith {}; \
(_this select 0) spawn { \
	waitUntil {!isNull commander _this}; \
	_this deleteVehicleCrew commander _this; \
}; \
(_this select 0) spawn { \
	while {true} do { \
		_speedCheck1 = false; \
		_speedCheck2 = false; \
		if ((speed _this <= 0.1) and (speed _this >= -0.1)) then { \
			_speedCheck1 = true \
		} else { \
			_speedCheck1 = false \
		}; \
		sleep 4; \
		if ((speed _this <= 0.1) and (speed _this >= -0.1)) then { \
			_speedCheck2 = true \
		} else { \
			_speedCheck2 = false \
		}; \
		if ((_speedCheck1) and (_speedCheck2)) then { \
			_this engineOn false \
		}; \
	}; \
};";