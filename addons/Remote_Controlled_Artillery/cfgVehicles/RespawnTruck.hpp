// Respawn Trucks
// Blufor
class B_Truck_01_medical_F;
class RC_RespawnTruck_base: B_Truck_01_medical_F
{
	class Components;
	class ViewOptics;
	//RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	scope=0;
	scopeCurator=0;
	RCEngineOffDelay=1; //1 = give it longer delay to turn off engine, required for slow accelerating vehicles
};
class RC_RespawnTruck_A: RC_RespawnTruck_base
{
	displayName="RC Medical Truck";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Transport_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
	memoryPointDriverOptics="driverview";
	crew="B_UAV_AI";
	driverForceOptics=1;
	forceHideDriver=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;

	class ViewOptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag"	//fix smoke launcher
	};
	smokeLauncherGrenadeCount=8;
	smokeLauncherVelocity=14;
	smokeLauncherOnTurret=0;
	smokeLauncherAngle=120;

	enableGPS=1;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=3000;

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
			};
		};
	};
};
/*
class RC_RespawnTruck_WD: RC_RespawnTruck_A
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
*/

/*
B_T_Truck_01_medical_F
I_Truck_02_medical_F

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
*/