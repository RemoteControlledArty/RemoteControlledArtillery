//MLRS
class B_MBT_01_mlrs_F;
class RC_MLRS_base: B_MBT_01_mlrs_F
{
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetHull;
	class showCamonetPlates1;
	class showCamonetPlates2;
	class Turrets;
	class MainTurret;
	class OpticsIn;
	class Wide;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=4; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=1.75;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=3.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_MLRS_A: RC_MLRS_base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	displayName="RC MLRS";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Rocket_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
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

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_CO.paa",
		"A3\armor_f_gamma\MBT_01\data\MBT_01_MLRS_co.paa",
		"Remote_Controlled_Artillery\textures\camonet_tan_CO.paa"
	};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
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
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_rockets_230mm_GAT";
		};
		class muzzle_hide_missiles
		{
			source="reload";
			weapon="RC_rockets_230mm_GAT";
		};
		class showCamonetPlates1: showCamonetPlates1
		{
			initPhase=1;
		};
		class showCamonetPlates2: showCamonetPlates2
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetTurret",
		0,
		"showCamonetHull",
		0
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerCompartments="Compartment2";
			gunnerForceOptics=1;
			stabilizedInAxes=3;
			weapons[]=
			{
				"RC_rockets_230mm_GAT"
			};
			magazines[]=
			{
				"RC_6Rnd_230mm_rockets_HEAB",
				"RC_4Rnd_230mm_rockets_MultiGuided",
				"RC_2Rnd_230mm_rockets_cluster"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.125;
					minFov=0.0125;
					maxFov=0.89999998;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
				};
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
							range[]={30000,20000,10000,5000,2500,67000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

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

	//#include "\Remote_Controlled_Artillery\loadouts\Artyitems.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MLRS_WD: RC_MLRS_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_mlrs_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_MLRS_olive_co.paa",
		//"A3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MLRS_A_O: RC_MLRS_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MLRS_WD_O: RC_MLRS_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MLRS_A_I: RC_MLRS_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_MLRS_WD_I: RC_MLRS_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//MLRS ATACMS
class RC_MLRS_ATACMS_A: RC_MLRS_A
{
	displayName="RC MLRS ATACMS";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_rockets_230mm_GAT"
			};
			magazines[]=
			{
				"RC_1Rnd_604mm_rockets_ATACMS_HEAB",
				"RC_1Rnd_604mm_rockets_ATACMS_DPICM"
			};
		};
	};
};
class RC_MLRS_ATACMS_WD: RC_MLRS_ATACMS_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_mlrs_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_MLRS_olive_co.paa",
		//"A3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_MLRS_ATACMS_A_O: RC_MLRS_ATACMS_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MLRS_ATACMS_WD_O: RC_MLRS_ATACMS_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MLRS_ATACMS_A_I: RC_MLRS_ATACMS_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_MLRS_ATACMS_WD_I: RC_MLRS_ATACMS_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//MRL
class I_Truck_02_MRL_F;
class RC_MRL_base: I_Truck_02_MRL_F
{
	class AnimationSources;
	class Turrets;
	class MainTurret;
	class OpticsIn;
	class Wide;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=4; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=1.65;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=3.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_MRL_DIG_I: RC_MRL_base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		/*
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
		*/
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	displayName="RC MRL";
	faction="RemoteControlled_I";
	editorSubcategory="RC_Rocket_subcat";
	scope=2;
	scopeCurator=2;
	side=2;
	forceInGarage=1;
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP1_pos";
	uavCameraGunnerDir="PiP1_dir";
	crew="I_UAV_AI";
	driverForceOptics=1;
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	enableGPS=1;
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
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
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class Missiles_revolving
		{
			source="revolving";
			weapon="RC_rockets_230mm_GAT";
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerCompartments="Compartment2";
			lockWhenVehicleSpeed=-1;
			gunnerForceOptics=1;
			stabilizedInAxes=3;

			weapons[]=
			{
				"RC_rockets_230mm_GAT"
			};
			magazines[]=
			{
				"RC_6Rnd_230mm_rockets_HEAB",
				"RC_4Rnd_230mm_rockets_MultiGuided",
				"RC_2Rnd_230mm_rockets_cluster"
			};
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					initFov=0.125;
					minFov=0.0125;
					maxFov=0.89999998;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
				};
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
							range[]={30000,20000,10000,5000,2500,67000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplayComponent";

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

	//#include "\Remote_Controlled_Artillery\loadouts\Artyitems.hpp"
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_MRL_WD_I: RC_MRL_DIG_I
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_Truck_02_MRL_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_kab_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_int_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_mrl_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\truck_02_chassis_EAF_CO.paa"
	};
};
class RC_MRL_WD: RC_MRL_WD_I
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_WD_O: RC_MRL_WD_I
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MRL_HEX_O: RC_MRL_DIG_I
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_kab_OPFOR_CO.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_int_CO.paa",
		"\A3\Soft_F_Gamma\Truck_02\Data\Truck_02_MRL_OPFOR_CO.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_OPFOR_CO.paa"
	};
};


