//APS
class Default
{
	class EventHandlers;
};
class MissileCore: Default {};
class MissileBase: MissileCore
{
	class EventHandlers: EventHandlers
	{
		class AT_Warning
		{
			fired = "params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];  if (!isServer) exitwith {};  [_unit, _projectile, _magazine] call RC_fnc_RC_AT_Warning;";
			//fired = "params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner']; [_unit, _projectile] spawn RC_fnc_RC_AT_Warning";
			//fired = "params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];  [_unit, _projectile] remoteExecCall ['RC_fnc_RC_AT_Warning', 2];";
			//fired = "systemchat 'missile'";
		};
	};
};
class RocketCore: Default {};
class RocketBase: RocketCore
{
	class EventHandlers: EventHandlers
	{
		class AT_Warning
		{
			fired = "params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];  if (!isServer) exitwith {};  [_unit, _projectile, _magazine] call RC_fnc_RC_AT_Warning;";
			//fired = "params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];  if (!(local _projectile)) exitwith {};  [_unit, _projectile] call RC_fnc_RC_AT_Warning;";
			//fired = "params ['_unit', '_weapon', '_muzzle', '_mode', '_ammo', '_magazine', '_projectile', '_gunner'];  if (!(local _projectile)) exitwith {};  [_unit, _projectile] remoteExecCall ['RC_fnc_RC_AT_Warning', 2];";
			//fired = "systemchat 'rocket'";
		};
	};
};


//class Default;
class RC_target_confirmer_ammo: Default
{
	author="Ascent";
	laserLock=1;
	irLock=1;
	airLock=1;
	nvLock=1;
};
class RC_APS_A: RC_target_confirmer_ammo
{
	//??
};
class ClaymoreDirectionalMine_Remote_Ammo_Scripted;
class RC_APS_Expl_Scripted: ClaymoreDirectionalMine_Remote_Ammo_Scripted
{
	author="Ascent";
	indirectHit=20;			//10	//default 40
	indirectHitRange=15;	//5		//default 30
	explosionAngle=200;				//default 60, 180 seems insufficient to damage source, but 360 endangers friendlies, but doesnt seem to actually work at all
};


class BulletBase;
class RC_FPV_Deployer_Ammo: BulletBase
{
	muzzleEffect="BIS_fnc_effectFiredSmokeLauncher";
	effectsSmoke="EmptyEffect";
	weaponLockSystem="1 + 2 + 4";
	hit=1;
	indirectHit=0;
	indirectHitRange=0;
	timeToLive=10;
	thrustTime=10;
	airFriction=-0.1;
	simulation="shotCM";
	model="\A3\weapons_f\empty";
	maxControlRange=50;
	initTime=2;
	aiAmmoUsageFlags="4 + 8";
};


/*
class FPV_AB_Trigger: Default
{
	model="\A3\weapons_f\launchers\RPG32\tbg32v_rocket.p3d";
	simulation="shotMissile";
	simulationStep=0.050000001;
	timeToLive=1;

	hit=0;
	indirectHit=0;
	indirectHitRange=0;

	lockType=0;
	laserLock=1;
	irLock=1;
	airLock=1;
	nvLock=1;

	missileLockCone=360;
	missileKeepLockedCone=360;
	missileLockMaxDistance=4000;
	missileLockMinDistance=1;
	missileLockMaxSpeed=150;
	cmImmunity=1;
	manualControl=1;
	missileManualControlCone=180;
	maxControlRange=4000;

	initTime=1;
	thrustTime=1;
	thrust=1;
	maneuvrability=1;
	trackOversteer=1;
	trackLead=1;
	airFriction=1;
	sideAirFriction=1;
	maxSpeed=1;
	typicalSpeed=1;
	fuseDistance=1;
	deflecting=1;
	cost=1;

	visibleFire=1;
	audibleFire=1;
	visibleFireTime=1;

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
				//autonomous engages lasers spots without differentiating
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
					angleRangeHorizontal=180;
					angleRangeVertical=180;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=600;
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
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=90;
					angleRangeVertical=90;
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
*/


/*
class Laserbeam;
class RC_Laserbeam: Laserbeam
{
	author="Ascent";
	laserLock=1;
	irLock=1;
	airLock=1;
	nvLock=1;
};
*/


//MMG
class B_762x51_Tracer_Red;
class RC_B_762x51_T_R: B_762x51_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	typicalSpeed=860;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_B_762x51_T_G: RC_B_762x51_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_762x51_T_Y: RC_B_762x51_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class B_338_NM_Ball;
class RC_B_338_T_R: B_338_NM_Ball
{
	laserLock=1;
	irLock=1;
	airLock=1;
	hit=16;
	typicalSpeed=890;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_B_338_T_G: RC_B_338_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_338_T_Y: RC_B_338_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class B_93x64_Ball;
class RC_B_93x64_T_G: B_93x64_Ball
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_B_93x64_T_R: RC_B_93x64_T_G {model="\A3\Weapons_f\Data\bullettracer\tracer_red";};
class RC_B_93x64_T_Y: RC_B_93x64_T_G {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//HMG
class B_127x99_Ball_Tracer_Red;
class RC_B_127x99_T_R: B_127x99_Ball_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_B_127x99_T_G: RC_B_127x99_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_127x99_T_Y: RC_B_127x99_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class B_127x99_SLAP_Tracer_Red;
class RC_B_127x99_SLAP_T_R: B_127x99_SLAP_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_B_127x99_SLAP_T_G: RC_B_127x99_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_127x99_SLAP_T_Y: RC_B_127x99_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_B_127x99_SLAP_HMG_T_R: B_127x99_SLAP_Tracer_Red
{
	laserLock=0;
	irLock=0;
	airLock=0;
	tracerStartTime=0.04;
	tracerEndTime=4;
};
class RC_B_127x99_SLAP_HMG_T_G: RC_B_127x99_SLAP_HMG_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_127x99_SLAP_HMG_T_Y: RC_B_127x99_SLAP_HMG_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//GMG
class G_40mm_HEDP;
class RC_G_40mm_HEDP: G_40mm_HEDP
{
	indirectHit=8;
	indirectHitRange=6;
	laserLock=1;
	irLock=1;
	airLock=1;
};


//Autocannon
class B_20mm_Tracer_Red;
class RC_20mm_HE_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
};
class RC_20mm_HE_T_G: RC_20mm_HE_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_20mm_HE_T_Y: RC_20mm_HE_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class B_20mm_AP;
class RC_20mm_AP_T_R: B_20mm_AP
{
	hit=70;
	caliber=3.8;
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=5;
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
	airFriction=-0.00042;
	timeToLive=12;
};
class RC_20mm_AP_T_G: RC_20mm_AP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_20mm_AP_T_Y: RC_20mm_AP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_20mm_APFSDS_T_R: RC_20mm_AP_T_R
{
	hit=90;
	caliber=4.8;
	deflecting=15;
	airFriction=-9.9999997e-005;
	typicalSpeed=1320;
	cost=50;

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
class RC_20mm_APFSDS_T_G: RC_20mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_20mm_APFSDS_T_Y: RC_20mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_20mm_mounted_APFSDS_T_R: RC_20mm_APFSDS_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_20mm_mounted_APFSDS_T_G: RC_20mm_mounted_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_20mm_mounted_APFSDS_T_Y: RC_20mm_mounted_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_20mm_mounted_APFSDS_T_W: RC_20mm_mounted_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};


//MP
class B_30mm_MP_Tracer_Red;
class B_30mm_HE_Tracer_Red;
class RC_B_30mm_MP_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
};
class RC_B_30mm_MP_T_G: RC_B_30mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_MP_T_Y: RC_B_30mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_40mm_MP_T_R: RC_B_30mm_MP_T_R
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	hit=110;
	caliber=4.5999999;
};
class RC_B_40mm_MP_T_G: RC_B_40mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_MP_T_Y: RC_B_40mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//GPR, differences:  MP explosive=0.6 sim=HEAT  vs  HE explosive=0.8 sim=HE  vs  GPR explosive=0.8 sim=AP,  as 0.7 is magic line of penetrating soft cover or detonating on cover
class B_40mm_GPR_Tracer_Red;
class RC_B_40mm_GPR_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	caliber=4.5999999;
};
class RC_B_40mm_GPR_T_G: RC_B_40mm_GPR_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_GPR_T_Y: RC_B_40mm_GPR_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_30mm_GPR_T_R: RC_B_40mm_GPR_T_R
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	hit=55;
	caliber=4.4000001;
};
class RC_B_30mm_GPR_T_G: RC_B_30mm_GPR_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_GPR_T_Y: RC_B_30mm_GPR_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class B_30mm_APFSDS_Tracer_Red;
class RC_B_30mm_APFSDS_T_R: B_30mm_APFSDS_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=4;
};
class RC_B_30mm_APFSDS_T_G: RC_B_30mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_APFSDS_T_Y: RC_B_30mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class B_40mm_APFSDS_Tracer_Red;
class RC_B_40mm_APFSDS_T_R: B_40mm_APFSDS_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=4;
};
class RC_B_40mm_APFSDS_T_G: RC_B_40mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_APFSDS_T_Y: RC_B_40mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


/*
class G_40mm_Smoke;
class RC_B_AC_Smoke: G_40mm_Smoke
{
	deflecting=0;
	explosionTime=0.5;
	timeToLive=120;
};
*/


