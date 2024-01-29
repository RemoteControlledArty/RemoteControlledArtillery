// Respawn Trucks
// Blufor
class B_Truck_01_medical_F;
class RC_RespawnTruck_base: B_Truck_01_medical_F
{
	class Components;
	class ViewOptics;
	class EventHandlers;
	//RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	scope=0;
	scopeCurator=0;
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_RespawnTruck_A: RC_RespawnTruck_base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [west, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};

	displayName="RC Medical Truck";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Respawn_subcat";
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

	threat[]={0,0,0};
	cost=0;

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
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=10;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=10;
		};
	};
	class TransportWeapons
	{
	};
};
class RC_RespawnTruck_A_O: RC_RespawnTruck_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [east, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};
class RC_RespawnTruck_A_I: RC_RespawnTruck_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [resistance, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};


class RC_RespawnTruck_WD: RC_RespawnTruck_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Truck_01_medical_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_cargo_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_cover_olive_co.paa"
	};
};
class RC_RespawnTruck_WD_O: RC_RespawnTruck_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [east, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};
class RC_RespawnTruck_WD_I: RC_RespawnTruck_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [resistance, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};


class I_Truck_02_medical_F;
class RC_RespawnTransporter_Base: I_Truck_02_medical_F
{
	class Components;
	class ViewOptics;
	class EventHandlers;
	//RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	scope=0;
	scopeCurator=0;
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_RespawnTransporter_DIG: RC_RespawnTransporter_base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [west, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};

	displayName="RC Medical Transporter";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Respawn_subcat";
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

	threat[]={0,0,0};
	cost=0;

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
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=10;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=10;
		};
	};
	class TransportWeapons
	{
	};
};
class RC_RespawnTransporter_DIG_O: RC_RespawnTransporter_DIG
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [east, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};
class RC_RespawnTransporter_DIG_I: RC_RespawnTransporter_DIG
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [resistance, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};


class RC_RespawnTransporter_WD: RC_RespawnTransporter_DIG
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_Truck_02_Medical_F.jpg";
	textureList[]=
	{
		"EAF",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_kab_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_kuz_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_int_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\truck_02_chassis_EAF_CO.paa"
	};
};
class RC_RespawnTransporter_WD_O: RC_RespawnTransporter_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [east, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};
class RC_RespawnTransporter_WD_I: RC_RespawnTransporter_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [resistance, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};


class RC_RespawnTransporter_HEX_O: RC_RespawnTransporter_DIG
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [east, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_Truck_02_medical_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\soft_f_beta\Truck_02\Data\Truck_02_kab_OPFOR_co.paa",
		"\A3\soft_f_beta\Truck_02\Data\Truck_02_kuz_OPFOR_co.paa",
		"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa"
	};
};


class I_E_Van_02_medevac_F;
class RC_RespawnVan_WD_Base: I_E_Van_02_medevac_F
{
	class Components;
	class ViewOptics;
	class EventHandlers;
	//RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	scope=0;
	scopeCurator=0;
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_RespawnVan_WD: RC_RespawnVan_WD_Base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [west, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};

	displayName="RC Medical Van";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Respawn_subcat";
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

	threat[]={0,0,0};
	cost=0;

	//extCameraPosition[]={0,2,-7};
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
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=10;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=10;
		};
	};
	class TransportWeapons
	{
	};
};
class RC_RespawnVan_WD_O: RC_RespawnVan_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [east, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};
class RC_RespawnVan_WD_I: RC_RespawnVan_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; [resistance, (_this select 0)] call BIS_fnc_addRespawnPosition;";
	};
};