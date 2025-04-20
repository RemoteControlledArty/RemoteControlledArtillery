simulationStep=0.0020000001;		//with max 1330m/s = 2.66m, with 1000m/s = 2m,   bullet default 0.050000001 with max 1330m/s = 66.5m, with 1000m/s = 50m
//!!! min required simulationStep for 7m intesection at 3,55m height of 5m triggerradius for max 1330m/s = 0.005, otherwise will not reliably trigger but pass by !!!

simulation="shotSubmunitions";
//deleteParentWhenTriggered=1;		//1 for removing explosion and maybe hit value
//triggerDistance=5; 				//5m is a good default, REQUIRES simulation "shotsubmunition"

//model="\A3\Weapons_f\Data\bullettracer\tracer_red.p3d"; //model="\A3\Weapons_f\Data\bullettracer\tracer_green.p3d";
//model="\A3\Weapons_F\Ammo\shell.p3d";
model="\A3\Weapons_f\Data\bullettracer\tracer_red";	//not visible for simulation shotSubmunitions

/*
//doublecheck if required for sim shotSubmunitions, or if it causes visual bugs, maybe no negative effects visible due to deleteParentWhenTriggered
effectFly="AmmoClassic";			//mostly AmmoClassic, also bulletbase
muzzleEffect="";					//seems rarely used, but maybe usable to insert script? like muzzleEffect="BIS_fnc_effectFiredRocket";
explosionEffects="ExploAmmoExplosion";
craterEffects="ExploAmmoCrater";
explosionSoundEffect="DefaultExplosion";
*/