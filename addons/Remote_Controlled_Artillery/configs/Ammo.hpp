//ATGM
class ammo_Penetrator_Vorona;
class RC_Penetrator_ATGM: ammo_Penetrator_Vorona
{
	hit=1000;
};


//82mm
class Sh_82mm_AMOS;
class RC_Sh_82mm_AMOS_submunition: Sh_82mm_AMOS
{
	explosionTime=0.01;
	explosive=1;
	CraterEffects="";
};
class RC_Sh_82mm_AMOS_HEAB: Sh_82mm_AMOS
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-16.1};		//high airburst to ignore cover very well
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_82mm_AMOS_HEAB_low: RC_Sh_82mm_AMOS_HEAB
{
	submunitionInitialOffset[]={0,0,-6};		//low airburst to ignore atleast microterrain
};


class Smoke_120mm_AMOS_White;
class RC_Smoke_82mm_AMOS_White: Smoke_120mm_AMOS_White
{
	model="\A3\weapons_f\ammo\shell";
	submunitionAmmo="SmokeShellArty";
	submunitionConeType[]=
	{
		"poissondisc",
		3
	};
	submunitionConeAngle=10;
	triggerDistance=50;
	cost=200;
	airFriction=0;
	muzzleEffect="";
	hit=165;
	class CamShakeFire
	{
		power=3.0092199;
		duration=1.8;
		frequency=20;
		distance=72.4431;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};


class M_Mo_82mm_AT;
class RC_M_Mo_82mm_AT: M_Mo_82mm_AT
{
	hit=450;
	indirectHit=100;
	indirectHitRange=4;
};
class Sh_82mm_AMOS_guided;
class RC_Sh_82mm_AMOS_guided: Sh_82mm_AMOS_guided
{
	submunitionAmmo="RC_M_Mo_82mm_AT";
};


class M_Mo_82mm_AT_LG;
class RC_M_Mo_82mm_AT_LG: M_Mo_82mm_AT_LG
{
	hit=450;
	indirectHit=100;
	indirectHitRange=4;
};
class Sh_82mm_AMOS_LG;
class RC_Sh_82mm_AMOS_LG: Sh_82mm_AMOS_LG
{
	submunitionAmmo="RC_M_Mo_82mm_AT_LG";
};


class RC_M_Mo_82mm_LGDF_submunition: M_Mo_82mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,1.8};	//1.8m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_82mm_AMOS_LGDF: Sh_82mm_AMOS_LG
{
	submunitionAmmo="RC_M_Mo_82mm_LGDF_submunition";
};


class Mo_ClassicMineRange;
class RC_Mo_ClassicMineRange: Mo_ClassicMineRange
{
	submunitionAmmo="APERSBoundingMine_Range_Ammo";
};
class SubmunitionBase;
class RC_Mine_82mm_AMOS_range: SubmunitionBase
{
	submunitionAmmo="RC_Mo_ClassicMineRange";
	submunitionConeType[]=
	{
		"poissondisc",
		12
	};
	submunitionConeAngle=20;
	triggerDistance=50;
	cost=200;
	airFriction=0;
	muzzleEffect="";
	hit=165;
	class CamShakeFire
	{
		power=3.0092199;
		duration=1.8;
		frequency=20;
		distance=72.4431;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};


class RC_AT_Mine_82mm_AMOS_range: SubmunitionBase
{
	submunitionAmmo="Mo_ATMineRange";
	submunitionConeType[]=
	{
		"poissondisc",
		6
	};
	submunitionConeAngle=20;
	triggerDistance=50;
	cost=200;
	airFriction=0;
	muzzleEffect="";
	hit=165;
	class CamShakeFire
	{
		power=3.0092199;
		duration=1.8;
		frequency=20;
		distance=72.4431;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};


class MissileBase;
class MissileBase_base: MissileBase
{
	class Components;
};
class RC_M_Mo_82mm_AT_MultiGuided: MissileBase_base
{
	model="\A3\weapons_f\ammo\shell";
	autoSeekTarget=1;
	proximityExplosionDistance=1; 	//might prevent overshot miss

