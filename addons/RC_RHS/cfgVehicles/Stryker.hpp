class rhsusf_stryker_m1126_m2_wd;
class RC_Stryker_M1126_M2_WD_Base: rhsusf_stryker_m1126_m2_wd
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class Hatch_Commander;
};
class RC_Stryker_M1126_M2_WD: RC_Stryker_M1126_M2_WD_Base
{
	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=2;
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
	//maxSpeed=66;
	//enginePower=447;
	//peakTorque=1660;

	//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
	//armorStructural=1000;	//280 //prevents instant explosion, does not make it stronger
	//hullExplosionDelay[]={15,20};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds

	//hullDamageCauseExplosion = 1; // vehicle will explode if HitHull is above 0.9
	//fuelExplosionPower=0.1;
	//secondaryExplosion=-1;

	/*
	//interesting values
	unitInfoType="RscOptics_AV_driverNoWeapon";
	memoryPointTaskMarker="TaskMarker_1_pos";
	cargoCanControlUAV=0;
	cargoIsCoDriver[]={0,0};
	killFriendlyExpCoef=0.1;
	transportSoldier=0;
	showNVGCargo[]={1};
	driverCompartments="Compartment3";
	cargoCompartments[]=
	{
		"Compartment2"
	};
	cargoProxyIndexes[]={1};
	getInProxyOrder[]={1};

	unitInfoType="RscOptics_AV_driver";
	//turret
	isCopilot=0;
	dontCreateAI=0;	//might be interesting to reduce script, or reduce commanding problems
	turretInfoType="RscOptics_UGV_gunner";
	*/

	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class DriverOpticsIn
	{
		/*
		class Wide: ViewOptics
		{
			camPos="view_driver";
			opticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_vision_block";
			visionMode[]=
			{
				"Normal"
			};
			hitpoint="Hit_Optic_Driver2";
		};
		*/
		class DVE_Wide
		{
			camPos="view_DVE";
			opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
			visionMode[]=
			{
				"Normal",
				"TI"
			};
			thermalMode[]={0};
			initFov=1.07692;
			minFov=1.07692;
			maxFov=1.07692;
			hitpoint="Hit_Optic_DVEA";
		};
		class DVS_Rear: DVE_Wide
		{
			camPos="view_rear";
			camDir="view_rear_dir";
			hitpoint="Hit_Optic_Driver_Rear";
		};
	};

	class AnimationSources: AnimationSources
	{
		/*
		class recoil_source
		{
			source="reload";
			weapon="RC_RHS_weap_M242BC";
		};
		class muzzle_hide_hmg: recoil_source
		{
		};
		class muzzle_rot_hmg: recoil_source
		{
			source="ammorandom";
		};
		class muzzle_rot_hmg2: muzzle_rot_hmg
		{
			weapon="RC_RHS_weap_m240_bradley_coax";
		};
		*/
		class Hatch_Commander: Hatch_Commander
		{
			animPeriod=0.8;
		};
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		/*
		class rear_hatch
		{
			source="door";
			animPeriod=0.80000001;
			initPhase=0;
		};
		*/
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
			defaultDisplay="EmptyDisplayComponent";

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
	};

	#include "\RC_RHS\loadouts\IFVitemsB_RHS.hpp"
};

class RC_APC_Stryker_M1126_M2_WD: RC_Stryker_M1126_M2_WD
{
	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			allowTabLock=1;

			weapons[]=
			{
				"RC_RHS_M2_CROWS_M151",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_mag_200rnd_127x99",
				"RC_RHS_mag_200rnd_127x99_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"rhsusf_mag_L8A3_16"
			};

			class OpticsIn
			{
				class DaysightWFOV: ViewOptics
				{
					camPos="View_CROWS";
					//opticsDisplayName="1.0x";
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CROWS_monitor";
					initFov=0.9;
					minFov=0.025;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					hitpoint="Hit_Optic_CROWS_Day";
				};
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="VehicleDriverDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
					};
				};
			};
		};
	};
};


