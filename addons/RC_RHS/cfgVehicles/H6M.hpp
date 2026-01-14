class RHS_MELB_AH6M;
class RC_MELB_AH6M_Core: RHS_MELB_AH6M
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_fetch.hpp"
};
class RC_MELB_AH6M_Base: RC_MELB_AH6M_Core
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_main.hpp"

	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_pilotCam.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_userActions.hpp"
	//#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_hitPoints.hpp"
	//#include "\Remote_Controlled_Artillery\MFD\MFD_merged.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"


	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_4pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_copilotTurret.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_cargoTurrets_frontRear.hpp"
	};


	editorSubcategory="RC_Heli_armed_subcat";
	transportsoldier=0;		//removes default 1 left pylon seat, replaced with 4 bench seats
	cargoProxyIndexes[]={10};


	class AnimationSources: AnimationSources
	{
		/*
		//REMOVE without breaking script
		class pilotpip
		{
			source="user";
			animperiod=0.001;
			initPhase=0;
		};
		class copilotpip: pilotpip
		{
		};
		*/
		class Addgunrack
		{
			source="user";
			animPeriod=0.1;
			initPhase=1;
		};
		class AddBenches
		{
			source="user";
			animPeriod=0.1;
			initPhase=1;
		};
		/*
		class Addcrosshair
		{
			source="user";
			animPeriod=1;
			initPhase=0;
		};
		*/
	};
};


//AH manned
class RC_MELB_AH6M_DAP: RC_MELB_AH6M_Base
{
	displayName="AH-6M DAP"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=0;	//1

	#include "\RC_RHS\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MELB_AH6M_DAP_O: RC_MELB_AH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MELB_AH6M_DAP_I: RC_MELB_AH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//AH optionally manned
class RC_MELB_OM_AH6M_DAP_UV: RC_MELB_AH6M_Base
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_EHs_UV.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_UV_conversion.hpp"

	displayName="OM AH-6M DAP"
};
class RC_MELB_OM_AH6M_DAP: RC_MELB_OM_AH6M_DAP_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=0;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MELB_OM_AH6M_DAP_O: RC_MELB_OM_AH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MELB_OM_AH6M_DAP_I: RC_MELB_OM_AH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//MH manned
class RC_MELB_MH6M_DAP_Base: RC_MELB_AH6M_Base
{
	transportsoldier=1;
	cargoProxyIndexes[]={9};

	memoryPointsGetInCargo[]= {"pos cargo"};
	memoryPointsGetInCargoDir[]= {"pos cargo dir"};
	memoryPointsGetInCargoPrecise[]= {"pos cargo"};
	cargoCompartments[]= {"Compartment1"};
	cargoGetInAction[]= {"GetInLow"};
	cargoGetOutAction[]= {"GetOutLow"};
	cargoAction[]= {"passenger_flatground_generic04"};

	class AnimationSources: AnimationSources
	{
		class Addgunrack
		{
			source="user";
			animPeriod=1e-007;
			initPhase=0;
		};
		class Addfueltank
		{
			source="user";
			animPeriod=1;
			initPhase=0;
		};
	};
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_2pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_copilotTurret.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_cargoTurrets_frontRear.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_cargoTurrets_middle.hpp"
	};
};
class RC_MELB_MH6M_DAP: RC_MELB_MH6M_DAP_Base
{
	displayName="MH-6M DAP"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=0;	//1

	#include "\RC_RHS\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MELB_MH6M_DAP_O: RC_MELB_MH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MELB_MH6M_DAP_I: RC_MELB_MH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//AH T optionally manned
class RC_MELB_OM_MH6M_DAP_UV: RC_MELB_MH6M_DAP_Base
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_EHs_UV.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_UV_conversion.hpp"

	displayName="OM MH-6M DAP"
};
class RC_MELB_OM_MH6M_DAP: RC_MELB_OM_MH6M_DAP_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=0;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MELB_OM_MH6M_DAP_O: RC_MELB_OM_MH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MELB_OM_MH6M_DAP_I: RC_MELB_OM_MH6M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};




class RHS_MELB_MH6M;
class RC_MELB_MH6M_Core: RHS_MELB_MH6M
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_fetch.hpp"
};
class RC_MELB_MH6M_Base: RC_MELB_MH6M_Core
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_main.hpp"

	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_pilotCam.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_userActions.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_hitPoints.hpp"
	//#include "\Remote_Controlled_Artillery\MFD\MFD_merged.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"


	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};
	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_copilotTurret.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_cargoTurrets_frontRear.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_cargoTurrets_middle.hpp"
	};

	editorSubcategory="RC_Heli_unarmed_subcat";
	cargoProxyIndexes[]={9};
};


//MH manned
class RC_MELB_MH6M: RC_MELB_MH6M_Base
{
	displayName="MH-6M"

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=0;	//1

	#include "\RC_RHS\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MELB_MH6M_O: RC_MELB_MH6M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MELB_MH6M_I: RC_MELB_MH6M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//MH optionally manned
class RC_MELB_OM_MH6M_UV: RC_MELB_MH6M_Base
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_EHs_UV.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H6M_UV_conversion.hpp"

	displayName="OM MH-6M"
};
class RC_MELB_OM_MH6M: RC_MELB_OM_MH6M_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=0;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsB.hpp"
};
class RC_MELB_OM_MH6M_O: RC_MELB_OM_MH6M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsO.hpp"
};
class RC_MELB_OM_MH6M_I: RC_MELB_OM_MH6M
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\TransportHeliitemsI.hpp"
};


//ADD RC CoPilot, manned Pilot, armored glass