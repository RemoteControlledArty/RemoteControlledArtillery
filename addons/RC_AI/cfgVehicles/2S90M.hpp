class RC_2S90M_WD;
class RC_AI_B_2S90M_WD_Core: RC_2S90M_WD
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
class RC_AI_B_2S90M_WD_Base: RC_AI_B_2S90M_WD_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_AI\includes_script\GunnerOrCommanderIsDriverEH_AI.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
		/*
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		*/
	};
	
	#include "\RC_AI\includes_script\UserActions_TakeDriverControlsGlobalServer_AI.hpp"
	#include "\RC_AI\includes_cfg\AI_DriverComponents4km.hpp"

	displayName="[AI] 2S90M";
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
		//"RC_1Rnd_APS_M",
		//"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=0;		//1
			commanding=1;		//3

			weapons[]=
			{
				"RC_AI_cannon_125mm",
				"RC_AI_MMG_93x64_coax_ext",
				"SmokeLauncher"
			};

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
			weapon="RC_AI_cannon_125mm";
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_AI_cannon_125mm";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_AI_cannon_125mm";
		};
	};

	#include "\RC_AI\loadouts\FSVitemsO_RHS_AI.hpp"
};


class RC_AI_B_2S90M_WD: RC_AI_B_2S90M_WD_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_2S90M_red.hpp"
		};
	};
};
class RC_AI_O_2S90M_WD: RC_AI_B_2S90M_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_2S90M_green.hpp"
		};
	};
};
class RC_AI_I_2S90M_WD: RC_AI_B_2S90M_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_2S90M_yellow.hpp"
		};
	};
};


class RC_AI_B_2S90M_A: RC_AI_B_2S90M_WD
{
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\Aegis_O_SFIA_APC_Wheeled_04_cannon_v2_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body2_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\apc_wheeled_04_sprut_turret_sand_co.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_Green_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	/*
	textureList[]=
	{
		"Green",
		0,
		"Sand",
		0
	};
	*/
};
class RC_AI_O_2S90M_A: RC_AI_B_2S90M_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_2S90M_green.hpp"
		};
	};
};
class RC_AI_I_2S90M_A: RC_AI_B_2S90M_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_2S90M_yellow.hpp"
		};
	};
};