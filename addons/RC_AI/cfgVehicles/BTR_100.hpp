class RC_IFV_7_WD;
class RC_AI_B_BTR100_A_Core: RC_IFV_7_WD
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
class RC_AI_B_BTR100_A_Base: RC_AI_B_BTR100_A_Core
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

	displayName="[AI] BTR-100 Bumerang";
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

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};

	class AnimationSources: AnimationSources
	{
		class reload_cannon
		{
			source="reload";
			weapon="RC_AI_autocannon_30mm_Bu";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_AI_autocannon_30mm_Bu";
		};
		class Missiles_reloadMagazine
		{
			source="reloadMagazine";
			weapon="RC_AI_IFV_Missile_Launcher_4R";
		};
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_AI_IFV_Missile_Launcher_4R";
		};
	};
};


class RC_AI_B_BTR100_A: RC_AI_B_BTR100_A_Base
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
				"RC_AI_autocannon_30mm_Bu",
				"RC_AI_MMG_93x64_coax_ext",
				"RC_AI_IFV_Missile_Launcher_4R",
				"SmokeLauncher"
			};
			#include "\RC_AI\includes_vicmags\mags_AI_BTR_100_red.hpp"
		};
	};
};
class RC_AI_O_BTR100_A: RC_AI_B_BTR100_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BTR_100_green.hpp"
		};
	};
};
class RC_AI_I_BTR100_A: RC_AI_B_BTR100_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BTR_100_yellow.hpp"
		};
	};
};


class RC_AI_B_BTR100_WD: RC_AI_B_BTR100_A
{
	//editorPreview="";		//non available
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body2_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_tow_sand_CO.paa",
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
class RC_AI_O_BTR100_WD: RC_AI_B_BTR100_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BTR_100_green.hpp"
		};
	};
};
class RC_AI_I_BTR100_WD: RC_AI_B_BTR100_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_BTR_100_yellow.hpp"
		};
	};
};