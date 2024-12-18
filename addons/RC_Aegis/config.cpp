class CfgPatches
{
	class RC_Aegis
	{
		name="Remote Controlled Aegis";
		author="Ascent";

		units[]=
		{
			RC_CBRad2_AI_WD,
			RC_CBRad2_AI_WD_O,
			RC_CBRad2_AI_WD_I,

			RC_CBRad2_Player_WD,
			RC_CBRad2_Player_WD_O,
			RC_CBRad2_Player_WD_I,

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
			RC_IFV_9_WD_I
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
			"A3_Aegis_Armor_F_Aegis_APC_Tracked_02",
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
class CfgMagazines
{
	#include "\RC_Aegis\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_Aegis\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_Aegis\cfgVehicles\2S90M.hpp"
	#include "\RC_Aegis\cfgVehicles\BTR_80A.hpp"
	#include "\RC_Aegis\cfgVehicles\BTR_100.hpp"
	#include "\RC_Aegis\cfgVehicles\BM_2T_Bumerang.hpp"
	#include "\RC_Aegis\cfgVehicles\CBRad_WD.hpp"
	#include "\RC_Aegis\cfgVehicles\Otokar_Arma_WD.hpp"
	#include "\RC_Aegis\cfgVehicles\Patria_AMV_ATGM_WD.hpp"
};