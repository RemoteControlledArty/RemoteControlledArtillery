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


/*
class CannonCore;
class mortar_82mm: CannonCore
{
	class Single1;
	class Single2;
	class Single3;
};
class twc_2inch_weapon: mortar_82mm
{
	displayname="60mm COMMANDO Mortar";
	ballisticsComputer=0;
	magazines[]=
	{
		"twc_2inch_he_1rnd",
		"twc_2inch_smoke_1rnd",
		"twc_2inch_illum_1rnd"
	};
	initSpeed=80;
	class Single1: Single1
	{
		displayname="";
		artilleryCharge=1;
	};
	class Single2: Single2
	{
		showToPlayer=0;
	};
	class Single3: Single3
	{
		showToPlayer=0;
	};
};
*/


/*
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
	ballisticsComputer=8;	//TEST WITHOUT
	initSpeed=242.58;	//???
	magazineReloadTime=3;
	reloadTime=1.8;

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
		reloadTime=1.8;
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


class RC_mortar_82mm_V3;
class RC_60mm_ULM_Weapon_Base: RC_mortar_82mm_V3
{
	class Single1;
	class Single2;
	class Single3;
};
class RC_60mm_ULM_Weapon: RC_60mm_ULM_Weapon_Base
{
	//initSpeed=242.58;	//???

	displayname="advanced 60mm Mortar";
	displayNameShort="60mm Mortar";
	ballisticsComputer=0;	//direct fire reticle for highest charge
	magazineReloadTime=3;
	reloadTime=1.8;

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
		reloadTime=1.8;
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


class CannonCore;
class M_Base: CannonCore
{
	scope=1;
	displayname="M";
	nameSound="CannonCore";
	cursor="mortar";
	cursorAim="EmptyCursor";
	sounds[]=
	{
		"StandardSound"
	};
	class StandardSound
	{
		begin1[]=
		{
			"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_01",
			1.2589254,
			1,
			250
		};
		begin2[]=
		{
			"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_02",
			1.2589254,
			1,
			250
		};
		soundBegin[]=
		{
			"begin1",
			0.5,
			"begin2",
			0.5
		};
	};
	reloadSound[]=
	{
		"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",
		1,
		1,
		20
	};
	reloadMagazineSound[]=
	{
		"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_magazine_Mortar",
		1,
		1,
		20
	};
	soundServo[]=
	{
		"",
		9.9999997e-005,
		1
	};
	reloadTime=1.8;
	magazineReloadTime=5;
	autoReload=1;
	canLock=0;
	magazines[]=
	{
		"RC_10Rnd_82mm_Mo_shells",
		"RC_10Rnd_R_HEAB"
	};
	ballisticsComputer=2;
	class GunParticles
	{
		class FirstEffect
		{
			effectName="MortarFired";
			positionName="Usti Hlavne";
			directionName="Konec Hlavne";
		};
	};
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Burst1",
		"Burst2",
		"Burst3"
	};
	class Single1: Mode_SemiAuto
	{
		displayName="M";
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_01",
				1.2589254,
				1,
				250
			};
			begin2[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_02",
				1.2589254,
				1,
				250
			};
			soundBegin[]=
			{
				"begin1",
				0.5,
				"begin2",
				0.5
			};
		};
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",
			1,
			1,
			20
		};
		reloadTime=1.8;
		artilleryDispersion=1.9;
		artilleryCharge=0.34999999;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
		minRange=0;
		minRangeProbab=0.0099999998;
		midRange=1;
		midRangeProbab=0.0099999998;
		maxRange=2;
		maxRangeProbab=0.0099999998;
	};
	class Single2: Single1
	{
		displayName="M";
		artilleryCharge=0.69999999;
	};
	class Single3: Single1
	{
		displayName="M";
		artilleryCharge=1;
	};
	class Burst1: Mode_Burst
	{
		showToPlayer=0;
		displayName="M";
		burst=4;
		aiBurstTerminable=1;
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_01",
				1.2589254,
				1,
				250
			};
			begin2[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_02",
				1.2589254,
				1,
				250
			};
			soundBegin[]=
			{
				"begin1",
				0.5,
				"begin2",
				0.5
			};
		};
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",
			1,
			1,
			20
		};
		soundServo[]=
		{
			"",
			9.9999997e-005,
			1
		};
		soundBurst=0;
		reloadTime=1.8;
		artilleryDispersion=2.2;
		artilleryCharge=0.34999999;
		minRange=60;
		minRangeProbab=0.5;
		midRange=290;
		midRangeProbab=0.69999999;
		maxRange=665;
		maxRangeProbab=0.5;
	};
	class Burst2: Burst1
	{
		showToPlayer=0;
		displayName="M";
		artilleryCharge=0.69999999;
		minRange=230;
		minRangeProbab=0.40000001;
		midRange=1175;
		midRangeProbab=0.60000002;
		maxRange=2660;
		maxRangeProbab=0.40000001;
	};
	class Burst3: Burst1
	{
		showToPlayer=0;
		displayName="M";
		artilleryCharge=1;
		minRange=540;
		minRangeProbab=0.30000001;
		midRange=2355;
		midRangeProbab=0.40000001;
		maxRange=5500;
		maxRangeProbab=0.30000001;
	};
};
class RC_M_V1: M_Base
{
	magazines[]=
	{
		"RC_10Rnd_82mm_Mo_shells",
		"RC_10Rnd_R_HEAB"
	};
};
class RC_M_V2: RC_M_V1
{
	reloadTime=1.8;
	magazineReloadTime=2.2;
	canLock=2;
	weaponLockDelay=0;
};
class RC_M_V3: RC_M_V2
{
	scope=2;

	modes[]=
	{
		"Single1",
		"Single2",
		"Single3"
	};
	/*
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Burst1",
		"Burst2",
		"Burst3"
	};
	*/
	class Single1: Single1
	{
		displayName="CH0, 0.5km";
		artilleryDispersion=1.25;
		artilleryCharge=0.35;
		minRange=34;	//34	//60
		midRange=216.5;	//216.5	//290
		maxRange=499;	//499	//665
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
		aiDispersionCoefX=1;
		aiDispersionCoefY=1;
		//aiRateOfFireDispersion=1;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
	};
	class Single2: Single1
	{
		displayName="CH1, 2km";
		artilleryCharge=0.7;
		minRange=139;	//139	//230
		midRange=1068.5;	//1068.5	1175
		maxRange=1998;	//1998	//2660
	};
	class Single3: Single1
	{
		displayName="CH2, 4km";
		artilleryCharge=1;
		minRange=284;	//284	//540
		midRange=2181;	//2181	//2355
		maxRange=4078;	//4078	//5500
	};
	//used by ai, rof decreased
	class Burst1: Burst1
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst2: Burst2
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst3: Burst3
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
};