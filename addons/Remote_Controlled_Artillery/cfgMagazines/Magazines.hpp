
class CA_Magazine;
class RC_target_confirmer_mag: CA_Magazine
{
	author="Ascent";
	scope=2;
	ammo="RC_target_confirmer_ammo";
	count=1;
};

//RC ATGM
class Vorona_HEAT;
class RC_1Rnd_ATGM_MP_SACLOS: Vorona_HEAT
{
	displayName="MP 3km SACLOS";
	displayNameShort="MP 3km";
	ammo="RC_M_ATGM_MP_SACLOS";
};
class 1Rnd_GAT_missiles;
class RC_1Rnd_ATGM_MP_Lock: 1Rnd_GAT_missiles
{
	displayName="MP 3km	Guided";
	displayNameShort="MP 3km";
	ammo="RC_M_ATGM_MP_Lock";
};


/*
//for later use
class PylonRack_4Rnd_BombDemine_01_F;
class RC_PylonRack_4Rnd_BombDemine_01_F: PylonRack_4Rnd_BombDemine_01_F
{
	ammo="RC_BombDemine_01_Ammo_F";
	displayName="$STR_A3_PylonRack_4Rnd_BombDemine_01_F0";
	displayNameShort="$STR_A3_PylonRack_4Rnd_BombDemine_01_F0";
	descriptionShort="$STR_A3_PylonRack_4Rnd_BombDemine_01_F1";
	model="\a3\Weapons_F_Orange\DynamicLoadout\PylonRack_4x_BombDemine_01_F.p3d";
	hardpoints[]=
	{
		"ANTIMINE_DRONE_PYLON"
	};
	pylonWeapon="RC_BombDemine_01_F";
	mass=10;
	initSpeed=0.1;
};
*/


//.338NM Vehicle MMG Belts
class VehicleMagazine;
class RC_200Rnd_338_T_R: VehicleMagazine
{
	author="Ascent";
	scope=2;
	count=200;
	ammo="RC_B_338_T_R";
	initSpeed=1006;
	maxLeadSpeed=36.111099;
	tracersEvery=1;	//4
	nameSound="mgun";
	displayName=".338 NM";
	displayNameShort=".338 NM";
	muzzleImpulseFactor[]={0.050000001,0.050000001};
};
class RC_200Rnd_338_T_G: RC_200Rnd_338_T_R
{
	ammo="RC_B_338_T_G";
};
class RC_200Rnd_338_T_Y: RC_200Rnd_338_T_R
{
	ammo="RC_B_338_T_Y";
};


class RC_200Rnd_93x64_T_G: VehicleMagazine
{
	author="Ascent";
	scope=2;
	count=200;
	ammo="RC_B_93x64_T_G";
	initSpeed=957;
	maxLeadSpeed=36.111099;
	tracersEvery=1;	//4
	nameSound="mgun";
	displayName="9.3mm";
	displayNameShort="9.3mm";
	muzzleImpulseFactor[]={0.050000001,0.050000001};
};
class RC_200Rnd_93x64_T_R: RC_200Rnd_93x64_T_G
{
	ammo="RC_B_93x64_T_R";
};
class RC_200Rnd_93x64_T_Y: RC_200Rnd_93x64_T_G
{
	ammo="RC_B_93x64_T_Y";
};
class RC_1000Rnd_93x64_T_G: RC_200Rnd_93x64_T_G
{
	count=1000;
};
class RC_1000Rnd_93x64_T_R: RC_200Rnd_93x64_T_R
{
	count=1000;
};
class RC_1000Rnd_93x64_T_Y: RC_200Rnd_93x64_T_Y
{
	count=1000;
};


class 200Rnd_127x99_mag_Tracer_Red;
class RC_200Rnd_127x99_SLAP_T_R: 200Rnd_127x99_mag_Tracer_Red
{
	author="Ascent";
	ammo="RC_B_127x99_SLAP_T_R";
	count=200;
	tracersEvery=1;	//4
	initSpeed=1200;
	displayName="12.7mm SLAP";
	displayNameShort="12.7mm SLAP";
};
class RC_200Rnd_127x99_SLAP_T_G: RC_200Rnd_127x99_SLAP_T_R
{
	ammo="RC_B_127x99_SLAP_T_G";
};
class RC_200Rnd_127x99_SLAP_T_Y: RC_200Rnd_127x99_SLAP_T_R
{
	ammo="RC_B_127x99_SLAP_T_Y";
};
class RC_100Rnd_127x99_SLAP_T_R: RC_200Rnd_127x99_SLAP_T_R
{
	count=100;
};
class RC_100Rnd_127x99_SLAP_T_G: RC_200Rnd_127x99_SLAP_T_G
{
	count=100;
};
class RC_100Rnd_127x99_SLAP_T_Y: RC_200Rnd_127x99_SLAP_T_Y
{
	count=100;
};


class 96Rnd_40mm_G_belt;
class RC_50Rnd_40mm_G_belt: 96Rnd_40mm_G_belt
{
	author="Ascent";
	ammo="RC_G_40mm_HEDP";
	displayName="40mm HEDP";
	displayNameShort="40mm HEDP";
	count=50;
};
class RC_75Rnd_40mm_G_belt: RC_50Rnd_40mm_G_belt
{
	count=75;
};
class RC_100Rnd_40mm_G_belt: RC_50Rnd_40mm_G_belt
{
	count=100;
};


//Autocannons
class 140Rnd_30mm_MP_shells_Tracer_Red;
class RC_100Rnd_30mm_MP_T_R: 140Rnd_30mm_MP_shells_Tracer_Red
{
	author="Ascent";
	ammo="RC_B_30mm_MP_T_R";
	count=100;
	displayName="30mm MP-T";
	displayNameShort="30mm MP-T";
};
class RC_100Rnd_30mm_MP_T_G: RC_100Rnd_30mm_MP_T_R
{
	ammo="RC_B_30mm_MP_T_G";
};
class RC_100Rnd_30mm_MP_T_Y: RC_100Rnd_30mm_MP_T_R
{
	ammo="RC_B_30mm_MP_T_Y";
};
class RC_100Rnd_30mm_GPR_T_R: RC_100Rnd_30mm_MP_T_R
{
	ammo="RC_B_30mm_GPR_T_R";
	displayName="30mm GPR-T";
	displayNameShort="30mm GPR-T";
};
class RC_100Rnd_30mm_GPR_T_G: RC_100Rnd_30mm_GPR_T_R
{
	ammo="RC_B_30mm_GPR_T_G";
};
class RC_100Rnd_30mm_GPR_T_Y: RC_100Rnd_30mm_GPR_T_R
{
	ammo="RC_B_30mm_GPR_T_Y";
};
class RC_60Rnd_30mm_MP_T_R: RC_100Rnd_30mm_MP_T_R
{
	count=60;
};
class RC_60Rnd_30mm_MP_T_G: RC_100Rnd_30mm_MP_T_G
{
	count=60;
};
class RC_60Rnd_30mm_MP_T_Y: RC_100Rnd_30mm_MP_T_Y
{
	count=60;
};
class RC_60Rnd_30mm_GPR_T_R: RC_100Rnd_30mm_GPR_T_R
{
	count=60;
};
class RC_60Rnd_30mm_GPR_T_G: RC_100Rnd_30mm_GPR_T_G
{
	count=60;
};
class RC_60Rnd_30mm_GPR_T_Y: RC_100Rnd_30mm_GPR_T_Y
{
	count=60;
};


class 60Rnd_30mm_APFSDS_shells_Tracer_Red;
class RC_100Rnd_30mm_APFSDS_T_R: 60Rnd_30mm_APFSDS_shells_Tracer_Red
{
	author="Ascent";
	ammo="RC_B_30mm_APFSDS_T_R";
	count=100;
	displayName="30mm APFSDS-T";
	displayNameShort="30mm APFSDS-T";
};
class RC_100Rnd_30mm_APFSDS_T_G: RC_100Rnd_30mm_APFSDS_T_R
{
	ammo="RC_B_30mm_APFSDS_T_G";
};
class RC_100Rnd_30mm_APFSDS_T_Y: RC_100Rnd_30mm_APFSDS_T_R
{
	ammo="RC_B_30mm_APFSDS_T_Y";
};
/*
class RC_100Rnd_40mm_Smoke: 140Rnd_30mm_MP_shells_Tracer_Red
{
	author="Ascent";
	ammo="RC_B_AC_Smoke";
	count=100;
	displayName="30mm Smoke";
	displayNameShort="30mm Smoke";
};
*/


class 60Rnd_40mm_GPR_Tracer_Red_shells;
class RC_50Rnd_40mm_GPR_T_R: 60Rnd_40mm_GPR_Tracer_Red_shells
{
	author="Ascent";
	ammo="RC_B_40mm_GPR_T_R";
	count=50;
	displayName="40mm GPR-T";
	displayNameShort="40mm GPR-T";
};
class RC_50Rnd_40mm_GPR_T_G: RC_50Rnd_40mm_GPR_T_R
{
	ammo="RC_B_40mm_GPR_T_G";
};
class RC_50Rnd_40mm_GPR_T_Y: RC_50Rnd_40mm_GPR_T_R
{
	ammo="RC_B_40mm_GPR_T_Y";
};
class RC_50Rnd_40mm_MP_T_R: RC_50Rnd_40mm_GPR_T_R
{
	ammo="RC_B_40mm_MP_T_R";
	displayName="40mm MP-T";
	displayNameShort="40mm MP-T";
};
class RC_50Rnd_40mm_MP_T_G: RC_50Rnd_40mm_MP_T_R
{
	ammo="RC_B_40mm_MP_T_G";
};
class RC_50Rnd_40mm_MP_T_Y: RC_50Rnd_40mm_MP_T_R
{
	ammo="RC_B_40mm_MP_T_Y";
};


class 40Rnd_40mm_APFSDS_Tracer_Red_shells;
class RC_50Rnd_40mm_APFSDS_T_R: 40Rnd_40mm_APFSDS_Tracer_Red_shells
{
	author="Ascent";
	ammo="RC_B_40mm_APFSDS_T_R";
	count=50;
	displayName="40mm APFSDS-T";
	displayNameShort="40mm APFSDS-T";
};
class RC_50Rnd_40mm_APFSDS_T_G: RC_50Rnd_40mm_APFSDS_T_R
{
	ammo="RC_B_40mm_APFSDS_T_G";
};
class RC_50Rnd_40mm_APFSDS_T_Y: RC_50Rnd_40mm_APFSDS_T_R
{
	ammo="RC_B_40mm_APFSDS_T_Y";
};
/*
class RC_50Rnd_40mm_Smoke: 60Rnd_40mm_GPR_Tracer_Red_shells
{
	author="Ascent";
	ammo="RC_B_AC_Smoke";
	count=50;
	displayName="40mm Smoke";
	displayNameShort="40mm Smoke";
};
*/


class 2Rnd_GAT_missiles;
class RC_4Rnd_IFV_MP_NLOS: 2Rnd_GAT_missiles
{
	count=4;
	displayName="4km NLOS ATGM";
	displayNameShort="NLOS ATGM";
	ammo="RC_IFV_MP_NLOS";
};
class RC_3Rnd_IFV_MP_NLOS: RC_4Rnd_IFV_MP_NLOS
{
	count=3;
};
class RC_2Rnd_IFV_MP_NLOS: RC_4Rnd_IFV_MP_NLOS
{
	count=2;
};
class RC_1Rnd_IFV_MP_NLOS: RC_4Rnd_IFV_MP_NLOS
{
	count=1;
};
class 4Rnd_Titan_long_missiles;
class RC_4Rnd_IFV_AA: 4Rnd_Titan_long_missiles
{
	count=4;
	displayName="AA 4.5km";
	displayNameShort="AA 4.5km";
	ammo="RC_IFV_AA";
};
class RC_3Rnd_IFV_AA: RC_4Rnd_IFV_AA
{
	count=3;
};
class RC_2Rnd_IFV_AA: RC_4Rnd_IFV_AA
{
	count=2;
};
class RC_1Rnd_IFV_AA: RC_4Rnd_IFV_AA
{
	count=1;
};


// 120mm direct fire
class 8Rnd_120mm_HEAT_MP_T_Red;
class RC_10Rnd_120mm_MP_T_R: 8Rnd_120mm_HEAT_MP_T_Red
{
	ammo="RC_Sh_120mm_MP_T_R";
	displayName="MP-T";
	displayNameShort="MP-T";
	count=10;
};
class RC_15Rnd_120mm_MP_T_R: RC_10Rnd_120mm_MP_T_R
{
	count=15;
};
class RC_20Rnd_120mm_MP_T_R: RC_10Rnd_120mm_MP_T_R
{
	count=20;
};
class RC_10Rnd_120mm_MP_T_G: RC_10Rnd_120mm_MP_T_R
{
	ammo="RC_Sh_120mm_MP_T_G";
};
class RC_15Rnd_120mm_MP_T_G: RC_10Rnd_120mm_MP_T_G
{
	count=15;
};
class RC_20Rnd_120mm_MP_T_G: RC_10Rnd_120mm_MP_T_G
{
	count=20;
};
class RC_10Rnd_120mm_MP_T_Y: RC_10Rnd_120mm_MP_T_R
{
	ammo="RC_Sh_120mm_MP_T_Y";
};
class RC_15Rnd_120mm_MP_T_Y: RC_10Rnd_120mm_MP_T_Y
{
	count=15;
};
class RC_20Rnd_120mm_MP_T_Y: RC_10Rnd_120mm_MP_T_Y
{
	count=20;
};


