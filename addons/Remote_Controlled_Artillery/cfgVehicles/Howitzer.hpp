// Non Adjustable Howitzers
// Blufor
class B_MBT_01_arty_F;
class RC_Howitzer_base: B_MBT_01_arty_F
{
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetHull;
	class showAmmobox;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class OpticsIn;
	class Wide;
	class Components;
	scope=0;
	scopeCurator=0;
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_Howitzer_NA_A: RC_Howitzer_base
{
	displayName="RC Howitzer (non adjustable)";
	faction="RemoteControlled_NA_B";
	editorSubcategory="RC_Howitzer_NA_subcat";
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

	crewCrashProtection=0.01;

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
		class showAmmobox: showAmmobox
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetTurret",
		0,
		"showCamonetHull",
		0,
		"showAmmobox",
		0
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			//elevationMode=2;	//has 3 by default, what button to change
			//elevationAnimSourceSpeed = 1.0f;

			maxElev=86;	//allows 200m close (compound defense) use
			/*
			minElev=-5;
			initElev=10;
			maxHorizontalRotSpeed=0.77999997;
			maxVerticalRotSpeed=0.25999999;
			*/
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
				};
			};

			//showAllTargets="2 + 4";

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
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						*/
					};
				};
			};
		};
	};
};
class RC_Howitzer_NA_WD: RC_Howitzer_NA_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_arty_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_scorcher_olive_CO.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		"A3\Armor_F\Data\camonet_NATO_Green_CO.paa"
	};
};

// Opfor
class RC_Howitzer_NA_A_O: RC_Howitzer_NA_A
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Howitzer_NA_WD_O: RC_Howitzer_NA_WD
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;
};

// Independent
class RC_Howitzer_NA_A_I: RC_Howitzer_NA_A
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_Howitzer_NA_WD_I: RC_Howitzer_NA_WD
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;
};

