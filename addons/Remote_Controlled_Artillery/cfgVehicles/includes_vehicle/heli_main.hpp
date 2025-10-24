//#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakePilotCtrl.hpp"
//#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\PilotComponents6kmSens.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
lockDetectionSystem="2+4+8";
//RC_ATrespondingTurret[] = {1};

weapons[]=
{
	"RC_APS_W"
	//"SmokeLauncher"
};
magazines[]=
{
	"RC_1Rnd_APS_M",
	//"RC_1Rnd_APS_M"
	//"SmokeLauncherMag",
	//"SmokeLauncherMag"
};

/*
smokeLauncherOnTurret=0;
smokeLauncherGrenadeCount=12;
smokeLauncherVelocity=14;
smokeLauncherAngle=360;
*/

editorSubcategory="RC_Heli_subcat";
author="Ascent";
ejectDeadGunner=0;
ejectDeadDriver=0;
ejectDeadCommander=0;
crewCrashProtection=0.01;
#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"


//edit values
//O_Heli_Transport_04_bench_black_F  	//Chinook B_Heli_Transport_03_F
slingLoadMaxCargoMass=25000;	//t 13500	ch
maximumLoad=6000;	//t 4000	//c 6000
maxSpeed=350;	//t250	//c300
liftForceCoef=1.65;	//taru 1.3	//chinook 1.65;

//ace_cargo_hasCargo=1;
//ace_cargo_space=20;	//t8 c40

/*
ace_refuel_canReceive=1;	//1
ace_refuel_flowRate=8;	//8
ace_refuel_fuelCapacity=3000;	//t ?, ch 3914
*/

//airCapacity=10; ???
//bodyFrictionCoef=2.8;	//2.8


class Viewoptics: ViewOptics
{
	initAngleX=0;
	minAngleX=0;
	maxAngleX=0;
	initAngleY=0;
	minAngleY=0;
	maxAngleY=0;
	minFov=0.25;
	maxFov=1.5;
	initFov=1.5;
	visionMode[]=
	{
		"Normal",
		"NVG",
		"Ti"
	};
	thermalMode[]={0};
};

class ViewPilot: ViewPilot
{
	initAngleX=0;
	minAngleX=0;
	maxAngleX=0;
	initAngleY=0;
	minAngleY=0;
	maxAngleY=0;
	minFov=0.25;
	maxFov=1.5;
	initFov=1.5;
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
	//turretInfoType="RscOptics_MBT_03_gunner";
	unitInfoType="RscOptics_AV_pilot";
	unitInfoTypeRTD="RscOptics_AV_pilot";

	class OpticsIn
	{
		class Wide
		{
			opticsDisplayName="W";
			initAngleX=0;
			minAngleX=0;
			maxAngleX=0;
			initAngleY=0;
			minAngleY=0;
			maxAngleY=0;
			minFov=0.025;
			maxFov=1.5;
			initFov=1.5;
			directionStabilized=0;
			//directionStabilized=1;
			visionMode[]=
			{
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[]={0};
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
		};
		showMiniMapInOptics=0;
		showUAVViewpInOptics=0;
		showSlingLoadManagerInOptics=1;
	};
	minTurn=0;
	maxTurn=0;
	initTurn=0;
	minElev=80;
	maxElev=80;
	initElev=80;
	maxXRotSpeed=0.5;
	maxYRotSpeed=0.5;
	pilotOpticsShowCursor=1;
	controllable=0;	//test 1
};

//cargoCanControlUAV=1;