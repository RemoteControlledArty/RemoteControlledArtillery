class Laserdesignator;
class Laserdesignator_base: Laserdesignator
{
	class Components;
	scope=0;
	scopeCurator=0;
	scopeArsenal=0;
};


// Arid
class Improved_FOV_Laserdesignator_Arid: Laserdesignator_base
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
class Improved_FOV_Laserdesignator_Woodland: Improved_FOV_Laserdesignator_Arid
{
	model="\A3\Weapons_F\Binocular\laserdesignator_01_khk_f.p3d";
	picture="\A3\Weapons_F_Exp\Binocular\Data\UI\icon_Laserdesignator_01_khk_x_ca.paa";
};


// Thermal / Ti
class Improved_FOV_Laserdesignator_Ti_Arid: Improved_FOV_Laserdesignator_Arid
{
	displayName="Improved Laser Designator (whTi)";
	visionMode[]=
	{
		"Normal",
		"NVG",
		"TI"
	};
	thermalMode[]={0};
};
class Improved_FOV_Laserdesignator_Ti_Woodland: Improved_FOV_Laserdesignator_Ti_Arid
{
	model="\A3\Weapons_F\Binocular\laserdesignator_01_khk_f.p3d";
	picture="\A3\Weapons_F_Exp\Binocular\Data\UI\icon_Laserdesignator_01_khk_x_ca.paa";
};


/*
class Datalink_Laserdesignator_Ti_Arid: Improved_FOV_Laserdesignator_Arid
{
	displayName="Datalink Laser Designator (whTi)";

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=360;
					angleRangeVertical=360;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=67000;

					class AirTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=67000;
						maxRange=67000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;

					class AirTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=3000;
						maxRange=3000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};

					maxTrackableSpeed=600;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					aimDown=-0.5;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1000;

					class AirTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};

					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					aimDown=-0.5;
				};

				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};

	class Turrets
	{
		class MainTurret
		{
			showAllTargets="2 + 4";

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
class Datalink_Laserdesignator_Ti_Woodland: Datalink_Laserdesignator_Ti_Arid
{
	model="\A3\Weapons_F\Binocular\laserdesignator_01_khk_f.p3d";
	picture="\A3\Weapons_F_Exp\Binocular\Data\UI\icon_Laserdesignator_01_khk_x_ca.paa";
};
*/


class launch_Vorona_base_F;
class RC_ATGM: launch_Vorona_base_F
{
	scope=1;
	displayName="SACLOS ATGM";
	displayNameShort="SACLOS ATGM";
	reloadTime=7;
	magazineReloadTime=7;
	autoReload=1;	
	magazines[]=
	{
		"RC_1Rnd_ATGM_MT"
	};
};


class missiles_titan_static;
class RC_missiles_titan_static: missiles_titan_static
{
	scope=1;
	displayName="ATGM";
	displayNameShort="ATGM";
	reloadTime=7;
	magazineReloadTime=7;
	magazines[]=
	{
		"RC_1Rnd_MT_missiles",
	};
};


