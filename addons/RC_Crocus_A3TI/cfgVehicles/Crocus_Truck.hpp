class RC_FPV_Truck_A;
class RC_Crocus_Truck_Base: RC_FPV_Truck_A
{
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_Truck_A: RC_Crocus_Truck_Base
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
		"RC_Crocus_Deployer",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_18xCrocus_Deployer_UGV_Mag",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	displayName="RC Crocus Truck";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_Truck_A_O: RC_Crocus_Truck_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Crocus_Truck_A_I: RC_Crocus_Truck_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Crocus_Truck_WD: RC_Crocus_Truck_A
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Truck_01_box_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\A3\Soft_F_Exp\Truck_01\Data\truck_01_ammo_olive_CO.paa",
		"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
	};
};
class RC_Crocus_Truck_WD_O: RC_Crocus_Truck_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Crocus_Truck_WD_I: RC_Crocus_Truck_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_FPV_Truck_manned_A;
class RC_Crocus_Truck_manned_Base: RC_FPV_Truck_manned_A
{
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Crocus_Truck_manned_A: RC_Crocus_Truck_manned_Base
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
		"RC_Crocus_Deployer",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"RC_18xCrocus_Deployer_UGV_Mag",
		"SmokeLauncherMag",
		"SmokeLauncherMag"
	};

	displayName="Crocus Truck";
	scope=2;
	scopeCurator=2;
};
class RC_Crocus_Truck_manned_A_O: RC_Crocus_Truck_manned_A
{
	faction="RemoteControlled_O";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Crocus_Truck_manned_A_I: RC_Crocus_Truck_manned_A
{
	faction="RemoteControlled_I";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Crocus_Truck_manned_WD: RC_Crocus_Truck_manned_A
{
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Truck_01_box_F.jpg";
	textureList[]=
	{
		"Olive",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_01_olive_co.paa",
		"\a3\soft_f_Exp\truck_01\data\truck_01_ext_02_olive_co.paa",
		"\A3\Soft_F_Exp\Truck_01\Data\truck_01_ammo_olive_CO.paa",
		"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
	};
};
class RC_Crocus_Truck_manned_WD_O: RC_Crocus_Truck_manned_WD
{
	faction="RemoteControlled_O";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Crocus_Truck_manned_WD_I: RC_Crocus_Truck_manned_WD
{
	faction="RemoteControlled_I";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};