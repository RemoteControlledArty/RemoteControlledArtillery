class TransportPylonsComponent
{
	uiPicture="\A3\Air_F\Heli_Light_02\Data\UI\Heli_Light_02_3DEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			maxweight			= 1200;
			bay					= -1;

			priority			= 2;
			UIposition[] 		= {0.04,0.42};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_300Rnd_25mm_O";
		};
		class pylon2: pylon1
		{
			//priority			= 1;
			UIposition[] 		= {0.625,0.42};
			attachment			= "RC_PylonM_19Rnd_S5_MP_Proxy";
		};
	};


	class Presets
	{
		class Unguided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm_O",
				"RC_PylonM_19Rnd_S5_MP_Proxy"
			};
			displayname="Unguided";
		};
		/*
		class LaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm_O",
				"RC_PylonM_12Rnd_S8_LG"
			};
			displayname="Laser Guided";
		};
		*/
		/*
		class Guided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm_O",
				"RC_PylonM_12Rnd_S8_G"
			};
			displayname="SACLOS / Lock - Guided";
		};
		*/
		/*
		class HeavyLaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm_O",
				"RC_PylonM_3Rnd_Vikhr"
			};
			displayname="Heavy Laser Guided";
		};
		*/
	};
};