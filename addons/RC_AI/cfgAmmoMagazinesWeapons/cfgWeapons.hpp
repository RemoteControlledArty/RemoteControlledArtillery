//Basegame
class RC_MMG_338_FSV_coax;
class RC_AI_MMG_338_FSV_coax_Base: RC_MMG_338_FSV_coax
{
	class manual;
};
class RC_AI_MMG_338_FSV_coax: RC_AI_MMG_338_FSV_coax_Base
{
	#include "\RC_AI\includes_weaponmags\mags_338.hpp"
};
class RC_AI_MMG_762x51_FSV_coax: RC_AI_MMG_338_FSV_coax_Base
{
	#include "\RC_AI\includes_weaponmags\mags_762x51.hpp"
};


class RC_MMG_338_coax_ext;
class RC_AI_MMG_338_coax_ext_Base: RC_MMG_338_FSV_coax
{
	class manual;
};
class RC_AI_MMG_338_coax_ext: RC_AI_MMG_338_coax_ext_Base
{
	#include "\RC_AI\includes_weaponmags\mags_338.hpp"
};
class RC_AI_MMG_762x51_coax_ext: RC_AI_MMG_338_coax_ext_Base
{
	#include "\RC_AI\includes_weaponmags\mags_762x51.hpp"
};


class RC_MMG_338_coax;
class RC_AI_MMG_338_coax_Base: RC_MMG_338_coax
{
	class manual;
};
class RC_AI_MMG_338_coax: RC_AI_MMG_338_coax_Base
{
	#include "\RC_AI\includes_weaponmags\mags_338.hpp"
};
class RC_AI_MMG_762x51_coax: RC_AI_MMG_338_coax_Base
{
	#include "\RC_AI\includes_weaponmags\mags_762x51.hpp"
};


class RC_MMG_93x64_coax_ext;
class RC_AI_MMG_93x64_coax_ext_Base: RC_MMG_93x64_coax_ext
{
	class manual;
};
class RC_AI_MMG_93x64_coax_ext: RC_AI_MMG_93x64_coax_ext_Base
{
	#include "\RC_AI\includes_weaponmags\mags_93x64.hpp"
};
class RC_AI_MMG_762x54_coax_ext: RC_AI_MMG_93x64_coax_ext_Base
{
	#include "\RC_AI\includes_weaponmags\mags_762x54.hpp"
};


class RC_MMG_93x64_coax;
class RC_AI_MMG_93x64_coax_Base: RC_MMG_93x64_coax
{
	class manual;
};
class RC_AI_MMG_93x64_coax: RC_AI_MMG_93x64_coax_Base
{
	#include "\RC_AI\includes_weaponmags\mags_93x64.hpp"
};
class RC_AI_MMG_762x54_coax: RC_AI_MMG_93x64_coax_Base
{
	#include "\RC_AI\includes_weaponmags\mags_762x54.hpp"
};


class RC_HMG_127x99_FSV;
class RC_AI_HMG_127x99_FSV: RC_HMG_127x99_FSV
{
	magazines[]=
	{
		"RC_AI_200Rnd_127x99_T_R",
		"RC_AI_200Rnd_127x99_T_G",
		"RC_AI_200Rnd_127x99_T_Y",
		"RC_AI_200Rnd_127x99_SLAP_T_R",
		"RC_AI_200Rnd_127x99_SLAP_T_G",
		"RC_AI_200Rnd_127x99_SLAP_T_Y",
		"RC_200Rnd_127x99_cUAS"
	};
};