/*
class BulletBase;
class B_30mm_MP_Core: BulletBase
{
	ace_vehicle_damage_incendiary=1;

	//B_19mm_HE
	explosionSoundEffect="DefaultExplosion";
	explosionEffects="ExploAmmoExplosion";
	craterEffects="ExploAmmoCrater";
	//model="\A3\Weapons_f\Data\bullettracer\tracer_white";

	//B_30mm_HE
	weaponType="cannon";
	visibleFire=32;
	audibleFire=200;
	visibleFireTime=3;
	cost=20;
	fuseDistance=3;
	airlock=1;
	aiAmmoUsageFlags="64 + 128 + 512";
	tracerScale=2.5;
	tracerStartTime=0.1;
	tracerEndTime=4.6999998;

	//B_30mm_MP
	hit=90;
	//indirectHit=4;
	//indirectHitRange=2;
	warheadName="HEAT";
	caliber=4.4000001;
	//deflecting=10;
	explosive=0.60000002;
	//typicalSpeed=1070;
	airFriction=-0.00036000001;
	dangerRadiusBulletClose=16;
	dangerRadiusHit=40;
	suppressionRadiusBulletClose=10;
	suppressionRadiusHit=14;

	//ShellCore
	//simulation="shotShell";
	simulationStep=0.050000001;
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

	//ammo_Penetrator_Base
	model="\A3\weapons_f\empty";
	indirectHit=0;
	indirectHitRange=0;
	//explosive=0;
	typicalSpeed=1000;	//1070
	timeToLive=0.2;
	deflecting=0;
	//deflectionDirDistribution=0;
	//penetrationDirDistribution=0;

	class HitEffects
	{
		Hit_Foliage_green="ImpactLeavesGreen";
		Hit_Foliage_Dead="ImpactLeavesDead";
		Hit_Foliage_Green_big="ImpactLeavesGreenBig";
		Hit_Foliage_Palm="ImpactLeavesPalm";
		Hit_Foliage_Pine="ImpactLeavesPine";
		hitFoliage="ImpactLeaves";
		hitGlass="ImpactMetalSabotSmall";
		hitGlassArmored="ImpactMetalSabotSmall";
		hitWood="ImpactMetalSabotSmall";
		hitHay="ImpactMetalSabotSmall";
		hitMetal="ImpactMetalSabotSmall";
		hitMetalPlate="ImpactMetalSabotSmall";
		hitBuilding="ImpactMetalSabotSmall";
		hitPlastic="ImpactMetalSabotSmall";
		hitRubber="ImpactMetalSabotSmall";
		hitTyre="ImpactMetalSabotSmall";
		hitConcrete="ImpactMetalSabotSmall";
		hitMan="ImpactMetalSabotSmall";
		hitGroundSoft="ImpactMetalSabotSmall";
		hitGroundRed="ImpactMetalSabotSmall";
		hitGroundHard="ImpactMetalSabotSmall";
		hitWater="ImpactEffectsWater";
		default_mat="ImpactMetalSabotSmall";
	};
	whistleOnFire=1;
	whistleDist=14;
};
*/


//MP Penetrator Submunitions
class ammo_Penetrator_Base;
/*
class RC_ammo_Penetrator_MPAB: ammo_Penetrator_Base
{
	explosive=0.60000002;	//expl 0 (purely kinetic) results in nearly no damage for small calibers for unknown reason

	airFriction=0;	//0 for it to still work with given airburst distance
	timeToLive=0.2;
	warheadName="HEAT";
	craterEffects="ExploAmmoCrater";	//no matter which, produces false craters
	explosionEffects="ExploAmmoExplosion";
	explosionSoundEffect="DefaultExplosion";
};
*/
class RC_ammo_Penetrator_MPAB: ammo_Penetrator_Base
{
	explosive=0;
	airFriction=0;	//0 for it to still work with given airburst distance
	timeToLive=0.2;
	warheadName="HEAT";
	CraterEffects="NoCrater";	//test both seperate
	explosionEffects="NoExplosion";
	dangerRadiusHit=40;
	suppressionRadiusHit=14;
};
class RC_ammo_Penetrator_MP_20mm: RC_ammo_Penetrator_MPAB
{
	hit=80;
	caliber=4.4;
};
class RC_ammo_Penetrator_MP_30mm: RC_ammo_Penetrator_MPAB
{
	hit=100;
	caliber=4.6;
};
class RC_ammo_Penetrator_MP_30mm_X: RC_ammo_Penetrator_MPAB
{
	hit=130;
	caliber=4.9;
};
class RC_ammo_Penetrator_MP_35mm: RC_ammo_Penetrator_MPAB
{
	hit=110;
	caliber=4.7;
};
class RC_ammo_Penetrator_MP_40mm: RC_ammo_Penetrator_MPAB
{
	hit=120;
	caliber=4.8;
};
class RC_ammo_Penetrator_MP_50mm: RC_ammo_Penetrator_MPAB
{
	hit=140;
	caliber=5;
};
class RC_ammo_Penetrator_MP_120mm: RC_ammo_Penetrator_MPAB
{
	hit=780;
	caliber=60;
	warheadName="TandemHEAT";
};
class RC_ammo_Penetrator_MP_125mm: RC_ammo_Penetrator_MPAB
{
	hit=780;
	caliber=60;
	warheadName="TandemHEAT";
};


//add penetrator to 40mm indirect!


//20mm MP Pen/DF/QF
class RC_B_20mm_MP_Pen_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_Pen.hpp"
	//submunitionAmmo="RC_ammo_Penetrator_MP_20mm";
};
class RC_B_20mm_MP_Pen_T_G: RC_B_20mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_MP_Pen_T_Y: RC_B_20mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_20mm_MP_DF_Sub: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_20mm";
	caliber=4.2;
};
class RC_B_20mm_MP_DF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_B_20mm_MP_DF_Sub";
};
class RC_B_20mm_MP_DF_T_G: RC_B_20mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_MP_DF_T_Y: RC_B_20mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_20mm_MP_QF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_20mm";
};
class RC_B_20mm_MP_QF_T_G: RC_B_20mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_MP_QF_T_Y: RC_B_20mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//20mm MPAB DF/QF
class RC_B_20mm_MPAB_DF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_B_20mm_MP_DF_Sub";
};
class RC_B_20mm_MPAB_DF_T_G: RC_B_20mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_MPAB_DF_T_Y: RC_B_20mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_20mm_MPAB_QF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_20mm";
};
class RC_B_20mm_MPAB_QF_T_G: RC_B_20mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_MPAB_QF_T_Y: RC_B_20mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//20mm HE Pen/DF/QF
class RC_B_20mm_HE_Pen_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_Pen.hpp"
};
class RC_B_20mm_HE_Pen_T_G: RC_B_20mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_HE_Pen_T_Y: RC_B_20mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_20mm_HE_DF_Sub: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_HE_DF.hpp"
};
class RC_B_20mm_HE_DF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_DF.hpp"
	submunitionAmmo="RC_B_20mm_HE_DF_Sub";
};
class RC_B_20mm_HE_DF_T_G: RC_B_20mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_HE_DF_T_Y: RC_B_20mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_20mm_HE_QF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_QF.hpp"
};
class RC_B_20mm_HE_QF_T_G: RC_B_20mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_HE_QF_T_Y: RC_B_20mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//20mm HEAB DF/QF
class RC_B_20mm_HEAB_DF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_DF.hpp"
	submunitionAmmo="RC_B_20mm_HE_DF_Sub";
};
class RC_B_20mm_HEAB_DF_T_G: RC_B_20mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_HEAB_DF_T_Y: RC_B_20mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_20mm_HEAB_QF_T_R: B_20mm_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_QF.hpp"
};
class RC_B_20mm_HEAB_QF_T_G: RC_B_20mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_HEAB_QF_T_Y: RC_B_20mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class B_35mm_AA;
class B_20mm_cUAS_Base: B_35mm_AA
{
	caliber=3.4000001;	//2.8 for 35mm
	hit=60;
	indirectHit=6;
	indirectHitRange=1.6;
	weaponType="cannon";	//not in 35mm
	warheadName="HE";
	explosive=0.40000001;	//0.6 for 35mm
	visibleFire=32;
	audibleFire=200;
	visibleFireTime=4;
	dangerRadiusBulletClose=16;
	dangerRadiusHit=40;
	suppressionRadiusBulletClose=10;
	suppressionRadiusHit=14;
	deflecting=0;
	airLock=1;
	aiAmmoUsageFlags="64 + 128 + 256";
	cost=30;	//42 for 35mm
	CraterEffects="ExploAmmoCrater";
	explosionEffects="ExploAmmoExplosion";
	explosionSoundEffect="DefaultExplosion";
	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
	tracerScale=1;
	tracerStartTime=0.050000001;
	nvgOnly=0;	//not in 35mm
	tracerEndTime=2;
	airFriction=-0.00078;
	muzzleEffect="";
	typicalSpeed=1030;
	soundHit1[]=
	{
		"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_01",
		1.7782794,
		1,
		1300
	};
	soundHit2[]=
	{
		"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_02",
		1.7782794,
		1,
		1300
	};
	soundHit3[]=
	{
		"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_03",
		1.7782794,
		1,
		1300
	};
	soundHit4[]=
	{
		"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_04",
		1.7782794,
		1,
		1300
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
		power=4;
		duration=0.80000001;
		frequency=20;
		distance=43.7771;
	};
	class CamShakeHit
	{
		power=20;
		duration=0.40000001;
		frequency=20;
		distance=1;
	};
	class CamShakeFire
	{
		power=2.1147399;
		duration=0.80000001;
		frequency=20;
		distance=35.7771;
	};
	class CamShakePlayerFire
	{
		power=0.0099999998;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};


//20mm HEAB C-UAS
class RC_B_20mm_HE_DF_cUAS_Sub: B_20mm_cUAS_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_HE_DF.hpp"
};
class RC_B_20mm_HEAB_cUAS_T_R: B_20mm_cUAS_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults_cUAS.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_20mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_DF.hpp"
	submunitionAmmo="RC_B_20mm_HE_DF_Sub";
};
class RC_B_20mm_HEAB_cUAS_T_G: RC_B_20mm_HEAB_cUAS_T_R {fuseDistance=12; model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_HEAB_cUAS_T_Y: RC_B_20mm_HEAB_cUAS_T_R {fuseDistance=12; model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_B_20mm_mounted_HE_DF_Sub: RC_B_20mm_HE_DF_cUAS_Sub
{
	explosionTime=0.028;
	airlock=1;
};
class RC_B_20mm_mounted_HEAB_T_R: RC_B_20mm_HEAB_cUAS_T_R
{
	triggerDistance=20;
	submunitionAmmo="RC_B_20mm_mounted_HE_DF_Sub";
	airlock=1;
};
class RC_B_20mm_mounted_HEAB_T_G: RC_B_20mm_mounted_HEAB_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_20mm_mounted_HEAB_T_Y: RC_B_20mm_mounted_HEAB_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_20mm_mounted_HEAB_T_W: RC_B_20mm_mounted_HEAB_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};


//25mm
class RC_B_25mm_APFSDS_T_R: RC_B_30mm_APFSDS_T_R
{
	hit=105;
	caliber=5.4;
};
class RC_B_25mm_APFSDS_T_G: RC_B_25mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_APFSDS_T_Y: RC_B_25mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//25mm MP Pen/DF/QF
class RC_B_25mm_MP_Pen_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_Pen.hpp"
	//submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
};
class RC_B_25mm_MP_Pen_T_G: RC_B_25mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_MP_Pen_T_Y: RC_B_25mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_25mm_MP_DF_Sub: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
	caliber=4.4;
};
class RC_B_25mm_MP_DF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_B_25mm_MP_DF_Sub";
};
class RC_B_25mm_MP_DF_T_G: RC_B_25mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_MP_DF_T_Y: RC_B_25mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_25mm_MP_QF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
};
class RC_B_25mm_MP_QF_T_G: RC_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_MP_QF_T_Y: RC_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//25mm MPAB DF/QF
class RC_B_25mm_MPAB_DF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_B_25mm_MP_DF_Sub";
};
class RC_B_25mm_MPAB_DF_T_G: RC_B_25mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_MPAB_DF_T_Y: RC_B_25mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_25mm_MPAB_QF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_25mm";
};
class RC_B_25mm_MPAB_QF_T_G: RC_B_25mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_MPAB_QF_T_Y: RC_B_25mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//25mm HE Pen/DF/QF
class RC_B_25mm_HE_Pen_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_Pen.hpp"
};
class RC_B_25mm_HE_Pen_T_G: RC_B_25mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_HE_Pen_T_Y: RC_B_25mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_25mm_HE_DF_Sub: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_HE_DF.hpp"
};
class RC_B_25mm_HE_DF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_DF.hpp"
	submunitionAmmo="RC_B_25mm_HE_DF_Sub";
};
class RC_B_25mm_HE_DF_T_G: RC_B_25mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_HE_DF_T_Y: RC_B_25mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_25mm_HE_QF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_QF.hpp"
};
class RC_B_25mm_HE_QF_T_G: RC_B_25mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_HE_QF_T_Y: RC_B_25mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//25mm HEAB DF/QF
class RC_B_25mm_HEAB_DF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_DF.hpp"
	submunitionAmmo="RC_B_25mm_HE_DF_Sub";
};
class RC_B_25mm_HEAB_DF_T_G: RC_B_25mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_HEAB_DF_T_Y: RC_B_25mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_25mm_HEAB_QF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_25mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_QF.hpp"
};
class RC_B_25mm_HEAB_QF_T_G: RC_B_25mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_25mm_HEAB_QF_T_Y: RC_B_25mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};




