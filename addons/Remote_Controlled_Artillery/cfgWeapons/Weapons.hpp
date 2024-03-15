// Improved Laser Designators
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
	opticsZoomMin=0.0099999998;
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
class RC_IFV_Missle_Launcher: missiles_titan
{
	scope=1;
	canLock=2;
	weaponLockSystem="2 + 4 + 16";
	displayName="NLOS ML";
	displayNameShort="NLOS ML";
	magazineReloadTime=20;
	magazines[]=
	{
		"RC_2Rnd_IFV_MP_NLOS",
		"RC_2Rnd_IFV_AA"
	};
};


//Vehicle MMG's
class HMG_127_AFV;
class RC_MMG_338_FSV_Base: HMG_127_AFV
{
	class manual;
};
class RC_MMG_338_FSV: RC_MMG_338_FSV_Base
{
	author="Ascent";
	displayName="coaxial MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.75;
	magazines[]=
	{
		"RC_200Rnd_338_T_Mag"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
	};
};
class RC_MMG_338_FSV_coax: RC_MMG_338_FSV
{
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
class RC_MMG_338_MBT_Base: HMG_127_MBT
{
	class manual;
};
class RC_MMG_338_MBT: RC_MMG_338_MBT_Base
{
	author="Ascent";
	displayName="coaxial MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.75;
	magazines[]=
	{
		"RC_200Rnd_338_T_Mag"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
	};
};
class RC_MMG_338_MBT_coax: RC_MMG_338_MBT
{
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
class LMG_coax;
class RC_MMG_338_IFV_2_Base: LMG_coax
{
	class manual;
};
class RC_MMG_338_IFV_2: RC_MMG_338_IFV_2_Base
{
	author="Ascent";
	displayName="coaxial MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.75;
	magazines[]=
	{
		"RC_200Rnd_338_T_Mag"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
	};
};
class LMG_coax_ext;
class RC_MMG_338_IFV_1_Base: LMG_coax_ext
{
	class manual;
};
class RC_MMG_338_IFV_1: RC_MMG_338_IFV_1_Base
{
	author="Ascent";
	displayName="coaxial MMG";
	canLock=2;
	maxZeroing=3000;
	FCSZeroingDelay=0.75;
	magazines[]=
	{
		"RC_200Rnd_338_T_Mag"
	};
	class manual: manual
	{
		displayName=".338 NM";
		dispersion=0.001;
	};
};


//Autocannons
class autocannon_30mm_CTWS;
class RC_autocannon_30mm_CTWS_Base: autocannon_30mm_CTWS
{
	class HE;
	class AP;
};
class RC_autocannon_30mm_CTWS: RC_autocannon_30mm_CTWS_Base
{
	author="Ascent";
	canLock=2;
	FCSZeroingDelay=0.75;

