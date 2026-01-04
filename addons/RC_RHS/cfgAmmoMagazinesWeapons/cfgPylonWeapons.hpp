class rhs_weap_FFARLauncher;
class RC_RHS_PylonWeap_Hydra_Core: rhs_weap_FFARLauncher
{
	class Burst;
};
class RC_RHS_PylonWeap_Hydra: RC_RHS_PylonWeap_Hydra_Core
{
	displayName="19x Hydra Pod";
	displayNameShort="19x Hydra Pod";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_RHS_PylonMag_19Rnd_M151",
		"RC_RHS_PylonMag_12Rnd_M151",
		"RC_RHS_PylonMag_9Rnd_M151",
		
		"RC_RHS_PylonMag_19Rnd_M229",
		"RC_RHS_PylonMag_12Rnd_M229",
		"RC_RHS_PylonMag_9Rnd_M229"
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