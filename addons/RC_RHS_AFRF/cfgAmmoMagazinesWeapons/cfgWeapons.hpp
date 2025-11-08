class rhs_weap_2a70;
class RC_RHS_weap_2a70_Base: rhs_weap_2a70
{
	class player;
};
class RC_RHS_weap_2a70: RC_RHS_weap_2a70_Base
{
	displayName="100mm";
	reloadTime=6;	//6.5
	magazineReloadTime=5;
	autoReload=1;
	canLock=2;
	minZeroing=50;
	maxZeroing=4000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"

	magazines[]=
	{
		"RC_RHS_AFRF_20Rnd_100mm_MP_Pen_T_R",
		"RC_RHS_AFRF_20Rnd_100mm_MP_Pen_T_G",
		"RC_RHS_AFRF_20Rnd_100mm_MP_Pen_T_Y",

		"RC_RHS_AFRF_15Rnd_100mm_MP_Pen_T_R",
		"RC_RHS_AFRF_15Rnd_100mm_MP_Pen_T_G",
		"RC_RHS_AFRF_15Rnd_100mm_MP_Pen_T_Y",

		"RC_RHS_AFRF_10Rnd_100mm_MP_Pen_T_R",
		"RC_RHS_AFRF_10Rnd_100mm_MP_Pen_T_G",
		"RC_RHS_AFRF_10Rnd_100mm_MP_Pen_T_Y",

		"RC_RHS_AFRF_5Rnd_100mm_MP_Pen_T_R",
		"RC_RHS_AFRF_5Rnd_100mm_MP_Pen_T_G",
		"RC_RHS_AFRF_5Rnd_100mm_MP_Pen_T_Y",


		"RC_RHS_AFRF_20Rnd_100mm_MP_DF_T_R",
		"RC_RHS_AFRF_20Rnd_100mm_MP_DF_T_G",
		"RC_RHS_AFRF_20Rnd_100mm_MP_DF_T_Y",

		"RC_RHS_AFRF_15Rnd_100mm_MP_DF_T_R",
		"RC_RHS_AFRF_15Rnd_100mm_MP_DF_T_G",
		"RC_RHS_AFRF_15Rnd_100mm_MP_DF_T_Y",

		"RC_RHS_AFRF_10Rnd_100mm_MP_DF_T_R",
		"RC_RHS_AFRF_10Rnd_100mm_MP_DF_T_G",
		"RC_RHS_AFRF_10Rnd_100mm_MP_DF_T_Y",

		"RC_RHS_AFRF_5Rnd_100mm_MP_DF_T_R",
		"RC_RHS_AFRF_5Rnd_100mm_MP_DF_T_G",
		"RC_RHS_AFRF_5Rnd_100mm_MP_DF_T_Y",


		"RC_RHS_AFRF_20Rnd_100mm_MP_QF_T_R",
		"RC_RHS_AFRF_20Rnd_100mm_MP_QF_T_G",
		"RC_RHS_AFRF_20Rnd_100mm_MP_QF_T_Y",

		"RC_RHS_AFRF_15Rnd_100mm_MP_QF_T_R",
		"RC_RHS_AFRF_15Rnd_100mm_MP_QF_T_G",
		"RC_RHS_AFRF_15Rnd_100mm_MP_QF_T_Y",

		"RC_RHS_AFRF_10Rnd_100mm_MP_QF_T_R",
		"RC_RHS_AFRF_10Rnd_100mm_MP_QF_T_G",
		"RC_RHS_AFRF_10Rnd_100mm_MP_QF_T_Y",

		"RC_RHS_AFRF_5Rnd_100mm_MP_QF_T_R",
		"RC_RHS_AFRF_5Rnd_100mm_MP_QF_T_G",
		"RC_RHS_AFRF_5Rnd_100mm_MP_QF_T_Y",


		"RC_RHS_AFRF_20Rnd_100mm_MPAB_DF_T_R",
		"RC_RHS_AFRF_20Rnd_100mm_MPAB_DF_T_G",
		"RC_RHS_AFRF_20Rnd_100mm_MPAB_DF_T_Y",

		"RC_RHS_AFRF_15Rnd_100mm_MPAB_DF_T_R",
		"RC_RHS_AFRF_15Rnd_100mm_MPAB_DF_T_G",
		"RC_RHS_AFRF_15Rnd_100mm_MPAB_DF_T_Y",

		"RC_RHS_AFRF_10Rnd_100mm_MPAB_DF_T_R",
		"RC_RHS_AFRF_10Rnd_100mm_MPAB_DF_T_G",
		"RC_RHS_AFRF_10Rnd_100mm_MPAB_DF_T_Y",

		"RC_RHS_AFRF_5Rnd_100mm_MPAB_DF_T_R",
		"RC_RHS_AFRF_5Rnd_100mm_MPAB_DF_T_G",
		"RC_RHS_AFRF_5Rnd_100mm_MPAB_DF_T_Y",
		

		"RC_RHS_AFRF_4Rnd_100mm_ATGM_Overfly",
		"RC_RHS_AFRF_3Rnd_100mm_ATGM_Overfly",
		"RC_RHS_AFRF_2Rnd_100mm_ATGM_Overfly",
		"RC_RHS_AFRF_1Rnd_100mm_ATGM_Overfly",

		"RC_RHS_AFRF_4Rnd_100mm_ATGM_NLOS",
		"RC_RHS_AFRF_3Rnd_100mm_ATGM_NLOS",
		"RC_RHS_AFRF_2Rnd_100mm_ATGM_NLOS",
		"RC_RHS_AFRF_1Rnd_100mm_ATGM_NLOS",

		"RC_RHS_AFRF_4Rnd_100mm_AA",
		"RC_RHS_AFRF_3Rnd_100mm_AA",
		"RC_RHS_AFRF_2Rnd_100mm_AA",
		"RC_RHS_AFRF_1Rnd_100mm_AA"
	};

