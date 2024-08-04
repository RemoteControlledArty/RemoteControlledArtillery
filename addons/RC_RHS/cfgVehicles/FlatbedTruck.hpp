// Respawn Trucks
class B_Truck_01_flatbed_F;
class RC_FlatbedTruck_base: B_Truck_01_flatbed_F
{
	class Components;
	class ViewOptics;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_FlatbedTruck: RC_FlatbedTruck_base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};

	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";
	author="Ascent";
	crewCrashProtection=0.01;
	enableGPS=1;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	threat[]={0,0,0};
	cost=0;
	typicalCargo[]=
	{
		""
	};
	smokeLauncherGrenadeCount=8;
	smokeLauncherVelocity=14;
	smokeLauncherOnTurret=0;
	smokeLauncherAngle=120;

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag"
	};

	class ViewOptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=16000;

					class AirTarget
					{
						minRange=16000;
						maxRange=16000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=16000;
						maxRange=16000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
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
					range[]={16000,8000,4000,2000,1000};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="UAVFeedDisplay";

			class Components
			{
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
			count=2;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=2;
		};
	};
	class TransportWeapons
	{
	};
};


class RC_FlatbedTruck_A: RC_FlatbedTruck
{
	displayName="RC 105mm Truck";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="B_UAV_AI";
	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";

	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	//driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
	memoryPointDriverOptics="driverview";
	driverForceOptics=1;
	forceHideDriver=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
};
class RC_FlatbedTruck_A_O: RC_FlatbedTruck_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_O', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};
class RC_FlatbedTruck_A_I: RC_FlatbedTruck_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_I', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};


class RC_FlatbedTruck_WD: RC_FlatbedTruck_A
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\B_T_Truck_01_flatbed_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\a3\Soft_F_Enoch\Truck_01\Data\truck_01_ammo_pacific_co.paa",
		"\a3\Soft_F_Enoch\Truck_01\Data\Truck_01_cargo_pacific_CO.paa"
	};
};
class RC_FlatbedTruck_WD_O: RC_FlatbedTruck_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_O', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};
class RC_FlatbedTruck_WD_I: RC_FlatbedTruck_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_I', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};


class RC_FlatbedTruck_LC_A: RC_FlatbedTruck_A
{
	displayName="RC 105mm Truck LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_LC', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};
class RC_FlatbedTruck_LC_A_O: RC_FlatbedTruck_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_LC_O', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};
class RC_FlatbedTruck_LC_A_I: RC_FlatbedTruck_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_LC_I', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};


class RC_FlatbedTruck_LC_WD: RC_FlatbedTruck_LC_A
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\B_T_Truck_01_flatbed_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\a3\Soft_F_Enoch\Truck_01\Data\truck_01_ammo_pacific_co.paa",
		"\a3\Soft_F_Enoch\Truck_01\Data\Truck_01_cargo_pacific_CO.paa"
	};
};
class RC_FlatbedTruck_LC_WD_O: RC_FlatbedTruck_LC_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_O', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};
class RC_FlatbedTruck_LC_WD_I: RC_FlatbedTruck_LC_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_I', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};


//manned variant, to allow both M119 gunner and AR-3 operator in truck front seats
class RC_FlatbedTruck_manned_A: RC_FlatbedTruck
{
	displayName="105mm Truck";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="";
};
class RC_FlatbedTruck_manned_A_O: RC_FlatbedTruck_manned_A
{
	faction="RemoteControlled_O";
	side=0;

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_O', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};
class RC_FlatbedTruck_manned_A_I: RC_FlatbedTruck_manned_A
{
	faction="RemoteControlled_I";
	side=2;

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_I', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};


class RC_FlatbedTruck_manned_WD: RC_FlatbedTruck_manned_A
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\B_T_Truck_01_flatbed_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\a3\Soft_F_Enoch\Truck_01\Data\truck_01_ammo_pacific_co.paa",
		"\a3\Soft_F_Enoch\Truck_01\Data\Truck_01_cargo_pacific_CO.paa"
	};
};
class RC_FlatbedTruck_manned_WD_O: RC_FlatbedTruck_manned_WD
{
	faction="RemoteControlled_O";
	side=0;
	
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_O', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};
class RC_FlatbedTruck_manned_WD_I: RC_FlatbedTruck_manned_WD
{
	faction="RemoteControlled_I";
	side=2;

	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {_How=(([[0,0,0], (getDir _this), 'RC_M119_I', west] call BIS_fnc_spawnVehicle) select 0); _How attachTo [_this, [0, -2.6, -0.775]]; _How setDir 180;};";
	};
};