class 20Rnd_120mm_APFSDS_shells_Tracer_Red;
class RC_10Rnd_120mm_APFSDS_T_R: 20Rnd_120mm_APFSDS_shells_Tracer_Red
{
	displayName="APFSDS-T";
	displayNameShort="APFSDS-T";
	ammo="RC_Sh_120mm_APFSDS_T_R";
	count=10;
};
class RC_15Rnd_120mm_APFSDS_T_R: RC_10Rnd_120mm_APFSDS_T_R
{
	count=15;
};
class RC_20Rnd_120mm_APFSDS_T_R: RC_10Rnd_120mm_APFSDS_T_R
{
	count=20;
};
class RC_10Rnd_120mm_APFSDS_T_G: RC_10Rnd_120mm_APFSDS_T_R
{
	ammo="RC_Sh_120mm_APFSDS_T_G";
};
class RC_15Rnd_120mm_APFSDS_T_G: RC_10Rnd_120mm_APFSDS_T_G
{
	count=15;
};
class RC_20Rnd_120mm_APFSDS_T_G: RC_10Rnd_120mm_APFSDS_T_G
{
	count=20;
};
class RC_10Rnd_120mm_APFSDS_T_Y: RC_10Rnd_120mm_APFSDS_T_R
{
	ammo="RC_Sh_120mm_APFSDS_T_Y";
};
class RC_15Rnd_120mm_APFSDS_T_Y: RC_10Rnd_120mm_APFSDS_T_Y
{
	count=15;
};
class RC_20Rnd_120mm_APFSDS_T_Y: RC_10Rnd_120mm_APFSDS_T_Y
{
	count=20;
};


class 4Rnd_120mm_LG_cannon_missiles;
class RC_4Rnd_120mm_DLG_cannon_missiles: 4Rnd_120mm_LG_cannon_missiles
{
	displayName="4km NLOS ATGM";
	displayNameShort="NLOS ATGM";
	ammo="RC_M_120mm_cannon_ATGM_DLG";
	count=4;
};
class RC_3Rnd_120mm_DLG_cannon_missiles: RC_4Rnd_120mm_DLG_cannon_missiles
{
	count=3;
};
class RC_2Rnd_120mm_DLG_cannon_missiles: RC_4Rnd_120mm_DLG_cannon_missiles
{
	count=2;
};
class RC_1Rnd_120mm_DLG_cannon_missiles: RC_4Rnd_120mm_DLG_cannon_missiles
{
	count=1;
};
class RC_4Rnd_125mm_DLG_cannon_missiles: RC_4Rnd_120mm_DLG_cannon_missiles
{
	ammo="RC_M_125mm_cannon_ATGM_DLG";
};
class RC_3Rnd_125mm_DLG_cannon_missiles: RC_4Rnd_125mm_DLG_cannon_missiles
{
	count=3;
};
class RC_2Rnd_125mm_DLG_cannon_missiles: RC_4Rnd_125mm_DLG_cannon_missiles
{
	count=2;
};
class RC_1Rnd_125mm_DLG_cannon_missiles: RC_4Rnd_125mm_DLG_cannon_missiles
{
	count=1;
};


class 12Rnd_125mm_HEAT_T_Red;
class RC_10Rnd_125mm_MP_T_R: 12Rnd_125mm_HEAT_T_Red
{
	ammo="RC_Sh_125mm_MP_T_R";
	displayName="MP-T";
	displayNameShort="MP-T";
	count=10;
};
class RC_15Rnd_125mm_MP_T_R: RC_10Rnd_125mm_MP_T_R
{
	count=15;
};
class RC_20Rnd_125mm_MP_T_R: RC_10Rnd_125mm_MP_T_R
{
	count=20;
};
class RC_10Rnd_125mm_MP_T_G: RC_10Rnd_125mm_MP_T_R
{
	ammo="RC_Sh_125mm_MP_T_G";
};
class RC_15Rnd_125mm_MP_T_G: RC_10Rnd_125mm_MP_T_G
{
	count=15;
};
class RC_20Rnd_125mm_MP_T_G: RC_10Rnd_125mm_MP_T_G
{
	count=20;
};
class RC_10Rnd_125mm_MP_T_Y: RC_10Rnd_125mm_MP_T_R
{
	ammo="RC_Sh_125mm_MP_T_Y";
};
class RC_15Rnd_125mm_MP_T_Y: RC_10Rnd_125mm_MP_T_Y
{
	count=15;
};
class RC_20Rnd_125mm_MP_T_Y: RC_10Rnd_125mm_MP_T_Y
{
	count=20;
};


class 20Rnd_125mm_APFSDS_T_Red;
class RC_10Rnd_125mm_APFSDS_T_R: 20Rnd_125mm_APFSDS_T_Red
{
	displayName="APFSDS-T";
	displayNameShort="APFSDS-T";
	ammo="RC_Sh_125mm_APFSDS_T_R";
	count=10;
};
class RC_15Rnd_125mm_APFSDS_T_R: RC_10Rnd_125mm_APFSDS_T_R
{
	count=15;
};
class RC_20Rnd_125mm_APFSDS_T_R: RC_10Rnd_125mm_APFSDS_T_R
{
	count=20;
};
class RC_10Rnd_125mm_APFSDS_T_G: RC_10Rnd_125mm_APFSDS_T_R
{
	ammo="RC_Sh_125mm_APFSDS_T_G";
};
class RC_15Rnd_125mm_APFSDS_T_G: RC_10Rnd_125mm_APFSDS_T_G
{
	count=15;
};
class RC_20Rnd_125mm_APFSDS_T_G: RC_10Rnd_125mm_APFSDS_T_G
{
	count=20;
};
class RC_10Rnd_125mm_APFSDS_T_Y: RC_10Rnd_125mm_APFSDS_T_R
{
	ammo="RC_Sh_125mm_APFSDS_T_Y";
};
class RC_15Rnd_125mm_APFSDS_T_Y: RC_10Rnd_125mm_APFSDS_T_Y
{
	count=15;
};
class RC_20Rnd_125mm_APFSDS_T_Y: RC_10Rnd_125mm_APFSDS_T_Y
{
	count=20;
};


//Artillery ammo below
//82mm
class 8Rnd_82mm_Mo_shells;
class RC_1Rnd_82mm_Mo_shells: 8Rnd_82mm_Mo_shells
{
	ammo="RC_Sh_82mm_AMOS_HE";
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="HE";
	displayNameShort="HE";
	count=1;
};
class RC_2Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=2;
};
class RC_3Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=3;
};
class RC_4Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=4;
};
class RC_5Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=5;
};
class RC_6Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=6;
};
class RC_7Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=7;
};
class RC_8Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=8;
};
class RC_9Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=9;
};
class RC_10Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=10;
};
class RC_11Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=11;
};
class RC_12Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=12;
};
class RC_13Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=13;
};
class RC_14Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=14;
};
class RC_15Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=15;
};
class RC_16Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=16;
};
class RC_17Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=17;
};
class RC_18Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=18;
};
class RC_19Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=19;
};
class RC_20Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=20;
};
class RC_21Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=21;
};
class RC_22Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=22;
};
class RC_23Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=23;
};
class RC_24Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=24;
};
class RC_25Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=25;
};
class RC_26Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=26;
};
class RC_27Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=27;
};
class RC_28Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=28;
};
class RC_29Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=29;
};
class RC_30Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=30;
};
class RC_31Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=31;
};
class RC_32Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=32;
};
class RC_33Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=33;
};
class RC_34Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=34;
};
class RC_35Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=35;
};
class RC_36Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=36;
};
class RC_37Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=37;
};
class RC_38Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=38;
};
class RC_39Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=39;
};
class RC_40Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	count=40;
};


class RC_1Rnd_82mm_Mo_HEAB: 8Rnd_82mm_Mo_shells
{
	ammo="RC_Sh_82mm_AMOS_HEAB";
	RC_AimAboveHeight=12.7;		//airburstheight
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="HE Airburst";
	displayNameShort="HE Airburst";
	count=1;
};
class RC_2Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=2;
};
class RC_3Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=3;
};
class RC_4Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=4;
};
class RC_5Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=5;
};
class RC_6Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=6;
};
class RC_7Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=7;
};
class RC_8Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=8;
};
class RC_9Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=9;
};
class RC_10Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=10;
};
class RC_11Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=11;
};
class RC_12Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=12;
};
class RC_13Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=13;
};
class RC_14Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=14;
};
class RC_15Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=15;
};
class RC_16Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=16;
};
class RC_17Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=17;
};
class RC_18Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=18;
};
class RC_19Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=19;
};
class RC_20Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=20;
};
class RC_21Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=21;
};
class RC_22Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=22;
};
class RC_23Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=23;
};
class RC_24Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=24;
};
class RC_25Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=25;
};
class RC_26Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=26;
};
class RC_27Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=27;
};
class RC_28Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=28;
};
class RC_29Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=29;
};
class RC_30Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=30;
};
class RC_31Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=31;
};
class RC_32Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=32;
};
class RC_33Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=33;
};
class RC_34Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=34;
};
class RC_35Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=35;
};
class RC_36Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=36;
};
class RC_37Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=37;
};
class RC_38Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=38;
};
class RC_39Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=39;
};
class RC_40Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	count=40;
};


class RC_1Rnd_82mm_Mo_lowHEAB: 8Rnd_82mm_Mo_shells
{
	ammo="RC_Sh_82mm_AMOS_lowHEAB";
	RC_AimAboveHeight=6;		//airburstheight
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="HE low Airburst";
	displayNameShort="HE low Airburst";
	count=1;
};
class RC_2Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=2;
};
class RC_3Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=3;
};
class RC_4Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=4;
};
class RC_5Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=5;
};
class RC_6Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=6;
};
class RC_7Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=7;
};
class RC_8Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=8;
};
class RC_9Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=9;
};
class RC_10Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=10;
};
class RC_11Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=11;
};
class RC_12Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=12;
};
class RC_13Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=13;
};
class RC_14Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=14;
};
class RC_15Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=15;
};
class RC_16Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=16;
};
class RC_17Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=17;
};
class RC_18Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=18;
};
class RC_19Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=19;
};
class RC_20Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=20;
};
class RC_21Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=21;
};
class RC_22Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=22;
};
class RC_23Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=23;
};
class RC_24Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=24;
};
class RC_25Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=25;
};
class RC_26Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=26;
};
class RC_27Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=27;
};
class RC_28Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=28;
};
class RC_29Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=29;
};
class RC_30Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=30;
};
class RC_31Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=31;
};
class RC_32Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=32;
};
class RC_33Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=33;
};
class RC_34Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=34;
};
class RC_35Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=35;
};
class RC_36Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=36;
};
class RC_37Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=37;
};
class RC_38Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=38;
};
class RC_39Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=39;
};
class RC_40Rnd_82mm_Mo_lowHEAB: RC_1Rnd_82mm_Mo_lowHEAB
{
	count=40;
};


class 8Rnd_82mm_Mo_Flare_white;
class RC_1Rnd_82mm_Mo_Flare_white: 8Rnd_82mm_Mo_Flare_white
{
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="Illumination";
	displayNameShort="Illum";
	count=1;
};
class RC_2Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=2;
};
class RC_3Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=3;
};
class RC_4Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=4;
};
class RC_5Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=5;
};
class RC_6Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=6;
};
class RC_7Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=7;
};
class RC_8Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=8;
};
class RC_9Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=9;
};
class RC_10Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=10;
};
class RC_11Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=11;
};
class RC_12Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=12;
};
class RC_13Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=13;
};
class RC_14Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=14;
};
class RC_15Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=15;
};
class RC_16Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=16;
};
class RC_17Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=17;
};
class RC_18Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=18;
};
class RC_19Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=19;
};
class RC_20Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=20;
};
class RC_21Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=21;
};
class RC_22Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=22;
};
class RC_23Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=23;
};
class RC_24Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=24;
};
class RC_25Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=25;
};
class RC_26Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=26;
};
class RC_27Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=27;
};
class RC_28Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=28;
};
class RC_29Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=29;
};
class RC_30Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=30;
};
class RC_31Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=31;
};
class RC_32Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=32;
};
class RC_33Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=33;
};
class RC_34Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=34;
};
class RC_35Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=35;
};
class RC_36Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=36;
};
class RC_37Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=37;
};
class RC_38Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=38;
};
class RC_39Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=39;
};
class RC_40Rnd_82mm_Mo_Flare_white: RC_1Rnd_82mm_Mo_Flare_white
{
	count=40;
};


