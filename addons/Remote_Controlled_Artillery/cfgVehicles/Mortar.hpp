class B_Mortar_01_F;
class RC_Mortar_base: B_Mortar_01_F
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
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;
	RCisMortar=1; //for Mortars only, which dont work correctly in manual fire atm without having ACE installed
};
class RC_Mortar: RC_Mortar_base
{
	displayName="RC Mortar 4km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";
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
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=5000;

					class AirTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=5000;
						maxRange=5000;
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
				"RC_8Rnd_82mm_Mo_shells",
				"RC_4Rnd_82mm_Mo_HEAB",
				"RC_5Rnd_82mm_Mo_MultiGuided",
				"RC_15Rnd_82mm_Mo_Smoke_white",
				"RC_6Rnd_82mm_Mo_Flare_white"
			};
			class ViewOptics: ViewOptics
			{
				initFov=0.125;
				minFov=0.0125;
				maxFov=0.89999998;
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
							range[]={4000,2000,1000,500,250};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
						*/
					};
				};
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
class RC_Mortar_Bag_base: B_Mortar_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Mortar_Bag: RC_Mortar_Bag_base
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
		assembleTo="RC_Mortar";
		base="";
	};
};
class RC_Mortar_Bag_O: RC_Mortar_Bag
{
	displayName="RC Mortar [Opf] (non adjustable)";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar [Opf]";
		assembleTo="RC_Mortar_O";
	};
};
class RC_Mortar_Bag_HEX_O: RC_Mortar_Bag_base
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
	displayName="RC Mortar [Ind] (non adjustable)";

	class assembleInfo: assembleInfo
	{
		displayName="RC Mortar [Ind]";
		assembleTo="RC_Mortar_I";
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
	displayName="RC Vehicle Mortar 6km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";

	armor=300;	//200 works
	threat[]={0,0,0};
	cost=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]={};
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
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=7000;

					class AirTarget
					{
						minRange=7000;
						maxRange=7000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=7000;
						maxRange=7000;
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
			minElev=-70;

			weapons[]=
			{
				"RC_vehiclemortar_82mm_V4"
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
							range[]={6000,3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
						*/
					};
				};
			};
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