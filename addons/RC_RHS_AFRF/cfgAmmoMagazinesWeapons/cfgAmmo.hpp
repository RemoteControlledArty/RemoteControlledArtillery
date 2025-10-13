//120mm
class rhs_ammo_M829A4;
class RC_RHS_ammo_M829A4: rhs_ammo_M829A4
{
	//caliber=?; //vanilla 35.268799, RHS 0.1, RHS seems to overpen with little hull damage

	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.045;
	tracerEndTime=4;
};
/*
class rhs_ammo_M829A3;
class RC_RHS_ammo_M829A3: rhs_ammo_M829A3
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.045;
	tracerEndTime=4;
};
*/
class rhs_ammo_M830A1;
class RC_RHS_ammo_M830A1: rhs_ammo_M830A1
{
	laserLock=1;
	irLock=1;
	airLock=1;
	aiAmmoUsageFlags="64 + 128 + 512";

	tracerStartTime=0.045;
	tracerEndTime=6;

	warheadName="HE";
	indirectHit=50;
	indirectHitRange=10;
	deflecting=1;
	craterEffects="AAMissileCrater";
};


class RC_RHS_ammo_M1147_DF_Sub: RC_RHS_ammo_M830A1
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_Sub_MP_DF.hpp"
	//submunitionAmmo="RC_ammo_Penetrator_MP_120mm";
};
class RC_RHS_ammo_M1147_MPAB_DF: RC_RHS_ammo_M830A1
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_MPAB_DF.hpp"
	submunitionAmmo="RC_RHS_ammo_M1147_DF_Sub";
};


//7.62x51mm
class rhs_ammo_762x51_M80A1EPR_Ball;
class RC_RHS_ammo_M80A1EPR_T_R: rhs_ammo_762x51_M80A1EPR_Ball
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4;

	hit=14;			//giving it acceptable lethality
	caliber=1.1;	//giving it acceptable lethality
	//airFriction=-0.00060999999;	//giving it acceptable range for vehicles
};
/*
class RC_RHS_ammo_M80A1EPR_T_Y: RC_RHS_ammo_M80A1EPR_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};
*/
class rhs_ammo_762x51_M61_AP;
class RC_RHS_ammo_M61_AP_T_R: rhs_ammo_762x51_M61_AP
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4;

	hit=14;			//giving it acceptable lethality
	caliber=1.1;	//giving it acceptable lethality
	//airFriction=-0.00060999999;	//giving it acceptable range for vehicles
};


//25mm
class RHS_ammo_M919_APFSDS;
class RC_RHS_B_25mm_APFSDS_T_R: RHS_ammo_M919_APFSDS
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_RHS_B_25mm_APFSDS_T_G: RC_RHS_B_25mm_APFSDS_T_R {model= "\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_APFSDS_T_Y: RC_RHS_B_25mm_APFSDS_T_R {model= "\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RHS_ammo_M792_HEI;
class RC_RHS_ammo_M792_HEI_T_R: RHS_ammo_M792_HEI
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.045;
	tracerEndTime=5;
	timeToLive=15;

	deflecting=1;
	indirectHit=6;
	indirectHitRange=3.75;
};
class RC_RHS_ammo_M792_HEI_T_G: RC_RHS_ammo_M792_HEI_T_R {model= "\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_ammo_M792_HEI_T_Y: RC_RHS_ammo_M792_HEI_T_R {model= "\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//MP Penetrator Submunition
class RC_ammo_Penetrator_MP_30mm;
class RC_ammo_Penetrator_MP_25mm: RC_ammo_Penetrator_MP_30mm
{
	hit=90;
	caliber=4.5;
	dangerRadiusHit=40;
	suppressionRadiusHit=14;
};


//25mm MP Pen/DF/QF
class RC_RHS_B_25mm_MP_Pen_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_Pen.hpp"
	//submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
};
class RC_RHS_B_25mm_MP_Pen_T_G: RC_RHS_B_25mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_MP_Pen_T_Y: RC_RHS_B_25mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_B_25mm_MP_DF_Sub: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
	caliber=4.3;
};
class RC_RHS_B_25mm_MP_DF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_RHS_B_25mm_MP_DF_Sub";
};
class RC_RHS_B_25mm_MP_DF_T_G: RC_RHS_B_25mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_MP_DF_T_Y: RC_RHS_B_25mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_B_25mm_MP_QF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
};
class RC_RHS_B_25mm_MP_QF_T_G: RC_RHS_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_MP_QF_T_Y: RC_RHS_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//25mm MPAB DF/QF
class RC_RHS_B_25mm_MPAB_DF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_RHS_B_25mm_MP_DF_Sub";
};
class RC_RHS_B_25mm_MPAB_DF_T_G: RC_RHS_B_25mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_MPAB_DF_T_Y: RC_RHS_B_25mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_B_25mm_MPAB_QF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
};
class RC_RHS_B_25mm_MPAB_QF_T_G: RC_RHS_B_25mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_MPAB_QF_T_Y: RC_RHS_B_25mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//25mm HE Pen/DF/QF
class RC_RHS_B_25mm_HE_Pen_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_Pen.hpp"
};
class RC_RHS_B_25mm_HE_Pen_T_G: RC_RHS_B_25mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_HE_Pen_T_Y: RC_RHS_B_25mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_B_25mm_HE_DF_Sub: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_HE_DF.hpp"
};
class RC_RHS_B_25mm_HE_DF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_DF.hpp"
	submunitionAmmo="RC_RHS_B_25mm_MP_DF_Sub";
};
class RC_RHS_B_25mm_HE_DF_T_G: RC_RHS_B_25mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_HE_DF_T_Y: RC_RHS_B_25mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_B_25mm_HE_QF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_QF.hpp"
};
class RC_RHS_B_25mm_HE_QF_T_G: RC_RHS_B_25mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_HE_QF_T_Y: RC_RHS_B_25mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//25mm HEAB DF/QF
class RC_RHS_B_25mm_HEAB_DF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_DF.hpp"
	submunitionAmmo="RC_RHS_B_25mm_MP_DF_Sub";
};
class RC_RHS_B_25mm_HEAB_DF_T_G: RC_RHS_B_25mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_HEAB_DF_T_Y: RC_RHS_B_25mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_B_25mm_HEAB_QF_T_R: RHS_ammo_M792_HEI
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults2.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_QF.hpp"
};
class RC_RHS_B_25mm_HEAB_QF_T_G: RC_RHS_B_25mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_B_25mm_HEAB_QF_T_Y: RC_RHS_B_25mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


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
	soundFly[]={"rhsusf\addons\rhsusf_heavyweapons\Sounds\TOW",1.1,0.7,550};
};
class RC_IFV_MP_Overfly;
class RC_TOW_MP_Overfly: RC_IFV_MP_Overfly
{
	effectsMissile="RHS_Missile2";
	model="\rhsusf\addons\rhsusf_heavyweapons\atgm\TOW2A";
	soundFly[]={"rhsusf\addons\rhsusf_heavyweapons\Sounds\TOW",1.1,0.7,550};
};
class RC_IFV_MP_LOS;
class RC_TOW_MP_LOS: RC_IFV_MP_LOS
{
	effectsMissile="RHS_Missile2";
	model="\rhsusf\addons\rhsusf_heavyweapons\atgm\TOW2A";
	soundFly[]={"rhsusf\addons\rhsusf_heavyweapons\Sounds\TOW",1.1,0.7,550};
};
class RC_IFV_MP_SACLOS;
class RC_TOW_MP_SACLOS: RC_IFV_MP_SACLOS
{
	effectsMissile="RHS_Missile2";
	//model="\rhsusf\addons\rhsusf_heavyweapons\atgm\TOW2A";
	soundFly[]={"rhsusf\addons\rhsusf_heavyweapons\Sounds\TOW",1.1,0.7,550};
};