//30mm MP Pen/DF/QF
class RC_B_30mm_MP_Pen_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_Pen.hpp"
	//submunitionAmmo="RC_ammo_Penetrator_MP_30mm";
};
class RC_B_30mm_MP_Pen_T_G: RC_B_30mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_MP_Pen_T_Y: RC_B_30mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_30mm_MP_DF_Sub: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_30mm";
	caliber=4.4;
};
class RC_B_30mm_MP_DF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_B_30mm_MP_DF_Sub";
};
class RC_B_30mm_MP_DF_T_G: RC_B_30mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_MP_DF_T_Y: RC_B_30mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_30mm_MP_QF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_30mm";
};
class RC_B_30mm_MP_QF_T_G: RC_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_MP_QF_T_Y: RC_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//30mm MPAB DF/QF
class RC_B_30mm_MPAB_DF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_B_30mm_MP_DF_Sub";
};
class RC_B_30mm_MPAB_DF_T_G: RC_B_30mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_MPAB_DF_T_Y: RC_B_30mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_30mm_MPAB_QF_T_R: B_30mm_MP_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_30mm";
};
class RC_B_30mm_MPAB_QF_T_G: RC_B_30mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_MPAB_QF_T_Y: RC_B_30mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_B_30mm_MP_DF_Sub_X: RC_B_30mm_MP_DF_Sub
{
	submunitionAmmo="RC_ammo_Penetrator_MP_30mm_X";
	submunitionInitialOffset[]={0,0,-3.5};
	explosionTime=0.014;
};
class RC_B_30mm_MPAB_DF_X_T_R: RC_B_30mm_MPAB_DF_T_R
{
	submunitionInitialOffset[]={0,0,-3.5};
	triggerDistance=10;
	submunitionAmmo="RC_B_30mm_MP_DF_Sub_X";
};
class RC_B_30mm_MPAB_DF_X_T_G: RC_B_30mm_MPAB_DF_X_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_MPAB_DF_X_T_Y: RC_B_30mm_MPAB_DF_X_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//30mm HE Pen/DF/QF
class RC_B_30mm_HE_Pen_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_Pen.hpp"
};
class RC_B_30mm_HE_Pen_T_G: RC_B_30mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_HE_Pen_T_Y: RC_B_30mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_30mm_HE_DF_Sub: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_HE_DF.hpp"
};
class RC_B_30mm_HE_DF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_DF.hpp"
	submunitionAmmo="RC_B_30mm_HE_DF_Sub";
};
class RC_B_30mm_HE_DF_T_G: RC_B_30mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_HE_DF_T_Y: RC_B_30mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_30mm_HE_QF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_QF.hpp"
};
class RC_B_30mm_HE_QF_T_G: RC_B_30mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_HE_QF_T_Y: RC_B_30mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//30mm HEAB DF/QF
class RC_B_30mm_HEAB_DF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_DF.hpp"
	submunitionAmmo="RC_B_30mm_HE_DF_Sub";
};
class RC_B_30mm_HEAB_DF_T_G: RC_B_30mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_HEAB_DF_T_Y: RC_B_30mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_30mm_HEAB_QF_T_R: B_30mm_HE_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_30mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_QF.hpp"
};
class RC_B_30mm_HEAB_QF_T_G: RC_B_30mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_HEAB_QF_T_Y: RC_B_30mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};




//35mm HEAB C-UAS / MPAB AA
class RC_B_35mm_MP_AA_Sub: B_35mm_AA
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_35mm_AA.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_35mm";
	caliber=4.5;
};
class RC_B_35mm_MPAB_AA_T_R: B_35mm_AA
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults_cUAS.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_35mm_AA.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_35mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_MPAB_DF.hpp"
	submunitionAmmo="RC_B_35mm_MP_AA_Sub";
};
class RC_B_35mm_MPAB_AA_T_G: RC_B_35mm_MPAB_AA_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_35mm_MPAB_AA_T_Y: RC_B_35mm_MPAB_AA_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_35mm_HE_AA_Sub: B_35mm_AA
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_35mm_AA.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_Sub_HE_DF.hpp"
};
class RC_B_35mm_HEAB_AA_T_R: B_35mm_AA
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults_cUAS.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_35mm_AA.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_HEAB_DF.hpp"
	submunitionAmmo="RC_B_35mm_HE_AA_Sub";
};
class RC_B_35mm_HEAB_AA_T_G: RC_B_35mm_HEAB_AA_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_35mm_HEAB_AA_T_Y: RC_B_35mm_HEAB_AA_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//35mm FSV
class RC_B_35mm_APFSDS_T_R: RC_B_30mm_APFSDS_T_R
{
	hit=135;
	cost=85;
};
class RC_B_35mm_APFSDS_T_G: RC_B_35mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_35mm_APFSDS_T_Y: RC_B_35mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_35mm_MP_DF_Sub: B_35mm_AA
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_35mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_35mm";
	caliber=4.5;
};
class RC_B_35mm_MPAB_DF_T_R: B_35mm_AA
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_35mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_35mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_B_35mm_MP_DF_Sub";
};
class RC_B_35mm_MPAB_DF_T_G: RC_B_35mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_35mm_MPAB_DF_T_Y: RC_B_35mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};




//40mm MP Pen/DF/QF
class RC_B_40mm_MP_Pen_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_Pen.hpp"
	//submunitionAmmo="RC_ammo_Penetrator_MP_40mm";
};
class RC_B_40mm_MP_Pen_T_G: RC_B_40mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_MP_Pen_T_Y: RC_B_40mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_40mm_MP_DF_Sub: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_40mm";
	caliber=4.6;
};
class RC_B_40mm_MP_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_B_40mm_MP_DF_Sub";
};
class RC_B_40mm_MP_DF_T_G: RC_B_40mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_MP_DF_T_Y: RC_B_40mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_40mm_MP_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_40mm";
};
class RC_B_40mm_MP_QF_T_G: RC_B_40mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_MP_QF_T_Y: RC_B_40mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//40mm MPAB DF/QF
class RC_B_40mm_MPAB_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_B_40mm_MP_DF_Sub";
};
class RC_B_40mm_MPAB_DF_T_G: RC_B_40mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_MPAB_DF_T_Y: RC_B_40mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_40mm_MPAB_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_40mm";
};
class RC_B_40mm_MPAB_QF_T_G: RC_B_40mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_MPAB_QF_T_Y: RC_B_40mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//40mm HE Pen/DF/QF
class RC_B_40mm_HE_Pen_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_Pen.hpp"
};
class RC_B_40mm_HE_Pen_T_G: RC_B_40mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_HE_Pen_T_Y: RC_B_40mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_40mm_HE_DF_Sub: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_HE_DF.hpp"
};
class RC_B_40mm_HE_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_DF.hpp"
	submunitionAmmo="RC_B_40mm_HE_DF_Sub";
};
class RC_B_40mm_HE_DF_T_G: RC_B_40mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_HE_DF_T_Y: RC_B_40mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_40mm_HE_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_QF.hpp"
};
class RC_B_40mm_HE_QF_T_G: RC_B_40mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_HE_QF_T_Y: RC_B_40mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//40mm HEAB DF/QF
class RC_B_40mm_HEAB_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_DF.hpp"
	submunitionAmmo="RC_B_40mm_HE_DF_Sub";
};
class RC_B_40mm_HEAB_DF_T_G: RC_B_40mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_HEAB_DF_T_Y: RC_B_40mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_40mm_HEAB_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_40mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_QF.hpp"
};
class RC_B_40mm_HEAB_QF_T_G: RC_B_40mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_40mm_HEAB_QF_T_Y: RC_B_40mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};




