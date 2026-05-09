class vtx_MH60M_DAP_MLASS;
class RC_MH60M_DAP_MLASS_Core: vtx_MH60M_DAP_MLASS
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_fetch.hpp"
};
class RC_MH60M_DAP_MLASS_Base: RC_MH60M_DAP_MLASS_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_main.hpp"
	editorSubcategory="RC_Heli_armed_subcat";

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_Main.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotView.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamBase.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFixed.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFree.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_hitPoints.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_userActions.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_4pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_copilotTurret.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_cargoTurrets.hpp"
	};
	/*
	class AnimationSources: AnimationSources
	{
		//DOOR
	};
	*/
};


//manned
class RC_MH60M_DAP_MLASS: RC_MH60M_DAP_MLASS_Base
{
	displayName="MH-60M DAP MLASS"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsB.hpp"
};
class RC_MH60M_DAP_MLASS_O: RC_MH60M_DAP_MLASS
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsO.hpp"
};
class RC_MH60M_DAP_MLASS_I: RC_MH60M_DAP_MLASS
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsI.hpp"
};


/*
class vtx_MH60M_DAP_MLASS;
class RC_MH60M_DAP_Core: RC_MH80M_DAP_Base
{
	class Components;
	class EventHandlers;
};
class RC_MH60M_DAP_Base: RC_MH60M_DAP_Core
{
	class Components: Components
	{
		#include "\RC_Hatchet\cfgVehicles\includes_vehicle\MH80M_4pylons.hpp"
	};
};


//manned
class RC_MH60M_DAP: RC_MH60M_DAP_Base
{
	displayName="MH-60M DAP - Black Hawk"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsB.hpp"
};
class RC_MH80M_DAP_O: RC_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsO.hpp"
};
class RC_MH80M_DAP_I: RC_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsI.hpp"
};
*/