class CfgPatches
{
	class RC_VVE
	{
		name="RC VVE";
		author="Ascent";

		units[]=
		{
			"RC_AMV_MGS_WD",
			"RC_AMV_MGS_WD_O",
			"RC_AMV_MGS_WD_I",

			"RC_AMV_MGS_A",
			"RC_AMV_MGS_A_O",
			"RC_AMV_MGS_A_I"
		};

		weapons[]=
		{
			"RC_AMV_MGS_120mm_M360",
			"RC_AMV_MGS_MMG_coax",
			"RC_AMV_MGS_HMG_com"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
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

//later required optics
class RCWSOptics;

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
};