params ['_vic'];

systemchat str time;
//(driver _vic) action ["SuspendVehicleControl", _vic];
(gunner _vic) action ["TakeVehicleControl", _vic];
//[_vic, 'took pilot controls'] remoteExec ['vehicleChat', 0];