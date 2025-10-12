class RC_Mortar_UGV_A: RC_Mule_UGV_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};

	displayName="RC Mortar UGV";
	editorSubcategory="RC_Mortar_subcat";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_Mortar_UGV_A_O: RC_Mortar_UGV_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_UGV_A_I: RC_Mortar_UGV_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};



class RC_Mortar_UGV_WD: RC_Mortar_UGV_A
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
class RC_Mortar_UGV_WD_O: RC_Mortar_UGV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_UGV_WD_I: RC_Mortar_UGV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Mortar_UGV_LC_A: RC_Mortar_UGV_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};

	displayName="RC Mortar UGV LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";
};
class RC_Mortar_UGV_LC_A_O: RC_Mortar_UGV_LC_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_UGV_LC_A_I: RC_Mortar_UGV_LC_A
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};
	
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};



class RC_Mortar_UGV_LC_WD: RC_Mortar_UGV_LC_A
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
class RC_Mortar_UGV_LC_WD_O: RC_Mortar_UGV_LC_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Mortar_UGV_LC_WD_I: RC_Mortar_UGV_LC_WD
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_LC_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.355, -0.87, 0.04]];};";
		};
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};