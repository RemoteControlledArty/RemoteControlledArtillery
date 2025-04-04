class CfgAmmo
{
	class M_Vorona_HEAT;
	class FPV_RPG42_AT: M_Vorona_HEAT
	{
		explosive=0.80000001;
		hit=150;
		htMax=1800;
		htMin=60;
		indirectHit=42;		//MP 42, AT 25, AP 60
		indirectHitRange=7;		//MP 5, AT 3.5, AP 6
		submunitionInitSpeed=1000;
		warheadName="TandemHEAT";
		submunitionAmmo="FPV_RPG42_AT_Penetrator";
		submunitionDirectionType="SubmunitionModelDirection";
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.1};
		triggerOnImpact=1;
		deleteParentWhenTriggered=0;
	};
	class ammo_Penetrator_Vorona;
	class FPV_RPG42_AT_Penetrator: ammo_Penetrator_Vorona
	{
		hit=480;
		indirectHit=0;
		indirectHitRange=0;
		warheadName="TandemHEAT";
	};
	class Default;
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
};
class cfgMagazines
{
	class RC_target_confirmer_mag;
	class RC_target_confirmer_AB_mag: RC_target_confirmer_mag
	{
		ammo="FPV_AB_Trigger";
		initSpeed=0;
		scope=2;
		count=1;
		//displayName="MP warhead";
		//displayNameShort="MP warhead";
	};
};
class cfgWeapons
{
	class RC_target_confirmer;
	class RC_target_confirmer_AB: RC_target_confirmer
	{
		displayName="airburst";
		displayNameShort="airburst";
		scope=2;
		canLock=2;
		weaponLockDelay=0;
		reloadTime=1;
		magazineReloadTime=1;
		magazines[]=
		{
			"RC_target_confirmer_AB_mag"
		};
		class Single
		{
			displayName="airburst";
			reloadTime=1;
			burst=1;
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

			textureType="semi";
			recoil="recoil_single_primary_3outof10";
			recoilProne="recoil_single_primary_prone_3outof10";
			aiDispersionCoefY=1.7;
			aiDispersionCoefX=1.4;
			soundBurst=0;
			requiredOpticType=-1;
			aiRateOfFire=2;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=500;
		};
	};
};