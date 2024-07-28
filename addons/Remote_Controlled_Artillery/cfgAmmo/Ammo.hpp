class Default;
class RC_target_confirmer_ammo: Default
{
	author="Ascent";
	laserLock=1;
	irLock=1;
	airLock=1;
	nvLock=1;
};

//.338 NM Tracer for Vehicle MMG
class BulletBase;
class RC_B_338_T_R: BulletBase
{
	laserLock=1;
	irLock=1;
	airLock=1;
	hit=16;
	indirectHit=0;
	indirectHitRange=0;
	cartridge="FxCartridge_338_Ball";
	audibleFire=80;
	visibleFireTime=3;
	dangerRadiusBulletClose=10;
	dangerRadiusHit=14;
	suppressionRadiusBulletClose=8;
	suppressionRadiusHit=10;
	cost=6;
	caliber=2;
	typicalSpeed=890;
	timeToLive=10;
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
	tracerScale=1.2;
	tracerStartTime=0.05;
	tracerEndTime=4;
	airFriction=-0.00060999999;
	class CamShakeExplode
	{
		power=3.1622801;
		duration=0.60000002;
		frequency=20;
		distance=9.4868298;
	};
	class CamShakeHit
	{
		power=10;
		duration=0.40000001;
		frequency=20;
		distance=1;
	};
};
class RC_B_338_T_G: RC_B_338_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_B_338_T_Y: RC_B_338_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class RC_B_93x64_T_G: BulletBase
{
	laserLock=1;
	irLock=1;
	airLock=1;
	hit=18;
	indirectHit=0;
	indirectHitRange=0;
	cartridge="FxCartridge_93x64_Ball";
	audibleFire=80;
	visibleFireTime=3;
	dangerRadiusBulletClose=10;
	dangerRadiusHit=14;
	suppressionRadiusBulletClose=8;
	suppressionRadiusHit=10;
	cost=6;
	caliber=2.2;
	typicalSpeed=785;
	timeToLive=10;
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
	tracerScale=1.2;
	tracerStartTime=0.05;
	tracerEndTime=4;
	airFriction=-0.00075000001;
	class CamShakeExplode
	{
		power=3.1622801;
		duration=0.60000002;
		frequency=20;
		distance=9.4868298;
	};
	class CamShakeHit
	{
		power=10;
		duration=0.40000001;
		frequency=20;
		distance=1;
	};
};
class RC_B_93x64_T_R: RC_B_93x64_T_G
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_B_93x64_T_Y: RC_B_93x64_T_G
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class B_127x99_SLAP_Tracer_Red;
class RC_B_127x99_SLAP_T_R: B_127x99_SLAP_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_B_127x99_SLAP_T_G: RC_B_127x99_SLAP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_B_127x99_SLAP_T_Y: RC_B_127x99_SLAP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class G_40mm_HEDP;
class RC_G_40mm_HEDP: G_40mm_HEDP
{
	indirectHit=8;
	indirectHitRange=6;
	laserLock=1;
	irLock=1;
	airLock=1;
	
};


class B_20mm_Tracer_Red;
class RC_20mm_HE_T_R: B_20mm_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.05;
	tracerEndTime=4;
	indirectHitRange=2;
	deflecting=1;
};
class RC_20mm_HE_T_G: RC_20mm_HE_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_20mm_HE_T_Y: RC_20mm_HE_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class B_20mm_AP;
class RC_20mm_AP_T_R: B_20mm_AP
{
	hit=70;
	caliber=3.8;
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.05;
	tracerEndTime=4;
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_20mm_AP_T_G: RC_20mm_AP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_20mm_AP_T_Y: RC_20mm_AP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class RC_20mm_APFSDS_T_R: RC_20mm_AP_T_R
{
	hit=90;
	caliber=4.8;
	deflecting=15;
	airFriction=-9.9999997e-005;
	typicalSpeed=1320;
	cost=50;
	tracerStartTime=0.04;

	class HitEffects
	{
		hitMetal="ImpactMetalSabotSmall";
		hitMetalPlate="ImpactMetalSabotSmall";
		hitBuilding="ImpactConcreteSabotSmall";
		hitConcrete="ImpactConcreteSabotSmall";
		hitGroundSoft="ImpactEffectsGroundSabot";
		hitGroundHard="ImpactEffectsGroundSabot";
		Hit_Foliage_green="ImpactLeavesGreen";
		Hit_Foliage_Dead="ImpactLeavesDead";
		Hit_Foliage_Green_big="ImpactLeavesGreenBig";
		Hit_Foliage_Palm="ImpactLeavesPalm";
		Hit_Foliage_Pine="ImpactLeavesPine";
		hitFoliage="ImpactLeaves";
		hitGlass="ImpactGlass";
		hitGlassArmored="ImpactGlassThin";
		hitWood="ImpactWood";
		hitHay="ImpactHay";
		hitPlastic="ImpactPlastic";
		hitRubber="ImpactRubber";
		hitTyre="ImpactTyre";
		hitMan="ImpactEffectsBlood";
		hitWater="ImpactEffectsWater";
		default_mat="ImpactEffectsGroundSabot";
	};
};
class RC_20mm_APFSDS_T_G: RC_20mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_20mm_APFSDS_T_Y: RC_20mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


//MP
class B_30mm_MP_Tracer_Red;
class RC_B_30mm_MP_T_R: B_30mm_MP_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	indirectHit=6;
	indirectHitRange=4;
	deflecting=1;
};
class RC_B_30mm_MP_T_G: RC_B_30mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_B_30mm_MP_T_Y: RC_B_30mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};
class RC_B_40mm_MP_T_R: RC_B_30mm_MP_T_R
{
	hit=110;
	indirectHit=8;
	indirectHitRange=5;
	caliber=4.5999999;
};
class RC_B_40mm_MP_T_G: RC_B_40mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_B_40mm_MP_T_Y: RC_B_40mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


