class RC_Ka60M_Base;
class RC_RHS_Ka60M_Core: RC_Ka60M_Base
{
	class Components;
	class EventHandlers;
};
class RC_RHS_Ka60M_Base: RC_RHS_Ka60M_Core
{
	class Components: Components
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\Ka60M_2pylons.hpp"
	};
};


//manned
class RC_Ka60M: RC_RHS_Ka60M_Base
{
	displayName="Ka-60M - Kasatka"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsB.hpp"
};
class RC_Ka60M_O: RC_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_Ka60M_I: RC_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};


//optionally manned
class RC_OM_Ka60M_UV: RC_RHS_Ka60M_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	displayName="OM Ka-60M - Kasatka"
};
class RC_OM_Ka60M: RC_OM_Ka60M_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsB.hpp"
};
class RC_OM_Ka60M_O: RC_OM_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsO.hpp"
};
class RC_OM_Ka60M_I: RC_OM_Ka60M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_itemsI.hpp"
};