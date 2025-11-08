class rhs_bmp3mera_msv;
class RC_BMP3_Core: rhs_bmp3mera_msv
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class GPMGTurret1;
	class GPMGTurret2;
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
class RC_BMP3_Base: RC_BMP3_Core
{
	class EventHandlers: EventHandlers
	{
		class RHS_EventHandlers
		{
			fired="_this call RHS_fnc_bmp3_autoloader;";
			getOut="_this call rhs_fnc_hatchAbandon";
			hitpart="_this call rhs_fnc_hitSpall";
			init="_this call rhs_fnc_bmp3_init;";
			postInit="_this call rhs_fnc_reapplyTextures";
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
	RC_ATrespondingTurret[]={2,0};

	weapons[]=
	{
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_1Rnd_APS_M",
		//"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	faction="RemoteControlled_O";
	editorSubcategory="RC_IFV_ATGM_subcat";
	author="Ascent";
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	/*
	maxSpeed=70;
	enginePower=1400;
	peakTorque=6875;
	*/
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	class Turrets: Turrets
	{
		class GPMGTurret1: GPMGTurret1
		{
			gunnerName="SL";
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_noDriver.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			allowTabLock=1;
			canUseScanners=1;
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
			discreteDistanceInitIndex=2;
			
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			turretInfoType="RscOptics_MBT_03_gunner";
			
			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"TI"
				};
				thermalMode[]={0};
				initFov=0.9;
				minFov=0.02;
				maxFov=0.9;
			};

			weapons[]=
			{
				"RC_RHS_weap_pkt_bmd_bow1"
			};
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_green.hpp"

			maxVerticalRotSpeed = 1.2;	//1.2
			maxHorizontalRotSpeed = 1.2;	//1.2
			maxTurn = 30;	//10
			minTurn = -30;	//-10
			maxElev = 45;	//35
			minElev = -24;	//-24
		};

		class GPMGTurret2: GPMGTurret2
		{
			gunnerName="TL";
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_noDriver.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			allowTabLock=1;
			canUseScanners=1;
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
			discreteDistanceInitIndex=2;
			
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
			turretInfoType="RscOptics_MBT_03_gunner";
			
			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"TI"
				};
				thermalMode[]={0};
				initFov=0.9;
				minFov=0.02;
				maxFov=0.9;
			};

			weapons[]=
			{
				"RC_RHS_weap_pkt_bmd_bow2"
			};
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_green.hpp"

