class CfgPatches
{
	class RC_Interceptor
	{
		name="Interceptor";
		author="Ascent";
		//Major credit to DarkBall for the HUD and steering, i drastically rewrote most parts to suit interceptor drone functionality more.
		//I would have made a inheritance based mod requiring their to be loaded BUT their mod completely BUGS mortars, so that was not possible!

		/*
		//not yet in
		units[]=
		{
			"B_Interceptor_MP",
			"O_Interceptor_MP",
			"I_Interceptor_MP"
		};
		magazines[]=
		{
			"Interceptor_MP_Throw"
		};
		weapons[]=
		{
			""
		};
		*/

		requiredAddons[]=
		{
			//"A3_Data_F_AoW_Loadorder",
			//"A3_Data_F_Enoch_Loadorder",
			//"cba_main",

			"RC_Artillery",
			"RC_Crocus"
		};
		skipWhenMissingDependencies=1;
	};
};


class CfgFunctions
{
	class RC
	{
		class RC_Interceptor
		{
			file="\RC_Interceptor\functions";
			class Interceptor_define 			{postInit=1;};
			class Interceptor_firedEH 			{};
			class Interceptor_create			{};
			//class Interceptor_create_veh		{};
			class Interceptor_UI 				{};
		};
	};
};


#include "\RC_Interceptor\UI_RSC\UI_RSC.hpp"


class CfgAmmo
{
	#include "\RC_Interceptor\cfgAmmoMagazinesWeapons\Ammo.hpp"
};
class CfgMagazines
{
	#include "\RC_Interceptor\cfgAmmoMagazinesWeapons\Magazines.hpp"
};
class Mode_SemiAuto;
class CfgWeapons
{
	#include "\RC_Interceptor\cfgAmmoMagazinesWeapons\Weapons.hpp"
};
/*
class CfgVehicles
{
	#include "\RC_Interceptor\cfgVehicles\Interceptor.hpp"
};
*/