class EF_B_AAV9_50mm_MJTF_Des;
class RC_AAV9A1_Base: EF_B_AAV9_50mm_MJTF_Des
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class CrewmanStation;
	class CargoGunner_3;
	class CargoGunner_4;
	class CargoGunner_5;
	class CargoGunner_6;
	//class HitPoints;
	//class HitHull;
	//class HitEngine;
	//class HitFuel;
	class AnimationSources;
	class TextureSources;
	class camonet_hull;
	class camonet_mainTurret;
	class camonet_mainGun;
	class camonet_trimvane;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_AAV9A1: RC_AAV9A1_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4kmSens.hpp"
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
	normalSpeedForwardCoef=0.75;
	enginePower=1000;	//800
	peakTorque=4000;	//3400
	
	/*
	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=2;
		};
		class HitEngine: HitEngine
		{
			armor=1.25;
		};
	};
	*/

	textureList[]=
	{
		"Desert",
		0,
		"Olive",
		0,
		"RACS",
		0,
		"RCOlive",
		0,
		"RCSand",
		1,
		"Sand",
		0,
		"Tropic",
		0,
		"Woodland",
		0
	};
	class TextureSources: TextureSources
	{
		class RCSand
		{
			textures[]=
			{
				"ef\ef_aav9_t\data\aav9_hull_1_co.paa",
				"ef\ef_aav9_t\data\aav9_hull_2_co.paa",
				"ef\ef_aav9_t\data\aav9_hull_3_co.paa",
				"ef\ef_aav9_t\data\aav9_hull_4_co.paa",
				"ef\ef_aav9_t\data\aav9_hull_5_co.paa",
				"ef\ef_aav9_t\data\aav9_turret_1_co.paa",
				"ef\ef_aav9_t\data\aav9_alpha_1_co.paa",
				"ef\ef_aav9_t\data\aav9_turret_2_co.paa",
				"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
			};
			factions[]={};
		};
		class RCOlive
		{
			textures[]=
			{
				"\ef\ef_aav9_t\data\aav9_hull_1_olive_co.paa",
				"\ef\ef_aav9_t\data\aav9_hull_2_olive_co.paa",
				"\ef\ef_aav9_t\data\aav9_hull_3_olive_co.paa",
				"\ef\ef_aav9_t\data\aav9_hull_4_olive_co.paa",
				"\ef\ef_aav9_t\data\aav9_hull_5_olive_co.paa",
				"\ef\ef_aav9_t\data\aav9_turret_1_olive_co.paa",
				"\ef\ef_aav9_t\data\aav9_alpha_1_olive_co.paa",
				"\ef\ef_aav9_t\data\aav9_turret_2_olive_co.paa",
				"a3\armor_f\data\camonet_green_co.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"ef\ef_aav9_t\data\aav9_hull_1_co.paa",
		"ef\ef_aav9_t\data\aav9_hull_2_co.paa",
		"ef\ef_aav9_t\data\aav9_hull_3_co.paa",
		"ef\ef_aav9_t\data\aav9_hull_4_co.paa",
		"ef\ef_aav9_t\data\aav9_hull_5_co.paa",
		"ef\ef_aav9_t\data\aav9_turret_1_co.paa",
		"ef\ef_aav9_t\data\aav9_alpha_1_co.paa",
		"ef\ef_aav9_t\data\aav9_turret_2_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};

	class AnimationSources: AnimationSources
	{
		class maingun_ammorandom
		{
			source="ammorandom";
			weapon="RC_EF_autocannon_50mm";
		};
		class maingun_reload
		{
			source="reload";
			weapon="RC_EF_autocannon_50mm";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_EF_autocannon_50mm";
		};
		class coax_ammorandom
		{
			source="ammorandom";
			weapon="RC_EF_MMG_coax";
		};
		class camonet_hull: camonet_hull
		{
			initPhase=1;
		};
		class camonet_mainTurret: camonet_mainTurret
		{
			initPhase=1;
		};
		/*
		class camonet_mainGun: camonet_mainGun
		{
			initPhase=1;
		};
		*/
		class camonet_trimvane: camonet_trimvane
		{
			initPhase=1;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_AAV9A1_A: RC_AAV9A1
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="AAV-9A1";
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
		class CargoGunner_3: CargoGunner_3 {};
		class CargoGunner_4: CargoGunner_4 {};
		class CargoGunner_5: CargoGunner_5 {};
		class CargoGunner_6: CargoGunner_6 {};

		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_Sens.hpp"
			showAllTargets="2 + 4";
			commanding=4;

			weapons[]=
			{
				"RC_EF_autocannon_50mm",
				"RC_EF_MMG_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_EF_120Rnd_50mm_HE_T_W",
				"RC_EF_120Rnd_50mm_HE_T_W",
				"RC_EF_120Rnd_50mm_HE_T_W",
				"RC_EF_50Rnd_50mm_APFSDS_T_W",
				"RC_EF_50Rnd_50mm_APFSDS_T_W",
				"RC_EF_50Rnd_50mm_APFSDS_T_W",
				"RC_400Rnd_338_T_W",
				"RC_400Rnd_338_T_W",
				"RC_400Rnd_338_T_W",
				"SmokeLauncherMag",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			//#include "\RC_ExpForces\includes_vicmags\mags_AAV9A1_red.hpp"

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
				class CrewmanStation: CrewmanStation
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_Sens.hpp"
					showAllTargets="2 + 4";
					commanding=2;
					turretInfoType="RscOptics_MBT_03_gunner";

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

				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_Sens.hpp"
					showAllTargets="2 + 4";
					commanding=3;
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
class RC_AAV9A1_A_O: RC_AAV9A1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class CargoGunner_3: CargoGunner_3 {};
		class CargoGunner_4: CargoGunner_4 {};
		class CargoGunner_5: CargoGunner_5 {};
		class CargoGunner_6: CargoGunner_6 {};

		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_EF_120Rnd_50mm_HE_T_G",
				"RC_EF_120Rnd_50mm_HE_T_G",
				"RC_EF_120Rnd_50mm_HE_T_G",
				"RC_EF_50Rnd_50mm_APFSDS_T_G",
				"RC_EF_50Rnd_50mm_APFSDS_T_G",
				"RC_EF_50Rnd_50mm_APFSDS_T_G",
				"RC_400Rnd_338_T_G",
				"RC_400Rnd_338_T_G",
				"RC_400Rnd_338_T_G"
			};
		};
	};
};
class RC_AAV9A1_A_I: RC_AAV9A1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class CargoGunner_3: CargoGunner_3 {};
		class CargoGunner_4: CargoGunner_4 {};
		class CargoGunner_5: CargoGunner_5 {};
		class CargoGunner_6: CargoGunner_6 {};

		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_EF_120Rnd_50mm_HE_T_Y",
				"RC_EF_120Rnd_50mm_HE_T_Y",
				"RC_EF_120Rnd_50mm_HE_T_Y",
				"RC_EF_50Rnd_50mm_APFSDS_T_Y",
				"RC_EF_50Rnd_50mm_APFSDS_T_Y",
				"RC_EF_50Rnd_50mm_APFSDS_T_Y",
				"RC_400Rnd_338_T_Y",
				"RC_400Rnd_338_T_Y",
				"RC_400Rnd_338_T_Y"
			};
		};
	};
};


