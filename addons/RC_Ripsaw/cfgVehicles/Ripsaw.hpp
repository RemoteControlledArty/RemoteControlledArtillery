class qav_ripsaw_Mk44;
class RC_Ripsaw_Fetch: qav_ripsaw_Mk44
{
	class EventHandlers;
	class UserActions;
	class Components;

	class Turrets;
	class MainTurret;
	class ViewOptics;

	class AnimationSources;
	class TextureSources;

	class HitPoints;
	class HitEngine;
	class HitFuel;
	class HitHull;
	class HitLTrack;
	class HitRTrack;

	class steel_hull;
	class skirts;
	class steel_skirts;

	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Ripsaw_Core: RC_Ripsaw_Fetch
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
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4kmSensLight.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\EjectDeadCrew.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	lockDetectionSystem="2+4+8";
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	author="Ascent";

	//driverCompartments="Compartment2";
	commanding=1;
	crewCrashProtection=0;

	smokeLauncherGrenadeCount=6;
	smokeLauncherVelocity=8;
	smokeLauncherAngle=180;

	//armor=200;	//200 	//btr 280

	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor = -400;	//2*200=-400		//btr 1.6*280=-448
			explosionShielding = 0.2;
			minimalHit = 0.2;
			passThrough = 1;	//1
		};
		class HitEngine: HitEngine
		{
			armor = -105;	//-5	//btr 0.75*280=-210
			explosionShielding = 0.2;
			minimalHit = 0.1;
			passThrough = 0;
		};
		class HitFuel: HitFuel
		{
			armor = -105;	//0.5	//btr 0.75*280=-210
			explosionShielding = 0.6;
			minimalHit = 0.1;
			passThrough = 0;
		};
		class HitLTrack: HitLTrack
		{
			armor = -300;	//-250
			explosionShielding = 0.4;
			minimalHit = 0.08;
			passThrough = 0;
		};
		class HitRTrack: HitRTrack
		{
			armor = -300;	//-250
			explosionShielding = 0.4;
			minimalHit = 0.08;
			passThrough = 0;
		};
	};
};


class RC_Ripsaw_Base: RC_Ripsaw_Core
{
	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			//#include "\Remote_Controlled_Artillery\includes_script\GunnerOrCommanderIsDriverEH.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};
	
	#include "\Remote_Controlled_Artillery\includes_cfg\values_IFV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverViewOptics.hpp"
	//RC_ATrespondingTurret[]={0,0};

	displayName="RC Ripsaw U-FSV";
	editorSubcategory="RC_FSV_subcat";

	maxSpeed=110;		//110
	//normalSpeedForwardCoef=0.64;
	enginePower=750;	//550
	peakTorque=1125;	//900

	//armor=200;
	//armorStructural=5;

	weapons[]=
	{
		//"TruckHorn",
		"RC_APS_W",
		"QAV_SmokeLauncher"
	};
	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		//"RC_1Rnd_APS_M",
		"QAV_SmokeLauncherMag",
		"QAV_SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\cfgVehicles\includes_vehicle\panels_ripsaw.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//dontCreateAI=1;
			commanding=3;

			//minElev=;		//50
			//maxElev=;		//-10

			weapons[]=
			{
				"RC_Ripsaw_Mk30",
				"RC_Ripsaw_coax",
				"QAV_SmokeLauncher"
			};

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";

