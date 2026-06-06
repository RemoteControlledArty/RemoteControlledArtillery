class CopilotTurret: CopilotTurret
{
	class Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};

	turretInfoType="RC_RHS_RscUH1Y_Observer";	//removes grey filter
	
	dontCreateAI=1;
	canEject=1;

	gunnerName="CoPilot";
	primaryGunner=0;
	primaryObserver=1;	//test 0, but center cam uses if commander condition
	gunnerCompartments="Compartment1";
	showAllTargets="2 + 4";
	canUseScanners=1;
	stabilizedInAxes=3;

	//test values
	//showHMD=0;
	gunnerCanFire=1;
	enableManualFire=1;
	vehicleWeaponAccess=1;
	inGunnerMayFire=1;
	allowTabLock=1;	//0
	isCopilot=1;
	//gunnerUsesPilotView=0;	//??? in Mi48

	class OpticsIn
	{
		class Wide
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\OpticsBasicsNVTI.hpp"
			gunnerOpticsModel="\rhsusf\addons\rhsusf_optics\data\rhs_uh1_flir";

			minAngleX=-30;
			maxAngleX=30;
			minAngleY=-100;
			maxAngleY=100;

			initFov=1;	//0.9
			minFov=0.02;
			maxFov=1;	//0.9

			directionStabilized=1;
			horizontallyStabilized=1;
		};
	};
};