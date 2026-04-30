//AMV MGS
class vve_cannon_105mm;
class RC_MGS_cannon_105mm_Base: vve_cannon_105mm
{
	class player;

	class close;
	class short;
	class medium;
	class far;
};
class RC_MGS_cannon_105mm: RC_MGS_cannon_105mm_Base
{
	author="Ascent";
	displayName="105mm";
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	canLock=2;
	reloadTime=5;
	magazineReloadTime=5;

	magazines[]=
	{
		"RC_10Rnd_105mm_APFSDS_T_R",
		"RC_15Rnd_105mm_APFSDS_T_R",
		"RC_20Rnd_105mm_APFSDS_T_R",
		"RC_10Rnd_105mm_APFSDS_T_G",
		"RC_15Rnd_105mm_APFSDS_T_G",
		"RC_20Rnd_105mm_APFSDS_T_G",
		"RC_10Rnd_105mm_APFSDS_T_Y",
		"RC_15Rnd_105mm_APFSDS_T_Y",
		"RC_20Rnd_105mm_APFSDS_T_Y",

		"RC_5Rnd_105mm_MP_T_R",
		"RC_10Rnd_105mm_MP_T_R",
		"RC_15Rnd_105mm_MP_T_R",
		"RC_20Rnd_105mm_MP_T_R",
		"RC_5Rnd_105mm_MP_T_G",
		"RC_10Rnd_105mm_MP_T_G",
		"RC_15Rnd_105mm_MP_T_G",
		"RC_20Rnd_105mm_MP_T_G",
		"RC_5Rnd_105mm_MP_T_Y",
		"RC_10Rnd_105mm_MP_T_Y",
		"RC_15Rnd_105mm_MP_T_Y",
		"RC_20Rnd_105mm_MP_T_Y",

		"RC_5Rnd_105mm_MP_DF_T_R",
		"RC_10Rnd_105mm_MP_DF_T_R",
		"RC_15Rnd_105mm_MP_DF_T_R",
		"RC_20Rnd_105mm_MP_DF_T_R",
		"RC_5Rnd_105mm_MP_DF_T_G",
		"RC_10Rnd_105mm_MP_DF_T_G",
		"RC_15Rnd_105mm_MP_DF_T_G",
		"RC_20Rnd_105mm_MP_DF_T_G",
		"RC_5Rnd_105mm_MP_DF_T_Y",
		"RC_10Rnd_105mm_MP_DF_T_Y",
		"RC_15Rnd_105mm_MP_DF_T_Y",
		"RC_20Rnd_105mm_MP_DF_T_Y",

		"RC_2Rnd_105mm_MPAB_DF_T_R",
		"RC_3Rnd_105mm_MPAB_DF_T_R",
		"RC_4Rnd_105mm_MPAB_DF_T_R",
		"RC_5Rnd_105mm_MPAB_DF_T_R",
		"RC_10Rnd_105mm_MPAB_DF_T_R",
		"RC_15Rnd_105mm_MPAB_DF_T_R",
		"RC_20Rnd_105mm_MPAB_DF_T_R",

		"RC_2Rnd_105mm_MPAB_DF_T_G",
		"RC_3Rnd_105mm_MPAB_DF_T_G",
		"RC_4Rnd_105mm_MPAB_DF_T_G",
		"RC_5Rnd_105mm_MPAB_DF_T_G",
		"RC_10Rnd_105mm_MPAB_DF_T_G",
		"RC_15Rnd_105mm_MPAB_DF_T_G",
		"RC_20Rnd_105mm_MPAB_DF_T_G",

		"RC_2Rnd_105mm_MPAB_DF_T_Y",
		"RC_3Rnd_105mm_MPAB_DF_T_Y",
		"RC_4Rnd_105mm_MPAB_DF_T_Y",
		"RC_5Rnd_105mm_MPAB_DF_T_Y",
		"RC_10Rnd_105mm_MPAB_DF_T_Y",
		"RC_15Rnd_105mm_MPAB_DF_T_Y",
		"RC_20Rnd_105mm_MPAB_DF_T_Y",

		"RC_5Rnd_105mm_M_Overfly",
		"RC_4Rnd_105mm_M_Overfly",
		"RC_3Rnd_105mm_M_Overfly",
		"RC_2Rnd_105mm_M_Overfly",
		"RC_1Rnd_105mm_M_Overfly",

		"RC_5Rnd_105mm_M_SACLOS",
		"RC_4Rnd_105mm_M_SACLOS",
		"RC_3Rnd_105mm_M_SACLOS",
		"RC_2Rnd_105mm_M_SACLOS",
		"RC_1Rnd_105mm_M_SACLOS",

		"RC_5Rnd_105mm_M_LOS",
		"RC_4Rnd_105mm_M_LOS",
		"RC_3Rnd_105mm_M_LOS",
		"RC_2Rnd_105mm_M_LOS",
		"RC_1Rnd_105mm_M_LOS",

		"RC_5Rnd_105mm_M_NLOS",
		"RC_4Rnd_105mm_M_NLOS",
		"RC_3Rnd_105mm_M_NLOS",
		"RC_2Rnd_105mm_M_NLOS",
		"RC_1Rnd_105mm_M_NLOS",

		"RC_5Rnd_105mm_M_AA",
		"RC_4Rnd_105mm_M_AA",
		"RC_3Rnd_105mm_M_AA",
		"RC_2Rnd_105mm_M_AA",
		"RC_1Rnd_105mm_M_AA",

		"RC_5Rnd_105mm_M_HVKEM",
		"RC_4Rnd_105mm_M_HVKEM",
		"RC_3Rnd_105mm_M_HVKEM",
		"RC_2Rnd_105mm_M_HVKEM",
		"RC_1Rnd_105mm_M_HVKEM"
	};
	class player: player
	{
		reloadTime=5;
		magazineReloadTime=20;
	};
	class cruise: player
	{
		displayName="$STR_A3_firemode_terrain0";
		textureType="terrain";
		minRange=150;
		minRangeProbab=0.4;
		midRange=400;
		midRangeProbab=0.95;
		maxRange=4000;
		maxRangeProbab=0.95;
	};
	class topDown: player
	{
		textureType="topDown";
		displayName="$STR_A3_FireMode_TopDown0";
		minRange=150;
		minRangeProbab=0.4;
		midRange=400;
		midRangeProbab=0.95;
		maxRange=4000;
		maxRangeProbab=0.95;
	};
	class overfly: cruise
	{
		displayName="Overfly Top Attack";
		textureType="overfly";
	};
	modes[]=
	{
		"player",
		"cruise",
		"topDown",
		"overfly",
		"close",
		"short",
		"medium",
		"far"
	};
};


