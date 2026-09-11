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
			"RC_eVTOL_C",

			"RC_eVTOL_TI_B",
			"RC_eVTOL_TI_O",
			"RC_eVTOL_TI_I",
			"RC_eVTOL_TI_C",

			"RC_eVTOL_Minigun_TI_B",
			"RC_eVTOL_Minigun_TI_O",
			"RC_eVTOL_Minigun_TI_I",

			"RC_MosquitoMothership_B",
			"RC_MosquitoMothership_O",
			"RC_MosquitoMothership_I",

			"RC_MosquitoMothership_Minigun_B",
			"RC_MosquitoMothership_Minigun_O",
			"RC_MosquitoMothership_Minigun_I",

			"RC_MosquitoMothership_NoCam_B",
			"RC_MosquitoMothership_NoCam_O",
			"RC_MosquitoMothership_NoCam_I",

			"RC_MosquitoMothership_NoCam_Minigun_B",
			"RC_MosquitoMothership_NoCam_Minigun_O",
			"RC_MosquitoMothership_NoCam_Minigun_I",

			/*
			"RC_eVTOL_Zoom_B",
			"RC_eVTOL_Zoom_O",
			"RC_eVTOL_Zoom_I",
			"RC_eVTOL_Zoom_C",

			"RC_eVTOL_ZoomTI_B",
			"RC_eVTOL_ZoomTI_O",
			"RC_eVTOL_ZoomTI_I",
			"RC_eVTOL_ZoomTI_C"
			*/
		};
		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"rhsusf_c_airweapons",	//for M134 minigun model
			"RC_RHS",
			"gyg_jetson"			//all credits to the Jetson eVTOL creator!
		};

		skipWhenMissingDependencies=1;	//soft dependency
	};
};


class CfgFunctions
{
	class RC
	{
		class RC_eVTOL
		{
			file="\RC_eVTOL\functions";

      		//class preInit {preInit=1;};
			//class postInit {postInit=1;};
      		//class InitCBASettings {preInit=1;};

			//class RC_EngineOff {postInit=1;};
			//class RC_attachToMotherShip {preInit=1;};
			class RC_eVTOL_define {preInit=1;};
		};
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


class CfgAmmo
{
	#include "\RC_eVTOL\cfgAmmoMagazinesWeapons\Ammo.hpp"
};
class CfgMagazines
{
	#include "\RC_eVTOL\cfgAmmoMagazinesWeapons\Magazines.hpp"
};
class CfgWeapons
{
	#include "\RC_eVTOL\cfgAmmoMagazinesWeapons\Weapons.hpp"
};
class CfgVehicles
{
	#include "\RC_eVTOL\cfgVehicles\eVTOL.hpp"
	#include "\RC_eVTOL\cfgVehicles\Mothership.hpp"
};