class ammo_Penetrator_Vorona;
class RC_Penetrator_ATGM: ammo_Penetrator_Vorona
{
	hit=1000;
};


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


class SubmunitionBase;
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

//new ammo tests
//reminder, change Cluster and Mines to submunitionConeType[] = {"poissondisc",  for more even submunition spead

//option A: explosionTime=1;  typicalSpeed=80;  submunitionInitSpeed=80;
//option B: explosionTime=0.1;  fuseDistance=80
//option C: triggerOnImpact=1;  submunitionInitialOffset[]={0,0,-X};
//option D: triggerDistance=100; explosionTime=0.01; submunitionInitialOffset[]={0,0,70};

class Sh_155mm_AMOS;
class Cluster_155mm_AMOS;
class Sh_155mm_AMOS_guided;
class Sh_155mm_AMOS_LG;
class Smoke_120mm_AMOS_White;
class AT_Mine_155mm_AMOS_range;

//add 82mm mine
class RC_82mm_HEAB_base: SubmunitionBase
{
	submunitionAmmo="RC_82mm_HE_sub";
	submunitionCount=1;
	submunitionConeAngle=0;
	cost=200;
	muzzleEffect="";
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
class Sh_82mm_AMOS;
class RC_82mm_HE_sub: Sh_82mm_AMOS
{
	explosionTime=0.01;
	explosive=1;
	CraterEffects="";
};
class ShellBase;
class RC_82mm_HEAB: RC_82mm_HEAB_base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-16.1};		//high airburst to ignore cover very well
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_82mm_HE_sub";

	//deleteParentWhenTriggered=1;
	ExplosionEffects="";
	CraterEffects="";
	explosive=0;
	hit=0;
	indirectHit=0;
	indirectHitRange=0;
};
class RC_82mm_HEAB_low: RC_82mm_HEAB
{
	submunitionInitialOffset[]={0,0,-6};		//low airburst to ignore atleast microterrain
};

class RC_155mm_Smoke: Smoke_120mm_AMOS_White
{
	submunitionConeAngle=10;
	submunitionConeType[]=
	{
		"poissondisc",
		10
	};
};

/*
class ShellCore: Default
{
	simulation="shotShell";
	simulationStep=0.050000001;
	timeToLive=20;
	cost=1000;
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
	indirectHitRange=8;
	visibleFire=16;
	audibleFire=16;
	visibleFireTime=10;
	deflecting=5;
};
class SubmunitionCore: Default
{
	simulation="shotSubmunitions";
	simulationStep=0.050000001;
	timeToLive=180;
	cost=1000;
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
	artilleryLock=1;
	indirectHitRange=8;
	visibleFire=16;
	audibleFire=16;
	visibleFireTime=10;
	deflecting=5;
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
	class Sh_155mm_AMOS: ShellBase
{
	hit=340;
	indirectHit=125;
	indirectHitRange=30;
	warheadName="HE";
	dangerRadiusHit=750;
	suppressionRadiusHit=75;
	typicalSpeed=800;
	caliber=10;
	deflecting=0;
	explosive=0.80000001;
	cost=300;
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
*/


/*
class Smoke_82mm_AMOS_White: ShotDeployBase
{
	model="\A3\weapons_f\ammo\shell";
	submunitionAmmo="SmokeShellArty";
};
*/














//airburst shell
class Default;
class RC_155mm_HEAB_shell_base: Default
{
	//CLASS shellcore
	simulation="shotShell";		//simulation="shotSubmunitions";
	//simulationStep=0.050000001;
	//timeToLive=20;
	//cost=1000;
	//soundHit[]=
	//{
	//	"",
	//	316.22775,
	//	1
	//};
	//soundFly[]=
	//{
	//	"",
	//	0.031622775,
	//	4
	//};
	//indirectHitRange=8;
	//visibleFire=16;
	//audibleFire=16;
	//visibleFireTime=10;
	//deflecting=5;


	//CLASS submunitioncore
	//simulation="shotSubmunitions";	//simulation="shotShell";
	simulationStep=0.050000001;
	//timeToLive=180;
	//cost=1000;
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
	//artilleryLock=1;
	//indirectHitRange=8;
	//visibleFire=16;
	//audibleFire=16;
	visibleFireTime=10;
	//deflecting=5;


