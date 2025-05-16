params ["_uav"];

if (_uav isEqualto objNull) then {
    continue;
};

if (local _uav) then {
    continue;
};