class 8Rnd_82mm_Mo_Smoke_white;
class RC_1Rnd_82mm_Mo_Smoke_white: 8Rnd_82mm_Mo_Smoke_white
{
	ammo="RC_Smoke_82mm_AMOS_White";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Smoke";
	displayNameShort="Smoke";
	count=1;
};
class RC_2Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=2;
};
class RC_3Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=3;
};
class RC_4Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=4;
};
class RC_5Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=5;
};
class RC_6Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=6;
};
class RC_7Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=7;
};
class RC_8Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=8;
};
class RC_9Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=9;
};
class RC_10Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=10;
};
class RC_11Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=11;
};
class RC_12Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=12;
};
class RC_13Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=13;
};
class RC_14Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=14;
};
class RC_15Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=15;
};
class RC_16Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=16;
};
class RC_17Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=17;
};
class RC_18Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=18;
};
class RC_19Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=19;
};
class RC_20Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=20;
};
class RC_21Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=21;
};
class RC_22Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=22;
};
class RC_23Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=23;
};
class RC_24Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=24;
};
class RC_25Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=25;
};
class RC_26Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=26;
};
class RC_27Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=27;
};
class RC_28Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=28;
};
class RC_29Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=29;
};
class RC_30Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=30;
};
class RC_31Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=31;
};
class RC_32Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=32;
};
class RC_33Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=33;
};
class RC_34Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=34;
};
class RC_35Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=35;
};
class RC_36Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=36;
};
class RC_37Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=37;
};
class RC_38Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=38;
};
class RC_39Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=39;
};
class RC_40Rnd_82mm_Mo_Smoke_white: RC_1Rnd_82mm_Mo_Smoke_white
{
	count=40;
};


class 8Rnd_82mm_Mo_LG;
class RC_1Rnd_82mm_Mo_LaserGuided: 8Rnd_82mm_Mo_LG
{
	ammo="RC_Sh_82mm_AMOS_MP_LaserGuided";
	RC_AimAboveHeight=270;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="MP Laser Guided";
	displayNameShort="MP Laser Guided";
	count=1;
};
class RC_2Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=2;
};
class RC_3Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=3;
};
class RC_4Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=4;
};
class RC_5Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=5;
};
class RC_6Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=6;
};
class RC_7Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=7;
};
class RC_8Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=8;
};
class RC_9Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=9;
};
class RC_10Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=10;
};
class RC_11Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=11;
};
class RC_12Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=12;
};
class RC_13Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=13;
};
class RC_14Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=14;
};
class RC_15Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=15;
};
class RC_16Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=16;
};
class RC_17Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=17;
};
class RC_18Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=18;
};
class RC_19Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=19;
};
class RC_20Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=20;
};
class RC_21Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=21;
};
class RC_22Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=22;
};
class RC_23Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=23;
};
class RC_24Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=24;
};
class RC_25Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=25;
};
class RC_26Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=26;
};
class RC_27Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=27;
};
class RC_28Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=28;
};
class RC_29Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=29;
};
class RC_30Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=30;
};
class RC_31Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=31;
};
class RC_32Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=32;
};
class RC_33Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=33;
};
class RC_34Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=34;
};
class RC_35Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=35;
};
class RC_36Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=36;
};
class RC_37Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=37;
};
class RC_38Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=38;
};
class RC_39Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=39;
};
class RC_40Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	count=40;
};


class RC_1Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	ammo="RC_Sh_82mm_AMOS_MP_MultiGuided";
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="MP Guided";
	displayNameShort="MP Guided";
};
class RC_2Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=2;
};
class RC_3Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=3;
};
class RC_4Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=4;
};
class RC_5Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=5;
};
class RC_6Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=6;
};
class RC_7Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=7;
};
class RC_8Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=8;
};
class RC_9Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=9;
};
class RC_10Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=10;
};
class RC_11Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=11;
};
class RC_12Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=12;
};
class RC_13Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=13;
};
class RC_14Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=14;
};
class RC_15Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=15;
};
class RC_16Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=16;
};
class RC_17Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=17;
};
class RC_18Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=18;
};
class RC_19Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=19;
};
class RC_20Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=20;
};
class RC_21Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=21;
};
class RC_22Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=22;
};
class RC_23Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=23;
};
class RC_24Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=24;
};
class RC_25Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=25;
};
class RC_26Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=26;
};
class RC_27Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=27;
};
class RC_28Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=28;
};
class RC_29Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=29;
};
class RC_30Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=30;
};
class RC_31Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=31;
};
class RC_32Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=32;
};
class RC_33Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=33;
};
class RC_34Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=34;
};
class RC_35Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=35;
};
class RC_36Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=36;
};
class RC_37Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=37;
};
class RC_38Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=38;
};
class RC_39Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=39;
};
class RC_40Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	count=40;
};


class RC_1Rnd_82mm_Mo_mine: 8Rnd_82mm_Mo_shells
{
	ammo="RC_Mine_82mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AP Mines";
	displayNameShort="AP Mines";
	count=1;
};
class RC_2Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=2;
};
class RC_3Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=3;
};
class RC_4Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=4;
};
class RC_5Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=5;
};
class RC_6Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=6;
};
class RC_7Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=7;
};
class RC_8Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=8;
};
class RC_9Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=9;
};
class RC_10Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=10;
};
class RC_11Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=11;
};
class RC_12Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=12;
};
class RC_13Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=13;
};
class RC_14Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=14;
};
class RC_15Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=15;
};
class RC_16Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=16;
};
class RC_17Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=17;
};
class RC_18Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=18;
};
class RC_19Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=19;
};
class RC_20Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=20;
};
class RC_21Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=21;
};
class RC_22Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=22;
};
class RC_23Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=23;
};
class RC_24Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=24;
};
class RC_25Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=25;
};
class RC_26Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=26;
};
class RC_27Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=27;
};
class RC_28Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=28;
};
class RC_29Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=29;
};
class RC_30Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=30;
};
class RC_31Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=31;
};
class RC_32Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=32;
};
class RC_33Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=33;
};
class RC_34Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=34;
};
class RC_35Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=35;
};
class RC_36Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=36;
};
class RC_37Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=37;
};
class RC_38Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=38;
};
class RC_39Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=39;
};
class RC_40Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	count=40;
};


class RC_1Rnd_82mm_Mo_AT_mine: 8Rnd_82mm_Mo_shells
{
	ammo="RC_AT_Mine_82mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AT Mines";
	displayNameShort="AT Mines";
	count=1;
};
class RC_2Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=2;
};
class RC_3Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=3;
};
class RC_4Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=4;
};
class RC_5Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=5;
};
class RC_6Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=6;
};
class RC_7Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=7;
};
class RC_8Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=8;
};
class RC_9Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=9;
};
class RC_10Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=10;
};
class RC_11Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=11;
};
class RC_12Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=12;
};
class RC_13Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=13;
};
class RC_14Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=14;
};
class RC_15Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=15;
};
class RC_16Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=16;
};
class RC_17Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=17;
};
class RC_18Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=18;
};
class RC_19Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=19;
};
class RC_20Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=20;
};
class RC_21Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=21;
};
class RC_22Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=22;
};
class RC_23Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=23;
};
class RC_24Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=24;
};
class RC_25Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=25;
};
class RC_26Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=26;
};
class RC_27Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=27;
};
class RC_28Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=28;
};
class RC_29Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=29;
};
class RC_30Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=30;
};
class RC_31Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=31;
};
class RC_32Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=32;
};
class RC_33Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=33;
};
class RC_34Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=34;
};
class RC_35Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=35;
};
class RC_36Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=36;
};
class RC_37Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=37;
};
class RC_38Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=38;
};
class RC_39Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=39;
};
class RC_40Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	count=40;
};


class RC_1Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LaserGuided
{
	ammo="RC_Sh_82mm_AMOS_LG_DelayedFuse";
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="LG 2m Delayed";
	displayNameShort="LG 2m Delayed";
};
class RC_2Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=2;
};
class RC_3Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=3;
};
class RC_4Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=4;
};
class RC_5Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=5;
};
class RC_6Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=6;
};
class RC_7Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=7;
};
class RC_8Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=8;
};
class RC_9Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=9;
};
class RC_10Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=10;
};
class RC_11Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=11;
};
class RC_12Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=12;
};
class RC_13Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=13;
};
class RC_14Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=14;
};
class RC_15Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=15;
};
class RC_16Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=16;
};
class RC_17Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=17;
};
class RC_18Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=18;
};
class RC_19Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=19;
};
class RC_20Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=20;
};
class RC_21Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=21;
};
class RC_22Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=22;
};
class RC_23Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=23;
};
class RC_24Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=24;
};
class RC_25Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=25;
};
class RC_26Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=26;
};
class RC_27Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=27;
};
class RC_28Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=28;
};
class RC_29Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=29;
};
class RC_30Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=30;
};
class RC_31Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=31;
};
class RC_32Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=32;
};
class RC_33Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=33;
};
class RC_34Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=34;
};
class RC_35Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=35;
};
class RC_36Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=36;
};
class RC_37Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=37;
};
class RC_38Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=38;
};
class RC_39Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=39;
};
class RC_40Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_82mm_Mo_backupHEAB: 8Rnd_82mm_Mo_shells
{
	ammo="RC_Sh_82mm_AMOS_backupHEAB";
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="HE AB [direct]";
	displayNameShort="HE Airburst";
	count=1;
};
class RC_2Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=2;
};
class RC_3Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=3;
};
class RC_4Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=4;
};
class RC_5Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=5;
};
class RC_6Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=6;
};
class RC_7Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=7;
};
class RC_8Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=8;
};
class RC_9Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=9;
};
class RC_10Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=10;
};
class RC_11Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=11;
};
class RC_12Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=12;
};
class RC_13Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=13;
};
class RC_14Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=14;
};
class RC_15Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=15;
};
class RC_16Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=16;
};
class RC_17Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=17;
};
class RC_18Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=18;
};
class RC_19Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=19;
};
class RC_20Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=20;
};
class RC_21Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=21;
};
class RC_22Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=22;
};
class RC_23Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=23;
};
class RC_24Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=24;
};
class RC_25Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=25;
};
class RC_26Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=26;
};
class RC_27Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=27;
};
class RC_28Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=28;
};
class RC_29Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=29;
};
class RC_30Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=30;
};
class RC_31Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=31;
};
class RC_32Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=32;
};
class RC_33Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=33;
};
class RC_34Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=34;
};
class RC_35Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=35;
};
class RC_36Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=36;
};
class RC_37Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=37;
};
class RC_38Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=38;
};
class RC_39Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=39;
};
class RC_40Rnd_82mm_Mo_backupHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backupHEAB
{
	displayName="HE lAB [direct]";
	displayNameShort="HE lAB [direct]";
};
class RC_2Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=2;
};
class RC_3Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=3;
};
class RC_4Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=4;
};
class RC_5Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=5;
};
class RC_6Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=6;
};
class RC_7Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=7;
};
class RC_8Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=8;
};
class RC_9Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=9;
};
class RC_10Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=10;
};
class RC_11Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=11;
};
class RC_12Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=12;
};
class RC_13Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=13;
};
class RC_14Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=14;
};
class RC_15Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=15;
};
class RC_16Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=16;
};
class RC_17Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=17;
};
class RC_18Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=18;
};
class RC_19Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=19;
};
class RC_20Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=20;
};
class RC_21Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=21;
};
class RC_22Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=22;
};
class RC_23Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=23;
};
class RC_24Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=24;
};
class RC_25Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=25;
};
class RC_26Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=26;
};
class RC_27Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=27;
};
class RC_28Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=28;
};
class RC_29Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=29;
};
class RC_30Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=30;
};
class RC_31Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=31;
};
class RC_32Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=32;
};
class RC_33Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=33;
};
class RC_34Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=34;
};
class RC_35Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=35;
};
class RC_36Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=36;
};
class RC_37Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=37;
};
class RC_38Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=38;
};
class RC_39Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=39;
};
class RC_40Rnd_82mm_Mo_backuplowHEAB: RC_1Rnd_82mm_Mo_backuplowHEAB
{
	count=40;
};


// 105mm
class 32Rnd_155mm_Mo_shells;
class RC_1Rnd_105mm_Mo_shells: 32Rnd_155mm_Mo_shells
{
	initSpeed=400;
	ammo="RC_Sh_105mm_AMOS_HE";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE";
	displayNameShort="HE";
	count=1;
};
class RC_2Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=2;
};
class RC_3Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=3;
};
class RC_4Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=4;
};
class RC_5Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=5;
};
class RC_6Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=6;
};
class RC_7Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=7;
};
class RC_8Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=8;
};
class RC_9Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=9;
};
class RC_10Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=10;
};
class RC_11Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=11;
};
class RC_12Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=12;
};
class RC_13Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=13;
};
class RC_14Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=14;
};
class RC_15Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=15;
};
class RC_16Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=16;
};
class RC_17Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=17;
};
class RC_18Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=18;
};
class RC_19Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=19;
};
class RC_20Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=20;
};
class RC_21Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=21;
};
class RC_22Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=22;
};
class RC_23Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=23;
};
class RC_24Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=24;
};
class RC_25Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=25;
};
class RC_26Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=26;
};
class RC_27Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=27;
};
class RC_28Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=28;
};
class RC_29Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=29;
};
class RC_30Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=30;
};
class RC_31Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=31;
};
class RC_32Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=32;
};
class RC_33Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=33;
};
class RC_34Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=34;
};
class RC_35Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=35;
};
class RC_36Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=36;
};
class RC_37Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=37;
};
class RC_38Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=38;
};
class RC_39Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=39;
};
class RC_40Rnd_105mm_Mo_shells: RC_1Rnd_105mm_Mo_shells
{
	count=40;
};


