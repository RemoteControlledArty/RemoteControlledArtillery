class O_Heli_Attack_02_dynamicLoadout_F;
class RC_Mi48M_Fetch: O_Heli_Attack_02_dynamicLoadout_F
{
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_fetch.hpp"
	class AnimationSources;
};
class RC_Mi48M_Core: RC_Mi48M_Fetch
{
	/*
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
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_copilotTurret.hpp"
	};
	*/

	class AnimationSources: AnimationSources
	{
		class Hide
		{
			animPeriod = 0;
			initPhase = 0;
			source = "user";
		};
		class HideWeapons
		{
			animPeriod = 0.001;	//1e-06
			initPhase = 1;
			source = "user";
		};
		class HideTurret
		{
			animPeriod = 0.001;
			initPhase = 1;
			source = "user";
		};
	};

	animationList[]=
	{
		"Hide",
		0,
		"HideWeapons",
		1,
		"HideTurret",
		1
	};
};
class RC_Mi48M_Base: RC_Mi48M_Core
{
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_hitPoints.hpp"
};


//AI
class RC_AI_Mi48M_O: RC_Mi48M_Base
{
	displayName="AI Mi-48M - Kajman"
	editorSubcategory="RC_Heli_subcat";

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};