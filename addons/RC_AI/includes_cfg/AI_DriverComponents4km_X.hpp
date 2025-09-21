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
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				maxTrackableSpeed=600;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="obsGun";
			};
			class ManSensorComponent: SensorTemplateMan
			{
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
				maxTrackableSpeed=15;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="obsGun";
			};
			class VisualSensorComponent: SensorTemplateVisual
			{
				typeRecognitionDistance=200;

				class AirTarget
				{
					minRange=200;
					maxRange=200;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=200;
					maxRange=200;
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				maxTrackableSpeed=600;
				nightRangeCoef=0.80000001;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="obsGun";
			};
			class ActiveRadarSensorComponent: SensorTemplateActiveRadar
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
				angleRangeHorizontal=360;
				angleRangeVertical=180;
				aimDown=0;
				groundNoiseDistanceCoef=0;
				maxGroundNoiseDistance=0;
				maxTrackableSpeed=694.44397;
				animDirection="obsGun";
			};
			class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
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
				//allowsMarking=1;
				animDirection="obsGun";
			};
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
				range[]={4000,2000,400};
				resource="RscCustomInfoSensors";
			};
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
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
	class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
	{
		defaultDisplay="EmptyDisplayComponent";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={400,2000,4000};
				resource="RscCustomInfoSensors";
			};
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
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