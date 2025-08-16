class CfgPatches
{
	class RC_Crocus_A3TI
	{
		name="improved Crocus FPV with A3TI";
		author="Ascent";

		units[]=
		{
			"B_Crocus_MP_TI",
			"O_Crocus_MP_TI",
			"I_Crocus_MP_TI",

			"B_Crocus_MP_TI_Sens",
			"O_Crocus_MP_TI_Sens",
			"I_Crocus_MP_TI_Sens",

			"B_Crocus_PvP",
			"O_Crocus_PvP",
			"I_Crocus_PvP",

			"B_Crocus_Training",
			"O_Crocus_Training",
			"I_Crocus_Training",

			"B_Crocus_MP_TI_Bag",
			"O_Crocus_MP_TI_Bag",
			"I_Crocus_MP_TI_Bag",

			"B_Crocus_MP_TI_Sens_Bag",
			"O_Crocus_MP_TI_Sens_Bag",
			"I_Crocus_MP_TI_Sens_Bag",

			"B_Crocus_PvP_Bag",
			"O_Crocus_PvP_Bag",
			"I_Crocus_PvP_Bag",

			"B_Crocus_Training_Bag",
			"O_Crocus_Training_Bag",
			"I_Crocus_Training_Bag",

			"RC_Crocus_Mothership",
			"RC_Crocus_Mothership_O",
			"RC_Crocus_Mothership_I",

			"RC_Crocus_Mothership_NoCam",
			"RC_Crocus_Mothership_NoCam_O",
			"RC_Crocus_Mothership_NoCam_I",

			"RC_Crocus_MothershipMQ",
			"RC_Crocus_MothershipMQ_O",
			"RC_Crocus_MothershipMQ_I",

			"RC_Crocus_MothershipMQ_NoCam",
			"RC_Crocus_MothershipMQ_NoCam_O",
			"RC_Crocus_MothershipMQ_NoCam_I",

			"RC_Crocus_Carrier_A",
			"RC_Crocus_Carrier_A_O",
			"RC_Crocus_Carrier_A_I",
			"RC_Crocus_Carrier_WD",
			"RC_Crocus_Carrier_WD_O",
			"RC_Crocus_Carrier_WD_I",

			"RC_Crocus_Truck_A",
			"RC_Crocus_Truck_A_O",
			"RC_Crocus_Truck_A_I",
			"RC_Crocus_Truck_WD",
			"RC_Crocus_Truck_WD_O",
			"RC_Crocus_Truck_WD_I",

			"RC_Crocus_Truck_manned_A",
			"RC_Crocus_Truck_manned_A_O",
			"RC_Crocus_Truck_manned_A_I",
			"RC_Crocus_Truck_manned_WD",
			"RC_Crocus_Truck_manned_WD_O",
			"RC_Crocus_Truck_manned_WD_I"
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
	#include "\RC_Crocus_A3TI\cfgVehicles\CrocusPvP.hpp"
	#include "\RC_Crocus_A3TI\cfgVehicles\CrocusTraining.hpp"
	#include "\RC_Crocus_A3TI\cfgVehicles\Crocus_Carrier.hpp"
	#include "\RC_Crocus_A3TI\cfgVehicles\Crocus_Mothership.hpp"
	#include "\RC_Crocus_A3TI\cfgVehicles\Crocus_Truck.hpp"
};