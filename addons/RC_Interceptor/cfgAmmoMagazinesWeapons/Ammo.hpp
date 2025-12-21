//throwable
class GrenadeHand;
class Interceptor_MP_ThrowAmmo_Base: GrenadeHand
{
	class Eventhandlers
	{
		fired="if (!local (_this select 6)) exitWith {}; [_this select 6, _this select 7] spawn RC_fnc_Interceptor_firedEH;";		//spawn to allow sleep
	};
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap";
	//model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap_fly";
	//model="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";

	hit=0;	//8
	indirectHit=0;	//8
	indirectHitRange=0;	//6
	dangerRadiusHit=0;	//60
	suppressionRadiusHit=0;	//24
	typicalspeed=18;
	fuseDistance=20;	//0
};
class Interceptor_MP_ThrowAmmo:		Interceptor_MP_ThrowAmmo_Base	{asset="Interceptor_MP";};


class ammo_Penetrator_Vorona;
class Interceptor_Penetrator_MP: ammo_Penetrator_Vorona
{
	//caliber=60;
	hit=480;
	indirectHit=0;
	indirectHitRange=0;
	warheadName="TandemHEAT";
	airFriction=-0.01;		//so shaped charge still has an effect when airbursted
};


class ammo_Missile_CruiseBase;
class Interceptor_MP_Core: ammo_Missile_CruiseBase
{
	soundHit1[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_01",
		2.5118899,
		1,
		2000
	};
	soundHit2[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_02",
		2.5118899,
		1,
		2000
	};
	soundHit3[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_03",
		2.5118899,
		1,
		2000
	};
	SoundSetExplosion[]=
	{
		"RocketsHeavy_Exp_SoundSet",
		"RocketsHeavy_Tail_SoundSet",
		"Explosion_Debris_SoundSet"
	};
	CraterEffects="ATMissileCrater";
	effectsFire="CannonFire";
	effectFlare="FlareShell";
	effectsMissile="EmptyEffect";
	explosionPos="explosionPos";
	explosionSoundEffect="DefaultExplosion";
	explosionEffectsDir="explosionDir";
	explosionEffects="ATMissileExplosion";
	explosionType="explosive";
	initTime=0.25;
	effectsMissileInit="";
	effectsSmoke="";
	muzzleEffect="";
	maxSpeed=15;
	class CamShakePlayerFire
	{
		distance=1;
		duration=0.1;
		frequency=20;
		power=3;
	};
	class CamShakeHit
	{
		distance=1;
		duration=0.60000002;
		frequency=20;
		power=110;
	};
	class CamShakeExplode
	{
		distance=91.329597;
		duration=1.4;
		frequency=20;
		power=11;
	};
	class CamShakeFire
	{
		distance=61.967701;
		duration=1.6;
		frequency=20;
		power=2.78316;
	};
};
class Interceptor_MP_Base: Interceptor_MP_Core
{
	explosive=0.80000001;
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.1};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;

	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_ap";
	//model="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";
	proxyShape="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";		//supposedly no effect
	soundFly[]=
	{
		//soundEngineOnExt[]=
		//"ArmaFPV\sounds\quad_start_full_01.wav",
		"ArmaFPV\sounds\quad_engine_full_01.wav",
		0.56234133,
		1,
		200
	};
	/*
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Fly_Titan",
		0.63095701,
		1.5,
		300
	};
	*/
};
class Interceptor_MP_Pre: Interceptor_MP_Base
{
	timeToLive=600;
	maxSpeed=97.222;
	//maneuvDependsOnSpeedCoef=0.40000001;
	fuseDistance=20;
	//cost=5000;

	hit=150;
	htMax=1800;
	htMin=60;
	indirectHit=42;
	indirectHitRange=7;	//7
	warheadName="TandemHEAT";
	submunitionAmmo="Interceptor_Penetrator_MP";
	submunitionDirectionType="SubmunitionModelDirection";
};
class Interceptor_MP: Interceptor_MP_Pre
{
	airFriction=0;			//vanilla 0.44999999
	sideAirFriction=0;		//vanilla 0.5

	initTime=0;
	thrustTime=0;
	thrust=0;				//0 causes jitter as it tries to fall?
};


//testing alternatives
class Interceptor_MP_Friction: Interceptor_MP_Pre
{
	airFriction=0.5;
	sideAirFriction=0.5;

	initTime=0;
	thrustTime=0;
	thrust=0;
};
class Interceptor_MP_Thrust10: Interceptor_MP_Pre
{
	airFriction=0;
	sideAirFriction=0;

	initTime=0.1;
	thrustTime=5;
	thrust=10;
};
class Interceptor_MP_Thrust35: Interceptor_MP_Pre
{
	airFriction=0;
	sideAirFriction=0;

	initTime=0.1;
	thrustTime=5;
	thrust=35;
};
class Interceptor_MP_Friction_Thrust10: Interceptor_MP_Pre
{
	airFriction=0.5;
	sideAirFriction=0.5;

	initTime=0.1;
	thrustTime=5;
	thrust=10;
};
class Interceptor_MP_Friction_Thrust35: Interceptor_MP_Pre
{
	airFriction=0.5;
	sideAirFriction=0.5;

	initTime=0.1;
	thrustTime=5;
	thrust=35;
};