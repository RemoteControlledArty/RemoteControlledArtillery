//NLOS FSV
class B_AFV_Wheeled_01_up_cannon_F;
class RC_NLOS_FSV_A_Base: B_AFV_Wheeled_01_up_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class Components;
	class EventHandlers;
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
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles

	RC_BarrelAGL=2;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=4;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
};
class RC_NLOS_FSV_A: RC_NLOS_FSV_A_Base
{
	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {if (local _this) then waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this};";
	};

	displayName="N/LOS FSV";
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;
	forceHideDriver=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	incomingMissileDetectionSystem=16;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=360;
					angleRangeVertical=360;

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
			//maxElev=45;	//unfortunately doesnt work, due to gun having internal animation
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
				};
			};

			weapons[]=
			{
				"RC_FSV_120mm_V5",
				"RC_cannon_120mm",
				"LMG_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_FSV_120mm_HEAB_x12",
				"RC_FSV_120mm_MultiGuided_x6",
				"RC_FSV_120mm_smoke_x12",
				"12Rnd_120mm_APFSDS_shells_Tracer_Green",
				"12Rnd_120mm_MP_T_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
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

					initFov=1.0;
					minFov=0.025;
					maxFov=1.0;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
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
};
class RC_NLOS_FSV_A_O: RC_NLOS_FSV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_NLOS_FSV_A_I: RC_NLOS_FSV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_NLOS_FSV_WD: RC_NLOS_FSV_A
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
class RC_NLOS_FSV_WD_O: RC_NLOS_FSV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_NLOS_FSV_WD_I: RC_NLOS_FSV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_LOS_FSV_A: RC_NLOS_FSV_A
{
	isRCArty=0;
	displayName="FSV";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_cannon_120mm",
				"LMG_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"12Rnd_120mm_APFSDS_shells_Tracer_Green",
				"16Rnd_120mm_MP_T_Green",
				"3Rnd_120mm_DLG_cannon_missiles",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_LOS_FSV_A_O: RC_LOS_FSV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_LOS_FSV_A_I: RC_LOS_FSV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_LOS_FSV_WD: RC_LOS_FSV_A
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
class RC_LOS_FSV_WD_O: RC_LOS_FSV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_LOS_FSV_WD_I: RC_LOS_FSV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


//MBT+6Inf
class B_MBT_01_TUSK_F;
class RC_MBT6_A_Base: B_MBT_01_TUSK_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class Components;
	class EventHandlers;
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetHull;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_MBT6_A: RC_MBT6_A_Base
{
	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {if (local _this) then waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this};";
	};

	displayName="MBT 2+6";
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;
	forceHideDriver=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	incomingMissileDetectionSystem=16;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=360;
					angleRangeVertical=360;

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
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;

					weapons[]=
					{
						"HMG_127_MBT",
						"Laserdesignator_mounted",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"200Rnd_127x99_mag_Tracer_Green",
						"200Rnd_127x99_mag_Tracer_Green",
						"200Rnd_127x99_mag_Tracer_Green",
						"200Rnd_127x99_mag_Tracer_Green",
						"Laserbatteries",
						"SmokeLauncherMag"
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
						initFov=0.31;
						minFov=0.034000002;
						maxFov=0.31;
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={2,3};
					};
					class OpticsIn: Optics_Commander_01
					{
						class Wide: Wide
						{
						};
						class Medium: Medium
						{
						};
						class Narrow: Narrow
						{
						};
					};
					*/
				};
			};

			weapons[]=
			{
				"RC_cannon_120mm",
				"LMG_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"20Rnd_120mm_APFSDS_shells_Tracer_Green",
				"20Rnd_120mm_MP_T_Green",
				"3Rnd_120mm_DLG_cannon_missiles",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"200Rnd_762x51_Belt_Green",
				"SmokeLauncherMag"
			};
		
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=1.0;
					minFov=0.025;
					maxFov=1.0;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_01_w_F.p3d";
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
							range[]={3000,2000,1000,500,250};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
					};
				};
			};
		};
	};

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_MRAWS_HEAT_F
		{
			magazine="MRAWS_HEAT_F";
			count=5;
		};
		class _xx_MRAWS_HE_F
		{
			magazine="MRAWS_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=6;
		};
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_Arid
		{
			weapon="Improved_FOV_Laserdesignator_Arid";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
	class TransportBackpacks
	{
		class _xx_B_Carryall_oli
		{
			backpack="B_Carryall_oli";
			count=1;
		};
		class _xx_B_Carryall_cbr
		{
			backpack="B_Carryall_cbr";
			count=1;
		};
	};
};
class RC_MBT6_A_O: RC_MBT6_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

		class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=6;
		};
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_Arid
		{
			weapon="Improved_FOV_Laserdesignator_Arid";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_MBT6_A_I: RC_MBT6_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=6;
		};
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
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
	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_Woodland
		{
			weapon="Improved_FOV_Laserdesignator_Woodland";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_MBT6_WD_O: RC_MBT6_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=6;
		};
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_Woodland
		{
			weapon="Improved_FOV_Laserdesignator_Woodland";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_MBT6_WD_I: RC_MBT6_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=6;
		};
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_Woodland
		{
			weapon="Improved_FOV_Laserdesignator_Woodland";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};