class RC_MBT_2_A;
class RC_AI_B_Leopard_A_Core: RC_MBT_2_A
{
	class Turrets;
	class MainTurret;
	class AdvisorOptics;
	class CommanderOptics;
	class AnimationSources;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_Leopard_A_Base: RC_AI_B_Leopard_A_Core
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

	displayName="[AI] Leopard II";
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
				"RC_AI_cannon_120mm",
				"RC_AI_MMG_338_MBT_coax",
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
						"RC_AI_HMG_127x99_MBT",
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
		class muzzle_hide_cannon
		{
			source="reload";
			weapon="RC_AI_cannon_120mm";
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_AI_cannon_120mm";
		};
		class muzzle_rot_HMG
		{
			source="ammorandom";
			weapon="RC_AI_MMG_338_MBT_coax";
		};
		class cannon_120mm_revolving
		{
			source="revolving";
			weapon="RC_AI_cannon_120mm";
		};
		class com_gun_reload
		{
			source="reload";
			weapon="RC_AI_HMG_127x99_MBT";
		};
	};

	#include "\RC_AI\loadouts\FSVitemsB_RHS_AI.hpp"
};


class RC_AI_B_Leopard_A: RC_AI_B_Leopard_A_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";	//B_UAV_AI

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_red.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};
class RC_AI_O_Leopard_A: RC_AI_B_Leopard_A
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";	//O_UAV_AI
	side=0;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_green.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};
class RC_AI_I_Leopard_A: RC_AI_B_Leopard_A
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";	//I_UAV_AI
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Rooikat_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AI\includes_vicmags\mags_AI_FSV_MBT_com_yellow.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};


class RC_AI_B_Leopard_WD: RC_AI_B_Leopard_A
{
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext01_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext02_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_rcws_co.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AI_O_Leopard_WD: RC_AI_O_Leopard_A
{
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext01_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext02_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_rcws_co.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AI_I_Leopard_WD: RC_AI_I_Leopard_A
{
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext01_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext02_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_rcws_co.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};


//ReTextures (optional, found in steam workshop)
class RC_AI_B_Leopard_ReTex_WD: RC_AI_B_Leopard_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_wd.paa",
		"leopard2\data\leopard_ext02_wd.paa",
		"leopard2\data\leopard_rcws_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AI_O_Leopard_ReTex_WD: RC_AI_O_Leopard_A
{
	faction="RemoteControlled_ReTex_O";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_wd.paa",
		"leopard2\data\leopard_ext02_wd.paa",
		"leopard2\data\leopard_rcws_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AI_I_Leopard_ReTex_WD: RC_AI_I_Leopard_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_wd.paa",
		"leopard2\data\leopard_ext02_wd.paa",
		"leopard2\data\leopard_rcws_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};


class RC_AI_B_Leopard_ReTex_A: RC_AI_B_Leopard_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Arid_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_e.paa",
		"leopard2\data\leopard_ext02_e.paa",
		"leopard2\data\leopard_rcws_e.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};
};
class RC_AI_O_Leopard_ReTex_A: RC_AI_O_Leopard_A
{
	faction="RemoteControlled_ReTex_O";
	editorSubcategory="RC_ReTex_Arid_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_e.paa",
		"leopard2\data\leopard_ext02_e.paa",
		"leopard2\data\leopard_rcws_e.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};
};
class RC_AI_I_Leopard_ReTex_A: RC_AI_I_Leopard_A
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Arid_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_e.paa",
		"leopard2\data\leopard_ext02_e.paa",
		"leopard2\data\leopard_rcws_e.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};
};