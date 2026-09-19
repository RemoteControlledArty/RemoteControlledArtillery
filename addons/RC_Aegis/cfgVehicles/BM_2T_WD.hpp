class RC_ICV_5_A_O;
class RC_ICV_5_WD2_O_Base: RC_ICV_5_A_O
{
	class TextureSources;
	class AnimationSources;
	class showCamonetHull;
	scope=0;
	scopeCurator=0;
};
class RC_ICV_5_WD2_O: RC_ICV_5_WD2_O_Base
{
	scope=2;
	scopeCurator=2;
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_APC_Tracked_02_cannon_ard_F.jpg";
	textureList[]=
	{
		"Green",
		1
	};
	class TextureSources: TextureSources
	{
		class Green
		{
			textures[]=
			{
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_01_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_02_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\RCWS30_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_01_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_02_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\RCWS30_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	class AnimationSources: AnimationSources
	{
		class showCamonetHull: showCamonetHull
		{
			initPhase=0;
		};
	};
	animationList[]=
	{
		"showTracks",
		0,
		"showCamonetHull",
		0,
		"showBags",
		0,
		"showSLATHull",
		1
	};
};
class RC_ICV_5_WD2: RC_ICV_5_WD2_O
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_ICV_5_WD2_I: RC_ICV_5_WD2_O
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


//vanilla turret retexture
class RC_IFV_5_Core;
class RC_IFV_5_WD2_Fetch: RC_IFV_5_Core
{
	class TextureSources;
	class AnimationSources;
	class showCamonetHull;
	class Turrets;
	class MainTurret;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_IFV_5_WD2_Core: RC_IFV_5_WD2_Fetch
{
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_APC_Tracked_02_cannon_ard_F.jpg";
	textureList[]=
	{
		"Green",
		1
	};
	class TextureSources: TextureSources
	{
		class Green
		{
			textures[]=
			{
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_01_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_02_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\RCWS30_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_01_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_02_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\RCWS30_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	class AnimationSources: AnimationSources
	{
		class showCamonetHull: showCamonetHull
		{
			initPhase=0;
		};
	};
	animationList[]=
	{
		"showTracks",
		0,
		"showCamonetHull",
		0,
		"showBags",
		0,
		"showSLATHull",
		1
	};
};
class RC_IFV_5_WD2_Base: RC_IFV_5_WD2_Core
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


class RC_IFV_5_WD2_O: RC_IFV_5_WD2_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_IFV_5_WD2: RC_IFV_5_WD2_O
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_BM2T_30mm_red.hpp"
		};
	};
};
class RC_IFV_5_WD2_I: RC_IFV_5_WD2_O
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_BM2T_30mm_yellow.hpp"
		};
	};
};