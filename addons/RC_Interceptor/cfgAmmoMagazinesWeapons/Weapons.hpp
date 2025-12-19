//throwable
class GrenadeLauncher;
class Throw: GrenadeLauncher {

	class ThrowMuzzle: GrenadeLauncher {};
	class Interceptor_MP_ThrowMuzzle: 			ThrowMuzzle {magazines[] = {"Interceptor_MP_Throw"};			};

	muzzles[]+=
	{
		"Interceptor_MP_ThrowMuzzle"
	};
};


/*
class RC_target_confirmer;
class RC_target_confirmer_AB_weapon: RC_target_confirmer
{
	displayName="MP airburst";
	displayNameShort="MP airburst";
	scope=1;
	canLock=2;
	weaponLockDelay=0;
	//ballisticsComputer=8;	//8 reticle for shaped charge airburst; requires maxControlRange=0;
	reloadTime=1;
	magazineReloadTime=1;
	magazines[]=
	{
		"RC_target_confirmer_AB_mag"
	};
	modes[]=
	{
		"player"
	};
	class player: Mode_SemiAuto
	{
		displayName="MP airburst";
		//ballisticsComputer=8;	//8 reticle for shaped charge airburst, requires maxControlRange=0;
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Release_01",
				3.9810717,
				1,
				20
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
		};
		showToPlayer=1;

		aiRateOfFire=100000;	//too not make AI fire itself when it flies in direction of laser target per waypoint
		aiRateOfFireDispersion=0;
		aiRateOfFireDistance=0;
		aiDispersionCoefY=0;
		aiDispersionCoefX=0;
		minRangeProbab=0;
		midRangeProbab=0;
		maxRangeProbab=0;
	};
};
class RC_shapedcharge_reticle_AB_weapon: RC_target_confirmer_AB_weapon
{
	displayName="MP airburst reticle";
	displayNameShort="MP airburst reticle";
	ballisticsComputer=8;	//reticle for shaped charge airburst; requires maxControlRange=0;
	magazines[]=
	{
		"RC_shapedcharge_reticle_AB_mag"
	};
	class player: player
	{
		ballisticsComputer=8;	//reticle for shaped charge airburst, requires maxControlRange=0;
	};
};


class RC_Crocus_Deployer: RC_target_confirmer_AB_weapon
{
	displayName="deploy Crocus";
	displayNameShort="deploy Crocus";
	reloadTime=3.5;
	magazineReloadTime=3.5;
	magazines[]=
	{
		"RC_8xCrocus_Deployer_Mag",
		"RC_6xCrocus_Deployer_Mag",
		"RC_18xCrocus_Deployer_UGV_Mag",
		"RC_8xCrocus_Deployer_UGV_Mag",
		"RC_6xCrocus_Deployer_UGV_Mag"
	};
	class player: player
	{
		displayName="deploy Crocus";
		reloadTime=3.5;
	};
};
*/