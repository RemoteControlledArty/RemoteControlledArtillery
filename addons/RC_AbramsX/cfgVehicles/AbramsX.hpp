class B_W_qav_abramsx;
class RC_AbramsX_Core: B_W_qav_abramsx
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class Components;
	class UserActions;
	class EventHandlers;
	class AnimationSources;
	class bashbar;
	class rubberskirts;
	class camonethull;
	class camonetturret;
	class TextureSources;
	class woodland;
	class desert;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_AbramsX_Base: RC_AbramsX_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_600m.hpp"
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

	faction="RemoteControlled_B";
	editorSubcategory="RC_MBT_subcat";
	author="Ascent";
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	/*
	maxSpeed=70;
	enginePower=1537.5;
	peakTorque=6250;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;
	*/
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet

	hiddenSelectionsTextures[]=
	{
		"QAV_AbramsX\data\textures\AbramsX\Woodland\AbramsX_Hull_co.paa",
		"a3\armor_f\data\camonet_green_co.paa"
	};
	
	class TextureSources: TextureSources
	{
		class woodland: woodland
		{
			displayName="Woodland";
			textures[]=
			{
				"QAV_AbramsX\data\textures\AbramsX\Woodland\AbramsX_Hull_co.paa",
				"A3\Armor_F\Data\camonet_nato_green_co.paa"
			};
		};
		class desert: desert
		{
			displayName="Desert";
			textures[]=
			{
				"QAV_AbramsX\data\textures\AbramsX\desert\AbramsX_Hull_co.paa",
				"A3\Armor_F\Data\camonet_NATO_Desert_CO.paa"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class zasleh1_rot
		{
			source="ammorandom";
			weapon="RC_cannon_120mm_M360";
		};
		class zasleh1_hide
		{
			source="reload";
			weapon="RC_cannon_120mm_M360";
		};
		class zasleh2_rot
		{
			source="ammorandom";
			weapon="RC_AbramsX_20mm_coax";
		};
		class zasleh2_hide
		{
			source="reload";
			weapon="RC_AbramsX_20mm_coax";
		};
		class zasleh3_hide
		{
			source="reload";
			weapon="RC_autocannon_30mm_M914";
		};
		class recoil_source
		{
			source="reload";
			weapon="RC_cannon_120mm_M360";
		};
		class commandergun_recoil
		{
			source="reload";
			weapon="RC_autocannon_30mm_M914";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_autocannon_30mm_M914";
		};
		class bashbar: bashbar
		{
			initPhase=1;
		};
		class rubberskirts: rubberskirts
		{
			initPhase=1;
		};
		class camonethull: camonethull
		{
			initPhase=1;
		};
		class camonetturret: camonetturret
		{
			initPhase=1;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_gunner_missile.hpp"
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			dontCreateAI=1;
			minElev=-11;
			commanding=2;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_cannon_120mm_M360",
				"RC_AbramsX_20mm_coax",
				//"RC_QAV_AbramsX_HMG_coax",
				"qav_SmokeLauncher"
			};
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_red.hpp"

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
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\cfgTakeControls.hpp"
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_FSV_commander.hpp"
					dontCreateAI=1;
					showAllTargets="2 + 4";
					commanding=1;
					turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_autocannon_30mm_M914",
						"Laserdesignator_mounted",
						"qav_SmokeLauncher"
					};
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_red.hpp"

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
			};
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};


class RC_AbramsX_A: RC_AbramsX_Base
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

	displayName="AbramsX";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	crew="B_UAV_AI";
};
class RC_AbramsX_A_O: RC_AbramsX_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_green.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_green.hpp"
				};
			};
		};
	};
};
class RC_AbramsX_A_I: RC_AbramsX_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_yellow.hpp"
				};
			};
		};
	};
};


class RC_AbramsX_WD: RC_AbramsX_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_tow_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\mbt_addons_olive_CO.paa",
		//"a3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_AbramsX_WD_O: RC_AbramsX_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_green.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_green.hpp"
				};
			};
		};
	};
};
class RC_AbramsX_WD_I: RC_AbramsX_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_yellow.hpp"
				};
			};
		};
	};
};