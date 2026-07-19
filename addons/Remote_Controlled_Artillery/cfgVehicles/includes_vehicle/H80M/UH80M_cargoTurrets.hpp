class MainTurret: MainTurret
{
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	gunnerCompartments="Compartment1";
	weapons[]={"RC_338_DoorMinigun"};
	magazines[]={"RC_2000Rnd_338_SLAP_T_R"};
	gunnerType="RC_B_DoorGunner";
	stabilizedInAxes=3;
	canUseScanner=1;

	class OpticsIn
	{
		class Wide
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
			gunnerOpticsModel="\A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";

			initFov=0.9;
			minFov=0.1;
			maxFov=0.9;
		};
	};
	turretInfoType="RscOptics_Strider_commander";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};
};
class RightDoorGun: RightDoorGun
{
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	gunnerCompartments="Compartment1";
	weapons[]={"RC_338_DoorMinigun2"};
	magazines[]={"RC_2000Rnd_338_SLAP_T_R"};
	gunnerType="RC_B_DoorGunner";
	stabilizedInAxes=3;
	canUseScanner=1;

	class OpticsIn
	{
		class Wide
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
			gunnerOpticsModel="\A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";

			initFov=0.9;
			minFov=0.1;
			maxFov=0.9;
		};
	};
	turretInfoType="RscOptics_Strider_commander";

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};
};