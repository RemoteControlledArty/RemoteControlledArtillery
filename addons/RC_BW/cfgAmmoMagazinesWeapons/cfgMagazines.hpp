class RC_2Rnd_IFV_MP_LOS;
class RC_2Rnd_SPz_Spike_LOS: RC_2Rnd_IFV_MP_LOS
{
	count=2;
	displayName="4km Spike Direct";
	displayNameShort="Spike Direct";
	ammo="RC_IFV_MP_LOS";
};
class RC_2Rnd_IFV_MP_Overfly;
class RC_2Rnd_SPz_Spike_Overfly: RC_2Rnd_IFV_MP_Overfly
{
	count=2;
	displayName="4km Spike Overfly";
	displayNameShort="Spike Overfly";
	ammo="RC_IFV_MP_Overfly";
};
class RC_2Rnd_IFV_MP_NLOS;
class RC_2Rnd_SPz_Spike_NLOS: RC_2Rnd_IFV_MP_NLOS
{
	count=2;
	displayName="4km Spike NLOS";
	displayNameShort="Spike NLOS";
	ammo="RC_IFV_MP_NLOS";
};
class RC_2Rnd_IFV_AA;
class RC_2Rnd_SPz_Spike_AA: RC_2Rnd_IFV_AA
{
	count=2;
	displayName="5km Spike AA";
	displayNameShort="Spike AA";
	ammo="RC_IFV_AA";
};


class BWA3_160Rnd_ABM_shells;
class RC_160Rnd_30mm_ABM_T_R: BWA3_160Rnd_ABM_shells
{
	count=160;
	ammo="RC_B_30mm_ABM_T_R";
};
class RC_160Rnd_30mm_ABM_T_G: RC_160Rnd_30mm_ABM_T_R {ammo="RC_B_30mm_ABM_T_G";};
class RC_160Rnd_30mm_ABM_T_Y: RC_160Rnd_30mm_ABM_T_R {ammo="RC_B_30mm_ABM_T_Y";};
class RC_100Rnd_30mm_ABM_T_R: RC_160Rnd_30mm_ABM_T_R {count=100;};
class RC_100Rnd_30mm_ABM_T_G: RC_160Rnd_30mm_ABM_T_G {count=100;};
class RC_100Rnd_30mm_ABM_T_Y: RC_160Rnd_30mm_ABM_T_Y {count=100;};


//Fetch
class RC_100Rnd_30mm_APFSDS_T_R;
class RC_100Rnd_30mm_APFSDS_T_G;
class RC_100Rnd_30mm_APFSDS_T_Y;


class RC_100Rnd_30mm_MP_Pen_T_R;
class RC_100Rnd_30mm_MP_Pen_T_G;
class RC_100Rnd_30mm_MP_Pen_T_Y;

class RC_100Rnd_30mm_MP_DF_T_R;
class RC_100Rnd_30mm_MP_DF_T_G;
class RC_100Rnd_30mm_MP_DF_T_Y;

class RC_100Rnd_30mm_MP_QF_T_R;
class RC_100Rnd_30mm_MP_QF_T_G;
class RC_100Rnd_30mm_MP_QF_T_Y;

class RC_100Rnd_30mm_MPAB_DF_T_R;
class RC_100Rnd_30mm_MPAB_DF_T_G;
class RC_100Rnd_30mm_MPAB_DF_T_Y;

class RC_100Rnd_30mm_MPAB_QF_T_R;
class RC_100Rnd_30mm_MPAB_QF_T_G;
class RC_100Rnd_30mm_MPAB_QF_T_Y;


class RC_100Rnd_30mm_HE_Pen_T_R;
class RC_100Rnd_30mm_HE_Pen_T_G;
class RC_100Rnd_30mm_HE_Pen_T_Y;

class RC_100Rnd_30mm_HE_DF_T_R;
class RC_100Rnd_30mm_HE_DF_T_G;
class RC_100Rnd_30mm_HE_DF_T_Y;

class RC_100Rnd_30mm_HE_QF_T_R;
class RC_100Rnd_30mm_HE_QF_T_G;
class RC_100Rnd_30mm_HE_QF_T_Y;

class RC_100Rnd_30mm_HEAB_DF_T_R;
class RC_100Rnd_30mm_HEAB_DF_T_G;
class RC_100Rnd_30mm_HEAB_DF_T_Y;

class RC_100Rnd_30mm_HEAB_QF_T_R;
class RC_100Rnd_30mm_HEAB_QF_T_G;
class RC_100Rnd_30mm_HEAB_QF_T_Y;


class RC_200Rnd_338_T_R;
class RC_200Rnd_338_T_G;
class RC_200Rnd_338_T_Y;


//AP
class RC_160Rnd_30mm_APFSDS_T_R: RC_100Rnd_30mm_APFSDS_T_R
{
    displayNameShort="APFSDS-T";
	count=160;
};
class RC_160Rnd_30mm_APFSDS_T_G: RC_100Rnd_30mm_APFSDS_T_G
{
    displayNameShort="APFSDS-T";
	count=160;
};
class RC_160Rnd_30mm_APFSDS_T_Y: RC_100Rnd_30mm_APFSDS_T_Y
{
    displayNameShort="APFSDS-T";
	count=160;
};


//MP
class RC_160Rnd_30mm_MP_Pen_T_R: RC_100Rnd_30mm_MP_Pen_T_R {count=160; displayNameShort="MP-T";};
class RC_160Rnd_30mm_MP_Pen_T_G: RC_100Rnd_30mm_MP_Pen_T_G {count=160; displayNameShort="MP-T";};
class RC_160Rnd_30mm_MP_Pen_T_Y: RC_100Rnd_30mm_MP_Pen_T_Y {count=160; displayNameShort="MP-T";};