// 82mm Mortar 4km
class mortar_82mm;
class mortar_82mm_base: mortar_82mm
{
	class Single1;
	class Single2;
	class Single3;
};
class RC_mortar_82mm_V1: mortar_82mm_base
{
	magazines[]=
	{
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

		"RC_1Rnd_82mm_Mo_LG",
		"RC_2Rnd_82mm_Mo_LG",
		"RC_3Rnd_82mm_Mo_LG",
		"RC_4Rnd_82mm_Mo_LG",
		"RC_5Rnd_82mm_Mo_LG",
		"RC_6Rnd_82mm_Mo_LG",
		"RC_7Rnd_82mm_Mo_LG",
		"RC_8Rnd_82mm_Mo_LG",
		"RC_9Rnd_82mm_Mo_LG",
		"RC_10Rnd_82mm_Mo_LG",
		"RC_11Rnd_82mm_Mo_LG",
		"RC_12Rnd_82mm_Mo_LG",
		"RC_13Rnd_82mm_Mo_LG",
		"RC_14Rnd_82mm_Mo_LG",
		"RC_15Rnd_82mm_Mo_LG",
		"RC_16Rnd_82mm_Mo_LG",
		"RC_17Rnd_82mm_Mo_LG",
		"RC_18Rnd_82mm_Mo_LG",
		"RC_19Rnd_82mm_Mo_LG",
		"RC_20Rnd_82mm_Mo_LG",
		"RC_21Rnd_82mm_Mo_LG",
		"RC_22Rnd_82mm_Mo_LG",
		"RC_23Rnd_82mm_Mo_LG",
		"RC_24Rnd_82mm_Mo_LG",
		"RC_25Rnd_82mm_Mo_LG",
		"RC_26Rnd_82mm_Mo_LG",
		"RC_27Rnd_82mm_Mo_LG",
		"RC_28Rnd_82mm_Mo_LG",
		"RC_29Rnd_82mm_Mo_LG",
		"RC_30Rnd_82mm_Mo_LG",
		"RC_31Rnd_82mm_Mo_LG",
		"RC_32Rnd_82mm_Mo_LG",
		"RC_33Rnd_82mm_Mo_LG",
		"RC_34Rnd_82mm_Mo_LG",
		"RC_35Rnd_82mm_Mo_LG",
		"RC_36Rnd_82mm_Mo_LG",
		"RC_37Rnd_82mm_Mo_LG",
		"RC_38Rnd_82mm_Mo_LG",
		"RC_39Rnd_82mm_Mo_LG",
		"RC_40Rnd_82mm_Mo_LG",

		"RC_1Rnd_82mm_Mo_guided",
		"RC_2Rnd_82mm_Mo_guided",
		"RC_3Rnd_82mm_Mo_guided",
		"RC_4Rnd_82mm_Mo_guided",
		"RC_5Rnd_82mm_Mo_guided",
		"RC_6Rnd_82mm_Mo_guided",
		"RC_7Rnd_82mm_Mo_guided",
		"RC_8Rnd_82mm_Mo_guided",
		"RC_9Rnd_82mm_Mo_guided",
		"RC_10Rnd_82mm_Mo_guided",
		"RC_11Rnd_82mm_Mo_guided",
		"RC_12Rnd_82mm_Mo_guided",
		"RC_13Rnd_82mm_Mo_guided",
		"RC_14Rnd_82mm_Mo_guided",
		"RC_15Rnd_82mm_Mo_guided",
		"RC_16Rnd_82mm_Mo_guided",
		"RC_17Rnd_82mm_Mo_guided",
		"RC_18Rnd_82mm_Mo_guided",
		"RC_19Rnd_82mm_Mo_guided",
		"RC_20Rnd_82mm_Mo_guided",
		"RC_21Rnd_82mm_Mo_guided",
		"RC_22Rnd_82mm_Mo_guided",
		"RC_23Rnd_82mm_Mo_guided",
		"RC_24Rnd_82mm_Mo_guided",
		"RC_25Rnd_82mm_Mo_guided",
		"RC_26Rnd_82mm_Mo_guided",
		"RC_27Rnd_82mm_Mo_guided",
		"RC_28Rnd_82mm_Mo_guided",
		"RC_29Rnd_82mm_Mo_guided",
		"RC_30Rnd_82mm_Mo_guided",
		"RC_31Rnd_82mm_Mo_guided",
		"RC_32Rnd_82mm_Mo_guided",
		"RC_33Rnd_82mm_Mo_guided",
		"RC_34Rnd_82mm_Mo_guided",
		"RC_35Rnd_82mm_Mo_guided",
		"RC_36Rnd_82mm_Mo_guided",
		"RC_37Rnd_82mm_Mo_guided",
		"RC_38Rnd_82mm_Mo_guided",
		"RC_39Rnd_82mm_Mo_guided",
		"RC_40Rnd_82mm_Mo_guided",

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

		"RC_1Rnd_82mm_Mo_HEAB_low",
		"RC_2Rnd_82mm_Mo_HEAB_low",
		"RC_3Rnd_82mm_Mo_HEAB_low",
		"RC_4Rnd_82mm_Mo_HEAB_low",
		"RC_5Rnd_82mm_Mo_HEAB_low",
		"RC_6Rnd_82mm_Mo_HEAB_low",
		"RC_7Rnd_82mm_Mo_HEAB_low",
		"RC_8Rnd_82mm_Mo_HEAB_low",
		"RC_9Rnd_82mm_Mo_HEAB_low",
		"RC_10Rnd_82mm_Mo_HEAB_low",
		"RC_11Rnd_82mm_Mo_HEAB_low",
		"RC_12Rnd_82mm_Mo_HEAB_low",
		"RC_13Rnd_82mm_Mo_HEAB_low",
		"RC_14Rnd_82mm_Mo_HEAB_low",
		"RC_15Rnd_82mm_Mo_HEAB_low",
		"RC_16Rnd_82mm_Mo_HEAB_low",
		"RC_17Rnd_82mm_Mo_HEAB_low",
		"RC_18Rnd_82mm_Mo_HEAB_low",
		"RC_19Rnd_82mm_Mo_HEAB_low",
		"RC_20Rnd_82mm_Mo_HEAB_low",
		"RC_21Rnd_82mm_Mo_HEAB_low",
		"RC_22Rnd_82mm_Mo_HEAB_low",
		"RC_23Rnd_82mm_Mo_HEAB_low",
		"RC_24Rnd_82mm_Mo_HEAB_low",
		"RC_25Rnd_82mm_Mo_HEAB_low",
		"RC_26Rnd_82mm_Mo_HEAB_low",
		"RC_27Rnd_82mm_Mo_HEAB_low",
		"RC_28Rnd_82mm_Mo_HEAB_low",
		"RC_29Rnd_82mm_Mo_HEAB_low",
		"RC_30Rnd_82mm_Mo_HEAB_low",
		"RC_31Rnd_82mm_Mo_HEAB_low",
		"RC_32Rnd_82mm_Mo_HEAB_low",
		"RC_33Rnd_82mm_Mo_HEAB_low",
		"RC_34Rnd_82mm_Mo_HEAB_low",
		"RC_35Rnd_82mm_Mo_HEAB_low",
		"RC_36Rnd_82mm_Mo_HEAB_low",
		"RC_37Rnd_82mm_Mo_HEAB_low",
		"RC_38Rnd_82mm_Mo_HEAB_low",
		"RC_39Rnd_82mm_Mo_HEAB_low",
		"RC_40Rnd_82mm_Mo_HEAB_low",

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
		"RC_40Rnd_82mm_Mo_LG_DelayedFuse"
	};
};
class RC_mortar_82mm_V2: RC_mortar_82mm_V1
{
	reloadTime=3;
	magazineReloadTime=3;
	//ballisticsComputer=8;		//direct fire reticle for highest charge
	canLock=2;
	weaponLockDelay=0;
};
class RC_mortar_82mm_V3: RC_mortar_82mm_V2
{
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
};

