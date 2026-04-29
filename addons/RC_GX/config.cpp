class CfgPatches
{
	class RC_GX
	{
		name="RC GX";
		author="Ascent";

		units[]=
		{
			"RC_FW_LM_MP_B",
			"RC_FW_LM_MP_O",
			"RC_FW_LM_MP_I"
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
			"RC_Crocus",
			"GX_DRONES_UAV_RQ11B"
		};

		skipWhenMissingDependencies=1;
	};
};

//later required sensors
class SensorTemplateDataLink;
class SensorTemplateLaser;
class SensorTemplateIR;
class SensorTemplateNV;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateActiveRadar;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


/*
class CfgWeapons
{
	#include "\RC_GX\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};
*/


class CfgVehicles
{
	#include "\RC_GX\cfgVehicles\FW_LM.hpp"
};