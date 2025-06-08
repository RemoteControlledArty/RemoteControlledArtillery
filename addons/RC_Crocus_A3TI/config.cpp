class CfgPatches
{
	class RC_Crocus_A3TI
	{
		name="improved Crocus FPV with A3TI";
		author="Ascent";

		units[]=
		{
			B_Crocus_MP_TI,
			O_Crocus_MP_TI,
			I_Crocus_MP_TI,

			B_Crocus_MP_TI_Sens,
			O_Crocus_MP_TI_Sens,
			I_Crocus_MP_TI_Sens,

			B_Crocus_MP_TI_Bag,
			O_Crocus_MP_TI_Bag,
			I_Crocus_MP_TI_Bag,

			B_Crocus_MP_TI_Sens_Bag,
			O_Crocus_MP_TI_Sens_Bag,
			I_Crocus_MP_TI_Sens_Bag,

			RC_Crocus_Mothership,
			RC_Crocus_Mothership_O,
			RC_Crocus_Mothership_I
		};

		requiredAddons[]=
		{
			"cba_main",
			"ArmaFPV_Data",
			"RC_Artillery",
			"A3TI"
		};

		skipWhenMissingDependencies=1;
	};
};

//later required sensors
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateDataLink;

class CfgVehicles
{
	#include "\RC_Crocus_A3TI\cfgVehicles\CrocusMP_TI.hpp"
	#include "\RC_Crocus_A3TI\cfgVehicles\Crocus_Mothership.hpp"
};