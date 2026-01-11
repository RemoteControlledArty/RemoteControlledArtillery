class TransportPylonsComponent
{
	uiPicture="\A3\Air_F_Beta\Heli_Transport_01\Data\UI\Heli_Transport_01_pylons_EDEN_CA.paa";
	
	class pylons
	{
		class pylon1
		{
			hardpoints[]=
			{
				"OM_H",
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
			};
			maxweight			= 1200;
			bay					= -1;

			priority			= 2;
			UIposition[] 		= {0.625,0.42};

			//turret[]			= {};	//none = both?
			attachment			= "RC_PylonM_12Rnd_70mm_Hydra_MP";
		};
		class pylon2: pylon1
		{
			priority			= 1;
			UIposition[] 		= {0.555,0.37};
			attachment			= "RC_PylonM_200Rnd_30mm";
		};
		class pylon3: pylon2
		{
			//mirroredMissilePos= 2;
			UIposition[] 		= {0.11,0.37};
			attachment			= "RC_PylonM_12Rnd_APKWS";
		};
		class pylon4: pylon1
		{
			//mirroredMissilePos= 1;
			UIposition[] 		= {0.04,0.42};
			attachment			= "RC_PylonM_12Rnd_70mm_Hydra_MP";
		};
	};


	/*
	class Presets
	{
		class Light
		{
			attachment[] =
			{
				"",
				"",
				"",
				""
			};
			displayname = "Light";
		};
		class Medium
		{
			attachment[] =
			{
				"",
				"",
				"",
				""
			};
			displayname = "Medium";
		};
		class Heavy
		{
			attachment[] =
			{
				"",
				"",
				"",
				""
			};
			displayname = "Heavy";
		};
	};
	*/
};