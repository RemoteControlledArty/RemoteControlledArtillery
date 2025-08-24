//120mm
class rhs_mag_M829A4;
//class RC_20Rnd_120mm_APFSDS_T_R;
class RC_RHS_mag_M829A4_20Rnd: rhs_mag_M829A4
{
	displayName="M829A4 APFSDS-T";
	displayNameShort="M829A4 AP";
	ammo="RC_RHS_ammo_M829A4";
	count=20;
};
class RC_RHS_mag_M829A4_15Rnd: RC_RHS_mag_M829A4_20Rnd {count=15;};
class RC_RHS_mag_M829A4_10Rnd: RC_RHS_mag_M829A4_20Rnd {count=10;};


class rhs_mag_M830A1;
//class RC_10Rnd_120mm_MP_T_R;
class RC_RHS_mag_M830A1_20Rnd: rhs_mag_M830A1
{
	displayName="M830A1 MPAT";
	displayNameShort="M830A1 MP";
	ammo="RC_RHS_ammo_M830A1";
	count=20;
};
class RC_RHS_mag_M830A1_15Rnd: RC_RHS_mag_M830A1_20Rnd {count=15;};
class RC_RHS_mag_M830A1_10Rnd: RC_RHS_mag_M830A1_20Rnd {count=10;};


/*
//SABOT
"rhs_mag_M829A4",
"rhs_mag_M829A3",
"rhs_mag_M829A2",
"rhs_mag_M829A1",
"rhs_mag_M829",
//HEAT
"rhs_mag_M830",
"rhs_mag_M830A1",
//HE
"rhs_mag_M1069",
"rhs_mag_M1147",
//Canister
"rhs_mag_M1028",
//Smoke/WP
"rhs_mag_M416"
*/


//7.62x51mm
class rhs_mag_1100Rnd_762x51_M240;
class RC_RHS_mag_1100Rnd_762x51_T_R: rhs_mag_1100Rnd_762x51_M240
{
	ammo="RC_RHS_ammo_M80A1EPR_T_R";
	tracersEvery=1;
};
class RC_RHS_mag_1200Rnd_762x51_T_R: RC_RHS_mag_1100Rnd_762x51_T_R {count=1200;};
class RC_RHS_mag_1100Rnd_762x51_M61_T_R: RC_RHS_mag_1100Rnd_762x51_T_R
{
	ammo="RC_RHS_ammo_M61_AP_T_R";
	displayname="7.62x51mm AP";
	displaynameshort="M61 AP";
};
class RC_RHS_mag_1200Rnd_762x51_M61_T_R: RC_RHS_mag_1100Rnd_762x51_M61_T_R {count=1200;};


//25mm
class rhs_mag_70Rnd_25mm_M242_APFSDS;
class RC_RHS_mag_70Rnd_25mm_APFSDS_T_R: rhs_mag_70Rnd_25mm_M242_APFSDS
{
	ammo="RC_RHS_ammo_M919_APFSDS_T_R";
	tracersEvery=1;
};
class rhs_mag_230Rnd_25mm_M242_HEI;
class RC_RHS_mag_230Rnd_25mm_HEI_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_ammo_M792_HEI_T_R";
	tracersEvery=1;
};


