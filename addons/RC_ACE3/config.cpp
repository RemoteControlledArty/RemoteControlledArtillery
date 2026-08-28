class CfgPatches
{
	class RC_ACE3
	{
		name="RC ACE3";
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
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\cfgPylonAmmo.hpp"
	//#include "\RC_ACE3\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	class CA_Magazine;
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\cfgPylonMagazines.hpp"
	//#include "\RC_ACE3\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	class Default;
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\cfgPylonWeapons.hpp"
	//#include "\RC_ACE3\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


/*
class CfgVehicles
{
	#include "\RC_ACE3\cfgVehicles\Heli_H80M.hpp"
};
*/