class I_Heli_light_03_dynamicLoadout_F;
class RC_AW159M_Core: I_Heli_light_03_dynamicLoadout_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_fetch.hpp"
};
class RC_AW159M_Base: RC_AW159M_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_main.hpp"
	editorSubcategory="RC_Heli_armed_subcat";

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_Main.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_pilotCamBase.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFixed.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFree.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_userActions.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_hitPoints.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_4pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_mainTurret.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_cargoTurrets.hpp"
	};
};


//manned
class RC_AW159M: RC_AW159M_Base
{
	displayName="AW159M DAP - Wildcat"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_AW159M_O: RC_AW159M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_AW159M_I: RC_AW159M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//optionally manned
class RC_OM_AW159M_UV: RC_AW159M_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	displayName="OM AW159M DAP - Wildcat"
};
class RC_OM_AW159M: RC_OM_AW159M_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_OM_AW159M_O: RC_OM_AW159M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_OM_AW159M_I: RC_OM_AW159M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};