//25mm multi purpose (HE with shaped charge penetrator) + pen/delayed/quick fuze
class RC_RHS_230Rnd_25mm_MP_Pen_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_MP_Pen_T_R";
	displayName="M792A1 MP-T";
	displayNameShort="M792A1 MP";
};
class RC_RHS_230Rnd_25mm_MP_Pen_T_G: RC_RHS_230Rnd_25mm_MP_Pen_T_R {ammo="RC_RHS_B_25mm_MP_Pen_T_G";};
class RC_RHS_230Rnd_25mm_MP_Pen_T_Y: RC_RHS_230Rnd_25mm_MP_Pen_T_R {ammo="RC_RHS_B_25mm_MP_Pen_T_Y";};
class RC_RHS_110Rnd_25mm_MP_Pen_T_R: RC_RHS_230Rnd_25mm_MP_Pen_T_R {count=110;};
class RC_RHS_110Rnd_25mm_MP_Pen_T_G: RC_RHS_230Rnd_25mm_MP_Pen_T_G {count=110;};
class RC_RHS_110Rnd_25mm_MP_Pen_T_Y: RC_RHS_230Rnd_25mm_MP_Pen_T_Y {count=110;};
class RC_RHS_230Rnd_25mm_MP_DF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_MP_DF_T_R";
	displayName="M792A1 MP-DF-T";
	displayNameShort="M792A1 MP-DF";
};
class RC_RHS_230Rnd_25mm_MP_DF_T_G: RC_RHS_230Rnd_25mm_MP_DF_T_R {ammo="RC_RHS_B_25mm_MP_DF_T_G";};
class RC_RHS_230Rnd_25mm_MP_DF_T_Y: RC_RHS_230Rnd_25mm_MP_DF_T_R {ammo="RC_RHS_B_25mm_MP_DF_T_Y";};
class RC_RHS_110Rnd_25mm_MP_DF_T_R: RC_RHS_230Rnd_25mm_MP_DF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_MP_DF_T_G: RC_RHS_230Rnd_25mm_MP_DF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_MP_DF_T_Y: RC_RHS_230Rnd_25mm_MP_DF_T_Y {count=110;};
class RC_RHS_230Rnd_25mm_MP_QF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_MP_QF_T_R";
	displayName="M792A1 MP-QF-T";
	displayNameShort="M792A1 MP-QF";
};
class RC_RHS_230Rnd_25mm_MP_QF_T_G: RC_RHS_230Rnd_25mm_MP_QF_T_R {ammo="RC_RHS_B_25mm_MP_QF_T_G";};
class RC_RHS_230Rnd_25mm_MP_QF_T_Y: RC_RHS_230Rnd_25mm_MP_QF_T_R {ammo="RC_RHS_B_25mm_MP_QF_T_Y";};
class RC_RHS_110Rnd_25mm_MP_QF_T_R: RC_RHS_230Rnd_25mm_MP_QF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_MP_QF_T_G: RC_RHS_230Rnd_25mm_MP_QF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_MP_QF_T_Y: RC_RHS_230Rnd_25mm_MP_QF_T_Y {count=110;};


//25mm multi purpose (HE with shaped charge penetrator) + airburst + delayed/quick fuze
class RC_RHS_230Rnd_25mm_MPAB_DF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_MPAB_DF_T_R";
	displayName="M792A1 MPAB-DF-T";
	displayNameShort="M792A1 MPAB-DF";
};
class RC_RHS_230Rnd_25mm_MPAB_DF_T_G: RC_RHS_230Rnd_25mm_MPAB_DF_T_R {ammo="RC_RHS_B_25mm_MPAB_DF_T_G";};
class RC_RHS_230Rnd_25mm_MPAB_DF_T_Y: RC_RHS_230Rnd_25mm_MPAB_DF_T_R {ammo="RC_RHS_B_25mm_MPAB_DF_T_Y";};
class RC_RHS_110Rnd_25mm_MPAB_DF_T_R: RC_RHS_230Rnd_25mm_MPAB_DF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_MPAB_DF_T_G: RC_RHS_230Rnd_25mm_MPAB_DF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_MPAB_DF_T_Y: RC_RHS_230Rnd_25mm_MPAB_DF_T_Y {count=110;};
class RC_RHS_230Rnd_25mm_MPAB_QF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_MPAB_QF_T_R";
	displayName="M792A1 MPAB-QF-T";
	displayNameShort="M792A1 MPAB-QF";
};
class RC_RHS_230Rnd_25mm_MPAB_QF_T_G: RC_RHS_230Rnd_25mm_MPAB_QF_T_R {ammo="RC_RHS_B_25mm_MPAB_QF_T_G";};
class RC_RHS_230Rnd_25mm_MPAB_QF_T_Y: RC_RHS_230Rnd_25mm_MPAB_QF_T_R {ammo="RC_RHS_B_25mm_MPAB_QF_T_Y";};
class RC_RHS_110Rnd_25mm_MPAB_QF_T_R: RC_RHS_230Rnd_25mm_MPAB_QF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_MPAB_QF_T_G: RC_RHS_230Rnd_25mm_MPAB_QF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_MPAB_QF_T_Y: RC_RHS_230Rnd_25mm_MPAB_QF_T_Y {count=110;};


