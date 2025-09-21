class CfgPatches
{
	class RC_AI
	{
		name="RC - Modernized AI Vehicles";
		author="Ascent";
		
		units[]=
		{
			//visually neutral crew
			"RC_AI_B_Crew",
			"RC_AI_O_Crew",
			"RC_AI_I_Crew",

			//Basegame
			"RC_AI_B_Pandur_A",
			"RC_AI_O_Pandur_A",
			"RC_AI_I_Pandur_A",

			"RC_AI_B_Pandur_WD",
			"RC_AI_O_Pandur_WD",
			"RC_AI_I_Pandur_WD",

			"RC_AI_I_Pandur_DIG",
			
			"RC_AI_B_Patria40_A",
			"RC_AI_O_Patria40_A",
			"RC_AI_I_Patria40_A",

			"RC_AI_B_Patria40_WD",
			"RC_AI_O_Patria40_WD",
			"RC_AI_I_Patria40_WD",

			"RC_AI_B_Rooikat_A",
			"RC_AI_O_Rooikat0_A",
			"RC_AI_I_Rooikat_A",

			"RC_AI_B_Rooikat_WD",
			"RC_AI_O_Rooikat_WD",
			"RC_AI_I_Rooikat_WD",

			//WS Retex
			"RC_AI_B_BM2T_A",
			"RC_AI_O_BM2T_A",
			"RC_AI_I_BM2T_A",

			//Aegis
			"RC_AI_B_2S90M_A",
			"RC_AI_O_2S90M_A",
			"RC_AI_I_2S90M_A",

			"RC_AI_B_2S90M_WD",
			"RC_AI_O_2S90M_WD",
			"RC_AI_I_2S90M_WD",

			"RC_AI_B_BTR80A_A",
			"RC_AI_O_BTR80A_A",
			"RC_AI_I_BTR80A_A",

			"RC_AI_B_BTR80A_WD",
			"RC_AI_O_BTR80A_WD",
			"RC_AI_I_BTR80A_WD",

			//Aegis Retex
			"RC_AI_B_BM2T_WD",
			"RC_AI_O_BM2T_WD",
			"RC_AI_I_BM2T_WD",

			"RC_AI_B_T100_WD",
			"RC_AI_O_T100_WD",
			"RC_AI_I_T100_WD",

			"RC_AI_B_T14_WD",
			"RC_AI_O_T14_WD",
			"RC_AI_I_T14_WD",

			//AegisWS
			"RC_AI_B_BTR100_A",
			"RC_AI_O_BTR100_A",
			"RC_AI_I_BTR100_A",

			"RC_AI_B_BTR100_WD",
			"RC_AI_O_BTR100_WD",
			"RC_AI_I_BTR100_WD",

			//AbramsX
			"RC_AI_B_AbramsX_A",
			"RC_AI_O_AbramsX_A",
			"RC_AI_I_AbramsX_A",

			"RC_AI_B_AbramsX_WD",
			"RC_AI_O_AbramsX_WD",
			"RC_AI_I_AbramsX_WD",

			//RHS
			"RC_AI_B_M1127_M2Jav_D",
			"RC_AI_O_M1127_M2Jav_D",
			"RC_AI_I_M1127_M2Jav_D",

			"RC_AI_B_M2A3_M2Jav_WD",
			"RC_AI_O_M2A3_M2Jav_WD",
			"RC_AI_I_M2A3_M2Jav_WD",

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
			"RC_AI_autocannon_40mm_CTWS",
			"RC_AI_RHS_weap_m240_bradley_coax",
			"RC_AI_RHS_weap_M242BC",
			"RC_AI_RHS_weap_m256"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",

			"RC_WesternSahara",
			"RC_Aegis",
			"RC_AegisWS",
			"RC_RHS",
			"RC_AbramsX",

			"RC_Crocus",
			"RC_Crocus_A3TI",
			"RC_ilbe",
			"RC_60mmULM"/*,

			"A3U"*/
		};

		skipWhenMissingDependencies=1;
	};
};


class CfgFunctions
{
	class RC
	{
		class RC_AI
		{
			file="\RC_AI\functions";

			/*
      		class preInit {preInit=1;};
      		class InitCBASettings {preInit=1;};
		
      		class RC_UI_Loop {postInit=1;};

			class RC_AT_Warning_Arrays {preInit=1;};
			class RC_AT_Warning {};
			*/

			class RC_CommanderIsDriverGlobal_AI {};
			class RC_GunnerIsDriverGlobal_AI {};
			class RC_CommanderOrGunnerIsDriverGlobal_AI {};
			class RC_GunnerOrCommanderIsDriverGlobal_AI {};

			class RC_TakeControlCommanderServer_AI {};
			class RC_TakeControlGunnerServer_AI {};
		};
	};
};


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
	//Basegame
	#include "\RC_AI\cfgVehicles\Crew.hpp"
	#include "\RC_AI\cfgVehicles\Pandur.hpp"
	#include "\RC_AI\cfgVehicles\Patria.hpp"
	#include "\RC_AI\cfgVehicles\Rooikat.hpp"

	//WS Retex
	#include "\RC_AI\cfgVehicles\BM_2T_A.hpp"

	//Aegis
	#include "\RC_AI\cfgVehicles\BTR_80A.hpp"
	#include "\RC_AI\cfgVehicles\2S90M.hpp"

	//Aegis Retex
	#include "\RC_AI\cfgVehicles\BM_2T_WD.hpp"
	#include "\RC_AI\cfgVehicles\T_100.hpp"
	#include "\RC_AI\cfgVehicles\T_14.hpp"

	//AegisWS
	#include "\RC_AI\cfgVehicles\BTR_100.hpp"

	//AbramsX
	#include "\RC_AI\cfgVehicles\AbramsX.hpp"
	
	//RHS
	#include "\RC_AI\cfgVehicles\Stryker.hpp"
	#include "\RC_AI\cfgVehicles\Bradley.hpp"
	#include "\RC_AI\cfgVehicles\Abrams.hpp"
};