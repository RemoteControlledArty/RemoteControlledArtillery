class RC_UCAV_Base;
class RC_MosquitoMothership_Fetch: RC_UCAV_Base
{
	class EventHandlers;
	class Components;
	class TransportPylonsComponent;
	class pylons;
    class pylon1;
    class pylon2;
};
class RC_MosquitoMothership_Core: RC_MosquitoMothership_Fetch
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

    camouflage=75;				//150
    //audible=?;                //?  
	radarTargetSize=0.1;		//0.15
	visualTargetSize=0.3;		//0.9
	irTargetSize=0.3;			//0.8
	
	displayName="RC Mosquito Mothership";
	editorSubcategory="RC_eVTOL_subcat";
};
class RC_MosquitoMothership_Base: RC_MosquitoMothership_Core
{
};


class RC_MosquitoMothership_B: RC_MosquitoMothership_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Attach
		{
			init="if (!isServer) exitwith {}; params ['_entity']; [_entity] spawn fnc_RC_eVTOL_attachToMothership";
		};
	};

	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_MosquitoMothership_O: RC_MosquitoMothership_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_MosquitoMothership_I: RC_MosquitoMothership_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};


class RC_MosquitoMothership_Minigun_B: RC_MosquitoMothership_B
{
	class EventHandlers: EventHandlers
	{
		class RC_Attach
		{
			init="if (!isServer) exitwith {}; params ['_entity']; [_entity] spawn fnc_RC_eVTOL_attachToMothership_Minigun";
		};
	};

	displayName="RC Minigun Mosquito Mothership [no camera]";
};
class RC_MosquitoMothership_Minigun_O: RC_MosquitoMothership_Minigun_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_MosquitoMothership_Minigun_I: RC_MosquitoMothership_Minigun_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};


//no turret freecam / ir sensors
class RC_UCAV_NoCam_Base;
class RC_MosquitoMothership_NoCam_Fetch: RC_UCAV_NoCam_Base
{
	class EventHandlers;
	class Components;
	class TransportPylonsComponent;
	class pylons;
    class pylon1;
    class pylon2;
};
class RC_MosquitoMothership_NoCam_Core: RC_MosquitoMothership_NoCam_Fetch
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

    camouflage=75;				//150
    //audible=?;                //?  
	radarTargetSize=0.1;		//0.15
	visualTargetSize=0.3;		//0.9
	irTargetSize=0.3;			//0.8
	
	displayName="RC Mosquito Mothership [no camera]";
	editorSubcategory="RC_eVTOL_subcat";
};
class RC_MosquitoMothership_NoCam_Base: RC_MosquitoMothership_NoCam_Core
{
};


class RC_MosquitoMothership_NoCam_B: RC_MosquitoMothership_NoCam_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Attach
		{
			init="if (!isServer) exitwith {}; params ['_entity']; [_entity] spawn fnc_RC_eVTOL_attachToMothership";
		};
	};

	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_MosquitoMothership_NoCam_O: RC_MosquitoMothership_NoCam_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_MosquitoMothership_NoCam_I: RC_MosquitoMothership_NoCam_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};


class RC_MosquitoMothership_NoCam_Minigun_B: RC_MosquitoMothership_NoCam_B
{
	class EventHandlers: EventHandlers
	{
		class RC_Attach
		{
			init="if (!isServer) exitwith {}; params ['_entity']; [_entity] spawn fnc_RC_eVTOL_attachToMothership_Minigun";
		};
	};

	displayName="RC Minigun Mosquito Mothership [no camera]";
};
class RC_MosquitoMothership_NoCam_Minigun_O: RC_MosquitoMothership_NoCam_Minigun_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_MosquitoMothership_NoCam_Minigun_I: RC_MosquitoMothership_NoCam_Minigun_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};