class RC_APC_Stryker_M1126_M2_WD_B: RC_APC_Stryker_M1126_M2_WD
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="M1126 Stryker M2";
	editorSubcategory="RC_RHS_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	maximumLoad=3000;
};


class rhsusf_stryker_m1126_mk19_wd;
class RC_Stryker_M1126_MK19_WD_Base: rhsusf_stryker_m1126_mk19_wd
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class Hatch_Commander;
};
class RC_Stryker_M1126_MK19_WD: RC_Stryker_M1126_MK19_WD_Base
{
	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=2;
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
	//maxSpeed=66;
	//enginePower=447;
	//peakTorque=1660;

	//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
	//armorStructural=1000;	//280 //prevents instant explosion, does not make it stronger
	//hullExplosionDelay[]={15,20};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds

	//hullDamageCauseExplosion = 1; // vehicle will explode if HitHull is above 0.9
	//fuelExplosionPower=0.1;
	//secondaryExplosion=-1;

	/*
	//interesting values
	unitInfoType="RscOptics_AV_driverNoWeapon";
	memoryPointTaskMarker="TaskMarker_1_pos";
	cargoCanControlUAV=0;
	cargoIsCoDriver[]={0,0};
	killFriendlyExpCoef=0.1;
	transportSoldier=0;
	showNVGCargo[]={1};
	driverCompartments="Compartment3";
	cargoCompartments[]=
	{
		"Compartment2"
	};
	cargoProxyIndexes[]={1};
	getInProxyOrder[]={1};

	unitInfoType="RscOptics_AV_driver";
	//turret
	isCopilot=0;
	dontCreateAI=0;	//might be interesting to reduce script, or reduce commanding problems
	turretInfoType="RscOptics_UGV_gunner";
	*/

	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class AnimationSources: AnimationSources
	{
		/*
		class recoil_source
		{
			source="reload";
			weapon="RC_RHS_weap_M242BC";
		};
		class muzzle_hide_hmg: recoil_source
		{
		};
		class muzzle_rot_hmg: recoil_source
		{
			source="ammorandom";
		};
		class muzzle_rot_hmg2: muzzle_rot_hmg
		{
			weapon="RC_RHS_weap_m240_bradley_coax";
		};
		*/
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		class Hatch_Commander: Hatch_Commander
		{
			animPeriod=0.8;
		};
		/*
		class rear_hatch
		{
			source="door";
			animPeriod=0.80000001;
			initPhase=0;
		};
		*/
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
			defaultDisplay="EmptyDisplayComponent";

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
	};

	#include "\RC_RHS\loadouts\IFVitemsB_RHS.hpp"
};

class RC_APC_Stryker_M1126_MK19_WD: RC_Stryker_M1126_MK19_WD
{
	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			allowTabLock=1;

			weapons[]=
			{
				"RC_RHS_MK19_CROWS_M153",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"rhsusf_mag_L8A3_16"
			};

			class OpticsIn
			{
				class DaysightWFOV: ViewOptics
				{
					camPos="View_CROWS";
					//opticsDisplayName="1.0x";
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CROWS_monitor";
					initFov=0.9;
					minFov=0.025;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					hitpoint="Hit_Optic_CROWS_Day";
				};
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="VehicleDriverDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
					};
				};
			};
		};
	};
};


class RC_APC_Stryker_M1126_MK19_WD_B: RC_APC_Stryker_M1126_MK19_WD
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="M1126 Stryker Mk19";
	editorSubcategory="RC_RHS_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	maximumLoad=3000;
};


