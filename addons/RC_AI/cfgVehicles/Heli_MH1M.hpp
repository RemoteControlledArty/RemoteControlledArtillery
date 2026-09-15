class RC_MH1M_Base;
class RC_AI_MH1M_Fetch: RC_MH1M_Base
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_fetch.hpp"
};
class RC_AI_MH1M_Core: RC_AI_MH1M_Fetch
{
	displayName="[AI] MH-1M - Huey";
	editorSubcategory="RC_Heli_subcat";

	class Components: Components
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_2pylons_AI.hpp"
	};

  class HitPoints: HitPoints
	{
		/*
		class HitFuel: HitFuel
		{
			armor=-150;				//V 1 = -40, H ?, RC -150
			explosionShielding=1;	//V 1, RC 1
		};
		class HitAvionics: HitAvionics
		{
			armor=-80;					//V 2 = -80, H ?, RC -80
			explosionShielding=1;		//V 1, RC 1
		};
		*/
		class HitVRotor: HitVRotor
		{
			//armor=-200;				//V 3 = -120, H 0.054, 0.81 = -32.4, RC -200
			explosionShielding=3;		//V 6, H 0.27, RC 1.5
		};
	};
};
class RC_AI_MH1M_Base: RC_AI_MH1M_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\getOutEngineOffEH.hpp"
	};
};


class RC_AI_B_MH1M: RC_AI_MH1M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsB.hpp"
};
class RC_AI_I_MH1M: RC_AI_B_MH1M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsO.hpp"
};
class RC_AI_I_MH1M: RC_AI_B_MH1M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsI.hpp"
};
