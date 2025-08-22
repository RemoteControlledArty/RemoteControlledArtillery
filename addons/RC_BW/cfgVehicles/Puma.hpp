class BWA3_Puma_Fleck;
class RC_Puma_FT_Core: BWA3_Puma_Fleck
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	//class HitPoints;
	class AnimationSources;
	class ViewOptics;
	class Components;
	class EventHandlers;
	class UserActions;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Puma_FT_Base: RC_Puma_FT_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			//#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
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
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	RC_ATrespondingTurret[]={0,0};
	//RC_ignoreRockets=1;

	weapons[]=
	{
		"TruckHorn",
		"RC_APS_W",
		"BWA3_SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"BWA3_SmokeLauncherMag",
		"BWA3_SmokeLauncherMag"
	};

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

	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};
	
	//maxSpeed=;					//
	//normalSpeedForwardCoef=;	//
	//enginePower=;				//
	//peakTorque=;				//

	//smokeLauncherGrenadeCount=6;
	//smokeLauncherAngle=180;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			//minElev=-10;
			//maxElev=45;

			/*
			weapons[]=
			{
				"BWA3_MK30",
				"BWA3_MG5_vehicle",
				"BWA3_Spike_LR"
			};
			*/
			/*
			magazines[]=
			{
				"RC_240Rnd_APFSDS_shells",
				"RC_160Rnd_HEAB_shells",
				"RC_1200Rnd_762x51",
				"RC_1200Rnd_762x51",
				"BWA3_2Rnd_Spike_Lr"
			};
			*/

			weapons[]=
			{
				"RC_MK30",
				"RC_MG338_vehicle",
				//"BWA3_Spike_LR",
				"RC_SPz_Spike",
				"BWA3_SmokeLauncher"
			};
			#include "\RC_BW\includes_vicmags\mags_Puma_30mm_red.hpp"

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
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_AAA_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=2;
					//turretInfoType="RscOptics_MBT_03_gunner";
					//turretInfoType="RscOptics_APC_Wheeled_03_commander";	//green

					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						"BWA3_SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries",
						"BWA3_SmokeLauncherMag",
						"BWA3_SmokeLauncherMag"
					};

					class OpticsIn
					{
						class Wide: RCWSOptics
						{
							//directionStabilized=1;	//unfortunately causes spinning camera bug

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
							gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class mainGun_reload
		{
			source="reload";
			weapon="RC_MK30";
		};
		class mainGun_random
		{
			source="ammorandom";
			weapon="RC_MK30";
		};
		class MG_reload
		{
			source="reload";
			weapon="RC_MG338_vehicle";
		};
		class MG_random
		{
			source="ammorandom";
			weapon="RC_MG338_vehicle";
		};
		class missiles_revolving
		{
			source="revolving";
			//weapon="BWA3_Spike_LR";
			weapon="RC_SPz_Spike";
		};
	};
	animationList[]=
	{
		"hide_netz",
		1,
		"hide_netz_turret",
		1,
		"hide_netz_gun",
		1,
		"hide_netz_mells",
		1
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_Puma_30mm_FT: RC_Puma_FT_Base
{
	displayName="SPz Puma";
	editorSubcategory="RC_BW_subcat";
	scope=2;
	scopeCurator=2;
	crew="B_UAV_AI";
};
class RC_Puma_30mm_FT_O: RC_Puma_30mm_FT
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_BW\includes_vicmags\mags_Puma_30mm_green.hpp"
		};
	};
};
class RC_Puma_30mm_FT_I: RC_Puma_30mm_FT
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_BW\includes_vicmags\mags_Puma_30mm_yellow.hpp"
		};
	};
};


class RC_Puma_30mm_TT: RC_Puma_30mm_FT
{
	editorPreview="\bwa3_puma\editorpreview\BWA3_Puma_Tropen.jpg";
	textureList[]=
	{
		"Tropen1",
		1
	};
};
class RC_Puma_30mm_TT_O: RC_Puma_30mm_TT
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_BW\includes_vicmags\mags_Puma_30mm_green.hpp"
		};
	};
};
class RC_Puma_30mm_TT_I: RC_Puma_30mm_TT
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_BW\includes_vicmags\mags_Puma_30mm_yellow.hpp"
		};
	};
};