class B_UGV_01_F;
class RC_FPV_Carrier_Core: B_UGV_01_F
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
class RC_FPV_Carrier_Base: RC_FPV_Carrier_Core
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
					range[]={4000,2000,1000,400};
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
					range[]={400,1000,2000,4000};
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
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=8000;

					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
			};
		};
	};
};

class RC_FPV_Carrier: RC_FPV_Carrier_Base
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

	displayName="6xFPV Carrier";
	editorSubcategory="RC_UAV_Designator_subcat";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_FPV_Carrier_O: RC_FPV_Carrier
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_FPV_Carrier_I: RC_FPV_Carrier
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};