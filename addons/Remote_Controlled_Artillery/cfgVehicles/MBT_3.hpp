class O_MBT_04_command_F;
class RC_MBT_3_Base: O_MBT_04_command_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class ViewOptics;
	class Components;
	class EventHandlers;
	class AnimationSources;
	class showCamonetCannon;
	class showCamonetHull;
	class showCamonetTurret;
	class OpticsIn;
	class Wide;
	scope=0;
	scopeCurator=0;
	//RCDisableSeats=6; //locks gunner&commander seat while remote controlling driver (changing seats causes serve bugs)
	//RCReenableSeats=6;	//reunlocks gunner/commander seats when not remote controlling
	RC_GunnerIsDriver=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_MBT_3_G_Base: RC_MBT_3_Base
{
	faction="RemoteControlled_B";
	editorSubcategory="RC_FSV_MBT_subcat";
	author="Ascent";
	driverForceOptics=1;
	forceHideDriver=1;
	driverCompartments="Compartment2";
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	lockDetectionSystem=4;
	incomingMissileDetectionSystem=16;
	//mineDetectorRange=50;	//doesnt work yet
	//canAccessMineDetector=1;	//doesnt work yet
	maxSpeed=70;
	enginePower=1537.5;
	peakTorque=6000;
	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Tank\MBT_04\Data\MBT_04_exterior_1_CO.paa",
		"a3\Armor_F_Tank\MBT_04\Data\MBT_04_exterior_2_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_Stripe_Desert_CO.paa"
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
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			isCopilot=1; //allows to trigger EH that gives driving controls
			showAllTargets="2 + 4";
			commanding=2;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_cannon_125mm_advanced",
				"RC_MMG_93x64_coax",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_20Rnd_125mm_APFSDS_T_G",
				"RC_20Rnd_125mm_MP_T_G",
				"RC_3Rnd_125mm_DLG_cannon_missiles",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"RC_200Rnd_93x64_T_G",
				"SmokeLauncherMag",
				"SmokeLauncherMag"
			};

			class OpticsIn
			{
				class Wide: RCWSOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;

					initFov=0.9;
					minFov=0.0166;
					maxFov=0.9;
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={0};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics: CommanderOptics
				{
					isCopilot=1; //allows to trigger EH that gives driving controls
					showAllTargets="2 + 4";
					commanding=1;
					turretInfoType="RscOptics_MBT_03_gunner";

					weapons[]=
					{
						"RC_autocannon_30mm_RCWS",
						"RC_Laserdesignator_vehicle",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"RC_60Rnd_30mm_MP_T_G",
						"RC_60Rnd_30mm_MP_T_G",
						"RC_60Rnd_30mm_MP_T_G",
						"RC_60Rnd_30mm_GPR_T_G",
						"RC_60Rnd_30mm_GPR_T_G",
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};

					class OpticsIn
					{
						class Wide: RCWSOptics
						{
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;

							initFov=0.9;
							minFov=0.0166;
							maxFov=0.9;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={0};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};
					/*
					class ViewOptics: ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.9;
						minFov=0.0166;
						maxFov=0.9;
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={0};
					};
					*/
					class Components: Components
					{
						class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
						{
							defaultDisplay="SensorDisplay";

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
								class SensorDisplay
								{
									componentType="SensorsDisplayComponent";
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
								};
								class VehicleDriverDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Driver";
								};
								class VehicleGunnerDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="PrimaryGunner";
								};
								class UAVFeedDisplay
								{
									componentType="UAVFeedDisplayComponent";
								};
								/*
								class MineDetectorDisplay
								{
									componentType="MineDetectorDisplayComponent";
									range=50;
									resource="RscCustomInfoMineDetect";
								};
								*/
							};
						};
						class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
						{
							defaultDisplay="VehicleDriverDisplay";

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
								class SensorDisplay
								{
									componentType="SensorsDisplayComponent";
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
								};
								class VehicleDriverDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Driver";
								};
								class VehicleGunnerDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="PrimaryGunner";
								};
								class UAVFeedDisplay
								{
									componentType="UAVFeedDisplayComponent";
								};
								/*
								class MineDetectorDisplay
								{
									componentType="MineDetectorDisplayComponent";
									range=50;
									resource="RscCustomInfoMineDetect";
								};
								*/
							};
						};
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
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
						};
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="VehicleDriverDisplay";

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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						class VehicleDriverDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Driver";
						};
						class VehicleCommanderDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Commander";
						};
						class UAVFeedDisplay
						{
							componentType="UAVFeedDisplayComponent";
						};
						/*
						class MineDetectorDisplay
						{
							componentType="MineDetectorDisplayComponent";
							range=50;
							resource="RscCustomInfoMineDetect";
						};
						*/
					};
				};
			};
		};
	};

	#include "\Remote_Controlled_Artillery\includes\FSVitemsB.hpp"
};



class RC_MBT_3_G_Driverless: RC_MBT_3_G_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!local (_this select 0)) exitwith {}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="DL MBT III";
	crew="";
	hasDriver=-1;
};
class RC_MBT_3_G_Driverless_O: RC_MBT_3_G_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsO.hpp"
};
class RC_MBT_3_G_Driverless_I: RC_MBT_3_G_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsI.hpp"
};


class RC_MBT_3_WD_Driverless: RC_MBT_3_G_Driverless
{
	editorPreview="\A3\EditorPreviews_F_Tank\Data\CfgVehicles\O_T_MBT_04_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Tank\MBT_04\Data\MBT_04_exterior_jungle_1_CO.paa",
		"a3\Armor_F_Tank\MBT_04\Data\MBT_04_exterior_jungle_2_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_Stripe_Green_CO.paa"
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
	};
};
class RC_MBT_3_WD_Driverless_O: RC_MBT_3_WD_Driverless
{
	faction="RemoteControlled_O";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsO.hpp"
};
class RC_MBT_3_WD_Driverless_I: RC_MBT_3_WD_Driverless
{
	faction="RemoteControlled_I";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsI.hpp"
};


class RC_MBT_3_G: RC_MBT_3_G_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			init="if (!local (_this select 0)) exitwith {}; (_this select 0) spawn {waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
			#include "\Remote_Controlled_Artillery\includes\DriverControlsEH_IFV.hpp"
		};
	};

	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	displayName="MBT III";
	vehicleClass="Autonomous";
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
};
class RC_MBT_3_G_O: RC_MBT_3_G
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsO.hpp"
};
class RC_MBT_3_G_I: RC_MBT_3_G
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsI.hpp"
};


class RC_MBT_3_WD: RC_MBT_3_G
{
	editorPreview="\A3\EditorPreviews_F_Tank\Data\CfgVehicles\O_T_MBT_04_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\Armor_F_Tank\MBT_04\Data\MBT_04_exterior_jungle_1_CO.paa",
		"a3\Armor_F_Tank\MBT_04\Data\MBT_04_exterior_jungle_2_CO.paa",
		"A3\Armor_F\Data\camonet_CSAT_Stripe_Green_CO.paa"
	};

	class AnimationSources: AnimationSources
	{
		class showCamonetCannon: showCamonetCannon
		{
			initPhase=1;
		};
		class showCamonetHull: showCamonetHull
		{
			initPhase=1;
		};
		class showCamonetTurret: showCamonetTurret
		{
			initPhase=1;
		};
	};
};
class RC_MBT_3_WD_O: RC_MBT_3_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsO.hpp"
};
class RC_MBT_3_WD_I: RC_MBT_3_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	#include "\Remote_Controlled_Artillery\includes\FSVitemsI.hpp"
};