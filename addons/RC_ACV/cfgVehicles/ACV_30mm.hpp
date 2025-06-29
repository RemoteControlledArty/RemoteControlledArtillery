class ACV_30;
class RC_ACV_30_Core: ACV_30
{
	class Turrets;
	class MainTurret;
	class Commander;
	class CargoTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_04;
	class CargoTurret_05;
	class CargoTurret_06;
	class CargoTurret_07;
	class HitPoints;
	//class HitHull;
	//class HitEngine;
	//class HitFuel;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class AnimationSources;
	//class showCamonetHull;
	//class showCamonetCannon;
	//class showCamonetTurret;
	//class showSLATHull;
	//class showSLATTurret;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_ACV_30_Base: RC_ACV_30_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	lockDetectionSystem="2+4+8";

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
	maxSpeed=120;					//110
	normalSpeedForwardCoef=0.64;	//0.52;
	enginePower=600;				//506.25
	peakTorque=3000;				//2825

	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;

	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher_ACV"
	};
	magazines[]=
	{
		"SmokeLauncherMag_ACV",
		"SmokeLauncherMag_ACV"
	};
	
	class HitPoints: HitPoints
	{
		/*
		class HitHull: HitHull
		{
			armor=2;
		};
		class HitEngine: HitEngine
		{
			armor=1.25;
		};
		*/
		#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
	};

	class AnimationSources: AnimationSources
	{
		/*
		class Smoke_source
		{
			source="revolving";
			weapon="SmokeLauncher_ACV";
		};
		*/
		class crow_flash
		{
			source="ammorandom";
			weapon="RC_HMG_M2_ACV";
		};
		class 30_flash
		{
			source="ammorandom";
			weapon="RC_autocannon_30mm_ACV";
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};

class RC_ACV_30: RC_ACV_30_Base
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

	class UserActions
	{
		delete Commander_Cam_Turret;
	};

	displayName="ACV-30";
	editorSubcategory="RC_IFV_APC_subcat";
	scope=2;
	scopeCurator=2;
	crew="B_UAV_AI";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=3;
			minElev=-27;
			maxElev=80;
			stabilizedInAxes=3;	//somehow doesnt work, not even 4

			weapons[]=
			{
				"RC_autocannon_30mm_ACV",
				"RC_HMG_M2_ACV",
				"SmokeLauncher_ACV"
			};
			#include "\RC_ACV\includes_vicmags\mags_ACV_30mm_red.hpp"

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
				class Commander: Commander
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=2;
					turretInfoType="RscOptics_MBT_03_gunner";
					//turretInfoType="RscOptics_APC_Wheeled_03_commander";	//green

					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher_ACV"
					};
					magazines[]=
					{
						"Laserbatteries",
						"SmokeLauncherMag_ACV",
						"SmokeLauncherMag_ACV"
					};

					class OpticsIn
					{
						class Wide: RCWSOptics
						{
							//directionStabilized=1;	//unfortunately causes spinning camera bug

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
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_w_F.p3d";	//green
							gunnerOpticsEffect[]={};
						};
					};
				};
			};
		};
		/*
		class Commandercamera: NewTurret
		{
			gunnerName="Commander Camera";
			memoryPointsGetInGunner="pos_gunner_getin";
			memoryPointsGetInGunnerDir="pos_gunner_getin_dir";
			dontCreateAI=1;
			hasGunner=0;
			proxyIndex=1;
			forceHideGunner=1;
			gunnerForceOptics=1;
			gunnerOutForceOptics=1;
			gunnerAction="ACV_Commander";
			gunnerInAction="ACV_Commander";
			LODTurnedIn=1000;
			LODTurnedOut=1200;
			LODOpticsIn=1200;
			LODOpticsOut=1200;
			weapons[]=
			{
				"Laserdesignator_mounted"
			};
			magazines[]=
			{
				"Laserbatteries"
			};
			gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
			gunnerOutOpticsModel="";
			gunnerOpticsEffect[]={};
			gunnerGetOutAction="GetOutLow";
			gunnerCompartments="compartment2";
			body="commander_camera_y";
			gun="commander_camera_x";
			memoryPointGun="commander_pip_dir";
			gunBeg="commander_pip_dir";
			gunEnd="commander_pip_pov";
			animationSourceElevation="CamElevation";
			animationSourceBody="commander_camera_y";
			animationSourceGun="commander_camera_x";
			memoryPointGunnerOutOptics="commander_pip_pov";
			memoryPointGunnerOptics="commander_pip_pov";
			turretInfoType="RscOptics_MBT_01_commander";
			class OpticsIn: Optics_Commander_01
			{
				class Widev: Wide
				{
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
				};
				class Mediumv: Medium
				{
				};
				class Narrowv: Narrow
				{
				};
			};
			class HitPoints
			{
				class HitCommandercameraTurret
				{
					armor=0.5;
					material=-1;
					armorComponent="hit_commander_camera";
					name="hit_commander_camera";
					visual="Commander_camera";
					passThrough=0;
					minimalHit=0.050000001;
					explosionShielding=1;
					radius=0.15000001;
					isTurret=1;
				};
			};
		};
		*/
		delete Commandercamera;
		class CargoTurret_03: CargoTurret
		{
			class ViewOptics
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
			class HitPoints
			{
				class HitCommandercameraTurret
				{
					armor=0.5;
					material=-1;
					armorComponent="hit_commander_camera";
					name="hit_commander_camera";
					visual="Commander_camera";
					passThrough=0;
					minimalHit=0.050000001;
					explosionShielding=1;
					radius=0.15000001;
					isTurret=1;
				};
			};

			primaryGunner=0;
			primaryObserver=1;

			//memoryPointsGetInGunner="pos_gunner_getin";
			//memoryPointsGetInGunnerDir="pos_gunner_getin_dir";
			dontCreateAI=1;
			hasGunner=0;
			//proxyIndex=1;
			//forceHideGunner=1;
			gunnerOutForceOptics=0;	//1
			//gunnerAction="ACV_Commander";
			//gunnerInAction="ACV_Commander";
			gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
			gunnerOutOpticsModel="";
			gunnerOpticsEffect[]={};
			body="commander_camera_y";
			gun="commander_camera_x";
			memoryPointGun="commander_pip_dir";
			gunBeg="commander_pip_dir";
			gunEnd="commander_pip_pov";
			animationSourceElevation="CamElevation";
			animationSourceBody="commander_camera_y";
			animationSourceGun="commander_camera_x";
			memoryPointGunnerOutOptics="commander_pip_pov";
			memoryPointGunnerOptics="commander_pip_pov";
			turretInfoType="RscOptics_MBT_01_commander";

			gunnerName="Troop Commander";
			gunnerGetInAction="GetInAMV_cargo";
			gunnerGetOutAction="GetOutLOW";
			gunnerCompartments="Compartment1";
			gunnerInAction="ACV_Squad_Leader";
			gunnerAction="ACV_Squad_Leader";
			memoryPointsGetInGunner="pos_cargo_getin";
			memoryPointsGetInGunnerDir="pos_cargo_getin_dir";
			hideWeaponsGunner=1;
			LODTurnedIn=1200;
			LODTurnedOut=1200;
			LODOpticsIn=1200;
			LODOpticsOut=1200;
			showAsCargo=1;
			inGunnerMayFire=0;
			outGunnerMayFire=0;
			canHideGunner=0;
			proxyIndex=12;
			viewGunnerInExternal=1;
			isPersonTurret=1;
			commanding=2;
			gunnerForceOptics=0;
		};
		class CargoTurret_01: CargoTurret_01 {};
		class CargoTurret_02: CargoTurret_02 {};
		class CargoTurret_04: CargoTurret_04 {};
		class CargoTurret_05: CargoTurret_05 {};
		class CargoTurret_06: CargoTurret_06 {};
		class CargoTurret_07: CargoTurret_07 {};
	};
};
class RC_ACV_30_O: RC_ACV_30
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_ACV\includes_vicmags\mags_ACV_30mm_green.hpp"
		};
	};
};
class RC_ACV_30_I: RC_ACV_30
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_ACV\includes_vicmags\mags_ACV_30mm_yellow.hpp"
		};
	};
};


class RC_ACV_40: RC_ACV_30
{
	displayName="ACV-40";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_40mm_ACV",
				"RC_HMG_M2_ACV",
				"SmokeLauncher_ACV"
			};
			#include "\RC_ACV\includes_vicmags\mags_ACV_40mm_red.hpp"
		};
	};
};
class RC_ACV_40_O: RC_ACV_40
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_ACV\includes_vicmags\mags_ACV_40mm_green.hpp"
		};
	};
};
class RC_ACV_40_I: RC_ACV_40
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_ACV\includes_vicmags\mags_ACV_40mm_yellow.hpp"
		};
	};
};


/*
class RC_ACV_30_WD: RC_ACV_30
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		//inster when available
	};
};
class RC_ACV_30_WD_O: RC_ACV_30_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_ACV\includes_vicmags\mags_ACV_30mm_green.hpp"
		};
	};
};
class RC_ACV_30_WD_I: RC_ACV_30_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_ACV\includes_vicmags\mags_ACV_30mm_yellow.hpp"
		};
	};
};
*/