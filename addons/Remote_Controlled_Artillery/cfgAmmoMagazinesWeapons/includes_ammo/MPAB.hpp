explosive=1;			//default 1, likely removes hit value, >0.7 does not penetrate light cover, <0.7 does, 1 is for triggering the spawn of delayed fuze submunition with <0.7 and timer
deleteParentWhenTriggered=1;			//1 for removing explosion and maybe hit value
submunitionInitialOffset[]={0,0,-3.5};	//for delayed submun not to be stuck in object causing bugs
warheadName="HE";
aiAmmoUsageFlags="64 + 128 + 256 + 512";	//can also engage "512" heavy armor

//hit=;								//edit? may affect recoil & if AI engages or not
indirectHit=0;
indirectHitRange=0;
explosionEffects="";				//needed?
//CraterEffects="";					//can bug i think