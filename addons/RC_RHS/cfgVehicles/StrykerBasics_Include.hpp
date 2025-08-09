class EventHandlers: EventHandlers
{
	class RC_Detection
	{
		#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
	};
	class RC_LightsOff
	{
		#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
	};
};

class UserActions: UserActions
{
	#include "\Remote_Controlled_Artillery\includes_script\TakeDriverControls.hpp"
	//class ToggleLight {};
	//class AdjustMap {};
	class AdjustMap: AdjustMap
	{
		displayName="removed";
		condition="1 => 0;";
	};
	class ToggleLight: ToggleLight
	{
		displayName="removed";
		condition="1 => 0;";
	};
};

#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
lockDetectionSystem="2+4+8";

editorSubcategory="RC_APC_subcat";

forceInGarage=1;
driverCompartments="Compartment2";
commanding=2;
ejectDeadGunner=0;
ejectDeadDriver=0;
ejectDeadCommander=0;
crewCrashProtection=0.01;
maximumLoad=4000;
//maxSpeed=;
//enginePower=;
//peakTorque=;

/*
smokeLauncherGrenadeCount=12;
smokeLauncherAngle=180;

weapons[]=
{
	"TruckHorn",
	"SmokeLauncher"
};
magazines[]=
{
	"SmokeLauncherMag",
	"SmokeLauncherMag"
};
*/

class DriverOpticsIn
{
	class DVE_Wide: ViewOptics
	{
		camPos="view_DVE";
		opticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
		visionMode[]=
		{
			"TI",
			"Normal"
		};
		thermalMode[]={0};
		initFov=1.07692;
		minFov=1.07692;
		maxFov=1.07692;
		hitpoint="Hit_Optic_DVEA";
	};
	class DVS_Rear: DVE_Wide
	{
		camPos="view_rear";
		camDir="view_rear_dir";
		hitpoint="Hit_Optic_Driver_Rear";
	};
};

/*
class UserActions: UserActions
{
	class AdjustMap
	{
		displayName="";
		position="pos driver";
		radius=20;
		condition="player == driver this";
		statement="";
		onlyforplayer=1;
	};
};
*/

class HitPoints: HitPoints
{
	#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
};

#include "\RC_RHS\loadouts\IFVitemsB_RHS.hpp"