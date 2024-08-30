class Aegis_O_R_APC_Tracked_02_30mm_lxWS;
class RC_ICV_IFV_8_WD_Base: Aegis_O_R_APC_Tracked_02_30mm_lxWS
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	//class HitPoints;
	//class HitLTrack;
	//class HitRTrack;
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_IFV_8_WD: RC_ICV_IFV_8_WD_Base
{
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
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
	enginePower=575.3;
	peakTorque=2923.7;

	/*
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_01_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_02_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\apc_tracked_02_ext_03_RUkhk_co.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_30mm_RUkhk_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	*/

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_autocannon_30mm_lxWS";
		};
		class reload_cannon
		{
			source="reload";
			weapon="RC_autocannon_30mm_lxWS";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm_lxWS";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=0;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showTracks",
		0,
		"showCamonetHull",
		0,
		"showBags",
		0,
		"showSLATHull",
		1
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};


class RC_ICV_8_WD: RC_ICV_IFV_8_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initICV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
	};

	displayName="RC BM-2T unarmed";
	editorSubcategory="RC_ICV_subcat";
	scope=2;
	scopeCurator=2;

	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;

	maximumLoad=4000;
	threat[]={0.30000001,0.30000001,0.30000001};

	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	weapons[]=
	{
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
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
			showAllTargets="2 + 4";
			gunnerCompartments="Compartment3";
			commanding=2;
			gunnerForceOptics=1;
			//forceHideGunner=1;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="";

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

					initFov=1;
					minFov=0.125;
					maxFov=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};

			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				initFov=1;
				minFov=0.125;
				maxFov=1;
			};

			weapons[]=
			{
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
					showAllTargets="2 + 4";
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					turretInfoType="";
					gunnerForceOptics=1;
					//forceHideGunner=1;
					commanding=3;

					weapons[]=
					{
						"SmokeLauncher"
					};
					magazines[]=
					{
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
					
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

							initFov=1;
							minFov=0.125;
							maxFov=1;
							visionMode[]=
							{
								"Normal",
								"NVG"
							};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};

					class ViewOptics: ViewOptics
					{
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
						initFov=1;
						minFov=0.125;
						maxFov=1;
					};
				};
			};
		};
	};
};
class RC_ICV_8_WD_O: RC_ICV_8_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_8_WD_I: RC_ICV_8_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_IFV_8_WD: RC_ICV_IFV_8_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="BM-2T Bumerang";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;
	maximumLoad=3000;
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

	crew="B_UAV_AI";
	
	weapons[]=
	{
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			showAllTargets="2 + 4";
			commanding=3;
			//forceHideGunner=1;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_autocannon_30mm_lxWS",
				"RC_MMG_93x64_coax_ext_lxWS",
				"missiles_Vorona_vehicle_lxWS",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_160Rnd_30mm_MP_T_R",
				"RC_160Rnd_30mm_GPR_T_R",
				"RC_160Rnd_30mm_APFSDS_T_R",
				"RC_160Rnd_30mm_APFSDS_T_R",
				"RC_1000Rnd_93x64_T_R",
				"4rnd_Vorona_HEAT_lxWS",
				"4rnd_Vorona_HE_lxWS",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

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
					showAllTargets="2 + 4";
					commanding=2;
					//forceHideGunner=1;
					turretInfoType="RscOptics_MBT_03_gunner";

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
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
				};
			};
		};
	};
};
class RC_IFV_8_WD_O: RC_IFV_8_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_160Rnd_30mm_MP_T_G",
				"RC_160Rnd_30mm_GPR_T_G",
				"RC_160Rnd_30mm_APFSDS_T_G",
				"RC_160Rnd_30mm_APFSDS_T_G",
				"RC_1000Rnd_93x64_T_G",
				"4rnd_Vorona_HEAT_lxWS",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};
class RC_IFV_8_WD_I: RC_IFV_8_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_160Rnd_30mm_MP_T_Y",
				"RC_160Rnd_30mm_GPR_T_Y",
				"RC_160Rnd_30mm_APFSDS_T_Y",
				"RC_160Rnd_30mm_APFSDS_T_Y",
				"RC_1000Rnd_93x64_T_Y",
				"4rnd_Vorona_HEAT_lxWS",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
		};
	};
};