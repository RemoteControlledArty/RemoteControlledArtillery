class RC_AbramsX_WD;
class RC_AI_B_AbramsX_WD_Core: RC_AbramsX_WD
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
class RC_AI_B_AbramsX_WD_Base: RC_AI_B_AbramsX_WD_Core
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
	#include "\RC_AI\includes_cfg\AI_DriverComponents4km_X.hpp"

	displayName="[AI] AbramsX";
	forceInGarage=1;	//1
	driverCompartments="Compartment2";	//2
	commanding=1;			//1
	ejectDeadGunner=1;		//0
	ejectDeadDriver=1;		//0
	ejectDeadCommander=1;	//0

	weapons[]=
	{
		"RC_APS_W",
		"qav_SmokeLauncher"
	};
	magazines[]=
	{
		"RC_1Rnd_APS_M",
		"qav_SmokeLauncherMag",
		"qav_SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_cfg\panels_AbramsX_gunner.hpp"
			dontCreateAI=0;		//1
			commanding=1;		//3
			
			weapons[]=
			{
				"RC_AI_AbramsX_120mm_M360",
				"RC_AI_AbramsX_HMG_coax",
				"qav_SmokeLauncher"
			};

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\RC_AI\includes_cfg\panels_AbramsX_commander.hpp"
					dontCreateAI=0;	//1
					commanding=2;	//2

					weapons[]=
					{
						"RC_AI_AbramsX_30mm_M914",
						"Laserdesignator_mounted",
						"qav_SmokeLauncher"
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class zasleh1_rot
		{
			source="ammorandom";
			weapon="RC_AI_AbramsX_120mm_M360";
		};
		class zasleh1_hide
		{
			source="reload";
			weapon="RC_AI_AbramsX_120mm_M360";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_AI_AbramsX_120mm_M360";
		};
		class zasleh3_hide
		{
			source="reload";
			weapon="RC_AI_AbramsX_30mm_M914";
		};
		class commandergun_recoil
		{
			source="reload";
			weapon="RC_AI_AbramsX_30mm_M914";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_AI_AbramsX_30mm_M914";
		};
		class zasleh2_rot
		{
			source="ammorandom";
			weapon="RC_AI_AbramsX_HMG_coax";
		};
		class zasleh2_hide
		{
			source="reload";
			weapon="RC_AI_AbramsX_HMG_coax";
		};
	};

	#include "\RC_AI\loadouts\FSVitemsB_RHS_AI.hpp"
};


class RC_AI_B_AbramsX_WD: RC_AI_B_AbramsX_WD_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_com_red.hpp"
				};
			};
		};
	};
};
class RC_AI_O_AbramsX_WD: RC_AI_B_AbramsX_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_com_green.hpp"
				};
			};
		};
	};
};
class RC_AI_I_AbramsX_WD: RC_AI_B_AbramsX_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_com_yellow.hpp"
				};
			};
		};
	};
};


class RC_AI_B_AbramsX_A: RC_AI_B_AbramsX_WD
{
	hiddenSelectionsTextures[]=
	{
		"QAV_AbramsX\data\textures\AbramsX\AbramsX_Hull_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};
	textureList[]=
	{
		"arid",
		1
	};
};
class RC_AI_O_AbramsX_A: RC_AI_B_AbramsX_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_com_green.hpp"
				};
			};
		};
	};
};
class RC_AI_I_AbramsX_A: RC_AI_B_AbramsX_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_AbramsX_com_yellow.hpp"
				};
			};
		};
	};
};