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

	minElev=-42.5;
	maxElev=42.5;
	minTurn=-125;
	maxTurn=125;

	class OpticsIn: OpticsIn
	{
		class Wide: Wide
		{
			directionStabilized=1;
			//horizontallyStabilized=1;
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
			gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
		};
	};
};