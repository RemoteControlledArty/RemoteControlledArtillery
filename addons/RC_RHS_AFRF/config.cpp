class CfgPatches
{
	class RC_RHS_AFRF
	{
		name="Remote Controlled RHS AFRF";
		author="Ascent";

		units[]=
		{
			"rhs_pchela1t_vvs",
			"rhs_pchela1t_vvsc",

			"RC_T90AM_WD",
			"RC_T90AM_WD_O",
			"RC_T90AM_WD_I",
			"RC_T90AM_A",
			"RC_T90AM_A_O",
			"RC_T90AM_A_I"
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
			"rhs_c_a2port_air",
			"rhs_c_t72"
		};

		skipWhenMissingDependencies=1;
	};
};


/*
class CfgFunctions
{
	class RC
	{
		class RC_RHS_AFRF
		{
		};
	};
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
//class RCWSOptics;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

/*
class RscInGameUI
{
	#include "\RC_RHS_AFRF\includes_cfg\T90HUD.hpp"
};
*/

/*
class CfgAmmo
{
	#include "\RC_RHS_AFRF\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_RHS_AFRF\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_RHS_AFRF\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};
*/

class CfgVehicles
{
	#include "\RC_RHS_AFRF\cfgVehicles\Pchela1T.hpp"
	#include "\RC_RHS_AFRF\cfgVehicles\T90AM.hpp"
	//#include "\RC_RHS_AFRF\cfgVehicles\T90SA.hpp"
};