class RC_HMG_127_NSVT;
class RC_AI_HMG_127_NSVT: RC_HMG_127_NSVT
{
	magazines[]=
	{
		"RC_AI_150Rnd_127x99_T_R",
		"RC_AI_150Rnd_127x99_T_G",
		"RC_AI_150Rnd_127x99_T_Y",
		"RC_AI_150Rnd_127x99_SLAP_T_R",
		"RC_AI_150Rnd_127x99_SLAP_T_G",
		"RC_AI_150Rnd_127x99_SLAP_T_Y",
		"RC_150Rnd_127x99_cUAS"
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
	class HE: HE
	{
		magazines[]=
		{
			"RC_AI_100Rnd_30mm_HE_Pen_T_R",
			"RC_AI_100Rnd_30mm_HE_Pen_T_G",
			"RC_AI_100Rnd_30mm_HE_Pen_T_Y",

			"RC_AI_100Rnd_30mm_HE_DF_T_R",
			"RC_AI_100Rnd_30mm_HE_DF_T_G",
			"RC_AI_100Rnd_30mm_HE_DF_T_Y",

			"RC_AI_100Rnd_30mm_HEAB_DF_T_R",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_G",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_Y",

			"RC_AI_100Rnd_30mm_MP_Pen_T_R",
			"RC_AI_100Rnd_30mm_MP_Pen_T_G",
			"RC_AI_100Rnd_30mm_MP_Pen_T_Y",

			"RC_AI_100Rnd_30mm_MP_DF_T_R",
			"RC_AI_100Rnd_30mm_MP_DF_T_G",
			"RC_AI_100Rnd_30mm_MP_DF_T_Y",

			"RC_AI_100Rnd_30mm_MPAB_DF_T_R",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_G",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_Y"
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


class RC_autocannon_30mm_APC_Wheeled_04;
class RC_AI_autocannon_30mm_APC_Wheeled_04_Base: RC_autocannon_30mm_APC_Wheeled_04
{
	class HE;
	class AP;
};
class RC_AI_autocannon_30mm_APC_Wheeled_04: RC_AI_autocannon_30mm_APC_Wheeled_04_Base
{
	class HE: HE
	{
		magazines[]=
		{
			"RC_AI_100Rnd_30mm_HE_Pen_T_R",
			"RC_AI_100Rnd_30mm_HE_Pen_T_G",
			"RC_AI_100Rnd_30mm_HE_Pen_T_Y",

			"RC_AI_100Rnd_30mm_HE_DF_T_R",
			"RC_AI_100Rnd_30mm_HE_DF_T_G",
			"RC_AI_100Rnd_30mm_HE_DF_T_Y",

			"RC_AI_100Rnd_30mm_HEAB_DF_T_R",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_G",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_Y",

			"RC_AI_100Rnd_30mm_MP_Pen_T_R",
			"RC_AI_100Rnd_30mm_MP_Pen_T_G",
			"RC_AI_100Rnd_30mm_MP_Pen_T_Y",

			"RC_AI_100Rnd_30mm_MP_DF_T_R",
			"RC_AI_100Rnd_30mm_MP_DF_T_G",
			"RC_AI_100Rnd_30mm_MP_DF_T_Y",

			"RC_AI_100Rnd_30mm_MPAB_DF_T_R",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_G",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_Y"
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


class RC_autocannon_30mm_Bu;
class RC_AI_autocannon_30mm_Bu_Base: RC_autocannon_30mm_Bu
{
	class HE;
	class AP;
};
class RC_AI_autocannon_30mm_Bu: RC_AI_autocannon_30mm_Bu_Base
{
	class HE: HE
	{
		magazines[]=
		{
			"RC_AI_100Rnd_30mm_HE_Pen_T_R",
			"RC_AI_100Rnd_30mm_HE_Pen_T_G",
			"RC_AI_100Rnd_30mm_HE_Pen_T_Y",

			"RC_AI_100Rnd_30mm_HE_DF_T_R",
			"RC_AI_100Rnd_30mm_HE_DF_T_G",
			"RC_AI_100Rnd_30mm_HE_DF_T_Y",

			"RC_AI_100Rnd_30mm_HEAB_DF_T_R",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_G",
			"RC_AI_100Rnd_30mm_HEAB_DF_T_Y",

			"RC_AI_100Rnd_30mm_MP_Pen_T_R",
			"RC_AI_100Rnd_30mm_MP_Pen_T_G",
			"RC_AI_100Rnd_30mm_MP_Pen_T_Y",

			"RC_AI_100Rnd_30mm_MP_DF_T_R",
			"RC_AI_100Rnd_30mm_MP_DF_T_G",
			"RC_AI_100Rnd_30mm_MP_DF_T_Y",

			"RC_AI_100Rnd_30mm_MPAB_DF_T_R",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_G",
			"RC_AI_100Rnd_30mm_MPAB_DF_T_Y"
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


class RC_autocannon_30mm_RCWS;
class RC_AI_autocannon_30mm_RCWS: RC_autocannon_30mm_RCWS
{
	magazines[]=
	{
		"RC_AI_60Rnd_30mm_HE_Pen_T_R",
		"RC_AI_60Rnd_30mm_HE_Pen_T_G",
		"RC_AI_60Rnd_30mm_HE_Pen_T_Y",

		"RC_AI_60Rnd_30mm_HE_DF_T_R",
		"RC_AI_60Rnd_30mm_HE_DF_T_G",
		"RC_AI_60Rnd_30mm_HE_DF_T_Y",

		"RC_AI_60Rnd_30mm_HEAB_DF_T_R",
		"RC_AI_60Rnd_30mm_HEAB_DF_T_G",
		"RC_AI_60Rnd_30mm_HEAB_DF_T_Y",

		"RC_AI_60Rnd_30mm_MP_Pen_T_R",
		"RC_AI_60Rnd_30mm_MP_Pen_T_G",
		"RC_AI_60Rnd_30mm_MP_Pen_T_Y",

		"RC_AI_60Rnd_30mm_MP_DF_T_R",
		"RC_AI_60Rnd_30mm_MP_DF_T_G",
		"RC_AI_60Rnd_30mm_MP_DF_T_Y",

		"RC_AI_60Rnd_30mm_MPAB_DF_T_R",
		"RC_AI_60Rnd_30mm_MPAB_DF_T_G",
		"RC_AI_60Rnd_30mm_MPAB_DF_T_Y",

		"RC_AI_60Rnd_30mm_APFSDS_T_R",
		"RC_AI_60Rnd_30mm_APFSDS_T_G",
		"RC_AI_60Rnd_30mm_APFSDS_T_Y",

		"RC_60Rnd_30mm_cUAS"
	};
};


class RC_autocannon_40mm_CTWS;
class RC_AI_autocannon_40mm_CTWS_Base: RC_autocannon_40mm_CTWS
{
	class HE;
	class AP;
	class player;
};
class RC_AI_autocannon_40mm_CTWS: RC_AI_autocannon_40mm_CTWS_Base
{
	class HE: HE
	{
		magazines[]=
		{
			"RC_AI_50Rnd_40mm_HE_Pen_T_R",
			"RC_AI_50Rnd_40mm_HE_Pen_T_G",
			"RC_AI_50Rnd_40mm_HE_Pen_T_Y",

			"RC_AI_50Rnd_40mm_HE_DF_T_R",
			"RC_AI_50Rnd_40mm_HE_DF_T_G",
			"RC_AI_50Rnd_40mm_HE_DF_T_Y",

			"RC_AI_50Rnd_40mm_HEAB_DF_T_R",
			"RC_AI_50Rnd_40mm_HEAB_DF_T_G",
			"RC_AI_50Rnd_40mm_HEAB_DF_T_Y",

			"RC_AI_50Rnd_40mm_MP_Pen_T_R",
			"RC_AI_50Rnd_40mm_MP_Pen_T_G",
			"RC_AI_50Rnd_40mm_MP_Pen_T_Y",

			"RC_AI_50Rnd_40mm_MP_DF_T_R",
			"RC_AI_50Rnd_40mm_MP_DF_T_G",
			"RC_AI_50Rnd_40mm_MP_DF_T_Y",

			"RC_AI_50Rnd_40mm_MPAB_DF_T_R",
			"RC_AI_50Rnd_40mm_MPAB_DF_T_G",
			"RC_AI_50Rnd_40mm_MPAB_DF_T_Y"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_AI_50Rnd_40mm_APFSDS_T_R",
			"RC_AI_50Rnd_40mm_APFSDS_T_G",
			"RC_AI_50Rnd_40mm_APFSDS_T_Y"
		};
	};
};


class RC_cannon_120mm;
class RC_AI_cannon_120mm: RC_cannon_120mm
{
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


class RC_cannon_125mm_advanced;
class RC_AI_cannon_125mm_advanced: RC_cannon_125mm_advanced
{
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

		"RC_2Rnd_IFV_MP_SACLOS",
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
};
class RC_AI_IFV_Missile_Launcher_4R: RC_AI_IFV_Missile_Launcher
{
	magazines[]=
	{	
		"RC_AI_4Rnd_IFV_MP_SACLOS",

		"RC_4Rnd_IFV_MP_SACLOS",
		"RC_4Rnd_IFV_MP_LOS",
		"RC_4Rnd_IFV_MP_Overfly",
		"RC_4Rnd_IFV_MP_NLOS",
		"RC_4Rnd_IFV_AA"
	};
};


//AbramsX
class RC_AbramsX_HMG_coax;
class RC_AI_AbramsX_HMG_coax: RC_AbramsX_HMG_coax
{
	magazines[]=
	{
		"RC_AI_300Rnd_127x99_SLAP_T_R",
		"RC_AI_300Rnd_127x99_SLAP_T_G",
		"RC_AI_300Rnd_127x99_SLAP_T_Y",
		"RC_AI_400Rnd_127x99_SLAP_T_G",
		"RC_AI_400Rnd_127x99_SLAP_T_R",
		"RC_AI_400Rnd_127x99_SLAP_T_Y"
	};
};


class RC_AbramsX_30mm_M914;
class RC_AI_AbramsX_30mm_M914_Base: RC_AbramsX_30mm_M914
{
	class HighROF;
};
class RC_AI_AbramsX_30mm_M914: RC_AI_AbramsX_30mm_M914_Base
{
	class HighROF: HighROF
	{
		magazines[]=
		{
			"RC_AI_140Rnd_30mm_HE_Pen_T_R",
			"RC_AI_140Rnd_30mm_HE_Pen_T_G",
			"RC_AI_140Rnd_30mm_HE_Pen_T_Y",

			"RC_AI_140Rnd_30mm_HE_DF_T_R",
			"RC_AI_140Rnd_30mm_HE_DF_T_G",
			"RC_AI_140Rnd_30mm_HE_DF_T_Y",

			"RC_AI_140Rnd_30mm_HEAB_DF_T_R",
			"RC_AI_140Rnd_30mm_HEAB_DF_T_G",
			"RC_AI_140Rnd_30mm_HEAB_DF_T_Y",

			"RC_AI_140Rnd_30mm_MP_Pen_T_R",
			"RC_AI_140Rnd_30mm_MP_Pen_T_G",
			"RC_AI_140Rnd_30mm_MP_Pen_T_Y",

			"RC_AI_140Rnd_30mm_MP_DF_T_R",
			"RC_AI_140Rnd_30mm_MP_DF_T_G",
			"RC_AI_140Rnd_30mm_MP_DF_T_Y",

			"RC_AI_140Rnd_30mm_MPAB_DF_T_R",
			"RC_AI_140Rnd_30mm_MPAB_DF_T_G",
			"RC_AI_140Rnd_30mm_MPAB_DF_T_Y",

			"RC_140Rnd_30mm_cUAS",

			"RC_AI_140Rnd_30mm_APFSDS_T_R",
			"RC_AI_140Rnd_30mm_APFSDS_T_G",
			"RC_AI_140Rnd_30mm_APFSDS_T_Y"
		};
	};
};


class RC_AbramsX_120mm_M360;
class RC_AI_AbramsX_120mm_M360: RC_AbramsX_120mm_M360
{
	magazines[]=
	{
		"RC_AI_20Rnd_120mm_APFSDS_X_T_R",
		"RC_AI_20Rnd_120mm_APFSDS_X_T_G",
		"RC_AI_20Rnd_120mm_APFSDS_X_T_Y",

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
		"RC_AI_5Rnd_120mm_MPAB_DF_T_R",
		"RC_AI_10Rnd_120mm_MPAB_DF_T_R",
		"RC_AI_15Rnd_120mm_MPAB_DF_T_R",

		"RC_AI_3Rnd_120mm_MPAB_DF_T_G",
		"RC_AI_5Rnd_120mm_MPAB_DF_T_G",
		"RC_AI_10Rnd_120mm_MPAB_DF_T_G",
		"RC_AI_15Rnd_120mm_MPAB_DF_T_G",

		"RC_AI_4Rnd_120mm_MPAB_DF_T_Y",
		"RC_AI_5Rnd_120mm_MPAB_DF_T_Y",
		"RC_AI_10Rnd_120mm_MPAB_DF_T_Y",
		"RC_AI_15Rnd_120mm_MPAB_DF_T_Y",

		"RC_3Rnd_120mm_DLG_LR_cannon_missiles",
		"RC_2Rnd_120mm_DLG_LR_cannon_missiles",
		"RC_1Rnd_120mm_DLG_LR_cannon_missiles",

		"RC_3Rnd_120mm_DLG_HVKEM",
		"RC_2Rnd_120mm_DLG_HVKEM",
		"RC_1Rnd_120mm_DLG_HVKEM"
	};
};


//RHS
class RC_RHS_weap_m240_abrams_coax;
class RC_AI_RHS_weap_m240_abrams_coax: RC_RHS_weap_m240_abrams_coax
{
	magazines[]=
	{
		"RC_AI_RHS_300Rnd_762x51_T_R",
		"RC_AI_RHS_300Rnd_762x51_M61_T_R"
	};
};


class RC_RHS_weap_m240_bradley_coax;
class RC_AI_RHS_weap_m240_bradley_coax: RC_RHS_weap_m240_bradley_coax
{
	magazines[]=
	{
		"RC_AI_RHS_400Rnd_762x51_T_R",
		"RC_AI_RHS_400Rnd_762x51_M61_T_R"
	};
};


class RC_RHS_M2_CROWS_M151;
class RC_AI_RHS_M2_CROWS_M151: RC_RHS_M2_CROWS_M151
{
	magazines[]=
	{
		"RC_AI_RHS_200rnd_127x99_T_R",
		"RC_AI_RHS_200rnd_127x99_SLAP_T_R"
	};
};


class RC_RHS_M2_CROWS_M153_Abrams;
class RC_AI_RHS_M2_CROWS_M153_Abrams: RC_RHS_M2_CROWS_M153_Abrams
{
	magazines[]=
	{
		"RC_AI_RHS_300rnd_127x99_T_R",
		"RC_AI_RHS_300rnd_127x99_SLAP_T_R"
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
	class HE: HE
	{
		magazines[]=
		{
			"RC_AI_RHS_110Rnd_25mm_HE_Pen_T_R",
			"RC_AI_RHS_110Rnd_25mm_HE_Pen_T_G",
			"RC_AI_RHS_110Rnd_25mm_HE_Pen_T_Y",

			"RC_AI_RHS_110Rnd_25mm_HE_DF_T_R",
			"RC_AI_RHS_110Rnd_25mm_HE_DF_T_G",
			"RC_AI_RHS_110Rnd_25mm_HE_DF_T_Y",

			"RC_AI_RHS_110Rnd_25mm_HEAB_DF_T_R",
			"RC_AI_RHS_110Rnd_25mm_HEAB_DF_T_G",
			"RC_AI_RHS_110Rnd_25mm_HEAB_DF_T_Y",

			"RC_AI_RHS_110Rnd_25mm_MP_Pen_T_R",
			"RC_AI_RHS_110Rnd_25mm_MP_Pen_T_G",
			"RC_AI_RHS_110Rnd_25mm_MP_Pen_T_Y",

			"RC_AI_RHS_110Rnd_25mm_MP_DF_T_R",
			"RC_AI_RHS_110Rnd_25mm_MP_DF_T_G",
			"RC_AI_RHS_110Rnd_25mm_MP_DF_T_Y",

			"RC_AI_RHS_110Rnd_25mm_MPAB_DF_T_R",
			"RC_AI_RHS_110Rnd_25mm_MPAB_DF_T_G",
			"RC_AI_RHS_110Rnd_25mm_MPAB_DF_T_Y"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_AI_RHS_70Rnd_25mm_APFSDS_T_R",
			"RC_AI_RHS_70Rnd_25mm_APFSDS_T_G",
			"RC_AI_RHS_70Rnd_25mm_APFSDS_T_Y"
		};
	};
};


class RC_RHS_weap_m256;
class RC_AI_RHS_weap_m256: RC_RHS_weap_m256
{
	magazines[]=
	{
		"RC_AI_20Rnd_120mm_APFSDS_T_R",
		"RC_AI_20Rnd_120mm_MP_T_R",
		"RC_AI_3Rnd_120mm_MPAB_DF_T_R",

		"RC_3Rnd_120mm_DLG_cannon_missiles",
		"RC_2Rnd_120mm_DLG_cannon_missiles",
		"RC_1Rnd_120mm_DLG_cannon_missiles",

		"RC_3Rnd_120mm_DLG_HVKEM",
		"RC_2Rnd_120mm_DLG_HVKEM",
		"RC_1Rnd_120mm_DLG_HVKEM"

		/*
		"RC_RHS_M829A4_20Rnd",
		"RC_RHS_M829A4_15Rnd",
		"RC_RHS_M829A4_10Rnd",

		"RC_RHS_M830A1_20Rnd",
		"RC_RHS_M830A1_15Rnd",
		"RC_RHS_M830A1_10Rnd",

		"RC_RHS_M1147_MPAB_DF_3Rnd",
		*/
	};
};


class RC_Bradley_Missile_Launcher;
class RC_AI_Bradley_Missile_Launcher: RC_Bradley_Missile_Launcher
{
	magazines[]=
	{
		"RC_AI_2Rnd_TOW_MP_SACLOS",

		"RC_2Rnd_TOW_MP_SACLOS",
		"RC_2Rnd_TOW_MP_LOS",
		"RC_2Rnd_TOW_MP_Overfly",
		"RC_2Rnd_TOW_MP_NLOS",
		"RC_2Rnd_TOW_AA"
	};
};


class RC_Stryker_Missile_Launcher;
class RC_AI_Stryker_Missile_Launcher: RC_Stryker_Missile_Launcher
{
	magazines[]=
	{
		"RC_AI_4Rnd_Javelin_MP_SACLOS",
		"RC_AI_3Rnd_Javelin_MP_SACLOS",
		"RC_AI_2Rnd_Javelin_MP_SACLOS",
		"RC_AI_1Rnd_Javelin_MP_SACLOS",

		"RC_4Rnd_Javelin_MP_SACLOS",
		"RC_3Rnd_Javelin_MP_SACLOS",
		"RC_2Rnd_Javelin_MP_SACLOS",
		"RC_1Rnd_Javelin_MP_SACLOS",
		"RC_4Rnd_Javelin_MP_LOS",
		"RC_3Rnd_Javelin_MP_LOS",
		"RC_2Rnd_Javelin_MP_LOS",
		"RC_1Rnd_Javelin_MP_LOS",
		"RC_4Rnd_Javelin_MP_Overfly",
		"RC_3Rnd_Javelin_MP_Overfly",
		"RC_2Rnd_Javelin_MP_Overfly",
		"RC_1Rnd_Javelin_MP_Overfly",
		"RC_4Rnd_Javelin_MP_NLOS",
		"RC_3Rnd_Javelin_MP_NLOS",
		"RC_2Rnd_Javelin_MP_NLOS",
		"RC_1Rnd_Javelin_MP_NLOS",
		"RC_4Rnd_Javelin_AA",
		"RC_3Rnd_Javelin_AA",
		"RC_2Rnd_Javelin_AA",
		"RC_1Rnd_Javelin_AA"
	};
};
