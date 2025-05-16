params ["_uav"];

if (_uav isEqualto objNull) then {
    [player, "_uav isEqualto objNull"] remoteExec ['globalChat', clientOwner];
    continue;
};

if (local _uav) then {
    [player, "_uav is already local"] remoteExec ['globalChat', clientOwner];
    continue;
} else {
    [player, "_uav != local"] remoteExec ['globalChat', clientOwner];
};