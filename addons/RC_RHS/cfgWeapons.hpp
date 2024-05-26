class rhs_weap_m240_bradley_coax;
class rhs_weap_m240_bradley_coax_base: rhs_weap_m240_bradley_coax
{
	class manual;
};
class RC_RHS_weap_m240_bradley_coax: rhs_weap_m240_bradley_coax_base
{
	canLock=2;
	minZeroing=15;
	magazines[]=
	{
		"RC_RHS_mag_1100Rnd_762x51_T_R"
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
	FCSMaxLeadSpeed=0;

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

	muzzles[]={"AP","HE"};

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
		FCSMaxLeadSpeed=0;
		minZeroing=20;
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
		FCSMaxLeadSpeed=0;
		minZeroing=15;
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
	magazines[] =
	{
		"RC_RHS_96Rnd_40mm_MK19_M430A1"
	};
	class manual: manual
	{
		dispersion=0.0025;
	};
};