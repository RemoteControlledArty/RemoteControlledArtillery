class CfgPatches
{
	class RC_eVTOL
	{
		name="RC eVTOL";
		author="Ascent";

		units[]=
		{
			"RC_eVTOL_B",
			"RC_eVTOL_O",
			"RC_eVTOL_I",
			"RC_eVTOL_C"
		};
		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"gyg_jetson"		//all credits to the Jetson eVTOL creator!
		};

		skipWhenMissingDependencies=1;	//soft dependency
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


class CfgVehicles
{
	#include "\RC_eVTOL\cfgVehicles\eVTOL.hpp"
};