class RC_ICV_2_WD_O;
class RC_ICV_2_WD_O_Base: RC_ICV_2_WD_O
{
	class TextureSources;
	scope=0;
	scopeCurator=0;
};
class RC_ICV_2_WD2_O: RC_ICV_2_WD_O_Base
{
	scope=2;
	scopeCurator=2;

	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Wheeled_02_rcws_v2_ghex_F.jpg";
	class TextureSources: TextureSources
	{
		class Green
		{
			textures[]=
			{
				"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_RUkhk_CO.paa",
				"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
				"a3\armor_f\data\camonet_green_co.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
			};
			factions[]={};
		};
	};
	textureList[]=
	{
		"Green",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_RUkhk_CO.paa",
		"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
};
class RC_ICV_2_WD2_B: RC_ICV_2_WD2_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_ICV_2_WD2_I: RC_ICV_2_WD2_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_APC_2_WD_O;
class RC_APC_2_WD2_O_Base: RC_APC_2_WD_O
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class TextureSources;
	scope=0;
	scopeCurator=0;
};
class RC_APC_2_WD2_O: RC_APC_2_WD2_O_Base
{
	scope=2;
	scopeCurator=2;

	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Wheeled_02_rcws_v2_ghex_F.jpg";
	class TextureSources: TextureSources
	{
		class Green
		{
			textures[]=
			{
				"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_RUkhk_CO.paa",
				"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
				"a3\armor_f\data\camonet_green_co.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
			};
			factions[]={};
		};
	};
	textureList[]=
	{
		"Green",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_RUkhk_CO.paa",
		"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
};
class RC_APC_2_WD2_B: RC_APC_2_WD2_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_338_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_GMG_red.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};
class RC_APC_2_WD2_I: RC_APC_2_WD2_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_338_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_GMG_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};


class RC_IFV_2_WD_O;
class RC_IFV_2_WD_O_Base: RC_IFV_2_WD_O
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class TextureSources;
	class AnimationSources;
	scope=0;
	scopeCurator=0;
};
class RC_IFV_2_WD2_O: RC_IFV_2_WD_O_Base
{
	scope=2;
	scopeCurator=2;

	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_APC_Wheeled_02_rcws_v2_ghex_F.jpg";
	class TextureSources: TextureSources
	{
		class Green
		{
			textures[]=
			{
				"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_RUkhk_CO.paa",
				"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
				"a3\armor_f\data\camonet_green_co.paa",
				"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
			};
			factions[]={};
		};
	};
	textureList[]=
	{
		"Green",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_01_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\APC_Wheeled_02\Data\APC_Wheeled_02_ext_02_RUkhk_CO.paa",
		"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
		"a3\armor_f\data\camonet_green_co.paa",
		"\A3_Aegis\Armor_F_Aegis\Data\cage_RUkhk_CO.paa"
	};
};
class RC_IFV_2_WD2_B: RC_IFV_2_WD2_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_autocannon_20mm_CTWS",
				"RC_MMG_338_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_20mm_red.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
	class AnimationSources: AnimationSources
	{
		class muzzle_hide1
		{
			source="reload";
			weapon="RC_MMG_338_APC";
		};
	};
};
class RC_IFV_2_WD2_I: RC_IFV_2_WD2_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_Arma_20mm_yellow.hpp"
		};

		class CommanderOptics: CommanderOptics {};
	};
};