//MRL ATACMS
class RC_MRL_ATACMS_DIG_I: RC_MRL_DIG_I
{
	displayName="RC MRL ATACMS";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_rockets_230mm_GAT"
			};
			magazines[]=
			{
				"RC_1Rnd_604mm_rockets_ATACMS_HEAB",
				"RC_1Rnd_604mm_rockets_ATACMS_DPICM"
			};
		};
	};
};
class RC_MRL_ATACMS_WD_I: RC_MRL_ATACMS_DIG_I
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_Truck_02_MRL_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_kab_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_int_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\Truck_02_mrl_EAF_co.paa",
		"\A3\soft_f_Enoch\Truck_02\Data\truck_02_chassis_EAF_CO.paa"
	};
};
class RC_MRL_ATACMS_WD: RC_MRL_ATACMS_WD_I
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_ATACMS_WD_O: RC_MRL_ATACMS_WD_I
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MRL_ATACMS_HEX_O: RC_MRL_ATACMS_DIG_I
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_kab_OPFOR_CO.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_int_CO.paa",
		"\A3\Soft_F_Gamma\Truck_02\Data\Truck_02_MRL_OPFOR_CO.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_OPFOR_CO.paa"
	};
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_MLRS_ReTex_D: RC_MLRS_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"merkava\data\mbt_01_body_d.paa",
		"merkava\data\mbt_01_mlrs_d.paa",
		"merkava\data\camonet_desert_co.paa"
	};
};
class RC_MLRS_ReTex_D_O: RC_MLRS_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MLRS_ReTex_D_I: RC_MLRS_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_MLRS_ATACMS_ReTex_D: RC_MLRS_ATACMS_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"merkava\data\mbt_01_body_d.paa",
		"merkava\data\mbt_01_mlrs_d.paa",
		"merkava\data\camonet_desert_co.paa"
	};
};
class RC_MLRS_ATACMS_ReTex_D_O: RC_MLRS_ATACMS_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_MLRS_ATACMS_ReTex_D_I: RC_MLRS_ATACMS_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_MRL_ReTex_WD_I: RC_MRL_DIG_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_Truck_02_MRL_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"iveco\data\iveco_front_wd.paa",
		"a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"iveco\data\truck_02_mrl_wd_co.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_CO.paa"
	};
};
class RC_MRL_ReTex_WD: RC_MRL_ReTex_WD_I
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_ReTex_WD_O: RC_MRL_ReTex_WD_I
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};


class RC_MRL_ReTex_D_I: RC_MRL_DIG_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"iveco\data\iveco_front_d.paa",
		"a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"iveco\data\truck_02_mrl_d_co.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_CO.paa"
	};
};
class RC_MRL_ReTex_D: RC_MRL_ReTex_D_I
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_ReTex_D_O: RC_MRL_ReTex_D_I
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};


class RC_MRL_ReTex_A_I: RC_MRL_DIG_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Arid_subcat";
	hiddenSelectionsTextures[]=
	{
		"iveco\data\iveco_front_e.paa",
		"a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"iveco\data\truck_02_mrl_e_co.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_CO.paa"
	};
};
class RC_MRL_ReTex_A: RC_MRL_ReTex_A_I
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_ReTex_A_O: RC_MRL_ReTex_A_I
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};


class RC_MRL_ATACMS_ReTex_WD_I: RC_MRL_ATACMS_DIG_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Woodland_subcat";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\I_E_Truck_02_MRL_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"iveco\data\iveco_front_wd.paa",
		"a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"iveco\data\truck_02_mrl_wd_co.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_CO.paa"
	};
};
class RC_MRL_ATACMS_ReTex_WD: RC_MRL_ATACMS_ReTex_WD_I
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_ATACMS_ReTex_WD_O: RC_MRL_ATACMS_ReTex_WD_I
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};


class RC_MRL_ATACMS_ReTex_D_I: RC_MRL_ATACMS_DIG_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"iveco\data\iveco_front_d.paa",
		"a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"iveco\data\truck_02_mrl_d_co.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_CO.paa"
	};
};
class RC_MRL_ATACMS_ReTex_D: RC_MRL_ATACMS_ReTex_D_I
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_ATACMS_ReTex_D_O: RC_MRL_ATACMS_ReTex_D_I
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};


class RC_MRL_ATACMS_ReTex_A_I: RC_MRL_ATACMS_DIG_I
{
	faction="RemoteControlled_ReTex_I";
	editorSubcategory="RC_ReTex_Arid_subcat";
	hiddenSelectionsTextures[]=
	{
		"iveco\data\iveco_front_e.paa",
		"a3\soft_f_beta\truck_02\data\truck_02_int_co.paa",
		"iveco\data\truck_02_mrl_e_co.paa",
		"\A3\Soft_F_Beta\Truck_02\Data\Truck_02_chassis_CO.paa"
	};
};
class RC_MRL_ATACMS_ReTex_A: RC_MRL_ATACMS_ReTex_A_I
{
	faction="RemoteControlled_ReTex_B";
	crew="B_UAV_AI";
	side=1;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_MRL_ATACMS_ReTex_A_O: RC_MRL_ATACMS_ReTex_A_I
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};