class B_Quadbike_01_F;
class RC_Quadbike_Core: B_Quadbike_01_F
{
	class Components;
	class HitPoints;
	class ViewOptics;
	class Turrets;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class CargoTurret_04;
	class CargoTurret_05;
	class HitHull;
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
class RC_Quadbike_Base: RC_Quadbike_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			//#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		/*
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		*/

		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargoFuel_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\driverCam1x.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	memoryPointDriverOptics="Light_L";

	author="Ascent";
	//armor=40;		//30
	crewCrashProtection=0;
	enableGPS=1;

	threat[]={0,0,0};
	cost=0;
	typicalCargo[]={""};
	
	maximumLoad=1200;	//600
	canHideGunner=1;
	camouflage=1;	//2
	audible=2.5;	//5

	maxSpeed=100;			//80
	enginePower=30;			//25
	engineStartSpeed=0.5;	//1.5
	peakTorque=300;			//280

	smokeLauncherOnTurret=0;
	smokeLauncherVelocity=4;
	smokeLauncherGrenadeCount=4;
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

	class PlayerSteeringCoefficients
	{
		turnIncreaseConst=0.8;	//0.8
		turnIncreaseLinear=2;
		turnIncreaseTime=1;

		turnDecreaseConst=9;
		turnDecreaseLinear=0;
		turnDecreaseTime=0;

		maxTurnHundred=0.5;	//0.8
	};

	class Turrets: Turrets
	{
		class DriverTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_car.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\DriverTurret.hpp"

			primaryObserver = 1;
			memoryPointGunnerOptics = "Light_L";			//P svetlo

			gunnerAction = "driver_quadbike";				//Driver_MBT_03_cannon_F_out
			gunnerInAction = "";							//Driver_MBT_03_cannon_F_in
			gunnerLeftHandAnimName = "drivewheel";			//drivewheel
			gunnerRightHandAnimName = "drivewheel";		//drivewheel
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
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

					minAngleX=-30;	//?
					maxAngleX=30;	//?
					minAngleY=-100;	//?
					maxAngleY=100;	//?

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
		/*
		class CargoTurret_01: CargoTurret_01
		{
			gunnerName="Front Right";
			gunnerCompartments="Compartment1";
		};
		*/
	};

	class TextureSources: TextureSources
	{
		class arid
		{
			displayName="Arid";
			textures[]=
			{
				"\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa",
				"\A3\Soft_F\Quadbike_01\Data\Quadbike_01_wheel_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class olive: arid
		{
			displayName="Olive";
			textures[] =
			{
				"\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_olive_CO.paa",
				"\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_wheel_olive_CO.paa"
			};
		};
		class black: arid
		{
			displayName="Black";
			textures[] =
			{
				"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa",
				"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa"
			};
		};
		class white: arid
		{
			displayName="White";
			textures[] =
			{
				"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_WHITE_CO.paa",
				"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVWHITE_CO.paa"
			};
		};
	};
	textureList[]=
	{
		"arid",
		1
	};

	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=2;				//1.5
			explosionShielding=4;	//8
			passThrough=0.5;		//0.5
		};
		class HitBody: HitBody
		{
			armor=1.25;				//1
			explosionShielding=1;	//1.5
			passThrough=1;
		};
		class HitFuel: HitFuel
		{
			armor=3;			//2
			passThrough=0;		//0
		};
		class HitEngine: HitEngine
		{
			armor=1.5;			//0.5
			passThrough=0.15;	//0.2
		};
		class HitLFWheel: HitLFWheel
		{
			armor=-120;				//-80
			explosionShielding=1;	//4
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-120;
			explosionShielding=1;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-120;
			explosionShielding=1;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-120;
			explosionShielding=1;
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

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};


class RC_Quadbike_A: RC_Quadbike_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CommanderIsDriverEH.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"

	displayName="RC Quadbike";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Car_subcat";
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

	uavCameraDriverPos="Light_L";
	uavCameraDriverDir="Light_L";

	//cost=0;
};
class RC_Quadbike_A_O: RC_Quadbike_A
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};
class RC_Quadbike_A_I: RC_Quadbike_A
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"
};


class RC_Quadbike_WD: RC_Quadbike_A
{
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_olive_CO.paa",
		"\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_wheel_olive_CO.paa"
	};
	textureList[]=
	{
		"olive",
		1
	};
};
class RC_Quadbike_WD_O: RC_Quadbike_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};
class RC_Quadbike_WD_I: RC_Quadbike_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"
};