class VVE_APC_Wheeled_01_shorad_QAV;
class RC_AMV_SHORAD_Fetch: VVE_APC_Wheeled_01_shorad_QAV
{
	class EventHandlers;
	class UserActions;
	class Components;

	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;

	class AnimationSources;
	//class nethull;
	class armor_comp;
	class TextureSources;

	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;

	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_AMV_SHORAD_Core: RC_AMV_SHORAD_Fetch
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
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\EjectDeadCrew.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";

	driverCompartments="Compartment2";
	commanding=1;
	crewCrashProtection=0.01;

	smokeLauncherVelocity=5;
	smokeLauncherGrenadeCount=8;
	smokeLauncherAngle=360;

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};
};


class RC_AMV_SHORAD_Base: RC_AMV_SHORAD_Core
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	RC_ATrespondingTurret[]={0,0};

	displayName="Patria AMV SHORAD";
	editorSubcategory="RC_AntiAir_subcat";

	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=600;
	peakTorque=3000;

	weapons[]=
	{
		//"TruckHorn",
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Components
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
					typeRecognitionDistance=12000;

					class AirTarget
					{
						minRange=12000;
						maxRange=12000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=12000;
						maxRange=12000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=6000;

					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
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
					angleRangeHorizontal=60;	//30
					angleRangeVertical=60;		//30
					animDirection="mainGun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=400;

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
					animDirection="";		//"" "mainGun" "obsGun"
				};
				class ActiveRadarSensorComponent: SensorTemplateActiveRadar
				{
					typeRecognitionDistance=7500;

					class AirTarget
					{
						minRange=10000;
						maxRange=10000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=10000;
						maxRange=10000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					angleRangeHorizontal=120;
					angleRangeVertical=120;
					animDirection="mainGun";
					aimDown=-0.5;
					maxTrackableSpeed=1388.89;
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
					typeRecognitionDistance=1;
					
					class AirTarget
					{
						minRange=10000;
						maxRange=10000;
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
					//allowsMarking=1;	//targeting would be great, problem is just it tells name which seems a bit op?
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
					range[]={10000,6000,4000,600};
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
					range[]={600,4000,6000,10000};
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
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_VVE\cfgVehicles\includes_vehicle\panels_AMV_SHORAD.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;

			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000};
			//minElev=-;
			//maxElev=;

			weapons[]=
			{
				"RC_Single_autocannon_35mm_AA",
				"SmokeLauncher"
			};

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";

					minAngleX=-30;
					maxAngleX=30;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
				};
			};
			turretInfoType="RscOptics_MBT_03_gunner";
			//turretInfoType="RscOptics_APC_Wheeled_03_gunner";
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\RC_VVE\cfgVehicles\includes_vehicle\panels_AMV_SHORAD.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
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

					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";

							minAngleX=-30;
							maxAngleX=30;
							minAngleY=-100;
							maxAngleY=100;

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
						};
					};
					turretInfoType="RscOptics_MBT_03_gunner";
					//turretInfoType="RscOptics_APC_Wheeled_03_gunner";
				};

				class AdvisorOptics
				{
					#include "\RC_VVE\cfgVehicles\includes_vehicle\panels_AMV_SHORAD.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\AdvisorOptics.hpp"

					class OpticsIn
					{
						class Gun1
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";

							camPos="pos_view_gunner_gun";
							//camDir="pos_view_gunner_gun_dir";

							minAngleX=-30;	//?
							maxAngleX=30;	//?
							minAngleY=-100;	//?
							maxAngleY=100;	//?

							initFov=0.4;
							minFov=0.4;
							maxFov=0.4;
						};
						class Gun2: Gun1
						{
							initFov=0.1;
							minFov=0.1;
							maxFov=0.1;
						};
						class Gun3: Gun1
						{
							initFov=0.02;
							minFov=0.02;
							maxFov=0.02;
						};

						class Com1: Gun1
						{
							gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";

							camPos="commanderview";
							//camDir="commanderview_dir";

							initFov=0.5;
							minFov=0.5;
							maxFov=0.5;
						};
						class Com2: Com1
						{
							initFov=0.1;
							minFov=0.1;
							maxFov=0.1;
						};
						class Com3: Com1
						{
							initFov=0.02;
							minFov=0.02;
							maxFov=0.02;
						};
					};
					turretInfoType="RscOptics_MBT_03_gunner";
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class maingun_recoil
		{
			source="reload";
			weapon="RC_Single_autocannon_35mm_AA";
		};
		class zasleh1_hide
		{
			source="reload";
			weapon="RC_Single_autocannon_35mm_AA";
		};
		class zasleh1_rot
		{
			source="ammorandom";
			weapon="RC_Single_autocannon_35mm_AA";
		};
		/*
		class nethull: nethull
		{
			initPhase=1;
		};
		*/
		class armor_comp: armor_comp
		{
			initPhase=1;
		};
	};

	class TextureSources: TextureSources
	{
		class woodland
		{
			displayName="Woodland";
			textures[]=
			{
				"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_base_olive_CO.paa",
				"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_adds_olive_co.paa",
				"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_tows_olive_co.paa",
				"QAV_Marshall\data\textures\olive\apc_wheeled_01_mgs_co.paa",
				"QAV_Marshall\data\textures\olive\apc_wheeled_01_mgs_adds_co.paa",
				"QAV_Marshall\data\textures\olive\apc_wheeled_01_apc_co.paa",
				"a3\armor_f\data\camonet_green_co.paa",
				"VVE_Core\data\AAA_system_01\apc_wheeled_01_shorad_olive_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class arid
		{
			displayName="Arid";
			textures[]=
			{
				"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
				"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
				"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
				"QAV_Marshall\data\textures\apc_wheeled_01_mgs_co.paa",
				"QAV_Marshall\data\textures\apc_wheeled_01_mgs_adds_co.paa",
				"QAV_Marshall\data\textures\apc_wheeled_01_apc_co.paa",
				"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
				"VVE_Core\data\AAA_system_01\apc_wheeled_01_shorad_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
	};

	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
		"QAV_Marshall\data\textures\apc_wheeled_01_mgs_co.paa",
		"QAV_Marshall\data\textures\apc_wheeled_01_mgs_adds_co.paa",
		"QAV_Marshall\data\textures\apc_wheeled_01_apc_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"VVE_Core\data\AAA_system_01\apc_wheeled_01_shorad_co.paa"
	};
	textureList[]=
	{
		"arid",
		1
	};
};


/*
class RC_AMV_SHORAD_manned_A_B: RC_AMV_SHORAD_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_600Rnd_35mm_HEAB_AA_T_R",
				"RC_600Rnd_35mm_HEAB_AA_T_R",
				"RC_600Rnd_35mm_HEAB_AA_T_R"
			};
		};
	};
};
class RC_AMV_SHORAD_manned_A_O: RC_AMV_SHORAD_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_600Rnd_35mm_HEAB_AA_T_G",
				"RC_600Rnd_35mm_HEAB_AA_T_G",
				"RC_600Rnd_35mm_HEAB_AA_T_G"
			};
		};
	};
};
class RC_AMV_SHORAD_manned_A_I: RC_AMV_SHORAD_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_600Rnd_35mm_HEAB_AA_T_Y",
				"RC_600Rnd_35mm_HEAB_AA_T_Y",
				"RC_600Rnd_35mm_HEAB_AA_T_Y"
			};
		};

	};
};
class RC_AMV_SHORAD_manned_WD_B: RC_AMV_SHORAD_manned_A_B
{
	#include "\RC_VVE\textures\AMV_SHORAD_Texture_WD.hpp"
};
class RC_AMV_SHORAD_manned_WD_O: RC_AMV_SHORAD_manned_A_O
{
	#include "\RC_VVE\textures\AMV_SHORAD_Texture_WD.hpp"
};
class RC_AMV_SHORAD_manned_WD_I: RC_AMV_SHORAD_manned_A_I
{
	#include "\RC_VVE\textures\AMV_SHORAD_Texture_WD.hpp"
};
*/


class RC_AMV_SHORAD_UV_Base: RC_AMV_SHORAD_Base
{
	displayName="RC Patria AMV SHORAD";
	
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	driverForceOptics=1;
	forceHideDriver=1;

	uavCameraDriverPos="driverview";
	uavCameraDriverDir="driverview";
	uavCameraGunnerPos="pos_view_gunner_gun";
	uavCameraGunnerDir="pos_view_gunner_gun_dir";
	
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//cannot yet be driven when RCing gunner from commander seat
			gunnerCompartments="Compartment3";
			dontCreateAI=0;
			gunnerForceOptics=1;
			forceHideGunner=1;
		};
	};
};
class RC_AMV_SHORAD_A_B: RC_AMV_SHORAD_UV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_600Rnd_35mm_HEAB_AA_T_R",
				"RC_600Rnd_35mm_HEAB_AA_T_R",
				"RC_600Rnd_35mm_HEAB_AA_T_R"
			};
		};
	};
};
class RC_AMV_SHORAD_A_O: RC_AMV_SHORAD_UV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_600Rnd_35mm_HEAB_AA_T_G",
				"RC_600Rnd_35mm_HEAB_AA_T_G",
				"RC_600Rnd_35mm_HEAB_AA_T_G"
			};
		};
	};
};
class RC_AMV_SHORAD_A_I: RC_AMV_SHORAD_UV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_600Rnd_35mm_HEAB_AA_T_Y",
				"RC_600Rnd_35mm_HEAB_AA_T_Y",
				"RC_600Rnd_35mm_HEAB_AA_T_Y"
			};
		};

	};
};
class RC_AMV_SHORAD_WD_B: RC_AMV_SHORAD_A_B
{
	#include "\RC_VVE\textures\AMV_SHORAD_Texture_WD.hpp"
};
class RC_AMV_SHORAD_WD_O: RC_AMV_SHORAD_A_O
{
	#include "\RC_VVE\textures\AMV_SHORAD_Texture_WD.hpp"
};
class RC_AMV_SHORAD_WD_I: RC_AMV_SHORAD_A_I
{
	#include "\RC_VVE\textures\AMV_SHORAD_Texture_WD.hpp"
};