//50mm MP Pen/DF/QF
class RC_B_50mm_MP_Pen_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_Pen.hpp"
	//submunitionAmmo="RC_ammo_Penetrator_MP_50mm";
};
class RC_B_50mm_MP_Pen_T_G: RC_B_50mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_MP_Pen_T_Y: RC_B_50mm_MP_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_50mm_MP_DF_Sub: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_50mm";
	caliber=4.8;
};
class RC_B_50mm_MP_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_DF.hpp"
	submunitionAmmo="RC_B_50mm_MP_DF_Sub";
};
class RC_B_50mm_MP_DF_T_G: RC_B_50mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_MP_DF_T_Y: RC_B_50mm_MP_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_50mm_MP_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MP_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_50mm";
};
class RC_B_50mm_MP_QF_T_G: RC_B_50mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_MP_QF_T_Y: RC_B_50mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//50mm MPAB DF/QF
class RC_B_50mm_MPAB_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_DF.hpp"
	submunitionAmmo="RC_B_50mm_MP_DF_Sub";
};
class RC_B_50mm_MPAB_DF_T_G: RC_B_50mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_MPAB_DF_T_Y: RC_B_50mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_50mm_MPAB_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HitMP_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\MPAB_QF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_50mm";
};
class RC_B_50mm_MPAB_QF_T_G: RC_B_50mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_MPAB_QF_T_Y: RC_B_50mm_MPAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//50mm HE Pen/DF/QF
class RC_B_50mm_HE_Pen_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_Pen.hpp"
};
class RC_B_50mm_HE_Pen_T_G: RC_B_50mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_HE_Pen_T_Y: RC_B_50mm_HE_Pen_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_50mm_HE_DF_Sub: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Sub_HE_DF.hpp"
};
class RC_B_50mm_HE_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_DF.hpp"
	submunitionAmmo="RC_B_50mm_HE_DF_Sub";
};
class RC_B_50mm_HE_DF_T_G: RC_B_50mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_HE_DF_T_Y: RC_B_50mm_HE_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_50mm_HE_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HE_QF.hpp"
};
class RC_B_50mm_HE_QF_T_G: RC_B_50mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_HE_QF_T_Y: RC_B_50mm_HE_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//50mm HEAB DF/QF
class RC_B_50mm_HEAB_DF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_DF.hpp"
	submunitionAmmo="RC_B_50mm_HE_DF_Sub";
};
class RC_B_50mm_HEAB_DF_T_G: RC_B_50mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_HEAB_DF_T_Y: RC_B_50mm_HEAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_B_50mm_HEAB_QF_T_R: B_40mm_GPR_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Defaults.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\Values_50mm.hpp"
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\HEAB_QF.hpp"
};
class RC_B_50mm_HEAB_QF_T_G: RC_B_50mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_50mm_HEAB_QF_T_Y: RC_B_50mm_HEAB_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};




//C-UAS
class RC_cUAS_Pellet: BulletBase
{
	hit=6;	//4-8
	indirectHit=0;
	indirectHitRange=0;	//0.15-0.6
	typicalSpeed=360;
	deflecting=30;	//30-50
	airFriction=-0.005;
};
class RC_20mm_cUAS: B_20mm_cUAS_Base
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\cUAS_Pellets.hpp"
	submunitionConeAngle="0.4";		//0.4deg = 600m 1/3 shots should hit with a spread of 4.16m, 500m 2/3 should hit with a spread of 3.4m
	submunitionConeType[]=
	{
		"poissondisc",	//test randomcenter
		64
	};
	hit=30;			//test if less doesnt engage vehicles
	indirectHit=0;
	indirectHitRange=0;
	cost=20;
	/*
	caliber=3.4000001;	//test if 1 doesnt engage helis
	*/
};
class RC_25mm_cUAS: RC_20mm_cUAS
{
	submunitionConeType[]=
	{
		"poissondisc",
		80
	};
};
class RC_30mm_cUAS: RC_20mm_cUAS
{
	submunitionConeAngle="0.4";		//0.4deg = 600m 2/3 shots should hit with a spread of 4.16m
	submunitionConeType[]=
	{
		"poissondisc",
		96
	};
};
class RC_40mm_cUAS: RC_20mm_cUAS
{
	submunitionConeAngle="0.4";		//0.4deg = 600m 2/3 shots should hit with a spread of 4.16m
	submunitionConeType[]=
	{
		"poissondisc",
		96
	};
};
class RC_127x99mm_cUAS: B_127x99_Ball_Tracer_Red
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\cUAS_Pellets.hpp"
	submunitionConeAngle="0.344";		//16, 0.384deg = 400m 1/4 shots should hit with a spread of 2.68m
	//submunitionConeAngle="0.384";		//20, 0.384deg = 400m 1/4 shots should hit with a spread of 2.68m	 //worked slightly too well
	//submunitionConeAngle="0.272";		//10 0.272deg = 400m 1/4 shots should hit with a spread of 1.9m
	//submunitionConeAngle="0.362";		//10? 0.362deg = 300m 1/4 shots should hit with a spread of 1.9m
	submunitionConeType[]=
	{
		"poissondisc",	//test randomcenter
		16
	};
	//caliber=2.5999999;	//test relating vehicles
};
class RC_338_cUAS: B_338_NM_Ball
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\cUAS_Pellets.hpp"
	submunitionConeAngle="0.272";		//10 0.272deg = 400m 1/4 shots should hit with a spread of 1.9m
	//submunitionConeAngle="0.281";		//6, 0.281deg = 300m 1/4 shots should hit with a spread of 1.47m
	submunitionConeType[]=
	{
		"poissondisc",
		10
	};
};
class RC_93x64_cUAS: B_93x64_Ball
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\cUAS_Pellets.hpp"
	submunitionConeAngle="0.272";		//10 0.272deg = 400m 1/4 shots should hit with a spread of 1.9m
	//submunitionConeAngle="0.281";		//6, 0.281deg = 300m 1/4 shots should hit with a spread of 1.47m
	submunitionConeType[]=
	{
		"poissondisc",
		10
	};
};


class RC_mounted_cUAS_Pellet: RC_cUAS_Pellet
{
	hit=6;
	deflecting=20;			//30
	airFriction=-0.0025;	//-0.005
};
class RC_127x99mm_mounted_cUAS: RC_127x99mm_cUAS
{
	submunitionAmmo="RC_mounted_cUAS_Pellet";
	airFriction=-0.0025;	//-0.005
	airLock=1;	//2
	submunitionConeAngle="0.344";		//16, 0.384deg = 400m 1/4 shots should hit with a spread of 2.68m
};
class RC_B_127x99_mounted_SLAP_T_R: RC_B_127x99_SLAP_T_R
{
	laserLock=0;	//1
	irLock=0;		//1
	airLock=1;
	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
};
class RC_20mm_mounted_cUAS: RC_20mm_cUAS
{
	submunitionAmmo="RC_mounted_cUAS_Pellet";
	airFriction=-0.0025;	//-0.005
	airLock=1;	//2
};


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
	deflecting=1;
	tracerEndTime=6;
	craterEffects="AAMissileCrater";
};
class RC_Sh_120mm_MP_T_G: RC_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_120mm_MP_T_Y: RC_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//120mm MPAB DF
class RC_Sh_120mm_MP_DF_Sub: RC_Sh_120mm_MP_T_R
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_120mm";
};
class RC_Sh_120mm_MPAB_DF_T_R: RC_Sh_120mm_MP_T_R
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_MPAB_DF.hpp"
	submunitionAmmo="RC_Sh_120mm_MP_DF_Sub";
};
class RC_Sh_120mm_MPAB_DF_T_G: RC_Sh_120mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_120mm_MPAB_DF_T_Y: RC_Sh_120mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_ammo_Penetrator_AB_120mm: RC_ammo_Penetrator_120mm
{
	airFriction=-0.001;
};
class RC_Sh_120mm_MP_HEAB_T_R: RC_Sh_120mm_MP_T_R
{
	submunitionAmmo="RC_ammo_Penetrator_AB_120mm";
	aiAmmoUsageFlags="64 + 128 + 256 + 512";
};
class RC_Sh_120mm_MP_HEAB_T_G: RC_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_120mm_MP_HEAB_T_Y: RC_Sh_120mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//class MissileBase;
class RC_Sh_120mm_HEAB_LV_Overflight_Core: MissileBase
{
	class Components;
};
class RC_Sh_120mm_HEAB_LV_Overflight_Base: RC_Sh_120mm_HEAB_LV_Overflight_Core
{
	effectsMissile="EmptyEffect";	//effectsMissile="missile3";
	effectsMissileInit="";
	whistleDist=16;
	craterEffects="AAMissileCrater";	//CraterEffects="ATRocketCrater";
	explosionEffects="ATRocketExplosion";
	soundHit[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\NLAW_Hit",
		1.7782794,
		1,
		1500
	};
	soundFly[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\Fly_NLAW",
		0.56234133,
		1.5,
		700
	};
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
		power=2.5148699;
		duration=1.2;
		frequency=20;
		distance=50.596401;
	};
	class CamShakePlayerFire
	{
		power=2;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};
class RC_Sh_120mm_HEAB_LV_Overflight: RC_Sh_120mm_HEAB_LV_Overflight_Base
{
	hit=250;
	indirectHit=60;
	indirectHitRange=12;
	explosive=1;	//0.5 rare value

	cost=400;
	timeToLive=1.5;	//2

	irLock=1;
	airLock=1;
	laserLock=1;
	allowAgainstInfantry=1;
	aiAmmoUsageFlags="64 + 128 + 256";

	maneuvrability=2;	//whats optimum
	simulationStep=0.0020000001;
	trackOversteer=0.80000001;
	trackLead=0;	//1 is op
	maxControlRange=11;
	model="\A3\weapons_f\launchers\nlaw\nlaw_rocket";
	airFriction=0.090000004;
	sideAirFriction=0.5;
	maxSpeed=180;
	initTime=0;
	thrustTime=1;
	thrust=70;	//200
	fuseDistance=10;	//test

	//submunitionAmmo="RC_ammo_Penetrator_AB_120mm";	//works like a charm, but is completely op, make seperate version
	//submunitionDirectionType="SubmunitionTargetDirection";
	//submunitionInitSpeed=1000;
	//submunitionParentSpeedCoef=0;
	//submunitionInitialOffset[]={0,0,-0.5};
	triggerOnImpact=1;
	triggerDistance=12;	//find optimum
	proximityExplosionDistance=12;
	deleteParentWhenTriggered=0;

	flightProfiles[]=
	{
		"Overfly"
	};
	class Overfly
	{
		overflyElevation=10;
	};
	/*
	flightProfiles[]=
	{
		"Cruise"
	};
	class Cruise
	{
		preferredFlightAltitude=10;
		lockDistanceToTarget=20;
	};
	*/

	//autoSeekTarget=1;	 //steers off course sideways if no target (maybe switches to datalink targets)
	missileLockCone=300;
	missileKeepLockedCone=300;
	missileLockMaxDistance=200;	//800
	missileLockMinDistance=1;	//20
	missileLockMaxSpeed=100;	//35
	weaponLockSystem="1 + 2 + 4 + 16";	//edit, reduce
	cmImmunity=1;

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
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=360;
					angleRangeVertical=360;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=300;
					class AirTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					maxTrackableSpeed=120;
					angleRangeHorizontal=180;
					angleRangeVertical=180;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=300;
					class AirTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					maxTrackableSpeed=120;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=180;
					angleRangeVertical=180;
				};
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=300;
					class AirTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=15;
					angleRangeHorizontal=180;
					angleRangeVertical=180;
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


class Sh_120mm_HE_Tracer_Red;
class RC_Sh_120mm_HEAB_LV_indirect2_T_R: Sh_120mm_HE_Tracer_Red
{
	//Default
	laserLock=1;
	irLock=1;
	airLock=1;
	deflecting=1;
	tracerEndTime=15;
	timeToLive=20;

