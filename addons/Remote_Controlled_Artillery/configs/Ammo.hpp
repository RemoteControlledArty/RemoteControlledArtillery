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


















//airburst shell
class Default;
class RC_155mm_HEAB_shell_base: Default
{
	//CLASS shellcore
	//simulation="shotShell";		//twice
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
	simulation="shotSubmunitions";
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
	indirectHit=0;	//155mm default 125
	indirectHitRange=0;	//155mm default 30
	warheadName="HE";
	dangerRadiusHit=0;	//155mm default 750
	suppressionRadiusHit=0;	//155mm default 75
	typicalSpeed=800;
	caliber=10;
	deflecting=0;
	explosive=0;	//155mm default 0.80000001
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
	/*
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
	*/
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
	triggerDistance=300;
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













/*
class RC_155mm_HE_sub_base: Default
{
	//shellcore
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

	//shellbase
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
	dangerRadiusHit=-1;
	suppressionRadiusHit=30;
	timeToLive=360;
	muzzleEffect="";
	caliber=34;
	deflecting=10;
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

	//155mm
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


class RC_155mm_HE_sub: Sh_155mm_AMOS
{
	explosionTime=0.01;
	explosive=1;
	CraterEffects="";
};
class RC_155mm_HEAB: RC_155mm_HEAB_shell_base
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