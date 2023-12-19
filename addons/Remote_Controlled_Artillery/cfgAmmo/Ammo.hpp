//ATGM
class ammo_Penetrator_Base;
class RC_ammo_Penetrator_MT: ammo_Penetrator_Base
{
	caliber=60;
	warheadName="TandemHEAT";
	hit=780;
};
class M_Vorona_HEAT;
class RC_M_ATGM_MT: M_Vorona_HEAT
{
	submunitionAmmo="RC_ammo_Penetrator_MT";
	indirectHit=40;
	indirectHitRange=10;
	maxControlRange=3000;
	trackOversteer=0.5;
	fuseDistance=20;
};


//ATGM
class M_Titan_AT_long;
class RC_M_MT_base: M_Titan_AT_long
{
	class Components;
};
class RC_M_MT: RC_M_MT_base
{
	submunitionAmmo="RC_ammo_Penetrator_MT";
	hit=150;
	indirectHit=40;
	indirectHitRange=10;
	maxControlRange=3000;
	cmImmunity=0.8;
	missileLockCone=180;	//for NLOS targeting, being able to shoot missle straight up, over barriers being in the way
	missileLockMaxDistance=3000;
	initTime=0.01;
	laserLock=1;
	weaponLockSystem="1 + 2 + 16";
	cameraViewAvailable=1;

	//test (likely cfgvic only...)
	receiveRemoteTargets=1;
	reportRemoteTargets=1;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				/*
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				*/
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=1500;
					class AirTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=500;
					class AirTarget
					{
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=3000;
					class AirTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};
};


class MissileBase;
/*
//im gonna work on this later
class ammo_Missile_CannonLaunchedBase: MissileBase
{
	class Components;
};
class M_125mm_cannon_ATGM: ammo_Missile_CannonLaunchedBase
{
	model="\A3\Weapons_F_Tank\Launchers\Vorona\Vorona_missile_heat_fly";
	submunitionAmmo="ammo_Penetrator_125mm_missile";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
	warheadName="TandemHEAT";
	hit=150;
	indirectHit=20;
	timeToLive=20;
	thrustTime=5;
	thrust=60;
	maxSpeed=350;
};
class M_120mm_cannon_ATGM: ammo_Missile_CannonLaunchedBase
{
	model="\A3\Weapons_F_Tank\Ammo\Missile_ATGM_01_fly_F";
	warheadName="TandemHEAT";
	submunitionAmmo="ammo_Penetrator_120mm_missile";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
	hit=150;
};
class M_120mm_cannon_ATGM_LG: M_120mm_cannon_ATGM
{
	thrustTime=6;
	thrust=40;
	lockType=0;
	autoSeekTarget=1;
	lockSeekRadius=100;
	manualControl=0;
	missileLockCone=180;
	missileKeepLockedCone=180;
	missileLockMaxDistance=8000;
	missileLockMinDistance=100;
	missileLockMaxSpeed=35;
	weaponLockSystem="4 + 16";
	flightProfiles[]=
	{
		"TopDown"
	};
	class TopDown
	{
		ascendHeight=250;
		descendDistance=400;
		minDistance=400;
		ascendAngle=25;
	};
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
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					maxTrackableSpeed=35;
					angleRangeHorizontal=40;
					angleRangeVertical=25;
				};
			};
		};
	};
};
*/


//82mm
class SubmunitionBase;
class Sh_82mm_AMOS;
class RC_Sh_82mm_AMOS_submunition: Sh_82mm_AMOS
{
	explosionTime=0.001;
	explosive=1;
	CraterEffects="";
};
class RC_Sh_82mm_AMOS_HEAB_backup: Sh_82mm_AMOS
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-16.1};		//high airburst to ignore cover very well
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_82mm_AMOS_HEAB_low_backup: RC_Sh_82mm_AMOS_HEAB_backup
{
	submunitionInitialOffset[]={0,0,-6};		//low airburst to ignore atleast microterrain
};


class Default;
class RC_HEAB_Base: Default
{
	//shell/submunition core
	simulation="shotSubmunitions";
	simulationStep=0.050000001;
	soundHit[]=
	{
		"",
		316.22775,
		1
	};
	soundFly[]=
	{
		"",
		0.031622775,
		4
	};
	hitOnWater=1;
	//visibleFire=16;
	//audibleFire=16;
	visibleFireTime=10;


