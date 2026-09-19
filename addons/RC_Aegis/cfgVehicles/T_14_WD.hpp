class RC_MBT_3_Core;
class RC_MBT_3_WD2_Fetch: RC_MBT_3_Core
{
	class MainTurret;
	class Turrets;
	class CommanderOptics;
	class TextureSources;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_MBT_3_WD2_Core: RC_MBT_3_WD2_Fetch
{
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_MBT_04_command_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Armor_F_Aegis\MBT_04\Data\MBT_04_exterior_RUkhk_1_CO.paa",
		"\A3_Aegis\Armor_F_Aegis\MBT_04\Data\MBT_04_exterior_RUkhk_2_CO.paa",
		"\A3\Armor_F_Tank\MBT_04\Data\MBT_04_command_CO.paa",
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
				"\A3_Aegis\Armor_F_Aegis\MBT_04\Data\MBT_04_exterior_RUkhk_1_CO.paa",
				"\A3_Aegis\Armor_F_Aegis\MBT_04\Data\MBT_04_exterior_RUkhk_2_CO.paa",
				"\A3\Armor_F_Tank\MBT_04\Data\MBT_04_command_CO.paa",
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
class RC_MBT_3_WD2_Base: RC_MBT_3_WD2_Core
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


class RC_MBT_3_WD2: RC_MBT_3_WD2_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	
	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\FSVitemsB.hpp"
};
class RC_MBT_3_WD2_O: RC_MBT_3_WD2
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
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
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
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