/*
	class UserActions: UserActions
	{
		class RaiseSMP
		{
			displayName="Raise Mine Plow";
			position="pos_gunnerpos";
			radius=2;
			showwindow=0;
			onlyforplayer=1;
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && this animationSourcePhase 'hide_SMP' < 0.5 && this animationSourcePhase 'SMP' < 0.5;";
			statement="this animateSource ['SMP', 1]";
		};
		class LowerSMP: RaiseSMP
		{
			displayName="Lower Mine Plow";
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && this animationSourcePhase 'hide_SMP' < 0.5 && this animationSourcePhase 'SMP' > 0.5;";
			statement="this animateSource ['SMP', 0]";
		};
		class SMP_TravelPosition_On: RaiseSMP
		{
			displayName="Switch Mine Plow to travel position";
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && {this animationSourcePhase 'hide_SMP' < 0.5} && {this animationSourcePhase 'SMP' > 0.5} && {this animationSourcePhase 'SMP_L' isEqualTo 0} && {this animationSourcePhase 'SMP_R' isEqualTo 0};";
			statement="this animateSource ['SMP_L', 1];this animateSource ['SMP_R', 1]";
		};
		class SMP_TravelPosition_Off: RaiseSMP
		{
			displayName="Switch Mine Plow to work position";
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && {this animationSourcePhase 'hide_SMP' < 0.5} && {this animationSourcePhase 'SMP' > 0.5} && {this animationSourcePhase 'SMP_L' isEqualTo 1} && {this animationSourcePhase 'SMP_R' isEqualTo 1};";
			statement="this animateSource ['SMP_L', 0];this animateSource ['SMP_R', 0]";
		};
		class LaneMarkingSystem_Activate
		{
			displayName="Activate Lane Marking System";
			position="pos_gunnerpos";
			radius=2;
			showwindow=0;
			onlyforplayer=1;
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && {this animationSourcePhase 'Dispenser_Fold' isEqualTo 0};";
			statement="this animateSource ['Dispenser_Fold', 1];this addWeaponTurret ['rhsusf_weap_laneMarkerSystem',[-1]]";
		};
	};
*/


class rhsusf_stryker_m1127_m2_wd;
class RC_Stryker_M1127_M2_WD_Base: rhsusf_stryker_m1127_m2_wd
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	//class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class Turret_LRAS;
	class ViewOptics;
	class AnimationSources;
	class ramp;
};
class RC_Stryker_M1127_M2_WD: RC_Stryker_M1127_M2_WD_Base
{
	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=2;
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
	//maxSpeed=66;
	//enginePower=447;
	//peakTorque=1660;

	//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
	//armorStructural=1000;	//280 //prevents instant explosion, does not make it stronger
	//hullExplosionDelay[]={15,20};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds

	//hullDamageCauseExplosion = 1; // vehicle will explode if HitHull is above 0.9
	//fuelExplosionPower=0.1;
	//secondaryExplosion=-1;

	/*
	//interesting values
	unitInfoType="RscOptics_AV_driverNoWeapon";
	memoryPointTaskMarker="TaskMarker_1_pos";
	cargoCanControlUAV=0;
	cargoIsCoDriver[]={0,0};
	killFriendlyExpCoef=0.1;
	transportSoldier=0;
	showNVGCargo[]={1};
	driverCompartments="Compartment3";
	cargoCompartments[]=
	{
		"Compartment2"
	};
	cargoProxyIndexes[]={1};
	getInProxyOrder[]={1};

	unitInfoType="RscOptics_AV_driver";
	//turret
	isCopilot=0;
	dontCreateAI=0;	//might be interesting to reduce script, or reduce commanding problems
	turretInfoType="RscOptics_UGV_gunner";
	*/

	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class AnimationSources: AnimationSources
	{
		/*
		class recoil_source
		{
			source="reload";
			weapon="RC_RHS_weap_M242BC";
		};
		class muzzle_hide_hmg: recoil_source
		{
		};
		class muzzle_rot_hmg: recoil_source
		{
			source="ammorandom";
		};
		class muzzle_rot_hmg2: muzzle_rot_hmg
		{
			weapon="RC_RHS_weap_m240_bradley_coax";
		};
		*/
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		/*
		class rear_hatch
		{
			source="door";
			animPeriod=0.80000001;
			initPhase=0;
		};
		*/
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
			defaultDisplay="EmptyDisplayComponent";

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
	};

