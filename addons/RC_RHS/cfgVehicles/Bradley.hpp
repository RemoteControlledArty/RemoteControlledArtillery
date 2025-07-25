class RHS_M2A3_BUSKIII;
class RC_M2A3_BUSKIII_Base: RHS_M2A3_BUSKIII
{
	scope=0;
	scopeCurator=0;
	class Components;
	class UserActions;
	class EventHandlers;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class HatchC;
};
class RC_M2A3_BUSKIII_D_Base: RC_M2A3_BUSKIII_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4kmSensIR.hpp"
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
	maxSpeed=75;
	enginePower=670;
	peakTorque=2490;
	maximumLoad=4000;

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
		/*
		class rear_hatch
		{
			source="door";
			animPeriod=0.80000001;
			initPhase=0;
		};
		*/
	};

	#include "\RC_RHS\loadouts\IFVitemsB_RHS.hpp"
};

class RC_M2A3_BUSKIII_D: RC_M2A3_BUSKIII_D_Base
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			//#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//isCopilot=1; //allows to trigger EH that gives driving controls
			dontCreateAI=1;
			commanding=3;
			allowTabLock=1;

			weapons[]=
			{
				"RC_RHS_weap_m240_bradley_coax",
				"RC_RHS_weap_M242BC",
				"RC_RHS_weap_TOW_Launcher",
				"rhs_weap_fcs_ammo",

				"rhsusf_weap_M257_8"
			};
			magazines[]=
			{
				"RC_110Rnd_25mm_HEI_Pen_T_R",
				"RC_110Rnd_25mm_HEI_DF_T_R",
				"RC_110Rnd_25mm_HEI_QF_T_R",
				"RC_110Rnd_25mm_HEAB_DF_T_R",
				/*
				"RC_110Rnd_25mm_MP_Pen_T_R",
				"RC_110Rnd_25mm_MP_DF_T_R",
				"RC_110Rnd_25mm_MP_QF_T_R",
				"RC_110Rnd_25mm_MPAB_DF_T_R",

				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				*/
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_1100Rnd_762x51_T_R",
				"RC_RHS_mag_1100Rnd_762x51_T_R",
				"RC_RHS_mag_2Rnd_TOW2A",
				"RC_RHS_mag_2Rnd_TOW2A",
				"RC_RHS_mag_2Rnd_TOW2A",
				"RC_RHS_mag_2Rnd_TOW2BB",
				"rhs_laserfcsmag",

				"rhsusf_mag_L8A3_8",
				"rhsusf_mag_L8A3_8"
			};
			
			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="60HZ";
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.9;
					minFov=0.02;	//realistic 12x magnification
					maxFov=0.9;		//larger FOV for improved usability on servers without third person
					visionMode[]=
					{
						"Normal",
						"Ti"
					};
					thermalMode[]={0};
					gunnerOpticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_IBAS_4x";
					gunnerOpticsEffect[]={};
					hitPoint="Hit_Optics_Gnr";
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					//#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=2;
					allowTabLock=1;
					
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


class RC_M2A3_BUSKIII_D_B: RC_M2A3_BUSKIII_D
{
	class EventHandlers: EventHandlers
	{	
		class RHSUSF_EventHandlers
		{
			postInit="_this call rhs_fnc_reapplyTextures";
			getIn="_this call rhs_fnc_m2_doors";
			getOut="_this call rhs_fnc_m2_doors";
		};
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	/*
	memoryPointsGetInCargo[]	= {"pos cargo","pos cargo 1","pos cargo 2","pos cargo 3"};
	memoryPointsGetInCargoDir[]	= {"pos cargo dir","pos cargo 1 dir","pos cargo dir","pos cargo 2 dir","pos cargo 3 dir"};
	cargoProxyIndexes[] = {1,2,3,4,5,6,7,8};
	getInProxyOrder[] = {1,2,3,4,5,6,7,8};
	cargoAction[] = {"RHS_M113_Cargo03","RHS_M113_Cargo03","RHS_M113_Cargo03","RHS_M113_Cargo03","RHS_M113_Cargo02","RHS_M113_Cargo02","RHS_M113_Cargo02","RHS_M113_Cargo02"};
	*/

	displayName="M2A3 Bradley";
	editorSubcategory="RC_RHS_D_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
	//forceHideDriver=1;
	//driverForceOptics=1;
};


class RC_M2A3_BUSKIII_WD_B: RC_M2A3_BUSKIII_D_B
{
	editorSubcategory="RC_RHS_WD_subcat";
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


class RC_M2A3_BUSKIII_D_I: RC_M2A3_BUSKIII_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_M2A3_BUSKIII_WD_I: RC_M2A3_BUSKIII_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};


class RC_M2A3_BUSKIII_NLOS_D_B: RC_M2A3_BUSKIII_D_B
{
	displayName="M2A3 Bradley NLOS";
	
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"

			weapons[]=
			{
				"RC_RHS_weap_M242BC",
				"RC_RHS_weap_m240_bradley_coax",
				"RC_Bradley_Missile_Launcher",
				"rhs_weap_fcs_ammo",

				"rhsusf_weap_M257_8"
			};
			magazines[]=
			{
				"RC_110Rnd_25mm_HEI_Pen_T_R",
				"RC_110Rnd_25mm_HEI_DF_T_R",
				"RC_110Rnd_25mm_HEI_QF_T_R",
				"RC_110Rnd_25mm_HEAB_DF_T_R",
				/*
				"RC_110Rnd_25mm_MP_Pen_T_R",
				"RC_110Rnd_25mm_MP_DF_T_R",
				"RC_110Rnd_25mm_MP_QF_T_R",
				"RC_110Rnd_25mm_MPAB_DF_T_R",

				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				"RC_RHS_mag_230Rnd_25mm_HEI_T_R",
				*/
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_70Rnd_25mm_APFSDS_T_R",
				"RC_RHS_mag_1100Rnd_762x51_T_R",
				"RC_RHS_mag_1100Rnd_762x51_T_R",
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
};
class RC_M2A3_BUSKIII_NLOS_WD_B: RC_M2A3_BUSKIII_NLOS_D_B
{
	editorSubcategory="RC_RHS_WD_subcat";
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


class RC_M2A3_BUSKIII_NLOS_D_I: RC_M2A3_BUSKIII_NLOS_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_M2A3_BUSKIII_NLOS_WD_I: RC_M2A3_BUSKIII_NLOS_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};