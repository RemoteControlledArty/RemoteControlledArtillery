class rhsusf_stryker_m1126_m2_wd;
class RC_Stryker_M1126_M2_WD_Base: rhsusf_stryker_m1126_m2_wd
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class Hatch_Commander;
	class UserActions;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
};
class RC_Stryker_M1126_M2_WD: RC_Stryker_M1126_M2_WD_Base
{
	#include "\RC_RHS\cfgVehicles\StrykerBasics_Include.hpp"

	class AnimationSources: AnimationSources
	{
		class Hatch_Commander: Hatch_Commander
		{
			animPeriod=0.8;
		};
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		
		class M2_CROWS_AmmoRandom
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="ammorandom";
		};
		class M2_CROWS_Reload
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="reload";
		};
		class M2_CROWS_ReloadMagazine
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="reloadmagazine";
		};
		class M2_CROWS_Revolving
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="revolving";
		};
	};

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01
		{
			gunnerName="Commander";
			primaryGunner=0;
			primaryObserver=1;
		};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			//isCopilot=1; //allows to trigger EH that gives driving controls
			commanding=3;
			allowTabLock=1;
			gunnerName="Gunner";

			weapons[]=
			{
				"RC_RHS_M2_CROWS_M151",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16"
			};

			class OpticsIn
			{
				class DaysightWFOV: ViewOptics
				{
					camPos="View_CROWS";
					//opticsDisplayName="1.0x";
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CROWS_monitor";
					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					hitpoint="Hit_Optic_CROWS_Day";
				};
			};
		};
	};
};
class RC_Stryker_M1126_M2_WD_B: RC_Stryker_M1126_M2_WD
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			//#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="M1126 Stryker M2";
	//editorSubcategory="RC_RHS_WD_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;
	crew="B_UAV_AI";
};
class RC_Stryker_M1126_M2_D_B: RC_Stryker_M1126_M2_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
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
class RC_Stryker_M1126_M2_WD_O: RC_Stryker_M1126_M2_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_M2_D_O: RC_Stryker_M1126_M2_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
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


class RC_Stryker_M1126_M2_Javelin_WD_B: RC_Stryker_M1126_M2_WD_B
{
	class EventHandlers: EventHandlers
	{
		class RC_Javelin
		{
			#include "\RC_RHS\includes_script\AttachJavelin.hpp"
		};
	};

	displayName="M1126 Stryker M2/Javelin";
	editorSubcategory="RC_APC_ATGM_subcat";

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner_missile.hpp"

			weapons[]=
			{
				"RC_RHS_M2_CROWS_M151",
				"RC_Stryker_Missile_Launcher",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_4Rnd_Javelin_MP_LOS",
				"RC_2Rnd_Javelin_MP_NLOS",
				"RC_4Rnd_Javelin_AA",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16"
			};
		};
	};
};
class RC_Stryker_M1126_M2_Javelin_D_B: RC_Stryker_M1126_M2_Javelin_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
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
class RC_Stryker_M1126_M2_Javelin_WD_O: RC_Stryker_M1126_M2_Javelin_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_M2_Javelin_D_O: RC_Stryker_M1126_M2_Javelin_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_M2_Javelin_WD_I: RC_Stryker_M1126_M2_Javelin_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1126_M2_Javelin_D_I: RC_Stryker_M1126_M2_Javelin_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};


class rhsusf_stryker_m1126_mk19_wd;
class RC_Stryker_M1126_MK19_WD_Base: rhsusf_stryker_m1126_mk19_wd
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class Hatch_Commander;
	class UserActions;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
};
class RC_Stryker_M1126_MK19_WD: RC_Stryker_M1126_MK19_WD_Base
{
	#include "\RC_RHS\cfgVehicles\StrykerBasics_Include.hpp"

	class AnimationSources: AnimationSources
	{
		class Hatch_Commander: Hatch_Commander
		{
			animPeriod=0.8;
		};
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		class MK19_CROWS_Reload
		{
			weapon="RC_RHS_MK19_CROWS_M153";
			source="reload";
		};
		class MK19_CROWS_ReloadMagazine
		{
			weapon="RC_RHS_MK19_CROWS_M153";
			source="reloadmagazine";
		};
		class MK19_CROWS_Revolving
		{
			weapon="RC_RHS_MK19_CROWS_M153";
			source="revolving";
		};
	};

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01
		{
			gunnerName="Commander";
			primaryGunner=0;
			primaryObserver=1;

			/*
			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleGunnerDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="PrimaryGunner";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="VehicleGunnerDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleGunnerDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="PrimaryGunner";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
					};
				};
			};
			*/
		};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			//isCopilot=1; //allows to trigger EH that gives driving controls
			commanding=3;
			allowTabLock=1;
			gunnerName="Gunner";

