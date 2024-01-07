//AR-4
class B_UAV_01_F;
class RC_UAV_base: B_UAV_01_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class ViewPilot;
	class assembleInfo;
	class Components;
	scope=0;
	scopeCurator=0;
};
class RC_UAV_AR1: RC_UAV_base
{
	displayName="RC AR-1";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Spotting_subcat";
	scope=2;
	scopeCurator=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag"
		};
	};

	radarTargetSize=0.05;
	visualTargetSize=0.05;

	maxSpeed=200;
	liftForceCoef=2;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	backRotorForceCoef=10;
	fuelCapacity=200;
	mainRotorSpeed=-14;
	backRotorSpeed=14;

	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	class Components: Components
	{
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={1000,500,250,2000};
					resource="RscCustomInfoSensors";
				};
			};
		};
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
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
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
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};

					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=750;

					class AirTarget
					{
						minRange=750;
						maxRange=750;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=750;
						maxRange=750;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};

					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
	};

	class ViewPilot: ViewPilot
	{
		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.25;
		maxFov=1.25;
		initFov=0.75;
		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0,1};
	};
	class Viewoptics: ViewOptics
	{
		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.25;
		maxFov=1.25;
		initFov=0.75;
		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0,1};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={1000,500,250,2000};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};

			//showAllTargets="2 + 4";

			isCopilot=1; //0
			commanding=2; //-1

			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="W";
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.5;
					minFov=0.01;
					maxFov=1.0;
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				};
			};
			class OpticsOut
			{
				class Monocular	//doesnt work...?
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=1.1;
					minFov=0.01;
					maxFov=1.0;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="";
					gunnerOpticsEffect[]={};
				};
			};
		};
	};
};


//AR-3
class RC_UAV_AR3: RC_UAV_AR1
{
	displayName="RC AR-3";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR3_Bag"
		};
	};

	class Components: Components
	{
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={3000,2000,1000,500,250};
					resource="RscCustomInfoSensors";
				};
			};
		};
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
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1000;

					class AirTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={3000,2000,1000,500,250};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};


class Bag_Base;
class Weapon_Bag_Base: Bag_Base
{
	class assembleInfo;
};
class RC_UAV_AR1_Bag: Weapon_Bag_Base
{
	mapSize=0.60000002;
	_generalMacro="RC_UAV_AR1_Bag_Arid_Base";
	scope=2;
	scopeCurator=2;
	displayName="RC AR-1";
	editorCategory="EdCat_Equipment";
	editorSubcategory="EdSubcat_Backpacks";
	faction="BLU_F";
	picture="\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_rgr";
	model="\A3\weapons_f\Ammoboxes\bags\Backpack_Fast";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_rgr_co.paa"
	};
	maximumLoad=0;
	mass=300;
	class assembleInfo: assembleInfo
	{
		base="";
		displayName="RC AR-1";
		assembleTo="RC_UAV_AR1";
	};
};


class RC_UAV_AR3_Bag: RC_UAV_AR1_Bag
{
	displayName="RC AR-3";

	class assembleInfo: assembleInfo
	{
		base="";
		displayName="RC AR-3";
		assembleTo="RC_UAV_AR3";
	};
};


/*
class O_UAV_01_backpack_F: B_UAV_01_backpack_F
{
	author="$STR_A3_Bohemia_Interactive";
	_generalMacro="O_UAV_01_backpack_F";
	displayName="$STR_A3_CFGVEHICLES_B_UAV_01_BACKPACK_F1";
	faction="OPF_F";
	picture="\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UI\icon_B_C_UAV_cbr_ca";
	hiddenSelectionsTextures[]=
	{
		"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UAV_backpack_cbr_co.paa"
	};
	class assembleInfo: assembleInfo
	{
		assembleTo="O_UAV_01_F";
		displayName="$STR_A3_CFGVEHICLES_O_UAV_01";
	};
};
class I_UAV_01_backpack_F: B_UAV_01_backpack_F
{
	author="$STR_A3_Bohemia_Interactive";
	_generalMacro="I_UAV_01_backpack_F";
	displayName="$STR_A3_CFGVEHICLES_B_UAV_01_BACKPACK_F2";
	faction="IND_F";
	picture="\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UI\icon_B_C_UAV_oli_ca";
	hiddenSelectionsTextures[]=
	{
		"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UAV_backpack_oli_co.paa"
	};
	class assembleInfo: assembleInfo
	{
		assembleTo="I_UAV_01_F";
	};
};
/*