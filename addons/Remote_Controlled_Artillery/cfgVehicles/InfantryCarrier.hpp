class B_APC_Wheeled_01_cannon_F;
class RC_Infantry_Carrier_A_base: B_APC_Wheeled_01_cannon_F
{
	class Turrets;
	class MainTurret;
	class CommanderOptics;
	class HitPoints;
	class HitHull;
	class HitEngine;
	class HitFuel;
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
	class Components;
	
	class Wheels;
	class L1;
	class L2;
	class L3;
	class L4;
	class R1;
	class R2;
	class R3;
	class R4;

	scope=0;
	scopeCurator=0;
	//RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_Infantry_Carrier_A: RC_Infantry_Carrier_A_base
{
	class EventHandlers
	{
		init="(_this select 0) spawn {if (local _this) then {{ _this animate [_x, 1]} forEach ['HideHull','HideTurret']}; waitUntil {!isNull commander _this}; _this deleteVehicleCrew commander _this;};";
	};

	//_this lockDriver true; _this lockTurret [[0,0], true];

	displayName="RC Infantry Carrier";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Transport_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	
	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	//uavCameraDriverPos="PiP0_pos";
	//uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	//driver="B_UAV_AI";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	commanding=2;

	/*
	memoryPointDriverOptics="gunnerview";
	driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
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
			gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
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
		initFov=1;	//0.8
		minFov=0.125;
		maxFov=1;	//0.8
	};
	*/

	weapons[]=
	{
		"TruckHorn",
		"SmokeLauncher"
	};
	magazines[]=
	{
		"SmokeLauncherMag"	//fix smoke launcher
	};

	maxSpeed=120;
	normalSpeedForwardCoef=0.64;
	peakTorque=5650;	//4237.5;
	fuelCapacity=50;
	maximumLoad=4000;
	
	ejectDeadGunner=0;
	ejectDeadDriver=0;
	ejectDeadCommander=0;

	crewCrashProtection=0.01;
	armor=110;	//makes 7.62x54/51 shoot, not or rarely 7.62x39/6.5/5.56/5.45
	armorStructural=1000;	//prevents instant explosion, does not make it stronger
	hullExplosionDelay[]={480,600};		//prevents instant explosions, makes it repairable within 480-600seconds
	threat[]={0.30000001,0.30000001,0.30000001};

	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	incomingMissileDetectionSystem=16;

	//smokeLauncherOnTurret=1;
	smokeLauncherGrenadeCount=8;
	smokeLauncherVelocity=14;
	smokeLauncherOnTurret=0;
	smokeLauncherAngle=120;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=2;
			gunnerForceOptics=1;
			forceHideGunner=1;
			//hasGunner=-1;
			//memoryPointGunnerOptics="commanderview";
			gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
			//gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
			turretInfoType="";

			class OpticsIn{};	//removes staged zoom, makes it fluid instead

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
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
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
							gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
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
						initFov=1;	//0.8
						minFov=0.125;
						maxFov=1;	//0.8
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
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={3000,1500,750,375};
							resource="RscCustomInfoSensors";
						};
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
					animDirection="mainTurret";
					minRange=10;
					maxRange=3000;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					class AirTarget
					{
						minRange=32000;
						maxRange=32000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=32000;
						maxRange=32000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class NVSensorComponent: SensorTemplateNV
				{
					class AirTarget
					{
						minRange=10;
						maxRange=1000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=10;
						maxRange=1000;
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
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
	};

	class HitPoints: HitPoints
	{
		class HitHull: HitHull
		{
			armor=-512;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.2;
		};
		class HitEngine: HitEngine
		{
			armor=0.75;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.5;
		};
		class HitFuel: HitFuel
		{
			armor=0.75;
			passThrough=0;
			minimalHit=0.1;
			explosionShielding=0.60000002;
		};
		class HitLFWheel: HitLFWheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
		};
		class HitLMWheel: HitLMWheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
		};
		class HitLBWheel: HitLBWheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
		};
		class HitRFWheel: HitRFWheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
		};
		class HitRMWheel: HitRMWheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
		};
		class HitRBWheel: HitRBWheel
		{
			armor=-250;
			minimalHit=-0.016000001;
			explosionShielding=1;
			passThrough=0;
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
			count=6;
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
class RC_Infantry_Carrier_A_O: RC_Infantry_Carrier_A
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
			count=6;
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
class RC_Infantry_Carrier_A_I: RC_Infantry_Carrier_A
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
			count=6;
		};
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};


class RC_Infantry_Carrier_WD: RC_Infantry_Carrier_A
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
class RC_Infantry_Carrier_WD_O: RC_Infantry_Carrier_WD
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
			count=6;
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
class RC_Infantry_Carrier_WD_I: RC_Infantry_Carrier_WD
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
			count=6;
		};
		class _xx_MineDetector
		{
			name="MineDetector";
			count=2;
		};
	};
};