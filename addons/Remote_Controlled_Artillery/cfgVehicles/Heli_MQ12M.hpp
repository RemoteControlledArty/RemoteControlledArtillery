class B_UAV_03_dynamicLoadout_F;
class RC_MQ12M_Fetch: B_UAV_03_dynamicLoadout_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_fetch.hpp"
};
class RC_MQ12M_Core: RC_MQ12M_Fetch
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\firedProxy_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\DetectInterceptorEH.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator_EH.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_main.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_pilotCamBase.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_pilotCamFixed.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_pilotCamFree.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_animationSources.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_userActions.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	radarTargetSize=0.8; 	//0.?

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_panels.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_4pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_mainTurret.hpp"
	};
};
class RC_MQ12M_Base: RC_MQ12M_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_hitPoints.hpp"
};


//4 armed pylons
class RC_MQ12M_V3: RC_MQ12M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	displayName="MQ-12M - Mantis - V3"
	editorSubcategory="RC_Heli_V3_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_4pylons_V3.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsB.hpp"
};
class RC_MQ12M_V3_O: RC_MQ12M_V3
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsO.hpp"
};
class RC_MQ12M_V3_I: RC_MQ12M_V3
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsI.hpp"
};


class RC_MQ12M_V4: RC_MQ12M_V2
{
	displayName="MQ-12M - Mantis - V4"
	editorSubcategory="RC_Heli_V4_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_4pylons_V4.hpp"
	};
};
class RC_MQ12M_V4_O: RC_MQ12M_V4
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsO.hpp"
};
class RC_MQ12M_V4_I: RC_MQ12M_V4
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsI.hpp"
};


class RC_MQ12M_V5: RC_MQ12M_V2
{
	displayName="MQ-12M - Mantis - V5"
	editorSubcategory="RC_Heli_V5_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_4pylons_V5.hpp"
	};
};
class RC_MQ12M_V5_O: RC_MQ12M_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsO.hpp"
};
class RC_MQ12M_V5_I: RC_MQ12M_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsI.hpp"
};


class RC_MQ12M_V6: RC_MQ12M_V2
{
	displayName="MQ-12M - Mantis - V6"
	editorSubcategory="RC_Heli_V6_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_4pylons_V6.hpp"
	};
};
class RC_MQ12M_V6_O: RC_MQ12M_V6
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsO.hpp"
};
class RC_MQ12M_V6_I: RC_MQ12M_V6
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\MQ12M\MQ12M_itemsI.hpp"
};