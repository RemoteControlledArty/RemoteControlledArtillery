//Vanilla

//RC_HMG_127x99_FSV
class RC_MMG_338_FSV_coax;
class RC_AI_MMG_338_FSV_coax: RC_MMG_338_FSV_coax
{
	magazines[]=
	{
		"RC_AI_200Rnd_338_T_R",
		"RC_AI_200Rnd_338_T_G",
		"RC_AI_200Rnd_338_T_Y",

		"RC_AI_300Rnd_338_T_R",
		"RC_AI_300Rnd_338_T_G",
		"RC_AI_300Rnd_338_T_Y",

		"RC_AI_400Rnd_338_T_R",
		"RC_AI_400Rnd_338_T_G",
		"RC_AI_400Rnd_338_T_Y"
	};
};
class RC_MMG_338_coax_ext;
class RC_AI_MMG_338_coax_ext: RC_MMG_338_coax_ext
{
	magazines[]=
	{
		"RC_AI_200Rnd_338_T_R",
		"RC_AI_200Rnd_338_T_G",
		"RC_AI_200Rnd_338_T_Y",

		"RC_AI_300Rnd_338_T_R",
		"RC_AI_300Rnd_338_T_G",
		"RC_AI_300Rnd_338_T_Y",

		"RC_AI_400Rnd_338_T_R",
		"RC_AI_400Rnd_338_T_G",
		"RC_AI_400Rnd_338_T_Y"
	};
};


class RC_MMG_93x64_coax_ext;
class RC_AI_MMG_93x64_coax_ext: RC_MMG_93x64_coax_ext
{
	magazines[]=
	{
		"RC_AI_200Rnd_93x64_T_G",
		"RC_AI_200Rnd_93x64_T_R",
		"RC_AI_200Rnd_93x64_T_Y",

		"RC_AI_300Rnd_93x64_T_G",
		"RC_AI_300Rnd_93x64_T_R",
		"RC_AI_300Rnd_93x64_T_Y",

		"RC_AI_400Rnd_93x64_T_G",
		"RC_AI_400Rnd_93x64_T_R",
		"RC_AI_400Rnd_93x64_T_Y",

		"RC_AI_600Rnd_93x64_T_G",
		"RC_AI_600Rnd_93x64_T_R",
		"RC_AI_600Rnd_93x64_T_Y"
	};
};


class RC_autocannon_30mm_CTWS;
class RC_AI_autocannon_30mm_CTWS_Base: RC_autocannon_30mm_CTWS
{
	class HE;
	class AP;
};
class RC_AI_autocannon_30mm_CTWS: RC_AI_autocannon_30mm_CTWS_Base
{
	//canLock=2;

	class HE: HE
	{
		magazines[]=
		{
			/*
			"RC_AI_100Rnd_30mm_MP_Pen_T_R",
			"RC_AI_100Rnd_30mm_MP_Pen_T_G",
			"RC_AI_100Rnd_30mm_MP_Pen_T_Y",

			"RC_AI_100Rnd_30mm_HE_Pen_T_R",
			"RC_AI_100Rnd_30mm_HE_Pen_T_G",
			"RC_AI_100Rnd_30mm_HE_Pen_T_Y",

			"RC_AI_100Rnd_30mm_MP_DF_T_R",
			"RC_AI_100Rnd_30mm_MP_DF_T_G",
			"RC_AI_100Rnd_30mm_MP_DF_T_Y",

			"RC_AI_100Rnd_30mm_HE_DF_T_R",
			"RC_AI_100Rnd_30mm_HE_DF_T_G",
			"RC_AI_100Rnd_30mm_HE_DF_T_Y",
			*/

			"RC_AI_100Rnd_30mm_MPAB_DF_T_R",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_G",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_Y"

			/*
			"RC_AI_100Rnd_30mm_HEAB_DF_T_R",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_G",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_Y"
			*/
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_AI_100Rnd_30mm_APFSDS_T_R",
			"RC_AI_100Rnd_30mm_APFSDS_T_G",
			"RC_AI_100Rnd_30mm_APFSDS_T_Y"
		};
	};
};


