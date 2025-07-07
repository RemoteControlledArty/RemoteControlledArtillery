class cannon_120mm_M360;
class RC_cannon_120mm_M360_base: cannon_120mm_M360
{
	class player;
};
class RC_cannon_120mm_M360: RC_cannon_120mm_M360_base
{
	author="Ascent";
	//displayName="120mm";
	canLock=2;
	maxZeroing=4000;
	FCSZeroingDelay=0.5;
	FCSMaxLeadSpeed=100;
	reloadTime=5;
	magazineReloadTime=5;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	magazines[]=
	{
		"RC_10Rnd_120mm_APFSDS_T_R",
		"RC_15Rnd_120mm_APFSDS_T_R",
		"RC_20Rnd_120mm_APFSDS_T_R",
		"RC_10Rnd_120mm_APFSDS_T_G",
		"RC_15Rnd_120mm_APFSDS_T_G",
		"RC_20Rnd_120mm_APFSDS_T_G",
		"RC_10Rnd_120mm_APFSDS_T_Y",
		"RC_15Rnd_120mm_APFSDS_T_Y",
		"RC_20Rnd_120mm_APFSDS_T_Y",
		/*
		"RC_10Rnd_120mm_MP_HEAB_T_R",
		"RC_15Rnd_120mm_MP_HEAB_T_R",
		"RC_20Rnd_120mm_MP_HEAB_T_R",
		"RC_10Rnd_120mm_MP_HEAB_T_G",
		"RC_15Rnd_120mm_MP_HEAB_T_G",
		"RC_20Rnd_120mm_MP_HEAB_T_G",
		"RC_10Rnd_120mm_MP_HEAB_T_Y",
		"RC_15Rnd_120mm_MP_HEAB_T_Y",
		"RC_20Rnd_120mm_MP_HEAB_T_Y",
		*/
		"RC_10Rnd_120mm_MP_T_R",
		"RC_15Rnd_120mm_MP_T_R",
		"RC_20Rnd_120mm_MP_T_R",
		"RC_10Rnd_120mm_MP_T_G",
		"RC_15Rnd_120mm_MP_T_G",
		"RC_20Rnd_120mm_MP_T_G",
		"RC_10Rnd_120mm_MP_T_Y",
		"RC_15Rnd_120mm_MP_T_Y",
		"RC_20Rnd_120mm_MP_T_Y",
		"RC_5Rnd_120mm_HEAB_LV_indirect_T_R",
		"RC_10Rnd_120mm_HEAB_LV_indirect_T_R",
		"RC_15Rnd_120mm_HEAB_LV_indirect_T_R",
		"RC_20Rnd_120mm_HEAB_LV_indirect_T_R",
		"RC_10Rnd_120mm_HEAB_LV_indirect_T_G",
		"RC_15Rnd_120mm_HEAB_LV_indirect_T_G",
		"RC_20Rnd_120mm_HEAB_LV_indirect_T_G",
		"RC_10Rnd_120mm_HEAB_LV_indirect_T_Y",
		"RC_15Rnd_120mm_HEAB_LV_indirect_T_Y",
		"RC_20Rnd_120mm_HEAB_LV_indirect_T_Y",
		"RC_4Rnd_120mm_DLG_cannon_missiles",
		"RC_3Rnd_120mm_DLG_cannon_missiles",
		"RC_2Rnd_120mm_DLG_cannon_missiles",
		"RC_1Rnd_120mm_DLG_cannon_missiles"
	};
	class player: player
	{
		reloadTime=5;
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
	class TopDown: player
	{
		textureType="topDown";
		displayName="$STR_A3_FireMode_TopDown0";
		minRange=150;
		minRangeProbab=0.40000001;
		midRange=400;
		midRangeProbab=0.94999999;
		maxRange=4000;
		maxRangeProbab=0.94999999;
	};
	modes[]=
	{
		"player",
		"Cruise",
		"topDown",
		"close",
		"short",
		"medium",
		"far"
	};
};


//Autocannons
class autocannon_30mm_M914;
class RC_autocannon_30mm_M914_Base: autocannon_30mm_M914
{
	class HighROF;
	class player;
};
class RC_autocannon_30mm_M914: RC_autocannon_30mm_M914_Base
{
	author="Ascent";
	//displayName="30mm";
	canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=4000;
	FCSMaxLeadSpeed=100;
	autoReload=1;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	class HighROF: HighROF
	{
		canLock=2;
		FCSZeroingDelay=0.5;
		maxZeroing=4000;
		FCSMaxLeadSpeed=100;
		autoReload=1;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		magazines[]=
		{
			"RC_140Rnd_30mm_MP_Pen_T_R",
			"RC_140Rnd_30mm_MP_Pen_T_G",
			"RC_140Rnd_30mm_MP_Pen_T_Y",

			"RC_140Rnd_30mm_HE_Pen_T_R",
			"RC_140Rnd_30mm_HE_Pen_T_G",
			"RC_140Rnd_30mm_HE_Pen_T_Y",

			"RC_140Rnd_30mm_MP_DF_T_R",
			"RC_140Rnd_30mm_MP_DF_T_G",
			"RC_140Rnd_30mm_MP_DF_T_Y",

			"RC_140Rnd_30mm_HE_DF_T_R",
			"RC_140Rnd_30mm_HE_DF_T_G",
			"RC_140Rnd_30mm_HE_DF_T_Y",

			"RC_140Rnd_30mm_MP_QF_T_R",
			"RC_140Rnd_30mm_MP_QF_T_G",
			"RC_140Rnd_30mm_MP_QF_T_Y",

			"RC_140Rnd_30mm_HE_QF_T_R",
			"RC_140Rnd_30mm_HE_QF_T_G",
			"RC_140Rnd_30mm_HE_QF_T_Y",

			"RC_140Rnd_30mm_MPAB_DF_T_R",
			"RC_140Rnd_30mm_MPAB_DF_T_G",
			"RC_140Rnd_30mm_MPAB_DF_T_Y",

			"RC_140Rnd_30mm_HEAB_DF_T_R",
			"RC_140Rnd_30mm_HEAB_DF_T_G",
			"RC_140Rnd_30mm_HEAB_DF_T_Y",

			"RC_140Rnd_30mm_MPAB_QF_T_R",
			"RC_140Rnd_30mm_MPAB_QF_T_G",
			"RC_140Rnd_30mm_MPAB_QF_T_Y",

			"RC_140Rnd_30mm_HEAB_QF_T_R",
			"RC_140Rnd_30mm_HEAB_QF_T_G",
			"RC_140Rnd_30mm_HEAB_QF_T_Y",
			"RC_140Rnd_30mm_cUAS",

			"RC_140Rnd_30mm_MP_T_R",
			"RC_140Rnd_30mm_MP_T_G",
			"RC_140Rnd_30mm_MP_T_Y",
			"RC_140Rnd_30mm_GPR_T_R",
			"RC_140Rnd_30mm_GPR_T_G",
			"RC_140Rnd_30mm_GPR_T_Y",

			"RC_140Rnd_30mm_APFSDS_T_R",
			"RC_140Rnd_30mm_APFSDS_T_G",
			"RC_140Rnd_30mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.2;
		};
	};
};


//Machineguns
class qav_abrams_coax;
class RC_QAV_AbramsX_HMG_coax_base: qav_abrams_coax
{
	class manual;
};
class RC_QAV_AbramsX_HMG_coax: RC_QAV_AbramsX_HMG_coax_base
{
	author="Ascent";
	displayName="coax HMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	FCSMaxLeadSpeed=100;
	autoReload=1;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	magazines[]=
	{
		"RC_150Rnd_127x99_SLAP_T_G",
		"RC_150Rnd_127x99_SLAP_T_R",
		"RC_150Rnd_127x99_SLAP_T_Y",
		"RC_150Rnd_127x99_T_G",
		"RC_150Rnd_127x99_T_R",
		"RC_150Rnd_127x99_T_Y"
	};
	class manual: manual
	{
		dispersion=0.001;
		reloadTime=0.1;
	};
};


class RC_autocannon_20mm;
class RC_AbramsX_20mm_coax_Base: RC_autocannon_20mm
{
	class HE;
	class AP;
	class player;
};
class RC_AbramsX_20mm_coax: RC_AbramsX_20mm_coax_Base
{
	author="Ascent";
	displayName="coax 20mm";
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
	FCSMaxLeadSpeed=100;

