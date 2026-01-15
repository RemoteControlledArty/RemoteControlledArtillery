class M_PG_AT;
class RC_RHS_APKWS: M_PG_AT
{
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";

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
class RC_APKWS;
class RC_RHS_APKWS: RC_APKWS
{
	//model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";
};
*/