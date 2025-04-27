//Autocannons
class autocannon_30mm_lxWS;
class RC_autocannon_30mm_lxWS_Base: autocannon_30mm_lxWS
{
	class HE;
	class AP;
	class player;
};
class RC_autocannon_30mm_lxWS: RC_autocannon_30mm_lxWS_Base
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
			"RC_160Rnd_30mm_MP_Pen_T_R",
			"RC_160Rnd_30mm_MP_Pen_T_G",
			"RC_160Rnd_30mm_MP_Pen_T_Y",

			"RC_160Rnd_30mm_HE_Pen_T_R",
			"RC_160Rnd_30mm_HE_Pen_T_G",
			"RC_160Rnd_30mm_HE_Pen_T_Y",

			"RC_160Rnd_30mm_MP_DF_T_R",
			"RC_160Rnd_30mm_MP_DF_T_G",
			"RC_160Rnd_30mm_MP_DF_T_Y",

			"RC_160Rnd_30mm_HE_DF_T_R",
			"RC_160Rnd_30mm_HE_DF_T_G",
			"RC_160Rnd_30mm_HE_DF_T_Y",

			"RC_160Rnd_30mm_MP_QF_T_R",
			"RC_160Rnd_30mm_MP_QF_T_G",
			"RC_160Rnd_30mm_MP_QF_T_Y",

			"RC_160Rnd_30mm_HE_QF_T_R",
			"RC_160Rnd_30mm_HE_QF_T_G",
			"RC_160Rnd_30mm_HE_QF_T_Y",

			"RC_160Rnd_30mm_MPAB_DF_T_R",
			"RC_160Rnd_30mm_MPAB_DF_T_G",
			"RC_160Rnd_30mm_MPAB_DF_T_Y",

			"RC_160Rnd_30mm_HEAB_DF_T_R",
			"RC_160Rnd_30mm_HEAB_DF_T_G",
			"RC_160Rnd_30mm_HEAB_DF_T_Y",

			"RC_160Rnd_30mm_MPAB_QF_T_R",
			"RC_160Rnd_30mm_MPAB_QF_T_G",
			"RC_160Rnd_30mm_MPAB_QF_T_Y",

			"RC_160Rnd_30mm_HEAB_QF_T_R",
			"RC_160Rnd_30mm_HEAB_QF_T_G",
			"RC_160Rnd_30mm_HEAB_QF_T_Y",
			"RC_160Rnd_30mm_cUAS",

			"RC_160Rnd_30mm_MP_T_R",
			"RC_160Rnd_30mm_MP_T_G",
			"RC_160Rnd_30mm_MP_T_Y",
			"RC_160Rnd_30mm_GPR_T_R",
			"RC_160Rnd_30mm_GPR_T_G",
			"RC_160Rnd_30mm_GPR_T_Y"
		};
		class player: player
		{
			reloadTime=0.15;
		};
	};
	class AP: AP
	{
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		magazines[]=
		{
			"RC_160Rnd_30mm_APFSDS_T_R",
			"RC_160Rnd_30mm_APFSDS_T_G",
			"RC_160Rnd_30mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.3;
		};
	};
};


class autocannon_30mm_APC_Wheeled_04;
class RC_autocannon_30mm_APC_Wheeled_04_Base: autocannon_30mm_APC_Wheeled_04
{
	class HE;
	class AP;
	class player;
};
class RC_autocannon_30mm_APC_Wheeled_04: RC_autocannon_30mm_APC_Wheeled_04_Base
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
			"RC_160Rnd_30mm_MP_Pen_T_R",
			"RC_160Rnd_30mm_MP_Pen_T_G",
			"RC_160Rnd_30mm_MP_Pen_T_Y",

			"RC_160Rnd_30mm_HE_Pen_T_R",
			"RC_160Rnd_30mm_HE_Pen_T_G",
			"RC_160Rnd_30mm_HE_Pen_T_Y",

			"RC_160Rnd_30mm_MP_DF_T_R",
			"RC_160Rnd_30mm_MP_DF_T_G",
			"RC_160Rnd_30mm_MP_DF_T_Y",

			"RC_160Rnd_30mm_HE_DF_T_R",
			"RC_160Rnd_30mm_HE_DF_T_G",
			"RC_160Rnd_30mm_HE_DF_T_Y",

			"RC_160Rnd_30mm_MP_QF_T_R",
			"RC_160Rnd_30mm_MP_QF_T_G",
			"RC_160Rnd_30mm_MP_QF_T_Y",

			"RC_160Rnd_30mm_HE_QF_T_R",
			"RC_160Rnd_30mm_HE_QF_T_G",
			"RC_160Rnd_30mm_HE_QF_T_Y",

			"RC_160Rnd_30mm_MPAB_DF_T_R",
			"RC_160Rnd_30mm_MPAB_DF_T_G",
			"RC_160Rnd_30mm_MPAB_DF_T_Y",

			"RC_160Rnd_30mm_HEAB_DF_T_R",
			"RC_160Rnd_30mm_HEAB_DF_T_G",
			"RC_160Rnd_30mm_HEAB_DF_T_Y",

			"RC_160Rnd_30mm_MPAB_QF_T_R",
			"RC_160Rnd_30mm_MPAB_QF_T_G",
			"RC_160Rnd_30mm_MPAB_QF_T_Y",

			"RC_160Rnd_30mm_HEAB_QF_T_R",
			"RC_160Rnd_30mm_HEAB_QF_T_G",
			"RC_160Rnd_30mm_HEAB_QF_T_Y",
			"RC_160Rnd_30mm_cUAS",

			"RC_160Rnd_30mm_MP_T_R",
			"RC_160Rnd_30mm_MP_T_G",
			"RC_160Rnd_30mm_MP_T_Y",
			"RC_160Rnd_30mm_GPR_T_R",
			"RC_160Rnd_30mm_GPR_T_G",
			"RC_160Rnd_30mm_GPR_T_Y"
		};
		class player: player
		{
			reloadTime=0.15;
		};
	};
	class AP: AP
	{
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		magazines[]=
		{
			"RC_160Rnd_30mm_APFSDS_T_R",
			"RC_160Rnd_30mm_APFSDS_T_G",
			"RC_160Rnd_30mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.3;
		};
	};
};


class RC_MMG_93x64_coax_ext;
class RC_MMG_93x64_coax_ext_lxWS: RC_MMG_93x64_coax_ext
{
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"
	magazines[]=
	{
		"RC_1000Rnd_93x64_T_G",
		"RC_1000Rnd_93x64_T_R",
		"RC_1000Rnd_93x64_T_Y"
	};
};


/*
class missles_Vorona_vehicles_lxWS;
class RC_missles_Vorona_vehicles_lxWS_Base: missles_Vorona_vehicles_lxWS
{
	class Player;
	class TopDown;
};
class RC_missles_Vorona_vehicles_lxWS: RC_missles_Vorona_vehicles_lxWS_Base
{
	scope=2;
};
*/
