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
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Titus_unarmed_D_base: RC_Titus_unarmed_base
{
	author="Ascent";
	faction="RemoteControlled_B";
	displayName="RC Titus";
	editorSubcategory="RC_Titus_subcat";
	side=0;
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
	driverCompartments="Compartment3";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	lockDetectionSystem=4;
	incomingMissileDetectionSystem=16;
	soundLocked[]=
	{
		"\A3\Sounds_F\weapons\Rockets\locked_1",
		1,
		1
	};
	soundIncommingMissile[]=
	{
		"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4",
		0.39810717,
		1
	};
	enginePower=460;
	peakTorque=1312.5;
	maxSpeed=120;
	normalSpeedForwardCoef=0.64;

	smokeLauncherOnTurret=1;
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;
	weapons[]=
	{
		"TruckHorn2",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};

				#include "\Remote_Controlled_Artillery\includes\passiveRadar.hpp"
			};
		};
	};

	class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
	{
		defaultDisplay="SensorDisplay";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={4000,2000,1000,500};
				resource="RscCustomInfoSensors";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class VehicleDriverDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Driver";
			};
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
			/*
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			*/
		};
	};
	class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
	{
		defaultDisplay="VehicleDriverDisplay";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={4000,2000,1000,500};
				resource="RscCustomInfoSensors";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class VehicleDriverDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Driver";
			};
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
			/*
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			*/
		};
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

	class HitPoints: HitPoints
	{
		class HitLFWheel: HitLFWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLMWheel: HitLMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLBWheel: HitLBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRMWheel: HitRMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRBWheel: HitRBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
	};
};

class RC_Titus_unarmed_D: RC_Titus_unarmed_D_base
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
	};

	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	threat[]={0.30000001,0.30000001,0.30000001};

	class Turrets: Turrets
	{
		class CommanderTurret : CommanderTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			gunnerCompartments="Compartment4";
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

			class ViewOptics: ViewOptics
			{
				initFov=1;
				minFov=0.05;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
			};

			weapons[]=
			{
				"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorsDisplayComponent";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
			};
		};

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03
		{
			commanding=4;
			primaryGunner=0;
			primaryObserver=1;

			weapons[]=
			{
				"TruckHorn2",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
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

/*
class QIN_Titus_arx20_DES;
class RC_Titus_armed_base: QIN_Titus_arx20_DES
{
	class ARX20Turret;
};
class RC_Titus_armed_D: RC_Titus_armed_base
{
	displayName="RC Titus 20mm";

	class Turrets: Turrets
	{
		class CommanderTurret : CommanderTurret
		{
			primaryGunner=1;
			primaryObserver=0;

		};
		class ARX20Turret: ARX20Turret
		{
			primaryGunner=0;
			primaryObserver=1;
		};
	};
};
*/