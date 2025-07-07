class LandVehicle;
class StaticWeapon: LandVehicle
{
	class Components;
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
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: ViewOptics
			{
			};
		};
	};
};
class twc_2inch_vehicle: Mortar_01_base_F
{
	displayname="60mm COMMANDO Mortar";
	author="LeoVetta";
	model="twc_2inch\twc_2inch.p3d";
	artilleryScanner=1;
	scope=2;
	side=1;
	faction="BLU_F";
	crew="B_Soldier_F";
	availableForSupportTypes[]=
	{
		"Artillery"
	};
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Mortar_01_F.jpg";
	class assembleInfo
	{
		assembleTo="";
		base="";
		displayName="";
		dissasembleTo[]={};
		primary=0;
	};

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=0;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=0.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;

	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
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


	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			initElev=-30;
			maxelev=0;
			minelev=-88;
			elevationAnimSourceSpeed=10;
			maxHorizontalRotSpeed=4;
			maxVerticalRotSpeed=4;
			//turretInfoType="twc_2inch_ui";

			weapons[]=
			{
				"RC_60mm_ULM_weapon"
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
							range[]={3000,1500,750};
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
						//class VehicleMissileDisplay
						//{
						//	componentType="TransportFeedDisplayComponent";
						//	source="Missile";
						//	resource="RscTransportCameraComponentMissile";
						//};
					};
				};
			};

			magazines[]={};
			gunnerAction="twc_2inch_Gunner";
			gunnerRightHandAnimName="OtocHlaven";
			gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
			turretInfoType="twc_2inch_ui";
			animationSourceElevation="elevBarrel";
			memoryPointGunnerOptics="AimPoint";
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=0;
				maxAngleY=45;
				initFov=0.69999999;
				minFov=0.69999999;
				maxFov=0.69999999;
				visionMode[]=
				{
					"Normal"
				};
			};
		};
	};
};


class RC_60mm_ULM_Core: twc_2inch_vehicle
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=0;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=0.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;
};
class RC_60mm_ULM_Vic: RC_60mm_ULM_Core
{
	displayName="advanced 60mm Mortar";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	//driverForceOptics=1;

	/*
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
	driverForceOptics=1;
	*/

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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			initElev=-30;
			maxelev=0;
			minelev=-88;
			elevationAnimSourceSpeed=10;
			maxHorizontalRotSpeed=4;
			maxVerticalRotSpeed=4;
			//turretInfoType="twc_2inch_ui";

			weapons[]=
			{
				"RC_60mm_ULM_weapon"
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
							range[]={3000,1500,750};
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
						//class VehicleMissileDisplay
						//{
						//	componentType="TransportFeedDisplayComponent";
						//	source="Missile";
						//	resource="RscTransportCameraComponentMissile";
						//};
					};
				};
			};
		};
	};
};