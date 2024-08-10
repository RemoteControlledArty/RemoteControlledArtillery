class RHS_M2A2;
class RC_M2A2_Base: RHS_M2A2
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
	class HatchC;
};
class RC_M2A2_D_Base: RC_M2A2_Base
{
	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=2;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	radartype=2;
	reportOwnPosition=1;
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
	maxSpeed=75;
	enginePower=670;
	peakTorque=2490;

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
		class DVE_Wide: ViewOptics
		{
			camPos="view_DVE";
			opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
			visionMode[]=
			{
				"TI",
				"Normal"
			};
			thermalMode[]={0};
			initFov=1.07692;
			minFov=1.07692;
			maxFov=1.07692;
			hitpoint="Hit_Optics_Dvr_DVE";
		};
		class DVS_Rear: DVE_Wide
		{
			camPos="view_rear";
			camDir="view_rear_dir";
			opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE2_4x3";
			hitpoint="Hit_Optics_Dvr_RearCam";
		};
	};

	class AnimationSources: AnimationSources
	{
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
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		class HatchC: HatchC
		{
			animPeriod=0.8;
		};
		class HatchG: HatchC
		{
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

	#include "\RC_RHS\loadouts\IFVitemsB_RHS_old.hpp"
};

class RC_M2A2_D: RC_M2A2_D_Base
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			//isCopilot=1; //allows to trigger EH that gives driving controls

			//showAllTargets="2 + 4";
			commanding=3;
			allowTabLock=1;

			weapons[]=
			{
				"RC_RHS_weap_M242BC",
				"RC_RHS_weap_m240_bradley_coax",
				"RC_RHS_weap_TOW_Launcher",
				"rhs_weap_fcs_ammo",

				"rhsusf_weap_M257_8"
			};
			magazines[]=
			{
				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_1100Rnd_762x51_M61_T_R",
				"RC_RHS_mag_1100Rnd_762x51_M61_T_R",
				"RC_RHS_mag_2Rnd_TOW2A",
				"RC_RHS_mag_2Rnd_TOW2A",
				"RC_RHS_mag_2Rnd_TOW2A",
				"RC_RHS_mag_2Rnd_TOW2BB",
				"rhs_laserfcsmag",

				"rhsusf_mag_L8A3_8",
				"rhsusf_mag_L8A3_8"
			};
			
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
					minFov=0.025;
					maxFov=0.9;		//larger FOV for improved usability on servers without third person
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
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					//#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
					//isCopilot=1; //allows to trigger EH that gives driving controls
					//showAllTargets="2 + 4";
					commanding=2;
					allowTabLock=1;
					
					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						"rhsusf_weap_M257_8"
					};
					magazines[]=
					{
						"Laserbatteries",
						"rhsusf_mag_L8A3_8",
						"rhsusf_mag_L8A3_8"
					};
					
					class Components: Components
					{
						class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
						{
							defaultDisplay="SensorDisplay";

							class Components
							{
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
								class VehicleGunnerDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="PrimaryGunner";
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
							};
						};
						class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
						{
							defaultDisplay="VehicleDriverDisplay";

							class Components
							{
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
								class VehicleGunnerDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="PrimaryGunner";
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
							};
						};
					};
				};
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					//defaultDisplay="SensorDisplay";

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


class RC_M2A2_D_B: RC_M2A2_D
{
	class EventHandlers: EventHandlers
	{	
		class RHSUSF_EventHandlers
		{
			postInit="_this call rhs_fnc_reapplyTextures";
			getIn="_this call rhs_fnc_m2_doors";
			getOut="_this call rhs_fnc_m2_doors";
		};
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
			//#include "\Remote_Controlled_Artillery\includes\dev_takeDriverControlsEH1.hpp"
		};
	};

	displayName="M2A2 Bradley";
	editorSubcategory="RC_RHS_D_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
	//forceHideDriver=1;
	//driverForceOptics=1;
};


class RC_M2A2_WD_B: RC_M2A2_D_B
{
	editorSubcategory="RC_RHS_WD_subcat";
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\RHS_M2A2_wd.paa";
	hiddenSelectionsTextures[]=
	{
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\base_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\a3_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\ultralp_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\base_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\base_co.paa"
	};
};


class RC_M2A2_D_I: RC_M2A2_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS_old.hpp"
};
class RC_M2A2_WD_I: RC_M2A2_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS_old.hpp"
};