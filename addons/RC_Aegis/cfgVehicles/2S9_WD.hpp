class RC_Howitzer_HEX_A_O;
class RC_Howitzer_WD2_O_Base: RC_Howitzer_HEX_A_O
{
	class Turrets;
	class MainTurret;
	class TextureSources;
	scope=0;
	scopeCurator=0;
};
class RC_Howitzer_WD2_O: RC_Howitzer_WD2_O_Base
{
	scope=2;
	scopeCurator=2;

	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_MBT_02_arty_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_body_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_scorcher_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_RUkhk_CO.paa",
		"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
		//"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
	class TextureSources: TextureSources
	{
		class RC_Green
		{
			displayName="Woodland";
			textures[]=
			{
				"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_body_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_scorcher_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_RUkhk_CO.paa",
				"\A3_Aegis\Soft_F_Aegis\UGV_01\Data\Turret_RUkhk_CO.paa",
				//"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa"
				"a3\armor_f\data\camonet_green_co.paa"
			};
			factions[]={};
		};
	};
	textureList[]=
	{
		"RC_Green",
		1
	};
};
class RC_Howitzer_WD2: RC_Howitzer_WD2_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_Howitzer_WD2_I: RC_Howitzer_WD2_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Howitzer_LC_WD2_O: RC_Howitzer_WD2_O
{
	displayName="RC Howitzer LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_155mm_Mo_shells",
				"RC_3Rnd_155mm_Mo_HEAB",
				"RC_3Rnd_155mm_Mo_MultiGuided",
				//"RC_2Rnd_155mm_Mo_Cluster",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_4Rnd_155mm_Mo_AT_mine",
				"RC_4Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
			};
		};
	};
};
class RC_Howitzer_LC_WD2: RC_Howitzer_LC_WD2_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_Howitzer_LC_WD2_I: RC_Howitzer_LC_WD2_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};