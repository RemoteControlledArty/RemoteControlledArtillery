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
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_OtokarArma_RCIV: RC_OtokarArma_RCIV_Base
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
	smokeLauncherGrenadeCount=12;
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

	/*
	driverAction="Driver_APC_Wheeled_02_rcws_F_out";
	driverInAction="Driver_APC_Wheeled_02_rcws_F_in";
	LODDriverTurnedOut=1201;
	LODDriverTurnedin=1100;
	LODDriverOpticsIn=1202;
	viewDriverInExternal=1;
	viewDriverShadowAmb=0.5;
	viewDriverShadowDiff=0.050000001;
	showNVGDriver=0;
	showNVGCommander=0;
	showNVGGunner=0;
	driverOpticsModel="\A3\weapons_f\reticle\optics_empty";

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_APC_Wheeled_02_rcws_v2_F.jpg";
	*/
	
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
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_HMG_127_APC";
		};
		class HideTurret
		{
			source="user";
			initPhase=0;
			animPeriod=0.001;
		};

		class showBags
		{
			initPhase=0;
		};
		class showCanisters
		{
			initPhase=0;
		};
		class showTools
		{
			initPhase=0;
		};
		class showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
		*/
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

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};


class RC_OtokarArma_RCIV_A: RC_OtokarArma_RCIV
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
	};
	//(_this select 0) spawn {while {true} do {if (player in _this && (commander _this == player)) then {player action ["TurnIn", _this player];}; sleep 0.5;};};

	displayName="RC Otokar Arma HMG";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_RCIV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	crew="B_UAV_AI";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

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

	class Turrets: Turrets
	{
		class mg_station: mg_station
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgPrimaryObserver.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_free.hpp"
			//gunnerCompartments="Compartment3";
			commanding=2;
			dontCreateAI=1;
			/*
			magazines[]=
			{
				"200Rnd_127x99_mag_Tracer_Red",
				"200Rnd_127x99_mag_Tracer_Red",
				"200Rnd_127x99_mag_Tracer_Red",
				"200Rnd_127x99_mag_Tracer_Red"
			};
			*/
		};
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_free.hpp"
			showAllTargets="2 + 4";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			commanding=3;
			dontCreateAI=1;

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

		class CommanderOptics : CommanderOptics
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgPrimaryGunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_free.hpp"
			showAllTargets="2 + 4";
			//personTurretAction="";	//no effect
			forceHideGunner=1;	//makes view bug
			//forceHideCommander=1;	//makes view bug
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			gunnerForceOptics=1;
			commanding=3;
			gunnerCompartments="Compartment3";

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
};
class RC_OtokarArma_RCIV_A_O: RC_OtokarArma_RCIV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OtokarArma_RCIV_A_I: RC_OtokarArma_RCIV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
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
};
class RC_OtokarArma_RCIV_WD_I: RC_OtokarArma_RCIV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};

//optional Phantom Hawk Retextures (found in steam workshop)
/*
class RC_ICV_2_ReTex_WD_O: RC_ICV_2_A_O
{
	faction="RemoteControlled_ReTex_O";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Wheeled_02_rcws_v2_ghex_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"arma\data\arma_01_ext_wd.paa",
		"arma\data\arma_02_ext_wd.paa",
		"arma\data\turret_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"a3\armor_f\data\cage_g1_co.paa"
	};
	textureList[]=
	{
		"Hex",
		0
	};
};


class RC_ICV_2_ReTex_D_O: RC_ICV_2_A_O
{
	faction="RemoteControlled_ReTex_O";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"arma\data\arma_01_ext_d.paa",
		"arma\data\arma_02_ext_d.paa",
		"arma\data\turret_d.paa",
		"arma\data\camonet_desert_co.paa",
		"arma\data\cage_desert_co.paa"
	};
	textureList[]=
	{
		"Hex",
		0
	};
};
*/