/*
class RC_B_30mm_MP_Pen_T_R;
class RC_B_30mm_ABM_Helper: RC_B_30mm_MP_Pen_T_R
{
	indirectHit=6;
	indirectHitRange=4.5;	//6
	//explosionTime=0;
	simulation="shotRocket";
	timeToLive=0;
};
*/
class BWA3_B_30mm_ABM_Helper;
class RC_B_30mm_ABM_Helper: BWA3_B_30mm_ABM_Helper
{
	model="\A3\weapons_f\empty";
	indirectHit=6;
	indirectHitRange=4.5;	//6
	//explosionTime=0;
	simulation="shotRocket";
	timeToLive=0;
};
class RC_B_30mm_MP_Pen_T_R;
class RC_B_30mm_ABM_T_R: RC_B_30mm_MP_Pen_T_R
{
	BWA3_firedAmmoScript="BWA3_fnc_firedABM";
	BWA3_subMunitionType="RC_B_30mm_ABM_Helper";
	deflecting=0;
};
class RC_B_30mm_ABM_T_G: RC_B_30mm_ABM_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_B_30mm_ABM_T_Y: RC_B_30mm_ABM_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};