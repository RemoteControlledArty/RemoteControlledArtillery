class rhsusf_m1165a1_gmv_m2_m240_socom_d;
class RC_HMMWV_M2_Base: rhsusf_m1165a1_gmv_m2_m240_socom_d
{
	scope=0;
	scopeCurator=0;
	//class Components;
	class EventHandlers;
	class Turrets;
	//class CargoTurret_01;
	//class CargoTurret_02;
	//class CargoTurret_03;
	class MainTurret;
	class ViewOptics;
	//class AnimationSources;
};
class RC_HMMWV_M2: RC_HMMWV_M2_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\RC_RHS\loadouts\IFVitemsB_RHS.hpp"

	forceInGarage=1;
	driverCompartments="Compartment3";
	commanding=2;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

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
			hitpoint="Hit_Optic_DVEA";
		};
		class DVS_Rear: DVE_Wide
		{
			camPos="view_rear";
			camDir="view_rear_dir";
			hitpoint="Hit_Optic_Driver_Rear";
		};
	};

	/*
	class AnimationSources: AnimationSources
	{
	};
	*/

	/*
	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			isCopilot=1; //allows to trigger EH that gives driving controls
			*/

			/*
			weapons[]=
			{
			};
			magazines[]=
			{
			};
			*/

			/*
		};
	};
	*/
};


class RC_HMMWV_M2_D: RC_HMMWV_M2
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="SF HMMWV M2";
	editorSubcategory="RC_RHS_D_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
};
/*
class RC_Stryker_M1126_M2_D_B: RC_Stryker_M1126_M2_WD_B
{
	editorSubcategory="RC_RHS_WD_subcat";
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
*/


/*
class RC_Stryker_M1126_M2_WD_I: RC_Stryker_M1126_M2_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1126_M2_D_I: RC_Stryker_M1126_M2_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1126_M2_A_I: RC_Stryker_M1126_M2_A_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
*/