class B_APC_Tracked_01_rcws_F;
class RC_ICV_APC_1_Base: B_APC_Tracked_01_rcws_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	//class HitPoints;
	//class HitHull;
	//class HitEngine;
	//class HitFuel;
	//class HitLTrack;
	//class HitRTrack;
	class AnimationSources;
	class showCamonetHull;
	class showCamonetPlates1;
	class showCamonetPlates2;
	class ViewOptics;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_APC_1_A: RC_ICV_APC_1_Base
{
	author="Ascent";
	faction="RemoteControlled_B";
	forceHideDriver=1;
	driverForceOptics=1;
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
	maxSpeed=80;
	enginePower=1059.9;
	peakTorque=5386.3;
	//armorStructural=1000;	//prevents instant explosion, does not make it stronger
	//hullExplosionDelay[]={15,20};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Beta\APC_Tracked_01\Data\APC_Tracked_01_body_CO.paa",
		"A3\Armor_F_Beta\APC_Tracked_01\Data\mbt_01_body_co.paa",
		"a3\data_f\vehicles\turret_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
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
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetPlates1: showCamonetPlates1
		{
			initPhase=1;
		};
		class showCamonetPlates2: showCamonetPlates2
		{
			initPhase=1;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_ICV_1_A: RC_ICV_APC_1_A
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

	displayName="RC Namer";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	maximumLoad=4000;
	threat[]={0.30000001,0.30000001,0.30000001};

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
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="";

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

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="MiniMapDisplayComponent";

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
						/*
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
						/*
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
		};
		class CommanderOptics : CommanderOptics
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			commanding=3;

			weapons[]=
			{
				"RC_Laserdesignator_vehicle",
				"TruckHorn",
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
				initFov=1;
				minFov=0.025;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
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
class RC_ICV_1_A_O: RC_ICV_1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_1_A_I: RC_ICV_1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_ICV_1_WD: RC_ICV_1_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_rcws_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\APC_Tracked_01_body_olive_CO.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_ICV_1_WD_O: RC_ICV_1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_1_WD_I: RC_ICV_1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_ICV_1_ReTex_D: RC_ICV_1_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_body_d.paa",
		"namer\data\mbt_01_body_d.paa",
		"namer\data\turret_d.paa",
		"namer\data\camonet_desert_co.paa"
	};
};
class RC_ICV_1_ReTex_D_O: RC_ICV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_1_ReTex_D_I: RC_ICV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_APC_1_A_Base: RC_ICV_APC_1_A
{
	editorSubcategory="RC_IFV_APC_subcat";
	maximumLoad=3000;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgPrimaryObserver.hpp"
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
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
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R",
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

			class Components: Components
			{
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
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
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
					defaultDisplay="VehicleDriverDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
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
		};
		class CommanderOptics : CommanderOptics
		{
			#include "\Remote_Controlled_Artillery\includes\cfgPrimaryGunner.hpp"
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			turretInfoType="RscOptics_MBT_03_gunner";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
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

			class Components: Components
			{
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
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleGunnerDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="PrimaryGunner";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
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
					defaultDisplay="VehicleDriverDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleGunnerDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="PrimaryGunner";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
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
		};
	};
};


class RC_APC_1_A: RC_APC_1_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Namer";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
};
class RC_APC_1_A_O: RC_APC_1_A
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
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_APC_1_A_I: RC_APC_1_A
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


class RC_APC_1_WD: RC_APC_1_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_rcws_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\APC_Tracked_01_body_olive_CO.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_APC_1_WD_O: RC_APC_1_WD
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
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_APC_1_WD_I: RC_APC_1_WD
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


/*
class RC_APC_1_A_Driverless: RC_APC_1_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			//#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="APC I";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="";
	hasDriver=-1;
};
class RC_APC_1_A_Driverless_O: RC_APC_1_A_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_APC_1_A_Driverless_I: RC_APC_1_A_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_APC_1_WD_Driverless: RC_APC_1_A_Driverless
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_rcws_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\APC_Tracked_01_body_olive_CO.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
	};
};
class RC_APC_1_WD_Driverless_O: RC_APC_1_WD_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_APC_1_WD_Driverless_I: RC_APC_1_WD_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
*/


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_APC_1_ReTex_D: RC_APC_1_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_body_d.paa",
		"namer\data\mbt_01_body_d.paa",
		"namer\data\turret_d.paa",
		"namer\data\camonet_desert_co.paa"
	};
};
class RC_APC_1_ReTex_D_O: RC_APC_1_ReTex_D
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
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_APC_1_ReTex_D_I: RC_APC_1_ReTex_D
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
class RC_IFV_1_A: RC_APC_1_A
{
	displayName="Namer 20mm AC";

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
};
class RC_IFV_1_A_O: RC_IFV_1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

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
};
class RC_IFV_1_A_I: RC_IFV_1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

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


class RC_IFV_1_WD: RC_IFV_1_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Tracked_01_rcws_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_exp\APC_Tracked_01\Data\APC_Tracked_01_body_olive_CO.paa",
		"A3\Armor_F_exp\APC_Tracked_01\Data\mbt_01_body_olive_co.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_IFV_1_WD_O: RC_IFV_1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

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
};
class RC_IFV_1_WD_I: RC_IFV_1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

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


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_IFV_1_ReTex_D: RC_IFV_1_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"namer\data\namer_01_body_d.paa",
		"namer\data\mbt_01_body_d.paa",
		"namer\data\turret_d.paa",
		"namer\data\camonet_desert_co.paa"
	};
};
class RC_IFV_1_ReTex_D_O: RC_IFV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

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
};
class RC_IFV_1_ReTex_D_I: RC_IFV_1_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

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