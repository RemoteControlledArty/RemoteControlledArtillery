class NDS_M224_mortar_base;
class NDS_M224_mortar_core: NDS_M224_mortar_base
{
	class Turrets;
	class MainTurret;
	class ViewOptics;

	class SimpleObject
	{
		animate[]=
		{
			
			{
				"foldweapon",
				0
			}
		};
		hide[]={};
		verticalOffset=0;
	};
	editorPreview="NDS_M224_mortar\cannon\data\ui\NDS_M224_eden.jpg";
	_generalMacro="NDS_M224_mortar";
	scope=0;
	scopecurator=0;
	side=1;
	displayname="M224 60mm Mortar";
	editorSubcategory="EdSubcat_Turrets";
	faction="BLU_F";
	crew="B_Soldier_F";
	availableForSupportTypes[]=
	{
		"Artillery"
	};
	hiddenSelectionsTextures[]=
	{
		"NDS_M224_mortar\cannon\data\NDS_M224_co.paa"
	};
};
class NDS_M224_mortar: NDS_M224_mortar_core
{
	/*
	class EventHandlers: EventHandlers
	{
		class RC_GuidedTriggerTime
		{
			#include "\Remote_Controlled_Artillery\includes_script\GuidedTriggerTimeEH.hpp"
		};
	};
	*/

	isULM=1; // 1 = display UI
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=0;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=1;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;

	displayName="60mm advanced Mortar [long]";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";
	author="Ascent";
	scope=1;
	scopeCurator=1;
	scopeArsenal=1;
	//driverForceOptics=1;

	enableGPS=1;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	class Components
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
			weapons[]=
			{
				"RC_60mm_ULM_weapon"
			};
			magazines[]=
			{
				"RC_ULM_1Rnd_60mm_Mo_shells",
				"RC_ULM_1Rnd_60mm_Mo_HEAB",
				"RC_ULM_1Rnd_60mm_Mo_backupHEAB",
				"RC_ULM_1Rnd_60mm_Mo_Smoke",

				"RC_ULM_1Rnd_60mm_Mo_MultiGuided",
				"RC_ULM_1Rnd_60mm_Mo_LaserGuided",
				"RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse",
				
				"RC_ULM_1Rnd_60mm_Mo_mine",
				"RC_ULM_1Rnd_60mm_Mo_Illum"
			};
			/*
			weapons[]=
			{
				"NDS_W_M224_mortar"
			};
			magazines[]=
			{
				"NDS_M_6Rnd_60mm_HE",
				"NDS_M_6Rnd_60mm_HE",
				"NDS_M_6Rnd_60mm_HE_0",
				"NDS_M_6Rnd_60mm_HE_0",
				"NDS_M_6Rnd_60mm_SMOKE",
				"NDS_M_6Rnd_60mm_SMOKE",
				"NDS_M_6Rnd_60mm_ILLUM",
				"NDS_M_6Rnd_60mm_ILLUM"
			};
			*/

			gunnerForceOptics=0;	//1

			minTurn=-45;
			maxTurn=45;
			//minelev=0;
			minelev=-38;
			//maxelev=38;
			maxelev=38;
			stabilizedInAxes=1;
			maxVerticalRotSpeed=1;
			initCamElev=-90;
			minCamElev=-100;
			maxCamElev=65;

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
					"NVG"
				};
				
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
						"NVG"
					};
					
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
					defaultDisplay="UAVFeedDisplay";

					class Components
					{
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
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
		};
	};
};