	//lockSeekRadius=32000;	//default 100, but that might be manual fire problem "Specifies the maximum distance from the initial target position where the missile will search for suitable targets if it has autoSeekTarget enabled."
	trackLead=1;
	airLock=0;
	laserLock=1; //from main shell
	irLock=1;
	canLock=2; //always locks
	lockAcquire=1;	//automatic acquisition of the closest target in missileLockCone

	receiveRemoteTargets=1;

	maneuvrability=12;	//6
	simulationStep=0.0020000001;
	fuseDistance=0;
	airFriction=0.0099999998;
	sideAirFriction=0.029999999;
	missileLockCone=40;
	missileKeepLockedCone=40;

	hit=400;
	indirectHit=400;
	indirectHitRange=5;
	EffectFly="ArtilleryTrails";
	cameraViewAvailable=1;

	weaponLockSystem="1+2+4";	//visual, ir, laser
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};
};

/*
class RC_M_Mo_155mm_LGDF_submunition: M_Mo_155mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,1.8};	//1.8m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
*/

class RC_Sh_82mm_AMOS_AT_MultiGuided: SubmunitionBase
{
	submunitionAmmo="RC_M_Mo_155mm_AT_MultiGuided";
	submunitionCount=1;		//2
	submunitionConeAngle=0;
	triggerDistance=500;
	laserLock=1;
	irLock=1;
	autoSeekTarget=1;

	muzzleEffect="";
	hit=165;
	cost=500;
	airFriction=0;

	class CamShakeFire
	{
		power=3.0092199;
		duration=1.8;
		frequency=20;
		distance=72.4431;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};


//155mm
class F_40mm_White;
class RC_Mo_Illum: F_40mm_White
{
	triggerTime=0;
	model="\A3\Weapons_F\Ammo\UGL_Flare";
	brightness=8000;
	intensity=80000;
	lightColor[]={100,100,100,100};
	timeToLive=120;
};
class Flare_155mm_AMOS_White: SubmunitionBase
{
	submunitionAmmo[]=
	{
		"RC_Mo_Illum",
		1
	};
	timeToLive=180;
	hit=9;
	indirectHit=0;
	indirectHitRange=0;
	explosive=0;
	ExplosionEffects="";
	CraterEffects="";
	soundHit[]=
	{
		"",
		0,
		1
	};
	whistleDist=0;
	aimAboveDefault=3;
	aimAboveTarget[]={360,400,500,640,720,800,850};
};


class Mine_155mm_AMOS_range;
class RC_Mine_155mm_AMOS_range: Mine_155mm_AMOS_range
{
	submunitionAmmo="RC_Mo_ClassicMineRange";
	submunitionConeType[]=
	{
		"poissondisccenter",
		24
	};
};


class AT_Mine_155mm_AMOS_range;
class RC_AT_Mine_155mm_AMOS_range: AT_Mine_155mm_AMOS_range
{
	submunitionConeType[]=
	{
		"custom",{{-5,0},{-3,0},{-1,0},{1,0},{3,0},{5,0} , {0,-5},{0,-3},{0,-1},{0,1},{0,3},{0,5}}
		//"poissondisccenter",
		//12
	};
};

//submunitionConeType[]={"custom",{{-5,0},{-3,0},{-1,0},{1,0},{3,0},{5,0} , {0,-5},{0,-3},{0,-1},{0,1},{0,3},{0,5}}};


class RC_Smoke_155mm_AMOS_White: Smoke_120mm_AMOS_White
{
	submunitionConeAngle=10;
	submunitionConeType[]=
	{
		"poissondisc",
		10
	};
};


/*
class RC_155mm_HEAB_test: Sh_155mm_AMOS
{
	triggerDistance=26.8;	//doesnt work
};
*/


class Sh_155mm_AMOS;
class RC_Sh_155mm_AMOS_submunition: Sh_155mm_AMOS
{
	explosionTime=0.01;
	explosive=1;
	CraterEffects="";	//removes ground impact animation
};
class RC_Sh_155mm_AMOS_HEAB: Sh_155mm_AMOS
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-20};		//20m high airburst to ignore cover very well
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_155mm_AMOS_HEAB_low: RC_Sh_155mm_AMOS_HEAB
{
	submunitionInitialOffset[]={0,0,-6};	//low airburst to ignore atleast microterrain
};


class M_Mo_155mm_AT_LG;
class RC_M_Mo_155mm_LGDF_submunition: M_Mo_155mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,1.8};	//1.8m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
class Sh_155mm_AMOS_LG;
class RC_Sh_155mm_AMOS_LGDF: Sh_155mm_AMOS_LG
{
	submunitionAmmo="RC_M_Mo_155mm_LGDF_submunition";
};


