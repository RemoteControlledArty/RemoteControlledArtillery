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

//maxSpeed=;
//enginePower=;
//peakTorque=;

//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
//armorStructural=1000;	//280 //prevents instant explosion, does not make it stronger
//hullExplosionDelay[]={15,20};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds

//hullDamageCauseExplosion = 1; // vehicle will explode if HitHull is above 0.9
//fuelExplosionPower=0.1;
//secondaryExplosion=-1;

/*
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
*/

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
		hitpoint="Hit_Optic_DVEA";
	};
	class DVS_Rear: DVE_Wide
	{
		camPos="view_rear";
		camDir="view_rear_dir";
		hitpoint="Hit_Optic_Driver_Rear";
	};
};

class UserActions: UserActions
{
	class AdjustMap {};
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