	//CLASS shellbase
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
	//CraterEffects="HEShellCrater";
	CraterWaterEffects="ImpactEffectsWaterHE";
	//ExplosionEffects="HEShellExplosion";
	visibleFire=64;
	audibleFire=250;
	//dangerRadiusHit=-1;
	//suppressionRadiusHit=30;
	//timeToLive=360;
	//muzzleEffect="";
	//caliber=34;
	//deflecting=10;
	deflectionDirDistribution=0.38999999;
	penetrationDirDistribution=0.25999999;
	whistleOnFire=2;
	aiAmmoUsageFlags="64 + 128 + 256";
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

		
	//CLASS 155mm
	hit=340;
	indirectHit=125;	//155mm default 125
	indirectHitRange=30;	//155mm default 30
	warheadName="HE";
	dangerRadiusHit=750;	//155mm default 750
	suppressionRadiusHit=75;	//155mm default 75
	typicalSpeed=800;
	caliber=10;
	deflecting=0;
	explosive=0.80000001;	//155mm default 0.80000001
	cost=300;
	model="\A3\weapons_f\ammo\shell";
	CraterEffects="ArtyShellCrater";
	ExplosionEffects="MortarExplosion";
	whistleDist=60;
	artilleryLock=1;
	thrust=0;
	timeToLive=180;
	airFriction=0;
	sideairFriction=0;
	///*
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
	//*/
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


	//CLASS 82mm guided
	submunitionCount=1;
	submunitionConeAngle=0;
	laserLock=0;
	autoSeekTarget=0;
	//cost=200;
	muzzleEffect="";
	//triggerDistance=300;	//disabled with -1
	//airFriction=0;
	//hit=165;
	/*
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
	*/
};



