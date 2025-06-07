init=
"if (!local (_this select 0)) exitwith {}; \
(_this select 0) spawn { \
	waitUntil {!isNull driver _this}; \
	_this deleteVehicleCrew driver _this; \
};";