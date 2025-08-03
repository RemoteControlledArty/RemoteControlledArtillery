//Autocannons
class autocannon_30mm_ACV;
class RC_autocannon_30mm_ACV_Base: autocannon_30mm_ACV
{
	class HE;
	class AP;
	class player;
};
class RC_autocannon_30mm_ACV: RC_autocannon_30mm_ACV_Base
{
	canLock=2;
	FCSZeroingDelay=0.5;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	name="30mm";
	//maxZeroing=4000;

	class HE: HE
	{
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		magazines[]=
		{
			"RC_100Rnd_30mm_MP_Pen_T_R",
			"RC_100Rnd_30mm_MP_Pen_T_G",
			"RC_100Rnd_30mm_MP_Pen_T_Y",

			"RC_100Rnd_30mm_HE_Pen_T_R",
			"RC_100Rnd_30mm_HE_Pen_T_G",
			"RC_100Rnd_30mm_HE_Pen_T_Y",

			"RC_100Rnd_30mm_MP_DF_T_R",
			"RC_100Rnd_30mm_MP_DF_T_G",
			"RC_100Rnd_30mm_MP_DF_T_Y",

			"RC_100Rnd_30mm_HE_DF_T_R",
			"RC_100Rnd_30mm_HE_DF_T_G",
			"RC_100Rnd_30mm_HE_DF_T_Y",

			"RC_100Rnd_30mm_MP_QF_T_R",
			"RC_100Rnd_30mm_MP_QF_T_G",
			"RC_100Rnd_30mm_MP_QF_T_Y",

			"RC_100Rnd_30mm_HE_QF_T_R",
			"RC_100Rnd_30mm_HE_QF_T_G",
			"RC_100Rnd_30mm_HE_QF_T_Y",

			"RC_100Rnd_30mm_MPAB_DF_T_R",
			"RC_100Rnd_30mm_MPAB_DF_T_G",
			"RC_100Rnd_30mm_MPAB_DF_T_Y",

			"RC_100Rnd_30mm_HEAB_DF_T_R",
			"RC_100Rnd_30mm_HEAB_DF_T_G",
			"RC_100Rnd_30mm_HEAB_DF_T_Y",

			"RC_100Rnd_30mm_MPAB_QF_T_R",
			"RC_100Rnd_30mm_MPAB_QF_T_G",
			"RC_100Rnd_30mm_MPAB_QF_T_Y",

			"RC_100Rnd_30mm_HEAB_QF_T_R",
			"RC_100Rnd_30mm_HEAB_QF_T_G",
			"RC_100Rnd_30mm_HEAB_QF_T_Y",
			"RC_100Rnd_30mm_cUAS",

			"RC_100Rnd_30mm_MP_T_R",
			"RC_100Rnd_30mm_MP_T_G",
			"RC_100Rnd_30mm_MP_T_Y",
			"RC_100Rnd_30mm_GPR_T_R",
			"RC_100Rnd_30mm_GPR_T_G",
			"RC_100Rnd_30mm_GPR_T_Y"
		};
		class player: player
		{
			reloadTime=0.3;
		};
	};
	class AP: AP
	{
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		magazines[]=
		{
			"RC_100Rnd_30mm_APFSDS_T_R",
			"RC_100Rnd_30mm_APFSDS_T_G",
			"RC_100Rnd_30mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.2;
		};
	};
};


class RC_autocannon_20mm_ACV: RC_autocannon_30mm_ACV
{
	name="20mm";

