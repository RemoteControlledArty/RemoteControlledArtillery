class CopilotTurret: CopilotTurret
{
	dontCreateAI=1;

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