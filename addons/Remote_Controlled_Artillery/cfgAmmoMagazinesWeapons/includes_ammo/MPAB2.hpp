simulation="shotSubmunitions";
//simulationStep=0.0020000001;			//1.66m  , bullet default 0.050000001; would be 50m which doesnt seem to be the case
submunitionCount=1;
submunitionInitSpeed=1000;				//edit?
submunitionParentSpeedCoef=0;
submunitionConeAngle=0;
submunitionDirectionType="SubmunitionModelDirection";
deleteParentWhenTriggered=1;			//1 for removing explosion and maybe hit value
triggerOnImpact=1;						//otherwise would trigger on vehicles/cover/terrain
submunitionInitialOffset[]={0,0,-3.5};	//min 3 required to not bug
triggerDistance=5; 						//5m as default, REQUIRES simulation "shotsubmunition"

model="\A3\Weapons_f\Data\bullettracer\tracer_red";	//not visible for simulation shotSubmunitions

//doublecheck if required for sim shotSubmunitions, or if it causes visual bugs, maybe no negative effects visible due to deleteParentWhenTriggered
effectFly="AmmoClassic";
muzzleEffect="";
explosionEffects="ExploAmmoExplosion";
craterEffects="ExploAmmoCrater";
explosionSoundEffect="DefaultExplosion";

explosive=1;			//default 1, likely removes hit value, >0.7 does not penetrate light cover, <0.7 does, 1 is for triggering the spawn of delayed fuze submunition with <0.7 and timer
//hit=;					//edit? may affect recoil & if AI engages or not
indirectHit=0;
indirectHitRange=0;
explosionEffects="";	//needed?
//CraterEffects="";		//can bug i think

laserLock=1;
irLock=1;
airLock=1;
deflecting=1;
tracerEndTime=4;
warheadName="HE";
aiAmmoUsageFlags="64 + 128 + 256 + 512";