//GPR
class B_40mm_GPR_Tracer_Red;
class RC_B_40mm_GPR_T_R: B_40mm_GPR_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	indirectHit=8;
	indirectHitRange=5;
	caliber=4.5999999;
	deflecting=1;
};
class RC_B_40mm_GPR_T_G: RC_B_40mm_GPR_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_B_40mm_GPR_T_Y: RC_B_40mm_GPR_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};
class RC_B_30mm_GPR_T_R: RC_B_40mm_GPR_T_R
{
	hit=55;
	indirectHit=6;
	indirectHitRange=4;
	caliber=4.4000001;
};
class RC_B_30mm_GPR_T_G: RC_B_30mm_GPR_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_B_30mm_GPR_T_Y: RC_B_30mm_GPR_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class B_30mm_APFSDS_Tracer_Red;
class RC_B_30mm_APFSDS_T_R: B_30mm_APFSDS_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
};
class RC_B_30mm_APFSDS_T_G: RC_B_30mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_B_30mm_APFSDS_T_Y: RC_B_30mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class B_40mm_APFSDS_Tracer_Red;
class RC_B_40mm_APFSDS_T_R: B_40mm_APFSDS_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
};
class RC_B_40mm_APFSDS_T_G: RC_B_40mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_B_40mm_APFSDS_T_Y: RC_B_40mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


/*
class G_40mm_Smoke;
class RC_B_AC_Smoke: G_40mm_Smoke
{
	deflecting=0;
	explosionTime=0.5;
	timeToLive=120;
};
*/


//120mm of FSV/MBT
class ammo_Penetrator_120mm;
class RC_ammo_Penetrator_120mm: ammo_Penetrator_120mm
{
	warheadName="TandemHEAT";
};
class Sh_120mm_HEAT_MP_T_Red;
class RC_Sh_120mm_MP_T_R: Sh_120mm_HEAT_MP_T_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	aiAmmoUsageFlags="64 + 128 + 512";
	//warheadName="TandemHEAT";		//submunition is TandemHEAT
	warheadName="HE";
	submunitionAmmo="RC_ammo_Penetrator_120mm";
	hit=95;
	indirectHit=50;
	indirectHitRange=10;
	deflecting=4;
	craterEffects="AAMissileCrater";
};
class RC_Sh_120mm_MP_T_G: RC_Sh_120mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_Sh_120mm_MP_T_Y: RC_Sh_120mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};
class Sh_120mm_APFSDS_Tracer_Red;
class RC_Sh_120mm_APFSDS_T_R: Sh_120mm_APFSDS_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
};
class RC_Sh_120mm_APFSDS_T_G: RC_Sh_120mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_Sh_120mm_APFSDS_T_Y: RC_Sh_120mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class Sh_125mm_HEAT_T_Red;
class RC_Sh_125mm_MP_T_R: Sh_125mm_HEAT_T_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	aiAmmoUsageFlags="64 + 128 + 512";
	indirectHit=50;
	indirectHitRange=10;
	deflecting=4;
	craterEffects="AAMissileCrater";
};
class RC_Sh_125mm_MP_T_G: RC_Sh_125mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\shell_tracer_green";
};
class RC_Sh_125mm_MP_T_Y: RC_Sh_125mm_MP_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\shell_tracer_yellow";
};
class Sh_125mm_APFSDS_T_Red;
class RC_Sh_125mm_APFSDS_T_R: Sh_125mm_APFSDS_T_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
};
class RC_Sh_125mm_APFSDS_T_G: RC_Sh_125mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_Sh_125mm_APFSDS_T_Y: RC_Sh_125mm_APFSDS_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class ammo_Penetrator_Base;
class RC_ammo_Penetrator_MP: ammo_Penetrator_Base
{
	caliber=60;
	warheadName="TandemHEAT";
	hit=800;
};
class M_Titan_AT_long;
class M_Titan_AT_long_Base: M_Titan_AT_long
{
	class Components;
};
class RC_IFV_MP_NLOS: M_Titan_AT_long_Base
{
	submunitionAmmo="RC_ammo_Penetrator_MP";
	indirectHit=250;
	indirectHitRange=6;
	maxControlRange=4000;
	cmImmunity=0.85;	//higher to simulate topdown ignoring smokes around the vehicle
	missileLockCone=180;	//for NLOS Datalink targeting, being able to shoot missle straight up, over barriers being in the way
	missileLockMaxDistance=4000;
	fuseDistance=20;
	thrust=70;
	maxSpeed=250;
	maneuvrability=25;
	initTime=0.01;
	cameraViewAvailable=1;
	weaponLockSystem="2 + 4 + 16";
	laserLock=1;
	irLock=1;
	airLock=1;
	trackLead=1;
	craterEffects="AAMissileCrater";