// normal adjustable Howitzers
// Blufor
class RC_Howitzer_A: RC_Howitzer_NA_A
{
	displayName="RC Howitzer";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			weapons[]=
			{
				"RC_155mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_12Rnd_155mm_Mo_HEAB",
				"RC_12Rnd_155mm_Mo_smoke",
				"RC_6Rnd_155mm_Mo_MultiGuided",
				"RC_2Rnd_155mm_Mo_Cluster",
				"RC_8Rnd_155mm_Mo_AT_mine",
				"RC_6Rnd_155mm_Mo_mine",
				"RC_12Rnd_155mm_Mo_Illum"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.17399999;
					minFov=0.01;
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
class RC_Howitzer_WD: RC_Howitzer_NA_WD
{
	displayName="RC Howitzer";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;

			weapons[]=
			{
				"RC_155mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_12Rnd_155mm_Mo_HEAB",
				"RC_12Rnd_155mm_Mo_smoke",
				"RC_6Rnd_155mm_Mo_MultiGuided",
				"RC_2Rnd_155mm_Mo_Cluster",
				"RC_8Rnd_155mm_Mo_AT_mine",
				"RC_6Rnd_155mm_Mo_mine",
				"RC_12Rnd_155mm_Mo_Illum"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.17399999;
					minFov=0.01;
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

// Opfor
class RC_Howitzer_A_O: RC_Howitzer_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Howitzer_WD_O: RC_Howitzer_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};

// Independent
class RC_Howitzer_A_I: RC_Howitzer_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_Howitzer_WD_I: RC_Howitzer_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};



//HEX Camo Howitzers (Opfor)
class O_MBT_02_arty_F;
class RC_Howitzer_base_HEX_O: O_MBT_02_arty_F
{
	class AnimationSources;
	class showCamonetHull;
	class showCamonetTurret;
	class showCamonetCannon;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class OpticsIn;
	class Wide;
	class Components;
	scope=0;
	scopeCurator=0;
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_Howitzer_NA_HEX_A_O: RC_Howitzer_base_HEX_O
{
	displayName="RC Howitzer (non adjustable)";
	faction="RemoteControlled_NA_O";
	editorSubcategory="RC_Howitzer_NA_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=0;
	forceInGarage=1;
	
	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="O_UAV_AI";
	driverForceOptics=1;
	
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	crewCrashProtection=0.01;

	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

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
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showCamonetCannon",
		1,
		"showCamonetTurret",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			maxElev=86;	//allows 200m close (compound defense) use
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
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
							range[]={30000,20000,10000,5000,2500,67000};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
class RC_Howitzer_NA_HEX_WD_O: RC_Howitzer_NA_HEX_A_O
{
	displayName="RC Howitzer (non adjustable)";

	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_MBT_02_arty_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_body_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_scorcher_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_ghex_CO.paa",
		"a3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa"
	};
};
class RC_Howitzer_HEX_A_O: RC_Howitzer_NA_HEX_A_O
{
	faction="RemoteControlled_O";
	displayName="RC Howitzer";
	editorSubcategory="RC_Howitzer_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;

			weapons[]=
			{
				"RC_155mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_12Rnd_155mm_Mo_shells",
				"RC_16Rnd_155mm_Mo_HEAB",
				"RC_16Rnd_155mm_Mo_smoke",
				"RC_2Rnd_155mm_Mo_Cluster",
				"RC_6Rnd_155mm_Mo_MultiGuided",
				"RC_8Rnd_155mm_Mo_AT_mine",
				"RC_6Rnd_155mm_Mo_mine",
				"RC_16Rnd_155mm_Mo_Illum"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.17399999;
					minFov=0.01;
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
class RC_Howitzer_HEX_WD_O: RC_Howitzer_NA_HEX_WD_O
{
	faction="RemoteControlled_O";
	displayName="RC Howitzer";
	editorSubcategory="RC_Howitzer_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;

			weapons[]=
			{
				"RC_155mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_12Rnd_155mm_Mo_shells",
				"RC_12Rnd_155mm_Mo_HEAB",
				"RC_12Rnd_155mm_Mo_smoke",
				"RC_6Rnd_155mm_Mo_MultiGuided",
				"RC_2Rnd_155mm_Mo_Cluster",
				"RC_8Rnd_155mm_Mo_AT_mine",
				"RC_6Rnd_155mm_Mo_mine",
				"RC_12Rnd_155mm_Mo_Illum"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.17399999;
					minFov=0.01;
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



class B_Ship_Gun_01_F;
class RC_Static_Arty_base: B_Ship_Gun_01_F
{
	class Turrets;
	class MainTurret;
	class Components;
	scope=0;
	scopeCurator=0;
	isRCArty=1;
};
class RC_Static_NA_Arty: RC_Static_Arty_base
{
	displayName="RC Static Howitzer (non adjustable)";
	faction="RemoteControlled_NA_B";
	editorSubcategory="RC_Howitzer_NA_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

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
};
class RC_Static_NA_Arty_O: RC_Static_NA_Arty
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Static_NA_Arty_I: RC_Static_NA_Arty
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_Static_Arty: RC_Static_NA_Arty
{
	displayName="RC Static Howitzer";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_ShipCannon_120mm_V4"
			};
			magazines[]=
			{
				"RC_ShipCannon_120mm_HEAB_shells_x12",
				"RC_ShipCannon_120mm_smoke_shells_x12",
				"RC_ShipCannon_120mm_MT_MultiGuided_shells_x6",
				"RC_ShipCannon_120mm_HE_cluster_shells_x2",
				"RC_ShipCannon_120mm_AT_mine_shells_x8",
				"RC_ShipCannon_120mm_mine_shells_x6",
				"RC_ShipCannon_120mm_Illum_shells_x12"
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
							range[]={30000,20000,10000,5000,2500,67000};
							resource="RscCustomInfoSensors";
						};
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						*/
					};
				};
			};
		};
	};
};
class RC_Static_Arty_O: RC_Static_Arty
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Static_Arty_I: RC_Static_Arty
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


//NLOS FSV
class B_AFV_Wheeled_01_up_cannon_F;
class RC_NLOS_FSV_A_Base: B_AFV_Wheeled_01_up_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class Components;
	class EventHandlers;
	/*
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetCannon;
	class showCamonetHull;
	class showSLATHull;
	*/
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
};
class RC_NLOS_FSV_A: RC_NLOS_FSV_A_Base
{
	class EventHandlers: EventHandlers
	{
		init="waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this};";
	};

	displayName="N/LOS FSV";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";
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

	/*
	class AnimationSources: AnimationSources
	{
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
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
				"RC_FSV_120mm_MT_MultiGuided_x6",
				"RC_FSV_120mm_smoke_x12",
				"12Rnd_120mm_APFSDS_shells_Tracer_Green",
				"12Rnd_120mm_MT_T_Green",
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