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
				typeRecognitionDistance=3000;

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
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				maxTrackableSpeed=600;
				angleRangeHorizontal=1;
				angleRangeVertical=2;
				animDirection="mainGun";
			};
			class ManSensorComponent: SensorTemplateMan
			{
				/*
				typeRecognitionDistance=300;

				class AirTarget
				{
					minRange=300;
					maxRange=300;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=300;
					maxRange=300;
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				*/
				maxTrackableSpeed=15;
				angleRangeHorizontal=22.5;
				angleRangeVertical=22.5;
				animDirection="mainGun";
				aimDown=0;	//-0.5
			};

			#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
		};
	};

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
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
			/*
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			*/
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
				range[]={500,1000,2000,4000};
				resource="RscCustomInfoSensors";
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
			/*
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			*/
		};
	};
};