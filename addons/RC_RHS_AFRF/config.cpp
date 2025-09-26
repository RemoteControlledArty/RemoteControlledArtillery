class CfgPatches
{
	class RC_RHS_AFRF
	{
		name="Remote Controlled RHS AFRF";
		author="Ascent";
		//NOTE: This is just a cfg inheriting test, might delete soon or change sicnificantly

		units[]=
		{
			"rhs_pchela1t_vvs",
			"rhs_pchela1t_vvsc"
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
			"rhs_c_a2port_air"
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
};