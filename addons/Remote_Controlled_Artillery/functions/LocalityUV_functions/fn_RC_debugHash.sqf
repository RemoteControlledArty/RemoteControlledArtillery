params ["_uav", "_RCLocalHash"];

if (isNil "_RCLocal") then {
    _RCLocal = getNumber (configFile >> "CfgVehicles" >> _uavClass >> "RC_Local");
    _RCLocalHash set [_uavClass, _RCLocal];
};