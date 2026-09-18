class RC_Ka60M_Base;
class RC_AI_Ka60M_Fetch: RC_Ka60M_Base
{
	class Components;
	class TransportPylonsComponent;
	class pylons;
	class pylon1;
	class pylon2;
	class HitPoints;
	class HitVRotor;
};
class RC_AI_Ka60M_Core: RC_AI_Ka60M_Fetch
{
	displayName="[AI] Ka-60M - Kasatka"
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
						"RC_Hardpoint_FuelTank",

						"RC_AI_Hardpoint_O_V1",
						"RC_AI_Hardpoint_O_V1_Right",
						"RC_AI_Hardpoint_O_V2",
						"RC_AI_Hardpoint_O_V2_Right",
						"RC_AI_Hardpoint_O_V3",
						"RC_AI_Hardpoint_O_V3_Right",
						"RC_AI_Hardpoint_O_V4",
						"RC_AI_Hardpoint_O_V4_Right"
					};

					attachment="RC_AI_PylonM_250Rnd_30mm_Proxy_O";
				};
				class pylon2: pylon2
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank",
						
						"RC_AI_Hardpoint_O_V1",
						"RC_AI_Hardpoint_O_V1_Left",
						"RC_AI_Hardpoint_O_V2",
						"RC_AI_Hardpoint_O_V2_Left",
						"RC_AI_Hardpoint_O_V3",
						"RC_AI_Hardpoint_O_V3_Left",
						"RC_AI_Hardpoint_O_V4",
						"RC_AI_Hardpoint_O_V4_Left"
					};

					attachment="RC_AI_PylonM_19Rnd_S5_MP_Proxy";
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
class RC_AI_Ka60M_Base: RC_AI_Ka60M_Core
{
};


class RC_AI_B_Ka60M: RC_AI_Ka60M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\RC_AI\includes_cfg\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsB.hpp"
};
class RC_AI_O_Ka60M: RC_AI_B_Ka60M
{
	#include "\RC_AI\includes_cfg\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_AI_I_Ka60M: RC_AI_B_Ka60M
{
	#include "\RC_AI\includes_cfg\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


class RC_AI_Ka60M_Tr_Core: RC_AI_Ka60M_Core
{
	displayName="[AI] Ka-60M - Kasatka (Transport)"
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
						"RC_Hardpoint_FuelTank",

						"RC_AI_Hardpoint_O_V1",
						"RC_AI_Hardpoint_O_V1_Right",
						"RC_AI_Hardpoint_O_V2",
						"RC_AI_Hardpoint_O_V2_Right",
						"RC_AI_Hardpoint_O_V3",
						"RC_AI_Hardpoint_O_V3_Right",
						"RC_AI_Hardpoint_O_V4",
						"RC_AI_Hardpoint_O_V4_Right"
					};

					attachment="RC_PylonM_5000Rnd_338_SLAP_T_R_right";
				};
				class pylon2: pylon2
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank",
						
						"RC_AI_Hardpoint_O_V1",
						"RC_AI_Hardpoint_O_V1_Left",
						"RC_AI_Hardpoint_O_V2",
						"RC_AI_Hardpoint_O_V2_Left",
						"RC_AI_Hardpoint_O_V3",
						"RC_AI_Hardpoint_O_V3_Left",
						"RC_AI_Hardpoint_O_V4",
						"RC_AI_Hardpoint_O_V4_Left"
					};

					attachment="RC_AI_PylonM_12Rnd_S5_MP_Proxy";
				};
			};
		};
	};
};
class RC_AI_Ka60M_Tr_Base: RC_AI_Ka60M_Tr_Core
{
};


class RC_AI_B_Ka60M_Tr: RC_AI_Ka60M_Tr_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\RC_AI\includes_cfg\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsB.hpp"
};
class RC_AI_O_Ka60M_Tr: RC_AI_B_Ka60M_Tr
{
	#include "\RC_AI\includes_cfg\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_AI_I_Ka60M_Tr: RC_AI_B_Ka60M_Tr
{
	#include "\RC_AI\includes_cfg\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};