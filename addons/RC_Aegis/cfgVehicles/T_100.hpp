class RC_MBT_4_HEX_A_O;
class RC_MBT_4_HEX_A_O_Base: RC_MBT_4_HEX_A_O
{
	class MainTurret;
	class Turrets;
	class CommanderOptics;
	class TextureSources;
	scope=0;
	scopeCurator=0;
};
class RC_MBT_4_WD_O: RC_MBT_4_HEX_A_O_Base
{
	scope=2;
	scopeCurator=2;
	
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_MBT_02_cannon_F.jpg";
	class TextureSources: TextureSources
	{
		class Green
		{
			textures[]=
			{
				"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_body_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_turret_RUkhk_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_RUkhk_CO.paa",
				//"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa"
				"a3\armor_f\data\camonet_green_co.paa"
			};
			factions[]={};
		};
	};
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_body_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_turret_RUkhk_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\MBT_02\Data\MBT_02_RUkhk_CO.paa",
		//"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
	textureList[]=
	{
		"Green",
		1
	};
};
class RC_MBT_4_WD: RC_MBT_4_WD_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T100_red.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T100_com_red.hpp"
				};
			};
		};
	};
};
class RC_MBT_4_WD_I: RC_MBT_4_WD_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T100_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T100_com_yellow.hpp"
				};
			};
		};
	};
};