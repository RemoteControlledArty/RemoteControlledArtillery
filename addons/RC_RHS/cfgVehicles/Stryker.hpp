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
					minFov=0.025;
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
	editorSubcategory="RC_RHS_WD_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;
	crew="B_UAV_AI";
};
class RC_Stryker_M1126_M2_D_B: RC_Stryker_M1126_M2_WD_B
{
	editorSubcategory="RC_RHS_D_subcat";
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
			init="if (!isserver) exitwith {}; \
			(_this select 0) spawn { \
				private _javelin = 'item_rhs_fgm148_magazine_AT' createVehicle [0,0,0]; \
				_javelin attachTo [_this, [0.34, -0.05, -0.13], 'konec hlavne', true]; \
				private _yaw = 90; private _pitch = 0; private _roll = 20; \
				_javelin setVectorDirAndUp [ \
					[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch], \
					[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D \
				]; \
			};";
		};
	};

	displayName="M1126 Stryker M2/Javelin";

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
	editorSubcategory="RC_RHS_D_subcat";
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
					minFov=0.025;
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
	editorSubcategory="RC_RHS_WD_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
};
class RC_Stryker_M1126_MK19_D_B: RC_Stryker_M1126_MK19_WD_B
{
	editorSubcategory="RC_RHS_D_subcat";
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


class RC_Stryker_M1126_20mm_AC_WD_B: RC_Stryker_M1126_MK19_WD_B
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
class RC_Stryker_M1126_20mm_AC_D_B: RC_Stryker_M1126_20mm_AC_WD_B
{
	editorSubcategory="RC_RHS_D_subcat";
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
class RC_Stryker_M1126_20mm_AC_WD_O: RC_Stryker_M1126_20mm_AC_WD_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_20mm_AC_D_O: RC_Stryker_M1126_20mm_AC_D_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\RC_RHS\loadouts\IFVitemsO_RHS.hpp"
};
class RC_Stryker_M1126_20mm_AC_WD_I: RC_Stryker_M1126_MK19_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\RC_RHS\loadouts\IFVitemsI_RHS.hpp"
};
class RC_Stryker_M1126_20mm_AC_D_I: RC_Stryker_M1126_20mm_AC_D_B
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
					minFov=0.025;
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
	editorSubcategory="RC_RHS_WD_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	faction="RemoteControlled_B";
	side=1;

	crew="B_UAV_AI";
};
class RC_Stryker_M1132_M2_D_B: RC_Stryker_M1132_M2_WD_B
{
	editorSubcategory="RC_RHS_D_subcat";
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
			init="if (!isserver) exitwith {}; \
			(_this select 0) spawn { \
				private _javelin = 'item_rhs_fgm148_magazine_AT' createVehicle [0,0,0]; \
				_javelin attachTo [_this, [0.34, -0.05, -0.13], 'konec hlavne', true]; \
				private _yaw = 90; private _pitch = 0; private _roll = 20; \
				_javelin setVectorDirAndUp [ \
					[sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch], \
					[[sin _roll, -sin _pitch, cos _roll * cos _pitch], -_yaw] call BIS_fnc_rotateVector2D \
				]; \
			};";
		};
	};

	displayName="M1132 Mineplow Stryker M2/Javelin";

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
	editorSubcategory="RC_RHS_D_subcat";
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
	//class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class MainTurret;
	class Turret_LRAS;
	class Turret_Weapon;
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

	/*
	weapons[]=
	{
		"rhsusf_weap_M6_GLUA",
		"rhsusf_weap_M6_L1",
		"rhsusf_weap_M6_L2",
		"rhsusf_weap_M6_L3",
		"rhsusf_weap_M6_R1",
		"rhsusf_weap_M6_R2",
		"rhsusf_weap_M6_R3"
	};
	magazines[]=
	{
		"rhsusf_mag_L8A3_48",
		"rhsusf_mag_L8A3_L1_8",
		"rhsusf_mag_L8A3_L2_8",
		"rhsusf_mag_L8A3_L3_8",
		"rhsusf_mag_L8A3_R1_8",
		"rhsusf_mag_L8A3_R2_8",
		"rhsusf_mag_L8A3_R3_8"
	};
	*/
	
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
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_APC_gunner.hpp"
			gunnerName="Gunner";
			//isCopilot=1; //allows to trigger EH that gives driving controls
			//canUseScanner = 0; // Can't use the vehicle's Sensors, can be defined per individual turret. Useful to restrict access to vehicle sensors (target marking) on some positions in vehicles (i.e. door gunners)
		};

		class Turret_Weapon: Turret_Weapon {};

		/*
		class Turret_Weapon: Turret_Weapon
		{
			weapons[]=
			{
				"RC_RHS_M2_nonlock"
			};
			magazines[]=
			{
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock",
				"RC_RHS_mag_100rnd_127x99_T_R_nonlock"
			};
		};
		*/
		
		class Turret_LRAS: Turret_LRAS
		{
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
						"TI",
						"Normal"
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


class RC_Stryker_M1127_M2_WD_B: RC_Stryker_M1127_M2_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
		};
	};

	displayName="M1127 Stryker M2";
	editorSubcategory="RC_RHS_WD_subcat";
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
	editorSubcategory="RC_RHS_D_subcat";
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


class RC_Stryker_M1127_WD_B: RC_Stryker_M1127_M2_WD_B
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\initAPC.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_APC.hpp"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			forceHideGunner=1;
		};
		class Turret_Weapon: Turret_Weapon {};
		class Turret_LRAS: Turret_LRAS {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_03: CargoTurret_03 {};
	};

	displayName="RC M1127 Stryker";
};
class RC_Stryker_M1127_D_B: RC_Stryker_M1127_WD_B
{
	editorSubcategory="RC_RHS_D_subcat";
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


class RC_Stryker_M1127_WD_I: RC_Stryker_M1127_WD_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
class RC_Stryker_M1127_D_I: RC_Stryker_M1127_D_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};