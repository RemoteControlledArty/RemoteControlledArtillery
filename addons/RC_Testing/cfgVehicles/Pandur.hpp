class RC_IFV_3_A;
class RC_AI_B_Pandur_A_Core: RC_IFV_3_A
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
class RC_AI_B_Pandur_A_Base: RC_AI_B_Pandur_A_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\GunnerOrCommanderIsDriverEH_Test.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
		class RC_EngineOff
		{
			#include "\RC_Testing\includes_script\EmptyGetOutEngineOffEH.hpp"
		};
		/*
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		*/
	};
	
	#include "\RC_Testing\includes_script\UserActions_TakeDriverControlsGlobalServer_Test.hpp"

	displayName="Test Pandur II";
	forceInGarage=1;	//1
	driverCompartments="Compartment2";	//2
	commanding=1;			//1
	ejectDeadGunner=1;		//0
	ejectDeadDriver=1;		//0
	ejectDeadCommander=1;	//0

	weapons[]=
	{
		"TruckHorn",
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

			/*
			weapons[]=
			{
				"RC_AI_autocannon_30mm_CTWS",
				"RC_AI_MMG_338_coax_ext",
				"RC_AI_IFV_Missile_Launcher",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_AI_100Rnd_30mm_HE_Pen_T_R",
				"RC_AI_100Rnd_30mm_HE_DF_T_R",
				"RC_AI_100Rnd_30mm_HEAB_DF_T_R",

				"RC_AI_100Rnd_30mm_APFSDS_T_R",
				"RC_AI_100Rnd_30mm_APFSDS_T_R",
				"RC_AI_100Rnd_30mm_APFSDS_T_R",

				"RC_AI_200Rnd_338_T_R",
				"RC_AI_200Rnd_338_T_R",
				"RC_AI_200Rnd_338_T_R",
				"RC_AI_200Rnd_338_T_R",

				"RC_AI_2Rnd_IFV_MP_SACLOS",
				"RC_AI_2Rnd_IFV_MP_SACLOS",

				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			*/

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
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_AI_autocannon_30mm_CTWS";
		};
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_AI_IFV_Missile_Launcher";
		};
		class Missiles_reloadMagazine: Missiles_revolving
		{
			source="reloadMagazine";
		};
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_AI_autocannon_30mm_CTWS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_AI_autocannon_30mm_CTWS";
		};
	};
};


class RC_AI_B_Pandur_A: RC_AI_B_Pandur_A_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";	//B_UAV_AI
};


/*
class RC_AI_O_Pandur_A: RC_AI_B_Pandur_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";	//O_UAV_AI
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_AI_I_Pandur_A: RC_AI_B_Pandur_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";	//I_UAV_AI
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
*/