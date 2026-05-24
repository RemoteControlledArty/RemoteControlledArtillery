class B_25x40mm_airburst;
class RC_M30_30mm_MPAB_T: B_25x40mm_airburst
{
	class Eventhandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\AB_EH.hpp"
	};

	//airFriction = -0.0006;	//-0.0006
	Aegis_airburstFuseDistance = 3;
	Aegis_isAirburst = 1;
	explosionAngle = 360;	//60
	deflecting = 0;		//5
	deflectionSlowDown = 0.8;
	fuseDistance = 4;
	//tracerStartTime = 0.04;
	tracerEndTime = 6;

	caliber=4.4;
	hit=90;
	indirectHit=6;	//2
	indirectHitRange=4;	//4

	triggerOnImpact=1;
	//deleteParentWhenTriggered=0;

	//Penetration / Fuze
	explosive=0.60000002;

	//Use
	warheadName="HE";
	aiAmmoUsageFlags="64 + 128 + 256 + 512";	//inf, veh, air, armor
};
class RC_M30_30mm_MPAB_DF_T: RC_M30_30mm_MPAB_T
{
	//Submun
	submunitionAmmo="RC_B_30mm_MP_DF_Sub";
	triggerOnImpact=1;
	submunitionCount=1;
	submunitionParentSpeedCoef=0;
	submunitionInitSpeed=1000;	//210 doesnt make it through walls
	submunitionConeAngle=0;
	submunitionDirectionType="SubmunitionModelDirection";

	//Trigger/ed
	deleteParentWhenTriggered=1;
	submunitionInitialOffset[]={0,0,-4};

	//Simulation
	//simulation="shotShell";	//wrecks zero function, submun and DF somehow works without this simulations
};
class RC_M30_30mm_MPAB_QF_T: RC_M30_30mm_MPAB_DF_T
{
	submunitionAmmo="RC_ammo_Penetrator_MP_30mm";
	submunitionInitSpeed=1000;
	deleteParentWhenTriggered=0;
	explosive=0.80000001;
};


class B_30mm_AP;
class RC_M30_30mm_Slug: B_30mm_AP
{
	typicalSpeed=1000;	//1120
	tracerStartTime = 0.04;
	tracerEndTime = 6;
	cost=20;
	aiAmmoUsageFlags="64 + 128";	//inf, veh

	class CamShakeHit
	{
		power=20;
		duration=0.60000002;
		frequency=20;
		distance=1;
	};
};


class BulletBase;
class RC_BuckshotClose_Pellet: BulletBase
{
	hit=6;	//4-8
	indirectHit=0;
	indirectHitRange=0;	//0.15-0.6
	typicalSpeed=400;	//360
	deflecting=15;	//30-50
	airFriction=-0.005;
};
class RC_BuckshotFar_Pellet: RC_BuckshotClose_Pellet
{
	hit=12;	//4-8
	deflecting=10;	//30-50
	airFriction=-0.0025;
};
/*
class RC_DroneShot_Pellet: RC_BuckshotClose_Pellet
{
	hit=4;	//4-8
	deflecting=10;	//30-50
	airFriction=-0.0075;
};
*/


class B_20mm_cUAS_Base;
class RC_M30_30mm_BuckshotClose: B_20mm_cUAS_Base
{
	model="\A3\weapons_f\empty";
	
	simulation="shotSubmunitions";
	submunitionAmmo="RC_BuckshotClose_Pellet";
	aiAmmoUsageFlags="64 + 256";	//inf, air
	deleteParentWhenTriggered=1;
	triggerTime=0;
	airFriction=-0.005;
	//airLock=2;
	tracerStartTime = 1;
	tracerEndTime = 1;

	submunitionConeAngle=1;
	submunitionConeType[]=
	{
		"poissondisc",
		50
	};

	hit=30;			//test if less doesnt engage vehicles
	indirectHit=0;
	indirectHitRange=0;
	cost=20;
	//caliber=3.4000001;	//test if 1 doesnt engage helis
};
class RC_M30_30mm_BuckshotFar: RC_M30_30mm_BuckshotClose
{
	submunitionAmmo="RC_BuckshotFar_Pellet";
	airFriction=-0.0025;

	submunitionConeAngle=0.3;
	submunitionConeType[]=
	{
		"poissondisc",
		25
	};
};
/*
class RC_M30_30mm_DroneShot: RC_M30_30mm_BuckshotClose
{
	submunitionAmmo="RC_DroneShot_Pellet";
	airFriction=-0.0075;

	submunitionConeAngle=1.25;
	submunitionConeType[]=
	{
		"poissondisc",
		100
	};
};
*/