					//higher but cannot see hull orientation
					//camPos = "gunnerview2";
					//camDir = "gunnerview2_dir";

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
		};
	};

	class AnimationSources: AnimationSources
	{
		class 30mm_recoil
		{
			source="reload";
			weapon="RC_Ripsaw_Mk30";
		};
		class zasleh_hide
		{
			source="reload";
			weapon="RC_Ripsaw_Mk30";
		};
		class zasleh_rot
		{
			source="ammorandom";
			weapon="RC_Ripsaw_Mk30";
		};
		class zasleh2_hide
		{
			source="reload";
			weapon="RC_Ripsaw_coax";
		};
		class zasleh2_rot
		{
			source="ammorandom";
			weapon="RC_Ripsaw_coax";
		};

		class steel_hull: steel_hull
		{
			displayName="Hull Armor [250kg]";
			mass=250;
			initPhase=1;
		};
		class skirts: skirts
		{
			initPhase=1;
		};
		class steel_skirts: steel_skirts
		{
			displayName="Skirt Armor [500kg]";
			mass=500;
			initPhase=1;
		};
	};

	animationList[]=
	{
		"bashbar", 1,
		"steel_hull", 1,
		"skirts", 1,
		"steel_skirts", 1
	};

	class TextureSources: TextureSources
	{
		class olive
		{
			displayName="Olive";
			textures[]=
			{
				"QAV_Ripsaw\data\textures\texgreen\rshull_co.paa",
				"QAV_Ripsaw\data\textures\texgreen\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\texgreen\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\texgreen\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\texgreen\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\texgreen\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\texgreen\rsacc2_co.paa"
			};
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class arid: olive
		{
			displayName="Arid";
			textures[]=
			{
				"QAV_Ripsaw\data\textures\nato\rshull_co.paa",
				"QAV_Ripsaw\data\textures\nato\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\nato\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\nato\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\nato\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\nato\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\nato\rsacc2_co.paa"
			};
		};
		class ion: olive
		{
			displayName="Ion";
			textures[]=
			{
				"QAV_Ripsaw\data\textures\ion\rshull_co.paa",
				"QAV_Ripsaw\data\textures\ion\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\ion\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\ion\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\ion\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\ion\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\ion\rsacc2_co.paa"
			};
		};
		class ldf: olive
		{
			displayName="LDF";
			textures[]=
			{
				"QAV_Ripsaw\data\textures\ldf\rshull_co.paa",
				"QAV_Ripsaw\data\textures\ldf\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\ldf\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\ldf\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\ldf\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\ldf\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\ldf\rsacc2_co.paa"
			};
		};
		class aaf: olive
		{
			displayName="AAF";
			textures[]=
			{
				"QAV_Ripsaw\data\textures\aaf\rshull_co.paa",
				"QAV_Ripsaw\data\textures\aaf\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\aaf\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\aaf\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\aaf\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\aaf\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\aaf\rsacc2_co.paa"
			};
		};
		class ctrg: olive
		{
			displayName="CTRG";
			textures[]=
			{
				"QAV_Ripsaw\data\textures\ctrg\rshull_co.paa",
				"QAV_Ripsaw\data\textures\ctrg\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\ctrg\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\ctrg\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\ctrg\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\ctrg\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\ctrg\rsacc2_co.paa"
			};
		};
		class black: olive
		{
			displayName="Black";
			textures[]={
				"QAV_Ripsaw\data\textures\black\rshull_co.paa",
				"QAV_Ripsaw\data\textures\black\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\black\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\black\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\black\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\black\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\black\rsacc2_co.paa"
			};
		};
		class un: olive
		{
			displayName="UN";
			textures[]={
				"QAV_Ripsaw\data\textures\una\rshull_co.paa",
				"QAV_Ripsaw\data\textures\un\rshull2_co.paa",
				"QAV_Ripsaw\data\textures\una\rssusp_co.paa",
				"QAV_Ripsaw\data\textures\un\rsturret_co.paa",
				"QAV_Ripsaw\data\textures\una\rsturret2_co.paa",
				"QAV_Ripsaw\data\textures\una\rsacc1_co.paa",
				"QAV_Ripsaw\data\textures\una\rsacc2_co.paa"
			};
		};
	};
};


class RC_Ripsaw_WD_B: RC_Ripsaw_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_R.hpp"
		};
	};
};
class RC_Ripsaw_WD_O: RC_Ripsaw_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_G.hpp"
		};
	};
};
class RC_Ripsaw_WD_I: RC_Ripsaw_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_Y.hpp"
		};
	};
};


class RC_Ripsaw_A_B: RC_Ripsaw_WD_B
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_A.hpp"
};
class RC_Ripsaw_A_O: RC_Ripsaw_WD_O
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_A.hpp"
};
class RC_Ripsaw_A_I: RC_Ripsaw_WD_I
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_A.hpp"
};


class RC_Ripsaw_cUAS_Base: RC_Ripsaw_Base
{
	displayName="RC Ripsaw C-UAS";
	editorSubcategory="RC_AntiDrone_subcat";

	smokeLauncherGrenadeCount=6;
	smokeLauncherVelocity=4;
	smokeLauncherAngle=360;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\cfgVehicles\includes_vehicle\panels_ripsaw_cUAS.hpp"

			weapons[]=
			{
				"RC_Ripsaw_Mk30_cUAS",
				"RC_Ripsaw_coax",
				"QAV_SmokeLauncher"
			};

			class OpticsIn
			{
				class Wide
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";

					minAngleX=-30;
					maxAngleX=30;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
				};
			};
			turretInfoType="RscOptics_MBT_03_gunner";
		};
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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=3000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;
					angleRangeVertical=60;
					animDirection="mainGun";
				};
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=300;

					class AirTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=300;
						maxRange=300;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=15;
					angleRangeHorizontal=22.5;
					angleRangeVertical=22.5;
					animDirection="mainGun";
					aimDown=0;	//-0.5
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=600;

					class AirTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					//animDirection="mainGun";	//"" , "obsGun"
					animDirection="";
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class 30mm_recoil
		{
			source="reload";
			weapon="RC_Ripsaw_Mk30_cUAS";
		};
		class zasleh_hide
		{
			source="reload";
			weapon="RC_Ripsaw_Mk30_cUAS";
		};
		class zasleh_rot
		{
			source="ammorandom";
			weapon="RC_Ripsaw_Mk30_cUAS";
		};
	};
};
class RC_Ripsaw_cUAS_WD_B: RC_Ripsaw_cUAS_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_cUAS_R.hpp"
		};
	};
};
class RC_Ripsaw_cUAS_WD_O: RC_Ripsaw_cUAS_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_cUAS_G.hpp"
		};
	};
};
class RC_Ripsaw_cUAS_WD_I: RC_Ripsaw_cUAS_Base
{
	scope=2;
	scopeCurator=2;
	//forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_cUAS_Y.hpp"
		};
	};
};


class RC_Ripsaw_cUAS_A_B: RC_Ripsaw_cUAS_WD_B
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_A.hpp"
};
class RC_Ripsaw_cUAS_A_O: RC_Ripsaw_cUAS_WD_O
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_A.hpp"
};
class RC_Ripsaw_cUAS_A_I: RC_Ripsaw_cUAS_WD_I
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_A.hpp"
};