class rhs_2s1_tv;
class RC_2S1_Base: rhs_2s1_tv
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class LoaderOptics;
	class AnimationSources;
	class ViewOptics;
	//class ViewPilot;
	class OpticsIn;
	class Op5_37;
	class Wide;
	class Components;
	class textureSources;
	class standard_dirty;
	class standard;
	class sand;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	//artilleryScanner=1;
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL, 5 = not compatible with script that disables vanilla artillery computer
	RC_BarrelAGL=2.1;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=4;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_2S1: RC_2S1_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_GuidedTriggerTime
		{
			#include "\Remote_Controlled_Artillery\includes_script\GuidedTriggerTimeEH.hpp"
		};
		/*
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		*/
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
		class RHS_EventHandlers
		{
			fired="_this call RHS_fnc_2s1_ejection;";
			init="_this call rhs_fnc_2s1_init";
			killed="[_this # 0,'rhs_Wreck_2s1_turret_F',50] call rhs_fnc_turretBlow";
			postInit="_this call rhs_fnc_reapplyTextures";
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	uavCameraDriverPos="driverview";
	uavCameraDriverDir="driverview";
	uavCameraGunnerPos="op5_pos";
	uavCameraGunnerDir="op5_dir";
	
	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
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
	canUseScanners=1;

	maxSpeed=80;		//60
	//normalSpeedForwardCoef=0.64;
	enginePower=330;	//220
	peakTorque=1618.5;	//1079

	//smokeLauncherGrenadeCount=12;
	//smokeLauncherAngle=180;

	unitInfoType="RscUnitInfoArtillery";

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
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=25000;

					class AirTarget
					{
						minRange=25000;
						maxRange=25000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=25000;
						maxRange=25000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};

				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class reload_magazine_source
		{
			source="reloadMagazine";
			weapon="RC_122mm_AMOS_V4_2S1";
		};
		class reload_source
		{
			source="reload";
			weapon="RC_122mm_AMOS_V4_2S1";
		};
	};

	class textureSources: textureSources
	{
		class standard_dirty: standard_dirty
		{
			factions[]={};
		};
		class standard: standard
		{
			factions[]={};
		};
		class sand: sand
		{
			factions[]={};
		};
	};
	/*
	hiddenSelectionsTextures[]=
	{
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_hull_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_turret_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa",
		"rhsafrf\addons\rhs_2s1\data\rhs_2s1_dirty_suspension_co.paa"
	};
	*/
	textureList[]=
	{
		"standard_dirty",
		1
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};


class RC_2S1_WD: RC_2S1
{
	/*
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\initIFV.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_IFV.hpp"
		};
	};
	*/

	displayName="122 PSH 74";	//2S1
	editorSubcategory="RC_Howitzer_subcat";
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	crew="B_UAV_AI";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
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
							range[]={20000,10000,5000,2500};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
						*/
					};
				};
			};

			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			canUseScanners=1;
			commanding=3;
			turretInfoType="RscOptics_Offroad_01";
			//turretInfoType="RscWeaponRangeArtilleryAuto";
			gunnerForceOptics=1;
			forceHideGunner=1;
			lockWhenVehicleSpeed=-1;
			stabilizedInAxes=3;
			startEngine=0;
			maxElev=87;

			weapons[]=
			{
				"RC_122mm_AMOS_V4_2S1"
			};
			magazines[]=
			{
				"RC_15Rnd_122mm_Mo_shells",
				"RC_4Rnd_122mm_Mo_HEAB",
				"RC_5Rnd_122mm_Mo_MultiGuided",
				"RC_2Rnd_122mm_Mo_Cluster",
				"RC_20Rnd_122mm_Mo_Smoke",
				"RC_9Rnd_122mm_Mo_AT_mine",
				"RC_9Rnd_122mm_Mo_mine",
				"RC_6Rnd_122mm_Mo_Illum"
			};

			class OpticsIn: OpticsIn
			{
				class Op5_37: Op5_37
				{
					initFov=0.9;
					minFov=0.0125;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="\a3\Weapons_F_Tank\acc\reticle_SPG9.p3d";	//backup
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					canUseScanners=1;
					commanding=2;
					dontCreateAI=1;
					gunnerCompartments="Compartment3";
					//turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						//"SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries",
						//"SmokeLauncherMag",
						//"SmokeLauncherMag"
					};

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
									range[]={20000,10000,5000,2500};
									resource="RscCustomInfoSensors";
								};
							};
						};
						class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
						{
							defaultDisplay="UAVFeedDisplay";

							class Components
							{
								class UAVFeedDisplay
								{
									componentType="UAVFeedDisplayComponent";
								};
								class EmptyDisplay
								{
									componentType="EmptyDisplayComponent";
								};
								class MinimapDisplay
								{
									componentType="MinimapDisplayComponent";
									resource="RscCustomInfoMiniMap";
								};
							};
						};
					};

					class OpticsIn: OpticsIn
					{
						class Wide: Wide
						{
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
					};
				};

				class LoaderOptics: LoaderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					canUseScanners=1;
					//commanding=2;
					dontCreateAI=1;
					gunnerCompartments="Compartment3";
					//turretInfoType="RscOptics_MBT_03_gunner";

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
									range[]={20000,10000,5000,2500};
									resource="RscCustomInfoSensors";
								};
							};
						};
						class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
						{
							defaultDisplay="UAVFeedDisplay";

							class Components
							{
								class UAVFeedDisplay
								{
									componentType="UAVFeedDisplayComponent";
								};
								class EmptyDisplay
								{
									componentType="EmptyDisplayComponent";
								};
								class MinimapDisplay
								{
									componentType="MinimapDisplayComponent";
									resource="RscCustomInfoMiniMap";
								};
							};
						};
					};
				};
			};
		};
	};
};
class RC_2S1_WD_O: RC_2S1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_2S1_WD_I: RC_2S1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


/*
class RC_2S1_A: RC_2S1_WD
{
	hiddenSelectionsTextures[]=
	{

	};
};
class RC_2S1_A_O: RC_2S1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_2S1_A_I: RC_2S1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
*/


class RC_2S1_LC_WD: RC_2S1_WD
{
	displayName="122 PSH 74 LowCap";	//2S1
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_122mm_Mo_shells",
				"RC_3Rnd_122mm_Mo_HEAB",
				"RC_3Rnd_122mm_Mo_MultiGuided",
				"RC_2Rnd_122mm_Mo_Cluster",
				"RC_20Rnd_122mm_Mo_smoke",
				"RC_4Rnd_122mm_Mo_AT_mine",
				"RC_4Rnd_122mm_Mo_mine",
				"RC_6Rnd_122mm_Mo_Illum"
			};
		};
	};
};
class RC_2S1_LC_WD_O: RC_2S1_LC_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_2S1_LC_WD_I: RC_2S1_LC_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


/*
class RC_2S1_LC_A: RC_2S1_LC_WD
{
	hiddenSelectionsTextures[]=
	{
		
	};
};
class RC_2S1_LC_A_O: RC_2S1_LC_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_2S1_LC_A_I: RC_2S1_LC_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
*/