// MRL
class rhsusf_M142_usarmy_WD;
class RC_HIMARS_base: rhsusf_M142_usarmy_WD
{
	class AnimationSources;
	class ViewOptics;
	class Turrets;
	class MainTurret;
	class OpticsIn;
	class Wide;
	class Components;
	scope=0;
	scopeCurator=0;

	isRCArty=1; // 1 = is a Remote Controlled Artillery Piece and should display UI
	RC_ArtyType=4; //1 = portable Mortar, 2 = vehicle Mortar, 3 = Howitzer, 4 = MLRS/MRL
	RCEngineOff=2; //1 = turns off engine when stopping, 2 = same but with delay, required for slow accelerating vehicles
	RC_BarrelAGL=1.65;	//AGL of barrel pivot point in meters, for estimating muzzle position, to increase accuracy
	RC_BarrelLenght=3.5;	//barrel lenght in meters, for estimating muzzle position, to increase accuracy
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_HIMARS_A: RC_HIMARS_base
{
	author="Ascent";
	displayName="RC HIMARS";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Rocket_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;
	textPlural="UGVs";
	textSingular="UGV";
	isUav=1;
	vehicleClass="Autonomous";
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
	enableGPS=1;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	lockDetectionSystem="2+4+8";
	incomingMissileDetectionSystem=16;

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

			class OpticsIn
			{
				class DVE_Wide: ViewOptics
				{
					camPos="dve_view_pos";
					gunnerOpticsModel="rhsusf\addons\rhsusf_optics\data\rhsusf_DVE_4x3";
					visionMode[]=
					{
						"TI"
					};
					thermalMode[]={0,1};
					initFov=0.60000002;
					minFov=0.60000002;
					maxFov=0.60000002;
					hitpoint="Hit_Optic_DVEA";
				};
			};

			/*
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
			*/

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

	class TransportMagazines
	{
	};
	class TransportItems
	{
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
	};
	class TransportWeapons
	{
	};
};
/*
class RC_HIMARS_WD: RC_HIMARS_A
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
class RC_MRL_WD_O: RC_MRL_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_MRL_DIG_I: RC_MRL_DIG
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
class RC_MRL_WD_I: RC_MRL_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};
*/