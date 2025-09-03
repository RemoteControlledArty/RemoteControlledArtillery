class qav_abramsx_templar;
class RC_AbramsX_Twin_Core: qav_abramsx_templar
{
	#include "\RC_AbramsX\cfgVehicles\fetch_include.hpp"
};
class RC_AbramsX_Twin_Base: RC_AbramsX_Twin_Core
{
	#include "\RC_AbramsX\cfgVehicles\main_include.hpp"
};
class RC_AbramsX_Twin_WD: RC_AbramsX_Twin_Base
{
	displayName="AbramsY";
	crew="B_UAV_AI";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	magazines[]=
	{
		"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		"RC_1Rnd_APS_M",
		
		"qav_SmokeLauncherMag",
		"qav_SmokeLauncherMag"
	};

	class AnimationSources: AnimationSources
	{
		class commandergun_recoil
		{
			source="reload";
			weapon="RC_AbramsX_30mm_M914_twin";
		};
		class commandergun_recoil_2
		{
			source="reload";
			weapon="RC_AbramsX_30mm_M914_twin";
		};
		class zasleh3_hide
		{
			source="reload";
			weapon="RC_AbramsX_30mm_M914_twin";
		};
		class zasleh4_hide
		{
			source="reload";
			weapon="RC_AbramsX_30mm_M914_twin";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_AbramsX_120mm_M360",
				"RC_AbramsX_20mm_coax",
				"qav_SmokeLauncher"
			};
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunnertwin_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					weapons[]=
					{
						"RC_AbramsX_30mm_M914_twin",
						"Laserdesignator_mounted",
						"qav_SmokeLauncher"
					};
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_comtwin_red.hpp"
				};
			};
		};
	};
};
class RC_AbramsX_Twin_WD_O: RC_AbramsX_Twin_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunnertwin_green.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_comtwin_green.hpp"
				};
			};
		};
	};
};
class RC_AbramsX_Twin_WD_I: RC_AbramsX_Twin_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunnertwin_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_comtwin_yellow.hpp"
				};
			};
		};
	};
};


class RC_AbramsX_Twin_A: RC_AbramsX_Twin_WD
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
class RC_AbramsX_Twin_A_O: RC_AbramsX_Twin_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunnertwin_green.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_comtwin_green.hpp"
				};
			};
		};
	};
};
class RC_AbramsX_Twin_A_I: RC_AbramsX_Twin_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_gunnertwin_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\RC_AbramsX\includes_vicmags\mags_AbramsX_comtwin_yellow.hpp"
				};
			};
		};
	};
};