//82mm Mortar 8km
class RC_mortar_82mm_V4: RC_mortar_82mm_V3
{
	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",
		"Single5"
	};
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
	class Single4: Single1
	{
		displayName="CH3, 6km";
		artilleryCharge=1.2129;
	};
	class Single5: Single1
	{
		displayName="CH4, 8km";
		artilleryCharge=1.4005;
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
};
class RC_ShipCannon_120mm_V1: RC_ShipCannon_120mm_base
{
	magazines[]=
	{
		"RC_ShipCannon_120mm_HEAB_shells_x1",
		"RC_ShipCannon_120mm_HEAB_shells_x2",
		"RC_ShipCannon_120mm_HEAB_shells_x3",
		"RC_ShipCannon_120mm_HEAB_shells_x4",
		"RC_ShipCannon_120mm_HEAB_shells_x5",
		"RC_ShipCannon_120mm_HEAB_shells_x6",
		"RC_ShipCannon_120mm_HEAB_shells_x7",
		"RC_ShipCannon_120mm_HEAB_shells_x8",
		"RC_ShipCannon_120mm_HEAB_shells_x9",
		"RC_ShipCannon_120mm_HEAB_shells_x10",
		"RC_ShipCannon_120mm_HEAB_shells_x11",
		"RC_ShipCannon_120mm_HEAB_shells_x12",
		"RC_ShipCannon_120mm_HEAB_shells_x13",
		"RC_ShipCannon_120mm_HEAB_shells_x14",
		"RC_ShipCannon_120mm_HEAB_shells_x15",
		"RC_ShipCannon_120mm_HEAB_shells_x16",
		"RC_ShipCannon_120mm_HEAB_shells_x17",
		"RC_ShipCannon_120mm_HEAB_shells_x18",
		"RC_ShipCannon_120mm_HEAB_shells_x19",
		"RC_ShipCannon_120mm_HEAB_shells_x20",
		"RC_ShipCannon_120mm_HEAB_shells_x21",
		"RC_ShipCannon_120mm_HEAB_shells_x22",
		"RC_ShipCannon_120mm_HEAB_shells_x23",
		"RC_ShipCannon_120mm_HEAB_shells_x24",
		"RC_ShipCannon_120mm_HEAB_shells_x25",
		"RC_ShipCannon_120mm_HEAB_shells_x26",
		"RC_ShipCannon_120mm_HEAB_shells_x27",
		"RC_ShipCannon_120mm_HEAB_shells_x28",
		"RC_ShipCannon_120mm_HEAB_shells_x29",
		"RC_ShipCannon_120mm_HEAB_shells_x30",
		"RC_ShipCannon_120mm_HEAB_shells_x31",
		"RC_ShipCannon_120mm_HEAB_shells_x32",
		"RC_ShipCannon_120mm_HEAB_shells_x33",
		"RC_ShipCannon_120mm_HEAB_shells_x34",
		"RC_ShipCannon_120mm_HEAB_shells_x35",
		"RC_ShipCannon_120mm_HEAB_shells_x36",
		"RC_ShipCannon_120mm_HEAB_shells_x37",
		"RC_ShipCannon_120mm_HEAB_shells_x38",
		"RC_ShipCannon_120mm_HEAB_shells_x39",
		"RC_ShipCannon_120mm_HEAB_shells_x40",

		"RC_ShipCannon_120mm_smoke_shells_x1",
		"RC_ShipCannon_120mm_smoke_shells_x2",
		"RC_ShipCannon_120mm_smoke_shells_x3",
		"RC_ShipCannon_120mm_smoke_shells_x4",
		"RC_ShipCannon_120mm_smoke_shells_x5",
		"RC_ShipCannon_120mm_smoke_shells_x6",
		"RC_ShipCannon_120mm_smoke_shells_x7",
		"RC_ShipCannon_120mm_smoke_shells_x8",
		"RC_ShipCannon_120mm_smoke_shells_x9",
		"RC_ShipCannon_120mm_smoke_shells_x10",
		"RC_ShipCannon_120mm_smoke_shells_x11",
		"RC_ShipCannon_120mm_smoke_shells_x12",
		"RC_ShipCannon_120mm_smoke_shells_x13",
		"RC_ShipCannon_120mm_smoke_shells_x14",
		"RC_ShipCannon_120mm_smoke_shells_x15",
		"RC_ShipCannon_120mm_smoke_shells_x16",
		"RC_ShipCannon_120mm_smoke_shells_x17",
		"RC_ShipCannon_120mm_smoke_shells_x18",
		"RC_ShipCannon_120mm_smoke_shells_x19",
		"RC_ShipCannon_120mm_smoke_shells_x20",
		"RC_ShipCannon_120mm_smoke_shells_x21",
		"RC_ShipCannon_120mm_smoke_shells_x22",
		"RC_ShipCannon_120mm_smoke_shells_x23",
		"RC_ShipCannon_120mm_smoke_shells_x24",
		"RC_ShipCannon_120mm_smoke_shells_x25",
		"RC_ShipCannon_120mm_smoke_shells_x26",
		"RC_ShipCannon_120mm_smoke_shells_x27",
		"RC_ShipCannon_120mm_smoke_shells_x28",
		"RC_ShipCannon_120mm_smoke_shells_x29",
		"RC_ShipCannon_120mm_smoke_shells_x30",
		"RC_ShipCannon_120mm_smoke_shells_x31",
		"RC_ShipCannon_120mm_smoke_shells_x32",
		"RC_ShipCannon_120mm_smoke_shells_x33",
		"RC_ShipCannon_120mm_smoke_shells_x34",
		"RC_ShipCannon_120mm_smoke_shells_x35",
		"RC_ShipCannon_120mm_smoke_shells_x36",
		"RC_ShipCannon_120mm_smoke_shells_x37",
		"RC_ShipCannon_120mm_smoke_shells_x38",
		"RC_ShipCannon_120mm_smoke_shells_x39",
		"RC_ShipCannon_120mm_smoke_shells_x40",

		"RC_ShipCannon_120mm_HE_cluster_shells_x1",
		"RC_ShipCannon_120mm_HE_cluster_shells_x2",
		"RC_ShipCannon_120mm_HE_cluster_shells_x3",
		"RC_ShipCannon_120mm_HE_cluster_shells_x4",
		"RC_ShipCannon_120mm_HE_cluster_shells_x5",
		"RC_ShipCannon_120mm_HE_cluster_shells_x6",
		"RC_ShipCannon_120mm_HE_cluster_shells_x7",
		"RC_ShipCannon_120mm_HE_cluster_shells_x8",
		"RC_ShipCannon_120mm_HE_cluster_shells_x9",
		"RC_ShipCannon_120mm_HE_cluster_shells_x10",
		"RC_ShipCannon_120mm_HE_cluster_shells_x11",
		"RC_ShipCannon_120mm_HE_cluster_shells_x12",
		"RC_ShipCannon_120mm_HE_cluster_shells_x13",
		"RC_ShipCannon_120mm_HE_cluster_shells_x14",
		"RC_ShipCannon_120mm_HE_cluster_shells_x15",
		"RC_ShipCannon_120mm_HE_cluster_shells_x16",
		"RC_ShipCannon_120mm_HE_cluster_shells_x17",
		"RC_ShipCannon_120mm_HE_cluster_shells_x18",
		"RC_ShipCannon_120mm_HE_cluster_shells_x19",
		"RC_ShipCannon_120mm_HE_cluster_shells_x20",
		"RC_ShipCannon_120mm_HE_cluster_shells_x21",
		"RC_ShipCannon_120mm_HE_cluster_shells_x22",
		"RC_ShipCannon_120mm_HE_cluster_shells_x23",
		"RC_ShipCannon_120mm_HE_cluster_shells_x24",
		"RC_ShipCannon_120mm_HE_cluster_shells_x25",
		"RC_ShipCannon_120mm_HE_cluster_shells_x26",
		"RC_ShipCannon_120mm_HE_cluster_shells_x27",
		"RC_ShipCannon_120mm_HE_cluster_shells_x28",
		"RC_ShipCannon_120mm_HE_cluster_shells_x29",
		"RC_ShipCannon_120mm_HE_cluster_shells_x30",
		"RC_ShipCannon_120mm_HE_cluster_shells_x31",
		"RC_ShipCannon_120mm_HE_cluster_shells_x32",
		"RC_ShipCannon_120mm_HE_cluster_shells_x33",
		"RC_ShipCannon_120mm_HE_cluster_shells_x34",
		"RC_ShipCannon_120mm_HE_cluster_shells_x35",
		"RC_ShipCannon_120mm_HE_cluster_shells_x36",
		"RC_ShipCannon_120mm_HE_cluster_shells_x37",
		"RC_ShipCannon_120mm_HE_cluster_shells_x38",
		"RC_ShipCannon_120mm_HE_cluster_shells_x39",
		"RC_ShipCannon_120mm_HE_cluster_shells_x40",

		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x1",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x2",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x3",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x4",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x5",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x6",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x7",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x8",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x9",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x10",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x11",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x12",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x13",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x14",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x15",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x16",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x17",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x18",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x19",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x20",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x21",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x22",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x23",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x24",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x25",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x26",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x27",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x28",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x29",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x30",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x31",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x32",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x33",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x34",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x35",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x36",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x37",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x38",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x39",
		"RC_ShipCannon_120mm_MT_MultiGuided_shells_x40",

		"RC_ShipCannon_120mm_HE_LG_shells_x1",
		"RC_ShipCannon_120mm_HE_LG_shells_x2",
		"RC_ShipCannon_120mm_HE_LG_shells_x3",
		"RC_ShipCannon_120mm_HE_LG_shells_x4",
		"RC_ShipCannon_120mm_HE_LG_shells_x5",
		"RC_ShipCannon_120mm_HE_LG_shells_x6",
		"RC_ShipCannon_120mm_HE_LG_shells_x7",
		"RC_ShipCannon_120mm_HE_LG_shells_x8",
		"RC_ShipCannon_120mm_HE_LG_shells_x9",
		"RC_ShipCannon_120mm_HE_LG_shells_x10",
		"RC_ShipCannon_120mm_HE_LG_shells_x11",
		"RC_ShipCannon_120mm_HE_LG_shells_x12",
		"RC_ShipCannon_120mm_HE_LG_shells_x13",
		"RC_ShipCannon_120mm_HE_LG_shells_x14",
		"RC_ShipCannon_120mm_HE_LG_shells_x15",
		"RC_ShipCannon_120mm_HE_LG_shells_x16",
		"RC_ShipCannon_120mm_HE_LG_shells_x17",
		"RC_ShipCannon_120mm_HE_LG_shells_x18",
		"RC_ShipCannon_120mm_HE_LG_shells_x19",
		"RC_ShipCannon_120mm_HE_LG_shells_x20",
		"RC_ShipCannon_120mm_HE_LG_shells_x21",
		"RC_ShipCannon_120mm_HE_LG_shells_x22",
		"RC_ShipCannon_120mm_HE_LG_shells_x23",
		"RC_ShipCannon_120mm_HE_LG_shells_x24",
		"RC_ShipCannon_120mm_HE_LG_shells_x25",
		"RC_ShipCannon_120mm_HE_LG_shells_x26",
		"RC_ShipCannon_120mm_HE_LG_shells_x27",
		"RC_ShipCannon_120mm_HE_LG_shells_x28",
		"RC_ShipCannon_120mm_HE_LG_shells_x29",
		"RC_ShipCannon_120mm_HE_LG_shells_x30",
		"RC_ShipCannon_120mm_HE_LG_shells_x31",
		"RC_ShipCannon_120mm_HE_LG_shells_x32",
		"RC_ShipCannon_120mm_HE_LG_shells_x33",
		"RC_ShipCannon_120mm_HE_LG_shells_x34",
		"RC_ShipCannon_120mm_HE_LG_shells_x35",
		"RC_ShipCannon_120mm_HE_LG_shells_x36",
		"RC_ShipCannon_120mm_HE_LG_shells_x37",
		"RC_ShipCannon_120mm_HE_LG_shells_x38",
		"RC_ShipCannon_120mm_HE_LG_shells_x39",
		"RC_ShipCannon_120mm_HE_LG_shells_x40",

		"RC_ShipCannon_120mm_HE_guided_shells_x1",
		"RC_ShipCannon_120mm_HE_guided_shells_x2",
		"RC_ShipCannon_120mm_HE_guided_shells_x3",
		"RC_ShipCannon_120mm_HE_guided_shells_x4",
		"RC_ShipCannon_120mm_HE_guided_shells_x5",
		"RC_ShipCannon_120mm_HE_guided_shells_x6",
		"RC_ShipCannon_120mm_HE_guided_shells_x7",
		"RC_ShipCannon_120mm_HE_guided_shells_x8",
		"RC_ShipCannon_120mm_HE_guided_shells_x9",
		"RC_ShipCannon_120mm_HE_guided_shells_x10",
		"RC_ShipCannon_120mm_HE_guided_shells_x11",
		"RC_ShipCannon_120mm_HE_guided_shells_x12",
		"RC_ShipCannon_120mm_HE_guided_shells_x13",
		"RC_ShipCannon_120mm_HE_guided_shells_x14",
		"RC_ShipCannon_120mm_HE_guided_shells_x15",
		"RC_ShipCannon_120mm_HE_guided_shells_x16",
		"RC_ShipCannon_120mm_HE_guided_shells_x17",
		"RC_ShipCannon_120mm_HE_guided_shells_x18",
		"RC_ShipCannon_120mm_HE_guided_shells_x19",
		"RC_ShipCannon_120mm_HE_guided_shells_x20",
		"RC_ShipCannon_120mm_HE_guided_shells_x21",
		"RC_ShipCannon_120mm_HE_guided_shells_x22",
		"RC_ShipCannon_120mm_HE_guided_shells_x23",
		"RC_ShipCannon_120mm_HE_guided_shells_x24",
		"RC_ShipCannon_120mm_HE_guided_shells_x25",
		"RC_ShipCannon_120mm_HE_guided_shells_x26",
		"RC_ShipCannon_120mm_HE_guided_shells_x27",
		"RC_ShipCannon_120mm_HE_guided_shells_x28",
		"RC_ShipCannon_120mm_HE_guided_shells_x29",
		"RC_ShipCannon_120mm_HE_guided_shells_x30",
		"RC_ShipCannon_120mm_HE_guided_shells_x31",
		"RC_ShipCannon_120mm_HE_guided_shells_x32",
		"RC_ShipCannon_120mm_HE_guided_shells_x33",
		"RC_ShipCannon_120mm_HE_guided_shells_x34",
		"RC_ShipCannon_120mm_HE_guided_shells_x35",
		"RC_ShipCannon_120mm_HE_guided_shells_x36",
		"RC_ShipCannon_120mm_HE_guided_shells_x37",
		"RC_ShipCannon_120mm_HE_guided_shells_x38",
		"RC_ShipCannon_120mm_HE_guided_shells_x39",
		"RC_ShipCannon_120mm_HE_guided_shells_x40",

		"RC_ShipCannon_120mm_mine_shells_x1",
		"RC_ShipCannon_120mm_mine_shells_x2",
		"RC_ShipCannon_120mm_mine_shells_x3",
		"RC_ShipCannon_120mm_mine_shells_x4",
		"RC_ShipCannon_120mm_mine_shells_x5",
		"RC_ShipCannon_120mm_mine_shells_x6",
		"RC_ShipCannon_120mm_mine_shells_x7",
		"RC_ShipCannon_120mm_mine_shells_x8",
		"RC_ShipCannon_120mm_mine_shells_x9",
		"RC_ShipCannon_120mm_mine_shells_x10",
		"RC_ShipCannon_120mm_mine_shells_x11",
		"RC_ShipCannon_120mm_mine_shells_x12",
		"RC_ShipCannon_120mm_mine_shells_x13",
		"RC_ShipCannon_120mm_mine_shells_x14",
		"RC_ShipCannon_120mm_mine_shells_x15",
		"RC_ShipCannon_120mm_mine_shells_x16",
		"RC_ShipCannon_120mm_mine_shells_x17",
		"RC_ShipCannon_120mm_mine_shells_x18",
		"RC_ShipCannon_120mm_mine_shells_x19",
		"RC_ShipCannon_120mm_mine_shells_x20",
		"RC_ShipCannon_120mm_mine_shells_x21",
		"RC_ShipCannon_120mm_mine_shells_x22",
		"RC_ShipCannon_120mm_mine_shells_x23",
		"RC_ShipCannon_120mm_mine_shells_x24",
		"RC_ShipCannon_120mm_mine_shells_x25",
		"RC_ShipCannon_120mm_mine_shells_x26",
		"RC_ShipCannon_120mm_mine_shells_x27",
		"RC_ShipCannon_120mm_mine_shells_x28",
		"RC_ShipCannon_120mm_mine_shells_x29",
		"RC_ShipCannon_120mm_mine_shells_x30",
		"RC_ShipCannon_120mm_mine_shells_x31",
		"RC_ShipCannon_120mm_mine_shells_x32",
		"RC_ShipCannon_120mm_mine_shells_x33",
		"RC_ShipCannon_120mm_mine_shells_x34",
		"RC_ShipCannon_120mm_mine_shells_x35",
		"RC_ShipCannon_120mm_mine_shells_x36",
		"RC_ShipCannon_120mm_mine_shells_x37",
		"RC_ShipCannon_120mm_mine_shells_x38",
		"RC_ShipCannon_120mm_mine_shells_x39",
		"RC_ShipCannon_120mm_mine_shells_x40",

		"RC_ShipCannon_120mm_AT_mine_shells_x1",
		"RC_ShipCannon_120mm_AT_mine_shells_x2",
		"RC_ShipCannon_120mm_AT_mine_shells_x3",
		"RC_ShipCannon_120mm_AT_mine_shells_x4",
		"RC_ShipCannon_120mm_AT_mine_shells_x5",
		"RC_ShipCannon_120mm_AT_mine_shells_x6",
		"RC_ShipCannon_120mm_AT_mine_shells_x7",
		"RC_ShipCannon_120mm_AT_mine_shells_x8",
		"RC_ShipCannon_120mm_AT_mine_shells_x9",
		"RC_ShipCannon_120mm_AT_mine_shells_x10",
		"RC_ShipCannon_120mm_AT_mine_shells_x11",
		"RC_ShipCannon_120mm_AT_mine_shells_x12",
		"RC_ShipCannon_120mm_AT_mine_shells_x13",
		"RC_ShipCannon_120mm_AT_mine_shells_x14",
		"RC_ShipCannon_120mm_AT_mine_shells_x15",
		"RC_ShipCannon_120mm_AT_mine_shells_x16",
		"RC_ShipCannon_120mm_AT_mine_shells_x17",
		"RC_ShipCannon_120mm_AT_mine_shells_x18",
		"RC_ShipCannon_120mm_AT_mine_shells_x19",
		"RC_ShipCannon_120mm_AT_mine_shells_x20",
		"RC_ShipCannon_120mm_AT_mine_shells_x21",
		"RC_ShipCannon_120mm_AT_mine_shells_x22",
		"RC_ShipCannon_120mm_AT_mine_shells_x23",
		"RC_ShipCannon_120mm_AT_mine_shells_x24",
		"RC_ShipCannon_120mm_AT_mine_shells_x25",
		"RC_ShipCannon_120mm_AT_mine_shells_x26",
		"RC_ShipCannon_120mm_AT_mine_shells_x27",
		"RC_ShipCannon_120mm_AT_mine_shells_x28",
		"RC_ShipCannon_120mm_AT_mine_shells_x29",
		"RC_ShipCannon_120mm_AT_mine_shells_x30",
		"RC_ShipCannon_120mm_AT_mine_shells_x31",
		"RC_ShipCannon_120mm_AT_mine_shells_x32",
		"RC_ShipCannon_120mm_AT_mine_shells_x33",
		"RC_ShipCannon_120mm_AT_mine_shells_x34",
		"RC_ShipCannon_120mm_AT_mine_shells_x35",
		"RC_ShipCannon_120mm_AT_mine_shells_x36",
		"RC_ShipCannon_120mm_AT_mine_shells_x37",
		"RC_ShipCannon_120mm_AT_mine_shells_x38",
		"RC_ShipCannon_120mm_AT_mine_shells_x39",
		"RC_ShipCannon_120mm_AT_mine_shells_x40",

		"RC_ShipCannon_120mm_HEAB_low_shells_x1",
		"RC_ShipCannon_120mm_HEAB_low_shells_x2",
		"RC_ShipCannon_120mm_HEAB_low_shells_x3",
		"RC_ShipCannon_120mm_HEAB_low_shells_x4",
		"RC_ShipCannon_120mm_HEAB_low_shells_x5",
		"RC_ShipCannon_120mm_HEAB_low_shells_x6",
		"RC_ShipCannon_120mm_HEAB_low_shells_x7",
		"RC_ShipCannon_120mm_HEAB_low_shells_x8",
		"RC_ShipCannon_120mm_HEAB_low_shells_x9",
		"RC_ShipCannon_120mm_HEAB_low_shells_x10",
		"RC_ShipCannon_120mm_HEAB_low_shells_x11",
		"RC_ShipCannon_120mm_HEAB_low_shells_x12",
		"RC_ShipCannon_120mm_HEAB_low_shells_x13",
		"RC_ShipCannon_120mm_HEAB_low_shells_x14",
		"RC_ShipCannon_120mm_HEAB_low_shells_x15",
		"RC_ShipCannon_120mm_HEAB_low_shells_x16",
		"RC_ShipCannon_120mm_HEAB_low_shells_x17",
		"RC_ShipCannon_120mm_HEAB_low_shells_x18",
		"RC_ShipCannon_120mm_HEAB_low_shells_x19",
		"RC_ShipCannon_120mm_HEAB_low_shells_x20",
		"RC_ShipCannon_120mm_HEAB_low_shells_x21",
		"RC_ShipCannon_120mm_HEAB_low_shells_x22",
		"RC_ShipCannon_120mm_HEAB_low_shells_x23",
		"RC_ShipCannon_120mm_HEAB_low_shells_x24",
		"RC_ShipCannon_120mm_HEAB_low_shells_x25",
		"RC_ShipCannon_120mm_HEAB_low_shells_x26",
		"RC_ShipCannon_120mm_HEAB_low_shells_x27",
		"RC_ShipCannon_120mm_HEAB_low_shells_x28",
		"RC_ShipCannon_120mm_HEAB_low_shells_x29",
		"RC_ShipCannon_120mm_HEAB_low_shells_x30",
		"RC_ShipCannon_120mm_HEAB_low_shells_x31",
		"RC_ShipCannon_120mm_HEAB_low_shells_x32",
		"RC_ShipCannon_120mm_HEAB_low_shells_x33",
		"RC_ShipCannon_120mm_HEAB_low_shells_x34",
		"RC_ShipCannon_120mm_HEAB_low_shells_x35",
		"RC_ShipCannon_120mm_HEAB_low_shells_x36",
		"RC_ShipCannon_120mm_HEAB_low_shells_x37",
		"RC_ShipCannon_120mm_HEAB_low_shells_x38",
		"RC_ShipCannon_120mm_HEAB_low_shells_x39",
		"RC_ShipCannon_120mm_HEAB_low_shells_x40",

		"RC_ShipCannon_120mm_HE_shells_x1",
		"RC_ShipCannon_120mm_HE_shells_x2",
		"RC_ShipCannon_120mm_HE_shells_x3",
		"RC_ShipCannon_120mm_HE_shells_x4",
		"RC_ShipCannon_120mm_HE_shells_x5",
		"RC_ShipCannon_120mm_HE_shells_x6",
		"RC_ShipCannon_120mm_HE_shells_x7",
		"RC_ShipCannon_120mm_HE_shells_x8",
		"RC_ShipCannon_120mm_HE_shells_x9",
		"RC_ShipCannon_120mm_HE_shells_x10",
		"RC_ShipCannon_120mm_HE_shells_x11",
		"RC_ShipCannon_120mm_HE_shells_x12",
		"RC_ShipCannon_120mm_HE_shells_x13",
		"RC_ShipCannon_120mm_HE_shells_x14",
		"RC_ShipCannon_120mm_HE_shells_x15",
		"RC_ShipCannon_120mm_HE_shells_x16",
		"RC_ShipCannon_120mm_HE_shells_x17",
		"RC_ShipCannon_120mm_HE_shells_x18",
		"RC_ShipCannon_120mm_HE_shells_x19",
		"RC_ShipCannon_120mm_HE_shells_x20",
		"RC_ShipCannon_120mm_HE_shells_x21",
		"RC_ShipCannon_120mm_HE_shells_x22",
		"RC_ShipCannon_120mm_HE_shells_x23",
		"RC_ShipCannon_120mm_HE_shells_x24",
		"RC_ShipCannon_120mm_HE_shells_x25",
		"RC_ShipCannon_120mm_HE_shells_x26",
		"RC_ShipCannon_120mm_HE_shells_x27",
		"RC_ShipCannon_120mm_HE_shells_x28",
		"RC_ShipCannon_120mm_HE_shells_x29",
		"RC_ShipCannon_120mm_HE_shells_x30",
		"RC_ShipCannon_120mm_HE_shells_x31",
		"RC_ShipCannon_120mm_HE_shells_x32",
		"RC_ShipCannon_120mm_HE_shells_x33",
		"RC_ShipCannon_120mm_HE_shells_x34",
		"RC_ShipCannon_120mm_HE_shells_x35",
		"RC_ShipCannon_120mm_HE_shells_x36",
		"RC_ShipCannon_120mm_HE_shells_x37",
		"RC_ShipCannon_120mm_HE_shells_x38",
		"RC_ShipCannon_120mm_HE_shells_x39",
		"RC_ShipCannon_120mm_HE_shells_x40",

		"RC_ShipCannon_120mm_Illum_shells_x1",
		"RC_ShipCannon_120mm_Illum_shells_x2",
		"RC_ShipCannon_120mm_Illum_shells_x3",
		"RC_ShipCannon_120mm_Illum_shells_x4",
		"RC_ShipCannon_120mm_Illum_shells_x5",
		"RC_ShipCannon_120mm_Illum_shells_x6",
		"RC_ShipCannon_120mm_Illum_shells_x7",
		"RC_ShipCannon_120mm_Illum_shells_x8",
		"RC_ShipCannon_120mm_Illum_shells_x9",
		"RC_ShipCannon_120mm_Illum_shells_x10",
		"RC_ShipCannon_120mm_Illum_shells_x11",
		"RC_ShipCannon_120mm_Illum_shells_x12",
		"RC_ShipCannon_120mm_Illum_shells_x13",
		"RC_ShipCannon_120mm_Illum_shells_x14",
		"RC_ShipCannon_120mm_Illum_shells_x15",
		"RC_ShipCannon_120mm_Illum_shells_x16",
		"RC_ShipCannon_120mm_Illum_shells_x17",
		"RC_ShipCannon_120mm_Illum_shells_x18",
		"RC_ShipCannon_120mm_Illum_shells_x19",
		"RC_ShipCannon_120mm_Illum_shells_x20",
		"RC_ShipCannon_120mm_Illum_shells_x21",
		"RC_ShipCannon_120mm_Illum_shells_x22",
		"RC_ShipCannon_120mm_Illum_shells_x23",
		"RC_ShipCannon_120mm_Illum_shells_x24",
		"RC_ShipCannon_120mm_Illum_shells_x25",
		"RC_ShipCannon_120mm_Illum_shells_x26",
		"RC_ShipCannon_120mm_Illum_shells_x27",
		"RC_ShipCannon_120mm_Illum_shells_x28",
		"RC_ShipCannon_120mm_Illum_shells_x29",
		"RC_ShipCannon_120mm_Illum_shells_x30",
		"RC_ShipCannon_120mm_Illum_shells_x31",
		"RC_ShipCannon_120mm_Illum_shells_x32",
		"RC_ShipCannon_120mm_Illum_shells_x33",
		"RC_ShipCannon_120mm_Illum_shells_x34",
		"RC_ShipCannon_120mm_Illum_shells_x35",
		"RC_ShipCannon_120mm_Illum_shells_x36",
		"RC_ShipCannon_120mm_Illum_shells_x37",
		"RC_ShipCannon_120mm_Illum_shells_x38",
		"RC_ShipCannon_120mm_Illum_shells_x39",
		"RC_ShipCannon_120mm_Illum_shells_x40",

		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x1",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x2",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x3",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x4",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x5",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x6",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x7",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x8",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x9",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x10",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x11",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x12",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x13",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x14",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x15",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x16",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x17",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x18",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x19",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x20",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x21",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x22",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x23",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x24",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x25",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x26",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x27",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x28",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x29",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x30",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x31",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x32",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x33",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x34",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x35",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x36",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x37",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x38",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x39",
		"RC_ShipCannon_120mm_HE_LG_DelayedFuse_shells_x40"
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
		"Single8",
		"Single9",

		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4",
		"Burst5"
	};

