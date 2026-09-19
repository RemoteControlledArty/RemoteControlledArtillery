class O_R_APC_Wheeled_04_cannon_F;
class RC_ICV_IFV_7_Fetch: O_R_APC_Wheeled_04_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	//class HitHull;
	//class HitEngine;
	class HitFuel;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class AnimationSources;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ICV_IFV_7_Core: RC_ICV_IFV_7_Fetch
{
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";

	driverCompartments="Compartment2";
	commanding=1;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=497.7;
	peakTorque=2529.4;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	class HitPoints: HitPoints
	{
		class HitFuel: HitFuel
		{
			passThrough=0.30000001;
		};
		
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics {};

				class SL_Seat
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\AdvisorOptics2.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"

					gunnerName="SL";
					proxyIndex=1;
					memoryPointsGetInGunner="pos cargo";
					memoryPointsGetInGunnerDir="pos cargo dir";
					memoryPointsGetInGunnerPrecise="pos cargo";
					gunnerCompartments="Compartment1";
				};
				class TL_Seat
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\AdvisorOptics2.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"

					gunnerName="TL";
					proxyIndex=2;
					memoryPointsGetInGunner="pos cargo";
					memoryPointsGetInGunnerDir="pos cargo dir";
					memoryPointsGetInGunnerPrecise="pos cargo";
					gunnerCompartments="Compartment1";
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class reload_cannon
		{
			source="reload";
			weapon="RC_autocannon_30mm_Bu";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm_Bu";
		};
		class Missiles_reloadMagazine
		{
			source="reloadMagazine";
			weapon="RC_IFV_Missile_Launcher_4R";
		};
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_IFV_Missile_Launcher_4R";
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};


class RC_ICV_7_Core: RC_ICV_IFV_7_Core
{
	//RC_ATrespondingTurret[]={0,0};

	displayName="RC BTR-80 unarmed";	//RC BTR-100 unarmed
	editorSubcategory="RC_ICV_subcat";

	weapons[]=
	{
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\values_RCIV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"

	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment3";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

					initFov=1;
					minFov=0.125;
					maxFov=1;
				};
			};
			turretInfoType="";
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

			/*
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
			*/

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
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_ICV_commander_gunner_fixated.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					gunnerForceOptics=1;
					commanding=3;

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
					
					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

							initFov=1;
							minFov=0.125;
							maxFov=1;
						};
					};
					turretInfoType="";
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

					/*
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
					*/
				};

				class SL_Seat: SL_Seat
				{
					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

							initFov=1;
							minFov=0.125;
							maxFov=1;
						};
					};
					turretInfoType="";
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
				};
				class TL_Seat: TL_Seat
				{
					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

							initFov=1;
							minFov=0.125;
							maxFov=1;
						};
					};
					turretInfoType="";
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
				};
			};
		};
	};
};
class RC_ICV_7_Base: RC_ICV_7_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Sensor_400m.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\DriveControls_CommanderOrGunner.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\initHideTurret.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cargo.hpp"
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
};


class RC_ICV_7_WD: RC_ICV_7_Base
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_ICV_7_WD_O: RC_ICV_7_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_7_WD_I: RC_ICV_7_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_ICV_7_A: RC_ICV_7_WD
{
	//editorPreview="";		//non available
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body2_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_tow_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_Green_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	/*
	textureList[]=
	{
		"Green",
		0,
		"Sand",
		0
	};
	*/
};
class RC_ICV_7_A_O: RC_ICV_7_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_ICV_7_A_I: RC_ICV_7_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_IFV_7_Core: RC_ICV_IFV_7_Core
{
	RC_ATrespondingTurret[]={0,0};

	displayName="BTR-100 Bumerang";
	editorSubcategory="RC_IFV_ATGM_subcat";
	
	weapons[]=
	{
		"RC_APS_W",
		"SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;

			weapons[]=
			{
				"RC_autocannon_30mm_Bu",
				"RC_MMG_93x64_coax_ext",
				"RC_IFV_Missile_Launcher_4R",
				"SmokeLauncher"
			};
			#include "\RC_Aegis\includes_vicmags\mags_BTR100_Bu_30mm_red.hpp"

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";

					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
				};
			};
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=2;

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
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
						};
					};
					turretInfoType="RscOptics_MBT_03_gunner";
				};

				class SL_Seat: SL_Seat
				{
					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
						};
					};
					turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				};
				class TL_Seat: TL_Seat
				{
					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
						};
					};
					turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				};
			};
		};
	};
};
class RC_IFV_7_Base: RC_IFV_7_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Sensor_400m.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\DriveControls_GunnerOrCommander.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cargo.hpp"
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
};


class RC_IFV_7_WD: RC_IFV_7_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

    #include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_IFV_7_WD_O: RC_IFV_7_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Aegis\includes_vicmags\mags_BTR100_Bu_30mm_green.hpp"
		};
	};
};
class RC_IFV_7_WD_I: RC_IFV_7_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Aegis\includes_vicmags\mags_BTR100_Bu_30mm_yellow.hpp"
		};
	};
};


class RC_IFV_7_A: RC_IFV_7_WD
{
	//editorPreview="";		//non available
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_body2_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_04\Data\APC_Wheeled_04_tow_sand_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_Green_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	/*
	textureList[]=
	{
		"Green",
		0,
		"Sand",
		0
	};
	*/
};
class RC_IFV_7_A_O: RC_IFV_7_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Aegis\includes_vicmags\mags_BTR100_Bu_30mm_green.hpp"
		};
	};
};
class RC_IFV_7_A_I: RC_IFV_7_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Aegis\includes_vicmags\mags_BTR100_Bu_30mm_yellow.hpp"
		};
	};
};