class RC_Default
{
	access=3;
	hit=0;
	indirectHit=0;
	indirectHitRange=1;
	underwaterHitRangeCoef=1;
	typicalSpeed=900;
	explosionForceCoef=1;
	isCraterOriented=0;
	model="";
	proxyShape="";
	craterShape="";
	simulation="";
	weaponType="Default";
	animated=0;
	shadow=0;
	cost=0;
	maxSpeed=0;
	cartridge="";
	simulationStep=0.050000001;
	tracerColor[]={0.69999999,0.69999999,0.5,0.039999999};
	tracerColorR[]={0.69999999,0.69999999,0.5,0.039999999};
	soundFly[]=
	{
		"",
		1,
		1
	};
	soundEngine[]=
	{
		"",
		1,
		1
	};
	soundHit[]=
	{
		"",
		1,
		1
	};
	supersonicCrackNear[]=
	{
		"",
		1,
		1
	};
	supersonicCrackFar[]=
	{
		"",
		1,
		1
	};
	soundFall[]=
	{
		"",
		1,
		1
	};
	soundFakeFall[]=
	{
		"soundFall",
		1
	};
	hitGroundSoft[]=
	{
		"soundHit",
		1
	};
	hitGroundHard[]=
	{
		"soundHit",
		1
	};
	hitMan[]=
	{
		"soundHit",
		1
	};
	hitArmor[]=
	{
		"soundHit",
		1
	};
	hitIron[]=
	{
		"soundHit",
		1
	};
	hitBuilding[]=
	{
		"soundHit",
		1
	};
	hitFoliage[]=
	{
		"soundHit",
		1
	};
	hitWood[]=
	{
		"soundHit",
		1
	};
	hitGlass[]=
	{
		"soundHit",
		1
	};
	hitGlassArmored[]=
	{
		"soundHit",
		1
	};
	hitConcrete[]=
	{
		"soundHit",
		1
	};
	hitRubber[]=
	{
		"soundHit",
		1
	};
	hitPlastic[]=
	{
		"soundHit",
		1
	};
	hitDefault[]=
	{
		"soundHit",
		1
	};
	hitMetal[]=
	{
		"soundHit",
		1
	};
	hitMetalplate[]=
	{
		"soundHit",
		1
	};
	hitTyre[]=
	{
		"soundHit",
		1
	};
	hitWater[]=
	{
		"soundHit",
		1
	};
	soundImpact[]=
	{
		"",
		1,
		1
	};
	impactGroundSoft[]=
	{
		"soundImpact",
		1
	};
	impactGroundHard[]=
	{
		"soundImpact",
		1
	};
	impactMan[]=
	{
		"soundImpact",
		1
	};
	impactIron[]=
	{
		"soundImpact",
		1
	};
	impactArmor[]=
	{
		"soundImpact",
		1
	};
	impactBuilding[]=
	{
		"soundImpact",
		1
	};
	impactFoliage[]=
	{
		"soundImpact",
		1
	};
	impactWood[]=
	{
		"soundImpact",
		1
	};
	impactGlass[]=
	{
		"soundImpact",
		1
	};
	impactGlassArmored[]=
	{
		"soundImpact",
		1
	};
	impactConcrete[]=
	{
		"soundImpact",
		1
	};
	impactRubber[]=
	{
		"soundImpact",
		1
	};
	impactPlastic[]=
	{
		"soundImpact",
		1
	};
	impactDefault[]=
	{
		"soundImpact",
		1
	};
	impactMetal[]=
	{
		"soundImpact",
		1
	};
	impactMetalplate[]=
	{
		"soundImpact",
		1
	};
	impactTyre[]=
	{
		"soundImpact",
		1
	};
	impactWater[]=
	{
		"soundImpact",
		1
	};
	grenadeFireSound[]={};
	grenadeBurningSound[]={};
	deflecting=0;
	deflectionSlowDown=0.80000001;
	explosive=1;
	explosionEffects="ExplosionEffects";
	craterEffects="ImpactEffectsMedium";
	craterWaterEffects="ImpactEffectsWater";
	effectsMissile="ExplosionEffects";
	effectsMissileInit="";
	effectsSmoke="SmokeShellWhite";
	effectsFire="CannonFire";
	effectFlare="FlareShell";
	effectFly="";
	mineJumpEffects="";
	waterEffectOffset=0.44999999;
	directionalExplosion=0;
	explosionAngle=60;
	explosionDir="explosionDir";
	explosionPos="explosionPos";
	explosionEffectsDir="explosionDir";
	minimumSafeZone=0.1;
	soundTrigger[]={};
	soundActivation[]={};
	soundDeactivation[]={};
	explosionSoundEffect="";
	timeToLive=10;
	minTimeToLive=0;
	irLock=0;
	airLock=0;
	laserLock=0;
	nvLock=0;
	artilleryLock=0;
	hitOnWater=0;
	lockSeekRadius=100;
	manualControl=0;
	maxControlRange=350;
	maneuvrability=1;
	trackLead=1;
	trackOversteer=1;
	missileLockCone=0;
	weaponLockSystem=0;
	cmImmunity=1;
	lockType=0;
	maverickweaponIndexOffset=0;
	sideAirFriction=1;
	artilleryDispersion=1;
	artilleryCharge=1;
	autoSeekTarget=0;
	visibleFire=0;
	audibleFire=0;
	shootDistraction=-1;
	visibleFireTime=0;
	explosionTime=0;
	fuseDistance=0;
	initTime=0;
	thrustTime=1.5;
	thrust=210;
	airFriction=-0.00050000002;
	icon="";
	submunitionAmmo="";
	explosionType="explosive";
	mineTrigger="RangeTrigger";
	mineBoundingTime=3;
	mineBoundingDist=3;
	mineInconspicuousness=10;
	mineFloating=-1;
	mineDiveSpeed=1;
	minePlaceDist=0.5;
	class HitEffects
	{
		vehicle="ImpactMetal";
		object="ImpactConcrete";
	};
	suppressionRadiusBulletClose=-1;
	suppressionRadiusHit=-1;
	dangerRadiusBulletClose=-1;
	dangerRadiusHit=-1;
	caliber=1;
	whistleDist=0;
	whistleOnFire=0;
	class NVGMarkers
	{
	};
	minDamageForCamShakeHit=0.55000001;
	class EventHandlers
	{
	};
};




