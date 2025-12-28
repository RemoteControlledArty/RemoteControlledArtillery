class PylonWeapon_300Rnd_20mm_shells;
class RC_PylonWeapon_shells_slow_base: PylonWeapon_300Rnd_20mm_shells
{
	author="Ascent";

	hardpoints[]=
	{
		"B_A143_BUZZARD_CENTER_PYLON",
		"20MM_TWIN_CANNON"
	};

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
	displayName="20mm MPAB-DF";
	displayNameShort="20mm MPAB-DF";
	//use airlock1 ones
	ammo="RC_B_20mm_MPAB_DF_T_R";
	pylonWeapon="RC_Twin_Cannon_20mm_gunpod_slow";
	count=300;
};
class RC_PylonWeapon_200Rnd_25mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	displayName="25mm MPAB-DF";
	displayNameShort="25mm MPAB-DF";
	pylonWeapon="RC_Twin_Cannon_25mm_gunpod_slow";
	ammo="RC_B_25mm_MPAB_DF_T_R";
	count=150;
};
class RC_PylonWeapon_150Rnd_30mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	displayName="30mm MPAB-DF";
	displayNameShort="30mm MPAB-DF";
	pylonWeapon="RC_Twin_Cannon_30mm_gunpod_slow";
	ammo="RC_B_30mm_MPAB_DF_T_R";
	count=150;
};


/*
class RC_PylonWeapon_150Rnd_30mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	displayName="30mm MPAB-DF";
	displayNameShort="30mm MPAB-DF";

	hardpoints[]=
	{
		"B_A143_BUZZARD_CENTER_PYLON",
		"20MM_TWIN_CANNON"
	};
	pylonWeapon="RC_Twin_SlowAutocannon_gunpod";

	ammo="RC_B_30mm_MP_DF_T_R";
};
*/