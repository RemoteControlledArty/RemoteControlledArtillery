class Air;
class Helicopter: Air
{
	class Turrets;
	class HitPoints;
};
class Helicopter_Base_F: Helicopter
{
	class Turrets: Turrets
	{
		class MainTurret;
	};
	class HitPoints: HitPoints
	{
		class HitHRotor;
		class HitHull;
	};
	class AnimationSources;
	class EventHandlers;
	class ViewOptics;
	class ViewPilot;
	class Components;
};
class drone_base_F: Helicopter_Base_F
{
	features="Randomization: No						<br />Camo selections: 1 - the whole body						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: No						<br />Slingload: No						<br />Cargo proxy indexes: None";
	author="$Sam";
	mapSize=4;
	class SpeechVariants
	{
		class Default
		{
			speechSingular[]=
			{
				"veh_air_UAV_s"
			};
			speechPlural[]=
			{
				"veh_air_UAV_p"
			};
		};
	};
	textSingular="$STR_A3_nameSound_veh_air_UAV_s";
	textPlural="$STR_A3_nameSound_veh_air_UAV_p";
	nameSound="veh_air_UAV_s";
	_generalMacro="drone_base_F";
	editorSubcategory="EdSubcat_Drones";
	scope=0;
	displayName="$STR_A3_CfgVehicles_UAV_01_base0";
	isUav=1;
	uavCameraDriverPos="pip_pilot_pos";
	uavCameraDriverDir="pip_pilot_dir";
	uavCameraGunnerPos="";
	uavCameraGunnerDir="";
	extCameraPosition[]={0,-0.25,-2.3499999};
	extCameraParams[]={0.93000001,10,30,0.25,1,10,30,0,1};
	formationX=10;
	formationZ=10;
	memoryPointTaskMarker="TaskMarker_1_pos";
	memoryPointDriverOptics="pip_pilot_pos";
	driverOpticsModel="\ArmaFPV\lancet_hud.p3d";
	GunnerOpticsModel="\ArmaFPV\lancet_hud.p3d";
	driverForceOptics=1;
	disableInventory=1;
	unitInfoType="RscUnitInfoParachute";
	unitInfoTypeRTD="RscUnitInfoParachute";
	driverWeaponsInfoType="RscOptics_Offroad_01";
	getInRadius=0;
	damageEffect="UAVDestructionEffects";
	damageTexDelay=0.5;
	dustEffect="UAVDust";
	waterEffect="UAVWater";
	washDownDiameter="10.0f";
	washDownStrength="0.25f";
	killFriendlyExpCoef=0.1;
	accuracy=1.5;
	camouflage=0.5;
	audible=0.1;
	armor=0.5;
	cost=20000;
	altFullForce=1000;
	altNoForce=2000;
	LODTurnedIn=-1;
	LODTurnedOut=-1;
	epeImpulseDamageCoef=5;
	fuelExplosionPower=0;
	vehicleClass="Autonomous";
	model="\ArmaFPV\drone.p3d";
	icon="\ArmaFPV\data\drononmap.paa";
	picture="\ArmaFPV\data\drononmap.paa";
	class Reflectors
	{
	};
	startDuration=3;
	maxSpeed=140;
	precision=15;
	steerAheadSimul=0.5;
	steerAheadPlan=0.69999999;
	predictTurnPlan=2;
	predictTurnSimul=1.5;
	liftForceCoef=1;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	bodyFrictionCoef=0.30000001;
	backRotorForceCoef=5;
	fuelCapacity=8.5;
	maxFordingDepth=0.30000001;
	threat[]={0.1,0.1,0.1};
	maxMainRotorDive=0;
	minMainRotorDive=0;
	neutralMainRotorDive=0;
	gearRetracting=0;
	mainRotorSpeed=-7;
	backRotorSpeed=7;
	tailBladeVertical=0;
	radarTargetSize=0.1;
	visualTargetSize=0.1;
	irTarget=0;
	lockDetectionSystem=0;
	incomingMissileDetectionSystem=0;
	weapons[]={};
	magazines[]={};
	irScanRangeMin=0;
	irScanRangeMax=0;
	irScanToEyeFactor=1;
	class TransportItems
	{
	};
	destrType="DestructDefault";
	driverCompartments="Compartment3";
	cargoCompartments[]=
	{
		"Compartment2"
	};
	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=0.1;
		};
		class HitHRotor: HitHRotor
		{
			armor=0.30000001;
		};
	};
	class Damage
	{
		tex[]={};
		mat[]=
		{
			"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01.rvmat",
			"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_damage.rvmat",
			"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_destruct.rvmat"
		};
	};
	class ViewPilot: ViewPilot
	{
		minFov=0.25;
		maxFov=1.25;
		initFov=1;
		initAngleX=0;
		minAngleX=-65;
		maxAngleX=85;
		initAngleY=0;
		minAngleY=-150;
		maxAngleY=150;
	};
	class Viewoptics: ViewOptics
	{
		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=1.25;
		maxFov=1.25;
		initFov=1.25;
		visionMode[]=
		{
			"Normal"
		};
		thermalMode[]={0,1};
	};
	class MFD
	{
	};
	enableManualFire=1;
	reportRemoteTargets=1;
	reportOwnPosition=1;
	class Components: Components
	{
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			class components
			{
			};
		};
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			class components
			{
			};
		};
	};
	class Turrets
	{
	};
	attenuationEffectType="OpenHeliAttenuation";
	soundGetIn[]=
	{
		"",
		1,
		1
	};
	soundGetOut[]=
	{
		"",
		1,
		1,
		50
	};
	soundEnviron[]=
	{
		"",
		0.031622775,
		1
	};
	soundDammage[]=
	{
		"",
		0.56234133,
		1
	};
	soundEngineOnInt[]=
	{
		"ArmaFPV\sounds\quad_start_full_int.wav",
		0.56234133,
		1
	};
	soundEngineOnExt[]=
	{
		"ArmaFPV\sounds\quad_start_full_01.wav",
		0.56234133,
		1,
		200
	};
	soundEngineOffInt[]=
	{
		"ArmaFPV\sounds\quad_stop_full_int.wav",
		0.56234133,
		1
	};
	soundEngineOffExt[]=
	{
		"ArmaFPV\sounds\quad_stop_full_01.wav",
		0.56234133,
		1,
		200
	};
	soundBushCollision1[]=
	{
		"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_1",
		1,
		1,
		100
	};
	soundBushCollision2[]=
	{
		"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_2",
		1,
		1,
		100
	};
	soundBushCollision3[]=
	{
		"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_3",
		1,
		1,
		100
	};
	soundBushCrash[]=
	{
		"soundBushCollision1",
		0.33000001,
		"soundBushCollision2",
		0.33000001,
		"soundBushCollision3",
		0.33000001
	};
	soundWaterCollision1[]=
	{
		"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_1",
		1,
		1,
		100
	};
	soundWaterCollision2[]=
	{
		"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_2",
		1,
		1,
		100
	};
	soundWaterCrashes[]=
	{
		"soundWaterCollision1",
		0.5,
		"soundWaterCollision2",
		0.5
	};
	Crash0[]=
	{
		"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
		1,
		1,
		900
	};
	Crash1[]=
	{
		"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
		1,
		1,
		900
	};
	Crash2[]=
	{
		"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
		1,
		1,
		900
	};
	Crash3[]=
	{
		"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
		1,
		1,
		900
	};
	soundCrashes[]=
	{
		"Crash0",
		0.25,
		"Crash1",
		0.25,
		"Crash2",
		0.25,
		"Crash3",
		0.25
	};
	class Sounds
	{
		class Engine
		{
			sound[]=
			{
				"ArmaFPV\sounds\quad_engine_full_01.wav",
				0.44668359,
				1,
				200
			};
			frequency="rotorSpeed";
			volume="camPos*((rotorSpeed-0.72)*4)";
		};
		class RotorLowOut
		{
			sound[]=
			{
				"A3\Sounds_F\air\Uav_01\blade",
				0.31622776,
				1,
				200
			};
			frequency="rotorSpeed";
			volume="camPos*(0 max (rotorSpeed-0.1))";
			cone[]={1.6,3.1400001,1.6,0.94999999};
		};
		class RotorHighOut
		{
			sound[]=
			{
				"A3\Sounds_F\air\Uav_01\blade_high",
				0.31622776,
				1,
				250
			};
			frequency="rotorSpeed";
			volume="camPos*10*(0 max (rotorThrust-0.9))";
			cone[]={1.6,3.1400001,1.6,0.94999999};
		};
		class EngineIn
		{
			sound[]=
			{
				"ArmaFPV\sounds\quad_engine_full_int.wav",
				0.56234133,
				1
			};
			frequency="rotorSpeed";
			volume="(1-camPos)*((rotorSpeed-0.75)*4)";
		};
		class RotorLowIn
		{
			sound[]=
			{
				"",
				0.56234133,
				1
			};
			frequency="rotorSpeed";
			volume="(1-camPos)*(0 max (rotorSpeed-0.1))";
		};
		class RotorHighIn
		{
			sound[]=
			{
				"",
				0.56234133,
				1
			};
			frequency="rotorSpeed";
			volume="(1-camPos)*3*(rotorThrust-0.9)";
		};
	};
	class Exhausts
	{
		class Exhaust_1
		{
			position="Exhaust_1_pos";
			direction="Exhaust_1_dir";
			effect="ExhaustsEffectDrone";
		};
	};
	class Library
	{
		libTextDesc="$STR_A3_CfgVehicles_UAV_01_base_Library0";
	};
};
class B_Crocus_Base: drone_base_F
{
	author="$Sam";
	class SimpleObject
	{
		eden=1;
		animate[]=
		{
			
			{
				"damagehide",
				0
			},
			
			{
				"rotorimpacthide",
				0
			},
			
			{
				"tailrotorimpacthide",
				0
			},
			
			{
				"propeller1_rotation",
				0
			},
			
			{
				"propeller1_blur_rotation",
				0
			},
			
			{
				"propeller2_rotation",
				0
			},
			
			{
				"propeller2_blur_rotation",
				0
			},
			
			{
				"propeller3_rotation",
				0
			},
			
			{
				"propeller3_blur_rotation",
				0
			},
			
			{
				"propeller4_rotation",
				0
			},
			
			{
				"propeller4_blur_rotation",
				0
			},
			
			{
				"propeller1_hide",
				0
			},
			
			{
				"propeller1_blur_hide",
				0
			},
			
			{
				"propeller2_hide",
				0
			},
			
			{
				"propeller2_blur_hide",
				0
			},
			
			{
				"propeller3_hide",
				0
			},
			
			{
				"propeller3_blur_hide",
				0
			},
			
			{
				"propeller4_hide",
				0
			},
			
			{
				"propeller4_blur_hide",
				0
			},
			
			{
				"mainturret",
				0
			},
			
			{
				"maingun",
				-0.050000001
			}
		};
		hide[]=
		{
			"zasleh",
			"tail rotor blur",
			"main rotor blur",
			"zadni svetlo",
			"clan",
			"podsvit pristroju",
			"poskozeni"
		};
		verticalOffset=0.15000001;
		verticalOffsetWorld=-0.001;
		init="''";
	};
	editorPreview="\ArmaFPV\data\krokus1.jpg";
	_generalMacro="B_Crocus_AT";
	scope=2;
	scopeCurator=2;
	side=1;
	faction="BLU_F";
	crew="B_UAV_AI";
	typicalCargo[]=
	{
		"B_UAV_AI"
	};
	displayName="Crocus AT";
	accuracy=0.5;
	class assembleInfo
	{
		primary=0;
		base="";
		assembleTo="";
		dissasembleTo[]=
		{
			"B_Crocus_AT_Bag"
		};
		displayName="";
	};
	textureList[]=
	{
		"Indep",
		1
	};
	class EventHandlers
	{
		class ArmaFPV
		{
			hit="_this call DB_fnc_fpv_onDestroy";
			init="(_this # 0) spawn DB_fnc_fpv_droneInit;";
		};
	};
};