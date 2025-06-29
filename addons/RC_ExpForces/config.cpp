class CfgPatches
{
	class RC_ExpForces
	{
		name="Remote Controlled Expeditionary Forces";
		author="Ascent";

		units[]=
		{
			"RC_AAV9_A",
			"RC_AAV9_WD",
			"RC_AAV9_A_O",
			"RC_AAV9_WD_O",
			"RC_AAV9_A_I",
			"RC_AAV9_WD_I",

			"RC_AAV9A1_A",
			"RC_AAV9A1_WD",
			"RC_AAV9A1_A_O",
			"RC_AAV9A1_WD_O",
			"RC_AAV9A1_A_I",
			"RC_AAV9A1_WD_I"
		};

		weapons[]=
		{
			"RC_EF_autocannon_30mm",
			"RC_EF_autocannon_50mm",
			"RC_EF_MMG_coax"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"EF_AAV9_C"
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


class CfgAmmo
{
	#include "\RC_ExpForces\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_ExpForces\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_ExpForces\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_ExpForces\cfgVehicles\AAV.hpp"
};