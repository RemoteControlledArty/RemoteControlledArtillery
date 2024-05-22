class QIN_Titus_arx20_DES;
class RC_Titus_AC_base: QIN_Titus_arx20_DES
{
	class ARX20Turret;

	class Turrets;
	class ViewOptics;
	class ViewGunner;
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
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Titus_AC_D: RC_Titus_AC_base
{
	#include "\RC_Titus\Titus_include.hpp"

	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes\initICV.hpp"
		#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
	};

	displayName="RC Titus 20mm";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_QIN_20mm_AC";
		};
		class muzzle2_rot
		{
			source="ammorandom";
			weapon="RC_QIN_338_MMG2";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_QIN_20mm_AC";
		};
		class muzzle2_hide
		{
			source="reload";
			weapon="RC_QIN_338_MMG2";
		};
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
		class CommanderTurret: CommanderTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
			gunnerCompartments="Compartment4";
			primaryGunner=1;
			primaryObserver=0;
			gunnerForceOptics=1;
			forceHideGunner=1;
			commanding=4;
			isPersonTurret=0;

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
				"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
		class ARX20Turret: ARX20Turret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			primaryGunner=0;
			primaryObserver=1;
			showAllTargets="2 + 4";

			class ViewOptics: ViewOptics
			{
				minFov=0.025;
				maxFov=0.9;
				initFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};

			weapons[]=
			{
				"RC_QIN_20mm_AC",
				"RC_QIN_338_MMG2",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_QIN_100Rnd_20mm_T_R",
				"RC_QIN_100Rnd_20mm_T_R",
				"RC_QIN_100Rnd_20mm_T_R",
				"RC_QIN_100Rnd_20mm_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
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
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleGunnerDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="PrimaryGunner";
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
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
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
	};
};


class RC_Titus_MMG_D: RC_Titus_AC_D
{
	#include "\RC_Titus\Titus_include.hpp"

	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes\initICV.hpp"
		#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_ICV.hpp"
	};

	displayName="RC Titus MMG";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_QIN_338_MMG1";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_QIN_338_MMG1";
		};
	};

	class Turrets: Turrets
	{
		class CommanderTurret: CommanderTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			showAllTargets="2 + 4";
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
				"RC_Laserdesignator_vehicle",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
		class ARX20Turret: ARX20Turret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			primaryGunner=0;
			primaryObserver=1;
			showAllTargets="2 + 4";
			commanding=3;

			class ViewOptics: ViewOptics
			{
				minFov=0.025;
				maxFov=0.9;
				initFov=0.9;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};

			weapons[]=
			{
				"RC_QIN_338_MMG1",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
				"RC_QIN_150Rnd_338_T_R",
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
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleGunnerDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="PrimaryGunner";
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
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
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
	};
};

#include "\RC_Titus\include_armed.hpp"