class CopilotTurret: CopilotTurret
{
	class Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};

	dontCreateAI=1;
	gunnerCompartments="Compartment1";	//3
	showAllTargets="2 + 4";
	canUseScanners=1;
	canEject=1;	//0
	allowTabLock=1;
};