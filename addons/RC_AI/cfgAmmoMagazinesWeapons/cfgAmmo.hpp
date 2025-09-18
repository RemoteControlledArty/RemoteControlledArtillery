//Vanilla
//MMG
class RC_B_338_T_R;
class RC_AI_B_338_T_R: RC_B_338_T_R
{
	hit=16;
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_B_338_T_G: RC_AI_B_338_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_B_338_T_Y: RC_AI_B_338_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_AI_B_338_T_W: RC_AI_B_338_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};


class RC_B_93x64_T_G;
class RC_AI_B_93x64_T_G: RC_B_93x64_T_G
{
	hit=16;
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_B_93x64_T_R: RC_AI_B_93x64_T_G {model="\A3\Weapons_f\Data\bullettracer\tracer_red";};
class RC_AI_B_93x64_T_Y: RC_AI_B_93x64_T_G {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//30mm
/*
class RC_B_30mm_MP_DF_Sub;
class RC_AI_B_30mm_MP_DF_Sub: RC_B_30mm_MP_DF_Sub
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_30mm";
	caliber=4.4;
};
*/
class RC_B_30mm_APFSDS_T_R;
class RC_AI_B_30mm_APFSDS_T_R: RC_B_30mm_APFSDS_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_B_30mm_APFSDS_T_G: RC_AI_B_30mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_B_30mm_APFSDS_T_Y: RC_AI_B_30mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_B_30mm_MP_Pen_T_R;
class RC_AI_B_30mm_MP_Pen_T_R: RC_B_30mm_MP_Pen_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_B_30mm_MP_Pen_T_G: RC_AI_B_30mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_B_30mm_MP_Pen_T_Y: RC_AI_B_30mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_B_30mm_MP_DF_T_R;
class RC_AI_B_30mm_MP_DF_T_R: RC_B_30mm_MP_DF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	//submunitionAmmo="RC_AI_B_30mm_MP_DF_Sub";
};
class RC_AI_B_30mm_MP_DF_T_G: RC_AI_B_30mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_B_30mm_MP_DF_T_Y: RC_AI_B_30mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_B_30mm_MPAB_DF_T_R;
class RC_AI_B_30mm_MPAB_DF_T_R: RC_B_30mm_MPAB_DF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	//submunitionAmmo="RC_AI_B_30mm_MP_DF_Sub";
};
class RC_AI_B_30mm_MPAB_DF_T_G: RC_AI_B_30mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_B_30mm_MPAB_DF_T_Y: RC_AI_B_30mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//120mm
class RC_Sh_120mm_APFSDS_T_R;
class RC_AI_Sh_120mm_APFSDS_T_R: RC_Sh_120mm_APFSDS_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Sh_120mm_APFSDS_T_G: RC_AI_Sh_120mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_120mm_APFSDS_T_Y: RC_AI_Sh_120mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};

