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
			dispersion=0.0008;
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
			dispersion=0.0008;
		};
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
