class MainTurret: MainTurret
{
	class Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};

	dontCreateAI=1;
	gunnerCompartments="Compartment1";	//3
	showAllTargets="2 + 4";
	canUseScanners=1;
	allowTabLock=1;
	stabilizedInAxes=3;
	canEject=1;	//0

	minElev=-45;
	maxElev=45;
	minTurn=-130;
	maxTurn=130;

	class OpticsIn: OpticsIn
	{
		class Wide: Wide
		{
			initFov=1;	//0.9
			minFov=0.02;
			maxFov=1;	//0.9
			visionMode[]=
			{
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[]={0};
			directionStabilized=1;
			horizontallyStabilized=1;
		};
	};
};