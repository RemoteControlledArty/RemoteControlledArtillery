class RC_M1A2_SEPV2_D_B;
class RC_AI_B_M1A2_SEPV2_D_Core: RC_M1A2_SEPV2_D_B
{
	class Turrets;
	class MainTurret;
	class CROWS_Turret;
	class AnimationSources;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_AI_B_M1A2_SEPV2_D_Base: RC_AI_B_M1A2_SEPV2_D_Core
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

	displayName="[AI] M1A2 SEPv2 Abrams";
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
		"rhsusf_weap_M250"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		"rhsusf_mag_L8A3_12",
		"rhsusf_mag_L8A3_12"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=0;		//1
			commanding=1;		//3

			weapons[]=
			{
				"RC_AI_RHS_weap_m256",
				"RC_AI_RHS_weap_m240_abrams_coax",
				"rhsusf_weap_M250"
			};

			class Turrets: Turrets
			{
				class CROWS_Turret : CROWS_Turret
				{
					dontCreateAI=0;	//1
					commanding=2;	//2

					weapons[]=
					{
						"RC_AI_RHS_M2_CROWS_M153_Abrams",
						"RC_Laserdesignator_vehicle",
						"rhsusf_weap_M250",
						"rhsusf_weap_duke"
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class recoil_source
		{
			source="reload";
			weapon="RC_AI_RHS_weap_m256";
		};
		class muzzle_hide_cannon: recoil_source
		{
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_AI_RHS_weap_m256";
		};
		class muzzle_rot_CoaxMG
		{
			source="ammorandom";
			weapon="RC_AI_RHS_weap_m240_abrams_coax";
		};
		/*
		class muzzle_rot_hmg2
		{
			source="ammorandom";
			weapon="RC_RHS_M2_Abrams_Gunner";
		};
		*/
		class muzzle_rot_crows
		{
			source="ammorandom";
			weapon="RC_AI_RHS_M2_CROWS_M153_Abrams";
		};
	};
};


class RC_AI_B_M1A2_SEPV2_D: RC_AI_B_M1A2_SEPV2_D_Base
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
			#include "\RC_AI\includes_vicmags\mags_AI_Abrams_red.hpp"

			class Turrets: Turrets
			{
				class CROWS_Turret: CROWS_Turret
				{
					#include "\RC_AI\includes_vicmags\mags_AI_Abrams_com_red.hpp"
				};
			};
		};
	};
};
class RC_AI_O_M1A2_SEPV2_D: RC_AI_B_M1A2_SEPV2_D
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Abrams_green.hpp"

			class Turrets: Turrets
			{
				class CROWS_Turret: CROWS_Turret
				{
					//#include "\RC_AI\includes_vicmags\mags_AI_Abrams_com_green.hpp"
				};
			};
		};
	};
};
class RC_AI_I_M1A2_SEPV2_D: RC_AI_B_M1A2_SEPV2_D
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Abrams_yellow.hpp"

			class Turrets: Turrets
			{
				class CROWS_Turret: CROWS_Turret
				{
					//#include "\RC_AI\includes_vicmags\mags_AI_Abrams_com_red.hpp"
				};
			};
		};
	};
};


class RC_AI_B_M1A2_SEPV2_WD: RC_AI_B_M1A2_SEPV2_D
{
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_m1a2sep2wd_usarmy.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1a2_wd_01_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1a2_wd_02_co.paa",
		"rhsusf\addons\rhsusf_m1a1\data\rhsusf_m1a1aim_03_co.paa",
		"rhsusf\addons\rhsusf_m1a1\loaderspintle\data\loaderspintle_wd_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_tuskia2_wd_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1slat_wd_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1a2sepv2_wd_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1a2sepv2_crows_wd_co.paa"
	};
};
class RC_AI_O_M1A2_SEPV2_WD: RC_AI_B_M1A2_SEPV2_WD
{
	faction="RC_AI_O";
	crew="RC_AI_O_Crew";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Abrams_green.hpp"

			class Turrets: Turrets
			{
				class CROWS_Turret: CROWS_Turret
				{
					//#include "\RC_AI\includes_vicmags\mags_AI_Abrams_com_red.hpp"
				};
			};
		};
	};
};
class RC_AI_I_M1A2_SEPV2_WD: RC_AI_B_M1A2_SEPV2_WD
{
	faction="RC_AI_I";
	crew="RC_AI_I_Crew";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\RC_AI\includes_vicmags\mags_AI_Pandur_Abrams_yellow.hpp"

			class Turrets: Turrets
			{
				class CROWS_Turret: CROWS_Turret
				{
					//#include "\RC_AI\includes_vicmags\mags_AI_Abrams_com_red.hpp"
				};
			};
		};
	};
};