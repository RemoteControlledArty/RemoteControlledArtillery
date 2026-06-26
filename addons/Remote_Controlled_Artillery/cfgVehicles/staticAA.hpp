// Static AA
// Blufor
class B_static_AA_F;
class RC_Static_AA_Core: B_static_AA_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class assembleInfo;
	class Components;
	class AnimationSources;
	class UserActions;
	scope=0;
	scopeCurator=0;
	
	RC_assembleSideSwitch=1;
	RC_assembleAutonomousOff=0;
};
class RC_Static_AA_Base: RC_Static_AA_Core
{
	displayname="RC Static AA 3.5km";
	editorSubcategory="RC_AntiAir_subcat";

	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";

	enableGPS=1;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

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
					typeRecognitionDistance=3500;

					class AirTarget
					{
						minRange=3500;
						maxRange=3500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;

					class AirTarget
					{
						minRange=3500;
						maxRange=3500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;
					angleRangeVertical=60;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			gunnerForceOptics=1;

			minTurn=-180;
			maxTurn=180;

			weapons[]=
			{
				"missiles_titan_static"
			};
			magazines[]=
			{
				"1Rnd_GAA_missiles",
				"1Rnd_GAA_missiles",
				"1Rnd_GAA_missiles",
				"1Rnd_GAA_missiles",
				"1Rnd_GAA_missiles",
				"1Rnd_GAA_missiles"
			};
			class ViewOptics: ViewOptics
			{
				initFov=0.5;
				minFov=0.02;
				maxFov=0.5;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
			};

			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

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
							range[]={3500,1750,875};
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

	class AnimationSources: AnimationSources
	{
		class muzzle_source
		{
			source="reload";
			weapon="missiles_titan_static";
		};
		class muzzle_source_rot
		{
			source="ammorandom";
			weapon="missiles_titan_static";
		};
		class ReloadAnim
		{
			source="reload";
			weapon="missiles_titan_static";
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="missiles_titan_static";
		};
		class Revolving
		{
			source="revolving";
			weapon="missiles_titan_static";
		};
	};

	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Static_AA_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F_Beta\Launchers\Titan\Data\Launcher_INDP_CO.paa",
		"\A3\Weapons_F_Enoch\Launchers\Titan\Data\launch_B_Titan_olive_F_02_CO.paa"
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_Bag"
		};
	};
};
class RC_Static_AA: RC_Static_AA_Base
{
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	side=1;
	crew="B_UAV_AI";
};
class RC_Static_AA_O: RC_Static_AA
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AA_Bag_O"
		};
	};
	*/
};
class RC_Static_AA_I: RC_Static_AA
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_AA_Bag_I"
		};
	};
	*/
};


class RC_Static_Interceptor: RC_Static_AA
{
	displayname="RC Interceptor Static";
	editorSubcategory="RC_AntiDrone_subcat";

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_InterceptorLauncher"
			};
			magazines[]=
			{
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock"
			};
		};
	};
};


class RC_Static_AA_Assemble: RC_Static_AA
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};


// Static AA Bag
class B_AA_01_weapon_F;
class RC_Static_AA_Bag_base: B_AA_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Static_AA_Bag: RC_Static_AA_Bag_base
{
	displayName="RC Static AA 3.5km";
	scope=2;
	scopeCurator=2;

	mass=540;
	model="\A3\Weapons_F\Ammoboxes\Bags\Backpack_Tortila.p3d";
	/*
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_khk.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_khk_co.paa"
	};
	*/
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_khk.paa";
	hiddenSelectionsTextures[]=
	{
		"\Remote_Controlled_Artillery\textures\carryall.paa"
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km";
		assembleTo="RC_Static_AA_Assemble";
		//assembleTo="RC_Static_AA";
		base="";
	};
};


//manned
/*
class RC_Static_manned_AA: RC_Static_AA
{
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			dontCreateAI=1;
		};
	};
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_manned_Bag"
		};
	};
};
class RC_Static_AA_manned_O: RC_Static_manned_AA
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";
};
class RC_Static_AA_manned_I: RC_Static_manned_AA
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";
};
*/