class rhs_mag_m134_pylon_3000;
class RC_RHS_PylonM_2500Rnd_338_SLAP_T_R: rhs_mag_m134_pylon_3000
{
	displayName="> .338NM SLAP 2500x red [RHS]";
	displayNameShort=".338NM SLAP";
	descriptionShort=".338NM Minigun";
	pylonWeapon="RC_RHS_PylonW_338_Minigun";
	ammo="RC_Pylon_B_338_SLAP_T_R";
	initSpeed=1200;
	count=2500;
	tracersEvery=1;
	hardpoints[]={"RC_Hardpoint_V1","RC_Hardpoint_O_V1"};
};
class RC_RHS_PylonM_2500Rnd_338_SLAP_T_G: RC_RHS_PylonM_2500Rnd_338_SLAP_T_R
{
	displayName="> .338NM SLAP 2500x green [RHS]";
	ammo="RC_Pylon_B_338_SLAP_T_R";
	hardpoints[]={"RC_Hardpoint_G_V1","RC_Hardpoint_G_O_V1"};
};
class RC_RHS_PylonM_2500Rnd_338_SLAP_T_Y: RC_RHS_PylonM_2500Rnd_338_SLAP_T_R
{
	displayName="> .338NM SLAP 2500x yellow [RHS]";
	ammo="RC_Pylon_B_338_SLAP_T_R";
	hardpoints[]={"RC_Hardpoint_Y_V1","RC_Hardpoint_Y_O_V1"};
};


class rhsusf_mag_gau19_melb_left;
class RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_left: rhsusf_mag_gau19_melb_left
{
	displayName="> .50 SLAP 1000x red [GAU-19 RHS]";
	displayNameShort=".50 SLAP";
	descriptionShort=".50 Minigun";
	pylonWeapon="RC_RHS_PylonW_GAU19A";
	ammo="RC_Pylon_B_127x99_SLAP_T_R";
	initSpeed=1200;
	count=1000;
	tracersEvery=1;
	hardpoints[]={"RC_Hardpoint_V2_Left","RC_Hardpoint_O_V2_Left"};
};
class RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_G_left: RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_left
{
	displayName="> .50 SLAP 1000x green [GAU-19 RHS]";
	ammo="RC_Pylon_B_127x99_SLAP_T_G";
	hardpoints[]={"RC_Hardpoint_G_V2_Left","RC_Hardpoint_G_O_V2_Left"};
};
class RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_Y_left: RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_left
{
	displayName="> .50 SLAP 1000x yellow [GAU-19 RHS]";
	ammo="RC_Pylon_B_127x99_SLAP_T_Y";
	hardpoints[]={"RC_Hardpoint_Y_V2_Left","RC_Hardpoint_Y_O_V2_Left"};
};


class rhsusf_mag_gau19_melb_right;
class RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_right: rhsusf_mag_gau19_melb_right
{
	displayName="> .50 SLAP 1000x red [GAU-19 RHS]";
	displayNameShort=".50 SLAP";
	descriptionShort=".50 Minigun";
	pylonWeapon="RC_RHS_PylonW_GAU19A";
	ammo="RC_Pylon_B_127x99_SLAP_T_R";
	initSpeed=1200;
	count=1000;
	tracersEvery=1;
	hardpoints[]={"RC_Hardpoint_V2_Right","RC_Hardpoint_O_V2_Right"};
};
class RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_G_right: RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_right
{
	displayName="> .50 SLAP 1000x green [GAU-19 RHS]";
	ammo="RC_Pylon_B_127x99_SLAP_T_G";
	hardpoints[]={"RC_Hardpoint_G_V2_Right","RC_Hardpoint_G_O_V2_Right"};
};
class RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_Y_right: RC_RHS_PylonM_1000Rnd_127mm_SLAP_T_R_right
{
	displayName="> .50 SLAP 1000x yellow [GAU-19 RHS]";
	ammo="RC_Pylon_B_127x99_SLAP_T_Y";
	hardpoints[]={"RC_Hardpoint_Y_V2_Right","RC_Hardpoint_Y_O_V2_Right"};
};


