class qav_abramsx;
class RC_AbramsX_Fetch: qav_abramsx
{
	#include "\RC_AbramsX\cfgVehicles\fetch_include.hpp"
};
class RC_AbramsX_Core: RC_AbramsX_Fetch
{
	#include "\RC_AbramsX\cfgVehicles\main_include.hpp"
};
class RC_AbramsX_Core2: RC_AbramsX_Core
{
	displayName="AbramsX";

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

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};
class RC_AbramsX_Base: RC_AbramsX_Core2
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Sensor_400m.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\DriveControls_GunnerOrCommander.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cargo.hpp"
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
};


class RC_AbramsX_WD: RC_AbramsX_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

    #include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};
class RC_AbramsX_WD_O: RC_AbramsX_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
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

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};
class RC_AbramsX_WD_I: RC_AbramsX_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
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

				class AdvisorOptics: AdvisorOptics {};
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
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
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

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};
class RC_AbramsX_A_I: RC_AbramsX_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
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

				class AdvisorOptics: AdvisorOptics {};
			};
		};
	};
};