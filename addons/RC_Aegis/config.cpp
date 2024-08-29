class CfgPatches
{
	class RC_Aegis
	{
		name="Remote Controlled Aegis";
		author="Ascent";

		units[]=
		{
			RC_IFV_7_A_O,
			RC_ICV_7_A_O,
			RC_IFV_8_A_O,
			RC_ICV_8_A_O
		};

		//add low detectability datalinked AP-5

		/*
		weapons[]=
		{
			RC_,
			RC_
		};
		*/

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"A3_Aegis_Armor_F_Aegis_APC_Tracked_02",
			"A3_Aegis_Armor_F_Aegis_APC_Wheeled_04"
		};

		skipWhenMissingDependencies=1;
	};
};


/*
class CfgFunctions
{
	class RC
	{
		class RC_Aegis
		{
		};
	};
};
*/


/*
class CfgEditorSubcategories
{
	class RC_Aegis_A_subcat {displayname="Aegis Arid";};
	class RC_Aegis_D_subcat {displayname="Aegis Desert";};
	class RC_Aegis_WD_subcat {displayname="Aegis Woodland";};
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
	#include "\RC_Aegis\cfgVehicles\BTR_100.hpp"
	#include "\RC_Aegis\cfgVehicles\BTR_T.hpp"
};