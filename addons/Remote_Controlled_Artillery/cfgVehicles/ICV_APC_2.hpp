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
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_APC_2_A: RC_ICV_APC_2_A_Base
{
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
	radartype=2;
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
	enginePower=475.3;
	peakTorque=2415.4;
	armor=375;
	//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
	//armorStructural=1000;	//prevents instant explosion, does not make it stronger
	//hullExplosionDelay[]={15,20};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_APC_Wheeled_02_rcws_v2_F.jpg";

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
				class VehicleDriverDisplay
				{
					componentType="TransportFeedDisplayComponent";
					source="Driver";
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
			defaultDisplay="VehicleDriverDisplay";

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
				class VehicleDriverDisplay
				{
					componentType="TransportFeedDisplayComponent";
					source="Driver";
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
			#include "\Remote_Controlled_Artillery\includes\initICV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
		};
	};
	//(_this select 0) spawn {while {true} do {if (player in _this && (commander _this == player)) then {player action ["TurnIn", _this player];}; sleep 0.5;};};

	displayName="RC Otokar Arma";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;

	vehicleClass="Autonomous";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="O_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;

	maximumLoad=4000;
	threat[]={0.30000001,0.30000001,0.30000001};

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
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
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

			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="MinimapDisplayComponent";

				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
					};
					/*
					//doesnt work yet
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,2000,1000,500};
						resource="RscCustomInfoSensors";
					};
					*/
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
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
					};
					/*
					//doesnt work yet
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,2000,1000,500};
						resource="RscCustomInfoSensors";
					};
					*/
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

		class CommanderOptics : CommanderOptics
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
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

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorsDisplayComponent";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
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
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
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
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Otokar Arma";
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
	crew="O_UAV_AI";
	//driverForceOptics=1;
	//forceHideDriver=1;

	class ViewOptics: ViewOptics
	{
		visionMode[]=
		{
			"TI",
			"NVG",
			"Normal"
		};
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
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes\panels_IFV_gunner.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			turretInfoType="RscOptics_MBT_03_gunner";

			weapons[]=
			{
				"RC_HMG_127_APC",
				"RC_GMG_40mm",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_200Rnd_127x99_SLAP_T_G",
				"RC_200Rnd_127x99_SLAP_T_G",
				"RC_200Rnd_127x99_SLAP_T_G",
				"RC_200Rnd_127x99_SLAP_T_G",
				"RC_200Rnd_127x99_SLAP_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class ViewOptics: RCWSOptics
			{
				initFov=0.9;
				minFov=0.025;
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
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes\panels_IFV_commander.hpp"
			showAllTargets="2 + 4";
			turretInfoType="RscOptics_MBT_03_gunner";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			commanding=2;
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
				"SmokeLauncherMag"
			};

			class ViewOptics: ViewOptics
			{
				//directionStabilized=1;
				initFov=1;
				minFov=0.025;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"NVG",
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
			magazines[]=
			{
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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
			magazines[]=
			{
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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
			magazines[]=
			{
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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
			magazines[]=
			{
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_50Rnd_40mm_G_belt",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"RC_200Rnd_127x99_SLAP_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};

		class CommanderOptics: CommanderOptics {};
	};
};


//20mm IFV variant
class RC_IFV_2_A_O: RC_APC_2_A_O
{
	displayName="Otokar Arma 20mm AC";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_MMG_93x64_APC",
				"RC_autocannon_20mm_CTWS",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"100Rnd_20mm_HE_T_G",
				"100Rnd_20mm_HE_T_G",
				"100Rnd_20mm_HE_T_G",
				"100Rnd_20mm_HE_T_G",
				"100Rnd_20mm_APFSDS_T_G",
				"100Rnd_20mm_APFSDS_T_G",
				"100Rnd_20mm_APFSDS_T_G",
				"100Rnd_20mm_APFSDS_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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
				"RC_MMG_338_APC",
				"RC_autocannon_20mm_CTWS",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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
			magazines[]=
			{
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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
				"RC_MMG_338_APC",
				"RC_autocannon_20mm_CTWS",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_HE_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"100Rnd_20mm_APFSDS_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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
			magazines[]=
			{
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_HE_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"100Rnd_20mm_APFSDS_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};

		class CommanderOptics: CommanderOptics {};
	};
};