class rhs_weap_FFARLauncher;
class RC_RHS_PylonW_Hydra_Core: rhs_weap_FFARLauncher
{
	class Burst;
};
class RC_RHS_PylonW_Hydra: RC_RHS_PylonW_Hydra_Core
{
	displayName="Hydra Pod";
	displayNameShort="Hydra Pod";
	ballisticsComputer=8;
	canLock=2;

	magazines[]=
	{
		/*
		//large pod
		"RC_RHS_PylonM_19Rnd_Hydra_MP",
		
		"RC_RHS_PylonM_19Rnd_Hydra_M151",
		"RC_RHS_PylonM_12Rnd_Hydra_M151",
		"RC_RHS_PylonM_9Rnd_Hydra_M151",

		"RC_RHS_PylonM_19Rnd_Hydra_M229",
		"RC_RHS_PylonM_12Rnd_Hydra_M229",
		"RC_RHS_PylonM_9Rnd_Hydra_M229",

		//small pod
		"RC_RHS_PylonM_7Rnd_Hydra_M151",

		"RC_RHS_PylonM_7Rnd_Hydra_M229",
		*/

		"RC_RHS_PylonM_19Rnd_Hydra_HE",
		"RC_RHS_PylonM_7Rnd_Hydra_HE",

		"RC_RHS_PylonM_19Rnd_Hydra_MP",
		"RC_RHS_PylonM_7Rnd_Hydra_MP"
	};
	modes[]=
	{
		"Burst",
		"Far_AI"
	};
	class Burst: Burst
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
		dispersion=0.006;	//0.12
	};
};


/*
class RC_PylonW_APKWS;
class RC_RHS_PylonW_APKWS: RC_PylonW_APKWS
{
	magazines[]=
	{
		"RC_RHS_PylonM_7Rnd_APKWS"
	};
};
*/


/*
//defunct guidance
class RHS_weap_AGM114K_Launcher;
class RC_RHS_PylonW_AGM114K: RHS_weap_AGM114K_Launcher
{
	displayName="AGM-114K Hellfire II";
	displayNameShort="AGM-114K Hellfire II";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_PylonM_2Rnd_AGM114K"
	};
};
*/


//lacks submun
class RHS_weap_DAGR_Launcher;
class RC_RHS_PylonW_DAGR_Base: RHS_weap_DAGR_Launcher
{
	class Direct;
	class LoalDistance;
};
class RC_RHS_PylonW_DAGR: RC_RHS_PylonW_DAGR_Base
{
	displayName="DAGR M310";
	displayNameShort="DAGR M310";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_RHS_PylonM_8Rnd_DAGR"
	};
	modes[]=
	{
		"Direct",
		"LoalDistance"
	};
	class Direct: Direct
	{
		displayName="DAGR M310 DIR";
		displayNameShort="DAGR M310 DIR";
	};
	class LoalDistance: LoalDistance
	{
		displayName="DAGR M310 LOAL";
		displayNameShort="DAGR M310 LOAL";
	};
};
class RC_RHS_PylonW_S8_G: RC_RHS_PylonW_DAGR
{
	displayName="S-8 G";
	displayNameShort="S-8 G";
	magazines[]=
	{
		"RC_RHS_PylonM_8Rnd_S8_G"
	};
	class Direct: Direct
	{
		displayName="S-8 G DIR";
		displayNameShort="S-8 G DIR";
	};
	class LoalDistance: LoalDistance
	{
		displayName="S-8 G LOAL";
		displayNameShort="S-8 G LOAL";
	};
};


class RHS_weap_gau19;
class RC_RHS_PylonW_GAU19A_Base: RHS_weap_gau19
{
	class HighROF;
};
class RC_RHS_PylonW_GAU19A: RC_RHS_PylonW_GAU19A_Base
{
	displayName="GAU-19/A";
	displayNameShort="GAU-19/A";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_RHS_PylonM_1300Rnd_GAU19A_left",
		"RC_RHS_PylonM_1300Rnd_GAU19A_right"
	};
	modes[]=
	{
		"HighROF","close","short","medium","far"
	};
	class HighROF: HighROF
	{
		displayName="GAU-19/A";
		displayNameShort="GAU-19/A";
	};
};


class RHS_weap_m134_pylon;
class RC_RHS_PylonW_338_Minigun_Base: RHS_weap_m134_pylon
{
	class HighROF;
};
class RC_RHS_PylonW_338_Minigun: RC_RHS_PylonW_338_Minigun_Base
{
	displayName=".338NM Minigun";
	displayNameShort=".338NM Minigun";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_RHS_PylonM_2600Rnd_338_SLAP"
	};
	modes[]=
	{
		"HighROF","close","short","medium","far"
	};
	class HighROF: HighROF
	{
		displayName=".338NM";
		displayNameShort=".338NM";
	};
};