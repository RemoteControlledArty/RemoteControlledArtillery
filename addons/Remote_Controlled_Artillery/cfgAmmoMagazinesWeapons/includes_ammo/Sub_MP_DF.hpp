//Default
deflecting=0;

//Submun
triggerOnImpact=1;
submunitionCount=1;
submunitionParentSpeedCoef=0;
submunitionInitSpeed=1000;
submunitionConeAngle=0;
submunitionDirectionType="SubmunitionModelDirection";

//Trigger/ed
deleteParentWhenTriggered=0;
submunitionInitialOffset[]={0,0,-3.5};
explosionTime=0.009;

//Penetration / Fuze
explosive=0.60000002;
hit=0;	//to not cause additional direct hit damage besides the penetrator submun

//Simulation
simulation="shotShell";
simulationStep=0.0020000001;

//Use
warheadName="HE";
aiAmmoUsageFlags="64 + 128 + 256 + 512";