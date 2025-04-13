class B_GMG_01_high_F;
class RC_cUAS_Turret_base: B_GMG_01_high_F
{
	class Turrets;
	class MainTurret;
	class assembleInfo;
	class OpticsIn;
	class ViewOptics;
	class Components;
	class AnimationSources;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_cUAS_Turret: RC_cUAS_Turret_base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\dev6.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	
	displayName="RC C-UAS Turret";
	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiDrone_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	uavCameraGunnerPos="gunnerview";
	uavCameraGunnerDir="gunnerview";
	crew="B_UAV_AI";
	enableGPS=1;
	//armor=30;	//30

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{	
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerForceOptics=1;
			maxElev=45;
			thermalMode[]={0};

			weapons[]=
			{
				"RC_GMG_20mm_cUAS"
			};
			magazines[]=
			{
				"RC_40Rnd_20mm_HEAB_T_R",
				"RC_40Rnd_20mm_HEAB_T_R",
				"RC_40Rnd_20mm_HEAB_T_R",
				"RC_40Rnd_20mm_cUAS",
				"RC_40Rnd_20mm_cUAS",
				"RC_40Rnd_20mm_cUAS"
			};

			class OpticsIn: OpticsIn
			{
				class ViewOptics: ViewOptics
				{
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
					initFov=0.89999998;
					minFov=0.02;
					maxFov=0.89999998;
					//memoryPointGunnerOptics="gunnerview";
					thermalMode[]={0};
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
					animDirection="";
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_source
		{
			source="reload";
			weapon="RC_GMG_20mm_cUAS";
		};
		class muzzle_source_rot
		{
			source="ammorandom";
			weapon="RC_GMG_20mm_cUAS";
		};
		class ReloadAnim
		{
			source="reload";
			weapon="RC_GMG_20mm_cUAS";
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="RC_GMG_20mm_cUAS";
		};
		class Revolving
		{
			source="revolving";
			weapon="RC_GMG_20mm_cUAS";
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_cUAS_Turret_Bag"
		};
	};
};
class RC_cUAS_Turret_O: RC_cUAS_Turret
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	armor=15;
};
class RC_cUAS_Turret_I: RC_cUAS_Turret
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	armor=15;
};


class RC_cUAS_Turret_Bag: RC_Mortar_Bag
{
	displayName="RC C-UAS Turret";
	mass=440;	//~30kg

	class assembleInfo: assembleInfo
	{
		displayName="RC C-UAS Turret";
		assembleTo="RC_cUAS_Turret";
		base="";
	};
};
class RC_cUAS_Turret_Bag_O: RC_cUAS_Turret_Bag
{
	displayName="RC C-UAS Turret [Opf]";

	class assembleInfo: assembleInfo
	{
		displayName="RC C-UAS Turret [Opf]";
		assembleTo="RC_cUAS_Turret_O";
	};
};	
class RC_cUAS_Turret_Bag_I: RC_cUAS_Turret_Bag
{
	displayName="RC C-UAS Turret [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC C-UAS Turret [Ind]";
		assembleTo="RC_cUAS_Turret_I";
	};
};