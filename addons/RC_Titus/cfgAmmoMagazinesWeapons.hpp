class CfgAmmo
{
	class B_20mm_Tracer_Red;
	class RC_QIN_20mm_HE_T_R: B_20mm_Tracer_Red
	{
		laserLock=1;
		irLock=1;
		airLock=1;
		tracerStartTime=0.05;
		tracerEndTime=4;
		indirectHitRange=2;
		deflecting=1;
	};
	class RC_QIN_20mm_HE_T_G: RC_QIN_20mm_HE_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
	};
	class RC_QIN_20mm_HE_T_Y: RC_QIN_20mm_HE_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
	};


	class B_20mm_AP;
	class RC_QIN_20mm_AP_T_R: B_20mm_AP
	{
		hit=70;
		caliber=3.8;
		laserLock=1;
		irLock=1;
		airLock=1;
		tracerStartTime=0.05;
		tracerEndTime=4;
		model="\A3\Weapons_f\Data\bullettracer\tracer_red";
	};
	class RC_QIN_20mm_AP_T_G: RC_QIN_20mm_AP_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
	};
	class RC_QIN_20mm_AP_T_Y: RC_QIN_20mm_AP_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
	};


	/*
	class B_127x99_Ball_Tracer_Red;
	class RC_QIN_127x99_T_R: B_127x99_Ball_Tracer_Red
	{
		laserLock=1;
		irLock=1;
		airLock=1;
		tracerStartTime=0.05;
		tracerEndTime=4;
	};
	class RC_QIN_127x99_T_G: RC_QIN_127x99_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
	};
	class RC_QIN_127x99_T_Y: RC_QIN_127x99_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
	};
	*/


	class B_338_NM_Ball;
	class RC_QIN_338_T_R: B_338_NM_Ball
	{
		laserLock=1;
		irLock=1;
		airLock=1;
		tracerStartTime=0.05;
		tracerEndTime=4;
	};
	class RC_QIN_338_T_G: RC_QIN_338_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
	};
	class RC_QIN_338_T_Y: RC_QIN_338_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
	};


	/*
	class 200Rnd_762x51_Belt_Red;
	class RC_QIN_200Rnd_762x51_T_R: 200Rnd_762x51_Belt_Red
	{
		laserLock=1;
		irLock=1;
		airLock=1;
		tracerStartTime=0.05;
		tracerEndTime=4;
	};
	class RC_QIN_200Rnd_762x51_T_G: RC_QIN_200Rnd_762x51_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
	};
	class RC_QIN_200Rnd_762x51_T_Y: RC_QIN_200Rnd_762x51_T_R
	{
		model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
	};
	*/
};


class CfgMagazines
{
	class 1000Rnd_20mm_shells;
	class RC_QIN_100Rnd_20mm_HE_T_R: 1000Rnd_20mm_shells
	{
		ammo="RC_QIN_20mm_HE_T_R";
		displayName="20mm HE-T";
		displayNameShort="20mm HE-T";
		tracersEvery=1;
		count=100;
	};
	class RC_QIN_100Rnd_20mm_HE_T_G: RC_QIN_100Rnd_20mm_HE_T_R
	{
		ammo="RC_QIN_20mm_HE_T_G";
	};
	class RC_QIN_100Rnd_20mm_HE_T_Y: RC_QIN_100Rnd_20mm_HE_T_R
	{
		ammo="RC_QIN_20mm_HE_T_Y";
	};


	class RC_QIN_100Rnd_20mm_AP_T_R: RC_QIN_100Rnd_20mm_HE_T_R
	{
		ammo="RC_QIN_20mm_AP_T_R";
		displayName="20mm AP-T";
		displayNameShort="20mm AP-T";
		initSpeed=1100;
	};
	class RC_QIN_100Rnd_20mm_AP_T_G: RC_QIN_100Rnd_20mm_AP_T_R
	{
		ammo="RC_QIN_20mm_AP_T_G";
	};
	class RC_QIN_100Rnd_20mm_AP_T_Y: RC_QIN_100Rnd_20mm_AP_T_R
	{
		ammo="RC_QIN_20mm_AP_T_Y";
	};


