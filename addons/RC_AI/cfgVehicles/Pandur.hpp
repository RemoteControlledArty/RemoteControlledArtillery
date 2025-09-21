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

	displayName="[AI] Pandur II";
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

			weapons[]=
			{
				"RC_AI_autocannon_30mm_CTWS",
				"RC_AI_MMG_338_coax_ext",
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
	//#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Pandur_red.hpp"
		};
	};
};
class RC_AI_O_Pandur_A: RC_AI_B_Pandur_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";	//O_UAV_AI
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Pandur_green.hpp"
		};
	};
};
class RC_AI_I_Pandur_A: RC_AI_B_Pandur_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";	//I_UAV_AI
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Pandur_yellow.hpp"
		};
	};
};
class RC_AI_I_Pandur_DIG: RC_AI_I_Pandur_A
{
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_APC_Wheeled_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext2_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\RCWS30_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_alpha_INDP_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
};


class RC_AI_B_Pandur_WD: RC_AI_B_Pandur_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext2_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\RCWS30_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_alpha_IG_01_CO.paa",
		//"A3\Armor_F\Data\camonet_AAF_FIA_green_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\armor_f\data\cage_G1_co.paa"
	};
	textureList[]=
	{
		"Guerilla_01",
		1,
		"Guerilla_02",
		0,
		"Guerilla_03",
		0
	};
};
class RC_AI_O_Pandur_WD: RC_AI_B_Pandur_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Pandur_green.hpp"
		};
	};
};
class RC_AI_I_Pandur_WD: RC_AI_B_Pandur_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Pandur_yellow.hpp"
		};
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
/*
class RC_IFV_3_ReTex_WD: RC_IFV_3_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	hiddenSelectionsTextures[]=
	{
		"pandurii\data\pandur_01_ext_wd.paa",
		"pandurii\data\pandur_02_ext_wd.paa",
		"pandurii\data\pandur_turret_wd.paa",
		"pandurii\data\pandur_03_ext_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"a3\armor_f\data\cage_g1_co.paa"
	};
};
class RC_IFV_3_ReTex_WD_O: RC_IFV_3_ReTex_WD
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Pandur_green.hpp"
		};
	};
};
class RC_IFV_3_ReTex_WD_I: RC_IFV_3_ReTex_WD
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Pandur_yellow.hpp"
		};
	};
};


class RC_IFV_3_ReTex_D: RC_IFV_3_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"pandurii\data\pandur_01_ext_d.paa",
		"pandurii\data\pandur_02_ext_d.paa",
		"pandurii\data\pandur_turret_d.paa",
		"pandurii\data\pandur_03_ext_d.paa",
		"pandurii\data\camonet_desert_co.paa",
		"pandurii\data\cage_desert_co.paa"
	};
};
class RC_IFV_3_ReTex_D_O: RC_IFV_3_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Pandur_green.hpp"
		};
	};
};
class RC_IFV_3_ReTex_D_I: RC_IFV_3_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Pandur_yellow.hpp"
		};
	};
};
*/