//25mm HEI + pen/delayed/quick fuze
class RC_RHS_230Rnd_25mm_HEI_Pen_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_HEI_Pen_T_R";
	displayName="M792 HEI-T";
	displayNameShort="M792 HEI";
};
class RC_RHS_230Rnd_25mm_HEI_Pen_T_G: RC_RHS_230Rnd_25mm_HEI_Pen_T_R {ammo="RC_RHS_B_25mm_HEI_Pen_T_G";};
class RC_RHS_230Rnd_25mm_HEI_Pen_T_Y: RC_RHS_230Rnd_25mm_HEI_Pen_T_R {ammo="RC_RHS_B_25mm_HEI_Pen_T_Y";};
class RC_RHS_110Rnd_25mm_HEI_Pen_T_R: RC_RHS_230Rnd_25mm_HEI_Pen_T_R {count=110;};
class RC_RHS_110Rnd_25mm_HEI_Pen_T_G: RC_RHS_230Rnd_25mm_HEI_Pen_T_G {count=110;};
class RC_RHS_110Rnd_25mm_HEI_Pen_T_Y: RC_RHS_230Rnd_25mm_HEI_Pen_T_Y {count=110;};
class RC_RHS_230Rnd_25mm_HEI_DF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_HEI_DF_T_R";
	displayName="M792 HEI-DF-T";
	displayNameShort="M792 HEI-DF";
};
class RC_RHS_230Rnd_25mm_HEI_DF_T_G: RC_RHS_230Rnd_25mm_HEI_DF_T_R {ammo="RC_RHS_B_25mm_HEI_DF_T_G";};
class RC_RHS_230Rnd_25mm_HEI_DF_T_Y: RC_RHS_230Rnd_25mm_HEI_DF_T_R {ammo="RC_RHS_B_25mm_HEI_DF_T_Y";};
class RC_RHS_110Rnd_25mm_HEI_DF_T_R: RC_RHS_230Rnd_25mm_HEI_DF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_HEI_DF_T_G: RC_RHS_230Rnd_25mm_HEI_DF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_HEI_DF_T_Y: RC_RHS_230Rnd_25mm_HEI_DF_T_Y {count=110;};
class RC_RHS_230Rnd_25mm_HEI_QF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_HEI_QF_T_R";
	displayName="M792 HEI-QF-T";
	displayNameShort="M792 HEI-QF";
};
class RC_RHS_230Rnd_25mm_HEI_QF_T_G: RC_RHS_230Rnd_25mm_HEI_QF_T_R {ammo="RC_RHS_B_25mm_HEI_QF_T_G";};
class RC_RHS_230Rnd_25mm_HEI_QF_T_Y: RC_RHS_230Rnd_25mm_HEI_QF_T_R {ammo="RC_RHS_B_25mm_HEI_QF_T_Y";};
class RC_RHS_110Rnd_25mm_HEI_QF_T_R: RC_RHS_230Rnd_25mm_HEI_QF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_HEI_QF_T_G: RC_RHS_230Rnd_25mm_HEI_QF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_HEI_QF_T_Y: RC_RHS_230Rnd_25mm_HEI_QF_T_Y {count=110;};


