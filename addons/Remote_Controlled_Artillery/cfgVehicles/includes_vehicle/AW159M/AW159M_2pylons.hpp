class TransportPylonsComponent
{
	uiPicture="\A3\Air_F_EPB\Heli_Light_03\data\UI\Heli_Light_03_3DEN_CA.paa";
	
	class pylons
	{
		class PylonRight1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",

				"RC_Hardpoint_V1",
				"RC_Hardpoint_V1_Right",
				"RC_Hardpoint_V2",
				"RC_Hardpoint_V2_Right",
				"RC_Hardpoint_V3",
				"RC_Hardpoint_V3_Right",
				"RC_Hardpoint_V4",
				"RC_Hardpoint_V4_Right",		
				"RC_Hardpoint_V5",
				"RC_Hardpoint_V5_Right",
				"RC_Hardpoint_V6",
				"RC_Hardpoint_V6_Right",

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

			priority			= 2;
			UIposition[]		= {0.06,0.4};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_300Rnd_25mm";
		};
		class PylonLeft1: PylonRight1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",
				
				"RC_Hardpoint_V1",
				"RC_Hardpoint_V1_Left",
				"RC_Hardpoint_V2",
				"RC_Hardpoint_V2_Left",
				"RC_Hardpoint_V3",
				"RC_Hardpoint_V3_Left",
				"RC_Hardpoint_V4",
				"RC_Hardpoint_V4_Left",		
				"RC_Hardpoint_V5",
				"RC_Hardpoint_V5_Left",
				"RC_Hardpoint_V6",
				"RC_Hardpoint_V6_Left",
				
				"RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134",
				"B_BOMB_PYLON","B_FUELTANK_HELI","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","DAR","DAGR","DAGRM"
			};

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