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
		#include "\RC_RHS\cfgVehicles\includes_vehicle\MH80M_4pylons.hpp"
	};
};


//manned
class RC_MH80M_DAP: RC_RHS_MH80M_DAP_Base
{
	displayName="MH-80M DAP - Ghost Hawk"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MH80M_DAP_O: RC_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MH80M_DAP_I: RC_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//optionally manned
class RC_OM_MH80M_DAP_UV: RC_RHS_MH80M_DAP_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	displayName="OM MH-80M DAP - Ghost Hawk"
};
class RC_OM_MH80M_DAP: RC_OM_MH80M_DAP_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_OM_MH80M_DAP_O: RC_OM_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_OM_MH80M_DAP_I: RC_OM_MH80M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};