class RC_cannon_120mm;
class RC_AI_cannon_120mm: RC_cannon_120mm
{
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	FCSZeroingDelay=0.5;

	magazines[]=
	{
		"RC_AI_15Rnd_120mm_APFSDS_T_R",
		"RC_AI_20Rnd_120mm_APFSDS_T_R",
		"RC_AI_15Rnd_120mm_APFSDS_T_G",
		"RC_AI_20Rnd_120mm_APFSDS_T_G",
		"RC_AI_15Rnd_120mm_APFSDS_T_Y",
		"RC_AI_20Rnd_120mm_APFSDS_T_Y",

		"RC_AI_10Rnd_120mm_MP_T_R",
		"RC_AI_15Rnd_120mm_MP_T_R",
		"RC_AI_20Rnd_120mm_MP_T_R",
		"RC_AI_10Rnd_120mm_MP_T_G",
		"RC_AI_15Rnd_120mm_MP_T_G",
		"RC_AI_20Rnd_120mm_MP_T_G",
		"RC_AI_10Rnd_120mm_MP_T_Y",
		"RC_AI_15Rnd_120mm_MP_T_Y",
		"RC_AI_20Rnd_120mm_MP_T_Y",

		"RC_AI_3Rnd_120mm_MPAB_DF_T_R",
		"RC_AI_3Rnd_120mm_MPAB_DF_T_G",
		"RC_AI_3Rnd_120mm_MPAB_DF_T_Y"

		/*
		"RC_5Rnd_120mm_cannon_missiles",
		"RC_4Rnd_120mm_cannon_missiles",
		"RC_3Rnd_120mm_cannon_missiles",
		"RC_2Rnd_120mm_cannon_missiles",
		"RC_1Rnd_120mm_cannon_missiles",

		"RC_5Rnd_120mm_DLG_cannon_missiles",
		"RC_4Rnd_120mm_DLG_cannon_missiles",
		"RC_3Rnd_120mm_DLG_cannon_missiles",
		"RC_2Rnd_120mm_DLG_cannon_missiles",
		"RC_1Rnd_120mm_DLG_cannon_missiles",

		"RC_5Rnd_120mm_DLG_HVKEM",
		"RC_4Rnd_120mm_DLG_HVKEM",
		"RC_3Rnd_120mm_DLG_HVKEM",
		"RC_2Rnd_120mm_DLG_HVKEM",
		"RC_1Rnd_120mm_DLG_HVKEM"
		*/
	};
};


class RC_cannon_125mm;
class RC_AI_cannon_125mm: RC_cannon_125mm
{
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	FCSZeroingDelay=0.5;

	magazines[]=
	{
		"RC_AI_15Rnd_125mm_APFSDS_T_R",
		"RC_AI_20Rnd_125mm_APFSDS_T_R",
		"RC_AI_15Rnd_125mm_APFSDS_T_G",
		"RC_AI_20Rnd_125mm_APFSDS_T_G",
		"RC_AI_15Rnd_125mm_APFSDS_T_Y",
		"RC_AI_20Rnd_125mm_APFSDS_T_Y",

		"RC_AI_10Rnd_125mm_MP_T_R",
		"RC_AI_15Rnd_125mm_MP_T_R",
		"RC_AI_20Rnd_125mm_MP_T_R",
		"RC_AI_10Rnd_125mm_MP_T_G",
		"RC_AI_15Rnd_125mm_MP_T_G",
		"RC_AI_20Rnd_125mm_MP_T_G",
		"RC_AI_10Rnd_125mm_MP_T_Y",
		"RC_AI_15Rnd_125mm_MP_T_Y",
		"RC_AI_20Rnd_125mm_MP_T_Y",

		"RC_AI_3Rnd_125mm_MPAB_DF_T_R",
		"RC_AI_3Rnd_125mm_MPAB_DF_T_G",
		"RC_AI_3Rnd_125mm_MPAB_DF_T_Y"

		/*
		"RC_5Rnd_125mm_cannon_missiles",
		"RC_4Rnd_125mm_cannon_missiles",
		"RC_3Rnd_125mm_cannon_missiles",
		"RC_2Rnd_125mm_cannon_missiles",
		"RC_1Rnd_125mm_cannon_missiles",

		"RC_5Rnd_125mm_DLG_cannon_missiles",
		"RC_4Rnd_125mm_DLG_cannon_missiles",
		"RC_3Rnd_125mm_DLG_cannon_missiles",
		"RC_2Rnd_125mm_DLG_cannon_missiles",
		"RC_1Rnd_125mm_DLG_cannon_missiles",

		"RC_5Rnd_125mm_DLG_HVKEM",
		"RC_4Rnd_125mm_DLG_HVKEM",
		"RC_3Rnd_125mm_DLG_HVKEM",
		"RC_2Rnd_125mm_DLG_HVKEM",
		"RC_1Rnd_125mm_DLG_HVKEM"
		*/
	};
};