	class HE: HE
	{
		magazines[]=
		{
			"RC_120Rnd_20mm_MP_Pen_T_R",
			"RC_120Rnd_20mm_MP_Pen_T_G",
			"RC_120Rnd_20mm_MP_Pen_T_Y",

			"RC_120Rnd_20mm_HE_Pen_T_R",
			"RC_120Rnd_20mm_HE_Pen_T_G",
			"RC_120Rnd_20mm_HE_Pen_T_Y",

			"RC_120Rnd_20mm_MP_DF_T_R",
			"RC_120Rnd_20mm_MP_DF_T_G",
			"RC_120Rnd_20mm_MP_DF_T_Y",

			"RC_120Rnd_20mm_HE_DF_T_R",
			"RC_120Rnd_20mm_HE_DF_T_G",
			"RC_120Rnd_20mm_HE_DF_T_Y",

			"RC_120Rnd_20mm_MP_QF_T_R",
			"RC_120Rnd_20mm_MP_QF_T_G",
			"RC_120Rnd_20mm_MP_QF_T_Y",

			"RC_120Rnd_20mm_HE_QF_T_R",
			"RC_120Rnd_20mm_HE_QF_T_G",
			"RC_120Rnd_20mm_HE_QF_T_Y",

			"RC_120Rnd_20mm_MPAB_DF_T_R",
			"RC_120Rnd_20mm_MPAB_DF_T_G",
			"RC_120Rnd_20mm_MPAB_DF_T_Y",

			"RC_120Rnd_20mm_HEAB_DF_T_R",
			"RC_120Rnd_20mm_HEAB_DF_T_G",
			"RC_120Rnd_20mm_HEAB_DF_T_Y",

			"RC_120Rnd_20mm_MPAB_QF_T_R",
			"RC_120Rnd_20mm_MPAB_QF_T_G",
			"RC_120Rnd_20mm_MPAB_QF_T_Y",

			"RC_120Rnd_20mm_HEAB_QF_T_R",
			"RC_120Rnd_20mm_HEAB_QF_T_G",
			"RC_120Rnd_20mm_HEAB_QF_T_Y",
			"RC_120Rnd_20mm_cUAS"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_120Rnd_20mm_APFSDS_T_R",
			"RC_120Rnd_20mm_APFSDS_T_G",
			"RC_120Rnd_20mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.15;
		};
	};
};


class RC_autocannon_25mm_ACV: RC_autocannon_30mm_ACV
{
	name="25mm";

	class HE: HE
	{
		magazines[]=
		{
			"RC_120Rnd_25mm_MP_Pen_T_R",
			"RC_120Rnd_25mm_MP_Pen_T_G",
			"RC_120Rnd_25mm_MP_Pen_T_Y",

			"RC_120Rnd_25mm_HE_Pen_T_R",
			"RC_120Rnd_25mm_HE_Pen_T_G",
			"RC_120Rnd_25mm_HE_Pen_T_Y",

			"RC_120Rnd_25mm_MP_DF_T_R",
			"RC_120Rnd_25mm_MP_DF_T_G",
			"RC_120Rnd_25mm_MP_DF_T_Y",

			"RC_120Rnd_25mm_HE_DF_T_R",
			"RC_120Rnd_25mm_HE_DF_T_G",
			"RC_120Rnd_25mm_HE_DF_T_Y",

			"RC_120Rnd_25mm_MP_QF_T_R",
			"RC_120Rnd_25mm_MP_QF_T_G",
			"RC_120Rnd_25mm_MP_QF_T_Y",

			"RC_120Rnd_25mm_HE_QF_T_R",
			"RC_120Rnd_25mm_HE_QF_T_G",
			"RC_120Rnd_25mm_HE_QF_T_Y",

			"RC_120Rnd_25mm_MPAB_DF_T_R",
			"RC_120Rnd_25mm_MPAB_DF_T_G",
			"RC_120Rnd_25mm_MPAB_DF_T_Y",

			"RC_120Rnd_25mm_HEAB_DF_T_R",
			"RC_120Rnd_25mm_HEAB_DF_T_G",
			"RC_120Rnd_25mm_HEAB_DF_T_Y",

			"RC_120Rnd_25mm_MPAB_QF_T_R",
			"RC_120Rnd_25mm_MPAB_QF_T_G",
			"RC_120Rnd_25mm_MPAB_QF_T_Y",

			"RC_120Rnd_25mm_HEAB_QF_T_R",
			"RC_120Rnd_25mm_HEAB_QF_T_G",
			"RC_120Rnd_25mm_HEAB_QF_T_Y",
			"RC_120Rnd_25mm_cUAS"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_120Rnd_25mm_APFSDS_T_R",
			"RC_120Rnd_25mm_APFSDS_T_G",
			"RC_120Rnd_25mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.175;
		};
	};
};


class RC_autocannon_40mm_ACV: RC_autocannon_30mm_ACV
{
	name="40mm";

