class rhs_mag_M151_19;
class RC_RHS_PylonM_19Rnd_M151: rhs_mag_M151_19
{
	//INCREASE REARM COST

	displayName="[Hydra M151 19x]";
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
	displayName="[Hydra M151 12x]";
	descriptionShort="Hydra M151 12x Pod";
	count=12;
};
class RC_RHS_PylonM_9Rnd_M151: RC_RHS_PylonM_19Rnd_M151
{
	displayName="[Hydra M151 12x]";
	descriptionShort="Hydra M151 12x Pod";
	count=9;
};


class rhs_mag_M229_19;
class RC_RHS_PylonM_19Rnd_M229: rhs_mag_M229_19
{
	displayName="[Hydra M229 19x]";
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
	displayName="[Hydra M229 12x]";
	descriptionShort="Hydra M229 12x Pod";
	count=12;
};
class RC_RHS_PylonM_9Rnd_M229: RC_RHS_PylonM_19Rnd_M229
{
	displayName="[Hydra M229 9x]";
	descriptionShort="Hydra M229 9x Pod";
	count=9;
};


class rhs_mag_M151_7;
class RC_RHS_PylonM_7Rnd_M151: rhs_mag_M151_7
{
	//INCREASE REARM COST

	displayName="[Hydra M151 7x]";
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

	displayName="[Hydra M229 7x]";
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
	displayName="[Hydra MP 7x]";
	displayNameShort="Hydra MP";
	descriptionShort="Hydra MP 7x Pod";
	ammo="RC_Hydra_MP";
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
	displayName="[APKWS LG 7x]";
	model="\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_r_FFAR_7x";
	ammo="RC_RHS_APKWS";
	count=7;
};


//rhs_mag_DAGR_8
displayName = "DAGR (M310)";
ammo = "RHS_Ammo_DAGR";
hardpoints[] = {"RHS_HP_HELLFIRE_RACK","RHS_HP_LONGBOW_RACK","RHS_HP_MELB"};

class rhs_mag_DAGR_8;
class RC_PylonM_8Rnd_DAGR: rhs_mag_DAGR_8
{
	displayName="[DAGR 8x]";
	//ammo="";

	hardpoints[]=
	{
		"OM_H"
	};
};


/*
rhs_mag_AGM114K_2
displayName = "AGM-114K (M310)";
descriptionShort = "×2 Hellfire, Laser-homing ";
ammo = "RHS_ammo_AGM_114K";
hardpoints[] = {"RHS_HP_HELLFIRE_RACK","RHS_HP_LONGBOW_RACK","RHS_HP_MELB"};
class rhs_mag_AGM114K_2;
class RC_PylonM_2Rnd_AGM114K: rhs_mag_AGM114K_2
{
	displayName="[AGM-114K 2x]";
	//ammo="";

	hardpoints[]=
	{
		"OM_H"
	};
};