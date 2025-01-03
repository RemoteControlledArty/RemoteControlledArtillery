class Default;
class RC_target_confirmer: Default
{
	scope=2;
	displayName="explosive charge";
	displayNameShort="explosive charge";
	magazines[]=
	{
		"RC_target_confirmer_mag"
	};
	canLock=2;
};


//vehicle laser designator that can lock datalink targets *needs modded mag, which sadly would likely break simple grid designator
class Laserdesignator_mounted;
class RC_Laserdesignator_mounted: Laserdesignator_mounted
{
	author="Ascent";
	canLock=2;

	/*
	magazines[]=
	{
		"RC_Laserbatteries"
	};
	*/
};
class Laserdesignator_vehicle;
class RC_Laserdesignator_vehicle: Laserdesignator_vehicle
{
	author="Ascent";
	canLock=2;

	/*
	magazines[]=
	{
		"RC_Laserbatteries"
	};
	*/
};


//Improved Handheld Laser Designators
class Laserdesignator;
class Laserdesignator_base: Laserdesignator
{
	class Components;
	scope=0;
	scopeCurator=0;
	scopeArsenal=0;
};
class Improved_FOV_Laserdesignator_A: Laserdesignator_base
{
	scope=2;
	scopeCurator=2;
	scopeArsenal=2;

	author="Ascent";
	displayName="Improved Laser Designator";
	magazines[]=
	{
		"Laserbatteries",
		"Laserbatteries"
	};
	visionMode[]=
	{
		"Normal",
		"NVG"
	};
	opticsZoomMin=0.01;
	opticsZoomMax=0.25;
	opticsZoomInit=0.25;
};
class Improved_FOV_Laserdesignator_WD: Improved_FOV_Laserdesignator_A
{
	model="\A3\Weapons_F\Binocular\laserdesignator_01_khk_f.p3d";
	picture="\A3\Weapons_F_Exp\Binocular\Data\UI\icon_Laserdesignator_01_khk_x_ca.paa";
};


// Thermal Improved Laser Designators
class Improved_FOV_Laserdesignator_Ti_A: Improved_FOV_Laserdesignator_A
{
	displayName="Improved Laser Designator TI";
	visionMode[]=
	{
		"Normal",
		"NVG",
		"TI"
	};
	thermalMode[]={0};
};
class Improved_FOV_Laserdesignator_Ti_WD: Improved_FOV_Laserdesignator_Ti_A
{
	model="\A3\Weapons_F\Binocular\laserdesignator_01_khk_f.p3d";
	picture="\A3\Weapons_F_Exp\Binocular\Data\UI\icon_Laserdesignator_01_khk_x_ca.paa";
};


class launch_Vorona_base_F;
class RC_ATGM_SACLOS: launch_Vorona_base_F
{
	scope=1;
	displayName="SACLOS ATGM";
	displayNameShort="SACLOS ATGM";
	canLock=2;
	weaponLockSystem="1 + 4 + 16";
	reloadTime=7;
	magazineReloadTime=7;
	autoReload=1;	
	magazines[]=
	{
		"RC_1Rnd_ATGM_MP_SACLOS"
	};
};
class missiles_titan_static;
class RC_ATGM_Lock: missiles_titan_static
{
	scope=1;
	displayName="ATGM";
	displayNameShort="ATGM";
	canLock=2;
	weaponLockSystem="1 + 4 + 16";
	reloadTime=7;
	magazineReloadTime=7;
	magazines[]=
	{
		"RC_1Rnd_ATGM_MP_Lock"
	};
};
class missiles_titan;
class RC_IFV_Missile_Launcher_Base: missiles_titan
{
	class Player;
	class TopDown;
};
class RC_IFV_Missile_Launcher: RC_IFV_Missile_Launcher_Base
{
	scope=1;
	canLock=2;
	weaponLockSystem="2 + 4 + 16";
	displayName="NLOS ML";
	displayNameShort="NLOS ML";
	magazineReloadTime=20;
	cmImmunity=0.67;
	magazines[]=
	{
		"RC_2Rnd_IFV_MP_NLOS",
		"2Rnd_GAT_missiles",
		"RC_2Rnd_IFV_AA"
	};
	class Player: Player
	{
		magazineReloadTime=20;

		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Missile_Launcher\Titan",
				1.4125376,
				1,
				1100
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
			soundSetShot[]=
			{
				"Launcher_Vorona_Shot_SoundSet",
				"Launcher_Vorona_Tail_SoundSet"
			};
		};
	};
	class TopDown: TopDown
	{
		magazineReloadTime=20;

		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Missile_Launcher\Titan",
				1.4125376,
				1,
				1100
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
			soundSetShot[]=
			{
				"Launcher_Vorona_Shot_SoundSet",
				"Launcher_Vorona_Tail_SoundSet"
			};
		};
	};
};


//Vehicle MMG's
class HMG_127;
class RC_MG_Base: HMG_127
{
	class manual;
};
class RC_HMG_127x99: RC_MG_Base
{
	author="Ascent";
	//displayName="HMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazines[]=
	{
		"RC_100Rnd_127x99_SLAP_T_R",
		"RC_100Rnd_127x99_SLAP_T_G",
		"RC_100Rnd_127x99_SLAP_T_Y",
		"RC_100Rnd_127x99_T_R",
		"RC_100Rnd_127x99_T_G",
		"RC_100Rnd_127x99_T_Y"
	};
	class manual: manual
	{
		//displayName="HMG";
		dispersion=0.001;
	};
};


class HMG_127_AFV;
class RC_MG_FSV_Base: HMG_127_AFV
{
	class manual;
};
class RC_HMG_127x99_FSV: RC_MG_FSV_Base
{
	author="Ascent";
	displayName="HMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazines[]=
	{
		"RC_200Rnd_127x99_T_R",
		"RC_200Rnd_127x99_T_G",
		"RC_200Rnd_127x99_T_Y",
		"RC_200Rnd_127x99_SLAP_T_R",
		"RC_200Rnd_127x99_SLAP_T_G",
		"RC_200Rnd_127x99_SLAP_T_Y"
	};
	class manual: manual
	{
		displayName="12.7mm";
		dispersion=0.001;
	};
};
class RC_MMG_338_FSV: RC_MG_FSV_Base
{
	author="Ascent";
	displayName="MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazineReloadTime=10;
	reloadTime=0.0857;
	magazines[]=
	{
		"RC_200Rnd_338_T_R",
		"RC_200Rnd_338_T_G",
		"RC_200Rnd_338_T_Y"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
		reloadTime=0.0857;
	};
};
class RC_MMG_338_FSV_coax: RC_MMG_338_FSV
{
	displayName="coaxial MMG";

	class GunParticles
	{
		class effect1
		{
			positionName="muzzle_2_beg";
			directionName="muzzle_2_end";
			effectName="MachineGunCloud";
		};
	};
};


class HMG_127_MBT;
class RC_MG_MBT_Base: HMG_127_MBT
{
	class manual;
};
class RC_HMG_127x99_MBT: RC_MG_MBT_Base
{
	author="Ascent";
	displayName="HMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazines[]=
	{
		"RC_200Rnd_127x99_T_R",
		"RC_200Rnd_127x99_T_G",
		"RC_200Rnd_127x99_T_Y",
		"RC_200Rnd_127x99_SLAP_T_R",
		"RC_200Rnd_127x99_SLAP_T_G",
		"RC_200Rnd_127x99_SLAP_T_Y"
	};
	class manual: manual
	{
		//displayName=".338 NM";
		dispersion=0.001;
		reloadTime=0.1;
	};
};
class RC_MMG_338_MBT: RC_MG_MBT_Base
{
	author="Ascent";
	displayName="MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	reloadTime=0.0857;
	magazineReloadTime=10;
	magazines[]=
	{
		"RC_200Rnd_338_T_R",
		"RC_200Rnd_338_T_G",
		"RC_200Rnd_338_T_Y"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
		reloadTime=0.0857;
	};
};
class RC_MMG_338_MBT_coax: RC_MMG_338_MBT
{
	displayName="coaxial MMG";

	class GunParticles
	{
		class effect1
		{
			positionName="usti hlavne3";
			directionName="konec hlavne3";
			effectName="MachineGunCloud";
		};
	};
};
class RC_MMG_338_MBT_Merkava_coax: RC_MMG_338_MBT_coax
{
	class GunParticles
	{
		class effect1
		{
			directionName="konec hlavne2";
			effectName="MachineGunCloud";
			positionName="usti hlavne2";
		};
	};
};


class LMG_coax;
class RC_MMG_338_coax_Base: LMG_coax
{
	class manual;
};
class RC_MMG_338_coax: RC_MMG_338_coax_Base
{
	author="Ascent";
	displayName="coaxial MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazines[]=
	{
		"RC_200Rnd_338_T_R",
		"RC_200Rnd_338_T_G",
		"RC_200Rnd_338_T_Y"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
		reloadTime=0.0857;
	};
};
class RC_MMG_93x64_coax: RC_MMG_338_coax
{
	magazines[]=
	{
		"RC_200Rnd_93x64_T_G",
		"RC_200Rnd_93x64_T_R",
		"RC_200Rnd_93x64_T_Y",
		"RC_1000Rnd_93x64_T_G",
		"RC_1000Rnd_93x64_T_R",
		"RC_1000Rnd_93x64_T_Y"
	};
	class manual: manual
	{
		displayName="9.3x64mm";
	};
};


class LMG_coax_ext;
class RC_MMG_338_coax_ext_Base: LMG_coax_ext
{
	class manual;
};
class RC_MMG_338_coax_ext: RC_MMG_338_coax_ext_Base
{
	author="Ascent";
	displayName="coaxial MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.5;
	magazines[]=
	{
		"RC_200Rnd_338_T_R",
		"RC_200Rnd_338_T_G",
		"RC_200Rnd_338_T_Y"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
		reloadTime=0.0857;
	};
};
class RC_MMG_93x64_coax_ext: RC_MMG_338_coax_ext
{
	magazines[]=
	{
		"RC_200Rnd_93x64_T_G",
		"RC_200Rnd_93x64_T_R",
		"RC_200Rnd_93x64_T_Y",
		"RC_1000Rnd_93x64_T_G",
		"RC_1000Rnd_93x64_T_R",
		"RC_1000Rnd_93x64_T_Y"
	};
	class manual: manual
	{
		displayName="9.3x64mm";
	};
};


class HMG_127_APC;
class HMG_127_APC_Base: HMG_127_APC
{
	class manual;
};
class RC_HMG_127_APC: HMG_127_APC_Base
{
	author="Ascent";
	displayName="HMG";
	canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=3000;

	class manual: manual
	{
		displayName="12.7mm HMG";
		dispersion=0.001;
	};

	magazines[]=
	{
		"RC_200Rnd_127x99_SLAP_T_R",
		"RC_200Rnd_127x99_SLAP_T_G",
		"RC_200Rnd_127x99_SLAP_T_Y",
		"RC_100Rnd_127x99_SLAP_T_R",
		"RC_100Rnd_127x99_SLAP_T_G",
		"RC_100Rnd_127x99_SLAP_T_Y"
	};
};
class RC_HMG_127_APC2: RC_HMG_127_APC
{
	magazines[]=
	{
		"RC_200Rnd_127x99_SLAP_T_R",
		"RC_200Rnd_127x99_SLAP_T_G",
		"RC_200Rnd_127x99_SLAP_T_Y",
		"RC_100Rnd_127x99_SLAP_T_R",
		"RC_100Rnd_127x99_SLAP_T_G",
		"RC_100Rnd_127x99_SLAP_T_Y",
		"RC_200Rnd_127x99_T_R",
		"RC_200Rnd_127x99_T_G",
		"RC_200Rnd_127x99_T_Y"
	};
};
class RC_MMG_338_APC: RC_HMG_127_APC
{
	displayName="MMG";
	maxZeroing=3000;
	reloadTime=0.0857;
	magazineReloadTime=10;

	magazines[]=
	{
		"RC_200Rnd_338_T_R",
		"RC_200Rnd_338_T_G",
		"RC_200Rnd_338_T_Y"
	};

	class manual: manual
	{
		displayName=".338 NM";
		reloadTime=0.0857;
	};
};
class RC_MMG_93x64_APC: RC_MMG_338_APC
{
	displayName="MMG";

	magazines[]=
	{
		"RC_200Rnd_93x64_T_R",
		"RC_200Rnd_93x64_T_G",
		"RC_200Rnd_93x64_T_Y"
	};

	class manual: manual
	{
		displayName="9.3x64mm";
	};
};


class HMG_NSVT;
class HMG_NSVT_Base: HMG_NSVT
{
	class manual;
};
class RC_HMG_127_NSVT: HMG_NSVT_Base
{
	author="Ascent";
	displayName="NSVT";
	canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=3000;

	class manual: manual
	{
		displayName="12.7mm";
		dispersion=0.001;
		reloadTime=0.1;
	};

	magazines[]=
	{
		"RC_150Rnd_127x99_T_R",
		"RC_150Rnd_127x99_T_G",
		"RC_150Rnd_127x99_T_Y",
		"RC_150Rnd_127x99_SLAP_T_R",
		"RC_150Rnd_127x99_SLAP_T_G",
		"RC_150Rnd_127x99_SLAP_T_Y"
	};
};


//GMG
class GMG_40mm;
class GMG_40mm_Base: GMG_40mm
{
	class manual;
};
class RC_GMG_40mm: GMG_40mm_Base
{
	author="Ascent";
	canLock=2;
	FCSZeroingDelay=0.5;

	class manual: manual
	{
		dispersion=0.0025;
	};

	magazines[]=
	{
		"RC_100Rnd_40mm_G_belt",
		"RC_75Rnd_40mm_G_belt",
		"RC_50Rnd_40mm_G_belt"
	};
};


//Autocannons
class autocannon_30mm_CTWS;
class RC_autocannon_30mm_CTWS_Base: autocannon_30mm_CTWS
{
	class HE;
	class AP;
	class player;
};
class RC_autocannon_20mm_CTWS: RC_autocannon_30mm_CTWS_Base
{
	author="Ascent";
	displayName="20mm AC";
	canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=3000;

	class HE: HE
	{
		displayName="20mm AC";
		magazineReloadTime=20;
		maxZeroing=3000;

		magazines[]=
		{
			"100Rnd_20mm_HE_T_R",
			"100Rnd_20mm_HE_T_G",
			"100Rnd_20mm_HE_T_Y"
		};
		class player: player
		{
			reloadTime=0.25;
		};
	};
	class AP: AP
	{
		displayName="20mm AC";
		magazineReloadTime=20;
		maxZeroing=3000;

		magazines[]=
		{
			"100Rnd_20mm_AP_T_R",
			"100Rnd_20mm_AP_T_G",
			"100Rnd_20mm_AP_T_Y",
			"100Rnd_20mm_APFSDS_T_R",
			"100Rnd_20mm_APFSDS_T_G",
			"100Rnd_20mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.2;
		};
	};

	class GunParticles
	{
		class Effect
		{
			effectName="AutoCannonFired";
			positionName="Usti hlavne";
			directionName="Konec hlavne";
		};
	};
};


class cannon_20mm;
class RC_autocannon_20mm_Base: cannon_20mm
{
	class HE;
	class AP;
	class player;
};
class RC_autocannon_20mm: RC_autocannon_20mm_Base
{
	author="Ascent";
	displayName="20mm AC";
	canLock=2;
	FCSZeroingDelay=0.5;
	maxZeroing=3000;
	FCSMaxLeadSpeed=30.555599;

	class HE: HE
	{
		displayName="20mm AC";
		magazineReloadTime=15;
		maxZeroing=3000;

		magazines[]=
		{
			"60Rnd_20mm_HE_T_R",
			"60Rnd_20mm_HE_T_G",
			"60Rnd_20mm_HE_T_Y"
		};
		class player: player
		{
			reloadTime=0.25;
		};
	};
	class AP: AP
	{
		displayName="20mm AC";
		magazineReloadTime=15;
		maxZeroing=3000;

		magazines[]=
		{
			"60Rnd_20mm_AP_T_R",
			"60Rnd_20mm_AP_T_G",
			"60Rnd_20mm_AP_T_Y",
			"60Rnd_20mm_APFSDS_T_R",
			"60Rnd_20mm_APFSDS_T_G",
			"60Rnd_20mm_APFSDS_T_Y"
		};
		class player: player
		{
			reloadTime=0.2;
		};
	};
};


class RC_autocannon_30mm_CTWS: RC_autocannon_30mm_CTWS_Base
{
	author="Ascent";
	canLock=2;
	FCSZeroingDelay=0.5;

	class HE: HE
	{
		magazines[]=
		{
			"RC_100Rnd_30mm_MP_T_R",
			"RC_100Rnd_30mm_MP_T_G",
			"RC_100Rnd_30mm_MP_T_Y",
			"RC_100Rnd_30mm_GPR_T_R",
			"RC_100Rnd_30mm_GPR_T_G",
			"RC_100Rnd_30mm_GPR_T_Y"
			//"RC_100Rnd_30mm_Smoke"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_100Rnd_30mm_APFSDS_T_R",
			"RC_100Rnd_30mm_APFSDS_T_G",
			"RC_100Rnd_30mm_APFSDS_T_Y"
		};
	};
};


//Warrior AC
class autocannon_30mm;
class RC_autocannon_30mm_base: autocannon_30mm
{
	class HE;
	class AP;
};
class RC_autocannon_30mm: RC_autocannon_30mm_base
{
	author="Ascent";
	canLock=2;
	FCSZeroingDelay=0.5;

	class HE: HE
	{
		magazines[]=
		{
			"RC_100Rnd_30mm_MP_T_R",
			"RC_100Rnd_30mm_MP_T_G",
			"RC_100Rnd_30mm_MP_T_Y",
			"RC_100Rnd_30mm_GPR_T_R",
			"RC_100Rnd_30mm_GPR_T_G",
			"RC_100Rnd_30mm_GPR_T_Y"
			//"RC_100Rnd_30mm_Smoke"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_100Rnd_30mm_APFSDS_T_R",
			"RC_100Rnd_30mm_APFSDS_T_G",
			"RC_100Rnd_30mm_APFSDS_T_Y"
		};
	};
};


class autocannon_40mm_CTWS;
class RC_autocannon_40mm_CTWS_Base: autocannon_40mm_CTWS
{
	class HE;
	class AP;
};
class RC_autocannon_40mm_CTWS: RC_autocannon_40mm_CTWS_Base
{
	author="Ascent";
	canLock=2;
	FCSZeroingDelay=0.5;

	class HE: HE
	{
		magazines[]=
		{
			"RC_50Rnd_40mm_MP_T_R",
			"RC_50Rnd_40mm_MP_T_G",
			"RC_50Rnd_40mm_MP_T_Y",
			"RC_50Rnd_40mm_GPR_T_R",
			"RC_50Rnd_40mm_GPR_T_G",
			"RC_50Rnd_40mm_GPR_T_Y"
			//"RC_50Rnd_40mm_Smoke"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_50Rnd_40mm_APFSDS_T_R",
			"RC_50Rnd_40mm_APFSDS_T_G",
			"RC_50Rnd_40mm_APFSDS_T_Y"
		};
	};
};


class autocannon_30mm_RCWS;
class RC_autocannon_30mm_RCWS: autocannon_30mm_RCWS
{
	author="Ascent";
	canLock=2;
	FCSZeroingDelay=0.5;

	magazines[]=
	{
		"RC_60Rnd_30mm_MP_T_G",
		"RC_60Rnd_30mm_MP_T_R",
		"RC_60Rnd_30mm_MP_T_Y",
		"RC_60Rnd_30mm_GPR_T_G",
		"RC_60Rnd_30mm_GPR_T_R",
		"RC_60Rnd_30mm_GPR_T_Y"
	};
};


//120mm direct fire
class cannon_120mm;
class RC_cannon_120mm: cannon_120mm
{
	displayName="120mm";
	canLock=2;
	reloadTime=5;
	magazineReloadTime=5;
	FCSZeroingDelay=0.5;
	FCSMaxLeadSpeed=30;
	//showAimCursorInternal=1; //which effect? maybe coordination improving?
	magazines[]=
	{
		"RC_10Rnd_120mm_APFSDS_T_R",
		"RC_15Rnd_120mm_APFSDS_T_R",
		"RC_20Rnd_120mm_APFSDS_T_R",
		"RC_10Rnd_120mm_APFSDS_T_G",
		"RC_15Rnd_120mm_APFSDS_T_G",
		"RC_20Rnd_120mm_APFSDS_T_G",
		"RC_10Rnd_120mm_APFSDS_T_Y",
		"RC_15Rnd_120mm_APFSDS_T_Y",
		"RC_20Rnd_120mm_APFSDS_T_Y",
		"RC_10Rnd_120mm_MP_T_R",
		"RC_15Rnd_120mm_MP_T_R",
		"RC_20Rnd_120mm_MP_T_R",
		"RC_10Rnd_120mm_MP_T_G",
		"RC_15Rnd_120mm_MP_T_G",
		"RC_20Rnd_120mm_MP_T_G",
		"RC_10Rnd_120mm_MP_T_Y",
		"RC_15Rnd_120mm_MP_T_Y",
		"RC_20Rnd_120mm_MP_T_Y",
		"RC_4Rnd_120mm_DLG_cannon_missiles",
		"RC_3Rnd_120mm_DLG_cannon_missiles",
		"RC_2Rnd_120mm_DLG_cannon_missiles",
		"RC_1Rnd_120mm_DLG_cannon_missiles"
	};
};


class cannon_125mm_advanced;
class cannon_125mm_advanced_base: cannon_125mm_advanced
{
	class player;
};
class RC_cannon_125mm_advanced: cannon_125mm_advanced_base
{
	displayName="125mm";
	canLock=2;
	//showAimCursorInternal=1; //which effect? maybe coordination improving?
	magazines[]=
	{
		"RC_10Rnd_125mm_APFSDS_T_R",
		"RC_15Rnd_125mm_APFSDS_T_R",
		"RC_20Rnd_125mm_APFSDS_T_R",
		"RC_10Rnd_125mm_APFSDS_T_G",
		"RC_15Rnd_125mm_APFSDS_T_G",
		"RC_20Rnd_125mm_APFSDS_T_G",
		"RC_10Rnd_125mm_APFSDS_T_Y",
		"RC_15Rnd_125mm_APFSDS_T_Y",
		"RC_20Rnd_125mm_APFSDS_T_Y",
		"RC_10Rnd_125mm_MP_T_R",
		"RC_15Rnd_125mm_MP_T_R",
		"RC_20Rnd_125mm_MP_T_R",
		"RC_10Rnd_125mm_MP_T_G",
		"RC_15Rnd_125mm_MP_T_G",
		"RC_20Rnd_125mm_MP_T_G",
		"RC_10Rnd_125mm_MP_T_Y",
		"RC_15Rnd_125mm_MP_T_Y",
		"RC_20Rnd_125mm_MP_T_Y",
		"RC_3Rnd_125mm_DLG_cannon_missiles",
		"4Rnd_125mm_cannon_missiles"
	};

	class TopDown: player
	{
		textureType="topDown";
		displayName="$STR_A3_FireMode_TopDown0";
		minRange=150;
		minRangeProbab=0.40000001;
		midRange=400;
		midRangeProbab=0.94999999;
		maxRange=8000;
		maxRangeProbab=0.94999999;
	};

	modes[]=
	{
		"player",
		"topDown",
		"close",
		"short",
		"medium",
		"far"
	};
};
class RC_cannon_125mm: RC_cannon_125mm_advanced
{
	reloadTime=6;
	magazineReloadTime=6;

	class player: player
	{
		reloadTime=6;
	};
};


/*
//for later use
class BombDemine_01_F;
class RC_BombDemine_01_F: BombDemine_01_F
{
	displayName="$STR_A3_CfgWeapons_BombDemine_01_F0";
	magazines[]=
	{
		"RC_PylonRack_4Rnd_BombDemine_01_F",
		"PylonRack_4Rnd_BombDemine_01_Dummy_F"
	};
	autoFire=0;
	reloadTime=0;
	cursorAim="";
	sounds[]=
	{
		"Bomb_Demine_Release"
	};
	class Bomb_Demine_Release
	{
		Bomb_Demine_Release_01[]=
		{
			"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Release_01",
			3.9810717,
			1,
			20
		};
		Bomb_Demine_Release_02[]=
		{
			"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Release_02",
			3.9810717,
			1,
			20
		};
		Bomb_Demine_Release_03[]=
		{
			"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Release_03",
			3.9810717,
			1,
			20
		};
		Bomb_Demine_Release_04[]=
		{
			"A3\Sounds_F_Orange\Vehicles\Air\UAV_06\UAV_6_DemineDrone_Bomb_Release_04",
			3.9810717,
			1,
			20
		};
		soundBegin[]=
		{
			"Bomb_Demine_Release_01",
			0.25,
			"Bomb_Demine_Release_02",
			0.25,
			"Bomb_Demine_Release_03",
			0.25,
			"Bomb_Demine_Release_04",
			0.25
		};
	};
	modes[]=
	{
		"this"
	};
	class EventHandlers
	{
		fired="_this call bis_fnc_firedBombDemine;";
	};
};
*/


