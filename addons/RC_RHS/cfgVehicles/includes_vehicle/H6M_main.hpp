lockDetectionSystem="2+4+8";		//4+8
showAllTargets="2 + 4";
receiveRemoteTargets=1;
reportRemoteTargets=1;
reportOwnPosition=1;
canUseScanner=1;


allowTabLock=1;
gunnerCanFire=1;
enableManualFire=1;					//only if copilot is primarygunner & pylons owned by copilot, but then lase is fixed and CCIP is gone


bodyFrictionCoef=0.2;				//0.3
maxSpeed=300;						//200
liftForceCoef=1;					//1				//1.7
cyclicAsideForceCoef=1.65;			//1.65			//2
cyclicForwardForceCoef=0.40000001;	//0.40000001	//0.43000001
backrotorforcecoef=0.89999998;			//0.89999998	//0.89999998	//1.35
startDuration=7.5;					//10
slingLoadMemoryPoint="slingLoad0";
slingLoadMaxCargoMass=4000;			//900
maximumLoad=1500;					//1000
//sensitivity=2.5;					//2.5
//mainBladeRadius=4.3200002;		//4.3200002
//tailBladeRadius=0.76999998;		//0.76999998


driverCompartments="Compartment1";
CanEject=1;
crewCrashProtection=0.1;			//0.2
ejectDeadCargo=1;
hullDamageCauseExplosion=1;			//1, maybe just bool?
hullExplosionDelay[]={20,30};		//{10,20}