class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
{
	typeRecognitionDistance=1;
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
	//allowsMarking=1;	//targeting would be great, problem is just it tells name which seems a bit op?
};