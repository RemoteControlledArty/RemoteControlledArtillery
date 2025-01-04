class B_APC_Tracked_01_rcws_F;
class RC_ICV_APC_1_Base: B_APC_Tracked_01_rcws_F
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
class RC_ICV_APC_1_A: RC_ICV_APC_1_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	faction="RemoteControlled_B";
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

	class AnimationSources: AnimationSources
	{
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


class RC_ICV_1_A: RC_ICV_APC_1_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initHideTurret.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
	};
	//(_this select 0) spawn {while {true} do {if (player in _this && (commander _this == player)) then {player action ["TurnIn", _this player];}; sleep 0.5;};};

	displayName="RC Namer unarmed";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_RCIV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	crew="B_UAV_AI";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
			showAllTargets="2 + 4";
			gunnerCompartments="Compartment3";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="";

			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				initFov=1;
				minFov=0.125;
				maxFov=1;
			};

			weapons[]=
			{
				"TruckHorn",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
		class CommanderOptics : CommanderOptics
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_free.hpp"
			dontCreateAI=1;
			showAllTargets="2 + 4";
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			commanding=3;

			weapons[]=
			{
				"RC_Laserdesignator_vehicle",
				"TruckHorn",
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
				initFov=1;
				minFov=0.025;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
		};
	};
};
class RC_ICV_1_A_O: RC_ICV_1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_1_A_I: RC_ICV_1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_ICV_1_WD: RC_ICV_1_A
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
class RC_ICV_1_WD_O: RC_ICV_1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_1_WD_I: RC_ICV_1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_ICV_1_ReTex_D: RC_ICV_1_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_body_d.paa",
		"namer\data\mbt_01_body_d.paa",
		"namer\data\turret_d.paa",
		"namer\data\camonet_desert_co.paa"
	};
};
class RC_ICV_1_ReTex_D_O: RC_ICV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_1_ReTex_D_I: RC_ICV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_APC_1_A_Base: RC_ICV_APC_1_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\values_APC.hpp"
	editorSubcategory="RC_IFV_APC_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			dontCreateAI=1;
			showAllTargets="2 + 4";
			minElev=-19;
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
				minFov=0.025;
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
			dontCreateAI=1;
			showAllTargets="2 + 4";
			turretInfoType="RscOptics_MBT_03_gunner";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			commanding=2;

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
				minFov=0.025;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"TI"
				};
				thermalMode[]={0};
			};
		};
	};
};


class RC_APC_1_A: RC_APC_1_A_Base
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
class RC_APC_1_A_O: RC_APC_1_A
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
class RC_APC_1_A_I: RC_APC_1_A
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


class RC_APC_1_WD: RC_APC_1_A
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
class RC_APC_1_WD_O: RC_APC_1_WD
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
class RC_APC_1_WD_I: RC_APC_1_WD
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


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_APC_1_ReTex_D: RC_APC_1_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_body_d.paa",
		"namer\data\mbt_01_body_d.paa",
		"namer\data\turret_d.paa",
		"namer\data\camonet_desert_co.paa"
	};
};
class RC_APC_1_ReTex_D_O: RC_APC_1_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
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
class RC_APC_1_ReTex_D_I: RC_APC_1_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
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


//20mm IFV variant
class RC_IFV_1_A: RC_APC_1_A
{
	displayName="Namer 20mm";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_338_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_20mm_red.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_20mm_CTWS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_20mm_CTWS";
		};
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_MMG_338_APC";
		};
	};
};
class RC_IFV_1_A_O: RC_IFV_1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_93x64_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_20mm_green.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_MMG_93x64_APC";
		};
	};
};
class RC_IFV_1_A_I: RC_IFV_1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_338_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_20mm_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};


class RC_IFV_1_WD: RC_IFV_1_A
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
class RC_IFV_1_WD_O: RC_IFV_1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_93x64_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_20mm_green.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_MMG_93x64_APC";
		};
	};
};
class RC_IFV_1_WD_I: RC_IFV_1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_338_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_20mm_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_IFV_1_ReTex_D: RC_IFV_1_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_body_d.paa",
		"namer\data\mbt_01_body_d.paa",
		"namer\data\turret_d.paa",
		"namer\data\camonet_desert_co.paa"
	};
};
class RC_IFV_1_ReTex_D_O: RC_IFV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_93x64_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_20mm_green.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_MMG_93x64_APC";
		};
	};
};
class RC_IFV_1_ReTex_D_I: RC_IFV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_338_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Namer_20mm_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};