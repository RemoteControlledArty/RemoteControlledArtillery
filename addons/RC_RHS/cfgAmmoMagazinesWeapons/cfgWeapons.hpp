class rhs_weap_m256;
class rhs_weap_m256_base: rhs_weap_m256
{
	class player;
};
class RC_RHS_weap_m256: rhs_weap_m256_base
{
	canLock=2;
	//minZeroing=50;
	//ballisticsComputer="2 + 16";
	//FCSMaxLeadSpeed=25;

	reloadTime=6;
	magazineReloadTime=6;

	class player: player
	{
		reloadTime=6;
	};

	magazines[]=
	{
		//SABOT
		"RC_RHS_mag_M829A4_20Rnd",
		"RC_RHS_mag_M829A4_15Rnd",
		"RC_RHS_mag_M829A4_10Rnd",
		"rhs_mag_M829A3",
		"rhs_mag_M829A2",
		"rhs_mag_M829A1",
		"rhs_mag_M829",
		//HEAT
		"RC_RHS_mag_M830A1_20Rnd",
		"RC_RHS_mag_M830A1_15Rnd",
		"RC_RHS_mag_M830A1_10Rnd",
		"rhs_mag_M830",
		//HE
		"rhs_mag_M1069",
		"rhs_mag_M1147",
		//Canister
		"rhs_mag_M1028",
		//Smoke/WP
		"rhs_mag_M416",
		"rhs_mag_M829A4_max",
		"rhs_mag_M829A3_max",
		"rhs_mag_M829A2_max",
		"rhs_mag_M829A1_max",
		"rhs_mag_M829_max",
		"rhs_mag_M830_max",
		"rhs_mag_M830A1_max",
		"rhs_mag_M1069_max",
		"rhs_mag_M1147_max",
		"rhs_mag_M1028_max",
		"rhs_mag_M416_max",

		//Datalink Missile
		"RC_4Rnd_120mm_DLG_cannon_missiles",
		"RC_3Rnd_120mm_DLG_cannon_missiles",
		"RC_2Rnd_120mm_DLG_cannon_missiles",
		"RC_1Rnd_120mm_DLG_cannon_missiles"
	};
};


class rhs_M2_CROWS_M153_Abrams;
class rhs_M2_CROWS_M153_Abrams_base: rhs_M2_CROWS_M153_Abrams
{
	class manual;
};
class RC_RHS_M2_CROWS_M153_Abrams: rhs_M2_CROWS_M153_Abrams_base
{
	canLock=2;
	minZeroing=50;
	maxZeroing=3000;
	magazines[]=
	{
		"RC_RHS_mag_400rnd_127x99_SLAP_T_R",
		"RC_RHS_mag_400rnd_127x99_T_R"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};


class rhs_M2_Abrams_Gunner;
class rhs_M2_Abrams_Gunner_base: rhs_M2_Abrams_Gunner
{
	class manual;
};
class RC_RHS_M2_Abrams_Gunner: rhs_M2_Abrams_Gunner_base
{
	canLock=2;
	minZeroing=50;
	maxZeroing=3000;
	magazines[]=
	{
		"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
		"RC_RHS_mag_200rnd_127x99_T_R"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};


class rhs_weap_m240_abrams_coax;
class rhs_weap_m240_abrams_coax_base: rhs_weap_m240_abrams_coax
{
	class manual;
};
class RC_RHS_weap_m240_abrams_coax: rhs_weap_m240_abrams_coax_base
{
	canLock=2;
	minZeroing=50;
	magazines[]=
	{
		"RC_RHS_mag_1200Rnd_762x51_T_R",
		"RC_RHS_mag_1200Rnd_762x51_M61_T_R"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};


class rhs_weap_m240_bradley_coax;
class rhs_weap_m240_bradley_coax_base: rhs_weap_m240_bradley_coax
{
	class manual;
};
class RC_RHS_weap_m240_bradley_coax: rhs_weap_m240_bradley_coax_base
{
	canLock=2;
	minZeroing=50;
	magazines[]=
	{
		"RC_RHS_mag_1100Rnd_762x51_T_R",
		"RC_RHS_mag_1100Rnd_762x51_M61_T_R"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};


class autocannon_Base_F;
class autocannon_30mm_CTWS: autocannon_Base_F
{
	class HE: autocannon_Base_F
	{
		class player;
		class close;
		class short;
		class medium;
		class far;
	};
	class AP: autocannon_Base_F
	{
		class player;
		class close;
		class short;
		class medium;
		class far;
	};
};
class RC_RHS_weap_M242BC: autocannon_30mm_CTWS
{
	displayName="25mm M242";

