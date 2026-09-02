//minigun
class RC_Pylon_B_338_SLAP_T_R: RC_B_338_SLAP_T_R
{
	indirectHit=1.4;		//1 - 1.2 for minigun 6.5 & 7.62
	indirectHitRange=2;		//2 for minigun 6.5 & 7.62
};
class RC_Pylon_B_338_SLAP_T_G: RC_Pylon_B_338_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Pylon_B_338_SLAP_T_Y: RC_Pylon_B_338_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_Pylon_B_338_SLAP_T_W: RC_Pylon_B_338_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};


class RC_Pylon_B_127x99_SLAP_T_R: RC_B_127x99_SLAP_T_R
{
	indirectHit=1.7;		//1 - 1.2 for minigun 6.5 & 7.62
	indirectHitRange=2;		//2 for minigun 6.5 & 7.62
};
class RC_Pylon_B_127x99_SLAP_T_G: RC_Pylon_B_127x99_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Pylon_B_127x99_SLAP_T_Y: RC_Pylon_B_127x99_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//autocannon (reduced smoke effect)
class RC_Pylon_ammo_Penetrator_MP_20mm: RC_ammo_Penetrator_MP_20mm
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\hitEffectsMP_AC.hpp"
};
class RC_Pylon_B_20mm_MP_QF_T_R: RC_B_20mm_MP_QF_T_R
{
	submunitionAmmo="RC_Pylon_ammo_Penetrator_MP_20mm";
	explosionEffects="RC_ExploAmmoExplosion_AC";
};
class RC_Pylon_B_20mm_MP_QF_T_G: RC_Pylon_B_20mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Pylon_B_20mm_MP_QF_T_Y: RC_Pylon_B_20mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_Pylon_ammo_Penetrator_MP_25mm: RC_ammo_Penetrator_MP_25mm
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\hitEffectsMP_AC.hpp"
};
class RC_Pylon_B_25mm_MP_QF_T_R: RC_B_25mm_MP_QF_T_R
{
	submunitionAmmo="RC_Pylon_ammo_Penetrator_MP_25mm";
	explosionEffects="RC_ExploAmmoExplosion_AC";
};
class RC_Pylon_B_25mm_MP_QF_T_G: RC_Pylon_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Pylon_B_25mm_MP_QF_T_Y: RC_Pylon_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_Pylon_ammo_Penetrator_MP_30mm: RC_ammo_Penetrator_MP_30mm
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\hitEffectsMP_AC.hpp"
};
class RC_Pylon_B_30mm_MP_QF_T_R: RC_B_30mm_MP_QF_T_R
{
	submunitionAmmo="RC_Pylon_ammo_Penetrator_MP_30mm";
	explosionEffects="RC_ExploAmmoExplosion_AC";
};
class RC_Pylon_B_30mm_MP_QF_T_G: RC_Pylon_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Pylon_B_30mm_MP_QF_T_Y: RC_Pylon_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//proxy fuse (per script not cfg)
class RC_Pylon_B_20mm_MP_QF_Proxy_T: RC_Pylon_B_20mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};
class RC_Pylon_B_25mm_MP_QF_Proxy_T: RC_Pylon_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};
class RC_Pylon_B_30mm_MP_QF_Proxy_T: RC_Pylon_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};


//unguided rockets
class M_AT;
class RC_Hydra_HE: M_AT
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoDatalink_6km.hpp"
	fuseDistance=20;	//50
	/*
	airLock=1;			//0
	irLock=1;			//0
	laserLock=1;		//0
	nvLock=0;			//0
	*/
};
class RC_Hydra_MP: RC_Hydra_HE
{
	submunitionAmmo="ammo_Penetrator_PG_AT";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;

	hit=95;
	indirectHit=40;
	indirectHitRange=8;
};
class RC_Hydra_MP_Proxy: RC_Hydra_MP {};


