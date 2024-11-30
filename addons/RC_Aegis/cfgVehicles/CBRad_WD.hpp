//Counter Battery Radar
class RC_CBRad2_Player_A_O;
class RC_CBRad2_Player_WD_O_Base: RC_CBRad2_Player_A_O
{
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_CBRad2_Player_WD_O: RC_CBRad2_Player_WD_O_Base
{
	scope=2;
	scopeCurator=2;
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_Radar_System_02_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Static_F_Aegis\Radar_System_02\Data\Radar_system_02_mat_01_RUkhk_CO.paa",
		"\A3_Aegis\Static_F_Aegis\Radar_System_02\Data\Radar_system_02_mat_02_RUkhk_CO.paa"
	};
};
class RC_CBRad2_Player_WD: RC_CBRad2_Player_WD_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_B.hpp"
		};
	};
};
class RC_CBRad2_Player_WD_I: RC_CBRad2_Player_WD_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_Player_I.hpp"
		};
	};
};


class RC_CBRad2_AI_A_O;
class RC_CBRad2_AI_WD_O_Base: RC_CBRad2_AI_A_O
{
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_CBRad2_AI_WD_O: RC_CBRad2_AI_WD_O_Base
{
	scope=2;
	scopeCurator=2;
	editorPreview="\A3_Aegis\EditorPreviews_F_Aegis\Data\CfgVehicles\O_R_Radar_System_02_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3_Aegis\Static_F_Aegis\Radar_System_02\Data\Radar_system_02_mat_01_RUkhk_CO.paa",
		"\A3_Aegis\Static_F_Aegis\Radar_System_02\Data\Radar_system_02_mat_02_RUkhk_CO.paa"
	};
};
class RC_CBRad2_AI_WD: RC_CBRad2_AI_WD_O
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_B.hpp"
		};
	};
};
class RC_CBRad2_AI_WD_I: RC_CBRad2_AI_WD_O
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class EventHandlers: EventHandlers
	{	
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\CBRad_AI_I.hpp"
		};
	};
};