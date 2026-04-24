class B_?_Wheeled_?_F;
class RC_AFV_Fetch: B_?_Wheeled_?_F
{
	class EventHandlers;
	class UserActions;
	class Components;

	class Turrets;
	class MainTurret;
	class CommanderOptics;

	class AnimationSources;
	class showCamonetHull;
	class showCamonetCannon;
	class showCamonetTurret;
	class showSLATHull;
	class showSLATTurret;

	class HitPoints;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;

	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_AFV_Core: RC_AFV_Core
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
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\EjectDeadCrew.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";

	driverCompartments="Compartment2";
	commanding=1;
	crewCrashProtection=0.01;

	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

	class HitPoints: HitPoints
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};
};


class RC_AFV_Base: RC_AFV_Core
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	RC_ATrespondingTurret[]={0,0};

	displayName="Designation";
	editorSubcategory="RC_IFV_subcat";

	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=600;
	peakTorque=3000;

	weapons[]=
	{
		//"TruckHorn",
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			//#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			//#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner.hpp"
			//#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;

			//minElev=-;
			//maxElev=;

			weapons[]=
			{
				"RC_?0mm",
				"RC_MMG_338_coax",
				"SmokeLauncher"
			};

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					//gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";	//AA

					minAngleX=-30;
					maxAngleX=30;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
				};
			};
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";
			//turretinfotype="RscOptics_APC_Tracked_01_gunner";	//AA
			//turretInfoType="RscOptics_APC_Wheeled_03_gunner";	//white with turret direction indicator
			//turretInfoType="RscOptics_MBT_03_gunner";			//white with turret direction indicator
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					//#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_commander.hpp"
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
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";		//cam
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";	//MG
							//gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";		//MG better

							minAngleX=-30;
							maxAngleX=30;
							minAngleY=-100;
							maxAngleY=100;

							initFov=0.9;
							minFov=0.02;
							maxFov=0.9;
						};
					};
					turretInfoType="RscOptics_MBT_03_gunner";			//white with turret direction indicator
					//turretInfoType="RscOptics_APC_Wheeled_03_gunner";	//white with turret direction indicator
				};

				/*
				class AdvisorOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\AdvisorOptics.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner.hpp"

					gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					turretInfoType="RscOptics_APC_Wheeled_01_gunner";

					class OpticsIn
					{
						class Gun1
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";

							minAngleX=-30;	//?
							maxAngleX=30;	//?
							minAngleY=-100;	//?
							maxAngleY=100;	//?

							initFov=0.4;
							minFov=0.4;
							maxFov=0.4;
						};
						class Gun2: Gun1
						{
							initFov=0.1;
							minFov=0.1;
							maxFov=0.1;
						};
						class Gun3: Gun1
						{
							initFov=0.02;
							minFov=0.02;
							maxFov=0.02;
						};

						class Com1: Gun1
						{
							camPos="commanderview";
							//camDir="commanderview_dir";
							gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";

							initFov=0.5;
							minFov=0.5;
							maxFov=0.5;
						};
						class Com2: Com1
						{
							initFov=0.1;
							minFov=0.1;
							maxFov=0.1;
						};
						class Com3: Com1
						{
							initFov=0.02;
							minFov=0.02;
							maxFov=0.02;
						};
					};
				};
				*/
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot
		{
			source="ammorandom";
			weapon="RC_?0mm";
		};
		class muzzle_hide
		{
			source="reload";
			weapon="RC_?0mm";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_?0mm";
		};
		/*
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_IFV_Missile_Launcher";
		};
		class Missiles_reloadMagazine: Missiles_revolving
		{
			source="reloadMagazine";
		};
		*/
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showSLATTurret: showSLATTurret
		{
			initPhase=1;
		};
	};

	class TextureSources: TextureSources
	{
		class woodland: woodland
		{
			displayName="Woodland";
			textures[]=
			{
				"a3\armor_f\data\camonet_green_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class arid: arid
		{
			displayName="Arid";
			textures[]=
			{
				"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
	};

	hiddenSelectionsTextures[]=
	{
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa",
	};
	textureList[]=
	{
		"arid",
		1
	};
};
class RC_AFV_A_B: RC_AFV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_?_?mm_R.hpp"

			/*
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_?_?mm_R.hpp"
				};
			};
			*/
		};
	};
};
class RC_AFV_A_O: RC_AFV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_?_?mm_G.hpp"

			/*
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_?_?mm_R.hpp"
				};
			};
			*/
		};
	};
};
class RC_AFV_A_I: RC_AFV_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_?_?mm_Y.hpp"

			/*
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_?_?mm_R.hpp"
				};
			};
			*/
		};
	};
};


class RC_AFV_WD_B: RC_AFV_A_B
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f\data\camonet_green_co.paa"
	};
	textureList[]=
	{
		"woodland",
		1
	};
};
class RC_AFV_WD_O: RC_AFV_A_O
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f\data\camonet_green_co.paa"
	};
	textureList[]=
	{
		"woodland",
		1
	};
};
class RC_AFV_WD_I: RC_AFV_A_I
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\armor_f\data\camonet_green_co.paa"
	};
	textureList[]=
	{
		"woodland",
		1
	};
};