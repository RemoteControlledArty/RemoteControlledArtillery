//throwable
class GrenadeHand;
class Interceptor_MP_ThrowAmmo_Base: GrenadeHand
{
	class Eventhandlers
	{
		fired="if (!local (_this select 6)) exitWith {}; [_this select 6, _this select 7] spawn RC_fnc_Interceptor_fired;";		//spawn to allow sleep
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
//class DB_ammo_switchblade_AT
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
	proxyShape="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";	//supposedly no effect
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
class Interceptor_MP: Interceptor_MP_Base
{
	hit=150;
	htMax=1800;
	htMin=60;
	indirectHit=42;
	indirectHitRange=7;	//7
	warheadName="TandemHEAT";
	submunitionAmmo="Interceptor_Penetrator_MP";
	submunitionDirectionType="SubmunitionModelDirection";
};


/*
class ammo_Penetrator_Vorona;
class FPV_RPG42_AT_Penetrator_MP: ammo_Penetrator_Vorona
{
	hit=480;
	indirectHit=0;
	indirectHitRange=0;
	warheadName="TandemHEAT";
	airFriction=-0.01;		//so shaped charge still has an effect when airbursted
};
class M_Vorona_HEAT;
class FPV_RPG42_MP: M_Vorona_HEAT
{
	explosive=0.80000001;
	hit=150;
	htMax=1800;
	htMin=60;
	indirectHit=42;
	indirectHitRange=7;	//7
	submunitionInitSpeed=1000;
	warheadName="TandemHEAT";
	submunitionAmmo="FPV_RPG42_AT_Penetrator_MP";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.1};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
};


class FPV_RPG42_AT_Penetrator_PvP: FPV_RPG42_AT_Penetrator_MP
{
	hit=240;
	warheadName="TandemHEAT";
	//warheadName="HEAT";
};
class FPV_RPG42_PvP: FPV_RPG42_MP
{
	hit=150;
	htMax=600;	//?
	htMin=60;	//?
	indirectHit=21;	//42
	indirectHitRange=5.5;
	warheadName="TandemHEAT";
	//warheadName="HEAT";
	submunitionAmmo="FPV_RPG42_AT_Penetrator_PvP";
};


class FPV_RPG42_AT_Penetrator_Training: FPV_RPG42_AT_Penetrator_MP
{
	hit=3;
	warheadName="HEAT";
};
class FPV_RPG42_Training: FPV_RPG42_MP
{
	hit=0;
	htMax=0;	//?
	htMin=0;	//?
	indirectHit=1;
	indirectHitRange=7;
	warheadName="HEAT";
	submunitionAmmo="FPV_RPG42_AT_Penetrator_Training";
};


class Default;
class RC_target_confirmer_AB_ammo: Default
{
	model="\A3\weapons_f\launchers\RPG32\tbg32v_rocket.p3d";	//change to something smaller, and remove all explosion effects
	simulation="shotMissile";
	simulationStep=0.050000001;
	timeToLive=1;
	CraterEffects="";
	explosionEffects="";

	hit=0;
	indirectHit=0;
	indirectHitRange=0;

	lockType=0;
	laserLock=1;
	irLock=1;
	airLock=1;
	nvLock=1;

	missileLockCone=40;
	missileKeepLockedCone=360;
	missileLockMaxDistance=4000;
	missileLockMinDistance=1;
	missileLockMaxSpeed=150;
	cmImmunity=1;
	manualControl=1;
	missileManualControlCone=0;
	maxControlRange=4000;

	initTime=1;
	thrustTime=1;
	thrust=0;
	maneuvrability=0;
	trackOversteer=1;
	trackLead=1;
	airFriction=0.01;
	sideAirFriction=0.01;
	maxSpeed=1;
	typicalSpeed=1;
	fuseDistance=1;
	deflecting=1;
	cost=1;

	visibleFire=1;
	audibleFire=1;
	visibleFireTime=1;

	aiAmmoUsageFlags="32";

	soundHit[]=
	{
		"",
		100,
		1
	};
	soundFly[]=
	{
		"",
		0.0099999998,
		2
	};
	soundEngine[]=
	{
		"",
		0.001,
		1
	};

	class Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};
};
class RC_shapedcharge_reticle_AB_ammo: RC_target_confirmer_AB_ammo
{
	maxControlRange=0;
	maxSpeed=1000;
	typicalSpeed=1000;
};

class RC_Crocus_Deployer_Ammo: RC_target_confirmer_AB_ammo
{
	model="\ArmaFPV\drone.p3d";
	timeToLive=3;
	initTime=3;
	thrustTime=3;
	typicalSpeed=1;
	fuseDistance=3;
	visibleFire=3;
	audibleFire=3;
	visibleFireTime=3;
};
*/