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
		"poissondisccenter",
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
	submunitionInitialOffset[]={0,0,-26.8};		//high airburst to ignore cover very well
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
		35
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
	submunitionInitialOffset[]={0,0,-26.8};		//30m indirecthitrange with 27.8m high airburst = 27.8m area covered, lower airburst would cover slightly larger area, but ignore cover less, esp in towns
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
	//change to large explosion
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
		50
	};
};


class RC_R_604mm_ATACMS_DPICM: R_230mm_Cluster
{
	submunitionConeAngle=30;

	submunitionConeType[]=
	{
		"poissondisccenter",	//test out non center spread
		350
	};
};