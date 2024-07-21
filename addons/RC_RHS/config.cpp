class CfgPatches
{
	class RC_RHS
	{
		name="Remote Controlled RHS";
		author="Ascent";

		units[]=
		{
			RC_M2A2_D_B,
			RC_M2A2_D_I,
			RC_M2A2_WD_B,
			RC_M2A2_WD_I,

			RC_M2A3_BUSKIII_D_B,
			RC_M2A3_BUSKIII_D_I,
			RC_M2A3_BUSKIII_WD_B,
			RC_M2A3_BUSKIII_WD_I,

			RC_M2A3_BUSKIII_RC_D_B,
			RC_M2A3_BUSKIII_DL_D_B,

			RC_M2A3_BUSKIII_NLOS_D_B,
			RC_M2A3_BUSKIII_NLOS_D_I,
			RC_M2A3_BUSKIII_NLOS_WD_B,
			RC_M2A3_BUSKIII_NLOS_WD_I,

			RC_Stryker_M1126_M2_D_B,
			RC_Stryker_M1126_M2_D_I,
			RC_Stryker_M1126_M2_WD_B,
			RC_Stryker_M1126_M2_WD_I,
			RC_Stryker_M1126_M2_A_B,
			RC_Stryker_M1126_M2_A_I,

			RC_Stryker_M1126_MK19_D_B,
			RC_Stryker_M1126_MK19_D_I,
			RC_Stryker_M1126_MK19_WD_B,
			RC_Stryker_M1126_MK19_WD_I,
			RC_Stryker_M1126_MK19_A_B,
			RC_Stryker_M1126_MK19_A_I,

			RC_Stryker_M1127_M2_D_B,
			RC_Stryker_M1127_M2_D_I,
			RC_Stryker_M1127_M2_WD_B,
			RC_Stryker_M1127_M2_WD_I
		};

		weapons[]=
		{
			RC_RHS_weap_m240_bradley_coax,

			RC_RHS_weap_M242BC,

			RC_RHS_weap_TOW_Launcher,
			RC_Bradley_Missle_Launcher,

			RC_RHS_M2_CROWS_M151,
			RC_RHS_MK19_CROWS_M153
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
	class RC_RHS_A_subcat {displayname="RHS Arid";};
	class RC_RHS_D_subcat {displayname="RHS Desert";};
	class RC_RHS_WD_subcat {displayname="RHS Woodland";};
};

//TARGET CONFIRMER FOR DRIVER, gunner camera panel for troop commander seat


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
	//#include "\RC_RHS\cfgVehicles\Abrams.hpp"
	#include "\RC_RHS\cfgVehicles\Bradley.hpp"
	#include "\RC_RHS\cfgVehicles\oldBradley.hpp"
	//#include "\RC_RHS\cfgVehicles\HMMWV.hpp"
	#include "\RC_RHS\cfgVehicles\Stryker.hpp"
};