class RC_1Rnd_105mm_Mo_HEAB: 32Rnd_155mm_Mo_shells
{
	initSpeed=400;
	ammo="RC_Sh_105mm_AMOS_HEAB";
	RC_AimAboveHeight=15.3;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE Airburst";
	displayNameShort="HE Airburst";
	count=1;
};
class RC_2Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=2;
};
class RC_3Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=3;
};
class RC_4Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=4;
};
class RC_5Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=5;
};
class RC_6Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=6;
};
class RC_7Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=7;
};
class RC_8Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=8;
};
class RC_9Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=9;
};
class RC_10Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=10;
};
class RC_11Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=11;
};
class RC_12Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=12;
};
class RC_13Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=13;
};
class RC_14Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=14;
};
class RC_15Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=15;
};
class RC_16Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=16;
};
class RC_17Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=17;
};
class RC_18Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=18;
};
class RC_19Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=19;
};
class RC_20Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=20;
};
class RC_21Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=21;
};
class RC_22Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=22;
};
class RC_23Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=23;
};
class RC_24Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=24;
};
class RC_25Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=25;
};
class RC_26Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=26;
};
class RC_27Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=27;
};
class RC_28Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=28;
};
class RC_29Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=29;
};
class RC_30Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=30;
};
class RC_31Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=31;
};
class RC_32Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=32;
};
class RC_33Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=33;
};
class RC_34Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=34;
};
class RC_35Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=35;
};
class RC_36Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=36;
};
class RC_37Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=37;
};
class RC_38Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=38;
};
class RC_39Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=39;
};
class RC_40Rnd_105mm_Mo_HEAB: RC_1Rnd_105mm_Mo_HEAB
{
	count=40;
};


class RC_1Rnd_105mm_Mo_lowHEAB: 32Rnd_155mm_Mo_shells
{
	initSpeed=400;
	ammo="RC_Sh_105mm_AMOS_lowHEAB";
	RC_AimAboveHeight=6;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE low Airburst";
	displayNameShort="HE low Airburst";
	count=1;
};
class RC_2Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=2;
};
class RC_3Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=3;
};
class RC_4Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=4;
};
class RC_5Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=5;
};
class RC_6Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=6;
};
class RC_7Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=7;
};
class RC_8Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=8;
};
class RC_9Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=9;
};
class RC_10Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=10;
};
class RC_11Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=11;
};
class RC_12Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=12;
};
class RC_13Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=13;
};
class RC_14Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=14;
};
class RC_15Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=15;
};
class RC_16Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=16;
};
class RC_17Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=17;
};
class RC_18Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=18;
};
class RC_19Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=19;
};
class RC_20Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=20;
};
class RC_21Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=21;
};
class RC_22Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=22;
};
class RC_23Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=23;
};
class RC_24Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=24;
};
class RC_25Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=25;
};
class RC_26Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=26;
};
class RC_27Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=27;
};
class RC_28Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=28;
};
class RC_29Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=29;
};
class RC_30Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=30;
};
class RC_31Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=31;
};
class RC_32Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=32;
};
class RC_33Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=33;
};
class RC_34Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=34;
};
class RC_35Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=35;
};
class RC_36Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=36;
};
class RC_37Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=37;
};
class RC_38Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=38;
};
class RC_39Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=39;
};
class RC_40Rnd_105mm_Mo_lowHEAB: RC_1Rnd_105mm_Mo_lowHEAB
{
	count=40;
};


class 6Rnd_155mm_Mo_mine;
class RC_1Rnd_105mm_Mo_mine: 6Rnd_155mm_Mo_mine
{
	initSpeed=400;
	ammo="RC_Mine_105mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AP Mines";
	displayNameShort="AP Mines";
	count=1;
};
class RC_2Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=2;
};
class RC_3Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=3;
};
class RC_4Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=4;
};
class RC_5Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=5;
};
class RC_6Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=6;
};
class RC_7Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=7;
};
class RC_8Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=8;
};
class RC_9Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=9;
};
class RC_10Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=10;
};
class RC_11Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=11;
};
class RC_12Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=12;
};
class RC_13Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=13;
};
class RC_14Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=14;
};
class RC_15Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=15;
};
class RC_16Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=16;
};
class RC_17Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=17;
};
class RC_18Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=18;
};
class RC_19Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=19;
};
class RC_20Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=20;
};
class RC_21Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=21;
};
class RC_22Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=22;
};
class RC_23Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=23;
};
class RC_24Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=24;
};
class RC_25Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=25;
};
class RC_26Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=26;
};
class RC_27Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=27;
};
class RC_28Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=28;
};
class RC_29Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=29;
};
class RC_30Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=30;
};
class RC_31Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=31;
};
class RC_32Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=32;
};
class RC_33Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=33;
};
class RC_34Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=34;
};
class RC_35Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=35;
};
class RC_36Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=36;
};
class RC_37Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=37;
};
class RC_38Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=38;
};
class RC_39Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=39;
};
class RC_40Rnd_105mm_Mo_mine: RC_1Rnd_105mm_Mo_mine
{
	count=40;
};


class 2Rnd_155mm_Mo_Cluster;
class RC_1Rnd_105mm_Mo_Cluster: 2Rnd_155mm_Mo_Cluster
{
	initSpeed=400;
	ammo="RC_Cluster_105mm_AMOS";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Cluster [7% UXO]";
	displayNameShort="Cluster";
	count=1;
};
class RC_2Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=2;
};
class RC_3Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=3;
};
class RC_4Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=4;
};
class RC_5Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=5;
};
class RC_6Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=6;
};
class RC_7Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=7;
};
class RC_8Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=8;
};
class RC_9Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=9;
};
class RC_10Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=10;
};
class RC_11Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=11;
};
class RC_12Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=12;
};
class RC_13Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=13;
};
class RC_14Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=14;
};
class RC_15Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=15;
};
class RC_16Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=16;
};
class RC_17Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=17;
};
class RC_18Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=18;
};
class RC_19Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=19;
};
class RC_20Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=20;
};
class RC_21Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=21;
};
class RC_22Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=22;
};
class RC_23Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=23;
};
class RC_24Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=24;
};
class RC_25Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=25;
};
class RC_26Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=26;
};
class RC_27Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=27;
};
class RC_28Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=28;
};
class RC_29Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=29;
};
class RC_30Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=30;
};
class RC_31Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=31;
};
class RC_32Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=32;
};
class RC_33Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=33;
};
class RC_34Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=34;
};
class RC_35Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=35;
};
class RC_36Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=36;
};
class RC_37Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=37;
};
class RC_38Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=38;
};
class RC_39Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=39;
};
class RC_40Rnd_105mm_Mo_Cluster: RC_1Rnd_105mm_Mo_Cluster
{
	count=40;
};


class 6Rnd_155mm_Mo_smoke;
class RC_1Rnd_105mm_Mo_smoke: 6Rnd_155mm_Mo_smoke
{
	initSpeed=400;
	ammo="RC_Smoke_155mm_AMOS_White";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Smoke";
	displayNameShort="Smoke";
	count=1;
};
class RC_2Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=2;
};
class RC_3Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=3;
};
class RC_4Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=4;
};
class RC_5Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=5;
};
class RC_6Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=6;
};
class RC_7Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=7;
};
class RC_8Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=8;
};
class RC_9Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=9;
};
class RC_10Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=10;
};
class RC_11Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=11;
};
class RC_12Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=12;
};
class RC_13Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=13;
};
class RC_14Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=14;
};
class RC_15Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=15;
};
class RC_16Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=16;
};
class RC_17Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=17;
};
class RC_18Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=18;
};
class RC_19Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=19;
};
class RC_20Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=20;
};
class RC_21Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=21;
};
class RC_22Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=22;
};
class RC_23Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=23;
};
class RC_24Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=24;
};
class RC_25Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=25;
};
class RC_26Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=26;
};
class RC_27Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=27;
};
class RC_28Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=28;
};
class RC_29Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=29;
};
class RC_30Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=30;
};
class RC_31Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=31;
};
class RC_32Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=32;
};
class RC_33Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=33;
};
class RC_34Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=34;
};
class RC_35Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=35;
};
class RC_36Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=36;
};
class RC_37Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=37;
};
class RC_38Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=38;
};
class RC_39Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=39;
};
class RC_40Rnd_105mm_Mo_smoke: RC_1Rnd_105mm_Mo_smoke
{
	count=40;
};


class 2Rnd_155mm_Mo_LG;
class RC_1Rnd_105mm_Mo_LaserGuided: 2Rnd_155mm_Mo_LG
{
	initSpeed=400;
	ammo="RC_Sh_105mm_AMOS_MP_LaserGuided";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Laser Guided";
	displayNameShort="MP Laser Guided";
	count=1;
};
class RC_2Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=2;
};
class RC_3Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=3;
};
class RC_4Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=4;
};
class RC_5Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=5;
};
class RC_6Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=6;
};
class RC_7Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=7;
};
class RC_8Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=8;
};
class RC_9Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=9;
};
class RC_10Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=10;
};
class RC_11Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=11;
};
class RC_12Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=12;
};
class RC_13Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=13;
};
class RC_14Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=14;
};
class RC_15Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=15;
};
class RC_16Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=16;
};
class RC_17Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=17;
};
class RC_18Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=18;
};
class RC_19Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=19;
};
class RC_20Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=20;
};
class RC_21Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=21;
};
class RC_22Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=22;
};
class RC_23Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=23;
};
class RC_24Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=24;
};
class RC_25Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=25;
};
class RC_26Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=26;
};
class RC_27Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=27;
};
class RC_28Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=28;
};
class RC_29Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=29;
};
class RC_30Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=30;
};
class RC_31Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=31;
};
class RC_32Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=32;
};
class RC_33Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=33;
};
class RC_34Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=34;
};
class RC_35Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=35;
};
class RC_36Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=36;
};
class RC_37Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=37;
};
class RC_38Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=38;
};
class RC_39Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=39;
};
class RC_40Rnd_105mm_Mo_LaserGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	count=40;
};


class RC_1Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_LaserGuided
{
	ammo="RC_Sh_105mm_AMOS_MP_MultiGuided";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Guided";
	displayNameShort="MP Guided";
};
class RC_2Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=2;
};
class RC_3Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=3;
};
class RC_4Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=4;
};
class RC_5Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=5;
};
class RC_6Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=6;
};
class RC_7Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=7;
};
class RC_8Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=8;
};
class RC_9Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=9;
};
class RC_10Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=10;
};
class RC_11Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=11;
};
class RC_12Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=12;
};
class RC_13Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=13;
};
class RC_14Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=14;
};
class RC_15Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=15;
};
class RC_16Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=16;
};
class RC_17Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=17;
};
class RC_18Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=18;
};
class RC_19Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=19;
};
class RC_20Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=20;
};
class RC_21Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=21;
};
class RC_22Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=22;
};
class RC_23Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=23;
};
class RC_24Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=24;
};
class RC_25Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=25;
};
class RC_26Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=26;
};
class RC_27Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=27;
};
class RC_28Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=28;
};
class RC_29Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=29;
};
class RC_30Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=30;
};
class RC_31Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=31;
};
class RC_32Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=32;
};
class RC_33Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=33;
};
class RC_34Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=34;
};
class RC_35Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=35;
};
class RC_36Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=36;
};
class RC_37Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=37;
};
class RC_38Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=38;
};
class RC_39Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=39;
};
class RC_40Rnd_105mm_Mo_MultiGuided: RC_1Rnd_105mm_Mo_MultiGuided
{
	count=40;
};


class 6Rnd_155mm_Mo_AT_mine;
class RC_1Rnd_105mm_Mo_AT_mine: 6Rnd_155mm_Mo_AT_mine
{
	initSpeed=400;
	ammo="RC_AT_Mine_105mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AT Mines";
	displayNameShort="AT Mines";
	count=1;
};
class RC_2Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=2;
};
class RC_3Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=3;
};
class RC_4Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=4;
};
class RC_5Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=5;
};
class RC_6Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=6;
};
class RC_7Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=7;
};
class RC_8Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=8;
};
class RC_9Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=9;
};
class RC_10Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=10;
};
class RC_11Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=11;
};
class RC_12Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=12;
};
class RC_13Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=13;
};
class RC_14Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=14;
};
class RC_15Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=15;
};
class RC_16Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=16;
};
class RC_17Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=17;
};
class RC_18Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=18;
};
class RC_19Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=19;
};
class RC_20Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=20;
};
class RC_21Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=21;
};
class RC_22Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=22;
};
class RC_23Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=23;
};
class RC_24Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=24;
};
class RC_25Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=25;
};
class RC_26Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=26;
};
class RC_27Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=27;
};
class RC_28Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=28;
};
class RC_29Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=29;
};
class RC_30Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=30;
};
class RC_31Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=31;
};
class RC_32Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=32;
};
class RC_33Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=33;
};
class RC_34Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=34;
};
class RC_35Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=35;
};
class RC_36Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=36;
};
class RC_37Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=37;
};
class RC_38Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=38;
};
class RC_39Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=39;
};
class RC_40Rnd_105mm_Mo_AT_mine: RC_1Rnd_105mm_Mo_AT_mine
{
	count=40;
};


class RC_1Rnd_105mm_Mo_Illum: 32Rnd_155mm_Mo_shells
{
	initSpeed=400;
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="Illumination";
	displayNameShort="Illum";
	ammo="Flare_155mm_AMOS_White";
	count=1;
};
class RC_2Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=2;
};
class RC_3Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=3;
};
class RC_4Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=4;
};
class RC_5Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=5;
};
class RC_6Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=6;
};
class RC_7Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=7;
};
class RC_8Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=8;
};
class RC_9Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=9;
};
class RC_10Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=10;
};
class RC_11Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=11;
};
class RC_12Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=12;
};
class RC_13Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=13;
};
class RC_14Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=14;
};
class RC_15Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=15;
};
class RC_16Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=16;
};
class RC_17Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=17;
};
class RC_18Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=18;
};
class RC_19Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=19;
};
class RC_20Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=20;
};
class RC_21Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=21;
};
class RC_22Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=22;
};
class RC_23Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=23;
};
class RC_24Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=24;
};
class RC_25Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=25;
};
class RC_26Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=26;
};
class RC_27Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=27;
};
class RC_28Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=28;
};
class RC_29Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=29;
};
class RC_30Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=30;
};
class RC_31Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=31;
};
class RC_32Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=32;
};
class RC_33Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=33;
};
class RC_34Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=34;
};
class RC_35Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=35;
};
class RC_36Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=36;
};
class RC_37Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=37;
};
class RC_38Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=38;
};
class RC_39Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=39;
};
class RC_40Rnd_105mm_Mo_Illum: RC_1Rnd_105mm_Mo_Illum
{
	count=40;
};


