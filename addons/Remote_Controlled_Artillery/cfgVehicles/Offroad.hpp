//Flatbed Truck with 105mm M119
class B_G_Offroad_01_F;
class RC_Offroad_Core: B_G_Offroad_01_F
{
	class Components;
	class EventHandlers;
	class HitPoints;
	class HitHull;
	class HitBody;
	class HitFuel;
	class HitEngine;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class TextureSources;
	class Green;
	scope=0;
	scopeCurator=0;
};
class RC_Offroad_Base: RC_Offroad_Core
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

	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiDrone_subcat";
	author="Ascent";
	armor=40;
	crewCrashProtection=0.01;
	side=1;

	threat[]={0,0,0};
	cost=0;
	typicalCargo[]={""};

	smokeLauncherOnTurret=0;
	smokeLauncherVelocity=5;
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
					range[]={3000,1500,600};
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
					range[]={600,1500,3000};
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

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};


class RC_Offroad_cUAS: RC_Offroad_Base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static', west] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
				((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="Offroad C-UAS/FS 12.7mm";
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
		init="if (!isserver) exitwith {};	\
		(_this select 0) spawn {	\
			private _static = ([[0,0,0], (getDir _this), 'RC_cUAS_Mounted_Static_HMG', west] call BIS_fnc_spawnVehicle);	\
			(_static #0) attachTo [_this, [0.16, -2.15, 1]];	\
			_this addEventHandler ['Killed', {	\
				params ['_unit'];	\
    			((attachedObjects _unit)#0) setDamage 1;	\
			}];	\
		};";
	};

	displayName="Offroad C-UAS/FS 20mm";
};