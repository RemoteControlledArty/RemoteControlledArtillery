class CfgPatches
{
	class RC_WesternSahara
	{
		name="Remote Controlled Western Sahara";
		author="Ascent";

		units[]=
		{
			RC_IFV_9_A,
			RC_IFV_9_A_O,
			RC_IFV_9_A_I
		};

		weapons[]=
		{
			"RC_IFV_Missile_Launcher_lxWS"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"Vehicles_F_lxWS_APC_Wheeled_01"
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
	#include "\RC_WesternSahara\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
*/
class CfgMagazines
{
	#include "\RC_WesternSahara\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_WesternSahara\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_WesternSahara\cfgVehicles\Patria_60mm_Mortar.hpp"
	//#include "\RC_WesternSahara\cfgVehicles\Patria_AMV_ATGM.hpp"
};