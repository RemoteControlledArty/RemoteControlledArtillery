class CfgPatches
{
	class RC_82mmULM
	{
		name="advanced 82mm Mortar";
		author="Ascent";

		units[]=
		{
			"RC_82mm_ULM_Vic"
		};
		weapons[]=
		{
			"RC_82mm_ULM_Bag",
			"RC_82mm_ULM_Weapon"
		};
		magazines[]=
		{
			"RC_ULM_1Rnd_82mm_Mo_shells",
			"RC_ULM_1Rnd_82mm_Mo_HEAB",
			"RC_ULM_1Rnd_82mm_Mo_Smoke",

			"RC_ULM_1Rnd_82mm_Mo_MultiGuided",
			"RC_ULM_1Rnd_82mm_Mo_LaserGuided",
			"RC_ULM_1Rnd_82mm_Mo_LG_DelayedFuse",
			
			"RC_ULM_1Rnd_82mm_Mo_mine",
			"RC_ULM_1Rnd_82mm_Mo_AT_mine",
			"RC_ULM_1Rnd_82mm_Mo_Illum"
		};
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
	class RC_82mmULM
	{
		class functions
		{
			file="\RC_82mmULM\functions";
      		//class preInit {preInit=1;};
      		//class InitCBASettings {preInit=1;};
			class RC_UI_Loop_ULM {postInit=1;};
      		class init_82mm {postInit=1;};
			class deploy_82mm {};
			class setPosAGLS {};
			class fire_82mm {};
			class getout_82mm {};
			//class ui {};
			//class rangetable {};
		};
	};
};


/*
class Extended_PostInit_EventHandlers
{
	class RC_ULM
	{
		init="_this call RC_ULM_fnc_init";
	};
};
class Extended_GetOut_Eventhandlers
{
	class RC_82mm_ULM_Vic
	{
		class RC_ULM
		{
			getout="systemchat 'GetOutEH'; _this call RC_ULM_fnc_getout";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class RC_82mm_ULM_Vic
	{
		class RC_ULM
		{
			firedBIS="_this call RC_ULM_fnc_fire";
		};
	};
};
*/


//later required sensors
class SensorTemplateDataLink;
class SensorTemplateLaser;
class SensorTemplateIR;
class SensorTemplateNV;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplatePassiveRadar;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

//later required sensor firemodes
class Mode_SemiAuto;
class Mode_Burst;


//to prevent ace ballistics messing with the the calulated trajectory (only needed for manned assets)
class RscInGameUI
{
	class RscWeaponRangeArtillery;
	class Rsc_ULM: RscWeaponRangeArtillery {};
};


class CfgMagazines
{
	#include "\RC_82mmULM\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_82mmULM\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_82mmULM\cfgVehicles\82mm_ULM.hpp"
};