//light guided
class M_PGM_AT;
class RC_APKWS: M_PGM_AT
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoLasersensor_6km.hpp"

	/*
	//maybe modify to increase accuracy while not fully aligned
	maneuvrability=8;
	airFriction=0.1;
	sideAirFriction=0.16;
	initTime=0;
	*/

	cameraViewAvailable=1;
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

	/*
	//C-UAS capability, doesnt work atm
	triggerDistance=12;
	proximityExplosionDistance=12;
	*/
};
class RC_APKWS_Proxy: RC_APKWS
{
	displayName="APKWS-PF 4km";
	displayNameShort="APKWS-PF 4km";
	description="APKWS-PF 4km LG";
	descriptionShort="APKWS-PF 4km LG";

	indirectHitRange=8;	//3.2, 5
};


//DAGR SACLOS / lock
class M_PG_AT;
class M_PG_AT_Fetch: M_PG_AT
{
	class EventHandlers;
};
class RC_DAGR: M_PG_AT_Fetch
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

	cameraViewAvailable=1;
	missileKeepLockedCone=60;		//60
	missileLockCone=60;				//30
	missileLockMaxDistance=4100;	//6000
	missileLockMinDistance=300;		//1000

	thrustTime=2.14;	//1.07 doubled to cancel thrust halving
	thrust=412.5;		//825 halved to increase accuracy
	
	warheadName="HE";
	hit=95;
	indirectHit=40;
	indirectHitRange=4.5;
	fuseDistance=20;

	ace_rearm_caliber=70;
	displayName="DAGR 4km";
	displayNameShort="DAGR 4km";
	description="DAGR 4km";
	descriptionShort="DAGR 4km";
	maxSpeed=290;

	manualControl=1;
	laserLock=1
	airLock=1;
	irLock=1;

	submunitionAmmo="ammo_Penetrator_PG_AT";	//RC_RHS_DAGR_M310_Penetrator
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;

	/*
	//C-UAS capability, doesnt work atm
	triggerDistance=12;
	proximityExplosionDistance=12;
	*/
};
class RC_DAGR_Proxy: RC_DAGR
{
};


class RC_SRAM: RC_DAGR
{
	class EventHandlers: EventHandlers
	{
		class SRAM
		{
			fired = "params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];  if (!(local _projectile)) exitwith {};  [_unit, _projectile] call RC_fnc_RC_SRAM;";
		};
	};

	maneuvrability=60;	//8
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

	indirectHit=60;
	indirectHitRange=6;	//4.5

	maxControlRange=1100;
	missileKeepLockedCone=360;
	missileLockCone=180;
	missileLockMaxDistance=1100;
	missileLockMinDistance=20;
	missileLockMaxSpeed=200;

	thrustTime=4;	//adjust to match 1km
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
class RC_SRAM_Vanilla: RC_SRAM
{
};


//heavy guided
class M_Scalpel_AT;
class RC_AGM114K: M_Scalpel_AT
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoLasersensor_6km.hpp"

	displayName="AGM-114K";
	displayNameShort="AGM-114K";
	description="AGM-114K";
	descriptionShort="AGM-114K";

	model="\A3\Weapons_F\Ammo\Missile_AT_03_fly_F";
	proxyShape="\A3\Weapons_F\Ammo\Missile_AT_03_F";
	effectsMissile="missile2";

	ace_rearm_caliber=178;
	cameraViewAvailable=1;

	indirectHit=50;			//50
	indirectHitRange=4.5;	//4

	manualControl=0;
	laserLock=1
	airLock=0;
	irLock=0;
	
	fuseDistance=50;
	timeToLive=40;
	maxSpeed=440;
	thrust=250;
	thrustTime=2.5;
};
class RC_AGM114K_Proxy: RC_AGM114K
{
	displayName="AGM-114K-PF";
	displayNameShort="AGM-114K-PF";
	description="AGM-114K-PF";
	descriptionShort="AGM-114K-PF";

	indirectHitRange=8;	//4
};


/*
class R_80mm_HE;
class RC_S5_HE: R_80mm_HE
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoDatalink_6km.hpp"
	fuseDistance=20;//50

	//airLock=1;		//0
	//irLock=1;		//0
	//laserLock=1;	//0
	//nvLock=0;		//0
};
class RC_S5_MP: RC_S5_HE
{
	submunitionAmmo="ammo_Penetrator_PG_AT";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;

	hit=95;
	indirectHit=40;		//60
	indirectHitRange=8;	//15
};
*/