class B_APC_Tracked_01_CRV_F;
class RC_CRV_Core: B_APC_Tracked_01_CRV_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	class HitHull;
	class HitEngine;
	class HitFuel;
	class HitLTrack;
	class HitRTrack;
	class AnimationSources;
	class showCamonetHull;
	class showCamonetPlates1;
	class showCamonetPlates2;
	class showAmmobox;
	class showWheels;
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
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km_CRV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\values_RCIV.hpp"
	author="Ascent";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Support_subcat";
	driverCompartments="Compartment2";
	commanding=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	maxSpeed=80;
	enginePower=1200;
	peakTorque=6000;
	smokeLauncherGrenadeCount=18;
	smokeLauncherAngle=270;

	canAccessMineDetector=1;
	mineDetectorRange=60;

	ace_cargo_hasCargo=1;
	ace_cargo_space=5;	//4

	uavCameraDriverPos="driverview_old";
	uavCameraDriverDir="driverview_old";
	uavCameraGunnerPos="commanderview";
	uavCameraGunnerDir="commanderview";
	
	hiddenSelectionsTextures[]=
	{
		"\A3\Armor_F_Beta\APC_Tracked_01\Data\APC_Tracked_01_body_CRV_CO.paa",
		"\A3\Armor_F_Beta\APC_Tracked_01\Data\MBT_01_body_CO.paa",
		"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_CO.paa",
		"\A3\Armor_F_Beta\APC_Tracked_01\Data\APC_Tracked_01_CRV_CO.paa",
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
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=1.6;
			passThrough=1;
			explosionShielding=0.2;	//0.2
		};
		class HitEngine: HitEngine
		{
			armor=0.30000001;
			passThrough=0.5;
			explosionShielding=0.50000001;	//0.8
		};
		class HitFuel: HitFuel
		{
			armor=0.5;
			passThrough=0.30000001;
			explosionShielding=0.40000002;	//0.6
		};
		class HitLTrack: HitLTrack
		{
			armor=-650;
			explosionShielding=0.20000001;	//0.8
		};
		class HitRTrack: HitRTrack
		{
			armor=-650;
			explosionShielding=0.20000001;	//0.8
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_CRV_commander_gunner_fixated.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="";
			commanding=3;
			canAccessMineDetector=1;

			dontCreateAI=1;
			primaryObserver=1;
			primaryGunner=0;
			gunnerForceOptics=1;
			forceHideGunner=1;

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
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
		class CommanderOptics : CommanderOptics
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_CRV_commander_free.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			commanding=2;
			canAccessMineDetector=1;

			gunnerCompartments="Compartment3";
			primaryObserver=0;
			primaryGunner=1;
			gunnerForceOptics=1;
			forceHideGunner=1;

			weapons[]=
			{
				"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class ViewOptics: ViewOptics
			{
				initFov=1;
				minFov=0.02;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
		};
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
			initPhase=0;
		};
		class showCamonetPlates1: showCamonetPlates1
		{
			initPhase=0;
		};
		class showCamonetPlates2: showCamonetPlates2
		{
			initPhase=0;
		};
		class showAmmobox: showAmmobox
		{
			initPhase=1;
		};
		class showWheels: showWheels
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
			#include "\Remote_Controlled_Artillery\includes_script\initHideTurret.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
		/*
		class RC_MinePlow
		{
			#include "\Remote_Controlled_Artillery\includes_script\initMinePlow.hpp"
		};
		*/
	};

	class UserActions: UserActions
	{
		class LowerMinePlow
		{
			displayName="Lower Mineplow";
			position="gunner";
			onlyForPlayer=0;
			radius=4;
			condition="((gunner this == player) or (this == getConnectedUAV player)) && this animationSourcePhase 'MovePlow' == 0";
			statement="this animateSource ['MovePlow', 1];";
		};
		class RaiseMinePlow
		{
			displayName="Raise Mineplow";
			position="gunner";
			onlyForPlayer=0;
			radius=4;
			condition="((gunner this == player) or (this == getConnectedUAV player)) && this animationSourcePhase 'MovePlow' == 1";
			statement="this animateSource ['MovePlow', 0];";
		};
	};

	displayName="RC Hercules U-CEV (Re-arm/pair/fuel/supply)";
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
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_CRV_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\apc_tracked_01_body_crv_olive_co.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\apc_tracked_01_crv_olive_co.paa",
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