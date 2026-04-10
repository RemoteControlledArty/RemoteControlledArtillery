class I_MBT_03_cannon_F;
class RC_MBT_2_Base: I_MBT_03_cannon_F
{
	class Turrets;
	class NewTurret; //test
	class CargoTurret; //test
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
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext01_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_ext02_co.paa",
		"a3\armor_f_epb\mbt_03\data\mbt_03_rcws_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};

	/*
	class CargoTurret: CargoTurret
	{
		memoryPointGunnerOptics = "gunnerview";
		gunnerCompartments="Compartment1";
		turretInfoType = "";
		dontCreateAI = 1;

		gunnerForceOptics = 1;
		isPersonTurret = 1;
		playerPosition = 1;

		primaryGunner = 0;
		primaryObserver = 0;
		showAsCargo = 1;
		startEngine = 0;
		
		//class TurnIn
		//class TurnOut
		//class Turrets
		//class TurretSpec

		class ViewGunner
		{
			initAngleX = 0;
			initAngleY = 0;
			initFov = 0.3;
			maxAngleX = 30;	
			maxAngleY = 100;
			maxFov = 0.35;		
			maxMoveX = 0;
			maxMoveY = 0;
			maxMoveZ = 0;
			minAngleX = -30;
			minAngleY = -100;
			minFov = 0.07;
			minMoveX = 0;
			minMoveY = 0;
			minMoveZ = 0;
			speedZoomMaxFOV = 0;
			speedZoomMaxSpeed = 1e+10;

			visionMode[]=
			{
				"Normal",
				"TI"
			};
			thermalMode[]={0};
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
			gunnerOpticsEffect[]={};
		};
		class ViewOptics
		{
			initAngleX = 0;
			initAngleY = 0;
			initFov = 0.3;
			maxAngleX = 30;	
			maxAngleY = 100;
			maxFov = 0.35;		
			maxMoveX = 0;
			maxMoveY = 0;
			maxMoveZ = 0;
			minAngleX = -30;
			minAngleY = -100;
			minFov = 0.07;
			minMoveX = 0;
			minMoveY = 0;
			minMoveZ = 0;
			speedZoomMaxFOV = 0;
			speedZoomMaxSpeed = 1e+10;

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
	*/

	/*
	//UAV Operator seat test
	hideWeaponsCargo=1;
	cargoIsCoDriver[]={0};
	transportSoldier=1;

	memoryPointsGetInCargo = "pos cargo";
	memoryPointsGetInCargoDir = "pos cargo dir";
	memoryPointsGetInCargoPrecise[] = {"pos cargo"};
	cargoCompartments[] = {"Compartment1"};
	cargoGetInAction[] = {"GetInLow"};
	cargoGetOutAction[] = {"GetOutLow"};
	//cargoProxyIndexes[] = {};
	cargoAction[] = {"passenger_flatground_leanleft"};
	*/



	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			commanding=2;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";
			//turretInfoType="RscOptics_MBT_03_gunner";

			weapons[]=
			{
				"RC_cannon_120mm",
				"RC_MMG_338_MBT_coax",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_red.hpp"

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
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_01_m_F.p3d";
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_m_F.p3d";
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			
			class Turrets: Turrets
			{
				class AdvisorOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\AdvisorOptics.hpp"
				};

				
				/*
				class UavTurret: MainTurret
				{
					proxyType = "CPCargo";	//proxyType = "CPGunner";	//proxyType = "CPCommander";
					proxyIndex = 1;

					// 1. Tell the engine this seat accepts a human
					hasGunner = 1;
					dontCreateAI = 1; // Prevents AI from taking the seat
					//proxyIndex = 1;   // Links to 'proxy:cargo.001'
					
					// 2. This is the exact text that appears in the scroll wheel
					gunnerName = "UAV Operator"; 
					
					// 3. Prevent conflicts with the actual tank crew
					primaryGunner = 0;
					primaryObserver = 0;
					commanding = -1; // Stops this seat from taking control of AI
					
					// 4. Where does the player stand to see the action menu?
					// You MUST use memory points that actually exist on the tank's .p3d model.
					// If "pos gunner" is taken, try "pos cargo" or "pos driver".
					memoryPointsGetInGunner = "pos cargo"; 
					memoryPointsGetInGunnerDir = "pos cargo dir";

					memoryPointsGetInGunnerPrecise = "pos cargo";
					gunnerCompartments = "Compartment1";
					
					// 5. Interaction radius (how close you need to be)
					radius = 10; //5
					
					// 6. Animation state when sitting
					gunnerAction = "passenger_flatground_leanleft"; 
					gunnerInAction = "passenger_flatground_leanleft";
				};
				*/

				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_commander.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					dontCreateAI=1;
					commanding=1;
					turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_HMG_127_APC2",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_red.hpp"

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
				};

