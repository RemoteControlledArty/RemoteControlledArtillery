class CfgPatches
{
	class RC_Challenger2
	{
		name="RC Challenger 2";
		author="Ascent";

		units[]=
		{
			"RC_Challenger2_WD",
			"RC_Challenger2_WD_O",
			"RC_Challenger2_WD_I",

			"RC_Challenger2_A",
			"RC_Challenger2_A_O",
			"RC_Challenger2_A_I"
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
			"QAV_Challenger"
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
class CfgWeapons
{
	#include "\RC_Challenger2\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};
*/


class CfgVehicles
{
	#include "\RC_Challenger2\cfgVehicles\Challenger2.hpp"
};