	aiDispersioncoefX=4;
	aiDispersioncoefY=6;
	airateoffire=2;
	airateoffiredistance=1000;
	canlock=2;
	FCSMaxLeadSpeed=30.555599;

	class GunParticles
	{
		class Effect
		{
			effectName="AutoCannonFired";
			positionName="Usti hlavne";
			directionName="Konec hlavne";
		};
		class Shell
		{
			positionName="shell_eject_pos";
			directionName="shell_eject_dir";
			effectName="RHS_HeavyGunCartridge1";
		};
	};

	muzzles[]={"HE","AP"};

	class HE: HE
	{
		// - M792 HEI-T
		displayName="25mm M242 - HEI-T";
		magazines[]={"RC_RHS_mag_230Rnd_25mm_HEI_T_R"};
		magazineWell[]={RHS_AutoCannon_25mm_M242_HE};
		canlock=2;
		magazineReloadTime = 0.3;
		modes[]={"player"};
		//200rpm
		class player: player
		{
			reloadTime=__EVAL(60/200);
			textureType="fullAuto";
			dispersion=0.0006;
		};
		FCSMaxLeadSpeed=30.555599;
		minZeroing=50;
	};
	class AP: AP
	{
		// - M919 APFSDS-T
		displayName="25mm M242 - APFSDS-T";
		magazines[]={"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R"};
		magazineWell[]={RHS_AutoCannon_25mm_M242_AP};
		canlock=2;
		magazineReloadTime = 0.3;
		modes[]={"player"};
		//200rpm
		class player: player
		{
			reloadTime=__EVAL(60/200);
			textureType="fullAuto";
			dispersion=0.0006;
		};
		FCSMaxLeadSpeed=30.555599;
		minZeroing=50;
	};
};


class Rhs_weap_TOW_Launcher;
class RC_RHS_weap_TOW_Launcher: Rhs_weap_TOW_Launcher
{
	canLock=2;
	autoReload=1;
	magazines[]=
	{
		"RC_RHS_mag_2Rnd_TOW2A",
		"RC_RHS_mag_2Rnd_TOW2BB"
	};
};


class RC_IFV_Missile_Launcher;
class RC_Bradley_Missile_Launcher_Base: RC_IFV_Missile_Launcher
{
	class Player;
	class TopDown;
}
class RC_Bradley_Missile_Launcher: RC_Bradley_Missile_Launcher_Base
{
	displayName="BGM-71 TOW";
	displayNameShort="BGM-71 TOW";

	magazines[]=
	{
		"RC_2Rnd_TOW_MP_NLOS",
		"RC_2Rnd_TOW_AA"
	};
};


/*
class rhs_weap_fcs_ammo;
class RC_rhs_weap_fcs_ammo: rhs_weap_fcs_ammo
{
	canLock=2;
};
*/


class RHS_M2_CROWS_M151;
class RHS_M2_CROWS_M151_base: RHS_M2_CROWS_M151
{
	class manual;
};
class RC_RHS_M2_CROWS_M151: RHS_M2_CROWS_M151_base
{
	canLock=2;
	minZeroing=50;
	maxZeroing=3000;
	magazines[] =
	{
		"RC_RHS_mag_200rnd_127x99",
		"RC_RHS_mag_200rnd_127x99_T_R",
		"RC_RHS_mag_200rnd_127x99_SLAP",
		"RC_RHS_mag_200rnd_127x99_SLAP_T_R"
	};
	class manual: manual
	{
		dispersion=0.001;
	};
};


class RHS_MK19_CROWS_M153;
class RHS_MK19_CROWS_M153_base: RHS_MK19_CROWS_M153
{
	class manual;
};
class RC_RHS_MK19_CROWS_M153: RHS_MK19_CROWS_M153_base
{
	canLock=2;
	minZeroing=50;
	magazines[] =
	{
		"RC_RHS_96Rnd_40mm_MK19_M430A1"
	};
	class manual: manual
	{
		dispersion=0.0025;
	};
};


/*
class RHS_M2;
class RC_RHS_M2_nonlock: RHS_M2
{
	canLock=0;
	magazines[] =
	{
		"RC_RHS_mag_100rnd_127x99_T_R_nonlock"
	};
};
*/