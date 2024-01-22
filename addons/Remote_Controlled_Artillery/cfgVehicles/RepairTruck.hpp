// Repair Trucks
//B_APC_Tracked_01_CRV_F

class B_Truck_01_Repair_F;
class RC_RepairTruck_base: B_Truck_01_Repair_F
{
	class Components;
	class ViewOptics;
	//RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	scope=0;
	scopeCurator=0;
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_RepairTruck_A: RC_RepairTruck_base
{
	class EventHandlers: EventHandlers
	{
		init="insert repair script, as due to ace it doesnt work by default";
	};

	displayName="RC Repair Truck";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Repair_subcat";
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
	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	//driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
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

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=5;
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
class RC_RepairTruck_A_O: RC_RepairTruck_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_RepairTruck_A_I: RC_RepairTruck_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=2;
};


class RC_RepairTruck_WD: RC_RepairTruck_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Truck_01_Repair_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\A3\Soft_F_Exp\Truck_01\Data\truck_01_ammo_olive_CO.paa",
		"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
	};
};
class RC_RepairTruck_WD_O: RC_RepairTruck_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_RepairTruck_WD_I: RC_RepairTruck_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=2;
};