class RC_1Rnd_82mm_Mo_shells;
class RC_ULM_1Rnd_82mm_Mo_shells: RC_1Rnd_82mm_Mo_shells
{
	displayName="82mm HE";
	ammo="RC_Sh_82mm_AMOS_HE";
	#include "\RC_82mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_82mm_Mo_HEAB;
class RC_ULM_1Rnd_82mm_Mo_HEAB: RC_1Rnd_82mm_Mo_HEAB
{
	displayName="82mm HE Airburst 12m";
	#include "\RC_82mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_82mm_Mo_Smoke_white;
class RC_ULM_1Rnd_82mm_Mo_Smoke: RC_1Rnd_82mm_Mo_Smoke_white
{
	displayName="82mm Smoke";
	#include "\RC_82mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};


class RC_1Rnd_82mm_Mo_MultiGuided;
class RC_ULM_1Rnd_82mm_Mo_MultiGuided: RC_1Rnd_82mm_Mo_MultiGuided
{
	displayName="82mm MP Guided";
	#include "\RC_82mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_82mm_Mo_LaserGuided;
class RC_ULM_1Rnd_82mm_Mo_LaserGuided: RC_1Rnd_82mm_Mo_LaserGuided
{
	displayName="82mm MP Laser Guided";
	#include "\RC_82mmULM\includes_cfg\magValues_Exp.hpp"
};
class RC_1Rnd_82mm_Mo_LG_DelayedFuse;
class RC_ULM_1Rnd_82mm_Mo_LG_DelayedFuse: RC_1Rnd_82mm_Mo_LG_DelayedFuse
{
	displayName="82mm LG 2m Delayed";
	#include "\RC_82mmULM\includes_cfg\magValues_Exp.hpp"
};
/*
class RC_ULM_1Rnd_MP_NLOS_Nano: RC_1Rnd_82mm_Mo_MultiGuided
{
	ammo="RC_MP_NLOS_Nano";
	displayName="82mm Nano NLOS 4km";
	displayNameShort="Nano NLOS";
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	#include "\RC_82mmULM\includes_cfg\magValues_Exp.hpp"
};
*/


class RC_1Rnd_82mm_Mo_mine;
class RC_ULM_1Rnd_82mm_Mo_mine: RC_1Rnd_82mm_Mo_mine
{
	displayName="82mm AP Mines";
	#include "\RC_82mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};
class RC_1Rnd_82mm_Mo_AT_mine;
class RC_ULM_1Rnd_82mm_Mo_AT_mine: RC_1Rnd_82mm_Mo_AT_mine
{
	displayName="82mm AT Mines";
	#include "\RC_82mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};
class RC_1Rnd_82mm_Mo_Flare_white;
class RC_ULM_1Rnd_82mm_Mo_Illum: RC_1Rnd_82mm_Mo_Flare_white
{
	displayName="82mm Illumination";
	#include "\RC_82mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_illum.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};