	class player: player
	{
		dispersion=0.001;
		reloadTime=6;
		magazineReloadTime=5;
	};
	class Cruise: Player
	{
		displayName="$STR_A3_firemode_terrain0";
		textureType="terrain";
		minRange=150;
		minRangeProbab=0.40000001;
		midRange=400;
		midRangeProbab=0.94999999;
		maxRange=4000;
		maxRangeProbab=0.94999999;
	};
	class Overfly: Cruise
	{
		displayName="Overfly Top Attack";
		textureType="overfly";
	};
	modes[]=
	{
		"player",
		"Overfly",
		"Cruise",
		//"topDown",
		"close",
		"short",
		"medium",
		"far"
	};
};


class rhs_weap_2a72;
class RC_RHS_weap_2a72_Base: rhs_weap_2a72
{
	class HighROFBMD2;
	class HE;
	class AP;
};
class RC_RHS_weap_2a72: RC_RHS_weap_2a72_Base
{
	displayName="30mm";
	autoReload=1;
	magazineReloadTime=20;
	canLock=2;
	minZeroing=50;
	maxZeroing=4000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	
	modes[]=
	{
		"HighROFBMD2",
		"close",
		"short",
		"medium",
		"far"
	};
	muzzles[]=
	{
		"HE",
		"AP"
	};

	class HE: HE
	{
		displayName="30mm HE";
		autoReload=1;
		magazineReloadTime=20;
		canLock=2;
		minZeroing=50;
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"

		class HighROFBMD2: HighROFBMD2
		{
			dispersion=0.001;
			magazineReloadTime=20;
		};
		magazines[]=
		{
			"RC_RHS_AFRF_100Rnd_30mm_MP_Pen_T_R",
			"RC_RHS_AFRF_100Rnd_30mm_MP_Pen_T_G",
			"RC_RHS_AFRF_100Rnd_30mm_MP_Pen_T_Y",

			"RC_RHS_AFRF_100Rnd_30mm_MP_DF_T_R",
			"RC_RHS_AFRF_100Rnd_30mm_MP_DF_T_G",
			"RC_RHS_AFRF_100Rnd_30mm_MP_DF_T_Y",

			"RC_RHS_AFRF_100Rnd_30mm_MP_QF_T_R",
			"RC_RHS_AFRF_100Rnd_30mm_MP_QF_T_G",
			"RC_RHS_AFRF_100Rnd_30mm_MP_QF_T_Y",

			"RC_RHS_AFRF_100Rnd_30mm_MPAB_DF_T_R",
			"RC_RHS_AFRF_100Rnd_30mm_MPAB_DF_T_G",
			"RC_RHS_AFRF_100Rnd_30mm_MPAB_DF_T_Y"
		};
		modes[]=
		{
			"HighROFBMD2",
			"close",
			"short",
			"medium",
			"far"
		};
	};
	class AP: AP
	{
		displayName="30mm AP";
		autoReload=1;
		magazineReloadTime=20;
		canLock=2;
		minZeroing=50;
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"

		class HighROFBMD2: HighROFBMD2
		{
			dispersion=0.001;
			magazineReloadTime=20;
		};
		magazines[]=
		{
			"RC_RHS_AFRF_100Rnd_30mm_APFSDS_T_R",
			"RC_RHS_AFRF_100Rnd_30mm_APFSDS_T_G",
			"RC_RHS_AFRF_100Rnd_30mm_APFSDS_T_Y"
		};
		modes[]=
		{
			"HighROFBMD2",
			"close",
			"short",
			"medium",
			"far"
		};
	};

	/*
	muzzles[]=
	{
		"this"
	};
	class HighROFBMD2: HighROFBMD2
	{
		dispersion=0.001;
		magazineReloadTime=20;
	};
	magazines[]=
	{
		"RC_RHS_AFRF_100Rnd_30mm_MP_Pen_T_R",
		"RC_RHS_AFRF_100Rnd_30mm_APFSDS_T_R"
	};
	*/
};


class rhs_weap_pkt_bmd_coax;
class RC_RHS_weap_pkt_bmd_coax_Base: rhs_weap_pkt_bmd_coax
{
	class manual;
};
class RC_RHS_weap_pkt_bmd_coax: RC_RHS_weap_pkt_bmd_coax_Base
{
	displayName="coax MMG";
	canLock=2;
	minZeroing=50;
	maxZeroing=3000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"

	magazines[]=
	{
		"RC_200Rnd_93x64_T_R",
		"RC_200Rnd_93x64_T_G",
		"RC_200Rnd_93x64_T_Y"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};


class rhs_weap_902a;
class RC_RHS_weap_902a: rhs_weap_902a
{

};


class rhs_weap_pkt_bmd_bow1;
class RC_RHS_weap_pkt_bmd_bow1_Base: rhs_weap_pkt_bmd_bow1
{
	class manual;
};
class RC_RHS_weap_pkt_bmd_bow1: RC_RHS_weap_pkt_bmd_bow1_Base
{
	canLock=2;
	minZeroing=50;
	maxZeroing=2000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"

	magazines[]=
	{
		"RC_200Rnd_762x51_T_R",
		"RC_200Rnd_762x51_T_G",
		"RC_200Rnd_762x51_T_Y"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};
class RC_RHS_weap_pkt_bmd_bow2: RC_RHS_weap_pkt_bmd_bow1 {};