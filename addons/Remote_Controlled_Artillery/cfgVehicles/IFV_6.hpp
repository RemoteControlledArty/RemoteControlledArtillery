//class I_APC_tracked_03_cannon_F;
class I_E_APC_tracked_03_cannon_F;
class RC_ICV_IFV_6_A_Base: I_E_APC_tracked_03_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	//class HitPoints;
	//class HitHull;
	//class HitEngine;
	//class HitLTrack;
	//class HitRTrack;
	class AnimationSources;
	class showCamonetHull;
	class showCamonetTurret;
	class showSLATHull;
	class showSLATTurret;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_IFV_6_A: RC_ICV_IFV_6_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	faction="RemoteControlled_B";
	scope=0;
	scopeCurator=0;
	side=1;
	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	maxSpeed=80;
	enginePower=768;
	peakTorque=3906.9;

	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Enoch\apc_tracked_03\data\apc_tracked_03_ext_eaf_co.paa",
		"A3\Armor_F_Enoch\apc_tracked_03\data\apc_tracked_03_ext2_eaf_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"A3\Armor_F_Enoch\apc_tracked_03\data\cage_EAF_CO.paa"
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_IFV_6_A: RC_ICV_IFV_6_A
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

	displayName="Warrior";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	crew="B_UAV_AI";
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;
	
	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			minElev=-14;
			maxElev=40;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_autocannon_30mm",
				"RC_MMG_338_coax",
				//"RC_IFV_Missile_Launcher",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_red.hpp"

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
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					turretInfoType="RscOptics_MBT_03_gunner";
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
						class Wide: RCWSOptics
						{
							//directionStabilized=1;	//unfortunately causes spinning camera bug

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
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};

					/*
					//no stabilization effect
					class ViewOptics: ViewOptics
					{
						directionStabilized=1;
						
						initFov=0.9;
						minFov=0.02;
						maxFov=0.9;
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={0};
					};
					*/
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_30mm";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm";
		};
		class autocannon_30mm_revolving
		{
			source="revolving";
			weapon="RC_autocannon_30mm";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
		class showSLATTurret: showSLATTurret
		{
			initPhase=1;
		};
	};
};
class RC_IFV_6_A_O: RC_IFV_6_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_green.hpp"
		};
	};
};
class RC_IFV_6_A_I: RC_IFV_6_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_yellow.hpp"
		};
	};
};
class RC_IFV_6_DIG_I: RC_IFV_6_A_I
{
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_APC_tracked_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_epb\apc_tracked_03\data\apc_tracked_03_ext_indp_co.paa",
		"A3\armor_f_epb\apc_tracked_03\data\apc_tracked_03_ext2_indp_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};


class RC_IFV_6_WD: RC_IFV_6_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Enoch\apc_tracked_03\data\apc_tracked_03_ext_eaf_co.paa",
		"A3\Armor_F_Enoch\apc_tracked_03\data\apc_tracked_03_ext2_eaf_co.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"A3\Armor_F_Enoch\apc_tracked_03\data\cage_EAF_CO.paa"
	};
};
class RC_IFV_6_WD_O: RC_IFV_6_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_green.hpp"
		};
	};
};
class RC_IFV_6_WD_I: RC_IFV_6_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_yellow.hpp"
		};
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_IFV_6_ReTex_WD: RC_IFV_6_A
{
	faction="RemoteControlled_ReTex_B";
	//editorSubcategory="RC_IFV_APC_ReTex_WD_subcat";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_APC_tracked_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"warrior\data\warrior_ext_01_wd.paa",
		"warrior\data\warrior_ext_02_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"a3\armor_f\data\cage_g1_co.paa"
	};
};
class RC_IFV_6_ReTex_WD_O: RC_IFV_6_ReTex_WD
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_green.hpp"
		};
	};
};
class RC_IFV_6_ReTex_WD_I: RC_IFV_6_ReTex_WD
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_yellow.hpp"
		};
	};
};


class RC_IFV_6_ReTex_D: RC_IFV_6_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_APC_tracked_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"warrior\data\warrior_ext_01_d.paa",
		"warrior\data\warrior_ext_02_d.paa",
		"warrior\data\camonet_desert_co.paa",
		"warrior\data\cage_desert_co.paa"
	};
};
class RC_IFV_6_ReTex_D_O: RC_IFV_6_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_green.hpp"
		};
	};
};
class RC_IFV_6_ReTex_D_I: RC_IFV_6_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_yellow.hpp"
		};
	};
};


class RC_IFV_6_ReTex_A: RC_IFV_6_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Arid_subcat";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_APC_tracked_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"warrior\data\warrior_ext_01_e.paa",
		"warrior\data\warrior_ext_02_e.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
		"a3\armor_f\data\cage_sand_co.paa"
	};
};
class RC_IFV_6_ReTex_A_O: RC_IFV_6_ReTex_A
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_green.hpp"
		};
	};
};
class RC_IFV_6_ReTex_A_I: RC_IFV_6_ReTex_A
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Warrior_30mm_yellow.hpp"
		};
	};
};