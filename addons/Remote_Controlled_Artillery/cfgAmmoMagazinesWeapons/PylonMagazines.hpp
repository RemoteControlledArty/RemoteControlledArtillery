class PylonWeapon_300Rnd_20mm_shells;
class RC_PylonM_Autocannon_base: PylonWeapon_300Rnd_20mm_shells
{
	//INCREASE REARM COST
	
	scope=0;
	author="Ascent";
	pylonWeapon="RC_PylonW_TwinCannon";
	muzzleImpulseFactor[]={0.0375,0.3};		//{0.1,0.8}		//(torque, force) 
	tracersEvery=1;

	/*
	hardpoints[]=
	{
		"OM_H"
		"B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","20MM_CANNON",
		"DAGR","DAR","B_MISSILE_PYLON",
		"GX_HELI_SMALL",
		"UNI_LEAFLETS_PYLON"
	};
	*/

	/*
	mass=230;
	initSpeed=1030;
	maxLeadSpeed=83.333298;
	model="\A3\Weapons_F\DynamicLoadout\PylonPod_Twin_Cannon_20mm.p3d";
	muzzlePos="muzzlePos";
	muzzleEnd="muzzleEnd";
	*/
};
class RC_PylonM_300Rnd_20mm: RC_PylonM_Autocannon_base
{
	scope=2;
	displayName="[20mm MP-QF 300x]";
	displayNameShort="20mm MP-QF";
	descriptionShort="20mm Autocannon";
	ammo="RC_Pylon_B_20mm_MP_QF_T_R";
	count=300;

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_PylonM_250Rnd_25mm: RC_PylonM_300Rnd_20mm
{
	displayName="[25mm MP-QF x250]";
	displayNameShort="25mm MP-QF";
	descriptionShort="25mm Autocannon";
	ammo="RC_Pylon_B_25mm_MP_QF_T_R";
	count=250;

	hardpoints[]=
	{
		"OM_H"
	};
};
//class RC_PylonM_200Rnd_25mm: RC_PylonM_250Rnd_25mm {count=200;};
class RC_PylonM_200Rnd_30mm: RC_PylonM_300Rnd_20mm
{
	displayName="[30mm MP-QF x200]";
	displayNameShort="30mm MP-QF";
	descriptionShort="30mm Autocannon";
	ammo="RC_Pylon_B_30mm_MP_QF_T_R";
	count=200;

	hardpoints[]=
	{
		"OM_H"
	};
};
//class RC_PylonM_150Rnd_30mm: RC_PylonM_200Rnd_30mm {count=150;};


/*
class RC_PylonWeapon_300Rnd_20mm_Aegis: RC_PylonWeapon_300Rnd_20mm
{
	//magazines[] = {"PylonWeapon_250Rnd_20mm_shells"};
	//model="\A3_Aegis\Weapons_F_Aegis\DynamicLoadout\PylonPod_Cannon_20mm.p3d";
	//pylonWeapon="cannon_20mm_Heli_Light_03";
};
*/


class PylonRack_12Rnd_missiles;
class RC_PylonM_12Rnd_70mm_Hydra_HE: PylonRack_12Rnd_missiles
{
	//INCREASE REARM COST
	
	author="Ascent";
	displayName="[Hydra HE 12x]";
	displayNameShort="Hydra HE";
	descriptionShort="Hydra HE 12x";
	pylonWeapon="RC_PylonW_12Rnd_70mm_Hydra";
	ammo="RC_Hydra_HE";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_PylonM_12Rnd_70mm_Hydra_MP: RC_PylonM_12Rnd_70mm_Hydra_HE
{
	displayName="[Hydra MP 12x]";
	displayNameShort="Hydra MP";
	descriptionShort="Hydra MP 12x";
	ammo="RC_Hydra_MP";
};


class PylonRack_12Rnd_PG_missiles;
class RC_PylonM_12Rnd_APKWS: PylonRack_12Rnd_PG_missiles
{
	displayName="[APKWS LG 12x]";
    displayNameShort="APKWS LG";
	descriptionShort="APKWS LG 12x";
    pylonWeapon="RC_PylonW_APKWS";
	ammo="RC_APKWS";

	hardpoints[]=
	{
		"OM_H"
	};
};


//fitting for MH-80M DAP
class PylonRack_19Rnd_Rocket_Skyfire;
class RC_PylonM_19Rnd_70mm_Hydra_HE: PylonRack_19Rnd_Rocket_Skyfire
{
	author="Ascent";
	displayName="[Hydra HE 19x hexagonal]";
	displayNameShort="Hydra HE";
	descriptionShort="Hydra HE 19x";
	pylonWeapon="RC_PylonW_19Rnd_70mm_Hydra";
	ammo="RC_Hydra_HE";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_PylonM_19Rnd_70mm_Hydra_MP: RC_PylonM_19Rnd_70mm_Hydra_HE
{
	displayName="[Hydra MP 19x hexagonal]";
	displayNameShort="Hydra MP";
	descriptionShort="Hydra MP 19x";
	ammo="RC_Hydra_MP";
};