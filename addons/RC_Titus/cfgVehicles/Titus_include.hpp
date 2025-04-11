#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
lockDetectionSystem="2+4+8";

faction="RemoteControlled_B";
crew="B_UAV_AI";
driverCompartments="Compartment3";
commanding=1;
forceHideDriver=1;
driverForceOptics=1;
//memoryPointDriverOptics="optika_velitel";

ejectDeadGunner=0;
ejectDeadDriver=0;
ejectDeadCommander=0;
crewCrashProtection=0.01;
enginePower=460;
peakTorque=1312.5;
maxSpeed=120;
normalSpeedForwardCoef=0.64;
class Reflectors {};	//removed, otherwise they are automatically on at night
aggregateReflectors[]={{""}};

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
			class VisualSensorComponent: SensorTemplateVisual
			{
				typeRecognitionDistance=500;

				class AirTarget
				{
					minRange=500;
					maxRange=500;
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
				animDirection="mainGun";
			};

			#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
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
	defaultDisplay="SensorDisplay";

	class Components
	{
		class SensorDisplay
		{
			componentType="SensorsDisplayComponent";
			range[]={500,1000,2000,4000};
			resource="RscCustomInfoSensors";
		};
		class MinimapDisplay
		{
			componentType="MinimapDisplayComponent";
			resource="RscCustomInfoMiniMap";
		};
		class VehicleGunnerDisplay
		{
			componentType="TransportFeedDisplayComponent";
			source="PrimaryGunner";
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

animationList[]=
{
	"comp_klec",
	0,
	"comp_camonet",
	0
};

class HitPoints: HitPoints
{
	#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
};

#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"