class pilotCamera
{
	//turretInfoType="RscOptics_MBT_03_gunner";
	unitInfoType="RscOptics_AV_pilot";
	unitInfoTypeRTD="RscOptics_AV_pilot";

	class OpticsIn
	{
		class Wide
		{
			opticsDisplayName="W";
			initAngleX=0;
			minAngleX=0;
			maxAngleX=0;
			initAngleY=0;
			minAngleY=0;
			maxAngleY=0;
			minFov=0.025;
			maxFov=1.5;
			initFov=1.5;
			directionStabilized=0;
			//directionStabilized=1;
			visionMode[]=
			{
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[]={0};
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
		};
		showMiniMapInOptics=0;
		showUAVViewpInOptics=0;
		showSlingLoadManagerInOptics=1;
	};
	minTurn=0;
	maxTurn=0;
	initTurn=0;
	minElev=80;
	maxElev=80;
	initElev=80;
	maxXRotSpeed=0.5;
	maxYRotSpeed=0.5;
	pilotOpticsShowCursor=1;
	controllable=0;	//test 1
};