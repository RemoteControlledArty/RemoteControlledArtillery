class RC_ICV_5_A_O;
class RC_ICV_5_A2_O_Base: RC_ICV_5_A_O
{
	class TextureSources;
	class AnimationSources;
	class showCamonetHull;
	scope=0;
	scopeCurator=0;
};
class RC_ICV_5_A2_O: RC_ICV_5_A2_O_Base
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
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand1_co.paa",
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand2_co.paa",
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand3_co.paa",
				"A3\Armor_F\Data\camonet_CSAT_HEX_Desert_CO.paa",
				"A3\armor_f\data\cage_csat_co.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand1_co.paa",
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand2_co.paa",
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand3_co.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Desert_CO.paa",
		"A3\armor_f\data\cage_csat_co.paa"
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
class RC_ICV_5_A2: RC_ICV_5_A2_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_ICV_5_A2_I: RC_ICV_5_A2_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


//vanilla turret retexture
class RC_IFV_5_A_O;
class RC_IFV_5_A2_O_Base: RC_IFV_5_A_O
{
	class TextureSources;
	class AnimationSources;
	class showCamonetHull;
	class Turrets;
	class MainTurret;
	scope=0;
	scopeCurator=0;
};
class RC_IFV_5_A2_O: RC_IFV_5_A2_O_Base
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
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand1_co.paa",
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand2_co.paa",
				"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand3_co.paa",
				"A3\Armor_F\Data\camonet_CSAT_HEX_Desert_CO.paa",
				"A3\armor_f\data\cage_csat_co.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand1_co.paa",
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand2_co.paa",
		"lxws\vehicles_f_lxws\data\APC_Tracked_02\kamysh_sand3_co.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Desert_CO.paa",
		"A3\armor_f\data\cage_csat_co.paa"
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
class RC_IFV_5_A2: RC_IFV_5_A2_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_BM2T_30mm_red.hpp"
		};
	};
};
class RC_IFV_5_A2_I: RC_IFV_5_A2_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_BM2T_30mm_yellow.hpp"
		};
	};
};