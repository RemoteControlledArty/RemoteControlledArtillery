class B_APC_Wheeled_03_cannon_F;
class RC_ICV_IFV_3_A_Base: B_APC_Wheeled_03_cannon_F
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
	class showCamonetHull;
	class showSLATHull;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_IFV_3_A: RC_ICV_IFV_3_A_Base
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
	enginePower=553;
	peakTorque=2810.4;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_APC_Wheeled_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_gamma\apc_wheeled_03\data\apc_wheeled_03_ext_co.paa",
		"a3\armor_f_gamma\apc_wheeled_03\data\apc_wheeled_03_ext2_co.paa",
		"a3\armor_f_gamma\apc_wheeled_03\data\rcws30_co.paa",
		"a3\armor_f_gamma\apc_wheeled_03\data\apc_wheeled_03_ext_alpha_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"a3\armor_f\data\cage_sand_co.paa"
	};

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
		class revolving_cannon
		{
			source="revolving";
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
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_ICV_3_A: RC_ICV_IFV_3_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initICV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
	};
	//init="if (!local (_this select 0)) exitwith {}; (_this select 0) spawn {waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this; {_this animate [_x, 1]} forEach ['HideHull','HideTurret'];}; (_this select 0) spawn {while {true} do {if (isPlayer _this && !(isPlayer (gunner _this))) then {_this lockTurret [[0], true]} else {_this lockTurret [[0], false]}; sleep 0.5;};}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	//(_this select 0) spawn {while {true} do {if (player in _this && (commander _this == player)) then {player action ["TurnIn", _this player];}; sleep 0.5;};};

	displayName="RC Pandur II unarmed";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;

	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;

	maximumLoad=4000;
	threat[]={0.30000001,0.30000001,0.30000001};

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
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
					showAllTargets="2 + 4";
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					turretInfoType="";
					gunnerForceOptics=1;
					commanding=3;

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
class RC_ICV_3_A_O: RC_ICV_3_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_3_A_I: RC_ICV_3_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
class RC_ICV_3_DIG_I: RC_ICV_3_A_I
{
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_APC_Wheeled_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext2_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\RCWS30_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_alpha_INDP_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
};


class RC_ICV_3_WD: RC_ICV_3_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext2_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\RCWS30_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_alpha_IG_01_CO.paa",
		//"A3\Armor_F\Data\camonet_AAF_FIA_green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_G1_co.paa"
	};
	textureList[]=
	{
		"Guerilla_01",
		1,
		"Guerilla_02",
		0,
		"Guerilla_03",
		0
	};
};
class RC_ICV_3_WD_O: RC_ICV_3_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_3_WD_I: RC_ICV_3_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_IFV_3_A: RC_ICV_IFV_3_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Pandur II";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;
	maximumLoad=3000;

	//vehicleClass="Autonomous";
	//uavCameraDriverPos="PiP0_pos";
	//uavCameraDriverDir="PiP0_dir";
	//isUav=1;
	//textPlural="UGVs";
	//textSingular="UGV";
	crew="B_UAV_AI";
	//driverForceOptics=1;
	//forceHideDriver=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_autocannon_30mm_CTWS",
				"RC_MMG_338_coax_ext",
				"RC_IFV_Missile_Launcher",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_100Rnd_30mm_MP_T_R",
				"RC_100Rnd_30mm_MP_T_R",
				"RC_100Rnd_30mm_GPR_T_R",
				"RC_100Rnd_30mm_GPR_T_R",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_R",
				"RC_100Rnd_30mm_APFSDS_T_R",
				"RC_100Rnd_30mm_APFSDS_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_2Rnd_IFV_MP_NLOS",
				"RC_2Rnd_IFV_MP_NLOS",
				"RC_2Rnd_IFV_AA",
				"RC_2Rnd_IFV_AA",
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
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_APC_03_m_F.p3d";
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
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
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
class RC_IFV_3_A_O: RC_IFV_3_A
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
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_3_A_I: RC_IFV_3_A
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
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_3_DIG_I: RC_IFV_3_A_I
{
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_APC_Wheeled_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext2_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\RCWS30_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_alpha_INDP_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
};


class RC_IFV_3_WD: RC_IFV_3_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext2_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\RCWS30_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_alpha_IG_01_CO.paa",
		//"A3\Armor_F\Data\camonet_AAF_FIA_green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_G1_co.paa"
	};
	textureList[]=
	{
		"Guerilla_01",
		1,
		"Guerilla_02",
		0,
		"Guerilla_03",
		0
	};
};
class RC_IFV_3_WD_O: RC_IFV_3_WD
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
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_3_WD_I: RC_IFV_3_WD
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
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_ICV_3_ReTex_WD: RC_ICV_3_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	hiddenSelectionsTextures[]=
	{
		"pandurii\data\pandur_01_ext_wd.paa",
		"pandurii\data\pandur_02_ext_wd.paa",
		"pandurii\data\pandur_turret_wd.paa",
		"pandurii\data\pandur_03_ext_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"a3\armor_f\data\cage_g1_co.paa"
	};
};
class RC_ICV_3_ReTex_WD_O: RC_ICV_3_ReTex_WD
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_3_ReTex_WD_I: RC_ICV_3_ReTex_WD
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_ICV_3_ReTex_D: RC_ICV_3_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"pandurii\data\pandur_01_ext_d.paa",
		"pandurii\data\pandur_02_ext_d.paa",
		"pandurii\data\pandur_turret_d.paa",
		"pandurii\data\pandur_03_ext_d.paa",
		"pandurii\data\camonet_desert_co.paa",
		"pandurii\data\cage_desert_co.paa"
	};
};
class RC_ICV_3_ReTex_D_O: RC_ICV_3_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_3_ReTex_D_I: RC_ICV_3_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_IFV_3_ReTex_WD: RC_IFV_3_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	hiddenSelectionsTextures[]=
	{
		"pandurii\data\pandur_01_ext_wd.paa",
		"pandurii\data\pandur_02_ext_wd.paa",
		"pandurii\data\pandur_turret_wd.paa",
		"pandurii\data\pandur_03_ext_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"a3\armor_f\data\cage_g1_co.paa"
	};
};
class RC_IFV_3_ReTex_WD_O: RC_IFV_3_ReTex_WD
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_3_ReTex_WD_I: RC_IFV_3_ReTex_WD
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};


class RC_IFV_3_ReTex_D: RC_IFV_3_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"pandurii\data\pandur_01_ext_d.paa",
		"pandurii\data\pandur_02_ext_d.paa",
		"pandurii\data\pandur_turret_d.paa",
		"pandurii\data\pandur_03_ext_d.paa",
		"pandurii\data\camonet_desert_co.paa",
		"pandurii\data\cage_desert_co.paa"
	};
};
class RC_IFV_3_ReTex_D_O: RC_IFV_3_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_MP_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				"RC_100Rnd_30mm_GPR_T_G",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_100Rnd_30mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_3_ReTex_D_I: RC_IFV_3_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_MP_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				"RC_100Rnd_30mm_GPR_T_Y",
				//"RC_100Rnd_30mm_Smoke",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_100Rnd_30mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_3Rnd_IFV_MP_NLOS",
				"RC_3Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};