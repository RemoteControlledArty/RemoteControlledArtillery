/*
    INCLUDE INHERITED ENTRIES: true
    SHOW CLASSES ONLY: false
    UNLOCALIZED TEXT: true
    CONFIG PATH: bin\config.bin/CfgVehicles/LT_01_scout_base_F/Turrets
    SOURCE ADD-ON(S): A3_Armor_F_Tank_LT_01
*/

class Turrets
{
    class MainTurret
    {
        gunBeg = "";
        gunEnd = "";
        memoryPointGunnerOptics = "gunnerview";
        viewGunnerInExternal = 1;
        class Turrets
        {
        };
        gunnerName = $STR_POSITION_COMMANDER;
        proxyType = "CPCommander";
        commanding = 2;
        primaryGunner = 1;
        primaryObserver = 1;
        body = "obsTurret";
        gun = "obsGun";
        animationSourceBody = "obsTurret";
        animationSourceGun = "obsGun";
        animationSourceElevation = "obsElevation";
        weapons[] = {"Laserdesignator_vehicle","SmokeLauncher"};
        magazines[] = {"Laserbatteries","SmokeLauncherMag"};
        soundServo[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03",0.177828,1,10};
        soundServoVertical[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03",0.177828,1,10};
        soundElevation[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03_elevation",0.316228,1,10};
        gunnerAction = "Commander_LT_01_AT_F_out";
        gunnerInAction = "Commander_LT_01_AT_F_in";
        animationSourceHatch = "hatchcommander";
        personTurretAction = "vehicle_turnout_1";
        isPersonTurret = 0;
        usePip = 1;
        gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Optics_Commander_01_F.p3d";
        Laser = 1;
        turretInfoType = "RscOptics_Strider_commander";
        gunnerForceOptics = 1;
        forceHideGunner = 1;
        startEngine = 0;
        minElev = -18;
        maxElev = 40;
        maxOutElev = 40;
        minOutElev = -24;
        minCamElev = -90;
        maxCamElev = 90;
        memoryPointsGetInGunner = "pos commander";
        memoryPointsGetInGunnerDir = "pos commander dir";
        gunnerGetInAction = "GetInLow";
        gunnerGetOutAction = "GetOutLow";
        animationSourceStickX = "turret_control_x";
        animationSourceStickY = "turret_control_y";
        gunnerRightHandAnimName = "turret_control";
        LODOpticsIn = 0;
        viewGunnerShadowAmb = 0.5;
        viewGunnerShadowDiff = 0.05;
        class ViewOptics
        {
            initAngleX = 0;
            minAngleX = -30;
            maxAngleX = 30;
            initAngleY = 0;
            minAngleY = -100;
            maxAngleY = 100;
            initFov = 0.155;
            minFov = 0.034;
            maxFov = 0.155;
            visionMode[] = {"Normal","NVG","Ti"};
            thermalMode[] = {2,3};
            minMoveX = 0;
            maxMoveX = 0;
            minMoveY = 0;
            maxMoveY = 0;
            minMoveZ = 0;
            maxMoveZ = 0;
            speedZoomMaxSpeed = 1e+010;
            speedZoomMaxFOV = 0;
        };
        class ViewGunner
        {
            initAngleX = -3;
            initAngleY = 0;
            initFov = 0.9;
            minFov = 0.25;
            maxFov = 1.25;
            minAngleX = -65;
            maxAngleX = 85;
            minAngleY = -150;
            maxAngleY = 150;
            minMoveX = -0.075;
            maxMoveX = 0.075;
            minMoveY = -0.075;
            maxMoveY = 0.075;
            minMoveZ = -0.075;
            maxMoveZ = 0.1;
            continuous = 0;
            speedZoomMaxSpeed = 1e+010;
            speedZoomMaxFOV = 0;
        };
        class HitPoints
        {
            class HitComTurret
            {
                armor = 0.1;
                material = -1;
                armorComponent = "hit_com_turret";
                name = "hit_com_turret_point";
                visual = "-";
                passThrough = 0;
                minimalHit = 0.1;
                explosionShielding = 1;
                radius = 0.15;
                isTurret = 1;
            };
            class HitComGun
            {
                armor = 0.1;
                material = -1;
                armorComponent = "hit_com_gun";
                name = "hit_com_gun_point";
                visual = "-";
                passThrough = 0;
                minimalHit = 0.1;
                explosionShielding = 1;
                radius = 0.15;
                isGun = 1;
            };
        };
        gunnerDoor = "";
        gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
        gunnerOutOpticsEffect[] = {};
        gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
        animationSourceCamElev = "camElev";
        proxyIndex = 1;
        gunnerType = "";
        initElev = 0;
        minTurn = -360;
        maxTurn = 360;
        initTurn = 0;
        initOutElev = 0;
        minOutTurn = -60;
        maxOutTurn = 60;
        initOutTurn = 0;
        maxHorizontalRotSpeed = 1.2;
        maxVerticalRotSpeed = 1.2;
        initCamElev = 0;
        stabilizedInAxes = 3;
        primary = 1;
        hasGunner = 1;
        turretCanSee = 0;
        canUseScanners = 1;
        class TurretSpec
        {
            showHeadPhones = 0;
        };
        gunnerOpticsColor[] = {0,0,0,1};
        gunnerOpticsShowCursor = 0;
        gunnerOutOpticsColor[] = {0,0,0,1};
        memoryPointGunnerOutOptics = "";
        gunnerOutForceOptics = 0;
        gunnerOutOpticsShowCursor = 0;
        gunnerFireAlsoInInternalCamera = 1;
        gunnerOutFireAlsoInInternalCamera = 1;
        gunnerUsesPilotView = 0;
        castGunnerShadow = 0;
        viewGunnerShadow = 1;
        ejectDeadGunner = 0;
        hideWeaponsGunner = 1;
        canHideGunner = -1;
        outGunnerMayFire = 0;
        inGunnerMayFire = 1;
        showHMD = 0;
        lockWhenDriverOut = 0;
        lockWhenVehicleSpeed = -1;
        gunnerCompartments = "Compartment1";
        LODTurnedIn = -1;
        LODTurnedOut = -1;
        memoryPointsGetInGunnerPrecise = "";
        missileBeg = "spice rakety";
        missileEnd = "konec rakety";
        armorLights = 0.4;
        class Reflectors
        {
        };
        aggregateReflectors[] = {};
        class GunFire
        {
            access = 0;
            cloudletDuration = 0.2;
            cloudletAnimPeriod = 1;
            cloudletSize = 1;
            cloudletAlpha = 1;
            cloudletGrowUp = 0.2;
            cloudletFadeIn = 0.01;
            cloudletFadeOut = 0.5;
            cloudletAccY = 0;
            cloudletMinYSpeed = -100;
            cloudletMaxYSpeed = 100;
            cloudletShape = "cloudletFire";
            cloudletColor[] = {1,1,1,0};
            interval = 0.01;
            size = 3;
            sourceSize = 0.5;
            timeToLive = 0;
            initT = 4500;
            deltaT = -3000;
            class Table
            {
                class T0
                {
                    maxT = 0;
                    color[] = {0.82,0.95,0.93,0};
                };
                class T1
                {
                    maxT = 200;
                    color[] = {0.75,0.77,0.9,0};
                };
                class T2
                {
                    maxT = 400;
                    color[] = {0.56,0.62,0.67,0};
                };
                class T3
                {
                    maxT = 600;
                    color[] = {0.39,0.46,0.47,0};
                };
                class T4
                {
                    maxT = 800;
                    color[] = {0.24,0.31,0.31,0};
                };
                class T5
                {
                    maxT = 1000;
                    color[] = {0.23,0.31,0.29,0};
                };
                class T6
                {
                    maxT = 1500;
                    color[] = {0.21,0.29,0.27,0};
                };
                class T7
                {
                    maxT = 2000;
                    color[] = {0.19,0.23,0.21,0};
                };
                class T8
                {
                    maxT = 2300;
                    color[] = {0.22,0.19,0.1,0};
                };
                class T9
                {
                    maxT = 2500;
                    color[] = {0.35,0.2,0.02,0};
                };
                class T10
                {
                    maxT = 2600;
                    color[] = {0.62,0.29,0.03,0};
                };
                class T11
                {
                    maxT = 2650;
                    color[] = {0.59,0.35,0.05,0};
                };
                class T12
                {
                    maxT = 2700;
                    color[] = {0.75,0.37,0.03,0};
                };
                class T13
                {
                    maxT = 2750;
                    color[] = {0.88,0.34,0.03,0};
                };
                class T14
                {
                    maxT = 2800;
                    color[] = {0.91,0.5,0.17,0};
                };
                class T15
                {
                    maxT = 2850;
                    color[] = {1,0.6,0.2,0};
                };
                class T16
                {
                    maxT = 2900;
                    color[] = {1,0.71,0.3,0};
                };
                class T17
                {
                    maxT = 2950;
                    color[] = {0.98,0.83,0.41,0};
                };
                class T18
                {
                    maxT = 3000;
                    color[] = {0.98,0.91,0.54,0};
                };
                class T19
                {
                    maxT = 3100;
                    color[] = {0.98,0.99,0.6,0};
                };
                class T20
                {
                    maxT = 3300;
                    color[] = {0.96,0.99,0.72,0};
                };
                class T21
                {
                    maxT = 3600;
                    color[] = {1,0.98,0.91,0};
                };
                class T22
                {
                    maxT = 4200;
                    color[] = {1,1,1,0};
                };
            };
        };
        class GunClouds
        {
            access = 0;
            cloudletDuration = 0.3;
            cloudletAnimPeriod = 1;
            cloudletSize = 1;
            cloudletAlpha = 1;
            cloudletGrowUp = 1;
            cloudletFadeIn = 0.01;
            cloudletFadeOut = 1;
            cloudletAccY = 0.4;
            cloudletMinYSpeed = 0.2;
            cloudletMaxYSpeed = 0.8;
            cloudletShape = "cloudletClouds";
            cloudletColor[] = {1,1,1,0};
            interval = 0.05;
            size = 3;
            sourceSize = 0.5;
            timeToLive = 0;
            initT = 0;
            deltaT = 0;
            class Table
            {
                class T0
                {
                    maxT = 0;
                    color[] = {1,1,1,0};
                };
            };
        };
        class MGunClouds
        {
            access = 0;
            cloudletGrowUp = 0.05;
            cloudletFadeIn = 0;
            cloudletFadeOut = 0.1;
            cloudletDuration = 0.05;
            cloudletAnimPeriod = 1;
            cloudletSize = 1;
            cloudletAlpha = 0.3;
            cloudletAccY = 0;
            cloudletMinYSpeed = -100;
            cloudletMaxYSpeed = 100;
            cloudletShape = "cloudletClouds";
            cloudletColor[] = {1,1,1,0};
            timeToLive = 0;
            interval = 0.02;
            size = 0.3;
            sourceSize = 0.02;
            initT = 0;
            deltaT = 0;
            class Table
            {
                class T0
                {
                    maxT = 0;
                    color[] = {1,1,1,0};
                };
            };
        };
        forceNVG = 0;
        isCopilot = 0;
        canEject = 1;
        gunnerLeftHandAnimName = "";
        gunnerLeftLegAnimName = "";
        gunnerRightLegAnimName = "";
        preciseGetInOut = 0;
        turretFollowFreeLook = 0;
        allowTabLock = 1;
        showAllTargets = 0;
        dontCreateAI = 0;
        disableSoundAttenuation = 0;
        slingLoadOperator = 0;
        playerPosition = 0;
        allowLauncherIn = 0;
        allowLauncherOut = 0;
        class TurnIn
        {
            turnOffset = 0;
        };
        class TurnOut
        {
            turnOffset = 0;
        };
        memoryPointGun = "kulas";
        selectionFireAnim = "zasleh";
        showCrewAim = 0;
        ace_fcs_Enabled = 0;
        ace_fcs_MinDistance = 200;
        ace_fcs_MaxDistance = 5500;
        ace_fcs_DistanceInterval = 5;
    };
};