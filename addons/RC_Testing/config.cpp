class CfgPatches
{
	class RC_Testing
	{
		name="RC - Testing";
		author="Ascent";
		
		units[]=
		{
			//[getPos player, 180, "RC_AI_I_Pandur_WD", resistance] call BIS_fnc_spawnVehicle;
			"RC_Test_B_Crew",
			"RC_Test_O_Crew",
			"RC_Test_I_Crew",

			"RC_Test_B_Crew_Agent",
			"RC_Test_O_Crew_Agent",
			"RC_Test_I_Crew_Agent",

			"RC_Test_B_Pandur_A"

			/*
			"RC_Test_O_Pandur_A",
			"RC_Test_I_Pandur_A"
			*/

			/*
			"RC_AI_B_Rooikat_A",
			"RC_AI_O_Rooikat0_A",
			"RC_AI_I_Rooikat_A",
			*/
		};

		/*
		weapons[]=
		{
			"",
			""
		};
		*/

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery"
		};

		skipWhenMissingDependencies=1;
	};
};


class CfgFunctions
{
	class RC
	{
		class RC_Testing
		{
			file="\RC_Testing\functions";

			class RC_CommanderIsDriverGlobal_Test {};
			class RC_GunnerIsDriverGlobal_Test {};
			class RC_CommanderOrGunnerIsDriverGlobal_Test {};
			class RC_GunnerOrCommanderIsDriverGlobal_Test {};

			class RC_TakeControlCommanderServer_Test {};
			class RC_TakeControlGunnerServer_Test {};
		};
	};
};


class CfgEditorSubcategories
{
	class RC_Testing_subcat {displayname="Test";};
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

//later required optics
class RCWSOptics;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


/*
class CfgAmmo
{
	#include "\RC_AI\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_AI\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_AI\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};
*/


class CfgVehicles
{
	#include "\RC_AI\cfgVehicles\Crew.hpp"
	#include "\RC_AI\cfgVehicles\Pandur.hpp"
	//#include "\RC_AI\cfgVehicles\Rooikat.hpp"
};