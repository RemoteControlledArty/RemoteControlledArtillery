author="Ascent";
faction="RemoteControlled_B";
editorSubcategory="RC_Titus_subcat";
side=0;
vehicleClass="Autonomous";
uavCameraDriverPos="PiP0_pos";
uavCameraDriverDir="PiP0_dir";
isUav=1;
textPlural="UGVs";
textSingular="UGV";
crew="B_UAV_AI";
forceHideDriver=1;
driverForceOptics=1;
commanding=1;
//memoryPointDriverOptics="optika_velitel";
driverCompartments="Compartment3";
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
enginePower=460;
peakTorque=1312.5;
maxSpeed=120;
normalSpeedForwardCoef=0.64;

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

			#include "\Remote_Controlled_Artillery\includes\passiveRadar.hpp"
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
		class VehicleDriverDisplay
		{
			componentType="TransportFeedDisplayComponent";
			source="Driver";
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

class AnimationSources: AnimationSources
{
	class Door_LF: Door_LF
	{
		animPeriod=0.5;
	};
	class Door_RF: Door_RF
	{
		animPeriod=0.5;
	};
	class Door_rear: Door_rear
	{
		animPeriod=0.8;
	};
	class comp_camonet: comp_camonet
	{
		initPhase=1;
	};
	class comp_klec: comp_klec
	{
		initPhase=1;
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
	class HitLFWheel: HitLFWheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
	class HitLF2Wheel: HitLF2Wheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
	class HitLMWheel: HitLMWheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
	class HitLBWheel: HitLBWheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
	class HitRFWheel: HitRFWheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
	class HitRF2Wheel: HitRF2Wheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
	class HitRMWheel: HitRMWheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
	class HitRBWheel: HitRBWheel
	{
		armor=-500;
		minimalHit=-0.016000001;
		explosionShielding=2;
		passThrough=0;
	};
};

#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"