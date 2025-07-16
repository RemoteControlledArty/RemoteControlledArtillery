class cannon_120mm_M360;
class RC_AbramsX_120mm_M360_base: cannon_120mm_M360
{
	class player;
};
class RC_AbramsX_120mm_M360: RC_AbramsX_120mm_M360_base
{
	author="Ascent";
	//displayName="120mm";
	canLock=2;
	weaponLockSystem=0;
	maxZeroing=6000;
	FCSZeroingDelay=0.5;
	FCSMaxLeadSpeed=100;
	reloadTime=4.5;
	magazineReloadTime=4.5;
	//ballisticsComputer="4";
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

		"RC_5Rnd_120mm_MP_T_R",
		"RC_10Rnd_120mm_MP_T_R",
		"RC_15Rnd_120mm_MP_T_R",
		"RC_20Rnd_120mm_MP_T_R",
		"RC_5Rnd_120mm_MP_T_G",
		"RC_10Rnd_120mm_MP_T_G",
		"RC_15Rnd_120mm_MP_T_G",
		"RC_20Rnd_120mm_MP_T_G",
		"RC_5Rnd_120mm_MP_T_Y",
		"RC_10Rnd_120mm_MP_T_Y",
		"RC_15Rnd_120mm_MP_T_Y",
		"RC_20Rnd_120mm_MP_T_Y",

		"RC_2Rnd_120mm_MPAB_DF_T_R",
		"RC_3Rnd_120mm_MPAB_DF_T_R",
		"RC_4Rnd_120mm_MPAB_DF_T_R",
		"RC_5Rnd_120mm_MPAB_DF_T_R",
		"RC_10Rnd_120mm_MPAB_DF_T_R",
		"RC_15Rnd_120mm_MPAB_DF_T_R",
		"RC_20Rnd_120mm_MPAB_DF_T_R",

		"RC_2Rnd_120mm_MPAB_DF_T_G",
		"RC_3Rnd_120mm_MPAB_DF_T_G",
		"RC_4Rnd_120mm_MPAB_DF_T_G",
		"RC_5Rnd_120mm_MPAB_DF_T_G",
		"RC_10Rnd_120mm_MPAB_DF_T_G",
		"RC_15Rnd_120mm_MPAB_DF_T_G",
		"RC_20Rnd_120mm_MPAB_DF_T_G",

		"RC_2Rnd_120mm_MPAB_DF_T_Y",
		"RC_3Rnd_120mm_MPAB_DF_T_Y",
		"RC_4Rnd_120mm_MPAB_DF_T_Y",
		"RC_5Rnd_120mm_MPAB_DF_T_Y",
		"RC_10Rnd_120mm_MPAB_DF_T_Y",
		"RC_15Rnd_120mm_MPAB_DF_T_Y",
		"RC_20Rnd_120mm_MPAB_DF_T_Y",

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
		
		"RC_5Rnd_120mm_DLG_LR_cannon_missiles",
		"RC_4Rnd_120mm_DLG_LR_cannon_missiles",
		"RC_3Rnd_120mm_DLG_LR_cannon_missiles",
		"RC_2Rnd_120mm_DLG_LR_cannon_missiles",
		"RC_1Rnd_120mm_DLG_LR_cannon_missiles",

		"RC_5Rnd_120mm_DLG_HVKEM",
		"RC_4Rnd_120mm_DLG_HVKEM",
		"RC_3Rnd_120mm_DLG_HVKEM",
		"RC_2Rnd_120mm_DLG_HVKEM",
		"RC_1Rnd_120mm_DLG_HVKEM"
	};
	class player: player
	{
		reloadTime=4.5;
		dispersion=0.0003;
	};
	class Cruise: Player
	{
		displayName="$STR_A3_firemode_terrain0";
		textureType="terrain";
		minRange=150;
		minRangeProbab=0.40000001;
		midRange=400;
		midRangeProbab=0.94999999;
		maxRange=6000;
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
		maxRange=6000;
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
class RC_AbramsX_30mm_M914_Base: autocannon_30mm_M914
{
	class HighROF;
	class player;
};
class RC_AbramsX_30mm_M914: RC_AbramsX_30mm_M914_Base
{
	author="Ascent";
	//displayName="30mm";
	canLock=2;
	weaponLockSystem=0;
	FCSZeroingDelay=0.5;
	maxZeroing=4000;
	FCSMaxLeadSpeed=100;
	autoReload=1;
	magazineReloadTime=20;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	class HighROF: HighROF
	{
		canLock=2;
		weaponLockSystem=0;
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
			dispersion=0.0008;
		};
	};
};


