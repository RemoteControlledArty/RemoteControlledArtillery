//light guided
class PylonRack_12Rnd_PGM_missiles_black;
class RC_PylonM_12Rnd_APKWS: PylonRack_12Rnd_PGM_missiles_black
{
	displayName="> APKWS LG 12x [ACE]";
    displayNameShort="APKWS LG";
	descriptionShort="missiles with ACE laser guidance";
    pylonWeapon="RC_PylonW_APKWS";
	ammo="RC_APKWS";
	hardpoints[]={"RC_Hardpoint_V6"};
};
class RC_PylonM_7Rnd_APKWS: RC_PylonM_12Rnd_APKWS
{
	displayName="> APKWS LG 7x [ACE]";
	hardpoints[]={"RC_Hardpoint_V5"};
};
/*
class RC_PylonM_12Rnd_APKWS_Proxy: PylonRack_12Rnd_PG_missiles
{
	scope=1;
	displayName="> APKWS LG Proxy 12x [ACE]";
    displayNameShort="APKWS LG Proxy";
	descriptionShort="proximity fuze missiles with ACE laser guidance";
    pylonWeapon="RC_PylonW_APKWS_Proxy";
	ammo="RC_APKWS_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/
class RC_PylonM_12Rnd_S8_LG: RC_PylonM_12Rnd_APKWS
{
	displayName="> S-8 LG 12x [ACE]";
    displayNameShort="S-8 LG";
	descriptionShort="missiles with ACE laser guidance";
    pylonWeapon="RC_PylonW_S8_LG";
	hardpoints[]={"RC_Hardpoint_O_V6"};
};
class RC_PylonM_7Rnd_S8_LG: RC_PylonM_12Rnd_S8_LG
{
	displayName="> S-8 LG 7x [ACE]";
	hardpoints[]={"RC_Hardpoint_O_V5"};
};
/*
class RC_PylonM_12Rnd_S8_LG_Proxy: RC_PylonM_12Rnd_S8_LG
{
	scope=1;
	displayName="> S-8 LG Proxy 12x [ACE]";
    displayNameShort="S-8 LG Proxy";
	descriptionShort="proximity fuze missiles with ACE laser guidance";
    pylonWeapon="RC_PylonW_S8_LG_Proxy";

	hardpoints[]={"OM_H_Proxy"};
};
*/


//heavy guided
class PylonRack_1Rnd_LG_scalpel;
class RC_PylonM_1Rnd_AGM114K: PylonRack_1Rnd_LG_scalpel
{
	displayName="> AGM-114K Hellfire II 1x [ACE]";
	displayNameShort="AGM-114K";
	descriptionShort="heavy missile with ACE laser guidance";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	count=1;

	model="\A3\Weapons_F\DynamicLoadout\PylonPod_1x_Missile_AA_04_F.p3d";
	//model="\A3\Weapons_F\DynamicLoadout\PylonMissile_1x_Bomb_04_F.p3d";
	//mass=85;		//85
	//weight=72;	//72
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

//vehicle player setPylonLoadout [1,"\A3\Weapons_F\DynamicLoadout\PylonPod_1x_Missile_LG_scalpel_F.p3d", true, [-1]];
//vehicle player setPylonLoadout [1,"\kj_oh76\Misc\Weapons\M299\M299x1h.p3d", true, [-1]];
//vehicle player setPylonLoadout [1,"PylonRack_1Rnd_LG_scalpel", true, [-1]];


/*
//which mod? \kj_oh76
class RC_PylonM_2Rnd_AGM114K: PylonRack_1Rnd_LG_scalpel
{
	displayName="> AGM-114K Hellfire II 2x";
	displayNameShort="AGM-114K";
	descriptionShort="heavy laser guided missile";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	count=2;

	model="\kj_oh76\Misc\Weapons\M299\M299x2.p3d";
	//mass=200;		//100
	//weight=100;	//45
	hardpoints[]={"RC_Hardpoint_V5"};
};
*/


class PylonRack_3Rnd_LG_scalpel;
class RC_PylonM_3Rnd_AGM114K: PylonRack_3Rnd_LG_scalpel
{
	displayName="> AGM-114K Hellfire II 3x [ACE]";
	displayNameShort="AGM-114K";
	descriptionShort="heavy missiles with ACE laser guidance";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	count=3;
	mass=300;		//300
	weight=400;		//400
	hardpoints[]={"RC_Hardpoint_V6"};
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


class PylonRack_4Rnd_LG_scalpel;
class RC_PylonM_4Rnd_AGM114K: PylonRack_4Rnd_LG_scalpel
{
	displayName="> AGM-114K Hellfire II 4x";
	displayNameShort="AGM-114K";
	descriptionShort="heavy laser guided missile";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	count=4;
	mass=370;	//370
	weight=400;	//400
	hardpoints[]={"RC_Hardpoint_V6"};
};


class RC_PylonM_1Rnd_Vikhr: RC_PylonM_1Rnd_AGM114K
{
	displayName="> 9K121 Vikhr 1x [ACE]";
	displayNameShort="9K121 Vikhr";
	pylonWeapon="RC_PylonW_Vikhr";
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


class RC_PylonM_3Rnd_Vikhr: RC_PylonM_3Rnd_AGM114K
{
	displayName="> 9K121 Vikhr 3x [ACE]";
	displayNameShort="9K121 Vikhr";
	pylonWeapon="RC_PylonW_Vikhr";
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


class RC_PylonM_4Rnd_Vikhr: RC_PylonM_4Rnd_AGM114K
{
	displayName="> 9K121 Vikhr 4x [ACE]";
	displayNameShort="9K121 Vikhr";
	pylonWeapon="RC_PylonW_Vikhr";
	hardpoints[]={"RC_Hardpoint_O_V6"};
};
