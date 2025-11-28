class qav_abramsx;
class RC_AbramsX_Core: qav_abramsx
{
	#include "\RC_AbramsX\cfgVehicles\fetch_include.hpp"
};
class RC_AbramsX_Base: RC_AbramsX_Core
{
	#include "\RC_AbramsX\cfgVehicles\main_include.hpp"
};
class RC_AbramsX_WD: RC_AbramsX_Base
{
	displayName="AbramsX";
	crew="B_UAV_AI";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	magazines[]=
	{
		//"RC_1Rnd_APS_M",
		//"RC_1Rnd_APS_M",
		
		"qav_SmokeLauncherMag",
		"qav_SmokeLauncherMag"
	};

	class AnimationSources: AnimationSources
	{
		class zasleh3_hide
		{
			source="reload";
			weapon="RC_AbramsX_30mm_M914";
		};
		class commandergun_recoil
		{
			source="reload";
			weapon="RC_AbramsX_30mm_M914";
		};
		class revolving_cannon
		{
			source="revolving";
			weapon="RC_AbramsX_30mm_M914";
		};
		class zasleh2_rot
		{
			source="ammorandom";
			weapon="RC_AbramsX_HMG_coax";
		};
		class zasleh2_hide
		{
			source="reload";
			weapon="RC_AbramsX_HMG_coax";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_AbramsX_120mm_M360",
				"RC_AbramsX_HMG_coax",
				"qav_SmokeLauncher"
			};
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunner_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					weapons[]=
					{
						"RC_AbramsX_30mm_M914",
						"Laserdesignator_mounted",
						"qav_SmokeLauncher"
					};
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_com_red.hpp"
				};

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
			};
		};
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


class RC_AbramsX_A: RC_AbramsX_WD
{
	hiddenSelectionsTextures[]=
	{
		"QAV_AbramsX\data\textures\AbramsX\AbramsX_Hull_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};
	textureList[]=
	{
		"arid",
		1
	};
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