// 82mm Mortar 4km
class mortar_82mm;
class mortar_82mm_base: mortar_82mm
{
	class Single1;
	class Single2;
	class Single3;
	class Burst1;
	class Burst2;
	class Burst3;
};
class RC_mortar_82mm_V1: mortar_82mm_base
{
	magazines[]=
	{
		"RC_1Rnd_82mm_Mo_shells",
		"RC_2Rnd_82mm_Mo_shells",
		"RC_3Rnd_82mm_Mo_shells",
		"RC_4Rnd_82mm_Mo_shells",
		"RC_5Rnd_82mm_Mo_shells",
		"RC_6Rnd_82mm_Mo_shells",
		"RC_7Rnd_82mm_Mo_shells",
		"RC_8Rnd_82mm_Mo_shells",
		"RC_9Rnd_82mm_Mo_shells",
		"RC_10Rnd_82mm_Mo_shells",
		"RC_11Rnd_82mm_Mo_shells",
		"RC_12Rnd_82mm_Mo_shells",
		"RC_13Rnd_82mm_Mo_shells",
		"RC_14Rnd_82mm_Mo_shells",
		"RC_15Rnd_82mm_Mo_shells",
		"RC_16Rnd_82mm_Mo_shells",
		"RC_17Rnd_82mm_Mo_shells",
		"RC_18Rnd_82mm_Mo_shells",
		"RC_19Rnd_82mm_Mo_shells",
		"RC_20Rnd_82mm_Mo_shells",
		"RC_21Rnd_82mm_Mo_shells",
		"RC_22Rnd_82mm_Mo_shells",
		"RC_23Rnd_82mm_Mo_shells",
		"RC_24Rnd_82mm_Mo_shells",
		"RC_25Rnd_82mm_Mo_shells",
		"RC_26Rnd_82mm_Mo_shells",
		"RC_27Rnd_82mm_Mo_shells",
		"RC_28Rnd_82mm_Mo_shells",
		"RC_29Rnd_82mm_Mo_shells",
		"RC_30Rnd_82mm_Mo_shells",
		"RC_31Rnd_82mm_Mo_shells",
		"RC_32Rnd_82mm_Mo_shells",
		"RC_33Rnd_82mm_Mo_shells",
		"RC_34Rnd_82mm_Mo_shells",
		"RC_35Rnd_82mm_Mo_shells",
		"RC_36Rnd_82mm_Mo_shells",
		"RC_37Rnd_82mm_Mo_shells",
		"RC_38Rnd_82mm_Mo_shells",
		"RC_39Rnd_82mm_Mo_shells",
		"RC_40Rnd_82mm_Mo_shells",

		"RC_1Rnd_82mm_Mo_HEAB",
		"RC_2Rnd_82mm_Mo_HEAB",
		"RC_3Rnd_82mm_Mo_HEAB",
		"RC_4Rnd_82mm_Mo_HEAB",
		"RC_5Rnd_82mm_Mo_HEAB",
		"RC_6Rnd_82mm_Mo_HEAB",
		"RC_7Rnd_82mm_Mo_HEAB",
		"RC_8Rnd_82mm_Mo_HEAB",
		"RC_9Rnd_82mm_Mo_HEAB",
		"RC_10Rnd_82mm_Mo_HEAB",
		"RC_11Rnd_82mm_Mo_HEAB",
		"RC_12Rnd_82mm_Mo_HEAB",
		"RC_13Rnd_82mm_Mo_HEAB",
		"RC_14Rnd_82mm_Mo_HEAB",
		"RC_15Rnd_82mm_Mo_HEAB",
		"RC_16Rnd_82mm_Mo_HEAB",
		"RC_17Rnd_82mm_Mo_HEAB",
		"RC_18Rnd_82mm_Mo_HEAB",
		"RC_19Rnd_82mm_Mo_HEAB",
		"RC_20Rnd_82mm_Mo_HEAB",
		"RC_21Rnd_82mm_Mo_HEAB",
		"RC_22Rnd_82mm_Mo_HEAB",
		"RC_23Rnd_82mm_Mo_HEAB",
		"RC_24Rnd_82mm_Mo_HEAB",
		"RC_25Rnd_82mm_Mo_HEAB",
		"RC_26Rnd_82mm_Mo_HEAB",
		"RC_27Rnd_82mm_Mo_HEAB",
		"RC_28Rnd_82mm_Mo_HEAB",
		"RC_29Rnd_82mm_Mo_HEAB",
		"RC_30Rnd_82mm_Mo_HEAB",
		"RC_31Rnd_82mm_Mo_HEAB",
		"RC_32Rnd_82mm_Mo_HEAB",
		"RC_33Rnd_82mm_Mo_HEAB",
		"RC_34Rnd_82mm_Mo_HEAB",
		"RC_35Rnd_82mm_Mo_HEAB",
		"RC_36Rnd_82mm_Mo_HEAB",
		"RC_37Rnd_82mm_Mo_HEAB",
		"RC_38Rnd_82mm_Mo_HEAB",
		"RC_39Rnd_82mm_Mo_HEAB",
		"RC_40Rnd_82mm_Mo_HEAB",

		"RC_1Rnd_82mm_Mo_lowHEAB",
		"RC_2Rnd_82mm_Mo_lowHEAB",
		"RC_3Rnd_82mm_Mo_lowHEAB",
		"RC_4Rnd_82mm_Mo_lowHEAB",
		"RC_5Rnd_82mm_Mo_lowHEAB",
		"RC_6Rnd_82mm_Mo_lowHEAB",
		"RC_7Rnd_82mm_Mo_lowHEAB",
		"RC_8Rnd_82mm_Mo_lowHEAB",
		"RC_9Rnd_82mm_Mo_lowHEAB",
		"RC_10Rnd_82mm_Mo_lowHEAB",
		"RC_11Rnd_82mm_Mo_lowHEAB",
		"RC_12Rnd_82mm_Mo_lowHEAB",
		"RC_13Rnd_82mm_Mo_lowHEAB",
		"RC_14Rnd_82mm_Mo_lowHEAB",
		"RC_15Rnd_82mm_Mo_lowHEAB",
		"RC_16Rnd_82mm_Mo_lowHEAB",
		"RC_17Rnd_82mm_Mo_lowHEAB",
		"RC_18Rnd_82mm_Mo_lowHEAB",
		"RC_19Rnd_82mm_Mo_lowHEAB",
		"RC_20Rnd_82mm_Mo_lowHEAB",
		"RC_21Rnd_82mm_Mo_lowHEAB",
		"RC_22Rnd_82mm_Mo_lowHEAB",
		"RC_23Rnd_82mm_Mo_lowHEAB",
		"RC_24Rnd_82mm_Mo_lowHEAB",
		"RC_25Rnd_82mm_Mo_lowHEAB",
		"RC_26Rnd_82mm_Mo_lowHEAB",
		"RC_27Rnd_82mm_Mo_lowHEAB",
		"RC_28Rnd_82mm_Mo_lowHEAB",
		"RC_29Rnd_82mm_Mo_lowHEAB",
		"RC_30Rnd_82mm_Mo_lowHEAB",
		"RC_31Rnd_82mm_Mo_lowHEAB",
		"RC_32Rnd_82mm_Mo_lowHEAB",
		"RC_33Rnd_82mm_Mo_lowHEAB",
		"RC_34Rnd_82mm_Mo_lowHEAB",
		"RC_35Rnd_82mm_Mo_lowHEAB",
		"RC_36Rnd_82mm_Mo_lowHEAB",
		"RC_37Rnd_82mm_Mo_lowHEAB",
		"RC_38Rnd_82mm_Mo_lowHEAB",
		"RC_39Rnd_82mm_Mo_lowHEAB",
		"RC_40Rnd_82mm_Mo_lowHEAB",

		"RC_1Rnd_82mm_Mo_Smoke_white",
		"RC_2Rnd_82mm_Mo_Smoke_white",
		"RC_3Rnd_82mm_Mo_Smoke_white",
		"RC_4Rnd_82mm_Mo_Smoke_white",
		"RC_5Rnd_82mm_Mo_Smoke_white",
		"RC_6Rnd_82mm_Mo_Smoke_white",
		"RC_7Rnd_82mm_Mo_Smoke_white",
		"RC_8Rnd_82mm_Mo_Smoke_white",
		"RC_9Rnd_82mm_Mo_Smoke_white",
		"RC_10Rnd_82mm_Mo_Smoke_white",
		"RC_11Rnd_82mm_Mo_Smoke_white",
		"RC_12Rnd_82mm_Mo_Smoke_white",
		"RC_13Rnd_82mm_Mo_Smoke_white",
		"RC_14Rnd_82mm_Mo_Smoke_white",
		"RC_15Rnd_82mm_Mo_Smoke_white",
		"RC_16Rnd_82mm_Mo_Smoke_white",
		"RC_17Rnd_82mm_Mo_Smoke_white",
		"RC_18Rnd_82mm_Mo_Smoke_white",
		"RC_19Rnd_82mm_Mo_Smoke_white",
		"RC_20Rnd_82mm_Mo_Smoke_white",
		"RC_21Rnd_82mm_Mo_Smoke_white",
		"RC_22Rnd_82mm_Mo_Smoke_white",
		"RC_23Rnd_82mm_Mo_Smoke_white",
		"RC_24Rnd_82mm_Mo_Smoke_white",
		"RC_25Rnd_82mm_Mo_Smoke_white",
		"RC_26Rnd_82mm_Mo_Smoke_white",
		"RC_27Rnd_82mm_Mo_Smoke_white",
		"RC_28Rnd_82mm_Mo_Smoke_white",
		"RC_29Rnd_82mm_Mo_Smoke_white",
		"RC_30Rnd_82mm_Mo_Smoke_white",
		"RC_31Rnd_82mm_Mo_Smoke_white",
		"RC_32Rnd_82mm_Mo_Smoke_white",
		"RC_33Rnd_82mm_Mo_Smoke_white",
		"RC_34Rnd_82mm_Mo_Smoke_white",
		"RC_35Rnd_82mm_Mo_Smoke_white",
		"RC_36Rnd_82mm_Mo_Smoke_white",
		"RC_37Rnd_82mm_Mo_Smoke_white",
		"RC_38Rnd_82mm_Mo_Smoke_white",
		"RC_39Rnd_82mm_Mo_Smoke_white",
		"RC_40Rnd_82mm_Mo_Smoke_white",

		"RC_1Rnd_82mm_Mo_LaserGuided",
		"RC_2Rnd_82mm_Mo_LaserGuided",
		"RC_3Rnd_82mm_Mo_LaserGuided",
		"RC_4Rnd_82mm_Mo_LaserGuided",
		"RC_5Rnd_82mm_Mo_LaserGuided",
		"RC_6Rnd_82mm_Mo_LaserGuided",
		"RC_7Rnd_82mm_Mo_LaserGuided",
		"RC_8Rnd_82mm_Mo_LaserGuided",
		"RC_9Rnd_82mm_Mo_LaserGuided",
		"RC_10Rnd_82mm_Mo_LaserGuided",
		"RC_11Rnd_82mm_Mo_LaserGuided",
		"RC_12Rnd_82mm_Mo_LaserGuided",
		"RC_13Rnd_82mm_Mo_LaserGuided",
		"RC_14Rnd_82mm_Mo_LaserGuided",
		"RC_15Rnd_82mm_Mo_LaserGuided",
		"RC_16Rnd_82mm_Mo_LaserGuided",
		"RC_17Rnd_82mm_Mo_LaserGuided",
		"RC_18Rnd_82mm_Mo_LaserGuided",
		"RC_19Rnd_82mm_Mo_LaserGuided",
		"RC_20Rnd_82mm_Mo_LaserGuided",
		"RC_21Rnd_82mm_Mo_LaserGuided",
		"RC_22Rnd_82mm_Mo_LaserGuided",
		"RC_23Rnd_82mm_Mo_LaserGuided",
		"RC_24Rnd_82mm_Mo_LaserGuided",
		"RC_25Rnd_82mm_Mo_LaserGuided",
		"RC_26Rnd_82mm_Mo_LaserGuided",
		"RC_27Rnd_82mm_Mo_LaserGuided",
		"RC_28Rnd_82mm_Mo_LaserGuided",
		"RC_29Rnd_82mm_Mo_LaserGuided",
		"RC_30Rnd_82mm_Mo_LaserGuided",
		"RC_31Rnd_82mm_Mo_LaserGuided",
		"RC_32Rnd_82mm_Mo_LaserGuided",
		"RC_33Rnd_82mm_Mo_LaserGuided",
		"RC_34Rnd_82mm_Mo_LaserGuided",
		"RC_35Rnd_82mm_Mo_LaserGuided",
		"RC_36Rnd_82mm_Mo_LaserGuided",
		"RC_37Rnd_82mm_Mo_LaserGuided",
		"RC_38Rnd_82mm_Mo_LaserGuided",
		"RC_39Rnd_82mm_Mo_LaserGuided",
		"RC_40Rnd_82mm_Mo_LaserGuided",

		"RC_1Rnd_82mm_Mo_MultiGuided",
		"RC_2Rnd_82mm_Mo_MultiGuided",
		"RC_3Rnd_82mm_Mo_MultiGuided",
		"RC_4Rnd_82mm_Mo_MultiGuided",
		"RC_5Rnd_82mm_Mo_MultiGuided",
		"RC_6Rnd_82mm_Mo_MultiGuided",
		"RC_7Rnd_82mm_Mo_MultiGuided",
		"RC_8Rnd_82mm_Mo_MultiGuided",
		"RC_9Rnd_82mm_Mo_MultiGuided",
		"RC_10Rnd_82mm_Mo_MultiGuided",
		"RC_11Rnd_82mm_Mo_MultiGuided",
		"RC_12Rnd_82mm_Mo_MultiGuided",
		"RC_13Rnd_82mm_Mo_MultiGuided",
		"RC_14Rnd_82mm_Mo_MultiGuided",
		"RC_15Rnd_82mm_Mo_MultiGuided",
		"RC_16Rnd_82mm_Mo_MultiGuided",
		"RC_17Rnd_82mm_Mo_MultiGuided",
		"RC_18Rnd_82mm_Mo_MultiGuided",
		"RC_19Rnd_82mm_Mo_MultiGuided",
		"RC_20Rnd_82mm_Mo_MultiGuided",
		"RC_21Rnd_82mm_Mo_MultiGuided",
		"RC_22Rnd_82mm_Mo_MultiGuided",
		"RC_23Rnd_82mm_Mo_MultiGuided",
		"RC_24Rnd_82mm_Mo_MultiGuided",
		"RC_25Rnd_82mm_Mo_MultiGuided",
		"RC_26Rnd_82mm_Mo_MultiGuided",
		"RC_27Rnd_82mm_Mo_MultiGuided",
		"RC_28Rnd_82mm_Mo_MultiGuided",
		"RC_29Rnd_82mm_Mo_MultiGuided",
		"RC_30Rnd_82mm_Mo_MultiGuided",
		"RC_31Rnd_82mm_Mo_MultiGuided",
		"RC_32Rnd_82mm_Mo_MultiGuided",
		"RC_33Rnd_82mm_Mo_MultiGuided",
		"RC_34Rnd_82mm_Mo_MultiGuided",
		"RC_35Rnd_82mm_Mo_MultiGuided",
		"RC_36Rnd_82mm_Mo_MultiGuided",
		"RC_37Rnd_82mm_Mo_MultiGuided",
		"RC_38Rnd_82mm_Mo_MultiGuided",
		"RC_39Rnd_82mm_Mo_MultiGuided",
		"RC_40Rnd_82mm_Mo_MultiGuided",

		"RC_1Rnd_82mm_Mo_mine",
		"RC_2Rnd_82mm_Mo_mine",
		"RC_3Rnd_82mm_Mo_mine",
		"RC_4Rnd_82mm_Mo_mine",
		"RC_5Rnd_82mm_Mo_mine",
		"RC_6Rnd_82mm_Mo_mine",
		"RC_7Rnd_82mm_Mo_mine",
		"RC_8Rnd_82mm_Mo_mine",
		"RC_9Rnd_82mm_Mo_mine",
		"RC_10Rnd_82mm_Mo_mine",
		"RC_11Rnd_82mm_Mo_mine",
		"RC_12Rnd_82mm_Mo_mine",
		"RC_13Rnd_82mm_Mo_mine",
		"RC_14Rnd_82mm_Mo_mine",
		"RC_15Rnd_82mm_Mo_mine",
		"RC_16Rnd_82mm_Mo_mine",
		"RC_17Rnd_82mm_Mo_mine",
		"RC_18Rnd_82mm_Mo_mine",
		"RC_19Rnd_82mm_Mo_mine",
		"RC_20Rnd_82mm_Mo_mine",
		"RC_21Rnd_82mm_Mo_mine",
		"RC_22Rnd_82mm_Mo_mine",
		"RC_23Rnd_82mm_Mo_mine",
		"RC_24Rnd_82mm_Mo_mine",
		"RC_25Rnd_82mm_Mo_mine",
		"RC_26Rnd_82mm_Mo_mine",
		"RC_27Rnd_82mm_Mo_mine",
		"RC_28Rnd_82mm_Mo_mine",
		"RC_29Rnd_82mm_Mo_mine",
		"RC_30Rnd_82mm_Mo_mine",
		"RC_31Rnd_82mm_Mo_mine",
		"RC_32Rnd_82mm_Mo_mine",
		"RC_33Rnd_82mm_Mo_mine",
		"RC_34Rnd_82mm_Mo_mine",
		"RC_35Rnd_82mm_Mo_mine",
		"RC_36Rnd_82mm_Mo_mine",
		"RC_37Rnd_82mm_Mo_mine",
		"RC_38Rnd_82mm_Mo_mine",
		"RC_39Rnd_82mm_Mo_mine",
		"RC_40Rnd_82mm_Mo_mine",

		"RC_1Rnd_82mm_Mo_AT_mine",
		"RC_2Rnd_82mm_Mo_AT_mine",
		"RC_3Rnd_82mm_Mo_AT_mine",
		"RC_4Rnd_82mm_Mo_AT_mine",
		"RC_5Rnd_82mm_Mo_AT_mine",
		"RC_6Rnd_82mm_Mo_AT_mine",
		"RC_7Rnd_82mm_Mo_AT_mine",
		"RC_8Rnd_82mm_Mo_AT_mine",
		"RC_9Rnd_82mm_Mo_AT_mine",
		"RC_10Rnd_82mm_Mo_AT_mine",
		"RC_11Rnd_82mm_Mo_AT_mine",
		"RC_12Rnd_82mm_Mo_AT_mine",
		"RC_13Rnd_82mm_Mo_AT_mine",
		"RC_14Rnd_82mm_Mo_AT_mine",
		"RC_15Rnd_82mm_Mo_AT_mine",
		"RC_16Rnd_82mm_Mo_AT_mine",
		"RC_17Rnd_82mm_Mo_AT_mine",
		"RC_18Rnd_82mm_Mo_AT_mine",
		"RC_19Rnd_82mm_Mo_AT_mine",
		"RC_20Rnd_82mm_Mo_AT_mine",
		"RC_21Rnd_82mm_Mo_AT_mine",
		"RC_22Rnd_82mm_Mo_AT_mine",
		"RC_23Rnd_82mm_Mo_AT_mine",
		"RC_24Rnd_82mm_Mo_AT_mine",
		"RC_25Rnd_82mm_Mo_AT_mine",
		"RC_26Rnd_82mm_Mo_AT_mine",
		"RC_27Rnd_82mm_Mo_AT_mine",
		"RC_28Rnd_82mm_Mo_AT_mine",
		"RC_29Rnd_82mm_Mo_AT_mine",
		"RC_30Rnd_82mm_Mo_AT_mine",
		"RC_31Rnd_82mm_Mo_AT_mine",
		"RC_32Rnd_82mm_Mo_AT_mine",
		"RC_33Rnd_82mm_Mo_AT_mine",
		"RC_34Rnd_82mm_Mo_AT_mine",
		"RC_35Rnd_82mm_Mo_AT_mine",
		"RC_36Rnd_82mm_Mo_AT_mine",
		"RC_37Rnd_82mm_Mo_AT_mine",
		"RC_38Rnd_82mm_Mo_AT_mine",
		"RC_39Rnd_82mm_Mo_AT_mine",
		"RC_40Rnd_82mm_Mo_AT_mine",

		"RC_1Rnd_82mm_Mo_Flare_white",
		"RC_2Rnd_82mm_Mo_Flare_white",
		"RC_3Rnd_82mm_Mo_Flare_white",
		"RC_4Rnd_82mm_Mo_Flare_white",
		"RC_5Rnd_82mm_Mo_Flare_white",
		"RC_6Rnd_82mm_Mo_Flare_white",
		"RC_7Rnd_82mm_Mo_Flare_white",
		"RC_8Rnd_82mm_Mo_Flare_white",
		"RC_9Rnd_82mm_Mo_Flare_white",
		"RC_10Rnd_82mm_Mo_Flare_white",
		"RC_11Rnd_82mm_Mo_Flare_white",
		"RC_12Rnd_82mm_Mo_Flare_white",
		"RC_13Rnd_82mm_Mo_Flare_white",
		"RC_14Rnd_82mm_Mo_Flare_white",
		"RC_15Rnd_82mm_Mo_Flare_white",
		"RC_16Rnd_82mm_Mo_Flare_white",
		"RC_17Rnd_82mm_Mo_Flare_white",
		"RC_18Rnd_82mm_Mo_Flare_white",
		"RC_19Rnd_82mm_Mo_Flare_white",
		"RC_20Rnd_82mm_Mo_Flare_white",
		"RC_21Rnd_82mm_Mo_Flare_white",
		"RC_22Rnd_82mm_Mo_Flare_white",
		"RC_23Rnd_82mm_Mo_Flare_white",
		"RC_24Rnd_82mm_Mo_Flare_white",
		"RC_25Rnd_82mm_Mo_Flare_white",
		"RC_26Rnd_82mm_Mo_Flare_white",
		"RC_27Rnd_82mm_Mo_Flare_white",
		"RC_28Rnd_82mm_Mo_Flare_white",
		"RC_29Rnd_82mm_Mo_Flare_white",
		"RC_30Rnd_82mm_Mo_Flare_white",
		"RC_31Rnd_82mm_Mo_Flare_white",
		"RC_32Rnd_82mm_Mo_Flare_white",
		"RC_33Rnd_82mm_Mo_Flare_white",
		"RC_34Rnd_82mm_Mo_Flare_white",
		"RC_35Rnd_82mm_Mo_Flare_white",
		"RC_36Rnd_82mm_Mo_Flare_white",
		"RC_37Rnd_82mm_Mo_Flare_white",
		"RC_38Rnd_82mm_Mo_Flare_white",
		"RC_39Rnd_82mm_Mo_Flare_white",
		"RC_40Rnd_82mm_Mo_Flare_white",

		"RC_1Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_2Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_3Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_4Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_5Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_6Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_7Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_8Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_9Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_10Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_11Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_12Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_13Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_14Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_15Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_16Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_17Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_18Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_19Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_20Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_21Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_22Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_23Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_24Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_25Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_26Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_27Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_28Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_29Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_30Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_31Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_32Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_33Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_34Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_35Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_36Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_37Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_38Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_39Rnd_82mm_Mo_LG_DelayedFuse",
		"RC_40Rnd_82mm_Mo_LG_DelayedFuse",

		"RC_1Rnd_82mm_Mo_backupHEAB",
		"RC_2Rnd_82mm_Mo_backupHEAB",
		"RC_3Rnd_82mm_Mo_backupHEAB",
		"RC_4Rnd_82mm_Mo_backupHEAB",
		"RC_5Rnd_82mm_Mo_backupHEAB",
		"RC_6Rnd_82mm_Mo_backupHEAB",
		"RC_7Rnd_82mm_Mo_backupHEAB",
		"RC_8Rnd_82mm_Mo_backupHEAB",
		"RC_9Rnd_82mm_Mo_backupHEAB",
		"RC_10Rnd_82mm_Mo_backupHEAB",
		"RC_11Rnd_82mm_Mo_backupHEAB",
		"RC_12Rnd_82mm_Mo_backupHEAB",
		"RC_13Rnd_82mm_Mo_backupHEAB",
		"RC_14Rnd_82mm_Mo_backupHEAB",
		"RC_15Rnd_82mm_Mo_backupHEAB",
		"RC_16Rnd_82mm_Mo_backupHEAB",
		"RC_17Rnd_82mm_Mo_backupHEAB",
		"RC_18Rnd_82mm_Mo_backupHEAB",
		"RC_19Rnd_82mm_Mo_backupHEAB",
		"RC_20Rnd_82mm_Mo_backupHEAB",
		"RC_21Rnd_82mm_Mo_backupHEAB",
		"RC_22Rnd_82mm_Mo_backupHEAB",
		"RC_23Rnd_82mm_Mo_backupHEAB",
		"RC_24Rnd_82mm_Mo_backupHEAB",
		"RC_25Rnd_82mm_Mo_backupHEAB",
		"RC_26Rnd_82mm_Mo_backupHEAB",
		"RC_27Rnd_82mm_Mo_backupHEAB",
		"RC_28Rnd_82mm_Mo_backupHEAB",
		"RC_29Rnd_82mm_Mo_backupHEAB",
		"RC_30Rnd_82mm_Mo_backupHEAB",
		"RC_31Rnd_82mm_Mo_backupHEAB",
		"RC_32Rnd_82mm_Mo_backupHEAB",
		"RC_33Rnd_82mm_Mo_backupHEAB",
		"RC_34Rnd_82mm_Mo_backupHEAB",
		"RC_35Rnd_82mm_Mo_backupHEAB",
		"RC_36Rnd_82mm_Mo_backupHEAB",
		"RC_37Rnd_82mm_Mo_backupHEAB",
		"RC_38Rnd_82mm_Mo_backupHEAB",
		"RC_39Rnd_82mm_Mo_backupHEAB",
		"RC_40Rnd_82mm_Mo_backupHEAB",

		"RC_1Rnd_82mm_Mo_backuplowHEAB",
		"RC_2Rnd_82mm_Mo_backuplowHEAB",
		"RC_3Rnd_82mm_Mo_backuplowHEAB",
		"RC_4Rnd_82mm_Mo_backuplowHEAB",
		"RC_5Rnd_82mm_Mo_backuplowHEAB",
		"RC_6Rnd_82mm_Mo_backuplowHEAB",
		"RC_7Rnd_82mm_Mo_backuplowHEAB",
		"RC_8Rnd_82mm_Mo_backuplowHEAB",
		"RC_9Rnd_82mm_Mo_backuplowHEAB",
		"RC_10Rnd_82mm_Mo_backuplowHEAB",
		"RC_11Rnd_82mm_Mo_backuplowHEAB",
		"RC_12Rnd_82mm_Mo_backuplowHEAB",
		"RC_13Rnd_82mm_Mo_backuplowHEAB",
		"RC_14Rnd_82mm_Mo_backuplowHEAB",
		"RC_15Rnd_82mm_Mo_backuplowHEAB",
		"RC_16Rnd_82mm_Mo_backuplowHEAB",
		"RC_17Rnd_82mm_Mo_backuplowHEAB",
		"RC_18Rnd_82mm_Mo_backuplowHEAB",
		"RC_19Rnd_82mm_Mo_backuplowHEAB",
		"RC_20Rnd_82mm_Mo_backuplowHEAB",
		"RC_21Rnd_82mm_Mo_backuplowHEAB",
		"RC_22Rnd_82mm_Mo_backuplowHEAB",
		"RC_23Rnd_82mm_Mo_backuplowHEAB",
		"RC_24Rnd_82mm_Mo_backuplowHEAB",
		"RC_25Rnd_82mm_Mo_backuplowHEAB",
		"RC_26Rnd_82mm_Mo_backuplowHEAB",
		"RC_27Rnd_82mm_Mo_backuplowHEAB",
		"RC_28Rnd_82mm_Mo_backuplowHEAB",
		"RC_29Rnd_82mm_Mo_backuplowHEAB",
		"RC_30Rnd_82mm_Mo_backuplowHEAB",
		"RC_31Rnd_82mm_Mo_backuplowHEAB",
		"RC_32Rnd_82mm_Mo_backuplowHEAB",
		"RC_33Rnd_82mm_Mo_backuplowHEAB",
		"RC_34Rnd_82mm_Mo_backuplowHEAB",
		"RC_35Rnd_82mm_Mo_backuplowHEAB",
		"RC_36Rnd_82mm_Mo_backuplowHEAB",
		"RC_37Rnd_82mm_Mo_backuplowHEAB",
		"RC_38Rnd_82mm_Mo_backuplowHEAB",
		"RC_39Rnd_82mm_Mo_backuplowHEAB",
		"RC_40Rnd_82mm_Mo_backuplowHEAB"
	};
};
class RC_mortar_82mm_V2: RC_mortar_82mm_V1
{
	reloadTime=1.8;
	magazineReloadTime=2.5;
	canLock=2;
	weaponLockDelay=0;
};
class RC_mortar_82mm_V3: RC_mortar_82mm_V2
{
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3"
	};
	/*
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Burst1",
		"Burst2",
		"Burst3"
	};
	*/
	class Single1: Single1
	{
		displayName="CH0, 0.5km";
		artilleryDispersion=1.25;
		artilleryCharge=0.35;
		minRange=34;	//34	//60
		midRange=216.5;	//216.5	//290
		maxRange=499;	//499	//665
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
		aiDispersionCoefX=1;
		aiDispersionCoefY=1;
		//aiRateOfFireDispersion=1;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
	};
	class Single2: Single1
	{
		displayName="CH1, 2km";
		artilleryCharge=0.7;
		minRange=139;	//139	//230
		midRange=1068.5;	//1068.5	1175
		maxRange=1998;	//1998	//2660
	};
	class Single3: Single1
	{
		displayName="CH2, 4km";
		artilleryCharge=1;
		minRange=284;	//284	//540
		midRange=2181;	//2181	//2355
		maxRange=4078;	//4078	//5500
	};
	//used by ai, rof decreased
	class Burst1: Burst1
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst2: Burst2
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst3: Burst3
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
};


//82mm Vehicle Mortar 6km
class RC_vehiclemortar_82mm_V4: RC_mortar_82mm_V3
{
	//ballisticsComputer=8;	//direct fire reticle for highest charge

