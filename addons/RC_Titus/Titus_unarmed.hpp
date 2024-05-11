class QIN_Titus_base;
class QIN_Titus_DES;
class RC_Titus_unarmed_base: QIN_Titus_DES
{
	class Turrets;
	class ViewOptics;
	//class ViewGunner;
	class CommanderTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class AnimationSources;
	class Components;
	class Door_LF;
	class Door_RF;
	class Door_rear;
	class comp_camonet;
	class comp_klec;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Titus_unarmed_D: RC_Titus_unarmed_base
{
	author="Ascent";
	faction="RemoteControlled_B";
	displayName="RC Titus";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	//side=0;
	forceInGarage=1;
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	commanding=1;
	//memoryPointDriverOptics="optika_velitel";
	//driverCompartments="Compartment3";
	//commanding=2;
	crewCrashProtection=0.01;

	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class EventHandlers: EventHandlers
	{
		/*
		//init="(_this select 0) spawn {waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;};";
		#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"

		if (crew _myVehicle findIf { _myVehicle getCargoIndex _x == 11 } > -1) then {
  		...
		};

		getin=
		"params ['_vehicle']; \
		if (isPlayer (commander _vehicle)) then { \
			(group (driver _vehicle)) setGroupOwner (owner (commander _vehicle)); \
			_vehicle setOwner (owner (commander _vehicle)); \
			_vehicle setEffectiveCommander (commander _vehicle); \
		} else { \
			if (isPlayer (gunner _vehicle)) then { \
				(group (driver _vehicle)) setGroupOwner (owner (gunner _vehicle)); \
				_vehicle setOwner (owner (gunner _vehicle)); \
				_vehicle setEffectiveCommander (gunner _vehicle); \
			} \
		};";
		*/
	};

	//uavCameraGunnerPos="PiP1_pos";
	//uavCameraGunnerDir="PiP1_dir";

	class Turrets: Turrets
	{
		class CommanderTurret : CommanderTurret
		{
			//gunnerCompartments="Compartment4";
			primaryGunner=1;
			primaryObserver=0;
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//personTurretAction="";	//no effect
			//forceHideGunner=1;	//makes view bug
			//forceHideCommander=1;	//makes view bug
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			gunnerForceOptics=1;
			//commanding=3;

			gunnerAction="";
			//canHideGunner=1;
			//viewGunnerInExternal=1;
			isPersonTurret=0;
			//animationSourceHatch="hatch_3";
			personTurretAction="";
		};

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03
		{
			commanding=4;
		};
		
		/*
		//seem to be blocked?
		class CargoTurret_03: CargoTurret_01
		{
			gunnerAction="vehicle_turnout_2";
			memoryPointsGetInGunner="pos codriver";
			memoryPointsGetInGunnerDir="pos codriver dir";
			gunnerName="Co-Driver";
			proxyIndex=11;
			gunnerInAction="passenger_low01";
			animationSourceHatch="hatch_4";
			gunnerDoor="door_rf";
		};
		*/
	};

	class AnimationSources: AnimationSources
	{
		class Door_LF: Door_LF
		{
			animPeriod=0.5;
		};
		class Door_RF: Door_RF
		{
			animPeriod=0.5;
		};
		class Door_rear: Door_rear
		{
			animPeriod=0.8;
		};
		class comp_camonet: comp_camonet
		{
			initPhase=1;
		};
		class comp_klec: comp_klec
		{
			initPhase=1;
		};
	};

	animationList[]=
	{
		"comp_klec",
		0,
		"comp_camonet",
		0
	};
};

class RC_Titus_unarmed_WD: RC_Titus_unarmed_D
{
	editorPreview="qin_titus\data\preview\titus_unarmed_wdl.jpg";
	hiddenSelectionsTextures[]=
	{
		"qin_titus\data\skins\wdl\karoserie1_wdl.paa",
		"qin_titus\data\skins\wdl\karoserie2_wdl.paa",
		"qin_titus\data\skins\wdl\karoserie3_wdl.paa",
		"qin_titus\data\skins\wdl\arx20_wdl.paa",
		"qin_titus\data\skins\wdl\interier1_wdl.paa",
		"qin_titus\data\skins\wdl\interier2_wdl.paa",
		"qin_titus\data\camonet_wdl_co.paa"
	};
};

class RC_Titus_unarmed_A: RC_Titus_unarmed_D
{
	hiddenSelectionsTextures[]=
	{
		"qin_titus\data\skins\wdl2\karoserie1_wdl2.paa",
		"qin_titus\data\skins\wdl2\karoserie2_wdl2.paa",
		"qin_titus\data\skins\wdl2\karoserie3_wdl2.paa",
		"qin_titus\data\skins\wdl2\arx20_wdl2.paa",
		"qin_titus\data\skins\wdl2\interier1_wdl2.paa",
		"qin_titus\data\skins\wdl2\interier2_wdl2.paa",
		"qin_titus\data\camonet_wdl2_co.paa"
	};
};

class QIN_Titus_arx20_DES;
class RC_Titus_armed_base: QIN_Titus_arx20_DES
{
	class Turrets;
	class ViewOptics;
	//class ViewGunner;
	class CommanderTurret;
	class ARX20Turret;
	class CargoTurret_01;
	class CargoTurret_02;
	class AnimationSources;
	class Components;
	class Door_LF;
	class Door_RF;
	class Door_rear;
	class comp_camonet;
	class comp_klec;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Titus_armed_D: RC_Titus_armed_base
{
	author="Ascent";
	faction="RemoteControlled_B";
	displayName="RC Titus 20mm";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	//side=0;
	forceInGarage=1;
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	//memoryPointDriverOptics="optika_velitel";
	driverCompartments="Compartment3";
	//commanding=2;
	crewCrashProtection=0.01;

	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;};";
		#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
	};

	//uavCameraGunnerPos="PiP1_pos";
	//uavCameraGunnerDir="PiP1_dir";

	class Turrets: Turrets
	{
		class CommanderTurret : CommanderTurret
		{
			gunnerCompartments="Compartment4";
			primaryGunner=1;
			primaryObserver=0;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//personTurretAction="";	//no effect
			//forceHideGunner=1;	//makes view bug
			//forceHideCommander=1;	//makes view bug
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			gunnerForceOptics=1;
			//commanding=3;
		};
		class ARX20Turret: ARX20Turret
		{
			primaryGunner=0;
			primaryObserver=1;
		};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};

	class AnimationSources: AnimationSources
	{
		class Door_LF: Door_LF
		{
			animPeriod=0.5;
		};
		class Door_RF: Door_RF
		{
			animPeriod=0.5;
		};
		class Door_rear: Door_rear
		{
			animPeriod=0.8;
		};
		class comp_camonet: comp_camonet
		{
			initPhase=1;
		};
		class comp_klec: comp_klec
		{
			initPhase=1;
		};
	};

	animationList[]=
	{
		"comp_klec",
		0,
		"comp_camonet",
		0
	};
};