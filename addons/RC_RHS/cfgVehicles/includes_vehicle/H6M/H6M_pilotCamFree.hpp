class pilotCamera
{
	controllable=1;				//can turn camera
	pilotOpticsShowCursor=1;	//?
	stabilizedInAxes=3;

	minTurn=-360;
	maxTurn=360;
	initTurn=0;
	minElev=-40;
	maxElev=90;
	initElev=0;
	maxMouseXRotSpeed=0.25;		//0.5
	maxMouseYRotSpeed=0.25;		//0.5

	//memoryPointGun="commanderview";	//no effect, and would be much harder to fly if helicopter orientation isnt visible
	//magazines[] += {"Laserbatteries"};
	//weapons[] += {"Laserdesignator_pilotCamera"};
	//maxXRotSpeed = 0.5;		//1, unsure if used here, not defined in other pilotCam's or Wiki
	//maxYRotSpeed = 0.5;		//1, unsure if used here, not defined in other pilotCam's or Wiki

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
				"NVG",
				"Ti"
			};
			thermalMode[]={0};
			gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
			//gunnerOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_m.p3d";
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
		};
		showMiniMapInOptics=1;			//alterative to cTab to follow path
		showUAVViewpInOptics=1;			//remove for optionally manned version
		showSlingLoadManagerInOptics=1;
	};
};


/*
class pilotCamera
{
	gunBeg="commanderview";
	gunEnd="laserstart";
	memoryPointGun="commanderview";
	discretedistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
	discretedistanceinitindex=3;
	weapons[]=
	{
		"rhs_weap_laserDesignator_AI",
		"rhs_weap_fcs_ah64"
	};
	magazines[]=
	{
		"rhs_laserfcsmag",
		"rhs_LaserMag_ai"
	};
	minTurn=-1080;
	maxTurn=1080;
	initTurn=0;
	minElev=-35;
	maxElev=90;
	initElev=0;
	maxXRotSpeed=0.5;
	maxYRotSpeed=0.5;
	pilotOpticsShowCursor=1;
	controllable=1;
};
*/