class RC_1Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LaserGuided
{
	ammo="RC_Sh_105mm_AMOS_LG_DelayedFuse";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="LG 2m Delayed";
	displayNameShort="LG 2m Delayed";
};
class RC_2Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=2;
};
class RC_3Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=3;
};
class RC_4Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=4;
};
class RC_5Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=5;
};
class RC_6Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=6;
};
class RC_7Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=7;
};
class RC_8Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=8;
};
class RC_9Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=9;
};
class RC_10Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=10;
};
class RC_11Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=11;
};
class RC_12Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=12;
};
class RC_13Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=13;
};
class RC_14Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=14;
};
class RC_15Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=15;
};
class RC_16Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=16;
};
class RC_17Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=17;
};
class RC_18Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=18;
};
class RC_19Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=19;
};
class RC_20Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=20;
};
class RC_21Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=21;
};
class RC_22Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=22;
};
class RC_23Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=23;
};
class RC_24Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=24;
};
class RC_25Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=25;
};
class RC_26Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=26;
};
class RC_27Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=27;
};
class RC_28Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=28;
};
class RC_29Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=29;
};
class RC_30Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=30;
};
class RC_31Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=31;
};
class RC_32Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=32;
};
class RC_33Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=33;
};
class RC_34Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=34;
};
class RC_35Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=35;
};
class RC_36Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=36;
};
class RC_37Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=37;
};
class RC_38Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=38;
};
class RC_39Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=39;
};
class RC_40Rnd_105mm_Mo_LG_DelayedFuse: RC_1Rnd_105mm_Mo_LG_DelayedFuse
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_105mm_Mo_backupHEAB: 32Rnd_155mm_Mo_shells
{
	initSpeed=400;
	ammo="RC_Sh_105mm_AMOS_backupHEAB";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE AB [direct]";
	displayNameShort="HE AB [direct]";
	count=1;
};
class RC_2Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=2;
};
class RC_3Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=3;
};
class RC_4Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=4;
};
class RC_5Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=5;
};
class RC_6Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=6;
};
class RC_7Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=7;
};
class RC_8Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=8;
};
class RC_9Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=9;
};
class RC_10Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=10;
};
class RC_11Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=11;
};
class RC_12Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=12;
};
class RC_13Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=13;
};
class RC_14Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=14;
};
class RC_15Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=15;
};
class RC_16Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=16;
};
class RC_17Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=17;
};
class RC_18Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=18;
};
class RC_19Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=19;
};
class RC_20Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=20;
};
class RC_21Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=21;
};
class RC_22Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=22;
};
class RC_23Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=23;
};
class RC_24Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=24;
};
class RC_25Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=25;
};
class RC_26Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=26;
};
class RC_27Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=27;
};
class RC_28Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=28;
};
class RC_29Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=29;
};
class RC_30Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=30;
};
class RC_31Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=31;
};
class RC_32Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=32;
};
class RC_33Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=33;
};
class RC_34Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=34;
};
class RC_35Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=35;
};
class RC_36Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=36;
};
class RC_37Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=37;
};
class RC_38Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=38;
};
class RC_39Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=39;
};
class RC_40Rnd_105mm_Mo_backupHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backupHEAB
{
	displayName="HE lAB [direct]";
	displayNameShort="HE lAB [direct]";
};
class RC_2Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=2;
};
class RC_3Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=3;
};
class RC_4Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=4;
};
class RC_5Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=5;
};
class RC_6Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=6;
};
class RC_7Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=7;
};
class RC_8Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=8;
};
class RC_9Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=9;
};
class RC_10Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=10;
};
class RC_11Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=11;
};
class RC_12Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=12;
};
class RC_13Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=13;
};
class RC_14Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=14;
};
class RC_15Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=15;
};
class RC_16Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=16;
};
class RC_17Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=17;
};
class RC_18Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=18;
};
class RC_19Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=19;
};
class RC_20Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=20;
};
class RC_21Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=21;
};
class RC_22Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=22;
};
class RC_23Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=23;
};
class RC_24Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=24;
};
class RC_25Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=25;
};
class RC_26Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=26;
};
class RC_27Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=27;
};
class RC_28Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=28;
};
class RC_29Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=29;
};
class RC_30Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=30;
};
class RC_31Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=31;
};
class RC_32Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=32;
};
class RC_33Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=33;
};
class RC_34Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=34;
};
class RC_35Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=35;
};
class RC_36Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=36;
};
class RC_37Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=37;
};
class RC_38Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=38;
};
class RC_39Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=39;
};
class RC_40Rnd_105mm_Mo_backuplowHEAB: RC_1Rnd_105mm_Mo_backuplowHEAB
{
	count=40;
};


// 120mm
class magazine_ShipCannon_120mm_HE_shells_x32;
class RC_1Rnd_120mm_Mo_shells: magazine_ShipCannon_120mm_HE_shells_x32
{
	ammo="RC_Sh_120mm_AMOS_HE";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE";
	displayNameShort="HE";
	count=1;
};
class RC_2Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=2;
};
class RC_3Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=3;
};
class RC_4Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=4;
};
class RC_5Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=5;
};
class RC_6Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=6;
};
class RC_7Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=7;
};
class RC_8Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=8;
};
class RC_9Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=9;
};
class RC_10Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=10;
};
class RC_11Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=11;
};
class RC_12Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=12;
};
class RC_13Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=13;
};
class RC_14Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=14;
};
class RC_15Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=15;
};
class RC_16Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=16;
};
class RC_17Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=17;
};
class RC_18Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=18;
};
class RC_19Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=19;
};
class RC_20Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=20;
};
class RC_21Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=21;
};
class RC_22Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=22;
};
class RC_23Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=23;
};
class RC_24Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=24;
};
class RC_25Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=25;
};
class RC_26Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=26;
};
class RC_27Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=27;
};
class RC_28Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=28;
};
class RC_29Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=29;
};
class RC_30Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=30;
};
class RC_31Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=31;
};
class RC_32Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=32;
};
class RC_33Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=33;
};
class RC_34Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=34;
};
class RC_35Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=35;
};
class RC_36Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=36;
};
class RC_37Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=37;
};
class RC_38Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=38;
};
class RC_39Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=39;
};
class RC_40Rnd_120mm_Mo_shells: RC_1Rnd_120mm_Mo_shells
{
	count=40;
};


class RC_1Rnd_120mm_Mo_HEAB: magazine_ShipCannon_120mm_HE_shells_x32
{
	ammo="RC_Sh_120mm_AMOS_HEAB";
	RC_AimAboveHeight=17.5;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE Airburst";
	displayNameShort="HE Airburst";
	count=1;
};
class RC_2Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=2;
};
class RC_3Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=3;
};
class RC_4Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=4;
};
class RC_5Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=5;
};
class RC_6Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=6;
};
class RC_7Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=7;
};
class RC_8Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=8;
};
class RC_9Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=9;
};
class RC_10Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=10;
};
class RC_11Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=11;
};
class RC_12Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=12;
};
class RC_13Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=13;
};
class RC_14Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=14;
};
class RC_15Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=15;
};
class RC_16Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=16;
};
class RC_17Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=17;
};
class RC_18Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=18;
};
class RC_19Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=19;
};
class RC_20Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=20;
};
class RC_21Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=21;
};
class RC_22Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=22;
};
class RC_23Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=23;
};
class RC_24Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=24;
};
class RC_25Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=25;
};
class RC_26Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=26;
};
class RC_27Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=27;
};
class RC_28Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=28;
};
class RC_29Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=29;
};
class RC_30Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=30;
};
class RC_31Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=31;
};
class RC_32Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=32;
};
class RC_33Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=33;
};
class RC_34Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=34;
};
class RC_35Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=35;
};
class RC_36Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=36;
};
class RC_37Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=37;
};
class RC_38Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=38;
};
class RC_39Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=39;
};
class RC_40Rnd_120mm_Mo_HEAB: RC_1Rnd_120mm_Mo_HEAB
{
	count=40;
};


class RC_1Rnd_120mm_Mo_lowHEAB: magazine_ShipCannon_120mm_HE_shells_x32
{
	ammo="RC_Sh_120mm_AMOS_lowHEAB";
	RC_AimAboveHeight=6;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE low Airburst";
	displayNameShort="HE low Airburst";
	count=1;
};
class RC_2Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=2;
};
class RC_3Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=3;
};
class RC_4Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=4;
};
class RC_5Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=5;
};
class RC_6Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=6;
};
class RC_7Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=7;
};
class RC_8Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=8;
};
class RC_9Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=9;
};
class RC_10Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=10;
};
class RC_11Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=11;
};
class RC_12Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=12;
};
class RC_13Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=13;
};
class RC_14Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=14;
};
class RC_15Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=15;
};
class RC_16Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=16;
};
class RC_17Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=17;
};
class RC_18Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=18;
};
class RC_19Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=19;
};
class RC_20Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=20;
};
class RC_21Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=21;
};
class RC_22Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=22;
};
class RC_23Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=23;
};
class RC_24Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=24;
};
class RC_25Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=25;
};
class RC_26Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=26;
};
class RC_27Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=27;
};
class RC_28Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=28;
};
class RC_29Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=29;
};
class RC_30Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=30;
};
class RC_31Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=31;
};
class RC_32Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=32;
};
class RC_33Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=33;
};
class RC_34Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=34;
};
class RC_35Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=35;
};
class RC_36Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=36;
};
class RC_37Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=37;
};
class RC_38Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=38;
};
class RC_39Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=39;
};
class RC_40Rnd_120mm_Mo_lowHEAB: RC_1Rnd_120mm_Mo_lowHEAB
{
	count=40;
};


class magazine_ShipCannon_120mm_HE_LG_shells_x2;
class RC_1Rnd_120mm_Mo_LaserGuided: magazine_ShipCannon_120mm_HE_LG_shells_x2
{
	ammo="RC_Sh_120mm_AMOS_MP_LaserGuided";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Laser Guided";
	displayNameShort="MP Laser Guided";
	count=1;
};
class RC_2Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=2;
};
class RC_3Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=3;
};
class RC_4Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=4;
};
class RC_5Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=5;
};
class RC_6Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=6;
};
class RC_7Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=7;
};
class RC_8Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=8;
};
class RC_9Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=9;
};
class RC_10Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=10;
};
class RC_11Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=11;
};
class RC_12Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=12;
};
class RC_13Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=13;
};
class RC_14Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=14;
};
class RC_15Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=15;
};
class RC_16Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=16;
};
class RC_17Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=17;
};
class RC_18Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=18;
};
class RC_19Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=19;
};
class RC_20Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=20;
};
class RC_21Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=21;
};
class RC_22Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=22;
};
class RC_23Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=23;
};
class RC_24Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=24;
};
class RC_25Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=25;
};
class RC_26Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=26;
};
class RC_27Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=27;
};
class RC_28Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=28;
};
class RC_29Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=29;
};
class RC_30Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=30;
};
class RC_31Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=31;
};
class RC_32Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=32;
};
class RC_33Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=33;
};
class RC_34Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=34;
};
class RC_35Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=35;
};
class RC_36Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=36;
};
class RC_37Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=37;
};
class RC_38Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=38;
};
class RC_39Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=39;
};
class RC_40Rnd_120mm_Mo_LaserGuided: RC_1Rnd_120mm_Mo_LaserGuided
{
	count=40;
};


class RC_1Rnd_120mm_Mo_MultiGuided: magazine_ShipCannon_120mm_HE_LG_shells_x2
{
	ammo="RC_Sh_120mm_AMOS_MP_MultiGuided";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Guided";
	displayNameShort="MP Guided";
	count=1;
};
class RC_2Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=2;
};
class RC_3Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=3;
};
class RC_4Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=4;
};
class RC_5Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=5;
};
class RC_6Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=6;
};
class RC_7Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=7;
};
class RC_8Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=8;
};
class RC_9Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=9;
};
class RC_10Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=10;
};
class RC_11Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=11;
};
class RC_12Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=12;
};
class RC_13Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=13;
};
class RC_14Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=14;
};
class RC_15Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=15;
};
class RC_16Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=16;
};
class RC_17Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=17;
};
class RC_18Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=18;
};
class RC_19Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=19;
};
class RC_20Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=20;
};
class RC_21Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=21;
};
class RC_22Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=22;
};
class RC_23Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=23;
};
class RC_24Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=24;
};
class RC_25Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=25;
};
class RC_26Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=26;
};
class RC_27Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=27;
};
class RC_28Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=28;
};
class RC_29Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=29;
};
class RC_30Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=30;
};
class RC_31Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=31;
};
class RC_32Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=32;
};
class RC_33Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=33;
};
class RC_34Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=34;
};
class RC_35Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=35;
};
class RC_36Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=36;
};
class RC_37Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=37;
};
class RC_38Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=38;
};
class RC_39Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=39;
};
class RC_40Rnd_120mm_Mo_MultiGuided: RC_1Rnd_120mm_Mo_MultiGuided
{
	count=40;
};


