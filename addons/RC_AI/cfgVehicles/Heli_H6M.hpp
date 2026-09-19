class RC_MELB_AH6M_Base;
class RC_AI_MELB_AH6M_Fetch: RC_MELB_AH6M_Base
{
	class Components;
	class TransportPylonsComponent;
	class pylons;
	class pylon1;
	class pylon2;
	class pylon3;
	class pylon4;
	class HitPoints;
	class HitVRotor;
	class EventHandlers;
};
class RC_AI_MELB_AH6M_Core: RC_AI_MELB_AH6M_Fetch
{
	displayName="[AI] AH-6M - Little Bird";
	editorSubcategory="RC_Heli_subcat";

	class Components: Components
	{
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				class pylon1: pylon1
				{
					hardpoints[]=
					{
						"RC_AI_Hardpoint_V1",
						"RC_AI_Hardpoint_V1_Left",
						"RC_AI_Hardpoint_V2",
						"RC_AI_Hardpoint_V2_Left",
						"RC_AI_Hardpoint_V3",
						"RC_AI_Hardpoint_V3_Left",
						"RC_AI_Hardpoint_V4",
						"RC_AI_Hardpoint_V4_Left"
					};

					attachment="RC_AI_RHS_PylonM_19Rnd_Hydra_MP_Proxy";
				};
				class pylon2: pylon2
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank",
						
						"RC_AI_Hardpoint_V1",
						"RC_AI_Hardpoint_V1_Left",
						"RC_AI_Hardpoint_V2",
						"RC_AI_Hardpoint_V2_Left",
						"RC_AI_Hardpoint_V3",
						"RC_AI_Hardpoint_V3_Left",
						"RC_AI_Hardpoint_V4",
						"RC_AI_Hardpoint_V4_Left"
					};

					attachment="RC_AI_PylonM_250Rnd_30mm_Proxy";
				};
				class pylon3: pylon3
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank",
						
						"RC_AI_Hardpoint_V1",
						"RC_AI_Hardpoint_V1_Right",
						"RC_AI_Hardpoint_V2",
						"RC_AI_Hardpoint_V2_Right",
						"RC_AI_Hardpoint_V3",
						"RC_AI_Hardpoint_V3_Right",
						"RC_AI_Hardpoint_V4",
						"RC_AI_Hardpoint_V4_Right"
					};

					attachment="RC_AI_PylonM_250Rnd_30mm_Proxy";
				};
				class pylon4: pylon4
				{
					hardpoints[]=
					{
						"RC_AI_Hardpoint_V1",
						"RC_AI_Hardpoint_V1_Right",
						"RC_AI_Hardpoint_V2",
						"RC_AI_Hardpoint_V2_Right",
						"RC_AI_Hardpoint_V3",
						"RC_AI_Hardpoint_V3_Right",
						"RC_AI_Hardpoint_V4",
						"RC_AI_Hardpoint_V4_Right"
					};

					attachment="RC_AI_RHS_PylonM_19Rnd_Hydra_MP_Proxy";
				};
			};
		};
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
class RC_AI_MELB_AH6M_Base: RC_AI_MELB_AH6M_Core
{
    class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\getOutEngineOff.hpp"
	};
};


class RC_AI_B_MELB_AH6M: RC_AI_MELB_AH6M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\RC_AI\includes_cfg\heli_sideB_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M\H6M_itemsB.hpp"
};
class RC_AI_O_MELB_AH6M: RC_AI_B_MELB_AH6M
{
	#include "\RC_AI\includes_cfg\heli_sideO_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M\H6M_itemsO.hpp"
};
class RC_AI_I_MELB_AH6M: RC_AI_B_MELB_AH6M
{
	#include "\RC_AI\includes_cfg\heli_sideI_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M\H6M_itemsI.hpp"
};


//MH
class RC_MELB_MH6M_DAP_Base;
class RC_AI_MELB_MH6M_Fetch: RC_MELB_MH6M_DAP_Base
{
	class Components;
	class TransportPylonsComponent;
	class pylons;
	class pylon1;
	class pylon2;
	class pylon3;
	class pylon4;
	class HitPoints;
	class HitVRotor;
	class EventHandlers;
};
class RC_AI_MELB_MH6M_Core: RC_AI_MELB_MH6M_Fetch
{
	displayName="[AI] MH-6M - Little Bird";
	editorSubcategory="RC_Heli_subcat";

	class Components: Components
	{
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				class pylon1: pylon1
				{
				};
				class pylon2: pylon2
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank",
						
						"RC_AI_Hardpoint_V1",
						"RC_AI_Hardpoint_V1_Left",
						"RC_AI_Hardpoint_V2",
						"RC_AI_Hardpoint_V2_Left",
						"RC_AI_Hardpoint_V3",
						"RC_AI_Hardpoint_V3_Left",
						"RC_AI_Hardpoint_V4",
						"RC_AI_Hardpoint_V4_Left"
					};

					attachment="RC_AI_PylonM_250Rnd_30mm_Proxy";
				};
				class pylon3: pylon3
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank",
						
						"RC_AI_Hardpoint_V1",
						"RC_AI_Hardpoint_V1_Right",
						"RC_AI_Hardpoint_V2",
						"RC_AI_Hardpoint_V2_Right",
						"RC_AI_Hardpoint_V3",
						"RC_AI_Hardpoint_V3_Right",
						"RC_AI_Hardpoint_V4",
						"RC_AI_Hardpoint_V4_Right"
					};

					attachment="RC_AI_RHS_PylonM_19Rnd_Hydra_MP_Proxy";
				};
				class pylon4: pylon4
                {
				};
			};
		};
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
class RC_AI_MELB_MH6M_Base: RC_AI_MELB_MH6M_Core
{
    class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\getOutEngineOff.hpp"
	};
};


class RC_AI_B_MELB_MH6M: RC_AI_MELB_MH6M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\RC_AI\includes_cfg\heli_sideB_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M\H6M_itemsB.hpp"
};
class RC_AI_O_MELB_MH6M: RC_AI_B_MELB_MH6M
{
	#include "\RC_AI\includes_cfg\heli_sideO_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M\H6M_itemsO.hpp"
};
class RC_AI_I_MELB_MH6M: RC_AI_B_MELB_MH6M
{
	#include "\RC_AI\includes_cfg\heli_sideI_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M\H6M_itemsI.hpp"
};
