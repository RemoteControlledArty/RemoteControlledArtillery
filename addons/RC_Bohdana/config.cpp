class CfgPatches
{
	class RC_Bohdana
	{
		name="RC Bohdana";
		author="Ascent";

		units[]=
		{
			"RC_Bohdana_B",
			"RC_Bohdana_O",
			"RC_Bohdana_I",

			"RC_Bohdana_manned_B",
			"RC_Bohdana_manned_O",
			"RC_Bohdana_manned_I"
		};
		weapons[]=
		{
			"RC_2S22_155mm_V4"
		};
		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"frtz_2s22_bogdana_maz"		//all credits to the Bohdana creators!
		};

		skipWhenMissingDependencies=1;	//soft dependency
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


class CfgMagazines
{
	#include "\RC_Bohdana\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_Bohdana\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_Bohdana\cfgVehicles\Bohdana.hpp"
};