class QIN_Titus_DES;
class RC_Titus_unarmed_D_base: QIN_Titus_DES
{
	class Turrets;
	class ViewOptics;
	//class ViewGunner;
	class CommanderTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class AnimationSources;
	class Components;
	class Door_LF;
	class Door_RF;
	class Door_rear;
	class comp_camonet;
	class comp_klec;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};

class RC_Titus_unarmed_D: RC_Titus_unarmed_D_base
{
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\RC_Titus\cfgVehicles\Titus_include.hpp"

	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
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

	displayName="RC Titus";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	
	threat[]={0.30000001,0.30000001,0.30000001};

	class AnimationSources: AnimationSources
	{
		class Door_LF: Door_LF
		{
			animPeriod=0.5;
		};
		class Door_RF: Door_RF
		{
			animPeriod=0.5;
		};
		class Door_rear: Door_rear
		{
			animPeriod=0.8;
		};
		class comp_camonet: comp_camonet
		{
			initPhase=1;
		};
		class comp_klec: comp_klec
		{
			initPhase=1;
		};
	};

	class Turrets: Turrets
	{
		class CommanderTurret : CommanderTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment4";
			primaryGunner=1;
			primaryObserver=0;
			gunnerForceOptics=1;
			forceHideGunner=1;
			isPersonTurret=0;
			commanding=4;

			class ViewOptics: ViewOptics
			{
				initFov=1;
				minFov=0.05;
				maxFov=1;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
			};

			weapons[]=
			{
				//"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				//"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorsDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,400};
							resource="RscCustomInfoSensors";
						};
						/*
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						*/
						class CrewDisplay
						{
							componentType="CrewDisplayComponent";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorsDisplay";

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
						class CrewDisplay
						{
							componentType="CrewDisplayComponent";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
			};
		};

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03
		{
			gunnerName="Driver";
			commanding=3;
			primaryGunner=0;
			primaryObserver=1;

			weapons[]=
			{
				"TruckHorn2",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorsDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,400};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class CrewDisplay
						{
							componentType="CrewDisplayComponent";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorsDisplay";

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
						class CrewDisplay
						{
							componentType="CrewDisplayComponent";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
			};
		};
	};
};
class RC_Titus_unarmed_WD: RC_Titus_unarmed_D
{
	#include "\RC_Titus\textures\tex_wd_unarmed.hpp"
};
class RC_Titus_unarmed_A: RC_Titus_unarmed_D
{
	#include "\RC_Titus\textures\tex_a_unarmed.hpp"
};


class RC_Titus_unarmed_D_O: RC_Titus_unarmed_D
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_Titus_unarmed_WD_O: RC_Titus_unarmed_D_O
{
	#include "\RC_Titus\textures\tex_wd_unarmed.hpp"
};
class RC_Titus_unarmed_A_O: RC_Titus_unarmed_D_O
{
	#include "\RC_Titus\textures\tex_a_unarmed.hpp"
};


class RC_Titus_unarmed_D_I: RC_Titus_unarmed_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
class RC_Titus_unarmed_WD_I: RC_Titus_unarmed_D_I
{
	#include "\RC_Titus\textures\tex_wd_unarmed.hpp"
};
class RC_Titus_unarmed_A_I: RC_Titus_unarmed_D_I
{
	#include "\RC_Titus\textures\tex_a_unarmed.hpp"
};