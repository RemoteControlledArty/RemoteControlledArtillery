//Vanilla
/*
body="mainTurret";
gun="mainGun";
animationSourceBody="mainTurret";
animationSourceGun="mainGun";
memoryPointGun="laserstart";
memoryPointGunnerOptics="commanderview";
gunBeg="commanderview";
gunEnd="laserstart";
*/

//Pchela1T
body = "Optics_turret";
gun = "Optics_gun";
animationSourceBody = "mainTurret";
animationSourceGun = "mainGun";
memoryPointGun = "gunnerview";
memoryPointGunnerOptics = "gunnerview";
gunBeg = "gunnerview_dir";
gunEnd = "gunnerview";

isCopilot = 0;
minElev = -85;
maxElev = 0;
initElev = 0;
minTurn = -360;
maxTurn = 360;
initTurn = 0;
outGunnerMayFire = 1;
inGunnerMayFire = 1;
commanding = -1;
gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
gunnerForceOptics = 1;
turretInfoType = "RscOptics_UAV_gunner";
stabilizedInAxes = 3;
GunnerCompartments = "Compartment1";
gunnerInAction = "Disabled";
gunnerAction = "Disabled";
startEngine = 0;
class OpticsIn
{
	class Wide
	{
		opticsDisplayName = "W";
		initAngleX = 0;
		minAngleX = -30;
		maxAngleX = 30;
		initAngleY = 0;
		minAngleY = -100;
		maxAngleY = 100;
		initFov = 0.5;
		minFov = 0.05;
		maxFov = 0.5;
		directionStabilized = 1;
		visionMode[] = {"Normal","Ti"};
		thermalMode[] = {0,1};
		gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
	};
};
class OpticsOut
{
	class Monocular
	{
		initAngleX = 0;
		minAngleX = -30;
		maxAngleX = 30;
		initAngleY = 0;
		minAngleY = -100;
		maxAngleY = 100;
		initFov = 1.1;
		minFov = 0.133;
		maxFov = 1.1;
		visionMode[] = {"Normal","NVG"};
		gunnerOpticsModel = "";
		gunnerOpticsEffect[] = {};
	};
};