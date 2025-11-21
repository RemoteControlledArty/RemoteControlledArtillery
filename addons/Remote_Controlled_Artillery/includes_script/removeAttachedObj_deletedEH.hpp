deleted="if (!isserver) exitwith {}; \
params ['_entity']; \
private _attObj = (attachedObjects _entity); \
if (count _attObj > 0) then { \
	{deleteVehicle _x} forEach _attObj; \
};";