class rhs_mag_M229_19;
class RC_RHS_PylonM_19Rnd_Hydra_MP: rhs_mag_M229_19
{
	displayName="> Hydra MP 19x";
	displayNameShort="Hydra MP";
	descriptionShort="multi purpose unguided rockets";
	pylonWeapon="RC_RHS_PylonW_Hydra";
	ammo="RC_RHS_Hydra_MP";
	hardpoints[]={"OM_H_Base"};
};
class RC_RHS_PylonM_19Rnd_Hydra_MP_Proxy: RC_RHS_PylonM_19Rnd_Hydra_MP
{
	displayName="> Hydra MP Proxy 19x";
	displayNameShort="Hydra MP Proxy";
	descriptionShort="multi purpose proximity fuze unguided rockets";
	ammo="RC_RHS_Hydra_MP_Proxy";
	hardpoints[]={"RC_Hardpoint_V4"};
};
/*
class RC_RHS_PylonM_19Rnd_Hydra_HE: RC_RHS_PylonM_19Rnd_Hydra_MP
{
	displayName="> Hydra HE 19x";
	displayNameShort="Hydra HE";
	descriptionShort="high explosive unguided rockets";
	ammo="RC_RHS_Hydra_HE";
};
*/


class rhs_mag_M229_7;
class RC_RHS_PylonM_7Rnd_Hydra_MP: rhs_mag_M229_7
{
	displayName="> Hydra MP 7x";
	displayNameShort="Hydra MP";
	descriptionShort="multi purpose unguided rockets";
	pylonWeapon="RC_RHS_PylonW_Hydra";
	ammo="RC_RHS_Hydra_MP";
	hardpoints[]={"OM_H_Base"};
};
class RC_RHS_PylonM_7Rnd_Hydra_MP_Proxy: RC_RHS_PylonM_7Rnd_Hydra_MP
{
	displayName="> Hydra MP Proxy 7x";
	displayNameShort="Hydra MP Proxy";
	descriptionShort="multi purpose proximity fuze unguided rockets";
	ammo="RC_RHS_Hydra_MP_Proxy";
	hardpoints[]={"RC_Hardpoint_V3"};
};
/*
class RC_RHS_PylonM_7Rnd_Hydra_HE: RC_RHS_PylonM_7Rnd_Hydra_MP
{
	displayName="> Hydra HE 7x";
	displayNameShort="Hydra HE";
	descriptionShort="high explosive unguided rockets";
	ammo="RC_RHS_Hydra_HE";
};
*/


/*
class RC_RHS_PylonM_7Rnd_APKWS: RC_RHS_PylonM_7Rnd_Hydra_M229
{
	displayName="[7x APKWS LG]";
    displayNameShort="APKWS LG";
    pylonWeapon="RC_RHS_PylonW_APKWS";
	ammo="RC_RHS_APKWS";

	hardpoints[]=
	{
		"OM_H"
	};
};
*/
class RC_PylonM_12Rnd_APKWS;
class RC_RHS_PylonM_7Rnd_APKWS: RC_PylonM_12Rnd_APKWS
{
	displayName="> APKWS LG 7x [RHS]";
	model="\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_r_FFAR_7x";
	ammo="RC_RHS_APKWS";
	count=7;
	hardpoints[]={"RC_Hardpoint_V5"};
};


class rhs_mag_DAGR_8;
class RC_PylonM_8Rnd_DAGR: rhs_mag_DAGR_8
{
	displayName="> DAGR M310 8x [RHS]";
	displayNameShort="DAGR";
	descriptionShort="SACLOS / lock - guided missiles";
	pylonWeapon="RC_PylonW_DAGR";
	ammo="RC_DAGR";
	hardpoints[]={"RC_Hardpoint_V5"};
};
class RC_PylonM_8Rnd_S8_G: RC_PylonM_8Rnd_DAGR
{
	displayName="> S-8 G 8x [RHS]";
	displayNameShort="S-8 G";
	descriptionShort="SACLOS / lock - guided missiles";
	pylonWeapon="RC_PylonW_S8_G";
	ammo="RC_DAGR";
	hardpoints[]={"RC_Hardpoint_O_V5"};
};


class rhs_mag_AGM114K_2;
class RC_PylonM_2Rnd_AGM114K: rhs_mag_AGM114K_2
{
	displayName="> AGM-114K Hellfire II 2x [RHS]";
	displayNameShort="AGM-114K";
	descriptionShort="heavy laser guided missiles";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_AGM114K";
	hardpoints[]={"RC_Hardpoint_V5"};
};