class rhs_t90am_tv;
class RC_T90AM_Core: rhs_t90am_tv
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
class RC_T90AM_Base: RC_T90AM_Core
{
	class EventHandlers: EventHandlers
	{
		class RHS_EventHandlers
		{
			init="_this call RHS_fnc_T72_init;";
			postInit="_this call rhs_fnc_reapplyTextures";
			fired="_this call RHS_fnc_T72_autoloader;";
			hitpart="_this call rhs_fnc_hitSpall";
			getOut="_this call rhs_fnc_t72_hatch;_this call rhs_fnc_hatchAbandon";
			killed="[_this select 0,'rhs_Wreck_T90am_turret_F'] call rhs_fnc_turretBlow";
		};
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
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	RC_ATrespondingTurret[]={0,0};

	weapons[]=
	{
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
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=2;
			allowTabLock=1;
			canUseScanners=1;
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,4100,4200,4300,4400,4500,4600,4700,4800,4900,5000};
			//turretInfoType="RC_RHS_RscWeaponSosnaU_FCS";
			turretInfoType="RscOptics_MBT_02_gunner";

			minElev=-10;	//-5
			maxElev=14;	//14
			maxHorizontalRotSpeed=1.2;	//1
			maxVerticalRotSpeed=1.2;	//0.07

			weapons[]=
			{
				"RC_cannon_125mm_advanced",
				"RC_MMG_93x64_coax",
				"SmokeLauncher"
			};
			#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_green.hpp"

			class OpticsIn
			{
				class Medium: ViewOptics
				{
					camPos="gunnerview2";
					hitpoint="Hit_Optic_SosnaU";
					opticsDisplayName="TI";
					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"Ti"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
					//gunnerOpticsModel="\rhsafrf\addons\rhs_optics\vehicles\rhs_sosnau.p3d";
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
					allowTabLock=1;
					canUseScanners=1;
					discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
					//turretInfoType="RC_RHS_RscWeaponSosnaU_commander_FCS";
					turretInfoType="RscOptics_MBT_02_gunner";

					minElev=-10;	//-7
					maxElev=35;		//50
					maxHorizontalRotSpeed=1.8;	//0.9
					maxVerticalRotSpeed=1.8;	//0.47

					weapons[]=
					{
						"RC_HMG_127_NSVT",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_com_green.hpp"

					class OpticsIn
					{
						class Medium: ViewOptics
						{
							camPos="commanderview";
							hitpoint="Hit_Optic_SosnaU";
							opticsDisplayName="TI";
							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"Ti"
							};
							thermalMode[]={0};
							//gunnerOpticsModel="\rhsafrf\addons\rhs_optics\vehicles\rhs_sosnau.p3d";
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
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
			weapon="RC_cannon_125mm_advanced";	//rhs_weap_2a46m_4
		};
		class muzzle_rot_mg1
		{
			weapon="RC_MMG_93x64_coax";	//rhs_weap_pkt
			source="ammorandom";
		};
		class reload_magazine_source
		{
			source="reloadMagazine";
			weapon="RC_cannon_125mm_advanced";	//rhs_weap_2a46m_4
		};
		class reload_source
		{
			source="reload";
			weapon="RC_cannon_125mm_advanced";	//rhs_weap_2a46m_5
		};
		class Revolving
		{
			source="revolving";
			weapon="RC_HMG_127_NSVT";	//rhs_weap_nsvt_t72
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="RC_HMG_127_NSVT";	//rhs_weap_nsvt_t72
		};
		class HatchC
		{
			source="door";
			animPeriod=0.5;
		};
		class HatchG: HatchC
		{
		};
		class HatchD: HatchC
		{
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};


class RC_T90AM_WD_O: RC_T90AM_Base
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

	displayName="T-90AM";
	scope=2;
	scopeCurator=2;
	side=0;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	crew="O_UAV_AI";
};
class RC_T90AM_WD: RC_T90AM_WD_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_com_yellow.hpp"
				};
			};
		};
	};
};
class RC_T90AM_WD_I: RC_T90AM_WD_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_com_yellow.hpp"
				};
			};
		};
	};
};


class RC_T90AM_A_O: RC_T90AM_WD_O
{
	//editorPreview="";
	hiddenSelectionsTextures[]=
	{
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t72b3_01_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t72b3_02_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t72b_03_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t72b_04_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t90am_01_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t90am_02_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t72b3_e_01_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t72b3_e_02_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t90parts_sand_co.paa",
		"rhsafrf\addons\rhs_t72_camo\data\rhs_t90a_02_sand_co.paa"
	};
	textureList[]=
	{
		"rhs_Sand",
		1
	};
};
class RC_T90AM_A: RC_T90AM_A_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_com_yellow.hpp"
				};
			};
		};
	};
};
class RC_T90AM_A_I: RC_T90AM_A_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_RHS_AFRF\includes_vicmags\mags_T90AM_com_yellow.hpp"
				};
			};
		};
	};
};