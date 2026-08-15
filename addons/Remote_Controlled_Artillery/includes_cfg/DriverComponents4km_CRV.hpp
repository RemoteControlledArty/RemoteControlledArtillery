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
			class VisualSensorComponent: SensorTemplateVisual
			{
				typeRecognitionDistance=600;

				class AirTarget
				{
					minRange=600;
					maxRange=600;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=600;
					maxRange=600;
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				maxTrackableSpeed=600;
				nightRangeCoef=0.80000001;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="obsGun";
			};

			#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
		};
	};

	class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
	{
		defaultDisplay="MineDetectorDisplay";

		class Components
		{
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=60;
				resource="RscCustomInfoMineDetect";
			};
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={4000,2000,1000,400};
				resource="RscCustomInfoSensors";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
		};
	};
	class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
	{
		defaultDisplay="SensorDisplay";

		class Components
		{
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={4000,2000,1000,400};
				resource="RscCustomInfoSensors";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
		};
	};
};