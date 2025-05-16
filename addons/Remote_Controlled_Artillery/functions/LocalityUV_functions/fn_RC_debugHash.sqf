params ["_uav"];

if (isNil "_RCLocal") then {
    _RCLocal = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_Local");
    RC_RCLocalHash set [_uavClass, _RCLocal];
};