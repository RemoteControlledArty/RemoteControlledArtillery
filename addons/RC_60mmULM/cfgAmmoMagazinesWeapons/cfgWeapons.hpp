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


class mortar_82mm_base;
class RC_60mm_ULM_Weapon_Base: mortar_82mm_base
{
	class Single1;
	class Single2;
	class Single3;
};
class RC_60mm_ULM_Weapon: RC_60mm_ULM_Weapon_Base
{
	displayname="60mm advanced Mortar";
	displayNameShort="60mm Mortar";
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
		artilleryDispersion=1.5;
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
	*/
};


/*
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
*/