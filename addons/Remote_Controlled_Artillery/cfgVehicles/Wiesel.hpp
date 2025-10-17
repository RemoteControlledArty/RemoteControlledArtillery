//Nyx / Wiesel
class I_LT_01_AA_F;
class RC_Wiesel_AA_Base: I_LT_01_AA_F
{
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class HitPoints;
	class HitEngine;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Wiesel_AA_WD: RC_Wiesel_AA_Base
{
	class EventHandlers: EventHandlers
	{
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
	
	//#include "\Remote_Controlled_Artillery\includes_script\UserActions_NameUV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	displayName="RC Wiesel II Anti-Air / C-UAS";
	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiAir_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	redRpm=1100;
	idleRpm=250;

	smokeLauncherVelocity=4;
	smokeLauncherGrenadeCount=6;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class ActiveRadarSensorComponent: SensorTemplateActiveRadar
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
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=4000;
					angleRangeHorizontal=360;
					angleRangeVertical=100;
					aimDown=-45;
					maxTrackableSpeed=694.44397;
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
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
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
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

	class HitPoints: HitPoints
	{
		class HitEngine: HitEngine
		{
			armor=-60;
		};
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showSLATHull",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment2";
			turretInfoType="RscOptics_crows";
			gunnerForceOptics=1;
			forceHideGunner=1;
			stabilizedInAxes=3;
			gunnerName="Gunner";

			weapons[]=
			{
				"RC_HMG_127x99",
				"RC_70mm_AA_Missile_Launcher",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_AA_red.hpp"

			/*
			class ViewOptics: RCWSOptics
			{
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				initFov=0.9;
				minFov=0.0166;
				maxFov=0.9;
			};
			*/

			class OpticsIn
			{
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
					initFov=0.9;
					minFov=0.0166;
					maxFov=0.9;
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
							range[]={8000,4000,2000,1000,600};
							resource="RscCustomInfoSensors";
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
							range[]={600,1000,2000,4000,8000};
							resource="RscCustomInfoSensors";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
						*/
					};
				};
			};
		};
	};

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
	};

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
		//"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_olive_co.paa"
	};
};
class RC_Wiesel_AA_WD_O: RC_Wiesel_AA_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Wiesel_AA_WD_I: RC_Wiesel_AA_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_Wiesel_AA_DIG_I: RC_Wiesel_AA_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_at_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


class I_LT_01_scout_F;
class RC_Wiesel_Radar_Base: I_LT_01_scout_F
{
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class HitPoints;
	class HitEngine;
	class Components;
	class SensorsManagerComponent;
	class SensorTemplateDataLink;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	forceHideDriver=1;
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Wiesel_Radar_WD_Base: RC_Wiesel_Radar_Base
{
	class EventHandlers: EventHandlers
	{
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

	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiAir_subcat";
	author="Ascent";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	redRpm=1100;
	idleRpm=250;

	smokeLauncherVelocity=4;
	smokeLauncherGrenadeCount=6;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
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
				};
				class ActiveRadarSensorComponent: SensorTemplateActiveRadar
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
					angleRangeHorizontal=360;
					angleRangeVertical=180;
					aimDown=0;
					groundNoiseDistanceCoef=0;
					maxGroundNoiseDistance=0;
					maxTrackableSpeed=694.44397;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=3000;

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
					angleRangeHorizontal=45;
					angleRangeVertical=35;
					//animDirection="obsTurret";
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
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					//animDirection="obsTurret";
					animDirection="obsGun";
				};
			};
		};
	};

	class HitPoints: HitPoints
	{
		class HitEngine: HitEngine
		{
			armor=-60;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment2";
			stabilizedInAxes=3;

			weapons[]=
			{
				"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class ViewOptics: ViewOptics
			{
				initFov=0.9;
				minFov=0.00833;
				maxFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
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
							range[]={8000,4000,2000,1000,600};
							resource="RscCustomInfoSensors";
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
							range[]={600,1000,2000,4000,8000};
							resource="RscCustomInfoSensors";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showSLATHull",
		1
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_radar_olive_co.paa",
		//"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_olive_co.paa"
	};
};


class RC_Wiesel_Radar_WD: RC_Wiesel_Radar_WD_Base
{
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="RC Wiesel II Radar";
	isUav=1;
	vehicleClass="Autonomous";
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			primaryGunner=1;
			primaryObserver=0;

			gunnerForceOptics=1;
			forceHideGunner=1;

			class ViewOptics: ViewOptics
			{
				directionStabilized=1;
			};
		};
	};
};
class RC_Wiesel_Radar_WD_O: RC_Wiesel_Radar_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Wiesel_Radar_WD_I: RC_Wiesel_Radar_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_Wiesel_Radar_DIG_I: RC_Wiesel_Radar_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_radar_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


