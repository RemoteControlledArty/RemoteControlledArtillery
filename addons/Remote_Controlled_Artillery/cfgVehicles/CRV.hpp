class B_APC_Tracked_01_CRV_F;
class RC_CRV_Core: B_APC_Tracked_01_CRV_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	//class HitPoints;
	//class HitHull;
	//class HitEngine;
	//class HitFuel;
	//class HitLTrack;
	//class HitRTrack;
	class AnimationSources;
	class showCamonetHull;
	class showCamonetPlates1;
	class showCamonetPlates2;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_CRV_Base: RC_CRV_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\values_APC.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	faction="RemoteControlled_B";
	editorSubcategory="RC_CRV_subcat";
	forceHideDriver=1;
	driverForceOptics=1;
	driverCompartments="Compartment2";
	commanding=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	maxSpeed=80;
	enginePower=1059.9;
	peakTorque=5386.3;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Beta\APC_Tracked_01\Data\APC_Tracked_01_body_CO.paa",
		"A3\Armor_F_Beta\APC_Tracked_01\Data\mbt_01_body_co.paa",
		"a3\data_f\vehicles\turret_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};

	weapons[]=
	{
		"TruckHorn",
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		/*
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			minElev=-19;
			maxElev=40;	//30
			commanding=3;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			turretInfoType="RscOptics_MBT_03_gunner";

			weapons[]=
			{
				"RC_HMG_127_APC",
				"RC_GMG_40mm",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_GMG_red.hpp"

			class ViewOptics: RCWSOptics
			{
				initFov=0.9;
				minFov=0.02;
				maxFov=0.9;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};
		};
		class CommanderOptics : CommanderOptics
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			turretInfoType="RscOptics_MBT_03_gunner";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			commanding=2;
			maxElev=40;

			weapons[]=
			{
				"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class ViewOptics: ViewOptics
			{
				//directionStabilized=1;
				initFov=1;
				minFov=0.02;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"TI"
				};
				thermalMode[]={0};
			};
		};
		*/
	};

	class AnimationSources: AnimationSources
	{
		/*
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_GMG_40mm";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_GMG_40mm";
		};
		class revolving_hmg
		{
			source="revolving";
			weapon="RC_HMG_127_APC";
		};
		class revolving_gmg
		{
			source="revolving";
			weapon="RC_GMG_40mm";
		};
		*/
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetPlates1: showCamonetPlates1
		{
			initPhase=1;
		};
		class showCamonetPlates2: showCamonetPlates2
		{
			initPhase=1;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_CRV_A: RC_CRV_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Namer";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="B_UAV_AI";
};
class RC_CRV_A_O: RC_CRV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_GMG_green.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_CRV_A_I: RC_CRV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_GMG_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};


class RC_CRV_WD: RC_CRV_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_rcws_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\APC_Tracked_01_body_olive_CO.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_CRV_WD_O: RC_CRV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_GMG_green.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_CRV_WD_I: RC_CRV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_GMG_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};