class O_Heli_Light_02_dynamicLoadout_F;
class RC_Ka60M_Core: O_Heli_Light_02_dynamicLoadout_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_fetch.hpp"
};
class RC_Ka60M_Base: RC_Ka60M_Core
{
	class EventHandlers: EventHandlers
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_main.hpp"
	editorSubcategory="RC_Heli_armed_subcat";

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_pilotCamBase.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFixed.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_pilotCamFree.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_userActions.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_hitPoints.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	/*
	class ViewPilot
	{
		initAngleX = 0;
		initAngleY = 0;
		initFov = 0.9;
		maxAngleX = 85;
		maxAngleY = 150;
		maxFov = 1.25;
		maxMoveX = 0.2;
		maxMoveY = 0.1;
		maxMoveZ = 0.2;
		minAngleX = -65;
		minAngleY = -150;
		minFov = 0.25;
		minMoveX = -0.2;
		minMoveY = -0.1;
		minMoveZ = -0.1;
		speedZoomMaxFOV = 0;
		speedZoomMaxSpeed = 1e+10;
	};
	*/
	
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_sensors.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\Ka60M\Ka60M_2pylons.hpp"
	};
	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_copilotTurret.hpp"
		//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_cargoTurrets.hpp"
	};
	/*
	class AnimationSources: AnimationSources
	{
		//DOOR
	};
	*/
};



// ADD UNARMED version, same with ghosthawk



//manned
class RC_Ka60M: RC_Ka60M_Base
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
class RC_OM_Ka60M_UV: RC_Ka60M_Base
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