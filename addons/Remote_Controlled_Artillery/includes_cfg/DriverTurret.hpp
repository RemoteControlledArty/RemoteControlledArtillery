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
gunnerName = "Driver";
gunnerCompartments = "Compartment1";
dontCreateAI = 1;								//1
forceHideGunner = 0;							//1
gunnerForceOptics = 0;							//1
hasGunner = 1;
//hasTerminal = 1;

commanding = -1;								//0
primaryGunner = 0;								//0
//primaryObserver = 1;							//1


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