class RC_160Rnd_30mm_MP_DF_T_R: RC_100Rnd_30mm_MP_DF_T_R {count=160; displayNameShort="MP-DF-T";};
class RC_160Rnd_30mm_MP_DF_T_G: RC_100Rnd_30mm_MP_DF_T_G {count=160; displayNameShort="MP-DF-T";};
class RC_160Rnd_30mm_MP_DF_T_Y: RC_100Rnd_30mm_MP_DF_T_Y {count=160; displayNameShort="MP-DF-T";};

class RC_160Rnd_30mm_MP_QF_T_R: RC_100Rnd_30mm_MP_QF_T_R {count=160; displayNameShort="MP-QF-T";};
class RC_160Rnd_30mm_MP_QF_T_G: RC_100Rnd_30mm_MP_QF_T_G {count=160; displayNameShort="MP-QF-T";};
class RC_160Rnd_30mm_MP_QF_T_Y: RC_100Rnd_30mm_MP_QF_T_Y {count=160; displayNameShort="MP-QF-T";};

class RC_160Rnd_30mm_MPAB_DF_T_R: RC_100Rnd_30mm_MPAB_DF_T_R {count=160; displayNameShort="MPAB-DF-T";};
class RC_160Rnd_30mm_MPAB_DF_T_G: RC_100Rnd_30mm_MPAB_DF_T_G {count=160; displayNameShort="MPAB-DF-T";};
class RC_160Rnd_30mm_MPAB_DF_T_Y: RC_100Rnd_30mm_MPAB_DF_T_Y {count=160; displayNameShort="MPAB-DF-T";};

class RC_160Rnd_30mm_MPAB_QF_T_R: RC_100Rnd_30mm_MPAB_QF_T_R {count=160; displayNameShort="MPAB-QF-T";};
class RC_160Rnd_30mm_MPAB_QF_T_G: RC_100Rnd_30mm_MPAB_QF_T_G {count=160; displayNameShort="MPAB-QF-T";};
class RC_160Rnd_30mm_MPAB_QF_T_Y: RC_100Rnd_30mm_MPAB_QF_T_Y {count=160; displayNameShort="MPAB-QF-T";};


//HE
class RC_160Rnd_30mm_HE_Pen_T_R: RC_100Rnd_30mm_HE_Pen_T_R {count=160; displayNameShort="HE-T";};
class RC_160Rnd_30mm_HE_Pen_T_G: RC_100Rnd_30mm_HE_Pen_T_G {count=160; displayNameShort="HE-T";};
class RC_160Rnd_30mm_HE_Pen_T_Y: RC_100Rnd_30mm_HE_Pen_T_Y {count=160; displayNameShort="HE-T";};

class RC_160Rnd_30mm_HE_DF_T_R: RC_100Rnd_30mm_HE_DF_T_R {count=160; displayNameShort="HE-DF-T";};
class RC_160Rnd_30mm_HE_DF_T_G: RC_100Rnd_30mm_HE_DF_T_G {count=160; displayNameShort="HE-DF-T";};
class RC_160Rnd_30mm_HE_DF_T_Y: RC_100Rnd_30mm_HE_DF_T_Y {count=160; displayNameShort="HE-DF-T";};

class RC_160Rnd_30mm_HE_QF_T_R: RC_100Rnd_30mm_HE_QF_T_R {count=160; displayNameShort="HE-QF-T";};
class RC_160Rnd_30mm_HE_QF_T_G: RC_100Rnd_30mm_HE_QF_T_G {count=160; displayNameShort="HE-QF-T";};
class RC_160Rnd_30mm_HE_QF_T_Y: RC_100Rnd_30mm_HE_QF_T_Y {count=160; displayNameShort="HE-QF-T";};

class RC_160Rnd_30mm_HEAB_DF_T_R: RC_100Rnd_30mm_HEAB_DF_T_R {count=160; displayNameShort="HEAB-DF-T";};
class RC_160Rnd_30mm_HEAB_DF_T_G: RC_100Rnd_30mm_HEAB_DF_T_G {count=160; displayNameShort="HEAB-DF-T";};
class RC_160Rnd_30mm_HEAB_DF_T_Y: RC_100Rnd_30mm_HEAB_DF_T_Y {count=160; displayNameShort="HEAB-DF-T";};

class RC_160Rnd_30mm_HEAB_QF_T_R: RC_100Rnd_30mm_HEAB_QF_T_R {count=160; displayNameShort="HEAB-QF-T";};
class RC_160Rnd_30mm_HEAB_QF_T_G: RC_100Rnd_30mm_HEAB_QF_T_G {count=160; displayNameShort="HEAB-QF-T";};
class RC_160Rnd_30mm_HEAB_QF_T_Y: RC_100Rnd_30mm_HEAB_QF_T_Y {count=160; displayNameShort="HEAB-QF-T";};


//MG
class RC_400Rnd_338_T_R: RC_200Rnd_338_T_R {count=400; displayNameShort="8.6x70mm";};
class RC_400Rnd_338_T_G: RC_200Rnd_338_T_G {count=400; displayNameShort="8.6x70mm";};
class RC_400Rnd_338_T_Y: RC_200Rnd_338_T_Y {count=400; displayNameShort="8.6x70mm";};

class RC_600Rnd_338_T_R: RC_400Rnd_338_T_R {count=600;};
class RC_600Rnd_338_T_G: RC_400Rnd_338_T_G {count=600;};
class RC_600Rnd_338_T_Y: RC_400Rnd_338_T_Y {count=600;};