class RC_MH80M_DAP_Base;
class RC_AI_MH80M_DAP_Fetch: RC_MH80M_DAP_Base
{
	class Components;
	class TransportPylonsComponent;
	class pylons;
	class pylon1;
	class pylon2;
	class pylon3;
	class pylon4;
	class camera;
	class wingtip1;
	class wingtip2;
	class HitPoints;
	class HitVRotor;
};
class RC_AI_MH80M_DAP_Core: RC_AI_MH80M_DAP_Fetch
{
  	displayName="[AI] MH80M DAP - Ghost Hawk";
	editorSubcategory="RC_Heli_subcat";

	class Components: Components
	{
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				//left outer
				class pylon1: pylon1
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
				//left inner
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
				//right inner
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
				//right outer
				class pylon4: pylon4
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

					attachment="RC_AI_PylonM_19Rnd_Hydra_MP_Proxy";
				};
				//center
				class camera: camera
				{
				};
				//left
				class wingtip1: wingtip1
				{
				};
				//right
				class wingtip2: wingtip2
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
class RC_AI_MH80M_DAP_Base: RC_AI_MH80M_DAP_Core
{
};


class RC_AI_B_MH80M_DAP: RC_AI_MH80M_DAP_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\RC_AI\includes_cfg\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsB.hpp"
};
class RC_AI_O_MH80M_DAP: RC_AI_B_MH80M_DAP
{
	#include "\RC_AI\includes_cfg\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsO.hpp"
};
class RC_AI_I_MH80M_DAP: RC_AI_B_MH80M_DAP
{
	#include "\RC_AI\includes_cfg\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsI.hpp"
};


class RC_AI_MH80M_Core: RC_AI_MH80M_DAP_Core
{
  	displayName="[AI] MH80M - Ghost Hawk"

	class Components: Components
	{
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				//left outer
				class pylon1: pylon1
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank"
					};

					attachment="RC_PylonFuelTank_HalfFull";
				};
				//left inner
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
				//right inner
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

					attachment="RC_AI_PylonM_19Rnd_Hydra_MP_Proxy";
				};
				//right outer
				class pylon4: pylon4
				{
					hardpoints[]=
					{
						"RC_Hardpoint_FuelTank"
					};

					attachment="RC_PylonFuelTank_HalfFull";
				};
				//center
				class camera: camera
				{
				};
				//left
				class wingtip1: wingtip1
				{
				};
				//right
				class wingtip2: wingtip2
				{
				};
			};
		};
	};
};
class RC_AI_MH80M_Base: RC_AI_MH80M_Core
{
};


class RC_AI_B_MH80M: RC_AI_MH80M_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\RC_AI\includes_cfg\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsB.hpp"
};
class RC_AI_O_MH80M: RC_AI_B_MH80M
{
	#include "\RC_AI\includes_cfg\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsO.hpp"
};
class RC_AI_I_MH80M: RC_AI_B_MH80M
{
	#include "\RC_AI\includes_cfg\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsI.hpp"
};
