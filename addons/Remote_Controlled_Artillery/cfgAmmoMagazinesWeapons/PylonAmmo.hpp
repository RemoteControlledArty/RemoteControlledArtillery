class M_PG_AT;
class RC_APKWS: M_PG_AT
{
	//indirectHit=40;
	indirectHitRange=5;	//3.2

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
		seekerMaxRange=4000;
		seekerAccuracy=1;
		seekerAngle=45;
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


class M_AT;
class RC_Hydra_MP: M_AT
{
	submunitionAmmo="ammo_Penetrator_PG_AT";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;

	hit=95;
	indirectHit=40;
	indirectHitRange=8;

	airLock=0;		//0
	irLock=0;		//0
	laserLock=0;	//0
	nvLock=0;		//0
};