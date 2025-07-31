// FPV Trucks
class B_Truck_01_box_F;
class RC_FPV_Truck_Core: B_Truck_01_box_F
{
	class Components;
	class ViewOptics;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_FPV_Truck_Base: RC_FPV_Truck_Core
{
	class EventHandlers: EventHandlers
	{
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

	//#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	author="Ascent";
	editorSubcategory="RC_UAV_Deployers_subcat";
	side=1;
	forceInGarage=1;

	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;

	threat[]={0,0,0};
	cost=0;
	typicalCargo[]=
	{
		""
	};

	smokeLauncherVelocity=6;
	smokeLauncherGrenadeCount=8;
	smokeLauncherOnTurret=0;
	smokeLauncherAngle=360;

	/*
	weapons[]=
	{
		"RC_FPV_Deployer",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_18xFPV_Deployer_Mag",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};
	*/

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
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
			};
		};
	};
};
class RC_FPV_Truck_A: RC_FPV_Truck_Base
{
	displayName="RC FPV Truck";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	//driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
	memoryPointDriverOptics="driverview";

	class ViewOptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_FPV_Truck_A_O: RC_FPV_Truck_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Truck_A_I: RC_FPV_Truck_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_FPV_Truck_WD: RC_FPV_Truck_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Truck_01_box_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\A3\Soft_F_Exp\Truck_01\Data\truck_01_ammo_olive_CO.paa",
		"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
	};
};
class RC_FPV_Truck_WD_O: RC_FPV_Truck_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Truck_WD_I: RC_FPV_Truck_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_FPV_Truck_manned_A: RC_FPV_Truck_Base
{
	displayName="FPV Truck";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	forceInGarage=1;

	faction="RemoteControlled_B";
	crew="";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_FPV_Truck_manned_A_O: RC_FPV_Truck_manned_A
{
	faction="RemoteControlled_O";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Truck_manned_A_I: RC_FPV_Truck_manned_A
{
	faction="RemoteControlled_I";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_FPV_Truck_manned_WD: RC_FPV_Truck_manned_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Truck_01_box_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\A3\Soft_F_Exp\Truck_01\Data\truck_01_ammo_olive_CO.paa",
		"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
	};
};
class RC_FPV_Truck_WD_manned_O: RC_FPV_Truck_manned_WD
{
	faction="RemoteControlled_O";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_FPV_Truck_WD_manned_I: RC_FPV_Truck_manned_WD
{
	faction="RemoteControlled_I";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};