class vve_HMG_127_APC;
class RC_AMV_HMG_Base: vve_HMG_127_APC
{
	class manual;
};
class RC_AMV_HMG: RC_AMV_HMG_Base
{
	author="Ascent";
	displayName="HMG";
	canLock=2;
	maxZeroing=3000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"
	autoReload=1;
	magazines[]=
	{
		"RC_250Rnd_127x99_T_R",
		"RC_250Rnd_127x99_T_G",
		"RC_250Rnd_127x99_T_Y",
		"RC_250Rnd_127x99_SLAP_T_R",
		"RC_250Rnd_127x99_SLAP_T_G",
		"RC_250Rnd_127x99_SLAP_T_Y",
		"RC_250Rnd_127x99_cUAS"
	};
	class manual: manual
	{
		displayName="12.7mm";
		dispersion=0.001;
	};
};


class vve_missiles_titan;
class RC_AMV_APC_Missile_Launcher_Fetch: vve_missiles_titan
{
	class Player;
	//class TopDown;
};
class RC_AMV_APC_Missile_Launcher: RC_AMV_APC_Missile_Launcher_Fetch
{
	scope=1;
	canLock=2;
	weaponLockSystem="1 + 2";	//"1 + 2 + 4 + 16"
	displayName="Launcher";
	displayNameShort="Launcher";
	magazineReloadTime=12;
	cmImmunity=0.67;
	//weaponLockDelay=3;	//3

	/*
	lockingTargetSound[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\locking_NLAW",
		0.31622776,
		1
	};
	lockedTargetSound[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\locked_NLAW",
		0.31622776,
		2.5
	};
	*/