	//shell/submunition base
	supersonicCrackNear[]=
	{
		"A3\Sounds_F\weapons\Explosion\supersonic_crack_close",
		0.31622776,
		1,
		50
	};
	supersonicCrackFar[]=
	{
		"A3\Sounds_F\weapons\Explosion\supersonic_crack_50meters",
		0.22387211,
		1,
		150
	};
	CraterEffects="HEShellCrater";
	CraterWaterEffects="ImpactEffectsWaterHE";
	ExplosionEffects="HEShellExplosion";
	visibleFire=64;
	audibleFire=250;
	muzzleEffect="";
	deflectionDirDistribution=0.38999999;
	penetrationDirDistribution=0.25999999;
	whistleOnFire=2;
	aiAmmoUsageFlags="64 + 128";
	class HitEffects
	{
		hitWater="ImpactEffectsWaterRocket";
	};
	soundFakeFall0[]=
	{
		"a3\Sounds_F\weapons\falling_bomb\fall_01",
		3.1622777,
		1,
		1000
	};
	soundFakeFall1[]=
	{
		"a3\Sounds_F\weapons\falling_bomb\fall_02",
		3.1622777,
		1,
		1000
	};
	soundFakeFall2[]=
	{
		"a3\Sounds_F\weapons\falling_bomb\fall_03",
		3.1622777,
		1,
		1000
	};
	soundFakeFall3[]=
	{
		"a3\Sounds_F\weapons\falling_bomb\fall_04",
		3.1622777,
		1,
		1000
	};
	soundFakeFall[]=
	{
		"soundFakeFall0",
		0.25,
		"soundFakeFall1",
		0.25,
		"soundFakeFall2",
		0.25,
		"soundFakeFall3",
		0.25
	};
};


class RC_HEAB_Shell_Base: RC_HEAB_Base
{
	warheadName="HE";
	dangerRadiusHit=750;
	suppressionRadiusHit=75;
	typicalSpeed=800;
	caliber=10;
	deflecting=0;
	explosive=0.80000001;
	model="\A3\weapons_f\ammo\shell";
	CraterEffects="ArtyShellCrater";
	ExplosionEffects="MortarExplosion";
	whistleDist=60;
	artilleryLock=1;
	thrust=0;
	timeToLive=180;
	airFriction=0;
	sideairFriction=0;
	soundHit1[]=
	{
		"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_01",
		2.5118864,
		1,
		1900
	};
	soundHit2[]=
	{
		"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_02",
		2.5118864,
		1,
		1900
	};
	soundHit3[]=
	{
		"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_03",
		2.5118864,
		1,
		1900
	};
	soundHit4[]=
	{
		"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_04",
		2.5118864,
		1,
		1900
	};
	multiSoundHit[]=
	{
		"soundHit1",
		0.25,
		"soundHit2",
		0.25,
		"soundHit3",
		0.25,
		"soundHit4",
		0.25
	};
};


