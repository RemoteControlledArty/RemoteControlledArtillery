//minigun
class RC_Pylon_B_338_SLAP_T_R;
class RC_AI_Pylon_B_338_SLAP_T_R: RC_Pylon_B_338_SLAP_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Pylon_B_338_SLAP_T_G: RC_AI_Pylon_B_338_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Pylon_B_338_SLAP_T_Y: RC_AI_Pylon_B_338_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};
class RC_AI_Pylon_B_338_SLAP_T_W: RC_AI_Pylon_B_338_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_white";};


class RC_Pylon_B_127x99_SLAP_T_R;
class RC_AI_Pylon_B_127x99_SLAP_T_R: RC_Pylon_B_127x99_SLAP_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Pylon_B_127x99_SLAP_T_G: RC_AI_Pylon_B_127x99_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Pylon_B_127x99_SLAP_T_Y: RC_AI_Pylon_B_127x99_SLAP_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//autocannon
class RC_Pylon_B_20mm_MP_QF_T_R;
class RC_AI_Pylon_B_20mm_MP_QF_T_R: RC_Pylon_B_20mm_MP_QF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Pylon_B_20mm_MP_QF_T_G: RC_AI_Pylon_B_20mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Pylon_B_20mm_MP_QF_T_Y: RC_AI_Pylon_B_20mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_Pylon_B_25mm_MP_QF_T_R;
class RC_AI_Pylon_B_25mm_MP_QF_T_R: RC_Pylon_B_25mm_MP_QF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Pylon_B_25mm_MP_QF_T_G: RC_AI_Pylon_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Pylon_B_25mm_MP_QF_T_Y: RC_AI_Pylon_B_25mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


class RC_Pylon_B_30mm_MP_QF_T_R;
class RC_AI_Pylon_B_30mm_MP_QF_T_R: RC_Pylon_B_30mm_MP_QF_T_R
{
	laserLock=0;
	irLock=0;
	airLock=1;
};
class RC_AI_Pylon_B_30mm_MP_QF_T_G: RC_AI_Pylon_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_green";};
class RC_AI_Pylon_B_30mm_MP_QF_T_Y: RC_AI_Pylon_B_30mm_MP_QF_T_R {model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";};


//proxy fuze
class RC_AI_Pylon_B_20mm_MP_QF_Proxy_T_R: RC_AI_Pylon_B_20mm_MP_QF_T_R {};
class RC_AI_Pylon_B_20mm_MP_QF_Proxy_T_G: RC_AI_Pylon_B_20mm_MP_QF_T_G {};
class RC_AI_Pylon_B_20mm_MP_QF_Proxy_T_Y: RC_AI_Pylon_B_20mm_MP_QF_T_Y {};

class RC_AI_Pylon_B_25mm_MP_QF_Proxy_T_R: RC_AI_Pylon_B_25mm_MP_QF_T_R {};
class RC_AI_Pylon_B_25mm_MP_QF_Proxy_T_G: RC_AI_Pylon_B_25mm_MP_QF_T_G {};
class RC_AI_Pylon_B_25mm_MP_QF_Proxy_T_Y: RC_AI_Pylon_B_25mm_MP_QF_T_Y {};

class RC_AI_Pylon_B_30mm_MP_QF_Proxy_T_R: RC_AI_Pylon_B_30mm_MP_QF_T_R {};
class RC_AI_Pylon_B_30mm_MP_QF_Proxy_T_G: RC_AI_Pylon_B_30mm_MP_QF_T_G {};
class RC_AI_Pylon_B_30mm_MP_QF_Proxy_T_Y: RC_AI_Pylon_B_30mm_MP_QF_T_Y {};


//rockets
class M_AT;
class RC_AI_Hydra_MP_Proxy: M_AT
{
	//#include "\Remote_Controlled_Artillery\cfgAmmoMagazinesWeapons\includes_ammo\AmmoDatalink_6km.hpp"
	fuseDistance=20;	//50

	submunitionAmmo="ammo_Penetrator_PG_AT";
	submunitionDirectionType="SubmunitionModelDirection";
	submunitionInitSpeed=1000;
	submunitionParentSpeedCoef=0;
	submunitionInitialOffset[]={0,0,-0.2};
	triggerOnImpact=1;

	hit=95;
	indirectHit=40;
	indirectHitRange=8;
};


/*
class RC_Hydra_MP_Proxy;
class RC_AI_Hydra_MP_Proxy: RC_Hydra_MP_Proxy
{
};
*/


//missiles
class RC_DAGR;
class RC_AI_DAGR: RC_DAGR
{
    laserLock=0;
	irLock=0;
	airLock=1;
};


class RC_SRAM;
class RC_AI_SRAM: RC_SRAM
{
    laserLock=0;
	irLock=0;
	airLock=1;
};