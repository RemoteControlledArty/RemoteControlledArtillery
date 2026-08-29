class TransportPylonsComponent
{
	uiPicture="\A3\Air_F_EPB\Heli_Light_03\data\UI\Heli_Light_03_3DEN_CA.paa";
	
	class pylons
	{
		class PylonRight1
		{
			maxweight			= 1200;
			bay					= -1;

			priority			= 2;
			UIposition[]		= {0.06,0.4};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_300Rnd_25mm";
		};
		class PylonLeft1: PylonRight1
		{
			priority			= 1;
			UIposition[]		= {0.59,0.4};
			attachment			= "RC_PylonM_19Rnd_Hydra_MP_Proxy";
		};
	};


	class Presets
	{
		class Unguided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm",
				"RC_PylonM_19Rnd_Hydra_MP_Proxy"
			};
			displayname="Unguided";
		};
		class LaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm",
				"RC_PylonM_12Rnd_Hydra_APKWS"
			};
			displayname="Laser Guided";
		};
		class HeavyLaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm",
				"RC_PylonM_3Rnd_AGM114K"
			};
			displayname="Heavy Laser Guided";
		};
	};
};