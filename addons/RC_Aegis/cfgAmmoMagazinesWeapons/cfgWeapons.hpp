class Aegis_NVG_IVAS_01_tan_F;
class RC_SO_Goggles_tan_Base: Aegis_NVG_IVAS_01_tan_F
{
	scope=0;
	scopeArsenal=0;
	class ItemInfo;
};
class RC_SO_Goggles_tan: RC_SO_Goggles_tan_Base
{
	scope=2;
	scopeArsenal=2;
	displayName="Systems-Operator Goggles";
	visionMode[]=
	{
		"Normal"
	};
	class ItemInfo: ItemInfo
	{
		mass=20;
	};
};
class RC_SO_Goggles_NV_tan: RC_SO_Goggles_tan
{
	displayName="Systems-Operator Goggles NV";
	visionMode[]=
	{
		"Normal",
		"NVG"
	};
};
class RC_SO_Goggles_TI_tan: RC_SO_Goggles_tan
{
	displayName="Systems-Operator Goggles TI";
	visionMode[]=
	{
		"Normal",
		"NVG",
		"TI"
	};
};


class Aegis_NVG_IVAS_01_blk_F;
class RC_SO_Goggles_blk_Base: Aegis_NVG_IVAS_01_blk_F
{
	scope=0;
	scopeArsenal=0;
	class ItemInfo;
};
class RC_SO_Goggles_blk: RC_SO_Goggles_blk_Base
{
	scope=2;
	scopeArsenal=2;
	displayName="Systems-Operator Goggles";
	visionMode[]=
	{
		"Normal"
	};
	class ItemInfo: ItemInfo
	{
		mass=20;
	};
};
class RC_SO_Goggles_NV_blk: RC_SO_Goggles_blk
{
	displayName="Systems-Operator Goggles NV";
	visionMode[]=
	{
		"Normal",
		"NVG"
	};
};
class RC_SO_Goggles_TI_blk: RC_SO_Goggles_blk
{
	displayName="Systems-Operator Goggles TI";
	visionMode[]=
	{
		"Normal",
		"NVG",
		"TI"
	};
};


class Aegis_NVG_IVAS_01_grn_F;
class RC_SO_Goggles_grn_Base: Aegis_NVG_IVAS_01_grn_F
{
	scope=0;
	scopeArsenal=0;
	class ItemInfo;
};
class RC_SO_Goggles_grn: RC_SO_Goggles_grn_Base
{
	scope=2;
	scopeArsenal=2;
	displayName="Systems-Operator Goggles";
	visionMode[]=
	{
		"Normal"
	};
	class ItemInfo: ItemInfo
	{
		mass=20;
	};
};
class RC_SO_Goggles_NV_grn: RC_SO_Goggles_grn
{
	displayName="Systems-Operator Goggles NV";
	visionMode[]=
	{
		"Normal",
		"NVG"
	};
};
class RC_SO_Goggles_TI_grn: RC_SO_Goggles_grn
{
	displayName="Systems-Operator Goggles TI";
	visionMode[]=
	{
		"Normal",
		"NVG",
		"TI"
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


class RC_autocannon_30mm_Bu: RC_autocannon_30mm_APC_Wheeled_04
{
	class GunParticles
	{
		directionName="konec hlavne";
		effectName="AutoCannonFired";
		positionName="usti hlavne";
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
