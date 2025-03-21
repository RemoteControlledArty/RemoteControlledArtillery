//Strider / Fennek - Scout
class I_MRAP_03_F;
class RC_Fennek_Base: I_MRAP_03_F
{
	class AnimationSources;
	class Turrets;
	class CommanderTurret;
	class ViewOptics;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class Components;
	class SensorsManagerComponent;
	class SensorTemplateDataLink;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	forceHideDriver=1;
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_Fennek_DIG_Base: RC_Fennek_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	faction="RemoteControlled_B";
	author="Ascent";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	//redRpm=1100;
	//idleRpm=250;

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
					typeRecognitionDistance=1500;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=45;
					angleRangeVertical=35;
					//animDirection="obsTurret";
					animDirection="obsGun";
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
					range[]={6000,4000,2000,1000};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="MinimapDisplay";

			class Components
			{
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
		class CommanderTurret: CommanderTurret
		{
			gunnerCompartments="Compartment2";
			showAllTargets="2 + 4";
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
							range[]={6000,4000,2000,1000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";

					class Components
					{
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

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};


class RC_Fennek_DIG: RC_Fennek_DIG_Base
{
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="RC Recon Fennek";
	editorSubcategory="RC_ICV_subcat";
	isUav=1;
	vehicleClass="Autonomous";
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	
	/* reactivate after middle passenger driver EH
	class Turrets: Turrets
	{
		class CommanderTurret: CommanderTurret
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
	*/
};
class RC_Fennek_DIG_O: RC_Fennek_DIG
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Fennek_DIG_I: RC_Fennek_DIG
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//Fennek with Vehicle Mortar attached, for low power but mobile indirect fire support
class RC_Mortar_Fennek_DIG: RC_Fennek_DIG
{
	class Turrets: Turrets
	{
		class CommanderTurret: CommanderTurret
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
	
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [-0.08, -0.35, 1.17]];};";
		};
	};

	displayName="RC Mortar Fennek";
	editorSubcategory="RC_Mortar_subcat";
};
class RC_Mortar_Fennek_DIG_O: RC_Mortar_Fennek_DIG
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [-0.08, -0.35, 1.17]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_Fennek_DIG_I: RC_Mortar_Fennek_DIG
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [-0.08, -0.35, 1.17]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//version with less rounds for smaller ops
class RC_Mortar_Fennek_LC_DIG: RC_Mortar_Fennek_DIG
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC', west] call BIS_fnc_spawnVehicle) select 0) attachTo [-0.08, -0.35, 1.17]];};";
		};
	};

	displayName="RC Mortar Fennek LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";
};
class RC_Mortar_Fennek_LC_DIG_O: RC_Mortar_Fennek_LC_DIG
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [-0.08, -0.35, 1.17]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_Fennek_LC_DIG_I: RC_Mortar_Fennek_LC_DIG
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [-0.08, -0.35, 1.17]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};