class EF_autocannon_30mm_AAV9;
class RC_EF_autocannon_30mm_Base: EF_autocannon_30mm_AAV9
{
	class HE;
	class AP;
	class player;
};
class RC_EF_autocannon_30mm: RC_EF_autocannon_30mm_Base
{
	displayName="XM913";
	magazineReloadTime=30;	//40
	//canLock=2;
	maxZeroing=4000;

	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
	cursorAim="mg";

	class HE: HE
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
		cursorAim="mg";

		magazines[]=
		{
			"RC_100Rnd_30mm_MPAB_DF_T_R",
			"RC_100Rnd_30mm_MPAB_DF_T_G",
			"RC_100Rnd_30mm_MPAB_DF_T_Y",

			"RC_EF_100Rnd_30mm_HEAB_T_W",
			"RC_EF_100Rnd_30mm_HEAB_T_R",
			"RC_EF_100Rnd_30mm_HEAB_T_G",
			"RC_EF_100Rnd_30mm_HEAB_T_Y"
		};
		class player: player
		{
			dispersion=0.0008;
		};
	};
	class AP: AP
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
		cursorAim="mg";

		magazines[]=
		{
			"RC_EF_100Rnd_30mm_APFSDS_T_W",
			"RC_EF_100Rnd_30mm_APFSDS_T_R",
			"RC_EF_100Rnd_30mm_APFSDS_T_G",
			"RC_EF_100Rnd_30mm_APFSDS_T_Y"
		};
		class player: player
		{
			dispersion=0.0008;
		};
	};
};


class EF_autocannon_50mm_AAV9;
class RC_EF_autocannon_50mm_Base: EF_autocannon_50mm_AAV9
{
	class HE;
	class AP;
	class player;
};
class RC_EF_autocannon_50mm: RC_EF_autocannon_50mm_Base
{
	displayName="XM913";
	magazineReloadTime=30;	//40
	//canLock=2;
	maxZeroing=4000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
	cursorAim="mg";

	class HE: HE
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
		cursorAim="mg";

		magazines[]=
		{
			"RC_60Rnd_50mm_MPAB_DF_T_R",
			"RC_60Rnd_50mm_MPAB_DF_T_G",
			"RC_60Rnd_50mm_MPAB_DF_T_Y",

			"RC_EF_60Rnd_50mm_HEAB_T_W",
			"RC_EF_60Rnd_50mm_HEAB_T_R",
			"RC_EF_60Rnd_50mm_HEAB_T_G",
			"RC_EF_60Rnd_50mm_HEAB_T_Y"
		};
		class player: player
		{
			dispersion=0.0008;
		};
	};
	class AP: AP
	{
		displayName="XM913";
		magazineReloadTime=30;	//40
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
		cursorAim="mg";

		magazines[]=
		{
			"RC_EF_60Rnd_50mm_APFSDS_T_W",
			"RC_EF_60Rnd_50mm_APFSDS_T_R",
			"RC_EF_60Rnd_50mm_APFSDS_T_G",
			"RC_EF_60Rnd_50mm_APFSDS_T_Y"
		};
		class player: player
		{
			dispersion=0.0008;
		};
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
	maxZeroing=3000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
	
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