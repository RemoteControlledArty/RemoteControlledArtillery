class M_PG_AT;
class RC_RHS_APKWS: M_PG_AT
{
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";

	//indirectHit=40;
	indirectHitRange=4.5;	//3.2

	ace_rearm_caliber=70;
	displayName="APKWS 4km";
	displayNameShort="APKWS 4km";
	description="APKWS 4km LG";
	descriptionShort="APKWS 4km LG";
	maxSpeed=290;

	manualControl=0;	//try 1
	//airlock=?;
	laserLock=0;		//1?
	irLock=0;

	class ace_missileguidance
	{
		enabled=1;
		canVanillaLock=0;
		seekerMinRange=1;
		seekerMaxRange=5000;	//4000
		seekerAccuracy=1;
		seekerAngle=60;			//45
		incDeflection=0.0005;
		minDeflection=0.0005;
		maxDeflection=0.0025;

		defaultAttackProfile="LIN";
		attackProfiles[]={"LIN"};
		defaultSeekerType="SALH";
		seekerTypes[]={"SALH"};
		defaultSeekerLockMode="LOAL";
		seekerLockModes[]={"LOAL"};
	};
};


/*
class RC_APKWS;
class RC_RHS_APKWS: RC_APKWS
{
	//model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";
};
*/