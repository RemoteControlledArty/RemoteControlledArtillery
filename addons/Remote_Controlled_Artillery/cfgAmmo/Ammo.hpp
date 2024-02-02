//ATGM
class ammo_Penetrator_Base;
class RC_ammo_Penetrator_MP: ammo_Penetrator_Base
{
	caliber=60;
	warheadName="TandemHEAT";
	hit=780;
};
class M_Vorona_HEAT;
class RC_M_ATGM_MP: M_Vorona_HEAT
{
	submunitionAmmo="RC_ammo_Penetrator_MP";
	indirectHit=40;
	indirectHitRange=10;
	maxControlRange=3000;
	trackOversteer=0.5;
	fuseDistance=20;
};


//ATGM
class M_Titan_AT_long;
class RC_M_MP_Base: M_Titan_AT_long
{
	class Components;
};
class RC_M_MP: RC_M_MP_Base
{
	submunitionAmmo="RC_ammo_Penetrator_MP";
	hit=150;
	indirectHit=40;
	indirectHitRange=10;
	maxControlRange=3000;
	cmImmunity=0.85;
	missileLockCone=180;	//for NLOS targeting, being able to shoot missle straight up, over barriers being in the way
	missileLockMaxDistance=3000;
	initTime=0.01;
	laserLock=0;
	weaponLockSystem="1 + 2 + 16";
	cameraViewAvailable=1;

	//test (likely cfgvic only...)
	//receiveRemoteTargets=1;
	//reportRemoteTargets=1;

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


class M_120mm_cannon_ATGM_LG;
class RC_M_120mm_cannon_ATGM_DLG_Base: M_120mm_cannon_ATGM_LG
{
	class Components;
};
class RC_M_120mm_cannon_ATGM_DLG: RC_M_120mm_cannon_ATGM_DLG_Base
{
	explosive=0.8;
	indirectHit=44.25;
	indirectHitRange=12;

	laserLock=1;
	irLock=1;
	airLock=1;
	trackLead=1;
	craterEffects="AAMissileCrater";
	weaponLockSystem="2 + 4 + 16";
	flightProfiles[]=
	{
		"TopDown"
	};
	class TopDown
	{
		ascendHeight=500;	//250
		descendDistance=400;	//400
		minDistance=400;	//400
		ascendAngle=45;	//25
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
					maxTrackableSpeed=35;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
				};
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


//groundwork
class Default;
class RC_HEAB_Base: Default
{
	submunitionCount=1;
	submunitionConeAngle=0;
	submunitionParentSpeedCoef=0;
	submunitionInitSpeed=0;

	artilleryLock=1;
	laserLock=1;
	irLock=1;
	timeToLive=360;
	
	//shell/submunition core
	simulation="shotSubmunitions";
	simulationStep=0.005;	//to make airburst work before hitting ground
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
	//CraterEffects="HEShellCrater";	//dirt thrown up doesnt fit as its airburst
	craterEffects="RC_ArtyShellCrater";	//dust on ground effect like caused by airburst
	CraterWaterEffects="ImpactEffectsWaterHE";
	ExplosionEffects="MortarExplosion";
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
	ExplosionEffects="MortarExplosion";
	whistleDist=60;
	thrust=0;
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


class RC_MP_MultiGuided_Submunition_MissleBase: MissileBase
{
	class Components;
};
class RC_MP_MultiGuided_Submunition_Base: RC_MP_MultiGuided_Submunition_MissleBase
{
	laserLock=1;
	irLock=1;
	//artilleryLock=1; seems to prevent laser and vehicle locking, so unusable for guided
	autoSeekTarget=1;
	cameraViewAvailable=1;

	missileLockCone=180;	//12
	missileKeepLockedCone=180;	//160
	lockSeekRadius=800;		//100
	missileLockMaxDistance=2000;	//5000
	missileLockMinDistance=1;
	missileLockMaxSpeed=150;	//35
	maxControlRange=800;	//500
	fuseDistance=30;	//50
	timeToLive=10;	//35

	//test (likely cfgvic only...)
	receiveRemoteTargets=1;
	reportRemoteTargets=1;	//would allow for sensor-recon shots, to then datalink lock with second shot
	laserScanner=1;

