class Twin_Cannon_20mm_gunpod;
class RC_Twin_Cannon_20mm_gunpod_slow_core: Twin_Cannon_20mm_gunpod
{
	class manual;
};
class RC_Twin_Cannon_gunpod_slow: RC_Twin_Cannon_20mm_gunpod_slow_core
{
	allowTabLock=1;
	canLock=2;
	weaponLockDelay=0;
	weaponLockSystem=0;
	lockAcquire=0;						//manual
	ballisticsComputer="4 + 8";
	//ballisticsComputer="1";
	
	/*
	showAimCursorInternal=0;
	nameSound="cannon";
	cursor="EmptyCursor";
	cursorAim="mg";
	*/

	class manual: manual
	{
		dispersion=0.003;				//0.003

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
class RC_Twin_Cannon_20mm_gunpod_slow: RC_Twin_Cannon_gunpod_slow
{
	displayName="20mm AC";
	displayNameShort="20mm AC";

	magazines[]=
	{
		"RC_PylonWeapon_300Rnd_20mm_shells_slow"
	};
	class manual: manual
	{
		displayName="20mm AC";
		displayNameShort="20mm AC";
		reloadTime=0.125;				//0.04
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
		reloadTime=0.1375;				//0.04
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
		reloadTime=0.15;				//0.04
	};
};