class magazine_ShipCannon_120mm_HE_cluster_shells_x2;
class RC_1Rnd_120mm_Mo_Cluster: magazine_ShipCannon_120mm_HE_cluster_shells_x2
{
	ammo="RC_Cluster_120mm_AMOS";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Cluster [7% UXO]";
	displayNameShort="Cluster";
	count=1;
};
class RC_2Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=2;
};
class RC_3Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=3;
};
class RC_4Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=4;
};
class RC_5Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=5;
};
class RC_6Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=6;
};
class RC_7Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=7;
};
class RC_8Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=8;
};
class RC_9Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=9;
};
class RC_10Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=10;
};
class RC_11Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=11;
};
class RC_12Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=12;
};
class RC_13Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=13;
};
class RC_14Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=14;
};
class RC_15Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=15;
};
class RC_16Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=16;
};
class RC_17Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=17;
};
class RC_18Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=18;
};
class RC_19Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=19;
};
class RC_20Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=20;
};
class RC_21Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=21;
};
class RC_22Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=22;
};
class RC_23Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=23;
};
class RC_24Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=24;
};
class RC_25Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=25;
};
class RC_26Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=26;
};
class RC_27Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=27;
};
class RC_28Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=28;
};
class RC_29Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=29;
};
class RC_30Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=30;
};
class RC_31Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=31;
};
class RC_32Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=32;
};
class RC_33Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=33;
};
class RC_34Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=34;
};
class RC_35Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=35;
};
class RC_36Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=36;
};
class RC_37Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=37;
};
class RC_38Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=38;
};
class RC_39Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=39;
};
class RC_40Rnd_120mm_Mo_Cluster: RC_1Rnd_120mm_Mo_Cluster
{
	count=40;
};


class magazine_ShipCannon_120mm_mine_shells_x6;
class RC_1Rnd_120mm_Mo_mine: magazine_ShipCannon_120mm_mine_shells_x6
{
	ammo="RC_Mine_120mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AP Mines";
	displayNameShort="AP Mines";
	count=1;
};
class RC_2Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=2;
};
class RC_3Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=3;
};
class RC_4Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=4;
};
class RC_5Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=5;
};
class RC_6Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=6;
};
class RC_7Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=7;
};
class RC_8Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=8;
};
class RC_9Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=9;
};
class RC_10Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=10;
};
class RC_11Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=11;
};
class RC_12Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=12;
};
class RC_13Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=13;
};
class RC_14Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=14;
};
class RC_15Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=15;
};
class RC_16Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=16;
};
class RC_17Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=17;
};
class RC_18Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=18;
};
class RC_19Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=19;
};
class RC_20Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=20;
};
class RC_21Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=21;
};
class RC_22Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=22;
};
class RC_23Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=23;
};
class RC_24Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=24;
};
class RC_25Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=25;
};
class RC_26Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=26;
};
class RC_27Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=27;
};
class RC_28Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=28;
};
class RC_29Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=29;
};
class RC_30Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=30;
};
class RC_31Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=31;
};
class RC_32Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=32;
};
class RC_33Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=33;
};
class RC_34Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=34;
};
class RC_35Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=35;
};
class RC_36Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=36;
};
class RC_37Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=37;
};
class RC_38Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=38;
};
class RC_39Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=39;
};
class RC_40Rnd_120mm_Mo_mine: RC_1Rnd_120mm_Mo_mine
{
	count=40;
};


class magazine_ShipCannon_120mm_smoke_shells_x6;
class RC_1Rnd_120mm_Mo_smoke: magazine_ShipCannon_120mm_smoke_shells_x6
{
	ammo="RC_Smoke_155mm_AMOS_White";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Smoke";
	displayNameShort="Smoke";
	count=1;
};
class RC_2Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=2;
};
class RC_3Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=3;
};
class RC_4Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=4;
};
class RC_5Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=5;
};
class RC_6Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=6;
};
class RC_7Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=7;
};
class RC_8Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=8;
};
class RC_9Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=9;
};
class RC_10Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=10;
};
class RC_11Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=11;
};
class RC_12Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=12;
};
class RC_13Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=13;
};
class RC_14Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=14;
};
class RC_15Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=15;
};
class RC_16Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=16;
};
class RC_17Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=17;
};
class RC_18Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=18;
};
class RC_19Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=19;
};
class RC_20Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=20;
};
class RC_21Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=21;
};
class RC_22Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=22;
};
class RC_23Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=23;
};
class RC_24Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=24;
};
class RC_25Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=25;
};
class RC_26Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=26;
};
class RC_27Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=27;
};
class RC_28Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=28;
};
class RC_29Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=29;
};
class RC_30Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=30;
};
class RC_31Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=31;
};
class RC_32Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=32;
};
class RC_33Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=33;
};
class RC_34Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=34;
};
class RC_35Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=35;
};
class RC_36Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=36;
};
class RC_37Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=37;
};
class RC_38Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=38;
};
class RC_39Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=39;
};
class RC_40Rnd_120mm_Mo_smoke: RC_1Rnd_120mm_Mo_smoke
{
	count=40;
};


class magazine_ShipCannon_120mm_AT_mine_shells_x6;
class RC_1Rnd_120mm_Mo_AT_mine: magazine_ShipCannon_120mm_AT_mine_shells_x6
{
	ammo="RC_AT_Mine_120mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AT Mines";
	displayNameShort="AT Mines";
	count=1;
};
class RC_2Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=2;
};
class RC_3Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=3;
};
class RC_4Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=4;
};
class RC_5Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=5;
};
class RC_6Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=6;
};
class RC_7Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=7;
};
class RC_8Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=8;
};
class RC_9Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=9;
};
class RC_10Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=10;
};
class RC_11Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=11;
};
class RC_12Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=12;
};
class RC_13Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=13;
};
class RC_14Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=14;
};
class RC_15Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=15;
};
class RC_16Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=16;
};
class RC_17Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=17;
};
class RC_18Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=18;
};
class RC_19Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=19;
};
class RC_20Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=20;
};
class RC_21Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=21;
};
class RC_22Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=22;
};
class RC_23Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=23;
};
class RC_24Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=24;
};
class RC_25Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=25;
};
class RC_26Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=26;
};
class RC_27Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=27;
};
class RC_28Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=28;
};
class RC_29Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=29;
};
class RC_30Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=30;
};
class RC_31Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=31;
};
class RC_32Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=32;
};
class RC_33Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=33;
};
class RC_34Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=34;
};
class RC_35Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=35;
};
class RC_36Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=36;
};
class RC_37Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=37;
};
class RC_38Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=38;
};
class RC_39Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=39;
};
class RC_40Rnd_120mm_Mo_AT_mine: RC_1Rnd_120mm_Mo_AT_mine
{
	count=40;
};


class RC_1Rnd_120mm_Mo_Illum: magazine_ShipCannon_120mm_HE_shells_x32
{
	ammo="Flare_155mm_AMOS_White";
	RC_AimAboveHeight=500;
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="Illumination";
	displayNameShort="Illum";
	count=1;
};
class RC_2Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=2;
};
class RC_3Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=3;
};
class RC_4Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=4;
};
class RC_5Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=5;
};
class RC_6Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=6;
};
class RC_7Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=7;
};
class RC_8Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=8;
};
class RC_9Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=9;
};
class RC_10Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=10;
};
class RC_11Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=11;
};
class RC_12Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=12;
};
class RC_13Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=13;
};
class RC_14Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=14;
};
class RC_15Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=15;
};
class RC_16Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=16;
};
class RC_17Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=17;
};
class RC_18Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=18;
};
class RC_19Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=19;
};
class RC_20Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=20;
};
class RC_21Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=21;
};
class RC_22Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=22;
};
class RC_23Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=23;
};
class RC_24Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=24;
};
class RC_25Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=25;
};
class RC_26Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=26;
};
class RC_27Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=27;
};
class RC_28Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=28;
};
class RC_29Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=29;
};
class RC_30Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=30;
};
class RC_31Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=31;
};
class RC_32Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=32;
};
class RC_33Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=33;
};
class RC_34Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=34;
};
class RC_35Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=35;
};
class RC_36Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=36;
};
class RC_37Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=37;
};
class RC_38Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=38;
};
class RC_39Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=39;
};
class RC_40Rnd_120mm_Mo_Illum: RC_1Rnd_120mm_Mo_Illum
{
	count=40;
};


class RC_1Rnd_120mm_Mo_LG_DelayedFuse: magazine_ShipCannon_120mm_HE_LG_shells_x2
{
	ammo="RC_Sh_120mm_AMOS_LG_DelayedFuse";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="LG 2m Delayed";
	displayNameShort="LG 2m Delayed";
	count=1;
};
class RC_2Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=2;
};
class RC_3Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=3;
};
class RC_4Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=4;
};
class RC_5Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=5;
};
class RC_6Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=6;
};
class RC_7Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=7;
};
class RC_8Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=8;
};
class RC_9Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=9;
};
class RC_10Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=10;
};
class RC_11Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=11;
};
class RC_12Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=12;
};
class RC_13Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=13;
};
class RC_14Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=14;
};
class RC_15Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=15;
};
class RC_16Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=16;
};
class RC_17Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=17;
};
class RC_18Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=18;
};
class RC_19Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=19;
};
class RC_20Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=20;
};
class RC_21Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=21;
};
class RC_22Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=22;
};
class RC_23Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=23;
};
class RC_24Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=24;
};
class RC_25Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=25;
};
class RC_26Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=26;
};
class RC_27Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=27;
};
class RC_28Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=28;
};
class RC_29Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=29;
};
class RC_30Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=30;
};
class RC_31Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=31;
};
class RC_32Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=32;
};
class RC_33Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=33;
};
class RC_34Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=34;
};
class RC_35Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=35;
};
class RC_36Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=36;
};
class RC_37Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=37;
};
class RC_38Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=38;
};
class RC_39Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=39;
};
class RC_40Rnd_120mm_Mo_LG_DelayedFuse: RC_1Rnd_120mm_Mo_LG_DelayedFuse
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_120mm_Mo_backupHEAB: magazine_ShipCannon_120mm_HE_shells_x32
{
	ammo="RC_Sh_120mm_AMOS_backupHEAB";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE AB [direct]";
	displayNameShort="HE AB [direct]";
	count=1;
};
class RC_2Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=2;
};
class RC_3Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=3;
};
class RC_4Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=4;
};
class RC_5Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=5;
};
class RC_6Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=6;
};
class RC_7Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=7;
};
class RC_8Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=8;
};
class RC_9Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=9;
};
class RC_10Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=10;
};
class RC_11Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=11;
};
class RC_12Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=12;
};
class RC_13Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=13;
};
class RC_14Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=14;
};
class RC_15Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=15;
};
class RC_16Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=16;
};
class RC_17Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=17;
};
class RC_18Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=18;
};
class RC_19Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=19;
};
class RC_20Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=20;
};
class RC_21Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=21;
};
class RC_22Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=22;
};
class RC_23Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=23;
};
class RC_24Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=24;
};
class RC_25Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=25;
};
class RC_26Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=26;
};
class RC_27Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=27;
};
class RC_28Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=28;
};
class RC_29Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=29;
};
class RC_30Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=30;
};
class RC_31Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=31;
};
class RC_32Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=32;
};
class RC_33Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=33;
};
class RC_34Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=34;
};
class RC_35Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=35;
};
class RC_36Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=36;
};
class RC_37Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=37;
};
class RC_38Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=38;
};
class RC_39Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=39;
};
class RC_40Rnd_120mm_Mo_backupHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backupHEAB
{
	displayName="HE lAB [direct]";
	displayNameShort="HE lAB [direct]";
};
class RC_2Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=2;
};
class RC_3Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=3;
};
class RC_4Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=4;
};
class RC_5Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=5;
};
class RC_6Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=6;
};
class RC_7Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=7;
};
class RC_8Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=8;
};
class RC_9Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=9;
};
class RC_10Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=10;
};
class RC_11Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=11;
};
class RC_12Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=12;
};
class RC_13Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=13;
};
class RC_14Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=14;
};
class RC_15Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=15;
};
class RC_16Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=16;
};
class RC_17Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=17;
};
class RC_18Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=18;
};
class RC_19Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=19;
};
class RC_20Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=20;
};
class RC_21Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=21;
};
class RC_22Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=22;
};
class RC_23Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=23;
};
class RC_24Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=24;
};
class RC_25Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=25;
};
class RC_26Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=26;
};
class RC_27Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=27;
};
class RC_28Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=28;
};
class RC_29Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=29;
};
class RC_30Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=30;
};
class RC_31Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=31;
};
class RC_32Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=32;
};
class RC_33Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=33;
};
class RC_34Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=34;
};
class RC_35Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=35;
};
class RC_36Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=36;
};
class RC_37Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=37;
};
class RC_38Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=38;
};
class RC_39Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=39;
};
class RC_40Rnd_120mm_Mo_backuplowHEAB: RC_1Rnd_120mm_Mo_backuplowHEAB
{
	count=40;
};


// 155mm
class RC_1Rnd_155mm_Mo_shells: 32Rnd_155mm_Mo_shells
{
	ammo="RC_Sh_155mm_AMOS_HE";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE";
	displayNameShort="HE";
	count=1;
};
class RC_2Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=2;
};
class RC_3Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=3;
};
class RC_4Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=4;
};
class RC_5Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=5;
};
class RC_6Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=6;
};
class RC_7Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=7;
};
class RC_8Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=8;
};
class RC_9Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=9;
};
class RC_10Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=10;
};
class RC_11Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=11;
};
class RC_12Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=12;
};
class RC_13Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=13;
};
class RC_14Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=14;
};
class RC_15Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=15;
};
class RC_16Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=16;
};
class RC_17Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=17;
};
class RC_18Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=18;
};
class RC_19Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=19;
};
class RC_20Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=20;
};
class RC_21Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=21;
};
class RC_22Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=22;
};
class RC_23Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=23;
};
class RC_24Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=24;
};
class RC_25Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=25;
};
class RC_26Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=26;
};
class RC_27Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=27;
};
class RC_28Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=28;
};
class RC_29Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=29;
};
class RC_30Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=30;
};
class RC_31Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=31;
};
class RC_32Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=32;
};
class RC_33Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=33;
};
class RC_34Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=34;
};
class RC_35Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=35;
};
class RC_36Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=36;
};
class RC_37Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=37;
};
class RC_38Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=38;
};
class RC_39Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=39;
};
class RC_40Rnd_155mm_Mo_shells: RC_1Rnd_155mm_Mo_shells
{
	count=40;
};


