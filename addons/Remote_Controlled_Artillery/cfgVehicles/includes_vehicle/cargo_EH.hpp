class RC_Cargo
{
	postInit="params ['_veh']; \
	[('RC_PortableRepairWelder' createVehicle [0,0,1000]), _veh, true] call ace_cargo_fnc_loadItem; \
	[('RC_PortableFuelTank' createVehicle [0,0,900]), _veh, true] call ace_cargo_fnc_loadItem;";
};