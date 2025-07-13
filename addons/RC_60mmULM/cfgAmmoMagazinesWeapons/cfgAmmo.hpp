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


//redefine smoke and mine for aimaboveheight