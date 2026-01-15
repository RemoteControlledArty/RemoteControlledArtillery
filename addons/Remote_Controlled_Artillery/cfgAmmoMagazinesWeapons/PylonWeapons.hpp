class Twin_Cannon_20mm_gunpod;
class RC_PylonW_TwinCannon_20mm_Core: Twin_Cannon_20mm_gunpod
{
	class manual;
};
class RC_PylonW_TwinCannon: RC_PylonW_TwinCannon_20mm_Core
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
		//"RC_PylonM_300Rnd_20mm_Aegis",
		"RC_PylonM_300Rnd_20mm",
		"RC_PylonM_250Rnd_25mm",
		//"RC_PylonM_200Rnd_25mm",
		"RC_PylonM_200Rnd_30mm",
		//"RC_PylonM_150Rnd_30mm"
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
		ballisticsComputer="8";				//4 + 8, test 1 more
		
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
class RC_PylonW_12Rnd_70mm_Hydra_Core: missiles_DAR
{
	class Burst;
};
class RC_PylonW_12Rnd_70mm_Hydra: RC_PylonW_12Rnd_70mm_Hydra_Core
{
	displayName="70mm Hydra Pod";
	displayNameShort="70mm Hydra Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_12Rnd_70mm_Hydra_HE",
		"RC_PylonM_12Rnd_70mm_Hydra_MP"
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


//unify 70mm rocket pods?
class rockets_Skyfire;
class RC_PylonW_19Rnd_70mm_Hydra_Core: rockets_Skyfire
{
	class Burst;
};
class RC_PylonW_19Rnd_70mm_Hydra: RC_PylonW_19Rnd_70mm_Hydra_Core
{
	displayName="70mm Hydra Pod";
	displayNameShort="70mm Hydra Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_19Rnd_70mm_Hydra_HE",
		"RC_PylonM_19Rnd_70mm_Hydra_MP"
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
class RC_PylonW_APKWS_Core: missiles_DAGR
{
	class Burst;
};
class RC_PylonW_APKWS: RC_PylonW_APKWS_Core
{
	// TEST WITHOUT ACE

	displayName="APKWS LG Pod";
	displayNameShort="APKWS LG Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_12Rnd_APKWS",
		"RC_PylonM_7Rnd_APKWS"
	};
	modes[]=
	{
		"Burst"
	};
	class Burst: Burst
	{
		ballisticsComputer=8;
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


class RocketPods;
class RC_PylonW_Hellfire: RocketPods
{
	// TEST WITHOUT ACE

	displayName="Hellfire";
	displayNameShort="Hellfire";
	magazines[]={"RC_PylonM_2Rnd_AGM114K","RC_PylonM_1Rnd_AGM114K"};

	ace_hellfire_enabled=1; // handle adding interactions and adding laser designator
	ace_laser_canSelect=1; 	// allows switching laser code
	ace_laser_showHud=1; 	// show attack profile / lock on hud
	autoFire=0;
	canLock=0;
	weaponLockSystem=0;
	lockingTargetSound[]={"",0,1};
	lockedTargetSound[]={"",0,1};
	soundFly[]={"A3\Sounds_F\weapons\Rockets\rocket_fly_1",1,1.1,700};
	nameSound="MissileLauncher";
	sounds[]={"StandardSound"};
	cursor="EmptyCursor";
	cursorAim="missile";
	showAimCursorInternal=0;

	class StandardSound
	{
		begin1[]={"A3\Sounds_F\weapons\Rockets\missile_1",1.12202,1.3,1000};
		soundBegin[]={"begin1",1};
		soundsetshot[]={"RocketsMedium_Shot_SoundSet"};
	};
};