class B_UGV_01_rcws_F;
class RC_GMG_UGV_base: B_UGV_01_rcws_F
{
	class AnimationSources;
	class HitPoints;
	class HitHull;
	class HitEngine;
	class HitFuel;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class Turrets;
	class MainTurret;
	class CargoTurret_01;
	class CommanderOptics;
	class ViewOptics;
	class Wide;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_GMG_UGV_A_base: RC_GMG_UGV_base
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
			#include "\Remote_Controlled_Artillery\includes_script\cUAS_Beep_400m.hpp"
		};
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_script\UserActions_NameUV.hpp"	
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	author="Ascent";
	faction="RemoteControlled_B";
	side=1;
	forceInGarage=1;
	crewCrashProtection=0.01;
	maxSpeed=80;
	enginePower=120;
	peakTorque=750;

	waterLeakiness=2.5;
	canFloat=1;
	waterAngularDampingCoef=10;
	waterPPInVehicle=0;
	waterResistanceCoef=0.5;

	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=1.05;
			passThrough=1;
			//minimalHit=0.2;
			explosionShielding=0.4;
		};
		class HitEngine: HitEngine
		{
			armor=3;
			passThrough=0.25;
			//minimalHit=0.2;
			explosionShielding=0.4;
		};
		class HitFuel: HitFuel
		{
			armor=2;
			passThrough=0.15;
			//minimalHit=0.1;
			explosionShielding=1.2;
		};
		class HitLFWheel: HitLFWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitLMWheel: HitLMWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
		class HitRMWheel: HitRMWheel
		{
			armor=-250;
			minimalHit=-0.045;
			explosionShielding=1;
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
};
class RC_indirect_GMG_UGV_A: RC_GMG_UGV_A_base
{
	artilleryScanner=1;
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=1.75;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=1.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy

	scope=2;
	scopeCurator=2;
	displayName="RC indirect GMG-UGV";
	editorSubcategory="RC_FSV_subcat";
	unitInfoType="RscUnitInfoArtillery";

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
						minRange=4000;
						maxRange=4000;
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
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
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
				};

				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			turretInfoType="RscWeaponRangeArtilleryAuto";
			//commanding=2;
			maxElev=72;
			minElev=-14;

			weapons[]=
			{
				"RC_indirect_40mm_GMG_V4",
				"RC_HMG_127_APC"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_indirect_red.hpp"

			class OpticsIn
			{
				class Wide: RCWSOptics
				{
					initFov=0.9;
					minFov=0.0125;
					maxFov=0.9;
					//directionStabilized=0;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
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
							range[]={4000,2000,1000,400};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={400,1000,2000,4000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
					};
				};
			};
		};
		class CargoTurret_01: CargoTurret_01
		{
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot_MG
		{
			source="ammorandom";
			weapon="RC_HMG_127_APC";
		};
		class muzzle_rot_GMG
		{
			source="ammorandom";
			weapon="RC_indirect_40mm_GMG_V4";
		};
		class muzzle_hide_MG
		{
			source="reload";
			weapon="RC_HMG_127_APC";
		};
		class muzzle_hide_GMG
		{
			source="reload";
			weapon="RC_indirect_40mm_GMG_V4";
		};
	};
};
class RC_indirect_GMG_UGV_WD: RC_indirect_GMG_UGV_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_UGV_01_rcws_olive_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa",
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};

class RC_indirect_GMG_UGV_A_O: RC_indirect_GMG_UGV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_indirect_green.hpp"
		};
	};
};
class RC_indirect_GMG_UGV_WD_O: RC_indirect_GMG_UGV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_indirect_green.hpp"
		};
	};
};

class RC_indirect_GMG_UGV_A_I: RC_indirect_GMG_UGV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_indirect_yellow.hpp"
		};
	};
};
class RC_indirect_GMG_UGV_WD_I: RC_indirect_GMG_UGV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_indirect_yellow.hpp"
		};
	};
};


class RC_cUAS_UGV_A: RC_GMG_UGV_A_base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			#include "\Remote_Controlled_Artillery\includes_script\fakeTracers.hpp"
		};
	};

	scope=2;
	scopeCurator=2;
	displayName="RC C-UAS UGV";
	editorSubcategory="RC_AntiDrone_subcat";

	smokeLauncherVelocity=3;
	smokeLauncherGrenadeCount=4;
	smokeLauncherAngle=360;	//360° instead of frontal against FPV's

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
						minRange=4000;
						maxRange=4000;
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
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;

					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
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
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=1000;

					class AirTarget
					{
						minRange=1000;
						maxRange=1000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=0;
						maxRange=0;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=1;
					angleRangeVertical=1;
					animDirection="maingun";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=400;

					class AirTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=400;
						maxRange=400;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="maingun";
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//commanding=2;
			maxElev=47.5;
			minElev=-14;

			weapons[]=
			{
				"RC_UGV_20mm_cUAS",
				"RC_HMG_127_APC",
				"SmokeLauncher"
			};
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_cUAS_red.hpp"

			class OpticsIn
			{
				class Wide: RCWSOptics
				{
					initFov=0.9;
					minFov=0.02;
					maxFov=0.9;
					//directionStabilized=0;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
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
							range[]={4000,2000,1000,400};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorDisplay";

					class Components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={400,1000,2000,4000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
					};
				};
			};
		};
		class CargoTurret_01: CargoTurret_01
		{
		};
	};

	class AnimationSources: AnimationSources
	{
		class muzzle_rot_MG
		{
			source="ammorandom";
			weapon="RC_HMG_127_APC";
		};
		class muzzle_rot_GMG
		{
			source="ammorandom";
			weapon="RC_UGV_20mm_cUAS";
		};
		class muzzle_hide_MG
		{
			source="reload";
			weapon="RC_HMG_127_APC";
		};
		class muzzle_hide_GMG
		{
			source="reload";
			weapon="RC_UGV_20mm_cUAS";
		};
	};
};
class RC_cUAS_UGV_WD: RC_cUAS_UGV_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_UGV_01_rcws_olive_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa",
		"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa",
		"\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"
	};
};

class RC_cUAS_UGV_A_O: RC_cUAS_UGV_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_cUAS_green.hpp"
		};
	};
};
class RC_cUAS_UGV_WD_O: RC_cUAS_UGV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_cUAS_green.hpp"
		};
	};
};

class RC_cUAS_UGV_A_I: RC_cUAS_UGV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_cUAS_yellow.hpp"
		};
	};
};
class RC_cUAS_UGV_WD_I: RC_cUAS_UGV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_vicmags\mags_UGV_cUAS_yellow.hpp"
		};
	};
};