class O_T_UAV_04_CAS_F;
class RC_FPV_Mothership_Core: O_T_UAV_04_CAS_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_FPV_Mothership_Base: RC_FPV_Mothership_Core
{
	/*
	radarTargetSize=0.5;
	visualTargetSize=0.69999999;
	irTargetSize=0.5;

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
	*/

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
					range[]={4000,2000,1000};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={1000,2000,4000};
					resource="RscCustomInfoSensors";
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
					typeRecognitionDistance=3000;
					maxTrackableSpeed=600;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
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
					typeRecognitionDistance=2500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=2500;
						maxRange=2500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2500;
						maxRange=2500;
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="W";
					initAngleX=0;
					minAngleX=-35;
					maxAngleX=85;
					initAngleY=0;
					minAngleY=-130;
					maxAngleY=130;
					initFov=1.0;
					minFov=0.03;
					maxFov=1.0;
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
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
							range[]={4000,2000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={2000,4000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
						};
					};
				};
			};
		};
	};
};

class RC_FPV_Mothership: RC_FPV_Mothership_Base
{
	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"Laserdesignator_mounted",
				"RC_FPV_Deployer"
			};
			magazines[]=
			{
				"Laserbatteries",
				"RC_6xFPV_Deployer_Mag"
			};
		};
	};
	*/

	displayName="6xFPV Mothership";
	editorSubcategory="RC_UAV_Designator_subcat";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_FPV_Mothership_O: RC_FPV_Mothership
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_FPV_Mothership_I: RC_FPV_Mothership
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};