	//Submun
	triggerOnImpact=1;
	submunitionCount=1;
	submunitionParentSpeedCoef=0;
	submunitionInitSpeed=40;	//NLAW default
	submunitionConeAngle=0;
	submunitionDirectionType="SubmunitionTargetDirection";

	//!!!TRY 10m above ground trigger + 10m triggerdistance!!!

	//Trigger/ed
	deleteParentWhenTriggered=1;
	submunitionInitialOffset[]={0,0,0};
	triggerDistance=50;

	//Penetration / Fuze
	explosive=0.80000001;

	//Simulation
	simulation="shotSubmunitions";
	simulationStep=0.0020000001;

	//Use
	warheadName="HE";
	aiAmmoUsageFlags="64 + 128 + 256";


	submunitionAmmo="RC_Sh_120mm_HEAB_LV_Overflight";
	//airFriction=0;
	//sideairFriction=0;
	hit=250;
	indirectHit=60;
	indirectHitRange=12;
	craterEffects="AAMissileCrater";
};
class RC_Sh_120mm_HEAB_LV_indirect_T_R: Sh_120mm_HE_Tracer_Red
{
	airFriction=0;
	sideairFriction=0;

	//explosive=1;
	hit=250;
	indirectHit=60;
	indirectHitRange=12;
	//typicalSpeed=1400;

	aiAmmoUsageFlags="64 + 128 + 256";
	laserLock=1;
	irLock=1;
	airLock=1;
	deflecting=1;
	tracerEndTime=15;
	craterEffects="AAMissileCrater";
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_Sh_120mm_HEAB_LV_indirect_T_G: RC_Sh_120mm_HEAB_LV_indirect_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_120mm_HEAB_LV_indirect_T_Y: RC_Sh_120mm_HEAB_LV_indirect_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class Sh_120mm_APFSDS_Tracer_Red;
class RC_Sh_120mm_APFSDS_T_R: Sh_120mm_APFSDS_Tracer_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=4;
};
class RC_Sh_120mm_APFSDS_T_G: RC_Sh_120mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_120mm_APFSDS_T_Y: RC_Sh_120mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_Sh_120mm_APFSDS_X_T_R: RC_Sh_120mm_APFSDS_T_R
{
	hit=600;
	indirectHitRange=1;
	deflecting=10;
};
class RC_Sh_120mm_APFSDS_X_T_G: RC_Sh_120mm_APFSDS_X_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_120mm_APFSDS_X_T_Y: RC_Sh_120mm_APFSDS_X_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class Sh_125mm_HEAT_T_Red;
class RC_Sh_125mm_MP_T_R: Sh_125mm_HEAT_T_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	aiAmmoUsageFlags="64 + 128 + 512";
	indirectHit=50;
	indirectHitRange=10;
	deflecting=1;
	tracerEndTime=6;
	craterEffects="AAMissileCrater";
};
class RC_Sh_125mm_MP_T_G: RC_Sh_125mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\shell_tracer_green";};
class RC_Sh_125mm_MP_T_Y: RC_Sh_125mm_MP_T_R {model="\A3\Weapons_f\Data\bullettracer\shell_tracer_yellow";};


//125mm MPAB DF
class RC_Sh_125mm_MP_DF_Sub: RC_Sh_125mm_MP_T_R
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_Sub_MP_DF.hpp"
	submunitionAmmo="RC_ammo_Penetrator_MP_125mm";
};
class RC_Sh_125mm_MPAB_DF_T_R: RC_Sh_125mm_MP_T_R
{
	#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AA_MPAB_DF.hpp"
	submunitionAmmo="RC_Sh_125mm_MP_DF_Sub";
};
class RC_Sh_125mm_MPAB_DF_T_G: RC_Sh_125mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_125mm_MPAB_DF_T_Y: RC_Sh_125mm_MPAB_DF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class Sh_125mm_HE_T_Red;
class RC_Sh_125mm_HEAB_LV_indirect_T_R: Sh_125mm_HE_T_Red
{
	airFriction=0;
	sideairFriction=0;

	//explosive=1;
	hit=275;
	indirectHit=60;
	indirectHitRange=12;
	//typicalSpeed=1400;

	aiAmmoUsageFlags="64 + 128 + 256";
	laserLock=1;
	irLock=1;
	airLock=1;
	deflecting=1;
	tracerEndTime=15;
	craterEffects="AAMissileCrater";
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_Sh_125mm_HEAB_LV_indirect_T_G: RC_Sh_125mm_HEAB_LV_indirect_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_125mm_HEAB_LV_indirect_T_Y: RC_Sh_125mm_HEAB_LV_indirect_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class Sh_125mm_APFSDS_T_Red;
class RC_Sh_125mm_APFSDS_T_R: Sh_125mm_APFSDS_T_Red
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=4;
};
class RC_Sh_125mm_APFSDS_T_G: RC_Sh_125mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_Sh_125mm_APFSDS_T_Y: RC_Sh_125mm_APFSDS_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//class ammo_Penetrator_Base;
class RC_ammo_Penetrator_MP: ammo_Penetrator_Base
{
	caliber=60;
	warheadName="TandemHEAT";
	hit=780;	//same as Titan AT long
};
class RC_ammo_Penetrator_MP_PD: RC_ammo_Penetrator_MP
{
	airFriction=-0.01;	//to allow further submunitionoffset
};
class M_Titan_AT_long;
class M_Titan_AT_long_Base: M_Titan_AT_long
{
	class Components;
};
class RC_IFV_MP_LOS: M_Titan_AT_long_Base
{
	craterEffects="AAMissileCrater";
	indirectHit=80;
	indirectHitRange=10;
	explosive=1;
	timeToLive=20;	//25 CLBM likely also cannon lg atgm

	//lockType=0;	//?, 0 Titan AT & cannon lg atgm, 1 Titan AP & CLMB, 0 likely fire forget 1 likely beamriding
	irLock=1;
	airLock=1;
	laserLock=1;
	allowAgainstInfantry=1;
	aiAmmoUsageFlags="64 + 128 + 256 + 512";

	simulationStep=0.0020000001;	//0.0020000001 CLMB & Titan AT & AA, 0.0099999998 missilebase, 0.050000001 missilecore
	airFriction=0.085000001;		//0.050000001 CLBM, 0.2 missilebase, -0.00050000002 default & missilecore, 0.085000001 Titan AT
	sideAirFriction=2;				//affects accuracy, 0.1 CLBM, 0.001 missilebase, 1 default & missilecore & Titan AT
	maneuvrability=40;	//40 is accurate with 160m and 1 SAFr, 3 CLMB & missilecore, 20 missilebase & ?cannon lg atgm?
	trackOversteer=1;	//1.4 CLBM, 1 default, missilecore, missilebase
	trackLead=1;		//CLBM 0.94999999
	maxSpeed=350;		//280 CLBM, 180 Titan AT, 350 125mm ATGM, 500 missilebase, 0 default & missilecore
	
	initTime=0;			//0 CLBM
	thrustTime=6;		//5 CLMB & Titan, 6 cannon lg atgm, NLAW 0.80000001, too long thrust time seems to lead to misses
	thrust=60;			//60 CLBM, 125mm ATGM, 40 cannon lg atgm, 45 Titan AT
	fuseDistance=15;	//test

	submunitionAmmo="RC_ammo_Penetrator_MP_PD";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-1};
	triggerOnImpact=1;
	triggerDistance=10;
	proximityExplosionDistance=10;
	deleteParentWhenTriggered=0;

	//autoSeekTarget=1;	 //unlear if it works in this context
	manualControl=1;
	//manualControlOffset=100;	//??? CLMB
	missileLockCone=300;
	missileKeepLockedCone=300;
	maxControlRange=4200;	//+200 for ascent and descent
	missileLockMaxDistance=4000;
	missileLockMinDistance=20;
	missileLockMaxSpeed=100;	//35
	weaponLockSystem="1 + 2 + 4 + 16";
	cmImmunity=0.85;	//higher to simulate topdown ignoring smokes around the vehicle
	cameraViewAvailable=1;

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
			};
		};
	};
};
class RC_IFV_MP_NLOS: RC_IFV_MP_LOS
{
	flightProfiles[]=
	{
		"Cruise"
	};
	class Cruise
	{
		preferredFlightAltitude=100;
		lockDistanceToTarget=160;	//~45°=142
	};

	class Components: Components
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
			};
		};
	};
};


class RC_IFV_MP_Overfly_Core: MissileBase
{
	class Components;
};
class RC_IFV_MP_Overfly_Base: RC_IFV_MP_Overfly_Core
{
	effectsMissile="EmptyEffect";	//effectsMissile="missile3";
	effectsMissileInit="";
	whistleDist=16;
	craterEffects="AAMissileCrater";	//CraterEffects="ATRocketCrater";
	explosionEffects="ATRocketExplosion";
	soundHit[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\NLAW_Hit",
		1.7782794,
		1,
		1500
	};
	soundFly[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\Fly_NLAW",
		0.56234133,
		1.5,
		700
	};
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
		power=2.5148699;
		duration=1.2;
		frequency=20;
		distance=50.596401;
	};
	class CamShakePlayerFire
	{
		power=2;
		duration=0.1;
		frequency=20;
		distance=1;
	};
};
class RC_M_NLAW_AT_F_Core: MissileBase
{
	hit=50;
	indirectHit=25;
	indirectHitRange=2.4000001;
	proximityExplosionDistance=5;
	explosive=0.5;
	maneuvrability=2;
	simulationStep=0.0020000001;
	trackOversteer=0.80000001;
	trackLead=1;
	irLock=1;
	aiAmmoUsageFlags="128 + 512";
	maxControlRange=11;
	model="\A3\weapons_f\launchers\nlaw\nlaw_rocket";
	cost=400;
	timeToLive=8;
	airFriction=0.090000004;
	sideAirFriction=0.5;
	maxSpeed=180;
	initTime=0.2;
	thrustTime=0.80000001;
	thrust=200;
	fuseDistance=20;
	effectsMissile="missile3";
	whistleDist=16;
	CraterEffects="ATRocketCrater";
	explosionEffects="ATRocketExplosion";
	effectsMissileInit="";
	allowAgainstInfantry=0;
	soundHit[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\NLAW_Hit",
		1.7782794,
		1,
		1500
	};
	soundFly[]=
	{
		"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\Fly_NLAW",
		0.56234133,
		1.5,
		700
	};
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
		power=2.5148699;
		duration=1.2;
		frequency=20;
		distance=50.596401;
	};
	class CamShakePlayerFire
	{
		power=2;
		duration=0.1;
		frequency=20;
		distance=1;
	};
	submunitionAmmo="ammo_Penetrator_NLAW";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.5};
	triggerOnImpact=1;
	triggerDistance=2.5;
	deleteParentWhenTriggered=0;
	flightProfiles[]=
	{
		//"Direct",
		"Overfly"
	};
	/*
	class Direct
	{
	};
	*/
	class Overfly	//: Direct
	{
		overflyElevation=2.5;
	};
	airLock=1;
	missileLockCone=5;
	missileKeepLockedCone=300;
	missileLockMaxDistance=800;
	missileLockMinDistance=20;
	missileLockMaxSpeed=35;
	weaponLockSystem="1 + 16";
	cmImmunity=0.2;
	
	class Components	//: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class VisualSensorComponent: SensorTemplateVisual
				{
					class AirTarget
					{
						minRange=500;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=800;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=35;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=5;
					angleRangeVertical=5;
					maxTrackableATL=20;
				};
			};
		};
	};
};
class RC_IFV_MP_Overfly: RC_M_NLAW_AT_F_Core
{
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";

