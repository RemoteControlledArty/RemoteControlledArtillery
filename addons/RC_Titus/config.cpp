class CfgPatches
{
	class RC_Titus
	{
		name="Remote Controlled Titus";
		author="Ascent";

		units[]=
		{
			RC_Titus_A,
			RC_Titus_D,
			RC_Titus_WD,
			RC_Titus_A_O,
			RC_Titus_D_O,
			RC_Titus_WD_O,
			RC_Titus_A_I,
			RC_Titus_D_I,
			RC_Titus_WD_I,

			RC_Titus_AC_A,
			RC_Titus_AC_D,
			RC_Titus_AC_WD,
			RC_Titus_AC_A_O,
			RC_Titus_AC_D_O,
			RC_Titus_AC_WD_O,
			RC_Titus_AC_A_I,
			RC_Titus_AC_D_I,
			RC_Titus_AC_WD_I,

			RC_Titus_MMG_A,
			RC_Titus_MMG_D,
			RC_Titus_MMG_WD,
			RC_Titus_MMG_A_O,
			RC_Titus_MMG_D_O,
			RC_Titus_MMG_WD_O,
			RC_Titus_MMG_A_I,
			RC_Titus_MMG_D_I,
			RC_Titus_MMG_WD_I
		};

		weapons[]=
		{
			RC_Titus_AC,
			RC_Titus_HMG
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"QIN_Titus"
		};
		
		skipWhenMissingDependencies=1;
	};
};


class CfgEditorSubcategories
{
	class RC_Titus_subcat {displayname="Titus MRAP";};
	//class RC_IMV_armed_subcat {displayname="IMV's (armed)";};
};


//later required sensors
class SensorTemplateDataLink;
class SensorTemplateLaser;
class SensorTemplatePassiveRadar;
//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


#include "\RC_Titus\cfgAmmoMagazinesWeapons.hpp"


class CfgVehicles
{
	#include "\RC_Titus\Titus_armed.hpp"
	#include "\RC_Titus\Titus_unarmed.hpp"
};