//Submun
triggerOnImpact=1;
submunitionCount=1;
submunitionParentSpeedCoef=0;
submunitionInitSpeed=700;	//to allow 10m triggerdistance, but no delayed fuze overpen of small rooms with its triggertime
submunitionConeAngle=0;
submunitionDirectionType="SubmunitionModelDirection";

//Trigger/ed
deleteParentWhenTriggered=1;
submunitionInitialOffset[]={0,0,-3.5};
triggerDistance=10;

//Penetration / Fuze
explosive=0.60000002;

//Simulation
simulation="shotSubmunitions";
simulationStep=0.0020000001;

//Use
warheadName="HE";
aiAmmoUsageFlags="64 + 128 + 256 + 512";