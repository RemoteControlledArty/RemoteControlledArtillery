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
		burst=1;						//5
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
	displayName="70mm Hydra";
	displayNameShort="70mm Hydra";
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

	/*
	displayName = "Hydra 70 12x HE";
	displayNameShort = "70mm HE";
	ammo = "M_AT";
	ballisticsComputer = 0;
	"PylonRack_12Rnd_missiles"
	pylonWeapon = "missiles_DAR";
	model = "\A3\Weapons_F\DynamicLoadout\PylonPod_12x_Rocket_DAR_F.p3d";
	hardpoints[] = {"B_MISSILE_PYLON","DAR"};
	*/
};


/*
class RC_Twin_Cannon_20mm_gunpod_slow: RC_Twin_Cannon_gunpod_slow
{
	displayName="20mm AC";
	displayNameShort="20mm AC";

	magazines[]=
	{
		"RC_PylonWeapon_300Rnd_20mm_shells_slow"
		//"RC_PylonWeapon_300Rnd_20mm_shells_slow_Aegis"
	};
	class manual: manual
	{
		displayName="20mm AC";
		displayNameShort="20mm AC";
		reloadTime=0.15;				//0.04
	};
};
class RC_Twin_Cannon_25mm_gunpod_slow: RC_Twin_Cannon_gunpod_slow
{
	displayName="25mm AC";
	displayNameShort="25mm AC";

	magazines[]=
	{
		"RC_PylonWeapon_200Rnd_25mm_shells_slow"
	};
	class manual: manual
	{
		displayName="25mm AC";
		displayNameShort="25mm AC";
		reloadTime=0.175;				//0.04
	};
};
class RC_Twin_Cannon_30mm_gunpod_slow: RC_Twin_Cannon_gunpod_slow
{
	displayName="30mm AC";
	displayNameShort="30mm AC";

	magazines[]=
	{
		"RC_PylonWeapon_150Rnd_30mm_shells_slow"
	};
	class manual: manual
	{
		displayName="30mm AC";
		displayNameShort="30mm AC";
		reloadTime=0.2;				//0.04
	};
};
*/
//EF_PylonMissile_Titan_NLOS_2Rnd  pylonWeapon = "EF_Weapon_Titan_NLOS";	 hardpoints[] = {"TITAN_NLOS_2RND"};	ammo = "EF_Ammo_Titan_NLOS";