class O_APC_Wheeled_02_rcws_F;
class RC_ICV_APC_2_A_Base: O_APC_Wheeled_02_rcws_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
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
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_APC_2_A: RC_ICV_APC_2_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
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
	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=475.3;
	peakTorque=2415.4;
	armor=375;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;
	
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
		class Smoke_source
		{
			source="revolving";
			weapon="SmokeLauncher";
		};
		class HitEngine_src
		{
			source="Hit";
			hitpoint="HitEngine";
			raw=1;
		};
		class HitFuel_src
		{
			source="Hit";
			hitpoint="HitFuel";
			raw=1;
		};
		class HitHull_src
		{
			source="Hit";
			hitpoint="HitHull";
			raw=1;
		};
		class HitMainGun_src
		{
			source="Hit";
			hitpoint="HitGun";
			raw=1;
		};
		class HitTurret_src
		{
			source="Hit";
			hitpoint="HitTurret";
			raw=1;
		};
		class HitComTurret_src
		{
			source="Hit";
			hitpoint="HitComTurret";
			raw=1;
		};
		class HitSLAT_Left_1_src
		{
			source="Hit";
			hitpoint="HitSLAT_Left_1";
			raw=1;
		};
		class HitSLAT_Left_2_src
		{
			source="Hit";
			hitpoint="HitSLAT_Left_2";
			raw=1;
		};
		class HitSLAT_Left_3_src
		{
			source="Hit";
			hitpoint="HitSLAT_Left_3";
			raw=1;
		};
		class HitSLAT_Right_1_src
		{
			source="Hit";
			hitpoint="HitSLAT_Right_1";
			raw=1;
		};
		class HitSLAT_Right_2_src
		{
			source="Hit";
			hitpoint="HitSLAT_Right_2";
			raw=1;
		};
		class HitSLAT_Right_3_src
		{
			source="Hit";
			hitpoint="HitSLAT_Right_3";
			raw=1;
		};
		class HitSLAT_back_src
		{
			source="Hit";
			hitpoint="HitSLAT_back";
			raw=1;
		};
		class HitSLAT_front_src
		{
			source="Hit";
			hitpoint="HitSLAT_front";
			raw=1;
		};
		class showBags
		{
			displayName="$STR_A3_animationsources_showbagshull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=0;
			mass=-50;
		};
		class showCanisters
		{
			displayName="$STR_A3_animationsources_showcanistershull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=0;
			mass=-50;
		};
		class showTools
		{
			displayName="$STR_A3_animationsources_showtoolshull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=0;
			mass=-50;
		};
		class showCamonetHull
		{
			displayName="$STR_A3_animationsources_showcamonethull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			forceAnimatePhase=1;
			forceAnimate[]=
			{
				"showCanisters",
				1
			};
			initPhase=1;
			mass=-50;
		};
		class showSLATHull
		{
			displayName="$STR_A3_animationsources_showslathull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=1;
			mass=-50;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};


class RC_ICV_2_A_O: RC_ICV_APC_2_A
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

	displayName="RC Otokar Arma unarmed";
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
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment3";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
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
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//gunnerCompartments="Compartment1";
			dontCreateAI=1;
			//personTurretAction="";	//no effect
			forceHideGunner=1;	//makes view bug
			//forceHideCommander=1;	//makes view bug
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			gunnerForceOptics=1;
			commanding=3;

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
					minFov=0.02;
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
				minFov=0.02;
				maxFov=1;
			};
		};
	};
};


class RC_ICV_2_WD_O: RC_ICV_2_A_O
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Wheeled_02_rcws_v2_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Exp\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_ghex_CO.paa",
		"a3\Armor_F_Exp\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_ghex_CO.paa",
		"a3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa",
		"A3\armor_f\data\cage_csat_green_CO.paa"
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
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
class RC_ICV_2_ReTex_WD: RC_ICV_2_ReTex_WD_O
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_ICV_2_ReTex_WD_I: RC_ICV_2_ReTex_WD_O
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
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
class RC_ICV_2_ReTex_D: RC_ICV_2_ReTex_D_O
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_ICV_2_ReTex_D_I: RC_ICV_2_ReTex_D_O
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_APC_2_A_O: RC_ICV_APC_2_A
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Otokar Arma";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_APC.hpp"
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
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			//gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_APC_02_m_F.p3d";
			turretInfoType="RscOptics_MBT_03_gunner";
			maxElev=40;	//31.5

			weapons[]=
			{
				"RC_HMG_127_APC",
				"RC_GMG_40mm",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_GMG_green.hpp"

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
			forceHideGunner=1;
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
	};
};


class RC_APC_2_WD_O: RC_APC_2_A_O
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Wheeled_02_rcws_v2_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Exp\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_ghex_CO.paa",
		"a3\Armor_F_Exp\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_ghex_CO.paa",
		"a3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa",
		"A3\armor_f\data\cage_csat_green_CO.paa"
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_APC_2_ReTex_WD_O: RC_APC_2_A_O
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
class RC_APC_2_ReTex_WD: RC_APC_2_ReTex_WD_O
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_GMG_red.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_APC_2_ReTex_WD_I: RC_APC_2_ReTex_WD_O
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_GMG_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};


class RC_APC_2_ReTex_D_O: RC_APC_2_A_O
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
class RC_APC_2_ReTex_D: RC_APC_2_ReTex_D_O
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_GMG_red.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_APC_2_ReTex_D_I: RC_APC_2_ReTex_D_O
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_GMG_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};


//20mm IFV variant
class RC_IFV_2_A_O: RC_APC_2_A_O
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
	
	displayName="Otokar Arma 20mm";

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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_20mm_green.hpp"
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
			weapon="RC_MMG_93x64_APC";
		};
	};
};


class RC_IFV_2_WD_O: RC_IFV_2_A_O
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Wheeled_02_rcws_v2_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Exp\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_ghex_CO.paa",
		"a3\Armor_F_Exp\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_ghex_CO.paa",
		"a3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa",
		"A3\armor_f\data\cage_csat_green_CO.paa"
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_IFV_2_ReTex_WD_O: RC_IFV_2_A_O
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
class RC_IFV_2_ReTex_WD: RC_IFV_2_ReTex_WD_O
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_20mm_red.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_MMG_338_APC";
		};
	};
};
class RC_IFV_2_ReTex_WD_I: RC_IFV_2_ReTex_WD
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_20mm_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};


class RC_IFV_2_ReTex_D_O: RC_IFV_2_A_O
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
class RC_IFV_2_ReTex_D: RC_IFV_2_ReTex_D_O
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_20mm_red.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_MMG_338_APC";
		};
	};
};
class RC_IFV_2_ReTex_D_I: RC_IFV_2_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_20mm_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};