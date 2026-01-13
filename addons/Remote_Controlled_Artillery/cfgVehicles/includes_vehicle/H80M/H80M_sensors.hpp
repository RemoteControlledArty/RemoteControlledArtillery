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
				minRange=5000;
				maxRange=5000;
				objectDistanceLimitCoef=-1;
				viewDistanceLimitCoef=-1;
			};
			class GroundTarget
			{
				minRange=5000;
				maxRange=5000;
				objectDistanceLimitCoef=-1;
				viewDistanceLimitCoef=-1;
			};
		};
		class DataLinkSensorComponent: SensorTemplateDataLink
		{
			typeRecognitionDistance=16000;

			class AirTarget
			{
				minRange=16000;
				maxRange=16000;
				objectDistanceLimitCoef=-1;
				viewDistanceLimitCoef=-1;
			};
			class GroundTarget
			{
				minRange=16000;
				maxRange=16000;
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
				minRange=16000;
				maxRange=16000;
				objectDistanceLimitCoef=-1;
				viewDistanceLimitCoef=-1;
			};
			class GroundTarget
			{
				minRange=16000;
				maxRange=16000;
				objectDistanceLimitCoef=-1;
				viewDistanceLimitCoef=-1;
			};
			*/
		};

		//#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
	};
};