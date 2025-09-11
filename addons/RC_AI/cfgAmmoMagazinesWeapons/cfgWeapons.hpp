//Vanilla
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