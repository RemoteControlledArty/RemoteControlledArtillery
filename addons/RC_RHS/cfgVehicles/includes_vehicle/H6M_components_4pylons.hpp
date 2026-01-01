class TransportPylonsComponent
{
	UIPicture = "\rhsusf\addons\rhsusf_melb\data\loadouts\RHS_AH6M_EDEN_CA.paa";
	class pylons
	{
		class pylon1
		{
			hardpoints[]		= {"TITAN_NLOS_1RND",  "20MM_CANNON","20MM_TWIN_CANNON",  "DAGR","DAR","B_MISSILE_PYLON",  "RHS_HP_MELB","RHS_HP_MELB_L","RHS_HP_MELB_R"};
			maxweight			= 1200;
			bay					= -1;
			turret[]			= {};

			priority			= 2;
			UIposition[]		= {0.625,0.2};
			hitpoint			= "HitPylon1";
			
			attachment			= "RC_PylonWeapon_300Rnd_20mm_shells_slow";
		};
		class pylon2 : pylon1
		{
			priority			= 1;
			UIposition[]		= {0.562,0.30};
			hitpoint 			= "HitPylon2";

			//attachment		= "rhs_mag_m134_pylon_3000";
			attachment			= "rhs_mag_M151_7";
		};
		class pylon3 : pylon2
		{
			//mirroredMissilePos= 2;
			UIposition[]		= {0.103,0.30};
			hitpoint 			= "HitPylon3";

			//attachment		= "rhs_mag_m134_pylon_3000";
			attachment			= "rhs_mag_M151_7";
		};
		class pylon4 : pylon1
		{
			//mirroredMissilePos= 1;
			UIposition[]		= {0.04,0.20};
			hitpoint 			= "HitPylon4";

			attachment			= "RC_PylonWeapon_300Rnd_20mm_shells_slow";
		};
	};

	class Presets
	{
		class Light
		{
			attachment[] =
			{
				"rhs_mag_M151_7",
				"rhs_mag_m134_pylon_3000",
				"rhs_mag_m134_pylon_3000",
				"rhs_mag_M151_7"
			};
			displayname = "Light";
		};
		class Medium
		{
			attachment[] =
			{
				"rhsusf_mag_gau19_melb_left",
				"",
				"",
				"rhs_mag_M151_19"
			};
			displayname = "Medium";
		};
		class Heavy
		{
			attachment[] =
			{
				"rhsusf_mag_gau19_melb_left",
				"",
				"",
				"rhs_mag_AGM114K_2"
			};
			displayname = "Heavy";
		};
	};
};