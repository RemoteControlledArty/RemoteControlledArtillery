class O_MBT_02_cannon_F;
class RC_MBT_4_Base: O_MBT_02_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	class AnimationSources;
	class showCamonetCannon;
	class showCamonetHull;
	class showCamonetTurret;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_MBT_4_HEX_A_Base: RC_MBT_4_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	faction="RemoteControlled_O";
	editorSubcategory="RC_MBT_subcat";
	author="Ascent";
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	maxSpeed=70;
	enginePower=1400;
	peakTorque=6875;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=2;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_cannon_125mm_advanced",
				"RC_MMG_93x64_coax",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T100_green.hpp"

			class OpticsIn
			{
				class Wide: RCWSOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=1;
					turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_HMG_127_NSVT",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T100_com_green.hpp"

					class OpticsIn
					{
						class Wide: RCWSOptics
						{
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={0};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_cannon_125mm_advanced";
		};
		class muzzle_rot_coax
		{
			source="ammorandom";
			weapon="RC_MMG_93x64_coax";
		};
		class muzzle_hide_coax
		{
			source="reload";
			weapon="RC_MMG_93x64_coax";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_cannon_125mm_advanced";
		};
		class zeroing_cannon
		{
			source="zeroing";
			weapon="RC_cannon_125mm_advanced";
		};
		class muzzle_rot_HMG
		{
			source="ammorandom";
			weapon="RC_HMG_127_NSVT";
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetCannon",
		1,
		"showCamonetHull",
		1,
		"showCamonetTurret",
		1
	};

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};


class RC_MBT_4_HEX_A_O: RC_MBT_4_HEX_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	displayName="T-100";
	scope=2;
	scopeCurator=2;
	side=0;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	crew="O_UAV_AI";
};
class RC_MBT_4_HEX_WD_O: RC_MBT_4_HEX_A_O
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_MBT_02_cannon_ghex_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_body_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_turret_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa"
	};
	textureList[]=
	{
		"GreenHex",
		1
	};
};