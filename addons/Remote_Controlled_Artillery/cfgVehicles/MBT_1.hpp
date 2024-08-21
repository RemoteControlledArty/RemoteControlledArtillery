class B_MBT_01_TUSK_F;
class RC_MBT_1_Base: B_MBT_01_TUSK_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetHull;
	class showCamonetPlates1;
	class showCamonetPlates2;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_MBT_1_A_Base: RC_MBT_1_Base
{
	#include "\Remote_Controlled_Artillery\includes\UserActions_TakeDriverControls.hpp"
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_MBT_subcat";
	author="Ascent";
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	lockDetectionSystem=4;
	incomingMissileDetectionSystem=16;
	soundLocked[]=
	{
		"\A3\Sounds_F\weapons\Rockets\locked_1",
		1,
		1
	};
	soundIncommingMissile[]=
	{
		"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4",
		0.39810717,
		1
	};
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet
	maxSpeed=70;
	enginePower=1537.5;
	peakTorque=6250;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	class ViewOptics: ViewOptics
	{
		visionMode[]=
		{
			"TI",
			"NVG",
			"Normal"
		};
	};

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_CO.paa",
		"A3\armor_f_gamma\MBT_01\Data\MBT_01_tow_CO.paa",
		"a3\armor_f_epc\mbt_01\data\mbt_addons_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};

				#include "\Remote_Controlled_Artillery\includes\passiveRadar.hpp"
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
		class recoil_source
		{
			source="reload";
			weapon="RC_cannon_120mm";
		};
		class muzzle_hide_cannon
		{
			source="reload";
			weapon="RC_cannon_120mm";
		};
		class muzzle_rot_coax
		{
			source="ammorandom";
			weapon="RC_MMG_338_MBT_coax";
		};
		class muzzle_hide_coax
		{
			source="reload";
			weapon="RC_MMG_338_MBT_coax";
		};
		class muzzle_rot_cmdr
		{
			source="ammorandom";
			weapon="RC_HMG_127x99_MBT";
		};
		class commander_gun_recoil
		{
			source="reload";
			weapon="RC_HMG_127x99_MBT";
		};
		class showCamonetPlates1: showCamonetPlates1
		{
			initPhase=1;
		};
		class showCamonetPlates2: showCamonetPlates2
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes\panels_IFV_gunner_missile.hpp"
			showAllTargets="2 + 4";
			commanding=2;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_cannon_120mm",
				"RC_MMG_338_MBT_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_20Rnd_120mm_APFSDS_T_R",
				"RC_20Rnd_120mm_MP_T_R",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
				"RC_200Rnd_338_T_R",
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
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes\panels_IFV_commander.hpp"
					showAllTargets="2 + 4";
					commanding=1;
					turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_HMG_127x99_MBT",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"RC_200Rnd_127x99_T_R",
						"RC_200Rnd_127x99_T_R",
						"RC_200Rnd_127x99_T_R",
						"RC_200Rnd_127x99_T_R",
						"RC_Laserbatteries",
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
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
					/*
					class ViewOptics: ViewOptics
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
					};
					*/
				};
			};
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


/*
//removed as engine cant be turned off for repair
class RC_MBT_1_A_Driverless: RC_MBT_1_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initDL.hpp"
			//#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="DL Merkava";
	crew="";
	hasDriver=-1;
};
class RC_MBT_1_A_Driverless_O: RC_MBT_1_A_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_MBT_1_A_Driverless_I: RC_MBT_1_A_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_MBT_1_WD_Driverless: RC_MBT_1_A_Driverless
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_TUSK_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_tow_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\mbt_addons_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MBT_1_WD_Driverless_O: RC_MBT_1_WD_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_MBT_1_WD_Driverless_I: RC_MBT_1_WD_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};
*/


class RC_MBT_1_A: RC_MBT_1_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Merkava";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	//vehicleClass="Autonomous";
	//uavCameraDriverPos="PiP0_pos";
	//uavCameraDriverDir="PiP0_dir";
	//isUav=1;
	//textPlural="UGVs";
	//textSingular="UGV";
	crew="B_UAV_AI";
	//driverForceOptics=1;
	//forceHideDriver=1;
};
class RC_MBT_1_A_O: RC_MBT_1_A
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
				"RC_20Rnd_120mm_APFSDS_T_G",
				"RC_20Rnd_120mm_MP_T_G",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_1_A_I: RC_MBT_1_A
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
				"RC_20Rnd_120mm_APFSDS_T_Y",
				"RC_20Rnd_120mm_MP_T_Y",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};


class RC_MBT_1_WD: RC_MBT_1_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_TUSK_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_tow_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\mbt_addons_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MBT_1_WD_O: RC_MBT_1_WD
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
				"RC_20Rnd_120mm_APFSDS_T_G",
				"RC_20Rnd_120mm_MP_T_G",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_1_WD_I: RC_MBT_1_WD
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
				"RC_20Rnd_120mm_APFSDS_T_Y",
				"RC_20Rnd_120mm_MP_T_Y",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_MBT_1_ReTex_D: RC_MBT_1_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"merkava\data\mbt_01_body_d.paa",
		"merkava\data\mbt_01_tow_d.paa",
		"merkava\data\mbt_addons_d.paa",
		"merkava\data\camonet_desert_co.paa"
	};
};
class RC_MBT_1_ReTex_D_O: RC_MBT_1_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_20Rnd_120mm_APFSDS_T_G",
				"RC_20Rnd_120mm_MP_T_G",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"RC_200Rnd_338_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_200Rnd_127x99_T_G",
						"RC_Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_1_ReTex_D_I: RC_MBT_1_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_20Rnd_120mm_APFSDS_T_Y",
				"RC_20Rnd_120mm_MP_T_Y",
				"RC_3Rnd_120mm_DLG_cannon_missiles",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"RC_200Rnd_338_T_Y",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					magazines[]=
					{
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_200Rnd_127x99_T_Y",
						"RC_Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};