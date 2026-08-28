class TransportPylonsComponent
{
	uiPicture="\A3\Air_F\Heli_Light_02\Data\UI\Heli_Light_02_3DEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",
				
				"RC_Hardpoint_O_V1",
				"RC_Hardpoint_O_V1_Right",
				"RC_Hardpoint_O_V2",
				"RC_Hardpoint_O_V2_Right",
				"RC_Hardpoint_O_V3",
				"RC_Hardpoint_O_V3_Right",
				"RC_Hardpoint_O_V4",
				"RC_Hardpoint_O_V4_Right",		
				"RC_Hardpoint_O_V5",
				"RC_Hardpoint_O_V5_Right",
				"RC_Hardpoint_O_V6",
				"RC_Hardpoint_O_V6_Right",

				"RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134",
				"B_FUELTANK_HELI","B_BOMB_PYLON","UNI_SCALPEL","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","DAR","DAGR","DAGRM"
			};
			
			maxweight			= 1200;
			bay					= -1;

			priority			= 2;
			UIposition[] 		= {0.625,0.42};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_300Rnd_25mm_O";
		};
		class pylon2: pylon1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",

				"RC_Hardpoint_O_V1",
				"RC_Hardpoint_O_V1_Left",
				"RC_Hardpoint_O_V2",
				"RC_Hardpoint_O_V2_Left",
				"RC_Hardpoint_O_V3",
				"RC_Hardpoint_O_V3_Left",
				"RC_Hardpoint_O_V4",
				"RC_Hardpoint_O_V4_Left",		
				"RC_Hardpoint_O_V5",
				"RC_Hardpoint_O_V5_Left",
				"RC_Hardpoint_O_V6",
				"RC_Hardpoint_O_V6_Left",

				"RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134",
				"B_FUELTANK_HELI","B_BOMB_PYLON","UNI_SCALPEL","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","DAR","DAGR","DAGRM"
			};

			//priority			= 1;
			UIposition[] 		= {0.04,0.42};
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