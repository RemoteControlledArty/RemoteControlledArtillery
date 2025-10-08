class RC_IFV_3_A_Base;
class RC_Test_B_Pandur_A_Core: RC_IFV_3_A_Base
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
class RC_Test_B_Pandur_A_Base: RC_Test_B_Pandur_A_Core
{
	editorSubcategory="RC_Testing_subcat";
	crew="RC_Test_B_Crew";	//B_UAV_AI

	forceInGarage=1;	//1
	driverCompartments="Compartment2";	//2
	commanding=1;			//1
	ejectDeadGunner=1;		//0
	ejectDeadDriver=1;		//0
	ejectDeadCommander=1;	//0

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
};


class RC_Test_B_Pandur_Agent: RC_Test_B_Pandur_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\Agent\Test_Agent_GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	#include "\RC_Testing\includes_script\Agent\Test_Agent_UserActions_TakeDriverControlsGlobalServer.hpp"

	displayName="Test Pandur - Agent AI";
	scope=2;
	scopeCurator=2;
};


class RC_Test_B_Pandur_AgentDelayed: RC_Test_B_Pandur_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\AgentDelayed\Test_AgentDelayed_GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	#include "\RC_Testing\includes_script\AgentDelayed\Test_AgentDelayed_UserActions_TakeDriverControlsGlobalServer.hpp"

	displayName="Test Pandur - AgentDelayed AI";
	scope=2;
	scopeCurator=2;
};


/*
class RC_Test_B_Pandur_AgentMove: RC_Test_B_Pandur_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\AgentMove\Test_AgentMove_GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	#include "\RC_Testing\includes_script\AgentMove\Test_AgentMove_UserActions_TakeDriverControlsGlobalServer.hpp"

	displayName="Test Pandur - AgentMove AI";
	scope=2;
	scopeCurator=2;
};


class RC_Test_B_Pandur_AgentMoveDelayed: RC_Test_B_Pandur_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\AgentMoveDelayed\Test_AgentMoveDelayed_GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	#include "\RC_Testing\includes_script\AgentMoveDelayed\Test_AgentMoveDelayed_UserActions_TakeDriverControlsGlobalServer.hpp"

	displayName="Test Pandur - AgentMoveDelayed AI";
	scope=2;
	scopeCurator=2;
};
*/


/*
driver deletion non stop triggers EH

class RC_Test_B_Pandur_AgentDelete: RC_Test_B_Pandur_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\AgentDelete\Test_AgentDelete_GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	#include "\RC_Testing\includes_script\AgentDelete\Test_AgentDelete_UserActions_TakeDriverControlsGlobalServer.hpp"

	displayName="Test Pandur - AgentDelete AI";
	scope=2;
	scopeCurator=2;
};
*/



class RC_Test_B_Pandur_UGV: RC_Test_B_Pandur_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\UGV\Test_UGV_GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	#include "\RC_Testing\includes_script\UGV\Test_UGV_UserActions_TakeDriverControlsGlobalServer.hpp"

	displayName="Test Pandur - UGV AI";
	scope=2;
	scopeCurator=2;
};


class RC_Test_B_Pandur_UGVDelayed: RC_Test_B_Pandur_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\RC_Testing\includes_script\UGVDelayed\Test_UGVDelayed_GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	#include "\RC_Testing\includes_script\UGVDelayed\Test_UGVDelayed_UserActions_TakeDriverControlsGlobalServer.hpp"

	displayName="Test Pandur - UGVDelayed AI";
	scope=2;
	scopeCurator=2;
};


/*
class RC_Test_O_Pandur_?: RC_Test_B_Pandur_?
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";	//O_UAV_AI
	side=0;
};
class RC_Test_I_Pandur_?: RC_Test_B_Pandur_?
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";	//I_UAV_AI
	side=2;
};
*/