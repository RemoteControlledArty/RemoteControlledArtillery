class RC_Stryker_M1126_M2_Javelin_WD_B;
class RC_AI_B_M1126_M2Jav_WD_Core: RC_Stryker_M1126_M2_Javelin_WD_B
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
class RC_AI_B_M1126_M2Jav_WD_Base: RC_AI_B_M1126_M2Jav_WD_Core
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
	#include "\RC_AI\includes_cfg\AI_DriverComponents4km.hpp"

	displayName="[AI] M1126 Stryker M2 Javelin";
	forceInGarage=1;	//1
	driverCompartments="Compartment2";	//2
	commanding=1;			//1
	ejectDeadGunner=1;		//0
	ejectDeadDriver=1;		//0
	ejectDeadCommander=1;	//0

	weapons[]=
	{
		"RC_APS_W",
		"rhsusf_weap_M6"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		//"RC_1Rnd_APS_M",
		"rhsusf_mag_L8A3_16",
		"rhsusf_mag_L8A3_16",
		"rhsusf_mag_L8A3_16"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=0;		//1
			commanding=1;		//3
			
			weapons[]=
			{
				"RC_AI_RHS_M2_CROWS_M151",
				"RC_AI_Stryker_Missile_Launcher",
				"rhsusf_weap_M6"
			};
		};
	};

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};

	class AnimationSources: AnimationSources
	{
		class M2_CROWS_AmmoRandom
		{
			weapon="RC_AI_RHS_M2_CROWS_M151";
			source="ammorandom";
		};
		class M2_CROWS_Reload
		{
			weapon="RC_AI_RHS_M2_CROWS_M151";
			source="reload";
		};
		class M2_CROWS_ReloadMagazine
		{
			weapon="RC_AI_RHS_M2_CROWS_M151";
			source="reloadmagazine";
		};
		class M2_CROWS_Revolving
		{
			weapon="RC_AI_RHS_M2_CROWS_M151";
			source="revolving";
		};
	};
};


class RC_AI_B_M1126_M2Jav_WD: RC_AI_B_M1126_M2Jav_WD_Base
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
			#include "\RC_AI\includes_vicmags\mags_AI_Stryker_M2Jav_red.hpp"
		};
	};
};
class RC_AI_O_M1126_M2Jav_WD: RC_AI_B_M1126_M2Jav_WD
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
			#include "\RC_AI\includes_vicmags\mags_AI_Stryker_M2Jav_green.hpp"
		};
	};
	*/
};
class RC_AI_I_M1126_M2Jav_WD: RC_AI_B_M1126_M2Jav_WD
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
			#include "\RC_AI\includes_vicmags\mags_AI_Stryker_M2Jav_yellow.hpp"
		};
	};
	*/
};


class RC_AI_B_M1126_M2Jav_A: RC_AI_B_M1126_M2Jav_WD
{
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_stryker_m1126_m2_d.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_hull_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_parts_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_slat_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_crows_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_wheels_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_ca.paa",
		"rhsusf\addons\rhsusf_m1a1\DUKE\data\duke_antennae_c_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa"
	};
};
class RC_AI_O_M1126_M2Jav_A: RC_AI_B_M1126_M2Jav_A
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
			#include "\RC_AI\includes_vicmags\mags_AI_Stryker_M2Jav_green.hpp"
		};
	};
	*/
};
class RC_AI_I_M1126_M2Jav_A: RC_AI_B_M1126_M2Jav_A
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
			#include "\RC_AI\includes_vicmags\mags_AI_Stryker_M2Jav_yellow.hpp"
		};
	};
	*/
};