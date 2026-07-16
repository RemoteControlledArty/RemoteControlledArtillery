//minigun
class 5000Rnd_762x51_Yellow_Belt;
class RC_PylonM_3000Rnd_338_SLAP_T_R: 5000Rnd_762x51_Yellow_Belt
{
	displayName="> .338NM SLAP 3000x red";
	displayNameShort=".338NM SLAP";
	descriptionShort=".338NM Minigun";
	pylonWeapon="RC_PylonW_338_Minigun";
	ammo="RC_Pylon_B_338_SLAP_T_R";
	count=3000;
	tracersEvery=1;
	hardpoints[]={"OM_H","OM_H_O"};
};
class RC_PylonM_3000Rnd_338_SLAP_T_G: RC_PylonM_3000Rnd_338_SLAP_T_R
{
	displayName="> .338NM SLAP 3000x green";
	ammo="RC_Pylon_B_338_SLAP_T_G";
};
class RC_PylonM_3000Rnd_338_SLAP_T_Y: RC_PylonM_3000Rnd_338_SLAP_T_R
{
	displayName="> .338NM SLAP 3000x yellow";
	ammo="RC_Pylon_B_338_SLAP_T_Y";
};


//autocannon
class PylonWeapon_300Rnd_20mm_shells;
class RC_PylonM_Autocannon_base: PylonWeapon_300Rnd_20mm_shells
{
	//INCREASE REARM COST
	scope=0;
	author="Ascent";
	pylonWeapon="RC_PylonW_TwinCannon";
	hardpoints[]={"OM_H"};	//OM_H
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
class RC_PylonM_350Rnd_20mm: RC_PylonM_Autocannon_base
{
	scope=2;
	displayName="> 20mm MP 350x";
	displayNameShort="20mm MP";
	descriptionShort="20mm Autocannon";
	ammo="RC_Pylon_B_20mm_MP_QF_T_R";
	count=350;
};
class RC_PylonM_350Rnd_20mm_Lead: RC_PylonM_350Rnd_20mm
{
	displayName="> Lead 20mm MP 350x";
	displayNameShort="20mm MP";
	descriptionShort="20mm Autocannon with lead indicator on locked target";
	pylonWeapon="RC_PylonW_TwinCannon_Lead";
};
class RC_PylonM_350Rnd_20mm_Proxy: RC_PylonM_350Rnd_20mm
{
	displayName="> Proxy 20mm MP 350x";
	displayNameShort="20mm MP Proxy";
	descriptionShort="30mm Autocannon with proximity fuze";
	ammo="RC_Pylon_B_20mm_MP_QF_Proxy_T";
	hardpoints[]={"OM_H_Proxy"};
};
class RC_PylonM_350Rnd_20mm_Proxy_Lead: RC_PylonM_350Rnd_20mm_Proxy
{
	displayName="> Lead Proxy 20mm MP 350x";
	descriptionShort="30mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_TwinCannon_Lead";
};


class RC_PylonM_300Rnd_25mm: RC_PylonM_350Rnd_20mm
{
	displayName="> 25mm MP 300x";
	displayNameShort="25mm MP";
	descriptionShort="25mm Autocannon";
	ammo="RC_Pylon_B_25mm_MP_QF_T_R";
	count=300;
};
class RC_PylonM_300Rnd_25mm_Lead: RC_PylonM_300Rnd_25mm
{
	displayName="> Lead 25mm MP 300x";
	displayNameShort="25mm MP";
	descriptionShort="25mm Autocannon with lead indicator on locked target";
	pylonWeapon="RC_PylonW_TwinCannon_Lead";
};
class RC_PylonM_300Rnd_25mm_Proxy: RC_PylonM_300Rnd_25mm
{
	displayName="> Proxy 25mm MP 300x";
	displayNameShort="25mm MP Proxy";
	descriptionShort="30mm Autocannon with proximity fuze";
	ammo="RC_Pylon_B_25mm_MP_QF_Proxy_T";
	hardpoints[]={"OM_H_Proxy"};
};
class RC_PylonM_300Rnd_25mm_Proxy_Lead: RC_PylonM_300Rnd_25mm_Proxy
{
	displayName="> Lead Proxy 25mm MP 300x";
	descriptionShort="30mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_TwinCannon_Lead";
};


class RC_PylonM_250Rnd_30mm: RC_PylonM_350Rnd_20mm
{
	displayName="> 30mm MP 250x";
	displayNameShort="30mm MP";
	descriptionShort="30mm Autocannon";
	ammo="RC_Pylon_B_30mm_MP_QF_T_R";
	count=250;
};
class RC_PylonM_250Rnd_30mm_Lead: RC_PylonM_250Rnd_30mm
{
	displayName="> Lead 30mm MP 250x";
	displayNameShort="30mm MP";
	descriptionShort="30mm Autocannon with lead indicator on locked target";
	pylonWeapon="RC_PylonW_TwinCannon_Lead";
};
class RC_PylonM_250Rnd_30mm_Proxy: RC_PylonM_250Rnd_30mm
{
	displayName="> Proxy 30mm MP 250x";
	displayNameShort="30mm MP Proxy";
	descriptionShort="30mm Autocannon with proximity fuze";
	ammo="RC_Pylon_B_30mm_MP_QF_Proxy_T";	//RC_B_35mm_MPAB_DF_T_R
	hardpoints[]={"OM_H_Proxy"};
};
class RC_PylonM_250Rnd_30mm_Proxy_Lead: RC_PylonM_250Rnd_30mm_Proxy
{
	displayName="> Lead Proxy 30mm MP 250x";
	descriptionShort="30mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_TwinCannon_Lead";
};


class RC_PylonM_350Rnd_20mm_O: RC_PylonM_350Rnd_20mm
{
	displayName="> 20mm MP 350x";
	displayNameShort="20mm MP";
	descriptionShort="20mm Autocannon";
	ammo="RC_Pylon_B_20mm_MP_QF_T_G";
	pylonWeapon="RC_PylonW_Avtopushka";
	count=350;
	hardpoints[]={"OM_H_O"};
};
class RC_PylonM_350Rnd_20mm_Lead_O: RC_PylonM_350Rnd_20mm_O
{
	displayName="> Lead 20mm MP 350x";
	displayNameShort="20mm MP";
	descriptionShort="20mm Autocannon with lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
};
class RC_PylonM_350Rnd_20mm_Proxy_O: RC_PylonM_350Rnd_20mm_O
{
	displayName="> Proxy 20mm MP 350x";
	displayNameShort="20mm MP Proxy";
	descriptionShort="30mm Autocannon with proximity fuze";
	ammo="RC_Pylon_B_20mm_MP_QF_Proxy_T";
	hardpoints[]={"OM_H_O_Proxy"};
};
class RC_PylonM_350Rnd_20mm_Proxy_Lead_O: RC_PylonM_350Rnd_20mm_Proxy_O
{
	displayName="> Lead Proxy 20mm MP 350x";
	descriptionShort="30mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
};


class RC_PylonM_300Rnd_25mm_O: RC_PylonM_350Rnd_20mm_O
{
	displayName="> 25mm MP 300x";
	displayNameShort="25mm MP";
	descriptionShort="25mm Autocannon";
	ammo="RC_Pylon_B_25mm_MP_QF_T_G";
	count=300;
};
class RC_PylonM_300Rnd_25mm_Lead_O: RC_PylonM_300Rnd_25mm_O
{
	displayName="> Lead 25mm MP 300x";
	displayNameShort="25mm MP";
	descriptionShort="25mm Autocannon with lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
};
class RC_PylonM_300Rnd_25mm_Proxy_O: RC_PylonM_300Rnd_25mm_O
{
	displayName="> Proxy 25mm MP 300x";
	displayNameShort="25mm MP Proxy";
	descriptionShort="30mm Autocannon with proximity fuze";
	ammo="RC_Pylon_B_25mm_MP_QF_Proxy_T";
	hardpoints[]={"OM_H_O_Proxy"};
};
class RC_PylonM_300Rnd_25mm_Proxy_Lead_O: RC_PylonM_300Rnd_25mm_Proxy_O
{
	displayName="> Lead Proxy 25mm MP 300x";
	descriptionShort="30mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
};


class RC_PylonM_250Rnd_30mm_O: RC_PylonM_350Rnd_20mm_O
{
	displayName="> 30mm MP 250x";
	displayNameShort="30mm MP";
	descriptionShort="30mm Autocannon";
	ammo="RC_Pylon_B_30mm_MP_QF_T_G";
	count=250;
};
class RC_PylonM_250Rnd_30mm_Lead_O: RC_PylonM_250Rnd_30mm_O
{
	displayName="> Lead 30mm MP 250x";
	displayNameShort="30mm MP";
	descriptionShort="30mm Autocannon with lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
};
class RC_PylonM_250Rnd_30mm_Proxy_O: RC_PylonM_250Rnd_30mm_O
{
	displayName="> Proxy 30mm MP 250x";
	displayNameShort="30mm MP Proxy";
	descriptionShort="30mm Autocannon with proximity fuze";
	ammo="RC_Pylon_B_30mm_MP_QF_Proxy_T";	//RC_B_35mm_MPAB_DF_T_R
	hardpoints[]={"OM_H_O_Proxy"};
};
class RC_PylonM_250Rnd_30mm_Proxy_Lead_O: RC_PylonM_250Rnd_30mm_Proxy_O
{
	displayName="> Lead Proxy 30mm MP 250x";
	descriptionShort="30mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
};


/*
class RC_PylonM_350Rnd_20mm_O: RC_PylonM_350Rnd_20mm
{
	descriptionShort="20mm Avtopushka";
	pylonWeapon="RC_PylonW_Avtopushka";
	ammo="RC_Pylon_B_20mm_MP_QF_T_G";
	hardpoints[]={"OM_H_O"};
};
class RC_PylonM_350Rnd_20mm_Lead_O: RC_PylonM_350Rnd_20mm_Lead
{
	descriptionShort="20mm Avtopushka with lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
	hardpoints[]={"OM_H_O"};
};
class RC_PylonM_350Rnd_20mm_Proxy_O: RC_PylonM_350Rnd_20mm_Proxy
{
	descriptionShort="20mm Avtopushka with proximity fuze";
	hardpoints[]={"OM_H_O_Proxy"};
};
class RC_PylonM_350Rnd_20mm_Proxy_Lead_O: RC_PylonM_350Rnd_20mm_Proxy_Lead
{
	descriptionShort="20mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
	hardpoints[]={"OM_H_O_Proxy"};
};


class RC_PylonM_300Rnd_25mm_O: RC_PylonM_300Rnd_25mm
{
	descriptionShort="25mm Avtopushka";
	pylonWeapon="RC_PylonW_Avtopushka";
	ammo="RC_Pylon_B_25mm_MP_QF_T_G";
	hardpoints[]={"OM_H_O"};
};
class RC_PylonM_300Rnd_25mm_Lead_O: RC_PylonM_300Rnd_25mm_Lead
{
	descriptionShort="25mm Avtopushka with lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
	hardpoints[]={"OM_H_O"};
};
class RC_PylonM_300Rnd_25mm_Proxy_O: RC_PylonM_300Rnd_25mm_Proxy
{
	descriptionShort="25mm Avtopushka with proximity fuze";
	hardpoints[]={"OM_H_O_Proxy"};
};
class RC_PylonM_300Rnd_25mm_Proxy_Lead_O: RC_PylonM_300Rnd_25mm_Proxy_Lead
{
	descriptionShort="25mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
	hardpoints[]={"OM_H_O_Proxy"};
};


class RC_PylonM_250Rnd_30mm_O: RC_PylonM_250Rnd_30mm
{
	descriptionShort="30mm Avtopushka";
	pylonWeapon="RC_PylonW_Avtopushka";
	ammo="RC_Pylon_B_30mm_MP_QF_T_G";
	hardpoints[]={"OM_H_O"};
};
class RC_PylonM_250Rnd_30mm_Lead_O: RC_PylonM_250Rnd_30mm_Lead
{
	descriptionShort="30mm Avtopushka with lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
	hardpoints[]={"OM_H_O"};
};
class RC_PylonM_250Rnd_30mm_Proxy_O: RC_PylonM_250Rnd_30mm_Proxy
{
	descriptionShort="30mm Avtopushka proximity fuze";
	hardpoints[]={"OM_H_O_Proxy"};
};
class RC_PylonM_250Rnd_30mm_Proxy_Lead_O: RC_PylonM_300Rnd_25mm_Proxy_Lead
{
	descriptionShort="30mm Autocannon with proximity fuze & lead indicator on locked target";
	pylonWeapon="RC_PylonW_Avtopushka_Lead";
	hardpoints[]={"OM_H_O_Proxy"};
};
*/


/*
class RC_PylonWeapon_300Rnd_20mm_Aegis: RC_PylonWeapon_300Rnd_20mm
{
	//magazines[] = {"PylonWeapon_250Rnd_20mm_shells"};
	//model="\A3_Aegis\Weapons_F_Aegis\DynamicLoadout\PylonPod_Cannon_20mm.p3d";
	//pylonWeapon="cannon_20mm_Heli_Light_03";
};
*/


//unguided rockets
class PylonRack_12Rnd_missiles;
class RC_PylonM_12Rnd_Hydra_MP: PylonRack_12Rnd_missiles
{
	//INCREASE REARM COST
	
