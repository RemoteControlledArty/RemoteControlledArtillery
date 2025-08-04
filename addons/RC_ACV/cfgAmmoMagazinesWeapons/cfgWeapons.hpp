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
	name="MCT-30";
	displayName="MCT-30";
	displayNameShort="MCT-30";
	magazineReloadTime=1;
	//maxZeroing=4000;

	class HE: HE
	{
		displayName="MCT-30 HE";
		displayNameShort="MCT-30 HE";
		maxZeroing=4000;
		magazineReloadTime=1;
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
			"RC_100Rnd_30mm_cUAS"
		};
		class player: player
		{
			reloadTime=0.3;
		};
	};
	class AP: AP
	{
		displayName="MCT-30 AP";
		displayNameShort="MCT-30 AP";
		maxZeroing=4000;
		magazineReloadTime=1;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		magazines[]=
		{
			"RC_100Rnd_30mm_APFSDS_T_R",
			"RC_100Rnd_30mm_APFSDS_T_G",
			"RC_100Rnd_30mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.225;
		};
	};
};


//make seamless reload but less rounds, 60-80 40mm, 100 30mm, 120 25mm, 140 20mm


class RC_autocannon_20mm_ACV: RC_autocannon_30mm_ACV
{
	name="MCT-20";
	displayName="MCT-20";
	displayNameShort="MCT-20";

	class HE: HE
	{
		displayName="MCT-20 HE";
		displayNameShort="MCT-20 HE";

		magazines[]=
		{
			"RC_140Rnd_20mm_MP_Pen_T_R",
			"RC_140Rnd_20mm_MP_Pen_T_G",
			"RC_140Rnd_20mm_MP_Pen_T_Y",

			"RC_140Rnd_20mm_HE_Pen_T_R",
			"RC_140Rnd_20mm_HE_Pen_T_G",
			"RC_140Rnd_20mm_HE_Pen_T_Y",

			"RC_140Rnd_20mm_MP_DF_T_R",
			"RC_140Rnd_20mm_MP_DF_T_G",
			"RC_140Rnd_20mm_MP_DF_T_Y",

			"RC_140Rnd_20mm_HE_DF_T_R",
			"RC_140Rnd_20mm_HE_DF_T_G",
			"RC_140Rnd_20mm_HE_DF_T_Y",

			"RC_140Rnd_20mm_MP_QF_T_R",
			"RC_140Rnd_20mm_MP_QF_T_G",
			"RC_140Rnd_20mm_MP_QF_T_Y",

			"RC_140Rnd_20mm_HE_QF_T_R",
			"RC_140Rnd_20mm_HE_QF_T_G",
			"RC_140Rnd_20mm_HE_QF_T_Y",

			"RC_140Rnd_20mm_MPAB_DF_T_R",
			"RC_140Rnd_20mm_MPAB_DF_T_G",
			"RC_140Rnd_20mm_MPAB_DF_T_Y",

			"RC_140Rnd_20mm_HEAB_DF_T_R",
			"RC_140Rnd_20mm_HEAB_DF_T_G",
			"RC_140Rnd_20mm_HEAB_DF_T_Y",

			"RC_140Rnd_20mm_MPAB_QF_T_R",
			"RC_140Rnd_20mm_MPAB_QF_T_G",
			"RC_140Rnd_20mm_MPAB_QF_T_Y",

			"RC_140Rnd_20mm_HEAB_QF_T_R",
			"RC_140Rnd_20mm_HEAB_QF_T_G",
			"RC_140Rnd_20mm_HEAB_QF_T_Y",
			"RC_140Rnd_20mm_cUAS"
		};
	};
	class AP: AP
	{
		displayName="MCT-20 AP";
		displayNameShort="MCT-20 AP";

		magazines[]=
		{
			"RC_140Rnd_20mm_APFSDS_T_R",
			"RC_140Rnd_20mm_APFSDS_T_G",
			"RC_140Rnd_20mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.175;
		};
	};
};


class RC_autocannon_25mm_ACV: RC_autocannon_30mm_ACV
{
	name="MCT-25";
	displayName="MCT-25";
	displayNameShort="MCT-25";

	class HE: HE
	{
		displayName="MCT-25 HE";
		displayNameShort="MCT-25 HE";

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
		displayName="MCT-25 AP";
		displayNameShort="MCT-25 AP";

		magazines[]=
		{
			"RC_120Rnd_25mm_APFSDS_T_R",
			"RC_120Rnd_25mm_APFSDS_T_G",
			"RC_120Rnd_25mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.2;
		};
	};
};


class RC_autocannon_40mm_ACV: RC_autocannon_30mm_ACV
{
	name="MCT-40";
	displayName="MCT-40";
	displayNameShort="MCT-40";

	class HE: HE
	{
		displayName="MCT-40 HE";
		displayNameShort="MCT-40 HE";

		magazines[]=
		{
			"RC_80Rnd_40mm_MP_Pen_T_R",
			"RC_80Rnd_40mm_MP_Pen_T_G",
			"RC_80Rnd_40mm_MP_Pen_T_Y",

			"RC_80Rnd_40mm_HE_Pen_T_R",
			"RC_80Rnd_40mm_HE_Pen_T_G",
			"RC_80Rnd_40mm_HE_Pen_T_Y",

			"RC_80Rnd_40mm_MP_DF_T_R",
			"RC_80Rnd_40mm_MP_DF_T_G",
			"RC_80Rnd_40mm_MP_DF_T_Y",

			"RC_80Rnd_40mm_HE_DF_T_R",
			"RC_80Rnd_40mm_HE_DF_T_G",
			"RC_80Rnd_40mm_HE_DF_T_Y",

			"RC_80Rnd_40mm_MP_QF_T_R",
			"RC_80Rnd_40mm_MP_QF_T_G",
			"RC_80Rnd_40mm_MP_QF_T_Y",

			"RC_80Rnd_40mm_HE_QF_T_R",
			"RC_80Rnd_40mm_HE_QF_T_G",
			"RC_80Rnd_40mm_HE_QF_T_Y",

			"RC_80Rnd_40mm_MPAB_DF_T_R",
			"RC_80Rnd_40mm_MPAB_DF_T_G",
			"RC_80Rnd_40mm_MPAB_DF_T_Y",

			"RC_80Rnd_40mm_HEAB_DF_T_R",
			"RC_80Rnd_40mm_HEAB_DF_T_G",
			"RC_80Rnd_40mm_HEAB_DF_T_Y",

			"RC_80Rnd_40mm_MPAB_QF_T_R",
			"RC_80Rnd_40mm_MPAB_QF_T_G",
			"RC_80Rnd_40mm_MPAB_QF_T_Y",

			"RC_80Rnd_40mm_HEAB_QF_T_R",
			"RC_80Rnd_40mm_HEAB_QF_T_G",
			"RC_80Rnd_40mm_HEAB_QF_T_Y",
			"RC_80Rnd_40mm_cUAS"
		};
	};
	class AP: AP
	{
		displayName="MCT-40 AP";
		displayNameShort="MCT-40 AP";

		magazines[]=
		{
			"RC_80Rnd_40mm_APFSDS_T_R",
			"RC_80Rnd_40mm_APFSDS_T_G",
			"RC_80Rnd_40mm_APFSDS_T_Y",

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