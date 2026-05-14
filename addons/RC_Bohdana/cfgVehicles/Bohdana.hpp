class frtz_2S22_bogdana_maz;
class RC_Bohdana_Fetch: frtz_2S22_bogdana_maz
{
	class EventHandlers;
	class UserActions;
	class Components;

	class Turrets;
	class MainTurret;
	class ViewOptics;

	class AnimationSources;

	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_validTurret[]={0}; //turret array pos in class turrets
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=2.3;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=7;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
    ace_artillerytables_showGunLaying=0;
    ace_artillerytables_applyCorrections=0; //prevents ace air resistance completely messing up the calculatable firing soltion
	//ace_artillerytables_showRangetable=1;

	scope=0;
	scopeCurator=0;
};
class RC_Bohdana_Core: RC_Bohdana_Fetch
{
	class EventHandlers: EventHandlers
	{
		class RC_GuidedTriggerTime
		{
			#include "\Remote_Controlled_Artillery\includes_script\GuidedTriggerTimeEH.hpp"
		};
		class RC_ETA
		{
			#include "\Remote_Controlled_Artillery\includes_script\ETA_EH.hpp"
		};
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\driverCam1x.hpp"
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	lockDetectionSystem="2+4+8";
	showAllTargets="2 + 4";
	memoryPointDriverOptics="Light_L";

	author="Ascent";

	commanding=1;
	crewCrashProtection=0;

	antiRollbarForceCoef=10;	//6
	antiRollbarForceLimit=5;	//5
	antiRollbarSpeedMax=100;	//60
	antiRollbarSpeedMin=0;		//0

	/*
	smokeLauncherVelocity=5;
	smokeLauncherGrenadeCount=8;
	smokeLauncherAngle=360;
	*/

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};
	class ViewPilot
	{
		initAngleX = -10;
		initAngleY = 0;
		initFov = 0.9;
		maxAngleX = 85;
		maxAngleY = 150;
		maxFov = 1.25;
		maxMoveX = 0.2;
		maxMoveY = 0.1;
		maxMoveZ = 0.2;
		minAngleX = -65;
		minAngleY = -150;
		minFov = 0.25;
		minMoveX = -0.2;
		minMoveY = -0.1;
		minMoveZ = -0.1;
		speedZoomMaxFOV = 0;
		speedZoomMaxSpeed = 1e+10;
	};
};


class RC_Bohdana_Base: RC_Bohdana_Core
{
	editorSubcategory="RC_Howitzer_subcat";

	maxSpeed=100;
	normalSpeedForwardCoef=0.8;
	enginePower=257.5;
	peakTorque=1475;
	engineStartSpeed=0.5;

	weapons[]=
	{
		"RC_target_confirmer_datalink",
		//"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag",
		//"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
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
					typeRecognitionDistance=45000;

					class AirTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			commanding=3;
			allowTabLock=1;
			canUseScanners=1;
			
			//minElev=-;
			maxElev=87;
			lockWhenVehicleSpeed=-1;
			stabilizedInAxes=3;
			//elevationMode=3;
			startEngine=0;

			weapons[]=
			{
				"RC_2S22_155mm_V4"
			};
			magazines[]=
			{
				//2s22_mag_155mm_of
				"RC_15Rnd_2S22_155mm_Mo_shells",
				"RC_4Rnd_2S22_155mm_Mo_HEAB",
				"RC_5Rnd_2S22_155mm_Mo_MultiGuided",
				"RC_2Rnd_2S22_155mm_Mo_Cluster",
				"RC_20Rnd_2S22_155mm_Mo_smoke",
				"RC_9Rnd_2S22_155mm_Mo_AT_mine",
				"RC_9Rnd_2S22_155mm_Mo_mine",
				"RC_6Rnd_2S22_155mm_Mo_Illum"
			};

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
					
					minAngleX=-30;
					maxAngleX=30;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.125;
					minFov=0.0125;
					maxFov=0.9;
				};
			};
			turretInfoType="RscWeaponRangeArtilleryAuto";
		};
	};

	class AnimationSources: AnimationSources
	{
		class recoil
		{
			source="reload";
			weapon="RC_2S22_155mm_V4";
		};
	};
};