	magazines[]=
	{
		"RC_1Rnd_82mm_vic_Mo_shells",
		"RC_2Rnd_82mm_vic_Mo_shells",
		"RC_3Rnd_82mm_vic_Mo_shells",
		"RC_4Rnd_82mm_vic_Mo_shells",
		"RC_5Rnd_82mm_vic_Mo_shells",
		"RC_6Rnd_82mm_vic_Mo_shells",
		"RC_7Rnd_82mm_vic_Mo_shells",
		"RC_8Rnd_82mm_vic_Mo_shells",
		"RC_9Rnd_82mm_vic_Mo_shells",
		"RC_10Rnd_82mm_vic_Mo_shells",
		"RC_11Rnd_82mm_vic_Mo_shells",
		"RC_12Rnd_82mm_vic_Mo_shells",
		"RC_13Rnd_82mm_vic_Mo_shells",
		"RC_14Rnd_82mm_vic_Mo_shells",
		"RC_15Rnd_82mm_vic_Mo_shells",
		"RC_16Rnd_82mm_vic_Mo_shells",
		"RC_17Rnd_82mm_vic_Mo_shells",
		"RC_18Rnd_82mm_vic_Mo_shells",
		"RC_19Rnd_82mm_vic_Mo_shells",
		"RC_20Rnd_82mm_vic_Mo_shells",
		"RC_21Rnd_82mm_vic_Mo_shells",
		"RC_22Rnd_82mm_vic_Mo_shells",
		"RC_23Rnd_82mm_vic_Mo_shells",
		"RC_24Rnd_82mm_vic_Mo_shells",
		"RC_25Rnd_82mm_vic_Mo_shells",
		"RC_26Rnd_82mm_vic_Mo_shells",
		"RC_27Rnd_82mm_vic_Mo_shells",
		"RC_28Rnd_82mm_vic_Mo_shells",
		"RC_29Rnd_82mm_vic_Mo_shells",
		"RC_30Rnd_82mm_vic_Mo_shells",
		"RC_31Rnd_82mm_vic_Mo_shells",
		"RC_32Rnd_82mm_vic_Mo_shells",
		"RC_33Rnd_82mm_vic_Mo_shells",
		"RC_34Rnd_82mm_vic_Mo_shells",
		"RC_35Rnd_82mm_vic_Mo_shells",
		"RC_36Rnd_82mm_vic_Mo_shells",
		"RC_37Rnd_82mm_vic_Mo_shells",
		"RC_38Rnd_82mm_vic_Mo_shells",
		"RC_39Rnd_82mm_vic_Mo_shells",
		"RC_40Rnd_82mm_vic_Mo_shells",

		"RC_1Rnd_82mm_vic_Mo_HEAB",
		"RC_2Rnd_82mm_vic_Mo_HEAB",
		"RC_3Rnd_82mm_vic_Mo_HEAB",
		"RC_4Rnd_82mm_vic_Mo_HEAB",
		"RC_5Rnd_82mm_vic_Mo_HEAB",
		"RC_6Rnd_82mm_vic_Mo_HEAB",
		"RC_7Rnd_82mm_vic_Mo_HEAB",
		"RC_8Rnd_82mm_vic_Mo_HEAB",
		"RC_9Rnd_82mm_vic_Mo_HEAB",
		"RC_10Rnd_82mm_vic_Mo_HEAB",
		"RC_11Rnd_82mm_vic_Mo_HEAB",
		"RC_12Rnd_82mm_vic_Mo_HEAB",
		"RC_13Rnd_82mm_vic_Mo_HEAB",
		"RC_14Rnd_82mm_vic_Mo_HEAB",
		"RC_15Rnd_82mm_vic_Mo_HEAB",
		"RC_16Rnd_82mm_vic_Mo_HEAB",
		"RC_17Rnd_82mm_vic_Mo_HEAB",
		"RC_18Rnd_82mm_vic_Mo_HEAB",
		"RC_19Rnd_82mm_vic_Mo_HEAB",
		"RC_20Rnd_82mm_vic_Mo_HEAB",
		"RC_21Rnd_82mm_vic_Mo_HEAB",
		"RC_22Rnd_82mm_vic_Mo_HEAB",
		"RC_23Rnd_82mm_vic_Mo_HEAB",
		"RC_24Rnd_82mm_vic_Mo_HEAB",
		"RC_25Rnd_82mm_vic_Mo_HEAB",
		"RC_26Rnd_82mm_vic_Mo_HEAB",
		"RC_27Rnd_82mm_vic_Mo_HEAB",
		"RC_28Rnd_82mm_vic_Mo_HEAB",
		"RC_29Rnd_82mm_vic_Mo_HEAB",
		"RC_30Rnd_82mm_vic_Mo_HEAB",
		"RC_31Rnd_82mm_vic_Mo_HEAB",
		"RC_32Rnd_82mm_vic_Mo_HEAB",
		"RC_33Rnd_82mm_vic_Mo_HEAB",
		"RC_34Rnd_82mm_vic_Mo_HEAB",
		"RC_35Rnd_82mm_vic_Mo_HEAB",
		"RC_36Rnd_82mm_vic_Mo_HEAB",
		"RC_37Rnd_82mm_vic_Mo_HEAB",
		"RC_38Rnd_82mm_vic_Mo_HEAB",
		"RC_39Rnd_82mm_vic_Mo_HEAB",
		"RC_40Rnd_82mm_vic_Mo_HEAB",

		"RC_1Rnd_82mm_vic_Mo_lowHEAB",
		"RC_2Rnd_82mm_vic_Mo_lowHEAB",
		"RC_3Rnd_82mm_vic_Mo_lowHEAB",
		"RC_4Rnd_82mm_vic_Mo_lowHEAB",
		"RC_5Rnd_82mm_vic_Mo_lowHEAB",
		"RC_6Rnd_82mm_vic_Mo_lowHEAB",
		"RC_7Rnd_82mm_vic_Mo_lowHEAB",
		"RC_8Rnd_82mm_vic_Mo_lowHEAB",
		"RC_9Rnd_82mm_vic_Mo_lowHEAB",
		"RC_10Rnd_82mm_vic_Mo_lowHEAB",
		"RC_11Rnd_82mm_vic_Mo_lowHEAB",
		"RC_12Rnd_82mm_vic_Mo_lowHEAB",
		"RC_13Rnd_82mm_vic_Mo_lowHEAB",
		"RC_14Rnd_82mm_vic_Mo_lowHEAB",
		"RC_15Rnd_82mm_vic_Mo_lowHEAB",
		"RC_16Rnd_82mm_vic_Mo_lowHEAB",
		"RC_17Rnd_82mm_vic_Mo_lowHEAB",
		"RC_18Rnd_82mm_vic_Mo_lowHEAB",
		"RC_19Rnd_82mm_vic_Mo_lowHEAB",
		"RC_20Rnd_82mm_vic_Mo_lowHEAB",
		"RC_21Rnd_82mm_vic_Mo_lowHEAB",
		"RC_22Rnd_82mm_vic_Mo_lowHEAB",
		"RC_23Rnd_82mm_vic_Mo_lowHEAB",
		"RC_24Rnd_82mm_vic_Mo_lowHEAB",
		"RC_25Rnd_82mm_vic_Mo_lowHEAB",
		"RC_26Rnd_82mm_vic_Mo_lowHEAB",
		"RC_27Rnd_82mm_vic_Mo_lowHEAB",
		"RC_28Rnd_82mm_vic_Mo_lowHEAB",
		"RC_29Rnd_82mm_vic_Mo_lowHEAB",
		"RC_30Rnd_82mm_vic_Mo_lowHEAB",
		"RC_31Rnd_82mm_vic_Mo_lowHEAB",
		"RC_32Rnd_82mm_vic_Mo_lowHEAB",
		"RC_33Rnd_82mm_vic_Mo_lowHEAB",
		"RC_34Rnd_82mm_vic_Mo_lowHEAB",
		"RC_35Rnd_82mm_vic_Mo_lowHEAB",
		"RC_36Rnd_82mm_vic_Mo_lowHEAB",
		"RC_37Rnd_82mm_vic_Mo_lowHEAB",
		"RC_38Rnd_82mm_vic_Mo_lowHEAB",
		"RC_39Rnd_82mm_vic_Mo_lowHEAB",
		"RC_40Rnd_82mm_vic_Mo_lowHEAB",

		"RC_1Rnd_82mm_vic_Mo_Smoke_white",
		"RC_2Rnd_82mm_vic_Mo_Smoke_white",
		"RC_3Rnd_82mm_vic_Mo_Smoke_white",
		"RC_4Rnd_82mm_vic_Mo_Smoke_white",
		"RC_5Rnd_82mm_vic_Mo_Smoke_white",
		"RC_6Rnd_82mm_vic_Mo_Smoke_white",
		"RC_7Rnd_82mm_vic_Mo_Smoke_white",
		"RC_8Rnd_82mm_vic_Mo_Smoke_white",
		"RC_9Rnd_82mm_vic_Mo_Smoke_white",
		"RC_10Rnd_82mm_vic_Mo_Smoke_white",
		"RC_11Rnd_82mm_vic_Mo_Smoke_white",
		"RC_12Rnd_82mm_vic_Mo_Smoke_white",
		"RC_13Rnd_82mm_vic_Mo_Smoke_white",
		"RC_14Rnd_82mm_vic_Mo_Smoke_white",
		"RC_15Rnd_82mm_vic_Mo_Smoke_white",
		"RC_16Rnd_82mm_vic_Mo_Smoke_white",
		"RC_17Rnd_82mm_vic_Mo_Smoke_white",
		"RC_18Rnd_82mm_vic_Mo_Smoke_white",
		"RC_19Rnd_82mm_vic_Mo_Smoke_white",
		"RC_20Rnd_82mm_vic_Mo_Smoke_white",
		"RC_21Rnd_82mm_vic_Mo_Smoke_white",
		"RC_22Rnd_82mm_vic_Mo_Smoke_white",
		"RC_23Rnd_82mm_vic_Mo_Smoke_white",
		"RC_24Rnd_82mm_vic_Mo_Smoke_white",
		"RC_25Rnd_82mm_vic_Mo_Smoke_white",
		"RC_26Rnd_82mm_vic_Mo_Smoke_white",
		"RC_27Rnd_82mm_vic_Mo_Smoke_white",
		"RC_28Rnd_82mm_vic_Mo_Smoke_white",
		"RC_29Rnd_82mm_vic_Mo_Smoke_white",
		"RC_30Rnd_82mm_vic_Mo_Smoke_white",
		"RC_31Rnd_82mm_vic_Mo_Smoke_white",
		"RC_32Rnd_82mm_vic_Mo_Smoke_white",
		"RC_33Rnd_82mm_vic_Mo_Smoke_white",
		"RC_34Rnd_82mm_vic_Mo_Smoke_white",
		"RC_35Rnd_82mm_vic_Mo_Smoke_white",
		"RC_36Rnd_82mm_vic_Mo_Smoke_white",
		"RC_37Rnd_82mm_vic_Mo_Smoke_white",
		"RC_38Rnd_82mm_vic_Mo_Smoke_white",
		"RC_39Rnd_82mm_vic_Mo_Smoke_white",
		"RC_40Rnd_82mm_vic_Mo_Smoke_white",

		"RC_1Rnd_82mm_vic_Mo_LaserGuided",
		"RC_2Rnd_82mm_vic_Mo_LaserGuided",
		"RC_3Rnd_82mm_vic_Mo_LaserGuided",
		"RC_4Rnd_82mm_vic_Mo_LaserGuided",
		"RC_5Rnd_82mm_vic_Mo_LaserGuided",
		"RC_6Rnd_82mm_vic_Mo_LaserGuided",
		"RC_7Rnd_82mm_vic_Mo_LaserGuided",
		"RC_8Rnd_82mm_vic_Mo_LaserGuided",
		"RC_9Rnd_82mm_vic_Mo_LaserGuided",
		"RC_10Rnd_82mm_vic_Mo_LaserGuided",
		"RC_11Rnd_82mm_vic_Mo_LaserGuided",
		"RC_12Rnd_82mm_vic_Mo_LaserGuided",
		"RC_13Rnd_82mm_vic_Mo_LaserGuided",
		"RC_14Rnd_82mm_vic_Mo_LaserGuided",
		"RC_15Rnd_82mm_vic_Mo_LaserGuided",
		"RC_16Rnd_82mm_vic_Mo_LaserGuided",
		"RC_17Rnd_82mm_vic_Mo_LaserGuided",
		"RC_18Rnd_82mm_vic_Mo_LaserGuided",
		"RC_19Rnd_82mm_vic_Mo_LaserGuided",
		"RC_20Rnd_82mm_vic_Mo_LaserGuided",
		"RC_21Rnd_82mm_vic_Mo_LaserGuided",
		"RC_22Rnd_82mm_vic_Mo_LaserGuided",
		"RC_23Rnd_82mm_vic_Mo_LaserGuided",
		"RC_24Rnd_82mm_vic_Mo_LaserGuided",
		"RC_25Rnd_82mm_vic_Mo_LaserGuided",
		"RC_26Rnd_82mm_vic_Mo_LaserGuided",
		"RC_27Rnd_82mm_vic_Mo_LaserGuided",
		"RC_28Rnd_82mm_vic_Mo_LaserGuided",
		"RC_29Rnd_82mm_vic_Mo_LaserGuided",
		"RC_30Rnd_82mm_vic_Mo_LaserGuided",
		"RC_31Rnd_82mm_vic_Mo_LaserGuided",
		"RC_32Rnd_82mm_vic_Mo_LaserGuided",
		"RC_33Rnd_82mm_vic_Mo_LaserGuided",
		"RC_34Rnd_82mm_vic_Mo_LaserGuided",
		"RC_35Rnd_82mm_vic_Mo_LaserGuided",
		"RC_36Rnd_82mm_vic_Mo_LaserGuided",
		"RC_37Rnd_82mm_vic_Mo_LaserGuided",
		"RC_38Rnd_82mm_vic_Mo_LaserGuided",
		"RC_39Rnd_82mm_vic_Mo_LaserGuided",
		"RC_40Rnd_82mm_vic_Mo_LaserGuided",

		"RC_1Rnd_82mm_vic_Mo_MultiGuided",
		"RC_2Rnd_82mm_vic_Mo_MultiGuided",
		"RC_3Rnd_82mm_vic_Mo_MultiGuided",
		"RC_4Rnd_82mm_vic_Mo_MultiGuided",
		"RC_5Rnd_82mm_vic_Mo_MultiGuided",
		"RC_6Rnd_82mm_vic_Mo_MultiGuided",
		"RC_7Rnd_82mm_vic_Mo_MultiGuided",
		"RC_8Rnd_82mm_vic_Mo_MultiGuided",
		"RC_9Rnd_82mm_vic_Mo_MultiGuided",
		"RC_10Rnd_82mm_vic_Mo_MultiGuided",
		"RC_11Rnd_82mm_vic_Mo_MultiGuided",
		"RC_12Rnd_82mm_vic_Mo_MultiGuided",
		"RC_13Rnd_82mm_vic_Mo_MultiGuided",
		"RC_14Rnd_82mm_vic_Mo_MultiGuided",
		"RC_15Rnd_82mm_vic_Mo_MultiGuided",
		"RC_16Rnd_82mm_vic_Mo_MultiGuided",
		"RC_17Rnd_82mm_vic_Mo_MultiGuided",
		"RC_18Rnd_82mm_vic_Mo_MultiGuided",
		"RC_19Rnd_82mm_vic_Mo_MultiGuided",
		"RC_20Rnd_82mm_vic_Mo_MultiGuided",
		"RC_21Rnd_82mm_vic_Mo_MultiGuided",
		"RC_22Rnd_82mm_vic_Mo_MultiGuided",
		"RC_23Rnd_82mm_vic_Mo_MultiGuided",
		"RC_24Rnd_82mm_vic_Mo_MultiGuided",
		"RC_25Rnd_82mm_vic_Mo_MultiGuided",
		"RC_26Rnd_82mm_vic_Mo_MultiGuided",
		"RC_27Rnd_82mm_vic_Mo_MultiGuided",
		"RC_28Rnd_82mm_vic_Mo_MultiGuided",
		"RC_29Rnd_82mm_vic_Mo_MultiGuided",
		"RC_30Rnd_82mm_vic_Mo_MultiGuided",
		"RC_31Rnd_82mm_vic_Mo_MultiGuided",
		"RC_32Rnd_82mm_vic_Mo_MultiGuided",
		"RC_33Rnd_82mm_vic_Mo_MultiGuided",
		"RC_34Rnd_82mm_vic_Mo_MultiGuided",
		"RC_35Rnd_82mm_vic_Mo_MultiGuided",
		"RC_36Rnd_82mm_vic_Mo_MultiGuided",
		"RC_37Rnd_82mm_vic_Mo_MultiGuided",
		"RC_38Rnd_82mm_vic_Mo_MultiGuided",
		"RC_39Rnd_82mm_vic_Mo_MultiGuided",
		"RC_40Rnd_82mm_vic_Mo_MultiGuided",

		"RC_1Rnd_82mm_vic_Mo_mine",
		"RC_2Rnd_82mm_vic_Mo_mine",
		"RC_3Rnd_82mm_vic_Mo_mine",
		"RC_4Rnd_82mm_vic_Mo_mine",
		"RC_5Rnd_82mm_vic_Mo_mine",
		"RC_6Rnd_82mm_vic_Mo_mine",
		"RC_7Rnd_82mm_vic_Mo_mine",
		"RC_8Rnd_82mm_vic_Mo_mine",
		"RC_9Rnd_82mm_vic_Mo_mine",
		"RC_10Rnd_82mm_vic_Mo_mine",
		"RC_11Rnd_82mm_vic_Mo_mine",
		"RC_12Rnd_82mm_vic_Mo_mine",
		"RC_13Rnd_82mm_vic_Mo_mine",
		"RC_14Rnd_82mm_vic_Mo_mine",
		"RC_15Rnd_82mm_vic_Mo_mine",
		"RC_16Rnd_82mm_vic_Mo_mine",
		"RC_17Rnd_82mm_vic_Mo_mine",
		"RC_18Rnd_82mm_vic_Mo_mine",
		"RC_19Rnd_82mm_vic_Mo_mine",
		"RC_20Rnd_82mm_vic_Mo_mine",
		"RC_21Rnd_82mm_vic_Mo_mine",
		"RC_22Rnd_82mm_vic_Mo_mine",
		"RC_23Rnd_82mm_vic_Mo_mine",
		"RC_24Rnd_82mm_vic_Mo_mine",
		"RC_25Rnd_82mm_vic_Mo_mine",
		"RC_26Rnd_82mm_vic_Mo_mine",
		"RC_27Rnd_82mm_vic_Mo_mine",
		"RC_28Rnd_82mm_vic_Mo_mine",
		"RC_29Rnd_82mm_vic_Mo_mine",
		"RC_30Rnd_82mm_vic_Mo_mine",
		"RC_31Rnd_82mm_vic_Mo_mine",
		"RC_32Rnd_82mm_vic_Mo_mine",
		"RC_33Rnd_82mm_vic_Mo_mine",
		"RC_34Rnd_82mm_vic_Mo_mine",
		"RC_35Rnd_82mm_vic_Mo_mine",
		"RC_36Rnd_82mm_vic_Mo_mine",
		"RC_37Rnd_82mm_vic_Mo_mine",
		"RC_38Rnd_82mm_vic_Mo_mine",
		"RC_39Rnd_82mm_vic_Mo_mine",
		"RC_40Rnd_82mm_vic_Mo_mine",

		"RC_1Rnd_82mm_vic_Mo_AT_mine",
		"RC_2Rnd_82mm_vic_Mo_AT_mine",
		"RC_3Rnd_82mm_vic_Mo_AT_mine",
		"RC_4Rnd_82mm_vic_Mo_AT_mine",
		"RC_5Rnd_82mm_vic_Mo_AT_mine",
		"RC_6Rnd_82mm_vic_Mo_AT_mine",
		"RC_7Rnd_82mm_vic_Mo_AT_mine",
		"RC_8Rnd_82mm_vic_Mo_AT_mine",
		"RC_9Rnd_82mm_vic_Mo_AT_mine",
		"RC_10Rnd_82mm_vic_Mo_AT_mine",
		"RC_11Rnd_82mm_vic_Mo_AT_mine",
		"RC_12Rnd_82mm_vic_Mo_AT_mine",
		"RC_13Rnd_82mm_vic_Mo_AT_mine",
		"RC_14Rnd_82mm_vic_Mo_AT_mine",
		"RC_15Rnd_82mm_vic_Mo_AT_mine",
		"RC_16Rnd_82mm_vic_Mo_AT_mine",
		"RC_17Rnd_82mm_vic_Mo_AT_mine",
		"RC_18Rnd_82mm_vic_Mo_AT_mine",
		"RC_19Rnd_82mm_vic_Mo_AT_mine",
		"RC_20Rnd_82mm_vic_Mo_AT_mine",
		"RC_21Rnd_82mm_vic_Mo_AT_mine",
		"RC_22Rnd_82mm_vic_Mo_AT_mine",
		"RC_23Rnd_82mm_vic_Mo_AT_mine",
		"RC_24Rnd_82mm_vic_Mo_AT_mine",
		"RC_25Rnd_82mm_vic_Mo_AT_mine",
		"RC_26Rnd_82mm_vic_Mo_AT_mine",
		"RC_27Rnd_82mm_vic_Mo_AT_mine",
		"RC_28Rnd_82mm_vic_Mo_AT_mine",
		"RC_29Rnd_82mm_vic_Mo_AT_mine",
		"RC_30Rnd_82mm_vic_Mo_AT_mine",
		"RC_31Rnd_82mm_vic_Mo_AT_mine",
		"RC_32Rnd_82mm_vic_Mo_AT_mine",
		"RC_33Rnd_82mm_vic_Mo_AT_mine",
		"RC_34Rnd_82mm_vic_Mo_AT_mine",
		"RC_35Rnd_82mm_vic_Mo_AT_mine",
		"RC_36Rnd_82mm_vic_Mo_AT_mine",
		"RC_37Rnd_82mm_vic_Mo_AT_mine",
		"RC_38Rnd_82mm_vic_Mo_AT_mine",
		"RC_39Rnd_82mm_vic_Mo_AT_mine",
		"RC_40Rnd_82mm_vic_Mo_AT_mine",

		"RC_1Rnd_82mm_vic_Mo_Flare_white",
		"RC_2Rnd_82mm_vic_Mo_Flare_white",
		"RC_3Rnd_82mm_vic_Mo_Flare_white",
		"RC_4Rnd_82mm_vic_Mo_Flare_white",
		"RC_5Rnd_82mm_vic_Mo_Flare_white",
		"RC_6Rnd_82mm_vic_Mo_Flare_white",
		"RC_7Rnd_82mm_vic_Mo_Flare_white",
		"RC_8Rnd_82mm_vic_Mo_Flare_white",
		"RC_9Rnd_82mm_vic_Mo_Flare_white",
		"RC_10Rnd_82mm_vic_Mo_Flare_white",
		"RC_11Rnd_82mm_vic_Mo_Flare_white",
		"RC_12Rnd_82mm_vic_Mo_Flare_white",
		"RC_13Rnd_82mm_vic_Mo_Flare_white",
		"RC_14Rnd_82mm_vic_Mo_Flare_white",
		"RC_15Rnd_82mm_vic_Mo_Flare_white",
		"RC_16Rnd_82mm_vic_Mo_Flare_white",
		"RC_17Rnd_82mm_vic_Mo_Flare_white",
		"RC_18Rnd_82mm_vic_Mo_Flare_white",
		"RC_19Rnd_82mm_vic_Mo_Flare_white",
		"RC_20Rnd_82mm_vic_Mo_Flare_white",
		"RC_21Rnd_82mm_vic_Mo_Flare_white",
		"RC_22Rnd_82mm_vic_Mo_Flare_white",
		"RC_23Rnd_82mm_vic_Mo_Flare_white",
		"RC_24Rnd_82mm_vic_Mo_Flare_white",
		"RC_25Rnd_82mm_vic_Mo_Flare_white",
		"RC_26Rnd_82mm_vic_Mo_Flare_white",
		"RC_27Rnd_82mm_vic_Mo_Flare_white",
		"RC_28Rnd_82mm_vic_Mo_Flare_white",
		"RC_29Rnd_82mm_vic_Mo_Flare_white",
		"RC_30Rnd_82mm_vic_Mo_Flare_white",
		"RC_31Rnd_82mm_vic_Mo_Flare_white",
		"RC_32Rnd_82mm_vic_Mo_Flare_white",
		"RC_33Rnd_82mm_vic_Mo_Flare_white",
		"RC_34Rnd_82mm_vic_Mo_Flare_white",
		"RC_35Rnd_82mm_vic_Mo_Flare_white",
		"RC_36Rnd_82mm_vic_Mo_Flare_white",
		"RC_37Rnd_82mm_vic_Mo_Flare_white",
		"RC_38Rnd_82mm_vic_Mo_Flare_white",
		"RC_39Rnd_82mm_vic_Mo_Flare_white",
		"RC_40Rnd_82mm_vic_Mo_Flare_white",

		"RC_1Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_2Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_3Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_4Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_5Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_6Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_7Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_8Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_9Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_10Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_11Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_12Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_13Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_14Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_15Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_16Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_17Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_18Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_19Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_20Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_21Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_22Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_23Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_24Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_25Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_26Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_27Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_28Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_29Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_30Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_31Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_32Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_33Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_34Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_35Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_36Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_37Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_38Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_39Rnd_82mm_vic_Mo_LG_DelayedFuse",
		"RC_40Rnd_82mm_vic_Mo_LG_DelayedFuse",

		"RC_1Rnd_82mm_vic_Mo_backupHEAB",
		"RC_2Rnd_82mm_vic_Mo_backupHEAB",
		"RC_3Rnd_82mm_vic_Mo_backupHEAB",
		"RC_4Rnd_82mm_vic_Mo_backupHEAB",
		"RC_5Rnd_82mm_vic_Mo_backupHEAB",
		"RC_6Rnd_82mm_vic_Mo_backupHEAB",
		"RC_7Rnd_82mm_vic_Mo_backupHEAB",
		"RC_8Rnd_82mm_vic_Mo_backupHEAB",
		"RC_9Rnd_82mm_vic_Mo_backupHEAB",
		"RC_10Rnd_82mm_vic_Mo_backupHEAB",
		"RC_11Rnd_82mm_vic_Mo_backupHEAB",
		"RC_12Rnd_82mm_vic_Mo_backupHEAB",
		"RC_13Rnd_82mm_vic_Mo_backupHEAB",
		"RC_14Rnd_82mm_vic_Mo_backupHEAB",
		"RC_15Rnd_82mm_vic_Mo_backupHEAB",
		"RC_16Rnd_82mm_vic_Mo_backupHEAB",
		"RC_17Rnd_82mm_vic_Mo_backupHEAB",
		"RC_18Rnd_82mm_vic_Mo_backupHEAB",
		"RC_19Rnd_82mm_vic_Mo_backupHEAB",
		"RC_20Rnd_82mm_vic_Mo_backupHEAB",
		"RC_21Rnd_82mm_vic_Mo_backupHEAB",
		"RC_22Rnd_82mm_vic_Mo_backupHEAB",
		"RC_23Rnd_82mm_vic_Mo_backupHEAB",
		"RC_24Rnd_82mm_vic_Mo_backupHEAB",
		"RC_25Rnd_82mm_vic_Mo_backupHEAB",
		"RC_26Rnd_82mm_vic_Mo_backupHEAB",
		"RC_27Rnd_82mm_vic_Mo_backupHEAB",
		"RC_28Rnd_82mm_vic_Mo_backupHEAB",
		"RC_29Rnd_82mm_vic_Mo_backupHEAB",
		"RC_30Rnd_82mm_vic_Mo_backupHEAB",
		"RC_31Rnd_82mm_vic_Mo_backupHEAB",
		"RC_32Rnd_82mm_vic_Mo_backupHEAB",
		"RC_33Rnd_82mm_vic_Mo_backupHEAB",
		"RC_34Rnd_82mm_vic_Mo_backupHEAB",
		"RC_35Rnd_82mm_vic_Mo_backupHEAB",
		"RC_36Rnd_82mm_vic_Mo_backupHEAB",
		"RC_37Rnd_82mm_vic_Mo_backupHEAB",
		"RC_38Rnd_82mm_vic_Mo_backupHEAB",
		"RC_39Rnd_82mm_vic_Mo_backupHEAB",
		"RC_40Rnd_82mm_vic_Mo_backupHEAB",

		"RC_1Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_2Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_3Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_4Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_5Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_6Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_7Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_8Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_9Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_10Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_11Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_12Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_13Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_14Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_15Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_16Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_17Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_18Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_19Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_20Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_21Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_22Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_23Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_24Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_25Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_26Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_27Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_28Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_29Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_30Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_31Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_32Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_33Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_34Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_35Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_36Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_37Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_38Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_39Rnd_82mm_vic_Mo_backuplowHEAB",
		"RC_40Rnd_82mm_vic_Mo_backuplowHEAB"
	};
	/*
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7",
		"Burst1",
		"Burst2",
		"Burst3",
	};
	*/
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7"
	};
	class Single1: Single1
	{
		displayName="CH0";
		artilleryDispersion=1.9;
		artilleryCharge=0.35;
		minRange=51;
		midRange=393;
		maxRange=735;
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
		aiDispersionCoefX=1;
		aiDispersionCoefY=1;
		//aiRateOfFireDispersion=1;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
	};
	class Single2: Single1
	{
		displayName="CH1";
		artilleryCharge=0.417;
		minRange=72;
		midRange=557.5;
		maxRange=1043;
	};
	class Single3: Single1
	{
		displayName="CH2";
		artilleryCharge=0.497;
		minRange=103;
		midRange=792.5;
		maxRange=1482;
	};
	class Single4: Single1
	{
		displayName="CH3";
		artilleryCharge=0.592;
		minRange=142;
		midRange=1122;
		maxRange=2102;
	};
	class Single5: Single1
	{
		displayName="CH4";
		artilleryCharge=0.705;
		minRange=208;
		midRange=1595;
		maxRange=2982;
	};
	class Single6: Single1
	{
		displayName="CH5";
		artilleryCharge=0.84;
		minRange=295;
		midRange=2264;
		maxRange=4233;
	};
	class Single7: Single1
	{
		displayName="CH6";
		artilleryCharge=1;
		minRange=418;
		midRange=3209;
		maxRange=6000;
	};
};


class RC_vehiclemortar_60mm_V4: RC_vehiclemortar_82mm_V4
{
	displayName="60mm Mortar";
	displayNameShort="60mm Mortar";
	ballisticsComputer=8;	//direct fire reticle for highest charge
	reloadTime=1.6;

	class Single1: Single1
	{
		reloadTime=1.6;
	};
	class Single2: Single2
	{
		reloadTime=1.6;
	};
	class Single3: Single3
	{
		reloadTime=1.6;
	};
	class Single4: Single4
	{
		reloadTime=1.6;
	};
	class Single5: Single5
	{
		reloadTime=1.6;
	};
	class Single6: Single6
	{
		reloadTime=1.6;
	};
	class Single7: Single7
	{
		reloadTime=1.6;
	};
	