class RC_Javelin_MP_NLOS: RC_IFV_MP_NLOS
{
	model="\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_missile";
	effectsMissile="missile2";
	effectsMissileInit="RocketBackEffectsRPG";
	effectsSmoke="SmokeShellWhite";
};
class RC_Javelin_MP_Overfly: RC_IFV_MP_Overfly
{
	model="\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_missile";
	effectsMissile="missile2";
	effectsMissileInit="RocketBackEffectsRPG";
	effectsSmoke="SmokeShellWhite";
};
class RC_Javelin_MP_LOS: RC_IFV_MP_LOS
{
	model="\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_missile";
	effectsMissile="missile2";
	effectsMissileInit="RocketBackEffectsRPG";
	effectsSmoke="SmokeShellWhite";
};
class RC_Javelin_MP_SACLOS: RC_IFV_MP_SACLOS
{
	//model="\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_missile";
	effectsMissile="missile2";
	effectsMissileInit="RocketBackEffectsRPG";
	effectsSmoke="SmokeShellWhite";
};


class RC_IFV_AA;
class RC_TOW_AA: RC_IFV_AA
{
	effectsMissile="RHS_Missile2";
	model="\rhsusf\addons\rhsusf_heavyweapons\atgm\TOW2A";
	soundFly[]={"rhsusf\addons\rhsusf_heavyweapons\Sounds\TOW",1.1,0.7,550};
};
class RC_Javelin_AA: RC_IFV_AA
{
	model="\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_missile";
	effectsMissile="missile2";
	effectsMissileInit="RocketBackEffectsRPG";
	effectsSmoke="SmokeShellWhite";
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
class RC_RHS_ammo_127x99_T_R: rhs_ammo_127x99_Ball_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=5;
};
class rhs_ammo_127x99_SLAP;
class RC_RHS_ammo_127x99_SLAP: rhs_ammo_127x99_SLAP
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=4.5;
};
class rhs_ammo_127x99_SLAP_Tracer_Red;
class RC_RHS_ammo_127x99_SLAP_T_R: rhs_ammo_127x99_SLAP_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4.5;
};
class RC_RHS_ammo_127x99_Ball_DroneLock_T_R: RC_RHS_ammo_127x99_T_R
{
	laserLock=0;
	irLock=0;
	airLock=2;
};
class RC_RHS_ammo_127x99_SLAP_DroneLock_T_R: RC_RHS_ammo_127x99_SLAP_T_R
{
	laserLock=0;
	irLock=0;
	airLock=2;
};


//40mm
class rhs_ammo_mk19m3_M430A1;
class RC_RHS_ammo_mk19m3_M430A1: rhs_ammo_mk19m3_M430A1
{
	laserLock=1;
	irLock=1;
	airLock=1;
};