				/*
				class ObserverTurret : NewTurret {
					// --- 1. MANDATORY ENGINE LINK ---
					// We use the Gunner's optics point but "lock" the turret
					body = "";
					gun = "";
					animationSourceBody = "";
					animationSourceGun = "";
					
					// --- 2. THE ACCESS FIX ---
					gunnerName = "Observer Seat";
					hasGunner = 1;
					primaryGunner = 0;
					primaryObserver = 0;
					commanding = -1;
					proxyIndex = 7; // High index to avoid Kuma's internal proxies
					
					// Use Commander's entry points (often more reliable for sub-turrets)
					memoryPointsGetInGunner = "pos_commander";
					memoryPointsGetInGunnerDir = "pos_commander_dir";

					// --- 3. VISION & POSITION ---
					gunnerAction = "driver_closed";
					gunnerInAction = "driver_closed";
					forceHideGunner = 1;
					gunnerForceOptics = 1;
					// Ties the camera to the main gunner's view
					memoryPointGunnerOptics = "gunnerview"; 
					gunnerOpticsModel = "\A3\Weapons_F\Reticle\optics_empty.p3d";

					// --- 4. ENGINE STABILITY FLAGS ---
					// These flags help the engine accept a turret with no 3D proxy
					canHideGunner = -1;
					isPersonTurret = 0;
					showAsCargo = 0; 
					allowTabLock = 0;
					stopBinocular = 1;

					class ViewOptics {
						initAngleX = 0; minAngleX = 0; maxAngleX = 0;
						initAngleY = 0; minAngleY = 0; maxAngleY = 0;
						initFov = 0.7;  minFov = 0.25; maxFov = 1.25;
						visionMode[] = {"Normal", "NVG", "Ti"};
					};

					// Ensure no weapons conflict
					weapons[] = {};
					magazines[] = {};
				};
				*/

				/*
				// Now we add your custom seat
				class ObserverTurret : NewTurret {
					// 1. ENGINE & HIERARCHY
					body = "";
					gun = "";
					animationSourceBody = "";
					animationSourceGun = "";
					
					// 2. IDENTITY
					gunnerName = "Observer Seat"; 
					hasGunner = 1;
					primaryGunner = 0;
					primaryObserver = 0; 
					commanding = -1;
					dontCreateAI = 1; // Prevents AI from stealing the seat
					
					// 3. THE ENTRY FIX
					// These tell Arma to use the Gunner's "Get In" spots for this seat
					memoryPointsGetInGunner = "pos_gunner";
					memoryPointsGetInGunnerDir = "pos_gunner_dir";
					gunnerGetInAction = "GetInAMV";
					gunnerGetOutAction = "GetOutLow";

					// 4. CHARACTER SETUP
					proxyType = "CPGunner";
					proxyIndex = 3; // Index 1 is Gunner, Index 2 is Commander
					forceHideGunner = 1;
					castGunnerShadow = 0;
					viewGunnerInExternal = 0;
					gunnerAction = "driver_closed"; 
					gunnerInAction = "driver_closed";
					
					// 5. OPTICS (Fixed to Main Gun)
					memoryPointGunnerOptics = "gunnerview"; 
					gunnerOpticsModel = "\A3\Weapons_F\Reticle\optics_empty.p3d";
					gunnerForceOptics = 1; 
					usePip = 0;

					class ViewOptics {
						initAngleX = 0; minAngleX = 0; maxAngleX = 0;
						initAngleY = 0; minAngleY = 0; maxAngleY = 0;
						initFov = 0.7;  minFov = 0.25; maxFov = 1.25;
						visionMode[] = {"Normal", "NVG", "Ti"};
					};

					weapons[] = {};
					magazines[] = {};
				};
				*/

