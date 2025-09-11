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