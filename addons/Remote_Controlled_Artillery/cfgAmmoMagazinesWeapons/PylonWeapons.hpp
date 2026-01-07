class Twin_Cannon_20mm_gunpod;
class RC_Twin_Cannon_20mm_gunpod_slow_core: Twin_Cannon_20mm_gunpod
{
	class manual;
};
class RC_Twin_Cannon_gunpod_slow: RC_Twin_Cannon_20mm_gunpod_slow_core
{
	displayName="Autocannon";
	displayNameShort="Autocannon";

	allowTabLock=1;
	canLock=2;
	weaponLockDelay=0;
	weaponLockSystem=0;
	lockAcquire=0;						//manual
	ballisticsComputer="8";				//4 + 8, test 1 more
	
	/*
	showAimCursorInternal=0;
	nameSound="cannon";
	cursor="EmptyCursor";
	cursorAim="mg";
	*/

	magazines[]=
	{
		"RC_PylonWeapon_300Rnd_20mm_shells_slow",
		//"RC_PylonWeapon_300Rnd_20mm_shells_slow_Aegis",
		"RC_PylonWeapon_200Rnd_25mm_shells_slow",
		"RC_PylonWeapon_150Rnd_30mm_shells_slow"
	};

	modes[]=
	{
		"manual"
	};
	class manual: manual
	{
		displayName="Autocannon";
		displayNameShort="Autocannon";
		reloadTime=0.1;					//0.04
		
		dispersion=0.0018;				//0.003		//0.018 Aegis
		allowTabLock=1;
		canLock=2;
		weaponLockDelay=0;
		burst=2;						//5
		autoFire=1;
		textureType="fullAuto";

		/*
		ballisticsComputer="1 + 2 + 16";
		maxZeroing=2500;				//2500
		FCSMaxLeadSpeed=30.555599;
		FCSZeroingDelay=0.5;
		*/
	};
};


class missiles_DAR;
class RC_Pylon_12Rnd_70mm_Hydra_RocketPod_Core: missiles_DAR
{
	class Burst;
};
class RC_Pylon_12Rnd_70mm_Hydra_RocketPod: RC_Pylon_12Rnd_70mm_Hydra_RocketPod_Core
{
	displayName="70mm Hydra Pod";
	displayNameShort="70mm Hydra Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonRack_12Rnd_70mm_Hydra"
	};
	modes[]=
	{
		"Burst"
	};
	class Burst: Burst
	{
		reloadTime=0.15;
	};
};
class missiles_DAGR;
class RC_Pylon_12Rnd_APKWS_RocketPod_Core: missiles_DAGR
{
	class Burst;
};
class RC_Pylon_12Rnd_APKWS_RocketPod: RC_Pylon_12Rnd_APKWS_RocketPod_Core
{
	// TEST WITHOUT ACE

	displayName="APKWS LG Pod";
	displayNameShort="APKWS LG Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonRack_12Rnd_APKWS"
	};
	modes[]=
	{
		"Burst"
	};
	class Burst: Burst
	{
		reloadTime=0.15;
	};

	//ace guidance
	ace_laser_canSelect=1; 	// can ace_laser lock (allows switching laser code)
	ace_laser_showHud=1; 	// show attack profile / lock on hud
	autoFire=0;
	canLock=0;
	weaponLockSystem=0;
	lockingTargetSound[]={"",0,1};
	lockedTargetSound[]={"",0,1};
};
//EF_PylonMissile_Titan_NLOS_2Rnd  pylonWeapon = "EF_Weapon_Titan_NLOS";	 hardpoints[] = {"TITAN_NLOS_2RND"};	ammo = "EF_Ammo_Titan_NLOS";