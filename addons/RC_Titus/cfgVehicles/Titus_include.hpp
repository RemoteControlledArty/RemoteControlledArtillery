#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\DriverComponents4km.hpp"
#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
lockDetectionSystem="2+4+8";
//RC_ATrespondingTurret[]={0,0};	//comCamera has no turretPath, and idk if gunner camera turn is good turing driving

weapons[]=
{
	"TruckHorn2",
	"RC_APS_W",
	"SmokeLauncher"
};
magazines[]=
{
	//"RC_1Rnd_APS_M",
	"RC_1Rnd_APS_M",
	"SmokeLauncherMag"
};

faction="RemoteControlled_B";
crew="B_UAV_AI";
driverCompartments="Compartment3";
commanding=1;
forceHideDriver=1;
driverForceOptics=1;
//memoryPointDriverOptics="optika_velitel";

ejectDeadGunner=0;
ejectDeadDriver=0;
ejectDeadCommander=0;
crewCrashProtection=0.01;
enginePower=460;
peakTorque=1312.5;
maxSpeed=120;
normalSpeedForwardCoef=0.64;
class Reflectors {};	//removed, otherwise they are automatically on at night
aggregateReflectors[]={{""}};

smokeLauncherOnTurret=1;
smokeLauncherGrenadeCount=12;
smokeLauncherVelocity=14;
smokeLauncherAngle=180;

animationList[]=
{
	"comp_klec",
	0,
	"comp_camonet",
	0
};

class HitPoints: HitPoints
{
	#include "\Remote_Controlled_Artillery\includes_cfg\hitWheels.hpp"
};

#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"