class Viewoptics: ViewOptics
{
	initFov=2;	//1.75
	maxFov=2;	//1.75
	minFov=0.125;

	initAngleX=0;
	minAngleX=0;
	maxAngleX=0;
	initAngleY=0;
	minAngleY=0;
	maxAngleY=0;

	/*
	//cannot be changed?
	minElev=0;
	maxElev=0;
	initElev=0;
	*/

	visionMode[]=
	{
		"Normal",
		"NVG",
		"Ti"
	};
	thermalMode[]={0};
};