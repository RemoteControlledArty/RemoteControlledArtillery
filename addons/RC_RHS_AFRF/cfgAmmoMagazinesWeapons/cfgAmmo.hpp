//100mm
class rhs_ammo_3UOF191;
class RC_RHS_AFRF_Sh_100mm_MP_Base: rhs_ammo_3UOF191
{
	craterEffects="AAMissileCrater";
	explosionEffects="RC_ULM_MortarExplosion";
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";

	laserLock=1;
	irLock=1;
	airLock=1;
	deflecting=1;
	tracerStartTime=0.05;
	tracerEndTime=10;
	timeToLive=15;

	//caliber=;
	hit=95;
	indirectHit=35;
	indirectHitRange=8;
	//airFriction=-0.00030799999;	//105mm
};
class RC_RHS_AFRF_Sh_100mm_MP_DF_Sub: RC_RHS_AFRF_Sh_100mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_AB_100mm";
};


class RC_RHS_AFRF_Sh_100mm_MP_Pen_T_R: RC_RHS_AFRF_Sh_100mm_MP_Base
{
	caliber=28.6667;
	hit=450;
	warheadName="TandemHEAT";

	explosive=0.60000002;
	simulation="shotBullet";
	aiAmmoUsageFlags="64 + 128 + 256 + 512";
};
class RC_RHS_AFRF_Sh_100mm_MP_Pen_T_G: RC_RHS_AFRF_Sh_100mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_Sh_100mm_MP_Pen_T_Y: RC_RHS_AFRF_Sh_100mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_RHS_AFRF_Sh_100mm_MP_DF_T_R: RC_RHS_AFRF_Sh_100mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_RHS_AFRF_Sh_100mm_MP_DF_Sub";
};
class RC_RHS_AFRF_Sh_100mm_MP_DF_T_G: RC_RHS_AFRF_Sh_100mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_Sh_100mm_MP_DF_T_Y: RC_RHS_AFRF_Sh_100mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_AFRF_Sh_100mm_MP_QF_T_R: RC_RHS_AFRF_Sh_100mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_AB_100mm";
};
class RC_RHS_AFRF_Sh_100mm_MP_QF_T_G: RC_RHS_AFRF_Sh_100mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_Sh_100mm_MP_QF_T_Y: RC_RHS_AFRF_Sh_100mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_RHS_AFRF_Sh_100mm_MPAB_DF_T_R: RC_RHS_AFRF_Sh_100mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_MPAB_DF.hpp"
	submunitionAmmo="RC_RHS_AFRF_Sh_100mm_MP_DF_Sub";
};
class RC_RHS_AFRF_Sh_100mm_MPAB_DF_T_G: RC_RHS_AFRF_Sh_100mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_Sh_100mm_MPAB_DF_T_Y: RC_RHS_AFRF_Sh_100mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//30mm
class rhs_ammo_3ubr11;
class RC_RHS_AFRF_B_30mm_APFSDS_T_R: rhs_ammo_3ubr11
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=4;

	hit=120;
	indirectHit=8;
	indirectHitRange=0.2;
	caliber=6;
	deflecting=15;
	airFriction=-9.9999997e-005;
	typicalSpeed=1320;
};
class RC_RHS_AFRF_B_30mm_APFSDS_T_G: RC_RHS_AFRF_B_30mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_B_30mm_APFSDS_T_Y: RC_RHS_AFRF_B_30mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class rhs_ammo_3uof8;
class RC_RHS_AFRF_B_30mm_MP_Base: rhs_ammo_3uof8
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";

	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_30mm.hpp"
};
class RC_RHS_AFRF_B_30mm_MP_DF_Sub: RC_RHS_AFRF_B_30mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_AB_30mm";
	caliber=4.3;
};


class RC_RHS_AFRF_B_30mm_MP_Pen_T_R: RC_RHS_AFRF_B_30mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_Pen.hpp"
};
class RC_RHS_AFRF_B_30mm_MP_Pen_T_G: RC_RHS_AFRF_B_30mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_B_30mm_MP_Pen_T_Y: RC_RHS_AFRF_B_30mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_RHS_AFRF_B_30mm_MP_DF_T_R: RC_RHS_AFRF_B_30mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_RHS_AFRF_B_30mm_MP_DF_Sub";
};
class RC_RHS_AFRF_B_30mm_MP_DF_T_G: RC_RHS_AFRF_B_30mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_B_30mm_MP_DF_T_Y: RC_RHS_AFRF_B_30mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_RHS_AFRF_B_30mm_MP_QF_T_R: RC_RHS_AFRF_B_30mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_AB_30mm";
};
class RC_RHS_AFRF_B_30mm_MP_QF_T_G: RC_RHS_AFRF_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_B_30mm_MP_QF_T_Y: RC_RHS_AFRF_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_RHS_AFRF_B_30mm_MPAB_DF_T_R: RC_RHS_AFRF_B_30mm_MP_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_RHS_AFRF_B_30mm_MP_DF_Sub";
};
class RC_RHS_AFRF_B_30mm_MPAB_DF_T_G: RC_RHS_AFRF_B_30mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_RHS_AFRF_B_30mm_MPAB_DF_T_Y: RC_RHS_AFRF_B_30mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


/*
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
*/


/*
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
*/