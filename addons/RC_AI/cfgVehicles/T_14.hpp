class RC_MBT_3_WD2;
class RC_AI_B_T14_WD_Core: RC_MBT_3_WD2
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class AnimationSources;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_T14_WD_Base: RC_AI_B_T14_WD_Core
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

	displayName="[AI] T-14";
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
		class com_gun_reload
		{
			source="reload";
			weapon="RC_AI_autocannon_30mm_RCWS";
		};
	};
};


class RC_AI_B_T14_WD: RC_AI_B_T14_WD_Base
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
			weapons[]=
			{
				"RC_AI_cannon_125mm_advanced",
				"RC_AI_MMG_93x64_coax",
				"SmokeLauncher"
			};
			#include "\RC_AI\includes_vicmags\mags_AI_T14_red.hpp"

			class Turrets: Turrets
			{
				weapons[]=
				{
					"RC_AI_autocannon_30mm_RCWS",
					"RC_Laserdesignator_vehicle",
					"SmokeLauncher"
				};
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_T14_com_red.hpp"
				};
			};
		};
	};
};
class RC_AI_O_T14_WD: RC_AI_B_T14_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_T14_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_T14_com_green.hpp"
				};
			};
		};
	};
};
class RC_AI_I_T14_WD: RC_AI_B_T14_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_T14_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_T14_com_yellow.hpp"
				};
			};
		};
	};
};