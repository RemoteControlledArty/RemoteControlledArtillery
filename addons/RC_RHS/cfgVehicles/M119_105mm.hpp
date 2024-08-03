class RHS_M119_D;
class RC_M119_base: RHS_M119_D
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class Components;
	class EventHandlers;
	class Hitpoints;
	class AnimationSources;
	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	scope=0;
	scopeCurator=0;
	RC_BarrelAGL=0.8;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=3;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelExtends=1;	//1 = true, if the barrel extends far past the vehicle, for estimating muzzle position, to increase accuracy;
	//RCisMortar=1; //for Mortars only, which dont work correctly in manual fire atm without having ACE installed
};
class RC_M119: RC_M119_base
{
	displayName="RC M119 105mm 16km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Howitzer_subcat";
	author="Ascent";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
	crew="B_UAV_AI";
	driverForceOptics=1;
	enableGPS=1;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	/*
	class Hitpoints
	{
		class HitHull
		{
			armor=50;
			passThrough=1;
			name="telo";
		};
	};
	*/

	class AnimationSources: AnimationSources
	{
		class recoil_source
		{
			source="reload";
			weapon="RC_105mm_AMOS_V4";
		};
		class muzzle_hide_arty: recoil_source
		{
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
						minRange=20000;
						maxRange=20000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=20000;
						maxRange=20000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=20000;

					class AirTarget
					{
						minRange=20000;
						maxRange=20000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=20000;
						maxRange=20000;
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
			showAllTargets="2 + 4";
			gunnerForceOptics=1;
			maxelev=87;

			weapons[]=
			{
				"RC_105mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_12Rnd_105mm_Mo_shells",
				"RC_4Rnd_105mm_Mo_HEAB",
				"RC_4Rnd_105mm_Mo_MultiGuided",
				"RC_20Rnd_105mm_Mo_Smoke",
				"RC_9Rnd_105mm_Mo_AT_mine",
				"RC_9Rnd_105mm_Mo_mine",
				"RC_6Rnd_105mm_Mo_Illum"
			};
			class ViewOptics: ViewOptics
			{
				initFov=0.125;
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
							range[]={16000,8000,4000,2000};
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
};
class RC_M119_O: RC_M119
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_M119_I: RC_M119
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_M119_LC: RC_M119
{
	displayName="RC M119 105mm 16km";
	editorSubcategory="RC_ReducedAmmo_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_105mm_AMOS_V4"
			};
			magazines[]=
			{
				"RC_6Rnd_105mm_Mo_shells",
				"RC_3Rnd_105mm_Mo_HEAB",
				"RC_3Rnd_105mm_Mo_MultiGuided",
				"RC_20Rnd_105mm_Mo_Smoke_white",
				"RC_4Rnd_105mm_Mo_AT_mine",
				"RC_4Rnd_105mm_Mo_mine",
				"RC_6Rnd_105mm_Mo_Illum"
			};
		};
	};
};
class RC_M119_LC_O: RC_M119_LC
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_M119_LC_I: RC_M119_LC
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};