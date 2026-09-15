class RC_AW159M_Base;
class RC_AI_AW159M_Fetch: RC_AW159M_Base
{
	class Components;
	class TransportPylonsComponent;
	class pylons;
	class PylonRight1;
	class PylonLeft1;
	class HitPoints;
	class HitVRotor;
};
class RC_AI_AW159M_Core: RC_AI_AW159M_Fetch
{
	displayName="[AI] AW159M - Wildcat";
	editorSubcategory="RC_Heli_subcat";

	class Components: Components
	{
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				class PylonRight1: PylonRight1
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
				class PylonLeft1: PylonLeft1
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

					attachment="RC_AI_PylonM_19Rnd_Hydra_MP_Proxy";
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
class RC_AI_AW159M_Base: RC_AI_AW159M_Core
{
};


class RC_AI_B_AW159M: RC_AI_AW159M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\RC_AI\includes_cfg\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsB.hpp"
};
class RC_AI_O_AW159M: RC_AI_B_AW159M
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_G",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\RC_AI\includes_cfg\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsO.hpp"
};
class RC_AI_I_AW159M: RC_AI_B_AW159M
{
	magazines[]=
	{
		"RC_5000Rnd_338_SLAP_T_Y",
		"Laserbatteries",
		"168Rnd_CMFlare_Chaff_Magazine"
	};

	#include "\RC_AI\includes_cfg\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\AW159M\AW159M_itemsI.hpp"
};
