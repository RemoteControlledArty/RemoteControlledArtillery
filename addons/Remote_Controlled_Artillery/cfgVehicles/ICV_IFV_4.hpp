class B_APC_Wheeled_01_cannon_F;
class RC_ICV_IFV_4_A_Base: B_APC_Wheeled_01_cannon_F
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
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_IFV_4_A: RC_ICV_IFV_4_A_Base
{
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
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	lockDetectionSystem=4;
	incomingMissileDetectionSystem=16;
	soundLocked[]=
	{
		"\A3\Sounds_F\weapons\Rockets\locked_1",
		1,
		1
	};
	soundIncommingMissile[]=
	{
		"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4",
		0.39810717,
		1
	};
	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=593.8;
	peakTorque=3017.6;
	//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
	//armorStructural=1000;	//prevents instant explosion, does not make it stronger
	//hullExplosionDelay[]={15,20};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds

	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"a3\Armor_F\Data\cage_sand_CO.paa"
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
		
		#include "\Remote_Controlled_Artillery\includes\hitWheels.hpp"
	};
	
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};

				#include "\Remote_Controlled_Artillery\includes\passiveRadar.hpp"
			};
		};

		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";

			class Components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={4000,2000,1000,500};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoMiniMap";
				};
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
				/*
				class MineDetectorDisplay
				{
					componentType="MineDetectorDisplayComponent";
					range=50;
					resource="RscCustomInfoMineDetect";
				};
				*/
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="EmptyDisplayComponent";

			class Components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={4000,2000,1000,500};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoMiniMap";
				};
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
				/*
				class MineDetectorDisplay
				{
					componentType="MineDetectorDisplayComponent";
					range=50;
					resource="RscCustomInfoMineDetect";
				};
				*/
			};
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_ICV_4_A: RC_ICV_IFV_4_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initICV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
		};
	};
	//(_this select 0) spawn {while {true} do {if (player in _this && (commander _this == player)) then {player action ["TurnIn", _this player];}; sleep 0.5;};};

	displayName="RC Patria AMV unarmed";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;

	vehicleClass="Autonomous";
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

	/*
	//doesnt work yet
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherOnTurret=0;	//1
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
	*/

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes\panels_ICV_commander_gunner_fixated.hpp"
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
				"TruckHorn"
			};
			/*
			//doesnt work yet
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
			*/
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes\panels_ICV_commander_gunner_fixated.hpp"
					showAllTargets="2 + 4";
					//personTurretAction="";	//no effect
					//forceHideGunner=1;	//makes view bug
					//forceHideCommander=1;	//makes view bug
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					turretInfoType="";
					gunnerForceOptics=1;
					commanding=3;

					weapons[]=
					{
						"TruckHorn"
					};

					/*
					//doesnt work yet
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
					*/
					
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

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_40mm_CTWS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_40mm_CTWS";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_autocannon_40mm_CTWS";
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
};
class RC_ICV_4_A_O: RC_ICV_4_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_4_A_I: RC_ICV_4_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_ICV_4_WD: RC_ICV_4_A
{
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
};
class RC_ICV_4_WD_O: RC_ICV_4_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_4_WD_I: RC_ICV_4_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_IFV_4_A: RC_ICV_IFV_4_A
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};
	/*
	//Missile launcher on top, memoryppoint unclear, and rotate with boolean not working
	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {waitUntil {!isNull driver _this}; _this lockDriver true; waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this; ('B_static_AA_F' createVehicle [0,0,0]) attachTo [_this, [1,1,1], 'mainTurret', true]}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};
	*/

	displayName="Patria AMV";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;
	maximumLoad=3000;
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

	//vehicleClass="Autonomous";
	//uavCameraDriverPos="PiP0_pos";
	//uavCameraDriverDir="PiP0_dir";
	//isUav=1;
	//textPlural="UGVs";
	//textSingular="UGV";
	crew="B_UAV_AI";
	//driverForceOptics=1;
	//forceHideDriver=1;
	
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

	class ViewOptics: ViewOptics
	{
		visionMode[]=
		{
			"TI",
			"NVG",
			"Normal"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes\panels_IFV_gunner.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			minElev=-10.6;
			maxElev=40;

			weapons[]=
			{
				"RC_autocannon_40mm_CTWS",
				"RC_MMG_338_coax",
				//"RC_IFV_Missile_Launcher",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_50Rnd_40mm_MP_T_R",
				"RC_50Rnd_40mm_MP_T_R",
				"RC_50Rnd_40mm_MP_T_R",
				"RC_50Rnd_40mm_GPR_T_R",
				"RC_50Rnd_40mm_GPR_T_R",
				"RC_50Rnd_40mm_GPR_T_R",
				//"RC_50Rnd_40mm_Smoke",
				//"RC_50Rnd_40mm_Smoke",
				"RC_50Rnd_40mm_APFSDS_T_R",
				"RC_50Rnd_40mm_APFSDS_T_R",
				"RC_50Rnd_40mm_APFSDS_T_R",
				"RC_50Rnd_40mm_APFSDS_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_AA",
				//"RC_2Rnd_IFV_AA",
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
					#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes\panels_IFV_commander.hpp"
					showAllTargets="2 + 4";
					commanding=2;
					turretInfoType="RscOptics_MBT_03_gunner";
					//turretInfoType="RscOptics_APC_Wheeled_03_commander";	//green

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
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_w_F.p3d";	//green
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

	class AnimationSources: AnimationSources
	{
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
};
class RC_IFV_4_A_O: RC_IFV_4_A
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
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				//"RC_50Rnd_40mm_Smoke",
				//"RC_50Rnd_40mm_Smoke",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_AA",
				//"RC_2Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_4_A_I: RC_IFV_4_A
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
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				//"RC_50Rnd_40mm_Smoke",
				//"RC_50Rnd_40mm_Smoke",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_AA",
				//"RC_2Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};


class RC_IFV_4_WD: RC_IFV_4_A
{
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
};
class RC_IFV_4_WD_O: RC_IFV_4_WD
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
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				//"RC_50Rnd_40mm_Smoke",
				//"RC_50Rnd_40mm_Smoke",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_AA",
				//"RC_2Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_4_WD_I: RC_IFV_4_WD
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
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				//"RC_50Rnd_40mm_Smoke",
				//"RC_50Rnd_40mm_Smoke",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_AA",
				//"RC_2Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_ICV_4_ReTex_D: RC_ICV_4_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"patria\data\patria_01_ext_d.paa",
		"patria\data\patria_02_ext_d.paa",
		"patria\data\patria_turret_d.paa",
		"patria\data\camonet_desert_co.paa",
		"patria\data\cage_desert_co.paa"
	};
};
class RC_ICV_4_ReTex_D_O: RC_ICV_4_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_4_ReTex_D_I: RC_ICV_4_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_IFV_4_ReTex_D: RC_IFV_4_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"patria\data\patria_01_ext_d.paa",
		"patria\data\patria_02_ext_d.paa",
		"patria\data\patria_turret_d.paa",
		"patria\data\camonet_desert_co.paa",
		"patria\data\cage_desert_co.paa"
	};
};
class RC_IFV_4_ReTex_D_O: RC_IFV_4_ReTex_D
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
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_MP_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				"RC_50Rnd_40mm_GPR_T_G",
				//"RC_50Rnd_40mm_Smoke",
				//"RC_50Rnd_40mm_Smoke",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_50Rnd_40mm_APFSDS_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_AA",
				//"RC_2Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_4_ReTex_D_I: RC_IFV_4_ReTex_D
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
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_MP_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				"RC_50Rnd_40mm_GPR_T_Y",
				//"RC_50Rnd_40mm_Smoke",
				//"RC_50Rnd_40mm_Smoke",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_50Rnd_40mm_APFSDS_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_MP_NLOS",
				//"RC_2Rnd_IFV_AA",
				//"RC_2Rnd_IFV_AA",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};