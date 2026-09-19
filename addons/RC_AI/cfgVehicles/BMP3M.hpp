class RC_BMP3M_Core;
class RC_AI_B_BMP3M_Fetch: RC_BMP3M_Core
{
	class Turrets;
	class MainTurret;
	class GPMGTurret1;
	class GPMGTurret2;
	class CommanderOptics;
	class AnimationSources;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_BMP3M_Core: RC_AI_B_BMP3M_Fetch
{
	#include "\RC_AI\includes_cfg\AI_DriverComponents4km.hpp"

	displayName="[AI] BMP-3";

	driverCompartments="Compartment1";	//2
	commanding=1;			//1
	ejectDeadGunner=1;		//0
	ejectDeadDriver=1;		//0
	ejectDeadCommander=1;	//0

	weapons[]=
	{
		"RC_APS_W",
		//"SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		//"RC_1Rnd_APS_M",
		//"SmokeLauncherMag",
		//"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class GPMGTurret1: GPMGTurret1
		{
			dontCreateAI=0;
		};
		class GPMGTurret2: GPMGTurret2
		{
			dontCreateAI=0;
		};

		class MainTurret: MainTurret
		{
			dontCreateAI=0;
			commanding=1;		//3
			
			weapons[]=
			{
				"RC_AI_RHS_weap_2a70",
				"RC_AI_RHS_weap_2a72",
				"RC_AI_RHS_weap_pkt_bmd_coax",
				"RC_RHS_weap_902a"
			};

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					dontCreateAI=0;
					commanding=2;	//2
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide_cannon
		{
			source="reload";
			weapon="RC_AI_RHS_weap_2a70";
		};
		class muzzle_hide_hmg
		{
			source="reload";
			weapon="RC_AI_RHS_weap_2a72";
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";	
			weapon="RC_AI_RHS_weap_2a70";
		};
		class muzzle_rot_coax
		{
			source="ammorandom";
			weapon="RC_AI_RHS_weap_pkt_bmd_coax";
		};
		class muzzle_rot_coax2
		{
			source="ammorandom";
			weapon="RC_AI_RHS_weap_pkt_bmd_bow1";
		};
		class muzzle_rot_coax3
		{
			source="ammorandom";
			weapon="RC_AI_RHS_weap_pkt_bmd_bow2";
		};
		class muzzle_rot_hmg
		{
			source="ammorandom";
			weapon="RC_AI_RHS_weap_2a72";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_AI_RHS_weap_2a70";
		};
		class recoil_source2
		{
			source="reload";
			weapon="RC_AI_RHS_weap_2a72";
		};
		class smokecap_revolving_source
		{
			source="revolving";
			weapon="RC_RHS_weap_902a";
		};
	};

	#include "\RC_AI\loadouts\FSVitemsO_RHS_AI.hpp"
};
class RC_AI_B_BMP3M_Base: RC_AI_B_BMP3M_Core
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


class RC_AI_B_BMP3_WD: RC_AI_B_BMP3_Base
{
	scope=2;
	scopeCurator=2;
	#include "\RC_AI\includes_cfg\sideB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BMP3_red.hpp"
		};
	};
};
class RC_AI_O_BMP3_WD: RC_AI_B_BMP3_WD
{
	#include "\RC_AI\includes_cfg\sideO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BMP3_green.hpp"
		};
	};
};
class RC_AI_I_BMP3_WD: RC_AI_B_BMP3_WD
{
	#include "\RC_AI\includes_cfg\sideI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BMP3_yellow.hpp"
		};
	};
};