class B_Mortar_01_F;
class RC_Mortar_NA_base: B_Mortar_01_F
{
	class Turrets;
	class MainTurret;
	class assembleInfo;
	class ViewOptics;
	class Components;
	class EventHandlers;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	scope=0;
	scopeCurator=0;

	RC_BarrelAGL=0;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=1.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
};
class RC_Mortar_NA: RC_Mortar_NA_base
{
	displayName="RC Mortar (non adjustable)";
	faction="RemoteControlled_NA_B";
	editorSubcategory="RC_Mortar_NA_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
	crew="B_UAV_AI";
	driverForceOptics=1;

	enableGPS=1;
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
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag_NA"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;

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
							range[]={4000,2000,1000,500,250};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
class RC_Mortar_NA_O: RC_Mortar_NA
{
	faction="RemoteControlled_NA_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag_NA_O"
		};
	};
};
class RC_Mortar_NA_HEX_O: RC_Mortar_NA_O
{
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag_NA_HEX_O"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_Mortar_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\Static_f\Mortar_01\data\Mortar_01_OPFOR_CO.paa"
	};
};
class RC_Mortar_NA_I: RC_Mortar_NA
{
	faction="RemoteControlled_NA_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag_NA_I"
		};
	};
};
class RC_Mortar: RC_Mortar_NA
{
	displayName="RC Mortar 4km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;

			weapons[]=
			{
				"RC_mortar_82mm_V3"
			};
			magazines[]=
			{
				"RC_12Rnd_82mm_Mo_HEAB",
				"RC_12Rnd_82mm_Mo_Smoke_white",
				"RC_6Rnd_82mm_Mo_MultiGuided",
				"RC_8Rnd_82mm_Mo_AT_mine",
				"RC_6Rnd_82mm_Mo_mine",
				"RC_12Rnd_82mm_Mo_Flare_white"
			};
			class ViewOptics: ViewOptics
			{
				initFov=0.125;
				minFov=0.0125;
				maxFov=0.89999998;
			};
		};
	};
};
class RC_Mortar_O: RC_Mortar
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag_O"
		};
	};
};
class RC_Mortar_HEX_O: RC_Mortar_O
{
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag_HEX_O"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_Mortar_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\Static_f\Mortar_01\data\Mortar_01_OPFOR_CO.paa"
	};
};
class RC_Mortar_I: RC_Mortar
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_Bag_I"
		};
	};
};



class B_Mortar_01_weapon_F;
class RC_Mortar_Bag_NA_base: B_Mortar_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Mortar_Bag_NA: RC_Mortar_Bag_NA_base
{
	displayName="RC Mortar (non adjustable)";
	scope=2;
	scopeCurator=2;

	mass=540;

	model="\A3\Weapons_F\Ammoboxes\Bags\Backpack_Tortila.p3d";
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_cbr.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_cbr_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar";
		assembleTo="RC_Mortar_NA";
		base="";
	};
};
class RC_Mortar_Bag_NA_O: RC_Mortar_Bag_NA
{
	displayName="RC Mortar [Opf] (non adjustable)";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar [Opf]";
		assembleTo="RC_Mortar_NA_O";
	};
};
class RC_Mortar_Bag_NA_HEX_O: RC_Mortar_Bag_NA_base
{
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_hex_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Mortar_NA_HEX_O";
	};
};	
class RC_Mortar_Bag_NA_I: RC_Mortar_Bag_NA
{
	displayName="RC Mortar [Ind] (non adjustable)";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar [Ind]";
		assembleTo="RC_Mortar_NA_I";
	};
};
class RC_Mortar_Bag: RC_Mortar_Bag_NA
{
	displayName="RC Mortar 4km";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar 4km";
		assembleTo="RC_Mortar";
	};
};
class RC_Mortar_Bag_O: RC_Mortar_Bag
{
	displayName="RC Mortar 4km [Opf]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar 4km [Opf]";
		assembleTo="RC_Mortar_O";
	};
};
class RC_Mortar_Bag_HEX_O: RC_Mortar_Bag_O
{
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_hex_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Mortar_HEX_O";
	};
};	
class RC_Mortar_Bag_I: RC_Mortar_Bag
{
	displayName="RC Mortar 4km [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar 4km [Ind]";
		assembleTo="RC_Mortar_I";
	};
};



class RC_Mortar_ER: RC_Mortar
{
	displayName="RC Mortar 8km";
	
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_ER_Bag"
		};
	};

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
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=8000;

					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
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
			weapons[]=
			{
				"RC_mortar_82mm_V4"
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
							range[]={8000,4000,2000,1000,500,250};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
class RC_Mortar_ER_O: RC_Mortar_ER
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_ER_Bag_O"
		};
	};
};
class RC_Mortar_ER_HEX_O: RC_Mortar_ER_O
{
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_ER_Bag_HEX_O"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_Mortar_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\Static_f\Mortar_01\data\Mortar_01_OPFOR_CO.paa"
	};
};
class RC_Mortar_ER_I: RC_Mortar_ER
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Mortar_ER_Bag_I"
		};
	};
};



class RC_Mortar_ER_Bag: RC_Mortar_Bag
{
	displayName="RC Mortar 8km";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar 8km";
		assembleTo="RC_Mortar_ER";
	};
};
class RC_Mortar_ER_Bag_O: RC_Mortar_ER_Bag
{
	displayName="RC Mortar 8km [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar 8km [Opf]";
		assembleTo="RC_Mortar_ER_O";
	};
};
class RC_Mortar_ER_Bag_HEX_O: RC_Mortar_ER_Bag_O
{
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_hex.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_hex_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Mortar_ER_HEX_O";
	};
};	
class RC_Mortar_ER_Bag_I: RC_Mortar_ER_Bag
{
	displayName="RC Mortar 8km [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar 8km [Ind]";
		assembleTo="RC_Mortar_ER_I";
	};
};


//vehicle attached mortar, allowing for low trajectory, shortening TOF
class RC_VehicleMortar: RC_Mortar
{
	/*
	class EventHandlers: EventHandlers
	{
		init="insert script for mortar leg hiding";
	};
	*/
	displayName="RC Vehicle Mortar 4km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";

	armor=1000;	//30
	threat[]={0,0,0};
	cost=0;	//200000

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]={};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			minElev=-70;
		};
	};
};
class RC_VehicleMortar_O: RC_VehicleMortar
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_VehicleMortar_HEX_O: RC_VehicleMortar_O
{
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_Mortar_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\Static_f\Mortar_01\data\Mortar_01_OPFOR_CO.paa"
	};
};
class RC_VehicleMortar_I: RC_VehicleMortar
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};