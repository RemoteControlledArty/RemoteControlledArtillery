class TransportPylonsComponent
{
	UIPicture = "\rhsusf\addons\rhsusf_melb\data\loadouts\RHS_AH6M_EDEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			hardpoints[]=
			{
				"OM_H",
				"RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134",
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
			maxweight			= 1200;
			bay					= -1;
			turret[]			= {};

			priority			= 2;
			UIposition[]		= {0.625,0.2};
			hitpoint			= "HitPylon1";
			
			attachment			= "RC_RHS_PylonM_1300Rnd_GAU19A_left";
		};
		class pylon2 : pylon1
		{
			priority			= 1;
			UIposition[]		= {0.562,0.30};
			hitpoint 			= "HitPylon2";

			//attachment		= "rhs_mag_m134_pylon_3000";
			attachment			= "RC_PylonM_300Rnd_20mm";
		};
		class pylon3 : pylon2
		{
			//mirroredMissilePos= 2;
			UIposition[]		= {0.103,0.30};
			hitpoint 			= "HitPylon3";

			//attachment		= "rhs_mag_m134_pylon_3000";
			attachment			= "RC_RHS_PylonM_19Rnd_Hydra_MP";
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
				"RC_RHS_PylonM_1300Rnd_GAU19A_left",
				"RC_PylonM_300Rnd_20mm",
				"RC_RHS_PylonM_19Rnd_Hydra_MP",
				"RC_PylonM_12Rnd_APKWS"
			};
			displayname="Default";
		};
	};
};