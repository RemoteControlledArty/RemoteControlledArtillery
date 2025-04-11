//Autocannons
class autocannon_30mm_lxWS;
class RC_autocannon_30mm_lxWS_Base: autocannon_30mm_lxWS
{
	class HE;
	class AP;
	class player;
};
class RC_autocannon_30mm_lxWS: RC_autocannon_30mm_lxWS_Base
{
	canLock=2;
	FCSZeroingDelay=0.5;
	name="30mm";

	class HE: HE
	{
		magazines[]=
		{
			"RC_160Rnd_30mm_MP_T_R",
			"RC_160Rnd_30mm_MP_T_G",
			"RC_160Rnd_30mm_MP_T_Y",
			"RC_160Rnd_30mm_GPR_T_R",
			"RC_160Rnd_30mm_GPR_T_G",
			"RC_160Rnd_30mm_GPR_T_Y"
		};

		class player: player
		{
			reloadTime=0.15;
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_160Rnd_30mm_APFSDS_T_R",
			"RC_160Rnd_30mm_APFSDS_T_G",
			"RC_160Rnd_30mm_APFSDS_T_Y"
		};

		class player: player
		{
			reloadTime=0.3;
		};
	};
};


class RC_MMG_93x64_coax_ext;
class RC_MMG_93x64_coax_ext_lxWS: RC_MMG_93x64_coax_ext
{
	weaponLockSystem="1 + 4 + 16";
	
	magazines[]=
	{
		"RC_1000Rnd_93x64_T_G",
		"RC_1000Rnd_93x64_T_R",
		"RC_1000Rnd_93x64_T_Y"
	};
};


/*
class missles_Vorona_vehicles_lxWS;
class RC_missles_Vorona_vehicles_lxWS_Base: missles_Vorona_vehicles_lxWS
{
	class Player;
	class TopDown;
};
class RC_missles_Vorona_vehicles_lxWS: RC_missles_Vorona_vehicles_lxWS_Base
{
	scope=2;
};
*/