class RC_IFV_Missile_Launcher;
class RC_AI_IFV_Missile_Launcher: RC_IFV_Missile_Launcher
{
	weaponLockSystem="1 + 2";	//"1 + 2 + 4 + 16"
	cmImmunity=0.67;
	//weaponLockDelay=3;	//3

	magazines[]=
	{
		"RC_AI_2Rnd_IFV_MP_SACLOS",

		"RC_2Rnd_IFV_MP_LOS",
		"RC_2Rnd_IFV_MP_Overfly",
		"RC_2Rnd_IFV_MP_NLOS",
		"2Rnd_GAT_missiles",
		"RC_2Rnd_IFV_AA"
	};
	modes[]=
	{
		"Player",
		"Overfly",
		"Cruise"
	};
	/*
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
		magazineReloadTime=20;
	};
	*/
};
class RC_IFV_Missile_Launcher_4R: RC_IFV_Missile_Launcher
{
	magazines[]=
	{
		"RC_4Rnd_IFV_MP_Overfly",
		"RC_4Rnd_IFV_MP_NLOS",
		"RC_4Rnd_IFV_AA"
	};
};


//RHS
class RC_RHS_weap_m240_bradley_coax;
class RC_AI_RHS_weap_m240_bradley_coax: RC_RHS_weap_m240_bradley_coax
{
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"

	magazines[]=
	{
		"RC_RHS_mag_400Rnd_762x51_T_R",
		"RC_RHS_mag_400Rnd_762x51_M61_T_R"
	};
};


class RC_RHS_weap_M242BC;
class RC_AI_RHS_weap_M242BC_Base: RC_RHS_weap_M242BC
{
	class HE;
	class AP;
};
class RC_AI_RHS_weap_M242BC: RC_AI_RHS_weap_M242BC_Base
{
	//canLock=2;

	class HE: HE
	{
		magazines[]=
		{
			"RC_AI_RHS_110Rnd_25mm_MPAB_DF_T_R"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_AI_RHS_mag_70Rnd_25mm_APFSDS_T_R"
		};
	};
};


class RC_RHS_weap_m256;
class RC_AI_RHS_weap_m256: RC_RHS_weap_m256
{
	canLock=2;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	FCSZeroingDelay=0.5;	//0.5

	magazines[]=
	{
		"RC_AI_20Rnd_120mm_APFSDS_T_R",
		"RC_AI_20Rnd_120mm_MP_T_R",
		"RC_AI_3Rnd_120mm_MPAB_DF_T_R"

		/*
		"RC_RHS_mag_M829A4_20Rnd",
		"RC_RHS_mag_M829A4_15Rnd",
		"RC_RHS_mag_M829A4_10Rnd",

		"RC_RHS_mag_M830A1_20Rnd",
		"RC_RHS_mag_M830A1_15Rnd",
		"RC_RHS_mag_M830A1_10Rnd",

		"RC_RHS_mag_M1147_MPAB_DF_3Rnd",
		*/
	};
};