class Cluster_155mm_AMOS;
class RC_Cluster_155mm_AMOS: Cluster_155mm_AMOS
{
	submunitionConeType[]=
	{
		"poissondisc",	//even spread
		50
	};
};

//ATLG

/*
	class M_Mo_82mm_AT: MissileBase
	{
		model="\A3\weapons_f\ammo\shell";
		hit=160;
		indirectHit=50;
		indirectHitRange=8;
		autoSeekTarget=1;
		airLock=0;
		maneuvrability=6;
		simulationStep=0.0020000001;
		fuseDistance=0;
		airFriction=0.0099999998;
		sideAirFriction=0.029999999;
		weaponLockSystem=2;
		missileLockCone=40;
		missileKeepLockedCone=40;
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=500;
							maxRange=800;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=800;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=40;
						angleRangeVertical=40;
					};
				};
			};
		};
	};

	class Sh_82mm_AMOS_guided: SubmunitionBase
	{
		submunitionAmmo="M_Mo_82mm_AT";
		submunitionCount=1;
		submunitionConeAngle=0;
		laserLock=0;
		autoSeekTarget=1;
		cost=200;
		muzzleEffect="";
		triggerDistance=300;
		airFriction=0;
		hit=165;
		class CamShakeFire
		{
			power=3.0092199;
			duration=1.8;
			frequency=20;
			distance=72.4431;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};

	class Sh_82mm_AMOS_LG: Sh_82mm_AMOS_guided
	{
		submunitionAmmo="M_Mo_82mm_AT_LG";
		cost=500;
		laserLock=1;
		irLock=0;
		muzzleEffect="";
	};

	class M_Mo_120mm_AT: M_Mo_82mm_AT
	{
		hit=800;
		indirectHit=50;
		indirectHitRange=3;
		EffectFly="ArtilleryTrails";
		cameraViewAvailable=1;
	};
	class M_Mo_120mm_AT_LG: M_Mo_120mm_AT
	{
		weaponLockSystem=4;
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class LaserSensorComponent: SensorTemplateLaser
					{
						class AirTarget
						{
							minRange=800;
							maxRange=800;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=800;
							maxRange=800;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=40;
						angleRangeVertical=40;
					};
				};
			};
		};
	};

	class M_Mo_155mm_AT: M_Mo_120mm_AT
	{
		hit=1200;
		indirectHit=200;
		indirectHitRange=4;
	};
	class M_Mo_155mm_AT_LG: M_Mo_120mm_AT_LG
	{
		hit=1200;
		indirectHit=200;
		indirectHitRange=4;
	};


	class Sh_82mm_AMOS_guided: SubmunitionBase
	{
		submunitionAmmo="M_Mo_82mm_AT";
		submunitionCount=1;
		submunitionConeAngle=0;
		laserLock=0;
		autoSeekTarget=1;
		cost=200;
		muzzleEffect="";
		triggerDistance=300;
		airFriction=0;
		hit=165;
		class CamShakeFire
		{
			power=3.0092199;
			duration=1.8;
			frequency=20;
			distance=72.4431;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
	class Sh_82mm_AMOS_LG: Sh_82mm_AMOS_guided
	{
		submunitionAmmo="M_Mo_82mm_AT_LG";
		cost=500;
		laserLock=1;
		irLock=0;
		muzzleEffect="";
	};


	class Sh_155mm_AMOS_guided: Sh_82mm_AMOS_guided
	{
		submunitionAmmo="M_Mo_155mm_AT";
		muzzleEffect="";
		triggerDistance=500;
		hit=300;
	};
	class Sh_155mm_AMOS_LG: Sh_82mm_AMOS_LG
	{
		submunitionAmmo="M_Mo_155mm_AT_LG";
		muzzleEffect="";
		triggerDistance=500;
		hit=300;
	};
*/

