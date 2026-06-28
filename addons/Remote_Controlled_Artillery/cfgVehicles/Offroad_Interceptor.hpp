//Flatbed Truck with 105mm M119
class I_G_Offroad_01_AT_F;
class RC_Offroad_Interceptor_Fetch: I_G_Offroad_01_AT_F
{
	class ViewOptics;
	class Turrets;
	class AT_Turret;
	/*
	class HitPoints;
	class HitHull;
	class HitBody;
	class HitFuel;
	class HitEngine;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRF2Wheel;
	*/
	class TextureSources;
	class Green;
	class Components;
	class AnimationSources;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_Offroad_Interceptor_Base: RC_Offroad_Interceptor_Fetch
{
	class EventHandlers: EventHandlers
	{
		/*
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_600m.hpp"
		};
		*/
		class RC_Interceptability
		{
			#include "\Remote_Controlled_Artillery\includes_script\firedInterceptorEH.hpp"
		};
		class RC_AttachRadar
		{
			#include "\Remote_Controlled_Artillery\includes_script\AttachRadar.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\driverCam.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	memoryPointDriverOptics="Light_L";
	
	author="Ascent";
	editorSubcategory="RC_AntiAir_subcat";
	//armor=;	//
	crewCrashProtection=0;
	canUseScanners=1;
	threat[]={0.1,0.1,0.8};
	//threat[]={0,0,0};
	//cost=0;
	//typicalCargo[]={""};

	smokeLauncherOnTurret=0;
	smokeLauncherVelocity=5;
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

	hiddenSelectionsTextures[]=
	{
		"\a3\Soft_F_Enoch\Offroad_01\Data\offroad_01_ext_grn_CO.paa",
		"\a3\Soft_F_Enoch\Offroad_01\Data\offroad_01_ext_grn_CO.paa"
	};
	class TextureSources: TextureSources
	{
		class Green: Green
		{
			displayName="Green";

			textures[]=
			{
				"\a3\Soft_F_Enoch\Offroad_01\Data\offroad_01_ext_grn_CO.paa",
				"\a3\Soft_F_Enoch\Offroad_01\Data\offroad_01_ext_grn_CO.paa"
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
		"Green",
		1
	};

	/*
	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			explosionShielding=4;
		};
		class HitBody: HitBody
		{
			explosionShielding=1;
		};
		class HitFuel: HitFuel
		{
			armor=4;
			explosionShielding=1;
		};
		class HitEngine: HitEngine
		{
			armor=8;
			passThrough=0.25;
		};
		class HitLFWheel: HitLFWheel
		{
			armor=-300;
			explosionShielding=1;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-300;
			explosionShielding=1;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-300;
			explosionShielding=1;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-300;
			explosionShielding=1;
		};
	};
	*/
			

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
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="";
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=3000;

					class AirTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;	//30
					angleRangeVertical=60;		//30
					animDirection="mainGun";
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
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class ActiveRadarSensorComponent: SensorTemplateActiveRadar
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
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=4000;
					angleRangeHorizontal=360;
					angleRangeVertical=100;
					aimDown=-45;
					maxTrackableSpeed=694.44397;
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
					range[]={6000,3000,600};
					resource="RscCustomInfoSensors";
				};
				class VehicleMissileDisplay
				{
					componentType="TransportFeedDisplayComponent";
					source="Missile";
					resource="RscTransportCameraComponentMissile";
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
			defaultDisplay="VehicleMissileDisplay";

			class Components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={600,3000,6000};
					resource="RscCustomInfoSensors";
				};
				class VehicleMissileDisplay
				{
					componentType="TransportFeedDisplayComponent";
					source="Missile";
					resource="RscTransportCameraComponentMissile";
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

	class Turrets: Turrets
	{
		class AT_Turret: AT_Turret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment1";
			//discreteDistance[]={};
			//discreteDistanceInitIndex=0;
			maxElev=45;	//20

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
					gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Optics_Commander_01_F.p3d";

					initFov=0.9;
					minFov=0.04;
					maxFov=0.9;
				};
			};
			turretInfoType="RscOptics_Strider_commander";

			weapons[]=
			{
				"RC_InterceptorLauncher_SPG"
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
							range[]={6000,3000,600};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
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
					defaultDisplay="VehicleMissileDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={600,3000,6000};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
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

	class AnimationSources: AnimationSources
	{
		class SPG9_reload
		{
			source="reload";	
			weapon="RC_InterceptorLauncher_SPG";
		};
		class SPG9_reloadmagazine
		{
			source="reloadmagazine";
			weapon="RC_InterceptorLauncher_SPG";
		};
	};

	animationList[]=
	{
		"HideBumper2",
		1,
		"HideBumper2",
		0,
		"HideDoor1",
		0,
		"HideDoor2",
		0,
		"HideDoor3",
		0,
	};
};


class RC_Offroad_Interceptor_Direct: RC_Offroad_Interceptor_Base
{
	displayname="Offroad AA-Interceptor (Direct)";
	scope=2;
	scopeCurator=2;

	class Turrets: Turrets
	{
		class AT_Turret: AT_Turret
		{
			magazines[]=
			{
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m",
				"RC_1Rnd_Interceptor_Direct_1m"
			};
		};
	};

	faction="RemoteControlled_B";
	//crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_Offroad_Interceptor_Direct_O: RC_Offroad_Interceptor_Direct
{
	faction="RemoteControlled_O";
	//crew="I_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Offroad_Interceptor_Direct_I: RC_Offroad_Interceptor_Direct
{
	faction="RemoteControlled_I";
	//crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Offroad_Interceptor_Overfly: RC_Offroad_Interceptor_Direct
{
	displayname="Offroad AA-Interceptor (Overfly)";

	class Turrets: Turrets
	{
		class AT_Turret: AT_Turret
		{
			magazines[]=
			{
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m",
				"RC_1Rnd_Interceptor_Overfly_5m"
			};
		};
	};
};
class RC_Offroad_Interceptor_Overfly_O: RC_Offroad_Interceptor_Overfly
{
	faction="RemoteControlled_O";
	//crew="I_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Offroad_Interceptor_Overfly_I: RC_Offroad_Interceptor_Overfly
{
	faction="RemoteControlled_I";
	//crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Offroad_Interceptor_TopDown: RC_Offroad_Interceptor_Direct
{
	displayname="Offroad AA-Interceptor (TopDown)";

	class Turrets: Turrets
	{
		class AT_Turret: AT_Turret
		{
			magazines[]=
			{
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m",
				"RC_1Rnd_Interceptor_TopDown_1m"
			};
		};
	};
};
class RC_Offroad_Interceptor_TopDown_O: RC_Offroad_Interceptor_TopDown
{
	faction="RemoteControlled_O";
	//crew="I_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Offroad_Interceptor_TopDown_I: RC_Offroad_Interceptor_TopDown
{
	faction="RemoteControlled_I";
	//crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Offroad_Interceptor_Cruise: RC_Offroad_Interceptor_Direct
{
	displayname="Offroad AA-Interceptor (Cruise)";

	class Turrets: Turrets
	{
		class AT_Turret: AT_Turret
		{
			magazines[]=
			{
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m",
				"RC_1Rnd_Interceptor_Cruise_1m"
			};
		};
	};
};
class RC_Offroad_Interceptor_Cruise_O: RC_Offroad_Interceptor_Cruise
{
	faction="RemoteControlled_O";
	//crew="I_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Offroad_Interceptor_Cruise_I: RC_Offroad_Interceptor_Cruise
{
	faction="RemoteControlled_I";
	//crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};