	class Single1: Single1
	{
		displayName="CH0"
		artilleryCharge=0.1479;
	};
	class Single2: Single1
	{
		displayName="CH1"
		artilleryCharge=0.1878;
	};
	class Single3: Single1
	{
		displayName="CH2"
		artilleryCharge=0.2385;
	};
	class Single4: Single1
	{
		displayName="CH3"
		artilleryCharge=0.3029;
	};
	class Single5: Single1
	{
		displayName="CH4"
		artilleryCharge=0.3846;
	};
	class Single6: Single1
	{
		displayName="CH5"
		artilleryCharge=0.4884;
	};
	class Single7: Single1
	{
		displayName="CH6"
		artilleryCharge=0.6201;
	};
	class Single8: Single1
	{
		displayName="CH7"
		artilleryCharge=0.7875;
	};
	class Single9: Single1
	{
		displayName="CH8 direct"
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
	class Single9: Single9
	{
		artilleryDispersion=2;
	};
};


//120mm NLOS FSV, roughly 4km indirect range with its cannon elevation
class RC_FSV_120mm_V5: RC_ShipCannon_120mm_V4
{
		magazines[]=
	{
		"RC_FSV_120mm_HEAB_x1",
		"RC_FSV_120mm_HEAB_x2",
		"RC_FSV_120mm_HEAB_x3",
		"RC_FSV_120mm_HEAB_x4",
		"RC_FSV_120mm_HEAB_x5",
		"RC_FSV_120mm_HEAB_x6",
		"RC_FSV_120mm_HEAB_x7",
		"RC_FSV_120mm_HEAB_x8",
		"RC_FSV_120mm_HEAB_x9",
		"RC_FSV_120mm_HEAB_x10",
		"RC_FSV_120mm_HEAB_x11",
		"RC_FSV_120mm_HEAB_x12",

		"RC_FSV_120mm_smoke_x1",
		"RC_FSV_120mm_smoke_x2",
		"RC_FSV_120mm_smoke_x3",
		"RC_FSV_120mm_smoke_x4",
		"RC_FSV_120mm_smoke_x5",
		"RC_FSV_120mm_smoke_x6",
		"RC_FSV_120mm_smoke_x7",
		"RC_FSV_120mm_smoke_x8",
		"RC_FSV_120mm_smoke_x9",
		"RC_FSV_120mm_smoke_x10",
		"RC_FSV_120mm_smoke_x11",
		"RC_FSV_120mm_smoke_x12",

		"RC_FSV_120mm_MT_MultiGuided_x1",
		"RC_FSV_120mm_MT_MultiGuided_x2",
		"RC_FSV_120mm_MT_MultiGuided_x3",
		"RC_FSV_120mm_MT_MultiGuided_x4",
		"RC_FSV_120mm_MT_MultiGuided_x5",
		"RC_FSV_120mm_MT_MultiGuided_x6",
		"RC_FSV_120mm_MT_MultiGuided_x7",
		"RC_FSV_120mm_MT_MultiGuided_x8",
		"RC_FSV_120mm_MT_MultiGuided_x9",
		"RC_FSV_120mm_MT_MultiGuided_x10",
		"RC_FSV_120mm_MT_MultiGuided_x11",
		"RC_FSV_120mm_MT_MultiGuided_x12",

		"RC_FSV_120mm_HE_LG_DelayedFuse_x1",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x2",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x3",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x4",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x5",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x6",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x7",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x8",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x9",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x10",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x11",
		"RC_FSV_120mm_HE_LG_DelayedFuse_x12"
	};

