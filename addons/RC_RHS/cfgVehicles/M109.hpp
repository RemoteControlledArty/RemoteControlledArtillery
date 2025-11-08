class rhsusf_M109d_usarmy;
class RC_M109_base: rhsusf_M109d_usarmy
{
	class AnimationSources;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class OpticsIn;
	class ViewOptics;
	class Wide;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=2;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=6;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_M109_A: RC_M109_base
{
	class EventHandlers: EventHandlers
	{
		class RHSUSF_EventHandlers
		{
			postInit = "_this call rhs_fnc_reapplyTextures";
		};
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		/*
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\DriverControlsEH_ICV.hpp"
		};
		*/
		/*
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
		*/
	};

	author="Ascent";
	displayName="RC M109 155mm";
	faction="RemoteControlled_B";
	//editorSubcategory="RC_RHS_D_subcat";
	editorSubcategory="RC_Howitzer_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	crew="B_UAV_AI";
	uavCameraDriverPos="driverview";
	uavCameraDriverDir="driverview";
	uavCameraGunnerPos="gunnerview";
	uavCameraGunnerDir="gunnerview";

	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

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
					typeRecognitionDistance=45000;

					class AirTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=45000;
						maxRange=45000;
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
		class recoil_source
		{
			source="reload";
			weapon="RC_155mm_AMOS_V4";
		};
		class muzzle_hide_arty
		{
			source="reload";
			weapon="RC_155mm_AMOS_V4";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment2";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			maxElev=87;
			lockWhenVehicleSpeed=-1;
			stabilizedInAxes=3;

			weapons[]=
			{
				"RC_155mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_15Rnd_155mm_Mo_shells",
				"RC_4Rnd_155mm_Mo_HEAB",
				"RC_5Rnd_155mm_Mo_MultiGuided",
				"RC_2Rnd_155mm_Mo_Cluster",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_9Rnd_155mm_Mo_AT_mine",
				"RC_9Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
			};

			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.125;
					minFov=0.0125;
					maxFov=0.89999998;

					visionMode[]=
					{
						"Normal",
						"NVG"
					};

					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					gunnerCompartments="Compartment3";
					commanding=1;
					dontCreateAI=1;

					class ViewOptics: ViewOptics
					{
						initFov=0.125;
						minFov=0.0125;
						maxFov=0.89999998;

						visionMode[]=
						{
							"Normal",
							"NVG"
						};
					};
					
					weapons[]=
					{
						//"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					magazines[]=
					{
						//"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
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
									range[]={30000,20000,10000,5000,2500,40000};
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
							range[]={30000,20000,10000,5000,2500,40000};
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
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_M109_WD: RC_M109_A
{
	//editorSubcategory="RC_RHS_WD_subcat";
	editorPreview = "rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_m109_usarmy.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_01_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_02_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_03_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_mesh_wd_ca.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_wheels_wd_co.paa"
	};
};
class RC_M109_A_O: RC_M109_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M109_WD_O: RC_M109_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M109_A_I: RC_M109_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_M109_WD_I: RC_M109_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_M109_LC_A: RC_M109_A
{
	displayName="RC M109 155mm LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_155mm_Mo_shells",
				"RC_3Rnd_155mm_Mo_HEAB",
				"RC_3Rnd_155mm_Mo_MultiGuided",
				//"RC_2Rnd_155mm_Mo_Cluster",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_4Rnd_155mm_Mo_AT_mine",
				"RC_4Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
			};
		};
	};
};
class RC_M109_LC_WD: RC_M109_LC_A
{
	//editorSubcategory="RC_RHS_WD_subcat";
	editorPreview = "rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_m109_usarmy.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_01_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_02_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_03_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_mesh_wd_ca.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_wheels_wd_co.paa"
	};
};
class RC_M109_LC_A_O: RC_M109_LC_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M109_LC_WD_O: RC_M109_LC_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M109_LC_A_I: RC_M109_LC_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_M109_LC_WD_I: RC_M109_LC_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_M108_A: RC_M109_A
{
	displayName="RC M108 105mm";

	class Components: Components
	{
		class SensorsManagerComponent: SensorsManagerComponent
		{
			class Components: Components
			{
				class DataLinkSensorComponent: DataLinkSensorComponent
				{
					typeRecognitionDistance=20000;

					class AirTarget
					{
						minRange=20000;
						maxRange=20000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=20000;
						maxRange=20000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class recoil_source
		{
			source="reload";
			weapon="RC_105mm_AMOS_V4";
		};
		class muzzle_hide_arty
		{
			source="reload";
			weapon="RC_105mm_AMOS_V4";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_105mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_15Rnd_105mm_Mo_shells",
				"RC_4Rnd_105mm_Mo_HEAB",
				"RC_5Rnd_105mm_Mo_MultiGuided",
				"RC_2Rnd_105mm_Mo_Cluster",
				"RC_20Rnd_105mm_Mo_Smoke",
				"RC_9Rnd_105mm_Mo_AT_mine",
				"RC_9Rnd_105mm_Mo_mine",
				"RC_6Rnd_105mm_Mo_Illum"
			};

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsDisplayManagerComponentRight
				{
					class Components: Components
					{
						class SensorDisplay: SensorDisplay
						{
							range[]={16000,8000,4000,2000,1000};
						};
					};
				};
			};
		};
	};
};


class RC_M108_WD: RC_M108_A
{
	//editorSubcategory="RC_RHS_WD_subcat";
	editorPreview = "rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_m109_usarmy.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_01_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_02_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_03_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_mesh_wd_ca.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_wheels_wd_co.paa"
	};
};
class RC_M108_A_O: RC_M108_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M108_WD_O: RC_M108_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M108_A_I: RC_M108_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_M108_WD_I: RC_M108_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_M108_LC_A: RC_M108_A
{
	displayName="RC M108 105mm LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_105mm_Mo_shells",
				"RC_3Rnd_105mm_Mo_HEAB",
				"RC_3Rnd_105mm_Mo_MultiGuided",
				//"RC_2Rnd_105mm_Mo_Cluster",
				"RC_20Rnd_105mm_Mo_Smoke",
				"RC_4Rnd_105mm_Mo_AT_mine",
				"RC_4Rnd_105mm_Mo_mine",
				"RC_6Rnd_105mm_Mo_Illum"
			};
		};
	};
};
class RC_M108_LC_WD: RC_M108_LC_A
{
	//editorSubcategory="RC_RHS_WD_subcat";
	editorPreview = "rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_m109_usarmy.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_01_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_02_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_03_wd_co.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_mesh_wd_ca.paa",
		"rhsusf\addons\rhsusf_m109\data\rhsusf_m109a6_wheels_wd_co.paa"
	};
};
class RC_M108_LC_A_O: RC_M108_LC_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M108_LC_WD_O: RC_M108_LC_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_M108_LC_A_I: RC_M108_LC_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_M108_LC_WD_I: RC_M108_LC_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};