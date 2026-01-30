class O_Heli_Light_02_dynamicLoadout_F;
class RC_Ka60M_Core: O_Heli_Light_02_dynamicLoadout_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_fetch.hpp"
};
class RC_Ka60M_Base: RC_Ka60M_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_main.hpp"
	editorSubcategory="RC_Heli_armed_subcat";

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_pilotCamBase.hpp"
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
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_copilotTurret.hpp"
		//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_cargoTurrets.hpp"
	};
	/*
	class AnimationSources: AnimationSources
	{
		//DOOR
	};
	*/
};

//renamed pylons Hydra -> S-8, APKWS -> Ugroza S-8L / S-8K, AGM -> 9K121 Vikhr / 9M120 Ataka, DAGR M310 -> S-8L / LMUR / 9M120 Ataka
//or descriptive: 70mm Rocket, 70mm LG, LG-AGM
//use old 20r skyfire pod


//manned
class RC_Ka60M: RC_Ka60M_Base
{
	displayName="Ka-60M - Kasatka"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_Ka60M_O: RC_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_Ka60M_I: RC_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//optionally manned
class RC_OM_Ka60M_UV: RC_Ka60M_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	displayName="OM Ka-60M - Kasatka"
};
class RC_OM_Ka60M: RC_OM_Ka60M_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_OM_Ka60M_O: RC_OM_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_OM_Ka60M_I: RC_OM_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};