class RC_Wiesel_Radar_manned_WD: RC_Wiesel_Radar_WD_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
		};
	};

	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="Wiesel II Radar";
	crew="B_UAV_AI";
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=1;
			primaryGunner=1;
			primaryObserver=0;

			/*
			class ViewOptics: ViewOptics
			{
				directionStabilized=0;
			};
			*/

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsDisplayManagerComponentLeft
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={600,1000,2000,4000,8000};
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
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
					};
				};
			};
		};
	};
};
class RC_Wiesel_Radar_manned_WD_O: RC_Wiesel_Radar_manned_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Wiesel_Radar_manned_WD_I: RC_Wiesel_Radar_manned_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_Wiesel_Radar_manned_DIG_I: RC_Wiesel_Radar_manned_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_radar_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


//Wiesel RADAR with Vehicle Mortar attached, for low power but mobile indirect fire support
class RC_Mortar_Carrier_WD: RC_Wiesel_Radar_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	displayName="RC Mortar Carrier";
	editorSubcategory="RC_Mortar_subcat";
};
class RC_Mortar_Carrier_WD_O: RC_Mortar_Carrier_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_Carrier_WD_I: RC_Mortar_Carrier_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_Mortar_Carrier_DIG_I: RC_Mortar_Carrier_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_radar_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


//semi manned variants
class RC_Mortar_Carrier_manned_WD: RC_Wiesel_Radar_manned_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	displayName="Mortar Carrier";
	editorSubcategory="RC_Mortar_subcat";
};
class RC_Mortar_Carrier_manned_WD_O: RC_Mortar_Carrier_manned_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_Carrier_manned_WD_I: RC_Mortar_Carrier_manned_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_Mortar_Carrier_manned_DIG_I: RC_Mortar_Carrier_manned_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_radar_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


//version with less rounds for smaller ops
class RC_Mortar_Carrier_LC_WD: RC_Wiesel_Radar_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	displayName="RC Mortar Carrier LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";
};
class RC_Mortar_Carrier_LC_WD_O: RC_Mortar_Carrier_LC_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_Carrier_LC_WD_I: RC_Mortar_Carrier_LC_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//semi manned variant
class RC_Mortar_Carrier_LC_manned_WD: RC_Wiesel_Radar_manned_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	displayName="Mortar Carrier LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";
};
class RC_Mortar_Carrier_LC_manned_WD_O: RC_Mortar_Carrier_LC_manned_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_Carrier_LC_manned_WD_I: RC_Mortar_Carrier_LC_manned_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class I_LT_01_AT_F;
class RC_Wiesel_ATGM_Base: I_LT_01_AT_F
{
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class TurnOut;
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class HitPoints;
	class HitEngine;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Wiesel_ATGM_WD_Base: RC_Wiesel_ATGM_Base
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

	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	//RC_ATrespondingTurret[]={0};	//deactivated until lock isnt stuck as long

	weapons[]=
	{
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

	displayName="RC Wiesel II ATGM 4km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_subcat";
	author="Ascent";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	redRpm=1100;
	idleRpm=250;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	//laserScanner=0;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=3000;

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
					angleRangeHorizontal=40;
					angleRangeVertical=20;
					animDirection="mainGun";
				};
				
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class HitPoints: HitPoints
	{
		class HitEngine: HitEngine
		{
			armor=-60;
		};
	};

	class AnimationSources: AnimationSources
	{
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_IFV_Missile_Launcher";
		};
		class Missiles_reloadMagazine: Missiles_revolving
		{
			source="reloadMagazine";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showSLATHull",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment2";
			stabilizedInAxes=3;
			maxElev=55;
			gunnerName="Gunner";

			weapons[]=
			{
				"RC_HMG_127x99",
				"RC_IFV_Missile_Launcher",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_ATGM_red.hpp"

			class ViewOptics: ViewOptics
			{
				//directionStabilized=1;	//sadly creates aiming problems
				initFov=0.9;
				minFov=0.0166;
				maxFov=0.9;
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
							range[]={4000,2000,1000,400};
							resource="RscCustomInfoSensors";
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
							range[]={400,1000,2000,4000};
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
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
		//"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_olive_co.paa"
	};
};


class RC_Wiesel_ATGM_WD: RC_Wiesel_ATGM_WD_Base
{
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	crew="B_UAV_AI";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			forceHideGunner=1;
		};
	};
};
class RC_Wiesel_ATGM_WD_O: RC_Wiesel_ATGM_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_ATGM_green.hpp"
		};
	};
};
class RC_Wiesel_ATGM_WD_I: RC_Wiesel_ATGM_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_ATGM_yellow.hpp"
		};
	};
};
class RC_Wiesel_ATGM_DIG_I: RC_Wiesel_ATGM_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_at_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


//semi manned version
class RC_Wiesel_ATGM_WD_manned: RC_Wiesel_ATGM_WD_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
		};
	};

	displayName="Wiesel II ATGM 4km";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="B_UAV_AI";
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=1;
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner_missile.hpp"
		};
	};
};
class RC_Wiesel_ATGM_WD_manned_O: RC_Wiesel_ATGM_WD_manned
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_ATGM_green.hpp"
		};
	};
};
class RC_Wiesel_ATGM_WD_manned_I: RC_Wiesel_ATGM_WD_manned
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_ATGM_yellow.hpp"
		};
	};
};
class RC_Wiesel_ATGM_DIG_manned_I: RC_Wiesel_ATGM_WD_manned_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_at_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


