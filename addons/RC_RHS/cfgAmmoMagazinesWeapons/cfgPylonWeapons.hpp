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
		//large pod
		"RC_RHS_PylonM_19Rnd_MP",
		
		"RC_RHS_PylonM_19Rnd_M151",
		"RC_RHS_PylonM_12Rnd_M151",
		"RC_RHS_PylonM_9Rnd_M151",

		"RC_RHS_PylonM_19Rnd_M229",
		"RC_RHS_PylonM_12Rnd_M229",
		"RC_RHS_PylonM_9Rnd_M229",

		//small pod
		"RC_RHS_PylonM_7Rnd_M151",

		"RC_RHS_PylonM_7Rnd_M229",
		"RC_RHS_PylonM_7Rnd_MP"
	};
	modes[]=
	{
		"Burst",
		"Far_AI"
	};
	class Burst: Burst
	{
		reloadTime=0.15;
		dispersion=0.006;	//0.12
	};
};


//lacks submun
class RHS_weap_DAGR_Launcher;
class RC_RHS_PylonW_DAGR: RHS_weap_DAGR_Launcher
{
	displayName="DAGR M310";
	displayNameShort="DAGR M310";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_PylonM_8Rnd_DAGR"
	};
};
class RC_RHS_PylonW_S8_SACLOS: RC_RHS_PylonW_DAGR
{
	displayName="S-8 SACLOS";
	displayNameShort="S-8 SACLOS";
	magazines[]=
	{
		"RC_PylonM_8Rnd_S8_SACLOS"
	};
};


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


class RHS_weap_gau19;
class RC_RHS_PylonW_GAU19A: RHS_weap_gau19
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
};


class RHS_weap_m134_pylon;
class RC_RHS_PylonW_338_Minigun: RHS_weap_m134_pylon
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