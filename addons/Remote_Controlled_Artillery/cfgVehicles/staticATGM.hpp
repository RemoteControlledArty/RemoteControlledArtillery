// Static AT Arid
// Blufor
class B_static_AT_F;
class RC_Static_AT_A_base: B_static_AT_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class assembleInfo;
	class Components;
	class AnimationSources;
	scope=0;
	scopeCurator=0;
};
class RC_Static_AT_A: RC_Static_AT_A_base
{
	displayname="RC ATGM 4km SACLOS";
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
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=0;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				/*
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
		displayName="RC ATGM 4km SACLOS";
		dissasembleTo[]=
		{
			"RC_Static_AT_A_Bag"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			gunnerForceOptics=1;

			minTurn=-180;
			maxTurn=180;

			weapons[]=
			{
				"RC_ATGM_SACLOS"
			};
			magazines[]=
			{
				"RC_1Rnd_ATGM_MP_SACLOS",
				"RC_1Rnd_ATGM_MP_SACLOS",
				"RC_1Rnd_ATGM_MP_SACLOS",
				"RC_1Rnd_ATGM_MP_SACLOS"
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
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="VehicleMissileDisplay";

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
						class VehicleMissileDisplay
						{
							componentType="TransportFeedDisplayComponent";
							source="Missile";
							resource="RscTransportCameraComponentMissile";
						};
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
			weapon="RC_ATGM_SACLOS";
		};
		class muzzle_source_rot
		{
			source="ammorandom";
			weapon="RC_ATGM_SACLOS";
		};
		class ReloadAnim
		{
			source="reload";
			weapon="RC_ATGM_SACLOS";
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="RC_ATGM_SACLOS";
		};
		class Revolving
		{
			source="revolving";
			weapon="RC_ATGM_SACLOS";
		};
	};
};
class RC_Static_AT_A_Bag: RC_Static_AA_A_Bag
{
	displayName="RC ATGM 4km SACLOS";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS";
		assembleTo="RC_Static_AT_A";
	};
};

// Woodland
class RC_Static_AT_WD: RC_Static_AT_A
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AT_WD_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_static_AT_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_beta\launchers\titan\data\launcher_INDP_co.paa",
		"\a3\weapons_f_beta\launchers\titan\data\tubem_INDP_co.paa"
	};
};
class RC_Static_AT_WD_Bag: RC_Static_AA_WD_Bag
{
	displayName="RC ATGM 4km SACLOS";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS";
		assembleTo="RC_Static_AT_WD";
	};
};


// Opfor
// Arid
class RC_Static_AT_A_O: RC_Static_AT_A
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AT_A_Bag_O"
		};
	};
};
class RC_Static_AT_A_Bag_O: RC_Static_AT_A_Bag
{
	displayName="RC ATGM 4km SACLOS [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Opf]";
		assembleTo="RC_Static_AT_A_O";
	};
};

// Woodland
class RC_Static_AT_WD_O: RC_Static_AT_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AT_WD_Bag_O"
		};
	};
};
class RC_Static_AT_WD_Bag_O: RC_Static_AT_WD_Bag
{
	displayName="RC ATGM 4km SACLOS [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Opf]";
		assembleTo="RC_Static_AT_WD_O";
	};
};


// Independent / Ind
// Arid
class RC_Static_AT_A_I: RC_Static_AT_A
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_AT_A_Bag_I"
		};
	};
};
class RC_Static_AT_A_Bag_I: RC_Static_AT_A_Bag
{
	displayName="RC ATGM 4km SACLOS [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Ind]";
		assembleTo="RC_Static_AT_A_I";
	};
};

// Woodland
class RC_Static_AT_WD_I: RC_Static_AT_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_AT_WD_Bag_I"
		};
	};
};
class RC_Static_AT_WD_Bag_I: RC_Static_AT_WD_Bag
{
	displayName="RC ATGM 4km SACLOS [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Ind]";
		assembleTo="RC_Static_AT_WD_I";
	};
};


// Blufor
// Arid
class RC_Static_ATGM_A: RC_Static_AT_A
{
	displayname="RC ATGM 4km NLOS";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_A_Bag"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"RC_ATGM_NLOS"
			};
			magazines[]=
			{
				"RC_1Rnd_ATGM_MP_NLOS",
				"RC_1Rnd_ATGM_MP_NLOS",
				"RC_1Rnd_ATGM_MP_NLOS",
				"RC_1Rnd_ATGM_MP_NLOS"
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
			weapon="RC_ATGM_NLOS";
		};
		class muzzle_source_rot
		{
			source="ammorandom";
			weapon="RC_ATGM_NLOS";
		};
		class ReloadAnim
		{
			source="reload";
			weapon="RC_ATGM_NLOS";
		};
		class ReloadMagazine
		{
			source="reloadmagazine";
			weapon="RC_ATGM_NLOS";
		};
		class Revolving
		{
			source="revolving";
			weapon="RC_ATGM_NLOS";
		};
	};
};
class RC_Static_ATGM_A_Bag: RC_Static_AA_A_Bag
{
	displayName="RC ATGM 4km NLOS";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS";
		assembleTo="RC_Static_ATGM_A";
	};
};

// Woodland
class RC_Static_ATGM_WD: RC_Static_ATGM_A
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_ATGM_WD_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_static_AT_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_beta\launchers\titan\data\launcher_INDP_co.paa",
		"\a3\weapons_f_beta\launchers\titan\data\tubem_INDP_co.paa"
	};
};
class RC_Static_ATGM_WD_Bag: RC_Static_AA_WD_Bag
{
	displayName="RC ATGM 4km NLOS";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS";
		assembleTo="RC_Static_ATGM_WD";
	};
};

// Opfor
// Arid
class RC_Static_ATGM_A_O: RC_Static_ATGM_A
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_A_Bag_O"
		};
	};
};
class RC_Static_ATGM_A_Bag_O: RC_Static_ATGM_A_Bag
{
	displayName="RC ATGM 4km NLOS [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Opf]";
		assembleTo="RC_Static_AT_A_O";
	};
};

// Woodland
class RC_Static_ATGM_WD_O: RC_Static_ATGM_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_WD_Bag_O"
		};
	};
};
class RC_Static_ATGM_WD_Bag_O: RC_Static_ATGM_WD_Bag
{
	displayName="RC ATGM 4km NLOS [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Opf]";
		assembleTo="RC_Static_ATGM_WD_O";
	};
};

// Independent / Indi
// Arid
class RC_Static_ATGM_A_I: RC_Static_ATGM_A
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_A_Bag_I"
		};
	};
};
class RC_Static_ATGM_A_Bag_I: RC_Static_ATGM_A_Bag
{
	displayName="RC ATGM 4km NLOS [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Ind]";
		assembleTo="RC_Static_ATGM_A_I";
	};
};

// Woodland
class RC_Static_ATGM_WD_I: RC_Static_ATGM_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_WD_Bag_I"
		};
	};
};
class RC_Static_ATGM_WD_Bag_I: RC_Static_ATGM_WD_Bag
{
	displayName="RC ATGM 4km NLOS [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Ind]";
		assembleTo="RC_Static_ATGM_WD_I";
	};
};