class RC_82mm_HEAB_Shell_Base: RC_HEAB_Shell_Base
{
	hit=165;
	indirectHit=52;
	indirectHitRange=18;
	cost=200;
	class CamShakeExplode
	{
		power=16.4;
		duration=1.8;
		frequency=20;
		distance=216.44299;
	};
	class CamShakeHit
	{
		power=82;
		duration=0.60000002;
		frequency=20;
		distance=1;
	};
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
class RC_Sh_82mm_AMOS_HEAB: RC_82mm_HEAB_Shell_Base
{
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
	submunitionCount=1;
	submunitionConeAngle=0;
	triggerDistance=16;
	//fuseDistance=30; doesnt work
};
class RC_Sh_82mm_AMOS_HEAB_low: RC_Sh_82mm_AMOS_HEAB
{
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
	submunitionCount=1;
	submunitionConeAngle=0;
	triggerDistance=6;
	//fuseDistance=30;
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


class Mo_ClassicMineRange;
class RC_Mo_ClassicMineRange: Mo_ClassicMineRange
{
	submunitionAmmo="APERSBoundingMine_Range_Ammo";
};
class RC_Mine_82mm_AMOS_range: SubmunitionBase
{
	submunitionAmmo="RC_Mo_ClassicMineRange";
	submunitionConeType[]=
	{
		"poissondisc",
		10
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
		5
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


class ammo_Penetrator_82mm_MT: ammo_Penetrator_Base
{
	caliber=37.8;
	warheadName="TandemHEAT";
	hit=454.1;
};
class RC_MT_MultiGuided_Submunition_base: MissileBase
{
	class Components;
};
class RC_82mm_MT_MultiGuided_Submunition: RC_MT_MultiGuided_Submunition_base
{
	laserLock=1;
	irLock=1;
	autoSeekTarget=1;
	cameraViewAvailable=1;

	//test (likely cfgvic only...)
	receiveRemoteTargets=1;
	reportRemoteTargets=1;	//would allow for sensor-recon shots, to then datalink lock with second shot
	laserScanner=1;
	//lockSeekRadius=100;	//higher doesnt result in unlocked manual fire locking //Specifies the maximum distance from the initial target position where the missile will search for suitable targets if it has autoSeekTarget enabled.

	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";
	explosive=1;
	cost=500;
	aiAmmoUsageFlags="128 + 512";
	explosionSoundEffect="DefaultExplosion";
	effectsMissileInit="";
	muzzleEffect="";
	simulationStep=0.0020000001;
	trackOversteer=1.5;
	trackLead=1;	//0.89999998
	maneuvrability=20;
	airFriction=0.085000001;
	sideAirFriction=1;
	fuseDistance=50;
	effectsMissile="missile2";
	whistleDist=4;
	airLock=1;
	lockType=0;
	missileKeepLockedCone=160;
	//manualControl=1;
	//missileManualControlCone=45;

	submunitionAmmo="ammo_Penetrator_82mm_MT";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
	warheadName="TandemHEAT";

	hit=100;
	indirectHit=40;
	indirectHitRange=10;

	timeToLive=35;
	initTime=0.15000001;
	thrustTime=8;
	thrust=35;
	maxSpeed=180;
	typicalSpeed=1660;
	missileLockCone=12;
	missileLockMaxDistance=5000;
	missileLockMinDistance=200;
	missileLockMaxSpeed=35;
	maxControlRange=5000;
	weaponLockSystem="1 + 2 + 4 + 16";
	cmImmunity=0.9;

	soundFly[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Fly_Titan",
		0.63095737,
		1.5,
		300
	};
	class CamShakeExplode
	{
		power=11;
		duration=1.4;
		frequency=20;
		distance=91.329597;
	};
	class CamShakeHit
	{
		power=110;
		duration=0.60000002;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=2.78316;
		duration=1.6;
		frequency=20;
		distance=61.967701;
	};
	class CamShakePlayerFire
	{
		power=3;
		duration=0.1;
		frequency=20;
		distance=1;
	};

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
class RC_Sh_82mm_AMOS_MT_MultiGuided: SubmunitionBase
{
	submunitionAmmo="RC_82mm_MT_MultiGuided_Submunition";
	submunitionCount=1;		//2
	submunitionConeAngle=0;
	triggerDistance=300;

	laserLock=1;
	irLock=1;
	airLock=1;	//test
	autoSeekTarget=1;
	cameraViewAvailable=1;
	canLock=2;	//supposedly only cfg weapons not ammo

	//test (likely cfgvic only...)
	receiveRemoteTargets=1;
	reportRemoteTargets=1;	//allows for sensor-recon shots, to then datalink lock with second shot

	//lockAcquire=1;	//likely cfgvic only
	//artilleryLock=1;
	//lockSeekRadius=67000;	//default 100, but that might be manual fire problem "Specifies the maximum distance from the initial target position where the missile will search for suitable targets if it has autoSeekTarget enabled."

	muzzleEffect="";
	hit=165;
	cost=500;
	airFriction=0;

	class CamShakeExplode
	{
		power=16.4;
		duration=1.8;
		frequency=20;
		distance=216.44299;
	};
	class CamShakeHit
	{
		power=82;
		duration=0.60000002;
		frequency=20;
		distance=1;
	};
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


class RC_Sh_82mm_AMOS_delayed_submunition: RC_Sh_82mm_AMOS_submunition
{
	explosionTime=0.2;
};
class RC_M_Mo_82mm_LG_DelayedFuse_Submunition: RC_82mm_MT_MultiGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_delayed_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_82mm_AMOS_LG_DelayedFuse: RC_Sh_82mm_AMOS_MT_MultiGuided
{
	submunitionAmmo="RC_M_Mo_82mm_LG_DelayedFuse_Submunition";
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


class RC_M_Mo_82mm_LG_DelayedFuse_submunition_backup: M_Mo_82mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_82mm_AMOS_LG_DelayedFuse_backup: Sh_82mm_AMOS_LG
{
	submunitionAmmo="RC_M_Mo_82mm_LG_DelayedFuse_submunition_backup";
};


//120mm
class ammo_Penetrator_120mm_MT: ammo_Penetrator_Base
{
	caliber=55.4;
	warheadName="TandemHEAT";
	hit=664.6;
};
class RC_120mm_MT_MultiGuided_Submunition: RC_82mm_MT_MultiGuided_Submunition
{
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";
	cost=700;
	fuseDistance=50;	//edit?
	lockType=0;	//add to shell?

	submunitionAmmo="ammo_Penetrator_120mm_MT";

	hit=150;
	indirectHit=50;
	indirectHitRange=10;
};
class RC_Sh_120mm_AMOS_MT_MultiGuided: RC_Sh_82mm_AMOS_MT_MultiGuided
{
	submunitionAmmo="RC_120mm_MT_MultiGuided_Submunition";
	triggerDistance=500;

	hit=300;
	cost=700;

	class CamShakeExplode
	{
		power=31;
		duration=2.4000001;
		frequency=20;
		distance=339.599;
	};
	class CamShakeHit
	{
		power=155;
		duration=0.80000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=3.52844;
		duration=2.4000001;
		frequency=20;
		distance=99.599197;
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
		"poissondisc",
		24
	};
};


class AT_Mine_155mm_AMOS_range;
class RC_AT_Mine_155mm_AMOS_range: AT_Mine_155mm_AMOS_range
{
	submunitionConeAngle=15;
	submunitionConeType[]=
	{
		//"custom",{{-5,0},{-3,0},{-1,0},{1,0},{3,0},{5,0} , {0,-5},{0,-3},{0,-1},{0,1},{0,3},{0,5}}
		"poissondisc",
		12
	};
};


class RC_Smoke_155mm_AMOS_White: Smoke_120mm_AMOS_White
{
	submunitionConeAngle=10;
	submunitionConeType[]=
	{
		"poissondisc",
		10
	};
};


class Sh_155mm_AMOS;
class RC_Sh_155mm_AMOS_submunition: Sh_155mm_AMOS
{
	explosionTime=0.001;
	explosive=1;
	CraterEffects="";	//removes ground impact animation
};
class RC_Sh_155mm_AMOS_HEAB_backup: Sh_155mm_AMOS
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-20};		//20m high airburst to ignore cover very well
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_155mm_AMOS_HEAB_low_backup: RC_Sh_155mm_AMOS_HEAB_backup
{
	submunitionInitialOffset[]={0,0,-6};	//low airburst to ignore atleast microterrain
};


class RC_155mm_HEAB_Shell_Base: RC_HEAB_Shell_Base
{
	hit=340;
	indirectHit=125;
	indirectHitRange=30;
	cost=300;
	class CamShakeExplode
	{
		power=31;
		duration=2.4000001;
		frequency=20;
		distance=339.599;
	};
	class CamShakeHit
	{
		power=155;
		duration=0.80000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=3.52844;
		duration=2.4000001;
		frequency=20;
		distance=99.599197;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};
class RC_Sh_155mm_AMOS_HEAB: RC_82mm_HEAB_Shell_Base
{
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
	submunitionCount=1;
	submunitionConeAngle=0;
	triggerDistance=20;
};
class RC_Sh_155mm_AMOS_HEAB_low: RC_Sh_155mm_AMOS_HEAB
{
	triggerDistance=6;
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


class ammo_Penetrator_155mm_MT: ammo_Penetrator_Base
{
	caliber=71.5;
	warheadName="TandemHEAT";
	hit=858.5;
};
class RC_155mm_MT_MultiGuided_Submunition: RC_82mm_MT_MultiGuided_Submunition
{
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";
	cost=700;
	fuseDistance=50;	//edit?
	lockType=0;	//add to shell?

	submunitionAmmo="ammo_Penetrator_155mm_MT";

	hit=150;
	indirectHit=60;
	indirectHitRange=10;
};
class RC_Sh_155mm_AMOS_MT_MultiGuided: RC_Sh_82mm_AMOS_MT_MultiGuided
{
	submunitionAmmo="RC_155mm_MT_MultiGuided_Submunition";
	triggerDistance=500;

	hit=300;
	cost=700;

	class CamShakeExplode
	{
		power=31;
		duration=2.4000001;
		frequency=20;
		distance=339.599;
	};
	class CamShakeHit
	{
		power=155;
		duration=0.80000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=3.52844;
		duration=2.4000001;
		frequency=20;
		distance=99.599197;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};


class RC_Sh_155mm_AMOS_delayed_submunition: RC_Sh_155mm_AMOS_submunition
{
	explosionTime=0.2;
};
class RC_M_Mo_155mm_LG_DelayedFuse_submunition: RC_155mm_MT_MultiGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_delayed_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_155mm_AMOS_LG_DelayedFuse: RC_Sh_155mm_AMOS_MT_MultiGuided
{
	submunitionAmmo="RC_M_Mo_155mm_LG_DelayedFuse_submunition";
};


class M_Mo_155mm_AT_LG;
class RC_M_Mo_155mm_LG_DelayedFuse_submunition_backup: M_Mo_155mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
class Sh_155mm_AMOS_LG;
class RC_Sh_155mm_AMOS_LG_DelayedFuse_backup: Sh_155mm_AMOS_LG
{
	submunitionAmmo="RC_M_Mo_155mm_LG_DelayedFuse_submunition_backup";
};


//230mm
class R_230mm_fly;
class RC_R_230mm_fly_HEAB_submunition: R_230mm_fly
{
	explosionTime=0.001;
	explosive=1;
	CraterEffects="";
};
class RC_R_230mm_HEAB_backup: SubmunitionBase
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
class RC_R_230mm_HEAB_backup_low: SubmunitionBase
{
	submunitionInitialOffset[]={0,0,-6};		//6m low airburst to atleast ignore microterrain
};


class RC_HEAB_Rocket_Base: RC_HEAB_Base
{
	//typicalSpeed=800;
	//caliber=10;
	//explosive=0.80000001;
	
	//CraterEffects="ArtyShellCrater";
	//ExplosionEffects="MortarExplosion";
	//whistleDist=60;
	
	//thrust=0;
	caliber=34;
	timeToLive=360;
	airFriction=0;
	sideairFriction=0;


	artilleryLock=1;
	//model="\A3\Weapons_F\Ammo\Rocket_230mm_Fly_F";
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	//effectFly="ArtilleryTrails";
	effectFly="Missile0";
	warheadName="HE";
	audibleFire=64;
	dangerRadiusHit=1250;
	suppressionRadiusHit=120;
	deflecting=0;


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
	soundFly[]=
	{
		"A3\Sounds_F\weapons\Rockets\rocket_fly_1",
		0.56234133,
		1.9,
		500
	};
};
class RC_230mm_HEAB_Rocket_Base: RC_HEAB_Rocket_Base
{
	hit=1200;
	indirectHit=800;
	indirectHitRange=30;
	cost=1000;
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
};
class RC_R_230mm_HEAB: RC_230mm_HEAB_Rocket_Base
{
	submunitionAmmo="RC_R_230mm_fly_HEAB_submunition";
	submunitionCount=1;
	submunitionConeAngle=0;
	triggerDistance=20;
};
class RC_R_230mm_HEAB_low: RC_230mm_HEAB_Rocket_Base
{
	triggerDistance=6;
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
class RC_604mm_HEAB_Rocket_Base: RC_230mm_HEAB_Rocket_Base
{
	hit=7200;
	indirectHit=4800;
	indirectHitRange=180;
	cost=6000;
}
class RC_R_604mm_ATACMS_HEAB: RC_604mm_HEAB_Rocket_Base
{
	submunitionAmmo="RC_R_230mm_fly_HEAB_submunition_ATACMS";
	submunitionCount=1;
	submunitionConeAngle=0;
	triggerDistance=30;		//test different heights
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


class ammo_Penetrator_230mm_MT: ammo_Penetrator_Base
{
	caliber=106.1;
	warheadName="TandemHEAT";
	hit=1273.8;
};
class RC_230mm_MT_MultiGuided_Submunition: RC_155mm_MT_MultiGuided_Submunition
{
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";
	cost=700;
	fuseDistance=50;	//edit?
	lockType=0;	//add to shell?

	submunitionAmmo="ammo_Penetrator_230mm_MT";

	hit=300;
	indirectHit=400;
	indirectHitRange=20;
};
class RC_R_230mm_MT_MultiGuided: RC_Sh_155mm_AMOS_MT_MultiGuided
{
	submunitionAmmo="RC_230mm_MT_MultiGuided_Submunition";
	triggerDistance=500;

	hit=300;
	cost=1000;

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


class RC_R_230mm_fly_HEAB_delayed_submunition: RC_R_230mm_fly_HEAB_submunition
{
	explosionTime=0.2;
};
class RC_230mm_LG_DelayedFuse_submunition: RC_230mm_MT_MultiGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_R_230mm_fly_HEAB_delayed_submunition";
	CraterEffects="";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_230mm_LG_DelayedFuse: RC_R_230mm_MT_MultiGuided
{
	submunitionAmmo="RC_M_Mo_155mm_LG_DelayedFuse_submunition";
};