class RC_Sting_Base: RC_UAV_base
{
	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=2;
	scopeCurator=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag"
		};
	};

	camouflage=0.25;
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
	reportOwnPosition=1;
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
					range[]={3000,1500,750};
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
					animDirection="mainGun";
					aimDown=-0.5;

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
				/*
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				*/
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
				};
			};
		};
	};

	class ViewPilot: ViewPilot
	{
		stabilizedInAxes=3;

		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.075;
		maxFov=1.25;
		initFov=0.75;
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};
	class Viewoptics: ViewOptics
	{
		stabilizedInAxes=3;

		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.075;
		maxFov=1.25;
		initFov=0.75;
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//isCopilot=1; //0		//doesnt work yet
			//commanding=1; //-1	//doesnt work yet

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
							range[]={3000,1500,750};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";
					class components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
						};
					};
				};
			};

			class OpticsIn
			{
				class Wide
				{
					stabilizedInAxes=3;

					opticsDisplayName="W";
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.8;
					minFov=0.05;
					maxFov=1.0;
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				};
			};
			class OpticsOut
			{
				class Monocular	//doesnt work...?
				{
					stabilizedInAxes=3;

					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=1.0;
					minFov=0.05;
					maxFov=1.0;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="";
					gunnerOpticsEffect[]={};
				};
			};
		};
	};
};


//Sting interceptor
class RC_Sting_Base2: RC_Sting_Base
{
	displayName="RC Sting MP";
	RC_UAVBlurRange=8000;	//no blur

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
					range[]={3000,1500,750};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="EmptyDisplay";
			class components
			{
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
				};
			};
		};
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					animDirection="mainGun";
					aimDown=-0.5;

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
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1000;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
				};
				/*
				class ManSensorComponent: SensorTemplateMan
				{
					maxTrackableSpeed=15;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
				*/
			};
		};
	};

	class ViewPilot: ViewPilot
	{
		minFov=0.025;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};
	class Viewoptics: Viewoptics
	{
		minFov=0.025;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

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
							range[]={3000,1500,750};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";
					class components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
						};
					};
				};
			};

			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					minFov=0.025;

					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
				};
			};
			class OpticsOut: OpticsOut
			{
				class Monocular: Monocular
				{
					minFov=0.025;

					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
				};
			};
		};
	};
};


class RC_Sting_B: RC_Sting_Base2
{
	fuelExplosionPower=25;
	stabilizedInAxes=3;

	camouflage=0.1;	//0.5
	audible=0.1;	//0.1
	radarTargetSize=0.035;	//0.1
	visualTargetSize=0.1;	//0.1

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			stabilizedInAxes=3;
			
			maxCamElev=360;
			maxElev=360;
			minElev=-360;
			minCamElev=-360;
		};
	};
};


/*
class RC_UAV_FPV: RC_UAV_base
{
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	displayName="RC FPV 4km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=2;
	scopeCurator=2;
	RC_UAVBlurRange=3000;
	fuelExplosionPower=25;

	maxSpeed=200;
	liftForceCoef=1.5;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	backRotorForceCoef=5;	//10
	fuelCapacity=200;
	mainRotorSpeed=-7;	//14
	backRotorSpeed=7;	//14

	camouflage=0.1;	//0.5
	audible=0.1;	//0.1
	radarTargetSize=0.035;	//0.1
	visualTargetSize=0.1;	//0.1

	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	weapons[]=
	{
		"RC_target_confirmer"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag"
	};

	class ViewPilot: ViewPilot
	{
		//#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
		initFov=1.25;

		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};
	class Viewoptics: ViewOptics
	{
		//#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
		initFov=1.25;

		visionMode[]=
		{
			"Normal",
			"NVG"
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
					range[]={4000,2000,1000,500};
					resource="RscCustomInfoSensors";
				};
			};
		};
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
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//mainGun
					aimDown=0;	//-0.5

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
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.67;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//mainGun
					aimDown=0;	//-0.5

					class AirTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
			};
		};
	};

	//no turret camera
	class Turrets {};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_FPV_Bag"
		};
	};
};
*/