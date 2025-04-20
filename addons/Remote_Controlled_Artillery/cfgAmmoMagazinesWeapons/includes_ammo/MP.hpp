simulation="shotShell";						//can release penetrator submunition
//simulationStep=0.0020000001;				//1.66m  , bullet default 0.050000001; would be 50m which doesnt seem to be the case
submunitionCount=1;
submunitionInitSpeed=1000;					//default for penetrator submunition
submunitionParentSpeedCoef=0;
submunitionConeAngle=0;
submunitionDirectionType="SubmunitionModelDirection";
deleteParentWhenTriggered=0;				//1 would remove explosion etc
triggerOnImpact=1;							//otherwise would trigger on vehicles/cover/terrain
submunitionInitialOffset[]={0,0,-0.2};

warheadName="HE";							//only submun is HEAT penetrator
aiAmmoUsageFlags="64 + 128 + 256 + 512";	//can also engage "512" heavy armor

//can lock on datalink targets
laserLock=1;
irLock=1;
airLock=1;

deflecting=1;								//prevents ricochets, its a proximity fuze afterall
tracerEndTime=4;
model="\A3\Weapons_f\Data\bullettracer\tracer_red";	//not visible for simulation shotSubmunitions