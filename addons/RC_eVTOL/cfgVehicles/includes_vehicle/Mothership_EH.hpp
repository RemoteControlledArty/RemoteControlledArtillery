class EventHandlers: EventHandlers
{
	class RC_FlyInHeight
	{
		postInit="params ['_entity'];  _entity flyInHeight 4000;";	//flyInHeight = where local argument, global effect
	};
	class RC_Detach
	{
		deleted="if (!isserver) exitwith {}; \
		params ['_entity']; \
		private _attObj = (attachedObjects _entity); \
		if (count _attObj > 0) then { \
			{deleteVehicle _x} forEach _attObj; \
		};";


		killed="params ['_unit']; \
		private _attObj = (attachedObjects _unit); \
		if (count _attObj > 0) then { \
			{_x disableCollisionWith _unit; detach _x} forEach _attObj; \
		};";
	};
};
