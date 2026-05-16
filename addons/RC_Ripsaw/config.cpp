class CfgPatches
{
	class RC_Ripsaw
	{
		name="RC Ripsaw";
		author="Ascent";

		units[]=
		{
			"RC_Ripsaw_WD_B",
			"RC_Ripsaw_WD_O",
			"RC_Ripsaw_WD_I",

			"RC_Ripsaw_A_B",
			"RC_Ripsaw_A_O",
			"RC_Ripsaw_A_I",

			"RC_Ripsaw_cUAS_WD_B",
			"RC_Ripsaw_cUAS_WD_O",
			"RC_Ripsaw_cUAS_WD_I",

			"RC_Ripsaw_cUAS_A_B",
			"RC_Ripsaw_cUAS_A_O",
			"RC_Ripsaw_cUAS_A_I"

			/*
			"RC_Bullfrog_WD_B",
			"RC_Bullfrog_WD_O",
			"RC_Bullfrog_WD_I",

			"RC_Bullfrog_A_B",
			"RC_Bullfrog_A_O",
			"RC_Bullfrog_A_I"
			*/
		};

		weapons[]=
		{
			"RC_Ripsaw_Mk30",
			"RC_Ripsaw_Mk30_cUAS",
			"RC_Ripsaw_coax"
		};
		
		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"QAV_Ripsaw"		//all credits to the QAV creators!
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
	#include "\RC_Ripsaw\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_Ripsaw\cfgVehicles\Ripsaw.hpp"
	//#include "\RC_Ripsaw\cfgVehicles\Bullfrog.hpp"
};