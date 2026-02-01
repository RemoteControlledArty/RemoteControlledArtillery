class TransportPylonsComponent
{
	uiPicture="\A3\Air_F\Heli_Light_02\Data\UI\Heli_Light_02_3DEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			hardpoints[]=
			{
				"OM_H_O",
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
			UIposition[] 		= {0.625,0.42};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_250Rnd_25mm_O";
		};
		class pylon2: pylon1
		{
			//priority			= 1;
			UIposition[] 		= {0.04,0.42};
			attachment			= "RC_PylonM_19Rnd_S5_MP";
		};
	};


	class Presets
	{
		class Unguided
		{
			attachment[] =
			{
				"RC_PylonM_250Rnd_25mm_O",
				"RC_PylonM_19Rnd_S5_MP"
			};
			displayname="Unguided";
		};
		/*
		class LaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_250Rnd_25mm_O",
				"RC_PylonM_12Rnd_S8_LG"
			};
			displayname="Laser Guided";
		};
		*/
		class Guided
		{
			attachment[] =
			{
				"RC_PylonM_250Rnd_25mm_Ru",
				"RC_RHS_PylonM_8Rnd_S8_G"
			};
			displayname="SACLOS / Lock - Guided";
		};
		/*
		class HeavyLaserGuided
		{
			attachment[] =
			{
				"RC_PylonM_250Rnd_25mm_O",
				"RC_PylonM_3Rnd_Vikhr"
			};
			displayname="Heavy Laser Guided";
		};
		*/
	};
};