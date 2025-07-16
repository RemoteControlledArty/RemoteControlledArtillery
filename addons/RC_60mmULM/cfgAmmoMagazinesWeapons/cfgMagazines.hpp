class 8Rnd_82mm_Mo_shells;
class twc_2inch_he_1rnd: 8Rnd_82mm_Mo_shells
{
	scope=0;
	scopeCurator=0;
};
class 8Rnd_82mm_Mo_Smoke_white;
class twc_2inch_smoke_1rnd: 8Rnd_82mm_Mo_Smoke_white
{
	scope=0;
	scopeCurator=0;
};
class 8Rnd_82mm_Mo_Flare_white;
class twc_2inch_illum_1rnd: 8Rnd_82mm_Mo_Flare_white
{
	scope=0;
	scopeCurator=0;
};


class RC_1Rnd_60mm_vic_Mo_shells;
class RC_ULM_1Rnd_60mm_Mo_shells: RC_1Rnd_60mm_vic_Mo_shells
{
	displayName="60mm HE";
	ammo="RC_ULM_Sh_60mm_AMOS_HE";
	#include "\RC_60mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_60mm_vic_Mo_HEAB;
class RC_ULM_1Rnd_60mm_Mo_HEAB: RC_1Rnd_60mm_vic_Mo_HEAB
{
	displayName="60mm HE-AB 7m";
	ammo="RC_ULM_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_60mm_vic_Mo_backupHEAB;
class RC_ULM_1Rnd_60mm_Mo_backupHEAB: RC_1Rnd_60mm_vic_Mo_backupHEAB
{
	ammo="RC_ULM_Sh_60mm_AMOS_backupHEAB";
	#include "\RC_60mmULM\includes_cfg\magValues_Backup.hpp"
};
class RC_1Rnd_60mm_vic_Mo_Smoke_white;
class RC_ULM_1Rnd_60mm_Mo_Smoke: RC_1Rnd_60mm_vic_Mo_Smoke_white
{
	displayName="60mm Smoke";
	ammo="RC_ULM_Sh_60mm_AMOS_Smoke";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};


class RC_1Rnd_60mm_vic_Mo_MultiGuided;
class RC_ULM_1Rnd_60mm_Mo_MultiGuided: RC_1Rnd_60mm_vic_Mo_MultiGuided
{
	displayName="60mm MP Guided";
	ammo="RC_ULM_Sh_60mm_AMOS_MP_MultiGuided";
	RC_AimAboveHeight=270;
	#include "\RC_60mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_60mm_vic_Mo_LaserGuided;
class RC_ULM_1Rnd_60mm_Mo_LaserGuided: RC_1Rnd_60mm_vic_Mo_LaserGuided
{
	displayName="60mm MP Laser Guided";
	ammo="RC_ULM_Sh_60mm_AMOS_MP_LaserGuided";
	RC_AimAboveHeight=270;
	#include "\RC_60mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_60mm_vic_Mo_LG_DelayedFuse;
class RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse: RC_1Rnd_60mm_vic_Mo_LG_DelayedFuse
{
	displayName="60mm LG 2m Delayed";
	ammo="RC_ULM_Sh_60mm_AMOS_LG_DelayedFuse";
	RC_AimAboveHeight=270;
	#include "\RC_60mmULM\includes_cfg\magValues_Exp.hpp"
};
/*
class RC_ULM_1Rnd_MP_NLOS_Nano: RC_1Rnd_60mm_vic_Mo_MultiGuided
{
	ammo="RC_MP_NLOS_Nano";
	displayName="60mm Nano NLOS 4km";
	displayNameShort="Nano NLOS";
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	#include "\RC_60mmULM\includes_cfg\magValues_Exp.hpp"
};
*/


class RC_1Rnd_60mm_vic_Mo_mine;
class RC_ULM_1Rnd_60mm_Mo_mine: RC_1Rnd_60mm_vic_Mo_mine
{
	displayName="60mm Bounding Mine";
	ammo="RC_ULM_Sh_60mm_AMOS_AP_Mine";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_Flare_white;
class RC_ULM_1Rnd_60mm_Mo_Illum: RC_1Rnd_60mm_vic_Mo_Flare_white
{
	displayName="60mm Illumination";
	ammo="RC_ULM_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_illum.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};