	class HE: HE
	{
		magazines[]=
		{
			"RC_100Rnd_30mm_MP_T"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_100Rnd_30mm_APFSDS_T"
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
	FCSZeroingDelay=0.75;

	class HE: HE
	{
		magazines[]=
		{
			"RC_50Rnd_40mm_MP_T"
		};
	};
	class AP: AP
	{
		magazines[]=
		{
			"RC_50Rnd_40mm_APFSDS_T"
		};
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
	magazines[]=
	{
		"RC_12Rnd_120mm_APFSDS_T",
		"RC_16Rnd_120mm_APFSDS_T",
		"RC_20Rnd_120mm_APFSDS_T",
		"RC_12Rnd_120mm_MP_T",
		"RC_16Rnd_120mm_MP_T",
		"RC_20Rnd_120mm_MP_T",
		"RC_3Rnd_120mm_DLG_cannon_missiles"
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
	reloadTime=3;
	magazineReloadTime=3;
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
	//disabled temporarely ai fire due to autonomous engaging of laser spots potentially causing friendly fire
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
		artilleryDispersion=1.9;
		artilleryCharge=0.34999999;
	};
	class Single2: Single1
	{
		displayName="CH1, 2km";
		artilleryCharge=0.69999999;
	};
	class Single3: Single1
	{
		displayName="CH2, 4km";
		artilleryCharge=1;
	};
	//used by ai, rof decreased
	class Burst1: Burst1
	{
		burst=1;
		reloadTime=15;
	};
	class Burst2: Burst2
	{
		burst=1;
		reloadTime=15;
	};
	class Burst3: Burst3
	{
		burst=1;
		reloadTime=15;
	};
};


//82mm Vehicle Mortar 6km
class RC_vehiclemortar_82mm_V4: RC_mortar_82mm_V3
{
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7",
		"Single8"
	};
	//disabled temporarely ai fire due to autonomous engaging of laser spots potentially causing friendly fire
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
		"Single8",
		"Burst1",
		"Burst2",
		"Burst3",
	};
	*/
	class Single1: Single1
	{
		displayName="CH0";
		artilleryDispersion=1.9;
		artilleryCharge=0.35;
	};
	class Single2: Single1
	{
		displayName="CH1";
		artilleryCharge=0.418;
	};
	class Single3: Single1
	{
		displayName="CH2";
		artilleryCharge=0.4992;
	};
	class Single4: Single1
	{
		displayName="CH3";
		artilleryCharge=0.5962;
	};
	class Single5: Single1
	{
		displayName="CH4";
		artilleryCharge=0.712;
	};
	class Single6: Single1
	{
		displayName="CH5";
		artilleryCharge=0.8504;
	};
	class Single7: Single1
	{
		displayName="CH6";
		artilleryCharge=1.0156;
	};
	class Single8: Single1
	{
		displayName="CH7";
		artilleryCharge=1.2129;
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
		burst=1;
		reloadTime=15;
	};
	class Burst2: Burst2
	{
		burst=1;
		reloadTime=15;
	};
	class Burst3: Burst3
	{
		burst=1;
		reloadTime=15;
	};
	class Burst4: Burst4
	{
		burst=1;
		reloadTime=15;
	};
	class Burst5: Burst5
	{
		burst=1;
		reloadTime=15;
	};
};
class RC_ShipCannon_120mm_V3: RC_ShipCannon_120mm_V2
{
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7",
		"Single8"
	};
	//disabled temporarely ai fire due to autonomous engaging of laser spots potentially causing friendly fire
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
		"Single8",
		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4",
		"Burst5"
	};
	*/
	class Single1: Single1
	{
		displayName="CH0"
		artilleryCharge=0.19;
	};
	class Single2: Single1
	{
		displayName="CH1"
		artilleryCharge=0.241;
	};
	class Single3: Single1
	{
		displayName="CH2"
		artilleryCharge=0.305;
	};
	class Single4: Single1
	{
		displayName="CH3"
		artilleryCharge=0.387;
	};
	class Single5: Single1
	{
		displayName="CH4"
		artilleryCharge=0.491;
	};
	class Single6: Single1
	{
		displayName="CH5"
		artilleryCharge=0.622;
	};
	class Single7: Single1
	{
		displayName="CH6"
		artilleryCharge=0.789;
	};
	class Single8: Single1
	{
		displayName="CH7 direct"
		artilleryCharge=1;
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
	class Single8: Single8
	{
		artilleryDispersion=2;
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
		burst=1;
		reloadTime=15;
	};
	class Burst2: Burst2
	{
		burst=1;
		reloadTime=15;
	};
	class Burst3: Burst3
	{
		burst=1;
		reloadTime=15;
	};
	class Burst4: Burst4
	{
		burst=1;
		reloadTime=15;
	};
	class Burst5: Burst5
	{
		burst=1;
		reloadTime=15;
	};
};
class RC_155mm_AMOS_V3: RC_155mm_AMOS_V2
{
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Single7",
		"Single8"
	};
	//disabled temporarely ai fire due to autonomous engaging of laser spots potentially causing friendly fire
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
		"Single8",
		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4",
		"Burst5"
	};
	*/
	class Single1: Single1
	{
		displayName="CH0"
		artilleryCharge=0.19;
	};
	class Single2: Single1
	{
		displayName="CH1"
		artilleryCharge=0.241;
	};
	class Single3: Single1
	{
		displayName="CH2"
		artilleryCharge=0.305;
	};
	class Single4: Single1
	{
		displayName="CH3"
		artilleryCharge=0.387;
	};
	class Single5: Single1
	{
		displayName="CH4"
		artilleryCharge=0.491;
	};
	class Single6: Single1
	{
		displayName="CH5"
		artilleryCharge=0.622;
	};
	class Single7: Single1
	{
		displayName="CH6"
		artilleryCharge=0.789;
	};
	class Single8: Single1
	{
		displayName="CH7 direct"
		artilleryCharge=1;
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
	class Single8: Single8
	{
		artilleryDispersion=2;
	};
};


//105mm
class RC_105mm_AMOS_V4: RC_155mm_AMOS_V4
{
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5"
	};
	//disabled temporarely ai fire due to autonomous engaging of laser spots potentially causing friendly fire
	/*
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5",
		"Single6",
		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4",
		"Burst5"
	};
	*/
	class Single1: Single1
	{
		displayName="CH0"
		artilleryCharge=0.3;
	};
	class Single2: Single1
	{
		displayName="CH1"
		artilleryCharge=0.405;
	};
	class Single3: Single1
	{
		displayName="CH2"
		artilleryCharge=0.55;
	};
	class Single4: Single1
	{
		displayName="CH3"
		artilleryCharge=0.74;
	};
	class Single5: Single1
	{
		displayName="CH4 direct"
		artilleryCharge=1;
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


// 230mm MLRS/MRL Rockets/Missles
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
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_2: Mode_2
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_3: Mode_3
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_4: Mode_4
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_5: Mode_5
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_6: Mode_6
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_7: Mode_7
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_8: Mode_8
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_9: Mode_9
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_10: Mode_10
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_11: Mode_11
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_12: Mode_12
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_13: Mode_13
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_14: Mode_14
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_15: Mode_15
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
	};
	class Mode_16: Mode_16
	{
		minRangeProbab=0.0099999998;
		midRangeProbab=0.0099999998;
		maxRangeProbab=0.0099999998;
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