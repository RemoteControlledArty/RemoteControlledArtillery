class rhs_mag_M151_19;
class RC_RHS_PylonM_19Rnd_M151: rhs_mag_M151_19
{
	//INCREASE REARM COST

	displayName="[19x M151 Hydra]";
	displayNameShort="M151 Hydra";
	descriptionShort="19x M151 Hydra Pod";
	pylonWeapon="RC_RHS_PylonW_Hydra";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_12Rnd_M151: RC_RHS_PylonM_19Rnd_M151
{
	displayName="[12x M151 Hydra]";
	descriptionShort="12x M151 Hydra Pod";
	count=12;
};
class RC_RHS_PylonM_9Rnd_M151: RC_RHS_PylonM_19Rnd_M151
{
	displayName="[9x M151 Hydra]";
	descriptionShort="9x M151 Hydra Pod";
	count=9;
};


class rhs_mag_M229_19;
class RC_RHS_PylonM_19Rnd_M229: rhs_mag_M229_19
{
	displayName="[19x M229 Hydra]";
	displayNameShort="M229 Hydra";
	descriptionShort="19x M229 Hydra Pod";
	pylonWeapon="RC_RHS_PylonW_Hydra";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_12Rnd_M229: RC_RHS_PylonM_19Rnd_M229
{
	displayName="[12x M229 Hydra]";
	descriptionShort="12x M229 Hydra Pod";
	count=12;
};
class RC_RHS_PylonM_9Rnd_M229: RC_RHS_PylonM_19Rnd_M229
{
	displayName="[9x M229 Hydra]";
	descriptionShort="9x M229 Hydra Pod";
	count=9;
};


class rhs_mag_M151_7;
class RC_RHS_PylonM_7Rnd_M151: rhs_mag_M151_7
{
	//INCREASE REARM COST

	displayName="[7x M151 Hydra]";
	displayNameShort="M151 Hydra";
	descriptionShort="7x M151 Hydra Pod";
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

	displayName="[7x M229 Hydra]";
	displayNameShort="M229 Hydra";
	descriptionShort="7x M229 Hydra Pod";
	pylonWeapon="RC_RHS_PylonW_Hydra";

	hardpoints[]=
	{
		"OM_H"
	};
};
class RC_RHS_PylonM_7Rnd_MP: RC_RHS_PylonM_7Rnd_M229
{
	displayName="[7x Hydra MP]";
	displayNameShort="Hydra MP";
	descriptionShort="7x Hydra MP Pod";
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
	displayName="[7x APKWS LG]";
	model="\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_r_FFAR_7x";
	ammo="RC_RHS_APKWS";
	count=7;
};