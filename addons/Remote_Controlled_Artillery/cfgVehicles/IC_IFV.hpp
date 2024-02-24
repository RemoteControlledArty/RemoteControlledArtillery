class B_APC_Wheeled_01_cannon_F;
class RC_ICV_IFV_2_A_Base: B_APC_Wheeled_01_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	class HitHull;
	class HitEngine;
	//class HitFuel;
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class ViewOptics;
	class ViewPilot;
	class Components;
	/*
	class Wheels;
	class L1;
	class L2;
	class L3;
	class L4;
	class R1;
	class R2;
	class R3;
	class R4;
	*/
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_ICV_IFV_2_A: RC_ICV_IFV_2_A_Base
{
	author="Ascent";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Transport_FSV_subcat";
	scope=0;
	scopeCurator=0;
	side=1;
	forceInGarage=1;
	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	commanding=2;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	incomingMissileDetectionSystem=16;
	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	enginePower=506.25;
	peakTorque=5650;
	//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
	armorStructural=1000;	//prevents instant explosion, does not make it stronger
	hullExplosionDelay[]={40,45};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds

	class HitPoints: HitPoints
	{
		/*
		class HitHull: HitHull
		{
			armor=-768;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.2;
		};
		class HitEngine: HitEngine
		{
			armor=-360;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.5;
		};
		class HitFuel: HitFuel
		{
			armor=-360;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.60000002;
		};
		*/

		class HitHull: HitHull
		{
			armor=2;
		};
		class HitEngine: HitEngine
		{
			armor=1.25;
		};
		
		class HitLFWheel: HitLFWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLMWheel: HitLMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLBWheel: HitLBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRMWheel: HitRMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRBWheel: HitRBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
	};

	/*
	class Wheels: Wheels
	{
		class L1: L1
		{
			latStiffX=25;
			latStiffY=90;
		};
		class L2: L2
		{
			latStiffX=25;
			latStiffY=90;
		};
		class L3: L3
		{
			latStiffX=25;
			latStiffY=90;
		};
		class L4: L4
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R1: R1
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R2: R2
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R3: R3
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R4: R4
		{
			latStiffX=25;
			latStiffY=90;
		};
	};
	*/

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
					typeRecognitionDistance=3000;

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
					range[]={3000,1500,750,375};
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
			defaultDisplay="EmptyDisplayComponent";

			class Components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={3000,1500,750,375};
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

	//Items
	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_MRAWS_HEAT_F
		{
			magazine="MRAWS_HEAT_F";
			count=5;
		};
		class _xx_MRAWS_HE_F
		{
			magazine="MRAWS_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_A
		{
			weapon="Improved_FOV_Laserdesignator_A";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
	class TransportBackpacks
	{
		class _xx_B_Carryall_oli
		{
			backpack="B_Carryall_oli";
			count=1;
		};
		class _xx_B_Carryall_cbr
		{
			backpack="B_Carryall_cbr";
			count=1;
		};
	};
};


class RC_ICV_2_A: RC_ICV_IFV_2_A
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {if (local _this) then {{ _this animate [_x, 1]} forEach ['HideHull','HideTurret']}; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this; waitUntil {!isNull driver _this}; _this lockDriver true;}; (_this select 0) spawn {while {true} do {if (isPlayer _this && !(isPlayer (gunner _this))) then {_this lockTurret [[0], true]} else {_this lockTurret [[0], false]}; sleep 0.5;};}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};
	//init="if (!isserver) exitwith {}; (_this select 0) spawn {if (local _this) then {{ _this animate [_x, 1]} forEach ['HideHull','HideTurret']}; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this; waitUntil {!isNull driver _this}; _this lockDriver true;}; (_this select 0) spawn {while {true} do {if (player in _this && !(gunner _this == player)) then {_this lockTurret [[0], true]} else {_this lockTurret [[0], false]}; sleep 0.5;};}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	//(_this select 0) spawn {while {true} do {if (player in _this && (commander _this == player)) then {player action ["TurnIn", _this player];}; sleep 0.5;};};

	RCDisableSeats=3; // locks commander seats
	RCReenableSeats=3;	//re-unlocks only commander seat, required for this vehicle

	displayName="RC ICV II";
	scope=2;
	scopeCurator=2;
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	maximumLoad=4000;
	threat[]={0.30000001,0.30000001,0.30000001};

	/*
	//doesnt work yet
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherOnTurret=0;	//1
	smokeLauncherAngle=180;

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag"
	};
	*/

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="";

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

					initFov=1;
					minFov=0.125;
					maxFov=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};

			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				initFov=1;
				minFov=0.125;
				maxFov=1;
			};

			weapons[]=
			{
				"TruckHorn"
			};
			/*
			//doesnt work yet
			weapons[]=
			{
				"TruckHorn",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag"
			};
			*/
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					turretInfoType="";
					gunnerForceOptics=1;
					commanding=3;

					weapons[]=
					{
						"TruckHorn"
					};

					/*
					//doesnt work yet
					weapons[]=
					{
						"TruckHorn",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"SmokeLauncherMag"
					};
					*/
					
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

							initFov=1;
							minFov=0.125;
							maxFov=1;
							visionMode[]=
							{
								"Normal",
								"NVG"
							};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};

					class ViewOptics: ViewOptics
					{
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
						initFov=1;
						minFov=0.125;
						maxFov=1;
					};

					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						defaultDisplay="MinimapDisplayComponent";

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
							class UAVFeedDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class CrewDisplay
							{
								componentType="CrewDisplayComponent";
							};
							/*
							//doesnt work yet
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={3000,1500,750,375};
								resource="RscCustomInfoSensors";
							};
							*/
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
							class UAVFeedDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class CrewDisplay
							{
								componentType="CrewDisplayComponent";
							};
							/*
							//doesnt work yet
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={3000,1500,750,375};
								resource="RscCustomInfoSensors";
							};
							*/
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

			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="MinimapDisplayComponent";

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
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
					};
					/*
					//doesnt work yet
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={3000,1500,750,375};
						resource="RscCustomInfoSensors";
					};
					*/
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
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
					};
					/*
					//doesnt work yet
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={3000,1500,750,375};
						resource="RscCustomInfoSensors";
					};
					*/
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

	class AnimationSources: AnimationSources
	{
		class showCamonetHull
		{
			displayName="$STR_A3_animationsources_showcamonethull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=0;
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
};
class RC_ICV_2_A_O: RC_ICV_2_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_A
		{
			weapon="Improved_FOV_Laserdesignator_A";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_ICV_2_A_I: RC_ICV_2_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};


class RC_ICV_2_WD: RC_ICV_2_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_base_olive_CO.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_adds_olive_co.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_tows_olive_co.paa",
		"a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
		"a3\Armor_F\Data\cage_olive_CO.paa"
	};

	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_ICV_2_WD_O: RC_ICV_2_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_ICV_2_WD_I: RC_ICV_2_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};


