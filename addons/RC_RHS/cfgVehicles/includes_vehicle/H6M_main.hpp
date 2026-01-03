editorSubcategory="RC_Heli_subcat";


lockDetectionSystem="2+4+8";		//4+8
showAllTargets="2 + 4";
receiveRemoteTargets=1;
reportRemoteTargets=1;
reportOwnPosition=1;
canUseScanner=1;


allowTabLock=1;
gunnerCanFire=1;
enableManualFire=1;


bodyFrictionCoef=0.2;				//0.3
maxSpeed=250;						//200
liftForceCoef=1;					//1				//1.7
cyclicAsideForceCoef=1.65;			//1.65			//2
cyclicForwardForceCoef=0.40000001;	//0.40000001	//0.43000001
backrotorforcecoef=0.89999998;			//0.89999998	//0.89999998	//1.35
startDuration=7.5;					//10
slingLoadMemoryPoint="slingLoad0";
slingLoadMaxCargoMass=4000;			//900
maximumLoad=2250;					//1000
//sensitivity=2.5;					//2.5
//mainBladeRadius=4.3200002;		//4.3200002
//tailBladeRadius=0.76999998;		//0.76999998


driverCompartments="Compartment1";
crewCrashProtection=0.1;			//0.2
ejectDeadCargo=1;
hullDamageCauseExplosion=1;			//1, maybe just bool?
hullExplosionDelay[]={20,30};		//{10,20}


memoryPointTaskMarker="TaskMarker_1_pos";
memoryPointDriverOptics="pos pilot dir";	//pos pilot, pos rack, pos gunner, pos cargo 	//memsupply, slingLoad0		//IR_Position, Light_pos


unitInfoType="RC_RscOptics_AV_Heli";
unitInfoTypeRTD="RC_RscOptics_AV_Heli";
//driverWeaponsInfoType="RscOptics_CAS_01_TGP";
//driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
driverOpticsModel="rhsusf\addons\rhsusf_melb\data\optics\melb_flir_wf.p3d";
weapons[]+={"Laserdesignator_pilotCamera"};
magazines[]+={"Laserbatteries"};


//2.0
/*
memoryPointGunnerOptics="commanderview";
memoryPointDriverOptics="commanderview";
gunBeg="commanderview";
gunEnd="laserstart";
memoryPointGun="commanderview";
body="obsTurret";
gun="obsGun";
animationSourceBody="obsTurret";
animationSourceGun="obsGun";
turretInfoType="Rsc_MELB_Turret_UnitInfo";
*/

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

	/*
	//cannot be changed?
	minElev=0;
	maxElev=0;
	initElev=0;
	*/

	visionMode[]=
	{
		"Normal",
		"NVG",
		"Ti"
	};
	thermalMode[]={0};
};
/*
class ViewPilot: ViewPilot
{
	initFov=1.25;
	maxFov=1.25;
	minFov=0.02;

	initAngleX=0;
	minAngleX=-65;
	maxAngleX=85;
	initAngleY=0;
	minAngleY=-150;
	maxAngleY=150;

	visionMode[]=
	{
		"Normal",
		"NVG",
		"Ti"
	};
	thermalMode[]={0};
};
*/