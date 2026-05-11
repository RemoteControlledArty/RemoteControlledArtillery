class rhsusf_m1165a1_gmv_m2_m240_socom_d;
class RC_HMMWV_Fetch: rhsusf_m1165a1_gmv_m2_m240_socom_d
{
	class Components;
	class HitPoints;
	class ViewOptics;
	class Turrets;
	class CoDriverTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class CargoTurret_04;
	class SAG_Turret;
	class SwingArm_L_Turret;
	class SwingArm_R_Turret;
	class HitBody;
	class HitFuel;
	class HitEngine;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class TextureSources;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_HMMWV_Core: RC_HMMWV_Fetch
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		/*
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		*/

		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargoFuel_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\driverCam1x.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	memoryPointDriverOptics="Light_L";

	author="Ascent";
	//armor=40;
	crewCrashProtection=0;

	//threat[]={0,0,0};
	//cost=0;
	typicalCargo[]={""};
	
	maximumLoad=2500;		//2000
	canHideGunner=1;
	//camouflage=1;	//2
	//audible=2.5;	//5

	maxSpeed=120;			//109
	enginePower=200;		//160
	engineStartSpeed=0.5;	//1.5
	peakTorque=746.25;		//597

	smokeLauncherOnTurret=0;
	smokeLauncherVelocity=6;
	smokeLauncherGrenadeCount=6;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

	weapons[]=
	{
		"RC_target_confirmer_datalink",
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class MFD {};

	class Turrets: Turrets
	{
		//SAG Turret somehow prevents driver cams from working...

		class SAG_Turret: SAG_Turret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_car.hpp"
			gunnerCompartments="Compartment1";
			//primaryObserver=0;
			primaryGunner=0;
			/*
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};

			weapons[]=
			{
				"RC_RHS_M2"
			};
			magazines[]=
			{
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_100rnd_127x99_SLAP_DroneLock_T_R"
			};
			*/
		};
		class CoDriverTurret: CoDriverTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_car.hpp"
			gunnerCompartments="Compartment1";
		};
		/*
		class SwingArm_L_Turret: SwingArm_L_Turret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_car.hpp"
			gunnerCompartments="Compartment1";
			discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};

			weapons[]=
			{
				"RC_RHS_weap_m240_gmv_l"
			};
			magazines[]=
			{
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R"
			};
		};
		*/

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};
		class CargoTurret_04: CargoTurret_04 {};

		class SwingArm_R_Turret: SwingArm_R_Turret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_car.hpp"
			gunnerCompartments="Compartment1";
			discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};

			weapons[]=
			{
				"RC_RHS_weap_m240_gmv_r"
			};
			magazines[]=
			{
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R",
				"RC_RHS_200Rnd_762x51_M240_DroneLock_T_R"
			};
		};

		class DriverTurret
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


			//basics
			gunnerName = "Driver";
			gunnerCompartments = "Compartment1";
			dontCreateAI = 1;								//1
			forceHideGunner = 0;							//1
			gunnerForceOptics = 0;							//1
			hasGunner = 1;
			//hasTerminal = 1;

			commanding = -1;								//0
			primaryGunner = 0;								//0
			//primaryObserver = 1;							//1 can bug viewpoint!


			//can
			allowLauncherIn = 0;
			allowLauncherOut = 0;
			allowTabLock = 1;
			canEject = 1;
			canHideGunner = -1;
			canUseScanners = 1;
			showAllTargets = "2 + 4";
			turretCanSee = 0;
			outGunnerMayFire = 1;							//1 seems to enable smoke launcher
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
			gunnerDoor = "";
			disableSoundAttenuation = 0;
			armorLights = 0.4;
			aggregateReflectors[] = {};


			//camera
			stabilizedInAxes = 0;		//?
			turretFollowFreeLook = 0;	//?


			//angles
			initCamElev = 0;
			initElev = 0;
			initOutElev = 0;
			initOutTurn = 0;
			initTurn = 0;

			maxHorizontalRotSpeed = 0;
			maxVerticalRotSpeed = 0;

			maxCamElev = 0;
			maxElev = 0;
			maxOutElev = 0;
			maxOutTurn = 0;
			maxTurn = 0;

			minCamElev = 0;
			minElev = 0;
			minOutElev = 0;	
			minOutTurn = 0;
			minTurn = 0;


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

			missileEnd = "konec rakety";
			missileBeg = "spice rakety";


			//memory points
			memoryPointGun = "kulas";						//gun_muzzle
			//memoryPointGunnerOptics = "gunnerview";			//gunnerview
			memoryPointGunnerOutOptics = "";				//

			memoryPointsGetInGunner = "pos driver";			//pos cargo
			memoryPointsGetInGunnerDir = "pos driver dir";	//pos cargo dir
			memoryPointsGetInGunnerPrecise = "pos driver";	//pos cargo

			#include "\Remote_Controlled_Artillery\includes_cfg\panels_car.hpp"
			//#include "\Remote_Controlled_Artillery\includes_cfg\DriverTurret.hpp"

			primaryObserver = 1;
			memoryPointGunnerOptics = "Light_L";			//P svetlo

			gunnerAction = "RHS_HMMWV_Driver";				//Driver_MBT_03_cannon_F_out
			gunnerInAction = "RHS_HMMWV_Driver";							//Driver_MBT_03_cannon_F_in
			gunnerLeftHandAnimName = "drivewheel";			//drivewheel
			gunnerRightHandAnimName = "drivewheel";			//drivewheel
			gunnerLeftLegAnimName = "";						//pedal_brake
			gunnerRightLegAnimName = "pedal_thrust";		//pedal_thrust

			//gunnerCompartments="Compartment1";
			//gunnerOpticsModel="";
			//turretInfoType="";

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

			weapons[]=
			{
				"RC_target_confirmer_datalink",
				"TruckHorn",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_target_confirmer_mag",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};

	class TextureSources: TextureSources
	{
		class desert
		{
			displayName="Desert";

			textures[]=
			{
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_Ext_CO.paa",
				"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa",
				"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa",
				"rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa",
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_CO.paa",
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_SAG_CO.paa",
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_des_co.paa"
			};
			factions[]=
			{
				/*
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
				*/
			};
			decals[]={8};
		};
		class woodland
		{
			displayName="Woodland";

			textures[]=
			{
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_Ext_WD_CO.paa",
				"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa",
				"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa",
				"rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa",
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_WD_CO.paa",
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_SAG_WD_CO.paa",
				"rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_wd_co.paa"
			};
			factions[]=
			{
				/*
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
				*/
			};
			decals[]={8};
		};
	};
	/*
	textureList[]=
	{
		"Green",
		1
	};
	*/

	class HitPoints: HitPoints
	{
		class HitBody: HitBody
		{
			explosionShielding=1;	//1.5
		};
		class HitFuel: HitFuel
		{
			armor=1;			//0.5
			passThrough=0.15;	//0.2
		};
		class HitEngine: HitEngine
		{
			armor=1;			//0.5
			passThrough=0.15;	//0.2
		};
		class HitLFWheel: HitLFWheel
		{
			armor=-300;
			explosionShielding=1;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-300;
			explosionShielding=1;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-300;
			explosionShielding=1;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-300;
			explosionShielding=1;
		};
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
					typeRecognitionDistance=8000;

					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=400;

					class AirTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="";
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
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
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";

			class Components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={4000,2000,400};
					resource="RscCustomInfoSensors";
				};
				class UAVFeedDisplay
				{
					componentType="UAVFeedDisplayComponent";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoMiniMap";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="SensorDisplay";

			class Components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={400,2000,4000};
					resource="RscCustomInfoSensors";
				};
				class UAVFeedDisplay
				{
					componentType="UAVFeedDisplayComponent";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoMiniMap";
				};
			};
		};
	};
};


