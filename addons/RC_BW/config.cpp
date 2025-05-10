class CfgPatches
{
	class RC_BW
	{
		name="RC BW";
		author="Ascent";

		units[]=
		{
			RC_Puma_30mm_FT,
			RC_Puma_30mm_FT_O,
			RC_Puma_30mm_FT_I,
			RC_Puma_30mm_TT,
			RC_Puma_30mm_TT_O,
			RC_Puma_30mm_TT_I,

			RC_PzH2000_FT,
			RC_PzH2000_FT_O,
			RC_PzH2000_FT_I,
			RC_PzH2000_TT,
			RC_PzH2000_TT_O,
			RC_PzH2000_TT_I,

			RC_PzH2000_LC_FT,
			RC_PzH2000_LC_FT_O,
			RC_PzH2000_LC_FT_I,
			RC_PzH2000_LC_TT,
			RC_PzH2000_LC_TT_O,
			RC_PzH2000_LC_TT_I
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
			"bwa3_puma",
			"bwa3_pzh2000"
		};

		skipWhenMissingDependencies=1;
	};
};


class CfgEditorSubcategories
{
	class RC_BW_subcat {displayname="Bundeswehr";};
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
	#include "\RC_BW\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_BW\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_BW\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_BW\cfgVehicles\Puma.hpp"
	#include "\RC_BW\cfgVehicles\PzH2000.hpp"
};