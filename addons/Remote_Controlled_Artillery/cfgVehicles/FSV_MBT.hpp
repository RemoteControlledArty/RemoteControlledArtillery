//NLOS FSV
class B_AFV_Wheeled_01_up_cannon_F;
class RC_FSV_A_Base: B_AFV_Wheeled_01_up_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class Components;
	class EventHandlers;
	class ViewOptics;
	class ViewPilot;
	class HitPoints;
	class HitLFWheel;
	class HitLBWheel;
	class HitLMWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRBWheel;
	class HitRMWheel;
	class HitRF2Wheel;
	scope=0;
	scopeCurator=0;
	//RCDisableSeats=6; //locks gunner&commander seat while remote controlling driver (changing seats causes serve bugs)
	//RCReenableSeats=6;	//reunlocks gunner/commander seats when not remote controlling
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_FSV_A: RC_FSV_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!local (_this select 0)) exitwith {}; (_this select 0) spawn {waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
			#include "\Remote_Controlled_Artillery\includes\RC_GunnerIsDriverEH.hpp"
		};
	};

	displayName="FSV";
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_MBT_subcat";
	author="Ascent";
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
	driverForceOptics=1;
	forceHideDriver=1;
	driverCompartments="Compartment2";
	//hideProxyInCombat=1;	//for later use
	//canHideDriver=1;	//for later use
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	weaponLockSystem=4;
	incomingMissileDetectionSystem=16;
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

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
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};

	animationList[]=
	{
		"showCamonetHull",
		1,
		"showCamonetCannon",
		1,
		"showCamonetTurret",
		1,
		"showSLATHull",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";
			commanding=2;

			weapons[]=
			{
				"RC_cannon_120mm",
				"RC_MMG_338_FSV_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_12Rnd_120mm_APFSDS_T",
				"RC_16Rnd_120mm_MP_T",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
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
					minFov=0.0166;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
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
							range[]={3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
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
							range[]={3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
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

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					showAllTargets="2 + 4";
					commanding=1;

					weapons[]=
					{
						"RC_MMG_338_FSV",
						"Laserdesignator_mounted",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"Laserbatteries",
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
							minFov=0.0166;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={0,1};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
					/*
					class ViewOptics: ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.9;
						minFov=0.0166;
						maxFov=0.9;
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={0,1};
					};
					*/
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
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
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
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
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
	};

	wheelDamageThreshold=0.18000001;
	wheelDamageRadiusCoef=0.75;
	class HitPoints: HitPoints
	{
		class HitLFWheel: HitLFWheel
		{
			radius=0.33000001;
			visual="wheel_1_1_hide";
			armorComponent="wheel_1_1_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			radius=0.33000001;
			visual="wheel_1_2_hide";
			armorComponent="wheel_1_2_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
		class HitLMWheel: HitLMWheel
		{
			radius=0.33000001;
			visual="wheel_1_3_hide";
			armorComponent="wheel_1_3_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
		class HitLBWheel: HitLBWheel
		{
			radius=0.33000001;
			visual="wheel_1_4_hide";
			armorComponent="wheel_1_4_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
		class HitRFWheel: HitRFWheel
		{
			radius=0.33000001;
			visual="wheel_2_1_hide";
			armorComponent="wheel_2_1_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			radius=0.33000001;
			visual="wheel_2_2_hide";
			armorComponent="wheel_2_2_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
		class HitRMWheel: HitRMWheel
		{
			radius=0.33000001;
			visual="wheel_2_3_hide";
			armorComponent="wheel_2_3_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
		class HitRBWheel: HitRBWheel
		{
			radius=0.33000001;
			visual="wheel_2_4_hide";
			armorComponent="wheel_2_4_hide";
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=3;
			passThrough=0;
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes\FSVitemsB.hpp"
};
class RC_FSV_A_O: RC_FSV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsO.hpp"
};
class RC_FSV_A_I: RC_FSV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsI.hpp"
};
class RC_FSV_WD: RC_FSV_A
{
	editorPreview="\A3\EditorPreviews_F_Tank\Data\CfgVehicles\B_T_AFV_Wheeled_01_up_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT1_green_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT2_green_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_wheel_green_CO.paa",
		"A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_commander_tow_CO.paa",
		"a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
		"A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_CO.paa"
	};
	textureList[]=
	{
		"Green",
		1,
		"Sand",
		0
	};
};
class RC_FSV_WD_O: RC_FSV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsO.hpp"
};
class RC_FSV_WD_I: RC_FSV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsI.hpp"
};


//MBT+6Inf
class B_MBT_01_TUSK_F;
class RC_MBT6_Base: B_MBT_01_TUSK_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class Components;
	class EventHandlers;
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetHull;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	//RCDisableSeats=6; //locks gunner&commander seat while remote controlling driver (changing seats causes serve bugs)
	//RCReenableSeats=6;	//reunlocks gunner/commander seats when not remote controlling
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_MBT6_A_Base: RC_MBT6_Base
{
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_MBT_subcat";
	author="Ascent";
	driverForceOptics=1;
	forceHideDriver=1;
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	weaponLockSystem=4;
	incomingMissileDetectionSystem=16;
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet
	maxSpeed=70;
	enginePower=1538;
	peakTorque=6250;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

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
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";
			commanding=2;
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					showAllTargets="2 + 4";
					commanding=1;

					weapons[]=
					{
						"RC_MMG_338_MBT",
						"Laserdesignator_mounted",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"RC_200Rnd_338_T_Mag",
						"Laserbatteries",
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
							minFov=0.0166;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={0,1};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
					/*
					class ViewOptics: ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.9;
						minFov=0.0166;
						maxFov=0.9;
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={0,1};
					};
					*/
					class Components: Components
					{
						class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
						{
							defaultDisplay="SensorDisplay";

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
								class SensorDisplay
								{
									componentType="SensorsDisplayComponent";
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
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
								class EmptyDisplay
								{
									componentType="EmptyDisplayComponent";
								};
								class MinimapDisplay
								{
									componentType="MinimapDisplayComponent";
									resource="RscCustomInfoMiniMap";
								};
								class SensorDisplay
								{
									componentType="SensorsDisplayComponent";
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
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

			weapons[]=
			{
				"RC_cannon_120mm",
				"RC_MMG_338_MBT_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_20Rnd_120mm_APFSDS_T",
				"RC_20Rnd_120mm_MP_T",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"SmokeLauncherMag"
			};

			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

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
					minFov=0.0166;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
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
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
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

	#include "\Remote_Controlled_Artillery\includes\IFVitemsB.hpp"
};


class RC_MBT6_A_Driverless: RC_MBT6_A_Base
{
	class EventHandlers: EventHandlers
	{
		init="if (!local (_this select 0)) exitwith {}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};

	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="MBT [6 Inf]";
	crew="";
	hasDriver=-1;
};
class RC_MBT6_A_Driverless_O: RC_MBT6_A_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsO.hpp"
};
class RC_MBT6_A_Driverless_I: RC_MBT6_A_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsI.hpp"
};


class RC_MBT6_WD_Driverless: RC_MBT6_A_Driverless
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_TUSK_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_tow_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\mbt_addons_olive_CO.paa",
		"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
	};
};
class RC_MBT6_WD_Driverless_O: RC_MBT6_WD_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsO.hpp"
};
class RC_MBT6_WD_Driverless_I: RC_MBT6_WD_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsI.hpp"
};


/*
class RC_MBT6_A: RC_MBT6_A_Base
{
	class EventHandlers: EventHandlers
	{
		init="if (!local (_this select 0)) exitwith {}; (_this select 0) spawn {waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};

	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="MBT [6 Inf]";
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
};
class RC_MBT6_A_O: RC_MBT6_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsO.hpp"
};
class RC_MBT6_A_I: RC_MBT6_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsI.hpp"
};


class RC_MBT6_WD: RC_MBT6_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_TUSK_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_tow_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\mbt_addons_olive_CO.paa",
		"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
	};
};
class RC_MBT6_WD_O: RC_MBT6_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsO.hpp"
};
class RC_MBT6_WD_I: RC_MBT6_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\IFVitemsI.hpp"
};
*/