	magazines[]=
	{
		"RC_1Rnd_60mm_vic_Mo_shells",
		"RC_2Rnd_60mm_vic_Mo_shells",
		"RC_3Rnd_60mm_vic_Mo_shells",
		"RC_4Rnd_60mm_vic_Mo_shells",
		"RC_5Rnd_60mm_vic_Mo_shells",
		"RC_6Rnd_60mm_vic_Mo_shells",
		"RC_7Rnd_60mm_vic_Mo_shells",
		"RC_8Rnd_60mm_vic_Mo_shells",
		"RC_9Rnd_60mm_vic_Mo_shells",
		"RC_10Rnd_60mm_vic_Mo_shells",
		"RC_11Rnd_60mm_vic_Mo_shells",
		"RC_12Rnd_60mm_vic_Mo_shells",
		"RC_13Rnd_60mm_vic_Mo_shells",
		"RC_14Rnd_60mm_vic_Mo_shells",
		"RC_15Rnd_60mm_vic_Mo_shells",
		"RC_16Rnd_60mm_vic_Mo_shells",
		"RC_17Rnd_60mm_vic_Mo_shells",
		"RC_18Rnd_60mm_vic_Mo_shells",
		"RC_19Rnd_60mm_vic_Mo_shells",
		"RC_20Rnd_60mm_vic_Mo_shells",
		"RC_21Rnd_60mm_vic_Mo_shells",
		"RC_22Rnd_60mm_vic_Mo_shells",
		"RC_23Rnd_60mm_vic_Mo_shells",
		"RC_24Rnd_60mm_vic_Mo_shells",
		"RC_25Rnd_60mm_vic_Mo_shells",
		"RC_26Rnd_60mm_vic_Mo_shells",
		"RC_27Rnd_60mm_vic_Mo_shells",
		"RC_28Rnd_60mm_vic_Mo_shells",
		"RC_29Rnd_60mm_vic_Mo_shells",
		"RC_30Rnd_60mm_vic_Mo_shells",
		"RC_31Rnd_60mm_vic_Mo_shells",
		"RC_32Rnd_60mm_vic_Mo_shells",
		"RC_33Rnd_60mm_vic_Mo_shells",
		"RC_34Rnd_60mm_vic_Mo_shells",
		"RC_35Rnd_60mm_vic_Mo_shells",
		"RC_36Rnd_60mm_vic_Mo_shells",
		"RC_37Rnd_60mm_vic_Mo_shells",
		"RC_38Rnd_60mm_vic_Mo_shells",
		"RC_39Rnd_60mm_vic_Mo_shells",
		"RC_40Rnd_60mm_vic_Mo_shells",

		"RC_1Rnd_60mm_vic_Mo_HEAB",
		"RC_2Rnd_60mm_vic_Mo_HEAB",
		"RC_3Rnd_60mm_vic_Mo_HEAB",
		"RC_4Rnd_60mm_vic_Mo_HEAB",
		"RC_5Rnd_60mm_vic_Mo_HEAB",
		"RC_6Rnd_60mm_vic_Mo_HEAB",
		"RC_7Rnd_60mm_vic_Mo_HEAB",
		"RC_8Rnd_60mm_vic_Mo_HEAB",
		"RC_9Rnd_60mm_vic_Mo_HEAB",
		"RC_10Rnd_60mm_vic_Mo_HEAB",
		"RC_11Rnd_60mm_vic_Mo_HEAB",
		"RC_12Rnd_60mm_vic_Mo_HEAB",
		"RC_13Rnd_60mm_vic_Mo_HEAB",
		"RC_14Rnd_60mm_vic_Mo_HEAB",
		"RC_15Rnd_60mm_vic_Mo_HEAB",
		"RC_16Rnd_60mm_vic_Mo_HEAB",
		"RC_17Rnd_60mm_vic_Mo_HEAB",
		"RC_18Rnd_60mm_vic_Mo_HEAB",
		"RC_19Rnd_60mm_vic_Mo_HEAB",
		"RC_20Rnd_60mm_vic_Mo_HEAB",
		"RC_21Rnd_60mm_vic_Mo_HEAB",
		"RC_22Rnd_60mm_vic_Mo_HEAB",
		"RC_23Rnd_60mm_vic_Mo_HEAB",
		"RC_24Rnd_60mm_vic_Mo_HEAB",
		"RC_25Rnd_60mm_vic_Mo_HEAB",
		"RC_26Rnd_60mm_vic_Mo_HEAB",
		"RC_27Rnd_60mm_vic_Mo_HEAB",
		"RC_28Rnd_60mm_vic_Mo_HEAB",
		"RC_29Rnd_60mm_vic_Mo_HEAB",
		"RC_30Rnd_60mm_vic_Mo_HEAB",
		"RC_31Rnd_60mm_vic_Mo_HEAB",
		"RC_32Rnd_60mm_vic_Mo_HEAB",
		"RC_33Rnd_60mm_vic_Mo_HEAB",
		"RC_34Rnd_60mm_vic_Mo_HEAB",
		"RC_35Rnd_60mm_vic_Mo_HEAB",
		"RC_36Rnd_60mm_vic_Mo_HEAB",
		"RC_37Rnd_60mm_vic_Mo_HEAB",
		"RC_38Rnd_60mm_vic_Mo_HEAB",
		"RC_39Rnd_60mm_vic_Mo_HEAB",
		"RC_40Rnd_60mm_vic_Mo_HEAB",

		"RC_1Rnd_60mm_vic_Mo_Smoke_white",
		"RC_2Rnd_60mm_vic_Mo_Smoke_white",
		"RC_3Rnd_60mm_vic_Mo_Smoke_white",
		"RC_4Rnd_60mm_vic_Mo_Smoke_white",
		"RC_5Rnd_60mm_vic_Mo_Smoke_white",
		"RC_6Rnd_60mm_vic_Mo_Smoke_white",
		"RC_7Rnd_60mm_vic_Mo_Smoke_white",
		"RC_8Rnd_60mm_vic_Mo_Smoke_white",
		"RC_9Rnd_60mm_vic_Mo_Smoke_white",
		"RC_10Rnd_60mm_vic_Mo_Smoke_white",
		"RC_11Rnd_60mm_vic_Mo_Smoke_white",
		"RC_12Rnd_60mm_vic_Mo_Smoke_white",
		"RC_13Rnd_60mm_vic_Mo_Smoke_white",
		"RC_14Rnd_60mm_vic_Mo_Smoke_white",
		"RC_15Rnd_60mm_vic_Mo_Smoke_white",
		"RC_16Rnd_60mm_vic_Mo_Smoke_white",
		"RC_17Rnd_60mm_vic_Mo_Smoke_white",
		"RC_18Rnd_60mm_vic_Mo_Smoke_white",
		"RC_19Rnd_60mm_vic_Mo_Smoke_white",
		"RC_20Rnd_60mm_vic_Mo_Smoke_white",
		"RC_21Rnd_60mm_vic_Mo_Smoke_white",
		"RC_22Rnd_60mm_vic_Mo_Smoke_white",
		"RC_23Rnd_60mm_vic_Mo_Smoke_white",
		"RC_24Rnd_60mm_vic_Mo_Smoke_white",
		"RC_25Rnd_60mm_vic_Mo_Smoke_white",
		"RC_26Rnd_60mm_vic_Mo_Smoke_white",
		"RC_27Rnd_60mm_vic_Mo_Smoke_white",
		"RC_28Rnd_60mm_vic_Mo_Smoke_white",
		"RC_29Rnd_60mm_vic_Mo_Smoke_white",
		"RC_30Rnd_60mm_vic_Mo_Smoke_white",
		"RC_31Rnd_60mm_vic_Mo_Smoke_white",
		"RC_32Rnd_60mm_vic_Mo_Smoke_white",
		"RC_33Rnd_60mm_vic_Mo_Smoke_white",
		"RC_34Rnd_60mm_vic_Mo_Smoke_white",
		"RC_35Rnd_60mm_vic_Mo_Smoke_white",
		"RC_36Rnd_60mm_vic_Mo_Smoke_white",
		"RC_37Rnd_60mm_vic_Mo_Smoke_white",
		"RC_38Rnd_60mm_vic_Mo_Smoke_white",
		"RC_39Rnd_60mm_vic_Mo_Smoke_white",
		"RC_40Rnd_60mm_vic_Mo_Smoke_white",

		"RC_1Rnd_60mm_vic_Mo_LaserGuided",
		"RC_2Rnd_60mm_vic_Mo_LaserGuided",
		"RC_3Rnd_60mm_vic_Mo_LaserGuided",
		"RC_4Rnd_60mm_vic_Mo_LaserGuided",
		"RC_5Rnd_60mm_vic_Mo_LaserGuided",
		"RC_6Rnd_60mm_vic_Mo_LaserGuided",
		"RC_7Rnd_60mm_vic_Mo_LaserGuided",
		"RC_8Rnd_60mm_vic_Mo_LaserGuided",
		"RC_9Rnd_60mm_vic_Mo_LaserGuided",
		"RC_10Rnd_60mm_vic_Mo_LaserGuided",
		"RC_11Rnd_60mm_vic_Mo_LaserGuided",
		"RC_12Rnd_60mm_vic_Mo_LaserGuided",
		"RC_13Rnd_60mm_vic_Mo_LaserGuided",
		"RC_14Rnd_60mm_vic_Mo_LaserGuided",
		"RC_15Rnd_60mm_vic_Mo_LaserGuided",
		"RC_16Rnd_60mm_vic_Mo_LaserGuided",
		"RC_17Rnd_60mm_vic_Mo_LaserGuided",
		"RC_18Rnd_60mm_vic_Mo_LaserGuided",
		"RC_19Rnd_60mm_vic_Mo_LaserGuided",
		"RC_20Rnd_60mm_vic_Mo_LaserGuided",
		"RC_21Rnd_60mm_vic_Mo_LaserGuided",
		"RC_22Rnd_60mm_vic_Mo_LaserGuided",
		"RC_23Rnd_60mm_vic_Mo_LaserGuided",
		"RC_24Rnd_60mm_vic_Mo_LaserGuided",
		"RC_25Rnd_60mm_vic_Mo_LaserGuided",
		"RC_26Rnd_60mm_vic_Mo_LaserGuided",
		"RC_27Rnd_60mm_vic_Mo_LaserGuided",
		"RC_28Rnd_60mm_vic_Mo_LaserGuided",
		"RC_29Rnd_60mm_vic_Mo_LaserGuided",
		"RC_30Rnd_60mm_vic_Mo_LaserGuided",
		"RC_31Rnd_60mm_vic_Mo_LaserGuided",
		"RC_32Rnd_60mm_vic_Mo_LaserGuided",
		"RC_33Rnd_60mm_vic_Mo_LaserGuided",
		"RC_34Rnd_60mm_vic_Mo_LaserGuided",
		"RC_35Rnd_60mm_vic_Mo_LaserGuided",
		"RC_36Rnd_60mm_vic_Mo_LaserGuided",
		"RC_37Rnd_60mm_vic_Mo_LaserGuided",
		"RC_38Rnd_60mm_vic_Mo_LaserGuided",
		"RC_39Rnd_60mm_vic_Mo_LaserGuided",
		"RC_40Rnd_60mm_vic_Mo_LaserGuided",

		"RC_1Rnd_60mm_vic_Mo_MultiGuided",
		"RC_2Rnd_60mm_vic_Mo_MultiGuided",
		"RC_3Rnd_60mm_vic_Mo_MultiGuided",
		"RC_4Rnd_60mm_vic_Mo_MultiGuided",
		"RC_5Rnd_60mm_vic_Mo_MultiGuided",
		"RC_6Rnd_60mm_vic_Mo_MultiGuided",
		"RC_7Rnd_60mm_vic_Mo_MultiGuided",
		"RC_8Rnd_60mm_vic_Mo_MultiGuided",
		"RC_9Rnd_60mm_vic_Mo_MultiGuided",
		"RC_10Rnd_60mm_vic_Mo_MultiGuided",
		"RC_11Rnd_60mm_vic_Mo_MultiGuided",
		"RC_12Rnd_60mm_vic_Mo_MultiGuided",
		"RC_13Rnd_60mm_vic_Mo_MultiGuided",
		"RC_14Rnd_60mm_vic_Mo_MultiGuided",
		"RC_15Rnd_60mm_vic_Mo_MultiGuided",
		"RC_16Rnd_60mm_vic_Mo_MultiGuided",
		"RC_17Rnd_60mm_vic_Mo_MultiGuided",
		"RC_18Rnd_60mm_vic_Mo_MultiGuided",
		"RC_19Rnd_60mm_vic_Mo_MultiGuided",
		"RC_20Rnd_60mm_vic_Mo_MultiGuided",
		"RC_21Rnd_60mm_vic_Mo_MultiGuided",
		"RC_22Rnd_60mm_vic_Mo_MultiGuided",
		"RC_23Rnd_60mm_vic_Mo_MultiGuided",
		"RC_24Rnd_60mm_vic_Mo_MultiGuided",
		"RC_25Rnd_60mm_vic_Mo_MultiGuided",
		"RC_26Rnd_60mm_vic_Mo_MultiGuided",
		"RC_27Rnd_60mm_vic_Mo_MultiGuided",
		"RC_28Rnd_60mm_vic_Mo_MultiGuided",
		"RC_29Rnd_60mm_vic_Mo_MultiGuided",
		"RC_30Rnd_60mm_vic_Mo_MultiGuided",
		"RC_31Rnd_60mm_vic_Mo_MultiGuided",
		"RC_32Rnd_60mm_vic_Mo_MultiGuided",
		"RC_33Rnd_60mm_vic_Mo_MultiGuided",
		"RC_34Rnd_60mm_vic_Mo_MultiGuided",
		"RC_35Rnd_60mm_vic_Mo_MultiGuided",
		"RC_36Rnd_60mm_vic_Mo_MultiGuided",
		"RC_37Rnd_60mm_vic_Mo_MultiGuided",
		"RC_38Rnd_60mm_vic_Mo_MultiGuided",
		"RC_39Rnd_60mm_vic_Mo_MultiGuided",
		"RC_40Rnd_60mm_vic_Mo_MultiGuided",

		"RC_1Rnd_60mm_vic_Mo_mine",
		"RC_2Rnd_60mm_vic_Mo_mine",
		"RC_3Rnd_60mm_vic_Mo_mine",
		"RC_4Rnd_60mm_vic_Mo_mine",
		"RC_5Rnd_60mm_vic_Mo_mine",
		"RC_6Rnd_60mm_vic_Mo_mine",
		"RC_7Rnd_60mm_vic_Mo_mine",
		"RC_8Rnd_60mm_vic_Mo_mine",
		"RC_9Rnd_60mm_vic_Mo_mine",
		"RC_10Rnd_60mm_vic_Mo_mine",
		"RC_11Rnd_60mm_vic_Mo_mine",
		"RC_12Rnd_60mm_vic_Mo_mine",
		"RC_13Rnd_60mm_vic_Mo_mine",
		"RC_14Rnd_60mm_vic_Mo_mine",
		"RC_15Rnd_60mm_vic_Mo_mine",
		"RC_16Rnd_60mm_vic_Mo_mine",
		"RC_17Rnd_60mm_vic_Mo_mine",
		"RC_18Rnd_60mm_vic_Mo_mine",
		"RC_19Rnd_60mm_vic_Mo_mine",
		"RC_20Rnd_60mm_vic_Mo_mine",
		"RC_21Rnd_60mm_vic_Mo_mine",
		"RC_22Rnd_60mm_vic_Mo_mine",
		"RC_23Rnd_60mm_vic_Mo_mine",
		"RC_24Rnd_60mm_vic_Mo_mine",
		"RC_25Rnd_60mm_vic_Mo_mine",
		"RC_26Rnd_60mm_vic_Mo_mine",
		"RC_27Rnd_60mm_vic_Mo_mine",
		"RC_28Rnd_60mm_vic_Mo_mine",
		"RC_29Rnd_60mm_vic_Mo_mine",
		"RC_30Rnd_60mm_vic_Mo_mine",
		"RC_31Rnd_60mm_vic_Mo_mine",
		"RC_32Rnd_60mm_vic_Mo_mine",
		"RC_33Rnd_60mm_vic_Mo_mine",
		"RC_34Rnd_60mm_vic_Mo_mine",
		"RC_35Rnd_60mm_vic_Mo_mine",
		"RC_36Rnd_60mm_vic_Mo_mine",
		"RC_37Rnd_60mm_vic_Mo_mine",
		"RC_38Rnd_60mm_vic_Mo_mine",
		"RC_39Rnd_60mm_vic_Mo_mine",
		"RC_40Rnd_60mm_vic_Mo_mine",

		"RC_1Rnd_60mm_vic_Mo_Flare_white",
		"RC_2Rnd_60mm_vic_Mo_Flare_white",
		"RC_3Rnd_60mm_vic_Mo_Flare_white",
		"RC_4Rnd_60mm_vic_Mo_Flare_white",
		"RC_5Rnd_60mm_vic_Mo_Flare_white",
		"RC_6Rnd_60mm_vic_Mo_Flare_white",
		"RC_7Rnd_60mm_vic_Mo_Flare_white",
		"RC_8Rnd_60mm_vic_Mo_Flare_white",
		"RC_9Rnd_60mm_vic_Mo_Flare_white",
		"RC_10Rnd_60mm_vic_Mo_Flare_white",
		"RC_11Rnd_60mm_vic_Mo_Flare_white",
		"RC_12Rnd_60mm_vic_Mo_Flare_white",
		"RC_13Rnd_60mm_vic_Mo_Flare_white",
		"RC_14Rnd_60mm_vic_Mo_Flare_white",
		"RC_15Rnd_60mm_vic_Mo_Flare_white",
		"RC_16Rnd_60mm_vic_Mo_Flare_white",
		"RC_17Rnd_60mm_vic_Mo_Flare_white",
		"RC_18Rnd_60mm_vic_Mo_Flare_white",
		"RC_19Rnd_60mm_vic_Mo_Flare_white",
		"RC_20Rnd_60mm_vic_Mo_Flare_white",
		"RC_21Rnd_60mm_vic_Mo_Flare_white",
		"RC_22Rnd_60mm_vic_Mo_Flare_white",
		"RC_23Rnd_60mm_vic_Mo_Flare_white",
		"RC_24Rnd_60mm_vic_Mo_Flare_white",
		"RC_25Rnd_60mm_vic_Mo_Flare_white",
		"RC_26Rnd_60mm_vic_Mo_Flare_white",
		"RC_27Rnd_60mm_vic_Mo_Flare_white",
		"RC_28Rnd_60mm_vic_Mo_Flare_white",
		"RC_29Rnd_60mm_vic_Mo_Flare_white",
		"RC_30Rnd_60mm_vic_Mo_Flare_white",
		"RC_31Rnd_60mm_vic_Mo_Flare_white",
		"RC_32Rnd_60mm_vic_Mo_Flare_white",
		"RC_33Rnd_60mm_vic_Mo_Flare_white",
		"RC_34Rnd_60mm_vic_Mo_Flare_white",
		"RC_35Rnd_60mm_vic_Mo_Flare_white",
		"RC_36Rnd_60mm_vic_Mo_Flare_white",
		"RC_37Rnd_60mm_vic_Mo_Flare_white",
		"RC_38Rnd_60mm_vic_Mo_Flare_white",
		"RC_39Rnd_60mm_vic_Mo_Flare_white",
		"RC_40Rnd_60mm_vic_Mo_Flare_white",

		"RC_1Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_2Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_3Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_4Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_5Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_6Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_7Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_8Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_9Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_10Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_11Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_12Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_13Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_14Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_15Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_16Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_17Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_18Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_19Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_20Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_21Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_22Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_23Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_24Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_25Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_26Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_27Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_28Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_29Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_30Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_31Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_32Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_33Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_34Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_35Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_36Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_37Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_38Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_39Rnd_60mm_vic_Mo_LG_DelayedFuse",
		"RC_40Rnd_60mm_vic_Mo_LG_DelayedFuse",

		"RC_1Rnd_60mm_vic_Mo_backupHEAB",
		"RC_2Rnd_60mm_vic_Mo_backupHEAB",
		"RC_3Rnd_60mm_vic_Mo_backupHEAB",
		"RC_4Rnd_60mm_vic_Mo_backupHEAB",
		"RC_5Rnd_60mm_vic_Mo_backupHEAB",
		"RC_6Rnd_60mm_vic_Mo_backupHEAB",
		"RC_7Rnd_60mm_vic_Mo_backupHEAB",
		"RC_8Rnd_60mm_vic_Mo_backupHEAB",
		"RC_9Rnd_60mm_vic_Mo_backupHEAB",
		"RC_10Rnd_60mm_vic_Mo_backupHEAB",
		"RC_11Rnd_60mm_vic_Mo_backupHEAB",
		"RC_12Rnd_60mm_vic_Mo_backupHEAB",
		"RC_13Rnd_60mm_vic_Mo_backupHEAB",
		"RC_14Rnd_60mm_vic_Mo_backupHEAB",
		"RC_15Rnd_60mm_vic_Mo_backupHEAB",
		"RC_16Rnd_60mm_vic_Mo_backupHEAB",
		"RC_17Rnd_60mm_vic_Mo_backupHEAB",
		"RC_18Rnd_60mm_vic_Mo_backupHEAB",
		"RC_19Rnd_60mm_vic_Mo_backupHEAB",
		"RC_20Rnd_60mm_vic_Mo_backupHEAB",
		"RC_21Rnd_60mm_vic_Mo_backupHEAB",
		"RC_22Rnd_60mm_vic_Mo_backupHEAB",
		"RC_23Rnd_60mm_vic_Mo_backupHEAB",
		"RC_24Rnd_60mm_vic_Mo_backupHEAB",
		"RC_25Rnd_60mm_vic_Mo_backupHEAB",
		"RC_26Rnd_60mm_vic_Mo_backupHEAB",
		"RC_27Rnd_60mm_vic_Mo_backupHEAB",
		"RC_28Rnd_60mm_vic_Mo_backupHEAB",
		"RC_29Rnd_60mm_vic_Mo_backupHEAB",
		"RC_30Rnd_60mm_vic_Mo_backupHEAB",
		"RC_31Rnd_60mm_vic_Mo_backupHEAB",
		"RC_32Rnd_60mm_vic_Mo_backupHEAB",
		"RC_33Rnd_60mm_vic_Mo_backupHEAB",
		"RC_34Rnd_60mm_vic_Mo_backupHEAB",
		"RC_35Rnd_60mm_vic_Mo_backupHEAB",
		"RC_36Rnd_60mm_vic_Mo_backupHEAB",
		"RC_37Rnd_60mm_vic_Mo_backupHEAB",
		"RC_38Rnd_60mm_vic_Mo_backupHEAB",
		"RC_39Rnd_60mm_vic_Mo_backupHEAB",
		"RC_40Rnd_60mm_vic_Mo_backupHEAB"
	};
};


//indirect 40mm GMG
class RC_indirect_40mm_GMG_V4: RC_vehiclemortar_60mm_V4
{
	displayName="indirect 40mm GMG";
	displayNameShort="indirect 40mm GMG";
	//ballisticsComputer=8;	//direct fire reticle for highest charge
	
	reloadTime=0.25;
	magazineReloadTime=2.5;
	autoFire=1;
	autoReload=1;
	textureType="fullAuto";
	type="1+4";

	magazines[]=
	{
		"RC_200Rnd_40mm_vic_Mo_shells"
	};

	modes[]=
	{
		"auto1",
		"auto2",
		"auto3"
	};
	class auto1: Single1
	{
		displayName="CH1, 0.5km";
		//artilleryDispersion=1.25;
		reloadTime=0.25;
		autoFire=1;
		autoReload=1;
		textureType="fullAuto";
		type="1+4";

		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_01",
				1.1220185,
				1,
				1200
			};
			begin2[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_02",
				1.1220185,
				1,
				1200
			};
			begin3[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_03",
				1.1220185,
				1,
				1200
			};
			soundBegin[]=
			{
				"begin1",
				0.33000001,
				"begin2",
				0.33000001,
				"begin3",
				0.34
			};
		};
		soundContinuous=0;
		soundBurst=0;
	};
	class auto2: auto1
	{
		displayName="CH1, 2km";
		artilleryCharge=0.7;
		minRange=139;	//139	//230
		midRange=1068.5;	//1068.5	1175
		maxRange=1998;	//1998	//2660
	};
	class auto3: auto1
	{
		displayName="CH2, 4km, reticle";
		artilleryCharge=1;
		minRange=284;	//284	//540
		midRange=2181;	//2181	//2355
		maxRange=4078;	//4078	//5500
	};
	class GunParticles
	{
		class effect1
		{
			positionName="usti hlavne";
			directionName="konec hlavne";
			effectName="GrenadeLauncherCloud";
		};
	};
};

