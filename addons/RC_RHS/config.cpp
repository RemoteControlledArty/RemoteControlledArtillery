class CfgPatches
{
	class RC_RHS
	{
		name="Remote Controlled RHS";
		author="Ascent";

		units[]=
		{
			"RC_M1A2_SEPV2_D_B",
			"RC_M1A2_SEPV2_WD_B",
			"RC_M1A2_SEPV2_D_I",
			"RC_M1A2_SEPV2_WD_I",

			"RC_M1A2_SEPV2_NLOS_D_B",
			"RC_M1A2_SEPV2_NLOS_WD_B",
			"RC_M1A2_SEPV2_NLOS_D_I",
			"RC_M1A2_SEPV2_NLOS_WD_I",

			"RC_M2A2_D_B",
			"RC_M2A2_D_I",
			"RC_M2A2_WD_B",
			"RC_M2A2_WD_I",

			"RC_M2A3_BUSKIII_D_B",
			"RC_M2A3_BUSKIII_D_I",
			"RC_M2A3_BUSKIII_WD_B",
			"RC_M2A3_BUSKIII_WD_I",
			
			//"RC_M2A3_BUSKIII_"RC_D_B",
			//"RC_M2A3_BUSKIII_DL_D_B",

			"RC_M2A3_BUSKIII_NLOS_D_B",
			"RC_M2A3_BUSKIII_NLOS_D_I",
			"RC_M2A3_BUSKIII_NLOS_WD_B",
			"RC_M2A3_BUSKIII_NLOS_WD_I",

			"RC_Stryker_M1126_M2_D_B",
			"RC_Stryker_M1126_M2_D_I",
			"RC_Stryker_M1126_M2_WD_B",
			"RC_Stryker_M1126_M2_WD_I",
			"RC_Stryker_M1126_M2_A_B",
			"RC_Stryker_M1126_M2_A_I",

			"RC_Stryker_M1126_MK19_D_B",
			"RC_Stryker_M1126_MK19_D_I",
			"RC_Stryker_M1126_MK19_WD_B",
			"RC_Stryker_M1126_MK19_WD_I",
			"RC_Stryker_M1126_MK19_A_B",
			"RC_Stryker_M1126_MK19_A_I",

			"RC_Stryker_M1127_M2_D_B",
			"RC_Stryker_M1127_M2_D_I",
			"RC_Stryker_M1127_M2_WD_B",
			"RC_Stryker_M1127_M2_WD_I",

			"RC_Stryker_M1127_D_B",
			"RC_Stryker_M1127_D_I",
			"RC_Stryker_M1127_WD_B",
			"RC_Stryker_M1127_WD_I",

			"RC_M108_A",
			"RC_M108_WD",
			"RC_M108_A_O",
			"RC_M108_WD_O",
			"RC_M108_A_I",
			"RC_M108_WD_I",

			"RC_M108_LC_A",
			"RC_M108_LC_WD",
			"RC_M108_LC_A_O",
			"RC_M108_LC_WD_O",
			"RC_M108_LC_A_I",
			"RC_M108_LC_WD_I",

			"RC_M109_A",
			"RC_M109_WD",
			"RC_M109_A_O",
			"RC_M109_WD_O",
			"RC_M109_A_I",
			"RC_M109_WD_I",

			"RC_M109_LC_A",
			"RC_M109_LC_WD",
			"RC_M109_LC_A_O",
			"RC_M109_LC_WD_O",
			"RC_M109_LC_A_I",
			"RC_M109_LC_WD_I",

			"RC_M119",
			"RC_M119_O",
			"RC_M119_I",

			"RC_M119_LC",
			"RC_M119_LC_O",
			"RC_M119_LC_I",

			"RC_HIMARS_D",
			"RC_HIMARS_WD",
			"RC_HIMARS_D_O",
			"RC_HIMARS_WD_O",
			"RC_HIMARS_D_I",
			"RC_HIMARS_WD_I",

			"RC_HIMARS_ATACMS_D",
			"RC_HIMARS_ATACMS_WD",
			"RC_HIMARS_ATACMS_D_O",
			"RC_HIMARS_ATACMS_WD_O",
			"RC_HIMARS_ATACMS_D_I",
			"RC_HIMARS_ATACMS_WD_I",

			"RC_FlatbedTruck_A",
			"RC_FlatbedTruck_WD",
			"RC_FlatbedTruck_A_O",
			"RC_FlatbedTruck_WD_O",
			"RC_FlatbedTruck_A_I",
			"RC_FlatbedTruck_WD_I",

			"RC_FlatbedTruck_LC_A",
			"RC_FlatbedTruck_LC_WD",
			"RC_FlatbedTruck_LC_A_O",
			"RC_FlatbedTruck_LC_WD_O",
			"RC_FlatbedTruck_LC_A_I",
			"RC_FlatbedTruck_LC_WD_I",

			"RC_FlatbedTruck_manned_A",
			"RC_FlatbedTruck_manned_WD",
			"RC_FlatbedTruck_manned_A_O",
			"RC_FlatbedTruck_manned_WD_O",
			"RC_FlatbedTruck_manned_A_I",
			"RC_FlatbedTruck_manned_WD_I"
		};

		weapons[]=
		{
			"RC_RHS_weap_m256",
			"RC_RHS_weap_m240_abrams_coax",

			"RC_RHS_weap_M242BC",
			"RC_RHS_weap_m240_bradley_coax",

			"RC_RHS_weap_TOW_Launcher",
			"RC_Bradley_Missile_Launcher",

			"RC_RHS_M2_CROWS_M151",
			"RC_RHS_MK19_CROWS_M153"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"RHS_US_A2Port_Armor",
			"rhsusf_c_m1a2",
			"rhsusf_c_statics",
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
	//class RC_RHS_A_subcat {displayname="RHS Arid";};
	class RC_RHS_D_subcat {displayname="RHS Desert";};
	class RC_RHS_WD_subcat {displayname="RHS Woodland";};
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
	//#include "\RC_RHS\cfgVehicles\ASV.hpp"
	#include "\RC_RHS\cfgVehicles\Abrams.hpp"
	#include "\RC_RHS\cfgVehicles\Bradley.hpp"
	#include "\RC_RHS\cfgVehicles\FlatbedTruck.hpp"
	#include "\RC_RHS\cfgVehicles\M109.hpp"
	#include "\RC_RHS\cfgVehicles\M119_105mm.hpp"
	#include "\RC_RHS\cfgVehicles\oldBradley.hpp"
	//#include "\RC_RHS\cfgVehicles\HMMWV.hpp"
	//#include "\RC_RHS\cfgVehicles\HIMARS.hpp"
	#include "\RC_RHS\cfgVehicles\Stryker.hpp"
};