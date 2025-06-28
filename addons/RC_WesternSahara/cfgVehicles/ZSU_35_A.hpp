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
class RC_ZSU35_A_O: RC_ZSU35_WD_O_Base
{
	scope=2;
	scopeCurator=2;
	//editorPreview="";		//non available yet
	textureList[]=
	{
		"Sand",
		1
	};
	class TextureSources: TextureSources
	{
		class Sand
		{
			textures[]=
			{
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_aa_sand1_co.paa",
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand2_co.paa",
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_aa_sand3.paa",
				"A3\Armor_F\Data\camonet_CSAT_HEX_Desert_CO.paa",
				"A3\armor_f\data\cage_csat_co.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_aa_sand1_co.paa",
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand2_co.paa",
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_aa_sand3.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Desert_CO.paa",
		"A3\armor_f\data\cage_csat_co.paa"
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
class RC_ZSU35_A: RC_ZSU35_A_O
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
class RC_ZSU35_A_I: RC_ZSU35_A_O
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