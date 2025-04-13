class rhsusf_m1a2sep2d_usarmy;
class RC_M1A2_SEPV2_Base: rhsusf_m1a2sep2d_usarmy
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class MainTurret;
	class CROWS_Turret;
	class ViewOptics;
	class DaysightWFOV;
	class AnimationSources;
	class Loader;
	class CommanderMG;
	class LoaderMG;
};
class RC_M1A2_SEPV2_D_Base: RC_M1A2_SEPV2_Base
{
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	forceInGarage=1;
	driverCompartments="Compartment2";
	commanding=2;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	/*
	smokeLauncherGrenadeCount=12;
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
	*/

	class DriverOpticsIn
	{
		class DVE_Wide: ViewOptics
		{
			camPos="view_DVE";
			opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
			visionMode[]=
			{
				"TI",
				"Normal"
			};
			thermalMode[]={0};
			initFov=1.07692;
			minFov=1.07692;
			maxFov=1.07692;
			hitpoint="Hit_Optics_Dvr_DVE";
		};
		class DVS_Rear: DVE_Wide
		{
			camPos="view_rear";
			camDir="view_rear_dir";
			opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE2_4x3";
			hitpoint="Hit_Optics_Dvr_RearCam";
		};
	};

	class AnimationSources: AnimationSources
	{
		class recoil_source
		{
			source="reload";
			weapon="RC_RHS_weap_m256";
		};
		class muzzle_hide_cannon: recoil_source
		{
		};
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_RHS_weap_m256";
		};
		class muzzle_rot_CoaxMG
		{
			source="ammorandom";
			weapon="RC_RHS_weap_m240_abrams_coax";
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
			weapon="RC_RHS_M2_CROWS_M153_Abrams";
		};
	};

	#include "\RC_RHS\loadouts\FSVitemsB_RHS.hpp"
};


class RC_M1A2_SEPV2_D: RC_M1A2_SEPV2_D_Base
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			allowTabLock=1;

			weapons[]=
			{
				"RC_RHS_weap_m256",
				"RC_RHS_weap_m240_abrams_coax",
				"rhsusf_weap_M250",
				"rhs_weap_fcs"
			};
			magazines[]=
			{
				"RC_RHS_mag_M829A4_20Rnd",
				"RC_RHS_mag_M830A1_20Rnd",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"rhsusf_mag_L8A3_12",
				"rhsusf_mag_L8A3_12",
				"rhs_laserfcsmag",
				"rhs_laserfcsmag"
			};

			//turretInfoType="RscOptics_MBT_01_commander";
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

					initFov=0.53;
					minFov=0.014;
					maxFov=0.53;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\rhsusf\addons\rhsusf_m1a1\gunnerOptics_M1A2_2";
					gunnerOpticsEffect[]={};
					hitpoint="Hit_Optic_GPS_TI";
				};
			};
			
			class Turrets: Turrets
			{
				class CROWS_Turret : CROWS_Turret
				{
					//#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=2;
					allowTabLock=1;

					class OpticsIn
					{
						class DaysightWFOV: DaysightWFOV
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

							opticsDisplayName="1-30x";
							gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CROWS_monitor";
							hitpoint="Hit_Optic_CROWS_Day";
							visionMode[]=
							{
								"Normal",
								"Ti"
							};
							thermalMode[]={0};
						};
					};

					weapons[]=
					{
						"RC_RHS_M2_CROWS_M153_Abrams",
						"RC_Laserdesignator_vehicle",
						"rhsusf_weap_M250",
						"rhsusf_weap_duke"
					};
					magazines[]=
					{
						"RC_RHS_mag_400rnd_127x99_SLAP_T_R",
						"RC_RHS_mag_400rnd_127x99_SLAP_T_R",
						"RC_RHS_mag_400rnd_127x99_T_R",
						"RC_RHS_mag_400rnd_127x99_T_R",
						"Laserbatteries",
						"rhsusf_mag_L8A3_12",
						"rhsusf_mag_L8A3_12",
						"rhsusf_mag_duke"
					};
				};

				class Loader: Loader
				{
					dontCreateAI=1;
				};
				class LoaderMG: LoaderMG {};
			};
		};
	};
};


class RC_M1A2_SEPV2_D_B: RC_M1A2_SEPV2_D
{
	class EventHandlers: EventHandlers
	{
		class RHSUSF_EventHandlers
		{
			getOut="_this call rhs_fnc_M1_hatch";
			init = "_this call RHS_fnc_M1_init";
			postInit = "_this call rhs_fnc_reapplyTextures";
		};
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="M1A2 SEPV2 Abrams";
	editorSubcategory="RC_RHS_D_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
};
class RC_M1A2_SEPV2_D_I: RC_M1A2_SEPV2_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


class RC_M1A2_SEPV2_WD_B: RC_M1A2_SEPV2_D_B
{
	editorSubcategory="RC_RHS_WD_subcat";
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
class RC_M1A2_SEPV2_WD_I: RC_M1A2_SEPV2_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


class RC_M1A2_SEPV2_NLOS_D_B: RC_M1A2_SEPV2_D_B
{
	displayName="M1A2 SEPV2 Abrams NLOS";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"

			weapons[]=
			{
				"RC_RHS_weap_m256",
				"RC_RHS_weap_m240_abrams_coax",
				"rhs_weap_fcs"
			};
			magazines[]=
			{
				"RC_RHS_mag_M829A4_20Rnd",
				"RC_RHS_mag_M830A1_15Rnd",
				"RC_4Rnd_120mm_DLG_cannon_missiles",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"RC_RHS_mag_1200Rnd_762x51_T_R",
				"rhs_laserfcsmag",
				"rhs_laserfcsmag"
			};
		};
	};
};
class RC_M1A2_SEPV2_NLOS_D_I: RC_M1A2_SEPV2_NLOS_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};


class RC_M1A2_SEPV2_NLOS_WD_B: RC_M1A2_SEPV2_NLOS_D_B
{
	editorSubcategory="RC_RHS_WD_subcat";
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
class RC_M1A2_SEPV2_NLOS_WD_I: RC_M1A2_SEPV2_NLOS_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\FSVitemsI_RHS.hpp"
};