class PylonWeapon_300Rnd_20mm_shells;
class RC_PylonWeapon_shells_slow_base: PylonWeapon_300Rnd_20mm_shells
{
	//ADD SCOPE 0
	//INCREASE REARM COST

	author="Ascent";
	model="\A3\Weapons_F\DynamicLoadout\PylonPod_Twin_Cannon_20mm.p3d";

	hardpoints[]=
	{
		"OM_H",

		//*
		"B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","20MM_CANNON",
		
		"DAGR","DAR","B_MISSILE_PYLON",

		"GX_HELI_SMALL",

		"UNI_LEAFLETS_PYLON"
		//*/
	};

	/*Moin, ich bin auf eure tolle Webseite gestoßen und mich sehr gefragt woher denn die schicke Maschinenkanone am AH-6M ist die auf der Webseite im Bereich "Rotary Wing" "AH-6M MELB" auf dem Bild zu sehen ist? :exploding_head: Finde es leider nirgends sonnst.
	Weiß das jemand / weiß jemand wer es von euch wissen könnte? Würde mich sehr freuen! :D*/

	muzzleImpulseFactor[]={0.0375,0.3};		//{0.1,0.8}
	//mass=230;
	tracersEvery=1;

	/*
	initSpeed=1030;
	maxLeadSpeed=83.333298;
	muzzleImpulseFactor[]={0.1,0.80000001};
	*/

	/*
	descriptionShort="$STR_A3_cfgMagazine_PL20_tooltip";
	model="\A3\Weapons_F\DynamicLoadout\PylonPod_Twin_Cannon_20mm.p3d";
	muzzlePos="muzzlePos";
	muzzleEnd="muzzleEnd";
	*/
};
class RC_PylonWeapon_300Rnd_20mm_shells_slow: RC_PylonWeapon_shells_slow_base
{
	displayName="20mm MP-DF";
	displayNameShort="20mm MP-DF";
	descriptionShort="20mm autocannon pod";
	//use airlock1 ones
	ammo="RC_B_20mm_MP_DF_T_R";
	pylonWeapon="RC_Twin_Cannon_gunpod_slow";
	//pylonWeapon="RC_Twin_Cannon_20mm_gunpod_slow";
	count=300;
};
class RC_PylonWeapon_200Rnd_25mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	displayName="25mm MPAB-DF";
	displayNameShort="25mm MPAB-DF";
	descriptionShort="25mm autocannon pod";
	pylonWeapon="RC_Twin_Cannon_gunpod_slow";
	//pylonWeapon="RC_Twin_Cannon_25mm_gunpod_slow";
	ammo="RC_B_25mm_MPAB_DF_T_R";
	count=200;
};
class RC_PylonWeapon_150Rnd_30mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	displayName="30mm MPAB-DF";
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
	displayName="70mm Hydra";
	displayNameShort="70mm Hydra";
	descriptionShort="12x 70mm Hydra Pod";
	pylonWeapon="RC_Pylon_12Rnd_70mm_Hydra_RocketPod";
	ammo="M_AT";

	hardpoints[]=
	{
		"OM_H",

		//*
		"B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","20MM_CANNON",
		
		"DAGR","DAR","B_MISSILE_PYLON",

		"GX_HELI_SMALL",

		"UNI_LEAFLETS_PYLON"
		//*/
	};
};
/*
class PylonRack_19Rnd_Rocket_Skyfire;
class RC_PylonRack_19Rnd_Rocket_Skyfire: PylonRack_19Rnd_Rocket_Skyfire
{
	//INCREASE REARM COST
	
	author="Ascent";
	hardpoints[]=
	{
		"OM_H"
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