	class HE: HE
	{
		magazines[]=
		{
			"RC_120Rnd_40mm_MP_Pen_T_R",
			"RC_120Rnd_40mm_MP_Pen_T_G",
			"RC_120Rnd_40mm_MP_Pen_T_Y",

			"RC_120Rnd_40mm_HE_Pen_T_R",
			"RC_120Rnd_40mm_HE_Pen_T_G",
			"RC_120Rnd_40mm_HE_Pen_T_Y",

			"RC_120Rnd_40mm_MP_DF_T_R",
			"RC_120Rnd_40mm_MP_DF_T_G",
			"RC_120Rnd_40mm_MP_DF_T_Y",

			"RC_120Rnd_40mm_HE_DF_T_R",
			"RC_120Rnd_40mm_HE_DF_T_G",
			"RC_120Rnd_40mm_HE_DF_T_Y",

			"RC_120Rnd_40mm_MP_QF_T_R",
			"RC_120Rnd_40mm_MP_QF_T_G",
			"RC_120Rnd_40mm_MP_QF_T_Y",

			"RC_120Rnd_40mm_HE_QF_T_R",
			"RC_120Rnd_40mm_HE_QF_T_G",
			"RC_120Rnd_40mm_HE_QF_T_Y",

			"RC_120Rnd_40mm_MPAB_DF_T_R",
			"RC_120Rnd_40mm_MPAB_DF_T_G",
			"RC_120Rnd_40mm_MPAB_DF_T_Y",

			"RC_120Rnd_40mm_HEAB_DF_T_R",
			"RC_120Rnd_40mm_HEAB_DF_T_G",
			"RC_120Rnd_40mm_HEAB_DF_T_Y",

			"RC_120Rnd_40mm_MPAB_QF_T_R",
			"RC_120Rnd_40mm_MPAB_QF_T_G",
			"RC_120Rnd_40mm_MPAB_QF_T_Y",

			"RC_120Rnd_40mm_HEAB_QF_T_R",
			"RC_120Rnd_40mm_HEAB_QF_T_G",
			"RC_120Rnd_40mm_HEAB_QF_T_Y",
			"RC_120Rnd_40mm_cUAS"

			
			//50Rnd
			"RC_50Rnd_40mm_MP_Pen_T_R",
			"RC_50Rnd_40mm_MP_Pen_T_G",
			"RC_50Rnd_40mm_MP_Pen_T_Y",

			"RC_50Rnd_40mm_HE_Pen_T_R",
			"RC_50Rnd_40mm_HE_Pen_T_G",
			"RC_50Rnd_40mm_HE_Pen_T_Y",

			"RC_50Rnd_40mm_MP_DF_T_R",
			"RC_50Rnd_40mm_MP_DF_T_G",
			"RC_50Rnd_40mm_MP_DF_T_Y",

			"RC_50Rnd_40mm_HE_DF_T_R",
			"RC_50Rnd_40mm_HE_DF_T_G",
			"RC_50Rnd_40mm_HE_DF_T_Y",

			"RC_50Rnd_40mm_MP_QF_T_R",
			"RC_50Rnd_40mm_MP_QF_T_G",
			"RC_50Rnd_40mm_MP_QF_T_Y",

			"RC_50Rnd_40mm_HE_QF_T_R",
			"RC_50Rnd_40mm_HE_QF_T_G",
			"RC_50Rnd_40mm_HE_QF_T_Y",

			"RC_50Rnd_40mm_MPAB_DF_T_R",
			"RC_50Rnd_40mm_MPAB_DF_T_G",
			"RC_50Rnd_40mm_MPAB_DF_T_Y",

			"RC_50Rnd_40mm_HEAB_DF_T_R",
			"RC_50Rnd_40mm_HEAB_DF_T_G",
			"RC_50Rnd_40mm_HEAB_DF_T_Y",

			"RC_50Rnd_40mm_MPAB_QF_T_R",
			"RC_50Rnd_40mm_MPAB_QF_T_G",
			"RC_50Rnd_40mm_MPAB_QF_T_Y",

			"RC_50Rnd_40mm_HEAB_QF_T_R",
			"RC_50Rnd_40mm_HEAB_QF_T_G",
			"RC_50Rnd_40mm_HEAB_QF_T_Y",
			"RC_50Rnd_40mm_cUAS",

			"RC_50Rnd_40mm_MP_T_R",
			"RC_50Rnd_40mm_MP_T_G",
			"RC_50Rnd_40mm_MP_T_Y",
			"RC_50Rnd_40mm_GPR_T_R",
			"RC_50Rnd_40mm_GPR_T_G",
			"RC_50Rnd_40mm_GPR_T_Y"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_50Rnd_40mm_APFSDS_T_R",
			"RC_50Rnd_40mm_APFSDS_T_G",
			"RC_50Rnd_40mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.3;
		};
	};
};


//Machineguns
class HMG_M2_ACV;
class RC_HMG_M2_ACV_Base: HMG_M2_ACV
{
	class manual;
};
class RC_HMG_M2_ACV: RC_HMG_M2_ACV_Base
{
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazines[]=
	{
		"RC_200Rnd_127x99_T_G",
		"RC_200Rnd_127x99_T_R",
		"RC_200Rnd_127x99_T_Y",
		"RC_200Rnd_127x99_SLAP_T_G",
		"RC_200Rnd_127x99_SLAP_T_R",
		"RC_200Rnd_127x99_SLAP_T_Y"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};