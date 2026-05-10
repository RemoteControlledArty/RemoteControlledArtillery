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
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=2.3;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=7;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality

	scope=0;
	scopeCurator=0;
};
class RC_Bohdana_Core: RC_Bohdana_Fetch
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\driverCam1x.hpp"
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	lockDetectionSystem="2+4+8";
	memoryPointDriverOptics="Light_L";

	author="Ascent";

	commanding=1;
	crewCrashProtection=0;

	/*
	smokeLauncherVelocity=5;
	smokeLauncherGrenadeCount=8;
	smokeLauncherAngle=360;
	*/

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};
};


class RC_Bohdana_Base: RC_Bohdana_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
	
	editorSubcategory="RC_Howitzer_subcat";

	maxSpeed=100;
	normalSpeedForwardCoef=0.8;
	enginePower=257.5;
	peakTorque=1475;
	engineStartSpeed=0.5;

	weapons[]=
	{
		"RC_target_confirmer_datalink",
		"RC_APS_W",
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
			dontCreateAI=1;
			commanding=3;

			//minElev=-;
			maxElev=87;
			lockWhenVehicleSpeed=-1;
			//elevationMode=3;

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
			turretInfoType="RC_RscArtyAuto";
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


class RC_Bohdana_manned_Base: RC_Bohdana_Base
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
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

			memoryPointGunnerOptics = "gunnerview";			//P svetlo

			gunnerAction = "UA_Driver_BogdanaMAZ_In";		//UA_Driver_BogdanaMAZ_In
			gunnerInAction = "";							//
			gunnerLeftHandAnimName = "DrivingWheel";		//drivewheel
			gunnerRightHandAnimName = "DrivingWheel";		//drivewheel
			gunnerLeftLegAnimName = "pedal_brake";			//pedal_brake
			gunnerRightLegAnimName = "pedal_thrust";		//pedal_thrust

			//basics
			gunnerName = "Driver";
			gunnerCompartments = "Compartment1";
			dontCreateAI = 1;								//1
			commanding = 2;									//-1
			//primaryGunner = 0;								//0
			//primaryObserver = 1;							//1

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
		};
	};

	displayName="2S22 Bohdana";
	driverCompartments="Compartment1";
};
class RC_Bohdana_manned_B: RC_Bohdana_manned_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};
class RC_Bohdana_manned_O: RC_Bohdana_manned_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};
class RC_Bohdana_manned_I: RC_Bohdana_manned_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"
};


class RC_Bohdana_UV_Base: RC_Bohdana_Base
{
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
			
			lockWhenVehicleSpeed=-1;
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