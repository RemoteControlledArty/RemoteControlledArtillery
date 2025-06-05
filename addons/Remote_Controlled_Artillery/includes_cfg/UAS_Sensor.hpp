class VisualSensorComponent: SensorTemplateVisual
{
	typeRecognitionDistance=400;

	class AirTarget
	{
		minRange=400;
		maxRange=400;
		objectDistanceLimitCoef=-1;
		viewDistanceLimitCoef=-1;
	};
	class GroundTarget
	{
		minRange=400;
		maxRange=400;
		objectDistanceLimitCoef=1;
		viewDistanceLimitCoef=1;
	};
	maxTrackableSpeed=600;
	nightRangeCoef=0.80000001;
	angleRangeHorizontal=360;
	angleRangeVertical=360;
	animDirection="mainGun";	//"" , "obsGun"
};