//#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakePilotCtrl.hpp"
//#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\PilotComponents6kmSens.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
lockDetectionSystem="2+4+8";
//RC_ATrespondingTurret[]={1};

weapons[]=
{
	"RC_target_confirmer_datalink",
	"RC_APS_W",
	"CMFlareLauncher"
};
magazines[]=
{
	"RC_target_confirmer_mag",
	//"RC_1Rnd_APS_M"
	"168Rnd_CMFlare_Chaff_Magazine"
};

/*
smokeLauncherOnTurret=0;
smokeLauncherGrenadeCount=12;
smokeLauncherVelocity=14;
smokeLauncherAngle=360;
*/

editorSubcategory="RC_Heli_unarmed_subcat";
author="Ascent";
ejectDeadGunner=0;
ejectDeadDriver=0;
ejectDeadCommander=0;
#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"


//edit values					//O_Heli_Transport_04_bench_black_F  	//Chinook B_Heli_Transport_03_F
startDuration=10;				//t 20
slingLoadMaxCargoMass=25000;	//t 13500	//c 
maximumLoad=6000;				//t 4000	//c 6000
maxSpeed=350;					//t 250		//c 300
liftForceCoef=1.65;				//t 1.3		//c 1.65;
bodyFrictionCoef=2.24;			//2.8

//ace_cargo_hasCargo=1;
//ace_cargo_space=20;	//t8 c40

/*
ace_refuel_canReceive=1;	//1
ace_refuel_flowRate=8;	//8
ace_refuel_fuelCapacity=3000;	//t ?, ch 3914
*/

//memoryPointDriverOptics="Supply_pos";
//memoryPointDriverOptics="Driver_dir";
//memoryPointDriverOptics="Driver_pos";
//memoryPointDriverOptics="Slingload_cam";

class Viewoptics: ViewOptics
{
	speedZoomMaxFOV=0;
	speedZoomMaxSpeed=1e+10;

	minFov=0.25;
	maxFov=2;	//1.5
	initFov=2;	//1.5

	initAngleX=0;
	minAngleX=0; //-40
	maxAngleX=0; //17

	initAngleY=0;
	minAngleY=0;	//-100
	maxAngleY=0;	//100

	minMoveZ=0;
	minMoveY=0;
	minMoveX=0;

	maxMoveZ=0;
	maxMoveY=0;
	maxMoveX=0;

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
*/

class pilotCamera
{
	//turretInfoType="RscOptics_MBT_03_gunner";
	unitInfoType="RC_RscOptics_AV_Heli";
	unitInfoTypeRTD="RC_RscOptics_AV_Heli";

	controllable=0;	//test 1
	pilotOpticsShowCursor=1;	//?
	//stabilizedInAxes=3;
	//directionStabilized=0;

	minTurn=0;
	maxTurn=0;
	initTurn=0;

	minElev=80;
	maxElev=80;
	initElev=80;

	maxXRotSpeed=0.5;
	maxYRotSpeed=0.5;

	class OpticsIn
	{
		class Wide
		{
			opticsDisplayName="V";
			//stabilizedInAxes=3;
			//directionStabilized=1;

			minFov=0.025;
			maxFov=2;	//1.5
			initFov=2;	//1.5

			initAngleX=0;
			minAngleX=0;
			maxAngleX=0;
			initAngleY=0;
			minAngleY=0;
			maxAngleY=0;

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
};

//cargoCanControlUAV=1;