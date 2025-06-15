class RC_FPV_Carrier_A;
class RC_Crocus_Carrier_Base: RC_FPV_Carrier_A
{
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_Carrier_A: RC_Crocus_Carrier_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			fired="params ['_uav', '_weapon'];  if (!Local _uav) exitWith {};  [_uav, _weapon] call RC_fnc_fpv_CarrierDeploy";
		};
	};

	weapons[]=
	{
		"RC_Crocus_Deployer"
	};
	magazines[]=
	{
		"RC_6xCrocus_Deployer_UGV_Mag"
	};

	displayName="6xCrocus Carrier";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_Carrier_A_O: RC_Crocus_Carrier_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Crocus_Carrier_A_I: RC_Crocus_Carrier_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Crocus_Carrier_WD: RC_Crocus_Carrier_A
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_UGV_01_olive_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa",
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};
class RC_Crocus_Carrier_WD_O: RC_Crocus_Carrier_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Crocus_Carrier_WD_I: RC_Crocus_Carrier_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};