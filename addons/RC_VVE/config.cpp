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
			"RC_AMV_SHORAD_WD_I"
		};

		weapons[]=
		{
			"RC_AMV_MGS_120mm_M360",
			"RC_AMV_MGS_MMG_coax",
			"RC_AMV_MGS_HMG_com",

			"RC_Single_autocannon_35mm_AA"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"vve_core",
			"qav_marshall"
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

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


class CfgWeapons
{
	#include "\RC_VVE\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	//#include "\RC_VVE\cfgVehicles\AMV_MGS.hpp"
	#include "\RC_VVE\cfgVehicles\AMV_SHORAD.hpp"
	//#include "\RC_VVE\cfgVehicles\AMV_APC.hpp"
};