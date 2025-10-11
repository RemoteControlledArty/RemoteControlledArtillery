class RC_MBT_4_WD;
class RC_AI_B_T100_WD_Core: RC_MBT_4_WD
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class AnimationSources;
	class showCamonetCannon;
	class showCamonetHull;
	class showCamonetTurret;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_T100_WD_Base: RC_AI_B_T100_WD_Core
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

	displayName="[AI] T-100";
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
				"RC_AI_cannon_125mm_advanced",
				"RC_AI_MMG_93x64_coax",
				"SmokeLauncher"
			};

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					dontCreateAI=0;	//1
					commanding=2;	//2
					
					weapons[]=
					{
						"RC_AI_HMG_127_NSVT",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_AI_cannon_125mm_advanced";
		};
		class muzzle_rot_coax
		{
			source="ammorandom";
			weapon="RC_AI_MMG_93x64_coax";
		};
		class muzzle_hide_coax
		{
			source="reload";
			weapon="RC_AI_MMG_93x64_coax";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_AI_cannon_125mm_advanced";
		};
		class zeroing_cannon
		{
			source="zeroing";
			weapon="RC_AI_cannon_125mm_advanced";
		};
		class muzzle_rot_HMG
		{
			source="ammorandom";
			weapon="RC_AI_HMG_127_NSVT";
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=0;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=0;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=0;
		};
	};
	animationList[]=
	{
		"showCamonetCannon",
		0,
		"showCamonetHull",
		0,
		"showCamonetTurret",
		0
	};

	#include "\RC_AI\loadouts\FSVitemsO_RHS_AI.hpp"
};


class RC_AI_B_T100_WD: RC_AI_B_T100_WD_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_T100_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_T100_com_red.hpp"
				};
			};
		};
	};
};
class RC_AI_O_T100_WD: RC_AI_B_T100_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_T100_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_T100_com_green.hpp"
				};
			};
		};
	};
};
class RC_AI_I_T100_WD: RC_AI_B_T100_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_T100_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_T100_com_yellow.hpp"
				};
			};
		};
	};
};