	/*
	class 100Rnd_127x99_mag_Tracer_Red;
	class RC_QIN_100Rnd_127x99_T_R: 100Rnd_127x99_mag_Tracer_Red
	{
		ammo="RC_QIN_127x99_T_R";
		tracersEvery=1;
	};
	class RC_QIN_100Rnd_127x99_T_G: RC_QIN_100Rnd_127x99_T_R
	{
		ammo="RC_QIN_127x99_T_G";
	};
	class RC_QIN_100Rnd_127x99_T_Y: RC_QIN_100Rnd_127x99_T_R
	{
		ammo="RC_QIN_127x99_T_Y";
	};
	class RC_QIN_150Rnd_127x99_T_R: RC_QIN_100Rnd_127x99_T_R
	{
		count=150;
	};
	class RC_QIN_150Rnd_127x99_T_G: RC_QIN_100Rnd_127x99_T_G
	{
		count=150;
	};
	class RC_QIN_150Rnd_127x99_T_Y: RC_QIN_100Rnd_127x99_T_Y
	{
		count=150;
	};
	*/


	class 130Rnd_338_Mag;
	class RC_QIN_150Rnd_338_T_R: 130Rnd_338_Mag
	{
		ammo="RC_QIN_338_T_R";
		displayName=".338 NM";
		displayNameShort=".338 NM";
		tracersEvery=1;
		count=150;
	};
	class RC_QIN_150Rnd_338_T_G: RC_QIN_150Rnd_338_T_R
	{
		ammo="RC_QIN_338_T_G";
	};
	class RC_QIN_150Rnd_338_T_Y: RC_QIN_150Rnd_338_T_R
	{
		ammo="RC_QIN_338_T_Y";
	};


	/*
	class 200Rnd_762x51_Belt_Red;
	class RC_QIN_300Rnd_762x51_T_R: 300Rnd_762x51_Belt_Red
	{
		ammo="RC_QIN_762x51_T_R";
		tracersEvery=1;
		count=300;
	};
	class RC_QIN_300Rnd_762x51_T_G: RC_QIN_300Rnd_762x51_T_R
	{
		ammo="RC_QIN_762x51_T_G";
	};
	class RC_QIN_300Rnd_762x51_T_Y: RC_QIN_300Rnd_762x51_T_R
	{
		ammo="RC_QIN_762x51_T_Y";
	};
	*/
};


class CfgWeapons
{
	class QIN_10M621_20mm;
	class RC_QIN_20mm_AC_base: QIN_10M621_20mm
	{
		class manual;
	};
	class RC_QIN_20mm_AC: RC_QIN_20mm_AC_base
	{
		canLock=2;
		displayName="20mm AC";
		magazineReloadTime=10;

		ballisticsComputer="2 + 16";
		FCSMaxLeadSpeed=30.555599;
		FCSZeroingDelay=1;

		magazines[]=
		{
			"RC_QIN_100Rnd_20mm_HE_T_R",
			"RC_QIN_100Rnd_20mm_HE_T_G",
			"RC_QIN_100Rnd_20mm_HE_T_Y",
			"RC_QIN_100Rnd_20mm_AP_T_R",
			"RC_QIN_100Rnd_20mm_AP_T_G",
			"RC_QIN_100Rnd_20mm_AP_T_Y"
		};

		class manual: manual
		{
			magazineReloadTime=10;
		};
	};


	/*
	class RC_QIN_50cal: QIN_10M621_20mm
	{
		canLock=2;

		displayName="12.7mm HMG";
		magazines[]=
		{
			"QIN_100Rnd_127mm"
		};
	};
	*/


	class QIN_M240C;
	class RC_QIN_338_MMG1: QIN_M240C
	{
		canLock=2;
		displayName=".338 NM MMG";
		magazineReloadTime=10;

		magazines[]=
		{
			"RC_QIN_150Rnd_338_T_R",
			"RC_QIN_150Rnd_338_T_G",
			"RC_QIN_150Rnd_338_T_Y"
		};

		muzzlePos="usti hlavne";
		muzzleEnd="konec hlavne";
		selectionFireAnim="zasleh";

		class GunParticles
		{
			class Effect
			{
				effectName="MachineGun1";
				positionName="Usti hlavne";
				directionName="Konec hlavne";
			};
		};
	};


	class RC_QIN_338_MMG2: QIN_M240C
	{
		canLock=2;
		displayName=".338 NM MMG";
		magazines[]=
		{
			"RC_QIN_150Rnd_338_T_R",
			"RC_QIN_150Rnd_338_T_G",
			"RC_QIN_150Rnd_338_T_Y"
		};
	};


	/*
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
	*/
};