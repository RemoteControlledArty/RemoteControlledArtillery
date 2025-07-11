class Launcher;
class Launcher_Base_F: Launcher
{
	class WeaponsSlotsInfo;
};
class twc_2inch_bag: Launcher_Base_F
{
	author="LeoVetta";
	scope=2;
	displayname="60mm Mortar";
	model="twc_2inch\twc_2inch_bag.p3d";
	picture="\twc_2inch\data\ui\w_2inch_ca.paa";
	UiPicture="\A3\Weapons_F\Data\UI\icon_at_CA.paa";
	magazines[]=
	{
		"twc_2inch_he_1rnd",
		"twc_2inch_smoke_1rnd",
		"twc_2inch_illum_1rnd",
		"RC_1Rnd_60mm_Mo_shells_ULM",
		"RC_1Rnd_60mm_Mo_HEAB_ULM",
		"RC_1Rnd_60mm_Mo_Flare_white_ULM",
		"RC_1Rnd_60mm_Mo_Smoke_white_ULM",
		"RC_1Rnd_60mm_Mo_LaserGuided_ULM",
		"RC_1Rnd_60mm_Mo_MultiGuided_ULM",
		"RC_1Rnd_60mm_Mo_mine_ULM",
		"RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM",
		"RC_1Rnd_60mm_Mo_backupHEAB_ULM"
	};
	handAnim[]={};
	class weaponSlotsInfo: WeaponsSlotsInfo
	{
		mass=50;
	};
};


class RC_60mm_ULM_Bag_Base: twc_2inch_bag
{
	class WeaponsSlotsInfo;
	scope=0;
};
class RC_60mm_ULM_Bag: RC_60mm_ULM_Bag_Base
{
	author="Ascent";
	scope=2;
	displayname="advanced 60mm Mortar";
	handAnim[]={};
	magazines[]=
	{
		"RC_1Rnd_60mm_Mo_shells_ULM",
		"RC_1Rnd_60mm_Mo_HEAB_ULM",
		"RC_1Rnd_60mm_Mo_Flare_white_ULM",
		"RC_1Rnd_60mm_Mo_Smoke_white_ULM",
		"RC_1Rnd_60mm_Mo_LaserGuided_ULM",
		"RC_1Rnd_60mm_Mo_MultiGuided_ULM",
		"RC_1Rnd_60mm_Mo_mine_ULM",
		"RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM",
		"RC_1Rnd_60mm_Mo_backupHEAB_ULM"
	};
	class weaponSlotsInfo: WeaponsSlotsInfo
	{
		mass=50;
	};
};


class twc_2inch_weapon;
class RC_60mm_ULM_Weapon_Base: twc_2inch_weapon
{
	class Single1;
	class Single2;
	class Single3;
};
class RC_60mm_ULM_Weapon: RC_60mm_ULM_Weapon_Base
{
	displayname="advanced 60mm Mortar";
	//ballisticsComputer=8;
	initSpeed=242.58;	//???
	magazineReloadTime=1.6;
	reloadTime=1.6;

	magazines[]=
	{
		"twc_2inch_he_1rnd",
		"twc_2inch_smoke_1rnd",
		"twc_2inch_illum_1rnd",

		"RC_1Rnd_60mm_Mo_shells_ULM",
		"RC_1Rnd_60mm_Mo_HEAB_ULM",
		"RC_1Rnd_60mm_Mo_Flare_white_ULM",
		"RC_1Rnd_60mm_Mo_Smoke_white_ULM",
		"RC_1Rnd_60mm_Mo_LaserGuided_ULM",
		"RC_1Rnd_60mm_Mo_MultiGuided_ULM",
		"RC_1Rnd_60mm_Mo_mine_ULM",
		"RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM",
		"RC_1Rnd_60mm_Mo_backupHEAB_ULM"
	};
	class Single1: Single1
	{
		burst=1;
		reloadTime=1.6;
		artilleryDispersion=1.25;

		displayname="CH0, 0.5km";
		artilleryCharge=0.35;

		minRange=34;
		midRange=216.5;
		maxRange=499;
	};
	class Single2: Single1
	{
		displayname="CH1, 2km";
		artilleryCharge=0.7;

		minRange=139;
		midRange=1068.5;
		maxRange=1998;
	};
	class Single3: Single1
	{
		displayname="CH2, 4km";
		artilleryCharge=1;

		minRange=284;
		midRange=2181;
		maxRange=4078;
	};
};


/*
class RC_mortar_82mm_V3;
class RC_60mm_ULM_Weapon_Base: RC_mortar_82mm_V3
{
	class Single1;
	class Single2;
	class Single3;
};
class RC_60mm_ULM_Weapon: RC_60mm_ULM_Weapon_Base
{
	displayname="advanced 60mm Mortar";
	ballisticsComputer=8;
	initSpeed=242.58;	//???

	displayName="60mm Mortar";
	displayNameShort="60mm Mortar";
	ballisticsComputer=8;	//direct fire reticle for highest charge
	magazineReloadTime=1.6;
	reloadTime=1.6;

	magazines[]=
	{
		"twc_2inch_he_1rnd",
		"twc_2inch_smoke_1rnd",
		"twc_2inch_illum_1rnd",

		"RC_1Rnd_60mm_Mo_shells_ULM",
		"RC_1Rnd_60mm_Mo_HEAB_ULM",
		"RC_1Rnd_60mm_Mo_Flare_white_ULM",
		"RC_1Rnd_60mm_Mo_Smoke_white_ULM",
		"RC_1Rnd_60mm_Mo_LaserGuided_ULM",
		"RC_1Rnd_60mm_Mo_MultiGuided_ULM",
		"RC_1Rnd_60mm_Mo_mine_ULM",
		"RC_1Rnd_60mm_Mo_LG_DelayedFuse_ULM",
		"RC_1Rnd_60mm_Mo_backupHEAB_ULM"
	};
	class Single1: Single1
	{
		burst=1;
		reloadTime=1.6;
		artilleryDispersion=1.25;

		displayname="CH0, 0.5km";
		artilleryCharge=0.35;

		minRange=34;
		midRange=216.5;
		maxRange=499;
	};
	class Single2: Single1
	{
		displayname="CH1, 2km";
		artilleryCharge=0.7;

		minRange=139;
		midRange=1068.5;
		maxRange=1998;
	};
	class Single3: Single1
	{
		displayname="CH2, 4km";
		artilleryCharge=1;

		minRange=284;
		midRange=2181;
		maxRange=4078;
	};
};
*/