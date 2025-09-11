class CfgPatches
{
	class RC_AI
	{
		name="RC - Modernized AI Vehicles";
		author="Ascent";
		
		units[]=
		{
			"RC_AI_B_Pandur_A",
			"RC_AI_O_Pandur_A",
			"RC_AI_I_Pandur_A",

			"RC_AI_B_Pandur_WD",
			"RC_AI_O_Pandur_WD",
			"RC_AI_I_Pandur_WD",

			"RC_AI_B_M2A3_BUSKIII_D",
			"RC_AI_O_M2A3_BUSKIII_D",
			"RC_AI_I_M2A3_BUSKIII_D",

			"RC_AI_B_M2A3_BUSKIII_WD",
			"RC_AI_O_M2A3_BUSKIII_WD",
			"RC_AI_I_M2A3_BUSKIII_WD",

			"RC_AI_B_M1A2_SEPV2_D",
			"RC_AI_O_M1A2_SEPV2_D",
			"RC_AI_I_M1A2_SEPV2_D",

			"RC_AI_B_M1A2_SEPV2_WD",
			"RC_AI_O_M1A2_SEPV2_WD",
			"RC_AI_I_M1A2_SEPV2_WD"
		};

		weapons[]=
		{
			/*
			"",
			"",
			"",
			*/

			"RC_AI_autocannon_30mm_CTWS",
			"RC_AI_RHS_weap_m240_bradley_coax",
			"RC_AI_RHS_weap_M242BC",
			"RC_AI_RHS_weap_m256"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"RC_Aegis",
			"RC_RHS"
		};

		skipWhenMissingDependencies=1;
	};
};


/*
class CfgFunctions
{
	class RC
	{
		class RC_AI
		{
			file="\Remote_Controlled_Artillery\functions";

      		class preInit {preInit=1;};
      		class InitCBASettings {preInit=1;};
		
      		class RC_UI_Loop {postInit=1;};

			class RC_AT_Warning_Arrays {preInit=1;};
			class RC_AT_Warning {};

		};
	};
};
*/


class CfgFactionClasses
{
	class RC_AI_O
	{
		displayName="'RC - Modernized AI Vehicles'";
		side=0;
		flag="\a3\Data_f\Flags\flag_CSAT_co.paa";
		icon="\a3\Data_f\cfgFactionClasses_OPF_ca.paa";
		priority=0;
	};
	class RC_AI_B
	{
		displayName="'RC - Modernized AI Vehicles'";
		side=1;
		flag="\a3\Data_f\Flags\flag_nato_co.paa";
		icon="\a3\Data_f\cfgFactionClasses_BLU_ca.paa";
		priority=0;
	};
	class RC_AI_I
	{
		displayName="'RC - Modernized AI Vehicles'";
		side=2;
		flag="\a3\Data_f\Flags\flag_AAF_CO.paa";
		icon="\a3\Data_f\cfgFactionClasses_IND_ca.paa";
		priority=0;
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

//later required optics
class RCWSOptics;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


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


class CfgVehicles
{
	#include "\RC_AI\cfgVehicles\Crew.hpp"
	#include "\RC_AI\cfgVehicles\Pandur.hpp"
	#include "\RC_AI\cfgVehicles\Abrams.hpp"
	#include "\RC_AI\cfgVehicles\Bradley.hpp"
};