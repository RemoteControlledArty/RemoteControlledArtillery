class RHS_weap_m134_pylon;
class RC_RHS_PylonW_338_Minigun_Base: RHS_weap_m134_pylon
{
	class HighROF;
};
class RC_RHS_PylonW_338_Minigun: RC_RHS_PylonW_338_Minigun_Base
{
	displayName=".338NM Minigun";
	displayNameShort=".338NM Minigun";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_RHS_PylonM_2500Rnd_338_SLAP_T_R",
		"RC_RHS_PylonM_2500Rnd_338_SLAP_T_G",
		"RC_RHS_PylonM_2500Rnd_338_SLAP_T_Y"
	};
	modes[]=
	{
		"HighROF","close","short","medium","far"
	};
	class HighROF: HighROF
	{
		displayName=".338NM";
		displayNameShort=".338NM";
		reloadTime=0.015;	//0.02 = 3000RPM, 0.015 = 4000RPM
		dispersion=0.005;	//0.0055
	};
};


class RHS_weap_gau19;
class RC_RHS_PylonW_GAU19A_Base: RHS_weap_gau19
{
	class HighROF;
};
class RC_RHS_PylonW_GAU19A: RC_RHS_PylonW_GAU19A_Base
{
	displayName="GAU-19/A";
	displayNameShort="GAU-19/A";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_left",
		"RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_left",
		"RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_left",
		
		"RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_right",
		"RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_right",
		"RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_right"
	};
	modes[]=
	{
		"HighROF","close","short","medium","far"
	};
	class HighROF: HighROF
	{
		displayName="GAU-19/A";
		displayNameShort="GAU-19/A";
		reloadTime=0.03;	//0.03, 2000RPM
		dispersion=0.005;	//0.005
	};
};


//redefine because default sound is awefull
class Gatling_127mm_HeliPylon_F;
class RC_PylonW_127mm_Minigun_Base: Gatling_127mm_HeliPylon_F
{
	class LowROF;
};
class RC_PylonW_127mm_Minigun: RC_PylonW_127mm_Minigun_Base
{
	displayName="12.7mm Minigun";
	displayNameShort="12.7mm Minigun";
	ballisticsComputer=8;
	allowTabLock=1;
	canLock=2;

	magazines[]=
	{
		"RC_PylonM_1000Rnd_127mm_SLAP_T_R_left",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_G_left",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_Y_left",

		"RC_PylonM_1000Rnd_127mm_SLAP_T_R_right",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_G_right",
		"RC_PylonM_1000Rnd_127mm_SLAP_T_Y_right"
	};
	modes[]=
	{
		"LowROF","close","short","medium","far"
	};
	class LowROF: LowROF
	{
		ballisticsComputer="8";
		displayName="12.7mm";
		displayNameShort="12.7mm";
		reloadTime=0.03;	//0.04 = 1500RPM, 0.03 = 2000RPM
		dispersion=0.005;	//0.003
		burst=4;			//5
		
		//better sound
    	class StandardSound
		{
			begin1[]={"rhsusf\addons\rhsusf_melb\Sound\Gau19\Gau19_1",2.5,1,2600};
			begin2[]={"rhsusf\addons\rhsusf_melb\Sound\Gau19\Gau19_2",2.5,1,2600};
			begin3[]={"rhsusf\addons\rhsusf_melb\Sound\Gau19\Gau19_3",2.5,1,2600};
			closure1[]={"A3\sounds_f\weapons\gatling\gatling_rotation_short_2",0.316228,1,20};
			closure2[]={"A3\sounds_f\weapons\gatling\gatling_rotation_short_3",0.316228,1,20};
			soundBegin[]={"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundClosure[]={"closure1",0.5,"closure2",0.5};
		};
	};
};


//redefine because default sound is awefull
class RC_PylonW_Twin_Base;
class RC_RHS_PylonW_TwinHMG_Fetch: RC_PylonW_Twin_Base
{
	class manual;
};
class RC_PylonW_TwinHMG: RC_RHS_PylonW_TwinHMG_Fetch
{
	displayName="Twin HMG";
	displayNameShort="Twin HMG";