// 120mm ShipCannon
class weapon_ShipCannon_120mm;
class RC_ShipCannon_120mm_base: weapon_ShipCannon_120mm
{
	class Single1;
	class Single2;
	class Single3;
	class Single4;
	class Single5;
	class Burst1;
	class Burst2;
	class Burst3;
	class Burst4;
	class Burst5;
};
class RC_ShipCannon_120mm_V1: RC_ShipCannon_120mm_base
{
	magazines[]=
	{
		"RC_1Rnd_120mm_Mo_shells",
		"RC_2Rnd_120mm_Mo_shells",
		"RC_3Rnd_120mm_Mo_shells",
		"RC_4Rnd_120mm_Mo_shells",
		"RC_5Rnd_120mm_Mo_shells",
		"RC_6Rnd_120mm_Mo_shells",
		"RC_7Rnd_120mm_Mo_shells",
		"RC_8Rnd_120mm_Mo_shells",
		"RC_9Rnd_120mm_Mo_shells",
		"RC_10Rnd_120mm_Mo_shells",
		"RC_11Rnd_120mm_Mo_shells",
		"RC_12Rnd_120mm_Mo_shells",
		"RC_13Rnd_120mm_Mo_shells",
		"RC_14Rnd_120mm_Mo_shells",
		"RC_15Rnd_120mm_Mo_shells",
		"RC_16Rnd_120mm_Mo_shells",
		"RC_17Rnd_120mm_Mo_shells",
		"RC_18Rnd_120mm_Mo_shells",
		"RC_19Rnd_120mm_Mo_shells",
		"RC_20Rnd_120mm_Mo_shells",
		"RC_21Rnd_120mm_Mo_shells",
		"RC_22Rnd_120mm_Mo_shells",
		"RC_23Rnd_120mm_Mo_shells",
		"RC_24Rnd_120mm_Mo_shells",
		"RC_25Rnd_120mm_Mo_shells",
		"RC_26Rnd_120mm_Mo_shells",
		"RC_27Rnd_120mm_Mo_shells",
		"RC_28Rnd_120mm_Mo_shells",
		"RC_29Rnd_120mm_Mo_shells",
		"RC_30Rnd_120mm_Mo_shells",
		"RC_31Rnd_120mm_Mo_shells",
		"RC_32Rnd_120mm_Mo_shells",
		"RC_33Rnd_120mm_Mo_shells",
		"RC_34Rnd_120mm_Mo_shells",
		"RC_35Rnd_120mm_Mo_shells",
		"RC_36Rnd_120mm_Mo_shells",
		"RC_37Rnd_120mm_Mo_shells",
		"RC_38Rnd_120mm_Mo_shells",
		"RC_39Rnd_120mm_Mo_shells",
		"RC_40Rnd_120mm_Mo_shells",

		"RC_1Rnd_120mm_Mo_HEAB",
		"RC_2Rnd_120mm_Mo_HEAB",
		"RC_3Rnd_120mm_Mo_HEAB",
		"RC_4Rnd_120mm_Mo_HEAB",
		"RC_5Rnd_120mm_Mo_HEAB",
		"RC_6Rnd_120mm_Mo_HEAB",
		"RC_7Rnd_120mm_Mo_HEAB",
		"RC_8Rnd_120mm_Mo_HEAB",
		"RC_9Rnd_120mm_Mo_HEAB",
		"RC_10Rnd_120mm_Mo_HEAB",
		"RC_11Rnd_120mm_Mo_HEAB",
		"RC_12Rnd_120mm_Mo_HEAB",
		"RC_13Rnd_120mm_Mo_HEAB",
		"RC_14Rnd_120mm_Mo_HEAB",
		"RC_15Rnd_120mm_Mo_HEAB",
		"RC_16Rnd_120mm_Mo_HEAB",
		"RC_17Rnd_120mm_Mo_HEAB",
		"RC_18Rnd_120mm_Mo_HEAB",
		"RC_19Rnd_120mm_Mo_HEAB",
		"RC_20Rnd_120mm_Mo_HEAB",
		"RC_21Rnd_120mm_Mo_HEAB",
		"RC_22Rnd_120mm_Mo_HEAB",
		"RC_23Rnd_120mm_Mo_HEAB",
		"RC_24Rnd_120mm_Mo_HEAB",
		"RC_25Rnd_120mm_Mo_HEAB",
		"RC_26Rnd_120mm_Mo_HEAB",
		"RC_27Rnd_120mm_Mo_HEAB",
		"RC_28Rnd_120mm_Mo_HEAB",
		"RC_29Rnd_120mm_Mo_HEAB",
		"RC_30Rnd_120mm_Mo_HEAB",
		"RC_31Rnd_120mm_Mo_HEAB",
		"RC_32Rnd_120mm_Mo_HEAB",
		"RC_33Rnd_120mm_Mo_HEAB",
		"RC_34Rnd_120mm_Mo_HEAB",
		"RC_35Rnd_120mm_Mo_HEAB",
		"RC_36Rnd_120mm_Mo_HEAB",
		"RC_37Rnd_120mm_Mo_HEAB",
		"RC_38Rnd_120mm_Mo_HEAB",
		"RC_39Rnd_120mm_Mo_HEAB",
		"RC_40Rnd_120mm_Mo_HEAB",

		"RC_1Rnd_120mm_Mo_lowHEAB",
		"RC_2Rnd_120mm_Mo_lowHEAB",
		"RC_3Rnd_120mm_Mo_lowHEAB",
		"RC_4Rnd_120mm_Mo_lowHEAB",
		"RC_5Rnd_120mm_Mo_lowHEAB",
		"RC_6Rnd_120mm_Mo_lowHEAB",
		"RC_7Rnd_120mm_Mo_lowHEAB",
		"RC_8Rnd_120mm_Mo_lowHEAB",
		"RC_9Rnd_120mm_Mo_lowHEAB",
		"RC_10Rnd_120mm_Mo_lowHEAB",
		"RC_11Rnd_120mm_Mo_lowHEAB",
		"RC_12Rnd_120mm_Mo_lowHEAB",
		"RC_13Rnd_120mm_Mo_lowHEAB",
		"RC_14Rnd_120mm_Mo_lowHEAB",
		"RC_15Rnd_120mm_Mo_lowHEAB",
		"RC_16Rnd_120mm_Mo_lowHEAB",
		"RC_17Rnd_120mm_Mo_lowHEAB",
		"RC_18Rnd_120mm_Mo_lowHEAB",
		"RC_19Rnd_120mm_Mo_lowHEAB",
		"RC_20Rnd_120mm_Mo_lowHEAB",
		"RC_21Rnd_120mm_Mo_lowHEAB",
		"RC_22Rnd_120mm_Mo_lowHEAB",
		"RC_23Rnd_120mm_Mo_lowHEAB",
		"RC_24Rnd_120mm_Mo_lowHEAB",
		"RC_25Rnd_120mm_Mo_lowHEAB",
		"RC_26Rnd_120mm_Mo_lowHEAB",
		"RC_27Rnd_120mm_Mo_lowHEAB",
		"RC_28Rnd_120mm_Mo_lowHEAB",
		"RC_29Rnd_120mm_Mo_lowHEAB",
		"RC_30Rnd_120mm_Mo_lowHEAB",
		"RC_31Rnd_120mm_Mo_lowHEAB",
		"RC_32Rnd_120mm_Mo_lowHEAB",
		"RC_33Rnd_120mm_Mo_lowHEAB",
		"RC_34Rnd_120mm_Mo_lowHEAB",
		"RC_35Rnd_120mm_Mo_lowHEAB",
		"RC_36Rnd_120mm_Mo_lowHEAB",
		"RC_37Rnd_120mm_Mo_lowHEAB",
		"RC_38Rnd_120mm_Mo_lowHEAB",
		"RC_39Rnd_120mm_Mo_lowHEAB",
		"RC_40Rnd_120mm_Mo_lowHEAB",

		"RC_1Rnd_120mm_Mo_smoke",
		"RC_2Rnd_120mm_Mo_smoke",
		"RC_3Rnd_120mm_Mo_smoke",
		"RC_4Rnd_120mm_Mo_smoke",
		"RC_5Rnd_120mm_Mo_smoke",
		"RC_6Rnd_120mm_Mo_smoke",
		"RC_7Rnd_120mm_Mo_smoke",
		"RC_8Rnd_120mm_Mo_smoke",
		"RC_9Rnd_120mm_Mo_smoke",
		"RC_10Rnd_120mm_Mo_smoke",
		"RC_11Rnd_120mm_Mo_smoke",
		"RC_12Rnd_120mm_Mo_smoke",
		"RC_13Rnd_120mm_Mo_smoke",
		"RC_14Rnd_120mm_Mo_smoke",
		"RC_15Rnd_120mm_Mo_smoke",
		"RC_16Rnd_120mm_Mo_smoke",
		"RC_17Rnd_120mm_Mo_smoke",
		"RC_18Rnd_120mm_Mo_smoke",
		"RC_19Rnd_120mm_Mo_smoke",
		"RC_20Rnd_120mm_Mo_smoke",
		"RC_21Rnd_120mm_Mo_smoke",
		"RC_22Rnd_120mm_Mo_smoke",
		"RC_23Rnd_120mm_Mo_smoke",
		"RC_24Rnd_120mm_Mo_smoke",
		"RC_25Rnd_120mm_Mo_smoke",
		"RC_26Rnd_120mm_Mo_smoke",
		"RC_27Rnd_120mm_Mo_smoke",
		"RC_28Rnd_120mm_Mo_smoke",
		"RC_29Rnd_120mm_Mo_smoke",
		"RC_30Rnd_120mm_Mo_smoke",
		"RC_31Rnd_120mm_Mo_smoke",
		"RC_32Rnd_120mm_Mo_smoke",
		"RC_33Rnd_120mm_Mo_smoke",
		"RC_34Rnd_120mm_Mo_smoke",
		"RC_35Rnd_120mm_Mo_smoke",
		"RC_36Rnd_120mm_Mo_smoke",
		"RC_37Rnd_120mm_Mo_smoke",
		"RC_38Rnd_120mm_Mo_smoke",
		"RC_39Rnd_120mm_Mo_smoke",
		"RC_40Rnd_120mm_Mo_smoke",

		"RC_1Rnd_120mm_Mo_Cluster",
		"RC_2Rnd_120mm_Mo_Cluster",
		"RC_3Rnd_120mm_Mo_Cluster",
		"RC_4Rnd_120mm_Mo_Cluster",
		"RC_5Rnd_120mm_Mo_Cluster",
		"RC_6Rnd_120mm_Mo_Cluster",
		"RC_7Rnd_120mm_Mo_Cluster",
		"RC_8Rnd_120mm_Mo_Cluster",
		"RC_9Rnd_120mm_Mo_Cluster",
		"RC_10Rnd_120mm_Mo_Cluster",
		"RC_11Rnd_120mm_Mo_Cluster",
		"RC_12Rnd_120mm_Mo_Cluster",
		"RC_13Rnd_120mm_Mo_Cluster",
		"RC_14Rnd_120mm_Mo_Cluster",
		"RC_15Rnd_120mm_Mo_Cluster",
		"RC_16Rnd_120mm_Mo_Cluster",
		"RC_17Rnd_120mm_Mo_Cluster",
		"RC_18Rnd_120mm_Mo_Cluster",
		"RC_19Rnd_120mm_Mo_Cluster",
		"RC_20Rnd_120mm_Mo_Cluster",
		"RC_21Rnd_120mm_Mo_Cluster",
		"RC_22Rnd_120mm_Mo_Cluster",
		"RC_23Rnd_120mm_Mo_Cluster",
		"RC_24Rnd_120mm_Mo_Cluster",
		"RC_25Rnd_120mm_Mo_Cluster",
		"RC_26Rnd_120mm_Mo_Cluster",
		"RC_27Rnd_120mm_Mo_Cluster",
		"RC_28Rnd_120mm_Mo_Cluster",
		"RC_29Rnd_120mm_Mo_Cluster",
		"RC_30Rnd_120mm_Mo_Cluster",
		"RC_31Rnd_120mm_Mo_Cluster",
		"RC_32Rnd_120mm_Mo_Cluster",
		"RC_33Rnd_120mm_Mo_Cluster",
		"RC_34Rnd_120mm_Mo_Cluster",
		"RC_35Rnd_120mm_Mo_Cluster",
		"RC_36Rnd_120mm_Mo_Cluster",
		"RC_37Rnd_120mm_Mo_Cluster",
		"RC_38Rnd_120mm_Mo_Cluster",
		"RC_39Rnd_120mm_Mo_Cluster",
		"RC_40Rnd_120mm_Mo_Cluster",

		"RC_1Rnd_120mm_Mo_LaserGuided",
		"RC_2Rnd_120mm_Mo_LaserGuided",
		"RC_3Rnd_120mm_Mo_LaserGuided",
		"RC_4Rnd_120mm_Mo_LaserGuided",
		"RC_5Rnd_120mm_Mo_LaserGuided",
		"RC_6Rnd_120mm_Mo_LaserGuided",
		"RC_7Rnd_120mm_Mo_LaserGuided",
		"RC_8Rnd_120mm_Mo_LaserGuided",
		"RC_9Rnd_120mm_Mo_LaserGuided",
		"RC_10Rnd_120mm_Mo_LaserGuided",
		"RC_11Rnd_120mm_Mo_LaserGuided",
		"RC_12Rnd_120mm_Mo_LaserGuided",
		"RC_13Rnd_120mm_Mo_LaserGuided",
		"RC_14Rnd_120mm_Mo_LaserGuided",
		"RC_15Rnd_120mm_Mo_LaserGuided",
		"RC_16Rnd_120mm_Mo_LaserGuided",
		"RC_17Rnd_120mm_Mo_LaserGuided",
		"RC_18Rnd_120mm_Mo_LaserGuided",
		"RC_19Rnd_120mm_Mo_LaserGuided",
		"RC_20Rnd_120mm_Mo_LaserGuided",
		"RC_21Rnd_120mm_Mo_LaserGuided",
		"RC_22Rnd_120mm_Mo_LaserGuided",
		"RC_23Rnd_120mm_Mo_LaserGuided",
		"RC_24Rnd_120mm_Mo_LaserGuided",
		"RC_25Rnd_120mm_Mo_LaserGuided",
		"RC_26Rnd_120mm_Mo_LaserGuided",
		"RC_27Rnd_120mm_Mo_LaserGuided",
		"RC_28Rnd_120mm_Mo_LaserGuided",
		"RC_29Rnd_120mm_Mo_LaserGuided",
		"RC_30Rnd_120mm_Mo_LaserGuided",
		"RC_31Rnd_120mm_Mo_LaserGuided",
		"RC_32Rnd_120mm_Mo_LaserGuided",
		"RC_33Rnd_120mm_Mo_LaserGuided",
		"RC_34Rnd_120mm_Mo_LaserGuided",
		"RC_35Rnd_120mm_Mo_LaserGuided",
		"RC_36Rnd_120mm_Mo_LaserGuided",
		"RC_37Rnd_120mm_Mo_LaserGuided",
		"RC_38Rnd_120mm_Mo_LaserGuided",
		"RC_39Rnd_120mm_Mo_LaserGuided",
		"RC_40Rnd_120mm_Mo_LaserGuided",

		"RC_1Rnd_120mm_Mo_MultiGuided",
		"RC_2Rnd_120mm_Mo_MultiGuided",
		"RC_3Rnd_120mm_Mo_MultiGuided",
		"RC_4Rnd_120mm_Mo_MultiGuided",
		"RC_5Rnd_120mm_Mo_MultiGuided",
		"RC_6Rnd_120mm_Mo_MultiGuided",
		"RC_7Rnd_120mm_Mo_MultiGuided",
		"RC_8Rnd_120mm_Mo_MultiGuided",
		"RC_9Rnd_120mm_Mo_MultiGuided",
		"RC_10Rnd_120mm_Mo_MultiGuided",
		"RC_11Rnd_120mm_Mo_MultiGuided",
		"RC_12Rnd_120mm_Mo_MultiGuided",
		"RC_13Rnd_120mm_Mo_MultiGuided",
		"RC_14Rnd_120mm_Mo_MultiGuided",
		"RC_15Rnd_120mm_Mo_MultiGuided",
		"RC_16Rnd_120mm_Mo_MultiGuided",
		"RC_17Rnd_120mm_Mo_MultiGuided",
		"RC_18Rnd_120mm_Mo_MultiGuided",
		"RC_19Rnd_120mm_Mo_MultiGuided",
		"RC_20Rnd_120mm_Mo_MultiGuided",
		"RC_21Rnd_120mm_Mo_MultiGuided",
		"RC_22Rnd_120mm_Mo_MultiGuided",
		"RC_23Rnd_120mm_Mo_MultiGuided",
		"RC_24Rnd_120mm_Mo_MultiGuided",
		"RC_25Rnd_120mm_Mo_MultiGuided",
		"RC_26Rnd_120mm_Mo_MultiGuided",
		"RC_27Rnd_120mm_Mo_MultiGuided",
		"RC_28Rnd_120mm_Mo_MultiGuided",
		"RC_29Rnd_120mm_Mo_MultiGuided",
		"RC_30Rnd_120mm_Mo_MultiGuided",
		"RC_31Rnd_120mm_Mo_MultiGuided",
		"RC_32Rnd_120mm_Mo_MultiGuided",
		"RC_33Rnd_120mm_Mo_MultiGuided",
		"RC_34Rnd_120mm_Mo_MultiGuided",
		"RC_35Rnd_120mm_Mo_MultiGuided",
		"RC_36Rnd_120mm_Mo_MultiGuided",
		"RC_37Rnd_120mm_Mo_MultiGuided",
		"RC_38Rnd_120mm_Mo_MultiGuided",
		"RC_39Rnd_120mm_Mo_MultiGuided",
		"RC_40Rnd_120mm_Mo_MultiGuided",

		"RC_1Rnd_120mm_Mo_mine",
		"RC_2Rnd_120mm_Mo_mine",
		"RC_3Rnd_120mm_Mo_mine",
		"RC_4Rnd_120mm_Mo_mine",
		"RC_5Rnd_120mm_Mo_mine",
		"RC_6Rnd_120mm_Mo_mine",
		"RC_7Rnd_120mm_Mo_mine",
		"RC_8Rnd_120mm_Mo_mine",
		"RC_9Rnd_120mm_Mo_mine",
		"RC_10Rnd_120mm_Mo_mine",
		"RC_11Rnd_120mm_Mo_mine",
		"RC_12Rnd_120mm_Mo_mine",
		"RC_13Rnd_120mm_Mo_mine",
		"RC_14Rnd_120mm_Mo_mine",
		"RC_15Rnd_120mm_Mo_mine",
		"RC_16Rnd_120mm_Mo_mine",
		"RC_17Rnd_120mm_Mo_mine",
		"RC_18Rnd_120mm_Mo_mine",
		"RC_19Rnd_120mm_Mo_mine",
		"RC_20Rnd_120mm_Mo_mine",
		"RC_21Rnd_120mm_Mo_mine",
		"RC_22Rnd_120mm_Mo_mine",
		"RC_23Rnd_120mm_Mo_mine",
		"RC_24Rnd_120mm_Mo_mine",
		"RC_25Rnd_120mm_Mo_mine",
		"RC_26Rnd_120mm_Mo_mine",
		"RC_27Rnd_120mm_Mo_mine",
		"RC_28Rnd_120mm_Mo_mine",
		"RC_29Rnd_120mm_Mo_mine",
		"RC_30Rnd_120mm_Mo_mine",
		"RC_31Rnd_120mm_Mo_mine",
		"RC_32Rnd_120mm_Mo_mine",
		"RC_33Rnd_120mm_Mo_mine",
		"RC_34Rnd_120mm_Mo_mine",
		"RC_35Rnd_120mm_Mo_mine",
		"RC_36Rnd_120mm_Mo_mine",
		"RC_37Rnd_120mm_Mo_mine",
		"RC_38Rnd_120mm_Mo_mine",
		"RC_39Rnd_120mm_Mo_mine",
		"RC_40Rnd_120mm_Mo_mine",

		"RC_1Rnd_120mm_Mo_AT_mine",
		"RC_2Rnd_120mm_Mo_AT_mine",
		"RC_3Rnd_120mm_Mo_AT_mine",
		"RC_4Rnd_120mm_Mo_AT_mine",
		"RC_5Rnd_120mm_Mo_AT_mine",
		"RC_6Rnd_120mm_Mo_AT_mine",
		"RC_7Rnd_120mm_Mo_AT_mine",
		"RC_8Rnd_120mm_Mo_AT_mine",
		"RC_9Rnd_120mm_Mo_AT_mine",
		"RC_10Rnd_120mm_Mo_AT_mine",
		"RC_11Rnd_120mm_Mo_AT_mine",
		"RC_12Rnd_120mm_Mo_AT_mine",
		"RC_13Rnd_120mm_Mo_AT_mine",
		"RC_14Rnd_120mm_Mo_AT_mine",
		"RC_15Rnd_120mm_Mo_AT_mine",
		"RC_16Rnd_120mm_Mo_AT_mine",
		"RC_17Rnd_120mm_Mo_AT_mine",
		"RC_18Rnd_120mm_Mo_AT_mine",
		"RC_19Rnd_120mm_Mo_AT_mine",
		"RC_20Rnd_120mm_Mo_AT_mine",
		"RC_21Rnd_120mm_Mo_AT_mine",
		"RC_22Rnd_120mm_Mo_AT_mine",
		"RC_23Rnd_120mm_Mo_AT_mine",
		"RC_24Rnd_120mm_Mo_AT_mine",
		"RC_25Rnd_120mm_Mo_AT_mine",
		"RC_26Rnd_120mm_Mo_AT_mine",
		"RC_27Rnd_120mm_Mo_AT_mine",
		"RC_28Rnd_120mm_Mo_AT_mine",
		"RC_29Rnd_120mm_Mo_AT_mine",
		"RC_30Rnd_120mm_Mo_AT_mine",
		"RC_31Rnd_120mm_Mo_AT_mine",
		"RC_32Rnd_120mm_Mo_AT_mine",
		"RC_33Rnd_120mm_Mo_AT_mine",
		"RC_34Rnd_120mm_Mo_AT_mine",
		"RC_35Rnd_120mm_Mo_AT_mine",
		"RC_36Rnd_120mm_Mo_AT_mine",
		"RC_37Rnd_120mm_Mo_AT_mine",
		"RC_38Rnd_120mm_Mo_AT_mine",
		"RC_39Rnd_120mm_Mo_AT_mine",
		"RC_40Rnd_120mm_Mo_AT_mine",

		"RC_1Rnd_120mm_Mo_Illum",
		"RC_2Rnd_120mm_Mo_Illum",
		"RC_3Rnd_120mm_Mo_Illum",
		"RC_4Rnd_120mm_Mo_Illum",
		"RC_5Rnd_120mm_Mo_Illum",
		"RC_6Rnd_120mm_Mo_Illum",
		"RC_7Rnd_120mm_Mo_Illum",
		"RC_8Rnd_120mm_Mo_Illum",
		"RC_9Rnd_120mm_Mo_Illum",
		"RC_10Rnd_120mm_Mo_Illum",
		"RC_11Rnd_120mm_Mo_Illum",
		"RC_12Rnd_120mm_Mo_Illum",
		"RC_13Rnd_120mm_Mo_Illum",
		"RC_14Rnd_120mm_Mo_Illum",
		"RC_15Rnd_120mm_Mo_Illum",
		"RC_16Rnd_120mm_Mo_Illum",
		"RC_17Rnd_120mm_Mo_Illum",
		"RC_18Rnd_120mm_Mo_Illum",
		"RC_19Rnd_120mm_Mo_Illum",
		"RC_20Rnd_120mm_Mo_Illum",
		"RC_21Rnd_120mm_Mo_Illum",
		"RC_22Rnd_120mm_Mo_Illum",
		"RC_23Rnd_120mm_Mo_Illum",
		"RC_24Rnd_120mm_Mo_Illum",
		"RC_25Rnd_120mm_Mo_Illum",
		"RC_26Rnd_120mm_Mo_Illum",
		"RC_27Rnd_120mm_Mo_Illum",
		"RC_28Rnd_120mm_Mo_Illum",
		"RC_29Rnd_120mm_Mo_Illum",
		"RC_30Rnd_120mm_Mo_Illum",
		"RC_31Rnd_120mm_Mo_Illum",
		"RC_32Rnd_120mm_Mo_Illum",
		"RC_33Rnd_120mm_Mo_Illum",
		"RC_34Rnd_120mm_Mo_Illum",
		"RC_35Rnd_120mm_Mo_Illum",
		"RC_36Rnd_120mm_Mo_Illum",
		"RC_37Rnd_120mm_Mo_Illum",
		"RC_38Rnd_120mm_Mo_Illum",
		"RC_39Rnd_120mm_Mo_Illum",
		"RC_40Rnd_120mm_Mo_Illum",

		"RC_1Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_2Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_3Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_4Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_5Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_6Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_7Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_8Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_9Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_10Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_11Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_12Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_13Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_14Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_15Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_16Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_17Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_18Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_19Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_20Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_21Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_22Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_23Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_24Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_25Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_26Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_27Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_28Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_29Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_30Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_31Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_32Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_33Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_34Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_35Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_36Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_37Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_38Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_39Rnd_120mm_Mo_LG_DelayedFuse",
		"RC_40Rnd_120mm_Mo_LG_DelayedFuse",

		"RC_1Rnd_120mm_Mo_backupHEAB",
		"RC_2Rnd_120mm_Mo_backupHEAB",
		"RC_3Rnd_120mm_Mo_backupHEAB",
		"RC_4Rnd_120mm_Mo_backupHEAB",
		"RC_5Rnd_120mm_Mo_backupHEAB",
		"RC_6Rnd_120mm_Mo_backupHEAB",
		"RC_7Rnd_120mm_Mo_backupHEAB",
		"RC_8Rnd_120mm_Mo_backupHEAB",
		"RC_9Rnd_120mm_Mo_backupHEAB",
		"RC_10Rnd_120mm_Mo_backupHEAB",
		"RC_11Rnd_120mm_Mo_backupHEAB",
		"RC_12Rnd_120mm_Mo_backupHEAB",
		"RC_13Rnd_120mm_Mo_backupHEAB",
		"RC_14Rnd_120mm_Mo_backupHEAB",
		"RC_15Rnd_120mm_Mo_backupHEAB",
		"RC_16Rnd_120mm_Mo_backupHEAB",
		"RC_17Rnd_120mm_Mo_backupHEAB",
		"RC_18Rnd_120mm_Mo_backupHEAB",
		"RC_19Rnd_120mm_Mo_backupHEAB",
		"RC_20Rnd_120mm_Mo_backupHEAB",
		"RC_21Rnd_120mm_Mo_backupHEAB",
		"RC_22Rnd_120mm_Mo_backupHEAB",
		"RC_23Rnd_120mm_Mo_backupHEAB",
		"RC_24Rnd_120mm_Mo_backupHEAB",
		"RC_25Rnd_120mm_Mo_backupHEAB",
		"RC_26Rnd_120mm_Mo_backupHEAB",
		"RC_27Rnd_120mm_Mo_backupHEAB",
		"RC_28Rnd_120mm_Mo_backupHEAB",
		"RC_29Rnd_120mm_Mo_backupHEAB",
		"RC_30Rnd_120mm_Mo_backupHEAB",
		"RC_31Rnd_120mm_Mo_backupHEAB",
		"RC_32Rnd_120mm_Mo_backupHEAB",
		"RC_33Rnd_120mm_Mo_backupHEAB",
		"RC_34Rnd_120mm_Mo_backupHEAB",
		"RC_35Rnd_120mm_Mo_backupHEAB",
		"RC_36Rnd_120mm_Mo_backupHEAB",
		"RC_37Rnd_120mm_Mo_backupHEAB",
		"RC_38Rnd_120mm_Mo_backupHEAB",
		"RC_39Rnd_120mm_Mo_backupHEAB",
		"RC_40Rnd_120mm_Mo_backupHEAB",

		"RC_1Rnd_120mm_Mo_backuplowHEAB",
		"RC_2Rnd_120mm_Mo_backuplowHEAB",
		"RC_3Rnd_120mm_Mo_backuplowHEAB",
		"RC_4Rnd_120mm_Mo_backuplowHEAB",
		"RC_5Rnd_120mm_Mo_backuplowHEAB",
		"RC_6Rnd_120mm_Mo_backuplowHEAB",
		"RC_7Rnd_120mm_Mo_backuplowHEAB",
		"RC_8Rnd_120mm_Mo_backuplowHEAB",
		"RC_9Rnd_120mm_Mo_backuplowHEAB",
		"RC_10Rnd_120mm_Mo_backuplowHEAB",
		"RC_11Rnd_120mm_Mo_backuplowHEAB",
		"RC_12Rnd_120mm_Mo_backuplowHEAB",
		"RC_13Rnd_120mm_Mo_backuplowHEAB",
		"RC_14Rnd_120mm_Mo_backuplowHEAB",
		"RC_15Rnd_120mm_Mo_backuplowHEAB",
		"RC_16Rnd_120mm_Mo_backuplowHEAB",
		"RC_17Rnd_120mm_Mo_backuplowHEAB",
		"RC_18Rnd_120mm_Mo_backuplowHEAB",
		"RC_19Rnd_120mm_Mo_backuplowHEAB",
		"RC_20Rnd_120mm_Mo_backuplowHEAB",
		"RC_21Rnd_120mm_Mo_backuplowHEAB",
		"RC_22Rnd_120mm_Mo_backuplowHEAB",
		"RC_23Rnd_120mm_Mo_backuplowHEAB",
		"RC_24Rnd_120mm_Mo_backuplowHEAB",
		"RC_25Rnd_120mm_Mo_backuplowHEAB",
		"RC_26Rnd_120mm_Mo_backuplowHEAB",
		"RC_27Rnd_120mm_Mo_backuplowHEAB",
		"RC_28Rnd_120mm_Mo_backuplowHEAB",
		"RC_29Rnd_120mm_Mo_backuplowHEAB",
		"RC_30Rnd_120mm_Mo_backuplowHEAB",
		"RC_31Rnd_120mm_Mo_backuplowHEAB",
		"RC_32Rnd_120mm_Mo_backuplowHEAB",
		"RC_33Rnd_120mm_Mo_backuplowHEAB",
		"RC_34Rnd_120mm_Mo_backuplowHEAB",
		"RC_35Rnd_120mm_Mo_backuplowHEAB",
		"RC_36Rnd_120mm_Mo_backuplowHEAB",
		"RC_37Rnd_120mm_Mo_backuplowHEAB",
		"RC_38Rnd_120mm_Mo_backuplowHEAB",
		"RC_39Rnd_120mm_Mo_backuplowHEAB",
		"RC_40Rnd_120mm_Mo_backuplowHEAB"
	};
};
class RC_ShipCannon_120mm_V2: RC_ShipCannon_120mm_V1
{
	reloadTime=6;
	magazineReloadTime=6;
	ballisticsComputer=8;	//direct fire reticle for highest charge
	canLock=2;
	weaponLockDelay=0;

	class Single1: Single1
	{
		/*
		//burst=1;
		//soundBurst=0;
		aiDispersionCoefX=1;
		aiDispersionCoefY=1;
		aiRateOfFireDispersion=1;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
		*/
		reloadTime=6;
	};
	class Single2: Single2
	{
		reloadTime=6;
	};
	class Single3: Single3
	{
		reloadTime=6;
	};
	class Single4: Single4
	{
		reloadTime=6;
	};
	class Single5: Single5
	{
		reloadTime=6;
	};
	//used by ai, rof decreased
	class Burst1: Burst1
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst2: Burst2
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst3: Burst3
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst4: Burst4
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst5: Burst5
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
};
class RC_ShipCannon_120mm_V3: RC_ShipCannon_120mm_V2
{
	/*
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7",
		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4",
		"Burst5"
	};
	*/
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7"
	};
	class Single1: Single1
	{
		displayName="CH0";
		artilleryCharge=0.265; //300m minrange
		minRange=293;
		midRange=1551;
		maxRange=2809;
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
		aiDispersionCoefX=1;
		aiDispersionCoefY=1;
		//aiRateOfFireDispersion=1;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
	};
	class Single2: Single1
	{
		displayName="CH1";
		artilleryCharge=0.331;
		minRange=458;
		midRange=2420;
		maxRange=4382;
	};
	class Single3: Single1
	{
		displayName="CH2";
		artilleryCharge=0.413;
		minRange=713;
		midRange=3767.5;
		maxRange=6822;
	};
	class Single4: Single1
	{
		displayName="CH3";
		artilleryCharge=0.515;
		minRange=1108;
		midRange=5858.5;
		maxRange=10609;
	};
	class Single5: Single1
	{
		displayName="CH4";
		artilleryCharge=0.642;
		minRange=1723;
		midRange=9104.5;
		maxRange=16486;
	};
	class Single6: Single1
	{
		displayName="CH5";
		artilleryCharge=0.801;
		minRange=2682;
		midRange=14173;
		maxRange=25664;
	};
	class Single7: Single1
	{
		displayName="CH6 reticle";
		artilleryCharge=1;
		minRange=4180;
		midRange=22090;
		maxRange=40000;
	};
};
class RC_ShipCannon_120mm_V4: RC_ShipCannon_120mm_V3
{
	class Single1: Single1
	{
		artilleryDispersion=2;
	};
	class Single2: Single2
	{
		artilleryDispersion=2;
	};
	class Single3: Single3
	{
		artilleryDispersion=2;
	};
	class Single4: Single4
	{
		artilleryDispersion=2;
	};
	class Single5: Single5
	{
		artilleryDispersion=2;
	};
	class Single6: Single6
	{
		artilleryDispersion=2;
	};
	class Single7: Single7
	{
		artilleryDispersion=2;
	};
};


// 122m Howitzer
class RC_122mm_AMOS_V4: RC_ShipCannon_120mm_V4
{
	displayName="122mm";
	displayNameShort="122mm";

