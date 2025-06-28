class CfgPatches
{
	class RC_AegisWS
	{
		name="Remote Controlled Aegis-WS";
		author="Ascent";

		units[]=
		{
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

			"vehicles_1_F_lxWS_APC_Tracked_02",
			"A3_Aegis_Armor_F_Aegis_APC_Tracked_02",
			
			"Vehicles_F_lxWS_APC_Wheeled_01",
			"A3_Aegis_Armor_F_Aegis_APC_Wheeled_01"
		};

		skipWhenMissingDependencies=1;
	};
};


/*
class CfgAmmo
{
	#include "\RC_Aegis\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
*/
class CfgMagazines
{
	#include "\RC_AegisWS\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_AegisWS\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_AegisWS\cfgVehicles\BM_2T_Bumerang.hpp"
	#include "\RC_AegisWS\cfgVehicles\Patria_AMV_ATGM_WD.hpp"
};