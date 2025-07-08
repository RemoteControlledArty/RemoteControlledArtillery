class B_W_qav_abramsx;
class RC_AbramsX_Core: B_W_qav_abramsx
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	class AnimationSources;
	class bashbar;
	class rubberskirts;
	class camonethull;
	class camonetturret;
	class TextureSources;
	class woodland;
	class desert;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_AbramsX_Base: RC_AbramsX_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_600m.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	faction="RemoteControlled_B";
	editorSubcategory="RC_MBT_subcat";
	author="Ascent";
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	/*
	maxSpeed=70;
	enginePower=1537.5;
	peakTorque=6250;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;
	*/
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet

	maxSpeed=121;
	enginePower=1216; //1100
	peakTorque=6500; //6500
	idleRPM=0; //1000
	redRPM=5000; //5000
	minOmega=__EVAL((0 * 2 * PI) / 60);
	maxOmega=__EVAL((5000 * 2 * PI) / 60);
	engineLosses=5; //25
	transmissionLosses=5; //15
	brakeDistance=3; //5
	brakeIdleSpeed=0.3; //0.1
	fuelCapacity=1909;

	irTarget=1;
	irTargetSize=0.7;
	radarTarget=1;
	radarTargetSize=0.7;

	torqueCurve[]=
	{
		{0,0},
		{0.00333505,1},
		{0.08333505,1},
		{0.16666804,1},
		{0.25000103,1},
		{0.33333402,1},
		{0.41666701,1},
		{0.5,1},
		{0.58333302,1},
		{0.66666698,1},
		{0.75,1},
		{0.83333302,1},
		{0.91666698,1},
		{1,1}
	};
	thrustDelay=0;
	accelAidForceCoef=3.5;
	accelAidForceYOffset=-3;
	accelAidForceSpd=2.83;

	mineDetectorRange=50;
	canAccessMineDetector=1;

	hiddenSelectionsTextures[]=
	{
		"QAV_AbramsX\data\textures\AbramsX\Woodland\AbramsX_Hull_co.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
	
	class TextureSources: TextureSources
	{
		class woodland: woodland
		{
			displayName="Woodland";
			textures[]=
			{
				"QAV_AbramsX\data\textures\AbramsX\Woodland\AbramsX_Hull_co.paa",
				"A3\Armor_F\Data\camonet_nato_green_co.paa"
			};
		};
		class desert: desert
		{
			displayName="Desert";
			textures[]=
			{
				"QAV_AbramsX\data\textures\AbramsX\desert\AbramsX_Hull_co.paa",
				"A3\Armor_F\Data\camonet_NATO_Desert_CO.paa"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class zasleh1_rot
		{
			source="ammorandom";
			weapon="RC_cannon_120mm_M360";
		};
		class zasleh1_hide
		{
			source="reload";
			weapon="RC_cannon_120mm_M360";
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
		class zasleh3_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm_M914";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_cannon_120mm_M360";
		};
		class commandergun_recoil
		{
			source="reload";
			weapon="RC_autocannon_30mm_M914";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_autocannon_30mm_M914";
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
					animDirection="mainGun";
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
					angleRangeVertical=180;
					animDirection="mainGun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=400;

					class AirTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					//animDirection="mainGun";
					animDirection="";
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
					range[]={600,2000,4000,6000};
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			//#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			minElev=-11;
			commanding=2;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_cannon_120mm_M360",
				"RC_AbramsX_20mm_coax",
				//"RC_QAV_AbramsX_HMG_coax",
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
					showAllTargets="2 + 4";
					commanding=1;
					turretInfoType="RscOptics_APC_Wheeled_01_gunner";

					weapons[]=
					{
						"RC_autocannon_30mm_M914",
						"Laserdesignator_mounted",
						"qav_SmokeLauncher"
					};
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_red.hpp"

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
								class MineDetectorDisplay
								{
									componentType="MineDetectorDisplayComponent";
									range=50;
									resource="RscCustomInfoMineDetect";
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
								/*
								class MineDetectorDisplay
								{
									componentType="MineDetectorDisplayComponent";
									range=50;
									resource="RscCustomInfoMineDetect";
								};
								*/
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
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
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
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
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
};


class RC_AbramsX_A: RC_AbramsX_Base
{
	class EventHandlers: EventHandlers
	{
		
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	displayName="AbramsX";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	crew="B_UAV_AI";
};
class RC_AbramsX_A_O: RC_AbramsX_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_green.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_green.hpp"
				};
			};
		};
	};
};
class RC_AbramsX_A_I: RC_AbramsX_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_yellow.hpp"
				};
			};
		};
	};
};


class RC_AbramsX_WD: RC_AbramsX_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_tow_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\mbt_addons_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AbramsX_WD_O: RC_AbramsX_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_green.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_green.hpp"
				};
			};
		};
	};
};
class RC_AbramsX_WD_I: RC_AbramsX_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_yellow.hpp"
				};
			};
		};
	};
};