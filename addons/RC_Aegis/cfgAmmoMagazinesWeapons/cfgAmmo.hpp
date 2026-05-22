class B_25x40mm_airburst;
class RC_M30_30mm_MPAB_DF_T: B_25x40mm_airburst
{
	class Eventhandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\AB_EH.hpp"
	};

	//airFriction = -0.0006;	//-0.0006
	//Aegis_airburstFuseDistance = 3;
	//Aegis_isAirburst = 1;
	explosionAngle = 360;	//60
	deflecting = 5;	
	deflectionSlowDown = 0.8;
	fuseDistance = 3;

	caliber=4.4;
	hit=90;
	indirectHit=6;	//2
	indirectHitRange=4;	//4


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

	//Penetration / Fuze
	explosive=0.60000002;

	//Simulation
	simulation="shotShell";

	//Use
	warheadName="HE";
	aiAmmoUsageFlags="64 + 128 + 256 + 512";
};
class RC_M30_30mm_MPAB_QF_T: RC_M30_30mm_MPAB_DF_T
{
	submunitionAmmo="RC_ammo_Penetrator_MP_30mm";
	submunitionInitSpeed=1000;
	deleteParentWhenTriggered=0;
	explosive=0.80000001;
};


class BulletBase;
class RC_BuckshotClose_Pellet: BulletBase
{
	hit=6;	//4-8
	indirectHit=0;
	indirectHitRange=0;	//0.15-0.6
	typicalSpeed=210;	//360
	deflecting=15;	//30-50
	airFriction=-0.005;
};
class RC_BuckshotFar_Pellet: BulletBase
{
	hit=6;	//4-8
	indirectHit=0;
	indirectHitRange=0;	//0.15-0.6
	typicalSpeed=210;	//360
	deflecting=15;	//30-50
	airFriction=-0.005;
};
class B_20mm_cUAS_Base;
class RC_M30_30mm_BuckshotClose: B_20mm_cUAS_Base
{
	simulation="shotSubmunitions";
	submunitionAmmo="RC_BuckshotClose_Pellet";
	aiAmmoUsageFlags="256";
	deleteParentWhenTriggered=1;
	triggerTime=0;
	airFriction=-0.005;
	airLock=2;

	submunitionConeAngle=1;		//0.4deg =
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

	submunitionConeAngle=0.5;		//0.4deg =
	submunitionConeType[]=
	{
		"poissondisc",
		25
	};
};