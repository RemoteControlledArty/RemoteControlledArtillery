class B_APC_Wheeled_01_cannon_F;
class RC_Infantry_Carrier_base: B_APC_Wheeled_01_cannon_F
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

	scope=0;
	scopeCurator=0;
	//RCDisableSeats=2; // 1 = Commander Seat, 2 = Commander and Driver Seat, 3 = Commander seat when it's at [0] instead of [0,0], 3 = Commander when the Seat is at [0] instead of the normal [0,0]
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
};
class RC_Infantry_Carrier: RC_Infantry_Carrier_base
{
	class EventHandlers
	{
		init="(_this select 0) spawn {if (local _this) then {{ _this animate [_x, 1]} forEach ['HideHull','HideTurret']}; waitUntil {!isNull gunner _this}; _this deleteVehicleCrew gunner _this};";
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
	uavCameraDriverPos="PiP0_pos";
	uavCameraDriverDir="PiP0_dir";
	uavCameraGunnerPos="PiP0_pos";
	uavCameraGunnerDir="PiP0_dir";
	//driver="B_UAV_AI";
	crew="B_UAV_AI";
	forceHideDriver=1;
	driverForceOptics=1;
	commanding=2;
	//driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
	//memoryPointDriverOptics="gunnerview";		//bugs on the left
	//memoryPointDriverOptics="commanderview";	//bugs on the left

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

	//smokeLauncherOnTurret=1;
	smokeLauncherGrenadeCount=8;
	smokeLauncherVelocity=14;
	smokeLauncherOnTurret=0;
	smokeLauncherAngle=120;

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			commanding=3;
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
				initFov=0.8;
				minFov=0.125;
				maxFov=0.8;
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
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
					turretInfoType="";
					gunnerForceOptics=1;

					commanding=1;

					hasGunner=-1;
					hasCommander=-1;
					forceHideGunner=1;
					forceHideCommander=1;
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
		class _xx_Improved_FOV_Laserdesignator_Arid
		{
			weapon="Improved_FOV_Laserdesignator_Arid";
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