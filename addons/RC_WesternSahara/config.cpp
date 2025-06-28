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
			RC_IFV_9_A_I,
			
			RC_60mmMortarPatria_A,
			RC_60mmMortarPatria_WD,
			RC_60mmMortarPatria_A_O,
			RC_60mmMortarPatria_WD_O,
			RC_60mmMortarPatria_A_I,
			RC_60mmMortarPatria_WD_I,

			RC_60mmMortarPatria_LC_A,
			RC_60mmMortarPatria_LC_WD,
			RC_60mmMortarPatria_LC_A_O,
			RC_60mmMortarPatria_LC_WD_O,
			RC_60mmMortarPatria_LC_A_I,
			RC_60mmMortarPatria_LC_WD_I,

			RC_OtokarArma_RCIV_A,
			RC_OtokarArma_RCIV_WD,
			RC_OtokarArma_RCIV_A_O,
			RC_OtokarArma_RCIV_WD_O,
			RC_OtokarArma_RCIV_A_I,
			RC_OtokarArma_RCIV_WD_I,

			RC_ICV_5_A2,
			RC_ICV_5_A2_O,
			RC_ICV_5_A2_I,

			RC_IFV_5_A2,
			RC_IFV_5_A2_O,
			RC_IFV_5_A2_I,

			RC_ZSU35_A,
			RC_ZSU35_A_O,
			RC_ZSU35_A_I
		};

		weapons[]=
		{
			"RC_IFV_Missile_Launcher_lxWS",
			"RC_vehiclemortar_60mm_V4_lxWS",
			"RC_HMG_M2_lxWS"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"vehicles_1_F_lxWS_APC_Wheeled_02",
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
/*
class CfgMagazines
{
	#include "\RC_WesternSahara\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
*/
class CfgWeapons
{
	#include "\RC_WesternSahara\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_WesternSahara\cfgVehicles\BM_2T_A.hpp"
	#include "\RC_WesternSahara\cfgVehicles\Otokar_Arma_HMG.hpp"
	#include "\RC_WesternSahara\cfgVehicles\Patria_60mm_Mortar.hpp"
	#include "\RC_WesternSahara\cfgVehicles\Patria_AMV_ATGM.hpp"
	#include "\RC_WesternSahara\cfgVehicles\ZSU_35_A.hpp"
};