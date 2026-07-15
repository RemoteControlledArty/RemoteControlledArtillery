//minigun
class M134_minigun;
class RC_PylonW_338_Minigun_Base: M134_minigun
{
	class HighROF;
};
class RC_PylonW_338_Minigun: RC_PylonW_338_Minigun_Base
{
	displayName=".338NM Minigun";
	displayNameShort=".338NM Minigun";
	ballisticsComputer=8;
	magazines[]=
	{
		"RC_PylonM_3000Rnd_338_SLAP_T_R",
		"RC_PylonM_3000Rnd_338_SLAP_T_G",
		"RC_PylonM_3000Rnd_338_SLAP_T_Y"
	};
	modes[]=
	{
		"HighROF","close","short","medium","far"
	};
	class HighROF: HighROF
	{
		displayName=".338NM";
		displayNameShort=".338NM";
	};
};


//autocannon
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
	ballisticsComputer="8";				//4+8, test 1 more
	
	/*
	showAimCursorInternal=0;
	nameSound="cannon";
	cursor="EmptyCursor";
	cursorAim="mg";
	*/

	magazines[]=
	{
		//"RC_PylonM_300Rnd_20mm_Aegis",
		"RC_PylonM_350Rnd_20mm",
		"RC_PylonM_300Rnd_25mm",
		"RC_PylonM_250Rnd_30mm",
		"RC_PylonM_250Rnd_20mm_Proxy",
		"RC_PylonM_250Rnd_25mm_Proxy",
		"RC_PylonM_250Rnd_30mm_Proxy"
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
		ballisticsComputer="8";			//4+8, test 1 more
		
		dispersion=0.0018;				//0.003		//0.018 Aegis
		allowTabLock=1;
		canLock=2;
		weaponLockDelay=0;
		burst=2;						//5
		autoFire=1;
		textureType="fullAuto";

		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_vehicles\cannon_30mm\autocannon_30mm_01",
				1.9952624,
				1,
				1500
			};
			begin2[]=
			{
				"A3\Sounds_F\arsenal\weapons_vehicles\cannon_30mm\autocannon_30mm_02",
				1.9952624,
				1,
				1500
			};
			begin3[]=
			{
				"A3\Sounds_F\arsenal\weapons_vehicles\cannon_30mm\autocannon_30mm_03",
				1.9952624,
				1,
				1500
			};
			soundBegin[]=
			{
				"begin1",
				0.33000001,
				"begin2",
				0.33000001,
				"begin3",
				0.34
			};
			/*
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_vehicles\gatling_20mm\20mm_01_burst",
				1.7782794,
				1,
				1300,
				{2,35740}
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
			*/
		};

		/*
		ballisticsComputer="1 + 2 + 16";
		maxZeroing=2500;				//2500
		FCSMaxLeadSpeed=30.555599;
		FCSZeroingDelay=0.5;
		*/
	};
};
class RC_PylonW_TwinCannon_Lead: RC_PylonW_TwinCannon
{
	displayName="Lead Autocannon";
	displayNameShort="Lead Autocannon";
	ballisticsComputer="4+8";	//projected reticle on ground if not locked & lead indicator if locked
	magazines[]=
	{
		"RC_PylonM_350Rnd_20mm_Lead",
		"RC_PylonM_300Rnd_25mm_Lead",
		"RC_PylonM_250Rnd_30mm_Lead",
		"RC_PylonM_250Rnd_20mm_Proxy_Lead",
		"RC_PylonM_250Rnd_25mm_Proxy_Lead",
		"RC_PylonM_250Rnd_30mm_Proxy_Lead"
	};
};


class RC_PylonW_Avtopushka: RC_PylonW_TwinCannon
{
	displayName="Avtopushka";
	displayNameShort="Avtopushka";

	magazines[]=
	{
		"RC_PylonM_350Rnd_20mm_O",
		"RC_PylonM_300Rnd_25mm_O",
		"RC_PylonM_250Rnd_30mm_O",
		"RC_PylonM_350Rnd_20mm_Proxy_O",
		"RC_PylonM_300Rnd_25mm_Proxy_O",
		"RC_PylonM_250Rnd_30mm_Proxy_O"
	};
	class manual: manual
	{
		displayName="Avtopushka";
		displayNameShort="Avtopushka";
	};
};
class RC_PylonW_Avtopushka_Lead: RC_PylonW_Avtopushka
{
	displayName="Lead Avtopushka";
	displayNameShort="Lead Avtopushka";
	ballisticsComputer="4+8";	//projected reticle on ground if not locked & lead indicator if locked
	magazines[]=
	{
		"RC_PylonM_350Rnd_20mm_Lead_O",
		"RC_PylonM_300Rnd_25mm_Lead_O",
		"RC_PylonM_250Rnd_30mm_Lead_O",
		"RC_PylonM_350Rnd_20mm_Proxy_Lead_O",
		"RC_PylonM_300Rnd_25mm_Proxy_Lead_O",
		"RC_PylonM_250Rnd_30mm_Proxy_Lead_O"
	};
};


//unguided rockets
class missiles_DAR;
class RC_PylonW_12Rnd_Hydra_Core: missiles_DAR
{
	class Burst;
};
class RC_PylonW_12Rnd_Hydra: RC_PylonW_12Rnd_Hydra_Core
{
	displayName="70mm Hydra Pod";
	displayNameShort="70mm Hydra Pod";
	ballisticsComputer=8;
	canLock=2;

