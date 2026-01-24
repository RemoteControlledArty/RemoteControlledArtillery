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


class RC_Interceptor_Base: Helicopter_Base_F
{
	features="Randomization: No						<br />Camo selections: 1 - the whole body						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: No						<br />Slingload: No						<br />Cargo proxy indexes: None";
	author="$STR_A3_Bohemia_Interactive";
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
	//_generalMacro="UAV_01_base_F";
	editorSubcategory="EdSubcat_Drones";
	scope=0;
	displayName="$STR_A3_CfgVehicles_UAV_01_base0";
	isUav=1;
	uavCameraDriverPos="pip_pilot_pos";
	uavCameraDriverDir="pip_pilot_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	extCameraPosition[]={0,-0.25,-2.3499999};
	extCameraParams[]={0.93000001,10,30,0.25,1,10,30,0,1};
	formationX=10;
	formationZ=10;
	memoryPointTaskMarker="TaskMarker_1_pos";
	memoryPointDriverOptics="pip_pilot_pos";
	driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
	driverForceOptics=1;
	disableInventory=1;
	unitInfoType="RscOptics_AV_pilot";
	unitInfoTypeRTD="RscOptics_AV_pilot";
	getInRadius=0;
	damageEffect="UAVDestructionEffects";
	damageTexDelay=0.5;
	dustEffect="UAVDust";
	waterEffect="UAVWater";
	washDownDiameter="10.0f";
	washDownStrength="0.25f";
	killFriendlyExpCoef=0.1;
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
	model="\A3\Drones_F\Air_F_Gamma\UAV_01\UAV_01_F.p3d";
	icon="\A3\Drones_F\Air_F_Gamma\UAV_01\Data\UI\Map_UAV_01_CA.paa";
	picture="\A3\Drones_F\Air_F_Gamma\UAV_01\Data\UI\UAV_01_CA.paa";
	class Reflectors
	{
	};
	startDuration=3;
	maxSpeed=100;
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
	fuelCapacity=100;
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
	/*
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
	*/
	class Viewoptics: ViewOptics
	{
		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.25;
		maxFov=1.25;
		initFov=0.75;
		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};
	class MFD
	{
	};
	enableManualFire=1;
	reportRemoteTargets=1;
	reportOwnPosition=1;
	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class ManSensorComponent: SensorTemplateMan
				{
					maxTrackableSpeed=15;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=500;
						maxRange=1500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=1000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=35;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			class components
			{
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoMiniMap";
				};
				class UAVDisplay
				{
					componentType="UAVFeedDisplayComponent";
				};
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={800,400,200,1600};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoMiniMap";
				};
				class UAVDisplay
				{
					componentType="UAVFeedDisplayComponent";
				};
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={800,400,200,1600};
					resource="RscCustomInfoSensors";
				};
			};
		};
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
		"A3\Sounds_F\air\Uav_01\quad_start_full_int",
		0.56234133,
		1
	};
	soundEngineOnExt[]=
	{
		"A3\Sounds_F\air\Uav_01\quad_start_full_01",
		0.56234133,
		1,
		200
	};
	soundEngineOffInt[]=
	{
		"A3\Sounds_F\air\Uav_01\quad_stop_full_int",
		0.56234133,
		1
	};
	soundEngineOffExt[]=
	{
		"A3\Sounds_F\air\Uav_01\quad_stop_full_01",
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
				"A3\Sounds_F\air\Uav_01\quad_engine_full_01",
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
				"A3\Sounds_F\air\Uav_01\quad_engine_full_int",
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
				"A3\Sounds_F\air\Uav_01\blade_int",
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
				"A3\Sounds_F\air\Uav_01\blade_high_int",
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
	/*
	hiddenSelections[]=
	{
		"camo"
	};
	*/

	//not base
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_UAV_01_F.jpg";
	_generalMacro="B_UAV_01_F";
	side=1;
	faction="BLU_F";
	crew="B_UAV_AI";
	typicalCargo[]=
	{
		"B_UAV_AI"
	};
	accuracy=0.5;
	class assembleInfo
	{
		primary=1;
		base="";
		assembleTo="";
		displayName="";
		dissasembleTo[]=
		{
			"B_UAV_01_backpack_F"
		};
	};
	hiddenSelectionsTextures[]=
	{
		"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_CO.paa"
	};
	/*
	textureList[]=
	{
		"Blufor",
		1
	};
	*/
};


