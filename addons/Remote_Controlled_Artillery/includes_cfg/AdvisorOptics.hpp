//class UavOptics
class OpticsIn
{
	class Wide: RCWSOptics
	{
		initAngleX=0;
		minAngleX=-30;
		maxAngleX=30;
		initAngleY=0;
		minAngleY=-100;
		maxAngleY=100;

		initFov=0.9;
		minFov=0.02;
		maxFov=0.9;
		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0};
		gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
		gunnerOpticsEffect[]={};
	};
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
	minAngleX = -65;
	minAngleY = -150;
	minFov = 0.25;
	minMoveX = -0.075;
	minMoveY = -0.075;
	minMoveZ = -0.075;
	speedZoomMaxFOV = 0;
	speedZoomMaxSpeed = 1e+10;
};
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
class Reflectors {};
class Hitpoints {};
class Turrets {};
class TurretSpec {showHeadPhones = 0;};
class TurnIn {turnOffset = 0;};
class TurnOut {turnOffset = 0;};

proxyIndex = 1;								//1, 2
proxyType = "CPCargo";						//CPCargo  CPGunner

animationSourceBody = "";					//crewmanTurret
animationSourceCamElev = "camElev";
animationSourceElevation = "";				//commanderelev
animationSourceGun = "";					//crewmanGun
animationSourceHatch = "hatchGunner";		//hatchCrewman

body = "";									//crewmanTurret
gun = "";									//crewmanGun
gunBeg = "";
gunEnd = "";
gunnerAction = "Gunner_MBT_03_cannon_F_out";//ManActTestDriver  Driver_APC_tracked_02_F_in
gunnerCompartments = "Compartment1";
hasGunner = 1;

gunnerGetInAction = "GetInLow";				//EF_Crew_AAV9
gunnerGetOutAction = "GetOutLow";			//GetOutHigh

gunnerInAction = "Gunner_MBT_03_cannon_F_in";//ManActTestDriver  EF_Crew_AAV9
gunnerLeftHandAnimName = "";				//com_turret_control
gunnerLeftLegAnimName = "";
gunnerName = "UAV Operator";

//personTurretAction = "vehicle_turnout_1";	//Leo NA
playerPosition = 0;

usePip = 2;									//2
selectionFireAnim = "zasleh";				//zasleh_1
showAllTargets = 0;

LODOpticsIn = 0;	//Leo NA
LODTurnedIn = -1;	//-1  1204
LODTurnedOut = -1;	//-1  1

gunnerForceOptics = 1;
memoryPointGun = "kulas";					//gun_muzzle
memoryPointGunnerOptics = "gunnerview";		//crewmanview
memoryPointGunnerOutOptics = "";			//crewmanview
memoryPointsGetInGunner = "pos cargo";			//pos commander
memoryPointsGetInGunnerDir = "pos cargo dir";	//pos commander dir
memoryPointsGetInGunnerPrecise = "";			//""

commanding = -1;	//0
dontCreateAI = 1;	//1

gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";	//""
turretInfoType="RscOptics_APC_Wheeled_01_gunner";

//rest
aggregateReflectors[] = {};
allowLauncherIn = 0;
allowLauncherOut = 0;
allowTabLock = 1;
animationSourceStickX = "com_turret_control_x";
animationSourceStickY = "com_turret_control_y";
armorLights = 0.4;
canEject = 1;
canHideGunner = -1;
canUseScanners = 1;
castGunnerShadow = 0;
disableSoundAttenuation = 0;
ejectDeadGunner = 0;
forceHideGunner = 0;
forceNVG = 0;
gunnerDoor = "";
gunnerFireAlsoInInternalCamera = 1;
gunnerHasFlares = 1;
gunnerOpticsColor[] = {0,0,0,1};
gunnerOpticsEffect[] = {};
gunnerOpticsShowCursor = 0;
gunnerOutFireAlsoInInternalCamera = 1;
gunnerOutForceOptics = 0;
gunnerOutOpticsColor[] = {0,0,0,1};
gunnerOutOpticsEffect[] = {};
gunnerOutOpticsModel = "";
gunnerOutOpticsShowCursor = 0;	
gunnerRightHandAnimName = "";
gunnerRightLegAnimName = "";
gunnerType = "";
gunnerUsesPilotView = 0;
hideWeaponsGunner = 1;
inGunnerMayFire = 1;
initCamElev = 0;
initElev = 0;
initOutElev = 0;
initOutTurn = 0;
initTurn = 0;
isCopilot = 0;
isPersonTurret = 0;
lockWhenDriverOut = 0;
lockWhenVehicleSpeed = -1;
magazines[] = {};
maxCamElev = 90;
maxElev = 60;
maxHorizontalRotSpeed = 1.8;
maxOutElev = 40;
maxOutTurn = 120;
maxTurn = 360;
maxVerticalRotSpeed = 1.8;
minCamElev = -90;
minElev = -25;
minOutElev = -20;	
minOutTurn = -120;
minTurn = -360;
missileBeg = "spice rakety";
missileEnd = "konec rakety";
outGunnerMayFire = 0;
preciseGetInOut = 0;
primary = 1;
primaryGunner = 0;
primaryObserver = 0;
showCrewAim = 1;
showHMD = 0;
slingLoadOperator = 0;
soundElevation[] = {"",0.00316228,1};
soundServo[] = {"A3\sounds_f\dummysound",0.01,1,10};
soundServoVertical[] = {"A3\sounds_f\dummysound",0.01,1,10};
stabilizedInAxes = 3;
startEngine = 0;
turretCanSee = 0;
turretFollowFreeLook = 2;
viewGunnerInExternal = 0;
viewGunnerShadow = 1;
viewGunnerShadowAmb = 1;
viewGunnerShadowDiff = 1;
weapons[] = {};