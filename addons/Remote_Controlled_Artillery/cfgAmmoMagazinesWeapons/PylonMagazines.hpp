class PylonWeapon_300Rnd_20mm_shells;
class RC_PylonWeapon_300Rnd_20mm_shells_slow: PylonWeapon_300Rnd_20mm_shells
{
	author="Ascent";
	/*
	displayName="20mm MP-DF";
	displayNameShort="20mm MP-DF";
	*/
	//*
	//use airlock1 ones
	displayName="20mm MPAB-DF";
	displayNameShort="20mm MPAB-DF";
	/*/

	pylonWeapon="RC_Twin_Cannon_20mm_gunpod_slow";
	hardpoints[]=
	{
		"B_A143_BUZZARD_CENTER_PYLON",
		"20MM_TWIN_CANNON"
	};
	
	//mass=230;
	tracersEvery=1;
	count=300;

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
class RC_PylonWeapon_200Rnd_25mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	displayName="25mm MP-DF";
	displayNameShort="25mm MP-DF";
	
	hardpoints[]=
	{
		"B_A143_BUZZARD_CENTER_PYLON",
		"20MM_TWIN_CANNON"
	};
	pylonWeapon="RC_Twin_Cannon_25mm_gunpod_slow";

	ammo="RC_B_25m_MP_DF_T_R";
	count=150;
};
class RC_PylonWeapon_150Rnd_30mm_shells_slow: RC_PylonWeapon_300Rnd_20mm_shells_slow
{
	displayName="30mm MP-DF";
	displayNameShort="30mm MP-DF";

	hardpoints[]=
	{
		"B_A143_BUZZARD_CENTER_PYLON",
		"20MM_TWIN_CANNON"
	};
	pylonWeapon="RC_Twin_Cannon_30mm_gunpod_slow";

	ammo="RC_B_30mm_MP_DF_T_R";
	count=150;
};