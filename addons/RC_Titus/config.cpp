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

		ammo[]=
		{
			RC_QIN_20mm_T_R,
			RC_QIN_20mm_T_G,
			RC_QIN_20mm_T_Y,
			RC_QIN_338_T_R,
			RC_QIN_338_T_G,
			RC_QIN_338_T_Y
		};

		magazines[]=
		{
			RC_QIN_100Rnd_20mm_T_R,
			RC_QIN_100Rnd_20mm_T_G,
			RC_QIN_100Rnd_20mm_T_Y,
			RC_QIN_150Rnd_338_T_R,
			RC_QIN_150Rnd_338_T_G,
			RC_QIN_150Rnd_338_T_Y
		};

		weapons[]=
		{
			RC_QIN_20mm_AC,
			RC_QIN_338_MMG1,
			RC_QIN_338_MMG2
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