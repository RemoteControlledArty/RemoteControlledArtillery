//class UavOptics

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
//gunnerName = "UAV Operator";
//gunnerCompartments = "Compartment1";			//define in asset cfg instead
dontCreateAI = 1;								//1
forceHideGunner = 1;							//1
gunnerForceOptics = 1;							//1
hasGunner = 1;
//hasTerminal = 1;

weapons[] = {"RC_target_confirmer_datalink"};
magazines[] = {"RC_target_confirmer_mag"};

commanding = -1;								//0
primaryGunner = 0;
primaryObserver = 0;


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
gunnerDoor = "";
disableSoundAttenuation = 0;
armorLights = 0.4;
aggregateReflectors[] = {};


//camera
discreteDistanceInitIndex = 2;
discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000};

ace_fcs_DistanceInterval = 5;
ace_fcs_Enabled = 0;
ace_fcs_MaxDistance = 5500;
ace_fcs_MinDistance = 200;

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


/*
driverRightHandAnimName = "drivewheel";
driverRightLegAnimName = "pedal_thrust";
driverLeftHandAnimName = "drivewheel";
driverLeftLegAnimName = "pedal_brake";
driverInAction = "Driver_MBT_03_cannon_F_in";
driverAction = "Driver_MBT_03_cannon_F_out";
LODDriverOpticsIn = 1202;
LODDriverTurnedOut = 0;
*/


//position
//proxyIndex = 1;								//1, 2
proxyType = "CPCargo";							//internal viewpoint: CPDriver  CPCargo  CPGunner  CPCommander
playerPosition = 0;
usePip = 2;										//2

LODOpticsIn = 0;								//0 shows full hull
LODTurnedIn = -1;								//-1 hides hull
LODTurnedOut = -1;								//-1 hides hull


//actions (body animations?)
gunnerAction = "ManActTestDriver";				//Driver_MBT_03_cannon_F_out
gunnerInAction = "ManActTestDriver";			//Driver_MBT_03_cannon_F_in
gunnerLeftHandAnimName = "";					//drivewheel
gunnerRightHandAnimName = "";					//drivewheel
gunnerLeftLegAnimName = "";						//pedal_brake
gunnerRightLegAnimName = "";					//pedal_thrust
gunnerGetInAction = "GetInLow";					//GetInLow  GetInHigh  GetInAMV_cargo
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
memoryPointGunnerOptics = "gunnerview";			//gunnerview
memoryPointGunnerOutOptics = "";				//

//memoryPointsGetInGunner = "pos driver";			//pos cargo
//memoryPointsGetInGunnerDir = "pos driver dir";	//pos cargo dir
//memoryPointsGetInGunnerPrecise = "pos driver";	//pos cargo


/*
class ViewOptics
{
	initAngleX = 0;
	initAngleY = 0;
	initFov = 0.31;
	maxAngleX = 30;
	maxAngleY = 100;
	maxFov = 0.31;
	maxMoveX = 0;
	maxMoveY = 0;
	maxMoveZ = 0;
	minAngleX = -30;
	minAngleY = -100;
	minFov = 0.034;
	minMoveX = 0;
	minMoveY = 0;
	minMoveZ = 0;
	speedZoomMaxFOV = 0;
	speedZoomMaxSpeed = 1e+10;
	thermalMode[] = {2,3};
	visionMode[] = {"Normal","TI"};
};
*/