			weapons[]=
			{
				"RC_RHS_MK19_CROWS_M153",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"RC_RHS_96Rnd_40mm_MK19_M430A1",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16"
			};

			class OpticsIn
			{
				class DaysightWFOV: ViewOptics
				{
					camPos="View_CROWS";
					//opticsDisplayName="1.0x";
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CROWS_monitor";
					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					hitpoint="Hit_Optic_CROWS_Day";
				};
			};
		};
	};
};
class RC_Stryker_M1126_MK19_WD_B: RC_Stryker_M1126_MK19_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			//#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="M1126 Stryker Mk19";
	//editorSubcategory="RC_RHS_WD_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
};
class RC_Stryker_M1126_MK19_D_B: RC_Stryker_M1126_MK19_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
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
class RC_Stryker_M1126_MK19_WD_O: RC_Stryker_M1126_MK19_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_MK19_D_O: RC_Stryker_M1126_MK19_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_MK19_WD_I: RC_Stryker_M1126_MK19_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1126_MK19_D_I: RC_Stryker_M1126_MK19_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};


class RC_Stryker_M1126_20mmAC_WD_B: RC_Stryker_M1126_MK19_WD_B
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	displayName="M1126 Stryker 20mm AC";
	editorSubcategory="RC_IFV_subcat";

	class AnimationSources: AnimationSources
	{
		class Hatch_Commander: Hatch_Commander
		{
			animPeriod=0.8;
		};
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		class MK19_CROWS_Reload
		{
			weapon="RC_RHS_20mm_AC_CROWS_M153";
			source="reload";
		};
		class MK19_CROWS_ReloadMagazine
		{
			weapon="RC_RHS_20mm_AC_CROWS_M153";
			source="reloadmagazine";
		};
		class MK19_CROWS_Revolving
		{
			weapon="RC_RHS_20mm_AC_CROWS_M153";
			source="revolving";
		};
	};

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_RHS_20mm_AC_CROWS_M153",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_100Rnd_20mm_HE_Pen_T_R",
				"RC_100Rnd_20mm_HE_Pen_T_R",
				"RC_100Rnd_20mm_HE_QF_T_R",
				"RC_100Rnd_20mm_HE_DF_T_R",
				"RC_100Rnd_20mm_HE_DF_T_R",
				"RC_100Rnd_20mm_HEAB_DF_T_R",
				/*
				//available but unused
				"RC_100Rnd_20mm_HEAB_QF_T_R",
				
				"RC_100Rnd_20mm_MP_Pen_T_R",
				"RC_100Rnd_20mm_MP_QF_T_R",
				"RC_100Rnd_20mm_MP_DF_T_R",
				"RC_100Rnd_20mm_MPAB_DF_T_R",
				"RC_100Rnd_20mm_MPAB_QF_T_R",

				"RC_100Rnd_20mm_MP_T_R",
				"RC_100Rnd_20mm_GPR_T_R",

				"RC_100Rnd_20mm_HE_T_R",
				*/
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16"
			};
		};
	};
};
class RC_Stryker_M1126_20mmAC_D_B: RC_Stryker_M1126_20mmAC_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
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
class RC_Stryker_M1126_20mmAC_WD_O: RC_Stryker_M1126_20mmAC_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_20mmAC_D_O: RC_Stryker_M1126_20mmAC_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_20mmAC_WD_I: RC_Stryker_M1126_MK19_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1126_20mmAC_D_I: RC_Stryker_M1126_20mmAC_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};


class RC_Stryker_M1126_20mmAC_Javelin_WD_B: RC_Stryker_M1126_20mmAC_WD_B
{
	class EventHandlers: EventHandlers
	{
		class RC_Javelin
		{
			#include "\RC_RHS\includes_script\AttachJavelin.hpp"
		};
	};

	displayName="M1126 Stryker 20mm AC/Javelin";
	editorSubcategory="RC_IFV_ATGM_subcat";

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner_missile.hpp"

