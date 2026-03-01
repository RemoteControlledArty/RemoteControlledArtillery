//sensorPosition="gunnerView";	// TEST MORE!!!


//unitInfoType="RC_RscOptics_AV_Heli";
//unitInfoTypeRTD="RC_RscOptics_AV_Heli";
driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

class Viewoptics: ViewOptics
{
	initFov=1;
	maxFov=1;
	minFov=0.25;

	initAngleX=0;
	minAngleX=0;
	maxAngleX=0;
	initAngleY=0;
	minAngleY=0;
	maxAngleY=0;

	visionMode[]=
	{
		"Normal",
		"NVG"
	};
	thermalMode[]={0};
};

class pilotCamera
{
	controllable=1;				//can turn camera
	pilotOpticsShowCursor=1;	//?
	stabilizedInAxes=3;

	minTurn=-360;
	maxTurn=360;
	initTurn=0;
	minElev=-45;
	maxElev=45;
	initElev=0;
	maxMouseXRotSpeed=0.25;
	maxMouseYRotSpeed=0.25;

	class OpticsIn
	{
		class Wide
		{
			opticsDisplayName="Cam";

			directionStabilized=1;
			stabilizedInAxes=3;

			minFov=0.02;
			maxFov=1.5;
			initFov=1.5;
			
			initAngleX=0;
			minAngleX=0;
			maxAngleX=0;
			initAngleY=0;
			minAngleY=0;
			maxAngleY=0;

			visionMode[]=
			{
				"Normal",
				"NVG"
			};
			thermalMode[]={0};
			gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
		};
		showMiniMapInOptics=1;			//alterative to cTab to follow path
		showUAVViewpInOptics=1;			//remove for optionally manned version
		showSlingLoadManagerInOptics=1;
	};
};