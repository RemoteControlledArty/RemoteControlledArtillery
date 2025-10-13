class O_Heli_Transport_04_bench_black_F;
class RC_OM_Heli_InfTransport_Core: O_Heli_Transport_04_bench_black_F
{
	class CargoTurret;

	class Turrets;
	class CopilotTurret;
	class LoadmasterTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class CargoTurret_04;
	class CargoTurret_05;
	class CargoTurret_06;
	class CargoTurret_07;
	class CargoTurret_08;

	class ViewPilot;
	class ViewOptics;
	class Components;
	//class UserActions;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_OM_Heli_InfTransport_Base: RC_OM_Heli_InfTransport_Core
{
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_NameUV.hpp"
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
		"RC_1Rnd_APS_M"
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

	class CargoTurret;

	class Turrets: Turrets
	{
		class CopilotTurret: CopilotTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_Heli_Copilot.hpp"

			primaryGunner=1;
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
			usePip=1;
			//turretInfoType="RscOptics_Heli_Attack_01_gunner";
			//turretInfoType="RscOptics_MBT_03_gunner";
			unitInfoType="RscOptics_AV_pilot";
			unitInfoTypeRTD="RscOptics_AV_pilot";

			/*
			weapons[]=
			{
				"CMFlareLauncher"
			};
			magazines[]=
			{
				"168Rnd_CMFlare_Chaff_Magazine"
			};
			*/
			weapons[]=
			{
				"FakeHorn"
			};
			magazines[]={};

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
		class LoadmasterTurret: LoadmasterTurret
		{
			dontCreateAI=1;
			gunnerCompartments="Compartment2";
		};
		class CargoTurret_01: CargoTurret_01 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_02: CargoTurret_02 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_03: CargoTurret_03 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_04: CargoTurret_04 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_05: CargoTurret_05 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_06: CargoTurret_06 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_07: CargoTurret_07 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_08: CargoTurret_08 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
	};
};


class RC_OM_Heli_InfTransport_blk: RC_OM_Heli_InfTransport_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		class RC_Heli
		{
			#include "\Remote_Controlled_Artillery\includes_script\initHeli.hpp"
		};
	};

	//add 2x FPV deployable per mousewheel
	//NEEDS script to reset camera when pilot left / when remote control is taken
	//make RC-OM Y-32
	//vehicle player setPilotCameraDirection [0,1,0] // re-centers the camera
	//correct uavCameraDriverPos
	//more variants

	//LOADMASTER COMMANDER, REMOVE COMMANDER SCRIPT! Going/leaving to Gopilot SPAWNS gunner AI in loadmaster or copilot seat.

	displayName="RC-OM Helicopter [Inf]";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	isUav=1;
	vehicleClass="Autonomous";
	uavCameraDriverPos="pip_pilot_pos";
	uavCameraDriverDir="pip_pilot_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	memoryPointTaskMarker="TaskMarker_1_pos";
	memoryPointDriverOptics="Copilot_view_dir";
	//memoryPointDriverOptics="pip_pilot_pos";
	//memoryPointDriverOptics="Slingload_cam";

	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	unitInfoType="RscOptics_AV_pilot";
	unitInfoTypeRTD="RscOptics_AV_pilot";

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_InfTransport_blk_O: RC_OM_Heli_InfTransport_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_InfTransport_blk_I: RC_OM_Heli_InfTransport_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};



/*
this addEventHandler ["Fired", {
	params ["_unit", "_weapon"];
	[getPos _unit, 180, "O_Crocus_MP_TI", east] call BIS_fnc_spawnVehicle;
}];

this addEventHandler ["Fired", {
	params ["_unit", "_weapon"];
	if (_weapon isNotEqualTo RC_Crocus_Deployer) exitWith {systemchat "nope";};
	[getPos _unit, 180, "O_Crocus_MP_TI", east] call BIS_fnc_spawnVehicle;
}];


this addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
	[getPos _this, 180, "BMP3", east] call BIS_fnc_spawnVehicle;
}];

heli addEventHandler ["ControlsShifted", { 
	params ["_vehicle", "_activeCoPilot", "_oldController"]; 
	systemchat "EH";
	hint format ["active %1 old %2 copilot %3", _activeCoPilot, _oldController, gunner _vehicle]; 
}];

heli addEventHandler ["ControlsShifted", {
	params ["_vic"];

	systemchat str time;
	(gunner _vic) action ["TakeVehicleControl", _vic];
}];
*/
