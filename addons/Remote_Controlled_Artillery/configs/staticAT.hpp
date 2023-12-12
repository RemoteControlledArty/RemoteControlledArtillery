/*
	The Order is
	Weapon -> Bag
*/

// Blufor
// Arid
class RC_Static_AT_Arid: RC_Static_AT_Arid_base
{
	displayname="RC ATGM 3km lock";
	faction="RemoteControlled_B";
	editorSubcategory="RC_ATGM_subcat";
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
	//laserScanner=1;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				/*
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=360;
					angleRangeVertical=360;
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
				*/
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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=1500;
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
					
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=500;
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
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
				};
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km lock";
		dissasembleTo[]=
		{
			"RC_Static_AT_Arid_Bag"
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
				"RC_missiles_titan_static"
			};
			magazines[]=
			{
				"RC_1Rnd_MT_missiles",
				"RC_1Rnd_MT_missiles",
				"RC_1Rnd_MT_missiles",
				"RC_1Rnd_MT_missiles"
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

			//showAllTargets="2 + 4";

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
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
				};
			};
		};
	};
};
class RC_Static_AT_Arid_Bag: RC_Static_AA_Arid_Bag
{
	displayName="RC ATGM 3km lock";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km lock";
		assembleTo="RC_Static_AT_Arid";
	};
};

// Woodland
class RC_Static_AT_Woodland: RC_Static_AT_Arid
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_Woodland_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_static_AT_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_beta\launchers\titan\data\launcher_INDP_co.paa",
		"\a3\weapons_f_beta\launchers\titan\data\tubem_INDP_co.paa"
	};
};
class RC_Static_AT_Woodland_Bag: RC_Static_AA_Woodland_Bag
{
	displayName="RC ATGM 3km lock";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 3km lock";
		assembleTo="RC_Static_AT_Woodland";
	};
};


// Opfor
// Arid
class RC_Static_AT_Arid_O: RC_Static_AT_Arid
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AT_Arid_Bag_O"
		};
	};
};
class RC_Static_AT_Arid_Bag_O: RC_Static_AT_Arid_Bag
{
	displayName="RC Static AT 3km [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Opf]";
		assembleTo="RC_Static_AT_Arid_O";
	};
};

// Woodland
class RC_Static_AT_Woodland_O: RC_Static_AT_Woodland
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AT_Woodland_Bag_O"
		};
	};
};
class RC_Static_AT_Woodland_Bag_O: RC_Static_AT_Woodland_Bag
{
	displayName="RC Static AT 3km [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Opf]";
		assembleTo="RC_Static_AT_Woodland_O";
	};
};


// Independent / Ind
// Arid
class RC_Static_AT_Arid_I: RC_Static_AT_Arid
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_AT_Arid_Bag_I"
		};
	};
};
class RC_Static_AT_Arid_Bag_I: RC_Static_AT_Arid_Bag
{
	displayName="RC Static AT 3km [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Ind]";
		assembleTo="RC_Static_AT_Arid_I";
	};
};

// Woodland
class RC_Static_AT_Woodland_I: RC_Static_AT_Woodland
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_AT_Woodland_Bag_I"
		};
	};
};
class RC_Static_AT_Woodland_Bag_I: RC_Static_AT_Woodland_Bag
{
	displayName="RC Static AT 3km [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AT 3km [Ind]";
		assembleTo="RC_Static_AT_Woodland_I";
	};
};