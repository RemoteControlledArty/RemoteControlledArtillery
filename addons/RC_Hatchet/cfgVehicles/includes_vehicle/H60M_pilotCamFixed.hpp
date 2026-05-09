class Viewoptics: ViewOptics
{
	initFov=1.5;	//1.25
	maxFov=1.5;		//1.25
	minFov=0.25;

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
/*
class ViewPilot: ViewPilot
{
	initFov=1.25;
	maxFov=1.25;
	minFov=0.02;

	initAngleX=0;
	minAngleX=-65;
	maxAngleX=85;
	initAngleY=0;
	minAngleY=-150;
	maxAngleY=150;

	visionMode[]=
	{
		"Normal",
		"NVG",
		"Ti"
	};
	thermalMode[]={0};
};
*/