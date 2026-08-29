class TransportPylonsComponent
{
	UIPicture = "\rhsusf\addons\rhsusf_a2port_air2\data\loadouts\RHS_UH1_EDEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			priority			= 1;
			UIposition[] 		= {0.573,0.44};
			hitpoint 			= "HitPylon1";
			bay 				= -1;
			//maxweight 		= 1200;	//1200

			attachment			= "RC_PylonM_300Rnd_25mm";
		};
		class pylon2: pylon1
		{
			//mirroredMissilePos= 1;	//1
			UIposition[] 		= {0.1,0.44};
			hitpoint 			= "HitPylon2";

			attachment			= "RC_RHS_PylonM_19Rnd_Hydra_MP_Proxy";
		};
		class cmDispenser
		{
			attachment = "rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4";
			hardpoints[] = {"RHSUSF_cm_ANALE39","RHSUSF_cm_ANALE39_x2","RHSUSF_cm_ANALE39_x4"};
			maxweight = 800;
			priority = 1;
			UIposition[] = {0.33,0};
		};
	};


	class Presets
	{
		class Unguided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm",
				"RC_RHS_PylonM_19Rnd_Hydra_MP_Proxy",
				"rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"
			};
			displayname="Unguided";
		};
		class LaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm",
				"RC_PylonM_12Rnd_Hydra_APKWS",
				"rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"
			};
			displayname="Laser Guided";
		};
		class Guided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm",
				"RC_RHS_PylonM_8Rnd_DAGR",
				"rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"
			};
			displayname="SACLOS / Lock - Guided";
		};
		class HeavyLaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_300Rnd_25mm",
				"RC_PylonM_2Rnd_AGM114K",
				"rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"
			};
			displayname="Heavy Laser Guided";
		};
	};
};