	flightProfiles[]=
	{
		"Direct",
		"TopDown"
	};
	class TopDown
	{
		ascendHeight=300;	//200
		descendDistance=360;	//240
		minDistance=50;	//240
		ascendAngle=45;	//30
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
					angleRangeHorizontal=360;
					angleRangeVertical=360;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
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
					maxTrackableSpeed=120;
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					maxTrackableSpeed=120;
					typeRecognitionDistance=400;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
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


class M_Titan_AA_long;
class RC_IFV_AA_Base: M_Titan_AA_long
{
	class Components;
};
class RC_IFV_AA: RC_IFV_AA_Base
{
	indirectHitRange=15;
	weaponLockSystem="2 + 4 + 16";
	laserLock=1;
	irLock=1;
	airLock=1;
	trackLead=1;
	cameraViewAvailable=1;
	initTime=0.01;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=4500;
						maxRange=4500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=2250;
					maxTrackableSpeed=500;
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
					groundNoiseDistanceCoef=0.2;
					maxGroundNoiseDistance=50;
				};
				class LaserSensorComponent: SensorTemplateLaser
				{
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
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=400;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
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


class MissileBase;


//ATGM
class M_Vorona_HEAT;
class RC_M_ATGM_MP_SACLOS: M_Vorona_HEAT
{
	submunitionAmmo="RC_ammo_Penetrator_MP";
	indirectHit=40;
	indirectHitRange=10;
	maxControlRange=3000;
	trackOversteer=0.5;
	fuseDistance=20;
	cameraViewAvailable=1;
};


//ATGM
class RC_M_ATGM_MP_Lock: M_Titan_AT_long_Base
{
	submunitionAmmo="RC_ammo_Penetrator_MP";
	indirectHit=40;
	indirectHitRange=10;
	maxControlRange=3000;
	cmImmunity=0.85;
	missileLockCone=180;	//for NLOS Datalink targeting, being able to shoot missle straight up, over barriers being in the way
	missileLockMaxDistance=3000;
	fuseDistance=20;
	initTime=0.01;
	laserLock=0;
	weaponLockSystem="1 + 2 + 16";
	cameraViewAvailable=1;

	flightProfiles[]=
	{
		"TopDown",
		"Direct"
	};
	class Direct
	{
	};
	class TopDown
	{
		ascendHeight=300;	//200
		descendDistance=360;	//240
		minDistance=100;	//240
		ascendAngle=45;	//30
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				/*
				//autonomous engages lasers spots without differentiating
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


class M_120mm_cannon_ATGM_LG;
class RC_M_120mm_cannon_ATGM_DLG_Base: M_120mm_cannon_ATGM_LG
{
	class Components;
};
class RC_M_120mm_cannon_ATGM_DLG: RC_M_120mm_cannon_ATGM_DLG_Base
{
	/*
	//for later use, doesnt work yet
	proximityExplosionDistance=10;
	triggerDistance=10;
	submunitionDirectionType="SubmunitionTargetDirection";
	*/

	explosive=0.8;
	indirectHit=250;
	indirectHitRange=6;

	laserLock=1;
	irLock=1;
	airLock=1;
	trackLead=1;
	craterEffects="AAMissileCrater";
	weaponLockSystem="2 + 4 + 16";
	missileLockMaxDistance=4000;
	maneuvrability=4;
	flightProfiles[]=
	{
		"TopDown"
	};
	class TopDown
	{
		ascendHeight=300;	//250
		descendDistance=480;	//400
		minDistance=100;	//400
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
					maxTrackableSpeed=120;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
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
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
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
class RC_M_125mm_cannon_ATGM_DLG: RC_M_120mm_cannon_ATGM_DLG
{
	submunitionAmmo="ammo_Penetrator_125mm_missile";
};


/*
//for later use
class BombDemine_01_SubAmmo_F;
class RC_BombDemine_01_SubAmmo_F: BombDemine_01_SubAmmo_F
{
	simulation="shotShell";
	model="\a3\Weapons_F_Orange\Ammo\BombDemine_01_ground_F";
	hit=1;
	indirectHit=35;
	indirectHitRange=11;
	explosionTime=1;	//0.01?
	thrust=0;
	thrustTime=0;
	typicalSpeed=1;
	craterShape="\a3\Data_f_orange\data\krater_maly";
	effectsMissile="DeminingExplosiveTrials";
	explosionEffects="DeminingExplosiveExplosion";
	craterEffects="DeminingExplosiveCrater";
	SoundSetExplosion[]=
	{
		"UAV_6_DemineDrone_Bomb_Exp_SoundSet",
		"Shell30mm40mm_Tail_SoundSet",
		"Explosion_Debris_SoundSet",
		"UXO_Debris_Dust_Cloud_SoundSet"
	};
};
class BombDemine_01_Ammo_F;
class RC_BombDemine_01_Ammo_F: BombDemine_01_Ammo_F
{
	model="\a3\Weapons_F_Orange\Ammo\BombDemine_01_fly_F";
	proxyShape="\a3\Weapons_F_Orange\Ammo\BombDemine_01_F";
	simulation="shotMissile";
	effectsMissile="DeminingExplosiveTrials";
	explosionEffects="DeminingExplosiveExplosion";
	craterEffects="DeminingExplosiveCrater";
	thrustTime=10;
	cost=10;
	triggerDistance=1;	//2?
	triggerSpeedCoef[]={0.1,0.1};
	submunitionConeAngle=0;
	submunitionConeType[]=
	{
		"custom",
		
		{
			{0,0}
		}
	};
	submunitionAmmo="RC_BombDemine_01_SubAmmo_F";
	hit=1;
	indirectHit=35;
	indirectHitRange=11;
	craterShape="\a3\Data_f_orange\data\krater_maly";
	soundFly[]=
	{
		"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Whistle",
		1,
		1,
		100
	};
};
*/


//groundwork
class RC_HEAB_Base: Default
{
	submunitionCount=1;
	submunitionConeAngle=0;
	submunitionParentSpeedCoef=0;
	submunitionInitSpeed=0;
	submunitionDirectionType="SubmunitionModelDirection";
	artilleryLock=1;
	laserLock=1;	//only for firing solution calculator
	irLock=1;	//only for firing solution calculator
	timeToLive=180;
	
