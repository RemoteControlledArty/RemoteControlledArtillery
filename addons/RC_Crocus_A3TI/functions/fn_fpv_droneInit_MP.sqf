params ["_uav"];

waitUntil {time > 1};

_uav disableTIEquipment true;
_uav setVariable ["DB_jammer_customUavBehavior", true, true];

