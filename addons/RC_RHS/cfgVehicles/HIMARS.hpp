class rhsusf_M142_usarmy_D;
class RC_HIMARS_base: rhsusf_M142_usarmy_D
{
	class AnimationSources;
	class ViewOptics;
	class Turrets;
	class MainTurret;
	class OpticsIn;
	class Wide;
	class Components;
	//class EventHandlers;
	scope=0;
	scopeCurator=0;

	//isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI	//CURRENTLY NOT FUNCTIONAL WITH HIMARS, due to lack of turret camera
	//RC_ArtyType=4; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=1.65;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=3.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_HIMARS_D: RC_HIMARS_base
{
	/*
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};
	*/

	author="Ascent";
	displayName="RC M142 HIMARS";
	faction="RemoteControlled_B";
	//editorSubcategory="RC_RHS_D_subcat";
	editorSubcategory="RC_Rocket_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	enableGPS=1;

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	crew="B_UAV_AI";
	uavCameraDriverPos="dve_view_pos";
	uavCameraDriverDir="dve_view_pos";
	uavCameraGunnerPos="dve_view_pos";
	uavCameraGunnerDir="dve_view_pos";

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
		class Missiles_revolving2: Missiles_revolving
		{
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
				"RC_3Rnd_230mm_rockets_HEAB",
				"RC_2Rnd_230mm_rockets_MultiGuided",
				"RC_1Rnd_230mm_rockets_cluster"
			};

			//working screen, but azimut not changing with launcher direction, but fixed camera direction
			class OpticsIn
			{
				class DVE_Wide: ViewOptics
				{
					camPos="dve_view_pos";
					gunnerOpticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					initFov=0.125;
					minFov=0.0125;
					maxFov=1.07692;
					hitpoint="Hit_Optic_DVEA";
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
					};
				};
			};
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_HIMARS_D_O: RC_HIMARS_D
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_HIMARS_D_I: RC_HIMARS_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_HIMARS_WD: RC_HIMARS_D
{
	//editorSubcategory="RC_RHS_WD_subcat";
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_M142_usmc_WD.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Cab_MC_CO.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Rear_MC_CO.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Chassis_MC_co.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Wheel_CO.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Int_CO.paa"
	};
};
class RC_HIMARS_WD_O: RC_HIMARS_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_HIMARS_WD_I: RC_HIMARS_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//ATACMS
class RC_HIMARS_ATACMS_D: RC_HIMARS_D
{
	displayName="RC M142 ATACMS";

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
				"RC_1Rnd_604mm_rockets_ATACMS_HEAB"
			};
		};
	};
};
class RC_HIMARS_ATACMS_D_O: RC_HIMARS_ATACMS_D
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_HIMARS_ATACMS_D_I: RC_HIMARS_ATACMS_D
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_HIMARS_ATACMS_WD: RC_HIMARS_ATACMS_D
{
	//editorSubcategory="RC_RHS_WD_subcat";
	editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhsusf_M142_usmc_WD.paa";
	hiddenSelectionsTextures[]=
	{
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Cab_MC_CO.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Rear_MC_CO.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Chassis_MC_co.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Wheel_CO.paa",
		"rhsusf\addons\rhsusf_HIMARS\data\M142_Int_CO.paa"
	};
};
class RC_HIMARS_ATACMS_WD_O: RC_HIMARS_ATACMS_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_HIMARS_ATACMS_WD_I: RC_HIMARS_ATACMS_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};