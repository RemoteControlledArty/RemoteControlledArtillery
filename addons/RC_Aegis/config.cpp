class CfgPatches
{
	class RC_Aegis
	{
		name="Remote Controlled Aegis";
		author="Ascent";

		units[]=
		{
			RC_2S23M_A,
			RC_2S23M_WD,
			RC_2S23M_A_O,
			RC_2S23M_WD_O,
			RC_2S23M_A_I,
			RC_2S23M_WD_I,

			RC_2S23M_LC_A,
			RC_2S23M_LC_WD,
			RC_2S23M_LC_A_O,
			RC_2S23M_LC_WD_O,
			RC_2S23M_LC_A_I,
			RC_2S23M_LC_WD_I,

			RC_2S90M_A,
			RC_2S90M_WD,
			RC_2S90M_A_O,
			RC_2S90M_WD_O,
			RC_2S90M_A_I,
			RC_2S90M_WD_I,

			RC_BTR80A_A,
			RC_BTR80A_WD,
			RC_BTR80A_A_O,
			RC_BTR80A_WD_O,
			RC_BTR80A_A_I,
			RC_BTR80A_WD_I,

			RC_ICV_2_WD2,
			RC_ICV_2_WD2_O,
			RC_ICV_2_WD2_I,

			RC_IFV_2_WD2,
			RC_IFV_2_WD2_O,
			RC_IFV_2_WD2_I,

			RC_ICV_5_WD2,
			RC_ICV_5_WD2_O,
			RC_ICV_5_WD2_I,
			
			RC_IFV_5_WD2,
			RC_IFV_5_WD2_O,
			RC_IFV_5_WD2_I,

			RC_ICV_7_WD,
			RC_ICV_7_WD_O,
			RC_ICV_7_WD_I,

			RC_IFV_7_WD,
			RC_IFV_7_WD_O,
			RC_IFV_7_WD_I,

			RC_IFV_8_WD,
			RC_IFV_8_WD_O,
			RC_IFV_8_WD_I,

			RC_IFV_9_WD,
			RC_IFV_9_WD_O,
			RC_IFV_9_WD_I,

			RC_MBT_3_WD2,
			RC_MBT_3_WD2_O,
			RC_MBT_3_WD2_I,

			RC_MBT_4_A,
			RC_MBT_4_WD,
			RC_MBT_4_A_O,
			RC_MBT_4_WD_O,
			RC_MBT_4_A_I,
			RC_MBT_4_WD_I
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
			"A3_Aegis_Armor_F_Aegis_APC_Wheeled_01",
			"A3_Aegis_Armor_F_Aegis_APC_Wheeled_04"
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
class SensorTemplatePassiveRadar;

//later required optics
class RCWSOptics;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


/*
class CfgAmmo
{
	#include "\RC_Aegis\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
*/
/*
class CfgMagazines
{
	#include "\RC_Aegis\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
*/
class CfgWeapons
{
	#include "\RC_Aegis\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_Aegis\cfgVehicles\2S23M.hpp"
	#include "\RC_Aegis\cfgVehicles\2S90M.hpp"
	#include "\RC_Aegis\cfgVehicles\BTR_80A.hpp"
	#include "\RC_Aegis\cfgVehicles\BTR_100.hpp"
	#include "\RC_Aegis\cfgVehicles\BM_2T_WD.hpp"
	#include "\RC_Aegis\cfgVehicles\Otokar_Arma_WD.hpp"
	#include "\RC_Aegis\cfgVehicles\T_100.hpp"
	#include "\RC_Aegis\cfgVehicles\T_14.hpp"
	#include "\RC_Aegis\cfgVehicles\ZSU_35_WD.hpp"
};