class RC_1Rnd_155mm_Mo_HEAB: 32Rnd_155mm_Mo_shells
{
	ammo="RC_Sh_155mm_AMOS_HEAB";
	RC_AimAboveHeight=21.2;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE Airburst";
	displayNameShort="HE Airburst";
	count=1;
};
class RC_2Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=2;
};
class RC_3Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=3;
};
class RC_4Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=4;
};
class RC_5Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=5;
};
class RC_6Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=6;
};
class RC_7Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=7;
};
class RC_8Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=8;
};
class RC_9Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=9;
};
class RC_10Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=10;
};
class RC_11Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=11;
};
class RC_12Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=12;
};
class RC_13Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=13;
};
class RC_14Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=14;
};
class RC_15Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=15;
};
class RC_16Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=16;
};
class RC_17Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=17;
};
class RC_18Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=18;
};
class RC_19Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=19;
};
class RC_20Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=20;
};
class RC_21Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=21;
};
class RC_22Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=22;
};
class RC_23Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=23;
};
class RC_24Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=24;
};
class RC_25Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=25;
};
class RC_26Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=26;
};
class RC_27Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=27;
};
class RC_28Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=28;
};
class RC_29Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=29;
};
class RC_30Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=30;
};
class RC_31Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=31;
};
class RC_32Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=32;
};
class RC_33Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=33;
};
class RC_34Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=34;
};
class RC_35Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=35;
};
class RC_36Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=36;
};
class RC_37Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=37;
};
class RC_38Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=38;
};
class RC_39Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=39;
};
class RC_40Rnd_155mm_Mo_HEAB: RC_1Rnd_155mm_Mo_HEAB
{
	count=40;
};


class RC_1Rnd_155mm_Mo_lowHEAB: 32Rnd_155mm_Mo_shells
{
	ammo="RC_Sh_155mm_AMOS_lowHEAB";
	RC_AimAboveHeight=6;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE low Airburst";
	displayNameShort="HE low Airburst";
	count=1;
};
class RC_2Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=2;
};
class RC_3Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=3;
};
class RC_4Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=4;
};
class RC_5Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=5;
};
class RC_6Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=6;
};
class RC_7Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=7;
};
class RC_8Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=8;
};
class RC_9Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=9;
};
class RC_10Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=10;
};
class RC_11Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=11;
};
class RC_12Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=12;
};
class RC_13Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=13;
};
class RC_14Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=14;
};
class RC_15Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=15;
};
class RC_16Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=16;
};
class RC_17Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=17;
};
class RC_18Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=18;
};
class RC_19Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=19;
};
class RC_20Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=20;
};
class RC_21Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=21;
};
class RC_22Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=22;
};
class RC_23Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=23;
};
class RC_24Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=24;
};
class RC_25Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=25;
};
class RC_26Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=26;
};
class RC_27Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=27;
};
class RC_28Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=28;
};
class RC_29Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=29;
};
class RC_30Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=30;
};
class RC_31Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=31;
};
class RC_32Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=32;
};
class RC_33Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=33;
};
class RC_34Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=34;
};
class RC_35Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=35;
};
class RC_36Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=36;
};
class RC_37Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=37;
};
class RC_38Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=38;
};
class RC_39Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=39;
};
class RC_40Rnd_155mm_Mo_lowHEAB: RC_1Rnd_155mm_Mo_lowHEAB
{
	count=40;
};


class RC_1Rnd_155mm_Mo_mine: 6Rnd_155mm_Mo_mine
{
	ammo="RC_Mine_155mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AP Mines";
	displayNameShort="AP Mines";
	count=1;
};
class RC_2Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=2;
};
class RC_3Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=3;
};
class RC_4Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=4;
};
class RC_5Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=5;
};
class RC_6Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=6;
};
class RC_7Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=7;
};
class RC_8Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=8;
};
class RC_9Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=9;
};
class RC_10Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=10;
};
class RC_11Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=11;
};
class RC_12Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=12;
};
class RC_13Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=13;
};
class RC_14Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=14;
};
class RC_15Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=15;
};
class RC_16Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=16;
};
class RC_17Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=17;
};
class RC_18Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=18;
};
class RC_19Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=19;
};
class RC_20Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=20;
};
class RC_21Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=21;
};
class RC_22Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=22;
};
class RC_23Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=23;
};
class RC_24Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=24;
};
class RC_25Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=25;
};
class RC_26Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=26;
};
class RC_27Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=27;
};
class RC_28Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=28;
};
class RC_29Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=29;
};
class RC_30Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=30;
};
class RC_31Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=31;
};
class RC_32Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=32;
};
class RC_33Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=33;
};
class RC_34Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=34;
};
class RC_35Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=35;
};
class RC_36Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=36;
};
class RC_37Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=37;
};
class RC_38Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=38;
};
class RC_39Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=39;
};
class RC_40Rnd_155mm_Mo_mine: RC_1Rnd_155mm_Mo_mine
{
	count=40;
};


class RC_1Rnd_155mm_Mo_Cluster: 2Rnd_155mm_Mo_Cluster
{
	ammo="RC_Cluster_155mm_AMOS";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Cluster [7% UXO]";
	displayNameShort="Cluster";
	count=1;
};
class RC_2Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=2;
};
class RC_3Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=3;
};
class RC_4Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=4;
};
class RC_5Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=5;
};
class RC_6Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=6;
};
class RC_7Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=7;
};
class RC_8Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=8;
};
class RC_9Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=9;
};
class RC_10Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=10;
};
class RC_11Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=11;
};
class RC_12Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=12;
};
class RC_13Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=13;
};
class RC_14Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=14;
};
class RC_15Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=15;
};
class RC_16Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=16;
};
class RC_17Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=17;
};
class RC_18Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=18;
};
class RC_19Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=19;
};
class RC_20Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=20;
};
class RC_21Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=21;
};
class RC_22Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=22;
};
class RC_23Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=23;
};
class RC_24Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=24;
};
class RC_25Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=25;
};
class RC_26Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=26;
};
class RC_27Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=27;
};
class RC_28Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=28;
};
class RC_29Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=29;
};
class RC_30Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=30;
};
class RC_31Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=31;
};
class RC_32Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=32;
};
class RC_33Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=33;
};
class RC_34Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=34;
};
class RC_35Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=35;
};
class RC_36Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=36;
};
class RC_37Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=37;
};
class RC_38Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=38;
};
class RC_39Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=39;
};
class RC_40Rnd_155mm_Mo_Cluster: RC_1Rnd_155mm_Mo_Cluster
{
	count=40;
};


class RC_1Rnd_155mm_Mo_smoke: 6Rnd_155mm_Mo_smoke
{
	ammo="RC_Smoke_155mm_AMOS_White";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Smoke";
	displayNameShort="Smoke";
	count=1;
};
class RC_2Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=2;
};
class RC_3Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=3;
};
class RC_4Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=4;
};
class RC_5Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=5;
};
class RC_6Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=6;
};
class RC_7Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=7;
};
class RC_8Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=8;
};
class RC_9Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=9;
};
class RC_10Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=10;
};
class RC_11Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=11;
};
class RC_12Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=12;
};
class RC_13Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=13;
};
class RC_14Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=14;
};
class RC_15Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=15;
};
class RC_16Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=16;
};
class RC_17Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=17;
};
class RC_18Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=18;
};
class RC_19Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=19;
};
class RC_20Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=20;
};
class RC_21Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=21;
};
class RC_22Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=22;
};
class RC_23Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=23;
};
class RC_24Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=24;
};
class RC_25Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=25;
};
class RC_26Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=26;
};
class RC_27Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=27;
};
class RC_28Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=28;
};
class RC_29Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=29;
};
class RC_30Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=30;
};
class RC_31Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=31;
};
class RC_32Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=32;
};
class RC_33Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=33;
};
class RC_34Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=34;
};
class RC_35Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=35;
};
class RC_36Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=36;
};
class RC_37Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=37;
};
class RC_38Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=38;
};
class RC_39Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=39;
};
class RC_40Rnd_155mm_Mo_smoke: RC_1Rnd_155mm_Mo_smoke
{
	count=40;
};


class RC_1Rnd_155mm_Mo_LaserGuided: 2Rnd_155mm_Mo_LG
{
	ammo="RC_Sh_155mm_AMOS_MP_LaserGuided";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Laser Guided";
	displayNameShort="MP Laser Guided";
	count=1;
};
class RC_2Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=2;
};
class RC_3Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=3;
};
class RC_4Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=4;
};
class RC_5Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=5;
};
class RC_6Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=6;
};
class RC_7Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=7;
};
class RC_8Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=8;
};
class RC_9Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=9;
};
class RC_10Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=10;
};
class RC_11Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=11;
};
class RC_12Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=12;
};
class RC_13Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=13;
};
class RC_14Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=14;
};
class RC_15Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=15;
};
class RC_16Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=16;
};
class RC_17Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=17;
};
class RC_18Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=18;
};
class RC_19Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=19;
};
class RC_20Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=20;
};
class RC_21Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=21;
};
class RC_22Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=22;
};
class RC_23Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=23;
};
class RC_24Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=24;
};
class RC_25Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=25;
};
class RC_26Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=26;
};
class RC_27Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=27;
};
class RC_28Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=28;
};
class RC_29Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=29;
};
class RC_30Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=30;
};
class RC_31Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=31;
};
class RC_32Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=32;
};
class RC_33Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=33;
};
class RC_34Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=34;
};
class RC_35Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=35;
};
class RC_36Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=36;
};
class RC_37Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=37;
};
class RC_38Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=38;
};
class RC_39Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=39;
};
class RC_40Rnd_155mm_Mo_LaserGuided: RC_1Rnd_155mm_Mo_LaserGuided
{
	count=40;
};


class RC_1Rnd_155mm_Mo_MultiGuided: 2Rnd_155mm_Mo_LG
{
	ammo="RC_Sh_155mm_AMOS_MP_MultiGuided";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Guided";
	displayNameShort="MP Guided";
	count=1;
};
class RC_2Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=2;
};
class RC_3Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=3;
};
class RC_4Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=4;
};
class RC_5Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=5;
};
class RC_6Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=6;
};
class RC_7Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=7;
};
class RC_8Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=8;
};
class RC_9Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=9;
};
class RC_10Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=10;
};
class RC_11Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=11;
};
class RC_12Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=12;
};
class RC_13Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=13;
};
class RC_14Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=14;
};
class RC_15Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=15;
};
class RC_16Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=16;
};
class RC_17Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=17;
};
class RC_18Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=18;
};
class RC_19Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=19;
};
class RC_20Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=20;
};
class RC_21Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=21;
};
class RC_22Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=22;
};
class RC_23Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=23;
};
class RC_24Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=24;
};
class RC_25Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=25;
};
class RC_26Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=26;
};
class RC_27Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=27;
};
class RC_28Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=28;
};
class RC_29Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=29;
};
class RC_30Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=30;
};
class RC_31Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=31;
};
class RC_32Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=32;
};
class RC_33Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=33;
};
class RC_34Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=34;
};
class RC_35Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=35;
};
class RC_36Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=36;
};
class RC_37Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=37;
};
class RC_38Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=38;
};
class RC_39Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=39;
};
class RC_40Rnd_155mm_Mo_MultiGuided: RC_1Rnd_155mm_Mo_MultiGuided
{
	count=40;
};


class RC_1Rnd_155mm_Mo_AT_mine: 6Rnd_155mm_Mo_AT_mine
{
	ammo="RC_AT_Mine_155mm_AMOS_range";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="AT Mines";
	displayNameShort="AT Mines";
	count=1;
};
class RC_2Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=2;
};
class RC_3Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=3;
};
class RC_4Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=4;
};
class RC_5Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=5;
};
class RC_6Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=6;
};
class RC_7Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=7;
};
class RC_8Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=8;
};
class RC_9Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=9;
};
class RC_10Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=10;
};
class RC_11Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=11;
};
class RC_12Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=12;
};
class RC_13Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=13;
};
class RC_14Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=14;
};
class RC_15Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=15;
};
class RC_16Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=16;
};
class RC_17Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=17;
};
class RC_18Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=18;
};
class RC_19Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=19;
};
class RC_20Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=20;
};
class RC_21Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=21;
};
class RC_22Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=22;
};
class RC_23Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=23;
};
class RC_24Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=24;
};
class RC_25Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=25;
};
class RC_26Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=26;
};
class RC_27Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=27;
};
class RC_28Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=28;
};
class RC_29Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=29;
};
class RC_30Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=30;
};
class RC_31Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=31;
};
class RC_32Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=32;
};
class RC_33Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=33;
};
class RC_34Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=34;
};
class RC_35Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=35;
};
class RC_36Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=36;
};
class RC_37Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=37;
};
class RC_38Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=38;
};
class RC_39Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=39;
};
class RC_40Rnd_155mm_Mo_AT_mine: RC_1Rnd_155mm_Mo_AT_mine
{
	count=40;
};