//M792 HEI + airburst + delayed/quick fuze
class RC_RHS_230Rnd_25mm_HEAB_DF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_HEAB_DF_T_R";
	displayName="M792 HEI-AB-DF-T";
	displayNameShort="M792 HEI-AB-DF";
};
class RC_RHS_230Rnd_25mm_HEAB_DF_T_G: RC_RHS_230Rnd_25mm_HEAB_DF_T_R {ammo="RC_RHS_B_25mm_HEAB_DF_T_G";};
class RC_RHS_230Rnd_25mm_HEAB_DF_T_Y: RC_RHS_230Rnd_25mm_HEAB_DF_T_R {ammo="RC_RHS_B_25mm_HEAB_DF_T_Y";};
class RC_RHS_110Rnd_25mm_HEAB_DF_T_R: RC_RHS_230Rnd_25mm_HEAB_DF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_HEAB_DF_T_G: RC_RHS_230Rnd_25mm_HEAB_DF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_HEAB_DF_T_Y: RC_RHS_230Rnd_25mm_HEAB_DF_T_Y {count=110;};
class RC_RHS_230Rnd_25mm_HEAB_QF_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_B_25mm_HEAB_QF_T_R";
	displayName="M792 HEI-AB-QF-T";
	displayNameShort="M792 HEI-AB-QF";
};
class RC_RHS_230Rnd_25mm_HEAB_QF_T_G: RC_RHS_230Rnd_25mm_HEAB_QF_T_R {ammo="RC_RHS_B_25mm_HEAB_QF_T_G";};
class RC_RHS_230Rnd_25mm_HEAB_QF_T_Y: RC_RHS_230Rnd_25mm_HEAB_QF_T_R {ammo="RC_RHS_B_25mm_HEAB_QF_T_Y";};
class RC_RHS_110Rnd_25mm_HEAB_QF_T_R: RC_RHS_230Rnd_25mm_HEAB_QF_T_R {count=110;};
class RC_RHS_110Rnd_25mm_HEAB_QF_T_G: RC_RHS_230Rnd_25mm_HEAB_QF_T_G {count=110;};
class RC_RHS_110Rnd_25mm_HEAB_QF_T_Y: RC_RHS_230Rnd_25mm_HEAB_QF_T_Y {count=110;};


//TOW's
class rhs_mag_2Rnd_TOW2A;
class RC_RHS_mag_2Rnd_TOW2A: rhs_mag_2Rnd_TOW2A
{
	ammo="RC_RHS_ammo_TOW2A_AT";
};
class rhs_mag_2Rnd_TOW2BB;
class RC_RHS_mag_2Rnd_TOW2BB: rhs_mag_2Rnd_TOW2BB
{
	ammo="RC_RHS_ammo_TOW2_BB";
};


class RC_2Rnd_IFV_MP_NLOS;
class RC_2Rnd_TOW_MP_NLOS: RC_2Rnd_IFV_MP_NLOS
{
	ammo="RC_TOW_MP_NLOS";
	displayName="TOW NLOS";
	displayNameShort="TOW NLOS";
};
class RC_2Rnd_IFV_MP_LOS;
class RC_2Rnd_TOW_MP_LOS: RC_2Rnd_IFV_MP_LOS
{
	ammo="RC_TOW_MP_LOS";
	displayName="TOW";
	displayNameShort="TOW";
};
class RC_2Rnd_IFV_MP_Overfly;
class RC_2Rnd_TOW_MP_Overfly: RC_2Rnd_IFV_MP_Overfly
{
	ammo="RC_TOW_MP_Overfly";
	displayName="TOW Overfly";
	displayNameShort="TOW Overfly";
};
class RC_2Rnd_IFV_AA;
class RC_2Rnd_TOW_AA: RC_2Rnd_IFV_AA
{
	ammo="RC_TOW_AA";
	displayName="TOW AA";
	displayNameShort="TOW AA";
};