				/*
				// We keep the CommanderOptics (usually index 0 in sub-turrets)
				// and add our Observer as a secondary sub-turret.
				class ObserverTurret : NewTurret {
					// 1. ENGINE & HIERARCHY
					body = "";
					gun = "";
					animationSourceBody = "";
					animationSourceGun = "";
					
					// 2. IDENTITY & ACCESS
					gunnerName = "Observer Seat"; 
					hasGunner = 1;
					primaryGunner = 0;
					primaryObserver = 0; // Set to 0 to avoid stealing Commander's spotting UI
					commanding = -1;
					
					// 3. THE "PHANTOM" FIX
					// Use a high proxyIndex so it doesn't try to sit in the Gunner's lap
					proxyType = "CPGunner";
					proxyIndex = 10; 
					forceHideGunner = 1;
					castGunnerShadow = 0;
					viewGunnerInExternal = 0;
					
					// 4. OPTICS (Locked to Gunner)
					memoryPointGunnerOptics = "gunnerview"; 
					gunnerOpticsModel = "\A3\Weapons_F\Reticle\optics_empty.p3d";
					gunnerForceOptics = 1; 
					usePip = 0;

					// 5. LIMITS (Prevents the camera from 'detaching' from the gunner's view)
					minElev = -90; maxElev = 90;
					minTurn = -360; maxTurn = 360;
					initElev = 0; initTurn = 0;

					class ViewOptics {
						initAngleX = 0; minAngleX = 0; maxAngleX = 0;
						initAngleY = 0; minAngleY = 0; maxAngleY = 0;
						initFov = 0.7;  minFov = 0.25; maxFov = 1.25;
						visionMode[] = {"Normal", "NVG", "Ti"};
					};

					// Empty Weapons
					weapons[] = {};
					magazines[] = {};
				};
				*/


