init=
"if (!local (_this select 0)) exitwith {}; \
(_this select 0) spawn { \
	waitUntil {!isNull gunner _this}; \
	_this deleteVehicleCrew gunner _this; \
};";