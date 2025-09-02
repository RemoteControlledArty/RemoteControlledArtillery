//Launcher
class RC_IFV_Missile_Launcher;
class RC_SPz_Spike: RC_IFV_Missile_Launcher
{
	displayName="Spike Launcher";
	displayNameShort="Spike Launcher";
	magazines[]=
	{
		"RC_2Rnd_SPz_Spike_NLOS",
		"RC_2Rnd_SPz_Spike_AA"
	};
};


//Autocannon
class autocannon_Base_F;
class RC_MK30_Base: autocannon_Base_F
{
	class player;
	class close;
	class short;
	class medium;
	class far;
};
class RC_MK30: RC_MK30_Base
{
	displayName="MK30";

	modes[]=
	{
		"player",
		"close",
		"short",
		"medium",
		"far"
	};
	muzzles[]=
	{
		"HE",
		"AP"
	};

	class HE: autocannon_Base_F
	{
		displayName="MK30";
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		//#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"

		magazines[]=
		{
			"RC_160Rnd_30mm_ABM_T_R",
			"RC_160Rnd_30mm_ABM_T_G",
			"RC_160Rnd_30mm_ABM_T_Y",

			"RC_160Rnd_30mm_MP_Pen_T_R",
			"RC_160Rnd_30mm_MP_Pen_T_G",
			"RC_160Rnd_30mm_MP_Pen_T_Y",

			"RC_160Rnd_30mm_MP_DF_T_R",
			"RC_160Rnd_30mm_MP_DF_T_G",
			"RC_160Rnd_30mm_MP_DF_T_Y",

			"RC_160Rnd_30mm_MP_QF_T_R",
			"RC_160Rnd_30mm_MP_QF_T_G",
			"RC_160Rnd_30mm_MP_QF_T_Y",

			"RC_160Rnd_30mm_MPAB_DF_T_R",
			"RC_160Rnd_30mm_MPAB_DF_T_G",
			"RC_160Rnd_30mm_MPAB_DF_T_Y",

			"RC_160Rnd_30mm_MPAB_QF_T_R",
			"RC_160Rnd_30mm_MPAB_QF_T_G",
			"RC_160Rnd_30mm_MPAB_QF_T_Y",

			"RC_160Rnd_30mm_HE_Pen_T_R",
			"RC_160Rnd_30mm_HE_Pen_T_G",
			"RC_160Rnd_30mm_HE_Pen_T_Y",

			"RC_160Rnd_30mm_HE_DF_T_R",
			"RC_160Rnd_30mm_HE_DF_T_G",
			"RC_160Rnd_30mm_HE_DF_T_Y",

			"RC_160Rnd_30mm_HE_QF_T_R",
			"RC_160Rnd_30mm_HE_QF_T_G",
			"RC_160Rnd_30mm_HE_QF_T_Y",

			"RC_160Rnd_30mm_HEAB_DF_T_R",
			"RC_160Rnd_30mm_HEAB_DF_T_G",
			"RC_160Rnd_30mm_HEAB_DF_T_Y",

			"RC_160Rnd_30mm_HEAB_QF_T_R",
			"RC_160Rnd_30mm_HEAB_QF_T_G",
			"RC_160Rnd_30mm_HEAB_QF_T_Y"
		};

		class player: player {dispersion=0.0008; class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class close: close {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class short: short {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class medium: medium {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class far: far {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
	};

	class AP: autocannon_Base_F
	{
		displayName="MK30";
		maxZeroing=4000;
		#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorCannon.hpp"
		//#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"

		magazines[]=
		{
			"RC_160Rnd_30mm_APFSDS_T_R",
			"RC_160Rnd_30mm_APFSDS_T_G",
			"RC_160Rnd_30mm_APFSDS_T_Y"
		};

		class player: player {dispersion=0.0008; class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class close: close {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class short: short {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class medium: medium {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
		class far: far {class StandardSound {SoundSetShot[] = {"BWA3_MK30_Shot_SoundSet", "BWA3_MK30_Tail_SoundSet"};};magazineReloadTime = 0.3;};
	};

	class GunParticles
	{
		class Effect
		{
			effectName="BWA3_AutoCannonFired";
			positionName="Usti hlavne";
			directionName="Konec hlavne";
		};
		class Shell
		{
			positionName="shell_eject_pos";
			directionName="shell_eject_dir";
			effectName="BWA3_30mm_Cartridge";
		};
	};
};


//Machinegun
class BWA3_MG5_vehicle;
class RC_MG338_vehicle_Base: BWA3_MG5_vehicle
{
	class manual;
};
class RC_MG338_vehicle: RC_MG338_vehicle_Base
{
	#include "\Remote_Controlled_Artillery\includes_cfg\BallisticsCalculatorMG.hpp"
	displayName="MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazines[]=
	{
		"RC_400Rnd_338_T_R",
		"RC_400Rnd_338_T_G",
		"RC_400Rnd_338_T_Y",

		"RC_600Rnd_338_T_R",
		"RC_600Rnd_338_T_G",
		"RC_600Rnd_338_T_Y"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};


class RC_155mm_AMOS_V4;
class RC_155mm_AMOS_PzH_Base: RC_155mm_AMOS_V4
{
	class Single1;
	class Single2;
	class Single3;
	class Single4;
	class Single5;
	class Single6;
	class Single7;
};
class RC_155mm_AMOS_PzH: RC_155mm_AMOS_PzH_Base
{
	reloadTime=5;
	magazineReloadTime=5;
	
	class Single1: Single1 {reloadTime=5;};
	class Single2: Single2 {reloadTime=5;};
	class Single3: Single3 {reloadTime=5;};
	class Single4: Single4 {reloadTime=5;};
	class Single5: Single5 {reloadTime=5;};
	class Single6: Single6 {reloadTime=5;};
	class Single7: Single7 {reloadTime=5;};
};