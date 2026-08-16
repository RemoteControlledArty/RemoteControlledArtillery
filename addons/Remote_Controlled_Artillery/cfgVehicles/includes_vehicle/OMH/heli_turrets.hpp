class CopilotTurret: CopilotTurret
{
	#include "\Remote_Controlled_Artillery\includes_cfg\panels_Heli_Copilot.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	
	gunnerName="Optional Pilot";
	gunnerCompartments="Compartment2";
	dontCreateAI=1;
	primaryGunner=0;	//0
	primaryObserver=0;	//0
	isCopilot=1;		//1
	//cargoCanControlUAV=1;

	stabilizedInAxes=3;	//3
	minElev=-90;	//40
	maxElev=20;		//20
	initElev=0;		//0
	minTurn=-360;	//-120
	maxTurn=360;	//120
	initTurn=0;		//0
	//minCamElev=-90;
	//maxCamElev=90;
	maxHorizontalRotSpeed=4;	//3
	maxVerticalRotSpeed=4;		//3

	weapons[]=
	{
		"RC_target_confirmer_datalink",
		//"CMFlareLauncher"
		//"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag",
		//"168Rnd_CMFlare_Chaff_Magazine"
		//"SmokeLauncherMag"
	};

	class OpticsIn
	{
		class Wide
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			opticsDisplayName="W";

			initFov=1.25;
			minFov=0.025;
			maxFov=1.25;
		};
	};
	//turretInfoType="RC_RscOptics_AV_Heli";
	//turretInfoTypeRTD="RC_RscOptics_AV_Heli";
	//turretInfoType="RscOptics_Heli_Attack_01_gunner";
	//turretInfoType="RscOptics_MBT_03_gunner";


	/*
	//default
	memoryPointGunnerOptics="Copilot_view_dir";	//Copilot_view_dir
	memoryPointGun="Copilot_view_pos";			//Copilot_view_pos
	
	gunnerAction="pilot_Heli_Transport_04";
	proxyIndex=1;
	hideWeaponsGunner=1;
	memoryPointsGetInGunner="Codriver_pos";
	memoryPointsGetInGunnerDir="Codriver_dir";
	gunnerLeftHandAnimName="Stick_collective_2";
	gunnerRightHandAnimName="Stick_control_2";
	gunnerLeftLegAnimName="Pedals_left_2";
	gunnerRightLegAnimName="Pedals_right_2";
	body="Optics_1_rot";
	gun="Optics_1_muzzle_rot";
	animationSourceBody="Optics_1_source";
	animationSourceGun="Optics_1_muzzle_source";
	gunBeg="Copilot_view_dir";
	gunEnd="Copilot_view_pos";
	usePip=1;

	inGunnerMayFire=1;			//1
	gunnerOpticsEffect[]={};	//{}
	gunnerOpticsModel="";		//""

	soundServo[]={"",0.01,1,30};	//{"",0.01,1,30}
	*/

	/*
	//what even was this for
	class ViewGunner: ViewPilot
	{
		initAngleX=-16;
	};
	*/

	/*
	//what god damn use has this? its defined for the Mi-290, not inherited from mainTurret, but its completely obscure
	class OpticsOut
	{
		class Monocular
		{
			initAngleX=0;
			minAngleX=-30;
			maxAngleX=30;
			initAngleY=0;
			minAngleY=-100;
			maxAngleY=100;
			initFov=1.25;
			minFov=0.25;
			maxFov=1.25;
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
			gunnerOpticsModel="";
			gunnerOpticsEffect[]={};

			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
		};
	};
	*/

	/*
	loadercamera attemt, didnt work as optics cannot be changed button wise, or other reason

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
	*/
};
/*
class CopilotTurret2: CopilotTurret
{
	gunnerName="Turret Camera";
	driverForceOptics=1;
	driverCompartments="Compartment3";
	dontCreateAI=0;
	primaryGunner=1;
	primaryObserver=0;
	//isCopilot=1;
};
*/
class LoadmasterTurret: LoadmasterTurret
{
	#include "\Remote_Controlled_Artillery\includes_cfg\panels_Heli_Copilot.hpp"
	dontCreateAI=1;

	primaryGunner=0;
	primaryObserver=0;
	gunnerCompartments="Compartment2";
};