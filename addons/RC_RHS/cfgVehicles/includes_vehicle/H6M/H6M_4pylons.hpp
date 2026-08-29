class TransportPylonsComponent
{
	UIPicture = "\rhsusf\addons\rhsusf_melb\data\loadouts\RHS_AH6M_EDEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			maxweight			= 1200;
			bay					= -1;
			turret[]			= {};

			priority			= 2;
			UIposition[]		= {0.625,0.2};
			hitpoint			= "HitPylon1";
			
			attachment			= "RC_RHS_PylonM_1250Rnd_GAU19A_left";
		};
		class pylon2 : pylon1
		{
			priority			= 1;
			UIposition[]		= {0.562,0.30};
			hitpoint 			= "HitPylon2";

			//attachment		= "rhs_mag_m134_pylon_3000";
			attachment			= "RC_PylonM_350Rnd_20mm";
		};
		class pylon3 : pylon2
		{
			//mirroredMissilePos= 2;
			UIposition[]		= {0.103,0.30};
			hitpoint 			= "HitPylon3";

			//attachment		= "rhs_mag_m134_pylon_3000";
			attachment			= "RC_RHS_PylonM_19Rnd_Hydra_MP_Proxy";
		};
		class pylon4 : pylon1
		{
			//mirroredMissilePos= 1;
			UIposition[]		= {0.04,0.20};
			hitpoint 			= "HitPylon4";

			attachment			= "RC_PylonM_12Rnd_APKWS";
		};
	};


	class Presets
	{
		class Default
		{
			attachment[] =
			{
				"RC_RHS_PylonM_1250Rnd_GAU19A_left",
				"RC_PylonM_350Rnd_20mm",
				"RC_RHS_PylonM_19Rnd_Hydra_MP_Proxy",
				"RC_PylonM_12Rnd_APKWS"
			};
			displayname="Default";
		};
	};
};