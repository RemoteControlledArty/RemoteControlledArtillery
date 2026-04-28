class CfgPatches
{
	class RC_VVE
	{
		name="RC VVE";
		author="Ascent";

		units[]=
		{
			"RC_AMV_MGS_WD_B",
			"RC_AMV_MGS_WD_O",
			"RC_AMV_MGS_WD_I",

			"RC_AMV_MGS_A_B",
			"RC_AMV_MGS_A_O",
			"RC_AMV_MGS_A_I",

			"RC_AMV_SHORAD_A_B",
			"RC_AMV_SHORAD_A_O",
			"RC_AMV_SHORAD_A_I",

			"RC_AMV_SHORAD_WD_B",
			"RC_AMV_SHORAD_WD_O",
			"RC_AMV_SHORAD_WD_I",
			
			/*
			"RC_AMV_SHORAD_manned_A_B",
			"RC_AMV_SHORAD_manned_A_O",
			"RC_AMV_SHORAD_manned_A_I",

			"RC_AMV_SHORAD_manned_WD_B",
			"RC_AMV_SHORAD_manned_WD_O",
			"RC_AMV_SHORAD_manned_WD_I",
			*/

			"RC_AMV_APC_A_B",
			"RC_AMV_APC_A_O",
			"RC_AMV_APC_A_I",

			"RC_AMV_APC_WD_B",
			"RC_AMV_APC_WD_O",
			"RC_AMV_APC_WD_I"
		};

		weapons[]=
		{
			"RC_Single_autocannon_35mm_AA",
			"RC_MGS_cannon_105mm",
			"RC_AMV_HMG"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"vve_core",					//all credits to the VVE creators!
			"qav_marshall"
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
	#include "\RC_VVE\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_VVE\cfgVehicles\AMV_MGS.hpp"
	#include "\RC_VVE\cfgVehicles\AMV_SHORAD.hpp"
	#include "\RC_VVE\cfgVehicles\AMV_APC.hpp"
};