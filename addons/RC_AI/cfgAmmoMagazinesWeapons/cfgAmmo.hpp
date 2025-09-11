//Vanilla
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


class RC_Sh_120mm_APFSDS_T_R;
class RC_AI_Sh_120mm_APFSDS_T_R: RC_Sh_120mm_APFSDS_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Sh_120mm_APFSDS_T_G: RC_AI_Sh_120mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_120mm_APFSDS_T_Y: RC_AI_Sh_120mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_ammo_Penetrator_MP_120mm;
class RC_AI_ammo_Penetrator_MP_120mm: RC_ammo_Penetrator_MP_120mm
{
	hit=510;		//780
	caliber=40;		//60
	warheadName="HEAT";	//TandemHEAT
};
class RC_Sh_120mm_MP_T_R;
class RC_AI_Sh_120mm_MP_T_R: RC_Sh_120mm_MP_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
	submunitionAmmo="RC_AI_ammo_Penetrator_120mm";		//RC_ammo_Penetrator_120mm
	indirectHit=40;			//50
	indirectHitRange=8;		//10
};
class RC_AI_Sh_120mm_MP_T_G: RC_AI_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Sh_120mm_MP_T_Y: RC_AI_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


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
};