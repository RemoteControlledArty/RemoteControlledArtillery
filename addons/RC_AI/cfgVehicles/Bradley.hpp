class RC_M2A3_BUSKIII_NLOS_D_B;
class RC_M2A3_BUSKIII_NLOS_D_B_Core: RC_M2A3_BUSKIII_NLOS_D_B
{
	class Components;
	class UserActions;
	class EventHandlers;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class AnimationSources;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_M2A3_BUSKIII_D_Base: RC_M2A3_BUSKIII_NLOS_D_B_Core
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

	displayName="[AI] M2A3 Bradley";
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
		"rhsusf_weap_M257_8"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		//"RC_1Rnd_APS_M",
		"rhsusf_mag_L8A3_8",
		"rhsusf_mag_L8A3_8"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=0;		//1
			commanding=1;		//3
			
			weapons[]=
			{
				"RC_AI_RHS_weap_M242BC",
				"RC_AI_RHS_weap_m240_bradley_coax",
				"RC_AI_Bradley_Missile_Launcher",
				"rhs_weap_fcs_ammo",

				"rhsusf_weap_M257_8"
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

	class AnimationSources: AnimationSources
	{
		class recoil_source
		{
			source="reload";
			weapon="RC_AI_RHS_weap_M242BC";
		};
		class muzzle_hide_hmg: recoil_source
		{
		};
		class muzzle_rot_hmg: recoil_source
		{
			source="ammorandom";
		};
		class muzzle_rot_hmg2: muzzle_rot_hmg
		{
			weapon="RC_AI_RHS_weap_m240_bradley_coax";
		};
	};
};


class RC_AI_B_M2A3_BUSKIII_D: RC_AI_B_M2A3_BUSKIII_D_Base
{
	scope=2;
	scopeCurator=2;

	faction="RC_AI_B";
	crew="RC_AI_B_Crew";
	//#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AI\includes_vicmags\mags_AI_Bradley_red.hpp"
		};
	};
};
class RC_AI_O_M2A3_BUSKIII_D: RC_AI_B_M2A3_BUSKIII_D
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Bradley_green.hpp"
		};
	};
	*/
};
class RC_AI_I_M2A3_BUSKIII_D: RC_AI_B_M2A3_BUSKIII_D
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Bradley_yellow.hpp"
		};
	};
	*/
};


class RC_AI_B_M2A3_BUSKIII_WD: RC_AI_B_M2A3_BUSKIII_D
{
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\RHS_M2A3_BUSKIII_wd.paa";
	hiddenSelectionsTextures[]=
	{
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\m6_base_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\m6_a3_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\ultralp_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\BUSKIII_co.paa",
		"\rhsusf\addons\rhsusf_m1a1\duke\data\duke_antennae_wd_co.paa"
	};
};
class RC_AI_O_M2A3_BUSKIII_WD: RC_AI_B_M2A3_BUSKIII_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Bradley_green.hpp"
		};
	};
	*/
};
class RC_AI_I_M2A3_BUSKIII_WD: RC_AI_B_M2A3_BUSKIII_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Bradley_yellow.hpp"
		};
	};
	*/
};