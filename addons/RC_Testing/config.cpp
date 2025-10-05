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

			"RC_Test_B_Pandur_Agent",
			"RC_Test_B_Pandur_AgentDelayed",
			"RC_Test_B_Pandur_UGV",
			"RC_Test_B_Pandur_UGVDelayed"


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
			"RC_Artillery",
			"experimental_stamina"			//only used because its loaded on our server and likely not others, so testing pbo isnt loaded for most, creating less errors
		};

		skipWhenMissingDependencies=1;
	};
};


class CfgFunctions
{
	class RC
	{
		class RC_Test_Agent
		{
			file="\RC_Testing\functions\Agent";

			class RC_Test_Agent_GunnerOrCommanderIsDriverGlobal {};

			class RC_Test_Agent_TakeControlCommanderServer {};
			class RC_Test_Agent_TakeControlGunnerServer {};
		};
		class RC_Test_AgentDelayed
		{
			file="\RC_Testing\functions\AgentDelayed";

			class RC_Test_AgentDelayed_GunnerOrCommanderIsDriverGlobal {};

			class RC_Test_AgentDelayed_TakeControlCommanderServer {};
			class RC_Test_AgentDelayed_TakeControlGunnerServer {};
		};
		class RC_Test_AgentDelete
		{
			file="\RC_Testing\functions\AgentDelete";

			class RC_Test_AgentDelete_GunnerOrCommanderIsDriverGlobal {};

			class RC_Test_AgentDelete_TakeControlCommanderServer {};
			class RC_Test_AgentDelete_TakeControlGunnerServer {};
		};
		class RC_Test_UGV
		{
			file="\RC_Testing\functions\UGV";

			class RC_Test_UGV_GunnerOrCommanderIsDriverGlobal {};

			class RC_Test_UGV_TakeControlCommanderServer {};
			class RC_Test_UGV_TakeControlGunnerServer {};
		};
		class RC_Test_UGVDelayed
		{
			file="\RC_Testing\functions\UGVDelayed";

			class RC_Test_UGVDelayed_GunnerOrCommanderIsDriverGlobal {};

			class RC_Test_UGVDelayed_TakeControlCommanderServer {};
			class RC_Test_UGVDelayed_TakeControlGunnerServer {};
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
	#include "\RC_Testing\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
class CfgMagazines
{
	#include "\RC_Testing\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_Testing\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};
*/


class CfgVehicles
{
	#include "\RC_Testing\cfgVehicles\Crew.hpp"
	#include "\RC_Testing\cfgVehicles\Pandur.hpp"
	//#include "\RC_Testing\cfgVehicles\Rooikat.hpp"
};