	magazines[]=
	{
		"RC_1Rnd_122mm_Mo_shells",
		"RC_2Rnd_122mm_Mo_shells",
		"RC_3Rnd_122mm_Mo_shells",
		"RC_4Rnd_122mm_Mo_shells",
		"RC_5Rnd_122mm_Mo_shells",
		"RC_6Rnd_122mm_Mo_shells",
		"RC_7Rnd_122mm_Mo_shells",
		"RC_8Rnd_122mm_Mo_shells",
		"RC_9Rnd_122mm_Mo_shells",
		"RC_10Rnd_122mm_Mo_shells",
		"RC_11Rnd_122mm_Mo_shells",
		"RC_12Rnd_122mm_Mo_shells",
		"RC_13Rnd_122mm_Mo_shells",
		"RC_14Rnd_122mm_Mo_shells",
		"RC_15Rnd_122mm_Mo_shells",
		"RC_16Rnd_122mm_Mo_shells",
		"RC_17Rnd_122mm_Mo_shells",
		"RC_18Rnd_122mm_Mo_shells",
		"RC_19Rnd_122mm_Mo_shells",
		"RC_20Rnd_122mm_Mo_shells",
		"RC_21Rnd_122mm_Mo_shells",
		"RC_22Rnd_122mm_Mo_shells",
		"RC_23Rnd_122mm_Mo_shells",
		"RC_24Rnd_122mm_Mo_shells",
		"RC_25Rnd_122mm_Mo_shells",
		"RC_26Rnd_122mm_Mo_shells",
		"RC_27Rnd_122mm_Mo_shells",
		"RC_28Rnd_122mm_Mo_shells",
		"RC_29Rnd_122mm_Mo_shells",
		"RC_30Rnd_122mm_Mo_shells",
		"RC_31Rnd_122mm_Mo_shells",
		"RC_32Rnd_122mm_Mo_shells",
		"RC_33Rnd_122mm_Mo_shells",
		"RC_34Rnd_122mm_Mo_shells",
		"RC_35Rnd_122mm_Mo_shells",
		"RC_36Rnd_122mm_Mo_shells",
		"RC_37Rnd_122mm_Mo_shells",
		"RC_38Rnd_122mm_Mo_shells",
		"RC_39Rnd_122mm_Mo_shells",
		"RC_40Rnd_122mm_Mo_shells",

		"RC_1Rnd_122mm_Mo_HEAB",
		"RC_2Rnd_122mm_Mo_HEAB",
		"RC_3Rnd_122mm_Mo_HEAB",
		"RC_4Rnd_122mm_Mo_HEAB",
		"RC_5Rnd_122mm_Mo_HEAB",
		"RC_6Rnd_122mm_Mo_HEAB",
		"RC_7Rnd_122mm_Mo_HEAB",
		"RC_8Rnd_122mm_Mo_HEAB",
		"RC_9Rnd_122mm_Mo_HEAB",
		"RC_10Rnd_122mm_Mo_HEAB",
		"RC_11Rnd_122mm_Mo_HEAB",
		"RC_12Rnd_122mm_Mo_HEAB",
		"RC_13Rnd_122mm_Mo_HEAB",
		"RC_14Rnd_122mm_Mo_HEAB",
		"RC_15Rnd_122mm_Mo_HEAB",
		"RC_16Rnd_122mm_Mo_HEAB",
		"RC_17Rnd_122mm_Mo_HEAB",
		"RC_18Rnd_122mm_Mo_HEAB",
		"RC_19Rnd_122mm_Mo_HEAB",
		"RC_20Rnd_122mm_Mo_HEAB",
		"RC_21Rnd_122mm_Mo_HEAB",
		"RC_22Rnd_122mm_Mo_HEAB",
		"RC_23Rnd_122mm_Mo_HEAB",
		"RC_24Rnd_122mm_Mo_HEAB",
		"RC_25Rnd_122mm_Mo_HEAB",
		"RC_26Rnd_122mm_Mo_HEAB",
		"RC_27Rnd_122mm_Mo_HEAB",
		"RC_28Rnd_122mm_Mo_HEAB",
		"RC_29Rnd_122mm_Mo_HEAB",
		"RC_30Rnd_122mm_Mo_HEAB",
		"RC_31Rnd_122mm_Mo_HEAB",
		"RC_32Rnd_122mm_Mo_HEAB",
		"RC_33Rnd_122mm_Mo_HEAB",
		"RC_34Rnd_122mm_Mo_HEAB",
		"RC_35Rnd_122mm_Mo_HEAB",
		"RC_36Rnd_122mm_Mo_HEAB",
		"RC_37Rnd_122mm_Mo_HEAB",
		"RC_38Rnd_122mm_Mo_HEAB",
		"RC_39Rnd_122mm_Mo_HEAB",
		"RC_40Rnd_122mm_Mo_HEAB",

		"RC_1Rnd_122mm_Mo_lowHEAB",
		"RC_2Rnd_122mm_Mo_lowHEAB",
		"RC_3Rnd_122mm_Mo_lowHEAB",
		"RC_4Rnd_122mm_Mo_lowHEAB",
		"RC_5Rnd_122mm_Mo_lowHEAB",
		"RC_6Rnd_122mm_Mo_lowHEAB",
		"RC_7Rnd_122mm_Mo_lowHEAB",
		"RC_8Rnd_122mm_Mo_lowHEAB",
		"RC_9Rnd_122mm_Mo_lowHEAB",
		"RC_10Rnd_122mm_Mo_lowHEAB",
		"RC_11Rnd_122mm_Mo_lowHEAB",
		"RC_12Rnd_122mm_Mo_lowHEAB",
		"RC_13Rnd_122mm_Mo_lowHEAB",
		"RC_14Rnd_122mm_Mo_lowHEAB",
		"RC_15Rnd_122mm_Mo_lowHEAB",
		"RC_16Rnd_122mm_Mo_lowHEAB",
		"RC_17Rnd_122mm_Mo_lowHEAB",
		"RC_18Rnd_122mm_Mo_lowHEAB",
		"RC_19Rnd_122mm_Mo_lowHEAB",
		"RC_20Rnd_122mm_Mo_lowHEAB",
		"RC_21Rnd_122mm_Mo_lowHEAB",
		"RC_22Rnd_122mm_Mo_lowHEAB",
		"RC_23Rnd_122mm_Mo_lowHEAB",
		"RC_24Rnd_122mm_Mo_lowHEAB",
		"RC_25Rnd_122mm_Mo_lowHEAB",
		"RC_26Rnd_122mm_Mo_lowHEAB",
		"RC_27Rnd_122mm_Mo_lowHEAB",
		"RC_28Rnd_122mm_Mo_lowHEAB",
		"RC_29Rnd_122mm_Mo_lowHEAB",
		"RC_30Rnd_122mm_Mo_lowHEAB",
		"RC_31Rnd_122mm_Mo_lowHEAB",
		"RC_32Rnd_122mm_Mo_lowHEAB",
		"RC_33Rnd_122mm_Mo_lowHEAB",
		"RC_34Rnd_122mm_Mo_lowHEAB",
		"RC_35Rnd_122mm_Mo_lowHEAB",
		"RC_36Rnd_122mm_Mo_lowHEAB",
		"RC_37Rnd_122mm_Mo_lowHEAB",
		"RC_38Rnd_122mm_Mo_lowHEAB",
		"RC_39Rnd_122mm_Mo_lowHEAB",
		"RC_40Rnd_122mm_Mo_lowHEAB",

		"RC_1Rnd_122mm_Mo_smoke",
		"RC_2Rnd_122mm_Mo_smoke",
		"RC_3Rnd_122mm_Mo_smoke",
		"RC_4Rnd_122mm_Mo_smoke",
		"RC_5Rnd_122mm_Mo_smoke",
		"RC_6Rnd_122mm_Mo_smoke",
		"RC_7Rnd_122mm_Mo_smoke",
		"RC_8Rnd_122mm_Mo_smoke",
		"RC_9Rnd_122mm_Mo_smoke",
		"RC_10Rnd_122mm_Mo_smoke",
		"RC_11Rnd_122mm_Mo_smoke",
		"RC_12Rnd_122mm_Mo_smoke",
		"RC_13Rnd_122mm_Mo_smoke",
		"RC_14Rnd_122mm_Mo_smoke",
		"RC_15Rnd_122mm_Mo_smoke",
		"RC_16Rnd_122mm_Mo_smoke",
		"RC_17Rnd_122mm_Mo_smoke",
		"RC_18Rnd_122mm_Mo_smoke",
		"RC_19Rnd_122mm_Mo_smoke",
		"RC_20Rnd_122mm_Mo_smoke",
		"RC_21Rnd_122mm_Mo_smoke",
		"RC_22Rnd_122mm_Mo_smoke",
		"RC_23Rnd_122mm_Mo_smoke",
		"RC_24Rnd_122mm_Mo_smoke",
		"RC_25Rnd_122mm_Mo_smoke",
		"RC_26Rnd_122mm_Mo_smoke",
		"RC_27Rnd_122mm_Mo_smoke",
		"RC_28Rnd_122mm_Mo_smoke",
		"RC_29Rnd_122mm_Mo_smoke",
		"RC_30Rnd_122mm_Mo_smoke",
		"RC_31Rnd_122mm_Mo_smoke",
		"RC_32Rnd_122mm_Mo_smoke",
		"RC_33Rnd_122mm_Mo_smoke",
		"RC_34Rnd_122mm_Mo_smoke",
		"RC_35Rnd_122mm_Mo_smoke",
		"RC_36Rnd_122mm_Mo_smoke",
		"RC_37Rnd_122mm_Mo_smoke",
		"RC_38Rnd_122mm_Mo_smoke",
		"RC_39Rnd_122mm_Mo_smoke",
		"RC_40Rnd_122mm_Mo_smoke",

		"RC_1Rnd_122mm_Mo_Cluster",
		"RC_2Rnd_122mm_Mo_Cluster",
		"RC_3Rnd_122mm_Mo_Cluster",
		"RC_4Rnd_122mm_Mo_Cluster",
		"RC_5Rnd_122mm_Mo_Cluster",
		"RC_6Rnd_122mm_Mo_Cluster",
		"RC_7Rnd_122mm_Mo_Cluster",
		"RC_8Rnd_122mm_Mo_Cluster",
		"RC_9Rnd_122mm_Mo_Cluster",
		"RC_10Rnd_122mm_Mo_Cluster",
		"RC_11Rnd_122mm_Mo_Cluster",
		"RC_12Rnd_122mm_Mo_Cluster",
		"RC_13Rnd_122mm_Mo_Cluster",
		"RC_14Rnd_122mm_Mo_Cluster",
		"RC_15Rnd_122mm_Mo_Cluster",
		"RC_16Rnd_122mm_Mo_Cluster",
		"RC_17Rnd_122mm_Mo_Cluster",
		"RC_18Rnd_122mm_Mo_Cluster",
		"RC_19Rnd_122mm_Mo_Cluster",
		"RC_20Rnd_122mm_Mo_Cluster",
		"RC_21Rnd_122mm_Mo_Cluster",
		"RC_22Rnd_122mm_Mo_Cluster",
		"RC_23Rnd_122mm_Mo_Cluster",
		"RC_24Rnd_122mm_Mo_Cluster",
		"RC_25Rnd_122mm_Mo_Cluster",
		"RC_26Rnd_122mm_Mo_Cluster",
		"RC_27Rnd_122mm_Mo_Cluster",
		"RC_28Rnd_122mm_Mo_Cluster",
		"RC_29Rnd_122mm_Mo_Cluster",
		"RC_30Rnd_122mm_Mo_Cluster",
		"RC_31Rnd_122mm_Mo_Cluster",
		"RC_32Rnd_122mm_Mo_Cluster",
		"RC_33Rnd_122mm_Mo_Cluster",
		"RC_34Rnd_122mm_Mo_Cluster",
		"RC_35Rnd_122mm_Mo_Cluster",
		"RC_36Rnd_122mm_Mo_Cluster",
		"RC_37Rnd_122mm_Mo_Cluster",
		"RC_38Rnd_122mm_Mo_Cluster",
		"RC_39Rnd_122mm_Mo_Cluster",
		"RC_40Rnd_122mm_Mo_Cluster",

		"RC_1Rnd_122mm_Mo_LaserGuided",
		"RC_2Rnd_122mm_Mo_LaserGuided",
		"RC_3Rnd_122mm_Mo_LaserGuided",
		"RC_4Rnd_122mm_Mo_LaserGuided",
		"RC_5Rnd_122mm_Mo_LaserGuided",
		"RC_6Rnd_122mm_Mo_LaserGuided",
		"RC_7Rnd_122mm_Mo_LaserGuided",
		"RC_8Rnd_122mm_Mo_LaserGuided",
		"RC_9Rnd_122mm_Mo_LaserGuided",
		"RC_10Rnd_122mm_Mo_LaserGuided",
		"RC_11Rnd_122mm_Mo_LaserGuided",
		"RC_12Rnd_122mm_Mo_LaserGuided",
		"RC_13Rnd_122mm_Mo_LaserGuided",
		"RC_14Rnd_122mm_Mo_LaserGuided",
		"RC_15Rnd_122mm_Mo_LaserGuided",
		"RC_16Rnd_122mm_Mo_LaserGuided",
		"RC_17Rnd_122mm_Mo_LaserGuided",
		"RC_18Rnd_122mm_Mo_LaserGuided",
		"RC_19Rnd_122mm_Mo_LaserGuided",
		"RC_20Rnd_122mm_Mo_LaserGuided",
		"RC_21Rnd_122mm_Mo_LaserGuided",
		"RC_22Rnd_122mm_Mo_LaserGuided",
		"RC_23Rnd_122mm_Mo_LaserGuided",
		"RC_24Rnd_122mm_Mo_LaserGuided",
		"RC_25Rnd_122mm_Mo_LaserGuided",
		"RC_26Rnd_122mm_Mo_LaserGuided",
		"RC_27Rnd_122mm_Mo_LaserGuided",
		"RC_28Rnd_122mm_Mo_LaserGuided",
		"RC_29Rnd_122mm_Mo_LaserGuided",
		"RC_30Rnd_122mm_Mo_LaserGuided",
		"RC_31Rnd_122mm_Mo_LaserGuided",
		"RC_32Rnd_122mm_Mo_LaserGuided",
		"RC_33Rnd_122mm_Mo_LaserGuided",
		"RC_34Rnd_122mm_Mo_LaserGuided",
		"RC_35Rnd_122mm_Mo_LaserGuided",
		"RC_36Rnd_122mm_Mo_LaserGuided",
		"RC_37Rnd_122mm_Mo_LaserGuided",
		"RC_38Rnd_122mm_Mo_LaserGuided",
		"RC_39Rnd_122mm_Mo_LaserGuided",
		"RC_40Rnd_122mm_Mo_LaserGuided",

		"RC_1Rnd_122mm_Mo_MultiGuided",
		"RC_2Rnd_122mm_Mo_MultiGuided",
		"RC_3Rnd_122mm_Mo_MultiGuided",
		"RC_4Rnd_122mm_Mo_MultiGuided",
		"RC_5Rnd_122mm_Mo_MultiGuided",
		"RC_6Rnd_122mm_Mo_MultiGuided",
		"RC_7Rnd_122mm_Mo_MultiGuided",
		"RC_8Rnd_122mm_Mo_MultiGuided",
		"RC_9Rnd_122mm_Mo_MultiGuided",
		"RC_10Rnd_122mm_Mo_MultiGuided",
		"RC_11Rnd_122mm_Mo_MultiGuided",
		"RC_12Rnd_122mm_Mo_MultiGuided",
		"RC_13Rnd_122mm_Mo_MultiGuided",
		"RC_14Rnd_122mm_Mo_MultiGuided",
		"RC_15Rnd_122mm_Mo_MultiGuided",
		"RC_16Rnd_122mm_Mo_MultiGuided",
		"RC_17Rnd_122mm_Mo_MultiGuided",
		"RC_18Rnd_122mm_Mo_MultiGuided",
		"RC_19Rnd_122mm_Mo_MultiGuided",
		"RC_20Rnd_122mm_Mo_MultiGuided",
		"RC_21Rnd_122mm_Mo_MultiGuided",
		"RC_22Rnd_122mm_Mo_MultiGuided",
		"RC_23Rnd_122mm_Mo_MultiGuided",
		"RC_24Rnd_122mm_Mo_MultiGuided",
		"RC_25Rnd_122mm_Mo_MultiGuided",
		"RC_26Rnd_122mm_Mo_MultiGuided",
		"RC_27Rnd_122mm_Mo_MultiGuided",
		"RC_28Rnd_122mm_Mo_MultiGuided",
		"RC_29Rnd_122mm_Mo_MultiGuided",
		"RC_30Rnd_122mm_Mo_MultiGuided",
		"RC_31Rnd_122mm_Mo_MultiGuided",
		"RC_32Rnd_122mm_Mo_MultiGuided",
		"RC_33Rnd_122mm_Mo_MultiGuided",
		"RC_34Rnd_122mm_Mo_MultiGuided",
		"RC_35Rnd_122mm_Mo_MultiGuided",
		"RC_36Rnd_122mm_Mo_MultiGuided",
		"RC_37Rnd_122mm_Mo_MultiGuided",
		"RC_38Rnd_122mm_Mo_MultiGuided",
		"RC_39Rnd_122mm_Mo_MultiGuided",
		"RC_40Rnd_122mm_Mo_MultiGuided",

		"RC_1Rnd_122mm_Mo_mine",
		"RC_2Rnd_122mm_Mo_mine",
		"RC_3Rnd_122mm_Mo_mine",
		"RC_4Rnd_122mm_Mo_mine",
		"RC_5Rnd_122mm_Mo_mine",
		"RC_6Rnd_122mm_Mo_mine",
		"RC_7Rnd_122mm_Mo_mine",
		"RC_8Rnd_122mm_Mo_mine",
		"RC_9Rnd_122mm_Mo_mine",
		"RC_10Rnd_122mm_Mo_mine",
		"RC_11Rnd_122mm_Mo_mine",
		"RC_12Rnd_122mm_Mo_mine",
		"RC_13Rnd_122mm_Mo_mine",
		"RC_14Rnd_122mm_Mo_mine",
		"RC_15Rnd_122mm_Mo_mine",
		"RC_16Rnd_122mm_Mo_mine",
		"RC_17Rnd_122mm_Mo_mine",
		"RC_18Rnd_122mm_Mo_mine",
		"RC_19Rnd_122mm_Mo_mine",
		"RC_20Rnd_122mm_Mo_mine",
		"RC_21Rnd_122mm_Mo_mine",
		"RC_22Rnd_122mm_Mo_mine",
		"RC_23Rnd_122mm_Mo_mine",
		"RC_24Rnd_122mm_Mo_mine",
		"RC_25Rnd_122mm_Mo_mine",
		"RC_26Rnd_122mm_Mo_mine",
		"RC_27Rnd_122mm_Mo_mine",
		"RC_28Rnd_122mm_Mo_mine",
		"RC_29Rnd_122mm_Mo_mine",
		"RC_30Rnd_122mm_Mo_mine",
		"RC_31Rnd_122mm_Mo_mine",
		"RC_32Rnd_122mm_Mo_mine",
		"RC_33Rnd_122mm_Mo_mine",
		"RC_34Rnd_122mm_Mo_mine",
		"RC_35Rnd_122mm_Mo_mine",
		"RC_36Rnd_122mm_Mo_mine",
		"RC_37Rnd_122mm_Mo_mine",
		"RC_38Rnd_122mm_Mo_mine",
		"RC_39Rnd_122mm_Mo_mine",
		"RC_40Rnd_122mm_Mo_mine",

		"RC_1Rnd_122mm_Mo_AT_mine",
		"RC_2Rnd_122mm_Mo_AT_mine",
		"RC_3Rnd_122mm_Mo_AT_mine",
		"RC_4Rnd_122mm_Mo_AT_mine",
		"RC_5Rnd_122mm_Mo_AT_mine",
		"RC_6Rnd_122mm_Mo_AT_mine",
		"RC_7Rnd_122mm_Mo_AT_mine",
		"RC_8Rnd_122mm_Mo_AT_mine",
		"RC_9Rnd_122mm_Mo_AT_mine",
		"RC_10Rnd_122mm_Mo_AT_mine",
		"RC_11Rnd_122mm_Mo_AT_mine",
		"RC_12Rnd_122mm_Mo_AT_mine",
		"RC_13Rnd_122mm_Mo_AT_mine",
		"RC_14Rnd_122mm_Mo_AT_mine",
		"RC_15Rnd_122mm_Mo_AT_mine",
		"RC_16Rnd_122mm_Mo_AT_mine",
		"RC_17Rnd_122mm_Mo_AT_mine",
		"RC_18Rnd_122mm_Mo_AT_mine",
		"RC_19Rnd_122mm_Mo_AT_mine",
		"RC_20Rnd_122mm_Mo_AT_mine",
		"RC_21Rnd_122mm_Mo_AT_mine",
		"RC_22Rnd_122mm_Mo_AT_mine",
		"RC_23Rnd_122mm_Mo_AT_mine",
		"RC_24Rnd_122mm_Mo_AT_mine",
		"RC_25Rnd_122mm_Mo_AT_mine",
		"RC_26Rnd_122mm_Mo_AT_mine",
		"RC_27Rnd_122mm_Mo_AT_mine",
		"RC_28Rnd_122mm_Mo_AT_mine",
		"RC_29Rnd_122mm_Mo_AT_mine",
		"RC_30Rnd_122mm_Mo_AT_mine",
		"RC_31Rnd_122mm_Mo_AT_mine",
		"RC_32Rnd_122mm_Mo_AT_mine",
		"RC_33Rnd_122mm_Mo_AT_mine",
		"RC_34Rnd_122mm_Mo_AT_mine",
		"RC_35Rnd_122mm_Mo_AT_mine",
		"RC_36Rnd_122mm_Mo_AT_mine",
		"RC_37Rnd_122mm_Mo_AT_mine",
		"RC_38Rnd_122mm_Mo_AT_mine",
		"RC_39Rnd_122mm_Mo_AT_mine",
		"RC_40Rnd_122mm_Mo_AT_mine",

		"RC_1Rnd_122mm_Mo_Illum",
		"RC_2Rnd_122mm_Mo_Illum",
		"RC_3Rnd_122mm_Mo_Illum",
		"RC_4Rnd_122mm_Mo_Illum",
		"RC_5Rnd_122mm_Mo_Illum",
		"RC_6Rnd_122mm_Mo_Illum",
		"RC_7Rnd_122mm_Mo_Illum",
		"RC_8Rnd_122mm_Mo_Illum",
		"RC_9Rnd_122mm_Mo_Illum",
		"RC_10Rnd_122mm_Mo_Illum",
		"RC_11Rnd_122mm_Mo_Illum",
		"RC_12Rnd_122mm_Mo_Illum",
		"RC_13Rnd_122mm_Mo_Illum",
		"RC_14Rnd_122mm_Mo_Illum",
		"RC_15Rnd_122mm_Mo_Illum",
		"RC_16Rnd_122mm_Mo_Illum",
		"RC_17Rnd_122mm_Mo_Illum",
		"RC_18Rnd_122mm_Mo_Illum",
		"RC_19Rnd_122mm_Mo_Illum",
		"RC_20Rnd_122mm_Mo_Illum",
		"RC_21Rnd_122mm_Mo_Illum",
		"RC_22Rnd_122mm_Mo_Illum",
		"RC_23Rnd_122mm_Mo_Illum",
		"RC_24Rnd_122mm_Mo_Illum",
		"RC_25Rnd_122mm_Mo_Illum",
		"RC_26Rnd_122mm_Mo_Illum",
		"RC_27Rnd_122mm_Mo_Illum",
		"RC_28Rnd_122mm_Mo_Illum",
		"RC_29Rnd_122mm_Mo_Illum",
		"RC_30Rnd_122mm_Mo_Illum",
		"RC_31Rnd_122mm_Mo_Illum",
		"RC_32Rnd_122mm_Mo_Illum",
		"RC_33Rnd_122mm_Mo_Illum",
		"RC_34Rnd_122mm_Mo_Illum",
		"RC_35Rnd_122mm_Mo_Illum",
		"RC_36Rnd_122mm_Mo_Illum",
		"RC_37Rnd_122mm_Mo_Illum",
		"RC_38Rnd_122mm_Mo_Illum",
		"RC_39Rnd_122mm_Mo_Illum",
		"RC_40Rnd_122mm_Mo_Illum",

		"RC_1Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_2Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_3Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_4Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_5Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_6Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_7Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_8Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_9Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_10Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_11Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_12Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_13Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_14Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_15Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_16Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_17Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_18Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_19Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_20Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_21Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_22Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_23Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_24Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_25Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_26Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_27Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_28Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_29Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_30Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_31Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_32Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_33Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_34Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_35Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_36Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_37Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_38Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_39Rnd_122mm_Mo_LG_DelayedFuse",
		"RC_40Rnd_122mm_Mo_LG_DelayedFuse",

		"RC_1Rnd_122mm_Mo_backupHEAB",
		"RC_2Rnd_122mm_Mo_backupHEAB",
		"RC_3Rnd_122mm_Mo_backupHEAB",
		"RC_4Rnd_122mm_Mo_backupHEAB",
		"RC_5Rnd_122mm_Mo_backupHEAB",
		"RC_6Rnd_122mm_Mo_backupHEAB",
		"RC_7Rnd_122mm_Mo_backupHEAB",
		"RC_8Rnd_122mm_Mo_backupHEAB",
		"RC_9Rnd_122mm_Mo_backupHEAB",
		"RC_10Rnd_122mm_Mo_backupHEAB",
		"RC_11Rnd_122mm_Mo_backupHEAB",
		"RC_12Rnd_122mm_Mo_backupHEAB",
		"RC_13Rnd_122mm_Mo_backupHEAB",
		"RC_14Rnd_122mm_Mo_backupHEAB",
		"RC_15Rnd_122mm_Mo_backupHEAB",
		"RC_16Rnd_122mm_Mo_backupHEAB",
		"RC_17Rnd_122mm_Mo_backupHEAB",
		"RC_18Rnd_122mm_Mo_backupHEAB",
		"RC_19Rnd_122mm_Mo_backupHEAB",
		"RC_20Rnd_122mm_Mo_backupHEAB",
		"RC_21Rnd_122mm_Mo_backupHEAB",
		"RC_22Rnd_122mm_Mo_backupHEAB",
		"RC_23Rnd_122mm_Mo_backupHEAB",
		"RC_24Rnd_122mm_Mo_backupHEAB",
		"RC_25Rnd_122mm_Mo_backupHEAB",
		"RC_26Rnd_122mm_Mo_backupHEAB",
		"RC_27Rnd_122mm_Mo_backupHEAB",
		"RC_28Rnd_122mm_Mo_backupHEAB",
		"RC_29Rnd_122mm_Mo_backupHEAB",
		"RC_30Rnd_122mm_Mo_backupHEAB",
		"RC_31Rnd_122mm_Mo_backupHEAB",
		"RC_32Rnd_122mm_Mo_backupHEAB",
		"RC_33Rnd_122mm_Mo_backupHEAB",
		"RC_34Rnd_122mm_Mo_backupHEAB",
		"RC_35Rnd_122mm_Mo_backupHEAB",
		"RC_36Rnd_122mm_Mo_backupHEAB",
		"RC_37Rnd_122mm_Mo_backupHEAB",
		"RC_38Rnd_122mm_Mo_backupHEAB",
		"RC_39Rnd_122mm_Mo_backupHEAB",
		"RC_40Rnd_122mm_Mo_backupHEAB",

		"RC_1Rnd_122mm_Mo_backuplowHEAB",
		"RC_2Rnd_122mm_Mo_backuplowHEAB",
		"RC_3Rnd_122mm_Mo_backuplowHEAB",
		"RC_4Rnd_122mm_Mo_backuplowHEAB",
		"RC_5Rnd_122mm_Mo_backuplowHEAB",
		"RC_6Rnd_122mm_Mo_backuplowHEAB",
		"RC_7Rnd_122mm_Mo_backuplowHEAB",
		"RC_8Rnd_122mm_Mo_backuplowHEAB",
		"RC_9Rnd_122mm_Mo_backuplowHEAB",
		"RC_10Rnd_122mm_Mo_backuplowHEAB",
		"RC_11Rnd_122mm_Mo_backuplowHEAB",
		"RC_12Rnd_122mm_Mo_backuplowHEAB",
		"RC_13Rnd_122mm_Mo_backuplowHEAB",
		"RC_14Rnd_122mm_Mo_backuplowHEAB",
		"RC_15Rnd_122mm_Mo_backuplowHEAB",
		"RC_16Rnd_122mm_Mo_backuplowHEAB",
		"RC_17Rnd_122mm_Mo_backuplowHEAB",
		"RC_18Rnd_122mm_Mo_backuplowHEAB",
		"RC_19Rnd_122mm_Mo_backuplowHEAB",
		"RC_20Rnd_122mm_Mo_backuplowHEAB",
		"RC_21Rnd_122mm_Mo_backuplowHEAB",
		"RC_22Rnd_122mm_Mo_backuplowHEAB",
		"RC_23Rnd_122mm_Mo_backuplowHEAB",
		"RC_24Rnd_122mm_Mo_backuplowHEAB",
		"RC_25Rnd_122mm_Mo_backuplowHEAB",
		"RC_26Rnd_122mm_Mo_backuplowHEAB",
		"RC_27Rnd_122mm_Mo_backuplowHEAB",
		"RC_28Rnd_122mm_Mo_backuplowHEAB",
		"RC_29Rnd_122mm_Mo_backuplowHEAB",
		"RC_30Rnd_122mm_Mo_backuplowHEAB",
		"RC_31Rnd_122mm_Mo_backuplowHEAB",
		"RC_32Rnd_122mm_Mo_backuplowHEAB",
		"RC_33Rnd_122mm_Mo_backuplowHEAB",
		"RC_34Rnd_122mm_Mo_backuplowHEAB",
		"RC_35Rnd_122mm_Mo_backuplowHEAB",
		"RC_36Rnd_122mm_Mo_backuplowHEAB",
		"RC_37Rnd_122mm_Mo_backuplowHEAB",
		"RC_38Rnd_122mm_Mo_backuplowHEAB",
		"RC_39Rnd_122mm_Mo_backuplowHEAB",
		"RC_40Rnd_122mm_Mo_backuplowHEAB"
	};
};


