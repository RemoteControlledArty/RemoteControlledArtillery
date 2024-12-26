class B_UGV_01_rcws_F;
class RC_indirect_GMG_UGV_base: B_UGV_01_rcws_F
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
	class OpticsIn;
	class Wide;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	artilleryScanner=1;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=1; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=1.75;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=1.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_indirect_GMG_UGV_A: RC_indirect_GMG_UGV_base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";
	class Reflectors {};	//removed, otherwise they are automatically on at night
	aggregateReflectors[]={{""}};

	author="Ascent";
	displayName="RC indirect GMG-UGV";
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	crewCrashProtection=0.01;
	maxSpeed=60;
	enginePower=120;
	peakTorque=750;

	unitInfoType="RscUnitInfoArtillery";

	waterLeakiness=2.5;
	canFloat=1;
	waterAngularDampingCoef=10;
	waterPPInVehicle=0;
	waterResistanceCoef=0.5;

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

				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";
			turretInfoType="RscWeaponRangeArtilleryAuto";
			//commanding=2;
			maxElev=72;
			minElev=-14;

			weapons[]=
			{
				"RC_indirect_40mm_GMG_V4",
				"RC_HMG_127_APC"
			};
			magazines[]=
			{
				"RC_200Rnd_40mm_vic_Mo_shells",
				"RC_200Rnd_127x99_SLAP_T_R",
				"RC_200Rnd_127x99_SLAP_T_R"
			};

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
							range[]={4000,2000,1000,500};
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
		class CargoTurret_01: CargoTurret_01
		{
		};
	};

	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsB.hpp"
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
};
class RC_indirect_GMG_UGV_WD_O: RC_indirect_GMG_UGV_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};

class RC_indirect_GMG_UGV_A_I: RC_indirect_GMG_UGV_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_indirect_GMG_UGV_WD_I: RC_indirect_GMG_UGV_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};