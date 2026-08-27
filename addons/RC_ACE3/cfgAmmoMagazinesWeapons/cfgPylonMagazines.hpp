//light guided
class RC_PylonM_12Rnd_APKWS;
class RC_ACE_PylonM_12Rnd_APKWS: RC_PylonM_12Rnd_APKWS
{
	displayName="> APKWS LG 12x [ACE]";
    pylonWeapon="RC_ACE_PylonW_APKWS";
	ammo="RC_ACE_APKWS";
};


//class PylonRack_12Rnd_PG_missiles;
class PylonRack_12Rnd_PGM_missiles_black;
class RC_PylonM_12Rnd_APKWS: PylonRack_12Rnd_PGM_missiles_black
{
	displayName="> APKWS LG 12x";
    displayNameShort="APKWS LG";
	descriptionShort="laser guided missiles";
    pylonWeapon="RC_PylonW_APKWS";
	ammo="RC_APKWS";
	hardpoints[]={"RC_Hardpoint_V6"};
};
/*
class RC_PylonM_12Rnd_APKWS_Proxy: PylonRack_12Rnd_PG_missiles
{
	scope=1;
	displayName="> APKWS LG Proxy 12x";
    displayNameShort="APKWS LG Proxy";
	descriptionShort="laser guided proximity fuze missiles";
    pylonWeapon="RC_PylonW_APKWS_Proxy";
	ammo="RC_APKWS_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/
class RC_PylonM_12Rnd_S8_LG: RC_PylonM_12Rnd_APKWS
{
	displayName="> S-8 LG 12x";
    displayNameShort="S-8 LG";
	descriptionShort="laser guided missiles";
    pylonWeapon="RC_PylonW_S8_LG";
	hardpoints[]={"RC_Hardpoint_O_V6"};
};
/*
class RC_PylonM_12Rnd_S8_LG_Proxy: RC_PylonM_12Rnd_S8_LG
{
	scope=1;
	displayName="> S-8 LG Proxy 12x";
    displayNameShort="S-8 LG Proxy";
	descriptionShort="laser guided proximity fuze missiles";
    pylonWeapon="RC_PylonW_S8_LG_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/


//heavy guided
class 12Rnd_PG_missiles;
class RC_PylonM_1Rnd_AGM114K: 12Rnd_PG_missiles
{
	displayName="> AGM-114K Hellfire II 1x";
	displayNameShort="AGM-114K";
	descriptionShort="heavy laser guided missile";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	count=1;

	model="\A3\Weapons_F\DynamicLoadout\PylonPod_1x_Missile_AA_04_F.p3d";
	mass=85;
	/*
	model="\A3\Weapons_F\DynamicLoadout\PylonMissile_1x_Bomb_04_F.p3d";
	mass=70;
	*/
	hardpoints[]={"RC_Hardpoint_V5"};
};
/*
class RC_PylonM_1Rnd_AGM114K_Proxy: RC_PylonM_1Rnd_AGM114K
{
	scope=1;
	displayName="> AGM-114K Hellfire II Proxy 1x";
	displayNameShort="AGM-114K Proxy";
	descriptionShort="heavy laser guided proximity fuze missile";
	pylonWeapon="RC_PylonW_Hellfire_Proxy";
	ammo="RC_AGM114K_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/


class RC_PylonM_3Rnd_AGM114K: RC_PylonM_1Rnd_AGM114K
{
	displayName="> AGM-114K Hellfire II 3x";
	count=3;
	model="\A3\Weapons_F\DynamicLoadout\PylonPod_3x_Missile_LG_scalpel_F.p3d";
	mass=300;
	hardpoints[]={"RC_Hardpoint_V6","OM_H_I"};
};
/*
class RC_PylonM_3Rnd_AGM114K_Proxy: RC_PylonM_3Rnd_AGM114K
{
	scope=1;
	displayName="> AGM-114K Hellfire II Proxy 3x";
	displayNameShort="AGM-114K Proxy";
	descriptionShort="heavy laser guided proximity fuze missile";
	pylonWeapon="RC_PylonW_Hellfire_Proxy";
	ammo="RC_AGM114K_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/


class RC_PylonM_1Rnd_Vikhr: RC_PylonM_1Rnd_AGM114K
{
	displayName="> 9K121 Vikhr 1x";
	displayNameShort="9K121 Vikhr";
	descriptionShort="heavy laser guided missile";
	pylonWeapon="RC_PylonW_Vikhr";
	ammo="RC_AGM114K";
	hardpoints[]={"RC_Hardpoint_O_V5"};
};
/*
class RC_PylonM_1Rnd_Vikhr_Proxy: RC_PylonM_1Rnd_Vikhr
{
	scope=1;
	displayName="> 9K121 Vikhr Proxy 1x";
	displayNameShort="9K121 Vikhr Proxy";
	descriptionShort="heavy laser guided proximity fuze missile";
	pylonWeapon="RC_PylonW_Vikhr_Proxy";
	ammo="RC_AGM114K_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/


//PylonRack_3Rnd_LG_scalpel
class RC_PylonM_3Rnd_Vikhr: RC_PylonM_1Rnd_Vikhr
{
	displayName="> 9K121 Vikhr 3x";
	descriptionShort="heavy laser guided missiles";
	ammo="RC_AGM114K";
	count=3;

	model="\A3\Weapons_F\DynamicLoadout\PylonPod_3x_Missile_LG_scalpel_F.p3d";
	mass=300;

	hardpoints[]={"RC_Hardpoint_O_V6"};
};
/*
class RC_PylonM_3Rnd_Vikhr_Proxy: RC_PylonM_1Rnd_Vikhr
{
	scope=1;
	displayName="> 9K121 Vikhr Proxy 3x";
	displayNameShort="9K121 Vikhr Proxy";
	descriptionShort="heavy laser guided proximity fuze missile";
	pylonWeapon="RC_PylonW_Vikhr_Proxy";
	ammo="RC_AGM114K_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/
