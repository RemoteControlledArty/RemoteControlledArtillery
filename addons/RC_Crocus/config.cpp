class CfgPatches
{
	class RC_Crocus
	{
		name="improved Crocus FPV";
		author="Ascent";

		units[]=
		{
			//RC_Crocus_MP,
			//RC_Crocus_MP_O,
			//RC_Crocus_MP_I,

			B_Crocus_AT,
			O_Crocus_AT,
			I_Crocus_AT,

			Crocus_MP_Bag,
			Crocus_MP_Bag_O,
			Crocus_MP_Bag_I,

			RC_CrocusRepeater,
			RC_CrocusRepeater_O,
			RC_CrocusRepeater_I
		};
		
		/*
		weapons[]=
		{
			"RC_Crocus_MP_Warhead",
			"RC_"
		};
		*/

		requiredAddons[]=
		{
			"cba_main",
			"ArmaFPV_Data",
			"RC_Artillery"
		};

		skipWhenMissingDependencies=1;
	};
};


//later required sensors
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};


#include "\RC_Crocus\cfgVehicles\CrocusFetch.hpp"
#include "\RC_Crocus\cfgAmmoMagazinesWeapons\cfgAmmoMagazinesWeapons.hpp"


class CfgVehicles
{
	#include "\RC_Crocus\cfgVehicles\CrocusBase.hpp"
	#include "\RC_Crocus\cfgVehicles\CrocusMP.hpp"
};