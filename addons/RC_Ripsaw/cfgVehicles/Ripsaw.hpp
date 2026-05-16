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

	//class HitPoints;

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
	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\EjectDeadCrew.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\faster_amphibious.hpp"
	//#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";

	//driverCompartments="Compartment2";
	commanding=1;
	crewCrashProtection=0;

	smokeLauncherGrenadeCount=6;
	smokeLauncherVelocity=8;
	smokeLauncherAngle=180;

	/*
	class HitPoints: HitPoints
	{
	};
	*/
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

	displayName="RC Ripsaw";
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
		//"RC_1Rnd_APS_M",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//dontCreateAI=1;
			commanding=3;

			//minElev=-;	//50
			//maxElev=;		//-10

			/*
			weapons[]=
			{
				"RC_AMV_HMG",
				"SmokeLauncher"
			};
			*/

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
			weapon="QAV_ripsaw_mk30";
		};
		class zasleh_hide
		{
			source="reload";
			weapon="QAV_ripsaw_mk30";
		};
		class zasleh_rot
		{
			source="ammorandom";
			weapon="QAV_ripsaw_mk30";
		};
		class zasleh2_hide
		{
			source="reload";
			weapon="lmg_coax";
		};
		class zasleh2_rot
		{
			source="ammorandom";
			weapon="lmg_coax";
		};
	};

	class TextureSources: TextureSources
	{
		class arid
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
			factions[]=
			{
				"RemoteControlled_B",
				"RemoteControlled_O",
				"RemoteControlled_I"
			};
		};
		class olive: arid
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
		};
		class ion: arid
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
		class ldf: arid
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
		class aaf: arid
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
		class ctrg: arid
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
		class black: arid
		{
			displayName="CTRG";
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
		class un: arid
		{
			displayName="CTRG";
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

	hiddenSelectionsTextures[]=
	{
		"QAV_Ripsaw\data\textures\texgreen\rshull_co.paa",
		"QAV_Ripsaw\data\textures\texgreen\rshull2_co.paa",
		"QAV_Ripsaw\data\textures\texgreen\rssusp_co.paa",
		"QAV_Ripsaw\data\textures\texgreen\rsturret_co.paa",
		"QAV_Ripsaw\data\textures\texgreen\rsturret2_co.paa",
		"QAV_Ripsaw\data\textures\texgreen\rsacc1_co.paa",
		"QAV_Ripsaw\data\textures\texgreen\rsacc2_co.paa"
	};
	textureList[]=
	{
		"olive",
		1
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
			//#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_R.hpp"
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
			//#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_G.hpp"
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
			//#include "\RC_Ripsaw\includes_vicmags\mags_Ripsaw_Y.hpp"
		};
	};
};


/*
class RC_Ripsaw_A_B: RC_Ripsaw_WD_B
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_WD.hpp"
};
class RC_Ripsaw_A_O: RC_Ripsaw_WD_O
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_WD.hpp"
};
class RC_Ripsaw_A_I: RC_Ripsaw_WD_I
{
	#include "\RC_Ripsaw\textures\Ripsaw_Texture_WD.hpp"
};
*/