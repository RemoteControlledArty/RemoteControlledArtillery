class CfgPatches
{
	class RC_AbramsX
	{
		name="RC AbramsX";
		author="Ascent";

		units[]=
		{
			"RC_AbramsX_A",
			"RC_AbramsX_WD"
		};

		weapons[]=
		{
			"RC_autocannon_30mm_ACV",
			"RC_autocannon_40mm_ACV"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"QAV_AbramsX"
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
class SensorTemplatePassiveRadar;

//later required optics
class RCWSOptics;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


/*
class CfgAmmo
{
	#include "\RC_ACV\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_ACV\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
*/
class CfgWeapons
{
	#include "\RC_AbramsX\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_AbramsX\cfgVehicles\AbramsX.hpp"
};