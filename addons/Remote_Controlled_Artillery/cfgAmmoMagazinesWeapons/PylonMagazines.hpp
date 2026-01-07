class PylonWeapon_300Rnd_20mm_shells;
class RC_PylonWeapon_shells_slow_base: PylonWeapon_300Rnd_20mm_shells
{
	//ADD SCOPE 0
	//INCREASE REARM COST
	scope=0;
	author="Ascent";
	muzzleImpulseFactor[]={0.0375,0.3};		//{0.1,0.8}
	tracersEvery=1;

	hardpoints[]=
	{
		"OM_H"

		/*
		"B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","20MM_CANNON",
		"DAGR","DAR","B_MISSILE_PYLON",
		"GX_HELI_SMALL",
		"UNI_LEAFLETS_PYLON"
		/*/
	};

	/*
	mass=230;
	initSpeed=1030;
	maxLeadSpeed=83.333298;
	model="\A3\Weapons_F\DynamicLoadout\PylonPod_Twin_Cannon_20mm.p3d";
	muzzlePos="muzzlePos";
	muzzleEnd="muzzleEnd";
	*/
};
class RC_PylonWeapon_300Rnd_20mm_shells_slow: RC_PylonWeapon_shells_slow_base
{
	scope=2;
	displayName="'20mm MP-QF";
	displayNameShort="20mm MP-QF";
	descriptionShort="20mm autocannon pod";
	//use airlock1 ones
	ammo="RC_B_20mm_MP_QF_T_R";
	pylonWeapon="RC_Twin_Cannon_gunpod_slow";
	//pylonWeapon="RC_Twin_Cannon_20mm_gunpod_slow";
	count=300;
};
class RC_PylonWeapon_200Rnd_25mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	scope=2;
	displayName="'25mm MPAB-DF";
	displayNameShort="25mm MPAB-DF";
	descriptionShort="25mm autocannon pod";
	pylonWeapon="RC_Twin_Cannon_gunpod_slow";
	//pylonWeapon="RC_Twin_Cannon_25mm_gunpod_slow";
	ammo="RC_B_25mm_MPAB_DF_T_R";
	count=200;
};
class RC_PylonWeapon_150Rnd_30mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	scope=2;
	displayName="'30mm MPAB-DF";
	displayNameShort="30mm MPAB-DF";
	descriptionShort="30mm autocannon pod";
	pylonWeapon="RC_Twin_Cannon_gunpod_slow";
	//pylonWeapon="RC_Twin_Cannon_30mm_gunpod_slow";
	ammo="RC_B_30mm_MPAB_DF_T_R";
	count=150;
};
/*
class RC_PylonWeapon_300Rnd_20mm_shells_slow_Aegis: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	//magazines[] = {"PylonWeapon_250Rnd_20mm_shells"};
	//model="\A3_Aegis\Weapons_F_Aegis\DynamicLoadout\PylonPod_Cannon_20mm.p3d";
	//pylonWeapon="cannon_20mm_Heli_Light_03";
};
*/
class PylonRack_12Rnd_missiles;
class RC_PylonRack_12Rnd_70mm_Hydra: PylonRack_12Rnd_missiles
{
	//INCREASE REARM COST
	
	author="Ascent";
	displayName="'12x 70mm Hydra";
	displayNameShort="70mm Hydra";
	descriptionShort="12x 70mm Hydra Pod";
	pylonWeapon="RC_Pylon_12Rnd_70mm_Hydra_RocketPod";
	ammo="M_AT";

	hardpoints[]=
	{
		"OM_H"

		/*
		"B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","20MM_CANNON",
		"DAGR","DAR","B_MISSILE_PYLON",
		"GX_HELI_SMALL",
		"UNI_LEAFLETS_PYLON"
		/*/
	};
};
class PylonRack_12Rnd_PG_missiles;
class RC_PylonRack_12Rnd_APKWS: PylonRack_12Rnd_PG_missiles
{
	displayName="12x APKWS LG";
    displayNameShort="APKWS LG";
    ammo="RC_APKWS";
    pylonWeapon="RC_Pylon_12Rnd_APKWS_RocketPod";
	hardpoints[]={"OM_H"};
};
/*
class PylonRack_19Rnd_Rocket_Skyfire;
class RC_PylonRack_19Rnd_Rocket_Skyfire: PylonRack_19Rnd_Rocket_Skyfire
{
	//INCREASE REARM COST
	
	author="Ascent";
	hardpoints[]=
	{
		"OM_H",

		"B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","20MM_CANNON",
		"DAGR","DAR","B_MISSILE_PYLON",
		"GX_HELI_SMALL",
		"UNI_LEAFLETS_PYLON"
	};
	//displayName="70mm Hydra";
	//displayNameShort="70mm Hydra";
	//descriptionShort="12x 70mm Hydra Pod";
	//pylonWeapon="RC_Pylon_12Rnd_70mm_Hydra_RocketPod";
	pylonWeapon="rockets_Skyfire";
	//ammo="R_80mm_HE";
	//initSpeed=44;
	//maxLeadSpeed=41.666698;
};
*/