class Launcher;
class Launcher_Base_F: Launcher
{
	class WeaponsSlotsInfo;
};
class twc_2inch_bag: Launcher_Base_F
{
	scope=1;
	scopeCurator=1;
	scopeArsenal=1;
	author="LeoVetta";
	displayname="60mm COMMANDO Mortar";
	model="twc_2inch\twc_2inch_bag.p3d";
	picture="\twc_2inch\data\ui\w_2inch_ca.paa";
	UiPicture="\A3\Weapons_F\Data\UI\icon_at_CA.paa";
	magazines[]={};
	handAnim[]={};
	class weaponSlotsInfo: WeaponsSlotsInfo
	{
		mass=50;
	};
};
/*
class twc_2inch_bag;
class RC_60mm_ULM_Bag_Base: twc_2inch_bag
{
	class WeaponsSlotsInfo;
	scope=0;
	scopeArsenal=0;
};
*/
class RC_82mm_ULM_Bag_Base: twc_2inch_bag
{
	author="Ascent";
	magazineReloadTime=2.5;
	reloadTime=1.8;

	model="twc_2inch\twc_2inch_bag.p3d";
	picture="\twc_2inch\data\ui\w_2inch_ca.paa";
	UiPicture="\A3\Weapons_F\Data\UI\icon_at_CA.paa";
	handAnim[]={};

	magazines[]=
	{
		"RC_ULM_1Rnd_82mm_Mo_shells",
		"RC_ULM_1Rnd_82mm_Mo_HEAB",
		"RC_ULM_1Rnd_82mm_Mo_Smoke",

		"RC_ULM_1Rnd_82mm_Mo_MultiGuided",
		"RC_ULM_1Rnd_82mm_Mo_LaserGuided",
		"RC_ULM_1Rnd_82mm_Mo_LG_DelayedFuse",
		//"RC_ULM_1Rnd_82mm_Mo_MP_NLOS_Nano",

		"RC_ULM_1Rnd_82mm_Mo_mine",
		"RC_ULM_1Rnd_82mm_Mo_AT_mine",
		"RC_ULM_1Rnd_82mm_Mo_Illum"
	};
	class weaponSlotsInfo: WeaponsSlotsInfo
	{
		mass=70;
	};
};
class RC_82mm_ULM_Bag: RC_82mm_ULM_Bag_Base
{
	displayname="82mm advanced Mortar";
	displayNameShort="82mm advanced Mortar";
	scope=2;
	scopeArsenal=2;
};


class RC_mortar_82mm_V3;
class RC_82mm_ULM_Weapon_Core: RC_mortar_82mm_V3
{
	class Single1;
};
class RC_82mm_ULM_Weapon_Base: RC_82mm_ULM_Weapon_Core
{
	ballisticsComputer=0;	//8 is direct fire reticle for highest charge
	canLock=2;
	weaponLockDelay=0;
	magazineReloadTime=2.2;
	reloadTime=1.8;

	magazines[]=
	{
		"RC_ULM_1Rnd_82mm_Mo_shells",
		"RC_ULM_1Rnd_82mm_Mo_HEAB",
		"RC_ULM_1Rnd_82mm_Mo_Smoke",

		"RC_ULM_1Rnd_82mm_Mo_MultiGuided",
		"RC_ULM_1Rnd_82mm_Mo_LaserGuided",
		"RC_ULM_1Rnd_82mm_Mo_LG_DelayedFuse",
		//"RC_ULM_1Rnd_82mm_Mo_MP_NLOS_Nano",

		"RC_ULM_1Rnd_82mm_Mo_mine",
		"RC_ULM_1Rnd_82mm_Mo_AT_mine",
		"RC_ULM_1Rnd_82mm_Mo_Illum"
	};
};
class RC_82mm_ULM_Weapon: RC_82mm_ULM_Weapon_Base
{
	displayname="82mm advanced Mortar";
	displayNameShort="82mm Mortar";

	modes[]=
	{
		"Single1",
		"Burst1",
		"Burst2",
		"Burst3"
		//"Cruise"
	};
	class Single1: Single1
	{
		displayName="adjusted";
		artilleryDispersion=1;	//no effect, dispersion applied by script
		artilleryCharge=1;		//velocity applied per script
		
		minRange=10;
		midRange=2000;
		maxRange=4000;
	};
	/*
	class Cruise: Single1
	{
		displayName="$STR_A3_firemode_terrain0";
		textureType="terrain";
		artilleryCharge=1;	//1.1
	};
	*/
};