class RC_ShellCore: RC_Default
{
	simulation="shotShell";
	simulationStep=0.050000001;
	//timeToLive=20;
	//cost=1000;
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
	//indirectHitRange=8;
	//visibleFire=16;
	//audibleFire=16;
	visibleFireTime=10;
	//deflecting=5;
};


class RC_ShellBase: RC_ShellCore
{
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
	//CraterEffects="HEShellCrater";
	CraterWaterEffects="ImpactEffectsWaterHE";
	//ExplosionEffects="HEShellExplosion";
	visibleFire=64;
	audibleFire=250;
	//dangerRadiusHit=-1;
	//suppressionRadiusHit=30;
	//timeToLive=360;
	//muzzleEffect="";
	//caliber=34;
	//deflecting=10;
	deflectionDirDistribution=0.38999999;
	penetrationDirDistribution=0.25999999;
	whistleOnFire=2;
	aiAmmoUsageFlags="64 + 128 + 256";
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


class RC_Sh_155mm_AMOS: RC_ShellBase
{
	hit=340;
	indirectHit=125;	//155mm default 125
	indirectHitRange=30;	//155mm default 30
	warheadName="HE";
	dangerRadiusHit=750;	//155mm default 750
	suppressionRadiusHit=75;	//155mm default 75
	typicalSpeed=800;
	caliber=10;
	deflecting=0;
	explosive=0.80000001;	//155mm default 0.80000001
	cost=300;
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













/*
class RC_155mm_HE_sub_base: Default

*/


class RC_155mm_HE_sub: Sh_155mm_AMOS
{
	explosionTime=0.01;
	explosive=1;
	CraterEffects="";
};
class RC_155mm_HEAB: RC_Sh_155mm_AMOS	//RC_155mm_HEAB_shell_base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-26.8};		//high airburst to ignore cover very well
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_155mm_HE_sub";

	//deleteParentWhenTriggered=1;
};
class RC_155mm_HEAB_low: RC_155mm_HEAB
{
	submunitionInitialOffset[]={0,0,-6};	//low airburst to ignore atleast microterrain
};

/*
class RC_155mm_HEAB_test: Sh_155mm_AMOS
{
	triggerDistance=26.8;	//doesnt work
};
*/

//Bunker Buster
class M_Mo_82mm_AT_LG;
class RC_155mm_LGBB_subcarrier: M_Mo_82mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,1.5};	//3m infront of projecticle during impact
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_155mm_HE_sub";

	//deleteParentWhenTriggered=1;
	ExplosionEffects="";
	CraterEffects="";
	explosive=0;
	hit=0;
	indirectHit=0;
	indirectHitRange=0;
};
class RC_155mm_LGBB: Sh_155mm_AMOS_LG
{
	submunitionAmmo="RC_155mm_LGBB_subcarrier";
};

class M_Mo_155mm_AT_LG;
class RC_155mm_LGD_sub: M_Mo_155mm_AT_LG
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,1.5};	//1.5m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_155mm_HE_sub";
};
class RC_155mm_LGD: Sh_155mm_AMOS_LG
{
	submunitionAmmo="RC_155mm_LGD_sub";
};

class RC_155mm_Cluster: Cluster_155mm_AMOS
{
	submunitionConeType[]=
	{
		"poissondisc",	//even spread
		35
	};
};

class R_230mm_fly;
class RC_230mm_HEAB_sub: R_230mm_fly
{
	explosionTime=0.01;
	explosive=1;
	CraterEffects="";
};
class RC_230mm_HEAB: SubmunitionBase
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,-26.8};		//30m indirecthitrange with 27.8m high airburst = 27.8m area covered, lower airburst would cover slightly larger area, but ignore cover less, esp in towns
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_230mm_HEAB_sub";

	artilleryLock=1;
	cost=1000;
	airFriction=0;
	muzzleEffect="";
	effectFly="Missile0";
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	hit=0;
};

//poissondisccenter exists

class R_230mm_Cluster;
class RC_230mm_Cluster: R_230mm_Cluster
{
	submunitionConeType[]=
	{
		"poissondisc",
		50
	};
};