class CfgPatches
{
	class RC_ilbe
	{
		name="RC ilbe";
		author="Ascent";

		units[]=
		{
			"RC_SignalBoosterLRR_ilbe_A",
			"RC_SignalBoosterLRR_ilbe_G",
			"RC_SignalBoosterLRR_ilbe_MC"
		};

		requiredAddons[]=
		{
			"cba_main",
			"RC_Crocus",
			"tfw_radios_main"
		};

		skipWhenMissingDependencies=1;
	};
};


class CfgVehicles
{
	#include "\RC_ilbe\cfgVehicles\SignalBoosterBackpackLRR.hpp"
};