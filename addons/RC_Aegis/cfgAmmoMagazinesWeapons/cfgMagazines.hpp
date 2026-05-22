/*
class 4rnd_Vorona_HEAT_lxWS;
class RC_4rnd_Vorona_HEAT_lxWS: 4rnd_Vorona_HEAT_lxWS
{
	ammo="RC_M_Vorona_HEAT";
	displayName="SACLOS ATGM";
	displayNameShort="SACLOS ATGM";
};
*/


class 5Rnd_25x40mm_airburst;
class RC_6Rnd_30mm_MPAB_DF_T: 5Rnd_25x40mm_airburst
{
	ammo = "RC_M30_30mm_MPAB_DF_T";
	displayName = "6Rnd 30mm MPAB-DF";
	displayNameShort = "30mm MPAB-DF";
	descriptionShort = "Caliber: 30mm MPAB-DF<br />Rounds: 6 <br />Used in: M30 Bolter";

	count = 6;
	//initSpeed = 210;
};
class RC_6Rnd_30mm_MPAB_QF_T: RC_6Rnd_30mm_MPAB_DF_T
{
	ammo = "RC_M30_30mm_MPAB_QF_T";
	displayName = "6Rnd 30mm MPAB-QF";
	displayNameShort = "30mm MPAB-QF";
	descriptionShort = "Caliber: 30mm MPAB-QF<br />Rounds: 6 <br />Used in: M30 Bolter";
};


class 5Rnd_25x40mm_HE;
class RC_6Rnd_30mm_BuckshotClose: 5Rnd_25x40mm_HE
{
	ammo = "RC_M30_30mm_BuckshotClose";
	displayName = "6Rnd 30mm Buckshot (close)";
	displayNameShort = "30mm Buckshot (close)";
	descriptionShort = "Caliber: 30mm Buckshot (close)<br />Rounds: 6 <br />Used in: M30 Bolter";

	count = 6;
	//initSpeed = 210;
	tracersEvery = 0;
};
class RC_6Rnd_30mm_BuckshotFar: RC_6Rnd_30mm_BuckshotClose
{
	ammo = "RC_M30_30mm_BuckshotFar";
	displayName = "6Rnd 30mm Buckshot (far)";
	displayNameShort = "30mm Buckshot (far)";
	descriptionShort = "Caliber: 30mm Buckshot (far)<br />Rounds: 6 <br />Used in: M30 Bolter";
};


class RC_6Rnd_30mm_Seeking: 5Rnd_25x40mm_HE
{
	ammo = "B_25x40mm_autoseek";
	displayName = "6Rnd 30mm Seeking";
	displayNameShort = "30mm Seeking";
	descriptionShort = "Caliber: 30mm Seeking<br />Rounds: 6 <br />Used in: M30 Bolter";

	count = 6;
	//initSpeed = 210;
	tracersEvery = 0;
};