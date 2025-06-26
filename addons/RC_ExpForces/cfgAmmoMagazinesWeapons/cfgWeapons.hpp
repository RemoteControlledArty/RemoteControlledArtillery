class EF_autocannon_30mm_AAV9;
class RC_EF_autocannon_30mm_Base: EF_autocannon_30mm_AAV9
{
	class HE;
	class AP;
};
class RC_EF_autocannon_30mm: RC_EF_autocannon_30mm_Base
{
	displayName="XM913";
	magazineReloadTime=30;	//40
	//canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=4000;

	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	cursorAim="mg";

	class HE: HE
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		FCSZeroingDelay=0.5;
		maxZeroing=4000;

		magazines[]=
		{
			"RC_120Rnd_30mm_MP_Pen_T_R",
			"RC_120Rnd_30mm_MP_Pen_T_G",
			"RC_120Rnd_30mm_MP_Pen_T_Y",
			
			"RC_120Rnd_30mm_MP_QF_T_R",
			"RC_120Rnd_30mm_MP_QF_T_G",
			"RC_120Rnd_30mm_MP_QF_T_Y",

			"RC_120Rnd_30mm_MP_DF_T_R",
			"RC_120Rnd_30mm_MP_DF_T_G",
			"RC_120Rnd_30mm_MP_DF_T_Y",


			"RC_120Rnd_30mm_HE_Pen_T_R",
			"RC_120Rnd_30mm_HE_Pen_T_G",
			"RC_120Rnd_30mm_HE_Pen_T_Y",
			
			"RC_120Rnd_30mm_HE_QF_T_R",
			"RC_120Rnd_30mm_HE_QF_T_G",
			"RC_120Rnd_30mm_HE_QF_T_Y",

			"RC_120Rnd_30mm_HE_DF_T_R",
			"RC_120Rnd_30mm_HE_DF_T_G",
			"RC_120Rnd_30mm_HE_DF_T_Y"
		};

		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		cursorAim="mg";
	};
	class AP: AP
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		FCSZeroingDelay=0.5;
		maxZeroing=4000;

		magazines[]=
		{
			"RC_EF_80Rnd_30mm_APFSDS_T_W",
			"RC_EF_80Rnd_30mm_APFSDS_T_R",
			"RC_EF_80Rnd_30mm_APFSDS_T_G",
			"RC_EF_80Rnd_30mm_APFSDS_T_Y"
		};

		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		cursorAim="mg";
	};
};


class EF_autocannon_50mm_AAV9;
class RC_EF_autocannon_50mm_Base: EF_autocannon_50mm_AAV9
{
	class HE;
	class AP;
};
class RC_EF_autocannon_50mm: RC_EF_autocannon_50mm_Base
{
	displayName="XM913";
	magazineReloadTime=30;	//40
	//canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=4000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
	cursorAim="mg";

	class HE: HE
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		FCSZeroingDelay=0.5;
		maxZeroing=4000;

		magazines[]=
		{
			"RC_120Rnd_50mm_MP_Pen_T_R",
			"RC_120Rnd_50mm_MP_Pen_T_G",
			"RC_120Rnd_50mm_MP_Pen_T_Y",
			
			"RC_120Rnd_50mm_MP_QF_T_R",
			"RC_120Rnd_50mm_MP_QF_T_G",
			"RC_120Rnd_50mm_MP_QF_T_Y",

			"RC_120Rnd_50mm_MP_DF_T_R",
			"RC_120Rnd_50mm_MP_DF_T_G",
			"RC_120Rnd_50mm_MP_DF_T_Y",


			"RC_120Rnd_50mm_HE_Pen_T_R",
			"RC_120Rnd_50mm_HE_Pen_T_G",
			"RC_120Rnd_50mm_HE_Pen_T_Y",
			
			"RC_120Rnd_50mm_HE_QF_T_R",
			"RC_120Rnd_50mm_HE_QF_T_G",
			"RC_120Rnd_50mm_HE_QF_T_Y",

			"RC_120Rnd_50mm_HE_DF_T_R",
			"RC_120Rnd_50mm_HE_DF_T_G",
			"RC_120Rnd_50mm_HE_DF_T_Y"
		};

		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		cursorAim="mg";
	};
	class AP: AP
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		FCSZeroingDelay=0.5;
		maxZeroing=4000;

		magazines[]=
		{
			"RC_EF_50Rnd_50mm_APFSDS_T_W",
			"RC_EF_50Rnd_50mm_APFSDS_T_R",
			"RC_EF_50Rnd_50mm_APFSDS_T_G",
			"RC_EF_50Rnd_50mm_APFSDS_T_Y"
		};

		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		cursorAim="mg";
	};
};


class EF_LMG_coax_AAV9;
class RC_EF_MMG_coax_Base: EF_LMG_coax_AAV9
{
	class manual;
};
class RC_EF_MMG_coax: RC_EF_MMG_coax_Base
{
	displayName="coaxial";
	magazineReloadTime=30;	//40
	canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=3000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"
	
	magazines[]=
	{
		"RC_400Rnd_338_T_W",
		"RC_400Rnd_338_T_R",
		"RC_400Rnd_338_T_G",
		"RC_400Rnd_338_T_Y"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
		reloadTime=0.0857;
	};
};