class RC_Bohdana_UV_Base: RC_Bohdana_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	displayName="RC 2S22 Bohdana";
	
	driverCompartments="Compartment2";
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	driverForceOptics=1;
	forceHideDriver=1;

	uavCameraDriverPos="Light_L";
	uavCameraDriverDir="Light_L";
	uavCameraGunnerPos="gunnerview";
	uavCameraGunnerDir="gunnerview";

	class Components: Components
	{
		#include "\RC_Bohdana\includes_cfg\panels_bohdana_UV.hpp"
	};
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class Components: Components
			{
				#include "\RC_Bohdana\includes_cfg\panels_bohdana_UV.hpp"
			};

			//cannot yet be driven when RCing gunner from commander seat
			gunnerCompartments="Compartment3";
			dontCreateAI=0;
			gunnerForceOptics=1;
			forceHideGunner=1;
		};
	};
};
class RC_Bohdana_B: RC_Bohdana_UV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};
class RC_Bohdana_O: RC_Bohdana_UV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};
class RC_Bohdana_I: RC_Bohdana_UV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"
};


/*
class RC_Bohdana_manned_Base: RC_Bohdana_Base
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\GunnerOrCommanderIsDriverEH.hpp"
		};
	};

	displayName="2S22 Bohdana";
	
	driverCompartments="Compartment2";
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	driverForceOptics=1;
	forceHideDriver=1;

	uavCameraDriverPos="Light_L";
	uavCameraDriverDir="Light_L";

	class Components: Components
	{
		#include "\RC_Bohdana\includes_cfg\panels_bohdana_manned.hpp"
	};
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class Components: Components
			{
				#include "\RC_Bohdana\includes_cfg\panels_bohdana_manned.hpp"
			};

			primaryGunner = 0;								//0 results in elev being calculatable, 1 results in gunner being RCable and buggable
			primaryObserver = 0;							//1 bugs viewpoint to below the truck

			memoryPointGunnerOptics = "gunnerview";			//P svetlo

			gunnerAction = "UA_Driver_BogdanaMAZ_In";		//UA_Driver_BogdanaMAZ_In
			gunnerInAction = "";							//
			gunnerLeftHandAnimName = "DrivingWheel";		//drivewheel
			gunnerRightHandAnimName = "DrivingWheel";		//drivewheel
			gunnerLeftLegAnimName = "pedal_brake";			//pedal_brake
			gunnerRightLegAnimName = "pedal_thrust";		//pedal_thrust

			//basics
			gunnerName = "Driver/Gunner";
			gunnerCompartments = "Compartment1";
			dontCreateAI = 1;								//1
			commanding = 2;									//-1

			//can
			allowTabLock = 1;
			canUseScanners = 1;
			showAllTargets = "2 + 4";
			startEngine = 0;
			lockWhenVehicleSpeed = -1;
			//isCopilot = 0;


			//position
			proxyIndex = 1;									//1, 2
			proxyType = "CPDriver";							//internal viewpoint: CPDriver  CPCargo  CPGunner  CPCommander
			playerPosition = 0;
			usePip = 2;										//2

			LODOpticsIn = 0;								//0 shows full hull
			LODTurnedIn = -1;								//-1 hides hull
			LODTurnedOut = -1;								//-1 hides hull


			//actions (body animations?)
			gunnerGetInAction = "GetInLow";					//GetInLow  GetInHigh
			gunnerGetOutAction = "GetOutLow";				//GetOutLow  GetOutHigh

			//personTurretAction = "vehicle_turnout_1";		//Leo NA
			//cargoIsCoDriver[] = {0};						//?
			//cargoPreciseGetInOut[]={0};					//?


			memoryPointsGetInGunner = "pos driver";			//pos cargo
			memoryPointsGetInGunnerDir = "pos driver dir";	//pos cargo dir
			memoryPointsGetInGunnerPrecise = "pos driver";	//pos cargo


			class ViewGunner
			{
				initAngleX = -10;
				initAngleY = 0;
				initFov = 0.9;
				maxAngleX = 85;
				maxAngleY = 150;
				maxFov = 1.25;
				maxMoveX = 0.075;
				maxMoveY = 0.025;
				maxMoveZ = 0.1;
				minAngleX = -75;
				minAngleY = -150;
				minFov = 0.25;
				minMoveX = 0;
				minMoveY = 0;
				minMoveZ = 0;
				speedZoomMaxFOV = 0;
				speedZoomMaxSpeed = 1e+10;
			};
		};
		class AdvisorTurret
		{
			//required classes
			class ViewGunner
			{
				initAngleX = -5;
				initAngleY = 0;
				initFov = 0.9;
				maxAngleX = 85;
				maxAngleY = 150;
				maxFov = 1.25;
				maxMoveX = 0.075;
				maxMoveY = 0.025;
				maxMoveZ = 0.1;
				minAngleX = -65;
				minAngleY = -150;
				minFov = 0.25;
				minMoveX = -0.075;
				minMoveY = -0.075;
				minMoveZ = -0.075;
				speedZoomMaxFOV = 0;
				speedZoomMaxSpeed = 1e+10;
			};
			class Reflectors {};
			class Hitpoints {};
			class Turrets {};
			class TurretSpec {showHeadPhones = 0;};
			class TurnIn {turnOffset = 0;};
			class TurnOut {turnOffset = 0;};
			//class dynamicViewLimits { MainTurret[] = {-135,75}; };
			//class GunClouds {};
			//class GunFire {};
			//class MGunClouds {};

			class Components: Components
			{
				#include "\RC_Bohdana\includes_cfg\panels_bohdana_manned.hpp"
			};
			class OpticsIn
			{
				class Driver
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

					minAngleX=-30;	//?
					maxAngleX=30;	//?
					minAngleY=-100;	//?
					maxAngleY=100;	//?

					initFov=1;
					minFov=0.25;
					maxFov=1;
				};
			};

			gunnerName = "UAV Operator";
			dontCreateAI = 1;
			gunnerCompartments="Compartment1";
			turretInfoType = "";
			forceHideGunner = 1;
			gunnerForceOptics = 0;

			weapons[]=
			{
				"RC_target_confirmer_datalink",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_target_confirmer_mag",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			commanding = -1;
			primaryGunner = 0;
			primaryObserver = 0;
			hasGunner=1;


			//can
			allowLauncherIn = 0;
			allowLauncherOut = 0;
			allowTabLock = 1;
			canEject = 1;
			canHideGunner = -1;
			canUseScanners = 1;
			showAllTargets = "2 + 4";
			turretCanSee = 0;
			outGunnerMayFire = 0;
			inGunnerMayFire = 1;


			//behavior
			startEngine = 0;
			lockWhenVehicleSpeed = -1;
			lockWhenDriverOut = 0;
			castGunnerShadow = 0;
			isCopilot = 0;
			hideWeaponsGunner = 1;
			slingLoadOperator = 0;
			showHMD = 0;
			showCrewAim = 0;
			forceNVG = 0;
			ejectDeadGunner = 0;	//?


			//sound
			soundElevation[] = {"",0.00316228,0.5};
			soundServo[] = {"",0.00316228,0.5};
			soundServoVertical[] = {"",0.00316228,0.5};


			//rest
			viewGunnerInExternal = 1;
			viewGunnerShadow = 1;
			viewGunnerShadowAmb = 0.5;
			viewGunnerShadowDiff = 0.05;
			primary = 1;
			preciseGetInOut = 0;
			gunnerUsesPilotView = 0;
			gunnerType = "";
			gunnerOutOpticsShowCursor = 0;
			gunnerOutOpticsModel = "";
			gunnerOutOpticsEffect[] = {};
			gunnerOutOpticsColor[] = {0,0,0,1};
			gunnerOutForceOptics = 0;
			gunnerOutFireAlsoInInternalCamera = 1;
			gunnerFireAlsoInInternalCamera = 1;
			gunnerOpticsShowCursor = 0;
			gunnerOpticsEffect[] = {};
			gunnerOpticsColor[] = {0,0,0,1};
			gunnerHasFlares = 1;
			disableSoundAttenuation = 0;
			armorLights = 0.4;
			aggregateReflectors[] = {};


			//camera
			stabilizedInAxes = 3;
			turretFollowFreeLook = 0;


			//angles
			initCamElev = 0;
			initElev = 0;
			initOutElev = 0;
			initOutTurn = 0;
			initTurn = 0;

			maxHorizontalRotSpeed = 1.8;
			maxVerticalRotSpeed = 1.8;

			maxCamElev = 90;
			maxElev = 60;
			maxOutElev = 40;
			maxOutTurn = 120;
			maxTurn = 360;

			minCamElev = -90;
			minElev = -25;
			minOutElev = -20;	
			minOutTurn = -120;
			minTurn = -360;


			//position
			proxyIndex=1;
			proxyType = "CPGunner";							//internal viewpoint: CPDriver  CPCargo  CPGunner  CPCommander
			playerPosition = 0;
			usePip = 1;

			LODOpticsIn = 0;								//0 shows full hull, -1 hides hull
			LODTurnedIn = 0;
			LODTurnedOut = 0;


			//memory points
			//memoryPointGun = "kulas";						//gun_muzzle
			memoryPointGunnerOptics = "Light_L";			//gunnerview
			memoryPointGunnerOutOptics = "";				//
			memoryPointsGetInGunner = "Pos Gunner";			//pos cargo
			memoryPointsGetInGunnerDir = "Pos Gunner Dir";	//pos cargo dir
			memoryPointsGetInGunnerPrecise = "";	//pos cargo


			//actions (body animations?)
			gunnerAction = "passenger_apc_narrow_generic01";
			gunnerInAction = "passenger_apc_narrow_generic01";
			gunnerDoor = "door_2_1";
			gunnerLeftHandAnimName = "";
			gunnerRightHandAnimName = "";
			gunnerLeftLegAnimName = "";
			gunnerRightLegAnimName = "";
			gunnerGetInAction = "GetInLow";					//GetInLow  GetInHigh
			gunnerGetOutAction = "GetOutLow";				//GetOutLow  GetOutHigh


			//animation sources
			animationSourceBody = "";						//crewmanTurret
			animationSourceCamElev = "camElev";
			animationSourceElevation = "";					//commanderelev
			animationSourceGun = "";						//crewmanGun
			animationSourceHatch = "";						//hatchDriver

			selectionFireAnim = "zasleh";					//zasleh_1

			body = "";										//crewmanTurret
			gun = "";										//crewmanGun
			gunBeg = "";
			gunEnd = "";

			missileEnd = "";
			missileBeg = "";
		};
	};
};
/*/


