class QIN_Titus_arx20_DES;
class RC_Titus_unarmed_base: QIN_Titus_arx20_DES
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	//class ViewGunner;
	//class CommanderOptics;
	class ARX20Turret;
	class CargoTurret;
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
	//memoryPointDriverOptics="optika_velitel";
	driverCompartments="Compartment3";
	//commanding=2;
	crewCrashProtection=0.01;

	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes\initICV.hpp"
			//#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
			//#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	//uavCameraGunnerPos="PiP1_pos";
	//uavCameraGunnerDir="PiP1_dir";

	//*
	class Turrets: Turrets
	{
		class CommanderTurret: MainTurret
		{
			//mod
			//primaryGunner=1;
			//primaryObserver=0;
			//personTurretAction="";	//no effect
			forceHideGunner=1;	//makes view bug
			//forceHideCommander=1;	//makes view bug
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			gunnerForceOptics=1;
			//commanding=3;


			//default, inerhitance would break otherwise
			gunnerName="$STR_POSITION_COMMANDER";
			proxyType="CPCommander";
			commanding=2;
			primaryGunner=0;
			primaryObserver=1;
			gunnerCompartments="Compartment2";
			body="obsTurret";
			gun="obsGun";
			animationSourceBody="obsTurret";
			animationSourceGun="obsGun";
			gunBeg="optika_velitel_dir";
			gunEnd="optika_velitel";
			memoryPointGunnerOptics="optika_velitel";
			weapons[]=
			{
				"Laserdesignator_mounted"
			};
			magazines[]=
			{
				"Laserbatteries"
			};
			gunnerAction="vehicle_turnout_2";
			usePip=0;
			gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Optics_Commander_01_F.p3d";
			Laser=1;
			turretInfoType="RscOptics_Strider_commander";
			stabilizedInAxes=0;
			canHideGunner=1;
			//forceHideGunner=0;
			//gunnerForceOptics=0;
			inGunnerMayFire=1;
			outGunnerMayFire=0;
			startEngine=0;
			viewGunnerInExternal=1;
			minElev=-18;
			maxElev=40;
			minTurn=-75;
			maxTurn=75;
			isPersonTurret=1;
			ejectDeadGunner=0;
			animationSourceHatch="hatch_3";
			enableManualFire=0;
			memoryPointsGetInGunner="pos commander";
			memoryPointsGetInGunnerDir="pos commander dir";
			gunnerInAction="passenger_low01";
			personTurretAction="vehicle_turnout_2";
			gunnerGetInAction="GetInLow";
			gunnerGetOutAction="GetOutLow";
			gunnerDoor="door_rear";
			LODTurnedIn=-1;
			LODTurnedOut=1;
			class TurnIn
			{
				turnOffset=-180;
			};
			class TurnOut: TurnIn
			{
			};
			class ViewOptics: ViewOptics
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;
				initFov=0.755;
				minFov=0.034000002;
				maxFov=0.89999998;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0,1};
			};
			class ViewGunner: ViewOptics
			{
				initAngleX=-15;
				minAngleX=-45;
				maxAngleX=45;
				minFov=0.25;
				maxFov=1.25;
				initFov=0.75;
				visionMode[]={};
			};
			class HitPoints
			{
				class HitTurret
				{
					armor=0.2;
					material=-1;
					name="commander_turret_hit";
					visual="commander_turret_hit";
					passThrough=0;
					minimalHit=0.1;
					explosionShielding=1;
					radius=0.25;
				};
				class HitGun
				{
					armor=0.2;
					material=-1;
					name="commander_turret_hit";
					visual="commander_turret_hit";
					passThrough=0;
					minimalHit=0.1;
					explosionShielding=1;
					radius=0.25;
				};
			};
		};
		/*
		class CommanderOptics : CommanderOptics
		{
			primaryGunner=1;
			primaryObserver=0;
			//personTurretAction="";	//no effect
			//forceHideGunner=1;	//makes view bug
			//forceHideCommander=1;	//makes view bug
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//turretInfoType="RscWeaponRangeFinder";
			//turretInfoType="";
			//gunnerForceOptics=1;
			//commanding=3;

			//class ViewOptics: ViewOptics {};
			//class ViewGunner: ViewGunner {};
		};
		*/
		class ARX20Turret: ARX20Turret
		{
			//primaryGunner=0;
			//primaryObserver=1;
		};

		class CargoTurret_01: CargoTurret
		{
			gunnerAction="vehicle_turnout_1";
			gunnerCompartments="Compartment2";
			memoryPointsGetInGunner="pos cargoffv1";
			memoryPointsGetInGunnerDir="pos cargoffv1 dir";
			gunnerName="Passenger (left rear)";
			proxyIndex=10;
			maxElev=15;
			minElev=-42;
			maxTurn=20;
			minTurn=-95;
			isPersonTurret=1;
			ejectDeadGunner=0;
			gunnerInAction="passenger_apc_generic02";
			startEngine=0;
			commanding=-1;
			outGunnerMayFire=1;
			inGunnerMayFire=0;
			animationSourceHatch="hatch_1";
			gunnerGetInAction="GetInLow";
			gunnerGetOutAction="GetOutLow";
			memoryPointGunnerOptics="";
			selectionFireAnim="";
			canHideGunner=1;
			gunnerForceOptics=0;
			gunnerDoor="door_rear";
			LODTurnedIn=-1;
			LODTurnedOut=1;
			class TurnIn
			{
				turnOffset=-180;
			};
			class TurnOut: TurnIn
			{
			};
		};
		class CargoTurret_02: CargoTurret_01
		{
			gunnerAction="vehicle_turnout_2";
			memoryPointsGetInGunner="pos cargoffv2";
			memoryPointsGetInGunnerDir="pos cargoffv2 dir";
			gunnerName="Passenger (right rear)";
			proxyIndex=9;
			gunnerInAction="passenger_apc_narrow_generic02";
			animationSourceHatch="hatch_2";
		};
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
	};
	//*/
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