			weapons[]=
			{
				"RC_RHS_20mm_AC_CROWS_M153",
				"RC_Stryker_Missile_Launcher",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_100Rnd_20mm_HE_Pen_T_R",
				"RC_100Rnd_20mm_HE_Pen_T_R",
				"RC_100Rnd_20mm_HE_QF_T_R",
				"RC_100Rnd_20mm_HE_DF_T_R",
				"RC_100Rnd_20mm_HE_DF_T_R",
				"RC_100Rnd_20mm_HEAB_DF_T_R",
				/*
				//available but unused
				"RC_100Rnd_20mm_HEAB_QF_T_R",
				
				"RC_100Rnd_20mm_MP_Pen_T_R",
				"RC_100Rnd_20mm_MP_QF_T_R",
				"RC_100Rnd_20mm_MP_DF_T_R",
				"RC_100Rnd_20mm_MPAB_DF_T_R",
				"RC_100Rnd_20mm_MPAB_QF_T_R",

				"RC_100Rnd_20mm_MP_T_R",
				"RC_100Rnd_20mm_GPR_T_R",

				"RC_100Rnd_20mm_HE_T_R",
				*/
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_100Rnd_20mm_APFSDS_T_R",
				"RC_2Rnd_Javelin_MP_LOS",
				"RC_2Rnd_Javelin_MP_NLOS",
				"RC_4Rnd_Javelin_AA",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16"
			};
		};
	};
};
class RC_Stryker_M1126_20mmAC_Javelin_D_B: RC_Stryker_M1126_20mmAC_Javelin_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
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
class RC_Stryker_M1126_20mmAC_Javelin_WD_O: RC_Stryker_M1126_20mmAC_Javelin_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_20mmAC_Javelin_D_O: RC_Stryker_M1126_20mmAC_Javelin_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_20mmAC_Javelin_WD_I: RC_Stryker_M1126_20mmAC_Javelin_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1126_20mmAC_Javelin_D_I: RC_Stryker_M1126_20mmAC_Javelin_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};


class rhsusf_stryker_m1132_m2_wd;
class RC_Stryker_M1132_M2_WD_Base: rhsusf_stryker_m1132_m2_wd
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class Hatch_Commander;
	class UserActions;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
};
class RC_Stryker_M1132_M2_WD: RC_Stryker_M1132_M2_WD_Base
{
	#include "\RC_RHS\cfgVehicles\StrykerBasics_Include.hpp"

