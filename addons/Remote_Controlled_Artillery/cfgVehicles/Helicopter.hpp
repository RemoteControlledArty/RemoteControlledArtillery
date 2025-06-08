class O_Heli_Transport_04_bench_black_F;
class RC_HeliTransport_blk_Base: O_Heli_Transport_04_bench_black_F
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
	class UserActions;
	class EventHandlers;

	scope=0;
	scopeCurator=0;
};
class RC_HeliTransport_blk: RC_HeliTransport_blk_Base
{
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakePilotCtrl.hpp"

	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		/*
		class RC_Heli
		{
			#include "\Remote_Controlled_Artillery\includes_script\initHeli.hpp"
		};
		*/
	};

	displayName="RC Transport Helicopter";
	faction="RemoteControlled_O";
	editorSubcategory="RC_Heli_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	vehicleClass="Autonomous";
	isUav=1;
	uavCameraDriverPos="pip_pilot_pos";
	uavCameraDriverDir="pip_pilot_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	//driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	//memoryPointDriverOptics="pip_pilot_pos";

	//isCopilot=0;
	
	//gunBeg="Copilot_view_dir";
	//gunEnd="Copilot_view_pos";
	//memoryPointGun="Copilot_view_pos";
	//memoryPointDriverOptics="Copilot_view_dir";

	extCameraPosition[]={0,-0.25,-2.3499999};
	extCameraParams[]={0.93000001,10,30,0.25,1,10,30,0,1};
	memoryPointTaskMarker="TaskMarker_1_pos";
	memoryPointDriverOptics="Copilot_view_dir";
	//memoryPointDriverOptics="pip_pilot_pos";
	//memoryPointDriverOptics="Slingload_cam";
	//driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	unitInfoType="RscOptics_AV_pilot";
	unitInfoTypeRTD="RscOptics_AV_pilot";

	crew="O_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment2";
	forceHideDriver=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;

	dontCreateAI=1;

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
		turretInfoType="RscOptics_MBT_03_gunner";
		//unitInfoType="RscOptics_AV_pilot";
		//unitInfoTypeRTD="RscOptics_AV_pilot";

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
			primaryGunner=1;
			primaryObserver=0;
			gunnerForceOptics=1;
			isCopilot=1;
			dontCreateAI=1;
			//cargoCanControlUAV=1;
			stabilizedInAxes=0;
			//stabilizedInAxes=3;

			minElev=-90;
			maxElev=30;
			initElev=0;
			minTurn=-360;
			maxTurn=360;
			initTurn=0;
			//minCamElev=-90;
			//maxCamElev=90;

			gunnerAction="pilot_Heli_Transport_04";
			gunnerCompartments="Compartment1";
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

			weapons[]=
			{
				"FakeHorn"
			};
			soundServo[]=
			{
				"",
				0.0099999998,
				1,
				30
			};
			magazines[]={};
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
					thermalMode[]={0,1};
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
		};
		class LoadmasterTurret: LoadmasterTurret
		{
			dontCreateAI=1;
			gunnerCompartments="Compartment2";
		};
		class CargoTurret_01: CargoTurret_01 {dontCreateAI=1;};
		class CargoTurret_02: CargoTurret_02 {dontCreateAI=1;};
		class CargoTurret_03: CargoTurret_03 {dontCreateAI=1;};
		class CargoTurret_04: CargoTurret_04 {dontCreateAI=1;};
		class CargoTurret_05: CargoTurret_05 {dontCreateAI=1;};
		class CargoTurret_06: CargoTurret_06 {dontCreateAI=1;};
		class CargoTurret_07: CargoTurret_07 {dontCreateAI=1;};
		class CargoTurret_08: CargoTurret_08 {dontCreateAI=1;};
	};
};


/*
this addEventHandler ["Fired", {
	params ["_unit", "_weapon"];
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


/*
_vic = _this select 0;
[_vic] spawn {
	params ["_vic"];

	while {true} do {
		(gunner _vic) action ["TakeVehicleControl", _vic];
	};
};
*/


/*
_vehicle = _this;
[_vehicle] spawn {
	params ["_vehicle"];

	while {true} do {
		sleep 0.1;
		(gunner _this) action ["TakeVehicleControl", _this];
		systemchat str time;
	};
};
*/


/*
heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	[_vehicle] spawn {
		params ["_vehicle"];
	
		while {true} do {
		sleep 1;
		(gunner _vehicle) action ["TakeVehicleControl", _vehicle];
		systemchat str time;
		};
	};
}];
*/




/*
heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	hint format ["active %1 old %2", _activeCoPilot, _oldController];
	hint format ["active %1 old %2", (gunner _vehicle), _vehicle];

	(group (driver _vic)) setGroupOwner (owner (gunner _vehicle));
	_vic setEffectiveCommander (gunner _vehicle);

	(gunner _vehicle) action ["TakeVehicleControl", _vehicle];
}];
*/

/*
heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	private _copilot = (gunner _vehicle);
	if (_oldController isNotEqualTo _copilot) then 
	{
		_copilot action ["TakeVehicleControl", _vehicle];
	} else {
		_copilot action ["SuspendVehicleControl", _vehicle];
	};
}];

heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	private _copilot = (gunner _vehicle);
	hint format ["active %1 old %2", _copilot, _oldController];

	if (_oldController isEqualTo _copilot) then 
	{
		_copilot action ["TakeVehicleControl", _vehicle];
	} else {
		_copilot action ["SuspendVehicleControl", _vehicle];
	};
}];

heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	private _copilot = (gunner _vehicle);
	hint format ["active %1 old %2 copilot %3", _activeCoPilot, _oldController, _copilot];
	_copilot action ["TakeVehicleControl", _vehicle];
}];

heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	systemchat str time;
	private _copilot = (gunner _vehicle);
	_copilot action ["TakeVehicleControl", _vehicle];
}];
*/

/*
heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	hint format ["active %1 old %2", _activeCoPilot, _oldController];
	hint format ["active %1 old %2", (gunner _vehicle), _vehicle];

	(group (driver _vic)) setGroupOwner (owner player);
	_vic setEffectiveCommander player;
}];
*/

/*
heli addEventHandler ["ControlsShifted", {
	params ["_vehicle", "_activeCoPilot", "_oldController"];

	hint format ["active %1 old %2", _activeCoPilot, _oldController];
	hint format ["active %1 old %2", (gunner _vehicle), _vehicle];
	(gunner _vehicle) remoteControl _vehicle;
}];
*/