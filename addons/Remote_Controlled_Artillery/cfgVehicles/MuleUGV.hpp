class B_UGV_01_F;
class RC_Mule_UGV_Core: B_UGV_01_F
{
	class HitPoints;
	class HitHull;
	class HitEngine;
	class HitFuel;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_Mule_UGV_Base: RC_Mule_UGV_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_RemoveAttachedObj
		{
			#include "\Remote_Controlled_Artillery\includes_script\removeAttachedObj_deletedEH.hpp"
		};
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
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

	author="Ascent";
	editorSubcategory="RC_Support_subcat";
	side=1;
	crewCrashProtection=0.01;
	maxSpeed=80;
	enginePower=120;
	peakTorque=750;

	waterLeakiness=2.5;
	canFloat=1;
	waterAngularDampingCoef=10;
	waterPPInVehicle=0;
	waterResistanceCoef=0.5;

	smokeLauncherVelocity=3;
	smokeLauncherGrenadeCount=4;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

	ace_cargo_hasCargo=1;
	ace_cargo_space=8;
	ace_repair_spareWheels=2;
	ace_repair_spareTracks=1;

	weapons[]=
	{
		"RC_target_confirmer_datalink",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag",
		"SmokeLauncherMag"
	};

	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=1.05;
			passThrough=1;
			//minimalHit=0.2;
			explosionShielding=0.4;
		};
		class HitEngine: HitEngine
		{
			armor=3;
			passThrough=0.25;
			//minimalHit=0.2;
			explosionShielding=0.4;
		};
		class HitFuel: HitFuel
		{
			armor=2;
			passThrough=0.15;
			//minimalHit=0.1;
			explosionShielding=1.2;
		};
		class HitLFWheel: HitLFWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitLMWheel: HitLMWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitRMWheel: HitRMWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
	};

	class Components: Components
	{
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={6000,3000,1500,400};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={400,1500,3000,6000};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
				};
			};
		};
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
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
			};
		};
	};
};


class RC_Mule_UGV_A: RC_Mule_UGV_Base
{
	displayName="RC Mule UGV";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_Mule_UGV_A_O: RC_Mule_UGV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mule_UGV_A_I: RC_Mule_UGV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Mule_UGV_WD: RC_Mule_UGV_A
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_UGV_01_olive_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa",
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};
class RC_Mule_UGV_WD_O: RC_Mule_UGV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mule_UGV_WD_I: RC_Mule_UGV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//ReArmPairFuel
class Land_WeldingTrolley_01_F;
class RC_PortableRepairWelder: Land_WeldingTrolley_01_F
{
	displayName="Portable Repair Welder";
	scope=2;
	scopeCurator=2;
	transportRepair=250000000000;
	ace_cargo_canLoad=1;
	ace_cargo_size=1;
	ace_dragging_canCarry=1;
	ace_dragging_canDrag=1;
	ace_dragging_carryDirection=270;
	ace_dragging_dragDirection=270;
	ace_dragging_dragPosition[]={0,1.2,0};
};
class RC_RepairWelder: Land_WeldingTrolley_01_F
{
	displayName="Repair Welder";
	transportRepair=250000000000;
	scope=1;
	scopeCurator=1;
};
class RC_Mule_UGV_ReArmPairFuel_A: RC_Mule_UGV_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isServer) exitwith {}; \
			(_this select 0) spawn { \
				('Box_NATO_AmmoVeh_F' createVehicle [0,0,0]) attachTo [_this, [0.425, -0.4, 0.1]]; \
				('RC_RepairWelder' createVehicle [0,0,0]) attachTo [_this, [0.105, -1.44, -0.3]]; \
				('FlexibleTank_01_forest_F' createVehicle [0,0,0]) attachTo [_this, [0.89, -1.45, -0.17]]; \
			};";
		};
	};

	displayName="RC Mule - Re-arm/pair/fuel";
	ace_repair_spareWheels=4;
	ace_repair_spareTracks=2;
};
class RC_Mule_UGV_ReArmPairFuel_A_O: RC_Mule_UGV_ReArmPairFuel_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mule_UGV_ReArmPairFuel_A_I: RC_Mule_UGV_ReArmPairFuel_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Mule_UGV_ReArmPairFuel_WD: RC_Mule_UGV_ReArmPairFuel_A
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_UGV_01_olive_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa",
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};
class RC_Mule_UGV_ReArmPairFuel_WD_O: RC_Mule_UGV_ReArmPairFuel_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mule_UGV_ReArmPairFuel_WD_I: RC_Mule_UGV_ReArmPairFuel_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//ReSupply
class Land_Pallet_MilBoxes_F;
class RC_ReSupplyPallet: Land_Pallet_MilBoxes_F
{
	displayName="Inf Resupply Pallet";
	ace_cargo_size=2;
	maximumLoad=4000;
	vehicleClass="Container";
	transportMaxMagazines=128;
	transportMaxWeapons=24;
	transportMaxBackpacks=12;
	transportAmmo=0;
	transportFuel=0;
};
class RC_Mule_UGV_ReSupply_A: RC_Mule_UGV_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isServer) exitwith {}; \
			(_this select 0) spawn { \
				('RC_ReSupplyPallet' createVehicle [0,0,0]) attachTo [_this, [0.3, -0.354, -0.4045]]; \
			};";
		};
	};

	displayName="RC Mule - Re-supply";
};
class RC_Mule_UGV_ReSupply_A_O: RC_Mule_UGV_ReSupply_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mule_UGV_ReSupply_A_I: RC_Mule_UGV_ReSupply_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Mule_UGV_ReSupply_WD: RC_Mule_UGV_ReSupply_A
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_UGV_01_olive_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa",
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};
class RC_Mule_UGV_ReSupply_WD_O: RC_Mule_UGV_ReSupply_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mule_UGV_ReSupply_WD_I: RC_Mule_UGV_ReSupply_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};