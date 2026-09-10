class RC_UCAV_Base;
class RC_InsertionMothership_Fetch: RC_UCAV_Base
{
	class EventHandlers;
	class Components;
	class TransportPylonsComponent;
	class pylons;
    class pylon1;
    class pylon2;
};
class RC_InsertionMothership_Core: RC_InsertionMothership_Fetch
{
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

    class Components: Components
	{
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				class pylon1: pylon1
				{
					attachment="";
				};
   				class pylon2: pylon2
				{
					attachment="";
				};
			};
		};
	};
	
	displayName="RC Insertion Mothership";
	editorSubcategory="RC_eVTOL_subcat";
};
class RC_InsertionMothership_Base: RC_InsertionMothership_Core
{
};


class RC_InsertionMothership_B: RC_InsertionMothership_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Attach
		{
			init="if (!isServer) exitwith {}; \
			(_this select 0) spawn { \
				private _eVTOL1 = 'RC_eVTOL_B' createVehicle [0,0,500]; \
				_eVTOL1 attachTo [_this, [-3.8, 1.3, -0.6], 'wing_fold_r', true];  \
				private _eVTOL2 = 'RC_eVTOL_B' createVehicle [5,0,500]; \
				_eVTOL2 attachTo [_this, [3.8, 1.3, -0.6], 'wing_fold_l', true];  \
			};";
		};
	};
	/*
	selectionNames (getConnectedUAV player);
	(getConnectedUAV player) animate ["wing_fold_r",1];
	(getConnectedUAV player) animate ["wing_fold_r_arm",1];

	private _offset = (getConnectedUAV player) worldToModel (ASLToAGL (getPosASL (vehicle player)));
	copyToClipboard str _offset;
	hint str _offset;
	[-5.14209,-2.40117,-1.09293]

	private _obj1 = (vehicle player);
	private _obj2 = (getConnectedUAV player);
	private _offset = (_obj2 worldToModel (ASLToAGL (getPosASL _obj1))) vectorDiff (_obj2 selectionPosition "wing_fold_l");
	copyToClipboard str _offset;
	hint str _offset;

	private _obj1 = (vehicle player);
	private _obj2 = (getConnectedUAV player);
	private _offset = (_obj2 worldToModel (getPos _obj1)) vectorDiff (_obj2 selectionPosition "wing_fold_l");
	copyToClipboard str _offset;
	hint str _offset;

	[3.77412,1.27356,-1.48752]
	(vehicle player) attachTo [(getConnectedUAV player), [-3.77412,1.27356,-0.6], 'wing_fold_r', true];

	(getConnectedUAV player) animate ["wing_fold_l", 1];
	*/

	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_InsertionMothership_O: RC_InsertionMothership_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_InsertionMothership_I: RC_InsertionMothership_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};


//no turret freecam / ir sensors
class RC_UCAV_NoCam_Base;
class RC_InsertionMothership_NoCam_Fetch: RC_UCAV_NoCam_Base
{
	class EventHandlers;
	class Components;
	class TransportPylonsComponent;
	class pylons;
    class pylon1;
    class pylon2;
};
class RC_InsertionMothership_NoCam_Core: RC_InsertionMothership_NoCam_Fetch
{
	class EventHandlers: EventHandlers
	{
		class RC_FlyInHeight
		{
			postInit="params ['_entity'];  _entity flyInHeight 4000;";	//flyInHeight = where local argument, global effect
		};
		/*
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
		*/
	};

	class Components: Components
	{
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				class pylon1: pylon1
				{
					attachment="";
				};
   				class pylon2: pylon2
				{
					attachment="";
				};
			};
		};
	};
	
	displayName="RC Insertion Mothership [no camera]";
	editorSubcategory="RC_eVTOL_subcat";
};
class RC_InsertionMothership_NoCam_Base: RC_InsertionMothership_NoCam_Core
{
};


class RC_InsertionMothership_NoCam_B: RC_InsertionMothership_NoCam_Base
{
	/*
	class EventHandlers: EventHandlers
	{
		class RC_Attach
		{
			init="if (!isserver) exitwith {}; \
			(_this select 0) spawn { \
				private _eVTOL1 = 'RC_eVTOL_B' createVehicle [0,0,500]; \
				_eVTOL1 attachTo [_this, [0.184,-0.23,0.125]];  \
				private _eVTOL2 = 'RC_eVTOL_B' createVehicle [5,0,500]; \
				_eVTOL2 attachTo [_this, [0.184,-0.23,0.125]];  \
			};";
		};
	};
	*/

	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_InsertionMothership_NoCam_O: RC_InsertionMothership_NoCam_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_InsertionMothership_NoCam_I: RC_InsertionMothership_NoCam_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};