class CfgPatches
{
	class RC_Crocus
	{
		name="improved Crocus FPV";
		author="Ascent";

		units[]=
		{
			RC_Crocus_MP,
			RC_Crocus_MP_O,
			RC_Crocus_MP_I,

			RC_CrocusRepeater,
			RC_CrocusRepeater_O,
			RC_CrocusRepeater_I
		};

		weapons[]=
		{
			"RC_Crocus_MP_Warhead",
			"RC_"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"ArmaFPV_Data"
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