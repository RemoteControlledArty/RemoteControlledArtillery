class CfgPatches
{
	class RC_DevHelp
	{
		name="Remote Controlled DevHelp";
		author="Ascent";

		units[]=
		{
			"RC_DeveloperBackpack"
		};
		requiredAddons[]=
		{
			"cba_main",
			"RC_Artillery",
			"RC_Aegis"
		};

		skipWhenMissingDependencies=1;
	};
};


/*
class CfgFunctions
{
	class RC
	{
		class RC_
		{
			file="\RC_DevHelp\functions";
      		class RC_ {postInit=1;};
		};
	};
};
*/


class CfgVehicles
{
	//for SP testing, add in crocus function array
	class RC_SignalBoosterLRR_g;
	class RC_DeveloperBackpack: RC_SignalBoosterLRR_g
	{
		displayName="Developer Backpack";
		maximumLoad=3000;
	};
};