class autocannon_30mm_M914_twin;
class RC_AbramsX_30mm_M914_twin_Base: autocannon_30mm_M914_twin
{
	class HighROF;
	class player;
};
class RC_AbramsX_30mm_M914_twin: RC_AbramsX_30mm_M914_twin_Base
{
	author="Ascent";
	//displayName="30mm";
	canLock=2;
	weaponLockSystem=0;
	FCSZeroingDelay=0.5;
	maxZeroing=4000;
	FCSMaxLeadSpeed=100;
	autoReload=1;
	magazineReloadTime=25;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	class HighROF: HighROF
	{
		canLock=2;
		weaponLockSystem=0;
		FCSZeroingDelay=0.5;
		maxZeroing=4000;
		FCSMaxLeadSpeed=100;
		autoReload=1;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		magazines[]=
		{
			"RC_200Rnd_30mm_MP_Pen_T_R",
			"RC_200Rnd_30mm_MP_Pen_T_G",
			"RC_200Rnd_30mm_MP_Pen_T_Y",

			"RC_200Rnd_30mm_HE_Pen_T_R",
			"RC_200Rnd_30mm_HE_Pen_T_G",
			"RC_200Rnd_30mm_HE_Pen_T_Y",

			"RC_200Rnd_30mm_MP_DF_T_R",
			"RC_200Rnd_30mm_MP_DF_T_G",
			"RC_200Rnd_30mm_MP_DF_T_Y",

			"RC_200Rnd_30mm_HE_DF_T_R",
			"RC_200Rnd_30mm_HE_DF_T_G",
			"RC_200Rnd_30mm_HE_DF_T_Y",

			"RC_200Rnd_30mm_MP_QF_T_R",
			"RC_200Rnd_30mm_MP_QF_T_G",
			"RC_200Rnd_30mm_MP_QF_T_Y",

			"RC_200Rnd_30mm_HE_QF_T_R",
			"RC_200Rnd_30mm_HE_QF_T_G",
			"RC_200Rnd_30mm_HE_QF_T_Y",

			"RC_200Rnd_30mm_MPAB_DF_T_R",
			"RC_200Rnd_30mm_MPAB_DF_T_G",
			"RC_200Rnd_30mm_MPAB_DF_T_Y",

			"RC_200Rnd_30mm_HEAB_DF_T_R",
			"RC_200Rnd_30mm_HEAB_DF_T_G",
			"RC_200Rnd_30mm_HEAB_DF_T_Y",

			"RC_200Rnd_30mm_MPAB_QF_T_R",
			"RC_200Rnd_30mm_MPAB_QF_T_G",
			"RC_200Rnd_30mm_MPAB_QF_T_Y",

			"RC_200Rnd_30mm_HEAB_QF_T_R",
			"RC_200Rnd_30mm_HEAB_QF_T_G",
			"RC_200Rnd_30mm_HEAB_QF_T_Y",
			"RC_200Rnd_30mm_cUAS",

			"RC_200Rnd_30mm_MP_T_R",
			"RC_200Rnd_30mm_MP_T_G",
			"RC_200Rnd_30mm_MP_T_Y",
			"RC_200Rnd_30mm_GPR_T_R",
			"RC_200Rnd_30mm_GPR_T_G",
			"RC_200Rnd_30mm_GPR_T_Y",

			"RC_200Rnd_30mm_APFSDS_T_R",
			"RC_200Rnd_30mm_APFSDS_T_G",
			"RC_200Rnd_30mm_APFSDS_T_Y"
		};
		class player: player
		{
			dispersion=0.0008;
		};
	};
};


class RC_AbramsX_20mm_coax: RC_AbramsX_30mm_M914
{
	displayName="coax 20mm";

	class HighROF: HighROF
	{
		displayName="coax 20mm";

