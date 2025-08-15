class B_ION_APC_Wheeled_02_hmg_lxWS;
class RC_OtokarArma_RCIV_Base: B_ION_APC_Wheeled_02_hmg_lxWS
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class mg_station;
	class HitPoints;
	class HitHull;
	class HitEngine;
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
	class TextureSources;
	class ViewOptics;
	class Components;
	class UserActions;
	class mg_hide_armor_front;
	class mg_hide_armor_rear;
	class mg_muzzle_hide;
	class mg_muzzle_rot;
	class mg_ReloadAnim;
	class mg_ReloadMagazine;
	class mg_Revolving;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_OtokarArma_RCIV: RC_OtokarArma_RCIV_Base
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
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	lockDetectionSystem="2+4+8";

	RC_ATrespondingTurret[]={0};
	//RC_ignoreRockets=1;
	RC_APSCharges=2;

	weapons[]=
	{
		"TruckHorn",
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

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
	enginePower=475.3;
	peakTorque=2415.4;
	armor=375;
	maximumLoad=4000;

	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;
	
	class TextureSources: TextureSources
	{
		class Desert
		{
			textures[]=
			{
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_01_nato_CO.paa",
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_02_nato_CO.paa",
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_01_nato_CO.paa",
				"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
				"A3\armor_f\data\cage_sand_CO.paa",
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_02_nato_CO.paa"
			};
			factions[]={};
		};
	};
	textureList[]=
	{
		"Desert",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_01_nato_CO.paa",
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_02_nato_CO.paa",
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_01_nato_CO.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"A3\armor_f\data\cage_sand_CO.paa",
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_02_nato_CO.paa"
	};
	
	class ViewOptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
		initFov=0.40000001;
		minFov=0.23;
		maxFov=0.40000001;
	};

	class Turrets: Turrets
	{
		//manual HMG
		class mg_station: mg_station
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgPrimaryObserver.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_free.hpp"
			commanding=2;
			dontCreateAI=1;

			weapons[]=
			{
				"RC_HMG_M2_lxWS",
				"SmokeLauncher"
			};
			#include "\RC_WesternSahara\includes_vicmags\mags_Otokar_Arma_HMG_red.hpp"

			class ViewOptics
			{
				initFov=0.75;
				minFov=0.175;
				maxFov=1;

				initAngleX=0;
				initAngleY=0;
				maxAngleX=30;
				maxAngleY=100;
				maxMoveX=0;
				maxMoveY=0;
				maxMoveZ=0;
				minAngleX=-30;
				minAngleY=-100;
				minMoveX=0;
				minMoveY=0;
				minMoveZ=0;
				speedZoomMaxFOV=0;
				speedZoomMaxSpeed=1e+010;
			};
		};

		//rear commander camera for remote control
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgPrimaryGunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_HMG.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			gunnerCompartments="Compartment3";
			forceHideGunner=1;
			gunnerForceOptics=1;

			//canUseScanner = 0; // Can't use the vehicle's Sensors, can be defined per individual turret. Useful to restrict access to vehicle sensors (target marking) on some positions in vehicles (i.e. door gunners)

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

					initFov=1;
					minFov=0.025;
					maxFov=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				initFov=1;
				minFov=0.025;
				maxFov=1;
			};
		};
		
		//commander seat camera
		class CommanderOptics : CommanderOptics
		{
			//#include "\Remote_Controlled_Artillery\includes_cfg\cfgPrimaryGunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgPrimaryObserver.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_HMG.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//forceHideGunner=1;
			//gunnerForceOptics=1;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			commanding=3;
			dontCreateAI=1;

			weapons[]=
			{
				"SmokeLauncher"
			};
			magazines[]=
			{
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

					initFov=1;
					minFov=0.025;
					maxFov=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				initFov=1;
				minFov=0.025;
				maxFov=1;
			};
		};
	};

	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=1.7;
		};
		class HitEngine: HitEngine
		{
			armor=0.925;
		};
		class HitFuel: HitFuel
		{
			armor=0.625;
		};

		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};
	
	class AnimationSources: AnimationSources
	{
		class mg_hide_armor_front: mg_hide_armor_front
		{
			initPhase=0;
		};
		class mg_hide_armor_rear: mg_hide_armor_rear
		{
			initPhase=0;
		};
		class mg_muzzle_hide
		{
			source="reload";
			weapon="RC_HMG_M2_lxWS";
		};
		class mg_muzzle_rot
		{
			source="ammorandom";
			weapon="RC_HMG_M2_lxWS";
		};
		class mg_ReloadAnim
		{
			source="reload";
			weapon="RC_HMG_M2_lxWS";
		};
		class mg_ReloadMagazine
		{
			source="reloadmagazine";
			weapon="RC_HMG_M2_lxWS";
		};
		class mg_Revolving
		{
			source="revolving";
			weapon="RC_HMG_M2_lxWS";
		};
	};

	animationList[]=
	{
		"showBags",
		0,
		"showCanisters",
		1,
		"showTools",
		0,
		"showCamonetHull",
		1,
		"showSLATHull",
		1,
		"mg_hide_armor_front",
		0,
		"mg_hide_armor_rear",
		0,
		"mg_Hide_Rail",
		0
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_OtokarArma_RCIV_A: RC_OtokarArma_RCIV
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initICV_HMG.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV_HMG.hpp"
		};
	};

	displayName="RC Otokar Arma HMG";
	editorSubcategory="RC_ICV_armed_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	crew="B_UAV_AI";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
};
class RC_OtokarArma_RCIV_A_O: RC_OtokarArma_RCIV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class mg_station: mg_station
		{
			#include "\RC_WesternSahara\includes_vicmags\mags_Otokar_Arma_HMG_green.hpp"
		};
	};
};
class RC_OtokarArma_RCIV_A_I: RC_OtokarArma_RCIV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class mg_station: mg_station
		{
			#include "\RC_WesternSahara\includes_vicmags\mags_Otokar_Arma_HMG_yellow.hpp"
		};
	};
};


class RC_OtokarArma_RCIV_WD: RC_OtokarArma_RCIV_A
{
	class TextureSources: TextureSources
	{
		class Green
		{
			textures[]=
			{
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_01_nato_CO.paa",
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_02_nato_CO.paa",
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_01_nato_CO.paa",
				"a3\armor_f\data\camonet_green_co.paa",
				"A3\armor_f\data\cage_csat_green_CO.paa",
				"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_02_nato_CO.paa"
			};
			factions[]={};
		};
	};
	textureList[]=
	{
		"Green",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_01_nato_CO.paa",
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_ext_02_nato_CO.paa",
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_01_nato_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_csat_green_CO.paa",
		"lxWS\vehicles_1_f_lxws\APC_Wheeled_02\data\APC_Wheeled_02_adds_02_nato_CO.paa"
	};
};
class RC_OtokarArma_RCIV_WD_O: RC_OtokarArma_RCIV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class mg_station: mg_station
		{
			#include "\RC_WesternSahara\includes_vicmags\mags_Otokar_Arma_HMG_green.hpp"
		};
	};
};
class RC_OtokarArma_RCIV_WD_I: RC_OtokarArma_RCIV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class mg_station: mg_station
		{
			#include "\RC_WesternSahara\includes_vicmags\mags_Otokar_Arma_HMG_yellow.hpp"
		};
	};
};