			maxVerticalRotSpeed = 1.2;	//1.2
			maxHorizontalRotSpeed = 1.2;	//1.2
			maxTurn = 30;	//10
			minTurn = -30;	//-10
			maxElev = 45;	//35
			minElev = -24;	//-24
		};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile_noDriver.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=2;
			allowTabLock=1;
			canUseScanners=1;
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,4100,4200,4300,4400,4500,4600,4700,4800,4900,5000};
			discreteDistanceInitIndex=5;
			//turretInfoType="RC_RHS_RscWeaponSosnaU_FCS";
			turretInfoType="RscOptics_MBT_02_gunner";

			minElev=-10;	//-5	//futher down not possible
			maxElev=60;		//45? 	//60
			maxHorizontalRotSpeed=1;	//1.2	//0.55
			maxVerticalRotSpeed=1;	//1.2	//0.55

			weapons[]=
			{
				"RC_RHS_weap_2a70",
				"RC_RHS_weap_2a72",
				"RC_RHS_weap_pkt_bmd_coax",
				"RC_RHS_weap_902a"
			};
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_green.hpp"

			/*
			"rhs_mag_3UOF191_22",
			"rhs_mag_9m117m1_8",
			"rhs_mag_3uof8_305",
			"rhs_mag_3ubr11_195",
			"rhs_mag_762x54mm_2000",
			"rhs_mag_3d17_6"
			*/

			class OpticsIn
			{
				class Medium: ViewOptics
				{
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
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_noDriver.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=1;
					allowTabLock=1;
					canUseScanners=1;
					discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
					//turretInfoType="RC_RHS_RscWeaponSosnaU_commander_FCS";
					turretInfoType="RscOptics_MBT_02_gunner";

					maxElev=60;
					minElev=-10;	//-5
					maxVerticalRotSpeed=1.8;
					maxHorizontalRotSpeed=1.8;

					weapons[]=
					{
						"RC_Laserdesignator_vehicle"
						//"SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries"
						//"SmokeLauncherMag",
						//"SmokeLauncherMag"
					};

					class OpticsIn
					{
						class Medium: ViewOptics
						{
							camPos="commanderview";
							hitpoint="Hit_Optic_SosnaU";
							opticsDisplayName="TI";
							initFov=0.75;
							minFov=0.02;
							maxFov=0.75;
							visionMode[]=
							{
								"Normal",
								"Ti"
							};
							thermalMode[]={0};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							//gunnerOpticsModel="\rhsafrf\addons\rhs_optics\vehicles\rhs_sosnau.p3d";
						};
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_hide_cannon
		{
			source="reload";
			weapon="RC_RHS_weap_2a70";
		};
		class muzzle_hide_hmg
		{
			source="reload";
			weapon="RC_RHS_weap_2a72";
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";	
			weapon="RC_RHS_weap_2a70";
		};
		class muzzle_rot_coax
		{
			source="ammorandom";
			weapon="RC_RHS_weap_pkt_bmd_coax";
		};
		class muzzle_rot_coax2
		{
			source="ammorandom";
			weapon="RC_RHS_weap_pkt_bmd_bow1";
		};
		class muzzle_rot_coax3
		{
			source="ammorandom";
			weapon="RC_RHS_weap_pkt_bmd_bow2";
		};
		class muzzle_rot_hmg
		{
			source="ammorandom";
			weapon="RC_RHS_weap_2a72";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_RHS_weap_2a70";
		};
		class recoil_source2
		{
			source="reload";
			weapon="RC_RHS_weap_2a72";
		};
		class smokecap_revolving_source
		{
			source="revolving";
			weapon="RC_RHS_weap_902a";
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
		class HatchRA: HatchC
		{
		};
		class HatchLA: HatchC
		{
		};
	};

	#include "\RC_RHS_AFRF\loadouts\FSVitemsO_RHS_AFRF.hpp"
};


class RC_BMP3_WD_O: RC_BMP3_Base
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

	displayName="BMP-3";
	scope=2;
	scopeCurator=2;
	side=0;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	crew="O_UAV_AI";
};
class RC_BMP3_WD: RC_BMP3_WD_O
{
	faction="RemoteControlled_B";
	crew="I_UAV_AI";
	side=1;
	#include "\RC_RHS_AFRF\loadouts\FSVitemsB_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_red.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_red.hpp"
		};
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_red.hpp"
		};
	};
};
class RC_BMP3_WD_I: RC_BMP3_WD_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS_AFRF\loadouts\FSVitemsI_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_yellow.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_yellow.hpp"
		};
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_yellow.hpp"
		};
	};
};


class RC_BMP3_A_O: RC_BMP3_WD_O
{
	//editorPreview="";
	hiddenSelectionsTextures[]=
	{
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_01_3mera_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_02_3mera_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_03_3m_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_04_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\3m_era_sand_co.paa"
	};
	textureList[]=
	{
		"rhs_Sand",
		1
	};
};
class RC_BMP3_A: RC_BMP3_A_O
{
	faction="RemoteControlled_B";
	crew="I_UAV_AI";
	side=1;
	#include "\RC_RHS_AFRF\loadouts\FSVitemsB_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_red.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_red.hpp"
		};
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_red.hpp"
		};
	};
};
class RC_BMP3_A_I: RC_BMP3_A_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS_AFRF\loadouts\FSVitemsI_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_yellow.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_side_yellow.hpp"
		};
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_yellow.hpp"
		};
	};
};