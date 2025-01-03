/*
class EF_B_50mm_HE;
class RC_EF_B_50mm_HEAB_T_R: EF_B_50mm_HE
{	
	EF_AirburstDistance=10;
	deflecting=0;
	aiAmmoUsageFlags="64 + 128 + 256";

	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=5.5;

	indirectHitRange=6.5;
};
*/
class EF_B_50mm_APFSDS;
class RC_EF_B_50mm_APFSDS_T: EF_B_50mm_APFSDS
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=5.5;
};


class EF_B_30mm_HEAB;
class RC_EF_B_50mm_HEAB_T: EF_B_30mm_HEAB
{	
	//EF_AirburstDistance=10;
	//aiAmmoUsageFlags="64 + 128 + 256";

	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=5.5;

	hit=110;
	indirectHit=12;
	indirectHitRange=6.5;
	
	airFriction=-0.0006;
	caliber=7;
	cost=40;
	deflecting=0;
	timeToLive=15;
	warheadname="HE";

	ace_frag_charge = 120;
	ace_frag_classes[] = {"ace_frag_tiny_HD","ace_frag_small_HD"};
	ace_frag_gurney_c = 2700;
	ace_frag_metal = 750;
	ace_rearm_caliber = 40;
	ace_vehicle_damage_incendiary = 0.6;

	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
};