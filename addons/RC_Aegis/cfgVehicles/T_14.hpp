class RC_MBT_3_WD;
class RC_MBT_3_WD_Base: RC_MBT_3_WD
{
	class MainTurret;
	class Turrets;
	class CommanderOptics;
	scope=0;
	scopeCurator=0;
};
class RC_MBT_3_WD2: RC_MBT_3_WD_Base
{
	scope=2;
	scopeCurator=2;

	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_MBT_04_command_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\MBT_04\Data\MBT_04_exterior_RUkhk_1_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\MBT_04\Data\MBT_04_exterior_RUkhk_2_CO.paa",
		"\A3\Armor_F_Tank\MBT_04\Data\MBT_04_command_CO.paa",
		//"\A3_Aegis\Armor_F_Aegis\Data\camonet_RUS_green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MBT_3_WD2_O: RC_MBT_3_WD2
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T14_green.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T14_com_green.hpp"
				};
			};
		};
	};
};
class RC_MBT_3_WD2_I: RC_MBT_3_WD2
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T14_yellow.hpp"
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_vicmags\mags_T14_com_yellow.hpp"
				};
			};
		};
	};
};