	magazines[]=
	{
		"RC_1Rnd_IFV_MP_SACLOS",
		"RC_2Rnd_IFV_MP_SACLOS",
		"RC_3Rnd_IFV_MP_SACLOS",
		"RC_4Rnd_IFV_MP_SACLOS",

		"RC_1Rnd_IFV_MP_LOS",
		"RC_2Rnd_IFV_MP_LOS",
		"RC_3Rnd_IFV_MP_LOS",
		"RC_4Rnd_IFV_MP_LOS",
		
		"RC_1Rnd_IFV_MP_Overfly",
		"RC_2Rnd_IFV_MP_Overfly",
		"RC_3Rnd_IFV_MP_Overfly",
		"RC_4Rnd_IFV_MP_Overfly",

		"RC_1Rnd_IFV_MP_NLOS",
		"RC_2Rnd_IFV_MP_NLOS",
		"RC_3Rnd_IFV_MP_NLOS",
		"RC_4Rnd_IFV_MP_NLOS",

		"RC_1Rnd_IFV_AA",
		"RC_2Rnd_IFV_AA",
		"RC_3Rnd_IFV_AA",
		"RC_4Rnd_IFV_AA"
	};
	
	modes[]=
	{
		"Player",
		"Overfly",
		"Cruise"
	};
	class Player: Player
	{
		reloadTime=12;
		magazineReloadTime=12;

		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Missile_Launcher\Titan",
				1.4125376,
				1,
				1100
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
			soundSetShot[]=
			{
				"Launcher_Vorona_Shot_SoundSet",
				"Launcher_Vorona_Tail_SoundSet"
			};
		};
	};
	class Cruise: Player
	{
		displayName="$STR_A3_firemode_terrain0";
		textureType="terrain";

		minRange=200;
		minRangeProbab=0.40000001;
		midRange=1000;
		midRangeProbab=0.89999998;
		maxRange=5000;
		maxRangeProbab=0.94999999;
	};
	class Overfly: Cruise
	{
		displayName="Overfly Top Attack";
		textureType="overfly";
	};
};


//AMV SHORAD
class vve_autocannon_35mm;
class RC_Single_autocannon_35mm_AA_base: vve_autocannon_35mm
{
	class AutoFast;
	class AutoSlow;

	class close;
	class short;
	class medium;
	class far;
};
class RC_Single_autocannon_35mm_AA: RC_Single_autocannon_35mm_AA_base
{
	author="Ascent";
	displayName="35mm SHORAD";

	magazineReloadTime=20;
	canLock=2;
	ballisticsComputer="2 + 4";	//why 2?

	magazines[]=
	{
		"RC_600Rnd_35mm_HEAB_AA_T_R",
		"RC_600Rnd_35mm_HEAB_AA_T_G",
		"RC_600Rnd_35mm_HEAB_AA_T_Y",
		"RC_600Rnd_35mm_MPAB_AA_T_R",
		"RC_600Rnd_35mm_MPAB_AA_T_G",
		"RC_600Rnd_35mm_MPAB_AA_T_Y"
	};

	modes[]=
	{
		"AutoSlow",
		"AutoFast",
		//"Direct",

		"close",
		"short",
		"medium",
		"far"
	};
	
	class AutoSlow: AutoSlow
	{
		magazineReloadTime=20;
		canLock=2;
		ballisticsComputer="2 + 4";

		displayName="35mm SHORAD";
		reloadTime=0.15;
		dispersion=0.002;	//0.002
	};
	class AutoFast: AutoFast
	{
		magazineReloadTime=20;
		canLock=2;
		ballisticsComputer="2 + 4";

		displayName="35mm SHORAD";
		reloadTime=0.05;
		dispersion=0.002;	//0.002
	};
	/*
	class Direct: AutoFast
	{
		magazineReloadTime=20;
		canLock=2;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		maxZeroing=4000;

		displayName="35mm Direct";
		reloadTime=0.06;
		dispersion=0.0008;
	};
	*/

	class close: close
	{
		magazineReloadTime=20;
		reloadTime=0.15;
	};
	class short: short
	{
		magazineReloadTime=20;
		reloadTime=0.15;
	};
	class medium: medium
	{
		magazineReloadTime=20;
		reloadTime=0.15;
	};
	class far: far
	{
		magazineReloadTime=20;
		reloadTime=0.15;
	};
};