class RC_2Rnd_Javelin_MP_NLOS: RC_2Rnd_IFV_MP_NLOS
{
	ammo="RC_Javelin_MP_NLOS";
	displayName="Javelin NLOS";
	displayNameShort="Javelin NLOS";
};
class RC_1Rnd_Javelin_MP_NLOS: RC_2Rnd_Javelin_MP_NLOS {count=1;};
class RC_3Rnd_Javelin_MP_NLOS: RC_2Rnd_Javelin_MP_NLOS {count=3;};
class RC_4Rnd_Javelin_MP_NLOS: RC_2Rnd_Javelin_MP_NLOS {count=4;};


class RC_2Rnd_Javelin_MP_Overfly: RC_2Rnd_IFV_MP_Overfly
{
	ammo="RC_Javelin_MP_Overfly";
	displayName="Javelin Overfly";
	displayNameShort="Javelin Overfly";
};
class RC_1Rnd_Javelin_MP_Overfly: RC_2Rnd_Javelin_MP_Overfly {count=1;};
class RC_3Rnd_Javelin_MP_Overfly: RC_2Rnd_Javelin_MP_Overfly {count=3;};
class RC_4Rnd_Javelin_MP_Overfly: RC_2Rnd_Javelin_MP_Overfly {count=4;};


class RC_2Rnd_Javelin_MP_LOS: RC_2Rnd_IFV_MP_LOS
{
	ammo="RC_Javelin_MP_LOS";
	displayName="Javelin Direct";
	displayNameShort="Javelin Direct";
};
class RC_1Rnd_Javelin_MP_LOS: RC_2Rnd_Javelin_MP_LOS {count=1;};
class RC_3Rnd_Javelin_MP_LOS: RC_2Rnd_Javelin_MP_LOS {count=3;};
class RC_4Rnd_Javelin_MP_LOS: RC_2Rnd_Javelin_MP_LOS {count=4;};


class RC_2Rnd_Javelin_AA: RC_2Rnd_IFV_AA
{
	ammo="RC_Javelin_AA";
	displayName="Javelin AA";
	displayNameShort="Javelin AA";
};
class RC_1Rnd_Javelin_AA: RC_2Rnd_Javelin_AA {count=1;};
class RC_3Rnd_Javelin_AA: RC_2Rnd_Javelin_AA {count=3;};
class RC_4Rnd_Javelin_AA: RC_2Rnd_Javelin_AA {count=4;};


/*
//bradley
class rhs_mag_2Rnd_TOW: VehicleMagazine
{
	scope=2;
	ammo = "rhs_ammo_TOW_AT";
	displayname = "BGM-71A TOW";
	displaynameshort = "BGM-71A";
	nameSound="missiles";
	count=2;
	initSpeed=55.71;
	maxleadspeed = 130;
	rhs_magazineIndex=4;
};

class rhs_mag_2Rnd_TOWB: rhs_mag_2Rnd_TOW
{
	scope=2;
	ammo = "rhs_ammo_TOWB_AT";
	displayname = "BGM-71B TOW";
	displaynameshort = "BGM-71B";
};

class rhs_mag_2Rnd_ITOW: rhs_mag_2Rnd_TOW
{
	scope=2;
	ammo = "rhs_ammo_ITOW_AT";
	displayname = "BGM-71C ITOW";
	displaynameshort = "BGM-71C";
};

class rhs_mag_2Rnd_TOW2: rhs_mag_2Rnd_TOW
{
	scope=2;
	ammo = "rhs_ammo_TOW2_AT";
	displayname = "BGM-71D TOW-2";
	displaynameshort = "BGM-71D";
};

class rhs_mag_2Rnd_TOW2A: rhs_mag_2Rnd_TOW
{
	scope=2;
	ammo = "rhs_ammo_TOW2A_AT";
	displayname = "BGM-71E TOW-2A";
	displaynameshort = "BGM-71E";
};

class rhs_mag_2Rnd_TOW2B: rhs_mag_2Rnd_TOW
{
	scope=2;
	ammo = "rhs_ammo_TOW2B_AT";
	displayname = "BGM-71F TOW-2B";
	displaynameshort = "BGM-71F";
};

class rhs_mag_2Rnd_TOW2B_AERO: rhs_mag_2Rnd_TOW
{
	scope=2;
	ammo = "rhs_ammo_TOW2B_AERO_AT";
	displayname = "BGM-71F-3 TOW-2B AERO";
	displaynameshort = "BGM-71F-3";
};

class rhs_mag_2Rnd_TOW2BB: rhs_mag_2Rnd_TOW
{
	scope=2;
	ammo = "rhs_ammo_TOW2_BB";
	displayname = "BGM-71H Bunker Buster";
	displaynameshort = "BGM-71H";
};
*/


