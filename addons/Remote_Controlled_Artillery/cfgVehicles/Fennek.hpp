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
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Fennek_A_Base: RC_Fennek_Base
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
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	faction="RemoteControlled_B";
	author="Ascent";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	//redRpm=1100;
	//idleRpm=250;

	smokeLauncherVelocity=5;
	smokeLauncherGrenadeCount=6;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

	//model="\A3\soft_f_beta\MRAP_03\MRAP_03_unarmed_F";
	hiddenSelectionsTextures[]=
	{
		"A3\soft_f_beta\MRAP_03\Data\mrap_03_ext_co.paa",
		"A3\Data_F\Vehicles\Turret_CO.paa"
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
					angleRangeVertical=45;
					//animDirection="obsTurret";
					animDirection="obsGun";
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

	class Turrets: Turrets
	{
		class CommanderTurret: CommanderTurret
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

	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsB.hpp"
};


class RC_Fennek_A: RC_Fennek_A_Base
{
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	camouflage=1.5;	//2
	/*
	radarTargetSize=0.7; //?
	irTargetSize=0.7; //?
	visualTargetSize=0.7; //?
	*/

	displayName="RC Recon Fennek";
	editorSubcategory="RC_ICV_subcat";
	isUav=1;
	vehicleClass="Autonomous";
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="B_UAV_AI";
	
	class Turrets: Turrets
	{
		class CommanderTurret: CommanderTurret
		{
			primaryGunner=1;
			primaryObserver=0;

			gunnerForceOptics=1;
			forceHideGunner=1;

			/*
			class ViewOptics: ViewOptics
			{
				directionStabilized=1;
			};
			*/
		};
	};
};
class RC_Fennek_A_O: RC_Fennek_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsO.hpp"
};
class RC_Fennek_A_I: RC_Fennek_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\L_FSVitemsI.hpp"
};
class RC_Fennek_DIG_I: RC_Fennek_A_I
{
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_beta\mrap_03\data\mrap_03_ext_indp_co.paa",
		"\a3\data_f\vehicles\turret_indp_co.paa"
	};
};


//Fennek with Vehicle Mortar attached, for low power but mobile indirect fire support
class RC_Mortar_Fennek_A: RC_Fennek_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [-0.08, -0.35, 1.17]];};";
		};
	};

	displayName="RC Mortar Fennek";
	editorSubcategory="RC_Mortar_subcat";
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
	camouflage=2;	//2

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
					range[]={6000,4000,2000,1000,400};
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
					range[]={400,1000,2000,4000,6000};
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
							range[]={6000,4000,2000,1000,400};
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
							range[]={400,1000,2000,4000,6000};
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
};
class RC_Mortar_Fennek_A_O: RC_Mortar_Fennek_A
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
class RC_Mortar_Fennek_A_I: RC_Mortar_Fennek_A
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
class RC_Mortar_Fennek_DIG_I: RC_Mortar_Fennek_A_I
{
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_beta\mrap_03\data\mrap_03_ext_indp_co.paa",
		"\a3\data_f\vehicles\turret_indp_co.paa"
	};
};


//version with less rounds for smaller ops
class RC_Mortar_Fennek_LC_A: RC_Mortar_Fennek_A
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
class RC_Mortar_Fennek_LC_A_O: RC_Mortar_Fennek_LC_A
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
class RC_Mortar_Fennek_LC_A_I: RC_Mortar_Fennek_LC_A
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
class RC_Mortar_Fennek_LC_DIG_I: RC_Mortar_Fennek_LC_A_I
{
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_beta\mrap_03\data\mrap_03_ext_indp_co.paa",
		"\a3\data_f\vehicles\turret_indp_co.paa"
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_Fennek_ReTex_WD: RC_Fennek_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};
class RC_Fennek_ReTex_WD_O: RC_Fennek_A_O
{
	faction="RemoteControlled_ReTex_O";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};
class RC_Fennek_ReTex_WD_I: RC_Fennek_A_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};


class RC_Mortar_Fennek_ReTex_WD: RC_Mortar_Fennek_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};
class RC_Mortar_Fennek_ReTex_WD_O: RC_Mortar_Fennek_A_O
{
	faction="RemoteControlled_ReTex_O";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};
class RC_Mortar_Fennek_ReTex_WD_I: RC_Mortar_Fennek_A_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};


class RC_Mortar_Fennek_LC_ReTex_WD: RC_Mortar_Fennek_LC_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};
class RC_Mortar_Fennek_LC_ReTex_WD_O: RC_Mortar_Fennek_LC_A_O
{
	faction="RemoteControlled_ReTex_O";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};
class RC_Mortar_Fennek_LC_ReTex_WD_I: RC_Mortar_Fennek_LC_A_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Woodland_subcat";

	hiddenSelectionsTextures[]=
	{
		"Fennek\Data\Fennek_ext_wd.paa",
		"Fennek\Data\Turret_wd.paa"
	};
};