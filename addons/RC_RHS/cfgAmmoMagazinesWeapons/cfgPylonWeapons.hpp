class rhs_weap_FFARLauncher;
class RC_RHS_PylonW_Hydra_Core: rhs_weap_FFARLauncher
{
	class Burst;
};
class RC_RHS_PylonW_Hydra: RC_RHS_PylonW_Hydra_Core
{
	displayName="19x Hydra Pod";
	displayNameShort="19x Hydra Pod";
	ballisticsComputer=8;
	magazines[]=
	{
		//large pod
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
		"Burst"
	};
	class Burst: Burst
	{
		reloadTime=0.15;
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