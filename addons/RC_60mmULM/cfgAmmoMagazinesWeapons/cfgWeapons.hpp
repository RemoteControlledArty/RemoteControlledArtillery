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
class RC_60mm_ULM_Bag: twc_2inch_bag
{
	author="Ascent";
	displayname="60mm advanced Mortar";
	displayNameShort="60mm advanced Mortar";
	scope=2;
	scopeArsenal=2;
	magazineReloadTime=2.5;
	reloadTime=1.8;

	model="twc_2inch\twc_2inch_bag.p3d";
	picture="\twc_2inch\data\ui\w_2inch_ca.paa";
	UiPicture="\A3\Weapons_F\Data\UI\icon_at_CA.paa";
	handAnim[]={};

	magazines[]=
	{
		"RC_ULM_1Rnd_60mm_Mo_shells",
		"RC_ULM_1Rnd_60mm_Mo_HEAB",
		"RC_ULM_1Rnd_60mm_Mo_backupHEAB",
		"RC_ULM_1Rnd_60mm_Mo_Smoke",

		"RC_ULM_1Rnd_60mm_Mo_MultiGuided",
		"RC_ULM_1Rnd_60mm_Mo_LaserGuided",
		"RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse",
		//"RC_ULM_1Rnd_MP_NLOS_Nano",

		"RC_ULM_1Rnd_60mm_Mo_mine",
		"RC_ULM_1Rnd_60mm_Mo_Illum"
	};
	class weaponSlotsInfo: WeaponsSlotsInfo
	{
		mass=50;
	};
};
class RC_60mm_ULM_Bag_AutoCharge: RC_60mm_ULM_Bag
{
	displayname="60mm advanced Mortar (automatic charge)";
	displayNameShort="60mm advanced Mortar (automatic charge)";
};


class mortar_82mm_base;
class RC_60mm_ULM_Weapon_Core: mortar_82mm_base
{
	class Single1;
	class Single2;
	class Single3;
};
class RC_60mm_ULM_Weapon_Base: RC_60mm_ULM_Weapon_Core
{
	ballisticsComputer=0;	//8 is direct fire reticle for highest charge
	canLock=2;
	weaponLockDelay=0;
	magazineReloadTime=2.5;
	reloadTime=1.8;

	magazines[]=
	{
		"RC_ULM_1Rnd_60mm_Mo_shells",
		"RC_ULM_1Rnd_60mm_Mo_HEAB",
		"RC_ULM_1Rnd_60mm_Mo_backupHEAB",
		"RC_ULM_1Rnd_60mm_Mo_Smoke",

		"RC_ULM_1Rnd_60mm_Mo_MultiGuided",
		"RC_ULM_1Rnd_60mm_Mo_LaserGuided",
		"RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse",
		//"RC_ULM_1Rnd_MP_NLOS_Nano",
		
		"RC_ULM_1Rnd_60mm_Mo_mine",
		"RC_ULM_1Rnd_60mm_Mo_Illum"
	};
};
class RC_60mm_ULM_Weapon: RC_60mm_ULM_Weapon_Base
{
	displayname="60mm advanced Mortar";
	displayNameShort="60mm Mortar";

	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7",
		"Burst1",
		"Burst2",
		"Burst3"
		//"Cruise"
	};
	class Single1: Single1
	{
		displayName="CH0";
		artilleryDispersion=1;
		artilleryCharge=0.2295;
		/*
		minRange=51;
		midRange=393;
		maxRange=735;
		*/
	};
	class Single2: Single1
	{
		displayName="CH1";
		artilleryCharge=0.2933;
		/*
		minRange=72;
		midRange=557.5;
		maxRange=1043;
		*/
	};
	class Single3: Single1
	{
		displayName="CH2";
		artilleryCharge=0.3748;
		/*
		minRange=103;
		midRange=792.5;
		maxRange=1482;
		*/
	};
	class Single4: Single1
	{
		displayName="CH3";
		artilleryCharge=0.4791;
		/*
		minRange=142;
		midRange=1122;
		maxRange=2102;
		*/
	};
	class Single5: Single1
	{
		displayName="CH4";
		artilleryCharge=0.6122;
		/*
		minRange=208;
		midRange=1595;
		maxRange=2982;
		*/
	};
	class Single6: Single1
	{
		displayName="CH5";
		artilleryCharge=0.7825;
		/*
		minRange=295;
		midRange=2264;
		maxRange=4233;
		*/
	};
	class Single7: Single1
	{
		displayName="CH6";
		artilleryCharge=1;
		/*
		minRange=418;
		midRange=3209;
		maxRange=6000;
		*/
	};
	/*
	class Cruise: Single1
	{
		displayName="$STR_A3_firemode_terrain0";
		textureType="terrain";
		artilleryCharge=1.1;
		*/
		/*
		minRange=200;
		minRangeProbab=0.40000001;
		midRange=2000;
		midRangeProbab=0.89999998;
		maxRange=4000;
		maxRangeProbab=0.94999999;
		*/
		/*
	};
	*/
};
class RC_60mm_ULM_Weapon_AutoCharge: RC_60mm_ULM_Weapon_Base
{
	displayname="60mm advanced Mortar V2";
	displayNameShort="60mm Mortar";

	modes[]=
	{
		"800MIL",
		"1200MIL",
		"Burst1",
		"Burst2",
		"Burst3"
		//"Cruise"
	};
	class 800MIL: Single1
	{
		displayName="45°";
		artilleryDispersion=1;
		artilleryCharge=1;
		
		minRange=10;
		midRange=1750;
		maxRange=3500;
	};
	class 1200MIL: 800MIL
	{
		displayName="65.5°";
		artilleryDispersion=1;
		artilleryCharge=1;

		minRange=10;
		midRange=875;
		maxRange=1750;
	};
};