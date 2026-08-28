class TransportPylonsComponent
{
	uiPicture="\A3\Air_F_Beta\Heli_Transport_01\Data\UI\Heli_Transport_01_pylons_EDEN_CA.paa";
	
	class pylons
	{
		//left outer
		class pylon1
		{
			hardpoints[]=
			{
				//V1 = .338, V2 = .50, V3 = lower capacity 20/25/30mm & rockets, V4 = full capacity 20/25/30mm & rockets
				//V5 = small guided pods, V6 = large guided pods
				
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

				"OM_H",
				"B_GAU19_HELI_L",

				"RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134",
				"B_FUELTANK_HELI","B_BOMB_PYLON","UNI_SCALPEL","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","DAR","DAGR","DAGRM"
			};

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
				
				"OM_H",
				"B_GAU19_HELI_R",

				"RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R","RHS_HP_MELB_M134",
				"B_FUELTANK_HELI","B_BOMB_PYLON","UNI_SCALPEL","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","DAR","DAGR","DAGRM"
			};

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


		//center
		class camera: pylon1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_Cam"
				//"B_CAMERA_HELI"
			};
			UIposition[]={0.35,0.55};
			attachment="RC_PylonM_Camera";
			priority=3;
			//only available for copilot, default {-1,0}
			turretsAvailable[]={0};
			//copilot by default, atm bugs camera to not be movable from copilot
			//turret[]={0};

			//what is MH80 config "groupCameraPosition[] = {0,5,-30};"?
		};


		//left
		class wingtip1: pylon2
		{
			attachment="PylonECMPod_01_Flare_R";
			hardpoints[]=
			{
				"ECM_POD_R"
			};
			UIposition[]={0.625,0.28};
			priority=4;
		};
		//right
		class wingtip2: wingtip1
		{
			attachment="PylonECMPod_01_Flare_L";
			hardpoints[]=
			{
				"ECM_POD_L"
			};
			UIposition[]={0.04,0.28};
			mirroredMissilePos=6;
		};
	};

	//["PylonFuelTank_UH80","PylonWeapon_500Rnd_127mm_HEIAP_belt_left","PylonRack_12Rnd_PGM_missiles_black","PylonFuelTank_UH80","PylonRadarPod_01_F","PylonECMPod_01_Flare_R","PylonECMPod_01_Flare_L"]


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
		/*
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
		*/
	};
};