	class AnimationSources: AnimationSources
	{
		class Hatch_Commander: Hatch_Commander
		{
			animPeriod=0.8;
		};
		class ramp: ramp
		{
			animPeriod=1.25;
		};	
		class M2_CROWS_AmmoRandom
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="ammorandom";
		};
		class M2_CROWS_Reload
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="reload";
		};
		class M2_CROWS_ReloadMagazine
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="reloadmagazine";
		};
		class M2_CROWS_Revolving
		{
			weapon="RC_RHS_M2_CROWS_M151";
			source="revolving";
		};
	};

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01
		{
			gunnerName="Commander";
			primaryGunner=0;
			primaryObserver=1;
		};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			//isCopilot=1; //allows to trigger EH that gives driving controls
			commanding=3;
			allowTabLock=1;
			gunnerName="Gunner";

			weapons[]=
			{
				"RC_RHS_M2_CROWS_M151",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16"
			};

			class OpticsIn
			{
				class DaysightWFOV: ViewOptics
				{
					camPos="View_CROWS";
					//opticsDisplayName="1.0x";
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CROWS_monitor";
					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					hitpoint="Hit_Optic_CROWS_Day";
				};
			};
		};
	};
};
class RC_Stryker_M1132_M2_WD_B: RC_Stryker_M1132_M2_WD
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			//#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	class UserActions: UserActions
	{
		class RaiseSMP
		{
			displayName="Raise Mine Plow";
			position="pos_gunnerpos";
			radius=2;
			showwindow=0;
			onlyforplayer=1;
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && this animationSourcePhase 'hide_SMP' < 0.5 && this animationSourcePhase 'SMP' < 0.5;";
			statement="this animateSource ['SMP', 1]";
		};
		class LowerSMP: RaiseSMP
		{
			displayName="Lower Mine Plow";
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && this animationSourcePhase 'hide_SMP' < 0.5 && this animationSourcePhase 'SMP' > 0.5;";
			statement="this animateSource ['SMP', 0]";
		};
		class SMP_TravelPosition_On: RaiseSMP
		{
			displayName="Switch Mine Plow to travel position";
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && {this animationSourcePhase 'hide_SMP' < 0.5} && {this animationSourcePhase 'SMP' > 0.5} && {this animationSourcePhase 'SMP_L' isEqualTo 0} && {this animationSourcePhase 'SMP_R' isEqualTo 0};";
			statement="this animateSource ['SMP_L', 1];this animateSource ['SMP_R', 1]";
		};
		class SMP_TravelPosition_Off: RaiseSMP
		{
			displayName="Switch Mine Plow to work position";
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && {this animationSourcePhase 'hide_SMP' < 0.5} && {this animationSourcePhase 'SMP' > 0.5} && {this animationSourcePhase 'SMP_L' isEqualTo 1} && {this animationSourcePhase 'SMP_R' isEqualTo 1};";
			statement="this animateSource ['SMP_L', 0];this animateSource ['SMP_R', 0]";
		};
		class LaneMarkingSystem_Activate
		{
			displayName="Activate Lane Marking System";
			position="pos_gunnerpos";
			radius=2;
			showwindow=0;
			onlyforplayer=1;
			condition="((gunner this) isEqualTo (call rhs_fnc_findPlayer)) && {this animationSourcePhase 'Dispenser_Fold' isEqualTo 0};";
			statement="this animateSource ['Dispenser_Fold', 1];this addWeaponTurret ['rhsusf_weap_laneMarkerSystem',[-1]]";
		};
		class LaneMarkingSystem_Deactivate: LaneMarkingSystem_Activate
		{
			displayName="Deactivate Lane Marking System";
			condition="((driver this) isEqualTo (call rhs_fnc_findPlayer)) && {this animationSourcePhase 'Dispenser_Fold' isEqualTo 1};";
			statement="this animateSource ['Dispenser_Fold', 0];this removeWeaponTurret ['rhsusf_weap_laneMarkerSystem',[-1]]";
		};
		class LaneMarkingSystem_Options: LaneMarkingSystem_Deactivate
		{
			displayName="<t color='#FDDE00'>Lane Marking System - Options</t>";
			statement="this call rhs_fnc_stryker_m1132_LMS_UI;";
		};
		class Interact_LeftPlow
		{
			displayName="Interact with left mine plow";
			position="";
			radius=1.5;
			onlyforplayer=0;
			actionNamedSel="SMP_L";
			condition="speed this < 1";
			statement="this animateSource ['SMP_L', abs((this animationSourcePhase 'SMP_L') - 1)]";
		};
		class Interact_RightPlow: Interact_LeftPlow
		{
			displayName="Interact with right mine plow";
			actionNamedSel="SMP_R";
			statement="this animateSource ['SMP_R', abs((this animationSourcePhase 'SMP_R') - 1)]";
		};
	};

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheelsRunflat.hpp"
	};

	displayName="M1132 Mineplow Stryker M2";
	//editorSubcategory="RC_RHS_WD_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
};
class RC_Stryker_M1132_M2_D_B: RC_Stryker_M1132_M2_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_stryker_m1132_m2_d.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_hull_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_parts_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_slat_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_crows_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_wheels_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1132_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_ca.paa",
		"rhsusf\addons\rhsusf_m1a1\DUKE\data\duke_antennae_c_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa"
	};
};
class RC_Stryker_M1132_M2_WD_O: RC_Stryker_M1132_M2_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1132_M2_D_O: RC_Stryker_M1132_M2_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1132_M2_WD_I: RC_Stryker_M1132_M2_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1132_M2_D_I: RC_Stryker_M1132_M2_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};


class RC_Stryker_M1132_M2_Javelin_WD_B: RC_Stryker_M1132_M2_WD_B
{
	class EventHandlers: EventHandlers
	{
		class RC_Javelin
		{
			#include "\RC_RHS\includes_script\AttachJavelin.hpp"
		};
	};

	displayName="M1132 Mineplow Stryker M2/Javelin";
	editorSubcategory="RC_APC_ATGM_subcat";

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner_missile.hpp"

			weapons[]=
			{
				"RC_RHS_M2_CROWS_M151",
				"RC_Stryker_Missile_Launcher",
				"rhsusf_weap_M6"
			};
			magazines[]=
			{
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_RHS_mag_200rnd_127x99_SLAP_T_R",
				"RC_4Rnd_Javelin_MP_LOS",
				"RC_2Rnd_Javelin_MP_NLOS",
				"RC_4Rnd_Javelin_AA",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16",
				"rhsusf_mag_L8A3_16"
			};
		};
	};
};
class RC_Stryker_M1132_M2_Javelin_D_B: RC_Stryker_M1132_M2_Javelin_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_stryker_m1132_m2_d.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_hull_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_parts_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_slat_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_crows_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_wheels_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1132_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_ca.paa",
		"rhsusf\addons\rhsusf_m1a1\DUKE\data\duke_antennae_c_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa"
	};
};
class RC_Stryker_M1132_M2_Javelin_WD_O: RC_Stryker_M1132_M2_Javelin_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1132_M2_Javelin_D_O: RC_Stryker_M1132_M2_Javelin_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1132_M2_Javelin_WD_I: RC_Stryker_M1132_M2_Javelin_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1132_M2_Javelin_D_I: RC_Stryker_M1132_M2_Javelin_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};


