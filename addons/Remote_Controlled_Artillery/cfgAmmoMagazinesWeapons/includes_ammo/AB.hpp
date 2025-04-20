//simulationStep=0.0020000001;		//1.66m  , bullet default 0.050000001; would be 50m which doesnt seem to be the case, engine very reliably triggers despite normal simulationStep for shotSubmunitions triggerDistance

simulation="shotSubmunitions";
submunitionCount=1;
submunitionInitSpeed=1000;			//edit?
submunitionParentSpeedCoef=0;
submunitionConeAngle=0;
submunitionDirectionType="SubmunitionModelDirection";
deleteParentWhenTriggered=1;		//1 for removing explosion and maybe hit value
triggerOnImpact=1;					//otherwise would trigger on vehicles/cover/terrain
//triggerDistance=5; 				//5m is a good default, REQUIRES simulation "shotsubmunition"

//can lock on datalink targets
laserLock=1;
irLock=1;
airLock=1;

deflecting=1;						//prevents ricochets, its a proximity fuze afterall
tracerEndTime=4;
model="\A3\Weapons_f\Data\bullettracer\tracer_red";	//not visible for simulation shotSubmunitions

/*
//doublecheck if required for sim shotSubmunitions, or if it causes visual bugs, maybe no negative effects visible due to deleteParentWhenTriggered
effectFly="AmmoClassic";			//mostly AmmoClassic, also bulletbase
muzzleEffect="";					//seems rarely used, but maybe usable to insert script? like muzzleEffect="BIS_fnc_effectFiredRocket";
explosionEffects="ExploAmmoExplosion";
craterEffects="ExploAmmoCrater";
explosionSoundEffect="DefaultExplosion";
*/