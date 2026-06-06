class RHS_UH1Y;
class RC_UH1M_Core: RHS_UH1Y
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_fetch.hpp"
};
class RC_UH1M_Base: RC_UH1M_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
	};

	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_main.hpp"

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_Main.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_pilotCamBase.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_pilotCamFixed.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_pilotCamFree.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_userActions.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_hitPoints.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"


	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_2pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_copilotTurret.hpp"
		#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_cargoTurrets.hpp"
	};

	editorSubcategory="RC_Heli_armed_subcat";
	transportsoldier=0;		//removes default 1 left pylon seat, replaced with 4 bench seats
	cargoProxyIndexes[]={10};

	class ViewPilot: ViewPilot
	{
		initFov=0.9;
		maxFov=1.25;
		minFov=0.25;
	};

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
class RC_UH1M_DAP: RC_UH1M_Base
{
	displayName="UH-1M DAP - Huey";

	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\RC_RHS\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsB.hpp"
};
class RC_UH1M_DAP_O: RC_UH1M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsO.hpp"
};
class RC_UH1M_DAP_I: RC_UH1M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsI.hpp"
};


//optionally manned
class RC_OM_UH1M_DAP_UV: RC_UH1M_Base
{
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_EHs_UV.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_UV_conversion.hpp"

	displayName="RC UH-1M DAP - Huey";
};
class RC_OM_UH1M_DAP: RC_OM_UH1M_DAP_UV
{
	scope=2;			//2
	scopeCurator=2;		//2
	forceInGarage=1;	//1

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsB.hpp"
};
class RC_OM_UH1M_DAP_O: RC_OM_UH1M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsO.hpp"
};
class RC_OM_UH1M_DAP_I: RC_OM_UH1M_DAP
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
	#include "\RC_RHS\cfgVehicles\includes_vehicle\H1M\H1M_itemsI.hpp"
};