init=
"if (!local (_this select 0)) exitwith {}; \
(_this select 0) spawn { \
	waitUntil {!isNull commander _this}; \
    _this deleteVehicleCrew (_this turretUnit [1]); \
	_this deleteVehicleCrew (_this turretUnit [0]); \
};";