	model="\A3\Weapons_F_Tank\Ammo\Missile_ATGM_01_fly_F";
	//model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";
	//effectsMissile="missile2";
	explosive=1;
	aiAmmoUsageFlags="128 + 512";
	explosionSoundEffect="DefaultExplosion";
	//ExplosionEffects="MortarExplosion";
	craterEffects="AAMissileCrater";
	effectsMissileInit="";
	muzzleEffect="";
	simulationStep=0.0020000001;
	trackOversteer=1;	//1.5	//required to not completly miss
	trackLead=0;	//0.89999998
	maneuvrability=20;	//20	//required to not completly miss
	airFriction=0.085000001;	//tanks atgm 0.2	//0.085000001
	sideAirFriction=0.1; //tanks 0.001	//0.1
	whistleDist=4;
	lockType=0;
	//manualControl=1;
	//missileManualControlCone=45;

	submunitionDirectionType="SubmunitionModelDirection";
	//submunitionDirectionType="SubmunitionTargetDirection";	//TEST OUT
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
	warheadName="TandemHEAT";
	hit=0;	//submunition penetrator contains real hit value

	initTime=0.01; //0.15000001
	thrustTime=8;	//8
	thrust=300;	//35
	maxSpeed=300;	//180
	typicalSpeed=1660;
	weaponLockSystem="1 + 2 + 4 + 16";
	cmImmunity=0.9;

