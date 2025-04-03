class B_30mm_APFSDS;
class RC_EF_B_30mm_APFSDS_T_W: B_30mm_APFSDS
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=5.5;
	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
};
class RC_EF_B_30mm_APFSDS_T_R: RC_EF_B_30mm_APFSDS_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_EF_B_30mm_APFSDS_T_G: RC_EF_B_30mm_APFSDS_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_EF_B_30mm_APFSDS_T_Y: RC_EF_B_30mm_APFSDS_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class EF_B_50mm_APFSDS;
class RC_EF_B_50mm_APFSDS_T_W: EF_B_50mm_APFSDS
{
	laserLock=1;
	irLock=1;
	airLock=1;
	tracerEndTime=5.5;
	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
};
class RC_EF_B_50mm_APFSDS_T_R: RC_EF_B_50mm_APFSDS_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_EF_B_50mm_APFSDS_T_G: RC_EF_B_50mm_APFSDS_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_EF_B_50mm_APFSDS_T_Y: RC_EF_B_50mm_APFSDS_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class EF_B_30mm_HEAB;
class RC_EF_B_30mm_HEAB_T_W: EF_B_30mm_HEAB
{
	laserLock=1;
	irLock=1;
	airLock=1;
	indirectHit=7;
	tracerEndTime=5.5;
	
	deflecting=0;
	timeToLive=15;
	warheadname="HE";

	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
};
class RC_EF_B_30mm_HEAB_T_R: RC_EF_B_30mm_HEAB_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_EF_B_30mm_HEAB_T_G: RC_EF_B_30mm_HEAB_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_EF_B_30mm_HEAB_T_Y: RC_EF_B_30mm_HEAB_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class RC_EF_B_50mm_HEAB_T_W: RC_EF_B_30mm_HEAB_T_W
{
	hit=110;
	indirectHit=12;
	indirectHitRange=6.5;
	
	airFriction=-0.0006;
	caliber=7;
	cost=40;

	ace_frag_charge = 120;
	ace_frag_classes[] = {"ace_frag_tiny_HD","ace_frag_small_HD"};
	ace_frag_gurney_c = 2700;
	ace_frag_metal = 750;
	ace_rearm_caliber = 40;
	ace_vehicle_damage_incendiary = 0.6;
};
class RC_EF_B_50mm_HEAB_T_R: RC_EF_B_50mm_HEAB_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_red";
};
class RC_EF_B_50mm_HEAB_T_G: RC_EF_B_50mm_HEAB_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_green";
};
class RC_EF_B_50mm_HEAB_T_Y: RC_EF_B_50mm_HEAB_T_W
{	
	model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
};


class RC_B_338_T_R;
class RC_B_338_T_W: RC_B_338_T_R
{
	model="\A3\Weapons_f\Data\bullettracer\tracer_white";
};