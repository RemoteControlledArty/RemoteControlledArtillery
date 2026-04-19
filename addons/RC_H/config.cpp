class CfgPatches
{
	class RC_Hatchet
	{
		name="Remote Controlled Hatchet";
		author="Ascent";

		units[]=
		{
			"RC_MH60M_DAP",
			"RC_MH60M_DAP_O",
			"RC_MH60M_DAP_I"
		};

		weapons[]=
		{
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"Hatchet"
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
	//#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
	#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgPylonAmmo.hpp"
};
class CfgMagazines
{
	//#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
	#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgPylonMagazines.hpp"
};
class CfgWeapons
{
	//#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
	#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgPylonWeapons.hpp"
};

class CfgVehicles
{
	#include "\RC_RHS\cfgVehicles\MH60M.hpp"
};