	soundFly[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Fly_Titan",
		0.63095737,
		1.5,
		300
	};

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
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				class IRSensorComponent: SensorTemplateIR
				{
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
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
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
class SubmunitionBase;
class RC_Sh_AMOS_MP_MultiGuided_Base: SubmunitionBase
{
	submunitionCount=1;
	submunitionConeAngle=0;
	submunitionDirectionType="SubmunitionTargetDirection";	//required to not completly miss
	//submunitionInitSpeed=0;
	submunitionParentSpeedCoef=0.1;	//required to not completly miss

	aiAmmoUsageFlags="128 + 512";
	laserLock=1;
	irLock=1;
	autoSeekTarget=1;
	cameraViewAvailable=1;
	canLock=2;	//supposedly only cfg weapons not ammo
	receiveRemoteTargets=1;
	reportRemoteTargets=1;	//would allows for sensor-recon shots, to then datalink lock with second shot, doesnt work yet, maybe cfgvic only

	//lockAcquire=1;	//likely cfgvic only
	artilleryLock=1;

	muzzleEffect="";
	airFriction=0;
	//ExplosionEffects="MortarExplosion";
	craterEffects="AAMissileCrater";

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


//82mm
class Sh_82mm_AMOS;
class RC_Sh_82mm_AMOS_submunition: Sh_82mm_AMOS
{
	explosionTime=0.0001;
	explosive=1;
	craterEffects="RC_82mmAirburstDust";
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
	aimAboveDefault=2;
	aimAboveTarget[]={12.7,12.7,12.7};	//high airburst to ignore cover, triggers when past half the trajectory aka descending while at this height above ground
};
class RC_Sh_82mm_AMOS_lowHEAB: RC_Sh_82mm_AMOS_HEAB
{
	imAboveTarget[]={6.35,6.35,6.35};	//low airburst to atleast ignore microterrain
};


//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_82mm_AMOS_backupHEAB: RC_82mm_HEAB_Shell_Base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,6,0};
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_submunition";
};


class SmokeShellArty;
class RC_SmokeShellArty: SmokeShellArty
{
	deflecting=0;
	explosionTime=0.2;
	timeToLive=120;
};
class Smoke_120mm_AMOS_White;
class RC_Smoke_82mm_AMOS_White: Smoke_120mm_AMOS_White
{
	aiAmmoUsageFlags=4;
	model="\A3\weapons_f\ammo\shell";	//model="\A3\Weapons_F\Ammo\shell.p3d";
	submunitionAmmo="RC_SmokeShellArty";
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
	aiAmmoUsageFlags="128 + 512";
	submunitionAmmo="RC_M_Mo_82mm_AT";
};


/* //makes game close when going close to mine...
class RangeTriggerBounding;
class RC_RangeTriggerBounding: RangeTriggerBounding
{
	mineTriggerRange=6;
	mineTriggerActivationRange=10;
	restrictZoneRadius=10;
};
*/
class APERSBoundingMine_Range_Ammo;
class RC_APERSBoundingMine_Range_Ammo: APERSBoundingMine_Range_Ammo
{
	mineBoundingDist=3;
	//mineTrigger="RC_RangeTriggerBounding";
};
class Mo_ClassicMineRange;
class RC_Mo_ClassicMineRange: Mo_ClassicMineRange
{
	submunitionAmmo="RC_APERSBoundingMine_Range_Ammo";
};


class RC_Mine_82mm_AMOS_range: SubmunitionBase
{
	aiAmmoUsageFlags=16;
	submunitionAmmo="RC_Mo_ClassicMineRange";
	submunitionConeType[]=
	{
		"custom", {{0.309,0.9511},{-0.809,0.5878},{-0.809,-0.5878},{0.309,-0.9511},{1,0}};
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


class RC_AT_Mine_82mm_AMOS_range: SubmunitionBase
{
	aiAmmoUsageFlags=16;
	submunitionAmmo="Mo_ATMineRange";
	submunitionConeType[]=
	{
		"custom", {{0.309,0.9511},{-0.809,0.5878},{-0.809,-0.5878},{0.309,-0.9511},{1,0}};
	};
	submunitionConeAngle=8;
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


class ammo_Penetrator_82mm_MP: ammo_Penetrator_Base
{
	caliber=37.8;
	warheadName="TandemHEAT";
	hit=454.1;
};
class RC_82mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_82mm_MP";
	indirectHit=26;
	indirectHitRange=9;
	cost=500;

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
};
class RC_Sh_82mm_AMOS_MP_MultiGuided: RC_Sh_AMOS_MP_MultiGuided_Base
{
	submunitionAmmo="RC_82mm_MP_MultiGuided_Submunition";
	triggerDistance=300;	//edit?
	hit=165;
	indirectHit=26;
	indirectHitRange=9;
	cost=500;

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
class RC_M_Mo_82mm_LG_DelayedFuse_Submunition: RC_82mm_MP_MultiGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_82mm_AMOS_LG_DelayedFuse: RC_Sh_82mm_AMOS_MP_MultiGuided
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


//105mm, yet to be introduced, no vehicle options yet
class Sh_155mm_AMOS;
class RC_Sh_105mm_AMOS_submunition: Sh_155mm_AMOS	//16km HE-RA range
{
	indirectHit=75.6;
	indirectHitRange=21.7;
	cost=233;
	explosionTime=0.0001;
	explosive=1;
	craterEffects="RC_105mmAirburstDust";
};
class RC_105mm_HEAB_Shell_Base: RC_HEAB_Shell_Base
{
	hit=207.3;
	indirectHit=75.6;
	indirectHitRange=21.7;
	cost=233;
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
class RC_Sh_105mm_AMOS_HEAB: RC_105mm_HEAB_Shell_Base
{
	submunitionAmmo="RC_Sh_105mm_AMOS_submunition";
	aimAboveDefault=2;
	aimAboveTarget[]={15.3,15.3,15.3};	//high airburst to ignore cover, triggers when past half the trajectory aka descending while at this height above ground
};
class RC_Sh_105mm_AMOS_lowHEAB: RC_Sh_105mm_AMOS_HEAB
{
	aimAboveTarget[]={7.65,7.65,7.65};	//low airburst to atleast ignore microterrain
};


//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_105mm_AMOS_backupHEAB: RC_105mm_HEAB_Shell_Base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,6,0};
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_105mm_AMOS_submunition";
};


class ammo_Penetrator_105mm_MP: ammo_Penetrator_Base
{
	caliber=48.4;
	warheadName="TandemHEAT";
	hit=581.6;
};
class RC_105mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_105mm_MP";
	indirectHit=37.8;
	indirectHitRange=10.9;
	cost=600;

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
class RC_Sh_105mm_AMOS_MP_MultiGuided: RC_Sh_AMOS_MP_MultiGuided_Base
{
	submunitionAmmo="RC_105mm_MP_MultiGuided_Submunition";
	triggerDistance=800;
	hit=207.3;
	indirectHit=37.8;
	indirectHitRange=10.9;
	cost=600;

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


class RC_Sh_105mm_AMOS_delayed_submunition: RC_Sh_105mm_AMOS_submunition
{
	explosionTime=0.2;
};
class RC_M_Mo_105mm_LG_DelayedFuse_submunition: RC_105mm_MP_MultiGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_105mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_105mm_AMOS_LG_DelayedFuse: RC_Sh_105mm_AMOS_MP_MultiGuided
{
	submunitionAmmo="RC_M_Mo_105mm_LG_DelayedFuse_submunition";
};


//120mm
class RC_Sh_120mm_AMOS_submunition: Sh_155mm_AMOS
{
	indirectHit=86.4;
	indirectHitRange=24.8;
	cost=266;
	explosionTime=0.0001;
	explosive=1;
	craterEffects="RC_120mmAirburstDust";
};
class RC_120mm_HEAB_Shell_Base: RC_HEAB_Shell_Base
{
	hit=236.7;
	indirectHit=86.4;
	indirectHitRange=24.8;
	cost=266;
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
class RC_Sh_120mm_AMOS_HEAB: RC_120mm_HEAB_Shell_Base
{
	submunitionAmmo="RC_Sh_120mm_AMOS_submunition";
	aimAboveDefault=2;
	aimAboveTarget[]={17.5,17.5,17.5};	//high airburst to ignore cover, triggers when past half the trajectory aka descending while at this height above ground
};
class RC_Sh_120mm_AMOS_lowHEAB: RC_Sh_120mm_AMOS_HEAB
{
	aimAboveTarget[]={8.75,8.75,8.75};	//low airburst to atleast ignore microterrain
};


//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_120mm_AMOS_backupHEAB: RC_120mm_HEAB_Shell_Base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,6,0};
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_120mm_AMOS_submunition";
};


class ammo_Penetrator_120mm_MP: ammo_Penetrator_Base
{
	caliber=55.4;
	warheadName="TandemHEAT";
	hit=664.6;
};
class RC_120mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_120mm_MP";
	indirectHit=43.2;
	indirectHitRange=12.4;
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
class RC_Sh_120mm_AMOS_MP_MultiGuided: RC_Sh_AMOS_MP_MultiGuided_Base
{
	submunitionAmmo="RC_120mm_MP_MultiGuided_Submunition";
	triggerDistance=500;
	hit=236.7;
	indirectHit=43.2;
	indirectHitRange=12.4;
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


class RC_Sh_120mm_AMOS_delayed_submunition: RC_Sh_120mm_AMOS_submunition
{
	explosionTime=0.2;
};
class RC_M_Mo_120mm_LG_DelayedFuse_submunition: RC_120mm_MP_MultiGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_120mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_120mm_AMOS_LG_DelayedFuse: RC_Sh_120mm_AMOS_MP_MultiGuided
{
	submunitionAmmo="RC_M_Mo_120mm_LG_DelayedFuse_submunition";
};


class Cluster_155mm_AMOS;
class RC_Cluster_120mm_AMOS: Cluster_155mm_AMOS
{
	aiAmmoUsageFlags="64 + 128";
	submunitionConeType[]=
	{
		"poissondisc",
		35
	};
};


//120mm NLOS, of N/LOS FSV
class RC_Sh_120mm_AMOS_HE_FSV: Sh_155mm_AMOS
{
	aiAmmoUsageFlags="64 + 128";
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,4,0};
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_120mm_AMOS_submunition";
	hit=236.7;
	indirectHit=0;
	indirectHitRange=0;
	cost=266;
};


//120mm LOS, of N/LOS FSV
class ammo_Penetrator_120mm;
class RC_ammo_Penetrator_120mm: ammo_Penetrator_120mm
{
	warheadName="TandemHEAT";
};
class Sh_120mm_HEAT_MP;
class RC_Sh_120mm_MP_T_Green: Sh_120mm_HEAT_MP
{
	aiAmmoUsageFlags="64 + 128 + 512";
	warheadName="TandemHEAT";
	//warheadName="HE";
	submunitionAmmo="RC_ammo_Penetrator_120mm";
	hit=95;
	indirectHit=50;
	indirectHitRange=10;
	deflecting=4;
	//dangerRadiusHit=160;
	//suppressionRadiusHit=32;
	//deflecting=8;
	model="\A3\Weapons_f\Data\bullettracer\shell_tracer_green";
	craterEffects="AAMissileCrater";
};


//155mm
class RC_Sh_155mm_AMOS_submunition: Sh_155mm_AMOS
{
	explosionTime=0.0001;
	explosive=1;
	//explosionEffects="RC_MortarExplosion";	//not ready yet
	craterEffects="RC_155mmAirburstDust";
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
class RC_Sh_155mm_AMOS_HEAB: RC_155mm_HEAB_Shell_Base
{
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
	aimAboveDefault=2;
	aimAboveTarget[]={21.2,21.2,21.2};	//high airburst to ignore cover, triggers when past half the trajectory aka descending while at this height above ground
};
class RC_Sh_155mm_AMOS_lowHEAB: RC_Sh_155mm_AMOS_HEAB
{
	aimAboveTarget[]={10.6,10.6,10.6};	//low airburst to atleast ignore microterrain, and able to take out MG/GMG bunkers with overhead protection, lower than 6m bugs
};


//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_155mm_AMOS_backupHEAB: RC_155mm_HEAB_Shell_Base
{
	aiAmmoUsageFlags="64 + 128";
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,6,0};
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_submunition";
};


class F_40mm_White;
class RC_Mo_Illum: F_40mm_White
{
	triggerTime=0;
	model="\A3\Weapons_F\Ammo\UGL_Flare";
	brightness=8000;
	intensity=80000;
	lightColor[]={100,100,100,100};
	timeToLive=180;
};
class Flare_155mm_AMOS_White: SubmunitionBase
{
	aiAmmoUsageFlags=1;
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
	aimAboveDefault=2;
	aimAboveTarget[]={500,500,500};		//triggers when past half the trajectory aka descending while at this height above ground
};


class Mine_155mm_AMOS_range;
class RC_Mine_155mm_AMOS_range: Mine_155mm_AMOS_range
{
	aiAmmoUsageFlags=16;
	submunitionAmmo="RC_Mo_ClassicMineRange";
	submunitionConeAngle=12;
	submunitionConeType[]=
	{
		"custom", {{0.95,0.31},{0.81,0.59},{0.59,0.81},{0.31,0.95},{0,1}  ,  {-0.95,0.31},{-0.81,0.59},{-0.59,0.81},{-0.31,0.95},{-1,0}  ,  {0.95,-0.31},{0.81,-0.59},{0.59,-0.81},{0.31,-0.95},{0,-1}  ,  {-0.95,-0.31},{-0.81,-0.59},{-0.59,-0.81},{-0.31,-0.95},{1,0}};
	};
};


class AT_Mine_155mm_AMOS_range;
class RC_AT_Mine_155mm_AMOS_range: AT_Mine_155mm_AMOS_range
{
	aiAmmoUsageFlags=16;
	submunitionConeAngle=12;
	submunitionConeType[]=
	{
		"custom", {{0.9511,0.309},{0.809,0.5878},{0.5878,0.809},{0.309,0.9511},{0,1}  ,  {-0.9511,0.309},{-0.809,0.5878},{-0.5878,0.809},{-0.309,0.9511},{-1,0}  ,  {0.9511,-0.309},{0.809,-0.5878},{0.5878,-0.809},{0.309,-0.9511},{0,-1}  ,  {-0.9511,-0.309},{-0.809,-0.5878},{-0.5878,-0.809},{-0.309,-0.9511},{1,0}};
	};
};


class RC_Smoke_155mm_AMOS_White: Smoke_120mm_AMOS_White
{
	aiAmmoUsageFlags=4;
	submunitionAmmo="RC_SmokeShellArty";
	submunitionConeAngle=10;
	submunitionConeType[]=
	{
		"poissondisc",
		10
	};
};


class RC_Cluster_155mm_AMOS: Cluster_155mm_AMOS
{
	aiAmmoUsageFlags="64 + 128";
	submunitionConeType[]=
	{
		"poissondisc",	//even spread
		50
	};
};


class ammo_Penetrator_155mm_MP: ammo_Penetrator_Base
{
	caliber=71.5;
	warheadName="TandemHEAT";
	hit=858.5;
};
class RC_155mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_155mm_MP";
	indirectHit=62.5;
	indirectHitRange=15;
	cost=800;

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
class RC_Sh_155mm_AMOS_MP_MultiGuided: RC_Sh_AMOS_MP_MultiGuided_Base
{
	submunitionAmmo="RC_155mm_MP_MultiGuided_Submunition";
	triggerDistance=800;
	hit=340;
	indirectHit=62.5;
	indirectHitRange=15;
	cost=800;

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
class RC_M_Mo_155mm_LG_DelayedFuse_submunition: RC_155mm_MP_MultiGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_155mm_AMOS_LG_DelayedFuse: RC_Sh_155mm_AMOS_MP_MultiGuided
{
	submunitionAmmo="RC_M_Mo_155mm_LG_DelayedFuse_submunition";
};


//230mm
class R_230mm_fly;
class RC_R_230mm_fly_HEAB_submunition: R_230mm_fly
{
	explosionTime=0.0001;
	explosive=1;
	explosionEffects="MortarExplosion";
	craterEffects="RC_230mmAirburstDust";
};
class RC_HEAB_Rocket_Base: RC_HEAB_Base
{
	//typicalSpeed=800;
	//explosive=0.80000001;
	//whistleDist=60;
	//thrust=0;
	caliber=34;
	airFriction=0;
	sideairFriction=0;
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	effectFly="Missile0";
	//model="\A3\Weapons_F\Ammo\Rocket_230mm_Fly_F";
	//effectFly="ArtilleryTrails";
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
	//craterEffects="BombCrater";
	craterEffects="RC_230mmAirburstDust";
	//explosionEffects="HeavyBombExplosion";
	/*
	soundSetExplosion[]=
	{
		"BombsHeavy_Exp_SoundSet",
		"BombsHeavy_Tail_SoundSet",
		"Explosion_Debris_SoundSet"
	};
	*/
	hit=300;	//defines recoil, needs to be this low, indirecthit defines damage
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
class RC_R_230mm_HEAB: RC_230mm_HEAB_Rocket_Base
{
	submunitionAmmo="RC_R_230mm_fly_HEAB_submunition";
	aimAboveDefault=2;
	aimAboveTarget[]={21.2,21.2,21.2};	//high airburst to ignore cover, triggers when past half the trajectory aka descending while at this height above ground
};
class RC_R_230mm_lowHEAB: RC_R_230mm_HEAB
{
	aimAboveTarget[]={10.6,10.6,10.6};	//to atleast ignore microterrain
};


//used in script as replacement when turret elevation is too low for Airburst
class RC_R_230mm_backupHEAB: RC_230mm_HEAB_Rocket_Base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,6,0};
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_R_230mm_fly_HEAB_submunition";
};


class R_230mm_Cluster;
class RC_R_230mm_Cluster: R_230mm_Cluster
{
	aiAmmoUsageFlags="64 + 128";
	submunitionConeType[]=
	{
		"poissondisccenter",
		80
	};
};


class ammo_Penetrator_230mm_MP: ammo_Penetrator_Base
{
	caliber=106.1;
	warheadName="TandemHEAT";
	hit=1273.8;
};
class RC_230mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	effectFly="Missile0";
	//model="\A3\Weapons_F\Ammo\Rocket_230mm_Fly_F";
	//effectFly="ArtilleryTrails";
	explosionEffects="HEShellExplosion";
	//explosionEffects="HeavyBombExplosion";
	craterEffects="BombCrater";
	submunitionAmmo="ammo_Penetrator_230mm_MP";
	indirectHit=400;
	indirectHitRange=15;
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
class RC_R_230mm_MP_MultiGuided: RC_Sh_AMOS_MP_MultiGuided_Base
{
	submunitionAmmo="RC_230mm_MP_MultiGuided_Submunition";
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	effectFly="Missile0";
	explosionEffects="HEShellExplosion";
	//explosionEffects="HeavyBombExplosion";
	craterEffects="BombCrater";
	triggerDistance=800;
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


class RC_R_230mm_fly_HEAB_delayed_submunition: RC_R_230mm_fly_HEAB_submunition
{
	explosionTime=0.2;
};
class RC_230mm_LG_DelayedFuse_submunition: RC_230mm_MP_MultiGuided_Submunition
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
class RC_230mm_LG_DelayedFuse: RC_R_230mm_MP_MultiGuided
{
	submunitionAmmo="RC_M_Mo_155mm_LG_DelayedFuse_submunition";
};


// 604mm ATACMS
class RC_R_604mm_fly_HEAB_submunition_ATACMS: RC_R_230mm_fly_HEAB_submunition
{
	indirectHit=3200;
	indirectHitRange=120;
	craterEffects="RC_604mmAirburstDust";
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
	aiAmmoUsageFlags="64 + 128 + 512";
	indirectHit=3200;
	indirectHitRange=120;
	cost=3000;
}
class RC_R_604mm_ATACMS_HEAB: RC_604mm_HEAB_Rocket_Base
{
	submunitionAmmo="RC_R_604mm_fly_HEAB_submunition_ATACMS";
	aimAboveDefault=2;
	aimAboveTarget[]={30,30,30};	//high airburst to ignore cover, triggers when past half the trajectory aka descending while at this height above ground
};


//used in script as replacement when turret elevation is too low for Airburst
class RC_R_604mm_backupHEAB: RC_604mm_HEAB_Rocket_Base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,6,0};
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_R_604mm_fly_HEAB_submunition_ATACMS";
};


class RC_R_604mm_ATACMS_DPICM: R_230mm_Cluster
{
	submunitionConeAngle=25;
	submunitionConeType[]=
	{
		"poissondisccenter",
		320
	};
};