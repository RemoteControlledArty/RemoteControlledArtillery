class B_APC_Wheeled_01_atgm_lxWS;
class RC_ICV_IFV_9_A_Base: B_APC_Wheeled_01_atgm_lxWS
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	class HitHull;
	class HitEngine;
	//class HitFuel;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class AnimationSources;
	class showCamonetHull;
	class showCamonetCannon;
	class showCamonetTurret;
	class showSLATHull;
	class showSLATTurret;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_IFV_9_A: RC_ICV_IFV_9_A_Base
{
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
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
	enginePower=593.8;
	peakTorque=3017.6;

	/*
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"a3\Armor_F\Data\cage_sand_CO.paa"
	};
	*/
	
	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=2;
		};
		class HitEngine: HitEngine
		{
			armor=1.25;
		};
		
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_30mm";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_autocannon_30mm";
		};
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_IFV_Missile_Launcher_lxWS";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
		class showSLATTurret: showSLATTurret
		{
			initPhase=1;
		};

		/*
		//not needed on original
		animationList[]=
		{
			"showTracks",
			0,
			"showCamonetHull",
			1,
			"showBags",
			0,
			"showSLATHull",
			1
		};
		*/
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_IFV_9_A: RC_ICV_IFV_9_A
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};
	//Missile launcher on top, memoryppoint unclear, and rotate with boolean not working

	displayName="Patria AMV ATGM";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;
	maximumLoad=3000;
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

	crew="B_UAV_AI";
	
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

	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			minElev=-10.6;
			maxElev=40;

			weapons[]=
			{
				"RC_autocannon_30mm",
				"RC_MMG_338_coax",
				"RC_IFV_Missile_Launcher_lxWS",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_100Rnd_30mm_GPR_T_R",
				"RC_100Rnd_30mm_GPR_T_R",
				"RC_100Rnd_30mm_MP_T_R",
				"RC_100Rnd_30mm_MP_T_R",
				"RC_100Rnd_30mm_APFSDS_T_R",
				"RC_100Rnd_30mm_APFSDS_T_R",
				"RC_100Rnd_30mm_APFSDS_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_4Rnd_IFV_MP_NLOS",
				"RC_4Rnd_IFV_AA",
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
					showAllTargets="2 + 4";
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
class RC_IFV_9_A_O: RC_IFV_9_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_4Rnd_IFV_MP_NLOS",
				"RC_4Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_9_A_I: RC_IFV_9_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_4Rnd_IFV_MP_NLOS",
				"RC_4Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};


class RC_IFV_9_WD: RC_IFV_9_A
{
	/*
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_base_olive_CO.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_adds_olive_co.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_tows_olive_co.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"a3\Armor_F\Data\cage_olive_CO.paa"
	};
	*/
};
class RC_IFV_9_WD_O: RC_IFV_9_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_4Rnd_IFV_MP_NLOS",
				"RC_4Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_9_WD_I: RC_IFV_9_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_4Rnd_IFV_MP_NLOS",
				"RC_4Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};