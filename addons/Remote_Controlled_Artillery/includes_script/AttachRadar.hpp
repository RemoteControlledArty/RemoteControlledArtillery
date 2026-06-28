init="if (!isserver) exitwith {}; \
(_this select 0) spawn { \
	private _radar = 'SatelliteAntenna_01_Small_Mounted_Olive_F' createVehicle [0,0,0]; \
	_radar attachTo [_this, [0.184,-0.23,0.125], 'OtocHlaven', true];  \
	_radar setVectorDirAndUp [[0.018,0.001,1],[-0.019,1,-0.0006]];	\
};";
//[0.184,-0.19,0.04]


deleted="if (!isserver) exitwith {}; \
params ['_entity']; \
private _attObj = (attachedObjects _entity); \
if (count _attObj > 0) then { \
	{deleteVehicle _x} forEach _attObj; \
};";


killed="params ['_unit']; \
private _attObj = (attachedObjects _unit); \
if (count _attObj > 0) then { \
	{deleteVehicle _x} forEach _attObj; \
};";