class RC_ammo_Penetrator_120mm;
class RC_AI_ammo_Penetrator_120mm: RC_ammo_Penetrator_120mm
{
	warheadName="HEAT";
};
class RC_Sh_120mm_MP_T_R;
class RC_AI_Sh_120mm_MP_T_R: RC_Sh_120mm_MP_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	submunitionAmmo="RC_AI_ammo_Penetrator_120mm";
	indirectHit=30;			//50
	indirectHitRange=7;		//10
};
class RC_AI_Sh_120mm_MP_T_G: RC_AI_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_120mm_MP_T_Y: RC_AI_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_ammo_Penetrator_AB_120mm;
class RC_AI_ammo_Penetrator_AB_120mm: RC_ammo_Penetrator_AB_120mm
{
	warheadName="HEAT";
};
class RC_Sh_120mm_MP_DF_Sub;
class RC_AI_Sh_120mm_MP_DF_Sub: RC_Sh_120mm_MP_DF_Sub
{
	laserLock=0;
	irLock=0;
	airLock=1;
	submunitionAmmo="RC_AI_ammo_Penetrator_AB_120mm";
	indirectHit=30;			//50
	indirectHitRange=7;		//10
};
class RC_Sh_120mm_MPAB_DF_T_R;
class RC_AI_Sh_120mm_MPAB_DF_T_R: RC_Sh_120mm_MPAB_DF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	submunitionAmmo="RC_AI_Sh_120mm_MP_DF_Sub";
	indirectHit=30;			//50
	indirectHitRange=7;		//10
};
class RC_AI_Sh_120mm_MPAB_DF_T_G: RC_AI_Sh_120mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_120mm_MPAB_DF_T_Y: RC_AI_Sh_120mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//125mm
class RC_Sh_125mm_APFSDS_T_R;
class RC_AI_Sh_125mm_APFSDS_T_R: RC_Sh_125mm_APFSDS_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Sh_125mm_APFSDS_T_G: RC_AI_Sh_125mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_125mm_APFSDS_T_Y: RC_AI_Sh_125mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class ammo_Penetrator_125mm;
class RC_AI_ammo_Penetrator_125mm: ammo_Penetrator_125mm
{
	warheadName="HEAT";
};
class RC_Sh_125mm_MP_T_R;
class RC_AI_Sh_125mm_MP_T_R: RC_Sh_125mm_MP_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	submunitionAmmo="RC_AI_ammo_Penetrator_125mm";
	indirectHit=30;			//50
	indirectHitRange=7;		//10
};
class RC_AI_Sh_125mm_MP_T_G: RC_AI_Sh_125mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_125mm_MP_T_Y: RC_AI_Sh_125mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_ammo_Penetrator_AB_125mm;
class RC_AI_ammo_Penetrator_AB_125mm: RC_ammo_Penetrator_AB_125mm
{
	warheadName="HEAT";
};
class RC_Sh_125mm_MP_DF_Sub;
class RC_AI_Sh_125mm_MP_DF_Sub: RC_Sh_125mm_MP_DF_Sub
{
	laserLock=0;
	irLock=0;
	airLock=1;
	submunitionAmmo="RC_AI_ammo_Penetrator_AB_125mm";
	indirectHit=30;			//50
	indirectHitRange=7;		//10
};
class RC_Sh_125mm_MPAB_DF_T_R;
class RC_AI_Sh_125mm_MPAB_DF_T_R: RC_Sh_125mm_MPAB_DF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	submunitionAmmo="RC_AI_Sh_125mm_MP_DF_Sub";
	indirectHit=30;			//50
	indirectHitRange=7;		//10
};
class RC_AI_Sh_125mm_MPAB_DF_T_G: RC_AI_Sh_125mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_125mm_MPAB_DF_T_Y: RC_AI_Sh_125mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//missiles
class ammo_Penetrator_Base;
class RC_AI_ammo_Penetrator_MP_SACLOS: ammo_Penetrator_Base
{
	warheadName="HEAT";
	caliber=40;
	hit=500;
};
class RC_M_ATGM_MP_SACLOS;
class RC_AI_IFV_MP_SACLOS: RC_M_ATGM_MP_SACLOS
{
	submunitionAmmo="RC_AI_ammo_Penetrator_MP_SACLOS";
	indirectHit=30;		//40
	indirectHitRange=7;	//10
	maxSpeed=200;
	thrustTime=8;
};



//RHS
class RC_RHS_ammo_M919_APFSDS_T_R;
class RC_AI_RHS_ammo_M919_APFSDS_T_R: RC_RHS_ammo_M919_APFSDS_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_RHS_B_25mm_MPAB_DF_T_R;
class RC_AI_RHS_B_25mm_MPAB_DF_T_R: RC_RHS_B_25mm_MPAB_DF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	//submunitionAmmo="RC_AI_B_30mm_MP_DF_Sub";
};
/*
class RC_AI_RHS_B_25mm_MPAB_DF_T_G: RC_AI_RHS_B_25mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_RHS_B_25mm_MPAB_DF_T_Y: RC_AI_RHS_B_25mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
*/


class RC_RHS_ammo_M80A1EPR_T_R;
class RC_AI_RHS_ammo_M80A1EPR_T_R: RC_RHS_ammo_M80A1EPR_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;

	hit=10.5;		//original
	caliber=0.55;	//original
	//hit=11.6; caliber=1.6; vanilla ball
};