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
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Titus_AC_D: RC_Titus_AC_base
{
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\RC_Titus\cfgVehicles\Titus_include.hpp"

	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	displayName="Titus 20mm";
	editorSubcategory="RC_Titus_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_Titus_autocannon_20mm";
		};
		class muzzle2_rot
		{
			source="ammorandom";
			weapon="RC_QIN_338_MMG2";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_Titus_autocannon_20mm";
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
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			showAllTargets="2 + 4";

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
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
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
				"RC_Titus_autocannon_20mm",
				"RC_QIN_338_MMG2",
				"SmokeLauncher"
			};
			#include "\RC_Titus\includes_vicmags\mags_Titus_20mm_red.hpp"

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
						/*
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						*/
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
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
						/*
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						*/
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					//defaultDisplay="EmptyDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
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
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
					};
				};
			};
		};

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_AC_WD: RC_Titus_AC_D
{
	#include "\RC_Titus\textures\tex_wd_armed.hpp"
};
class RC_Titus_AC_A: RC_Titus_AC_D
{
	#include "\RC_Titus\textures\tex_a_unarmed.hpp"
};


class RC_Titus_AC_D_O: RC_Titus_AC_D
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			#include "\RC_Titus\includes_vicmags\mags_Titus_20mm_green.hpp"
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_AC_WD_O: RC_Titus_AC_D_O
{
	#include "\RC_Titus\textures\tex_wd_armed.hpp"
};
class RC_Titus_AC_A_O: RC_Titus_AC_D_O
{
	#include "\RC_Titus\textures\tex_a_armed.hpp"
};


class RC_Titus_AC_D_I: RC_Titus_AC_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			#include "\RC_Titus\includes_vicmags\mags_Titus_20mm_yellow.hpp"
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_AC_WD_I: RC_Titus_AC_D_I
{
	#include "\RC_Titus\textures\tex_wd_armed.hpp"
};
class RC_Titus_AC_A_I: RC_Titus_AC_D_I
{
	#include "\RC_Titus\textures\tex_a_armed.hpp"
};


class RC_Titus_MMG_D: RC_Titus_AC_D
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\initICV.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
	};

	displayName="RC Titus MMG";
	
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";

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
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
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
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
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
			#include "\RC_Titus\includes_vicmags\mags_Titus_MMG_red.hpp"
		};

		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_MMG_WD: RC_Titus_MMG_D
{
	#include "\RC_Titus\textures\tex_wd_armed.hpp"
};
class RC_Titus_MMG_A: RC_Titus_MMG_D
{
	#include "\RC_Titus\textures\tex_a_armed.hpp"
};


class RC_Titus_MMG_D_O: RC_Titus_MMG_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			#include "\RC_Titus\includes_vicmags\mags_Titus_MMG_green.hpp"
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_MMG_WD_O: RC_Titus_MMG_D_O
{
	#include "\RC_Titus\textures\tex_wd_armed.hpp"
};
class RC_Titus_MMG_A_O: RC_Titus_MMG_D_O
{
	#include "\RC_Titus\textures\tex_a_armed.hpp"
};


class RC_Titus_MMG_D_I: RC_Titus_MMG_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class ARX20Turret: ARX20Turret
		{
			#include "\RC_Titus\includes_vicmags\mags_Titus_MMG_yellow.hpp"
		};

		class CommanderTurret: CommanderTurret {};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
	};
};
class RC_Titus_MMG_WD_I: RC_Titus_MMG_D_I
{
	#include "\RC_Titus\textures\tex_wd_armed.hpp"
};
class RC_Titus_MMG_A_I: RC_Titus_MMG_D_I
{
	#include "\RC_Titus\textures\tex_a_armed.hpp"
};