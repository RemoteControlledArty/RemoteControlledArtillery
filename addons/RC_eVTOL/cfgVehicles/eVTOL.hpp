class gyg_jetson_F;
class RC_eVTOL_Fetch: gyg_jetson_F
{
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_fetch.hpp"
};
class RC_eVTOL_Core: RC_eVTOL_Fetch
{
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_main.hpp"
	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_Main.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_pilotCamBase.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_pilotCamFixed.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_pilotCamFree.hpp"
	//#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_hitPoints.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_animationSources.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_userActions.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"

	editorSubcategory="RC_eVTOL_subcat";

	//liftForceCoef=3;		//1.5
	//camouflage=?;			//100
	radarTargetSize=0.5;	//0.7
	visualTargetSize=0.5;	//0.8
	irTargetSize=0.5;		//0.8

	class Components: Components
	{
		#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_sensors.hpp"
		#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_panels.hpp"
		//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\eVTOL_2pylons.hpp"
	};

    /*
	class turrets: turrets
    {
	    coilot=1;
    };
    */
};
class RC_eVTOL_Base: RC_eVTOL_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_getOut1
		{
			getOut="params ['_vehicle'];  if (!local _vehicle) exitWith {};  [_vehicle] spawn fnc_RC_eVTOL_EH_getOut;"
		};
		class RC_engine1
		{
			engine="params ['_vehicle', '_engineState'];  if (!local _vehicle) exitWith {};  [_vehicle, _engineState] spawn fnc_RC_eVTOL_EH_engine;"
		};
		class RC_attached1
		{
			attached="params ['_attachedObj', '_parentObj', '_isReattach', '_offset', '_memoryPointIndex', '_followBoneRotation'];  if (!local _attachedObj) exitWith {};  [_attachedObj] spawn fnc_RC_eVTOL_EH_attached;"
		};

		//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\HMD\HMD_EH.hpp"
		//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\firedProxy_EH.hpp"
		//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\cargo_EH.hpp"
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\DetectInterceptorEH.hpp"

		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_Backup.hpp"
	};

	//#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_hitPoints.hpp"
};


class RC_eVTOL_B: RC_eVTOL_Base
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	displayName="Mosquito - eVTOL"

	/*
	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\eVTOL_2pylons_V2.hpp"
	};
	*/

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsB.hpp"
};
class RC_eVTOL_O: RC_eVTOL_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsO.hpp"
};
class RC_eVTOL_I: RC_eVTOL_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};
class RC_eVTOL_C: RC_eVTOL_B
{
	side=3;
	faction="CIV_F";
	crew="C_man_pilot_F";

	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideC_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};


class RC_eVTOL_TI_B: RC_eVTOL_B
{
	displayName="Mosquito TI - eVTOL";

	class pilotCamera: pilotCamera
	{
		class OpticsIn: OpticsIn
		{
			class Wide: Wide
			{
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
			};
		};
	};
};
class RC_eVTOL_TI_O: RC_eVTOL_TI_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsO.hpp"
};
class RC_eVTOL_TI_I: RC_eVTOL_TI_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};
class RC_eVTOL_TI_C: RC_eVTOL_TI_B
{
	side=3;
	faction="CIV_F";
	crew="C_man_pilot_F";

	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideC_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};


class RC_eVTOL_Minigun_TI_B: RC_eVTOL_TI_B
{
	class EventHandlers: EventHandlers
	{
		class RC_init3
		{
			init="params ['_vehicle'];  if (!local _vehicle) exitWith {};  [_vehicle] spawn fnc_RC_eVTOL_minigun;"
		};
	};

	displayName="Minigun Mosquito TI - eVTOL";

	weapons[]={"RC_eVTOL_Minigun", "Laserdesignator_pilotCamera"};
	magazines[]={"RC_eVTOL_1000Rnd_338_SLAP_T_W", "Laserbatteries"};
	//weapons[]={"RC_eVTOL_Minigun", "Laserdesignator_pilotCamera", "SmokeLauncher"};
	//magazines[]={"RC_eVTOL_1000Rnd_338_SLAP_T_W", "Laserbatteries","SmokeLauncherMag","SmokeLauncherMag"};
};
class RC_eVTOL_Minigun_TI_O: RC_eVTOL_Minigun_TI_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsO.hpp"
};
class RC_eVTOL_Minigun_TI_I: RC_eVTOL_Minigun_TI_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};


/*
class RC_eVTOL_Zoom_B: RC_eVTOL_B
{
	displayName="eVTOL [magnified cam]"

	class pilotCamera: pilotCamera
	{
		class OpticsIn: OpticsIn
		{
			class Wide: Wide
			{
				minFov=0.025;
			};
		};
	};
};
class RC_eVTOL_Zoom_O: RC_eVTOL_Zoom_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsO.hpp"
};
class RC_eVTOL_Zoom_I: RC_eVTOL_Zoom_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};
class RC_eVTOL_Zoom_C: RC_eVTOL_Zoom_B
{
	side=3;
	faction="CIV_F";
	crew="C_man_pilot_F";

	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideC_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};


class RC_eVTOL_ZoomTI_B: RC_eVTOL_B
{
	displayName="eVTOL [magnified TI cam]";

	class pilotCamera: pilotCamera
	{
		class OpticsIn: OpticsIn
		{
			class Wide: Wide
			{
				minFov=0.025;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
			};
		};
	};
};
class RC_eVTOL_ZoomTI_O: RC_eVTOL_ZoomTI_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsO.hpp"
};
class RC_eVTOL_ZoomTI_I: RC_eVTOL_ZoomTI_B
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};
class RC_eVTOL_ZoomTI_C: RC_eVTOL_ZoomTI_B
{
	side=3;
	faction="CIV_F";
	crew="C_man_pilot_F";

	//#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideC_manned.hpp"
	#include "\RC_eVTOL\cfgVehicles\includes_vehicle\eVTOL_itemsI.hpp"
};
*/


/*
//optionally manned
class RC_OM_MH80M_DAP_UV: RC_MH80M_DAP_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_EHs_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_UV_conversion.hpp"

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\eVTOL_pilotTurret.hpp"
	};

	displayName="RC MH-80M DAP - Ghost Hawk"
};
*/