	modes[]=
	{
		"Single1",
		"Single2",
		"Single3",
		"Single4",

		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4"
	};

	class Single1: Single1
	{
		displayName="CH0"
		artilleryCharge=0.3845;
	};
	class Single2: Single1
	{
		displayName="CH1"
		artilleryCharge=0.4883;
	};
	class Single3: Single1
	{
		displayName="CH2"
		artilleryCharge=0.6201;
	};
	class Single4: Single1
	{
		displayName="CH3"
		artilleryCharge=0.7875;
	};
	class Single5: Single1
	{
		displayName="CH4"
		artilleryCharge=1;
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
};
class RC_155mm_AMOS_V1: RC_155mm_AMOS_base
{
	magazines[]=
	{
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

		"RC_1Rnd_155mm_Mo_LG",
		"RC_2Rnd_155mm_Mo_LG",
		"RC_3Rnd_155mm_Mo_LG",
		"RC_4Rnd_155mm_Mo_LG",
		"RC_5Rnd_155mm_Mo_LG",
		"RC_6Rnd_155mm_Mo_LG",
		"RC_7Rnd_155mm_Mo_LG",
		"RC_8Rnd_155mm_Mo_LG",
		"RC_9Rnd_155mm_Mo_LG",
		"RC_10Rnd_155mm_Mo_LG",
		"RC_11Rnd_155mm_Mo_LG",
		"RC_12Rnd_155mm_Mo_LG",
		"RC_13Rnd_155mm_Mo_LG",
		"RC_14Rnd_155mm_Mo_LG",
		"RC_15Rnd_155mm_Mo_LG",
		"RC_16Rnd_155mm_Mo_LG",
		"RC_17Rnd_155mm_Mo_LG",
		"RC_18Rnd_155mm_Mo_LG",
		"RC_19Rnd_155mm_Mo_LG",
		"RC_20Rnd_155mm_Mo_LG",
		"RC_21Rnd_155mm_Mo_LG",
		"RC_22Rnd_155mm_Mo_LG",
		"RC_23Rnd_155mm_Mo_LG",
		"RC_24Rnd_155mm_Mo_LG",
		"RC_25Rnd_155mm_Mo_LG",
		"RC_26Rnd_155mm_Mo_LG",
		"RC_27Rnd_155mm_Mo_LG",
		"RC_28Rnd_155mm_Mo_LG",
		"RC_29Rnd_155mm_Mo_LG",
		"RC_30Rnd_155mm_Mo_LG",
		"RC_31Rnd_155mm_Mo_LG",
		"RC_32Rnd_155mm_Mo_LG",
		"RC_33Rnd_155mm_Mo_LG",
		"RC_34Rnd_155mm_Mo_LG",
		"RC_35Rnd_155mm_Mo_LG",
		"RC_36Rnd_155mm_Mo_LG",
		"RC_37Rnd_155mm_Mo_LG",
		"RC_38Rnd_155mm_Mo_LG",
		"RC_39Rnd_155mm_Mo_LG",
		"RC_40Rnd_155mm_Mo_LG",

		"RC_1Rnd_155mm_Mo_guided",
		"RC_2Rnd_155mm_Mo_guided",
		"RC_3Rnd_155mm_Mo_guided",
		"RC_4Rnd_155mm_Mo_guided",
		"RC_5Rnd_155mm_Mo_guided",
		"RC_6Rnd_155mm_Mo_guided",
		"RC_7Rnd_155mm_Mo_guided",
		"RC_8Rnd_155mm_Mo_guided",
		"RC_9Rnd_155mm_Mo_guided",
		"RC_10Rnd_155mm_Mo_guided",
		"RC_11Rnd_155mm_Mo_guided",
		"RC_12Rnd_155mm_Mo_guided",
		"RC_13Rnd_155mm_Mo_guided",
		"RC_14Rnd_155mm_Mo_guided",
		"RC_15Rnd_155mm_Mo_guided",
		"RC_16Rnd_155mm_Mo_guided",
		"RC_17Rnd_155mm_Mo_guided",
		"RC_18Rnd_155mm_Mo_guided",
		"RC_19Rnd_155mm_Mo_guided",
		"RC_20Rnd_155mm_Mo_guided",
		"RC_21Rnd_155mm_Mo_guided",
		"RC_22Rnd_155mm_Mo_guided",
		"RC_23Rnd_155mm_Mo_guided",
		"RC_24Rnd_155mm_Mo_guided",
		"RC_25Rnd_155mm_Mo_guided",
		"RC_26Rnd_155mm_Mo_guided",
		"RC_27Rnd_155mm_Mo_guided",
		"RC_28Rnd_155mm_Mo_guided",
		"RC_29Rnd_155mm_Mo_guided",
		"RC_30Rnd_155mm_Mo_guided",
		"RC_31Rnd_155mm_Mo_guided",
		"RC_32Rnd_155mm_Mo_guided",
		"RC_33Rnd_155mm_Mo_guided",
		"RC_34Rnd_155mm_Mo_guided",
		"RC_35Rnd_155mm_Mo_guided",
		"RC_36Rnd_155mm_Mo_guided",
		"RC_37Rnd_155mm_Mo_guided",
		"RC_38Rnd_155mm_Mo_guided",
		"RC_39Rnd_155mm_Mo_guided",
		"RC_40Rnd_155mm_Mo_guided",

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

		"RC_1Rnd_155mm_Mo_HEAB_low",
		"RC_2Rnd_155mm_Mo_HEAB_low",
		"RC_3Rnd_155mm_Mo_HEAB_low",
		"RC_4Rnd_155mm_Mo_HEAB_low",
		"RC_5Rnd_155mm_Mo_HEAB_low",
		"RC_6Rnd_155mm_Mo_HEAB_low",
		"RC_7Rnd_155mm_Mo_HEAB_low",
		"RC_8Rnd_155mm_Mo_HEAB_low",
		"RC_9Rnd_155mm_Mo_HEAB_low",
		"RC_10Rnd_155mm_Mo_HEAB_low",
		"RC_11Rnd_155mm_Mo_HEAB_low",
		"RC_12Rnd_155mm_Mo_HEAB_low",
		"RC_13Rnd_155mm_Mo_HEAB_low",
		"RC_14Rnd_155mm_Mo_HEAB_low",
		"RC_15Rnd_155mm_Mo_HEAB_low",
		"RC_16Rnd_155mm_Mo_HEAB_low",
		"RC_17Rnd_155mm_Mo_HEAB_low",
		"RC_18Rnd_155mm_Mo_HEAB_low",
		"RC_19Rnd_155mm_Mo_HEAB_low",
		"RC_20Rnd_155mm_Mo_HEAB_low",
		"RC_21Rnd_155mm_Mo_HEAB_low",
		"RC_22Rnd_155mm_Mo_HEAB_low",
		"RC_23Rnd_155mm_Mo_HEAB_low",
		"RC_24Rnd_155mm_Mo_HEAB_low",
		"RC_25Rnd_155mm_Mo_HEAB_low",
		"RC_26Rnd_155mm_Mo_HEAB_low",
		"RC_27Rnd_155mm_Mo_HEAB_low",
		"RC_28Rnd_155mm_Mo_HEAB_low",
		"RC_29Rnd_155mm_Mo_HEAB_low",
		"RC_30Rnd_155mm_Mo_HEAB_low",
		"RC_31Rnd_155mm_Mo_HEAB_low",
		"RC_32Rnd_155mm_Mo_HEAB_low",
		"RC_33Rnd_155mm_Mo_HEAB_low",
		"RC_34Rnd_155mm_Mo_HEAB_low",
		"RC_35Rnd_155mm_Mo_HEAB_low",
		"RC_36Rnd_155mm_Mo_HEAB_low",
		"RC_37Rnd_155mm_Mo_HEAB_low",
		"RC_38Rnd_155mm_Mo_HEAB_low",
		"RC_39Rnd_155mm_Mo_HEAB_low",
		"RC_40Rnd_155mm_Mo_HEAB_low",

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

		"RC_20Rnd_155mm_Mo_HEAB_backup1",
		"RC_20Rnd_155mm_Mo_HEAB_backup2",
		"RC_20Rnd_155mm_Mo_HEAB_backup3"
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
		"Single8",
		"Single9",

		"Burst1",
		"Burst2",
		"Burst3",
		"Burst4",
		"Burst5"
	};