	craterEffects="AAMissileCrater";
	indirectHit=80;
	indirectHitRange=10;
	explosive=1;
	timeToLive=20;	//25 CLBM likely also cannon lg atgm

	//lockType=0;	//?, 0 Titan AT & cannon lg atgm, 1 Titan AP & CLMB, 0 likely fire forget 1 likely beamriding
	irLock=1;
	airLock=1;
	laserLock=1;
	allowAgainstInfantry=1;
	aiAmmoUsageFlags="64 + 128 + 256 + 512";

	simulationStep=0.0020000001;	//0.0020000001 CLMB & Titan AT & AA, 0.0099999998 missilebase, 0.050000001 missilecore
	airFriction=0.085000001;		//0.050000001 CLBM, 0.2 missilebase, -0.00050000002 default & missilecore, 0.085000001 Titan AT
	sideAirFriction=2;				//affects accuracy, 0.1 CLBM, 0.001 missilebase, 1 default & missilecore & Titan AT
	maneuvrability=40;	//40 is accurate with 160m and 1 SAFr, 3 CLMB & missilecore, 20 missilebase & ?cannon lg atgm?
	trackOversteer=1;	//1.4 CLBM, 1 default, missilecore, missilebase
	trackLead=1;		//CLBM 0.94999999
	maxSpeed=350;		//280 CLBM, 180 Titan AT, 350 125mm ATGM, 500 missilebase, 0 default & missilecore
	
	initTime=0;			//0 CLBM
	thrustTime=10;		//5 CLMB & Titan, 6 cannon lg atgm, NLAW 0.80000001, too long thrust time seems to lead to misses
	thrust=120;			//60 CLBM, 125mm ATGM, 40 cannon lg atgm, 45 Titan AT
	fuseDistance=15;	//test

	submunitionAmmo="RC_ammo_Penetrator_MP_PD";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-1};
	triggerOnImpact=1;
	triggerDistance=12;
	proximityExplosionDistance=14;
	deleteParentWhenTriggered=0;

	//autoSeekTarget=1;	 //unlear if it works in this context
	manualControl=1;
	//manualControlOffset=100;	//??? CLMB
	missileLockCone=300;
	missileKeepLockedCone=300;
	maxControlRange=4200;	//+200 for ascent and descent
	missileLockMaxDistance=4000;
	missileLockMinDistance=20;
	missileLockMaxSpeed=100;	//35
	weaponLockSystem="1 + 2 + 4 + 16";
	cmImmunity=0.85;	//higher to simulate topdown ignoring smokes around the vehicle
	cameraViewAvailable=1;

	class Overfly	//: Direct
	{
		overflyElevation=10;
	};
	
	class Components: Components
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
			};
		};
	};
};
/*
class RC_IFV_MP_Overfly: RC_IFV_MP_Overfly_Base
{
	cost=400;
	hit=250;

	craterEffects="AAMissileCrater";
	indirectHit=80;
	indirectHitRange=10;
	explosive=1;
	timeToLive=20;	//25 CLBM likely also cannon lg atgm

	//lockType=0;	//?, 0 Titan AT & cannon lg atgm, 1 Titan AP & CLMB, 0 likely fire forget 1 likely beamriding
	irLock=1;
	airLock=1;
	laserLock=1;
	allowAgainstInfantry=1;
	aiAmmoUsageFlags="64 + 128 + 256 + 512";

	simulationStep=0.0020000001;	//0.0020000001 CLMB & Titan AT & AA, 0.0099999998 missilebase, 0.050000001 missilecore
	airFriction=0.085000001;		//0.050000001 CLBM, 0.2 missilebase, -0.00050000002 default & missilecore, 0.085000001 Titan AT
	sideAirFriction=2;				//affects accuracy, 0.1 CLBM, 0.001 missilebase, 1 default & missilecore & Titan AT
	maneuvrability=40;	//40 is accurate with 160m and 1 SAFr, 3 CLMB & missilecore, 20 missilebase & ?cannon lg atgm?
	trackOversteer=1;	//1.4 CLBM, 1 default, missilecore, missilebase
	trackLead=1;		//CLBM 0.94999999
	maxSpeed=350;		//280 CLBM, 180 Titan AT, 350 125mm ATGM, 500 missilebase, 0 default & missilecore
	
	initTime=0;			//0 CLBM
	thrustTime=6;		//5 CLMB & Titan, 6 cannon lg atgm, NLAW 0.80000001, too long thrust time seems to lead to misses
	thrust=60;			//60 CLBM, 125mm ATGM, 40 cannon lg atgm, 45 Titan AT
	fuseDistance=15;	//test

	submunitionAmmo="RC_ammo_Penetrator_MP_PD";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-1};
	triggerOnImpact=1;
	triggerDistance=12;	//10
	proximityExplosionDistance=12;	//10
	deleteParentWhenTriggered=0;

	//autoSeekTarget=1;	 //unlear if it works in this context
	manualControl=1;
	//manualControlOffset=100;	//??? CLMB
	missileLockCone=300;
	missileKeepLockedCone=300;
	maxControlRange=4200;	//+200 for ascent and descent
	missileLockMaxDistance=4000;
	missileLockMinDistance=20;
	missileLockMaxSpeed=100;	//35
	weaponLockSystem="1 + 2 + 4 + 16";
	cmImmunity=0.85;	//higher to simulate topdown ignoring smokes around the vehicle
	cameraViewAvailable=1;

	//maneuvrability=2;	//whats optimum
	//maxControlRange=11;
	//triggerDistance=12;	//find optimum
	//proximityExplosionDistance=12;

	//model="\A3\weapons_f\launchers\nlaw\nlaw_rocket";
	//airFriction=0.090000004;
	//sideAirFriction=0.5;
	

	flightProfiles[]=
	{
		"Overfly"
	};
	class Overfly
	{
		overflyElevation=10;
	};

	class Components: Components
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
			};
		};
	};
};
*/
/*
class RC_IFV_MP_Overfly: RC_IFV_MP_LOS
{
	triggerDistance=12;
	
	flightProfiles[]=
	{
		"Direct",
		"Overfly"
	};
	class Direct
	{
	};
	class Overfly
	{
		overflyElevation=10;
	};

	class Components: Components
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
			};
		};
	};
};
*/


class M_Titan_AA_long;
class RC_IFV_AA_Base: M_Titan_AA_long
{
	class Components;
};
class RC_IFV_AA: RC_IFV_AA_Base
{
	indirectHitRange=12;
	proximityExplosionDistance=12;
	weaponLockSystem="2 + 4 + 16";
	laserLock=1;
	irLock=1;
	airLock=1;
	trackLead=1;
	cmImmunity=0.92000002;
	cameraViewAvailable=1;
	initTime=0.01;

	missileLockMinDistance=20;
	missileLockCone=90;
	missileKeepLockedCone=90;
	thrustTime=4;

	//autoSeekTarget=1;	 //unlear if it works in this context
	//lockSeekRadius=1500;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=5000;
					class AirTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=5000;
						maxRange=5000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=2500;
					maxTrackableSpeed=500;
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
					groundNoiseDistanceCoef=0.2;
					maxGroundNoiseDistance=50;
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
			};
		};
	};
};
class ammo_Penetrator_Nano_MP: ammo_Penetrator_Base
{
	caliber=30;
	warheadName="TandemHEAT";
	hit=300;
	airFriction=-0.01;	//to allow further submunitionoffset
};
class RC_MP_NLOS_Nano: RC_IFV_MP_NLOS
{
	//model="";
	//craterEffects="AAMissileCrater";
	indirectHit=40;
	indirectHitRange=12;
	submunitionAmmo="ammo_Penetrator_Nano_MP";

	delete Direct;

	flightProfiles[]=
	{
		"Cruise"
	};
	class Cruise
	{
		preferredFlightAltitude=50;
		lockDistanceToTarget=100;
	};

	//initTime=8;
	autoSeekTarget=1;	 //unlear if it works in this context
	manualControl=0;
	//missileLockMaxSpeed=100;	//35
	//weaponLockSystem="1 + 2 + 4 + 16";
	//cmImmunity=0.85;	//higher to simulate topdown ignoring smokes around the vehicle
};
/*
class RC_AA_NLOS: RC_IFV_AA
{
	indirectHitRange=12;
	proximityExplosionDistance=12;
	//weaponLockSystem="2 + 4 + 16";
	//cmImmunity=0.89999998;
	lockType=0;

	//manualControl=1;
	//missileManualControlCone=45;
	//maxControlRange=8000;
	
	//autoSeekTarget=1;	 //unlear if it works in this context
	//lockSeekRadius=1500;
	missileLockCone=180;
	missileKeepLockedCone=180;
	thrustTime=5;

	flightProfiles[]=
	{
		"Direct",
		"Cruise"
	};
	class Direct
	{
	};
	class Cruise
	{
		preferredFlightAltitude=100;
		lockDistanceToTarget=150;
	};
};
*/


class RC_70mm_AA: RC_IFV_AA
{
	model="\A3\Weapons_F_Tank\Ammo\Missile_SAAMI_AA_01_fly_F.p3d";
	hit=80;
	indirectHit=60;
	indirectHitRange=8;
	proximityExplosionDistance=10;
};


//ATGM
class M_Vorona_HEAT;
class RC_M_ATGM_MP_SACLOS: M_Vorona_HEAT
{
	submunitionAmmo="RC_ammo_Penetrator_MP";
	indirectHit=40;
	indirectHitRange=10;
	maxControlRange=4000;
	trackOversteer=0.5;
	fuseDistance=20;
	cameraViewAvailable=1;
};


