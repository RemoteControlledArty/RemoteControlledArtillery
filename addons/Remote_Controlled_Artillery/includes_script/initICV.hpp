init=
"(_this select 0) spawn { \
	{_this animate [_x, 1]} forEach ['HideHull','HideTurret']; \
}; \
if (!local (_this select 0)) exitwith {}; \
(_this select 0) spawn { \
	waitUntil {!isNull commander _this}; \
	_this deleteVehicleCrew commander _this; \
};";