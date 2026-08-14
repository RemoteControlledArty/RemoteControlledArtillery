class rhsusf_m113_usarmy_unarmed;
class RC_M113_Core: rhsusf_m113_usarmy_unarmed
{
	class Components;
	class HitPoints;
	class ViewOptics;
	class Turrets;
	class HitBody;
	class HitFuel;
	class HitEngine;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class TextureSources;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_M113_Base: RC_M113_Core
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

		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargoFuel_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\driverCam1x.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	memoryPointDriverOptics="P svetlo";

	author="Ascent";
	//armor=200;
	crewCrashProtection=0;

	//threat[]={0,0,0};
	//cost=0;
	//typicalCargo[]={""};
	
	maximumLoad=3500;
	canHideGunner=1;
	forceHideDriver=1;
	driverForceOptics=1;
	//camouflage=1;	//2
	//audible=2.5;	//5

	maxSpeed=90;			//72
	enginePower=256;		//205
	engineStartSpeed=0.5;	//5
	peakTorque=962;			//770

	smokeLauncherOnTurret=0;
	smokeLauncherVelocity=6;
	smokeLauncherGrenadeCount=6;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

	weapons[]=
	{
		"RC_target_confirmer_datalink",
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class DriverTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_car.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\DriverTurret.hpp"

			primaryObserver = 1;
			memoryPointGunnerOptics = "P svetlo";			//P svetlo

			gunnerAction = "rhs_mrzr_driver";				//Driver_MBT_03_cannon_F_out
			gunnerInAction = "";							//Driver_MBT_03_cannon_F_in
			gunnerLeftHandAnimName = "steeringwheel";		//drivewheel
			gunnerRightHandAnimName = "steeringwheel";		//drivewheel
			gunnerLeftLegAnimName = "";						//pedal_brake
			gunnerRightLegAnimName = "pedal_thrust";		//pedal_thrust

			//gunnerCompartments="Compartment1";
			//gunnerOpticsModel="";
			//turretInfoType="";

			class OpticsIn
			{
				class Driver
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

					initFov=1;
					minFov=0.25;
					maxFov=1;
				};
			};

			weapons[]=
			{
				"RC_target_confirmer_datalink",
				"TruckHorn",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_target_confirmer_mag",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};

	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_01_d_l_co.paa",
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_02_d_l_co.paa",
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_03_d_co.paa",
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_d_co.paa"
	};

	class TextureSources: TextureSources
	{
		class olive
		{
			displayName="Olive";
			textures[]=
			{
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_01_od_l_co.paa",
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_02_od_l_co.paa",
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_03_wd_co.paa",
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_wd_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class desert
		{
			displayName="Desert";
			textures[]=
			{
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_01_d_l_co.paa",
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_02_d_l_co.paa",
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_03_d_co.paa",
				"rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_d_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
	};
	/*
	textureList[]=
	{
		"Green",
		1
	};
	*/

	/*
	class HitPoints: HitPoints
	{
		class HitBody: HitBody
		{
			explosionShielding=1;	//1.5
		};
		class HitFuel: HitFuel
		{
			armor=1;			//0.5
			passThrough=0.15;	//0.2
		};
		class HitEngine: HitEngine
		{
			armor=1;			//0.5
			passThrough=0.15;	//0.2
		};
	};
	*/

	class Reflectors
	{
		class LSvetla
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\reflectorsOff.hpp"
			
			direction = "konec L svetla";
			hitpoint = "L svetlo";
			position = "L svetlo";
			selection = "L svetlo";
		};
		class RSvetla: LSvetla
		{
			direction = "konec P svetla";
			hitpoint = "P svetlo";
			position = "P svetlo";
			selection = "P svetlo";
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
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=8000;

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
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="";
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
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
					range[]={4000,2000,400};
					resource="RscCustomInfoSensors";
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
					range[]={400,2000,4000};
					resource="RscCustomInfoSensors";
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
			};
		};
	};

	#include "\RC_RHS\loadouts\FSVitemsB_RHS.hpp"
};


class RC_M113_D: RC_M113_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CommanderIsDriverEH.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"

	displayName="RC M113";
	faction="RemoteControlled_B";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	isUav=1;
	driverForceOptics=1;
	vehicleClass="Autonomous";
	driverCompartments="Compartment2";
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";

	uavCameraDriverPos="P svetlo";
	uavCameraDriverDir="P svetlo";
};
class RC_M113_D_O: RC_M113_D
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsO_RHS.hpp"
};
class RC_M113_D_I: RC_M113_D
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


class RC_M113_WD: RC_M113_D
{
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_01_od_l_co.paa",
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_02_od_l_co.paa",
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_03_wd_co.paa",
		"rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_wd_co.paa"
	};
};
class RC_M113_WD_O: RC_M113_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsO_RHS.hpp"
};
class RC_M113_WD_I: RC_M113_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};