// 155m Howitzer
class mortar_155mm_AMOS;
class RC_155mm_AMOS_base: mortar_155mm_AMOS
{
	class Single1;
	class Single2;
	class Single3;
	class Single4;
	class Single5;
	class Burst1;
	class Burst2;
	class Burst3;
	class Burst4;
	class Burst5;
};
class RC_155mm_AMOS_V1: RC_155mm_AMOS_base
{
	magazines[]=
	{
		"RC_1Rnd_155mm_Mo_shells",
		"RC_2Rnd_155mm_Mo_shells",
		"RC_3Rnd_155mm_Mo_shells",
		"RC_4Rnd_155mm_Mo_shells",
		"RC_5Rnd_155mm_Mo_shells",
		"RC_6Rnd_155mm_Mo_shells",
		"RC_7Rnd_155mm_Mo_shells",
		"RC_8Rnd_155mm_Mo_shells",
		"RC_9Rnd_155mm_Mo_shells",
		"RC_10Rnd_155mm_Mo_shells",
		"RC_11Rnd_155mm_Mo_shells",
		"RC_12Rnd_155mm_Mo_shells",
		"RC_13Rnd_155mm_Mo_shells",
		"RC_14Rnd_155mm_Mo_shells",
		"RC_15Rnd_155mm_Mo_shells",
		"RC_16Rnd_155mm_Mo_shells",
		"RC_17Rnd_155mm_Mo_shells",
		"RC_18Rnd_155mm_Mo_shells",
		"RC_19Rnd_155mm_Mo_shells",
		"RC_20Rnd_155mm_Mo_shells",
		"RC_21Rnd_155mm_Mo_shells",
		"RC_22Rnd_155mm_Mo_shells",
		"RC_23Rnd_155mm_Mo_shells",
		"RC_24Rnd_155mm_Mo_shells",
		"RC_25Rnd_155mm_Mo_shells",
		"RC_26Rnd_155mm_Mo_shells",
		"RC_27Rnd_155mm_Mo_shells",
		"RC_28Rnd_155mm_Mo_shells",
		"RC_29Rnd_155mm_Mo_shells",
		"RC_30Rnd_155mm_Mo_shells",
		"RC_31Rnd_155mm_Mo_shells",
		"RC_32Rnd_155mm_Mo_shells",
		"RC_33Rnd_155mm_Mo_shells",
		"RC_34Rnd_155mm_Mo_shells",
		"RC_35Rnd_155mm_Mo_shells",
		"RC_36Rnd_155mm_Mo_shells",
		"RC_37Rnd_155mm_Mo_shells",
		"RC_38Rnd_155mm_Mo_shells",
		"RC_39Rnd_155mm_Mo_shells",
		"RC_40Rnd_155mm_Mo_shells",

		"RC_1Rnd_155mm_Mo_HEAB",
		"RC_2Rnd_155mm_Mo_HEAB",
		"RC_3Rnd_155mm_Mo_HEAB",
		"RC_4Rnd_155mm_Mo_HEAB",
		"RC_5Rnd_155mm_Mo_HEAB",
		"RC_6Rnd_155mm_Mo_HEAB",
		"RC_7Rnd_155mm_Mo_HEAB",
		"RC_8Rnd_155mm_Mo_HEAB",
		"RC_9Rnd_155mm_Mo_HEAB",
		"RC_10Rnd_155mm_Mo_HEAB",
		"RC_11Rnd_155mm_Mo_HEAB",
		"RC_12Rnd_155mm_Mo_HEAB",
		"RC_13Rnd_155mm_Mo_HEAB",
		"RC_14Rnd_155mm_Mo_HEAB",
		"RC_15Rnd_155mm_Mo_HEAB",
		"RC_16Rnd_155mm_Mo_HEAB",
		"RC_17Rnd_155mm_Mo_HEAB",
		"RC_18Rnd_155mm_Mo_HEAB",
		"RC_19Rnd_155mm_Mo_HEAB",
		"RC_20Rnd_155mm_Mo_HEAB",
		"RC_21Rnd_155mm_Mo_HEAB",
		"RC_22Rnd_155mm_Mo_HEAB",
		"RC_23Rnd_155mm_Mo_HEAB",
		"RC_24Rnd_155mm_Mo_HEAB",
		"RC_25Rnd_155mm_Mo_HEAB",
		"RC_26Rnd_155mm_Mo_HEAB",
		"RC_27Rnd_155mm_Mo_HEAB",
		"RC_28Rnd_155mm_Mo_HEAB",
		"RC_29Rnd_155mm_Mo_HEAB",
		"RC_30Rnd_155mm_Mo_HEAB",
		"RC_31Rnd_155mm_Mo_HEAB",
		"RC_32Rnd_155mm_Mo_HEAB",
		"RC_33Rnd_155mm_Mo_HEAB",
		"RC_34Rnd_155mm_Mo_HEAB",
		"RC_35Rnd_155mm_Mo_HEAB",
		"RC_36Rnd_155mm_Mo_HEAB",
		"RC_37Rnd_155mm_Mo_HEAB",
		"RC_38Rnd_155mm_Mo_HEAB",
		"RC_39Rnd_155mm_Mo_HEAB",
		"RC_40Rnd_155mm_Mo_HEAB",

		"RC_1Rnd_155mm_Mo_lowHEAB",
		"RC_2Rnd_155mm_Mo_lowHEAB",
		"RC_3Rnd_155mm_Mo_lowHEAB",
		"RC_4Rnd_155mm_Mo_lowHEAB",
		"RC_5Rnd_155mm_Mo_lowHEAB",
		"RC_6Rnd_155mm_Mo_lowHEAB",
		"RC_7Rnd_155mm_Mo_lowHEAB",
		"RC_8Rnd_155mm_Mo_lowHEAB",
		"RC_9Rnd_155mm_Mo_lowHEAB",
		"RC_10Rnd_155mm_Mo_lowHEAB",
		"RC_11Rnd_155mm_Mo_lowHEAB",
		"RC_12Rnd_155mm_Mo_lowHEAB",
		"RC_13Rnd_155mm_Mo_lowHEAB",
		"RC_14Rnd_155mm_Mo_lowHEAB",
		"RC_15Rnd_155mm_Mo_lowHEAB",
		"RC_16Rnd_155mm_Mo_lowHEAB",
		"RC_17Rnd_155mm_Mo_lowHEAB",
		"RC_18Rnd_155mm_Mo_lowHEAB",
		"RC_19Rnd_155mm_Mo_lowHEAB",
		"RC_20Rnd_155mm_Mo_lowHEAB",
		"RC_21Rnd_155mm_Mo_lowHEAB",
		"RC_22Rnd_155mm_Mo_lowHEAB",
		"RC_23Rnd_155mm_Mo_lowHEAB",
		"RC_24Rnd_155mm_Mo_lowHEAB",
		"RC_25Rnd_155mm_Mo_lowHEAB",
		"RC_26Rnd_155mm_Mo_lowHEAB",
		"RC_27Rnd_155mm_Mo_lowHEAB",
		"RC_28Rnd_155mm_Mo_lowHEAB",
		"RC_29Rnd_155mm_Mo_lowHEAB",
		"RC_30Rnd_155mm_Mo_lowHEAB",
		"RC_31Rnd_155mm_Mo_lowHEAB",
		"RC_32Rnd_155mm_Mo_lowHEAB",
		"RC_33Rnd_155mm_Mo_lowHEAB",
		"RC_34Rnd_155mm_Mo_lowHEAB",
		"RC_35Rnd_155mm_Mo_lowHEAB",
		"RC_36Rnd_155mm_Mo_lowHEAB",
		"RC_37Rnd_155mm_Mo_lowHEAB",
		"RC_38Rnd_155mm_Mo_lowHEAB",
		"RC_39Rnd_155mm_Mo_lowHEAB",
		"RC_40Rnd_155mm_Mo_lowHEAB",

		"RC_1Rnd_155mm_Mo_smoke",
		"RC_2Rnd_155mm_Mo_smoke",
		"RC_3Rnd_155mm_Mo_smoke",
		"RC_4Rnd_155mm_Mo_smoke",
		"RC_5Rnd_155mm_Mo_smoke",
		"RC_6Rnd_155mm_Mo_smoke",
		"RC_7Rnd_155mm_Mo_smoke",
		"RC_8Rnd_155mm_Mo_smoke",
		"RC_9Rnd_155mm_Mo_smoke",
		"RC_10Rnd_155mm_Mo_smoke",
		"RC_11Rnd_155mm_Mo_smoke",
		"RC_12Rnd_155mm_Mo_smoke",
		"RC_13Rnd_155mm_Mo_smoke",
		"RC_14Rnd_155mm_Mo_smoke",
		"RC_15Rnd_155mm_Mo_smoke",
		"RC_16Rnd_155mm_Mo_smoke",
		"RC_17Rnd_155mm_Mo_smoke",
		"RC_18Rnd_155mm_Mo_smoke",
		"RC_19Rnd_155mm_Mo_smoke",
		"RC_20Rnd_155mm_Mo_smoke",
		"RC_21Rnd_155mm_Mo_smoke",
		"RC_22Rnd_155mm_Mo_smoke",
		"RC_23Rnd_155mm_Mo_smoke",
		"RC_24Rnd_155mm_Mo_smoke",
		"RC_25Rnd_155mm_Mo_smoke",
		"RC_26Rnd_155mm_Mo_smoke",
		"RC_27Rnd_155mm_Mo_smoke",
		"RC_28Rnd_155mm_Mo_smoke",
		"RC_29Rnd_155mm_Mo_smoke",
		"RC_30Rnd_155mm_Mo_smoke",
		"RC_31Rnd_155mm_Mo_smoke",
		"RC_32Rnd_155mm_Mo_smoke",
		"RC_33Rnd_155mm_Mo_smoke",
		"RC_34Rnd_155mm_Mo_smoke",
		"RC_35Rnd_155mm_Mo_smoke",
		"RC_36Rnd_155mm_Mo_smoke",
		"RC_37Rnd_155mm_Mo_smoke",
		"RC_38Rnd_155mm_Mo_smoke",
		"RC_39Rnd_155mm_Mo_smoke",
		"RC_40Rnd_155mm_Mo_smoke",

		"RC_1Rnd_155mm_Mo_Cluster",
		"RC_2Rnd_155mm_Mo_Cluster",
		"RC_3Rnd_155mm_Mo_Cluster",
		"RC_4Rnd_155mm_Mo_Cluster",
		"RC_5Rnd_155mm_Mo_Cluster",
		"RC_6Rnd_155mm_Mo_Cluster",
		"RC_7Rnd_155mm_Mo_Cluster",
		"RC_8Rnd_155mm_Mo_Cluster",
		"RC_9Rnd_155mm_Mo_Cluster",
		"RC_10Rnd_155mm_Mo_Cluster",
		"RC_11Rnd_155mm_Mo_Cluster",
		"RC_12Rnd_155mm_Mo_Cluster",
		"RC_13Rnd_155mm_Mo_Cluster",
		"RC_14Rnd_155mm_Mo_Cluster",
		"RC_15Rnd_155mm_Mo_Cluster",
		"RC_16Rnd_155mm_Mo_Cluster",
		"RC_17Rnd_155mm_Mo_Cluster",
		"RC_18Rnd_155mm_Mo_Cluster",
		"RC_19Rnd_155mm_Mo_Cluster",
		"RC_20Rnd_155mm_Mo_Cluster",
		"RC_21Rnd_155mm_Mo_Cluster",
		"RC_22Rnd_155mm_Mo_Cluster",
		"RC_23Rnd_155mm_Mo_Cluster",
		"RC_24Rnd_155mm_Mo_Cluster",
		"RC_25Rnd_155mm_Mo_Cluster",
		"RC_26Rnd_155mm_Mo_Cluster",
		"RC_27Rnd_155mm_Mo_Cluster",
		"RC_28Rnd_155mm_Mo_Cluster",
		"RC_29Rnd_155mm_Mo_Cluster",
		"RC_30Rnd_155mm_Mo_Cluster",
		"RC_31Rnd_155mm_Mo_Cluster",
		"RC_32Rnd_155mm_Mo_Cluster",
		"RC_33Rnd_155mm_Mo_Cluster",
		"RC_34Rnd_155mm_Mo_Cluster",
		"RC_35Rnd_155mm_Mo_Cluster",
		"RC_36Rnd_155mm_Mo_Cluster",
		"RC_37Rnd_155mm_Mo_Cluster",
		"RC_38Rnd_155mm_Mo_Cluster",
		"RC_39Rnd_155mm_Mo_Cluster",
		"RC_40Rnd_155mm_Mo_Cluster",

		"RC_1Rnd_155mm_Mo_LaserGuided",
		"RC_2Rnd_155mm_Mo_LaserGuided",
		"RC_3Rnd_155mm_Mo_LaserGuided",
		"RC_4Rnd_155mm_Mo_LaserGuided",
		"RC_5Rnd_155mm_Mo_LaserGuided",
		"RC_6Rnd_155mm_Mo_LaserGuided",
		"RC_7Rnd_155mm_Mo_LaserGuided",
		"RC_8Rnd_155mm_Mo_LaserGuided",
		"RC_9Rnd_155mm_Mo_LaserGuided",
		"RC_10Rnd_155mm_Mo_LaserGuided",
		"RC_11Rnd_155mm_Mo_LaserGuided",
		"RC_12Rnd_155mm_Mo_LaserGuided",
		"RC_13Rnd_155mm_Mo_LaserGuided",
		"RC_14Rnd_155mm_Mo_LaserGuided",
		"RC_15Rnd_155mm_Mo_LaserGuided",
		"RC_16Rnd_155mm_Mo_LaserGuided",
		"RC_17Rnd_155mm_Mo_LaserGuided",
		"RC_18Rnd_155mm_Mo_LaserGuided",
		"RC_19Rnd_155mm_Mo_LaserGuided",
		"RC_20Rnd_155mm_Mo_LaserGuided",
		"RC_21Rnd_155mm_Mo_LaserGuided",
		"RC_22Rnd_155mm_Mo_LaserGuided",
		"RC_23Rnd_155mm_Mo_LaserGuided",
		"RC_24Rnd_155mm_Mo_LaserGuided",
		"RC_25Rnd_155mm_Mo_LaserGuided",
		"RC_26Rnd_155mm_Mo_LaserGuided",
		"RC_27Rnd_155mm_Mo_LaserGuided",
		"RC_28Rnd_155mm_Mo_LaserGuided",
		"RC_29Rnd_155mm_Mo_LaserGuided",
		"RC_30Rnd_155mm_Mo_LaserGuided",
		"RC_31Rnd_155mm_Mo_LaserGuided",
		"RC_32Rnd_155mm_Mo_LaserGuided",
		"RC_33Rnd_155mm_Mo_LaserGuided",
		"RC_34Rnd_155mm_Mo_LaserGuided",
		"RC_35Rnd_155mm_Mo_LaserGuided",
		"RC_36Rnd_155mm_Mo_LaserGuided",
		"RC_37Rnd_155mm_Mo_LaserGuided",
		"RC_38Rnd_155mm_Mo_LaserGuided",
		"RC_39Rnd_155mm_Mo_LaserGuided",
		"RC_40Rnd_155mm_Mo_LaserGuided",

		"RC_1Rnd_155mm_Mo_MultiGuided",
		"RC_2Rnd_155mm_Mo_MultiGuided",
		"RC_3Rnd_155mm_Mo_MultiGuided",
		"RC_4Rnd_155mm_Mo_MultiGuided",
		"RC_5Rnd_155mm_Mo_MultiGuided",
		"RC_6Rnd_155mm_Mo_MultiGuided",
		"RC_7Rnd_155mm_Mo_MultiGuided",
		"RC_8Rnd_155mm_Mo_MultiGuided",
		"RC_9Rnd_155mm_Mo_MultiGuided",
		"RC_10Rnd_155mm_Mo_MultiGuided",
		"RC_11Rnd_155mm_Mo_MultiGuided",
		"RC_12Rnd_155mm_Mo_MultiGuided",
		"RC_13Rnd_155mm_Mo_MultiGuided",
		"RC_14Rnd_155mm_Mo_MultiGuided",
		"RC_15Rnd_155mm_Mo_MultiGuided",
		"RC_16Rnd_155mm_Mo_MultiGuided",
		"RC_17Rnd_155mm_Mo_MultiGuided",
		"RC_18Rnd_155mm_Mo_MultiGuided",
		"RC_19Rnd_155mm_Mo_MultiGuided",
		"RC_20Rnd_155mm_Mo_MultiGuided",
		"RC_21Rnd_155mm_Mo_MultiGuided",
		"RC_22Rnd_155mm_Mo_MultiGuided",
		"RC_23Rnd_155mm_Mo_MultiGuided",
		"RC_24Rnd_155mm_Mo_MultiGuided",
		"RC_25Rnd_155mm_Mo_MultiGuided",
		"RC_26Rnd_155mm_Mo_MultiGuided",
		"RC_27Rnd_155mm_Mo_MultiGuided",
		"RC_28Rnd_155mm_Mo_MultiGuided",
		"RC_29Rnd_155mm_Mo_MultiGuided",
		"RC_30Rnd_155mm_Mo_MultiGuided",
		"RC_31Rnd_155mm_Mo_MultiGuided",
		"RC_32Rnd_155mm_Mo_MultiGuided",
		"RC_33Rnd_155mm_Mo_MultiGuided",
		"RC_34Rnd_155mm_Mo_MultiGuided",
		"RC_35Rnd_155mm_Mo_MultiGuided",
		"RC_36Rnd_155mm_Mo_MultiGuided",
		"RC_37Rnd_155mm_Mo_MultiGuided",
		"RC_38Rnd_155mm_Mo_MultiGuided",
		"RC_39Rnd_155mm_Mo_MultiGuided",
		"RC_40Rnd_155mm_Mo_MultiGuided",

		"RC_1Rnd_155mm_Mo_mine",
		"RC_2Rnd_155mm_Mo_mine",
		"RC_3Rnd_155mm_Mo_mine",
		"RC_4Rnd_155mm_Mo_mine",
		"RC_5Rnd_155mm_Mo_mine",
		"RC_6Rnd_155mm_Mo_mine",
		"RC_7Rnd_155mm_Mo_mine",
		"RC_8Rnd_155mm_Mo_mine",
		"RC_9Rnd_155mm_Mo_mine",
		"RC_10Rnd_155mm_Mo_mine",
		"RC_11Rnd_155mm_Mo_mine",
		"RC_12Rnd_155mm_Mo_mine",
		"RC_13Rnd_155mm_Mo_mine",
		"RC_14Rnd_155mm_Mo_mine",
		"RC_15Rnd_155mm_Mo_mine",
		"RC_16Rnd_155mm_Mo_mine",
		"RC_17Rnd_155mm_Mo_mine",
		"RC_18Rnd_155mm_Mo_mine",
		"RC_19Rnd_155mm_Mo_mine",
		"RC_20Rnd_155mm_Mo_mine",
		"RC_21Rnd_155mm_Mo_mine",
		"RC_22Rnd_155mm_Mo_mine",
		"RC_23Rnd_155mm_Mo_mine",
		"RC_24Rnd_155mm_Mo_mine",
		"RC_25Rnd_155mm_Mo_mine",
		"RC_26Rnd_155mm_Mo_mine",
		"RC_27Rnd_155mm_Mo_mine",
		"RC_28Rnd_155mm_Mo_mine",
		"RC_29Rnd_155mm_Mo_mine",
		"RC_30Rnd_155mm_Mo_mine",
		"RC_31Rnd_155mm_Mo_mine",
		"RC_32Rnd_155mm_Mo_mine",
		"RC_33Rnd_155mm_Mo_mine",
		"RC_34Rnd_155mm_Mo_mine",
		"RC_35Rnd_155mm_Mo_mine",
		"RC_36Rnd_155mm_Mo_mine",
		"RC_37Rnd_155mm_Mo_mine",
		"RC_38Rnd_155mm_Mo_mine",
		"RC_39Rnd_155mm_Mo_mine",
		"RC_40Rnd_155mm_Mo_mine",

		"RC_1Rnd_155mm_Mo_AT_mine",
		"RC_2Rnd_155mm_Mo_AT_mine",
		"RC_3Rnd_155mm_Mo_AT_mine",
		"RC_4Rnd_155mm_Mo_AT_mine",
		"RC_5Rnd_155mm_Mo_AT_mine",
		"RC_6Rnd_155mm_Mo_AT_mine",
		"RC_7Rnd_155mm_Mo_AT_mine",
		"RC_8Rnd_155mm_Mo_AT_mine",
		"RC_9Rnd_155mm_Mo_AT_mine",
		"RC_10Rnd_155mm_Mo_AT_mine",
		"RC_11Rnd_155mm_Mo_AT_mine",
		"RC_12Rnd_155mm_Mo_AT_mine",
		"RC_13Rnd_155mm_Mo_AT_mine",
		"RC_14Rnd_155mm_Mo_AT_mine",
		"RC_15Rnd_155mm_Mo_AT_mine",
		"RC_16Rnd_155mm_Mo_AT_mine",
		"RC_17Rnd_155mm_Mo_AT_mine",
		"RC_18Rnd_155mm_Mo_AT_mine",
		"RC_19Rnd_155mm_Mo_AT_mine",
		"RC_20Rnd_155mm_Mo_AT_mine",
		"RC_21Rnd_155mm_Mo_AT_mine",
		"RC_22Rnd_155mm_Mo_AT_mine",
		"RC_23Rnd_155mm_Mo_AT_mine",
		"RC_24Rnd_155mm_Mo_AT_mine",
		"RC_25Rnd_155mm_Mo_AT_mine",
		"RC_26Rnd_155mm_Mo_AT_mine",
		"RC_27Rnd_155mm_Mo_AT_mine",
		"RC_28Rnd_155mm_Mo_AT_mine",
		"RC_29Rnd_155mm_Mo_AT_mine",
		"RC_30Rnd_155mm_Mo_AT_mine",
		"RC_31Rnd_155mm_Mo_AT_mine",
		"RC_32Rnd_155mm_Mo_AT_mine",
		"RC_33Rnd_155mm_Mo_AT_mine",
		"RC_34Rnd_155mm_Mo_AT_mine",
		"RC_35Rnd_155mm_Mo_AT_mine",
		"RC_36Rnd_155mm_Mo_AT_mine",
		"RC_37Rnd_155mm_Mo_AT_mine",
		"RC_38Rnd_155mm_Mo_AT_mine",
		"RC_39Rnd_155mm_Mo_AT_mine",
		"RC_40Rnd_155mm_Mo_AT_mine",

		"RC_1Rnd_155mm_Mo_Illum",
		"RC_2Rnd_155mm_Mo_Illum",
		"RC_3Rnd_155mm_Mo_Illum",
		"RC_4Rnd_155mm_Mo_Illum",
		"RC_5Rnd_155mm_Mo_Illum",
		"RC_6Rnd_155mm_Mo_Illum",
		"RC_7Rnd_155mm_Mo_Illum",
		"RC_8Rnd_155mm_Mo_Illum",
		"RC_9Rnd_155mm_Mo_Illum",
		"RC_10Rnd_155mm_Mo_Illum",
		"RC_11Rnd_155mm_Mo_Illum",
		"RC_12Rnd_155mm_Mo_Illum",
		"RC_13Rnd_155mm_Mo_Illum",
		"RC_14Rnd_155mm_Mo_Illum",
		"RC_15Rnd_155mm_Mo_Illum",
		"RC_16Rnd_155mm_Mo_Illum",
		"RC_17Rnd_155mm_Mo_Illum",
		"RC_18Rnd_155mm_Mo_Illum",
		"RC_19Rnd_155mm_Mo_Illum",
		"RC_20Rnd_155mm_Mo_Illum",
		"RC_21Rnd_155mm_Mo_Illum",
		"RC_22Rnd_155mm_Mo_Illum",
		"RC_23Rnd_155mm_Mo_Illum",
		"RC_24Rnd_155mm_Mo_Illum",
		"RC_25Rnd_155mm_Mo_Illum",
		"RC_26Rnd_155mm_Mo_Illum",
		"RC_27Rnd_155mm_Mo_Illum",
		"RC_28Rnd_155mm_Mo_Illum",
		"RC_29Rnd_155mm_Mo_Illum",
		"RC_30Rnd_155mm_Mo_Illum",
		"RC_31Rnd_155mm_Mo_Illum",
		"RC_32Rnd_155mm_Mo_Illum",
		"RC_33Rnd_155mm_Mo_Illum",
		"RC_34Rnd_155mm_Mo_Illum",
		"RC_35Rnd_155mm_Mo_Illum",
		"RC_36Rnd_155mm_Mo_Illum",
		"RC_37Rnd_155mm_Mo_Illum",
		"RC_38Rnd_155mm_Mo_Illum",
		"RC_39Rnd_155mm_Mo_Illum",
		"RC_40Rnd_155mm_Mo_Illum",

		"RC_1Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_2Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_3Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_4Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_5Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_6Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_7Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_8Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_9Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_10Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_11Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_12Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_13Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_14Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_15Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_16Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_17Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_18Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_19Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_20Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_21Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_22Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_23Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_24Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_25Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_26Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_27Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_28Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_29Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_30Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_31Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_32Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_33Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_34Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_35Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_36Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_37Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_38Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_39Rnd_155mm_Mo_LG_DelayedFuse",
		"RC_40Rnd_155mm_Mo_LG_DelayedFuse",

		"RC_1Rnd_155mm_Mo_backupHEAB",
		"RC_2Rnd_155mm_Mo_backupHEAB",
		"RC_3Rnd_155mm_Mo_backupHEAB",
		"RC_4Rnd_155mm_Mo_backupHEAB",
		"RC_5Rnd_155mm_Mo_backupHEAB",
		"RC_6Rnd_155mm_Mo_backupHEAB",
		"RC_7Rnd_155mm_Mo_backupHEAB",
		"RC_8Rnd_155mm_Mo_backupHEAB",
		"RC_9Rnd_155mm_Mo_backupHEAB",
		"RC_10Rnd_155mm_Mo_backupHEAB",
		"RC_11Rnd_155mm_Mo_backupHEAB",
		"RC_12Rnd_155mm_Mo_backupHEAB",
		"RC_13Rnd_155mm_Mo_backupHEAB",
		"RC_14Rnd_155mm_Mo_backupHEAB",
		"RC_15Rnd_155mm_Mo_backupHEAB",
		"RC_16Rnd_155mm_Mo_backupHEAB",
		"RC_17Rnd_155mm_Mo_backupHEAB",
		"RC_18Rnd_155mm_Mo_backupHEAB",
		"RC_19Rnd_155mm_Mo_backupHEAB",
		"RC_20Rnd_155mm_Mo_backupHEAB",
		"RC_21Rnd_155mm_Mo_backupHEAB",
		"RC_22Rnd_155mm_Mo_backupHEAB",
		"RC_23Rnd_155mm_Mo_backupHEAB",
		"RC_24Rnd_155mm_Mo_backupHEAB",
		"RC_25Rnd_155mm_Mo_backupHEAB",
		"RC_26Rnd_155mm_Mo_backupHEAB",
		"RC_27Rnd_155mm_Mo_backupHEAB",
		"RC_28Rnd_155mm_Mo_backupHEAB",
		"RC_29Rnd_155mm_Mo_backupHEAB",
		"RC_30Rnd_155mm_Mo_backupHEAB",
		"RC_31Rnd_155mm_Mo_backupHEAB",
		"RC_32Rnd_155mm_Mo_backupHEAB",
		"RC_33Rnd_155mm_Mo_backupHEAB",
		"RC_34Rnd_155mm_Mo_backupHEAB",
		"RC_35Rnd_155mm_Mo_backupHEAB",
		"RC_36Rnd_155mm_Mo_backupHEAB",
		"RC_37Rnd_155mm_Mo_backupHEAB",
		"RC_38Rnd_155mm_Mo_backupHEAB",
		"RC_39Rnd_155mm_Mo_backupHEAB",
		"RC_40Rnd_155mm_Mo_backupHEAB",

		"RC_1Rnd_155mm_Mo_backuplowHEAB",
		"RC_2Rnd_155mm_Mo_backuplowHEAB",
		"RC_3Rnd_155mm_Mo_backuplowHEAB",
		"RC_4Rnd_155mm_Mo_backuplowHEAB",
		"RC_5Rnd_155mm_Mo_backuplowHEAB",
		"RC_6Rnd_155mm_Mo_backuplowHEAB",
		"RC_7Rnd_155mm_Mo_backuplowHEAB",
		"RC_8Rnd_155mm_Mo_backuplowHEAB",
		"RC_9Rnd_155mm_Mo_backuplowHEAB",
		"RC_10Rnd_155mm_Mo_backuplowHEAB",
		"RC_11Rnd_155mm_Mo_backuplowHEAB",
		"RC_12Rnd_155mm_Mo_backuplowHEAB",
		"RC_13Rnd_155mm_Mo_backuplowHEAB",
		"RC_14Rnd_155mm_Mo_backuplowHEAB",
		"RC_15Rnd_155mm_Mo_backuplowHEAB",
		"RC_16Rnd_155mm_Mo_backuplowHEAB",
		"RC_17Rnd_155mm_Mo_backuplowHEAB",
		"RC_18Rnd_155mm_Mo_backuplowHEAB",
		"RC_19Rnd_155mm_Mo_backuplowHEAB",
		"RC_20Rnd_155mm_Mo_backuplowHEAB",
		"RC_21Rnd_155mm_Mo_backuplowHEAB",
		"RC_22Rnd_155mm_Mo_backuplowHEAB",
		"RC_23Rnd_155mm_Mo_backuplowHEAB",
		"RC_24Rnd_155mm_Mo_backuplowHEAB",
		"RC_25Rnd_155mm_Mo_backuplowHEAB",
		"RC_26Rnd_155mm_Mo_backuplowHEAB",
		"RC_27Rnd_155mm_Mo_backuplowHEAB",
		"RC_28Rnd_155mm_Mo_backuplowHEAB",
		"RC_29Rnd_155mm_Mo_backuplowHEAB",
		"RC_30Rnd_155mm_Mo_backuplowHEAB",
		"RC_31Rnd_155mm_Mo_backuplowHEAB",
		"RC_32Rnd_155mm_Mo_backuplowHEAB",
		"RC_33Rnd_155mm_Mo_backuplowHEAB",
		"RC_34Rnd_155mm_Mo_backuplowHEAB",
		"RC_35Rnd_155mm_Mo_backuplowHEAB",
		"RC_36Rnd_155mm_Mo_backuplowHEAB",
		"RC_37Rnd_155mm_Mo_backuplowHEAB",
		"RC_38Rnd_155mm_Mo_backuplowHEAB",
		"RC_39Rnd_155mm_Mo_backuplowHEAB",
		"RC_40Rnd_155mm_Mo_backuplowHEAB"
	};
};
class RC_155mm_AMOS_V2: RC_155mm_AMOS_V1
{
	reloadTime=6;
	magazineReloadTime=6;
	ballisticsComputer=8;		//direct fire reticle for highest charge
	canLock=2;
	weaponLockDelay=0;

	class Single1: Single1
	{	
		/*
		aiBurstTerminable=1;
		burst=1;
		soundBurst=0;
		aiDispersionCoefX=1;
		aiDispersionCoefY=1;
		aiRateOfFireDispersion=1;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		*/
		reloadTime=6;
	};
	class Single2: Single2
	{
		reloadTime=6;
	};
	class Single3: Single3
	{
		reloadTime=6;
	};
	class Single4: Single4
	{
		reloadTime=6;
	};
	class Single5: Single5
	{
		reloadTime=6;
	};
	//used by ai, rof decreased
	class Burst1: Burst1
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst2: Burst2
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst3: Burst3
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst4: Burst4
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
	class Burst5: Burst5
	{
		minRangeProbab=0.01;
		midRangeProbab=0.01;
		maxRangeProbab=0.01;
		burst=1;
		//reloadTime=15;
	};
};
class RC_155mm_AMOS_V3: RC_155mm_AMOS_V2
{
	/*
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7",
		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4",
		"Burst5"
	};
	*/
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7"
	};
	class Single1: Single1
	{
		displayName="CH0";
		artilleryCharge=0.265; //300m minrange
		minRange=293;
		midRange=1551;
		maxRange=2809;
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
		aiDispersionCoefX=1;
		aiDispersionCoefY=1;
		//aiRateOfFireDispersion=1;
		aiRateOfFire=1;
		aiRateOfFireDistance=10;
	};
	class Single2: Single1
	{
		displayName="CH1";
		artilleryCharge=0.331;
		minRange=458;
		midRange=2420;
		maxRange=4382;
	};
	class Single3: Single1
	{
		displayName="CH2";
		artilleryCharge=0.413;
		minRange=713;
		midRange=3767.5;
		maxRange=6822;
	};
	class Single4: Single1
	{
		displayName="CH3";
		artilleryCharge=0.515;
		minRange=1108;
		midRange=5858.5;
		maxRange=10609;
	};
	class Single5: Single1
	{
		displayName="CH4";
		artilleryCharge=0.642;
		minRange=1723;
		midRange=9104.5;
		maxRange=16486;
	};
	class Single6: Single1
	{
		displayName="CH5";
		artilleryCharge=0.801;
		minRange=2682;
		midRange=14173;
		maxRange=25664;
	};
	class Single7: Single1
	{
		displayName="CH6 reticle";
		artilleryCharge=1;
		minRange=4180;
		midRange=22090;
		maxRange=40000;
	};
};
class RC_155mm_AMOS_V4: RC_155mm_AMOS_V3
{
	class Single1: Single1
	{
		artilleryDispersion=2;
	};
	class Single2: Single2
	{
		artilleryDispersion=2;
	};
	class Single3: Single3
	{
		artilleryDispersion=2;
	};
	class Single4: Single4
	{
		artilleryDispersion=2;
	};
	class Single5: Single5
	{
		artilleryDispersion=2;
	};
	class Single6: Single6
	{
		artilleryDispersion=2;
	};
	class Single7: Single7
	{
		artilleryDispersion=2;
	};
};


//105mm
class RC_105mm_AMOS_V4: RC_155mm_AMOS_V4
{
	displayName="105mm";
	displayNameShort="105mm";
	reloadTime=5;
	magazineReloadTime=5;

	class Single1: Single1
	{
		reloadTime=5;
		minRange=117;
		midRange=620;
		maxRange=1123;
	};
	class Single2: Single2
	{
		reloadTime=5;
		minRange=183;
		midRange=968;
		maxRange=1753;
	};
	class Single3: Single3
	{
		reloadTime=5;
		minRange=285;
		midRange=1507;
		maxRange=2729;
	};
	class Single4: Single4
	{
		reloadTime=5;
		minRange=443;
		midRange=2343;
		maxRange=4243;
	};
	class Single5: Single5
	{
		reloadTime=5;
		minRange=689;
		midRange=3641.5;
		maxRange=6594;
	};
	class Single6: Single6
	{
		reloadTime=5;
		minRange=1073;
		midRange=5669;
		maxRange=10265;
	};
	class Single7: Single7
	{
		reloadTime=5;
		minRange=1672;
		midRange=8836;
		maxRange=16000;
	};