class RC_IFV_2_A: RC_ICV_IFV_2_A
{
	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {waitUntil {!isNull driver _this}; _this lockDriver true; waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};
	/*
	//Missile launcher on top, memoryppoint unclear, and rotate with boolean not working
	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {waitUntil {!isNull driver _this}; _this lockDriver true; waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this; ('B_static_AA_F' createVehicle [0,0,0]) attachTo [_this, [1,1,1], 'mainTurret', true]}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};
	*/

	RCDisableSeats=6; //locks gunner&commander seat while remote controlling driver (changing seats causes serve bugs)
	RCReenableSeats=6;	//reunlocks gunner/commander seats when not remote controlling

	displayName="IFV 40mm";
	scope=2;
	scopeCurator=2;
	maximumLoad=3000;
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;
	
	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=3;
			//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			//gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
			//turretInfoType="";
			//turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_autocannon_40mm_CTWS",
				"RC_MMG_338_IFV_2",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_50Rnd_40mm_MP_T",
				"RC_50Rnd_40mm_MP_T",
				"RC_50Rnd_40mm_MP_T",
				"RC_50Rnd_40mm_MP_T",
				"RC_50Rnd_40mm_APFSDS_T",
				"RC_50Rnd_40mm_APFSDS_T",
				"RC_50Rnd_40mm_APFSDS_T",
				"RC_50Rnd_40mm_APFSDS_T",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
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
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					//gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
					//gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
					//turretInfoType="";
					commanding=2;

