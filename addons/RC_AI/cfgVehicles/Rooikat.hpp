class RC_FSV_A;
class RC_AI_B_Rooikat_A_Core: RC_FSV_A
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class AnimationSources;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_Rooikat_A_Base: RC_AI_B_Rooikat_A_Core
{
	/*
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
	};
	*/
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"

	displayName="[AI] Rooikat";
	forceInGarage=1;	//1
	driverCompartments="Compartment2";	//2
	commanding=1;			//1
	ejectDeadGunner=1;		//0
	ejectDeadDriver=1;		//0
	ejectDeadCommander=1;	//0

	weapons[]=
	{
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=0;		//1
			commanding=1;		//3

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					dontCreateAI=0;	//1
					commanding=2;	//2
				};
			};
		};
	};

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide_cannon
		{
			source="reload";
			weapon="RC_AI_cannon_120mm";
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_AI_cannon_120mm";
		};
		class muzzle_rot_HMG
		{
			source="ammorandom";
			weapon="RC_AI_MMG_338_FSV_coax";
		};
		class cannon_120mm_revolving
		{
			source="revolving";
			weapon="RC_AI_cannon_120mm";
		};
		class com_gun_reload
		{
			source="reload";
			weapon="RC_AI_HMG_127x99_FSV";
		};
	};
};


class RC_AI_B_Rooikat_A: RC_AI_B_Rooikat_A_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";	//B_UAV_AI
	//#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_AI_cannon_120mm",
				"RC_AI_MMG_338_FSV_coax",
				"SmokeLauncher"
			};
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					weapons[]=
					{
						"RC_AI_HMG_127x99_FSV",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_red.hpp"
				};
			};
		};
	};
};
class RC_AI_O_Rooikat_A: RC_AI_B_Rooikat_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";	//O_UAV_AI
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_green.hpp"
				};
			};
		};
	};
};
class RC_AI_I_Rooikat_A: RC_AI_B_Rooikat_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";	//I_UAV_AI
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_yellow.hpp"
				};
			};
		};
	};
};


class RC_AI_B_Rooikat_WD: RC_AI_B_Rooikat_A
{
	editorPreview="\A3\EditorPreviews_F_Tank\Data\CfgVehicles\B_T_AFV_Wheeled_01_up_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT1_green_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT2_green_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_wheel_green_CO.paa",
		"A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_CO.paa",
		"a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_commander_tow_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_CO.paa"
	};
	textureList[]=
	{
		"Green",
		0,
		"Sand",
		0
	};
};
class RC_AI_O_Rooikat_WD: RC_AI_B_Rooikat_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_green.hpp"
				};
			};
		};
	};
};
class RC_AI_I_Rooikat_WD: RC_AI_B_Rooikat_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_yellow.hpp"
				};
			};
		};
	};
};