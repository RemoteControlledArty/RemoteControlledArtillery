lockDetectionSystem="2+4+8";		//4+8
showAllTargets="2 + 4";
receiveRemoteTargets=1;
reportRemoteTargets=1;
reportOwnPosition=1;
canUseScanner=1;


allowTabLock=1;
gunnerCanFire=1;
enableManualFire=1;					//only if copilot is primarygunner & pylons owned by copilot, but then lase is fixed and CCIP is gone


bodyFrictionCoef=0.6;				//0.7
maxSpeed=300;						//290
/*
liftForceCoef=1;					//1
cyclicAsideForceCoef=1;				//1
cyclicForwardForceCoef=1;			//1
backRotorForceCoef=1;				//1
*/
startDuration=15;					//20
slingLoadMaxCargoMass=13500;		//t 13500


/*
slingLoadMemoryPoint="slingLoad0";
maximumLoad=1500;					//1000
*/
//sensitivity=2.5;					//2.5
//mainBladeRadius=4.3200002;		//4.3200002
//tailBladeRadius=0.76999998;		//0.76999998


driverCompartments="Compartment1";
cargoCompartments[]={"Compartment1"};
CanEject=1;
crewCrashProtection=0.1;			//0.2
ejectDeadCargo=1;
//hullDamageCauseExplosion=1;		//0 for vanilla (bool?)
//hullExplosionDelay[]={20,30};		//undefined? like because bool is 0, hull also has 999 armor

/*
hiddenSelections[]=
{
	"Black"
	//"camo1"
};
*/
editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_Heli_Light_02_unarmed_F.jpg";
hiddenSelectionsTextures[]=
{
	"\A3\Air_F\Heli_Light_02\Data\Heli_Light_02_ext_CO.paa"
};
/*
icon="\A3\Air_F\Heli_Light_02\Data\UI\Map_Heli_Light_02_rockets_CA.paa";
picture="\A3\Air_F\Heli_Light_02\Data\UI\Heli_Light_02_rockets_CA.paa";
*/