					weapons[]=
					{
						"Laserdesignator_mounted",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries",
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
							thermalMode[]={0,1};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_w_F.p3d";
							//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							//gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
							gunnerOpticsEffect[]={};
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
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								/*
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
								};
								*/
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
								class MinimapDisplay
								{
									componentType="MinimapDisplayComponent";
									resource="RscCustomInfoMiniMap";
								};
								class EmptyDisplay
								{
									componentType="EmptyDisplayComponent";
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
								class SensorDisplay
								{
									componentType="SensorsDisplayComponent";
									range[]={3000,1500,750,375};
									resource="RscCustomInfoSensors";
								};
								/*
								class VehicleMissileDisplay
								{
									componentType="TransportFeedDisplayComponent";
									source="Missile";
								};
								*/
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
								class MinimapDisplay
								{
									componentType="MinimapDisplayComponent";
									resource="RscCustomInfoMiniMap";
								};
								class EmptyDisplay
								{
									componentType="EmptyDisplayComponent";
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
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						*/
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
						/*
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
						};
						*/
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

	class AnimationSources: AnimationSources
	{
		class showCamonetHull
		{
			displayName="$STR_A3_animationsources_showcamonethull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=1;
			mass=-50;
		};
		class showCamonetCannon
		{
			source="user";
			animPeriod=0.001;
			initPhase=1;
		};
		class showCamonetTurret
		{
			displayName="$STR_A3_animationsources_showcamonetturret0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=1;
			forceAnimatePhase=1;
			forceAnimate[]=
			{
				"showCamonetCannon",
				1
			};
			forceAnimate2[]=
			{
				"showCamonetCannon",
				0
			};
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
		class showSLATTurret
		{
			displayName="$STR_A3_animationsources_showslatturret0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
			initPhase=1;
			mass=-50;
		};
	};
};
class RC_IFV_2_A_O: RC_IFV_2_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_A
		{
			weapon="Improved_FOV_Laserdesignator_A";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_IFV_2_A_I: RC_IFV_2_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};


class RC_IFV_2_WD: RC_IFV_2_A
{
	DLC="Expansion";
	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_APC_Wheeled_01_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_base_olive_CO.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_adds_olive_co.paa",
		"A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_tows_olive_co.paa",
		"a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
		"a3\Armor_F\Data\cage_olive_CO.paa"
	};

	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_IFV_2_WD_O: RC_IFV_2_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_IFV_2_WD_I: RC_IFV_2_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};


class B_APC_Wheeled_03_cannon_F;
class RC_ICV_IFV_1_A_Base: B_APC_Wheeled_03_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	/*
	class HitHull;
	class HitEngine;
	class HitFuel;
	*/
	class HitLFWheel;
	class HitLF2Wheel;
	class HitLMWheel;
	class HitLBWheel;
	class HitRFWheel;
	class HitRF2Wheel;
	class HitRMWheel;
	class HitRBWheel;
	class AnimationSources;
	class showCamonetHull;
	class showSLATHull;
	class ViewOptics;
	class ViewPilot;
	class Components;
	/*
	class Wheels;
	class L1;
	class L2;
	class L3;
	class L4;
	class R1;
	class R2;
	class R3;
	class R4;
	*/
	class EventHandlers;
	scope=0;
	scopeCurator=0;
};
class RC_ICV_IFV_1_A: RC_ICV_IFV_1_A_Base
{
	author="Ascent";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Transport_FSV_subcat";
	scope=0;
	scopeCurator=0;
	side=1;
	forceInGarage=1;
	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	commanding=2;
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;
	crewCrashProtection=0.01;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	incomingMissileDetectionSystem=16;
	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	peakTorque=5650;
	//armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45, but difficult to set up all hitpoints correctly
	armorStructural=1000;	//prevents instant explosion, does not make it stronger
	hullExplosionDelay[]={40,45};		//placeholder until script is found to remove ugv ai to keep it from getting engaged during a longer time
	//hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds

	DLC="Tacops";
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_APC_Wheeled_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_IG_02_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext2_IG_02_CO.paa",
		"A3\Data_F_Tacops\data\RCWS30_IG_02_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_alpha_IG_02_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_FIA_desert_CO.paa",
		"A3\armor_f\data\cage_sand_co.paa"
	};
	textureList[]=
	{
		"Guerilla_01",
		0,
		"Guerilla_02",
		1,
		"Guerilla_03",
		0
	};

	class HitPoints: HitPoints
	{
		/*
		class HitHull: HitHull
		{
			armor=-960;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.2;
		};
		class HitEngine: HitEngine
		{
			armor=360;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.5;
		};
		class HitFuel: HitFuel
		{
			armor=360;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.60000002;
		};
		*/

		class HitLFWheel: HitLFWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLMWheel: HitLMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitLBWheel: HitLBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRMWheel: HitRMWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
		class HitRBWheel: HitRBWheel
		{
			armor=-500;
			minimalHit=-0.016000001;
			explosionShielding=2;
			passThrough=0;
		};
	};

	/*
	class Wheels: Wheels
	{
		class L1: L1
		{
			latStiffX=25;
			latStiffY=90;
		};
		class L2: L2
		{
			latStiffX=25;
			latStiffY=90;
		};
		class L3: L3
		{
			latStiffX=25;
			latStiffY=90;
		};
		class L4: L4
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R1: R1
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R2: R2
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R3: R3
		{
			latStiffX=25;
			latStiffY=90;
		};
		class R4: R4
		{
			latStiffX=25;
			latStiffY=90;
		};
	};
	*/

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
					typeRecognitionDistance=3000;

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
					range[]={3000,1500,750,375};
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
			defaultDisplay="EmptyDisplayComponent";

			class Components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={3000,1500,750,375};
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

	class AnimationSources: AnimationSources
	{
		class showCamonetHull
		{
			displayName="$STR_A3_animationsources_showcamonethull0";
			author="$STR_A3_Bohemia_Interactive";
			source="user";
			animPeriod=0.001;
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

	//Items
	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_MRAWS_HEAT_F
		{
			magazine="MRAWS_HEAT_F";
			count=5;
		};
		class _xx_MRAWS_HE_F
		{
			magazine="MRAWS_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_A
		{
			weapon="Improved_FOV_Laserdesignator_A";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
	class TransportBackpacks
	{
		class _xx_B_Carryall_oli
		{
			backpack="B_Carryall_oli";
			count=1;
		};
		class _xx_B_Carryall_cbr
		{
			backpack="B_Carryall_cbr";
			count=1;
		};
	};
};


class RC_ICV_1_A: RC_ICV_IFV_1_A
{
	class EventHandlers: EventHandlers
	{
		init="if (!isserver) exitwith {}; (_this select 0) spawn {if (local _this) then {{ _this animate [_x, 1]} forEach ['HideHull','HideTurret']}; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this; waitUntil {!isNull driver _this}; _this lockDriver true;}; (_this select 0) spawn {while {true} do {if (isPlayer _this && !(isPlayer (gunner _this))) then {_this lockTurret [[0], true]} else {_this lockTurret [[0], false]}; sleep 0.5;};}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};
	//init="if (!isserver) exitwith {}; (_this select 0) spawn {if (local _this) then {{ _this animate [_x, 1]} forEach ['HideHull','HideTurret']}; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this; waitUntil {!isNull driver _this}; _this lockDriver true;}; (_this select 0) spawn {while {true} do {if (player in _this && !(gunner _this == player)) then {_this lockTurret [[0], true]} else {_this lockTurret [[0], false]}; sleep 0.5;};}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	//(_this select 0) spawn {while {true} do {if (player in _this && (commander _this == player)) then {player action ["TurnIn", _this player];}; sleep 0.5;};};

	RCDisableSeats=3; // locks commander seats
	RCReenableSeats=3;	//re-unlocks only commander seat, required for this vehicle

	displayName="RC ICV I";
	scope=2;
	scopeCurator=2;
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	maximumLoad=4000;
	threat[]={0.30000001,0.30000001,0.30000001};

	smokeLauncherGrenadeCount=12;
	smokeLauncherAngle=180;

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
			turretInfoType="";

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

					initFov=1;
					minFov=0.125;
					maxFov=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};

			class ViewOptics: ViewOptics
			{
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				initFov=1;
				minFov=0.125;
				maxFov=1;
			};

			weapons[]=
			{
				"TruckHorn",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"SmokeLauncherMag"
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
					turretInfoType="";
					gunnerForceOptics=1;
					commanding=3;

					weapons[]=
					{
						"TruckHorn",
						"SmokeLauncher"
					};
					magazines[]=
					{
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

							initFov=1;
							minFov=0.125;
							maxFov=1;
							visionMode[]=
							{
								"Normal",
								"NVG"
							};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
							gunnerOpticsEffect[]={};
						};
					};

					class ViewOptics: ViewOptics
					{
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
						initFov=1;
						minFov=0.125;
						maxFov=1;
					};

					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						defaultDisplay="MinimapDisplayComponent";

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
							class UAVFeedDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class CrewDisplay
							{
								componentType="CrewDisplayComponent";
							};
							/*
							//doesnt work yet
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={3000,1500,750,375};
								resource="RscCustomInfoSensors";
							};
							*/
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
							class UAVFeedDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class CrewDisplay
							{
								componentType="CrewDisplayComponent";
							};
							/*
							//doesnt work yet
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={3000,1500,750,375};
								resource="RscCustomInfoSensors";
							};
							*/
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

			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="MinimapDisplayComponent";

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
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
					};
					/*
					//doesnt work yet
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={3000,1500,750,375};
						resource="RscCustomInfoSensors";
					};
					*/
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
					class UAVFeedDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
					};
					/*
					//doesnt work yet
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={3000,1500,750,375};
						resource="RscCustomInfoSensors";
					};
					*/
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
class RC_ICV_1_A_O: RC_ICV_1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_A
		{
			weapon="Improved_FOV_Laserdesignator_A";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_ICV_1_A_I: RC_ICV_1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};


class RC_ICV_1_WD: RC_ICV_1_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext2_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\RCWS30_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_alpha_IG_01_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_FIA_green_CO.paa",
		"A3\armor_f\data\cage_G1_co.paa"
	};
	textureList[]=
	{
		"Guerilla_01",
		1,
		"Guerilla_02",
		0,
		"Guerilla_03",
		0
	};

	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_ICV_1_WD_O: RC_ICV_1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_ICV_1_WD_I: RC_ICV_1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};
class RC_ICV_1_DIG_I: RC_ICV_1_WD_I
{
	DLC="";
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_APC_Wheeled_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext2_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\RCWS30_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_alpha_INDP_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
};


class RC_IFV_1_A: RC_ICV_IFV_1_A
{
	class EventHandlers: EventHandlers
	{
		init="(_this select 0) spawn {waitUntil {!isNull driver _this}; _this lockDriver true; waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;}; (_this select 0) spawn {while {true} do {_speedCheck1 = false; _speedCheck2 = false; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck1 = true} else {_speedCheck1 = false}; sleep 4; if ((speed _this <= 0.1) and (speed _this >= -0.1)) then {_speedCheck2 = true} else {_speedCheck2 = false}; if ((_speedCheck1) and (_speedCheck2)) then {_this engineOn false};};};";
	};

	RCDisableSeats=6; //locks gunner&commander seat while remote controlling driver (changing seats causes serve bugs)
	RCReenableSeats=6;	//reunlocks gunner/commander seats when not remote controlling

	displayName="IFV 30mm";
	scope=2;
	scopeCurator=2;
	maximumLoad=3000;
	smokeLauncherGrenadeCount=12;
	smokeLauncherVelocity=14;
	smokeLauncherAngle=180;
	
	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag"
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=3;
			turretInfoType="RscOptics_APC_Wheeled_01_gunner";

			weapons[]=
			{
				"RC_autocannon_30mm_CTWS",
				"RC_MMG_338_IFV_1",
				"RC_IFV_Missle_Launcher",
				"SmokeLauncher"
			};
			magazines[]=
			{
				"RC_100Rnd_30mm_MP_T",
				"RC_100Rnd_30mm_MP_T",
				"RC_100Rnd_30mm_MP_T",
				"RC_100Rnd_30mm_APFSDS_T",
				"RC_100Rnd_30mm_APFSDS_T",
				"RC_100Rnd_30mm_APFSDS_T",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_200Rnd_338_T_Mag",
				"RC_2Rnd_IFV_MP_NLOS",
				"RC_2Rnd_IFV_AA",
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
					thermalMode[]={0,1};
					//gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_APC_03_m_F.p3d";
					gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_01_m_F.p3d";
					gunnerOpticsEffect[]={};
				};
			};
			
			class Turrets: Turrets
			{
				class CommanderOptics : CommanderOptics
				{
					commanding=2;

					weapons[]=
					{
						"Laserdesignator_mounted",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries",
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
							thermalMode[]={0,1};
							gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_w_F.p3d";
							gunnerOpticsEffect[]={};
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
								class MinimapDisplay
								{
									componentType="MinimapDisplayComponent";
									resource="RscCustomInfoMiniMap";
								};
								class EmptyDisplay
								{
									componentType="EmptyDisplayComponent";
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
								class MinimapDisplay
								{
									componentType="MinimapDisplayComponent";
									resource="RscCustomInfoMiniMap";
								};
								class EmptyDisplay
								{
									componentType="EmptyDisplayComponent";
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
};
class RC_IFV_1_A_O: RC_IFV_1_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_A
		{
			weapon="Improved_FOV_Laserdesignator_A";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_IFV_1_A_I: RC_IFV_1_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};


class RC_IFV_1_WD: RC_IFV_1_A
{
	hiddenSelectionsTextures[]=
	{
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext2_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\RCWS30_IG_01_CO.paa",
		"A3\Data_F_Tacops\data\APC_Wheeled_03_Ext_alpha_IG_01_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_FIA_green_CO.paa",
		"A3\armor_f\data\cage_G1_co.paa"
	};
	textureList[]=
	{
		"Guerilla_01",
		1,
		"Guerilla_02",
		0,
		"Guerilla_03",
		0
	};

	class TransportWeapons
	{
		class _xx_launch_NLAW_F
		{
			weapon="launch_NLAW_F";
			count=2;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_IFV_1_WD_O: RC_IFV_1_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class TransportMagazines
	{
		class _xx_HandGrenade
		{
			magazine="HandGrenade";
			count=20;
		};
		class _xx_SmokeShell
		{
			magazine="SmokeShell";
			count=10;
		};
		class _xx_RPG32_F
		{
			magazine="RPG32_F";
			count=5;
		};
		class _xx_RPG32_HE_F
		{
			magazine="RPG32_HE_F";
			count=5;
		};
		class _xx_1Rnd_Smoke_Grenade_shell
		{
			magazine="1Rnd_Smoke_Grenade_shell";
			count=10;
		};
		class _xx_Laserbatteries
		{
			magazine="Laserbatteries";
			count=2;
		};
	};
	class TransportItems
	{
		class _xx_B_UavTerminal
		{
			name="B_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
	class TransportWeapons
	{
		class _xx_launch_launch_RPG32_green_F
		{
			weapon="launch_RPG32_green_F";
			count=1;
		};
		class _xx_Improved_FOV_Laserdesignator_WD
		{
			weapon="Improved_FOV_Laserdesignator_WD";
			count=1;
		};
		class _xx_Rangefinder
		{
			weapon="Rangefinder";
			count=1;
		};
	};
};
class RC_IFV_1_WD_I: RC_IFV_1_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class TransportItems
	{
		class _xx_I_UavTerminal
		{
			name="I_UavTerminal";
			count=2;
		};
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
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};
class RC_IFV_1_DIG_I: RC_IFV_1_WD_I
{
	DLC="";
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_APC_Wheeled_03_cannon_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext2_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\RCWS30_INDP_CO.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\APC_Wheeled_03_Ext_alpha_INDP_CO.paa",
		"A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
		"A3\armor_f\data\cage_aaf_co.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
};