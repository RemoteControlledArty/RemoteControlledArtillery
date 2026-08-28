//light guided
class missiles_DAGR;
class RC_PylonW_APKWS_Core: missiles_DAGR
{
	class Burst;
};
class RC_PylonW_APKWS: RC_PylonW_APKWS_Core
{
	displayName="APKWS LG Pod";
	displayNameShort="APKWS LG Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_12Rnd_APKWS",
		//"RC_PylonM_12Rnd_APKWS_cUAS",
		"RC_PylonM_7Rnd_APKWS",
		"RC_RHS_PylonM_7Rnd_APKWS",

		"RC_PylonM_12Rnd_APKWS_Proxy",
		"RC_PylonM_7Rnd_APKWS_Proxy"
	};
	modes[]=
	{
		"Burst"
	};
	class Burst: Burst
	{
		displayName="APKWS";
		displayNameShort="APKWS";
		ballisticsComputer=8;
		reloadTime=0.15;
	};

	//ace guidance
	ace_laser_canSelect=1; 	// can ace_laser lock (allows switching laser code)
	ace_laser_showHud=1; 	// show attack profile / lock on hud
	autoFire=0;
	canLock=0;				// 2 for missile locking
	weaponLockSystem=0;
	lockingTargetSound[]={"",0,1};
	lockedTargetSound[]={"",0,1};
};


class RC_PylonW_S8_LG: RC_PylonW_APKWS
{
	displayName="S-8 LG Ugroza";
	displayNameShort="S-8 LG Ugroza";
	magazines[]=
	{
		"RC_PylonM_12Rnd_S8_LG",
		"RC_PylonM_7Rnd_S8_LG",

		"RC_PylonM_12Rnd_S8_LG_Proxy"
	};
};


//heavy guided
class RocketPods;
class RC_PylonW_Hellfire: RocketPods
{
	displayName="Hellfire";
	displayNameShort="Hellfire";
	magazines[]=
	{
		"RC_PylonM_4Rnd_AGM114K",
		"RC_PylonM_3Rnd_AGM114K",
		"RC_PylonM_2Rnd_AGM114K",
		"RC_PylonM_1Rnd_AGM114K",

		"RC_PylonM_3Rnd_AGM114K_Proxy",
		"RC_PylonM_2Rnd_AGM114K_Proxy",
		"RC_PylonM_1Rnd_AGM114K_Proxy"
	};

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


class RC_PylonW_Vikhr: RC_PylonW_Hellfire
{
	displayName="9K121 Vikhr";
	displayNameShort="9K121 Vikhr";
	magazines[]=
	{
		"RC_PylonM_3Rnd_Vikhr",
		"RC_PylonM_1Rnd_Vikhr",

		"RC_PylonM_3Rnd_Vikhr_Proxy",
		"RC_PylonM_1Rnd_Vikhr_Proxy"
	};
};