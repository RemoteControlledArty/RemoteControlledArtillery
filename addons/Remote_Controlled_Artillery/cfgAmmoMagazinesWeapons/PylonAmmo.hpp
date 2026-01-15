class M_PG_AT;
class RC_APKWS: M_PG_AT
{
	//indirectHit=40;
	indirectHitRange=5;	//3.2
	fuseDistance=20;

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


class M_Scalpel_AT;
class RC_AGM114K: M_Scalpel_AT
{
	displayName="AGM-114K";
	displayNameShort="AGM-114K";
	description="AGM-114K";
	descriptionShort="AGM-114K";

	model="\A3\Weapons_F\Ammo\Missile_AT_03_fly_F";
	proxyShape="\A3\Weapons_F\Ammo\Missile_AT_03_F";
	effectsMissile="missile2";

	ace_rearm_caliber=178;

	//airLock=0;	//
	irLock=0;
	laserLock=0;
	manualControl=0;
	
	timeToLive=40;
	maxSpeed=440;
	thrust=250;
	thrustTime=2.5;

	class ace_missileguidance
	{
		enabled = 1;
		canVanillaLock=0;
		pitchRate=30;
		yawRate=30;
		seekLastTargetPos=1;
		seekerAccuracy=1;
		seekerAngle=70;
		seekerMaxRange=8000;
		seekerMinRange=1;

		attackProfiles[]={"hellfire","hellfire_hi","hellfire_lo"};
		defaultAttackProfile="hellfire";
		defaultNavigationType="Direct";
		defaultSeekerLockMode="LOAL";
		defaultSeekerType="SALH";
		navigationTypes[]={"Direct","ZeroEffortMiss"};
		seekerTypes[]={"SALH"};
		seekerLockModes[]={"LOAL","LOBL"};

		class navigationStates
		{
			states[]={"initial","terminal"};

			class initial
			{
				navigationType="Direct";
				transitionCondition="ace_hellfire_fnc_midCourseTransition";
			};
			class terminal
			{
				navigationType="ZeroEffortMiss";
				transitionCondition="";
			};
		};
	};
};


class M_AT;
class RC_Hydra_HE: M_AT
{
	fuseDistance=20;//50

	airLock=0;		//0
	irLock=0;		//0
	laserLock=0;	//0
	nvLock=0;		//0
};
class RC_Hydra_MP: RC_Hydra_HE
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
};