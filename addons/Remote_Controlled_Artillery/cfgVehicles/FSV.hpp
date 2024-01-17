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
					minFov=0.01;
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