	magazines[]=
	{
		"RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_R",
		"RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_G",
		"RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_Y"
	};
	class manual: manual
	{
		displayName="Twin HMG";
		displayNameShort="Twin HMG";

		reloadTime=0.03;	//0.04 = 1500RPM, 0.03 = 2000RPM
		dispersion=0.005;	//0.003
		burst=4;			//2

		sounds[]=
		{
			"StandardSound"
		};
		//better sound
    	class StandardSound
		{
			begin1[]={"rhsusf\addons\rhsusf_melb\Sound\Gau19\Gau19_1",2.5,1,2600};
			begin2[]={"rhsusf\addons\rhsusf_melb\Sound\Gau19\Gau19_2",2.5,1,2600};
			begin3[]={"rhsusf\addons\rhsusf_melb\Sound\Gau19\Gau19_3",2.5,1,2600};
			closure1[]={"A3\sounds_f\weapons\gatling\gatling_rotation_short_2",0.316228,1,20};
			closure2[]={"A3\sounds_f\weapons\gatling\gatling_rotation_short_3",0.316228,1,20};
			soundBegin[]={"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundClosure[]={"closure1",0.5,"closure2",0.5};
		};
	};
};


class rhs_weap_FFARLauncher;
class RC_RHS_PylonW_Hydra_Core: rhs_weap_FFARLauncher
{
	class Burst;
};
class RC_RHS_PylonW_Hydra: RC_RHS_PylonW_Hydra_Core
{
	displayName="Hydra Pod";
	displayNameShort="Hydra Pod";
	ballisticsComputer=8;
	canLock=2;

	magazines[]=
	{
		"RC_RHS_PylonM_19Rnd_Hydra_MP",
		"RC_RHS_PylonM_7Rnd_Hydra_MP",
		"RC_RHS_PylonM_19Rnd_Hydra_MP_Proxy",
		"RC_RHS_PylonM_7Rnd_Hydra_MP_Proxy"
		//"RC_RHS_PylonM_19Rnd_Hydra_HE",
		//"RC_RHS_PylonM_7Rnd_Hydra_HE"
	};
	modes[]=
	{
		"Burst",
		"Far_AI"
	};
	class Burst: Burst
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
		dispersion=0.004;	//0.12 default, 0.004 to make more viable alternative to guided against vics that need direct hit
	};
};


/*
class RC_PylonW_APKWS;
class RC_RHS_PylonW_APKWS: RC_PylonW_APKWS
{
	magazines[]=
	{
		"RC_RHS_PylonM_7Rnd_APKWS"
	};
};
*/


class RHS_weap_DAGR_Launcher;
class RC_PylonW_DAGR_Base: RHS_weap_DAGR_Launcher
{
	class Direct;
	class LoalDistance;
};
class RC_PylonW_DAGR: RC_PylonW_DAGR_Base
{
	displayName="DAGR M310";
	displayNameShort="DAGR M310";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_PylonM_8Rnd_DAGR",
		"RC_PylonM_8Rnd_DAGR_Proxy"
	};
	modes[]=
	{
		"Direct",
		"LoalDistance"
	};
	class Direct: Direct
	{
		displayName="DAGR M310 DIR";
		displayNameShort="DAGR M310 DIR";
	};
	class LoalDistance: LoalDistance
	{
		displayName="DAGR M310 LOAL";
		displayNameShort="DAGR M310 LOAL";
	};
};


class RC_PylonW_S8_G: RC_PylonW_DAGR
{
	displayName="S-8 G";
	displayNameShort="S-8 G";
	magazines[]=
	{
		"RC_PylonM_8Rnd_S8_G",
		"RC_PylonM_8Rnd_S8_G_Proxy"
	};
	class Direct: Direct
	{
		displayName="S-8 G DIR";
		displayNameShort="S-8 G DIR";
	};
	class LoalDistance: LoalDistance
	{
		displayName="S-8 G LOAL";
		displayNameShort="S-8 G LOAL";
	};
};


/*
//defunct guidance
class RHS_weap_AGM114K_Launcher;
class RC_RHS_PylonW_AGM114K: RHS_weap_AGM114K_Launcher
{
	displayName="AGM-114K Hellfire II";
	displayNameShort="AGM-114K Hellfire II";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_PylonM_2Rnd_AGM114K"
	};
};
*/