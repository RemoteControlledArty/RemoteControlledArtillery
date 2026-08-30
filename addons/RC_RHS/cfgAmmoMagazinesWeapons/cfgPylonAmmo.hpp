class RC_Hydra_MP;
class RC_RHS_Hydra_MP: RC_Hydra_MP
{
	model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";
};
class RC_RHS_Hydra_MP_Proxy: RC_RHS_Hydra_MP {};


class M_PGM_AT;
class RC_RHS_APKWS: M_PGM_AT
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoLasersensor_6km.hpp"

	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";

	/*
	//maybe modify to increase accuracy while not fully aligned
	maneuvrability=8;	//try 14 like DAGR M310 that uses same thrust?
	airFriction=0.1;
	sideAirFriction=0.16;
	initTime=0;
	*/

	missileKeepLockedCone=60;		//60
	missileLockCone=60;				//30
	missileLockMaxDistance=4100;	//5000
	missileLockMinDistance=300;		//100

	thrustTime=2.14;	//1.07 doubled to cancel thrust halving
	thrust=412.5;		//825 halved to increase accuracy
	
	indirectHit=40;			//40
	indirectHitRange=4.5;	//3.2
	fuseDistance=20;

	ace_rearm_caliber=70;
	displayName="APKWS 4km";
	displayNameShort="APKWS 4km";
	description="APKWS 4km LG";
	descriptionShort="APKWS 4km LG";
	maxSpeed=290;

	manualControl=0;
	laserLock=1;
	airlock=0;
	irLock=0;
};
/*
class RC_APKWS;
class RC_RHS_APKWS: RC_APKWS
{
	//model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_r_M229";
};
*/


/*
class ammo_Penetrator_PG_AT;
class RC_RHS_DAGR_M310_Penetrator: ammo_Penetrator_PG_AT
{
	caliber=20;
	hit=300;	//reduced as lockon already is very strong
};
*/
class RHS_Ammo_DAGR;
class RC_DAGR: RHS_Ammo_DAGR
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoDatalink_6km.hpp"
	//#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoLasersensor_6km.hpp"

	/*
	//maybe modify to increase accuracy while not fully aligned
	maneuvrability=8;
	airFriction=0.1;
	sideAirFriction=0.16;
	initTime=0;
	*/

	maxControlRange=4100;			//8000
	missileKeepLockedCone=60;		//25
	missileLockCone=60;				//25
	missileLockMaxDistance=4100;	//6000
	missileLockMinDistance=300;		//100

	thrustTime=3.14;	//1.57 doubled to cancel thrust halving
	thrust=412.5;		//825 halved to increase accuracy at shorter distance
	
	warheadName="HE";
	hit=95;
	indirectHit=40;
	indirectHitRange=4.5;
	fuseDistance=20;

	ace_rearm_caliber=250;
	displayName="DAGR 4km";
	displayNameShort="DAGR 4km";
	description="DAGR 4km";
	descriptionShort="DAGR 4km";
	//maxSpeed=290;	//720

	//added submun
	submunitionAmmo="ammo_Penetrator_PG_AT";	//RC_RHS_DAGR_M310_Penetrator
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
};
class RC_DAGR_Proxy: RC_DAGR
{
};


class RC_SRAM: RC_DAGR
{
	maneuvrability=80;	//8
	airFriction=0.1;	//maybe increase and increase thrust, for post thrusttime slowdown
	sideAirFriction=4;	//0.16
	trackLead=1;
	trackOversteer=1;

	triggerDistance=10;
	proximityExplosionDistance=10;
	fuseDistance=15;
	cameraViewAvailable=1;

	irLock=1;
	airLock=1;
	laserLock=1;

	maxControlRange=1100;
	missileKeepLockedCone=360;
	missileLockCone=180;
	missileLockMaxDistance=1100;
	missileLockMinDistance=20;
	missileLockMaxSpeed=200;

	thrustTime=2;	//adjust to match 1km
	thrust=400;		//825

	displayName="SRAM 1km";
	displayNameShort="SRAM 1km";
	description="SRAM 1km";
	descriptionShort="SRAM 1km";

	class Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=6000;
					class AirTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=180;
					angleRangeVertical=180;
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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=1000;
					maxTrackableSpeed=500;
					angleRangeHorizontal=180;
					angleRangeVertical=180;
					groundNoiseDistanceCoef=0.2;
					maxGroundNoiseDistance=50;
				};
				/*
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
					typeRecognitionDistance=1000;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=180;
					angleRangeVertical=180;
				};
				*/
			};
		};
	};
};


class M_Scalpel_AT;
class RC_AGM114K: M_Scalpel_AT
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoLasersensor_6km.hpp"
	
	displayName="AGM-114K";
	displayNameShort="AGM-114K";
	description="AGM-114K";
	descriptionShort="AGM-114K";

	model="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
	proxyShape="\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
	effectsMissile="rhs_missile2";

	ace_rearm_caliber=178;

	indirectHit=50;			//50
	indirectHitRange=4.5;	//4

	manualControl=0;
	laserLock=1;
	airLock=0;
	irLock=0;
	
	fuseDistance=50;
	timeToLive=40;
	maxSpeed=440;
	thrust=250;
	thrustTime=2.5;
};