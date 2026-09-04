class CfgPatches
{
	class RC_ACE
	{
		name="RC ACE";
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
			"ace_missileguidance"
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
	#include "\RC_ACE\cfgAmmoMagazinesWeapons\cfgPylonAmmo.hpp"
	//#include "\RC_ACE\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	class CA_Magazine;
	#include "\RC_ACE\cfgAmmoMagazinesWeapons\cfgPylonMagazines.hpp"
	//#include "\RC_ACE\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	class Default;
	#include "\RC_ACE\cfgAmmoMagazinesWeapons\cfgPylonWeapons.hpp"
	//#include "\RC_ACE\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


/*
class CfgVehicles
{
	#include "\RC_ACE\cfgVehicles\Heli_H80M.hpp"
};
*/