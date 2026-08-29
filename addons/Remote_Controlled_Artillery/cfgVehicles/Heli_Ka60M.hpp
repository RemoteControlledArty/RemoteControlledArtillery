class O_Heli_Light_02_dynamicLoadout_F;
class RC_Ka60M_Fetch: O_Heli_Light_02_dynamicLoadout_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_fetch.hpp"
};
class RC_Ka60M_Core: RC_Ka60M_Fetch
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\getOutEngineOffEH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\firedProxy_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\DetectInterceptorEH.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator_EH.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_main.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_pilotCamBase.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFixed.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFree.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_userActions.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	/*
	class ViewPilot
	{
		initAngleX = 0;
		initAngleY = 0;
		initFov = 0.9;
		maxAngleX = 85;
		maxAngleY = 150;
		maxFov = 1.25;
		maxMoveX = 0.2;
		maxMoveY = 0.1;
		maxMoveZ = 0.2;
		minAngleX = -65;
		minAngleY = -150;
		minFov = 0.25;
		minMoveX = -0.2;
		minMoveY = -0.1;
		minMoveZ = -0.1;
		speedZoomMaxFOV = 0;
		speedZoomMaxSpeed = 1e+10;
	};
	*/
	
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
};
class RC_Ka60M_Base: RC_Ka60M_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_hitPoints.hpp"
};


//AI
class RC_AI_Ka60M: RC_Ka60M_Core
{
	displayName="AI Ka-60M - Kasatka"
	editorSubcategory="RC_Heli_subcat";

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons_V5.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsB.hpp"
};
class RC_AI_Ka60M_O: RC_AI_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_AI_Ka60M_I: RC_AI_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


//manned
class RC_Ka60M_V1: RC_Ka60M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	displayName="Ka-60M - Kasatka - V1"
	editorSubcategory="RC_Heli_V1_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons_V1.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsB.hpp"
};
class RC_Ka60M_V1_O: RC_Ka60M_V1
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_Ka60M_V1_I: RC_Ka60M_V1
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


class RC_Ka60M_V2: RC_Ka60M_V1
{
	displayName="Ka-60M - Kasatka - V2"
	editorSubcategory="RC_Heli_V2_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons_V2.hpp"
	};
};
class RC_Ka60M_V2_O: RC_Ka60M_V2
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_Ka60M_V2_I: RC_Ka60M_V2
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


class RC_Ka60M_V3: RC_Ka60M_V1
{
	displayName="Ka-60M - Kasatka - V3"
	editorSubcategory="RC_Heli_V3_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons_V3.hpp"
	};
};
class RC_Ka60M_V3_O: RC_Ka60M_V3
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_Ka60M_V3_I: RC_Ka60M_V3
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


class RC_Ka60M_V4: RC_Ka60M_V1
{
	displayName="Ka-60M - Kasatka - V4"
	editorSubcategory="RC_Heli_V4_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons_V4.hpp"
	};
};
class RC_Ka60M_V4_O: RC_Ka60M_V4
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_Ka60M_V4_I: RC_Ka60M_V4
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


class RC_Ka60M_V5: RC_Ka60M_V1
{
	displayName="Ka-60M - Kasatka - V5"
	editorSubcategory="RC_Heli_V5_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons_V5.hpp"
	};
};
class RC_Ka60M_V5_O: RC_Ka60M_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_Ka60M_V5_I: RC_Ka60M_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


class RC_Ka60M_V6: RC_Ka60M_V1
{
	displayName="Ka-60M - Kasatka - V6"
	editorSubcategory="RC_Heli_V6_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons_V6.hpp"
	};
};
class RC_Ka60M_V6_O: RC_Ka60M_V6
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_Ka60M_V6_I: RC_Ka60M_V6
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


/*
//optionally manned
class RC_OM_Ka60M_UV: RC_Ka60M_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	displayName="RC Ka-60M - Kasatka"
};
class RC_OM_Ka60M: RC_OM_Ka60M_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsB.hpp"
};
class RC_OM_Ka60M_O: RC_OM_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_OM_Ka60M_I: RC_OM_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};
*/