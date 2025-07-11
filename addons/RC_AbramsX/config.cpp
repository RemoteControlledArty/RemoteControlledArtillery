class CfgPatches
{
	class RC_AbramsX
	{
		name="RC AbramsX";
		author="Ascent";

		units[]=
		{
			"RC_AbramsX_WD",
			"RC_AbramsX_WD_O",
			"RC_AbramsX_WD_I",

			"RC_AbramsX_A",
			"RC_AbramsX_A_O",
			"RC_AbramsX_A_I",

			"RC_AbramsX_Twin_WD",
			"RC_AbramsX_Twin_WD_O",
			"RC_AbramsX_Twin_WD_I",
			
			"RC_AbramsX_Twin_A",
			"RC_AbramsX_Twin_A_O",
			"RC_AbramsX_Twin_A_I"
		};

		weapons[]=
		{
			"RC_AbramsX_120mm_M360",
			"RC_AbramsX_30mm_M914",
			"RC_AbramsX_30mm_M914_twin",
			"RC_AbramsX_20mm_coax",
			"RC_AbramsX_20mm_DualFed_coax",
			"RC_AbramsX_HMG_coax"
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
class SensorTemplateActiveRadar;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;

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
	#include "\RC_AbramsX\cfgVehicles\AbramsX_twin.hpp"
};