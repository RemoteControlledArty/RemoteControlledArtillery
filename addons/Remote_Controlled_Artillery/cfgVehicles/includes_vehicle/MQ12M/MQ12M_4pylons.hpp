class TransportPylonsComponent
{
	uiPicture="\A3\Air_F_Beta\Heli_Transport_01\Data\UI\Heli_Transport_01_pylons_EDEN_CA.paa";
	
	class pylons
	{
		//left outer
		class pylon1
		{
			maxweight			= 1200;
			bay					= -1;

			priority			= 2;
			UIposition[] 		= {0.625,0.42};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_12Rnd_APKWS";
		};
		//left inner
		class pylon2: pylon1
		{
			priority			= 1;
			UIposition[] 		= {0.555,0.37};
			attachment			= "RC_PylonM_250Rnd_30mm";
		};

		
		//right inner
		class pylon3: pylon2
		{
			//mirroredMissilePos= 2;
			UIposition[] 		= {0.11,0.37};
			attachment			= "RC_PylonM_19Rnd_Hydra_MP_Proxy";
		};
		//right outer
		class pylon4: pylon3
		{
			//mirroredMissilePos= 1;
			priority			= 1;
			UIposition[] 		= {0.04,0.42};
			attachment			= "RC_PylonM_1Rnd_AGM114K";
		};
	};


	class Presets
	{
		class Default
		{
			attachment[]=
			{
				"RC_PylonM_12Rnd_APKWS",
				"RC_PylonM_250Rnd_30mm",
				"RC_PylonM_19Rnd_Hydra_MP_Proxy",
				"RC_PylonM_1Rnd_AGM114K",

				"RC_PylonM_Camera",
				
				"PylonECMPod_01_DIRCM_R",
				"PylonECMPod_01_DIRCM_L"
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
				"RC_PylonM_19Rnd_Hydra_MP_Proxy",

				"RC_PylonM_Camera",
				
				"PylonECMPod_01_DIRCM_R",
				"PylonECMPod_01_DIRCM_L"
			};
			displayname="Unguided";
		};
		class Miniguns
		{
			attachment[]=
			{
				"RC_PylonFuelTank_HalfFull",
				"RC_PylonM_1000Rnd_127mm_SLAP_T_R_left",
				"RC_PylonM_1000Rnd_127mm_SLAP_T_R_right",
				"RC_PylonFuelTank_HalfFull",

				"RC_PylonM_Camera",

				"PylonECMPod_01_DIRCM_R",
				"PylonECMPod_01_DIRCM_L"
			};
			displayname="Miniguns";
		};
	};
};