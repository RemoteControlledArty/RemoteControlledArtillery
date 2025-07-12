class LandVehicle;
class StaticWeapon: LandVehicle
{
	class Turrets
	{
		class MainTurret;
	};
};
class StaticMortar: StaticWeapon
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics;
		};
	};
};
class Mortar_01_base_F: StaticMortar
{
	features="Randomization: No						<br />Camo selections: 1 - the whole weapon with pod						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: Just the weapon						<br />Slingload: No						<br />Cargo proxy indexes: None";
	author="$STR_A3_Bohemia_Interactive";
	_generalMacro="Mortar_01_base_F";
	scope=0;
	displayname="$STR_A3_CfgVehicles_Mortar_01_Base0";
	class Library
	{
		libTextDesc="$STR_A3_CfgVehicles_Mortar_01_Base_Library0";
	};
	transportSoldier=0;
	cargoAction[]=
	{
		"Mortar_Gunner"
	};
	getInAction="GetInMortar";
	getOutAction="GetOutLow";
	unitInfoType="RscUnitInfoMortar";
	editorSubcategory="EdSubcat_Turrets";
	picture="\A3\Static_f\Mortar_01\data\UI\Mortar_01_ca.paa";
	icon="\A3\Static_f\Mortar_01\data\UI\map_Mortar_01_CA.paa";
	cost=200000;
	accuracy=0.25;
	EPEImpulseDamageCoef=5;
	class Damage
	{
		tex[]={};
		mat[]=
		{
			"A3\Static_f\Mortar_01\data\Mortar_01.rvmat",
			"A3\Static_f\Mortar_01\data\Mortar_01_damage.rvmat",
			"A3\Static_f\Mortar_01\data\Mortar_01_destruct.rvmat"
		};
	};
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerAction="Mortar_Gunner";
			gunnergetInAction="";
			gunnergetOutAction="";
			weapons[]=
			{
				"mortar_82mm"
			};
			elevationMode=1;
			initCamElev=0;
			minCamElev=-35;
			maxCamElev=35;
			initElev=0;
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			cameraDir="look";
			discreteDistance[]={100,200,300,400,500,700,1000,1600,2000,2400,2800};
			discreteDistanceCameraPoint[]=
			{
				"eye"
			};
			discreteDistanceInitIndex=5;
			turretInfoType="RscWeaponRangeArtillery";
			gunnerForceOptics=0;
			memoryPointGunnerOptics="eye";
			gunnerOpticsModel="\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
			disableSoundAttenuation=1;
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;
				initFov=0.17399999;
				minFov=0.0077777999;
				maxFov=0.14;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
			minelev=-30;
			maxelev=13;
			magazines[]=
			{
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_shells",
				"8Rnd_82mm_Mo_Flare_white",
				"8Rnd_82mm_Mo_Smoke_white"
			};
			ejectDeadGunner=1;
			usepip=2;
		};
	};
	class EventHandlers
	{
		fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
	};
	htMin=1;
	htMax=480;
	afMax=0;
	mfMax=0;
	mFact=1;
	tBody=100;
	class DestructionEffects
	{
		class Smoke
		{
			simulation="particles";
			type="WeaponWreckSmoke";
			position="destructionEffect";
			intensity=1;
			interval=1;
			lifeTime=5;
		};
	};
	model="\A3\static_f\Mortar_01\Mortar_01_F";
	artilleryScanner=1;
	class assembleInfo
	{
		primary=0;
		base="";
		assembleTo="";
		dissasembleTo[]=
		{
			"B_Mortar_01_weapon_F",
			"B_Mortar_01_support_F"
		};
		displayName="";
	};
	hiddenSelections[]=
	{
		"Camo"
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\Static_f\Mortar_01\data\Mortar_01_CO.paa"
	};
};
class B_Mortar_01_F: Mortar_01_base_F
{
	author="$STR_A3_Bohemia_Interactive";
	class SimpleObject
	{
		eden=1;
		animate[]=
		{
			
			{
				"mainturret",
				0
			},
			
			{
				"maingun",
				0
			},
			
			{
				"optics",
				0
			},
			
			{
				"optics_stabilization",
				0
			},
			
			{
				"legs_zeroing",
				0
			},
			
			{
				"uplegs_zeroing",
				0
			}
		};
		hide[]=
		{
			"light_back",
			"brzdove svetlo",
			"clan",
			"podsvit pristroju",
			"poskozeni"
		};
		verticalOffset=0.75700003;
		verticalOffsetWorld=0.035;
		init="''";
	};
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Mortar_01_F.jpg";
	_generalMacro="B_Mortar_01_F";
	scope=2;
	side=1;
	faction="BLU_F";
	crew="B_Soldier_F";
	availableForSupportTypes[]=
	{
		"Artillery"
	};
};



//class B_Mortar_01_F;
class RC_Mortar_base: B_Mortar_01_F
{
	class Turrets;
	class MainTurret;
	class assembleInfo;
	class ViewOptics;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=0;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=1.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;
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
	reportOwnPosition=1;
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
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//maxCamElev=67.5;
			gunnerForceOptics=1;

			weapons[]=
			{
				"RC_mortar_82mm_V3"
			};
			magazines[]=
			{
				"RC_8Rnd_82mm_Mo_shells",
				"RC_3Rnd_82mm_Mo_HEAB",
				"RC_4Rnd_82mm_Mo_MultiGuided",
				"RC_12Rnd_82mm_Mo_Smoke_white",
				"RC_6Rnd_82mm_Mo_Flare_white"
			};
			class ViewOptics: ViewOptics
			{
				/*
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;
				*/
				
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
							range[]={4000,2000,1000,500};
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
	displayName="RC Mortar";
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
	displayName="RC Mortar [Opf]";

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
	displayName="RC Mortar [Ind]";

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
	//didnt found a fitting script yet, as its a single texture
	class EventHandlers: EventHandlers
	{
		init="insert script for mortar leg hiding";
	};
	*/

	RC_ArtyType=2; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	displayName="RC Vehicle Mortar 6km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";

	armor=120;
	threat[]={0,0,0};
	cost=0;
	typicalCargo[]={""};

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
			magazines[]=
			{
				"RC_15Rnd_82mm_vic_Mo_shells",
				"RC_4Rnd_82mm_vic_Mo_HEAB",
				"RC_5Rnd_82mm_vic_Mo_MultiGuided",
				"RC_20Rnd_82mm_vic_Mo_Smoke_white",
				"RC_9Rnd_82mm_vic_Mo_AT_mine",
				"RC_9Rnd_82mm_vic_Mo_mine",
				"RC_6Rnd_82mm_vic_Mo_Flare_white"
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
							range[]={6000,3000,1500,750};
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


class RC_VehicleMortar_LC: RC_VehicleMortar
{
	displayName="RC Vehicle Mortar 6km LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_vehiclemortar_82mm_V4"
			};
			magazines[]=
			{
				"RC_6Rnd_82mm_vic_Mo_shells",
				"RC_3Rnd_82mm_vic_Mo_HEAB",
				"RC_3Rnd_82mm_vic_Mo_MultiGuided",
				"RC_20Rnd_82mm_vic_Mo_Smoke_white",
				"RC_4Rnd_82mm_vic_Mo_AT_mine",
				"RC_4Rnd_82mm_vic_Mo_mine",
				"RC_6Rnd_82mm_vic_Mo_Flare_white"
			};
		};
	};
};
class RC_VehicleMortar_LC_O: RC_VehicleMortar_LC
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_VehicleMortar_LC_I: RC_VehicleMortar_LC
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};