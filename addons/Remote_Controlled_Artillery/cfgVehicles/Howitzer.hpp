class B_MBT_01_arty_F;
class RC_Howitzer_base: B_MBT_01_arty_F
{
	class AnimationSources;
	class showCamonetTurret;
	class showCamonetHull;
	class showCamonetPlates1;
	class showCamonetPlates2;
	class showAmmobox;
	class showCanisters;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class OpticsIn;
	class Wide;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=2;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=7;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Howitzer_A: RC_Howitzer_base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	displayName="RC Howitzer";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="B_UAV_AI";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;

	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_CO.paa",
		"A3\armor_f_gamma\MBT_01\data\MBT_01_scorcher_co.paa",
		"A3\Data_F\Vehicles\Turret_CO.paa",
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
					typeRecognitionDistance=45000;

					class AirTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=500;

					class AirTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="mainGun";
				};

				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};

	class AnimationSources: AnimationSources
	{
		class recoil_source
		{
			source="reload";
			weapon="RC_155mm_AMOS_V4";
		};
		class muzzle_hide_arty
		{
			source="reload";
			weapon="RC_155mm_AMOS_V4";
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
		class showAmmobox: showAmmobox
		{
			initPhase=1;
		};
		class showCanisters: showCanisters
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		
		"showCamonetTurret",
		0,
		"showCamonetHull",
		0,
		"showCamonetPlates1",
		0,
		"showCamonetPlates2",
		0
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment2";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			maxElev=87;

			weapons[]=
			{
				"RC_155mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_15Rnd_155mm_Mo_shells",
				"RC_4Rnd_155mm_Mo_HEAB",
				"RC_5Rnd_155mm_Mo_MultiGuided",
				"RC_2Rnd_155mm_Mo_Cluster",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_9Rnd_155mm_Mo_AT_mine",
				"RC_9Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
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
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					gunnerCompartments="Compartment3";
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
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
							range[]={30000,20000,10000,5000,2500,40000};
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
							range[]={500};
							resource="RscCustomInfoSensors";
						};
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
class RC_Howitzer_WD: RC_Howitzer_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_arty_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_scorcher_olive_CO.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		//"A3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_Howitzer_A_O: RC_Howitzer_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Howitzer_WD_O: RC_Howitzer_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Howitzer_A_I: RC_Howitzer_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_Howitzer_WD_I: RC_Howitzer_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


class RC_Howitzer_LC_A: RC_Howitzer_A
{
	displayName="RC Howitzer LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_155mm_Mo_shells",
				"RC_3Rnd_155mm_Mo_HEAB",
				"RC_3Rnd_155mm_Mo_MultiGuided",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_4Rnd_155mm_Mo_AT_mine",
				"RC_4Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
			};
		};
	};
};
class RC_Howitzer_LC_WD: RC_Howitzer_LC_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_MBT_01_arty_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa",
		"A3\Armor_F_Exp\MBT_01\data\MBT_01_scorcher_olive_CO.paa",
		"A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa",
		//"A3\Armor_F\Data\camonet_NATO_Green_CO.paa"
		"a3\armor_f\data\camonet_green_co.paa"
	};
};
class RC_Howitzer_LC_A_O: RC_Howitzer_LC_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Howitzer_LC_WD_O: RC_Howitzer_LC_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Howitzer_LC_A_I: RC_Howitzer_LC_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};
class RC_Howitzer_LC_WD_I: RC_Howitzer_LC_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsI.hpp"
};


//HEX Camo Howitzers (Opfor only)
class O_MBT_02_arty_F;
class RC_Howitzer_HEX_O_base: O_MBT_02_arty_F
{
	class AnimationSources;
	class showCamonetHull;
	class showCamonetTurret;
	class showCamonetCannon;
	class showAmmobox;
	class showCanisters;
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class OpticsIn;
	class Wide;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=1; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=2;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=7;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_Howitzer_HEX_A_O: RC_Howitzer_HEX_O_base
{
	class EventHandlers: EventHandlers
	{
		class RC_LightsOff
		{
			#include "\Remote_Controlled_Artillery\includes_script\initLightsOff.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\isUGV.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\reflectors.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	displayName="RC Howitzer";
	faction="RemoteControlled_O";
	editorSubcategory="RC_Howitzer_subcat";
	scope=2;
	scopeCurator=2;
	side=0;
	forceInGarage=1;
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	crew="O_UAV_AI";
	driverCompartments="Compartment1";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;

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
					typeRecognitionDistance=45000;