	#include "\RC_RHS\loadouts\IFVitemsB_RHS.hpp"
};

class RC_ICV_Stryker_M1127_M2_WD: RC_Stryker_M1127_M2_WD
{
	class Turrets: Turrets
	{
		/*
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			allowTabLock=1;

			weapons[]=
			{
				"RC_RHS_M2_CROWS_M151",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_mag_200rnd_127x99",
				"RC_RHS_mag_200rnd_127x99_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"rhsusf_mag_L8A3_16"
			};

			class OpticsIn
			{
				class DaysightWFOV: ViewOptics
				{
					camPos="View_CROWS";
					//opticsDisplayName="1.0x";
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CROWS_monitor";
					initFov=0.9;
					minFov=0.025;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					hitpoint="Hit_Optic_CROWS_Day";
				};
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="VehicleDriverDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
					};
				};
			};
		};
		*/
		/*
		class Turret_Weapon: MainTurret
		{
			weapons[]=
			{
				"RHS_M2"
			};
			magazines[]=
			{
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red",
				"rhs_mag_100rnd_127x99_mag_Tracer_Red"
			};
		};
		*/
		//Give this datalink but not the M2?
		class Turret_LRAS: Turret_LRAS
		{
			weapons[]=
			{
				"rhs_weap_laserDesignator_AI"
			};
			magazines[]=
			{
				"rhs_LaserMag_ai"
			};
			class ViewGunner: ViewOptics
			{
				initAngleX=-5;
				initAngleY=0;
				initFov=0.89999998;
				minFov=0.25;
				maxFov=1.25;
				minAngleX=-65;
				maxAngleX=85;
				minAngleY=-150;
				maxAngleY=150;
				minMoveX=-0.075000003;
				maxMoveX=0.075000003;
				minMoveY=-0.075000003;
				maxMoveY=0.075000003;
				minMoveZ=-0.075000003;
				maxMoveZ=0.1;
			};
			class Components
			{
			};

			gunnerOutOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_LRAS3";
			turretInfoType="RHS_RscLRAS3";
			
			class OpticsIn
			{
				class Wide: ViewOptics
				{
					opticsDisplayName="4";
					initFov=0.175;
					minFov=0.175;
					maxFov=0.175;
					visionMode[]=
					{
						"TI"
					};
					thermalMode[]={2,3};
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CITV_w";
					hitpoint="Hit_Optic_LRAS3";
				};
				/*
				class WideZoom: Wide
				{
					opticsDisplayName="8";
					initFov=0.087499999;
					minFov=0.087499999;
					maxFov=0.087499999;
				};
				class Narrow: Wide
				{
					opticsDisplayName="12";
					initFov=0.0583333;
					minFov=0.0583333;
					maxFov=0.0583333;
				};
				class NarrowZoom: Wide
				{
					opticsDisplayName="24";
					initFov=0.0291667;
					minFov=0.0291667;
					maxFov=0.0291667;
				};
				class NarrowDoubleZoom: Wide
				{
					opticsDisplayName="48";
					initFov=0.0145833;
					minFov=0.0145833;
					maxFov=0.0145833;
				};
				*/
			};
			class OpticsOut
			{
				class Wide: ViewOptics
				{
					initFov=0.89999998;
					minFov=0.25;
					maxFov=1.25;
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_LRAS3";
					hitpoint="Hit_Optic_LRAS3";
				};
			};
		};
		class CargoTurret_02: CargoTurret_02
		{
		};
		class CargoTurret_03: CargoTurret_03
		{
		};
	};
};


class RC_ICV_Stryker_M1127_M2_WD_B: RC_ICV_Stryker_M1127_M2_WD
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			//make new script, deleting gunner only for all strykers
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="M1127 Stryker M2";
	editorSubcategory="RC_RHS_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	maximumLoad=3000;
};