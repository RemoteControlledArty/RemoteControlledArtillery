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
/*
class RC_60mm_ULM_Core: Mortar_01_base_F
{
	scope=0;
	scopeCurator=0;

	model="twc_2inch\twc_2inch.p3d";
	artilleryScanner=1;
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			elevationAnimSourceSpeed=10;
			maxHorizontalRotSpeed=4;
			maxVerticalRotSpeed=4;
			magazines[]={};
			gunnerAction="twc_2inch_Gunner";
			gunnerRightHandAnimName="OtocHlaven";
		};
	};
};
*/

class B_Mortar_01_F;
class RC_60mm_ULM_Core: B_Mortar_01_F
{
	scope=0;
	scopeCurator=0;
	class Turrets;
	class MainTurret;
	class Components;
	class ViewOptics;

	/*
	model="twc_2inch\twc_2inch.p3d";
	artilleryScanner=1;
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			elevationAnimSourceSpeed=10;
			maxHorizontalRotSpeed=4;
			maxVerticalRotSpeed=4;
			magazines[]={};
			gunnerAction="twc_2inch_Gunner";
			gunnerRightHandAnimName="OtocHlaven";
		};
	};
	*/
};
/*
class RC_60mm_ULM_Base: RC_60mm_ULM_Core
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			*/
			/*
			initElev=-30;
			maxelev=0;
			minelev=-88;
			turretInfoType="twc_2inch_ui";
			gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
			animationSourceElevation="elevBarrel";
			memoryPointGunnerOptics="AimPoint";
			*/

			/*
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
			*/

			/*
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;

				initFov=0.9;
				minFov=0.0125;
				maxFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0,1};
				
				minMoveX=0;
				maxMoveX=0;
				minMoveY=0;
				maxMoveY=0;
				minMoveZ=0;
				maxMoveZ=0;

				gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
				gunnerOpticsEffect[]={};
			};
			class OpticsIn
			{
				class Wide
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.0125;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					
					minMoveX=0;
					maxMoveX=0;
					minMoveY=0;
					maxMoveY=0;
					minMoveZ=0;
					maxMoveZ=0;

					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			*/
			/*
		};
	};
};
*/


/*
class RC_60mm_ULM_Base: RC_60mm_ULM_Core
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			initElev=-30;
			maxelev=0;
			minelev=-88;
			turretInfoType="twc_2inch_ui";
			gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
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
*/


/*
class RC_60mm_ULM_Base: RC_60mm_ULM_Core
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			initElev=-30;
			maxelev=0;
			minelev=-88;
			turretInfoType="twc_2inch_ui";
			//gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
			animationSourceElevation="elevBarrel";
			memoryPointGunnerOptics="AimPoint";

			//gunnerAction="Mortar_Gunner";
			gunnergetInAction="";
			gunnergetOutAction="";
			elevationMode=1;
			initCamElev=0;
			minCamElev=-35;
			maxCamElev=35;
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
			//turretInfoType="RscWeaponRangeArtillery";
			gunnerForceOptics=0;
			//memoryPointGunnerOptics="eye";
			gunnerOpticsModel="\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
			disableSoundAttenuation=1;
			*/

			/*
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
			*/
			/*
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;

				initFov=0.9;
				minFov=0.0125;
				maxFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0,1};
				*/
				
				//test this
				/*
				minMoveX=0;
				maxMoveX=0;
				minMoveY=0;
				maxMoveY=0;
				minMoveZ=0;
				maxMoveZ=0;
				*/

				/*
				gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
				gunnerOpticsEffect[]={};
			};
			class OpticsIn
			{
				class Wide
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.0125;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					*/

					//test this
					/*
					minMoveX=0;
					maxMoveX=0;
					minMoveY=0;
					maxMoveY=0;
					minMoveZ=0;
					maxMoveZ=0;
					*/

					/*
					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
					gunnerOpticsEffect[]={};
				};
			};
		};
	};
};
*/

/*
class RC_60mm_ULM_Base: RC_60mm_ULM_Core
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			initElev=-30;
			maxelev=0;
			minelev=-88;
			turretInfoType="twc_2inch_ui";
			gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
			animationSourceElevation="elevBarrel";
			memoryPointGunnerOptics="AimPoint";

			/*
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
			*/

			/*
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;

				initFov=0.9;
				minFov=0.0125;
				maxFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0,1};
				
				minMoveX=0;
				maxMoveX=0;
				minMoveY=0;
				maxMoveY=0;
				minMoveZ=0;
				maxMoveZ=0;

				gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
				gunnerOpticsEffect[]={};
			};
			class OpticsIn
			{
				class Wide
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.0125;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					
					minMoveX=0;
					maxMoveX=0;
					minMoveY=0;
					maxMoveY=0;
					minMoveZ=0;
					maxMoveZ=0;

					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
					gunnerOpticsEffect[]={};
				};
			};
		};
	};
};
*/

class RC_Mortar;
class RC_60mm_ULM_Vic: RC_Mortar
{
	displayName="60mm advanced Mortar";
	scope=2;
	scopeCurator=2;
};

/*
class RC_60mm_ULM_Vic: RC_60mm_ULM_Core
{
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=0;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=1.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;

	displayName="60mm advanced Mortar";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	//driverForceOptics=1;

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
					typeRecognitionDistance=6000;

					class AirTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=6000;
						maxRange=6000;
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
			*/
			/*
			weapons[]=
			{
				"RC_60mm_ULM_weapon"
			};
			*/
			/*
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
							range[]={4000,2000,1000};
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
*/