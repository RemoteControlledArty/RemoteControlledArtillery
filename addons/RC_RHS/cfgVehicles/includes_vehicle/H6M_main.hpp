editorSubcategory="RC_Heli_subcat";


lockDetectionSystem="2+4+8";		//4+8
showAllTargets="2 + 4";
receiveRemoteTargets=1;
reportRemoteTargets=1;
reportOwnPosition=1;
canUseScanner=1;


allowTabLock=1;
gunnerCanFire=1;
enableManualFire=1;


bodyFrictionCoef=0.2;				//0.3
maxSpeed=250;						//200
liftForceCoef=1;					//1				//1.7
cyclicAsideForceCoef=1.65;			//1.65			//2
cyclicForwardForceCoef=0.40000001;	//0.40000001	//0.43000001
backrotorforcecoef=1.35;			//0.89999998	//0.89999998
startDuration=7.5;					//10
slingLoadMemoryPoint="slingLoad0";
slingLoadMaxCargoMass=4000;			//900
maximumLoad=2250;					//1000
//sensitivity=2.5;					//2.5
//mainBladeRadius=4.3200002;		//4.3200002
//tailBladeRadius=0.76999998;		//0.76999998


driverCompartments="Compartment1";
crewCrashProtection=0.1;			//0.2
ejectDeadCargo=1;
hullDamageCauseExplosion=1;			//1
hullExplosionDelay[]={20,30};		//{10,20}


memoryPointTaskMarker="TaskMarker_1_pos";
memoryPointDriverOptics="pos pilot dir";	//pos pilot, pos rack, pos gunner, pos cargo 	//memsupply, slingLoad0		//IR_Position, Light_pos
//memoryPointDriverOptics="Copilot_view_dir";
//memoryPointDriverOptics="Slingload_cam";


unitInfoType="RC_RscOptics_AV_Heli";
unitInfoTypeRTD="RC_RscOptics_AV_Heli";
driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";


//ADD RC CoPilot, manned Pilot