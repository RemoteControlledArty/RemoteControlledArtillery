class RHS_M2A3_BUSKIII;
class RC_M2A3_BUSKIII_D_Base: RHS_M2A3_BUSKIII
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class AnimationSources;
	class ramp;
};
class RC_M2A3_BUSKIII_IFV_D_base: RC_M2A3_BUSKIII_D_Base
{
	author="Ascent";
	scope=0;
	scopeCurator=0;
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
		class ramp: ramp
		{
			animPeriod=1;
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

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};

class RC_M2A3_BUSKIII_IFV_D: RC_M2A3_BUSKIII_IFV_D_base
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			//minElev=-9;
			//maxElev=57;
			//turretInfoType="RscOptics_APC_Wheeled_01_gunner";
			allowTabLock=1;

			weapons[]=
			{
				"RHS_weap_M242BC",
				"rhs_weap_m240_bradley_coax",
				"Rhs_weap_TOW_Launcher",
				"rhs_weap_fcs_ammo",

				"SmokeLauncher"
			};
			magazines[]=
			{
				"rhs_mag_1100Rnd_762x51_M240",
				"rhs_mag_1100Rnd_762x51_M240",
				"rhs_mag_230Rnd_25mm_M242_HEI",
				"rhs_mag_230Rnd_25mm_M242_HEI",
				"rhs_mag_230Rnd_25mm_M242_HEI",
				"rhs_mag_70Rnd_25mm_M242_APFSDS",
				"rhs_mag_70Rnd_25mm_M242_APFSDS",
				"rhs_mag_70Rnd_25mm_M242_APFSDS",
				"rhs_mag_70Rnd_25mm_M242_APFSDS",
				"rhs_mag_70Rnd_25mm_M242_APFSDS",
				"rhs_mag_2Rnd_TOW2A",
				"rhs_mag_2Rnd_TOW2A",
				"rhs_mag_2Rnd_TOW2A",
				"rhs_mag_2Rnd_TOW2BB",
				"rhs_laserfcsmag",

				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			/*
			weapons[]=
			{
				"RC_RHS_weap_M242BC",
				"RC_rhs_weap_m240_bradley_coax",
				"RC_Rhs_weap_TOW_Launcher",
				"RC_rhs_weap_fcs_ammo",

				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_rhs_mag_1100Rnd_762x51_M240",
				"RC_rhs_mag_1100Rnd_762x51_M240",
				"RC_rhs_mag_230Rnd_25mm_M242_HEI",
				"RC_rhs_mag_230Rnd_25mm_M242_HEI",
				"RC_rhs_mag_230Rnd_25mm_M242_HEI",
				"RC_rhs_mag_70Rnd_25mm_M242_APFSDS",
				"RC_rhs_mag_70Rnd_25mm_M242_APFSDS",
				"RC_rhs_mag_70Rnd_25mm_M242_APFSDS",
				"RC_rhs_mag_70Rnd_25mm_M242_APFSDS",
				"RC_rhs_mag_70Rnd_25mm_M242_APFSDS",
				"RC_rhs_mag_2Rnd_TOW2A",
				"RC_rhs_mag_2Rnd_TOW2A",
				"RC_rhs_mag_2Rnd_TOW2A",
				"RC_rhs_mag_2Rnd_TOW2BB",
				"RC_rhs_laserfcsmag",

				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			*/
			
			/*
			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="WIDE";
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.9;
					minFov=0.0166;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"Ti"
					};
					thermalMode[]={0};
					//thermalMode[]={4};
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_ISU";
					gunnerOpticsEffect[]={};
					hitPoint="Hit_Optics_Gnr";
				};
				//class Narrow: Wide
				//{
				//	opticsDisplayName="NARROW";
				//	initFov=0.0583333;
				//	minFov=0.0583333;
				//	maxFov=0.0583333;
				//};
			};
			*/

			/*
			class OpticsIn
			{
				class Wide: RCWSOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.0166;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			*/
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
					showAllTargets="2 + 4";
					//turretInfoType="RscOptics_MBT_03_gunner";
					commanding=2;

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

					/*
					class ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.155;
						minFov=0.067000002;
						maxFov=0.155;
					};
					*/

					/*
					class OpticsIn
					{
						class VisionBlock
						{
							opticsDisplayName="periscope";
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;
							initfov=0.9;
							minFov=0.0166;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"Ti"
							};
							thermalMode[]={0};
							gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_vision_block";
							gunnerOpticsEffect[]={};
							hitPoint="Hit_Optics_Cdr_Peri";
						};
						class Wide
						{
							camPos="gunnerview";
							opticsDisplayName="WIDE";
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;
							initfov=0.9;
							minFov=0.0166;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"Ti"
							};
							thermalMode[]={0};
							gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_ISU";
							gunnerOpticsEffect[]={};
							hitPoint="Hit_Optics_Gnr";
						};
					};
					*/

					/*
					class OpticsIn
					{
						class Wide: RCWSOptics
						{
							//directionStabilized=1;	//unfortunately causes spinning camera bug

							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;

							initFov=0.9;
							minFov=0.0166;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={0};
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
					*/

					/*
					//no stabilization effect
					class ViewOptics: ViewOptics
					{
						directionStabilized=1;
						
						initFov=0.9;
						minFov=0.0166;
						maxFov=0.9;
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={0};
					};
					*/

					class Components: Components
					{
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
								/*
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
								};
								*/
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
							defaultDisplay="VehicleDriverDisplay";

							class Components
							{
								class SensorDisplay
								{
									componentType="SensorsDisplayComponent";
									range[]={4000,2000,1000,500};
									resource="RscCustomInfoSensors";
								};
								/*
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
								};
								*/
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
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						*/
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
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						*/
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
	};
};

class RC_M2A3_BUSKIII_IFV_D_B: RC_M2A3_BUSKIII_IFV_D
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="M2A3 Bradley";
	editorSubcategory="RC_IFV_APC_subcat";
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
};


/*
class RC_AMPV_BUSKIII_ICV_D_B: RC_M2A3_BUSKIII_IFV_D
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initICV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
		};
	};

	displayName="AMPV";
	editorSubcategory="RC_Stryker_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RC_Stryker_B";
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
};
*/
/*
class RC_AMPV_BUSKIII_ICV_D_I: RC_AMPV_BUSKIII_ICV_D_B
{

};
*/


class RC_M2A3_BUSKIII_DL_IFV_D_B: RC_M2A3_BUSKIII_IFV_D
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initDL.hpp"
			//#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="DL M2A3 Bradley";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="";
	hasDriver=-1;
};