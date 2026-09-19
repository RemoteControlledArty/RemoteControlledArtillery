class RC_MBT_3_WD2_Core;
class RC_AI_B_T14_Fetch: RC_MBT_3_WD2_Core
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class AdvisorOptics;
	class AnimationSources;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_T14_Core: RC_AI_B_T14_Fetch
{
	#include "\RC_AI\includes_cfg\AI_DriverComponents4km.hpp"

	displayName="[AI] T-14";

	driverCompartments="Compartment1";	//2
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
				//"RC_AI_MMG_93x64_coax",
				"RC_AI_MMG_762x54_coax",
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
						"RC_AI_autocannon_30mm_RCWS",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
				};

				class AdvisorOptics: AdvisorOptics {};
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
			//weapon="RC_AI_MMG_93x64_coax";
			weapon="RC_AI_MMG_762x54_coax";
		};
		class muzzle_hide_coax
		{
			source="reload";
			//weapon="RC_AI_MMG_93x64_coax";
			weapon="RC_AI_MMG_762x54_coax";
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

	#include "\RC_AI\loadouts\FSVitemsO_RHS_AI.hpp"
};
class RC_AI_B_T14_Base: RC_AI_B_T14_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Sensor_400m.hpp"
		//#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		//#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"

		#include "\RC_AI\includes_script\GunnerOrCommanderIsDriverEH_AI.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
	};

	#include "\RC_AI\includes_script\UserActions_TakeDriverControlsGlobalServer_AI.hpp"
};


class RC_AI_B_T14_WD: RC_AI_B_T14_Base
{
	scope=2;
	scopeCurator=2;
	#include "\RC_AI\includes_cfg\sideB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_T14_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_T14_com_red.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};
class RC_AI_O_T14_WD: RC_AI_B_T14_WD
{
	#include "\RC_AI\includes_cfg\sideO.hpp"

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

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};
class RC_AI_I_T14_WD: RC_AI_B_T14_WD
{
	#include "\RC_AI\includes_cfg\sideI.hpp"

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

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};