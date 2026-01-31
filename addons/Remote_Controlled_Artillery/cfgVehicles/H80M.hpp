class B_Heli_Transport_01_pylons_F;
class RC_MH80M_DAP_Core: B_Heli_Transport_01_pylons_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_fetch.hpp"
};
class RC_MH80M_DAP_Base: RC_MH80M_DAP_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_main.hpp"
	editorSubcategory="RC_Heli_armed_subcat";

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotView.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamBase.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFixed.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFree.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_userActions.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_hitPoints.hpp"
	//#include "\Remote_Controlled_Artillery\MFD\MFD_merged.hpp"
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
class RC_MH80M_DAP: RC_MH80M_DAP_Base
{
	displayName="MH-80M DAP - Ghost Hawk"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MH80M_DAP_O: RC_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MH80M_DAP_I: RC_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//optionally manned
class RC_OM_MH80M_DAP_UV: RC_MH80M_DAP_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	displayName="OM MH-80M DAP - Ghost Hawk"
};
class RC_OM_MH80M_DAP: RC_OM_MH80M_DAP_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_OM_MH80M_DAP_O: RC_OM_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_OM_MH80M_DAP_I: RC_OM_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};