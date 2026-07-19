class RHS_UH1Y;
class RC_MH1M_Core: RHS_UH1Y
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_fetch.hpp"
};
class RC_MH1M_Base: RC_MH1M_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\DetectInterceptorEH.hpp"
	};

	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_main.hpp"

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_Main.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_pilotCamBase.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_pilotCamFixed.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_pilotCamFree.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_userActions.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_hitPoints.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	editorSubcategory="RC_Heli_armed_subcat";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_2pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_copilotTurret.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_cargoTurrets.hpp"
	};
	class ViewPilot: ViewPilot
	{
		initFov=0.9;
		maxFov=1.25;
		minFov=0.25;
	};
	class AnimationSources: AnimationSources
	{
		class Gatling_1
		{
			source="revolving";
			weapon="RC_RHS_338_DoorMinigun_1";
		};
		class Gatling_2
		{
			source="revolving";
			weapon="RC_RHS_338_DoorMinigun_2";
		};
		class muzzle_rot_hmg
		{
			source="ammorandom";
			weapon="RC_RHS_338_DoorMinigun_1";
		};
		class muzzle_rot_hmg2
		{
			source="ammorandom";
			weapon="RC_RHS_338_DoorMinigun_2";
		};
	};
};


//manned
class RC_MH1M_DAP: RC_MH1M_Base
{
	displayName="MH-1M DAP - Huey";

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\RC_RHS\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsB.hpp"
};
class RC_MH1M_DAP_O: RC_MH1M_DAP
{
	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_G"}; gunnerType="RC_O_DoorGunner";};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_G"}; gunnerType="RC_O_DoorGunner";};
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsO.hpp"
};
class RC_MH1M_DAP_I: RC_MH1M_DAP
{
	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"}; gunnerType="RC_I_DoorGunner";};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"}; gunnerType="RC_I_DoorGunner";};
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsI.hpp"
};


//optionally manned
class RC_OM_MH1M_DAP_UV: RC_MH1M_Base
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_EHs_UV.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_UV_conversion.hpp"

	displayName="RC MH-1M DAP - Huey";

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {dontCreateAI=1;};
		class RightDoorGun: RightDoorGun {dontCreateAI=1;};
	};
};
class RC_OM_MH1M_DAP: RC_OM_MH1M_DAP_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsB.hpp"
};
class RC_OM_MH1M_DAP_O: RC_OM_MH1M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsO.hpp"

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_G"};};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_G"};};
	};
};
class RC_OM_MH1M_DAP_I: RC_OM_MH1M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsI.hpp"

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"};};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"};};
	};
};


class RC_UH1M: RC_MH1M_DAP
{
	displayName="UH-1M - Huey";
	
	class Components: Components
	{
		class TransportPylonsComponent
		{
			UIPicture = "\rhsusf\addons\rhsusf_a2port_air2\data\loadouts\RHS_UH1_EDEN_CA.paa";
			
			class pylons
			{
				class cmDispenser
				{
					attachment = "rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4";
					hardpoints[] = {"RHSUSF_cm_ANALE39","RHSUSF_cm_ANALE39_x2","RHSUSF_cm_ANALE39_x4"};
					maxweight = 800;
					priority = 1;
					UIposition[] = {0.33,0};
				};
			};
		};
	};
};
class RC_UH1M_O: RC_UH1M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsO.hpp"

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"
		
		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_G"}; gunnerType="RC_O_DoorGunner";};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_G"}; gunnerType="RC_O_DoorGunner";};
	};
};
class RC_UH1M_I: RC_UH1M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsI.hpp"

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"
		
		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"}; gunnerType="RC_I_DoorGunner";};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"}; gunnerType="RC_I_DoorGunner";};
	};
};


//optionally manned
class RC_OM_UH1M_UV: RC_UH1M
{
	scope=0;
	scopeCurator=0;

	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_EHs_UV.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_UV_conversion.hpp"

	displayName="RC UH-1M - Huey";

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {dontCreateAI=1;};
		class RightDoorGun: RightDoorGun {dontCreateAI=1;};
	};
};
class RC_OM_UH1M: RC_OM_UH1M_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsB.hpp"
};
class RC_OM_UH1M_O: RC_OM_UH1M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsO.hpp"

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_G"};};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_G"};};
	};
};
class RC_OM_UH1M_I: RC_OM_UH1M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsI.hpp"

	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_turretsInherit.hpp"

		class MainTurret: MainTurret {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"};};
		class RightDoorGun: RightDoorGun {magazines[]={"RC_2000Rnd_338_SLAP_T_Y"};};
	};
};