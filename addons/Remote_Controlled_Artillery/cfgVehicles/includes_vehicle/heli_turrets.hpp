class CopilotTurret: CopilotTurret
{
	#include "\Remote_Controlled_Artillery\includes_cfg\panels_Heli_Copilot.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

	dontCreateAI=1;
	primaryGunner=0;
	primaryObserver=0;
	isCopilot=1;
	//dontCreateAI=1;
	//cargoCanControlUAV=1;
	stabilizedInAxes=3;
	gunnerCompartments="Compartment2";
	//driverCompartments="Compartment2";

	minElev=-90;
	maxElev=20;
	initElev=0;
	minTurn=-360;
	maxTurn=360;
	initTurn=0;
	//minCamElev=-90;
	//maxCamElev=90;

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
	memoryPointGun="Copilot_view_pos";
	memoryPointGunnerOptics="Copilot_view_dir";
	gunnerName="$STR_A3_COPILOT";
	/*
	minElev=-40;
	maxElev=20;
	initElev=0;
	minTurn=-120;
	maxTurn=120;
	initTurn=0;
	*/
	usePip=1;	//needed?
	//turretInfoType="RscOptics_Heli_Attack_01_gunner";
	//turretInfoType="RscOptics_MBT_03_gunner";
	unitInfoType="RscOptics_AV_pilot";
	unitInfoTypeRTD="RscOptics_AV_pilot";

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

	soundServo[]=
	{
		"",
		0.0099999998,
		1,
		30
	};
	inGunnerMayFire=1;
	gunnerOpticsEffect[]={};
	gunnerOpticsModel="";
	class ViewGunner: ViewPilot
	{
		initAngleX=-16;
	};
	class OpticsIn
	{
		class Wide
		{
			initAngleX=0;
			minAngleX=-30;
			maxAngleX=30;
			initAngleY=0;
			minAngleY=-100;
			maxAngleY=100;
			initFov=1.25;
			minFov=0.025;
			maxFov=1.25;
			visionMode[]=
			{
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[]={0};
			opticsDisplayName="W";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
		};
	};
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