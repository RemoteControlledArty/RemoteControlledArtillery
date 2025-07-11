class CfgPatches
{
	class RC_60mmULM
	{
		name="advanced 60mm Mortar";
		author="Ascent";

		units[]=
		{
			"RC_60mm_ULM_Vic"
		};
		weapons[]=
		{
			"RC_60mm_ULM_Bag",
			"RC_60mm_ULM_Weapon"
		};
		magazines[]=
		{
			"RC_1Rnd_60mm_Mo_shells_ULM",
			"RC_1Rnd_60mm_Mo_HEAB_ULM",
			"RC_1Rnd_60mm_Mo_Flare_white_ULM",
			"RC_1Rnd_60mm_Mo_Smoke_white_ULM",
			"RC_1Rnd_60mm_Mo_LaserGuided_ULM",
			"RC_1Rnd_60mm_Mo_LaserGuided_ULM",
			"RC_1Rnd_60mm_Mo_MultiGuided_ULM",
			"RC_1Rnd_60mm_Mo_mine_ULM",
			"RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM",
			"RC_1Rnd_60mm_Mo_backupHEAB_ULM"
		};
		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"twc_2inch"
		};

		skipWhenMissingDependencies=1;
	};
};

class CfgFunctions
{
	class RC_ULM
	{
		class functions
		{
			file="\RC_60mmULM\functions";
      		//class preInit {preInit=1;};
      		//class InitCBASettings {preInit=1;};
      		//class RC_UI_Loop_ULM {postInit=1;};
			class ui {};
			class deploy {};
			class rangetable {};
			class fire {};
			class init {};
			class getout {};
		};
	};
};

class Extended_PostInit_EventHandlers
{
	class RC_ULM
	{
		init="_this call RC_ULM_fnc_init";
	};
};
class Extended_GetOut_Eventhandlers
{
	class RC_60mm_ULM_Vic
	{
		class RC_ULM
		{
			getout="_this call RC_ULM_fnc_getout";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class RC_60mm_ULM_Vic
	{
		class RC_ULM
		{
			firedBIS="_this call RC_ULM_fnc_fire";
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
class SensorTemplatePassiveRadar;

//later required sensor panels
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;


/*
class CfgAmmo
{
	#include "\RC_60mmULM\cfgAmmoMagazinesWeapons\cfgAmmo.hpp"
};
*/
class CfgMagazines
{
	#include "\RC_60mmULM\cfgAmmoMagazinesWeapons\cfgMagazines.hpp"
};
class CfgWeapons
{
	#include "\RC_60mmULM\cfgAmmoMagazinesWeapons\cfgWeapons.hpp"
};


class CfgVehicles
{
	#include "\RC_60mmULM\cfgVehicles\60mm_ULM.hpp"
};