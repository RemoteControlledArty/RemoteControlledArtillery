//light guided
class RC_PylonM_12Rnd_APKWS;
class RC_RHS_PylonM_7Rnd_APKWS: RC_PylonM_12Rnd_APKWS
{
	displayName="> APKWS LG 7x [ACE RHS]";
	model="\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_r_FFAR_7x";
	ammo="RC_RHS_APKWS";
	count=7;
	hardpoints[]={"RC_Hardpoint_V5"};
};


/*
//light SACLOS/lock guided
class rhs_mag_DAGR_8;
class RC_PylonM_8Rnd_DAGR: rhs_mag_DAGR_8
{
	displayName="> DAGR M310 8x";
	displayNameShort="DAGR";
	descriptionShort="SACLOS / lock - guided missiles";
	pylonWeapon="RC_PylonW_DAGR";
	ammo="RC_RHS_DAGR";
	hardpoints[]={"RC_Hardpoint_V6"};
};
class RC_PylonM_8Rnd_S8_G: RC_PylonM_8Rnd_DAGR
{
	displayName="> S-8 G 8x";
	displayNameShort="S-8 G";
	descriptionShort="SACLOS / lock - guided missiles";
	pylonWeapon="RC_PylonW_S8_G";
	ammo="RC_DAGR";
	hardpoints[]={"RC_Hardpoint_O_V6"};
};
*/


//heavy guided
class PylonRack_1Rnd_LG_scalpel;
class RC_PylonM_1Rnd_AGM114K: PylonRack_1Rnd_LG_scalpel
{
	displayName="> AGM-114K Hellfire II 1x [ACE RHS]";
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


class rhs_mag_AGM114K_2;
class RC_PylonM_2Rnd_AGM114K: rhs_mag_AGM114K_2
{
	displayName="> AGM-114K Hellfire II 2x [ACE RHS]";
	displayNameShort="AGM-114K";
	descriptionShort="heavy missiles with ACE laser guidance";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	hardpoints[]={"RC_Hardpoint_V5"};
};
class RC_PylonM_2Rnd_Vikhr: RC_PylonM_2Rnd_AGM114K
{
	displayName="> 9K121 Vikhr 2x [ACE RHS]";
	displayNameShort="9K121 Vikhr";
	pylonWeapon="RC_PylonW_Vikhr";
	ammo="RC_Vikhr";
	hardpoints[]={"RC_Hardpoint_O_V5_ACE"};
};


class PylonRack_3Rnd_LG_scalpel;
class RC_PylonM_3Rnd_AGM114K: PylonRack_3Rnd_LG_scalpel
{
	displayName="> AGM-114K Hellfire II 3x [ACE RHS]";
	displayNameShort="AGM-114K";
	descriptionShort="heavy missiles with ACE laser guidance";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	count=3;
	mass=300;		//300
	weight=400;		//400
	hardpoints[]={"RC_Hardpoint_V6"};
};


class PylonRack_4Rnd_LG_scalpel;
class RC_PylonM_4Rnd_AGM114K: PylonRack_4Rnd_LG_scalpel
{
	displayName="> AGM-114K Hellfire II 4x [ACE RHS]";
	displayNameShort="AGM-114K";
	descriptionShort="heavy missiles with ACE laser guidance";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	mass=370;	//370
	weight=400;	//400
	hardpoints[]={"RC_Hardpoint_V6"};
};