//12.7x99mm
class rhs_mag_200rnd_127x99_mag;
class RC_RHS_mag_200rnd_127x99: rhs_mag_200rnd_127x99_mag
{
	ammo="RC_RHS_ammo_127x99_Ball";
};
class RC_RHS_mag_400rnd_127x99: RC_RHS_mag_200rnd_127x99 {count=400;};


class rhs_mag_200rnd_127x99_mag_Tracer_Red;
class RC_RHS_mag_200rnd_127x99_T_R: rhs_mag_200rnd_127x99_mag_Tracer_Red
{
	ammo="RC_RHS_ammo_127x99_Ball_T_R";
	tracersEvery=1;
};
class RC_RHS_mag_400rnd_127x99_T_R: RC_RHS_mag_200rnd_127x99_T_R {count=400;};


class rhs_mag_200rnd_127x99_SLAP_mag;
class RC_RHS_mag_200rnd_127x99_SLAP: rhs_mag_200rnd_127x99_SLAP_mag
{
	ammo="RC_RHS_ammo_127x99_SLAP";
};
class RC_RHS_mag_400rnd_127x99_SLAP: RC_RHS_mag_200rnd_127x99_SLAP {count=400;};


class rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red;
class RC_RHS_mag_200rnd_127x99_SLAP_T_R: rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red
{
	ammo="RC_RHS_ammo_127x99_SLAP_T_R";
	tracersEvery=1;
};
class RC_RHS_mag_400rnd_127x99_SLAP_T_R: RC_RHS_mag_200rnd_127x99_SLAP_T_R {count=400;};


class RC_RHS_mag_200rnd_127x99_Ball_DroneLock_T_R: RC_RHS_mag_200rnd_127x99_T_R
{
	ammo="RC_RHS_ammo_127x99_Ball_DroneLock_T_R";
	tracersEvery=1;
};
class RC_RHS_mag_150rnd_127x99_Ball_DroneLock_T_R: RC_RHS_mag_200rnd_127x99_Ball_DroneLock_T_R {count=150;};
class RC_RHS_mag_100rnd_127x99_Ball_DroneLock_T_R: RC_RHS_mag_200rnd_127x99_Ball_DroneLock_T_R {count=100;};


class RC_RHS_mag_200rnd_127x99_SLAP_DroneLock_T_R: rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red
{
	ammo="RC_RHS_ammo_127x99_SLAP_DroneLock_T_R";
	tracersEvery=1;
};
class RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R: RC_RHS_mag_200rnd_127x99_SLAP_DroneLock_T_R {count=150;};
class RC_RHS_mag_100rnd_127x99_SLAP_DroneLock_T_R: RC_RHS_mag_200rnd_127x99_SLAP_DroneLock_T_R {count=100;};


//40mm
class RHS_96Rnd_40mm_MK19_M430A1;
class RC_RHS_96Rnd_40mm_MK19_M430A1: RHS_96Rnd_40mm_MK19_M430A1
{
	ammo="RC_RHS_ammo_mk19m3_M430A1";
};
