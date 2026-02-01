class rhs_mag_M229_19;
class RC_RHS_PylonM_19Rnd_Hydra_HE: rhs_mag_M229_19
{
	displayName="> Hydra HE 19x";
	displayNameShort="Hydra HE";
	descriptionShort="high explosive unguided rockets";
	pylonWeapon="RC_RHS_PylonW_Hydra";
	ammo="RC_RHS_Hydra_HE";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_19Rnd_Hydra_MP: RC_RHS_PylonM_19Rnd_Hydra_HE
{
	displayName="> Hydra MP 19x";
	displayNameShort="Hydra MP";
	descriptionShort="multi purpose unguided rockets";
	ammo="RC_RHS_Hydra_MP";
};


class rhs_mag_M229_7;
class RC_RHS_PylonM_7Rnd_Hydra_HE: rhs_mag_M229_7
{
	displayName="> Hydra HE 7x";
	displayNameShort="Hydra HE";
	descriptionShort="high explosive unguided rockets";
	pylonWeapon="RC_RHS_PylonW_Hydra";
	ammo="RC_RHS_Hydra_HE";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_7Rnd_Hydra_MP: RC_RHS_PylonM_7Rnd_Hydra_HE
{
	displayName="> Hydra MP 7x";
	displayNameShort="Hydra MP";
	descriptionShort="multi purpose unguided rockets";
	ammo="RC_RHS_Hydra_MP";
};


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
class RC_PylonM_7Rnd_APKWS: RC_PylonM_12Rnd_APKWS
{
	displayName="> APKWS LG 7x";
	model="\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_r_FFAR_7x";
	ammo="RC_RHS_APKWS";
	count=7;
};


//lacks submun
class rhs_mag_DAGR_8;
class RC_RHS_PylonM_8Rnd_DAGR: rhs_mag_DAGR_8
{
	displayName="> DAGR M310 8x";
	descriptionShort="SACLOS guided missiles";
	pylonWeapon="RC_RHS_PylonW_DAGR";
	ammo="RC_RHS_DAGR_M310";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_8Rnd_S8_G: RC_RHS_PylonM_8Rnd_DAGR
{
	displayName="> S-8 G 8x";
	displayNameShort="S-8 G";
	descriptionShort="SACLOS / lock - guided missiles";
	pylonWeapon="RC_RHS_PylonW_S8_G";
	ammo="RC_RHS_DAGR_M310";

	hardpoints[]=
	{
		"OM_H_O"
	};
};


/*
//defunct guidance
class rhs_mag_AGM114K_2;
class RC_PylonM_2Rnd_AGM114K: rhs_mag_AGM114K_2
{
	displayName="> AGM-114K Hellfire II 2x";
	pylonWeapon="RC_RHS_PylonW_AGM114K";
	//ammo="RHS_ammo_AGM_114K";

	hardpoints[]=
	{
		"OM_H"
	};
};
*/


class rhs_mag_AGM114K_2;
class RC_PylonM_2Rnd_AGM114K: rhs_mag_AGM114K_2
{
	displayName="> AGM-114K Hellfire II 2x";
	descriptionShort="heavy laser guided missiles";
	pylonWeapon="RC_PylonW_Hellfire";
	ammo="RC_RHS_AGM114K";

	hardpoints[]=
	{
		"OM_H"
	};
};


class rhsusf_mag_gau19_melb_left;
class RC_RHS_PylonM_1300Rnd_GAU19A_left: rhsusf_mag_gau19_melb_left
{
	displayName="> GAU-19/A left 1300x";
	displayNameShort="GAU-19/A";
	descriptionShort="GAU-19/A Minigun";
	pylonWeapon="RC_RHS_PylonW_GAU19A";
	ammo="RC_B_127x99_SLAP_T_R";

	hardpoints[]=
	{
		"OM_H",
		"OM_H_O"
	};
};


class rhsusf_mag_gau19_melb_right;
class RC_RHS_PylonM_1300Rnd_GAU19A_right: rhsusf_mag_gau19_melb_right
{
	displayName="> GAU-19/A right 1300x";
	displayNameShort="GAU-19/A";
	descriptionShort="GAU-19/A Minigun";
	pylonWeapon="RC_RHS_PylonW_GAU19A";
	ammo="RC_B_127x99_SLAP_T_R";

	hardpoints[]=
	{
		"OM_H",
		"OM_H_O"
	};
};


class rhs_mag_m134_pylon_3000;
class RC_RHS_PylonM_2600Rnd_338_SLAP: rhs_mag_m134_pylon_3000
{
	displayName="> .338NM SLAP 2600x";
	displayNameShort=".338NM SLAP";
	descriptionShort=".338NM Minigun";
	pylonWeapon="RC_RHS_PylonW_338_Minigun";
	ammo="RC_B_338_SLAP_T_R";
	count=2600;

	hardpoints[]=
	{
		"OM_H",
		"OM_H_O"
	};
};