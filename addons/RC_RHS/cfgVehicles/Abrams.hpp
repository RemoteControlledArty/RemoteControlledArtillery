class rhsusf_m1a2sep1tuskiid_usarmy;
class RC_M1A2_TUSKII_Base: rhsusf_m1a2sep1tuskiid_usarmy
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class HatchC;
};
class RC_M1A2_TUSKII_D_Base: RC_M1A2_TUSKII_Base
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
			weapon="RC_RHS_weap_M242BC";
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
			weapon="RC_RHS_weap_m240_bradley_coax";
		};
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		class HatchC: HatchC
		{
			animPeriod=0.8;
		};
		class HatchG: HatchC
		{
		};
	};

	#include "\RC_RHS\loadouts\IFVitemsB_RHS.hpp"
};

class RC_M1A2_TUSKII_D: RC_M1A2_TUSKII_D_Base
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"

			showAllTargets="2 + 4";
			commanding=3;
			allowTabLock=1;
			//turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"rhs_weap_m256",
				"RHS_M2_Abrams_Gunner",
				"rhs_weap_m240_abrams_coax",
				"rhs_weap_fcs"
			};
			magazines[]=
			{
				"rhs_mag_M829A3",
				"rhs_mag_M830A1",
				"rhs_mag_200rnd_127x99_SLAP_mag_Tracer_Red",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_laserfcsmag",
				"rhs_laserfcsmag"
			};

			/*
			weapons[]=
			{
				"rhs_weap_m256",
				"rhs_weap_m240_abrams_coax",
				"rhs_weap_fcs"
			};
			magazines[]=
			{
				"rhs_mag_M829A3",
				"rhs_mag_M830A1",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_mag_762x51_M240_1200",
				"rhs_laserfcsmag",
				"rhs_laserfcsmag"
			};
			*/

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
					//gunnerOpticsModel="\rhsusf\addons\rhsusf_m1a1\gunnerOptics_M1A1_2";
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
					hitpoint="Hit_Optic_GPS_TI";
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					//#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					showAllTargets="2 + 4";
					commanding=2;
					allowTabLock=1;
					
					/*
					class ViewOptics: ViewOptics
					{
						initFov=0.9;
						minFov=0.02;
						maxFov=0.9;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0};
					};
					class OpticsIn
					{
						class Ultrawide
						{
							opticsDisplayName="60HZ";
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
								"Ti"
							};
							thermalMode[]={0};
							gunnerOpticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_IBAS_1x";
							gunnerOpticsEffect[]={};
							hitPoint="Hit_Optics_Cdr_CIV";
						};
					};
					*/

					gunnerOpticsModel="\rhsusf\addons\rhsusf_a2port_armor\M2A2_Bradley\comTI_M2A2";
					gunnerOpticsEffect[]={};
					class ViewOptics: ViewOptics
					{
						initFov=0.46599999;
						minFov=0.015;
						maxFov=0.46599999;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0};
					};
					class OpticsIn
					{
						class Ultrawide
						{
							opticsDisplayName="60HZ";
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
								"Ti"
							};
							thermalMode[]={0};
							gunnerOpticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_IBAS_4x";
							gunnerOpticsEffect[]={};
							hitPoint="Hit_Optics_Cdr_CIV";
						};
					};

					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						"rhsusf_weap_M257_8"
					};
					magazines[]=
					{
						"Laserbatteries",
						"rhsusf_mag_L8A3_8",
						"rhsusf_mag_L8A3_8"
					};
				};
			};
		};
	};
};


class RC_M1A2_TUSKII_D_B: RC_M1A2_TUSKII_D
{
	class EventHandlers: EventHandlers
	{	
		class RHSUSF_EventHandlers
		{
			postInit="_this call rhs_fnc_reapplyTextures";
			getIn="_this call rhs_fnc_m2_doors";
			getOut="_this call rhs_fnc_m2_doors";
		};
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			//#include "\Remote_Controlled_Artillery\includes_script\dev_takeDriverControlsEH1.hpp"
		};
	};

	displayName="M1A2 Abrams";
	editorSubcategory="RC_RHS_D_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
};


class RC_M1A2_TUSKII_WD_B: RC_M1A2_TUSKII_D_B
{
	editorSubcategory="RC_RHS_WD_subcat";

	hiddenSelectionsTextures[]=
	{
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\m6_base_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\m6_a3_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\ultralp_co.paa",
		"\rhsusf\addons\rhsusf_a2port_armor\m2a2_bradley\data\woodland\BUSKIII_co.paa",
		"\rhsusf\addons\rhsusf_m1a1\duke\data\duke_antennae_wd_co.paa"
	};
};


class RC_M1A2_TUSKII_NLOS_D_B: RC_M1A2_TUSKII_D_B
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_RHS_weap_m240_bradley_coax",
				"RC_RHS_weap_M242BC",
				"RC_Bradley_Missle_Launcher",
				"rhs_weap_fcs_ammo",

				"rhsusf_weap_M257_8"
			};
			magazines[]=
			{
				"RC_RHS_mag_1100Rnd_762x51_T_R",
				"RC_RHS_mag_1100Rnd_762x51_T_R",
				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_2Rnd_TOW_MP_NLOS",
				"RC_2Rnd_TOW_MP_NLOS",
				"RC_2Rnd_TOW_AA",
				"RC_2Rnd_TOW_AA",
				"rhs_laserfcsmag",

				"rhsusf_mag_L8A3_8",
				"rhsusf_mag_L8A3_8",
				"rhsusf_mag_L8A3_8"
			};
		};
	};

	displayName="M1A2 Abrams NLOS";
};


class RC_M1A2_TUSKII_NLOS_WD_B: RC_M1A2_TUSKII_NLOS_D_B
{
	editorSubcategory="RC_RHS_WD_subcat";
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_m1a2sep1tuskiiwd_usarmy.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1a2sepv1tuskii_wd_01_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1a2sepv1tuskii_wd_02_co.paa",
		"rhsusf\addons\rhsusf_m1a1\data\rhsusf_m1a1aim_03_co.paa",
		"rhsusf\addons\rhsusf_m1a1\loaderspintle\data\loaderspintle_tuski_wd_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_tuskiia2_wd_co.paa",
		"rhsusf\addons\rhsusf_m1a2\data\rhsusf_m1slat_wd_co.paa",
		"rhsusf\addons\rhsusf_m1a1\duke\data\duke_antennae_wd_co.paa"
	};
};