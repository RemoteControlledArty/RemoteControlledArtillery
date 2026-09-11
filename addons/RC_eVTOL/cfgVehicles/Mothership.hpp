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