	author="Ascent";
	displayName="> Hydra MP 12x";
	displayNameShort="Hydra MP";
	descriptionShort="multi purpose unguided rockets";
	pylonWeapon="RC_PylonW_12Rnd_Hydra";
	ammo="RC_Hydra_MP";
	hardpoints[]={"OM_H_Base"};	//OM_H
};
class RC_PylonM_12Rnd_Hydra_MP_Proxy: RC_PylonM_12Rnd_Hydra_MP
{
	displayName="> Hydra MP Proxy 12x";
	displayNameShort="Hydra MP Proxy";
	descriptionShort="multi purpose proximity fuze unguided rockets";
	pylonWeapon="RC_PylonW_12Rnd_Hydra_Proxy";
	ammo="RC_Hydra_MP_Proxy";
	hardpoints[]={"OM_H"};
};
/*
class RC_PylonM_12Rnd_Hydra_HE: RC_PylonM_12Rnd_Hydra_MP
{
	displayName="> Hydra HE 12x";
	displayNameShort="Hydra HE";
	descriptionShort="high explosive unguided rockets";
	ammo="RC_Hydra_HE";
};
*/


class RC_PylonM_12Rnd_S5_MP: RC_PylonM_12Rnd_Hydra_MP
{
	author="Ascent";
	displayName="> S-5 MP 12x";
	displayNameShort="S-5 MP";
	descriptionShort="multi purpose unguided rockets";
	pylonWeapon="RC_PylonW_12Rnd_S5";
	ammo="RC_Hydra_MP";
	hardpoints[]={"OM_H_Base"};	//OM_H_O
};
class RC_PylonM_12Rnd_S5_MP_Proxy: RC_PylonM_12Rnd_S5_MP
{
	displayName="> S-5 MP Proxy 12x";
	displayNameShort="S-5 MP Proxy";
	descriptionShort="multi purpose proximity fuze unguided rockets";
	pylonWeapon="RC_PylonW_12Rnd_S5_Proxy";
	ammo="RC_Hydra_MP_Proxy";
	hardpoints[]={"OM_H_O"};
};
/*
class RC_PylonM_12Rnd_S5_HE: RC_PylonM_12Rnd_S5_MP
{
	displayName="> S-5 HE 12x";
	displayNameShort="S-5 HE";
	descriptionShort="high explosive unguided rockets";
	ammo="RC_Hydra_HE";
};
*/


class PylonRack_19Rnd_Rocket_Skyfire;
class RC_PylonM_19Rnd_Hydra_MP: PylonRack_19Rnd_Rocket_Skyfire
{
	author="Ascent";
	displayName="> Hydra MP 19x Hex";
	displayNameShort="Hydra MP";
	descriptionShort="multi purpose unguided rockets";
	pylonWeapon="RC_PylonW_19Rnd_Hydra";
	ammo="RC_Hydra_MP";
	hardpoints[]={"OM_H_Base"};	//OM_H
};
class RC_PylonM_19Rnd_Hydra_MP_Proxy: RC_PylonM_19Rnd_Hydra_MP
{
	displayName="> Hydra MP Proxy 19x Hex";
	displayNameShort="Hydra MP Proxy";
	descriptionShort="multi purpose proximity fuze unguided rockets";
	pylonWeapon="RC_PylonW_19Rnd_Hydra_Proxy";
	ammo="RC_Hydra_MP_Proxy";
	hardpoints[]={"OM_H"};
	//initSpeed=700;	//44	//still doesnt lead correctly with 700 and no thrust
};
/*
class RC_PylonM_19Rnd_Hydra_HE: RC_PylonM_19Rnd_Hydra_MP
{
	displayName="> Hydra HE 19x Hex";
	displayNameShort="Hydra HE";
	descriptionShort="high explosive unguided rockets";
	ammo="RC_Hydra_HE";
};
*/


class RC_PylonM_19Rnd_S5_MP: RC_PylonM_19Rnd_Hydra_MP
{
	displayName="> S-5 MP 19x";
	displayNameShort="S-5 MP";
	pylonWeapon="RC_PylonW_19Rnd_S5";
	ammo="RC_Hydra_MP";
	hardpoints[]={"OM_H_Base"};	//OM_H_O
};
class RC_PylonM_19Rnd_S5_MP_Proxy: RC_PylonM_19Rnd_S5_MP
{
	displayName="> S-5 MP Proxy 19x";
	displayNameShort="S-5 MP Proxy";
	pylonWeapon="RC_PylonW_19Rnd_S5_Proxy";
	ammo="RC_Hydra_MP_Proxy";
	hardpoints[]={"OM_H_O"};
};
/*
class RC_PylonM_19Rnd_S5_HE: RC_PylonM_19Rnd_S5_MP
{
	displayName="> S-5 HE 19x";
	displayNameShort="S-5 HE";
	descriptionShort="high explosive unguided rockets";
	ammo="RC_Hydra_HE";
};
*/


//light guided
class PylonRack_12Rnd_PG_missiles;
class RC_PylonM_12Rnd_APKWS: PylonRack_12Rnd_PG_missiles
{
	displayName="> APKWS LG 12x";
    displayNameShort="APKWS LG";
	descriptionShort="laser guided missiles";
    pylonWeapon="RC_PylonW_APKWS";
	ammo="RC_APKWS";
	hardpoints[]={"OM_H"};
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
	hardpoints[]={"OM_H_O_REWORK"};
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
	hardpoints[]={"OM_H"};
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
	hardpoints[]={"OM_H_I"};
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
	hardpoints[]={"OM_H_O_REWORK"};
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

	hardpoints[]={"OM_H_O_REWORK"};
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


/*
//add in RC_Aegis pbo
class PylonRack_20Rnd_Rocket_80mm;
class RC_PylonM_20Rnd_S5_HE: PylonRack_20Rnd_Rocket
{
	author="Ascent";
	displayName="> S-5 HE 20x";
	displayNameShort="S-5 HE";
	descriptionShort="high explosive unguided rockets";
	pylonWeapon="RC_PylonW_19Rnd_Hydra";	//rockets_Skyfire
	ammo="RC_Hydra_HE";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_PylonM_20Rnd_S5_MP: RC_PylonM_20Rnd_S5_HE
{
	displayName="> S-5 MP 20x";
	displayNameShort="S-5 MP";
	descriptionShort="multi purpose unguided rockets";
	ammo="RC_Hydra_MP";
};
*/