class RC_Interceptor_B: RC_Interceptor_Base
{
	displayName="Interceptor MP";
	RC_UAVBlurRange=8000;	//no blur

	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=1;
	scopeCurator=0;

	//threat[]={0.1,0.1,0.1};
	camouflage=0.1;			//0.5
	audible=0.1;			//0.1
	radarTargetSize=0.035;	//0.1
	visualTargetSize=0.1;	//0.1

	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	//
	model="\A3\Drones_F\Air_F_Gamma\UAV_01\UAV_01_F.p3d";
	icon="\A3\Drones_F\Air_F_Gamma\UAV_01\Data\UI\Map_UAV_01_CA.paa";
	picture="\A3\Drones_F\Air_F_Gamma\UAV_01\Data\UI\UAV_01_CA.paa";

	//
	altFullForce=0;
	altNoForce=0;
	startDuration=0;
	maxSpeed=400;	//?
	liftForceCoef=0;
	cyclicAsideForceCoef=0;
	cyclicForwardForceCoef=0;
	bodyFrictionCoef=0;
	backRotorForceCoef=0;
	fuelCapacity=0;
	maxMainRotorDive=0;
	minMainRotorDive=0;
	neutralMainRotorDive=0;
	gearRetracting=0;
	mainRotorSpeed=-0;
	backRotorSpeed=0;
	tailBladeVertical=0;

	precision=15;	//?
	steerAheadSimul=0;
	steerAheadPlan=0;
	predictTurnPlan=0;
	predictTurnSimul=0;

	class Components: Components
	{
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={3000,1500,750};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					animDirection="mainGun";
					aimDown=-0.5;

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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
					maxTrackableSpeed=600;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="mainGun";
					aimDown=-0.5;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				class ManSensorComponent: SensorTemplateMan
				{
					maxTrackableSpeed=15;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
	};
	
	/*
	class ViewPilot: ViewPilot
	{
		stabilizedInAxes=3;

		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.025;
		maxFov=1.25;
		initFov=0.9;
		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
	};
	*/

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag"
		};
	};
	*/

	/*
	memoryPointTaskMarker="TaskMarker_1_pos";
	memoryPointDriverOptics="light_l";

	unitInfoType="RC_RscOptics_AV_Heli";
	unitInfoTypeRTD="RC_RscOptics_AV_Heli";
	driverWeaponsInfoType="RscOptics_CAS_01_TGP";

	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	*/

	weapons[]+={"Laserdesignator_pilotCamera"};
	magazines[]+={"Laserbatteries"};

	class Viewoptics: ViewOptics
	{
		initFov=1.5;	//1.25
		maxFov=1.5;		//1.25
		minFov=0.25;

		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};

	class pilotCamera
	{
		controllable=1;				//can turn camera
		pilotOpticsShowCursor=1;	//?
		stabilizedInAxes=3;

		minTurn=-360;
		maxTurn=360;
		initTurn=0;
		minElev=-360;
		maxElev=360;
		initElev=0;
		maxMouseXRotSpeed=0.25;		//0.5
		maxMouseYRotSpeed=0.25;		//0.5

		class OpticsIn
		{
			class Wide
			{
				opticsDisplayName="Cam";

				directionStabilized=1;
				stabilizedInAxes=3;

				minFov=0.02;
				maxFov=1.5;
				initFov=1.5;
				
				initAngleX=0;
				minAngleX=0;
				maxAngleX=0;
				initAngleY=0;
				minAngleY=0;
				maxAngleY=0;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
				gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
			};
			showMiniMapInOptics=1;			//alterative to cTab to follow path
			showUAVViewpInOptics=1;			//remove for optionally manned version
			showSlingLoadManagerInOptics=1;
		};
	};
};


class RC_Interceptor_O: RC_Interceptor_B
{
	side=0;
	crew="O_UAV_AI";
	faction="RemoteControlled_O";
};