class RC_IFV_4_A;
class RC_AI_B_Patria40_A_Core: RC_IFV_4_A
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
class RC_AI_B_Patria40_A_Base: RC_AI_B_Patria40_A_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_AI\includes_script\GunnerOrCommanderIsDriverEH_AI.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
		class RC_EngineOff
		{
			#include "\RC_AI\includes_script\EmptyGetOutEngineOffEH.hpp"
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

	displayName="[AI] Patria AMV40";
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
				"RC_AI_autocannon_40mm_CTWS",
				"RC_AI_MMG_338_coax",
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
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_AI_autocannon_40mm_CTWS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_AI_autocannon_40mm_CTWS";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_AI_autocannon_40mm_CTWS";
		};
	};
};


class RC_AI_B_Patria40_A: RC_AI_B_Patria40_A_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Patria40_red.hpp"
		};
	};
};
class RC_AI_O_Patria40_A: RC_AI_B_Patria40_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Patria40_green.hpp"
		};
	};
};
class RC_AI_I_Patria40_A: RC_AI_B_Patria40_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Patria40_yellow.hpp"
		};
	};
};


class RC_AI_B_Patria40_WD: RC_AI_B_Patria40_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_base_olive_CO.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_adds_olive_co.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_tows_olive_co.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"a3\Armor_F\Data\cage_olive_CO.paa"
	};
};
class RC_AI_O_Patria40_WD: RC_AI_B_Patria40_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Patria40_green.hpp"
		};
	};
};
class RC_AI_I_Patria40_WD: RC_AI_B_Patria40_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Patria40_yellow.hpp"
		};
	};
};