/*
	class ammo_Penetrator_Vorona: ammo_Penetrator_Base
	{
		caliber=60;
		warheadName="TandemHEAT";
		hit=720;
		typicalSpeed=2000;
	};
*/

/*class default
	directionalExplosion=0;
	explosionAngle=60;
*/

class RC_M_Mo_155mm_AT_MultiGuided: MissileBase_base
{
	model="\A3\weapons_f\ammo\shell";
	autoSeekTarget=1;
	proximityExplosionDistance=1; 	//might prevent overshot miss

	//lockSeekRadius=32000;	//default 100, but that might be manual fire problem "Specifies the maximum distance from the initial target position where the missile will search for suitable targets if it has autoSeekTarget enabled."
	trackLead=1;
	airLock=0;
	laserLock=1; //from main shell
	irLock=1;
	canLock=2; //always locks
	lockAcquire=1;	//automatic acquisition of the closest target in missileLockCone

	receiveRemoteTargets=1;

	maneuvrability=12;	//6
	simulationStep=0.0020000001;
	fuseDistance=0;
	airFriction=0.0099999998;
	sideAirFriction=0.029999999;
	missileLockCone=40;
	missileKeepLockedCone=40;

	hit=1200;
	indirectHit=1200;
	indirectHitRange=5;
	EffectFly="ArtilleryTrails";
	cameraViewAvailable=1;

	weaponLockSystem="1+2+4";	//visual, ir, laser
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};
};

/*
class RC_M_Mo_155mm_LGDF_submunition: M_Mo_155mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,1.8};	//1.8m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
*/

class RC_Sh_155mm_AMOS_AT_MultiGuided: SubmunitionBase
{
	submunitionAmmo="RC_M_Mo_155mm_AT_MultiGuided";
	submunitionCount=1;		//2
	submunitionConeAngle=0;
	triggerDistance=500;

	laserLock=1;
	irLock=1;
	autoSeekTarget=1;
	//artilleryLock=1;
	
	//testing
	/*
	receiveRemoteTargets=1;
	lockSeekRadius=67000;	//default 100, but that might be manual fire problem "Specifies the maximum distance from the initial target position where the missile will search for suitable targets if it has autoSeekTarget enabled."
	autoSeekTarget=1;
	lockAcquire=1;	//automatic acquisition of the closest target in missileLockCone
	canLock=2; //always locks

	proximityExplosionDistance=1; 	//might prevent overshot miss
	trackLead=1;
	laserLock=1; //from main shell
	irLock=1;
	airLock=1;	//TEST
	*/
	//

	muzzleEffect="";
	hit=300;
	cost=500;
	airFriction=0;

	class CamShakeFire
	{
		power=3.0092199;
		duration=1.8;
		frequency=20;
		distance=72.4431;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};


//230mm
class R_230mm_fly;
class RC_R_230mm_fly_HEAB_submunition: R_230mm_fly
{
	explosionTime=0.01;
	explosive=1;
	CraterEffects="";
};
class RC_R_230mm_HEAB: SubmunitionBase
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-20};		//20m high airburst to ignore cover very well
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_R_230mm_fly_HEAB_submunition";

	artilleryLock=1;
	cost=1000;
	airFriction=0;
	muzzleEffect="";
	effectFly="Missile0";
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	hit=0;
};


class RC_R_230mm_fly_HEAB_submunition_ATACMS: RC_R_230mm_fly_HEAB_submunition
{
	hit=7200;
	indirectHit=4800;
	indirectHitRange=180;

	craterEffects="HeavyBombCrater";
	explosionEffects="HeavyBombExplosion";