class RC_HMMWV_Base: RC_HMMWV_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CommanderIsDriverEH.hpp"
		};
	};

	class UserActions
	{
		class DriveControlsCommander
		{
			displayName="Take Drive Controls";
			position="pos commander";
			radius=15;
			showwindow=0;
			onlyforplayer=1;
			shortcut="";

			condition="player isEqualTo (commander this);";
			statement="[this, RC_fnc_RC_TakeControlCommanderServer] remoteExec ['call', 2]";
		};
		class SwitchTurret
		{
			displayName="Switch turret";
			position="";
			radius=4;
			showwindow=0;
			onlyForplayer=0;
			shortcut="curatorMoveCamTo";

			condition="(this turretUnit [0]) isEqualTo (call rhs_fnc_findPlayer) OR (this turretUnit [2]) isEqualTo (call rhs_fnc_findPlayer);";
			statement="[this,'SWITCH_WEAPON'] call rhs_fnc_m1165_turret";
		};
	};

	displayName="RC HMMWV";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Car_subcat";

	isUav=1;
	driverForceOptics=1;
	vehicleClass="Autonomous";
	driverCompartments="Compartment4";
	textPlural="UGVs";
	textSingular="UGV";

	uavCameraDriverPos="Light_L";
	uavCameraDriverDir="Light_L";
};
class RC_HMMWV_D: RC_HMMWV_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	faction="RemoteControlled_B";
	side=1;
	crew="B_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsB_RHS.hpp"
};
class RC_HMMWV_D_O: RC_HMMWV_D
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsO_RHS.hpp"
};
class RC_HMMWV_D_I: RC_HMMWV_D
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


class RC_HMMWV_WD: RC_HMMWV_D
{
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_Ext_WD_CO.paa",
		"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa",
		"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa",
		"rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa",
		"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_WD_CO.paa",
		"rhsusf\addons\rhsusf_m1165\data\rhsusf_M1165A1_GMV_SAG_WD_CO.paa",
		"rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_wd_co.paa"
	};
};
class RC_HMMWV_WD_O: RC_HMMWV_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsO_RHS.hpp"
};
class RC_HMMWV_WD_I: RC_HMMWV_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


/*
class RC_Offroad_RCIMV_cUAS: RC_Offroad_RCIMV
{
	class EventHandlers: EventHandlers
	{
		init="if (!isServer) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static_HMG_manned', side _this] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
    			((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="RC Offroad + 12.7mm C-UAS";
};
class RC_Offroad_RCIMV_cUAS_O: RC_Offroad_RCIMV_cUAS
{
	side=0;
	crew="O_UAV_AI";
};
class RC_Offroad_RCIMV_cUAS_I: RC_Offroad_RCIMV_cUAS
{
	side=2;
	crew="I_UAV_AI";
};
*/


/*
class RC_Offroad_cUAS_Base: RC_Offroad_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_600m.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
	};

	editorSubcategory="RC_AntiDrone_subcat";
};


class RC_Offroad_cUAS: RC_Offroad_cUAS_Base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isServer) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static', west] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
				((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="Offroad C-UAS/FS 20mm";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="B_Soldier_UAV_F";		//crew="";	//dontCreateAI=1;	//doesnt fully work
};
class RC_Offroad_cUAS_HMG: RC_Offroad_cUAS
{
	class EventHandlers: EventHandlers
	{
		init="if (!isServer) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static_HMG', west] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
    			((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="Offroad C-UAS/FS 12.7mm";
};
*/