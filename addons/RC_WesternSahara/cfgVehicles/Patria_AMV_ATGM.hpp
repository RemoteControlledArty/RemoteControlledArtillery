class B_APC_Wheeled_01_atgm_lxWS;
class RC_ICV_IFV_9_Fetch: B_APC_Wheeled_01_atgm_lxWS
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
class RC_ICV_IFV_9_Core: RC_ICV_IFV_9_Fetch
{
	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	lockDetectionSystem="2+4+8";
	RC_ATrespondingTurret[]={0,0};

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

	author="Ascent";

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

	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"a3\Armor_F\Data\cage_sand_CO.paa",
		"lxws\vehicles_f_lxws\data\APC_Wheeled_01\APC_Wheeled_01_lxws_CO.paa"
	};
	
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
			weapon="RC_IFV_Missile_Launcher_4R";
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
	};

	animationList[] =
	{
		"showBags",
		0,
		"showCamonetHull",
		1,
		"showCamonetCannon",
		1,
		"showCamonetTurret",
		1,
		"showSLATHull",
		1,
		"showSLATTurret",
		1
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_IFV_9_Core: RC_ICV_IFV_9_Core
{
	displayName="Patria AMV ATGM";
	editorSubcategory="RC_IFV_ATGM_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			minElev=-10.6;
			maxElev=40;

			weapons[]=
			{
				"RC_autocannon_30mm",
				"RC_MMG_338_coax",
				"RC_IFV_Missile_Launcher_4R",
				"SmokeLauncher"
			};
			#include "\RC_WesternSahara\includes_vicmags\mags_Patria_ATGM_30mm_red.hpp"

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";

					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
				};
			};
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
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

					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
						};
					};
					turretInfoType="RscOptics_MBT_03_gunner";
				};
			};
		};
	};
};
class RC_IFV_9_Base: RC_IFV_9_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Sensor_400m.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\DriveControls_GunnerOrCommander.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cargo.hpp"
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
};


class RC_IFV_9_A: RC_IFV_9_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_IFV_9_A_O: RC_IFV_9_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_WesternSahara\includes_vicmags\mags_Patria_ATGM_30mm_green.hpp"
		};
	};
};
class RC_IFV_9_A_I: RC_IFV_9_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_WesternSahara\includes_vicmags\mags_Patria_ATGM_30mm_yellow.hpp"
		};
	};
};