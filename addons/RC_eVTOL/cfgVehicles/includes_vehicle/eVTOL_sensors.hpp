class SensorsManagerComponent
{
	class Components
	{
		class LaserSensorComponent: SensorTemplateLaser
		{
			angleRangeHorizontal=360;	//180
			angleRangeVertical=360;		//180

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
			typeRecognitionDistance=10000;

			class AirTarget
			{
				minRange=10000;
				maxRange=10000;
				objectDistanceLimitCoef=-1;
				viewDistanceLimitCoef=-1;
			};
			class GroundTarget
			{
				minRange=10000;
				maxRange=10000;
				objectDistanceLimitCoef=-1;
				viewDistanceLimitCoef=-1;
			};
		};
		class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
		{
			/*
			typeRecognitionDistance=1;
			//allowsMarking=1;	//targeting would be great, problem is just it tells name which seems a bit op?

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
			*/
		};

		//#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
	};
};