class CfgPatches
{
	class RC_Titus
	{
		//skipWhenMissingDependencies=1;
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

			/*
			RC_Titus_Ti_A,
			RC_Titus_Ti_D,
			RC_Titus_Ti_WD,
			*/

			RC_Titus_AC_A,
			RC_Titus_AC_D,
			RC_Titus_AC_WD,
			RC_Titus_AC_A_O,
			RC_Titus_AC_D_O,
			RC_Titus_AC_WD_O,
			RC_Titus_AC_A_I,
			RC_Titus_AC_D_I,
			RC_Titus_AC_WD_I,

			RC_Titus_HMG_A,
			RC_Titus_HMG_D,
			RC_Titus_HMG_WD,
			RC_Titus_HMG_A_O,
			RC_Titus_HMG_D_O,
			RC_Titus_HMG_WD_O,
			RC_Titus_HMG_A_I,
			RC_Titus_HMG_D_I,
			RC_Titus_HMG_WD_I
		};

		weapons[]=
		{
			RC_Titus_AC,
			RC_Titus_HMG
		};

		requiredAddons[]=
		{
			"A3_Weapons_F",
			"A3_Data_F_Enoch_Loadorder",
			"cba_main",
			"Remote_Controlled_Artillery",
			"QIN_Titus"
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
	class RC_Titus_subcat {displayname="Titus MRAP";};
	//class RC_IMV_armed_subcat {displayname="IMV's (armed)";};
};


//later required sensors
class SensorTemplateDataLink;
class SensorTemplateLaser;
class SensorTemplateIR;
class SensorTemplateNV;
class SensorTemplateVisual;
class SensorTemplateMan;
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