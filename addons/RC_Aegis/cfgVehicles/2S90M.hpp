class RC_2S90M_Base: O_R_APC_Wheeled_04_cannon_v2_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	//class HitHull;
	//class HitEngine;
	class HitFuel;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class AnimationSources;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_2S90M: RC_2S90M_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	faction="RemoteControlled_B";
	scope=0;
	scopeCurator=0;
	side=1;
	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=497.7;
	peakTorque=2529.4;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	waterLeakiness=2.5;
	canFloat=1;
	waterAngularDampingCoef=10;
	waterPPInVehicle=0;
	waterResistanceCoef=0.5;

	class HitPoints: HitPoints
	{
		class HitFuel: HitFuel
		{
			passThrough=0.30000001;
		};
		
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide_cannon
		{
			source="reload";
			weapon="RC_cannon_125mm";
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_cannon_125mm";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_cannon_125mm";
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};


class RC_2S90M_WD: RC_2S90M
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="2S90M";
	editorSubcategory="RC_FSV_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	crew="B_UAV_AI";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";
			minElev=-13;
			maxElev=25;

			weapons[]=
			{
				"RC_cannon_125mm",
				"RC_MMG_93x64_coax_ext",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_20Rnd_125mm_APFSDS_T_R",
				"RC_20Rnd_125mm_MP_T_R",
				"4Rnd_125mm_cannon_missiles",
				"RC_1000Rnd_93x64_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class OpticsIn
			{
				class Wide: RCWSOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.0125;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=2;
					turretInfoType="RscOptics_MBT_03_gunner";

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

					class OpticsIn
					{
						class Wide: RCWSOptics
						{
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={0};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
				};
			};
		};
	};
};
class RC_2S90M_WD_O: RC_2S90M_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_20Rnd_125mm_APFSDS_T_G",
				"RC_20Rnd_125mm_MP_T_G",
				"4Rnd_125mm_cannon_missiles",
				"RC_1000Rnd_93x64_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_2S90M_WD_I: RC_2S90M_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_20Rnd_125mm_APFSDS_T_Y",
				"RC_20Rnd_125mm_MP_T_Y",
				"4Rnd_125mm_cannon_missiles",
				"RC_1000Rnd_93x64_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};


class RC_2S90M_A: RC_2S90M_WD
{
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\Aegis_O_SFIA_APC_Wheeled_04_cannon_v2_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body2_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\apc_wheeled_04_sprut_turret_sand_co.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_Green_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	/*
	textureList[]=
	{
		"Green",
		0,
		"Sand",
		0
	};
	*/
};
class RC_2S90M_A_O: RC_2S90M_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_20Rnd_125mm_APFSDS_T_G",
				"RC_20Rnd_125mm_MP_T_G",
				"4Rnd_125mm_cannon_missiles",
				"RC_1000Rnd_93x64_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_2S90M_A_I: RC_2S90M_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_20Rnd_125mm_APFSDS_T_Y",
				"RC_20Rnd_125mm_MP_T_Y",
				"4Rnd_125mm_cannon_missiles",
				"RC_1000Rnd_93x64_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};