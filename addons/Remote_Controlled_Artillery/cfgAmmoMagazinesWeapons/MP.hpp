//simulation="shotShell";

//simulationStep=0.0020000001;	//1.66m  , bullet default 0.050000001; would be 50m which doesnt seem to be the case
submunitionCount=1;
submunitionInitSpeed=1000;
submunitionParentSpeedCoef=0;
submunitionConeAngle=0;
submunitionDirectionType="SubmunitionModelDirection";

//deleteParentWhenTriggered=0;

triggerOnImpact=1;

//submunitionInitialOffset[]={0,0,-0.2};	//test if suitable or not

//proximityExplosionDistance=6; doesnt work on sim shotShell
//triggerDistance=6; doesnt work on sim shotShell
laserLock=1;
irLock=1;
airLock=1;
deflecting=1;
tracerEndTime=4;
warheadName="HE";
aiAmmoUsageFlags="64 + 128 + 256 + 512";

//explosive=0.60000002;	//for penetrating light cover, 0.60000002 = MP, 0.80000001 = HE/GPR, 1 = HE with HEAT submun, test 0.7