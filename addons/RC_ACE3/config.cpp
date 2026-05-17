class CfgPatches
{
	class RC_ACE3
	{
		name="RC ACE3";
		author="Ascent";

		/*
		units[]=
		{
			"",
		};
		*/

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
			"ace3"	//?
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


/*
class CfgAmmo
{
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\PylonAmmo.hpp"
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\Ammo.hpp"
};
class CfgMagazines
{
	class CA_Magazine;
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\PylonMagazines.hpp"
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\Magazines.hpp"
};
class CfgWeapons
{
	class Default;
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\PylonWeapons.hpp"
	#include "\RC_ACE3\cfgAmmoMagazinesWeapons\Weapons.hpp"
};
*/


class CfgVehicles
{
	//#include "\RC_GX\cfgVehicles\.hpp"
};