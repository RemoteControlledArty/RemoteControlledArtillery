class RC_IFV_5_A2;	//Arid is WS, Woodland is Aegis!
class RC_AI_B_BM2T_A_Core: RC_IFV_5_A2
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	class AnimationSources;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_BM2T_A_Base: RC_AI_B_BM2T_A_Core
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

	displayName="[AI] BM-2T";
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
				"RC_AI_autocannon_30mm_CTWS",
				"RC_AI_MMG_93x64_coax_ext",
				"RC_AI_IFV_Missile_Launcher",
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

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_30mm_CTWS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm_CTWS";
		};
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_IFV_Missile_Launcher";
		};
		class Missiles_reloadMagazine: Missiles_revolving
		{
			source="reloadMagazine";
		};
	};
};


class RC_AI_B_BM2T_A: RC_AI_B_BM2T_A_Base
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
			#include "\RC_AI\includes_vicmags\mags_AI_BM_2T_red.hpp"
		};
	};
};
class RC_AI_O_BM2T_A: RC_AI_B_BM2T_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BM_2T_green.hpp"
		};
	};
};
class RC_AI_I_BM2T_A: RC_AI_B_BM2T_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BM_2T_yellow.hpp"
		};
	};
};