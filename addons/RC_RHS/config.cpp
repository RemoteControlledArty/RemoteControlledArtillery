class CfgPatches
{
	class RC_RHS
	{
		//skipWhenMissingDependencies=1;
		name="Remote Controlled RHS";
		author="Ascent";

		units[]=
		{
			RC_Bradley_D,
			RC_Bradley_D_I,
			RC_Bradley_WD,
			RC_Bradley_WD_I,

			RC_Bradley_V2_D,
			RC_Bradley_V2_D_I,
			RC_Bradley_V2_WD,
			RC_Bradley_V2_WD_I
		};

		weapons[]=
		{
			RC_RHS_AC,
			RC_RHS_MMG
		};

		requiredAddons[]=
		{
			"A3_Weapons_F",
			"A3_Data_F_Enoch_Loadorder",
			"cba_main",
			"Remote_Controlled_Artillery",
			"RHS_US_A2Port_Armor"
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


/*
class CfgEditorSubcategories
{
	class RC_Bradley_subcat {displayname="Bradley";};
};
*/


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
	#include "\RC_Titus\Ammo.hpp"
};
class CfgMagazines
{
	#include "\RC_Titus\Magazines.hpp"
};
class CfgWeapons
{
	#include "\RC_Titus\Weapons.hpp"
};
*/

class CfgVehicles
{
	#include "\RC_RHS\Bradley.hpp"
	//#include "\RC_RHS\Stryker.hpp"
};