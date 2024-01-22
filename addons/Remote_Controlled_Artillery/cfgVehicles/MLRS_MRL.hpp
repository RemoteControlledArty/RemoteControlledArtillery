// MLRS
class B_MBT_01_mlrs_F;
class RC_MLRS_base: B_MBT_01_mlrs_F
{
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetHull;
	class Turrets;
	class MainTurret;
	class OpticsIn;
	class Wide;
	class Components;
	scope=0;
	scopeCurator=0;
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0]
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles

	RC_BarrelAGL=1.75;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=3.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
};
class RC_MLRS_NA_A: RC_MLRS_base
{
	displayName="RC MLRS (non adjustable)";
	faction="RemoteControlled_NA_B";
	editorSubcategory="RC_Rocket_NA_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";	
	crew="B_UAV_AI";
	driverForceOptics=1;

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
	animationList[]=
	{
		"showCamonetTurret",
		0,
		"showCamonetHull",
		0
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			stabilizedInAxes=3;

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
							range[]={30000,20000,10000,5000,2500,67000};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
	};
};
class RC_MLRS_NA_WD: RC_MLRS_NA_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_mlrs_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_MLRS_olive_co.paa",
		"A3\Armor_F\Data\camonet_NATO_Green_CO.paa"
	};
};
class RC_MLRS_NA_A_O: RC_MLRS_NA_A
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_MLRS_NA_WD_O: RC_MLRS_NA_WD
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_MLRS_NA_A_I: RC_MLRS_NA_A
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_MLRS_NA_WD_I: RC_MLRS_NA_WD
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_MLRS_A: RC_MLRS_NA_A
{
	displayName="RC MLRS";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Rocket_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			stabilizedInAxes=3;
			weapons[]=
			{
				"RC_rockets_230mm_GAT",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_6Rnd_230mm_rockets_HEAB",
				"RC_4Rnd_230mm_rockets_MultiGuided",
				"RC_2Rnd_230mm_rockets_cluster",
				"SmokeLauncherMag"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.125;
					minFov=0.0125;
					maxFov=0.89999998;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
				};
			};
		};
	};
};
class RC_MLRS_WD: RC_MLRS_NA_WD
{
	displayName="RC MLRS";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Rocket_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			stabilizedInAxes=3;
			weapons[]=
			{
				"RC_rockets_230mm_GAT",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_6Rnd_230mm_rockets_HEAB",
				"RC_4Rnd_230mm_rockets_MultiGuided",
				"RC_2Rnd_230mm_rockets_cluster",
				"SmokeLauncherMag"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.125;
					minFov=0.0125;
					maxFov=0.89999998;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
				};
			};
		};
	};
};
class RC_MLRS_A_O: RC_MLRS_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_MLRS_WD_O: RC_MLRS_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_MLRS_WD_I: RC_MLRS_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_MLRS_A_I: RC_MLRS_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};



// MRL
class I_Truck_02_MRL_F;
class RC_MRL_base: I_Truck_02_MRL_F
{
	class AnimationSources;
	class Turrets;
	class MainTurret;
	class OpticsIn;
	class Wide;
	class Components;

	scope=0;
	scopeCurator=0;
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0]
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles

	RC_BarrelAGL=1.65;
	RC_BarrelLenght=3.5;
};
class RC_MRL_NA_DIG: RC_MRL_base
{
	displayName="RC MRL (non adjustable)";
	faction="RemoteControlled_NA_B";
	editorSubcategory="RC_Rocket_NA_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;

	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	enableGPS=1;
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			lockWhenVehicleSpeed=-1;
			gunnerForceOptics=1;
			stabilizedInAxes=3;

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
							range[]={30000,20000,10000,5000,2500,67000};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
	};
};
class RC_MRL_NA_WD: RC_MRL_NA_DIG
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_Truck_02_MRL_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_kab_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_int_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_mrl_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\truck_02_chassis_EAF_CO.paa"
	};
};
class RC_MRL_NA_WD_O: RC_MRL_NA_WD
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_MRL_NA_HEX_O: RC_MRL_NA_DIG
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;

	hiddenSelectionsTextures[]=
	{
		"\A3\soft_f_beta\Truck_02\Data\Truck_02_kab_opfor_co.paa",
		"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"\a3\soft_f_gamma\truck_02\data\truck_02_mrl_OPFOR_co.paa"
	};
};
class RC_MRL_NA_DIG_I: RC_MRL_NA_DIG
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_MRL_NA_WD_I: RC_MRL_NA_WD
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_MRL_DIG: RC_MRL_NA_DIG
{
	displayName="RC MRL";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Rocket_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			lockWhenVehicleSpeed=-1;

			weapons[]=
			{
				"RC_rockets_230mm_GAT"
			};
			magazines[]=
			{
				"RC_6Rnd_230mm_rockets_HEAB",
				"RC_4Rnd_230mm_rockets_MultiGuided",
				"RC_2Rnd_230mm_rockets_cluster"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.125;
					minFov=0.0125;
					maxFov=0.89999998;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
				};
			};
		};
	};
};
class RC_MRL_WD: RC_MRL_NA_WD
{
	displayName="RC MRL";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Rocket_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			lockWhenVehicleSpeed=-1;

			weapons[]=
			{
				"RC_rockets_230mm_GAT"
			};
			magazines[]=
			{
				"RC_6Rnd_230mm_rockets_HEAB",
				"RC_4Rnd_230mm_rockets_MultiGuided",
				"RC_2Rnd_230mm_rockets_cluster"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.125;
					minFov=0.0125;
					maxFov=0.89999998;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
				};
			};
		};
	};
};
class RC_MRL_WD_O: RC_MRL_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_MRL_HEX_O: RC_MRL_DIG
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	hiddenSelectionsTextures[]=
	{
		"\A3\soft_f_beta\Truck_02\Data\Truck_02_kab_opfor_co.paa",
		"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"\a3\soft_f_gamma\truck_02\data\truck_02_mrl_OPFOR_co.paa"
	};
};
class RC_MRL_DIG_I: RC_MRL_DIG
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_MRL_WD_I: RC_MRL_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
