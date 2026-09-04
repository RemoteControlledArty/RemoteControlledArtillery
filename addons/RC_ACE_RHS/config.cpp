class CfgPatches
{
	class RC_ACE_RHS
	{
		name="RC ACE RHS";
		author="Ascent";

		units[]=
		{
			//"RC_MH80M_DAP"
		};

		/*
		weapons[]=
		{
			""
		};
		*/

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"RC_ACE",
			"ace_hellfire"
		};

		skipWhenMissingDependencies=1;
	};
};

//later required sensors
class SensorTemplateDataLink;
class SensorTemplateLaser;
class SensorTemplateIR;
class SensorTemplateNV;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateActiveRadar;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


class CfgAmmo
{
	#include "\RC_ACE_RHS\cfgAmmoMagazinesWeapons\cfgPylonAmmo.hpp"
	//#include "\RC_ACE_RHS\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	class CA_Magazine;
	#include "\RC_ACE_RHS\cfgAmmoMagazinesWeapons\cfgPylonMagazines.hpp"
	//#include "\RC_ACE_RHS\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	class Default;
	#include "\RC_ACE_RHS\cfgAmmoMagazinesWeapons\cfgPylonWeapons.hpp"
	//#include "\RC_ACE_RHS\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


/*
class CfgVehicles
{
	#include "\RC_ACE\cfgVehicles\Heli_H80M.hpp"
};
*/