class RC_1Rnd_155mm_Mo_Illum: 32Rnd_155mm_Mo_shells
{
	RC_AdvisedTrajectory=3;	//1low, 2high, 3both
	displayName="Illumination";
	displayNameShort="Illum";
	ammo="Flare_155mm_AMOS_White";
	count=1;
};
class RC_2Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=2;
};
class RC_3Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=3;
};
class RC_4Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=4;
};
class RC_5Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=5;
};
class RC_6Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=6;
};
class RC_7Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=7;
};
class RC_8Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=8;
};
class RC_9Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=9;
};
class RC_10Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=10;
};
class RC_11Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=11;
};
class RC_12Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=12;
};
class RC_13Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=13;
};
class RC_14Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=14;
};
class RC_15Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=15;
};
class RC_16Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=16;
};
class RC_17Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=17;
};
class RC_18Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=18;
};
class RC_19Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=19;
};
class RC_20Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=20;
};
class RC_21Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=21;
};
class RC_22Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=22;
};
class RC_23Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=23;
};
class RC_24Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=24;
};
class RC_25Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=25;
};
class RC_26Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=26;
};
class RC_27Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=27;
};
class RC_28Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=28;
};
class RC_29Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=29;
};
class RC_30Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=30;
};
class RC_31Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=31;
};
class RC_32Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=32;
};
class RC_33Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=33;
};
class RC_34Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=34;
};
class RC_35Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=35;
};
class RC_36Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=36;
};
class RC_37Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=37;
};
class RC_38Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=38;
};
class RC_39Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=39;
};
class RC_40Rnd_155mm_Mo_Illum: RC_1Rnd_155mm_Mo_Illum
{
	count=40;
};


class RC_1Rnd_155mm_Mo_LG_DelayedFuse: 2Rnd_155mm_Mo_LG
{
	ammo="RC_Sh_155mm_AMOS_LG_DelayedFuse";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="LG 2m Delayed";
	displayNameShort="LG 2m Delayed";
	count=1;
};
class RC_2Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=2;
};
class RC_3Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=3;
};
class RC_4Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=4;
};
class RC_5Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=5;
};
class RC_6Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=6;
};
class RC_7Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=7;
};
class RC_8Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=8;
};
class RC_9Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=9;
};
class RC_10Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=10;
};
class RC_11Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=11;
};
class RC_12Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=12;
};
class RC_13Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=13;
};
class RC_14Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=14;
};
class RC_15Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=15;
};
class RC_16Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=16;
};
class RC_17Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=17;
};
class RC_18Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=18;
};
class RC_19Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=19;
};
class RC_20Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=20;
};
class RC_21Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=21;
};
class RC_22Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=22;
};
class RC_23Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=23;
};
class RC_24Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=24;
};
class RC_25Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=25;
};
class RC_26Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=26;
};
class RC_27Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=27;
};
class RC_28Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=28;
};
class RC_29Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=29;
};
class RC_30Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=30;
};
class RC_31Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=31;
};
class RC_32Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=32;
};
class RC_33Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=33;
};
class RC_34Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=34;
};
class RC_35Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=35;
};
class RC_36Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=36;
};
class RC_37Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=37;
};
class RC_38Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=38;
};
class RC_39Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=39;
};
class RC_40Rnd_155mm_Mo_LG_DelayedFuse: RC_1Rnd_155mm_Mo_LG_DelayedFuse
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_155mm_Mo_backupHEAB: 32Rnd_155mm_Mo_shells
{
	ammo="RC_Sh_155mm_AMOS_backupHEAB";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE AB [direct]";
	displayNameShort="HE AB [direct]";
	count=1;
};
class RC_2Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=2;
};
class RC_3Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=3;
};
class RC_4Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=4;
};
class RC_5Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=5;
};
class RC_6Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=6;
};
class RC_7Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=7;
};
class RC_8Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=8;
};
class RC_9Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=9;
};
class RC_10Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=10;
};
class RC_11Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=11;
};
class RC_12Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=12;
};
class RC_13Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=13;
};
class RC_14Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=14;
};
class RC_15Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=15;
};
class RC_16Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=16;
};
class RC_17Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=17;
};
class RC_18Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=18;
};
class RC_19Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=19;
};
class RC_20Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=20;
};
class RC_21Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=21;
};
class RC_22Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=22;
};
class RC_23Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=23;
};
class RC_24Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=24;
};
class RC_25Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=25;
};
class RC_26Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=26;
};
class RC_27Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=27;
};
class RC_28Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=28;
};
class RC_29Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=29;
};
class RC_30Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=30;
};
class RC_31Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=31;
};
class RC_32Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=32;
};
class RC_33Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=33;
};
class RC_34Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=34;
};
class RC_35Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=35;
};
class RC_36Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=36;
};
class RC_37Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=37;
};
class RC_38Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=38;
};
class RC_39Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=39;
};
class RC_40Rnd_155mm_Mo_backupHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	count=40;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backupHEAB
{
	displayName="HE lAB [direct]";
	displayNameShort="HE lAB [direct]";
};
class RC_2Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=2;
};
class RC_3Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=3;
};
class RC_4Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=4;
};
class RC_5Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=5;
};
class RC_6Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=6;
};
class RC_7Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=7;
};
class RC_8Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=8;
};
class RC_9Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=9;
};
class RC_10Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=10;
};
class RC_11Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=11;
};
class RC_12Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=12;
};
class RC_13Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=13;
};
class RC_14Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=14;
};
class RC_15Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=15;
};
class RC_16Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=16;
};
class RC_17Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=17;
};
class RC_18Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=18;
};
class RC_19Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=19;
};
class RC_20Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=20;
};
class RC_21Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=21;
};
class RC_22Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=22;
};
class RC_23Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=23;
};
class RC_24Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=24;
};
class RC_25Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=25;
};
class RC_26Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=26;
};
class RC_27Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=27;
};
class RC_28Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=28;
};
class RC_29Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=29;
};
class RC_30Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=30;
};
class RC_31Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=31;
};
class RC_32Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=32;
};
class RC_33Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=33;
};
class RC_34Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=34;
};
class RC_35Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=35;
};
class RC_36Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=36;
};
class RC_37Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=37;
};
class RC_38Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=38;
};
class RC_39Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=39;
};
class RC_40Rnd_155mm_Mo_backuplowHEAB: RC_1Rnd_155mm_Mo_backuplowHEAB
{
	count=40;
};


//230mm
class 12Rnd_230mm_rockets;
class RC_1Rnd_230mm_rockets: 12Rnd_230mm_rockets
{
	ammo="RC_R_230mm_HE";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE";
	displayNameShort="HE";
	count=1;
};
class RC_2Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=2;
};
class RC_3Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=3;
};
class RC_4Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=4;
};
class RC_5Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=5;
};
class RC_6Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=6;
};
class RC_7Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=7;
};
class RC_8Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=8;
};
class RC_9Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=9;
};
class RC_10Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=10;
};
class RC_11Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=11;
};
class RC_12Rnd_230mm_rockets: RC_1Rnd_230mm_rockets
{
	count=12;
};


class RC_1Rnd_230mm_rockets_HEAB: 12Rnd_230mm_rockets
{
	ammo="RC_R_230mm_HEAB";
	RC_AimAboveHeight=21.2;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE Airburst";
	displayNameShort="HE Airburst";
	count=1;
};
class RC_2Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=2;
};
class RC_3Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=3;
};
class RC_4Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=4;
};
class RC_5Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=5;
};
class RC_6Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=6;
};
class RC_7Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=7;
};
class RC_8Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=8;
};
class RC_9Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=9;
};
class RC_10Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=10;
};
class RC_11Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=11;
};
class RC_12Rnd_230mm_rockets_HEAB: RC_1Rnd_230mm_rockets_HEAB
{
	count=12;
};


class RC_1Rnd_230mm_rockets_lowHEAB: 12Rnd_230mm_rockets
{
	ammo="RC_R_230mm_lowHEAB";
	RC_AimAboveHeight=6;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE low Airburst";
	displayNameShort="HE low Airburst";
	count=1;
};
class RC_2Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=2;
};
class RC_3Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=3;
};
class RC_4Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=4;
};
class RC_5Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=5;
};
class RC_6Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=6;
};
class RC_7Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=7;
};
class RC_8Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=8;
};
class RC_9Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=9;
};
class RC_10Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=10;
};
class RC_11Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=11;
};
class RC_12Rnd_230mm_rockets_lowHEAB: RC_1Rnd_230mm_rockets_lowHEAB
{
	count=12;
};


class 12Rnd_230mm_rockets_cluster;
class RC_1Rnd_230mm_rockets_cluster: 12Rnd_230mm_rockets_cluster
{
	ammo="RC_R_230mm_Cluster";
	RC_TerrainWarning=1;
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="Cluster [7% UXO]";
	displayNameShort="Cluster";
	count=1;
};
class RC_2Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=2;
};
class RC_3Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=3;
};
class RC_4Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=4;
};
class RC_5Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=5;
};
class RC_6Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=6;
};
class RC_7Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=7;
};
class RC_8Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=8;
};
class RC_9Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=9;
};
class RC_10Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=10;
};
class RC_11Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=11;
};
class RC_12Rnd_230mm_rockets_cluster: RC_1Rnd_230mm_rockets_cluster
{
	count=12;
};


class RC_1Rnd_230mm_rockets_LaserGuided: 12Rnd_230mm_rockets
{
	ammo="RC_R_230mm_MP_LaserGuided";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Laser Guided";
	displayNameShort="MP Laser Guided";
	count=1;
};
class RC_2Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=2;
};
class RC_3Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=3;
};
class RC_4Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=4;
};
class RC_5Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=5;
};
class RC_6Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=6;
};
class RC_7Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=7;
};
class RC_8Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=8;
};
class RC_9Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=9;
};
class RC_10Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=10;
};
class RC_11Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=11;
};
class RC_12Rnd_230mm_rockets_LaserGuided: RC_1Rnd_230mm_rockets_LaserGuided
{
	count=12;
};


class RC_1Rnd_230mm_rockets_MultiGuided: 12Rnd_230mm_rockets
{
	ammo="RC_R_230mm_MP_MultiGuided";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="MP Guided";
	displayNameShort="MP Guided";
	count=1;
};
class RC_2Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=2;
};
class RC_3Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=3;
};
class RC_4Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=4;
};
class RC_5Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=5;
};
class RC_6Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=6;
};
class RC_7Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=7;
};
class RC_8Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=8;
};
class RC_9Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=9;
};
class RC_10Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=10;
};
class RC_11Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=11;
};
class RC_12Rnd_230mm_rockets_MultiGuided: RC_1Rnd_230mm_rockets_MultiGuided
{
	count=12;
};


class RC_1Rnd_230mm_rockets_LG_DelayedFuse: 12Rnd_230mm_rockets
{
	ammo="RC_230mm_LG_DelayedFuse";
	RC_AimAboveHeight=450;
	RC_RequiresLock=1;
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="LG 2m Delayed";
	displayNameShort="LG 2m Delayed";
	count=1;
};
class RC_2Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=2;
};
class RC_3Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=3;
};
class RC_4Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=4;
};
class RC_5Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=5;
};
class RC_6Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=6;
};
class RC_7Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=7;
};
class RC_8Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=8;
};
class RC_9Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=9;
};
class RC_10Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=10;
};
class RC_11Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=11;
};
class RC_12Rnd_230mm_rockets_LG_DelayedFuse: RC_1Rnd_230mm_rockets_LG_DelayedFuse
{
	count=12;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_230mm_rockets_backupHEAB: 12Rnd_230mm_rockets
{
	ammo="RC_R_230mm_backupHEAB";
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="HE AB [direct]";
	displayNameShort="HE AB [direct]";
	count=1;
};
class RC_2Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=2;
};
class RC_3Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=3;
};
class RC_4Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=4;
};
class RC_5Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=5;
};
class RC_6Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=6;
};
class RC_7Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=7;
};
class RC_8Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=8;
};
class RC_9Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=9;
};
class RC_10Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=10;
};
class RC_11Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=11;
};
class RC_12Rnd_230mm_rockets_backupHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	count=12;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backupHEAB
{
	displayName="HE lAB [direct]";
	displayNameShort="HE lAB [direct]";
};
class RC_2Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=2;
};
class RC_3Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=3;
};
class RC_4Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=4;
};
class RC_5Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=5;
};
class RC_6Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=6;
};
class RC_7Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=7;
};
class RC_8Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=8;
};
class RC_9Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=9;
};
class RC_10Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=10;
};
class RC_11Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=11;
};
class RC_12Rnd_230mm_rockets_backuplowHEAB: RC_1Rnd_230mm_rockets_backuplowHEAB
{
	count=12;
};


// 604mm MLRS/MRL Rockets
class RC_1Rnd_604mm_rockets_ATACMS_HEAB: 12Rnd_230mm_rockets
{
	displayName="ATACMS HE Airburst";
	RC_AimAboveHeight=30;		//airburstheight
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayNameShort="ATACMS HE AB";
	ammo="RC_R_604mm_ATACMS_HEAB";
	count=1;
};
class RC_2Rnd_604mm_rockets_ATACMS_HEAB: RC_1Rnd_604mm_rockets_ATACMS_HEAB
{
	count=2;
};


//backup ammo used in script for when the barrel is pointed too low for airburst
class RC_1Rnd_604mm_rockets_ATACMS_backupHEAB: 12Rnd_230mm_rockets
{
	RC_AdvisedTrajectory=1;	//1low, 2high, 3both
	displayName="ATACMS HE AB [direct]";
	displayNameShort="ATACMS HE AB [direct]";
	ammo="RC_R_604mm_ATACMS_backupHEAB";
	count=1;
};
class RC_2Rnd_604mm_rockets_ATACMS_backupHEAB: RC_1Rnd_604mm_rockets_ATACMS_backupHEAB
{
	count=2;
};


class RC_1Rnd_604mm_rockets_ATACMS_DPICM: 12Rnd_230mm_rockets
{
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="ATACMS DPICM";
	RC_TerrainWarning=1;
	displayNameShort="ATACMS DPICM";
	ammo="RC_R_604mm_ATACMS_DPICM";
	count=1;
};
class RC_2Rnd_604mm_rockets_ATACMS_DPICM: RC_1Rnd_604mm_rockets_ATACMS_DPICM
{
	count=2;
};