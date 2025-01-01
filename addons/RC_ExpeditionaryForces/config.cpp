class CfgPatches
{
	class RC_ExpeditionaryForces
	{
		name="Remote Controlled Expeditionary Forces";
		author="Ascent";

		units[]=
		{
			/*
			RC_AAV_30mm_A,
			RC_AAV_30mm_WD,
			RC_AAV_30mm_A_O,
			RC_AAV_30mm_WD_O,
			RC_AAV_30mm_A_I,
			RC_AAV_30mm_WD_I,
			*/

			RC_AAV_50mm_A
			/*
			RC_AAV_50mm_WD,
			RC_AAV_50mm_A_O,
			RC_AAV_50mm_WD_O,
			RC_AAV_50mm_A_I,
			RC_AAV_50mm_WD_I,

			RC_AAV_unarmed_A,
			RC_AAV_unarmed_WD,
			RC_AAV_unarmed_A_O,
			RC_AAV_unarmed_WD_O,
			RC_AAV_unarmed_A_I,
			RC_AAV_unarmed_WD_I
			*/
		};

		weapons[]=
		{
			"RC_IFV_Missile_Launcher_lxWS"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"vehicles_1_F_lxWS_APC_Wheeled_02"
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
	#include "\RC_ExpeditionaryForces\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_ExpeditionaryForces\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_ExpeditionaryForces\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_ExpeditionaryForces\cfgVehicles\AAV.hpp"
};