class CfgPatches
{
	class RC_Interceptor
	{
		name="Interceptor";
		author="Ascent";	//large credits to DarkBall for steering / HUD
		//url="";
		//requiredVersion=2.0799999;

		/*
		units[]=
		{
			"B_Interceptor_MP",
			"O_Interceptor_MP",
			"I_Interceptor_MP"
		};
		*/
		/*
		weapons[]=
		{
			"",
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


/*
//added automatically or manual?
class cfgMods
{
	author="Ascent";
	timepacked="code";
};
*/


class CfgFunctions
{
	class RC
	{
		class RC_Interceptor
		{
			file="\RC_Interceptor\functions";
			//class Interceptor_preInit 		{preInit=1;};
			class Interceptor_postInit 			{postInit=1;};
			class Interceptor_fired 			{};
			class Interceptor_createUAV_camera 	{};
			class Interceptor_createUAV_vehicle {};
			class Interceptor_waitUAVdestroy 	{};
			class Interceptor_createUI 			{};
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