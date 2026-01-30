//allows datalink target cycling for rockets/missiles
class Components
{
	class SensorsManagerComponent
	{
		class Components
		{
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
			class LaserSensorComponent: SensorTemplateLaser
			{
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