	soundSetExplosion[]=
	{
		"BombsHeavy_Exp_SoundSet",
		"BombsHeavy_Tail_SoundSet",
		"Explosion_Debris_SoundSet"
	};
};
class RC_R_604mm_ATACMS_HEAB: RC_R_230mm_HEAB
{
	submunitionAmmo="RC_R_230mm_fly_HEAB_submunition_ATACMS";
};


class R_230mm_Cluster;
class RC_R_230mm_Cluster: R_230mm_Cluster
{
	submunitionConeType[]=
	{
		"poissondisccenter",
		80
	};
};


class RC_R_604mm_ATACMS_DPICM: R_230mm_Cluster
{
	submunitionConeAngle=30;

	submunitionConeType[]=
	{
		"poissondisccenter",
		350
	};
};


class R_230mm_LG;
class RC_R_230mm_LG: R_230mm_LG
{
	submunitionAmmo="M_Mo_230mm_AT_LG";
	muzzleEffect="";
	triggerDistance=500;

	laserLock=1;
	irLock=0;

	submunitionCount=1;
	submunitionConeAngle=0;
	autoSeekTarget=1;
};

/*
class R_230mm_fly: ShellBase
{
	artilleryLock=1;
	model="\A3\Weapons_F\Ammo\Rocket_230mm_Fly_F";
	hit=1200;
	indirectHit=800;
	indirectHitRange=30;
	warheadName="HE";
	cost=1000;
	audibleFire=64;
	dangerRadiusHit=1250;
	suppressionRadiusHit=120;
	deflecting=0;
	airFriction=0;
	muzzleEffect="";
	effectFly="ArtilleryTrails";
	class CamShakeExplode
	{
		power=46;
		duration=3;
		frequency=20;
		distance=361.32599;
	};
	class CamShakeHit
	{
		power=230;
		duration=0.80000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=3.89432;
		duration=3;
		frequency=20;
		distance=121.326;
	};
	class CamShakePlayerFire
	{
		power=5;
		duration=0.1;
		frequency=20;
		distance=1;
	};
	soundHit1[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_01",
		2.5118864,
		1,
		1900
	};
	soundHit2[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_02",
		2.5118864,
		1,
		1900
	};
	soundHit3[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_03",
		2.5118864,
		1,
		1900
	};
	multiSoundHit[]=
	{
		"soundHit1",
		0.34,
		"soundHit2",
		0.33000001,
		"soundHit3",
		0.33000001
	};
};
*/


class RC_M_Mo_230mm_MultiGuided: MissileBase_base
{
	model="\A3\Weapons_F\Ammo\Rocket_230mm_Fly_F";
	hit=1200;
	indirectHit=800;
	indirectHitRange=30;
	//warheadName="HE";
	//audibleFire=64;
	//dangerRadiusHit=1250;
	//suppressionRadiusHit=120;

	autoSeekTarget=1;
	proximityExplosionDistance=1; 	//might prevent overshot miss

	//lockSeekRadius=32000;	//default 100, but that might be manual fire problem "Specifies the maximum distance from the initial target position where the missile will search for suitable targets if it has autoSeekTarget enabled."
	trackLead=1;
	airLock=0;
	laserLock=1; //from main shell
	irLock=1;
	canLock=2; //always locks
	lockAcquire=1;	//automatic acquisition of the closest target in missileLockCone

	receiveRemoteTargets=1;

	maneuvrability=12;	//6
	simulationStep=0.0020000001;
	fuseDistance=0;
	airFriction=0.0099999998;
	sideAirFriction=0.029999999;
	missileLockCone=40;
	missileKeepLockedCone=40;

	EffectFly="ArtilleryTrails";
	cameraViewAvailable=1;

	weaponLockSystem="1+2+4";	//visual, ir, laser
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};
	class CamShakeExplode
	{
		power=46;
		duration=3;
		frequency=20;
		distance=361.32599;
	};
	class CamShakeHit
	{
		power=230;
		duration=0.80000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=3.89432;
		duration=3;
		frequency=20;
		distance=121.326;
	};
	class CamShakePlayerFire
	{
		power=5;
		duration=0.1;
		frequency=20;
		distance=1;
	};
	soundHit1[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_01",
		2.5118864,
		1,
		1900
	};
	soundHit2[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_02",
		2.5118864,
		1,
		1900
	};
	soundHit3[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_03",
		2.5118864,
		1,
		1900
	};
	multiSoundHit[]=
	{
		"soundHit1",
		0.34,
		"soundHit2",
		0.33000001,
		"soundHit3",
		0.33000001
	};
};