	class HE: HE
	{
		displayName="coax 20mm";
		FCSMaxLeadSpeed=100;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		magazines[]=
		{
			"RC_60Rnd_20mm_MP_Pen_T_R",
			"RC_60Rnd_20mm_MP_Pen_T_G",
			"RC_60Rnd_20mm_MP_Pen_T_Y",

			"RC_60Rnd_20mm_HE_Pen_T_R",
			"RC_60Rnd_20mm_HE_Pen_T_G",
			"RC_60Rnd_20mm_HE_Pen_T_Y",

			"RC_60Rnd_20mm_MP_DF_T_R",
			"RC_60Rnd_20mm_MP_DF_T_G",
			"RC_60Rnd_20mm_MP_DF_T_Y",

			"RC_60Rnd_20mm_HE_DF_T_R",
			"RC_60Rnd_20mm_HE_DF_T_G",
			"RC_60Rnd_20mm_HE_DF_T_Y",

			"RC_60Rnd_20mm_MP_QF_T_R",
			"RC_60Rnd_20mm_MP_QF_T_G",
			"RC_60Rnd_20mm_MP_QF_T_Y",

			"RC_60Rnd_20mm_HE_QF_T_R",
			"RC_60Rnd_20mm_HE_QF_T_G",
			"RC_60Rnd_20mm_HE_QF_T_Y",

			"RC_60Rnd_20mm_MPAB_DF_T_R",
			"RC_60Rnd_20mm_MPAB_DF_T_G",
			"RC_60Rnd_20mm_MPAB_DF_T_Y",

			"RC_60Rnd_20mm_HEAB_DF_T_R",
			"RC_60Rnd_20mm_HEAB_DF_T_G",
			"RC_60Rnd_20mm_HEAB_DF_T_Y",

			"RC_60Rnd_20mm_MPAB_QF_T_R",
			"RC_60Rnd_20mm_MPAB_QF_T_G",
			"RC_60Rnd_20mm_MPAB_QF_T_Y",

			"RC_60Rnd_20mm_HEAB_QF_T_R",
			"RC_60Rnd_20mm_HEAB_QF_T_G",
			"RC_60Rnd_20mm_HEAB_QF_T_Y",

			"RC_60Rnd_20mm_cUAS",

			"RC_60Rnd_20mm_HE_T_R",
			"RC_60Rnd_20mm_HE_T_G",
			"RC_60Rnd_20mm_HE_T_Y"
		};
		class player: player
		{
			reloadTime=0.25;
		};
	};
	class AP: AP
	{
		displayName="coax 20mm";
		FCSMaxLeadSpeed=100;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		magazines[]=
		{
			"RC_60Rnd_20mm_AP_T_R",
			"RC_60Rnd_20mm_AP_T_G",
			"RC_60Rnd_20mm_AP_T_Y",
			"RC_60Rnd_20mm_APFSDS_T_R",
			"RC_60Rnd_20mm_APFSDS_T_G",
			"RC_60Rnd_20mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.2;
		};
	};

	//selectionFireAnim="zasleh2";
	class GunParticles
	{
		class effect1
		{
			effectName="AutoCannonFired";
			positionName="Usti hlavne2";
			directionName="konec hlavne2";
		};
	};
};