//ATGM
class RC_M_ATGM_MP_LOS: M_Titan_AT_long_Base
{
	craterEffects="AAMissileCrater";
	indirectHit=40;
	indirectHitRange=10;
	explosive=1;
	timeToLive=20;

	//lockType=0;	//?, 0 Titan AT & cannon lg atgm, 1 Titan AP & CLMB, 0 likely fire forget 1 likely beamriding
	irLock=1;
	airLock=1;
	laserLock=1;
	allowAgainstInfantry=1;
	aiAmmoUsageFlags="64 + 128 + 256 + 512";

	simulationStep=0.0020000001;
	airFriction=0.085000001;
	sideAirFriction=2;
	maneuvrability=40;
	trackOversteer=1;
	trackLead=1;
	maxSpeed=350;
	
	initTime=0;
	thrustTime=5;
	thrust=50;
	fuseDistance=15;

	submunitionAmmo="RC_ammo_Penetrator_MP_PD";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-1};
	triggerOnImpact=1;
	triggerDistance=10;
	proximityExplosionDistance=10;
	deleteParentWhenTriggered=0;

	//autoSeekTarget=1;	 //unlear if it works in this context
	manualControl=1;
	//manualControlOffset=100;	//??? CLMB
	missileLockCone=180;	//for NLOS Datalink targeting, being able to shoot missle straight up, over barriers being in the way
	missileKeepLockedCone=180;
	maxControlRange=4200;	//+200 for ascent and descent
	missileLockMaxDistance=4000;
	missileLockMinDistance=20;
	missileLockMaxSpeed=100;	//35
	weaponLockSystem="1 + 2 + 4 + 16";
	cmImmunity=0.85;	//higher to simulate topdown ignoring smokes around the vehicle
	cameraViewAvailable=1;

	class Components: Components
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
				/*
				//autonomous engages lasers spots without differentiating
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
					angleRangeHorizontal=40;
					angleRangeVertical=40;
				};
				*/
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
					angleRangeHorizontal=45;
					angleRangeVertical=45;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1000;
					class AirTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					maxTrackableSpeed=120;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
				};
			};
		};
	};
};
class RC_M_ATGM_MP_NLOS: RC_M_ATGM_MP_LOS
{
	flightProfiles[]=
	{
		"Cruise"
	};
	class Cruise
	{
		preferredFlightAltitude=100;
		lockDistanceToTarget=160;	//~45°=142
	};
};


class M_120mm_cannon_ATGM_LG;
class RC_M_120mm_cannon_ATGM_Base: M_120mm_cannon_ATGM_LG
{
	class Components;
};
class RC_M_120mm_cannon_ATGM: RC_M_120mm_cannon_ATGM_Base
{
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";
	craterEffects="AAMissileCrater";
	indirectHit=80;
	indirectHitRange=10;
	explosive=1;
	timeToLive=20;

	//lockType=0;	//?, 0 Titan AT & cannon lg atgm, 1 Titan AP & CLMB, 0 likely fire forget 1 likely beamriding
	irLock=1;
	airLock=1;
	laserLock=1;
	allowAgainstInfantry=1;
	aiAmmoUsageFlags="64 + 128 + 256 + 512";

	simulationStep=0.0020000001;
	airFriction=0.085000001;
	sideAirFriction=2;
	maneuvrability=40;
	trackOversteer=1;
	trackLead=1;
	maxSpeed=350;
	
	initTime=0.5;
	thrustTime=6;
	thrust=60;
	fuseDistance=15;

	submunitionAmmo="RC_ammo_Penetrator_MP_PD";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-1};
	triggerOnImpact=1;
	triggerDistance=10;
	proximityExplosionDistance=10;
	deleteParentWhenTriggered=0;

	//autoSeekTarget=1;	 //unlear if it works in this context
	manualControl=1;
	//manualControlOffset=100;	//??? CLMB
	missileLockCone=300;
	missileKeepLockedCone=300;
	maxControlRange=4200;	//+200 for ascent and descent
	missileLockMaxDistance=4000;
	missileLockMinDistance=20;
	missileLockMaxSpeed=100;	//35
	weaponLockSystem="1 + 2 + 4 + 16";
	cmImmunity=0.85;	//higher to simulate topdown ignoring smokes around the vehicle
	cameraViewAvailable=1;

	class Components: Components
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
			};
		};
	};
};
class RC_M_120mm_cannon_ATGM_DLG: RC_M_120mm_cannon_ATGM
{
	flightProfiles[]=
	{
		"Cruise"
	};
	class Cruise
	{
		preferredFlightAltitude=100;
		lockDistanceToTarget=160;	//~45°=142
	};
};
class RC_M_120mm_cannon_ATGM_DLG_LR: RC_M_120mm_cannon_ATGM_DLG
{
	timeToLive=30;
	maxControlRange=6200;	//+200 for ascent and descent
	missileLockMaxDistance=6000;

	class Components: Components
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
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
				class IRSensorComponent: SensorTemplateIR
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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=3000;
					maxTrackableSpeed=500;
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
					groundNoiseDistanceCoef=0.2;
					maxGroundNoiseDistance=50;
				};
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
					typeRecognitionDistance=500;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=67.5;
					angleRangeVertical=67.5;
				};
			};
		};
	};
};
class RC_M_125mm_cannon_ATGM_DLG: RC_M_120mm_cannon_ATGM_DLG {};
class RC_M_125mm_cannon_ATGM: RC_M_120mm_cannon_ATGM {};
class RC_M_125mm_cannon_ATGM_DLG_LR: RC_M_120mm_cannon_ATGM_DLG_LR {};


class Sh_120mm_APFSDS;
class RC_Sh_HVKEM_Penetrator_Base: Sh_120mm_APFSDS
{
	class HitEffects;
};
class RC_Sh_HVKEM_Penetrator: RC_Sh_HVKEM_Penetrator_Base
{
	typicalSpeed=2200;	//1550
	hit=900;
	indirectHit=30;
	indirectHitRange=3;
	deflecting=5;

	class HitEffects: HitEffects
	{
		hitMetal="ImpactMetalSabotBig_HVKEM";
		hitMetalPlate="ImpactMetalSabotBig_HVKEM";
	};
};
class RC_M_120mm_DLG_HVKEM: RC_M_120mm_cannon_ATGM_DLG
{
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";

	submunitionAmmo="RC_Sh_HVKEM_Penetrator";
	submunitionDirectionType="SubmunitionTargetDirection";
	//submunitionInitSpeed=1715;
	submunitionParentSpeedCoef=1;	//worse at short range
	submunitionInitialOffset[]={0,0,-1};
	triggerOnImpact=1;
	triggerDistance=20;
	proximityExplosionDistance=20;
	deleteParentWhenTriggered=1;

	missileLockMaxSpeed=686;
	cmImmunity=1;

	indirectHit=30;
	indirectHitRange=3;
	explosive=0.6;
	timeToLive=6;	//6km in 3sec

	simulationStep=0.0020000001;
	airFriction=0.02;
	sideAirFriction=2;
	maneuvrability=40;
	trackOversteer=1;
	trackLead=1;
	maxSpeed=2200;	//like CKEM
	
	initTime=0.01;
	thrustTime=3;	//6km in 3sec
	thrust=1000;

	flightProfiles[]=
	{
		"TopDown"
	};
	class TopDown
	{
		ascendHeight=100;
		descendDistance=500;
		minDistance=500;
		ascendAngle=20;
	};
	//autoSeekTarget=1;
};


/*
(vehicle player) addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

	[_projectile] spawn {
		params ["_projectile"];

		while {alive _projectile} do
		{
			_speed = round ((speed _projectile) / 3.6);
			systemchat str _speed;
		};

		systemchat "splash";
	};
}];
*/


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


class ammo_Penetrator_MP_Guided_Base: ammo_Penetrator_Base
{
	warheadName="TandemHEAT";
	airFriction=-0.01;	//to allow further submunitionoffset
};
//class MissileBase;
class RC_MP_Guided_Submunition_MissleBase: MissileBase
{
	class Components;
};
class RC_MP_LaserGuided_Submunition_SteeringBase: RC_MP_Guided_Submunition_MissleBase
{
	//model="\A3\Weapons_F_Tank\Ammo\Missile_ATGM_01_fly_F";	//fancier but inaccurate
	model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at_fly";
	simulationStep=0.0020000001;

	trackOversteer=1;	//required to not completly miss
	trackLead=1;
	maneuvrability=40;	//20, required to not completly miss
	airFriction=0.085000001;		//0.085000001 Titan AT
	sideAirFriction=2;	//0.1

	initTime=0.01;	//0.01
	thrustTime=8;
	thrust=120;		//300
	maxSpeed=350;	//300
	typicalSpeed=350;	//300

	submunitionAmmo="RC_ammo_Penetrator_MP_PD";
	submunitionDirectionType="SubmunitionTargetDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-1};
	triggerOnImpact=1;
	triggerDistance=10;
	proximityExplosionDistance=10;
	deleteParentWhenTriggered=0;

	/*
	submunitionDirectionType="SubmunitionModelDirection";	//later test SubmunitionTargetDirection, with triggerDistance=; and proximityExplosionDistance=;
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;
	deleteParentWhenTriggered=0;
	*/
};
class RC_MP_LaserGuided_Submunition_Base: RC_MP_LaserGuided_Submunition_SteeringBase
{
	artilleryLock=0;	//1 would make submunition unable to hit vanilla firing computer gps point
	laserLock=1;
	autoSeekTarget=1;
	cameraViewAvailable=1;

	lockType=0;
	weaponLockSystem="4 + 16";
	cmImmunity=0.9;

	missileLockCone=180;
	missileKeepLockedCone=180;
	lockSeekRadius=900;
	missileLockMaxDistance=2000;
	missileLockMinDistance=1;	//maybe edit
	missileLockMaxSpeed=150;
	maxControlRange=1000;
	//manualControl=0;
	fuseDistance=20;
	timeToLive=10;
	explosive=1;

	whistleDist=60;
	//warheadName="TandemHEAT";
	warheadName="HE";
	hit=165;	//submunition penetrator contains main hit value
	aiAmmoUsageFlags="128 + 512";
	
	explosionSoundEffect="DefaultExplosion";
	explosionEffects="RC_GuidedExplosion";
	craterEffects="AAMissileCrater";
	effectsMissileInit="";
	muzzleEffect="";

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
				//would be too op
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
				class AntiRadiationSensorComponent: SensorTemplateAntiRadiation
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
					allowsMarking=1;
				};
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


