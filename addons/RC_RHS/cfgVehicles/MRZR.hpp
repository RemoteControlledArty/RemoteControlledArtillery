class rhsusf_mrzr4_d;
class RC_MRZR_Core: rhsusf_mrzr4_d
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
class RC_MRZR_Base: RC_MRZR_Core
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
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\driverCam1x.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	memoryPointDriverOptics="P svetlo";

	author="Ascent";
	armor=40;
	crewCrashProtection=0.01;

	threat[]={0,0,0};
	cost=0;
	typicalCargo[]={""};
	
	maximumLoad=2500;
	canHideGunner=1;
	camouflage=1;	//2
	audible=2.5;	//5

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
		class CargoTurret_01: CargoTurret_01
		{
			//primaryObserver=1;
			gunnerName="Front Right";
			gunnerCompartments="Compartment1";

			/*
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
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
					};
				};
			};
			*/
		};
		class CargoTurret_02: CargoTurret_02
		{
			gunnerName="Middle Left";
			gunnerCompartments="Compartment1";
		};
		class CargoTurret_03: CargoTurret_03
		{
			gunnerName="Middle Right";
			gunnerCompartments="Compartment1";
		};
		class CargoTurret_04: CargoTurret_04
		{
			gunnerName="Rear Right";
			gunnerCompartments="Compartment1";

			//allowLauncherOut=1;
			//canHideGunner=1;
		};
		class CargoTurret_05: CargoTurret_05
		{
			primaryObserver=1;
			/*
			gunnerName="Driver";

			proxyIndex=0;
			playerPosition=0;
			memoryPointsGetInGunner="pos codriver";
			memoryPointsGetInGunnerDir="pos codriver dir";

			gunnerAction="rhs_mrzr_driver";
			gunnerInAction="";
			gunnerLeftHandAnimName="steeringwheel";
			gunnerLeftLegAnimName="";
			gunnerRightHandAnimName="steeringwheel";
			gunnerRightLegAnimName="pedal_thrust";
			*/

			gunnerName="Rear Left";
			gunnerCompartments="Compartment1";

			//allowLauncherOut=1;
			//canHideGunner=1;
		};
	};

	/*
	gunnerName="AI Driver";
	memoryPointsGetInDriver="pos cargo R";
	memoryPointsGetInDriverDir="pos cargo R dir";
	memoryPointsGetInDriverPrecise="pos cargo R";
	driverAction="passenger_flatground_4";
	driverInAction="passenger_flatground_4";
	proxyIndex=6;
	playerPosition=6;
	*/

	/*
	driverAction = "rhs_mrzr_driver";
	driverInAction = "";
	driverLeftHandAnimName = "steeringwheel";
	driverLeftLegAnimName = "";
	driverRightHandAnimName = "steeringwheel";
	driverRightLegAnimName = "pedal_thrust";
	*/

	hiddenSelectionsTextures[]=
	{
		"\rhsusf\addons\rhsusf_mrzr\data\blue_tan_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\yel_tan_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\red_tan_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\grn_tan_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\merged\orng_tan_mud_co.paa"
	};

	class TextureSources: TextureSources
	{
		class standard
		{
			displayName="Tan";
			textures[]=
			{
				"\rhsusf\addons\rhsusf_mrzr\data\blue_tan_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\yel_tan_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\red_tan_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\grn_tan_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\merged\orng_tan_co.paa"
			};
			materials[]=
			{
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_blue.rvmat",
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_yel_metal.rvmat",
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_red.rvmat",
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_grn.rvmat"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class mud
		{
			displayName="Tan (Muddy)";
			textures[]=
			{
				"\rhsusf\addons\rhsusf_mrzr\data\blue_tan_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\yel_tan_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\red_tan_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\grn_tan_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\merged\orng_tan_mud_co.paa"
			};
			materials[]=
			{
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_blue_mud.rvmat",
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_yel_metal_mud.rvmat",
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_red_mud.rvmat",
				"\rhsusf\addons\rhsusf_mrzr\data\rhsusf_mrzr_grn_mud.rvmat"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class olive: standard
		{
			displayName="Olive";
			textures[]=
			{
				"\rhsusf\addons\rhsusf_mrzr\data\blue_grn_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\yel_grn_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\red_grn_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\grn_grn_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\merged\orng_grn_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class mud_olive: mud
		{
			displayName="Olive (Muddy)";
			textures[]=
			{
				"\rhsusf\addons\rhsusf_mrzr\data\blue_grn_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\yel_grn_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\red_grn_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\grn_grn_mud_co.paa",
				"\rhsusf\addons\rhsusf_mrzr\data\merged\orng_grn_mud_co.paa"
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
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
			};
		};
	};

	#include "\RC_RHS\loadouts\FSVitemsB_RHS.hpp"
};


class RC_MRZR_D: RC_MRZR_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"

	displayName="RC MRZR";
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

	uavCameraDriverPos="P svetlo";
	uavCameraDriverDir="P svetlo";

	//cost=0;
};
class RC_MRZR_D_O: RC_MRZR_D
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsO_RHS.hpp"
};
class RC_MRZR_D_I: RC_MRZR_D
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


class RC_MRZR_WD: RC_MRZR_D
{
	hiddenSelectionsTextures[]=
	{
		"\rhsusf\addons\rhsusf_mrzr\data\blue_grn_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\yel_grn_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\red_grn_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\grn_grn_mud_co.paa",
		"\rhsusf\addons\rhsusf_mrzr\data\merged\orng_grn_mud_co.paa"
	};
};
class RC_MRZR_WD_O: RC_MRZR_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsO_RHS.hpp"
};
class RC_MRZR_WD_I: RC_MRZR_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


/*
class RC_Offroad_RCIMV_cUAS: RC_Offroad_RCIMV
{
	class EventHandlers: EventHandlers
	{
		init="if (!isServer) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static_HMG_manned', side _this] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
    			((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="RC Offroad + 12.7mm C-UAS";
};
class RC_Offroad_RCIMV_cUAS_O: RC_Offroad_RCIMV_cUAS
{
	side=0;
	crew="O_UAV_AI";
};
class RC_Offroad_RCIMV_cUAS_I: RC_Offroad_RCIMV_cUAS
{
	side=2;
	crew="I_UAV_AI";
};
*/


/*
class RC_Offroad_cUAS_Base: RC_Offroad_Base
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
	};

	editorSubcategory="RC_AntiDrone_subcat";
};


class RC_Offroad_cUAS: RC_Offroad_cUAS_Base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isServer) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static', west] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
				((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="Offroad C-UAS/FS 20mm";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="B_Soldier_UAV_F";		//crew="";	//dontCreateAI=1;	//doesnt fully work
};
class RC_Offroad_cUAS_HMG: RC_Offroad_cUAS
{
	class EventHandlers: EventHandlers
	{
		init="if (!isServer) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static_HMG', west] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
    			((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="Offroad C-UAS/FS 12.7mm";
};
*/