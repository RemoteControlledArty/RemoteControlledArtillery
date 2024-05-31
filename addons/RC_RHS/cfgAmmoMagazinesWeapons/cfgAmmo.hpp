//7.62x51mm
class rhs_ammo_762x51_M80A1EPR_Ball;
class RC_RHS_ammo_M80A1EPR_T_R: rhs_ammo_762x51_M80A1EPR_Ball
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=3;

	hit=14;			//giving it acceptable lethality
	caliber=1.1;	//giving it acceptable lethality
};
/*
class RC_RHS_ammo_M80A1EPR_T_Y: RC_RHS_ammo_M80A1EPR_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};
*/


//25mm
class RHS_ammo_M792_HEI;
class RC_RHS_ammo_M792_HEI_T_R: RHS_ammo_M792_HEI
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.045;
	//tracerEndTime=3;

	deflecting=1;
	indirectHitRange=4;
};
/*
class RC_RHS_ammo_M792_HEI_T_Y: RC_RHS_ammo_M792_HEI_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};
*/

class RHS_ammo_M919_APFSDS;
class RC_RHS_ammo_M919_APFSDS_T_R: RHS_ammo_M919_APFSDS
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=3;
};
/*
class RC_RHS_ammo_M919_APFSDS_T_Y: RC_RHS_ammo_M919_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};
*/


//TOW's
class rhs_ammo_TOW2A_AT;
class RC_RHS_ammo_TOW2A_AT: rhs_ammo_TOW2A_AT
{
	laserLock=1;
	irLock=1;
	airLock=1;
};

class rhs_ammo_TOW2_BB;
class RC_RHS_ammo_TOW2_BB: rhs_ammo_TOW2_BB
{
	laserLock=1;
	irLock=1;
	airLock=1;
};

class RC_IFV_MP_NLOS;
class RC_TOW_MP_NLOS: RC_IFV_MP_NLOS
{
	effectsMissile="RHS_Missile2";
	model="\rhsusf\addons\rhsusf_heavyweapons\atgm\TOW2A";
	soundFly[] = {"rhsusf\addons\rhsusf_heavyweapons\Sounds\TOW",1.1,0.7,550};
};

class RC_IFV_AA;
class RC_TOW_AA: RC_IFV_AA
{
	effectsMissile="RHS_Missile2";
	model="\rhsusf\addons\rhsusf_heavyweapons\atgm\TOW2A";
	soundFly[] = {"rhsusf\addons\rhsusf_heavyweapons\Sounds\TOW",1.1,0.7,550};
};


//12.7x99mm
class rhs_ammo_127x99_Ball;
class RC_RHS_ammo_127x99_Ball: rhs_ammo_127x99_Ball
{
	laserLock=1;
	irLock=1;
	airLock=1;
};

class rhs_ammo_127x99_Ball_Tracer_Red;
class RC_RHS_ammo_127x99_Ball_T_R: rhs_ammo_127x99_Ball_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.045;
};

class rhs_ammo_127x99_SLAP;
class RC_RHS_ammo_127x99_SLAP: rhs_ammo_127x99_SLAP
{
	laserLock=1;
	irLock=1;
	airLock=1;
};

class rhs_ammo_127x99_SLAP_Tracer_Red;
class RC_RHS_mag_100rnd_127x99_SLAP_T_R: rhs_ammo_127x99_SLAP_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
};

class RC_RHS_ammo_127x99_Ball_T_R_nonlock: RC_RHS_ammo_127x99_Ball_T_R
{
	laserLock=0;
	irLock=0;
	airLock=0;
};


//40mm
class rhs_ammo_mk19m3_M430A1;
class RC_RHS_ammo_mk19m3_M430A1: rhs_ammo_mk19m3_M430A1
{
	laserLock=1;
	irLock=1;
	airLock=1;
};