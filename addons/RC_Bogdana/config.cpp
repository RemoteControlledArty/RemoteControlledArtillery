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
			"RC_Bohdana_I"
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
			"vve_core"					//all credits to the Bohdana creators!
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


class CfgWeapons
{
	#include "\RC_Bohdana\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_Bohdana\cfgVehicles\Bohdana.hpp"
};