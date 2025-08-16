class EventHandlers: EventHandlers
{
	class RC_Artillery
	{
		#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
	};
	class RC_Detection
	{
		#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_600m.hpp"
	};
	class RC_AT_Warning
	{
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
	};
	class RC_LightsOff
	{
		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
	};
};

RC_ATrespondingTurret[]={0,0};
//RC_ignoreRockets=1;

weapons[]=
{
	"RC_APS_W",
	"qav_SmokeLauncher"
};
magazines[]=
{
	"RC_1Rnd_APS_M",
	"RC_1Rnd_APS_M",

	"RC_1Rnd_APS_M",
	"RC_1Rnd_APS_M",
	"RC_1Rnd_APS_M",
	"RC_1Rnd_APS_M",
	"qav_SmokeLauncherMag",
	"qav_SmokeLauncherMag"
};

#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
lockDetectionSystem="2+4+8";
canAccessMineDetector=1;
mineDetectorRange=50;

faction="RemoteControlled_B";
editorSubcategory="RC_MBT_subcat";
author="Ascent";
driverCompartments="Compartment2";
ejectDeadGunner=0;
ejectDeadDriver=0;
ejectDeadCommander=0;
crewCrashProtection=0.01;

//experimental values for testing, maybe removed later
armor=800;
//armorStructural=5;	//5

class HitPoints: HitPoints
{
	class HitHull: HitHull
	{
		armor=2;  //1.8
		passThrough=0.75; //1
	};
	class HitLTrack: HitLTrack
	{
		explosionShielding=0.7;
	};
	class HitRTrack: HitRTrack
	{
		explosionShielding=0.7;
	};
};

radarTargetSize=0.75;
irTargetSize=0.75;
fuelCapacity=1800;
maxSpeed=110;
peakTorque=6250;
enginePower=1200;
redRPM=5000;
idleRPM=0;
maxOmega=__EVAL((5000*2*PI)/60);
minOmega=__EVAL((0*2*PI)/60);
brakeIdleSpeed=0.31;
brakeDistance=3.5;
thrustDelay=0;
transmissionLosses=6;
engineLosses=6;
accelAidForceCoef=3.6;
accelAidForceSpd=2.9;
accelAidForceYOffset=-3;
torqueCurve[]={{0,0},{0.00333505,1},{0.08333505,1},{0.16666804,1},{0.25000103,1},{0.33333402,1},{0.41666701,1},{0.5,1},{0.58333302,1},{0.66666698,1},{0.75,1},{0.83333302,1},{0.91666698,1},{1,1}};

hiddenSelectionsTextures[]=
{
	"QAV_AbramsX\data\textures\AbramsX\Pacific\AbramsX_Hull_co.paa",
	"a3\armor_f\data\camonet_green_co.paa"
};
class TextureSources: TextureSources
{
	class woodland: woodland
	{
		displayName="Woodland";
		textures[]=
		{
			"QAV_AbramsX\data\textures\AbramsX\Pacific\AbramsX_Hull_co.paa",
			"a3\armor_f\data\camonet_green_co.paa"
		};
		factions[]=
		{
			"RemoteControlled_B",
			"RemoteControlled_O",
			"RemoteControlled_I"
		};
	};
	class arid: arid
	{
		displayName="Arid";
		textures[]=
		{
			"QAV_AbramsX\data\textures\AbramsX\AbramsX_Hull_co.paa",
			"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
		};
		factions[]=
		{
			"RemoteControlled_B",
			"RemoteControlled_O",
			"RemoteControlled_I"
		};
	};
};
textureList[]=
{
	"woodland",
	1
};
class AnimationSources: AnimationSources
{
	class zasleh1_rot
	{
		source="ammorandom";
		weapon="RC_AbramsX_120mm_M360";
	};
	class zasleh1_hide
	{
		source="reload";
		weapon="RC_AbramsX_120mm_M360";
	};
	class recoil_source
	{
		source="reload";
		weapon="RC_AbramsX_120mm_M360";
	};
	class zasleh2_rot
	{
		source="ammorandom";
		weapon="RC_AbramsX_20mm_coax";
	};
	class zasleh2_hide
	{
		source="reload";
		weapon="RC_AbramsX_20mm_coax";
	};
	class bashbar: bashbar
	{
		initPhase=1;
	};
	class rubberskirts: rubberskirts
	{
		initPhase=1;
	};
	class camonethull: camonethull
	{
		initPhase=1;
	};
	class camonetturret: camonetturret
	{
		initPhase=1;
	};
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
				typeRecognitionDistance=6000;

