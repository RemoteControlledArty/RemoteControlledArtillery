class CfgPatches
{
	class RC_ACV
	{
		name="RC ACV";
		author="Ascent";

		units[]=
		{
			"RC_ACV_30",
			"RC_ACV_30_O",
			"RC_ACV_30_I",

			"RC_ACV_40",
			"RC_ACV_40_O",
			"RC_ACV_40_I"
			
			/*
			"RC_ACV_HMG",
			"RC_ACV_HMG_O",
			"RC_ACV_HMG_I"
			*/
		};

		weapons[]=
		{
			"RC_autocannon_30mm_ACV",
			"RC_autocannon_40mm_ACV",
			"RC_HMG_M2_ACV"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"ACV"
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
	#include "\RC_ACV\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_ACV\cfgVehicles\ACV_30mm.hpp"
};