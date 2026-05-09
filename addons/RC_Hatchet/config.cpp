class CfgPatches
{
	class RC_Hatchet
	{
		name="RC Hatchet";
		author="Ascent";

		units[]=
		{
			"RC_MH60M_DAP_MLASS",
			"RC_MH60M_DAP_MLASS_O",
			"RC_MH60M_DAP_MLASS_I"
		};

		weapons[]=
		{
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"ace_main",
			"vtx_main"
		};

		skipWhenMissingDependencies=1;
	};
};


/*
class CfgFunctions
{
	class RC
	{
		class RC_Hatchet
		{
		};
	};
};
*/


//later required sensors
class SensorTemplateDataLink;
class SensorTemplateLaser;
class SensorTemplateIR;
class SensorTemplateNV;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplatePassiveRadar;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


class CfgAmmo
{
	//#include "\RC_Hatchet\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
	//#include "\RC_Hatchet\cfgAmmoMagazinesWeapons\cfgPylonAmmo.hpp"
};
class CfgMagazines
{
	//#include "\RC_Hatchet\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
	//#include "\RC_Hatchet\cfgAmmoMagazinesWeapons\cfgPylonMagazines.hpp"
};
class CfgWeapons
{
	//#include "\RC_Hatchet\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
	//#include "\RC_Hatchet\cfgAmmoMagazinesWeapons\cfgPylonWeapons.hpp"
};

class CfgVehicles
{
	#include "\RC_Hatchet\cfgVehicles\MH60M.hpp"
};