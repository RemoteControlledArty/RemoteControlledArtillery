class BWA3_Panzerhaubitze2000_Fleck;
class RC_PzH2000_Fetch: BWA3_Panzerhaubitze2000_Fleck
{
	class AnimationSources;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class LoaderTurret;
	class ViewOptics;
	class OpticsIn;
	class Wide;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_validTurret[]={0}; //turret array pos in class turrets
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=2.3;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=7.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
    ace_artillerytables_showGunLaying=0;
    ace_artillerytables_applyCorrections=0; //prevents ace air resistance completely messing up the calculatable firing soltion
	//ace_artillerytables_showRangetable=1;
};
class RC_PzH2000_Core: RC_PzH2000_Fetch
{
	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	displayName="RC PzH 2000";
	editorSubcategory="RC_BW_subcat";

	uavCameraDriverPos="driverview";
	uavCameraDriverDir="driverview";
	uavCameraGunnerPos="gunnerview";
	uavCameraGunnerDir="gunnerview";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;

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
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class recoil_source
		{
			source="reload";
			weapon="RC_155mm_AMOS_PzH";
		};
		class mainGun_reload
		{
			source="reload";
			weapon="RC_155mm_AMOS_PzH";
		};
		class muzzle_hide_arty
		{
			source="reload";
			weapon="RC_155mm_AMOS_PzH";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			#include "\RC_BW\includes_cfg\PzH2000_DisplayComponents.hpp"
			turretInfoType="RscWeaponRangeArtilleryAuto";
			gunnerCompartments="Compartment2";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			maxElev=87;
			stabilizedInAxes=3;

			maxHorizontalRotSpeed=0.78;	 //0.5 was too slow, 0.78 of sholef is decent
			maxVerticalRotSpeed=0.26;

			weapons[]=
			{
				"RC_155mm_AMOS_PzH"
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

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";

					initFov=0.9;
					minFov=0.0125;
					maxFov=0.9;
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					#include "\RC_BW\includes_cfg\PzH2000_DisplayComponents.hpp"
					turretInfoType="RscOptics_Strider_commander";
					gunnerCompartments="Compartment3";
					commanding=1;
					dontCreateAI=1;
					stabilizedInAxes=3;

					/*
					//laser direction bugs
					weapons[]=
					{
						"RC_Laserdesignator_vehicle",
						"BWA3_SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries",
						"BWA3_SmokeLauncherMag",
						"BWA3_SmokeLauncherMag"
					};
					*/

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

					class OpticsIn
					{
						class Wide
						{
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNV.hpp"
							#include "\Remote_Controlled_Artillery\includes_cfg\OpticsAngles_X30_Y100.hpp"
							gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Optics_Commander_01_F.p3d";

							initFov=0.9;
							minFov=0.0125;
							maxFov=0.9;
						};
					};
				};
				class LoaderTurret: LoaderTurret
				{
					//#include "\RC_BW\includes_cfg\PzH2000_DisplayComponents.hpp"
					gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Optics_Commander_01_F.p3d";
					turretInfoType="RscOptics_Strider_commander";
					gunnerCompartments="Compartment3";
					gunnerName="Loader";
					dontCreateAI=1;

					class ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.9;
						minFov=0.0125;
						maxFov=0.9;
						minMoveX=0;
						maxMoveX=0;
						minMoveY=0;
						maxMoveY=0;
						minMoveZ=0;
						maxMoveZ=0;
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
					};
				};
			};
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_PzH2000_Base: RC_PzH2000_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Sensor_400m.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\GuidedTriggerTime.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\ETA.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cargo.hpp"
	};
};


class RC_PzH2000_FT: RC_PzH2000_Base
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_PzH2000_FT_O: RC_PzH2000_FT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_PzH2000_FT_I: RC_PzH2000_FT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_PzH2000_LC_FT: RC_PzH2000_FT
{
	displayName="RC PzH 2000 LowCap";

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
class RC_PzH2000_LC_FT_O: RC_PzH2000_LC_FT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_PzH2000_LC_FT_I: RC_PzH2000_LC_FT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_PzH2000_TT: RC_PzH2000_FT
{
	editorPreview="\bwa3_pzh2000\editorpreview\BWA3_Panzerhaubitze2000_Tropen.jpg";
	textureList[]=
	{
		"Tropen1",
		1
	};
};
class RC_PzH2000_TT_O: RC_PzH2000_TT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_PzH2000_TT_I: RC_PzH2000_TT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_PzH2000_LC_TT: RC_PzH2000_TT
{
	displayName="PzH 2000 LowCap";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_155mm_Mo_shells",
				"RC_3Rnd_155mm_Mo_HEAB",
				"RC_3Rnd_155mm_Mo_MultiGuided",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_4Rnd_155mm_Mo_AT_mine",
				"RC_4Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
			};
		};
	};
};
class RC_PzH2000_LC_TT_O: RC_PzH2000_LC_TT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_PzH2000_LC_TT_I: RC_PzH2000_LC_TT
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};