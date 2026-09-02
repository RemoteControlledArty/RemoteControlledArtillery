class TransportPylonsComponent
{
	uiPicture = "\A3\Air_F_Exp\UAV_03\Data\UI\Map_UAV_03_3DEN_CA.paa";
	
	class pylons
	{
		//right outer
		class pylon1
		{
			maxweight			= 1200;
			//bay				= -1;	//NA

			priority			= 2;	//5
			UIposition[] 		= {0.05,0.3};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_19Rnd_Hydra_MP_Proxy";
		};
		//right inner
		class pylon2: pylon1
		{
			priority			= 1;	//4
			UIposition[] 		= {0.1,0.38};
			attachment			= "RC_PylonM_250Rnd_30mm";
		};
		//left inner
		class pylon3: pylon2
		{
			//mirroredMissilePos= 2;
			UIposition[] 		= {0.53,0.38};
			attachment			= "RC_PylonM_250Rnd_30mm";
		};
		//left outer
		class pylon4: pylon3
		{
			//mirroredMissilePos= 1;
			priority			= 1;	//5
			UIposition[] 		= {0.58,0.3};
			attachment			= "RC_PylonM_19Rnd_Hydra_MP_Proxy";
		};
	};


	class Presets
	{
		class Default
		{
			attachment[]=
			{
				"RC_PylonM_19Rnd_Hydra_MP_Proxy",
				"RC_PylonM_250Rnd_30mm",
				"RC_PylonM_250Rnd_30mm",
				"RC_PylonM_19Rnd_Hydra_MP_Proxy"
			};
			displayname="Default";
		};
		class Unguided
		{
			attachment[] =
			{
				"RC_PylonM_19Rnd_Hydra_MP_Proxy",
				"RC_PylonM_250Rnd_30mm",
				"RC_PylonM_250Rnd_30mm",
				"RC_PylonM_19Rnd_Hydra_MP_Proxy"
			};
			displayname="Unguided";
		};
	};
};