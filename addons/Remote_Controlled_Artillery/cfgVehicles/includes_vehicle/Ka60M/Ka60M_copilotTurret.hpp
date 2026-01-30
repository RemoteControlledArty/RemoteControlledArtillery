class CopilotTurret: CopilotTurret
{
	class Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};

	//memoryPointGunnerOptics="";

	dontCreateAI=1;
	gunnerCompartments="Compartment1";	//3
	showAllTargets="2 + 4";
	canUseScanners=1;
	allowTabLock=1;
	//stabilizedInAxes=3;

	/*
	gunnerCanFire=1;
	enableManualFire=1;
	vehicleWeaponAccess=1;
	inGunnerMayFire=1;
	isCopilot=1;
	*/


	//vanilla
	CanEject=1;	//0

	/*
	commanding=-3;
	gunnerAction="pilot_Heli_Transport_01";
	gunnerInAction="pilot_Heli_Transport_01";
	memoryPointsGetInGunner="pos copilot";
	memoryPointsGetInGunnerDir="pos copilot dir";
	gunnerGetInAction="GetInHeli_Transport_01Cargo";
	gunnerGetOutAction="GetOutLow";
	preciseGetInOut=0;
	GunnerDoor="";
	gunnerLeftHandAnimName="lever_copilot";
	gunnerRightHandAnimName="stick_copilot";
	gunnerLeftLegAnimName="PedalL";
	gunnerRightLegAnimName="PedalR";
	proxyIndex=3;
	LODTurnedIn=1100;
	LODTurnedOut=1100;

	class ViewGunner: ViewPilot
	{
	};
	class Hitpoints
	{
	};
	*/
	selectionFireAnim="";
};


/*
class CopilotTurret: CopilotTurret
{
	class OpticsIn: OpticsIn
	{
		class Wide: Wide
		{
			initFov=1;	//0.9
			minFov=0.02;
			maxFov=1;	//0.9
			visionMode[]=
			{
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[]={0};
			directionStabilized=1;
			horizontallyStabilized=1;
		};
	};
};
*/