class CfgPatches
{
	class RC_ACE3_RHS
	{
		name="RC ACE3 RHS";
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
			"RC_ACE3",
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
	#include "\RC_ACE3_RHS\cfgAmmoMagazinesWeapons\cfgPylonAmmo.hpp"
	//#include "\RC_ACE3_RHS\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	class CA_Magazine;
	#include "\RC_ACE3_RHS\cfgAmmoMagazinesWeapons\cfgPylonMagazines.hpp"
	//#include "\RC_ACE3_RHS\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	class Default;
	#include "\RC_ACE3_RHS\cfgAmmoMagazinesWeapons\cfgPylonWeapons.hpp"
	//#include "\RC_ACE3_RHS\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


/*
class CfgVehicles
{
	#include "\RC_ACE3\cfgVehicles\Heli_H80M.hpp"
};
*/