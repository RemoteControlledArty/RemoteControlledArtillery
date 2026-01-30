class M_PG_AT;
class RC_RHS_APKWS: M_PG_AT
{
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";

	/*
	//maybe modify to increase accuracy while not fully aligned
	maneuvrability=8;
	airFriction=0.1;
	sideAirFriction=0.16;
	initTime=0;
	*/

	thrustTime=2.14;	//1.07 doubled to cancel thrust halving
	thrust=412.5;		//825 halved to increase accuracy
	
	//indirectHit=40;
	indirectHitRange=4.5;	//3.2
	fuseDistance=20;

	ace_rearm_caliber=70;
	displayName="APKWS 4km";
	displayNameShort="APKWS";
	description="APKWS LG";
	descriptionShort="APKWS LG";
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
class RC_RHS_AGM114K: M_Scalpel_AT
{
	displayName="AGM-114K";
	displayNameShort="AGM-114K";
	description="AGM-114K";
	descriptionShort="AGM-114K";

	model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
	effectsMissile="rhs_missile2";

	ace_rearm_caliber=178;

	//airLock=0;	//
	irLock=0;
	laserLock=0;
	manualControl=0;
	
	fuseDistance=50;
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


class RC_Hydra_MP;
class RC_RHS_Hydra_MP: RC_Hydra_MP
{
	model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";
};


/*
class rhs_ammo_Hydra_M229;
class RC_RHS_Hydra_MP: rhs_ammo_Hydra_M229
{
	//simulation="shotMissile";
	simulation="shotRocket";

	fuseDistance=20;//50
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
*/


class rhs_ammo_Hydra_M229;
{
	access = 3;
	ACE_damageType = "explosive";
	ace_frag_charge = 1040;
	ace_frag_classes[] = {"ace_frag_medium","ace_frag_medium_HD"};
	ace_frag_gurney_c = 2700;
	ace_frag_gurney_k = 0.5;
	ace_frag_metal = 3850;
	ace_frag_skip = 0;
	ace_rearm_caliber = 70;
	ace_rearm_dummy = "ace_rearm_Rocket_04_HE_F";
	ace_vehicle_damage_incendiary = 0.4;
	afMax = 200;
	aiAmmoUsageFlags = "64 + 128";
	airFriction = 0.09;	//0.1
	airLock = 0;
	animated = 0;
	artilleryCharge = 1;
	artilleryDispersion = 1;
	artilleryLock = 0;
	audibleFire = 32;
	autoSeekTarget = 0;	
	caliber = 1;
	cartridge = "";
	cmImmunity = 0.9;	//0.3
	cost = 75;	//100
	CraterEffects = "ATMissileCrater";
	craterShape = "";
	craterWaterEffects = "ImpactEffectsWater";
	dangerRadiusBulletClose = -1;
	dangerRadiusHit = -1;
	deflecting = 0;
	deflectionSlowDown = 0.8;
	directionalExplosion = 0;
	explosionAngle = 60;
	explosionDir = "explosionDir";
	explosionEffects = "ATMissileExplosion";
	explosionEffectsDir = "explosionDir";
	explosionForceCoef = 1;
	explosionPos = "explosionPos";
	explosionSoundEffect = "DefaultExplosion";
	explosionTime = 0;
	explosionType = "explosive";
	explosive = 1;	
	fuseDistance = 40;
	hit = 220;	//300
	htMax = 1800;
	htMin = 60;
	icon = "";
	indirectHit = 50;
	indirecthitrange = 15;	//8
	initTime = 0.002;		//0
	irLock = 0;
	isCraterOriented = 0;
	laserLock = 0;
	lockSeekRadius = 100;	//1000
	lockType = 0;
	maneuvrability = 0;
	manualControl = 0;
	maverickweapon = 1;	//no entry
	maverickWeaponIndexOffset = 0;
						//maxControlRange = 0;
	maxSpeed = 740;	//720
	mFact = 0;
	mfMax = 100;
	minDamageForCamShakeHit = 0.55;
	minimumSafeZone = 0.1;
	minTimeToLive = 0;
	missileLockCone = 50;	//60
	missileLockMaxDistance = 3000;	//5000
									//missileLockMaxSpeed = 35;
	missileLockMinDistance = 500;	//100
									//missileManualControlCone = 240;
	nvLock = 0;
	shadow = 0;
	shootDistraction = -1;
	sideAirFriction = 0.004;		//0.005
	simulation = "shotMissile";		//shotRocket
	simulationStep = 0.01;			//simulationStep = 0.05;
	submunitionAmmo = "";
									//submunitionDirectionType = "";
									//submunitionInitialOffset[] = {0,0,0};
									//submunitionInitSpeed = 0;
									//submunitionParentSpeedCoef = 0;
	suppressionRadiusBulletClose = -1;
	suppressionRadiusHit = 30;
	tBody = 0;
	thrust = 800;					//825
	thrustTime = 1.1;				//1.07
	timeToLive = 60;				//20
	trackLead = 1;
	trackOversteer = 1;
	typicalSpeed = 900;
	underwaterHitRangeCoef = 1;
	visibleFire = 32;
	visibleFireTime = 20;
	warheadName = "HE";
	waterEffectOffset = 0.45;
	weaponLockSystem = 0;
	weaponType = "Default";
	whistleDist = 24;				//4
	whistleOnFire = 0;
};



/*
class RC_APKWS;
class RC_RHS_APKWS: RC_APKWS
{
	//model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";
};
*/