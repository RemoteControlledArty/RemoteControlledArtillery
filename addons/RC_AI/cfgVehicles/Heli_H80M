class RC_MH80M_DAP_Base;
class RC_AI_MH80M_DAP_Fetch: RC_MH80M_DAP_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_fetch.hpp"
};
class RC_AI_MH80M_DAP_Core: RC_AI_MH80M_DAP_Fetch
{
  displayName="[AI] MH80M DAP - Ghost Hawk"
	editorSubcategory="RC_Heli_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_4pylons_AI.hpp"
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
class RC_AI_MH80M_DAP_Base: RC_AI_MH80M_DAP_Core
{
};


class RC_AI_MH80M_DAP: RC_AI_MH80M_DAP_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsB.hpp"
};
class RC_AI_MH80M_DAP_O: RC_AI_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsO.hpp"
};
class RC_AI_MH80M_DAP_I: RC_AI_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsI.hpp"
};
