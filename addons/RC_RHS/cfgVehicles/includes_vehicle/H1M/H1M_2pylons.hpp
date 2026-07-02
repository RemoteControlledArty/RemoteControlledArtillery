class TransportPylonsComponent
{
	UIPicture = "\rhsusf\addons\rhsusf_a2port_air2\data\loadouts\RHS_UH1_EDEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			hardpoints[]=
			{
				"OM_H",
				"RHS_HP_FFAR_USMC","RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134",
				"B_BOMB_PYLON","B_FUELTANK_HELI","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","DAR","DAGR","DAGRM"

				/*
				//"Pylon",
				"O_MISSILE_PYLON","O_SKYFIRE",
				"VTX_ST_L","VTX_ST_R",

				"B_BOMB_PYLON","B_FUELTANK_HELI","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","DAR","DAGRM",

				"WEAPON_PODS_RF","CANNON_PODS_RF","B_A143_BUZZARD_CENTER_PYLON",
				"CE_Munitions_Cannon_Hardpoint","O_ORCA_RIGHT_PYLON","UK3CB_BAF_M621_PYLON_GUNPOD","CE_Munitions_BigCannon_Hardpoint",
				
				"TITAN_NLOS_1RND",
				"20MM_CANNON","20MM_TWIN_CANNON",
				"DAGR","DAR","B_MISSILE_PYLON",
				"RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134"
				*/
			};

			priority			= 1;
			UIposition[] 		= {0.573,0.44};
			hitpoint 			= "HitPylon1";
			bay 				= -1;
			//maxweight 		= 1200;	//1200

			//attachment		= "rhs_mag_m134_pylon_3000";
			attachment			= "RC_PylonM_300Rnd_25mm";
		};
		class pylon2: pylon1
		{
			//mirroredMissilePos= 1;	//1
			UIposition[] 		= {0.1,0.44};
			hitpoint 			= "HitPylon2";

			attachment			= "RC_RHS_PylonM_19Rnd_Hydra_MP";
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
				"RC_RHS_PylonM_19Rnd_Hydra_MP",
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