				class AirTarget
				{
					minRange=6000;
					maxRange=6000;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=6000;
					maxRange=6000;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
			};
			class IRSensorComponent: SensorTemplateIR
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
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				maxTrackableSpeed=600;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="obsGun";
			};
			class ManSensorComponent: SensorTemplateMan
			{
				typeRecognitionDistance=600;

				class AirTarget
				{
					minRange=600;
					maxRange=600;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=600;
					maxRange=600;
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				maxTrackableSpeed=15;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="obsGun";
			};
			class VisualSensorComponent: SensorTemplateVisual
			{
				typeRecognitionDistance=600;

				class AirTarget
				{
					minRange=600;
					maxRange=600;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=600;
					maxRange=600;
					objectDistanceLimitCoef=1;
					viewDistanceLimitCoef=1;
				};
				maxTrackableSpeed=600;
				nightRangeCoef=0.80000001;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="obsGun";
			};
			class ActiveRadarSensorComponent: SensorTemplateActiveRadar
			{
				typeRecognitionDistance=6000;

				class AirTarget
				{
					minRange=6000;
					maxRange=6000;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=6000;
					maxRange=6000;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				angleRangeHorizontal=360;
				angleRangeVertical=180;
				aimDown=0;
				groundNoiseDistanceCoef=0;
				maxGroundNoiseDistance=0;
				maxTrackableSpeed=694.44397;
				animDirection="obsGun";
			};
			class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
			{
				class AirTarget
				{
					minRange=8000;
					maxRange=8000;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				class GroundTarget
				{
					minRange=8000;
					maxRange=8000;
					objectDistanceLimitCoef=-1;
					viewDistanceLimitCoef=-1;
				};
				allowsMarking=1;
				animDirection="obsGun";
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
				range[]={6000,4000,2000,600};
				resource="RscCustomInfoSensors";
			};
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
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
		defaultDisplay="EmptyDisplayComponent";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={600,2000,4000,6000};
				resource="RscCustomInfoSensors";
			};
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
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

class Turrets: Turrets
{
	class MainTurret: MainTurret
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
		//#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
		#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
		dontCreateAI=1;
		canAccessMineDetector=1;
		//minElev=-12;	//doesnt work
		commanding=2;
		turretInfoType="RscOptics_APC_Wheeled_01_gunner";

		weapons[]=
		{
			"RC_AbramsX_120mm_M360",
			"RC_AbramsX_20mm_coax",
			//"RC_AbramsX_HMG_coax",
			"qav_SmokeLauncher"
		};
		#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_red.hpp"

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
				minFov=0.01;
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
		
		class Turrets: Turrets
		{
			class CommanderOptics: CommanderOptics
			{
				#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
				//#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_commander_600m_cUAS.hpp"
				dontCreateAI=1;
				canAccessMineDetector=1;
				showAllTargets="2 + 4";
				commanding=1;
				maxElev=50;
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";

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
						minFov=0.01;
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

				class HitPoints: HitPoints
				{
					class HitComTurret: HitComTurret
					{
						armor=0.3;
						explosionShielding=0.8;
					};
					class HitComGun: HitComGun
					{
						armor=0.3;
						explosionShielding=0.8;
					};
				};

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
								range[]={6000,4000,2000,600};
								resource="RscCustomInfoSensors";
							};
							class UAVFeedDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class MineDetectorDisplay
							{
								componentType="MineDetectorDisplayComponent";
								range=50;
								resource="RscCustomInfoMineDetect";
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
							/*
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
								resource="RscCustomInfoMiniMap";
							};
							*/
							/*
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							*/
						};
					};
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						defaultDisplay="SensorDisplay";

						class Components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={600,2000,4000,6000};
								resource="RscCustomInfoSensors";
							};
							class UAVFeedDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class MineDetectorDisplay
							{
								componentType="MineDetectorDisplayComponent";
								range=50;
								resource="RscCustomInfoMineDetect";
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
				defaultDisplay="SensorDisplay";

				class Components
				{
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={6000,4000,2000,600};
						resource="RscCustomInfoSensors";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class MineDetectorDisplay
					{
						componentType="MineDetectorDisplayComponent";
						range=50;
						resource="RscCustomInfoMineDetect";
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
					/*
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					*/
					/*
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					*/
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				defaultDisplay="SensorDisplay";

				class Components
				{
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={600,2000,4000,6000};
						resource="RscCustomInfoSensors";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class MineDetectorDisplay
					{
						componentType="MineDetectorDisplayComponent";
						range=50;
						resource="RscCustomInfoMineDetect";
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

#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"