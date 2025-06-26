class B_UGV_01_F;
class RC_FPV_Carrier_Core: B_UGV_01_F
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
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_FPV_Carrier_Base: RC_FPV_Carrier_Core
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

	side=1;
	forceInGarage=1;
	crewCrashProtection=0.01;
	maxSpeed=80;
	enginePower=120;
	peakTorque=750;

	waterLeakiness=2.5;
	canFloat=1;
	waterAngularDampingCoef=10;
	waterPPInVehicle=0;
	waterResistanceCoef=0.5;

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
			};
		};
	};
};

class RC_FPV_Carrier_A: RC_FPV_Carrier_Base
{
	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"Laserdesignator_mounted",
				"RC_FPV_Deployer"
			};
			magazines[]=
			{
				"Laserbatteries",
				"RC_6xFPV_Deployer_Mag"
			};
		};
	};
	*/

	author="Ascent";
	displayName="6xFPV Carrier";
	editorSubcategory="RC_UAV_Designator_subcat";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_FPV_Carrier_A_O: RC_FPV_Carrier_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Carrier_A_I: RC_FPV_Carrier_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};



class RC_FPV_Carrier_WD: RC_FPV_Carrier_A
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
class RC_FPV_Carrier_WD_O: RC_FPV_Carrier_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Carrier_WD_I: RC_FPV_Carrier_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};