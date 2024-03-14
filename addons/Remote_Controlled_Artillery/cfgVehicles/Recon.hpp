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
	RCDisableSeats=1; // locks driver seat
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
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";
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
			gunnerCompartments="Compartment2";
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
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
						*/
					};
				};
			};
		};
	};

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
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
	class Components;
	class SensorsManagerComponent;
	class SensorTemplateDataLink;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	forceHideDriver=1;
	RCDisableSeats=6; // locks gunner and commander seat
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	
};
class RC_radar_small_WD: RC_radar_small_base
{
	/*
	//for later use
	class EventHandlers
	{
		init="(_this select 0) spawn {};";
	};
	*/
	displayName="RC Recon Radar";
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
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	redRpm=1100;
	idleRpm=250;

	class Components: Components
	{
		class SensorsManagerComponent: SensorsManagerComponent
		{
			class Components: Components
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
			};
		};
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
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="EmptyDisplay";

			class Components
			{
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoMiniMap";
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerCompartments="Compartment2";
			showAllTargets="2 + 4";
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

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
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


//Recon RADAR with Vehicle Mortar attached, for low power but mobile indirect fire support
class RC_Mortar_Carrier_WD: RC_radar_small_WD
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
	};

	displayName="RC Mortar Carrier";
	editorSubcategory="RC_Mortar_subcat";
};
class RC_Mortar_Carrier_WD_O: RC_Mortar_Carrier_WD
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
	};

	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Mortar_Carrier_DIG_I: RC_Mortar_Carrier_WD
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
	};

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
class RC_Mortar_Carrier_WD_I: RC_Mortar_Carrier_WD
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]];};";
	};

	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


//semi manned version
class RC_Mortar_Carrier_Manned_WD: RC_Mortar_Carrier_WD
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar', west] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]]; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;};";
	};

	displayName="Mortar Carrier";
};
class RC_Mortar_Carrier_Manned_WD_O: RC_Mortar_Carrier_WD_O
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_O', east] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]]; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;};";
	};

	displayName="Mortar Carrier";
};
class RC_Mortar_Carrier_Manned_DIG_I: RC_Mortar_Carrier_DIG_I
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]]; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;};";
	};

	displayName="Mortar Carrier";
};
class RC_Mortar_Carrier_Manned_WD_I: RC_Mortar_Carrier_WD_I
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {(([[0,0,0], (getDir _this), 'RC_VehicleMortar_I', resistance] call BIS_fnc_spawnVehicle) select 0) attachTo [_this, [0.0151367, -0.959518, 0.6475]]; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;};";
	};

	displayName="Mortar Carrier";
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
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RCDisableSeats=1; // locks driver seat
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
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="B_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";
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
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
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
			gunnerCompartments="Compartment2";
			showAllTargets="2 + 4";
			gunnerForceOptics=1;
			forceHideGunner=1;

			class ViewOptics: ViewOptics
			{
				initFov=0.89999998;
				minFov=0.0125;
				maxFov=0.89999998;
			};

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
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
						*/
					};
				};
			};
		};
	};

	class TransportMagazines
	{
	};
	class TransportItems
	{
		class _xx_Toolkit
		{
			name="Toolkit";
			count=2;
		};
		class _xx_Medikit
		{
			name="Medikit";
			count=5;
		};
		class _xx_FirstAidKit
		{
			name="FirstAidKit";
			count=5;
		};
	};
	class TransportWeapons
	{
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
	displayName="RC stabilized Recon ATGM 4.5km";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			stabilizedInAxes=3;

			class ViewOptics: ViewOptics
			{
				directionStabilized=1;
			};
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


//semi manned version
class RC_ATGM_small_S_Manned_WD: RC_ATGM_small_WD
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this;};";
	};

	displayName="stabilized Recon ATGM 4.5km";
};
class RC_ATGM_small_S_Manned_WD_O: RC_ATGM_small_S_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_ATGM_small_S_Manned_DIG_I: RC_ATGM_small_S_WD
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
class RC_ATGM_small_S_Manned_WD_I: RC_ATGM_small_S_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};