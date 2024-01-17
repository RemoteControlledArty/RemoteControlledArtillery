//Nyx / Wiesel
class I_LT_01_AA_F;
class RC_AA_small_base: I_LT_01_AA_F
{
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class HitPoints;
	class HitEngine;
	class Components;
	scope=0;
	scopeCurator=0;
	RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0]
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_AA_small_WD: RC_AA_small_base
{
	displayName="RC Recon Anti-Air";
	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiAir_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;

	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	redRpm=1100;
	idleRpm=250;

	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	incomingMissileDetectionSystem=16;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class ActiveRadarSensorComponent: SensorTemplateActiveRadar
				{
					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					typeRecognitionDistance=4000;
					angleRangeHorizontal=360;
					angleRangeVertical=100;
					aimDown=-45;
					maxTrackableSpeed=694.44397;
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
					typeRecognitionDistance=6000;

					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1500;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
				};
			};
		};
	};

	class HitPoints: HitPoints
	{
		class HitEngine: HitEngine
		{
			armor=-60;
		};
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showSLATHull",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			forceHideGunner=1;

			class ViewOptics: ViewOptics
			{
				initFov=0.89999998;
				minFov=0.0125;
				maxFov=0.89999998;
			};

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
							range[]={8000,4000,2000,1000};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_olive_co.paa"
	};
};
class RC_AA_small_WD_O: RC_AA_small_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_AA_small_DIG_I: RC_AA_small_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_AA_small_WD_I: RC_AA_small_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	hiddenSelectionsTextures[]=
	{
	"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
	"A3\armor_f_tank\lt_01\data\lt_01_at_co.paa",
	"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
	"A3\armor_f\data\cage_aaf_co.paa"
	};
};


class I_LT_01_scout_F;
class RC_radar_small_base: I_LT_01_scout_F
{
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class Turrets;
	class MainTurret;
	class HitPoints;
	class HitEngine;
	//class ViewOptics;
	scope=0;
	scopeCurator=0;
	forceHideDriver=1;
	RCDisableSeats=3; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0]
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	
};
class RC_radar_small_WD: RC_radar_small_base
{
	displayName="RC Recon Radar";
	//faction="RemoteControlled_B";		//radar activation has to be fixed first
	//editorSubcategory="RC_AntiAir_subcat";	//radar activation has to be fixed first
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;

	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	redRpm=1100;
	idleRpm=250;

	//class EventHandlers
	//{
	//	init="(_this select 0) spawn {if (local _this) then {_this setVehicleRadar 1};};";
	//};

	class HitPoints: HitPoints
	{
		class HitEngine: HitEngine
		{
			armor=-60;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			forceHideGunner=1;
		};
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showSLATHull: showSLATHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showSLATHull",
		1
	};

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_radar_olive_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_olive_co.paa"
	};
};
class RC_radar_small_WD_O: RC_radar_small_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_radar_small_DIG_I: RC_radar_small_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_radar_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
};
class RC_radar_small_WD_I: RC_radar_small_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class I_LT_01_AT_F;
class RC_ATGM_small_base: I_LT_01_AT_F
{
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class HitPoints;
	class HitEngine;
	class Components;
	scope=0;
	scopeCurator=0;
	RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0]
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_ATGM_small_WD: RC_ATGM_small_base
{
	displayName="RC Recon ATGM 4.5km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_ATGM_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;

	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	redRpm=1100;
	idleRpm=250;

	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	incomingMissileDetectionSystem=16;
	//laserScanner=0;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
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
					typeRecognitionDistance=1500;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=750;

					class AirTarget
					{
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
				};
			};
		};
	};

	class HitPoints: HitPoints
	{
		class HitEngine: HitEngine
		{
			armor=-60;
		};
	};

	class AnimationSources: AnimationSources
	{
		class HitSLAT_Left_1_src
		{
			source="Hit";
			hitpoint="HitSLAT_Left_1";
			raw=1;
		};
		class HitSLAT_Left_2_src
		{
			source="Hit";
			hitpoint="HitSLAT_Left_2";
			raw=1;
		};
		class HitSLAT_Left_3_src
		{
			source="Hit";
			hitpoint="HitSLAT_Left_3";
			raw=1;
		};
		class HitSLAT_Right_1_src
		{
			source="Hit";
			hitpoint="HitSLAT_Right_1";
			raw=1;
		};
		class HitSLAT_Right_2_src
		{
			source="Hit";
			hitpoint="HitSLAT_Right_2";
			raw=1;
		};
		class HitSLAT_Right_3_src
		{
			source="Hit";
			hitpoint="HitSLAT_Right_3";
			raw=1;
		};
		class HitSLAT_back_src
		{
			source="Hit";
			hitpoint="HitSLAT_back";
			raw=1;
		};
		class HitSLAT_front_src
		{
			source="Hit";
			hitpoint="HitSLAT_front";
			raw=1;
		};
		class showCamonetPlates1
		{
			source="user";
			animPeriod=0.001;
			initPhase=0;
		};
		class showCamonetPlates2
		{
			source="user";
			animPeriod=0.001;
			initPhase=0;
		};
		class showCamonetHull
		{
			displayName="$STR_A3_animationsources_showcamonethull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			forceAnimatePhase=1;
			forceAnimate[]=
			{
				"showCamonetPlates1",
				1,
				"showCamonetPlates2",
				1
			};
			forceAnimate2[]=
			{
				"showCamonetPlates1",
				0,
				"showCamonetPlates2",
				0
			};
			initPhase=1;
			mass=-50;
		};
		class showSLATHull
		{
			displayName="$STR_A3_animationsources_showslathull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=1;
			mass=-50;
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;
			forceHideGunner=1;

			class ViewOptics: ViewOptics
			{
				initFov=0.89999998;
				minFov=0.0125;
				maxFov=0.89999998;
			};

			//showAllTargets="2 + 4";

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
							range[]={4500,2000,1000,500,250};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
		"A3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_olive_co.paa"
	};
};
class RC_ATGM_small_WD_O: RC_ATGM_small_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_ATGM_small_DIG_I: RC_ATGM_small_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	hiddenSelectionsTextures[]=
	{
	"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
	"A3\armor_f_tank\lt_01\data\lt_01_at_co.paa",
	"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
	"A3\armor_f\data\cage_aaf_co.paa"
	};
};
class RC_ATGM_small_WD_I: RC_ATGM_small_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};



class RC_ATGM_small_S_WD: RC_ATGM_small_WD
{
	displayName="RC Recon stabilized ATGM 4.5km";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			stabilizedInAxes=3;
		};
	};
};
class RC_ATGM_small_S_WD_O: RC_ATGM_small_S_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_ATGM_small_S_DIG_I: RC_ATGM_small_S_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	hiddenSelectionsTextures[]=
	{
	"A3\armor_f_tank\lt_01\data\lt_01_main_co.paa",
	"A3\armor_f_tank\lt_01\data\lt_01_at_co.paa",
	"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
	"A3\armor_f\data\cage_aaf_co.paa"
	};
};
class RC_ATGM_small_S_WD_I: RC_ATGM_small_S_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};