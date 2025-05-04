class CfgAmmo
{
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
		indirectHitRange=7;
		submunitionInitSpeed=1000;
		warheadName="TandemHEAT";
		submunitionAmmo="FPV_RPG42_AT_Penetrator_MP";
		submunitionDirectionType="SubmunitionModelDirection";
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.1};
		triggerOnImpact=1;
		deleteParentWhenTriggered=0;
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

		/*
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
		*/

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
};
class cfgMagazines
{
	class RC_target_confirmer_mag;
	class RC_target_confirmer_AB_mag: RC_target_confirmer_mag
	{
		ammo="RC_target_confirmer_AB_ammo";
		initSpeed=1;	//1000 for reticle of bc=8; requires maxControlRange=0;
		scope=2;
		count=1;
	};
};
class Mode_SemiAuto;
class cfgWeapons
{
	class RC_target_confirmer;
	class RC_target_confirmer_AB_weapon: RC_target_confirmer
	{
		displayName="MP airburst";
		displayNameShort="MP airburst";
		scope=2;
		canLock=2;
		weaponLockDelay=0;
		//ballisticsComputer=8;	//8 reticle for shaped charge airburst; requires maxControlRange=0;
		reloadTime=1;
		magazineReloadTime=1;
		magazines[]=
		{
			"RC_target_confirmer_AB_mag"
		};
		modes[]=
		{
			"player"
		};
		class player: Mode_SemiAuto
		{
			displayName="MP airburst";
			//ballisticsComputer=8;	//8 reticle for shaped charge airburst, requires maxControlRange=0;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Release_01",
					3.9810717,
					1,
					20
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			showToPlayer=1;

			aiRateOfFire=100000;	//too not make AI fire itself when it flies in direction of laser target per waypoint
			aiRateOfFireDispersion=0;
			aiRateOfFireDistance=0;
			aiDispersionCoefY=0;
			aiDispersionCoefX=0;
			minRangeProbab=0;
			midRangeProbab=0;
			maxRangeProbab=0;
		};
	};
};