	magazines[]=
	{
		"RC_1Rnd_105mm_Mo_shells",
		"RC_2Rnd_105mm_Mo_shells",
		"RC_3Rnd_105mm_Mo_shells",
		"RC_4Rnd_105mm_Mo_shells",
		"RC_5Rnd_105mm_Mo_shells",
		"RC_6Rnd_105mm_Mo_shells",
		"RC_7Rnd_105mm_Mo_shells",
		"RC_8Rnd_105mm_Mo_shells",
		"RC_9Rnd_105mm_Mo_shells",
		"RC_10Rnd_105mm_Mo_shells",
		"RC_11Rnd_105mm_Mo_shells",
		"RC_12Rnd_105mm_Mo_shells",
		"RC_13Rnd_105mm_Mo_shells",
		"RC_14Rnd_105mm_Mo_shells",
		"RC_15Rnd_105mm_Mo_shells",
		"RC_16Rnd_105mm_Mo_shells",
		"RC_17Rnd_105mm_Mo_shells",
		"RC_18Rnd_105mm_Mo_shells",
		"RC_19Rnd_105mm_Mo_shells",
		"RC_20Rnd_105mm_Mo_shells",
		"RC_21Rnd_105mm_Mo_shells",
		"RC_22Rnd_105mm_Mo_shells",
		"RC_23Rnd_105mm_Mo_shells",
		"RC_24Rnd_105mm_Mo_shells",
		"RC_25Rnd_105mm_Mo_shells",
		"RC_26Rnd_105mm_Mo_shells",
		"RC_27Rnd_105mm_Mo_shells",
		"RC_28Rnd_105mm_Mo_shells",
		"RC_29Rnd_105mm_Mo_shells",
		"RC_30Rnd_105mm_Mo_shells",
		"RC_31Rnd_105mm_Mo_shells",
		"RC_32Rnd_105mm_Mo_shells",
		"RC_33Rnd_105mm_Mo_shells",
		"RC_34Rnd_105mm_Mo_shells",
		"RC_35Rnd_105mm_Mo_shells",
		"RC_36Rnd_105mm_Mo_shells",
		"RC_37Rnd_105mm_Mo_shells",
		"RC_38Rnd_105mm_Mo_shells",
		"RC_39Rnd_105mm_Mo_shells",
		"RC_40Rnd_105mm_Mo_shells",

		"RC_1Rnd_105mm_Mo_HEAB",
		"RC_2Rnd_105mm_Mo_HEAB",
		"RC_3Rnd_105mm_Mo_HEAB",
		"RC_4Rnd_105mm_Mo_HEAB",
		"RC_5Rnd_105mm_Mo_HEAB",
		"RC_6Rnd_105mm_Mo_HEAB",
		"RC_7Rnd_105mm_Mo_HEAB",
		"RC_8Rnd_105mm_Mo_HEAB",
		"RC_9Rnd_105mm_Mo_HEAB",
		"RC_10Rnd_105mm_Mo_HEAB",
		"RC_11Rnd_105mm_Mo_HEAB",
		"RC_12Rnd_105mm_Mo_HEAB",
		"RC_13Rnd_105mm_Mo_HEAB",
		"RC_14Rnd_105mm_Mo_HEAB",
		"RC_15Rnd_105mm_Mo_HEAB",
		"RC_16Rnd_105mm_Mo_HEAB",
		"RC_17Rnd_105mm_Mo_HEAB",
		"RC_18Rnd_105mm_Mo_HEAB",
		"RC_19Rnd_105mm_Mo_HEAB",
		"RC_20Rnd_105mm_Mo_HEAB",
		"RC_21Rnd_105mm_Mo_HEAB",
		"RC_22Rnd_105mm_Mo_HEAB",
		"RC_23Rnd_105mm_Mo_HEAB",
		"RC_24Rnd_105mm_Mo_HEAB",
		"RC_25Rnd_105mm_Mo_HEAB",
		"RC_26Rnd_105mm_Mo_HEAB",
		"RC_27Rnd_105mm_Mo_HEAB",
		"RC_28Rnd_105mm_Mo_HEAB",
		"RC_29Rnd_105mm_Mo_HEAB",
		"RC_30Rnd_105mm_Mo_HEAB",
		"RC_31Rnd_105mm_Mo_HEAB",
		"RC_32Rnd_105mm_Mo_HEAB",
		"RC_33Rnd_105mm_Mo_HEAB",
		"RC_34Rnd_105mm_Mo_HEAB",
		"RC_35Rnd_105mm_Mo_HEAB",
		"RC_36Rnd_105mm_Mo_HEAB",
		"RC_37Rnd_105mm_Mo_HEAB",
		"RC_38Rnd_105mm_Mo_HEAB",
		"RC_39Rnd_105mm_Mo_HEAB",
		"RC_40Rnd_105mm_Mo_HEAB",

		"RC_1Rnd_105mm_Mo_lowHEAB",
		"RC_2Rnd_105mm_Mo_lowHEAB",
		"RC_3Rnd_105mm_Mo_lowHEAB",
		"RC_4Rnd_105mm_Mo_lowHEAB",
		"RC_5Rnd_105mm_Mo_lowHEAB",
		"RC_6Rnd_105mm_Mo_lowHEAB",
		"RC_7Rnd_105mm_Mo_lowHEAB",
		"RC_8Rnd_105mm_Mo_lowHEAB",
		"RC_9Rnd_105mm_Mo_lowHEAB",
		"RC_10Rnd_105mm_Mo_lowHEAB",
		"RC_11Rnd_105mm_Mo_lowHEAB",
		"RC_12Rnd_105mm_Mo_lowHEAB",
		"RC_13Rnd_105mm_Mo_lowHEAB",
		"RC_14Rnd_105mm_Mo_lowHEAB",
		"RC_15Rnd_105mm_Mo_lowHEAB",
		"RC_16Rnd_105mm_Mo_lowHEAB",
		"RC_17Rnd_105mm_Mo_lowHEAB",
		"RC_18Rnd_105mm_Mo_lowHEAB",
		"RC_19Rnd_105mm_Mo_lowHEAB",
		"RC_20Rnd_105mm_Mo_lowHEAB",
		"RC_21Rnd_105mm_Mo_lowHEAB",
		"RC_22Rnd_105mm_Mo_lowHEAB",
		"RC_23Rnd_105mm_Mo_lowHEAB",
		"RC_24Rnd_105mm_Mo_lowHEAB",
		"RC_25Rnd_105mm_Mo_lowHEAB",
		"RC_26Rnd_105mm_Mo_lowHEAB",
		"RC_27Rnd_105mm_Mo_lowHEAB",
		"RC_28Rnd_105mm_Mo_lowHEAB",
		"RC_29Rnd_105mm_Mo_lowHEAB",
		"RC_30Rnd_105mm_Mo_lowHEAB",
		"RC_31Rnd_105mm_Mo_lowHEAB",
		"RC_32Rnd_105mm_Mo_lowHEAB",
		"RC_33Rnd_105mm_Mo_lowHEAB",
		"RC_34Rnd_105mm_Mo_lowHEAB",
		"RC_35Rnd_105mm_Mo_lowHEAB",
		"RC_36Rnd_105mm_Mo_lowHEAB",
		"RC_37Rnd_105mm_Mo_lowHEAB",
		"RC_38Rnd_105mm_Mo_lowHEAB",
		"RC_39Rnd_105mm_Mo_lowHEAB",
		"RC_40Rnd_105mm_Mo_lowHEAB",

		"RC_1Rnd_105mm_Mo_smoke",
		"RC_2Rnd_105mm_Mo_smoke",
		"RC_3Rnd_105mm_Mo_smoke",
		"RC_4Rnd_105mm_Mo_smoke",
		"RC_5Rnd_105mm_Mo_smoke",
		"RC_6Rnd_105mm_Mo_smoke",
		"RC_7Rnd_105mm_Mo_smoke",
		"RC_8Rnd_105mm_Mo_smoke",
		"RC_9Rnd_105mm_Mo_smoke",
		"RC_10Rnd_105mm_Mo_smoke",
		"RC_11Rnd_105mm_Mo_smoke",
		"RC_12Rnd_105mm_Mo_smoke",
		"RC_13Rnd_105mm_Mo_smoke",
		"RC_14Rnd_105mm_Mo_smoke",
		"RC_15Rnd_105mm_Mo_smoke",
		"RC_16Rnd_105mm_Mo_smoke",
		"RC_17Rnd_105mm_Mo_smoke",
		"RC_18Rnd_105mm_Mo_smoke",
		"RC_19Rnd_105mm_Mo_smoke",
		"RC_20Rnd_105mm_Mo_smoke",
		"RC_21Rnd_105mm_Mo_smoke",
		"RC_22Rnd_105mm_Mo_smoke",
		"RC_23Rnd_105mm_Mo_smoke",
		"RC_24Rnd_105mm_Mo_smoke",
		"RC_25Rnd_105mm_Mo_smoke",
		"RC_26Rnd_105mm_Mo_smoke",
		"RC_27Rnd_105mm_Mo_smoke",
		"RC_28Rnd_105mm_Mo_smoke",
		"RC_29Rnd_105mm_Mo_smoke",
		"RC_30Rnd_105mm_Mo_smoke",
		"RC_31Rnd_105mm_Mo_smoke",
		"RC_32Rnd_105mm_Mo_smoke",
		"RC_33Rnd_105mm_Mo_smoke",
		"RC_34Rnd_105mm_Mo_smoke",
		"RC_35Rnd_105mm_Mo_smoke",
		"RC_36Rnd_105mm_Mo_smoke",
		"RC_37Rnd_105mm_Mo_smoke",
		"RC_38Rnd_105mm_Mo_smoke",
		"RC_39Rnd_105mm_Mo_smoke",
		"RC_40Rnd_105mm_Mo_smoke",

		"RC_1Rnd_105mm_Mo_Cluster",
		"RC_2Rnd_105mm_Mo_Cluster",
		"RC_3Rnd_105mm_Mo_Cluster",
		"RC_4Rnd_105mm_Mo_Cluster",
		"RC_5Rnd_105mm_Mo_Cluster",
		"RC_6Rnd_105mm_Mo_Cluster",
		"RC_7Rnd_105mm_Mo_Cluster",
		"RC_8Rnd_105mm_Mo_Cluster",
		"RC_9Rnd_105mm_Mo_Cluster",
		"RC_10Rnd_105mm_Mo_Cluster",
		"RC_11Rnd_105mm_Mo_Cluster",
		"RC_12Rnd_105mm_Mo_Cluster",
		"RC_13Rnd_105mm_Mo_Cluster",
		"RC_14Rnd_105mm_Mo_Cluster",
		"RC_15Rnd_105mm_Mo_Cluster",
		"RC_16Rnd_105mm_Mo_Cluster",
		"RC_17Rnd_105mm_Mo_Cluster",
		"RC_18Rnd_105mm_Mo_Cluster",
		"RC_19Rnd_105mm_Mo_Cluster",
		"RC_20Rnd_105mm_Mo_Cluster",
		"RC_21Rnd_105mm_Mo_Cluster",
		"RC_22Rnd_105mm_Mo_Cluster",
		"RC_23Rnd_105mm_Mo_Cluster",
		"RC_24Rnd_105mm_Mo_Cluster",
		"RC_25Rnd_105mm_Mo_Cluster",
		"RC_26Rnd_105mm_Mo_Cluster",
		"RC_27Rnd_105mm_Mo_Cluster",
		"RC_28Rnd_105mm_Mo_Cluster",
		"RC_29Rnd_105mm_Mo_Cluster",
		"RC_30Rnd_105mm_Mo_Cluster",
		"RC_31Rnd_105mm_Mo_Cluster",
		"RC_32Rnd_105mm_Mo_Cluster",
		"RC_33Rnd_105mm_Mo_Cluster",
		"RC_34Rnd_105mm_Mo_Cluster",
		"RC_35Rnd_105mm_Mo_Cluster",
		"RC_36Rnd_105mm_Mo_Cluster",
		"RC_37Rnd_105mm_Mo_Cluster",
		"RC_38Rnd_105mm_Mo_Cluster",
		"RC_39Rnd_105mm_Mo_Cluster",
		"RC_40Rnd_105mm_Mo_Cluster",

		"RC_1Rnd_105mm_Mo_LaserGuided",
		"RC_2Rnd_105mm_Mo_LaserGuided",
		"RC_3Rnd_105mm_Mo_LaserGuided",
		"RC_4Rnd_105mm_Mo_LaserGuided",
		"RC_5Rnd_105mm_Mo_LaserGuided",
		"RC_6Rnd_105mm_Mo_LaserGuided",
		"RC_7Rnd_105mm_Mo_LaserGuided",
		"RC_8Rnd_105mm_Mo_LaserGuided",
		"RC_9Rnd_105mm_Mo_LaserGuided",
		"RC_10Rnd_105mm_Mo_LaserGuided",
		"RC_11Rnd_105mm_Mo_LaserGuided",
		"RC_12Rnd_105mm_Mo_LaserGuided",
		"RC_13Rnd_105mm_Mo_LaserGuided",
		"RC_14Rnd_105mm_Mo_LaserGuided",
		"RC_15Rnd_105mm_Mo_LaserGuided",
		"RC_16Rnd_105mm_Mo_LaserGuided",
		"RC_17Rnd_105mm_Mo_LaserGuided",
		"RC_18Rnd_105mm_Mo_LaserGuided",
		"RC_19Rnd_105mm_Mo_LaserGuided",
		"RC_20Rnd_105mm_Mo_LaserGuided",
		"RC_21Rnd_105mm_Mo_LaserGuided",
		"RC_22Rnd_105mm_Mo_LaserGuided",
		"RC_23Rnd_105mm_Mo_LaserGuided",
		"RC_24Rnd_105mm_Mo_LaserGuided",
		"RC_25Rnd_105mm_Mo_LaserGuided",
		"RC_26Rnd_105mm_Mo_LaserGuided",
		"RC_27Rnd_105mm_Mo_LaserGuided",
		"RC_28Rnd_105mm_Mo_LaserGuided",
		"RC_29Rnd_105mm_Mo_LaserGuided",
		"RC_30Rnd_105mm_Mo_LaserGuided",
		"RC_31Rnd_105mm_Mo_LaserGuided",
		"RC_32Rnd_105mm_Mo_LaserGuided",
		"RC_33Rnd_105mm_Mo_LaserGuided",
		"RC_34Rnd_105mm_Mo_LaserGuided",
		"RC_35Rnd_105mm_Mo_LaserGuided",
		"RC_36Rnd_105mm_Mo_LaserGuided",
		"RC_37Rnd_105mm_Mo_LaserGuided",
		"RC_38Rnd_105mm_Mo_LaserGuided",
		"RC_39Rnd_105mm_Mo_LaserGuided",
		"RC_40Rnd_105mm_Mo_LaserGuided",

		"RC_1Rnd_105mm_Mo_MultiGuided",
		"RC_2Rnd_105mm_Mo_MultiGuided",
		"RC_3Rnd_105mm_Mo_MultiGuided",
		"RC_4Rnd_105mm_Mo_MultiGuided",
		"RC_5Rnd_105mm_Mo_MultiGuided",
		"RC_6Rnd_105mm_Mo_MultiGuided",
		"RC_7Rnd_105mm_Mo_MultiGuided",
		"RC_8Rnd_105mm_Mo_MultiGuided",
		"RC_9Rnd_105mm_Mo_MultiGuided",
		"RC_10Rnd_105mm_Mo_MultiGuided",
		"RC_11Rnd_105mm_Mo_MultiGuided",
		"RC_12Rnd_105mm_Mo_MultiGuided",
		"RC_13Rnd_105mm_Mo_MultiGuided",
		"RC_14Rnd_105mm_Mo_MultiGuided",
		"RC_15Rnd_105mm_Mo_MultiGuided",
		"RC_16Rnd_105mm_Mo_MultiGuided",
		"RC_17Rnd_105mm_Mo_MultiGuided",
		"RC_18Rnd_105mm_Mo_MultiGuided",
		"RC_19Rnd_105mm_Mo_MultiGuided",
		"RC_20Rnd_105mm_Mo_MultiGuided",
		"RC_21Rnd_105mm_Mo_MultiGuided",
		"RC_22Rnd_105mm_Mo_MultiGuided",
		"RC_23Rnd_105mm_Mo_MultiGuided",
		"RC_24Rnd_105mm_Mo_MultiGuided",
		"RC_25Rnd_105mm_Mo_MultiGuided",
		"RC_26Rnd_105mm_Mo_MultiGuided",
		"RC_27Rnd_105mm_Mo_MultiGuided",
		"RC_28Rnd_105mm_Mo_MultiGuided",
		"RC_29Rnd_105mm_Mo_MultiGuided",
		"RC_30Rnd_105mm_Mo_MultiGuided",
		"RC_31Rnd_105mm_Mo_MultiGuided",
		"RC_32Rnd_105mm_Mo_MultiGuided",
		"RC_33Rnd_105mm_Mo_MultiGuided",
		"RC_34Rnd_105mm_Mo_MultiGuided",
		"RC_35Rnd_105mm_Mo_MultiGuided",
		"RC_36Rnd_105mm_Mo_MultiGuided",
		"RC_37Rnd_105mm_Mo_MultiGuided",
		"RC_38Rnd_105mm_Mo_MultiGuided",
		"RC_39Rnd_105mm_Mo_MultiGuided",
		"RC_40Rnd_105mm_Mo_MultiGuided",

		"RC_1Rnd_105mm_Mo_mine",
		"RC_2Rnd_105mm_Mo_mine",
		"RC_3Rnd_105mm_Mo_mine",
		"RC_4Rnd_105mm_Mo_mine",
		"RC_5Rnd_105mm_Mo_mine",
		"RC_6Rnd_105mm_Mo_mine",
		"RC_7Rnd_105mm_Mo_mine",
		"RC_8Rnd_105mm_Mo_mine",
		"RC_9Rnd_105mm_Mo_mine",
		"RC_10Rnd_105mm_Mo_mine",
		"RC_11Rnd_105mm_Mo_mine",
		"RC_12Rnd_105mm_Mo_mine",
		"RC_13Rnd_105mm_Mo_mine",
		"RC_14Rnd_105mm_Mo_mine",
		"RC_15Rnd_105mm_Mo_mine",
		"RC_16Rnd_105mm_Mo_mine",
		"RC_17Rnd_105mm_Mo_mine",
		"RC_18Rnd_105mm_Mo_mine",
		"RC_19Rnd_105mm_Mo_mine",
		"RC_20Rnd_105mm_Mo_mine",
		"RC_21Rnd_105mm_Mo_mine",
		"RC_22Rnd_105mm_Mo_mine",
		"RC_23Rnd_105mm_Mo_mine",
		"RC_24Rnd_105mm_Mo_mine",
		"RC_25Rnd_105mm_Mo_mine",
		"RC_26Rnd_105mm_Mo_mine",
		"RC_27Rnd_105mm_Mo_mine",
		"RC_28Rnd_105mm_Mo_mine",
		"RC_29Rnd_105mm_Mo_mine",
		"RC_30Rnd_105mm_Mo_mine",
		"RC_31Rnd_105mm_Mo_mine",
		"RC_32Rnd_105mm_Mo_mine",
		"RC_33Rnd_105mm_Mo_mine",
		"RC_34Rnd_105mm_Mo_mine",
		"RC_35Rnd_105mm_Mo_mine",
		"RC_36Rnd_105mm_Mo_mine",
		"RC_37Rnd_105mm_Mo_mine",
		"RC_38Rnd_105mm_Mo_mine",
		"RC_39Rnd_105mm_Mo_mine",
		"RC_40Rnd_105mm_Mo_mine",

		"RC_1Rnd_105mm_Mo_AT_mine",
		"RC_2Rnd_105mm_Mo_AT_mine",
		"RC_3Rnd_105mm_Mo_AT_mine",
		"RC_4Rnd_105mm_Mo_AT_mine",
		"RC_5Rnd_105mm_Mo_AT_mine",
		"RC_6Rnd_105mm_Mo_AT_mine",
		"RC_7Rnd_105mm_Mo_AT_mine",
		"RC_8Rnd_105mm_Mo_AT_mine",
		"RC_9Rnd_105mm_Mo_AT_mine",
		"RC_10Rnd_105mm_Mo_AT_mine",
		"RC_11Rnd_105mm_Mo_AT_mine",
		"RC_12Rnd_105mm_Mo_AT_mine",
		"RC_13Rnd_105mm_Mo_AT_mine",
		"RC_14Rnd_105mm_Mo_AT_mine",
		"RC_15Rnd_105mm_Mo_AT_mine",
		"RC_16Rnd_105mm_Mo_AT_mine",
		"RC_17Rnd_105mm_Mo_AT_mine",
		"RC_18Rnd_105mm_Mo_AT_mine",
		"RC_19Rnd_105mm_Mo_AT_mine",
		"RC_20Rnd_105mm_Mo_AT_mine",
		"RC_21Rnd_105mm_Mo_AT_mine",
		"RC_22Rnd_105mm_Mo_AT_mine",
		"RC_23Rnd_105mm_Mo_AT_mine",
		"RC_24Rnd_105mm_Mo_AT_mine",
		"RC_25Rnd_105mm_Mo_AT_mine",
		"RC_26Rnd_105mm_Mo_AT_mine",
		"RC_27Rnd_105mm_Mo_AT_mine",
		"RC_28Rnd_105mm_Mo_AT_mine",
		"RC_29Rnd_105mm_Mo_AT_mine",
		"RC_30Rnd_105mm_Mo_AT_mine",
		"RC_31Rnd_105mm_Mo_AT_mine",
		"RC_32Rnd_105mm_Mo_AT_mine",
		"RC_33Rnd_105mm_Mo_AT_mine",
		"RC_34Rnd_105mm_Mo_AT_mine",
		"RC_35Rnd_105mm_Mo_AT_mine",
		"RC_36Rnd_105mm_Mo_AT_mine",
		"RC_37Rnd_105mm_Mo_AT_mine",
		"RC_38Rnd_105mm_Mo_AT_mine",
		"RC_39Rnd_105mm_Mo_AT_mine",
		"RC_40Rnd_105mm_Mo_AT_mine",

		"RC_1Rnd_105mm_Mo_Illum",
		"RC_2Rnd_105mm_Mo_Illum",
		"RC_3Rnd_105mm_Mo_Illum",
		"RC_4Rnd_105mm_Mo_Illum",
		"RC_5Rnd_105mm_Mo_Illum",
		"RC_6Rnd_105mm_Mo_Illum",
		"RC_7Rnd_105mm_Mo_Illum",
		"RC_8Rnd_105mm_Mo_Illum",
		"RC_9Rnd_105mm_Mo_Illum",
		"RC_10Rnd_105mm_Mo_Illum",
		"RC_11Rnd_105mm_Mo_Illum",
		"RC_12Rnd_105mm_Mo_Illum",
		"RC_13Rnd_105mm_Mo_Illum",
		"RC_14Rnd_105mm_Mo_Illum",
		"RC_15Rnd_105mm_Mo_Illum",
		"RC_16Rnd_105mm_Mo_Illum",
		"RC_17Rnd_105mm_Mo_Illum",
		"RC_18Rnd_105mm_Mo_Illum",
		"RC_19Rnd_105mm_Mo_Illum",
		"RC_20Rnd_105mm_Mo_Illum",
		"RC_21Rnd_105mm_Mo_Illum",
		"RC_22Rnd_105mm_Mo_Illum",
		"RC_23Rnd_105mm_Mo_Illum",
		"RC_24Rnd_105mm_Mo_Illum",
		"RC_25Rnd_105mm_Mo_Illum",
		"RC_26Rnd_105mm_Mo_Illum",
		"RC_27Rnd_105mm_Mo_Illum",
		"RC_28Rnd_105mm_Mo_Illum",
		"RC_29Rnd_105mm_Mo_Illum",
		"RC_30Rnd_105mm_Mo_Illum",
		"RC_31Rnd_105mm_Mo_Illum",
		"RC_32Rnd_105mm_Mo_Illum",
		"RC_33Rnd_105mm_Mo_Illum",
		"RC_34Rnd_105mm_Mo_Illum",
		"RC_35Rnd_105mm_Mo_Illum",
		"RC_36Rnd_105mm_Mo_Illum",
		"RC_37Rnd_105mm_Mo_Illum",
		"RC_38Rnd_105mm_Mo_Illum",
		"RC_39Rnd_105mm_Mo_Illum",
		"RC_40Rnd_105mm_Mo_Illum",

		"RC_1Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_2Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_3Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_4Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_5Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_6Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_7Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_8Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_9Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_10Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_11Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_12Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_13Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_14Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_15Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_16Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_17Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_18Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_19Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_20Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_21Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_22Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_23Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_24Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_25Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_26Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_27Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_28Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_29Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_30Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_31Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_32Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_33Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_34Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_35Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_36Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_37Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_38Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_39Rnd_105mm_Mo_LG_DelayedFuse",
		"RC_40Rnd_105mm_Mo_LG_DelayedFuse",

		"RC_1Rnd_105mm_Mo_backupHEAB",
		"RC_2Rnd_105mm_Mo_backupHEAB",
		"RC_3Rnd_105mm_Mo_backupHEAB",
		"RC_4Rnd_105mm_Mo_backupHEAB",
		"RC_5Rnd_105mm_Mo_backupHEAB",
		"RC_6Rnd_105mm_Mo_backupHEAB",
		"RC_7Rnd_105mm_Mo_backupHEAB",
		"RC_8Rnd_105mm_Mo_backupHEAB",
		"RC_9Rnd_105mm_Mo_backupHEAB",
		"RC_10Rnd_105mm_Mo_backupHEAB",
		"RC_11Rnd_105mm_Mo_backupHEAB",
		"RC_12Rnd_105mm_Mo_backupHEAB",
		"RC_13Rnd_105mm_Mo_backupHEAB",
		"RC_14Rnd_105mm_Mo_backupHEAB",
		"RC_15Rnd_105mm_Mo_backupHEAB",
		"RC_16Rnd_105mm_Mo_backupHEAB",
		"RC_17Rnd_105mm_Mo_backupHEAB",
		"RC_18Rnd_105mm_Mo_backupHEAB",
		"RC_19Rnd_105mm_Mo_backupHEAB",
		"RC_20Rnd_105mm_Mo_backupHEAB",
		"RC_21Rnd_105mm_Mo_backupHEAB",
		"RC_22Rnd_105mm_Mo_backupHEAB",
		"RC_23Rnd_105mm_Mo_backupHEAB",
		"RC_24Rnd_105mm_Mo_backupHEAB",
		"RC_25Rnd_105mm_Mo_backupHEAB",
		"RC_26Rnd_105mm_Mo_backupHEAB",
		"RC_27Rnd_105mm_Mo_backupHEAB",
		"RC_28Rnd_105mm_Mo_backupHEAB",
		"RC_29Rnd_105mm_Mo_backupHEAB",
		"RC_30Rnd_105mm_Mo_backupHEAB",
		"RC_31Rnd_105mm_Mo_backupHEAB",
		"RC_32Rnd_105mm_Mo_backupHEAB",
		"RC_33Rnd_105mm_Mo_backupHEAB",
		"RC_34Rnd_105mm_Mo_backupHEAB",
		"RC_35Rnd_105mm_Mo_backupHEAB",
		"RC_36Rnd_105mm_Mo_backupHEAB",
		"RC_37Rnd_105mm_Mo_backupHEAB",
		"RC_38Rnd_105mm_Mo_backupHEAB",
		"RC_39Rnd_105mm_Mo_backupHEAB",
		"RC_40Rnd_105mm_Mo_backupHEAB",

		"RC_1Rnd_105mm_Mo_backuplowHEAB",
		"RC_2Rnd_105mm_Mo_backuplowHEAB",
		"RC_3Rnd_105mm_Mo_backuplowHEAB",
		"RC_4Rnd_105mm_Mo_backuplowHEAB",
		"RC_5Rnd_105mm_Mo_backuplowHEAB",
		"RC_6Rnd_105mm_Mo_backuplowHEAB",
		"RC_7Rnd_105mm_Mo_backuplowHEAB",
		"RC_8Rnd_105mm_Mo_backuplowHEAB",
		"RC_9Rnd_105mm_Mo_backuplowHEAB",
		"RC_10Rnd_105mm_Mo_backuplowHEAB",
		"RC_11Rnd_105mm_Mo_backuplowHEAB",
		"RC_12Rnd_105mm_Mo_backuplowHEAB",
		"RC_13Rnd_105mm_Mo_backuplowHEAB",
		"RC_14Rnd_105mm_Mo_backuplowHEAB",
		"RC_15Rnd_105mm_Mo_backuplowHEAB",
		"RC_16Rnd_105mm_Mo_backuplowHEAB",
		"RC_17Rnd_105mm_Mo_backuplowHEAB",
		"RC_18Rnd_105mm_Mo_backuplowHEAB",
		"RC_19Rnd_105mm_Mo_backuplowHEAB",
		"RC_20Rnd_105mm_Mo_backuplowHEAB",
		"RC_21Rnd_105mm_Mo_backuplowHEAB",
		"RC_22Rnd_105mm_Mo_backuplowHEAB",
		"RC_23Rnd_105mm_Mo_backuplowHEAB",
		"RC_24Rnd_105mm_Mo_backuplowHEAB",
		"RC_25Rnd_105mm_Mo_backuplowHEAB",
		"RC_26Rnd_105mm_Mo_backuplowHEAB",
		"RC_27Rnd_105mm_Mo_backuplowHEAB",
		"RC_28Rnd_105mm_Mo_backuplowHEAB",
		"RC_29Rnd_105mm_Mo_backuplowHEAB",
		"RC_30Rnd_105mm_Mo_backuplowHEAB",
		"RC_31Rnd_105mm_Mo_backuplowHEAB",
		"RC_32Rnd_105mm_Mo_backuplowHEAB",
		"RC_33Rnd_105mm_Mo_backuplowHEAB",
		"RC_34Rnd_105mm_Mo_backuplowHEAB",
		"RC_35Rnd_105mm_Mo_backuplowHEAB",
		"RC_36Rnd_105mm_Mo_backuplowHEAB",
		"RC_37Rnd_105mm_Mo_backuplowHEAB",
		"RC_38Rnd_105mm_Mo_backuplowHEAB",
		"RC_39Rnd_105mm_Mo_backuplowHEAB",
		"RC_40Rnd_105mm_Mo_backuplowHEAB"
	};
};


// 230mm MLRS/MRL Rockets/Missiles
class rockets_230mm_GAT;
class rockets_230mm_GAT_Base: rockets_230mm_GAT
{
	class Mode_1;
	class Mode_2;
	class Mode_3;
	class Mode_4;
	class Mode_5;
	class Mode_6;
	class Mode_7;
	class Mode_8;
	class Mode_9;
	class Mode_10;
	class Mode_11;
	class Mode_12;
	class Mode_13;
	class Mode_14;
	class Mode_15;
	class Mode_16;
};
class RC_rockets_230mm_GAT: rockets_230mm_GAT_Base
{
	magazineReloadTime=1;
	ballisticsComputer=8;
	canLock=2;
	weaponLockDelay=0;

	class Mode_1: Mode_1
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_2: Mode_2
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_3: Mode_3
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_4: Mode_4
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_5: Mode_5
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_6: Mode_6
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_7: Mode_7
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_8: Mode_8
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_9: Mode_9
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_10: Mode_10
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_11: Mode_11
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_12: Mode_12
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_13: Mode_13
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_14: Mode_14
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_15: Mode_15
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	class Mode_16: Mode_16
	{
		minRangeProbab=0.01;
		midRangeProbab=0.02;
		maxRangeProbab=0.01;
	};
	magazines[]=
	{
		"RC_1Rnd_230mm_rockets",
		"RC_2Rnd_230mm_rockets",
		"RC_3Rnd_230mm_rockets",
		"RC_4Rnd_230mm_rockets",
		"RC_5Rnd_230mm_rockets",
		"RC_6Rnd_230mm_rockets",
		"RC_7Rnd_230mm_rockets",
		"RC_8Rnd_230mm_rockets",
		"RC_9Rnd_230mm_rockets",
		"RC_10Rnd_230mm_rockets",
		"RC_11Rnd_230mm_rockets",
		"RC_12Rnd_230mm_rockets",
		
		"RC_1Rnd_230mm_rockets_HEAB",
		"RC_2Rnd_230mm_rockets_HEAB",
		"RC_3Rnd_230mm_rockets_HEAB",
		"RC_4Rnd_230mm_rockets_HEAB",
		"RC_5Rnd_230mm_rockets_HEAB",
		"RC_6Rnd_230mm_rockets_HEAB",
		"RC_7Rnd_230mm_rockets_HEAB",
		"RC_8Rnd_230mm_rockets_HEAB",
		"RC_9Rnd_230mm_rockets_HEAB",
		"RC_10Rnd_230mm_rockets_HEAB",
		"RC_11Rnd_230mm_rockets_HEAB",
		"RC_12Rnd_230mm_rockets_HEAB",

		"RC_1Rnd_230mm_rockets_lowHEAB",
		"RC_2Rnd_230mm_rockets_lowHEAB",
		"RC_3Rnd_230mm_rockets_lowHEAB",
		"RC_4Rnd_230mm_rockets_lowHEAB",
		"RC_5Rnd_230mm_rockets_lowHEAB",
		"RC_6Rnd_230mm_rockets_lowHEAB",
		"RC_7Rnd_230mm_rockets_lowHEAB",
		"RC_8Rnd_230mm_rockets_lowHEAB",
		"RC_9Rnd_230mm_rockets_lowHEAB",
		"RC_10Rnd_230mm_rockets_lowHEAB",
		"RC_11Rnd_230mm_rockets_lowHEAB",
		"RC_12Rnd_230mm_rockets_lowHEAB",

		"RC_1Rnd_230mm_rockets_cluster",
		"RC_2Rnd_230mm_rockets_cluster",
		"RC_3Rnd_230mm_rockets_cluster",
		"RC_4Rnd_230mm_rockets_cluster",
		"RC_5Rnd_230mm_rockets_cluster",
		"RC_6Rnd_230mm_rockets_cluster",
		"RC_7Rnd_230mm_rockets_cluster",
		"RC_8Rnd_230mm_rockets_cluster",
		"RC_9Rnd_230mm_rockets_cluster",
		"RC_10Rnd_230mm_rockets_cluster",
		"RC_11Rnd_230mm_rockets_cluster",
		"RC_12Rnd_230mm_rockets_cluster",

		"RC_1Rnd_230mm_rockets_LaserGuided",
		"RC_2Rnd_230mm_rockets_LaserGuided",
		"RC_3Rnd_230mm_rockets_LaserGuided",
		"RC_4Rnd_230mm_rockets_LaserGuided",
		"RC_5Rnd_230mm_rockets_LaserGuided",
		"RC_6Rnd_230mm_rockets_LaserGuided",
		"RC_7Rnd_230mm_rockets_LaserGuided",
		"RC_8Rnd_230mm_rockets_LaserGuided",
		"RC_9Rnd_230mm_rockets_LaserGuided",
		"RC_10Rnd_230mm_rockets_LaserGuided",
		"RC_11Rnd_230mm_rockets_LaserGuided",
		"RC_12Rnd_230mm_rockets_LaserGuided",

		"RC_1Rnd_230mm_rockets_MultiGuided",
		"RC_2Rnd_230mm_rockets_MultiGuided",
		"RC_3Rnd_230mm_rockets_MultiGuided",
		"RC_4Rnd_230mm_rockets_MultiGuided",
		"RC_5Rnd_230mm_rockets_MultiGuided",
		"RC_6Rnd_230mm_rockets_MultiGuided",
		"RC_7Rnd_230mm_rockets_MultiGuided",
		"RC_8Rnd_230mm_rockets_MultiGuided",
		"RC_9Rnd_230mm_rockets_MultiGuided",
		"RC_10Rnd_230mm_rockets_MultiGuided",
		"RC_11Rnd_230mm_rockets_MultiGuided",
		"RC_12Rnd_230mm_rockets_MultiGuided",

		"RC_1Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_2Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_3Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_4Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_5Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_6Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_7Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_8Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_9Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_10Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_11Rnd_230mm_rockets_LG_DelayedFuse",
		"RC_12Rnd_230mm_rockets_LG_DelayedFuse",

		"RC_1Rnd_604mm_rockets_ATACMS_HEAB",
		"RC_2Rnd_604mm_rockets_ATACMS_HEAB",

		"RC_1Rnd_604mm_rockets_ATACMS_DPICM",
		"RC_2Rnd_604mm_rockets_ATACMS_DPICM",

		"RC_1Rnd_230mm_rockets_backupHEAB",
		"RC_2Rnd_230mm_rockets_backupHEAB",
		"RC_3Rnd_230mm_rockets_backupHEAB",
		"RC_4Rnd_230mm_rockets_backupHEAB",
		"RC_5Rnd_230mm_rockets_backupHEAB",
		"RC_6Rnd_230mm_rockets_backupHEAB",
		"RC_7Rnd_230mm_rockets_backupHEAB",
		"RC_8Rnd_230mm_rockets_backupHEAB",
		"RC_9Rnd_230mm_rockets_backupHEAB",
		"RC_10Rnd_230mm_rockets_backupHEAB",
		"RC_11Rnd_230mm_rockets_backupHEAB",
		"RC_12Rnd_230mm_rockets_backupHEAB",

		"RC_1Rnd_230mm_rockets_backuplowHEAB",
		"RC_2Rnd_230mm_rockets_backuplowHEAB",
		"RC_3Rnd_230mm_rockets_backuplowHEAB",
		"RC_4Rnd_230mm_rockets_backuplowHEAB",
		"RC_5Rnd_230mm_rockets_backuplowHEAB",
		"RC_6Rnd_230mm_rockets_backuplowHEAB",
		"RC_7Rnd_230mm_rockets_backuplowHEAB",
		"RC_8Rnd_230mm_rockets_backuplowHEAB",
		"RC_9Rnd_230mm_rockets_backuplowHEAB",
		"RC_10Rnd_230mm_rockets_backuplowHEAB",
		"RC_11Rnd_230mm_rockets_backuplowHEAB",
		"RC_12Rnd_230mm_rockets_backuplowHEAB",

		"RC_1Rnd_604mm_rockets_ATACMS_backupHEAB",
		"RC_2Rnd_604mm_rockets_ATACMS_backupHEAB"
	};
};
class RC_rockets_604mm_GAT: RC_rockets_230mm_GAT
{
	magazines[]=
	{
		"RC_1Rnd_604mm_rockets_ATACMS_HEAB",
		"RC_2Rnd_604mm_rockets_ATACMS_HEAB",

		"RC_1Rnd_604mm_rockets_ATACMS_DPICM",
		"RC_2Rnd_604mm_rockets_ATACMS_DPICM",

		"RC_1Rnd_604mm_rockets_ATACMS_backupHEAB",
		"RC_2Rnd_604mm_rockets_ATACMS_backupHEAB"
	};
};