		magazines[]=
		{
			"RC_200Rnd_20mm_MP_Pen_T_R",
			"RC_200Rnd_20mm_MP_Pen_T_G",
			"RC_200Rnd_20mm_MP_Pen_T_Y",

			"RC_200Rnd_20mm_HE_Pen_T_R",
			"RC_200Rnd_20mm_HE_Pen_T_G",
			"RC_200Rnd_20mm_HE_Pen_T_Y",

			"RC_200Rnd_20mm_MP_DF_T_R",
			"RC_200Rnd_20mm_MP_DF_T_G",
			"RC_200Rnd_20mm_MP_DF_T_Y",

			"RC_200Rnd_20mm_HE_DF_T_R",
			"RC_200Rnd_20mm_HE_DF_T_G",
			"RC_200Rnd_20mm_HE_DF_T_Y",

			"RC_200Rnd_20mm_MP_QF_T_R",
			"RC_200Rnd_20mm_MP_QF_T_G",
			"RC_200Rnd_20mm_MP_QF_T_Y",

			"RC_200Rnd_20mm_HE_QF_T_R",
			"RC_200Rnd_20mm_HE_QF_T_G",
			"RC_200Rnd_20mm_HE_QF_T_Y",

			"RC_200Rnd_20mm_MPAB_DF_T_R",
			"RC_200Rnd_20mm_MPAB_DF_T_G",
			"RC_200Rnd_20mm_MPAB_DF_T_Y",

			"RC_200Rnd_20mm_HEAB_DF_T_R",
			"RC_200Rnd_20mm_HEAB_DF_T_G",
			"RC_200Rnd_20mm_HEAB_DF_T_Y",

			"RC_200Rnd_20mm_MPAB_QF_T_R",
			"RC_200Rnd_20mm_MPAB_QF_T_G",
			"RC_200Rnd_20mm_MPAB_QF_T_Y",

			"RC_200Rnd_20mm_HEAB_QF_T_R",
			"RC_200Rnd_20mm_HEAB_QF_T_G",
			"RC_200Rnd_20mm_HEAB_QF_T_Y",
			"RC_200Rnd_20mm_cUAS",
			
			"RC_200Rnd_20mm_HE_T_R",
			"RC_200Rnd_20mm_HE_T_G",
			"RC_200Rnd_20mm_HE_T_Y",

			"RC_200Rnd_20mm_AP_T_R",
			"RC_200Rnd_20mm_AP_T_G",
			"RC_200Rnd_20mm_AP_T_Y",
			"RC_200Rnd_20mm_APFSDS_T_R",
			"RC_200Rnd_20mm_APFSDS_T_G",
			"RC_200Rnd_20mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.25;
			dispersion=0.0008;
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


/*
class RC_autocannon_30mm_CTWS;
class RC_autocannon_30mm_M914_twin_Base: RC_autocannon_30mm_CTWS
{
	class HE;
	class AP;
	class player;
};
class RC_autocannon_30mm_M914_twin: RC_autocannon_30mm_M914_twin_Base
{
	author="Ascent";
	displayName="Twin M914 30mm";
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
	FCSMaxLeadSpeed=100;

	class HE: HE
	{
		displayName="M914 30mm";
		FCSMaxLeadSpeed=100;
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
			dispersion=0.0008;
		};
	};
	class AP: AP
	{
		displayName="M914 30mm";
		FCSMaxLeadSpeed=100;
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
			dispersion=0.0008;
		};
	};

	class GunParticles
	{
		class Effect1
		{
			effectName="AutoCannonFired";
			positionName="usti hlavne3";
			directionName="konec hlavne3";
		};
		class Effect2
		{
			effectName="QAV_mk30_casingeject";
			positionName="nabojnicestart";
			directionName="nabojniceend";
		};
		class Effect3
		{
			effectName="QAV_mk30_casingeject";
			positionName="nabojnicestart_2";
			directionName="nabojniceend_2";
		};
	};
};
*/


//Machineguns
class qav_abrams_coax;
class RC_AbramsX_HMG_coax_base: qav_abrams_coax
{
	class manual;
};
class RC_AbramsX_HMG_coax: RC_AbramsX_HMG_coax_base
{
	author="Ascent";
	displayName="coax HMG";
	canLock=2;
	weaponLockSystem=0;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	FCSMaxLeadSpeed=100;
	autoReload=1;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	magazines[]=
	{
		"RC_400Rnd_127x99_SLAP_T_G",
		"RC_400Rnd_127x99_SLAP_T_R",
		"RC_400Rnd_127x99_SLAP_T_Y"
	};
	class manual: manual
	{
		dispersion=0.0008;
		reloadTime=0.1;
	};
};


class RC_autocannon_20mm_CTWS;
class RC_AbramsX_20mm_coax_Base: RC_autocannon_20mm_CTWS
{
	class HE;
	class AP;
	class player;
};
class RC_AbramsX_20mm_DualFed_coax: RC_AbramsX_20mm_coax_Base
{
	author="Ascent";
	displayName="coax 20mm dualfed";
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
	FCSMaxLeadSpeed=100;
	//type="1+4";

	class HE: HE
	{
		displayName="coax 20mm";
		FCSMaxLeadSpeed=100;
		//type="1+4";
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		class player: player
		{
			dispersion=0.0008;
		};
	};
	class AP: AP
	{
		displayName="coax 20mm";
		FCSMaxLeadSpeed=100;
		//type="1+4";
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		class player: player
		{
			dispersion=0.0008;
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