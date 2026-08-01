params ['_vic'];

systemchat str time;
//(gunner _vic) action ["SuspendVehicleControl", _vic];
(driver _vic) action ["TakeVehicleControl", _vic];
//[_vic, 'took pilot controls'] remoteExec ['vehicleChat', 0];