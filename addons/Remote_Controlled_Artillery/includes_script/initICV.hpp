init=
"(_this select 0) spawn { \
	{_this animate [_x, 1]} forEach ['HideHull','HideTurret']; \
}; \
if (!local (_this select 0)) exitwith {}; \
(_this select 0) spawn { \
	waitUntil {!isNull commander _this}; \
	_this deleteVehicleCrew commander _this; \
	\
	_this setHitPointDamage ['#light_l', 1]; \
	_this setHitPointDamage ['#light_r', 1]; \
	_this setHitPointDamage ['#light_l_flare', 1]; \
	_this setHitPointDamage ['#light_r_flare', 1]; \
	_this setHitPointDamage ['#light_l2_flare', 1]; \
	_this setHitPointDamage ['#light_r2_flare', 1]; \
	_this setHitPointDamage ['hit_light_l', 1]; \
	_this setHitPointDamage ['hit_light_r', 1]; \
	_this setHitPointDamage ['hit_lightl', 1]; \
	_this setHitPointDamage ['hit_lightr', 1]; \
};";