/*
class R_230mm_HE: SubmunitionBase
{
	artilleryLock=1;
	submunitionAmmo="R_230mm_fly";
	triggerDistance=500;
	cost=1000;
	airFriction=0;
	muzzleEffect="";
	effectFly="Missile0";
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	hit=300;
	class CamShakeExplode
	{
		power=46;
		duration=3;
		frequency=20;
		distance=361.32599;
	};
	class CamShakeHit
	{
		power=230;
		duration=0.80000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=3.89432;
		duration=3;
		frequency=20;
		distance=121.326;
	};
	class CamShakePlayerFire
	{
		power=5;
		duration=0.1;
		frequency=20;
		distance=1;
	};
	soundFly[]=
	{
		"A3\Sounds_F\weapons\Rockets\rocket_fly_1",
		0.56234133,
		1.9,
		500
	};
};
*/


class RC_Sh_230mm_AMOS_AT_MultiGuided: SubmunitionBase
{
	submunitionAmmo="RC_M_Mo_230mm_AT_MultiGuided";
	submunitionCount=1;		//2
	submunitionConeAngle=0;
	triggerDistance=500;

	//artilleryLock=1;
	laserLock=1;
	irLock=1;
	autoSeekTarget=1;

	muzzleEffect="";
	hit=300;
	cost=1000;
	airFriction=0;

	class CamShakeExplode
	{
		power=46;
		duration=3;
		frequency=20;
		distance=361.32599;
	};
	class CamShakeHit
	{
		power=230;
		duration=0.80000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=3.89432;
		duration=3;
		frequency=20;
		distance=121.326;
	};
	class CamShakePlayerFire
	{
		power=5;
		duration=0.1;
		frequency=20;
		distance=1;
	};
	soundFly[]=
	{
		"A3\Sounds_F\weapons\Rockets\rocket_fly_1",
		0.56234133,
		1.9,
		500
	};
};

class RC_R_230mm_fly_MultiGuided: MissileBase_base
{
	model="\A3\Weapons_F\Ammo\Rocket_230mm_Fly_F";
	//model="\A3\weapons_f\ammo\shell";
	autoSeekTarget=1;
	proximityExplosionDistance=1; 	//might prevent overshot miss

	//lockSeekRadius=32000;	//default 100, but that might be manual fire problem "Specifies the maximum distance from the initial target position where the missile will search for suitable targets if it has autoSeekTarget enabled."
	trackLead=1;
	airLock=0;
	laserLock=1; //from main shell
	irLock=1;
	canLock=2; //always locks
	lockAcquire=1;	//automatic acquisition of the closest target in missileLockCone

	receiveRemoteTargets=1;

	maneuvrability=12;	//6
	simulationStep=0.0020000001;
	fuseDistance=0;
	airFriction=0.0099999998;
	sideAirFriction=0.029999999;
	missileLockCone=40;
	missileKeepLockedCone=40;

	hit=1200;
	indirectHit=1200;
	indirectHitRange=5;
	EffectFly="ArtilleryTrails";
	cameraViewAvailable=1;

	weaponLockSystem="1+2+4";	//visual, ir, laser
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};

				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};
};


class RC_R_230mm_MultiGuided: SubmunitionBase
{
	effectFly="Missile0";
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";

	submunitionAmmo="RC_R_230mm_fly_MultiGuided";
	submunitionCount=1;		//2
	submunitionConeAngle=0;
	triggerDistance=500;

	laserLock=1;
	irLock=1;
	autoSeekTarget=1;
	//artilleryLock=1;

	muzzleEffect="";
	hit=300;
	cost=500;
	airFriction=0;

	class CamShakeFire
	{
		power=3.0092199;
		duration=1.8;
		frequency=20;
		distance=72.4431;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};
