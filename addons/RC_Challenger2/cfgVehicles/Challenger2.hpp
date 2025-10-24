class qav_B_challenger2_e;
class RC_Challenger2_Base: qav_B_challenger2_e
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class LoaderTurret;
	class ViewOptics;
	class Components;
	class TextureSources;
	class olive;
	class natoarid;
	class showCamonetHull;
	class showCamonetCannon;
	class showCamonetCannon1;
	class showCamonetTurret;
	class OpticsIn;
	class Wide;
	class UserActions;
	class AnimationSources;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Challenger2_A_Base: RC_Challenger2_Base
{
	class EventHandlers: EventHandlers
	{
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

	faction="RemoteControlled_B";
	editorSubcategory="RC_MBT_subcat";
	author="Ascent";
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	maxSpeed=70;
	enginePower=1537.5;
	peakTorque=6250;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet

	hiddenSelectionsTextures[]=
	{
		"QAV_Challenger\data\textures\olive\c2hull1_co.paa",
		"QAV_Challenger\data\textures\olive\c2hull2_co.paa",
		"QAV_Challenger\data\textures\olive\c2turret1_co.paa",
		"QAV_Challenger\data\textures\olive\c2turret2_co.paa",
		"QAV_Challenger\data\textures\olive\c2wheels1_co.paa",
		"QAV_Challenger\data\textures\olive\c2acc1_co.paa",
		"QAV_Challenger\data\textures\olive\c2eparts_co.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};

	class TextureSources: TextureSources
	{
		class RC_Olive: olive
		{
			displayName="Olive (RC)";
			textures[]=
			{
				"QAV_Challenger\data\textures\olive\c2hull1_co.paa",
				"QAV_Challenger\data\textures\olive\c2hull2_co.paa",
				"QAV_Challenger\data\textures\olive\c2turret1_co.paa",
				"QAV_Challenger\data\textures\olive\c2turret2_co.paa",
				"QAV_Challenger\data\textures\olive\c2wheels1_co.paa",
				"QAV_Challenger\data\textures\olive\c2acc1_co.paa",
				"QAV_Challenger\data\textures\olive\c2eparts_co.paa",
				"a3\armor_f\data\camonet_green_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class RC_Arid: natoarid
		{
			displayName="Arid (RC)";
			textures[]=
			{
				"QAV_Challenger\data\textures\natoarid\c2hull1_co.paa",
				"QAV_Challenger\data\textures\natoarid\c2hull2_co.paa",
				"QAV_Challenger\data\textures\natoarid\c2turret1_co.paa",
				"QAV_Challenger\data\textures\natoarid\c2turret2_co.paa",
				"QAV_Challenger\data\textures\natoarid\c2wheels1_co.paa",
				"QAV_Challenger\data\textures\natoarid\c2acc1_co.paa",
				"QAV_Challenger\data\textures\natoarid\c2eparts_co.paa",
				"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
	};
	textureList[]=
	{
		"RC_Olive",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=2;
			//turretInfoType="RscOptics_APC_Wheeled_01_gunner";
			//turretInfoType="RscOptics_MBT_03_gunner";

			weapons[]=
			{
				"RC_cannon_120mm",
				"RC_MMG_338_MBT_coax",
				"qav_SmokeLauncher"
			};
			#include "\RC_Challenger2\includes_vicmags\mags_Challenger2_gunner_red.hpp"

			class OpticsIn
			{
				class Wide: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.4;
					minFov=0.02;
					maxFov=0.4;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\QAV_Challenger\c2_com_op_n.p3d";
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_01_m_F.p3d";
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_m_F.p3d";
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
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
					//turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						"qav_SmokeLauncher"
					};
					magazines[]=
					{
						"qav_SmokeLauncherMag",
						"qav_SmokeLauncherMag",
						"Laserbatteries"
					};

					class OpticsIn
					{
						class Wide: ViewOptics
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
							gunnerOpticsModel="\QAV_Challenger\c2_com_op_n.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
				};
				class LoaderTurret: LoaderTurret
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_commander.hpp"

					weapons[]=
					{
						"qav_challenger_m2"
					};
					magazines[]=
					{
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red",
						"100Rnd_127x99_mag_Tracer_Red"
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
			weapon="RC_cannon_120mm";
		};
		class muzzle_rot_coax
		{
			source="ammorandom";
			weapon="RC_MMG_338_MBT_coax";
		};
		class muzzle_rot_hmg
		{
			source="ammorandom";
			weapon="RC_HMG_127x99_MBT";
		};
		class muzzle_hide_coax
		{
			source="reload";
			weapon="RC_MMG_338_MBT_coax";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_cannon_120mm";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=0;
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=0;
		};
		class showCamonetCannon1: showCamonetCannon1
		{
			initPhase=0;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=0;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};


class RC_Challenger2_A: RC_Challenger2_A_Base
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

	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class Turrets: Turrets
			{
				class CommanderOptics;
				class LoaderTurret;
			};
		};
	};
	*/

	displayName="Challenger 2E";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	crew="B_UAV_AI";
};
class RC_Challenger2_A_O: RC_Challenger2_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Challenger2\includes_vicmags\mags_Challenger2_gunner_green.hpp"

			/*
			class Turrets: Turrets
			{
				class CommanderOptics;
				class LoaderTurret;
			};
			*/
		};
	};
};
class RC_Challenger2_A_I: RC_Challenger2_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Challenger2\includes_vicmags\mags_Challenger2_gunner_yellow.hpp"

			/*
			class Turrets: Turrets
			{
				class CommanderOptics;
				class LoaderTurret;
			};
			*/
		};
	};
};


class RC_Challenger2_WD: RC_Challenger2_A
{
	hiddenSelectionsTextures[]=
	{
		"QAV_Challenger\data\textures\natoarid\c2hull1_co.paa",
		"QAV_Challenger\data\textures\natoarid\c2hull2_co.paa",
		"QAV_Challenger\data\textures\natoarid\c2turret1_co.paa",
		"QAV_Challenger\data\textures\natoarid\c2turret2_co.paa",
		"QAV_Challenger\data\textures\natoarid\c2wheels1_co.paa",
		"QAV_Challenger\data\textures\natoarid\c2acc1_co.paa",
		"QAV_Challenger\data\textures\natoarid\c2eparts_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};
	textureList[]=
	{
		"RC_Arid",
		1
	};
};
class RC_Challenger2_WD_O: RC_Challenger2_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Challenger2\includes_vicmags\mags_Challenger2_gunner_green.hpp"

			/*
			class Turrets: Turrets
			{
				class CommanderOptics;
				class LoaderTurret;
			};
			*/
		};
	};
};
class RC_Challenger2_WD_I: RC_Challenger2_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Challenger2\includes_vicmags\mags_Challenger2_gunner_yellow.hpp"

			/*
			class Turrets: Turrets
			{
				class CommanderOptics;
				class LoaderTurret;
			};
			*/
		};
	};
};