class I_LT_01_cannon_F;
class RC_Wiesel_AC_Base: I_LT_01_cannon_F
{
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class TurnOut;
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class HitPoints;
	class HitEngine;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Wiesel_AC_WD_Base: RC_Wiesel_AC_Base
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
	
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	//RC_ATrespondingTurret[]={0};	//deactivated until lock isnt stuck as long

	weapons[]=
	{
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

	displayName="RC Wiesel II 20mm";
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_subcat";
	author="Ascent";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	redRpm=1100;
	idleRpm=250;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	//laserScanner=0;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=3000;

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
					angleRangeHorizontal=40;
					angleRangeVertical=20;
					animDirection="mainGun";
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class HitPoints: HitPoints
	{
		class HitEngine: HitEngine
		{
			armor=-60;
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_20mm";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_20mm";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showSLATHull",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment2";
			stabilizedInAxes=3;
			maxElev=80;	//of 90°: 67.5 = 3/4, 72 = 4/5
			gunnerName="Gunner";

			weapons[]=
			{
				"RC_autocannon_20mm",
				"RC_MMG_338_coax_ext",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_20mm_red.hpp"

			class ViewOptics: ViewOptics
			{
				//directionStabilized=1;	//sadly creates aiming problems
				initFov=0.9;
				minFov=0.0166;
				maxFov=0.9;
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
							range[]={4000,2000,1000,400};
							resource="RscCustomInfoSensors";
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
							range[]={400,1000,2000,4000};
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
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_cannon_olive_co.paa",
		//"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_olive_co.paa"
	};
};


class RC_Wiesel_AC_WD: RC_Wiesel_AC_WD_Base
{
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	crew="B_UAV_AI";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			forceHideGunner=1;
		};
	};
};
class RC_Wiesel_AC_WD_O: RC_Wiesel_AC_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_20mm_green.hpp"
		};
	};
};
class RC_Wiesel_AC_WD_I: RC_Wiesel_AC_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_20mm_yellow.hpp"
		};
	};
};
class RC_Wiesel_AC_DIG_I: RC_Wiesel_AC_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_cannon_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


//semi manned version
class RC_Wiesel_AC_WD_manned: RC_Wiesel_AC_WD_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
		};
	};

	displayName="Wiesel II 20mm";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="B_UAV_AI";
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=1;
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"
		};
	};
};
class RC_Wiesel_AC_WD_manned_O: RC_Wiesel_AC_WD_manned
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_20mm_green.hpp"
		};
	};
};
class RC_Wiesel_AC_WD_manned_I: RC_Wiesel_AC_WD_manned
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_20mm_yellow.hpp"
		};
	};
};
class RC_Wiesel_AC_DIG_manned_I: RC_Wiesel_AC_WD_manned_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_cannon_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


class RC_Wiesel_cUAS_WD_Base: RC_Wiesel_AC_WD_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_600m.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
	
	displayName="RC Wiesel II C-UAS";
	editorSubcategory="RC_AntiDrone_subcat";

	smokeLauncherVelocity=4;
	smokeLauncherGrenadeCount=6;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{	
			maxElev=80;	//of 90°: 67.5 = 3/4, 72 = 4/5

			weapons[]=
			{
				"RC_autocannon_20mm_cUAS",
				"RC_MMG_338_coax_ext",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_cUAS_red.hpp"

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
							range[]={4000,2000,1000,600};
							resource="RscCustomInfoSensors";
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
							range[]={600,1000,2000,4000};
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
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_20mm_cUAS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_20mm_cUAS";
		};
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
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
					angleRangeHorizontal=1;
					angleRangeVertical=1;
					animDirection="mainGun";
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
};


class RC_Wiesel_cUAS_WD: RC_Wiesel_cUAS_WD_Base
{
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	crew="B_UAV_AI";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			forceHideGunner=1;
		};
	};
};
class RC_Wiesel_cUAS_WD_O: RC_Wiesel_cUAS_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_cUAS_green.hpp"
		};
	};
};
class RC_Wiesel_cUAS_WD_I: RC_Wiesel_cUAS_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_cUAS_yellow.hpp"
		};
	};
};
class RC_Wiesel_cUAS_DIG_I: RC_Wiesel_cUAS_WD_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_cannon_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


//semi manned version
class RC_Wiesel_cUAS_WD_manned: RC_Wiesel_cUAS_WD_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery: RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
		};
	};

	displayName="Wiesel II C-UAS";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="B_UAV_AI";
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=1;
			
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
							range[]={4000,1200,600};
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
							range[]={600,1200,4000};
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
		};
	};
};
class RC_Wiesel_cUAS_WD_manned_O: RC_Wiesel_cUAS_WD_manned
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_cUAS_green.hpp"
		};
	};
};
class RC_Wiesel_cUAS_WD_manned_I: RC_Wiesel_cUAS_WD_manned
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Wiesel_cUAS_yellow.hpp"
		};
	};
};
class RC_Wiesel_cUAS_DIG_manned_I: RC_Wiesel_cUAS_WD_manned_I
{
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_cannon_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};