/*
	//testing alternatives to make M1127 driver view work

	class B_UAV_AI;
	class RC_B_UAV_AI_Model: B_UAV_AI
	{
		model="\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
		modelSides[]={3,1};
		moves="CfgMovesMaleSdr";
	};
*/


class rhsusf_stryker_m1127_m2_wd;
class RC_Stryker_M1127_M2_WD_Base: rhsusf_stryker_m1127_m2_wd
{
	scope=0;
	scopeCurator=0;
	class Components;
	class EventHandlers;
	class Turrets;
	class CargoTurret;
	//class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class Turret_LRAS;
	class Turret_Weapon;
	class ViewPilot;
	class ViewOptics;
	class AnimationSources;
	class ramp;
	class Hatch_Commander;
	class UserActions;
	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Stryker_M1127_M2_WD: RC_Stryker_M1127_M2_WD_Base
{
	#include "\RC_RHS\cfgVehicles\StrykerBasics_Include.hpp"

	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;
	weapons[]=
	{
		"RC_target_confirmer_datalink",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};
	
	class AnimationSources: AnimationSources
	{
		class Hatch_Commander: Hatch_Commander
		{
			animPeriod=0.8;
		};
		class ramp: ramp
		{
			animPeriod=1.25;
		};
		/*
		class Hatch_Driver
		{
		};
		*/
		class ReloadAnim
		{
			source="reload";
			weapon="RC_RHS_M2_DroneLock";
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="RC_RHS_M2_DroneLock";
		};
		class Revolving
		{
			source="revolving";
			weapon="RC_RHS_M2_DroneLock";
		};
		class muzzle_rot_MG
		{
			source="ammorandom";
			weapon="RC_RHS_M2_DroneLock";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"
			gunnerName="Gunner";

			weapons[]=
			{
				"RC_target_confirmer_datalink",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_target_confirmer_mag",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			/*
			memoryPointGunnerOptics[]={"driverview","pilot"};	// ""
			//gunnerOpticsModel="";

			class OpticsIn
			{
				class DVE_Wide: ViewOptics
				{
					camPos="view_DVE";
					opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
					gunnerOpticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={0};
					hitpoint="Hit_Optic_DVEA";
					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
				};
				class DVS_Rear: DVE_Wide
				{
					camPos="view_rear";
					camDir="view_rear_dir";
					hitpoint="Hit_Optic_Driver_Rear";
				};
			};
			class ViewOptics: ViewOptics
			{
				camPos="view_DVE";
				opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
				gunnerOpticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
				hitpoint="Hit_Optic_DVEA";
				initFov=0.9;
				minFov=0.02;
				maxFov=0.9;
			};
			*/
		};

		class Turret_Weapon: Turret_Weapon
		{
			//canUseScanner=0; // Can't use the vehicle's Sensors, can be defined per individual turret. Useful to restrict access to vehicle sensors (target marking) on some positions in vehicles (i.e. door gunners)
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"
			maxElev=50;	//30

			weapons[]=
			{
				"RC_RHS_M2_DroneLock",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R",
				"RC_RHS_mag_150rnd_127x99_SLAP_DroneLock_T_R",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
		
		class Turret_LRAS: Turret_LRAS
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"

			class OpticsIn
			{
				class Wide: ViewOptics
				{
					opticsDisplayName="4";
					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI",
						"NVG"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhsusf_CITV_w";
					hitpoint="Hit_Optic_LRAS3";
				};
			};
		};

		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};
	};
};
class RC_Stryker_M1127_M2_WD_FixedRC: RC_Stryker_M1127_M2_WD
{
	class DriverOpticsIn: DriverOpticsIn
	{
		class DVE_Wide: DVE_Wide
		{
			visionMode[]=
			{
				"Normal",
				"TI",
				"NVG"
			};
		};
		class DVS_Rear: DVS_Rear
		{
			visionMode[]=
			{
				"Normal",
				"TI",
				"NVG"
			};
		};
	};

	//driverDoor="";
	//LODDriverTurnedOut=1100;
	//LODDriverTurnedin=1100;

	/*
	class AnimationSources: AnimationSources
	{
		class Hatch_Driver
		{
			*/
			/*
			displayName="Open driver hatch";
			source="door";
			animPeriod=2.0999999;
			sound="RHS_HMMWV_Door";
			soundPosition="hatch_driver_axis";
			*/
			/*
		};
	};
	*/

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=1;
			primaryGunner=0;	//to not be bugged by being remote controlled
			primaryObserver=1;	//to still trigger driver controls script
			//gunnerForceOptics=1;
			//forceHideGunner=1;
		};
		class Turret_Weapon: Turret_Weapon {};
		class Turret_LRAS: Turret_LRAS {};
		class CargoTurret_01: CargoTurret
		{
			//required to keep AI driver hatch closed, as turned out driver cannot view optic while remote controlling
			dontCreateAI=0;

			gunnerName="AI";
			gunnerCompartments="Compartment3";
			proxyIndex=8;	//1
			cargoProxyIndexes[]={2,3,4,5,6,7, 8};

			showAsCargo=0;
			personturretAction="";
			gunnerDoor="Ramp";
			viewGunnerInExternal=1;
			isPersonTurret=2;
			commanding=4;
			maxOutTurn=110;
			minOutTurn=-110;
			maxOutElev=75;
			minOutElev=-15;
			LODTurnedOut=1;
			LODTurnedin=1200;
			animationSourceHatch="";
			gunnerForceOptics=0;

			//commenting out one of these below removed buggy first passenger sitting animation
			//gunnerInAction="RHS_Stryker_M1126_TC_in";
			//gunnerAction="RHS_Stryker_M1126_TC_out";
			//rhs_hatch="Hatch_Front";
			//rhs_hatch_control=1;
			//enabledByAnimationSource="Hatch_Front";
		};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};
	};
};