				/*
				class AdvisorOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_advisor.hpp"
					gunnername="UAV Operator";
					primaryObserver=0;
					commanding=-3;
					dontCreateAI=1;
					canUseScanners=1;

					weapons[]=
					{
						"RC_target_confirmer_datalink"
					};
					magazines[]=
					{
						"RC_target_confirmer_mag"
					};

					class HitPoints
					{
						class Hit_Optic_LoaderPeriscope
						{
							armor=-40;
							explosionShielding=0;
							name="";
							visual="vis_optic_LoaderPeriscope";
							armorComponent="Hit_Optic_LoaderPeriscope";
							passThrough=0;
						};
					};

					minTurn=360;	//-140
					maxTurn=360;	//140
					stabilizedInAxes=0;

					isPersonTurret=1;
					lockWhenDriverOut=0;
					lodTurnedOut=1200;
					gunnerAction="RHS_M1A1_Loader_out";
					gunnerInAction="RHS_M1A1_Loader_in";

					gunnerForceOptics=1;
					gunnerOutForceOptics=0;
					gunnerOutOpticsModel="\A3\weapons_f\reticle\optics_empty";
					inGunnerMayFire=1;
					outGunnerMayFire=1;

					memoryPointGun="usti hlavne5";
					gunBeg="usti hlavne5";
					gunEnd="konec hlavne5";
					selectionFireAnim="";
					soundAttenuationTurret="HeliAttenuationGunner";
					disableSoundAttenuation=0;

					animationSourceHatch="HatchGunner";
					animationSourceBody="LoaderVisorTurret";
					animationSourceGun="LoaderVisorGun";
					body="LoaderVisorTurret";
					gun="LoaderVisorGun";
					animationSourceStickX="";
					animationSourceStickY="";
				
					memoryPointsGetInGunner="pos gunner";
					memoryPointsGetInGunnerDir="pos gunner dir";
					memoryPointGunnerOptics="loadervisor_view";

					gunnerDoor="hatchL";
					proxyindex=2;

					soundServo[]=
					{
						"A3\sounds_f\dummysound",
						1e-006,
						1
					};

					class OpticsIn: OpticsIn
					{
						class Medium_TI: RCWSOptics
						{
							//mainturret memoryPointGunnerOptics="CITV_view";
							camPos="CITV_view";
							camDir="CITV_view_dir";

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
							//gunnerOpticsModel="\rhsusf\addons\rhsusf_m1a1\gunnerOptics_M1A2_2";
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
							gunnerOpticsEffect[]={};
							hitpoint="Hit_Optic_GPS_TI";
						};
					};
				};
				*/
			};
		};

		/*
		class UavTurret: MainTurret {
			// Essential FFV / CargoTurret flags
			isPersonTurret = 1; // Allows the "Internal" feel
			dontCreateAI = 1;   // Stops an AI from spawning in your operator seat
			proxyIndex = 1;     // Links to 'proxy:cargo.001' in the model
			
			// Viewpoint Fixes
			memoryPointGunnerOptics ="gunnerview"; // Use an existing model point
			gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_01_F"; // Adds a physical reticle
			
			// Disable weapon usage (so they don't fire the tank's main gun)
			weapons[] = {};
			magazines[] = {};

			// Immersion
			class ViewOptics {
				initAngleX = 0; minAngleX = -30; maxAngleX = 30;
				initAngleY = 0; minAngleY = -100; maxAngleY = 100;
				initFov = 0.75; minFov = 0.25; maxFov = 1.25;
				visionMode[] = {"Normal","NVG","Ti"};
				thermalMode[] = {0};
			};
		};
		*/

		/*
		class UavTurret: MainTurret
		{
			proxyType = "CPCargo";	//proxyType = "CPGunner";	//proxyType = "CPCommander";
			proxyIndex = 1;

			// 1. Tell the engine this seat accepts a human
			hasGunner = 1;
			dontCreateAI = 1; // Prevents AI from taking the seat
			//proxyIndex = 1;   // Links to 'proxy:cargo.001'
			
			// 2. This is the exact text that appears in the scroll wheel
			gunnerName = "UAV Operator"; 
			
			// 3. Prevent conflicts with the actual tank crew
			primaryGunner = 0;
			primaryObserver = 0;
			commanding = -1; // Stops this seat from taking control of AI
			
			// 4. Where does the player stand to see the action menu?
			// You MUST use memory points that actually exist on the tank's .p3d model.
			// If "pos gunner" is taken, try "pos cargo" or "pos driver".
			memoryPointsGetInGunner = "pos cargo"; 
			memoryPointsGetInGunnerDir = "pos cargo dir";

			memoryPointsGetInGunnerPrecise = "pos cargo";
			gunnerCompartments = "Compartment1";
			
			// 5. Interaction radius (how close you need to be)
			radius = 10; //5
			
			// 6. Animation state when sitting
			gunnerAction = "passenger_flatground_leanleft"; 
			gunnerInAction = "passenger_flatground_leanleft";
		};
		*/
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
			#include "\Remote_Controlled_Artillery\includes_script\initDL.hpp"
			//#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
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
			//#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	displayName="Leopard 2";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	crew="B_UAV_AI";
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_green.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_yellow.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_green.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_yellow.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_green.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_yellow.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_green.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_yellow.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_green.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_green.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
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
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Leopard_yellow.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_FSV_MBT_com_yellow.hpp"
				};

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};