class rhs_mag_M151_19;
class RC_RHS_PylonM_19Rnd_M151: rhs_mag_M151_19
{
	//INCREASE REARM COST

	displayName="> Hydra M151 19x";
	displayNameShort="Hydra M151";
	descriptionShort="Hydra M151 19x Pod";
	pylonWeapon="RC_RHS_PylonW_Hydra";
	//ammo="rhs_ammo_Hydra_M151";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_12Rnd_M151: RC_RHS_PylonM_19Rnd_M151
{
	displayName="> Hydra M151 12x";
	descriptionShort="Hydra M151 12x Pod";
	count=12;
};
class RC_RHS_PylonM_9Rnd_M151: RC_RHS_PylonM_19Rnd_M151
{
	displayName="> Hydra M151 9x";
	descriptionShort="Hydra M151 9x Pod";
	count=9;
};


class rhs_mag_M229_19;
class RC_RHS_PylonM_19Rnd_M229: rhs_mag_M229_19
{
	displayName="> Hydra M229 19x";
	displayNameShort="Hydra M229";
	descriptionShort="Hydra M229 19x Pod";
	pylonWeapon="RC_RHS_PylonW_Hydra";
	//ammo="rhs_ammo_Hydra_M229";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_12Rnd_M229: RC_RHS_PylonM_19Rnd_M229
{
	displayName="> Hydra M229 12x";
	descriptionShort="Hydra M229 12x Pod";
	count=12;
};
class RC_RHS_PylonM_9Rnd_M229: RC_RHS_PylonM_19Rnd_M229
{
	displayName="> Hydra M229 9x";
	descriptionShort="Hydra M229 9x Pod";
	count=9;
};


class RC_RHS_PylonM_19Rnd_MP: RC_RHS_PylonM_19Rnd_M229
{
	displayName="> Hydra MP 19x";
	displayNameShort="Hydra MP";
	descriptionShort="Hydra MP 19x Pod";
	ammo="RC_RHS_Hydra_MP";
};


class rhs_mag_M151_7;
class RC_RHS_PylonM_7Rnd_M151: rhs_mag_M151_7
{
	//INCREASE REARM COST

	displayName="> Hydra M151 7x";
	displayNameShort="Hydra M151";
	descriptionShort="Hydra M151 7x Pod";
	pylonWeapon="RC_RHS_PylonW_Hydra";

	hardpoints[]=
	{
		"OM_H"
	};
};


class rhs_mag_M229_7;
class RC_RHS_PylonM_7Rnd_M229: rhs_mag_M229_7
{
	//INCREASE REARM COST

	displayName="> Hydra M229 7x";
	displayNameShort="Hydra M229";
	descriptionShort="Hydra M229 7x Pod";
	pylonWeapon="RC_RHS_PylonW_Hydra";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_7Rnd_MP: RC_RHS_PylonM_7Rnd_M229
{
	displayName="> Hydra MP 7x";
	displayNameShort="Hydra MP";
	descriptionShort="Hydra MP 7x Pod";
	ammo="RC_RHS_Hydra_MP";
};


/*
class RC_RHS_PylonM_7Rnd_APKWS: RC_RHS_PylonM_7Rnd_M229
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
class RC_PylonM_8Rnd_DAGR: rhs_mag_DAGR_8
{
	displayName="> DAGR M310 8x";
	pylonWeapon="RC_RHS_PylonW_DAGR";
	//ammo="RHS_Ammo_DAGR";

	hardpoints[]=
	{
		"OM_H",
		"OM_H_O"
	};
};
class RC_PylonM_8Rnd_S8_SACLOS: RC_PylonM_8Rnd_DAGR
{
	displayName="> S-8 SACLOS 8x";
	displayNameShort="S-8 SACLOS";
	descriptionShort="S-8 SACLOS 8x";
	pylonWeapon="RC_RHS_PylonW_S8_SACLOS";
	//ammo="RHS_Ammo_DAGR";

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