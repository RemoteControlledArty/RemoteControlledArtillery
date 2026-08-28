class I_Heli_light_03_dynamicLoadout_F;
class RC_AW159M_Fetch: I_Heli_light_03_dynamicLoadout_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_fetch.hpp"
};
class RC_AW159M_Core: RC_AW159M_Fetch
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\firedProxy_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\DetectInterceptorEH.hpp"

		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		class RC_EngineOff
		{
			getOut="params ['_vehicle']; if (local _vehicle) then {_vehicle engineOn false};"
		};
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_main.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_Main.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_pilotCamBase.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFixed.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFree.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_userActions.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_mainTurret.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_cargoTurrets.hpp"
	};
};
class RC_AW159M_Base: RC_AW159M_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_hitPoints.hpp"
};


class RC_AI_AW159M: RC_AW159M_Core
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	displayName="AI AW159M - Wildcat"
	editorSubcategory="RC_Heli_outdated_subcat";

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsB.hpp"
};
class RC_AI_AW159M_O: RC_AI_AW159M
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AI_AW159M_I: RC_AI_AW159M
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_Y",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};


//manned
class RC_AW159M_X: RC_AW159M_Base
{
	displayName="AW159M DAP - Wildcat  V6"
	editorSubcategory="RC_Heli_outdated_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons_V6.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsB.hpp"
};
class RC_AW159M: RC_AW159M_X
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
};


class RC_AW159M_O_X: RC_AW159M
{
	scope=0;
	scopeCurator=0;

	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AW159M_O: RC_AW159M_O_X
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
};


class RC_AW159M_I_X: RC_AW159M
{
	scope=0;
	scopeCurator=0;
	
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_Y",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};
class RC_AW159M_I: RC_AW159M_I_X
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
};


class RC_AW159M_V1: RC_AW159M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	displayName="AW159M - Wildcat  V1"
	editorSubcategory="RC_Heli_V1_subcat";
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons_V1.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsB.hpp"
};
class RC_AW159M_V1_O: RC_AW159M_V1
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AW159M_V1_I: RC_AW159M_V1
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_I",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};


class RC_AW159M_V2: RC_AW159M_V1
{
	displayName="AW159M - Wildcat  V2"
	editorSubcategory="RC_Heli_V2_subcat";
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons_V2.hpp"
	};
};
class RC_AW159M_V2_O: RC_AW159M_V2
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AW159M_V2_I: RC_AW159M_V2
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_I",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};


class RC_AW159M_V3: RC_AW159M_V1
{
	displayName="AW159M - Wildcat  V3"
	editorSubcategory="RC_Heli_V3_subcat";
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons_V3.hpp"
	};
};
class RC_AW159M_V3_O: RC_AW159M_V3
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AW159M_V3_I: RC_AW159M_V3
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_I",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};


class RC_AW159M_V4: RC_AW159M_V1
{
	displayName="AW159M - Wildcat  V4"
	editorSubcategory="RC_Heli_V4_subcat";
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons_V4.hpp"
	};
};
class RC_AW159M_V4_O: RC_AW159M_V4
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AW159M_V4_I: RC_AW159M_V4
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_I",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};


class RC_AW159M_V5: RC_AW159M_V1
{
	displayName="AW159M - Wildcat  V5"
	editorSubcategory="RC_Heli_V5_subcat";
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons_V5.hpp"
	};
};
class RC_AW159M_V5_O: RC_AW159M_V5
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AW159M_V5_I: RC_AW159M_V5
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_I",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};


class RC_AW159M_V6: RC_AW159M_V1
{
	displayName="AW159M - Wildcat  V6"
	editorSubcategory="RC_Heli_V6_subcat";
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_2pylons_V6.hpp"
	};
};
class RC_AW159M_V6_O: RC_AW159M_V6
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AW159M_V6_I: RC_AW159M_V6
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_I",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};


/*
//optionally manned
class RC_OM_AW159M_UV: RC_AW159M_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	displayName="RC AW159M DAP - Wildcat"
};
class RC_OM_AW159M_X: RC_OM_AW159M_UV
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsB.hpp"
};
class RC_OM_AW159M: RC_OM_AW159M_X
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
};


class RC_OM_AW159M_O_X: RC_OM_AW159M
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_OM_AW159M_O: RC_OM_AW159M_O_X
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
};


class RC_OM_AW159M_I_X: RC_OM_AW159M
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_Y",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};
class RC_OM_AW159M_I: RC_OM_AW159M_I_X
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
};
*/