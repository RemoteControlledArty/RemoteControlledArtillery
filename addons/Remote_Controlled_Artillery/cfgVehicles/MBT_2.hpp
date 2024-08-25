class I_MBT_03_cannon_F;
class RC_MBT_2_Base: I_MBT_03_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	class AnimationSources;
	class showCamonetHull;
	class showCamonetCannon;
	class showCamonetCannon1;
	class showCamonetTurret;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_MBT_2_A_Base: RC_MBT_2_Base
{
	#include "\Remote_Controlled_Artillery\includes\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_MBT_subcat";
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
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext01_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext02_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_rcws_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
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

					initFov=0.4;
					minFov=0.02;
					maxFov=0.4;
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
			initPhase=1;
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
		class showCamonetCannon1: showCamonetCannon1
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};


/*
//removed as engine cant be turned off for repair
class RC_MBT_2_A_Driverless: RC_MBT_2_A_Base
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

	displayName="DL Leopard 2";
	crew="";
	hasDriver=-1;
};
class RC_MBT_2_A_Driverless_O: RC_MBT_2_A_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};
class RC_MBT_2_A_Driverless_I: RC_MBT_2_A_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"
};


class RC_MBT_2_WD_Driverless: RC_MBT_2_A_Driverless
{
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext01_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext02_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_rcws_co.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MBT_2_WD_Driverless_O: RC_MBT_2_WD_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"
};
class RC_MBT_2_WD_Driverless_I: RC_MBT_2_WD_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"
};
*/



class RC_MBT_2_A: RC_MBT_2_A_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	displayName="Leopard 2";
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
class RC_MBT_2_A_O: RC_MBT_2_A
{
	faction="RemoteControlled_O";
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_2_A_I: RC_MBT_2_A
{
	faction="RemoteControlled_I";
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};


class RC_MBT_2_WD: RC_MBT_2_A
{
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext01_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext02_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_rcws_co.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MBT_2_WD_O: RC_MBT_2_WD
{
	faction="RemoteControlled_O";
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_2_WD_I: RC_MBT_2_WD
{
	faction="RemoteControlled_I";
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_MBT_2_ReTex_WD: RC_MBT_2_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_wd.paa",
		"leopard2\data\leopard_ext02_wd.paa",
		"leopard2\data\leopard_rcws_wd.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MBT_2_ReTex_WD_O: RC_MBT_2_ReTex_WD
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_2_ReTex_WD_I: RC_MBT_2_ReTex_WD
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};


class RC_MBT_2_ReTex_D: RC_MBT_2_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_d.paa",
		"leopard2\data\leopard_ext02_d.paa",
		"leopard2\data\leopard_rcws_d.paa",
		"leopard2\data\camonet_desert_co.paa"
	};
};
class RC_MBT_2_ReTex_D_O: RC_MBT_2_ReTex_D
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_2_ReTex_D_I: RC_MBT_2_ReTex_D
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};


class RC_MBT_2_ReTex_A: RC_MBT_2_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Arid_subcat";
	hiddenSelectionsTextures[]=
	{
		"leopard2\data\leopard_ext01_e.paa",
		"leopard2\data\leopard_ext02_e.paa",
		"leopard2\data\leopard_rcws_e.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};
};
class RC_MBT_2_ReTex_A_O: RC_MBT_2_ReTex_A
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};
class RC_MBT_2_ReTex_A_I: RC_MBT_2_ReTex_A
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
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
				};
			};
		};
	};
};