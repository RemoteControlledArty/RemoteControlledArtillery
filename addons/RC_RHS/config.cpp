class CfgPatches
{
	class RC_RHS
	{
		name="Remote Controlled RHS";
		author="Ascent";

		units[]=
		{
			RC_Bradley_D,
			RC_Bradley_D_I,
			RC_Bradley_WD,
			RC_Bradley_WD_I,

			RC_APC_Stryker_M1126_M2_D,
			RC_APC_Stryker_M1126_M2_D_I,
			RC_APC_Stryker_M1126_M2_WD,
			RC_APC_Stryker_M1126_M2_WD_I,
			RC_APC_Stryker_M1126_MK19_D,
			RC_APC_Stryker_M1126_MK19_D_I,
			RC_APC_Stryker_M1126_MK19_WD,
			RC_APC_Stryker_M1126_MK19_WD_I
		};

		weapons[]=
		{
			RC_RHS_weap_m240_bradley_coax,
			RC_RHS_weap_M242BC,
			RC_RHS_weap_TOW_Launcher
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"RHS_US_A2Port_Armor",
			"rhsusf_c_stryker"
		};

		skipWhenMissingDependencies=1;
	};
};


/*
class CfgFunctions
{
	class RC
	{
		class RC_RHS
		{
		};
	};
};
*/


class CfgEditorSubcategories
{
	class RC_RHS_subcat {displayname="RHS";};
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
	#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_RHS\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};

class CfgVehicles
{
	#include "\RC_RHS\cfgVehicles\Bradley.hpp"
	#include "\RC_RHS\cfgVehicles\Stryker.hpp"
};