	//shell/submunition core
	simulation="shotSubmunitions";
	simulationStep=0.005;	//required to make airburst work before hitting ground
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
	craterEffects="ArtyShellCrater";
	CraterWaterEffects="ImpactEffectsWaterHE";
	explosionEffects="RC_MortarExplosion";
	visibleFire=64;
	audibleFire=250;
	muzzleEffect="";
	deflectionDirDistribution=0.38999999;
	penetrationDirDistribution=0.25999999;
	whistleOnFire=2;	//?
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
	whistleDist=153.9;	//unclear effect
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
	soundFly[]=
	{
		"a3\Sounds_F\weapons\falling_bomb\fall_01",
		3.1622777,	//likely priority
		1,	//likely playspeed
		153.9	//hearable distance, should me min m/s of the shell (lowest charge)
	};
};
class Sh_155mm_AMOS;
//alternative base to make soundmods like jsrs work, might create problems with other artillery mods that sicnificantly change 155mm HE shell values
//for now finetuned shell soundfly to create correct fall and passby sound instead
/*
class RC_HEAB_Shell_Base: Sh_155mm_AMOS
{
	simulation="shotSubmunitions";
	simulationStep=0.005;	//required to make airburst work before hitting ground
	submunitionCount=1;
	submunitionConeAngle=0;
	submunitionParentSpeedCoef=0;
	submunitionInitSpeed=0;
	artilleryLock=1;
	laserLock=1;	//only for firing solution calculator
	irLock=1;	//only for firing solution calculator
	craterEffects="RC_ArtyShellCrater";	//dust on ground effect like caused by airburst
	ExplosionEffects="RC_MortarExplosion";
};
*/
class RC_HEAB_Rocket_Base: RC_HEAB_Base
{
	warheadName="HE";
	explosive=0.80000001;
	caliber=34;
	airFriction=0;
	sideairFriction=0;
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	effectFly="Missile0";
	audibleFire=64;
	dangerRadiusHit=1250;
	suppressionRadiusHit=120;
	deflecting=0;
	thrust=0;
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

/*
//postponed
class ShellBase;
class RC_MP_Warhead_Base: ShellBase
{
	warheadName="HE";
	//submunitionDirectionType="SubmunitionModelDirection";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,9.8};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
	
	indirectHit=125;
	indirectHitRange=15;
	//typicalSpeed=1400;
	explosive=1;
	muzzleEffect="";
	
	explosionEffects="RC_GuidedExplosion";
	craterEffects="AAMissileCrater";
	explosionSoundEffect="DefaultExplosion";

	dangerRadiusHit=350;
	suppressionRadiusHit=37.5;
	//caliber=10;
	deflecting=0;
	model="";
	artilleryLock=1;
	thrust=0;
	timeToLive=1;
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

class RC_MP_Guided_Submunition_MissleBase: MissileBase
{
	class Components;
};
class RC_MP_LaserGuided_Submunition_Base: RC_MP_Guided_Submunition_MissleBase
{
	artilleryLock=0;	//1 would make submunition unable to hit vanilla firing computer gps point
	laserLock=1;
	autoSeekTarget=1;
	cameraViewAvailable=1;
	missileLockCone=180;
	missileKeepLockedCone=180;
	lockSeekRadius=900;
	missileLockMaxDistance=2000;
	missileLockMinDistance=1;	//maybe edit
	missileLockMaxSpeed=150;
	maxControlRange=1000;
	fuseDistance=20;
	timeToLive=10;
	model="\A3\Weapons_F_Tank\Ammo\Missile_ATGM_01_fly_F";
	explosive=1;
	aiAmmoUsageFlags="128 + 512";
	explosionSoundEffect="DefaultExplosion";
	explosionEffects="RC_GuidedExplosion";
	craterEffects="AAMissileCrater";
	effectsMissileInit="";
	muzzleEffect="";
	simulationStep=0.0020000001;
	trackOversteer=1;	//required to not completly miss
	trackLead=1;
	maneuvrability=20;	//required to not completly miss
	airFriction=0.085000001;
	sideAirFriction=0.1;
	whistleDist=60;
	lockType=0;
	submunitionDirectionType="SubmunitionModelDirection";	//later test SubmunitionTargetDirection, with triggerDistance=; and proximityExplosionDistance=;
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
	//warheadName="TandemHEAT";
	warheadName="HE";
	hit=165;	//submunition penetrator contains main hit value
	initTime=0.01;
	thrustTime=8;
	thrust=300;
	maxSpeed=300;
	typicalSpeed=300;
	weaponLockSystem="4 + 16";
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
					angleRangeHorizontal=90;
					angleRangeVertical=90;
				};
				/*
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
				*/
			};
		};
	};
};
class RC_MP_MultiGuided_Submunition_Base: RC_MP_LaserGuided_Submunition_Base
{
	laserLock=1;
	irLock=1;
	airLock=1;
	weaponLockSystem="2 + 4 + 16";

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class GroundTarget
					{
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=90;
					angleRangeVertical=90;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=1000;

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
					angleRangeHorizontal=90;
					angleRangeVertical=90;
				};
				/*
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=10;

					class AirTarget
					{
						minRange=10;
						maxRange=10;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=10;
						maxRange=10;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				*/
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

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
class RC_Sh_AMOS_MP_LaserGuided_Base: SubmunitionBase
{
	submunitionCount=1;
	submunitionConeAngle=0;
	submunitionDirectionType="SubmunitionTargetDirection";	//required to not completly miss
	submunitionParentSpeedCoef=0.1;	//required to not completly miss
	aiAmmoUsageFlags="128 + 512";
	timeToLive=180;
	laserLock=1;
	artilleryLock=1;
	autoSeekTarget=1;
	//simulation="shotMissile"; makes misslecam connect, but not for guided submunition, and likely creates other issues, testing still needed
	//cameraViewAvailable=1;	//should be submun only
	muzzleEffect="";
	airFriction=0;
	explosionEffects="RC_GuidedExplosion";
	craterEffects="AAMissileCrater";
	canLock=2;	//supposedly only cfgweapons not ammo
	
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
class RC_Sh_AMOS_MP_MultiGuided_Base: RC_Sh_AMOS_MP_LaserGuided_Base
{
	irLock=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;	//would allow for sensor-recon shots, to then datalink lock with second shot, doesnt work yet, maybe cfgvic only
};


//82mm
class Sh_82mm_AMOS;
/*
class RC_Sh_82mm_AMOS: Sh_82mm_AMOS
{
	laserLock=1;	//only for firing solution calculator
	irLock=1;	//only for firing solution calculator
	explosionEffects="RC_MortarExplosion";
}
*/
class RC_Sh_82mm_AMOS_submunition: Sh_82mm_AMOS
{
	explosionTime=0.0001;
	explosive=1;
	explosionEffects="RC_MortarExplosion";
	craterEffects="RC_82mmAirburstDust";
};
class RC_82mm_HEAB_Shell_Base: RC_HEAB_Shell_Base
{
	hit=165;
	indirectHit=52;
	indirectHitRange=18;
	cost=200;
	whistleDist=70;	//yet unclear
	soundFly[]=
	{
		"a3\Sounds_F\weapons\falling_bomb\fall_01",
		3.1622777,	//likely priority
		1,	//likely playspeed
		70	//hearable distance, should me min m/s of the shell (lowest charge)
	};
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
	aimAboveTarget[]={12.7,12.7,12.7};	//high airburst to ignore cover, triggers when descending and this height above ground
};
class RC_Sh_82mm_AMOS_lowHEAB: RC_Sh_82mm_AMOS_HEAB
{
	imAboveTarget[]={6,6,6};	//low airburst to atleast ignore microterrain, triggers when descending and this height above ground
};


//impact quick fuze
class RC_Sh_82mm_AMOS_HE_submunition: RC_Sh_82mm_AMOS_submunition
{
	craterEffects="ArtyShellCrater";
};
class RC_Sh_82mm_AMOS_HE: RC_82mm_HEAB_Shell_Base
{
	simulationStep=0.050000001;
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0.8,-0.4};
	submunitionAmmo="RC_Sh_82mm_AMOS_HE_submunition";
};
//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_82mm_AMOS_backupHEAB: RC_Sh_82mm_AMOS_HE
{
	submunitionInitialOffset[]={0,5,0};
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
	model="\A3\weapons_f\ammo\shell";
	submunitionAmmo="RC_SmokeShellArty";
	submunitionConeType[]=
	{
		"poissondisc",
		4
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


/*
//makes game close when going close to mine... removed until fixed
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
class RC_82mm_MP_LaserGuided_Submunition: RC_MP_LaserGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_82mm_MP";
	//craterEffects="RC_82mmGuidedDust";
	indirectHit=52;
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
class RC_Sh_82mm_AMOS_MP_LaserGuided: RC_Sh_AMOS_MP_LaserGuided_Base
{
	submunitionAmmo="RC_82mm_MP_LaserGuided_Submunition";
	triggerDistance=300;
	hit=165;
	indirectHit=104;
	indirectHitRange=6;
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


class RC_82mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_82mm_MP";
	//craterEffects="RC_82mmGuidedDust";
	indirectHit=104;
	indirectHitRange=6;
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
	triggerDistance=300;
	hit=165;
	indirectHit=104;
	indirectHitRange=6;
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
class RC_M_Mo_82mm_LG_DelayedFuse_Submunition: RC_82mm_MP_LaserGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_82mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_82mm_AMOS_LG_DelayedFuse: RC_Sh_82mm_AMOS_MP_LaserGuided
{
	submunitionAmmo="RC_M_Mo_82mm_LG_DelayedFuse_Submunition";
};


//105mm, yet to be introduced, no vehicle options yet
/*
class RC_Sh_105mm_AMOS: Sh_155mm_AMOS
{
	laserLock=1;	//only for firing solution calculator
	irLock=1;	//only for firing solution calculator
	indirectHit=75.6;
	indirectHitRange=21.7;
	cost=233;
	explosionEffects="RC_MortarExplosion";
}
*/
class RC_Sh_105mm_AMOS_submunition: Sh_155mm_AMOS	//could be given 16km HE-RA range
{
	indirectHit=75.6;
	indirectHitRange=21.7;
	cost=233;
	explosionTime=0.0001;
	explosive=1;
	explosionEffects="RC_MortarExplosion";
	craterEffects="RC_105mmAirburstDust";
};
class RC_105mm_HEAB_Shell_Base: RC_HEAB_Shell_Base
{
	hit=207.3;
	indirectHit=75.6;
	indirectHitRange=21.7;
	cost=233;
	whistleDist=120;	//yet unclear
	soundFly[]=
	{
		"a3\Sounds_F\weapons\falling_bomb\fall_01",
		3.1622777,	//likely priority
		1,	//likely playspeed
		120	//hearable distance, should me min m/s of the shell (lowest charge)
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
class RC_Sh_105mm_AMOS_HEAB: RC_105mm_HEAB_Shell_Base
{
	submunitionAmmo="RC_Sh_105mm_AMOS_submunition";
	aimAboveDefault=2;
	aimAboveTarget[]={15.3,15.3,15.3};	//high airburst to ignore cover, triggers when descending and this height above ground
};
class RC_Sh_105mm_AMOS_lowHEAB: RC_Sh_105mm_AMOS_HEAB
{
	aimAboveTarget[]={6,6,6};	//low airburst to atleast ignore microterrain, triggers when descending and this height above ground
};


//impact quick fuze
class RC_Sh_105mm_AMOS_HE_submunition: RC_Sh_105mm_AMOS_submunition
{
	craterEffects="ArtyShellCrater";
};
class RC_Sh_105mm_AMOS_HE: RC_105mm_HEAB_Shell_Base
{
	simulationStep=0.050000001;
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0.8,-0.4};
	submunitionAmmo="RC_Sh_105mm_AMOS_HE_submunition";
};
//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_105mm_AMOS_backupHEAB: RC_Sh_105mm_AMOS_HE
{
	submunitionInitialOffset[]={0,5,0};
	submunitionAmmo="RC_Sh_105mm_AMOS_submunition";
};


class ammo_Penetrator_105mm_MP: ammo_Penetrator_Base
{
	caliber=48.4;
	warheadName="TandemHEAT";
	hit=581.6;
};
class RC_105mm_MP_LaserGuided_Submunition: RC_MP_LaserGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_105mm_MP";
	//craterEffects="RC_105mmGuidedDust";
	indirectHit=151.2;
	indirectHitRange=7.2;
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
class RC_Sh_105mm_AMOS_MP_LaserGuided: RC_Sh_AMOS_MP_LaserGuided_Base
{
	submunitionAmmo="RC_105mm_MP_LaserGuided_Submunition";
	triggerDistance=500;
	hit=207.3;
	indirectHit=151.2;
	indirectHitRange=7.2;
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


class RC_105mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_105mm_MP";
	//craterEffects="RC_105mmGuidedDust";
	indirectHit=151.2;
	indirectHitRange=7.2;
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
	triggerDistance=500;
	hit=207.3;
	indirectHit=151.2;
	indirectHitRange=7.2;
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
class RC_M_Mo_105mm_LG_DelayedFuse_submunition: RC_105mm_MP_LaserGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_105mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_105mm_AMOS_LG_DelayedFuse: RC_Sh_105mm_AMOS_MP_LaserGuided
{
	submunitionAmmo="RC_M_Mo_105mm_LG_DelayedFuse_submunition";
};


class Cluster_155mm_AMOS;
class RC_Cluster_105mm_AMOS: Cluster_155mm_AMOS
{
	hit=207.3;
	indirectHit=75.6;
	indirectHitRange=21.7;
	aiAmmoUsageFlags="64 + 128";
	submunitionConeAngle=15.25;
	submunitionConeType[]=
	{
		"poissondisc",
		32
	};
};


class Mine_155mm_AMOS_range;
class RC_Mine_105mm_AMOS_range: Mine_155mm_AMOS_range
{
	aiAmmoUsageFlags=16;
	submunitionAmmo="RC_Mo_ClassicMineRange";
	submunitionConeAngle=8.74;
	submunitionConeType[]=
	{
		"custom", {{1,0} , {0.866,0.5},{0.5,0.866}, {0,1} , {-0.866,0.5},{-0.5,0.866} , {-1,0} , {-0.866,-0.5},{-0.5,-0.866} , {0,-1} , {0.866,-0.5},{0.5,-0.866}};
	};
};


class AT_Mine_155mm_AMOS_range;
class RC_AT_Mine_105mm_AMOS_range: AT_Mine_155mm_AMOS_range
{
	aiAmmoUsageFlags=16;
	submunitionConeAngle=8.74;
	submunitionConeType[]=
	{
		"custom", {{1,0} , {0.866,0.5},{0.5,0.866}, {0,1} , {-0.866,0.5},{-0.5,0.866} , {-1,0} , {-0.866,-0.5},{-0.5,-0.866} , {0,-1} , {0.866,-0.5},{0.5,-0.866}};
	};
};


class RC_Smoke_105mm_AMOS_White: Smoke_120mm_AMOS_White
{
	aiAmmoUsageFlags=4;
	submunitionAmmo="RC_SmokeShellArty";
	submunitionConeAngle=10;
	submunitionConeType[]=
	{
		"poissondisc",
		8
	};
};


//120mm
/*
class RC_Sh_120mm_AMOS: Sh_155mm_AMOS
{
	laserLock=1;	//only for firing solution calculator
	irLock=1;	//only for firing solution calculator
	indirectHit=86.4;
	indirectHitRange=24.8;
	cost=266;
	explosionEffects="RC_MortarExplosion";
}
*/
class RC_Sh_120mm_AMOS_submunition: Sh_155mm_AMOS
{
	indirectHit=86.4;
	indirectHitRange=24.8;
	cost=266;
	explosionTime=0.0001;
	explosive=1;
	explosionEffects="RC_MortarExplosion";
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
	aimAboveTarget[]={17.5,17.5,17.5};	//high airburst to ignore cover, triggers when descending and this height above ground
};
class RC_Sh_120mm_AMOS_lowHEAB: RC_Sh_120mm_AMOS_HEAB
{
	aimAboveTarget[]={6,6,6};	//low airburst to atleast ignore microterrain, triggers when descending and this height above ground
};


//impact quick fuze
class RC_Sh_120mm_AMOS_HE_submunition: RC_Sh_120mm_AMOS_submunition
{
	craterEffects="ArtyShellCrater";
};
class RC_Sh_120mm_AMOS_HE: RC_120mm_HEAB_Shell_Base
{
	simulationStep=0.050000001;
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0.8,-0.4};
	submunitionAmmo="RC_Sh_120mm_AMOS_HE_submunition";
};
//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_120mm_AMOS_backupHEAB: RC_Sh_120mm_AMOS_HE
{
	submunitionInitialOffset[]={0,5,0};
	submunitionAmmo="RC_Sh_120mm_AMOS_submunition";
};


class ammo_Penetrator_120mm_MP: ammo_Penetrator_Base
{
	caliber=55.4;
	warheadName="TandemHEAT";
	hit=664.6;
};
class RC_120mm_MP_LaserGuided_Submunition: RC_MP_LaserGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_120mm_MP";
	//craterEffects="RC_120mmGuidedDust";
	indirectHit=172.8;
	indirectHitRange=8.3;
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
class RC_Sh_120mm_AMOS_MP_LaserGuided: RC_Sh_AMOS_MP_LaserGuided_Base
{
	submunitionAmmo="RC_120mm_MP_LaserGuided_Submunition";
	triggerDistance=500;
	hit=236.7;
	indirectHit=172.8;
	indirectHitRange=8.3;
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


class RC_120mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_120mm_MP";
	//craterEffects="RC_120mmGuidedDust";
	indirectHit=172.8;
	indirectHitRange=8.3;
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
	indirectHit=172.8;
	indirectHitRange=8.3;
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
class RC_M_Mo_120mm_LG_DelayedFuse_submunition: RC_120mm_MP_LaserGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_120mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_120mm_AMOS_LG_DelayedFuse: RC_Sh_120mm_AMOS_MP_LaserGuided
{
	submunitionAmmo="RC_M_Mo_120mm_LG_DelayedFuse_submunition";
};


class RC_Cluster_120mm_AMOS: Cluster_155mm_AMOS
{
	hit=236.7;
	indirectHit=86.4;
	indirectHitRange=24.8;
	aiAmmoUsageFlags="64 + 128";
	submunitionConeAngle=16.6;
	submunitionConeType[]=
	{
		"poissondisc",
		38
	};
};


class RC_Mine_120mm_AMOS_range: RC_Mine_105mm_AMOS_range
{
	submunitionConeAngle=10.2;
	submunitionConeType[]=
	{
		"custom", {{1,0} , {0.901,0.4339},{0.6235,0.7818}, {0.2225,0.9749} , {-0.2225,0.9749},{-0.6235,0.7818},{-0.901,0.4339} , {-1,0} , {-0.901,-0.4339},{-0.6235,-0.7818},{-0.2225,-0.9749} , {0.2225,-0.9749},{0.6235,-0.7818},{0.901,-0.4339}};
	};
};


class RC_AT_Mine_120mm_AMOS_range: RC_AT_Mine_105mm_AMOS_range
{
	submunitionConeAngle=10.2;
	submunitionConeType[]=
	{
		"custom", {{1,0} , {0.901,0.4339},{0.6235,0.7818}, {0.2225,0.9749} , {-0.2225,0.9749},{-0.6235,0.7818},{-0.901,0.4339} , {-1,0} , {-0.901,-0.4339},{-0.6235,-0.7818},{-0.2225,-0.9749} , {0.2225,-0.9749},{0.6235,-0.7818},{0.901,-0.4339}};
	};
};


class RC_Smoke_120mm_AMOS_White: RC_Smoke_105mm_AMOS_White
{
	submunitionConeAngle=10;
	submunitionConeType[]=
	{
		"poissondisc",
		10
	};
};


//155mm
/*
class RC_Sh_155mm_AMOS: Sh_155mm_AMOS
{
	laserLock=1;	//only for firing solution calculator
	irLock=1;	//only for firing solution calculator
	explosionEffects="RC_MortarExplosion";
}
*/
class RC_Sh_155mm_AMOS_submunition: Sh_155mm_AMOS
{
	explosionTime=0.0001;
	explosive=1;
	explosionEffects="RC_MortarExplosion";
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
	aimAboveTarget[]={21.2,21.2,21.2};	//high airburst to ignore cover, triggers when descending and this height above ground
};
class RC_Sh_155mm_AMOS_lowHEAB: RC_Sh_155mm_AMOS_HEAB
{
	aimAboveTarget[]={6,6,6};	//low airburst to atleast ignore microterrain, triggers when descending and this height above ground
};

//impact quick fuze
class RC_Sh_155mm_AMOS_HE_submunition: RC_Sh_155mm_AMOS_submunition
{
	craterEffects="ArtyShellCrater";
};
class RC_Sh_155mm_AMOS_HE: RC_155mm_HEAB_Shell_Base
{
	simulationStep=0.050000001;
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0.8,-0.4};
	submunitionAmmo="RC_Sh_155mm_AMOS_HE_submunition";
};
//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_155mm_AMOS_backupHEAB: RC_Sh_155mm_AMOS_HE
{
	submunitionInitialOffset[]={0,5,0};
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
	aimAboveTarget[]={500,500,500};		//triggers when descending and at this height above ground
};


class RC_Mine_155mm_AMOS_range: RC_Mine_105mm_AMOS_range
{
	submunitionConeAngle=13.07;
	submunitionConeType[]=
	{
		"custom", {{1,0} , {0.9397,0.342},{0.766,0.6428},{0.5,0.866},{0.1736,0.9848} , {-0.9397,0.342},{-0.766,0.6428},{-0.5,0.866},{-0.1736,0.9848} , {-1,0} , {-0.9397,-0.342},{-0.766,-0.6428},{-0.5,-0.866},{-0.1736,-0.9848} , {0.9397,-0.342},{0.766,-0.6428},{0.5,-0.866},{0.1736,-0.9848}};
	};
};


class RC_AT_Mine_155mm_AMOS_range: RC_AT_Mine_105mm_AMOS_range
{
	submunitionConeAngle=13.07;
	submunitionConeType[]=
	{
		"custom", {{1,0} , {0.9397,0.342},{0.766,0.6428},{0.5,0.866},{0.1736,0.9848} , {-0.9397,0.342},{-0.766,0.6428},{-0.5,0.866},{-0.1736,0.9848} , {-1,0} , {-0.9397,-0.342},{-0.766,-0.6428},{-0.5,-0.866},{-0.1736,-0.9848} , {0.9397,-0.342},{0.766,-0.6428},{0.5,-0.866},{0.1736,-0.9848}};
	};
};


class RC_Smoke_155mm_AMOS_White: RC_Smoke_105mm_AMOS_White
{
	submunitionConeAngle=10;
	submunitionConeType[]=
	{
		"poissondisc",
		12
	};
};


class RC_Cluster_155mm_AMOS: Cluster_155mm_AMOS
{
	indirectHit=125;
	indirectHitRange=30;
	aiAmmoUsageFlags="64 + 128";
	submunitionConeAngle=19;
	submunitionConeType[]=
	{
		"poissondisc",
		50
	};
};


class ammo_Penetrator_155mm_MP: ammo_Penetrator_Base
{
	caliber=71.5;
	warheadName="TandemHEAT";
	hit=858.5;
};
class RC_155mm_MP_LaserGuided_Submunition: RC_MP_LaserGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_155mm_MP";
	//craterEffects="RC_155mmGuidedDust";
	indirectHit=250;
	indirectHitRange=10;
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
class RC_Sh_155mm_AMOS_MP_LaserGuided: RC_Sh_AMOS_MP_LaserGuided_Base
{
	submunitionAmmo="RC_155mm_MP_LaserGuided_Submunition";
	triggerDistance=500;
	hit=340;
	indirectHit=250;
	indirectHitRange=10;
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


class RC_155mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	submunitionAmmo="ammo_Penetrator_155mm_MP";
	//craterEffects="RC_155mmGuidedDust";
	indirectHit=250;
	indirectHitRange=10;
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
	triggerDistance=500;
	hit=340;
	indirectHit=250;
	indirectHitRange=10;
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
class RC_M_Mo_155mm_LG_DelayedFuse_submunition: RC_155mm_MP_LaserGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_155mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_155mm_AMOS_LG_DelayedFuse: RC_Sh_155mm_AMOS_MP_LaserGuided
{
	submunitionAmmo="RC_M_Mo_155mm_LG_DelayedFuse_submunition";
};


//230mm
class R_230mm_fly;
/*
class RC_R_230mm_fly: R_230mm_fly
{
	laserLock=1;	//only for firing solution calculator
	irLock=1;	//only for firing solution calculator
	cost=1000;
	explosionEffects="RC_MortarExplosion";
}
*/
class RC_R_230mm_fly_HEAB_submunition: R_230mm_fly
{
	explosionTime=0.0001;
	explosive=1;
	explosionEffects="RC_MortarExplosion";
	craterEffects="RC_230mmAirburstDust";
};
class RC_230mm_HEAB_Rocket_Base: RC_HEAB_Rocket_Base
{
	craterEffects="RC_230mmAirburstDust";
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
	aimAboveTarget[]={21.2,21.2,21.2};	//high airburst to ignore cover, triggers when descending and this height above ground
};
class RC_R_230mm_lowHEAB: RC_R_230mm_HEAB
{
	aimAboveTarget[]={6,6,6};	//to atleast ignore microterrain, triggers when descending and this height above ground
};

//impact quick fuze
class RC_R_230mm_fly_HE_submunition: RC_R_230mm_fly_HEAB_submunition
{
	craterEffects="ArtyShellCrater";
};
class RC_R_230mm_HE: RC_230mm_HEAB_Rocket_Base
{
	simulationStep=0.050000001;
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,1.75,-0.875};
	submunitionAmmo="RC_R_230mm_fly_HE_submunition";
};
//used in script as replacement when turret elevation is too low for Airburst
class RC_R_230mm_backupHEAB: RC_R_230mm_HE
{
	submunitionInitialOffset[]={0,5,0};
	submunitionAmmo="RC_R_230mm_fly_HEAB_submunition";
};


class R_230mm_Cluster;
class RC_R_230mm_Cluster: R_230mm_Cluster
{
	indirectHit=800;
	indirectHitRange=30;
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
class RC_230mm_MP_LaserGuided_Submunition: RC_MP_LaserGuided_Submunition_Base
{
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	effectFly="Missile0";
	explosionEffects="HEShellExplosion";
	craterEffects="BombCrater";
	submunitionAmmo="ammo_Penetrator_230mm_MP";
	indirectHit=800;
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
class RC_R_230mm_MP_LaserGuided: RC_Sh_AMOS_MP_LaserGuided_Base
{
	submunitionAmmo="RC_230mm_MP_LaserGuided_Submunition";
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	effectFly="Missile0";
	explosionEffects="HEShellExplosion";
	craterEffects="BombCrater";
	triggerDistance=500;
	hit=300;
	indirectHit=800;
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


class RC_230mm_MP_MultiGuided_Submunition: RC_MP_MultiGuided_Submunition_Base
{
	model="\A3\Weapons_F\Ammo\Rocket_230mm_F";
	effectFly="Missile0";
	//explosionEffects="HEShellExplosion";
	craterEffects="BombCrater";
	submunitionAmmo="ammo_Penetrator_230mm_MP";
	indirectHit=800;
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
	craterEffects="BombCrater";
	triggerDistance=500;
	hit=300;
	indirectHit=800;
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


class RC_R_230mm_fly_HEAB_delayed_submunition: RC_R_230mm_fly_HEAB_submunition
{
	explosionTime=0.2;
};
class RC_230mm_LG_DelayedFuse_submunition: RC_230mm_MP_LaserGuided_Submunition
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
class RC_230mm_LG_DelayedFuse: RC_R_230mm_MP_LaserGuided
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
	explosionEffects="RC_HeavyBombExplosion";
	soundSetExplosion[]=
	{
		"BombsHeavy_Exp_SoundSet",
		"BombsHeavy_Tail_SoundSet",
		"Explosion_Debris_SoundSet"
	};
}
class RC_R_604mm_ATACMS_HEAB: RC_604mm_HEAB_Rocket_Base
{
	submunitionAmmo="RC_R_604mm_fly_HEAB_submunition_ATACMS";
	aimAboveDefault=2;
	aimAboveTarget[]={30,30,30};	//high airburst to ignore cover, triggers when descending and this height above ground
};


//used in script as replacement when turret elevation is too low for Airburst
class RC_R_604mm_backupHEAB: RC_604mm_HEAB_Rocket_Base
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,5,0};
	submunitionAmmo="RC_R_604mm_fly_HEAB_submunition_ATACMS";
};


class RC_R_604mm_ATACMS_DPICM: R_230mm_Cluster
{
	indirectHit=3200;
	indirectHitRange=120;
	submunitionConeAngle=25;
	submunitionConeType[]=
	{
		"poissondisccenter",
		320
	};
};