class RC_Stryker_M1127_M2_WD_B: RC_Stryker_M1127_M2_WD_FixedRC
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="RC M1127 Stryker LRAS/M2";
	//editorSubcategory="RC_RHS_WD_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	vehicleClass="Autonomous";
	uavCameraDriverPos="view_DVE";
	uavCameraDriverDir="view_DVE";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
};
class RC_Stryker_M1127_M2_D_B: RC_Stryker_M1127_M2_WD_B
{
	//editorSubcategory="RC_RHS_D_subcat";
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_stryker_m1127_m2_d.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_hull_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_parts_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_slat_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_crows_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_wheels_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_M1127_des_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_LRAS3_d_CO.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_co.paa",
		"rhsusf\addons\rhsusf_stryker\data\rhsusf_m1126_acc_d_ca.paa",
		"rhsusf\addons\rhsusf_m1a1\DUKE\data\duke_antennae_c_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMFC\data\rhsusf_mfc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa",
		"rhsusf\addons\rhsusf_props\jerrycans\scepterMWC\data\rhsusf_mwc_d_co.paa"
	};
};
class RC_Stryker_M1127_M2_WD_O: RC_Stryker_M1127_M2_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_Stryker_M1127_M2_D_O: RC_Stryker_M1127_M2_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_Stryker_M1127_M2_WD_I: RC_Stryker_M1127_M2_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
class RC_Stryker_M1127_M2_D_I: RC_Stryker_M1127_M2_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};



class RC_Stryker_M1127_M2_RCIV_WD_B: RC_Stryker_M1127_M2_WD_B
{
	editorSubcategory="RC_ICV_armed_subcat";
};
class RC_Stryker_M1127_M2_RCIV_D_B: RC_Stryker_M1127_M2_D_B
{
	editorSubcategory="RC_ICV_armed_subcat";
};
class RC_Stryker_M1127_M2_RCIV_WD_O: RC_Stryker_M1127_M2_WD_O
{
	editorSubcategory="RC_ICV_armed_subcat";
};
class RC_Stryker_M1127_M2_RCIV_D_O: RC_Stryker_M1127_M2_D_O
{
	editorSubcategory="RC_ICV_armed_subcat";
};
class RC_Stryker_M1127_M2_RCIV_WD_I: RC_Stryker_M1127_M2_WD_I
{
	editorSubcategory="RC_ICV_armed_subcat";
};
class RC_Stryker_M1127_M2_RCIV_D_I: RC_Stryker_M1127_M2_D_I
{
	editorSubcategory="RC_ICV_armed_subcat";
};