class RC_MH80M_DAP_Base;
class RC_RHS_MH80M_DAP_Core: RC_MH80M_DAP_Base
{
	class Components;
	class EventHandlers;
};
class RC_RHS_MH80M_DAP_Base: RC_RHS_MH80M_DAP_Core
{
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_4pylons.hpp"
	};
};


//manned
class RC_MH80M_DAP_V5: RC_RHS_MH80M_DAP_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	displayName="MH-80M DAP - Ghost Hawk  V5"
	editorSubcategory="RC_Heli_V5_subcat";

	class Components: Components
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H80M\H80M_4pylons_V5.hpp"
	};

	#include "\RC_RHS\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsB.hpp"
};
class RC_MH80M_DAP_V5_O: RC_MH80M_DAP_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsO.hpp"
};
class RC_MH80M_DAP_V5_I: RC_MH80M_DAP_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsI.hpp"
};


/*
//optionally manned
class RC_OM_MH80M_DAP_V5_UV: RC_RHS_MH80M_DAP_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"
};
class RC_OM_MH80M_DAP_V5: RC_OM_MH80M_DAP_V5_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	displayName="RC MH-80M DAP - Ghost Hawk  V5"
	editorSubcategory="RC_Heli_V5_subcat";

	class Components: Components
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H80M\H80M_4pylons_V5.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsB.hpp"
};
class RC_OM_MH80M_DAP_V5_O: RC_OM_MH80M_DAP_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsO.hpp"
};
class RC_OM_MH80M_DAP_V5_I: RC_OM_MH80M_DAP_V5
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_itemsI.hpp"
};
*/