	class Single1: Single1
	{
		displayName="CH0"
		artilleryCharge=0.1479;
	};
	class Single2: Single1
	{
		displayName="CH1"
		artilleryCharge=0.1878;
	};
	class Single3: Single1
	{
		displayName="CH2"
		artilleryCharge=0.2385;
	};
	class Single4: Single1
	{
		displayName="CH3"
		artilleryCharge=0.3029;
	};
	class Single5: Single1
	{
		displayName="CH4"
		artilleryCharge=0.3846;
	};
	class Single6: Single1
	{
		displayName="CH5"
		artilleryCharge=0.4884;
	};
	class Single7: Single1
	{
		displayName="CH6"
		artilleryCharge=0.6201;
	};
	class Single8: Single1
	{
		displayName="CH7"
		artilleryCharge=0.7875;
	};
	class Single9: Single1
	{
		displayName="CH8 direct"
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
	class Single9: Single9
	{
		artilleryDispersion=2;
	};
};


// 230mm MLRS/MRL Rockets/Missles
class rockets_230mm_GAT;
class RC_rockets_230mm_GAT: rockets_230mm_GAT
{
	magazineReloadTime=1;
	ballisticsComputer=8;
	canLock=2;
	weaponLockDelay=0;

	magazines[]=
	{
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
		"RC_2Rnd_604mm_rockets_ATACMS_DPICM"
	};
};