//cluster submun that does more damage to vehicles
class Mo_cluster_AP;
class RC_Mo_cluster_82mm_AP: Mo_cluster_AP
{
	hit=20;
	indirectHit=20;
	indirectHitRange=6;
};
class RC_Mo_cluster_105mm_AP: Mo_cluster_AP
{
	hit=30;
	indirectHit=30;
	indirectHitRange=8;
};
class RC_Mo_cluster_120mm_AP: Mo_cluster_AP
{
	hit=40;
	indirectHit=40;
	indirectHitRange=10;
};
class RC_Mo_cluster_155mm_AP: Mo_cluster_AP
{
	hit=50;
	indirectHit=50;
	indirectHitRange=12;
};
class RC_Mo_cluster_230mm_AP: Mo_cluster_AP
{
	hit=60;
	indirectHit=60;
	indirectHitRange=14;
};
class RC_Mo_cluster_604mm_AP: Mo_cluster_AP
{
	hit=70;
	indirectHit=70;
	indirectHitRange=16;
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
	timeToLive=180;
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
NEEDS TO BE own cfg like:
class CfgMineTriggers
{
	class RangeTriggerBounding;
	class RC_RangeTriggerBounding: RangeTriggerBounding
	{
		mineTriggerRange=9;	//3
		mineTriggerActivationRange=15;	//5
		restrictZoneRadius=15;	//5
	};
};
//test if triggers from to far like without LOS
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


class ammo_Penetrator_82mm_MP: ammo_Penetrator_MP_Guided_Base
{
	caliber=37.8;
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


//40mm
class RC_Sh_40mm_AMOS_HE: RC_G_40mm_HEDP
{
	artilleryLock=1;
	timeToLive=45;
	airFriction=0;
	sideairFriction=0;
	deflecting=1;

	hit=110;
	caliber=4.7;
	indirectHit=12;
	indirectHitRange=8;
	warheadName="HEAT";
	//warheadName="HE";
	simulation="shotShell";
	//explosive=1;
};


//60mm
class RC_Sh_60mm_AMOS_submunition: RC_Sh_82mm_AMOS_submunition
{
	craterEffects="RC_60mmAirburstDust";
	hit=100;
	indirectHit=40;
	indirectHitRange=12;
	cost=100;
};
class RC_60mm_HEAB_Shell_Base: RC_82mm_HEAB_Shell_Base
{
	hit=100;
	indirectHit=40;
	indirectHitRange=12;
	cost=100;
};
class RC_Sh_60mm_AMOS_HEAB: RC_60mm_HEAB_Shell_Base
{
	submunitionAmmo="RC_Sh_60mm_AMOS_submunition";
	aimAboveDefault=2;
	aimAboveTarget[]={7,7,7};	//high airburst to ignore cover, triggers when descending and this height above ground
};


class RC_Sh_60mm_AMOS_HE_submunition: RC_Sh_60mm_AMOS_submunition
{
	craterEffects="ArtyShellCrater";
};
class RC_Sh_60mm_AMOS_HE: RC_60mm_HEAB_Shell_Base
{
	simulationStep=0.050000001;
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0.8,-0.4};
	submunitionAmmo="RC_Sh_60mm_AMOS_HE_submunition";
};
//used in script as replacement when turret elevation is too low for Airburst
class RC_Sh_60mm_AMOS_backupHEAB: RC_Sh_60mm_AMOS_HE
{
	submunitionInitialOffset[]={0,5,0};
	submunitionAmmo="RC_Sh_60mm_AMOS_submunition";
};


class RC_Smoke_60mm_AMOS_White: RC_Smoke_82mm_AMOS_White
{
	submunitionConeType[]=
	{
		"poissondisc",
		3
	};
	//submunitionConeAngle=10;
	//triggerDistance=50;
	cost=100;
	hit=100;
};


class RC_Mine_60mm_AMOS_range: RC_Mine_82mm_AMOS_range
{
	submunitionConeType[]=
	{
		"custom", {{0,1},{-0.866,-0.5},{0.866,-0.5}};
	};
	submunitionConeAngle=10;
	triggerDistance=50;
	cost=100;
	hit=100;
};


class ammo_Penetrator_60mm_MP: ammo_Penetrator_MP_Guided_Base
{
	caliber=30;
	hit=300;
};
class RC_60mm_MP_LaserGuided_Submunition: RC_82mm_MP_LaserGuided_Submunition
{
	submunitionAmmo="ammo_Penetrator_60mm_MP";
	//craterEffects="RC_82mmGuidedDust";
	indirectHit=60;
	indirectHitRange=4.5;
	cost=250;
};
class RC_Sh_60mm_AMOS_MP_LaserGuided: RC_Sh_82mm_AMOS_MP_LaserGuided
{
	submunitionAmmo="RC_60mm_MP_LaserGuided_Submunition";
	triggerDistance=300;
	hit=100;
	indirectHit=60;
	indirectHitRange=4.5;
	cost=250;
};


class RC_60mm_MP_MultiGuided_Submunition: RC_82mm_MP_MultiGuided_Submunition
{
	submunitionAmmo="ammo_Penetrator_60mm_MP";
	//craterEffects="RC_82mmGuidedDust";
	indirectHit=60;
	indirectHitRange=4.5;
	cost=250;
};
class RC_Sh_60mm_AMOS_MP_MultiGuided: RC_Sh_82mm_AMOS_MP_MultiGuided
{
	submunitionAmmo="RC_60mm_MP_MultiGuided_Submunition";
	triggerDistance=300;
	hit=100;
	indirectHit=60;
	indirectHitRange=4.5;
	cost=250;
};


class RC_Sh_60mm_AMOS_delayed_submunition: RC_Sh_60mm_AMOS_submunition
{
	explosionTime=0.2;
};
class RC_M_Mo_60mm_LG_DelayedFuse_Submunition: RC_60mm_MP_LaserGuided_Submunition
{
	triggerDistance=-1;
	triggerOnImpact=1;
	submunitionInitialOffset[]={0,0,2};	//2m infront of projecticle during impact, acting as delayed fuse against bunkers
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionAmmo="RC_Sh_60mm_AMOS_delayed_submunition";
	indirectHit=0;
	indirectHitRange=0;
};
class RC_Sh_60mm_AMOS_LG_DelayedFuse: RC_Sh_60mm_AMOS_MP_LaserGuided
{
	submunitionAmmo="RC_M_Mo_60mm_LG_DelayedFuse_Submunition";
};


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


class ammo_Penetrator_105mm_MP: ammo_Penetrator_MP_Guided_Base
{
	caliber=48.4;
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
	submunitionAmmo[]=
	{
		"RC_Mo_cluster_105mm_AP",
		0.93000001,
		"Mo_cluster_AP_UXO_deploy",
		0.07
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


class ammo_Penetrator_120mm_MP: ammo_Penetrator_MP_Guided_Base
{
	caliber=55.4;
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
	submunitionAmmo[]=
	{
		"RC_Mo_cluster_120mm_AP",
		0.93000001,
		"Mo_cluster_AP_UXO_deploy",
		0.07
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
	submunitionAmmo[]=
	{
		"RC_Mo_cluster_155mm_AP",
		0.93000001,
		"Mo_cluster_AP_UXO_deploy",
		0.07
	};
};


class ammo_Penetrator_155mm_MP: ammo_Penetrator_MP_Guided_Base
{
	caliber=71.5;
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
	//lockSeekDistanceFromParent=10;	//could allow lock after launch, but wasnt achivable in testing so far
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
/*
class RC_Sh_155mm_AMOS_TuFrag_Prox: RC_Sh_155mm_AMOS_submunition
{
	indirectHit=375;
	indirectHitRange=15;
};
class ammo_Penetrator_155mm_MP_Prox: ammo_Penetrator_155mm_MP
{
	airFriction=0.0001;
};
class RC_155mm_MP_MultiGuided_Proximity_Submunition: RC_155mm_MP_MultiGuided_Submunition
{
	submunitionInitSpeed=3000;
	submunitionDirectionType="SubmunitionTargetDirection";
	indirectHit=375;
	indirectHitRange=15;
	triggerDistance=10.6;
	submunitionConeAngle=0;
	//submunitionInitialOffset[]={0,0,10.1};
	submunitionInitialOffset[]={0,0,0};
	deleteParentWhenTriggered=1;
	submunitionConeType[]=
	{
		"poissondisccenter",
		1
	};
	submunitionAmmo[]=
	{
		"RC_Sh_155mm_AMOS_TuFrag_Prox",
		1,
		"ammo_Penetrator_155mm_MP_Prox",
		1
	};
	submunitionAmmo[]=
	{
		"RC_Sh_155mm_AMOS_TuFrag_Prox",
		0.5,
		"ammo_Penetrator_155mm_MP_Prox",
		0.5
	};
};
*/
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
	submunitionAmmo[]=
	{
		"RC_Mo_cluster_230mm_AP",
		0.93000001,
		"Mo_cluster_AP_UXO_deploy",
		0.07
	};
};


class ammo_Penetrator_230mm_MP: ammo_Penetrator_MP_Guided_Base
{
	caliber=106.1;
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
/*
class ammo_Penetrator_230mm_MP_Prox: ammo_Penetrator_230mm_MP
{
	airFriction=0.0001;
};
class RC_R_230mm_fly_HEAB_TuFrag_Prox: RC_R_230mm_fly_HEAB_submunition
{
	indirectHit=1000;
	indirectHitRange=15;
};
class RC_230mm_MP_MultiGuided_Proximity_Submunition: RC_230mm_MP_MultiGuided_Submunition
{
	submunitionInitSpeed=3000;
	submunitionDirectionType="SubmunitionTargetDirection";
	indirectHit=1000;
	indirectHitRange=15;
	triggerDistance=10.6;
	submunitionConeAngle=0;
	submunitionInitialOffset[]={0,0,0};
	submunitionInitialOffset[]={0,0,10.1};
	deleteParentWhenTriggered=1;
	submunitionConeType[]=
	{
		"poissondisccenter",
		1
	};
	submunitionAmmo[]=
	{
		"RC_R_230mm_fly_HEAB_TuFrag_Prox",
		1,
		"ammo_Penetrator_230mm_MP_Prox",
		1
	};
};
*/
class RC_R_230mm_MP_MultiGuided: RC_Sh_AMOS_MP_MultiGuided_Base
{
	//deleteParentWhenTriggered=1;
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
class RC_R_604mm_ATACMS_backupHEAB: RC_604mm_HEAB_Rocket_Base
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
	submunitionAmmo[]=
	{
		"RC_Mo_cluster_604mm_AP",
		0.93000001,
		"Mo_cluster_AP_UXO_deploy",
		0.07
	};
};