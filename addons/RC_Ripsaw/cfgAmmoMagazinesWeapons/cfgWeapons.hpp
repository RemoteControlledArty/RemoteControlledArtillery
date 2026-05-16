class QAV_ripsaw_mk30;
class RC_Ripsaw_Mk30_Fetch: QAV_ripsaw_mk30
{
	class AP;
	class HE;
	class player;
};
class RC_Ripsaw_Mk30: RC_Ripsaw_Mk30_Fetch
{
	displayName="Mk44 Bushmaster II 30mm";
	canLock=2;
	weaponLockSystem=0;
	maxZeroing=4000;
	autoReload=1;
	magazineReloadTime=20;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	class HE: HE
	{
		displayName="Mk44 Bushmaster II 30mm";
		canLock=2;
		weaponLockSystem=0;
		maxZeroing=4000;
		autoReload=1;
		magazineReloadTime=20;
		#include "\Remote_controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		class player: player
		{
			reloadTime=0.3;
			dispersion=0.0008;
		};

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
	};
	class AP: AP
	{
		displayName="Mk44 Bushmaster II 30mm";
		canLock=2;
		weaponLockSystem=0;
		maxZeroing=4000;
		autoReload=1;
		magazineReloadTime=20;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

		class player: player
		{
			reloadTime=0.3;
			dispersion=0.0008;
		};

		magazines[]=
		{
			"RC_200Rnd_30mm_APFSDS_T_R",
			"RC_200Rnd_30mm_APFSDS_T_G",
			"RC_200Rnd_30mm_APFSDS_T_Y"
		};
	};
};

class CannonCore;
class autocannon_35mm;
/*
class RC_Ripsaw_Mk30_cUAS_Fetch: autocannon_35mm
{
	class AP;
	class HE;
	class player;
};
*/
class RC_Ripsaw_Mk30_cUAS: autocannon_35mm
{
	displayName="Mk44 Bushmaster II 30mm";
	ballisticsComputer="2 + 4";
	canLock=2;
	weaponLockSystem=0;
	maxZeroing=4000;
	autoReload=1;
	magazineReloadTime=20;
	//#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"

	class AutoFast: CannonCore
	{
		displayName="Mk44 Bushmaster II 30mm";
		textureType="fastAuto";
		/*
		canLock=2;
		weaponLockSystem=0;
		maxZeroing=4000;
		autoReload=1;
		magazineReloadTime=20;
		#include "\Remote_controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
		*/

		reloadTime=0.05;
		dispersion=0.002;
	};
	class AutoSlow: AutoFast
	{
		displayName="Mk44 Bushmaster II 30mm";
		textureType="fullAuto";
		/*
		canLock=2;
		weaponLockSystem=0;
		maxZeroing=4000;
		autoReload=1;
		magazineReloadTime=20;
		#include "\Remote_controlled_Artillery\includes_cfg\BallisticsCalculatorAuto.hpp"
		*/

		reloadTime=0.15;
		dispersion=0.002;
	};

	magazines[]=
	{
		"RC_300Rnd_30mm_MPAB_AA_T_R",
		"RC_300Rnd_30mm_MPAB_AA_T_G",
		"RC_300Rnd_30mm_MPAB_AA_T_Y",

		"RC_300Rnd_30mm_HEAB_AA_T_R",
		"RC_300Rnd_30mm_HEAB_AA_T_G",
		"RC_300Rnd_30mm_HEAB_AA_T_Y",

		"RC_300Rnd_30mm_cUAS"
	};
};


class QAV_ripsaw_coax;
class RC_Ripsaw_coax_Fetch: QAV_ripsaw_coax
{
	class manual;
};
class RC_Ripsaw_coax: RC_Ripsaw_coax_Fetch
{
	displayName="coaxial MMG";
	canLock=2;
	maxZeroing=3000;
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"
	autoReload=1;
	magazineReloadTime=20;

	magazines[]=
	{
		"RC_200Rnd_762x51_T_R",
		"RC_200Rnd_762x51_T_G",
		"RC_200Rnd_762x51_T_Y"
	};
	class manual: manual
	{
		displayName="coaxial MMG";
		dispersion=0.001;
		reloadTime=0.0857;
	};
};
