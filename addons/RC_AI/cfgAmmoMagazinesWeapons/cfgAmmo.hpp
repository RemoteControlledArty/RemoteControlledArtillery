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