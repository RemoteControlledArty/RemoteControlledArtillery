//retexture
class RC_AA_HEX_A_O;
class RC_ZSU35_WD_O_Base: RC_AA_HEX_A_O
{
	class TextureSources;
	class AnimationSources;
	class showCamonetHull;
	class showCamonetTurret;
	class Turrets;
	class MainTurret;
	scope=0;
	scopeCurator=0;
};
class RC_ZSU35_WD_O: RC_ZSU35_WD_O_Base
{
	scope=2;
	scopeCurator=2;
	editorPreview = "\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_APC_Tracked_02_AA_F.jpg";
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
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_01_AA_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_02_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_01_AA_Tower_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_01_AA_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_02_ext_02_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Tracked_02\Data\APC_Tracked_01_AA_Tower_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
	class AnimationSources: AnimationSources
	{
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=0;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=0;
		};
	};
	animationList[]=
	{
		"showTracks",
		0,
		"showCamonetTurret",
		0,
		"showCamonetHull",
		0,
		"showBags",
		0,
		"showSLATHull",
		1
	};
};
class RC_ZSU35_WD: RC_ZSU35_WD_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_AA_35mm_red.hpp"
		};
	};
};
class RC_ZSU35_WD_I: RC_ZSU35_WD_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_AA_35mm_yellow.hpp"
		};
	};
};