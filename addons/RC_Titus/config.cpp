class CfgPatches
{
	class RC_Titus
	{
		skipWhenMissingDependencies=1;
		name="Remote Controlled Titus";
		author="Ascent";

		units[]=
		{
			RC_Titus_A,
			RC_Titus_D,
			RC_Titus_WD,

			RC_Titus_Ti_A,
			RC_Titus_Ti_D,
			RC_Titus_Ti_WD,

			RC_Titus_AC_A,
			RC_Titus_AC_D,
			RC_Titus_AC_WD,

			RC_Titus_AC_Ti_A,
			RC_Titus_AC_Ti_D,
			RC_Titus_AC_Ti_WD,

			RC_Titus_HMG_A,
			RC_Titus_HMG_D,
			RC_Titus_HMG_WD,

			RC_Titus_HMG_Ti_A,
			RC_Titus_HMG_Ti_D,
			RC_Titus_HMG_Ti_WD
		};

		weapons[]=
		{
			RC_HMG_127_APC,
			RC_MMG_338_FSV
		};

		requiredAddons[]=
		{
			"A3_Weapons_F",
			"A3_Data_F_Enoch_Loadorder",
			"cba_main",
			"Remote_Controlled_Artillery"
		};
	};
};


/*
class CfgFunctions
{
	class RC
	{
		class RC_Titus
		{
		};
	};
};
*/


class CfgEditorSubcategories
{
	class RC_IMV_unarmed_subcat {displayname="IMV's (unarmed)";};
	class RC_IMV_armed_subcat {displayname="IMV's (armed)";};
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
	#include "\RC_Titus\cfgAmmo\Ammo.hpp"
};
class CfgMagazines
{
	#include "\RC_Titus\cfgMagazines\Magazines.hpp"
};
class CfgWeapons
{
	#include "\RC_Titus\cfgWeapons\Weapons.hpp"
};
class CfgVehicles
{
	#include "\RC_Titus\cfgVehicles\Titus_unarmed.hpp"
	#include "\RC_Titus\cfgVehicles\Titus_armed.hpp"
};