class RC_Bohdana_manned_Base: RC_Bohdana_Base
{
	displayName="2S22 Bohdana";
	//dontCreateAI=1;

	class Components: Components
	{
		#include "\RC_Bohdana\includes_cfg\panels_bohdana_manned.hpp"
	};
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//dontCreateAI=1;
			gunnerCompartments="Compartment1";

			class Components: Components
			{
				#include "\RC_Bohdana\includes_cfg\panels_bohdana_manned.hpp"
			};
			class ViewGunner
			{
				initAngleX = -5;
				initAngleY = 0;
				initFov = 0.9;
				maxAngleX = 85;
				maxAngleY = 150;
				maxFov = 1.25;
				maxMoveX = 0.075;
				maxMoveY = 0.025;
				maxMoveZ = 0.1;
				minAngleX = -75;
				minAngleY = -150;
				minFov = 0.25;
				minMoveX = 0;
				minMoveY = 0;
				minMoveZ = 0;
				speedZoomMaxFOV = 0;
				speedZoomMaxSpeed = 1e+10;
			};
		};
	};
};


class RC_Bohdana_manned_B: RC_Bohdana_manned_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};
class RC_Bohdana_manned_O: RC_Bohdana_manned_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	//#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};
class RC_Bohdana_manned_I: RC_Bohdana_manned_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"
};