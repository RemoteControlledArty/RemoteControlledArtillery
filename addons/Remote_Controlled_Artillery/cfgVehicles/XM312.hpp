class B_HMG_01_high_F;
class RC_cUAS_Static_HMG_core: B_HMG_01_high_F
{
	class Turrets;
	class MainTurret;
	class assembleInfo;
	class ViewOptics;
	class Components;
	class AnimationSources;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_cUAS_Static_HMG_base: RC_cUAS_Static_HMG_core
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	
	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiDrone_subcat";
	author="Ascent";
	side=1;
	enableGPS=1;
	//armor=30;	//30

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{	
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			turretInfoType="RscOptics_Strider_commander";
			gunnerForceOptics=1;
			maxElev=50;
			thermalMode[]={0};

			weapons[]=
			{
				"RC_HMG_127x99_cUAS"
			};
			magazines[]=
			{
				"RC_100Rnd_127x99_cUAS",
				"RC_100Rnd_127x99_cUAS",
				"RC_100Rnd_127x99_cUAS",
				"RC_100Rnd_127x99_cUAS"
			};

			class OpticsIn
			{
				class ViewOptics: ViewOptics
				{
					gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Optics_Commander_01_F.p3d";	//"\A3\weapons_f\reticle\Optics_Gunner_02_F"
					initFov=0.89999998;
					minFov=0.06;
					maxFov=0.89999998;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					//thermalMode[]={0};
					//memoryPointGunnerOptics="gunnerview";
				};
			};

			class ViewOptics: ViewOptics
			{
				gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Optics_Commander_01_F.p3d";	//"\A3\weapons_f\reticle\Optics_Gunner_02_F"
				initFov=0.89999998;
				minFov=0.06;
				maxFov=0.89999998;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				//thermalMode[]={0};
				//memoryPointGunnerOptics="gunnerview";
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
							range[]={1000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={400};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=1000;

					class AirTarget
					{
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=1;
					angleRangeVertical=1;
					animDirection="maingun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=400;

					class AirTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;

					/*
					angleRangeHorizontal=360;
					angleRangeVertical=178;
					animDirection="";
					aimDown=-90;
					*/

					//groundNoiseDistanceCoef=;
					//maxGroundNoiseDistance=;
					//maxTrackableATL=400; //good or bad?
					minTrackableATL=4;	//whats good?

					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="maingun";
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_source
		{
			source="reload";
			weapon="RC_HMG_127x99_cUAS";
		};
		class muzzle_source_rot
		{
			source="ammorandom";
			weapon="RC_HMG_127x99_cUAS";
		};
		class ReloadAnim
		{
			source="reload";
			weapon="RC_HMG_127x99_cUAS";
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="RC_HMG_127x99_cUAS";
		};
		class Revolving
		{
			source="revolving";
			weapon="RC_HMG_127x99_cUAS";
		};
	};
};
class RC_cUAS_Static_HMG: RC_cUAS_Static_HMG_base
{
	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"

	displayName="RC C-UAS Static 12.7mm";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	uavCameraGunnerPos="gunnerview";
	uavCameraGunnerDir="gunnerview";
	crew="B_UAV_AI";
	//armor=30;	//30

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_cUAS_Static_HMG_Bag"
		};
	};
};
class RC_cUAS_Static_HMG_O: RC_cUAS_Static_HMG
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	armor=15;
};
class RC_cUAS_Static_HMG_I: RC_cUAS_Static_HMG
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	armor=15;
};


class RC_cUAS_Static_HMG_Bag: RC_Mortar_Bag
{
	displayName="RC C-UAS Static 12.7mm";
	mass=400;	//~27kg

	/*
	picture="\a3\Supplies_F_Enoch\Bags\Data\UI\icon_B_Carryall_green_F_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Supplies_F_Enoch\bags\data\backpack_tortila_RUkhk_co.paa"
	};
	*/

	class assembleInfo: assembleInfo
	{
		displayName="RC C-UAS Static 12.7mm";
		assembleTo="RC_cUAS_Static_HMG";
		base="";
	};
};
class RC_cUAS_Static_HMG_Bag_O: RC_cUAS_Static_HMG_Bag
{
	displayName="RC C-UAS Static 12.7mm [Opf]";

	class assembleInfo: assembleInfo
	{
		displayName="RC C-UAS Static 12.7mm [Opf]";
		assembleTo="RC_cUAS_Static_HMG_O";
	};
};	
class RC_cUAS_Static_HMG_Bag_I: RC_cUAS_Static_HMG_Bag
{
	displayName="RC C-UAS Static 12.7mm [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC C-UAS Static 12.7mm [Ind]";
		assembleTo="RC_cUAS_Static_HMG_I";
	};
};


class RC_cUAS_Static_HMG_manned: RC_cUAS_Static_HMG_base
{
	displayName="C-UAS Static 12.7mm";
	isUav=1;
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	//armor=30;	//30

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=1;
		};
	};
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_cUAS_Static_HMG_Bag"
		};
	};
};
class RC_cUAS_Static_HMG_manned_O: RC_cUAS_Static_HMG_manned
{
	faction="RemoteControlled_O";
	side=0;

	armor=15;
};
class RC_cUAS_Static_HMG_manned_I: RC_cUAS_Static_HMG_manned
{
	faction="RemoteControlled_I";
	side=2;

	armor=15;
};


class RC_cUAS_Static_HMG_manned_Bag: RC_cUAS_Static_HMG_Bag
{
	displayName="C-UAS Static 12.7mm";

	class assembleInfo: assembleInfo
	{
		displayName="C-UAS Static 12.7mm";
		assembleTo="RC_cUAS_Static_HMG_manned";
	};
};
class RC_cUAS_Static_HMG_manned_Bag_O: RC_cUAS_Static_HMG_manned_Bag
{
	displayName="C-UAS Static 12.7mm [Opf]";

	class assembleInfo: assembleInfo
	{
		displayName="C-UAS Static 12.7mm [Opf]";
		assembleTo="RC_cUAS_Static_HMG_manned_O";
	};
};
class RC_cUAS_Static_HMG_manned_Bag_I: RC_cUAS_Static_HMG_manned_Bag
{
	displayName="C-UAS Static [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="C-UAS Static 12.7mm [Ind]";
		assembleTo="RC_cUAS_Static_HMG_manned_I";
	};
};