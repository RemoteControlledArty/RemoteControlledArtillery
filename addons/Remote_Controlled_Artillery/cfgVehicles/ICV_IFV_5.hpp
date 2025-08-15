class O_APC_Tracked_02_cannon_F;
class RC_ICV_IFV_5_A_Base: O_APC_Tracked_02_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	//class HitPoints;
	//class HitLTrack;
	//class HitRTrack;
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class UserActions;
	//class TextureSources;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_IFV_5_A: RC_ICV_IFV_5_A_Base
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
	lockDetectionSystem="2+4+8";

	RC_ATrespondingTurret[]={0,0};
	//RC_ignoreRockets=1;

	weapons[]=
	{
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag"
	};

	author="Ascent";
	faction="RemoteControlled_O";
	scope=0;
	scopeCurator=0;
	side=0;
	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	enginePower=575.3;
	peakTorque=2923.7;

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_30mm_CTWS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm_CTWS";
		};
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_IFV_Missile_Launcher";
		};
		class Missiles_reloadMagazine: Missiles_revolving
		{
			source="reloadMagazine";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
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

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};


class RC_ICV_5_A_O: RC_ICV_IFV_5_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initHideTurret.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
	};

	displayName="RC BM-2T unarmed";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_RCIV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	crew="O_UAV_AI";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	weapons[]=
	{
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment3";
			commanding=2;
			gunnerForceOptics=1;
			//forceHideGunner=1;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="";

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
					minFov=0.125;
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
				minFov=0.125;
				maxFov=1;
			};

			weapons[]=
			{
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					turretInfoType="";
					gunnerForceOptics=1;
					//forceHideGunner=1;
					commanding=3;

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
							minFov=0.125;
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
						minFov=0.125;
						maxFov=1;
					};
				};
			};
		};
	};
};
class RC_ICV_5_WD_O: RC_ICV_5_A_O
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Tracked_02_cannon_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\APC_Tracked_02\Data\APC_Tracked_02_ext_01_ghex_CO.paa",
		"A3\Armor_F_Exp\APC_Tracked_02\Data\APC_Tracked_02_ext_02_ghex_CO.paa",
		"A3\Armor_F_Exp\APC_Tracked_02\Data\RCWS30_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa",
		"A3\armor_f\data\cage_csat_green_CO.paa"
	};
};


class RC_IFV_5_A_O: RC_ICV_IFV_5_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	displayName="BM-2T";
	editorSubcategory="RC_IFV_ATGM_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	crew="O_UAV_AI";
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;
	
	weapons[]=
	{
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			//forceHideGunner=1;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_autocannon_30mm_CTWS",
				"RC_MMG_93x64_coax_ext",
				"RC_IFV_Missile_Launcher",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_BM2T_30mm_green.hpp"

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
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_APC_03_m_F.p3d";
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
					//forceHideGunner=1;
					turretInfoType="RscOptics_MBT_03_gunner";
					//turretInfoType="RscOptics_APC_Wheeled_03_commander";

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
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							//gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
							gunnerOpticsEffect[]={};
						};
					};

					/*
					//no stabilization effect
					class ViewOptics: ViewOptics
					{
						directionStabilized=1;
						
						initFov=0.9;
						minFov=0.02;
						maxFov=0.9;
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={0};
					};
					*/
				};
			};
		};
	};
};
class RC_IFV_5_WD_O: RC_IFV_5_A_O
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Tracked_02_cannon_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\APC_Tracked_02\Data\APC_Tracked_02_ext_01_ghex_CO.paa",
		"A3\Armor_F_Exp\APC_Tracked_02\Data\APC_Tracked_02_ext_02_ghex_CO.paa",
		"A3\Armor_F_Exp\APC_Tracked_02\Data\RCWS30_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa",
		"A3\armor_f\data\cage_csat_green_CO.paa"
	};
};