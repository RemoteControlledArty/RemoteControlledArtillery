// Blufor
class RC_Static_AA_Arid: RC_Static_AA_Arid_base
{
	displayname="RC Static AA 3.5km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_AntiAir_subcat";
	scope=2;
	scopeCurator=2;
	side=1;

	vehicleClass="Autonomous";
	isUav=1;
	textPlural="UGVs";
	textSingular="UGV";
	uavCameraGunnerPos="eye";
	uavCameraGunnerDir="look";
	crew="B_UAV_AI";

	enableGPS=1;
	radartype=2;
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
					animDirection="mainTurret";
					minRange=10;
					maxRange=3500;
					angleRangeHorizontal=360;
					angleRangeVertical=180;
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
				class IRSensorComponent: SensorTemplateIR
				{
					class AirTarget
					{
						minRange=10;
						maxRange=3500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=-1;
						maxRange=-1;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_Arid_Bag"
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

			showAllTargets="2 + 4";

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
							range[]={3500,1750,875,437.5};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
		};
	};
};
class RC_Static_AA_Woodland: RC_Static_AA_Arid
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_Woodland_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Static_AA_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_exp\launchers\titan\data\launch_b_titan_tna_f_01_co.paa",
		"\a3\weapons_f_exp\launchers\titan\data\launch_b_titan_tna_f_02_co.paa"
	};
};
class RC_Static_AA_Arid_Bag: RC_Static_AA_Arid_Bag_base
{
	displayName="RC Static AA 3.5km Bag";
	scope=2;
	scopeCurator=2;

	mass=560;

	model="\A3\Weapons_F\Ammoboxes\Bags\Backpack_Tortila.p3d";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_cbr_co.paa"
	};
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_cbr.paa";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km";
		assembleTo="RC_Static_AA_Arid";
		base="";
	};
};
class RC_Static_AA_Woodland_Bag: RC_Static_AA_Arid_Bag
{
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_oli_co.paa"
	};
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_oli.paa";

	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AA_Woodland";
	};
};

// Independent / Indi
class RC_Static_AA_Arid_I: RC_Static_AA_Arid
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_Arid_Bag_I"
		};
	};
};
class RC_Static_AA_Woodland_I: RC_Static_AA_Woodland
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_Woodland_Bag_I"
		};
	};
};
class RC_Static_AA_Arid_Bag_I: RC_Static_AA_Arid_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AA_Arid_I";
	};
};
class RC_Static_AA_Woodland_Bag_I: RC_Static_AA_Woodland_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AA_Woodland_I";
	};
};


// Opfor
class RC_Static_AA_Arid_O: RC_Static_AA_Arid
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_Arid_Bag_O"
		};
	};
};
class RC_Static_AA_Woodland_O: RC_Static_AA_Woodland
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_Woodland_Bag_O"
		};
	};
};
class RC_Static_AA_Arid_Bag_O: RC_Static_AA_Arid_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AA_Arid_O";
	};
};
class RC_Static_AA_Woodland_Bag_O: RC_Static_AA_Woodland_Bag
{
	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AA_Woodland_O";
	};
};