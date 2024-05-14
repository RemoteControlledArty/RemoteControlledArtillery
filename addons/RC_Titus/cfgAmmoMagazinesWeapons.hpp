class CfgAmmo
{
	class B_127x99_Ball_Tracer_Red;
	class RC_QIN_127x99_T_R: B_127x99_Ball_Tracer_Red
	{
		laserLock=1;
		irLock=1;
		airLock=1;
	};
	class RC_QIN_127x99_T_G: RC_QIN_127x99_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
	};
	class RC_QIN_127x99_T_Y: RC_QIN_127x99_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
	};
};


class CfgMagazines
{
	class RC_QIN_139Rnd_20mm_shells;
	class RC_QIN_139Rnd_20mm: RC_QIN_139Rnd_20mm_shells
	{
		//add tracer
		ammo="";
	};

	class QIN_300Rnd_762x51_Belt;
	class RC_QIN_300Rnd_762x51: QIN_300Rnd_762x51_Belt
	{
		ammo="";
	};

	class 100Rnd_127x99_mag_Tracer_Red;
	class RC_QIN_100Rnd_127x99_T_R: 100Rnd_127x99_mag_Tracer_Red
	{
		ammo="RC_QIN_127x99_T_R";
	};
};


class CfgWeapons
{
	class QIN_M240C;
	class RC_QIN_M240C: QIN_M240C
	{
		canLock=2;
		
		//displayName="M240C";
		ballisticsComputer=2;
		magazines[]=
		{
			"RC_QIN_300Rnd_762x51_Belt"
		};
	};

	class QIN_10M621_20mm;
	class RC_QIN_10M621_20mm: QIN_10M621_20mm
	{
		canLock=2;

		//displayName="10M261 20mm";
		magazines[]=
		{
			"RC_QIN_139Rnd_20mm_shells"
		};
	};

	class RC_QIN_50cal: QIN_10M621_20mm
	{
		canLock=2;

		displayName="12.7mm HMG";
		magazines[]=
		{
			"QIN_100Rnd_127mm"
		};
	};
};