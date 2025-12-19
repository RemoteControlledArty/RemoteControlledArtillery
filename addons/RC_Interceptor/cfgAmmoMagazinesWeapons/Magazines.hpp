//throwable
class HandGrenade;
class Interceptor_MP_Throw_Base: HandGrenade
{
	scope=0;
	//scopeArsenal = 0;
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap";
	//model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap_fly";
	//model="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";
	picture="\A3\Weapons_F_beta\Launchers\titan\Data\UI\gear_titan_missile_ap_CA.paa";
	descriptionShort="throwable Interceptor";
	mass=50;
};
class Interceptor_MP_Throw: Interceptor_MP_Throw_Base
{
	scope=2;
	scopeArsenal=2;

	ammo="Interceptor_MP_ThrowAmmo";
	displayName="MP Interceptor";
	displayNameShort="MP Interceptor";
};


/*
class RC_target_confirmer_mag;
class RC_target_confirmer_AB_mag: RC_target_confirmer_mag
{
	ammo="RC_target_confirmer_AB_ammo";
	initSpeed=1;
	scope=1;
	count=1;
};
class RC_shapedcharge_reticle_AB_mag: RC_target_confirmer_AB_mag
{
	ammo="RC_shapedcharge_reticle_AB_ammo";
	initSpeed=1000;	//for reticle of bc=8; requires maxControlRange=0;
};
class RC_8xCrocus_Deployer_Mag: RC_target_confirmer_AB_mag
{
	ammo="RC_Crocus_Deployer_Ammo";
	count=8;
};
class RC_6xCrocus_Deployer_Mag: RC_8xCrocus_Deployer_Mag
{
	count=6;
};
class RC_18xCrocus_Deployer_UGV_Mag: RC_8xCrocus_Deployer_Mag
{
	initSpeed=1000;		//only to prevent scorch mark on ground below the vic
	count=18;
};
class RC_8xCrocus_Deployer_UGV_Mag: RC_18xCrocus_Deployer_UGV_Mag
{
	count=8;
};
class RC_6xCrocus_Deployer_UGV_Mag: RC_18xCrocus_Deployer_UGV_Mag
{
	count=6;
};
*/