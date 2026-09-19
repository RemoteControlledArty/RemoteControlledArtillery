class RC_BMP3_old_Core: RC_BMP3_Core
{
	displayName="BMP-3 old";

	#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km_old.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\values_FSV.hpp"
	radartype=2;
	reportOwnPosition=1;
	laserScanner=1;
	lockDetectionSystem="2+4+8";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_gunner_noDriver_old.hpp"
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_red.hpp"

			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_noDriver_old.hpp"
				};
			};
		};
		class GPMGTurret1: GPMGTurret1
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_noDriver_old.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\panels_IFV_commander_noDriver_old.hpp"
		};	
	};
};
class RC_BMP3_Base: RC_BMP3_old_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\includes_script\DriveControls_GunnerOrCommander.hpp"
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_TakeDriverControls.hpp"
};


class RC_BMP3_WD: RC_BMP3_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_BMP3_WD_O: RC_BMP3_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\RC_RHS_AFRF\loadouts\FSVitemsO_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_green.hpp"
		};
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_green.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_green.hpp"
		};
	};
};
class RC_BMP3_WD_I: RC_BMP3_WD
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\RC_RHS_AFRF\loadouts\FSVitemsI_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_yellow.hpp"
		};
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_yellow.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_yellow.hpp"
		};	
	};
};


class RC_BMP3_A: RC_BMP3_WD
{
	//editorPreview="";
	hiddenSelectionsTextures[]=
	{
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_01_3mera_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_02_3mera_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_03_3m_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\rhs_bmp3_04_sand_co.paa",
		"rhsafrf\addons\rhs_bmp3_camo\data\3m_era_sand_co.paa"
	};
	textureList[]=
	{
		"rhs_Sand",
		1
	};
};
class RC_BMP3_A_O: RC_BMP3_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\RC_RHS_AFRF\loadouts\FSVitemsO_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_green.hpp"
		};
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_green.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_green.hpp"
		};
	};
};
class RC_BMP3_A_I: RC_BMP3_A
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\RC_RHS_AFRF\loadouts\FSVitemsI_RHS_AFRF.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3_yellow.hpp"
		};
		class GPMGTurret1: GPMGTurret1
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_yellow.hpp"
		};
		class GPMGTurret2: GPMGTurret2
		{
			#include "\RC_RHS_AFRF\includes_vicmags\mags_BMP3M_side_yellow.hpp"
		};
	};
};