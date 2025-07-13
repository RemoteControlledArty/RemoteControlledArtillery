class RC_1Rnd_60mm_vic_Mo_shells;
class RC_ULM_1Rnd_60mm_Mo_shells: RC_1Rnd_60mm_vic_Mo_shells
{
	//ammo="RC_Sh_60mm_AMOS_HE";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	picture="\twc_2inch\data\ui\m_he_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_HEAB;
class RC_ULM_1Rnd_60mm_Mo_HEAB: RC_1Rnd_60mm_vic_Mo_HEAB
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	picture="\twc_2inch\data\ui\m_he_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_backupHEAB;
class RC_ULM_1Rnd_60mm_Mo_backupHEAB: RC_1Rnd_60mm_vic_Mo_backupHEAB
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	picture="\twc_2inch\data\ui\m_he_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_Smoke_white;
class RC_ULM_1Rnd_60mm_Mo_Smoke: RC_1Rnd_60mm_vic_Mo_Smoke_white
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_LaserGuided;
class RC_ULM_1Rnd_60mm_Mo_LaserGuided: RC_1Rnd_60mm_vic_Mo_LaserGuided
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	picture="\twc_2inch\data\ui\m_he_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_MultiGuided;
class RC_ULM_1Rnd_60mm_Mo_MultiGuided: RC_1Rnd_60mm_vic_Mo_MultiGuided
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	picture="\twc_2inch\data\ui\m_he_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_mine;
class RC_ULM_1Rnd_60mm_Mo_mine: RC_1Rnd_60mm_vic_Mo_mine
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_LG_DelayedFuse;
class RC_ULM_1Rnd_60mm_Mo_LG_DelayedFuse: RC_1Rnd_60mm_vic_Mo_LG_DelayedFuse
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	picture="\twc_2inch\data\ui\m_he_ca.paa";
};
class RC_1Rnd_60mm_vic_Mo_Flare_white;
class RC_ULM_1Rnd_60mm_Mo_Illum: RC_1Rnd_60mm_vic_Mo_Flare_white
{
	//ammo="RC_Sh_60mm_AMOS_HEAB";
	#include "\RC_60mmULM\includes_cfg\magValues.hpp"
	model="\twc_2inch\twc_2inch_shell_illum.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
};


/*
class VehicleMagazine;
class RC_10Rnd_R_HEAB_Base: VehicleMagazine
{
	scope=2;
	displayNameMFDFormat="HE";
	nameSound="heat";
	author="$STR_A3_Bohemia_Interactive";
	displayName="$STR_A3_cfgmagazines_8rnd_82mm_mo_shells0";
	displayNameShort="$STR_A3_cfgmagazines_8rnd_82mm_mo_shells_dns";
	count=10;
	ammo="Sh_82mm_AMOS";
	muzzleImpulseFactor[]={0,0};
	initSpeed=200;
};
class RC_10Rnd_R_HEAB: RC_10Rnd_R_HEAB_Base
{
	ammo="RC_Sh_82mm_AMOS_HEAB";
	RC_AimAboveHeight=12.7;		//airburstheight
	RC_AdvisedTrajectory=2;	//1low, 2high, 3both
	displayName="HE Airburst 12m";
	displayNameShort="HE Airburst 12m";
	count=10;
};
*/


/*
class 8Rnd_82mm_Mo_shells;
class 8Rnd_82mm_Mo_Smoke_white;
class 8Rnd_82mm_Mo_Flare_white;
class twc_2inch_he_1rnd: 8Rnd_82mm_Mo_shells
{
	displayname="60mm COMMANDO 1Rnd HE";
	DLC="twc_config";
	count=1;
	ammo="twc_2inch_he";
	scope=2;
	scopeCurator=2;
	weaponPoolAvailable=1;
	author="LeoVetta";
	displayNameShort="HE";
	descriptionShort="HE round for the 60mm COMMANDO Mortar";
	model="\twc_2inch\twc_2inch_shell_he.p3d";
	picture="\twc_2inch\data\ui\m_he_ca.paa";
	mass=5;
	type=256;
	initSpeed=80;
};
class twc_2inch_smoke_1rnd: 8Rnd_82mm_Mo_Smoke_white
{
	displayname="60mm COMMANDO 1Rnd Smoke";
	DLC="twc_config";
	count=1;
	ammo="twc_2inch_smoke";
	scope=2;
	scopeCurator=2;
	weaponPoolAvailable=1;
	author="LeoVetta";
	displayNameShort="Smoke";
	descriptionShort="Smoke round for the 60mm COMMANDO Mortar";
	model="\twc_2inch\twc_2inch_shell_smoke.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
	mass=5;
	type=256;
	initSpeed=80;
};
class twc_2inch_illum_1rnd: 8Rnd_82mm_Mo_Flare_white
{
	displayname="60mm COMMANDO 1Rnd Illum";
	DLC="twc_config";
	count=1;
	ammo="twc_2inch_illum";
	scope=2;
	scopeCurator=2;
	weaponPoolAvailable=1;
	author="LeoVetta";
	displayNameShort="Illum";
	descriptionShort="Illum round for the 60mm COMMANDO Mortar";
	model="\twc_2inch\twc_2inch_shell_illum.p3d";
	picture="\twc_2inch\data\ui\m_smoke_ca.paa";
	mass=5;
	type=256;
	initSpeed=80;
};
*/