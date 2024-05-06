//NLOS FSV
class B_AFV_Wheeled_01_up_cannon_F;
class RC_FSV_A_Base: B_AFV_Wheeled_01_up_cannon_F
{
	/*
	class AnimationSources;
	class showCamonetHull;
	class showCamonetCannon;
	class showCamonetTurret;
	class showSLATHull;
	*/
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
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_FSV_A: RC_FSV_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Rooikat";
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
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT1_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT2_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_wheel_CO.paa",
		"A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_sand_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_commander_tow_sand_CO.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_sand_CO.paa"
	};
	textureList[]=
	{
		"Green",
		0,
		"Sand",
		0
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
	};

	/*
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
	};
	*/
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
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
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
				"RC_15Rnd_120mm_APFSDS_T_R",
				"RC_15Rnd_120mm_MP_T_R",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
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
					minFov=0.0166;
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
							range[]={4000,2000,1000,500};
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
					#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
					showAllTargets="2 + 4";
					commanding=1;
					turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_MMG_338_FSV",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"RC_200Rnd_338_T_R",
						"RC_200Rnd_338_T_R",
						"RC_200Rnd_338_T_R",
						"RC_200Rnd_338_T_R",
						"RC_200Rnd_338_T_R",
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

							initFov=0.9;
							minFov=0.0166;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={0};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
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
						thermalMode[]={0};
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
									range[]={4000,2000,1000,500};
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
									range[]={4000,2000,1000,500};
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
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
		class HitLMWheel: HitLMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
		class HitLBWheel: HitLBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
		class HitRMWheel: HitRMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
		class HitRBWheel: HitRBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
		};
	};
	
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};
class RC_FSV_A_O: RC_FSV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_15Rnd_120mm_APFSDS_T_G",
				"RC_15Rnd_120mm_MP_T_G",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_FSV_A_I: RC_FSV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_15Rnd_120mm_APFSDS_T_Y",
				"RC_15Rnd_120mm_MP_T_Y",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
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
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_CO.paa"
	};
	textureList[]=
	{
		"Green",
		0,
		"Sand",
		0
	};
};
class RC_FSV_WD_O: RC_FSV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_15Rnd_120mm_APFSDS_T_G",
				"RC_15Rnd_120mm_MP_T_G",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"RC_200Rnd_338_T_G",
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_FSV_WD_I: RC_FSV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_15Rnd_120mm_APFSDS_T_Y",
				"RC_15Rnd_120mm_MP_T_Y",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"RC_200Rnd_338_T_Y",
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};