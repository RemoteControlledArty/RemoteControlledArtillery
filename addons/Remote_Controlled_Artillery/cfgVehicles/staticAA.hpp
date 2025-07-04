// Static AA
// Blufor
class B_static_AA_F;
class RC_Static_AA_A_base: B_static_AA_F
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
class RC_Static_AA_A: RC_Static_AA_A_base
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
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
				#include "\Remote_Controlled_Artillery\includes_cfg\UAS_Sensor.hpp"
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km";
		dissasembleTo[]=
		{
			"RC_Static_AA_A_Bag"
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
};
class RC_Static_AA_WD: RC_Static_AA_A
{
	DLC="Expansion";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Static_AA_WD_Bag"
		};
	};

	editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\B_T_Static_AA_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_exp\launchers\titan\data\launch_b_titan_tna_f_01_co.paa",
		"\a3\weapons_f_exp\launchers\titan\data\launch_b_titan_tna_f_02_co.paa"
	};
};


// Static AA Bag
class B_AA_01_weapon_F;
class RC_Static_AA_A_Bag_base: B_AA_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Static_AA_A_Bag: RC_Static_AA_A_Bag_base
{
	displayName="RC Static AA 3.5km";
	scope=2;
	scopeCurator=2;

	mass=540;

	model="\A3\Weapons_F\Ammoboxes\Bags\Backpack_Tortila.p3d";
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Tortila_cbr.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Weapons_F\Ammoboxes\Bags\Data\backpack_Tortila_cbr_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km";
		assembleTo="RC_Static_AA_A";
		base="";
	};
};
class RC_Static_AA_WD_Bag: RC_Static_AA_A_Bag
{
	picture="\a3\Supplies_F_Enoch\Bags\Data\UI\icon_B_Carryall_green_F_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\Supplies_F_Enoch\bags\data\backpack_tortila_RUkhk_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		assembleTo="RC_Static_AA_WD";
	};
};

// Independent / Indi
class RC_Static_AA_A_I: RC_Static_AA_A
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_AA_A_Bag_I"
		};
	};
};
class RC_Static_AA_WD_I: RC_Static_AA_WD
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_AA_WD_Bag_I"
		};
	};
};
class RC_Static_AA_A_Bag_I: RC_Static_AA_A_Bag
{
	displayName="RC Static AA 3.5km [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Ind]";
		assembleTo="RC_Static_AA_A_I";
	};
};
class RC_Static_AA_WD_Bag_I: RC_Static_AA_WD_Bag
{
	displayName="RC Static AA 3.5km [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Ind]";
		assembleTo="RC_Static_AA_WD_I";
	};
};


// Opfor
class RC_Static_AA_A_O: RC_Static_AA_A
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AA_A_Bag_O"
		};
	};
};
class RC_Static_AA_WD_O: RC_Static_AA_WD
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AA_WD_Bag_O"
		};
	};
};
class RC_Static_AA_A_Bag_O: RC_Static_AA_A_Bag
{
	displayName="RC Static AA 3.5km [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Opf]";
		assembleTo="RC_Static_AA_A_O";
	};
};
class RC_Static_AA_WD_Bag_O: RC_Static_AA_WD_Bag
{
	displayName="RC Static AA 3.5km [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Static AA 3.5km [Opf]";
		assembleTo="RC_Static_AA_WD_O";
	};
};