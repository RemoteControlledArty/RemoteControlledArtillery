class RC_Sh_60mm_AMOS_submunition;
class RC_ULM_Sh_60mm_AMOS_submunition: RC_Sh_60mm_AMOS_submunition
{
	explosionEffects="RC_ULM_MortarExplosion";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
};
class RC_Sh_60mm_AMOS_HEAB;
class RC_ULM_Sh_60mm_AMOS_HEAB: RC_Sh_60mm_AMOS_HEAB
{
	submunitionAmmo="RC_ULM_Sh_60mm_AMOS_submunition";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	fuseDistance=3;
};
class RC_Sh_60mm_AMOS_HE;
class RC_ULM_Sh_60mm_AMOS_HE: RC_Sh_60mm_AMOS_HE
{
	submunitionAmmo="RC_ULM_Sh_60mm_AMOS_submunition";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	fuseDistance=3;
};
class RC_Sh_60mm_AMOS_backupHEAB;
class RC_ULM_Sh_60mm_AMOS_backupHEAB: RC_Sh_60mm_AMOS_backupHEAB
{
	submunitionAmmo="RC_ULM_Sh_60mm_AMOS_submunition";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	fuseDistance=3;
};


class SmokeShellArty;
class RC_ULM_Sh_60mm_AMOS_Smoke_Sub: SmokeShellArty
{
	deflecting=0;
	explosionTime=0.2;
	timeToLive=180;
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	effectsSmoke="TWC_2inch_WP";
	ExplosionEffects="TWC_2inch_WP";
};
class Smoke_82mm_AMOS_White;
class RC_ULM_Sh_60mm_AMOS_Smoke: Smoke_82mm_AMOS_White
{
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	effectsSmoke="TWC_2inch_WP";
	ExplosionEffects="TWC_2inch_WP";
	submunitionAmmo="RC_ULM_Sh_60mm_AMOS_Smoke_Sub";
	fuseDistance=3;

	laserLock=1;
	irLock=1;
	//airLock=1;
};


class RC_60mm_MP_MultiGuided_Submunition;
class RC_ULM_60mm_MP_MultiGuided_Submunition: RC_60mm_MP_MultiGuided_Submunition
{
	explosionEffects="RC_ULM_MortarExplosion";
	submunitionAmmo="ammo_Penetrator_60mm_MP";
};
class RC_Sh_60mm_AMOS_MP_MultiGuided;
class RC_ULM_Sh_60mm_AMOS_MP_MultiGuided: RC_Sh_60mm_AMOS_MP_MultiGuided
{
	submunitionAmmo="RC_ULM_60mm_MP_MultiGuided_Submunition";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	fuseDistance=3;
};
class RC_60mm_MP_LaserGuided_Submunition;
class RC_ULM_60mm_MP_LaserGuided_Submunition: RC_60mm_MP_LaserGuided_Submunition
{
	explosionEffects="RC_ULM_MortarExplosion";
	submunitionAmmo="ammo_Penetrator_60mm_MP_Test";
};
class RC_Sh_60mm_AMOS_MP_LaserGuided;
class RC_ULM_Sh_60mm_AMOS_MP_LaserGuided: RC_Sh_60mm_AMOS_MP_LaserGuided
{
	submunitionAmmo="RC_ULM_60mm_MP_LaserGuided_Submunition";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	fuseDistance=3;
};
class RC_Sh_60mm_AMOS_delayed_submunition;
class RC_ULM_Sh_60mm_AMOS_delayed_submunition: RC_Sh_60mm_AMOS_delayed_submunition
{
	explosionEffects="RC_ULM_MortarExplosion";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
};
class RC_M_Mo_60mm_LG_DelayedFuse_Submunition;
class RC_ULM_M_Mo_60mm_LG_DelayedFuse_Submunition: RC_M_Mo_60mm_LG_DelayedFuse_Submunition
{
	submunitionAmmo="RC_ULM_Sh_60mm_AMOS_delayed_submunition";
};
class RC_Sh_60mm_AMOS_LG_DelayedFuse;
class RC_ULM_Sh_60mm_AMOS_LG_DelayedFuse: RC_Sh_60mm_AMOS_LG_DelayedFuse
{
	submunitionAmmo="RC_ULM_M_Mo_60mm_LG_DelayedFuse_Submunition";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	fuseDistance=3;
};


class APERSBoundingMine_Range_Ammo;
class RC_ULM_APERSBoundingMine_Range_Ammo: APERSBoundingMine_Range_Ammo
{
	mineBoundingDist=3;
	mineTrigger="RC_ULM_RangeTriggerBounding";
};
class ShotDeployBase;
class RC_ULM_Sh_60mm_AMOS_AP_Mine: ShotDeployBase
{
	aiAmmoUsageFlags=16;
	submunitionAmmo="RC_ULM_APERSBoundingMine_Range_Ammo";
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	airFriction=0;
	fuseDistance=3;

	laserLock=1;
	irLock=1;
	//airLock=1;
};
class Flare_82mm_AMOS_White;
class RC_ULM_Sh_60mm_AMOS_Illum: Flare_82mm_AMOS_White
{
	model="\twc_2inch\twc_2inch_shell_illum.p3d";
	timeToLive=120;
	fuseDistance=3;
	brightness=4;

	aimAboveDefault=2;
	aimAboveTarget[]={300,300,300};
};


/*
class Sh_82mm_AMOS;
class Flare_82mm_AMOS_White;
class Smoke_82mm_AMOS_White;
class SmokeShellArty;
class twc_2inch_he: Sh_82mm_AMOS
{
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	hit=90;
	indirectHit=40;
	indirectHitRange=16;
	fuseDistance=3;
};
class twc_2inch_smoke_submunition: SmokeShellArty
{
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	effectsSmoke="TWC_2inch_WP";
	ExplosionEffects="TWC_2inch_WP";
};
class twc_2inch_smoke: Smoke_82mm_AMOS_White
{
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	effectsSmoke="TWC_2inch_WP";
	ExplosionEffects="TWC_2inch_WP";
	fuseDistance=3;
	submunitionAmmo="twc_2inch_smoke_submunition";
};
class twc_2inch_illum: Flare_82mm_AMOS_White
{
	model="\twc_2inch\twc_2inch_shell_illum.p3d";
	timeToLive=60;
	fuseDistance=3;
	brightness=4;
};
*/