					class AirTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=45000;
						maxRange=45000;
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
		class recoil_source
		{
			source="reload";
			weapon="RC_155mm_AMOS_V4";
		};
		class muzzle_hide_arty
		{
			source="reload";
			weapon="RC_155mm_AMOS_V4";
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
		class showAmmobox: showAmmobox
		{
			initPhase=1;
		};
		class showCanisters:showCanisters
		{
			initPhase=1;
		};
	};
	animationList[]=
	{
		"showCamonetHull",
		1,
		"showCamonetCannon",
		1,
		"showCamonetTurret",
		1
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerCompartments="Compartment2";
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			maxElev=87;

			weapons[]=
			{
				"RC_155mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_15Rnd_155mm_Mo_shells",
				"RC_4Rnd_155mm_Mo_HEAB",
				"RC_5Rnd_155mm_Mo_MultiGuided",
				"RC_2Rnd_155mm_Mo_Cluster",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_9Rnd_155mm_Mo_AT_mine",
				"RC_9Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
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
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
					gunnerCompartments="Compartment3";
					commanding=1;
					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
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
							range[]={30000,20000,10000,5000,2500,40000};
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
	#include "\Remote_Controlled_Artillery\loadouts\ArtyitemsO.hpp"
};
class RC_Howitzer_HEX_WD_O: RC_Howitzer_HEX_A_O
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_MBT_02_arty_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_body_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_scorcher_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_ghex_CO.paa",
		"a3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa"
	};
};


class RC_Howitzer_HEX_LC_A_O: RC_Howitzer_HEX_A_O
{
	displayName="RC Howitzer LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_155mm_Mo_shells",
				"RC_3Rnd_155mm_Mo_HEAB",
				"RC_3Rnd_155mm_Mo_MultiGuided",
				"RC_20Rnd_155mm_Mo_smoke",
				"RC_4Rnd_155mm_Mo_AT_mine",
				"RC_4Rnd_155mm_Mo_mine",
				"RC_6Rnd_155mm_Mo_Illum"
			};
		};
	};
};
class RC_Howitzer_HEX_LC_WD_O: RC_Howitzer_HEX_LC_A_O
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_T_MBT_02_arty_ghex_F.jpg";
	textureList[]=
	{
		"GreenHex",
		1
	};
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_body_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_scorcher_ghex_CO.paa",
		"a3\Armor_F_Exp\MBT_02\Data\MBT_02_ghex_CO.paa",
		"a3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_HEX_Green_CO.paa"
	};
};


class B_Ship_Gun_01_F;
class RC_Static_Arty_base: B_Ship_Gun_01_F
{
	class Turrets;
	class MainTurret;
	class Components;
	class AnimationSources;
	scope=0;
	scopeCurator=0;

	isRCArty=1;
	RC_ArtyType=3; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RC_BarrelAGL=3.5;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=3.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy
};
class RC_Static_Arty: RC_Static_Arty_base
{
	author="Ascent";
	displayName="RC Naval Gun";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	lockDetectionSystem="2+4+8";
	incomingMissileDetectionSystem=16;

	/*
	class AnimationSources: AnimationSources
	{
		class muzzle_rot_cannon
		{
			source="ammorandom";
			weapon="RC_ShipCannon_120mm_V4";
		};
		class muzzle_hide_cannon
		{
			source="reload";
			weapon="RC_ShipCannon_120mm_V4";
		};
	};
	*/

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			maxelev=87;

			weapons[]=
			{
				"RC_ShipCannon_120mm_V4"
			};
			magazines[]=
			{
				"RC_15Rnd_120mm_Mo_shells",
				"RC_4Rnd_120mm_Mo_HEAB",
				"RC_5Rnd_120mm_Mo_MultiGuided",
				"RC_2Rnd_120mm_Mo_Cluster",
				"RC_20Rnd_120mm_Mo_smoke",
				"RC_9Rnd_120mm_Mo_AT_mine",
				"RC_9Rnd_120mm_Mo_mine",
				"RC_6Rnd_120mm_Mo_Illum"
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
							range[]={30000,20000,10000,5000,2500,40000};
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
					typeRecognitionDistance=45000;

					class AirTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=45000;
						maxRange=45000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};

				#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar.hpp"
			};
		};
	};
};
class RC_Static_Arty_O: RC_Static_Arty
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Static_Arty_I: RC_Static_Arty
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_Static_Arty_LC: RC_Static_Arty
{
	displayName="RC Naval Gun LowCap";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			magazines[]=
			{
				"RC_6Rnd_120mm_Mo_shells",
				"RC_3Rnd_120mm_Mo_HEAB",
				"RC_3Rnd_120mm_Mo_MultiGuided",
				"RC_20Rnd_120mm_Mo_smoke",
				"RC_4Rnd_120mm_Mo_AT_mine",
				"RC_4Rnd_120mm_Mo_mine",
				"RC_6Rnd_120mm_Mo_Illum"
			};
		};
	};
};
class RC_Static_Arty_LC_O: RC_Static_Arty_LC
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Static_Arty_LC_I: RC_Static_Arty_LC
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


//optional Phantom Hawk Retextures (found in steam workshop)
class RC_Howitzer_ReTex_D: RC_Howitzer_A
{
	faction="RemoteControlled_ReTex_B";
	editorSubcategory="RC_ReTex_Desert_subcat";
	hiddenSelectionsTextures[]=
	{
		"merkava\data\mbt_01_body_d.paa",
		"merkava\data\mbt_01_spg_d.paa",
		"merkava\data\turret_d.paa",
		"merkava\data\camonet_desert_co.paa"
	};
};
class RC_Howitzer_ReTex_D_O: RC_Howitzer_ReTex_D
{
	faction="RemoteControlled_ReTex_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Howitzer_ReTex_D_I: RC_Howitzer_ReTex_D
{
	faction="RemoteControlled_ReTex_I";
	crew="I_UAV_AI";
	side=2;
};