	magazines[]=
	{
		"RC_PylonM_12Rnd_Hydra_MP"
		//"RC_PylonM_12Rnd_Hydra_HE"
	};
	modes[]=
	{
		"Burst",
		"Far_AI",
		"Medium_AI"
	};
	class Burst: Burst
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
		dispersion=0.006;	//0.015
	};
};
class RC_PylonW_12Rnd_Hydra_Proxy: RC_PylonW_12Rnd_Hydra
{
	//ballisticsComputer="4+8";	//4 doesnt correctly predict for rocket acceleration
	magazines[]=
	{
		"RC_PylonM_12Rnd_Hydra_MP_Proxy"
	};
};
class RC_PylonW_12Rnd_S5: RC_PylonW_12Rnd_Hydra
{
	displayName="55mm S-5 UB-12";
	displayNameShort="55mm S-5 UB-12";
	magazines[]=
	{
		"RC_PylonM_12Rnd_S5_MP"
		//"RC_PylonM_12Rnd_S5_HE"
	};
	class Burst: Burst
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
};
class RC_PylonW_12Rnd_S5_Proxy: RC_PylonW_12Rnd_S5
{
	//ballisticsComputer="4+8";	//4 doesnt correctly predict for rocket acceleration
	magazines[]=
	{
		"RC_PylonM_12Rnd_S5_MP_Proxy"
	};
};


//unify 70mm rocket pods?
class rockets_Skyfire;
class RC_PylonW_19Rnd_Hydra_Core: rockets_Skyfire
{
	class Burst;
};
class RC_PylonW_19Rnd_Hydra: RC_PylonW_19Rnd_Hydra_Core
{
	displayName="70mm Hydra Pod";
	displayNameShort="70mm Hydra Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_19Rnd_Hydra_MP"
	};
	modes[]=
	{
		"Burst"
	};
	class Burst: Burst
	{
		displayName="Hydra";
		displayNameShort="Hydra";
		reloadTime=0.15;
	};
};
class RC_PylonW_19Rnd_Hydra_Proxy: RC_PylonW_19Rnd_Hydra
{
	//ballisticsComputer="4+8";	//4 doesnt correctly predict for rocket acceleration
	magazines[]=
	{
		"RC_PylonM_19Rnd_Hydra_MP_Proxy"
	};
};


class RC_PylonW_19Rnd_S5: RC_PylonW_19Rnd_Hydra
{
	displayName="55mm S-5 UB-19";
	displayNameShort="55mm S-5 UB-19";
	magazines[]=
	{
		"RC_PylonM_19Rnd_S5_MP"
		//"RC_PylonM_19Rnd_S5_HE"
	};
	class Burst: Burst
	{
		displayName="S-5";
		displayNameShort="S-5";
	};
};
class RC_PylonW_19Rnd_S5_Proxy: RC_PylonW_19Rnd_S5
{
	//ballisticsComputer="4+8";	//4 doesnt correctly predict for rocket acceleration
	magazines[]=
	{
		"RC_PylonM_19Rnd_S5_MP_Proxy"
	};
};


//light guided
class missiles_DAGR;
class RC_PylonW_APKWS_Core: missiles_DAGR
{
	class Burst;
};
class RC_PylonW_APKWS: RC_PylonW_APKWS_Core
{
	// TEST effect WITHOUT ACE
	displayName="APKWS LG Pod";
	displayNameShort="APKWS LG Pod";
	ballisticsComputer=8;

	magazines[]=
	{
		"RC_PylonM_12Rnd_APKWS",
		//"RC_PylonM_12Rnd_APKWS_cUAS",
		"RC_PylonM_7Rnd_APKWS"
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
/*
class RC_PylonW_APKWS_Proxy: RC_PylonW_APKWS
{
	//ballisticsComputer="4+8";	//doesnt work for missiles
	magazines[]=
	{
		"RC_PylonM_12Rnd_APKWS_Proxy",
		"RC_PylonM_7Rnd_APKWS_Proxy"
	};
};
*/


class RC_PylonW_S8_LG: RC_PylonW_APKWS
{
	displayName="S-8 LG Ugroza";
	displayNameShort="S-8 LG Ugroza";
	magazines[]=
	{
		"RC_PylonM_12Rnd_S8_LG"
	};
};
/*
class RC_PylonW_S8_LG_Proxy: RC_PylonW_APKWS
{
	//ballisticsComputer="4+8";	//doesnt work for missiles
	magazines[]=
	{
		"RC_PylonM_12Rnd_S8_LG_Proxy"
	};
};
*/


//heavy guided
class RocketPods;
class RC_PylonW_Hellfire: RocketPods
{
	// TEST WITHOUT ACE

	displayName="Hellfire";
	displayNameShort="Hellfire";
	magazines[]=
	{
		"RC_PylonM_3Rnd_AGM114K",
		"RC_PylonM_2Rnd_AGM114K",
		"RC_PylonM_1Rnd_AGM114K"
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
/*
class RC_PylonW_Hellfire_Proxy: RC_PylonW_Hellfire
{
	magazines[]=
	{
		"RC_PylonM_3Rnd_AGM114K_Proxy",
		"RC_PylonM_2Rnd_AGM114K_Proxy",
		"RC_PylonM_1Rnd_AGM114K_Proxy"
	};
};
*/


class RC_PylonW_Vikhr: RC_PylonW_Hellfire
{
	displayName="9K121 Vikhr";
	displayNameShort="9K121 Vikhr";
	magazines[]=
	{
		"RC_PylonM_3Rnd_Vikhr",
		"RC_PylonM_1Rnd_Vikhr"
	};
};
/*
class RC_PylonW_Vikhr_Proxy: RC_PylonW_Vikhr
{
	magazines[]=
	{
		"RC_PylonM_3Rnd_Vikhr_Proxy",
		"RC_PylonM_1Rnd_Vikhr_Proxy"
	};
};
*/