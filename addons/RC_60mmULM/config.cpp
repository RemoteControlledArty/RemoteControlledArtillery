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
			"RC_ULM_1Rnd_60mm_Mo_shells",
			"RC_ULM_1Rnd_60mm_Mo_HEAB",
			"RC_ULM_1Rnd_60mm_Mo_backupHEAB",
			"RC_ULM_1Rnd_60mm_Mo_Smoke",

			"RC_ULM_1Rnd_60mm_Mo_MultiGuided",
			"RC_ULM_1Rnd_60mm_Mo_LaserGuided",
			"RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse",
			
			"RC_ULM_1Rnd_60mm_Mo_mine",
			"RC_ULM_1Rnd_60mm_Mo_Illum"
		};
		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"twc_2inch",
			"NDS_M224_mortar"
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
			class RC_UI_Loop_ULM {postInit=1;};
      		class init {postInit=1;};
			//class ui {};
			class deploy {};
			class rangetable {};
			class fire {};
			class getout {};

			//ADD "HE - splash in 5sec", fired EH, mag speed, elev TOF for ASL, or fired setvalue on mortar if true UILoop starts scritpt and sets to false so it doesnt trigger twice
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
	class RC_60mm_ULM_Vic
	{
		class RC_ULM
		{
			getout="systemchat 'GetOutEH'; _this call RC_ULM_fnc_getout";
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


class RscInGameUI
{
	class RscWeaponRangeArtillery;
	class Rsc_ULM: RscWeaponRangeArtillery {};
};

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