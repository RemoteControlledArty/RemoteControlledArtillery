//7.62x51mm
class rhs_mag_1100Rnd_762x51_M240;
class RC_RHS_mag_1100Rnd_762x51_T_R: rhs_mag_1100Rnd_762x51_M240
{
	ammo="RC_RHS_ammo_M80A1EPR_T_R";
	tracersEvery=1;
};


//25mm
class rhs_mag_230Rnd_25mm_M242_HEI;
class RC_RHS_mag_230Rnd_25mm_HEI_T_R: rhs_mag_230Rnd_25mm_M242_HEI
{
	ammo="RC_RHS_ammo_M792_HEI_T_R";
	tracersEvery=1;
};

class rhs_mag_70Rnd_25mm_M242_APFSDS;
class RC_RHS_mag_70Rnd_25mm_APFSDS_T_R: rhs_mag_70Rnd_25mm_M242_APFSDS
{
	ammo="RC_RHS_ammo_M919_APFSDS_T_R";
	tracersEvery=1;
};


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

class rhs_mag_200rnd_127x99_mag_Tracer_Red;
class RC_RHS_mag_200rnd_127x99_T_R: rhs_mag_200rnd_127x99_mag_Tracer_Red
{
	ammo="RC_RHS_ammo_127x99_Ball_T_R";
	tracersEvery=1;
};

class rhs_mag_200rnd_127x99_SLAP_mag;
class RC_RHS_mag_200rnd_127x99_SLAP: rhs_mag_200rnd_127x99_SLAP_mag
{
	ammo="RC_RHS_ammo_127x99_SLAP";
};

class rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red;
class RC_RHS_mag_200rnd_127x99_SLAP_T_R: rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red
{
	ammo="RC_RHS_mag_100rnd_127x99_SLAP_T_R";
	tracersEvery=1;
};

class RC_RHS_mag_100rnd_127x99_T_R_nonlock: RC_RHS_mag_200rnd_127x99_T_R
{
	ammo="RC_RHS_ammo_127x99_Ball_T_R_nonlock";
	count=100;
};


//40mm
class RHS_96Rnd_40mm_MK19_M430A1;
class RC_RHS_96Rnd_40mm_MK19_M430A1: RHS_96Rnd_40mm_MK19_M430A1
{
	ammo="RC_RHS_ammo_mk19m3_M430A1";
};