class RC_AAV9A1_WD: RC_AAV9A1_A
{
	editorPreview="\ef\ef_data\editorpreviews\cfgvehicles\EF_B_AAV9_50mm_MJTF_Wdl.jpg";
	textureList[]=
	{
		"Desert",
		0,
		"Olive",
		0,
		"RACS",
		0,
		"RCOlive",
		1,
		"RCSand",
		0,
		"Sand",
		0,
		"Tropic",
		0,
		"Woodland",
		0
	};
	hiddenSelectionsTextures[]=
	{
		"\ef\ef_aav9_t\data\aav9_hull_1_olive_co.paa",
		"\ef\ef_aav9_t\data\aav9_hull_2_olive_co.paa",
		"\ef\ef_aav9_t\data\aav9_hull_3_olive_co.paa",
		"\ef\ef_aav9_t\data\aav9_hull_4_olive_co.paa",
		"\ef\ef_aav9_t\data\aav9_hull_5_olive_co.paa",
		"\ef\ef_aav9_t\data\aav9_turret_1_olive_co.paa",
		"\ef\ef_aav9_t\data\aav9_alpha_1_olive_co.paa",
		"\ef\ef_aav9_t\data\aav9_turret_2_olive_co.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AAV9A1_WD_O: RC_AAV9A1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class CargoGunner_3: CargoGunner_3 {};
		class CargoGunner_4: CargoGunner_4 {};
		class CargoGunner_5: CargoGunner_5 {};
		class CargoGunner_6: CargoGunner_6 {};

		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_EF_120Rnd_50mm_HE_T_G",
				"RC_EF_120Rnd_50mm_HE_T_G",
				"RC_EF_120Rnd_50mm_HE_T_G",
				"RC_EF_50Rnd_50mm_APFSDS_T_G",
				"RC_EF_50Rnd_50mm_APFSDS_T_G",
				"RC_EF_50Rnd_50mm_APFSDS_T_G",
				"RC_400Rnd_338_T_G",
				"RC_400Rnd_338_T_G",
				"RC_400Rnd_338_T_G"
			};
		};
	};
};
class RC_AAV9A1_WD_I: RC_AAV9A1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class CargoGunner_3: CargoGunner_3 {};
		class CargoGunner_4: CargoGunner_4 {};
		class CargoGunner_5: CargoGunner_5 {};
		class CargoGunner_6: CargoGunner_6 {};

		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_EF_120Rnd_50mm_HE_T_Y",
				"RC_EF_120Rnd_50mm_HE_T_Y",
				"RC_EF_120Rnd_50mm_HE_T_Y",
				"RC_EF_50Rnd_50mm_APFSDS_T_Y",
				"RC_EF_50Rnd_50mm_APFSDS_T_Y",
				"RC_EF_50Rnd_50mm_APFSDS_T_Y",
				"RC_400Rnd_338_T_Y",
				"RC_400Rnd_338_T_Y",
				"RC_400Rnd_338_T_Y"
			};
		};
	};
};