//Flatbed Truck with 105mm M119
class B_MRAP_01_F;
class RC_MortarMATV_base: B_MRAP_01_F
{
	class Components;
	class EventHandlers;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRF2Wheel;
	scope=0;
	scopeCurator=0;
};
class RC_MortarMATV: RC_MortarMATV_base
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [-0.05, -2.45, 1.27]];};";

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

	faction="RemoteControlled_B";
	editorSubcategory="RC_Mortar_subcat";
	author="Ascent";
	crewCrashProtection=0.01;
	enableGPS=1;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	threat[]={0,0,0};
	cost=0;
	typicalCargo[]=
	{
		""
	};

	smokeLauncherOnTurret=0;
	smokeLauncherVelocity=5;
	smokeLauncherGrenadeCount=6;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

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

	class HitPoints: HitPoints
	{
		class HitLFWheel: HitLFWheel
		{
			armor=-400;
			explosionShielding=1;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-400;
			explosionShielding=1;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-400;
			explosionShielding=1;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-400;
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
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
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
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
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
					range[]={6000,4000,2000,1000};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="UAVFeedDisplay";

			class Components
			{
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

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=6;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=1;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=2;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_Improved_FOV_Laserdesignator_A
		{
			weapon="Improved_FOV_Laserdesignator_A";
			count=1;
		};
	};
	class TransportBackpacks
	{
		class _xx_RC_UAV_AR1_Bag
		{
			backpack="RC_UAV_AR1_Bag";
			count=2;
		};
	};
};


class RC_MortarMATV_manned_A: RC_MortarMATV
{
	displayName="Mortar MATV 6km";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	crew="";
	//crew="B_UAV_AI";
	//dontCreateAI=1;	//doesnt fully work
};
class RC_MortarMATV_manned_A_I: RC_MortarMATV_manned_A
{
	faction="RemoteControlled_I";
	side=2;
	//crew="I_UAV_AI";
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [-0.05, -2.45, 1.27]];};";
	};

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=2;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=2;
		};
	};
	class TransportBackpacks
	{
		class _xx_RC_UAV_AR1_Bag
		{
			backpack="RC_UAV_AR1_Bag_I";
			count=2;
		};
	};
};


class RC_MortarMATV_manned_WD: RC_MortarMATV_manned_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MRAP_01_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\soft_F_Exp\MRAP_01\data\MRAP_01_base_olive_CO.paa",
		"\A3\soft_F_Exp\MRAP_01\data\MRAP_01_adds_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};
class RC_MortarMATV_manned_WD_I: RC_MortarMATV_manned_WD
{
	faction="RemoteControlled_I";
	side=2;
	//crew="I_UAV_AI";
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [-0.05, -2.45, 1.27]];};";
	};

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=2;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=2;
		};
	};
	class TransportBackpacks
	{
		class _xx_RC_UAV_AR1_Bag
		{
			backpack="RC_UAV_AR1_Bag_I";
			count=2;
		};
	};
};