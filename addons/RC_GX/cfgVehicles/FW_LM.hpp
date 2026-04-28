class VVE_APC_Wheeled_01_apc_QAV;
class RC_AMV_APC_Fetch: VVE_APC_Wheeled_01_apc_QAV
{
	class EventHandlers;
	class UserActions;
	class Components;

	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;

	class AnimationSources;
	//class nethull;
	class armor_comp;
	class TextureSources;

	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;

	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_AMV_APC_Core: RC_AMV_APC_Fetch
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\EjectDeadCrew.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";

	driverCompartments="Compartment2";
	commanding=1;
	crewCrashProtection=0.01;

	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};
};


class RC_AMV_APC_Base: RC_AMV_APC_Core
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	RC_ATrespondingTurret[]={0,0};

	displayName="Patria AMV APC";
	editorSubcategory="RC_APC_ATGM_subcat";

	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=600;
	peakTorque=3000;

	weapons[]=
	{
		//"TruckHorn",
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;

			//minElev=-;
			//maxElev=;

			weapons[]=
			{
				"RC_AMV_HMG",
				"RC_IFV_Missile_Launcher_Single",
				"SmokeLauncher"
			};

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";

					minAngleX=-30;
					maxAngleX=30;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
				};
			};
			turretInfoType="RscOptics_MBT_03_gunner";
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=2;

					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};

					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";

							minAngleX=-30;
							maxAngleX=30;
							minAngleY=-100;
							maxAngleY=100;

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
						};
					};
					turretInfoType="RscOptics_MBT_03_gunner";
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class zasleh3_hide
		{
			source="reload";
			weapon="RC_AMV_HMG";
		};
		class zasleh3_rot
		{
			source="ammorandom";
			weapon="RC_AMV_HMG";
		};
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_IFV_Missile_Launcher_Single";
		};
		class Missiles_reloadMagazine: Missiles_revolving
		{
			source="reloadMagazine";
		};
		/*
		class nethull: nethull
		{
			initPhase=1;
		};
		*/
		class armor_comp: armor_comp
		{
			initPhase=1;
		};
	};

	class TextureSources: TextureSources
	{
		class arid
		{
			displayName="Arid";
			textures[]=
			{
				"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
				"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
				"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
				"QAV_Marshall\data\textures\apc_wheeled_01_mgs_co.paa",
				"QAV_Marshall\data\textures\apc_wheeled_01_mgs_adds_co.paa",
				"QAV_Marshall\data\textures\apc_wheeled_01_apc_co.paa",
				"QAV_Marshall\data\textures\eos_r400_co.paa",
				"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
				"a3\weapons_f_beta\launchers\titan\data\tubem_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class woodland
		{
			displayName="Woodland";
			textures[]=
			{
				"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_base_olive_CO.paa",
				"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_adds_olive_co.paa",
				"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_tows_olive_co.paa",
				"QAV_Marshall\data\textures\olive\apc_wheeled_01_mgs_co.paa",
				"QAV_Marshall\data\textures\olive\apc_wheeled_01_mgs_adds_co.paa",
				"QAV_Marshall\data\textures\olive\apc_wheeled_01_apc_co.paa",
				"QAV_Marshall\data\textures\olive\eos_r400_co.paa",
				"a3\armor_f\data\camonet_green_co.paa",
				"a3\weapons_f_exp\Launchers\Titan\Data\launch_B_Titan_short_tna_F_02_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
	};

	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_base_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_adds_co.paa",
		"a3\armor_f_beta\APC_Wheeled_01\data\APC_Wheeled_01_tows_co.paa",
		"QAV_Marshall\data\textures\apc_wheeled_01_mgs_co.paa",
		"QAV_Marshall\data\textures\apc_wheeled_01_mgs_adds_co.paa",
		"QAV_Marshall\data\textures\apc_wheeled_01_apc_co.paa",
		"QAV_Marshall\data\textures\eos_r400_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"a3\weapons_f_beta\launchers\titan\data\tubem_co.paa"
	};
	textureList[]=
	{
		"arid",
		1
	};
};


class RC_AMV_APC_A_B: RC_AMV_APC_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_VVE\includes_vicmags\mags_AMV_APC_R.hpp"
		};
	};
};
class RC_AMV_APC_A_O: RC_AMV_APC_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_VVE\includes_vicmags\mags_AMV_APC_G.hpp"
		};
	};
};
class RC_AMV_APC_A_I: RC_AMV_APC_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_VVE\includes_vicmags\mags_AMV_APC_Y.hpp"
		};
	};
};


class RC_AMV_APC_WD_B: RC_AMV_APC_A_B
{
	#include "\RC_VVE\textures\AMV_APC_Texture_WD.hpp"
};
class RC_AMV_APC_WD_O: RC_AMV_APC_A_O
{
	#include "\RC_VVE\textures\AMV_APC_Texture_WD.hpp"
};
class RC_AMV_APC_WD_I: RC_AMV_APC_A_I
{
	#include "\RC_VVE\textures\AMV_APC_Texture_WD.hpp"
};