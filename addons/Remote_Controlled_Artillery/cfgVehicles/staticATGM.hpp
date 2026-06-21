// Static AT Arid
// Blufor
class B_static_AT_F;
class RC_Static_ATGM_base: B_static_AT_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class assembleInfo;
	class Components;
	class UserActions;
	class AnimationSources;
	scope=0;
	scopeCurator=0;
	
	RC_assembleSideSwitch=1;
	RC_assembleAutonomousOff=1;
};
class RC_Static_ATGM_SACLOS: RC_Static_ATGM_base
{
	displayname="RC Static ATGM 4km SACLOS";
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
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				*/
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=4000;
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
					class AirTarget
					{
						minRange=4000;
						maxRange=4000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=4000;
						maxRange=4000;
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
					typeRecognitionDistance=1000;
					class AirTarget
					{
						minRange=1500;
						maxRange=1500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=1500;
						maxRange=1500;
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
							range[]={4000,2000,1000,500};
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

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_static_AT_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"\a3\weapons_f_beta\launchers\titan\data\launcher_INDP_co.paa",
		"\a3\weapons_f_beta\launchers\titan\data\tubem_INDP_co.paa"
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 4km SACLOS";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_SACLOS_Bag"
		};
	};
};
class RC_Static_ATGM_SACLOS_O: RC_Static_ATGM_SACLOS
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AT_Bag_O"
		};
	};
	*/
};
class RC_Static_ATGM_SACLOS_I: RC_Static_ATGM_SACLOS
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_AT_Bag_O"
		};
	};
	*/
};


class RC_Static_ATGM_SACLOS_Assemble: RC_Static_ATGM_SACLOS
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_Static_ATGM_SACLOS_Bag: RC_Static_AA_Bag
{
	displayName="RC Static ATGM 4km SACLOS";

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km SACLOS";
		assembleTo="RC_Static_ATGM_SACLOS_Assemble";
	};
};

//Overfly
class RC_Static_ATGM_Overfly: RC_Static_ATGM_SACLOS
{
	displayname="RC Static ATGM 4km Overfly";

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
				"RC_1Rnd_ATGM_MP_Overfly",
				"RC_1Rnd_ATGM_MP_Overfly",
				"RC_1Rnd_ATGM_MP_Overfly",
				"RC_1Rnd_ATGM_MP_Overfly"
				/*
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock",
				"RC_1Rnd_MP_Interceptor_Lock"
				*/
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
							range[]={4000,2000,1000,500};
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

	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km Overfly";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Overfly_Bag"
		};
	};
};
class RC_Static_ATGM_Overfly_O: RC_Static_ATGM_Overfly
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km Overfly [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Overfly_Bag_O"
		};
	};
	*/
};
class RC_Static_ATGM_Overfly_I: RC_Static_ATGM_Overfly
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km Overfly [Ind]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Overfly_Bag_I"
		};
	};
	*/
};


class RC_Static_ATGM_Overfly_Assemble: RC_Static_ATGM_Overfly
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_Static_ATGM_Overfly_Bag: RC_Static_AA_Bag
{
	displayName="RC Static ATGM 4km Overfly";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 4km Overfly";
		assembleTo="RC_Static_ATGM_Overfly_Assemble";
	};
};


//NLOS
class RC_Static_ATGM_NLOS: RC_Static_ATGM_Overfly
{
	displayname="RC Static ATGM 4km NLOS";

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
		};
	};

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 4km NLOS";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_NLOS_Bag"
		};
	};
};
class RC_Static_ATGM_NLOS_O: RC_Static_ATGM_NLOS
{
	faction="RemoteControlled_O";
	side=0;
	crew="O_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGM_Bag_O"
		};
	};
	*/
};
class RC_Static_ATGM_NLOS_I: RC_Static_ATGM_NLOS
{
	faction="RemoteControlled_I";
	side=2;
	crew="I_UAV_AI";

	/*
	class assembleInfo: assembleInfo
	{
		displayName="RC ATGM 4km NLOS [Opf]";
		dissasembleTo[]=
		{
			"RC_Static_ATGN_Bag_O"
		};
	};
	*/
};


class RC_Static_ATGM_NLOS_Assemble: RC_Static_ATGM_NLOS
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_Static_ATGM_NLOS_Bag: RC_Static_AA_Bag
{
	displayName="RC Static ATGM 4km NLOS";

	class assembleInfo: assembleInfo
	{
		displayName="RC Static ATGM 4km NLOS";
		assembleTo="RC_Static_ATGM_NLOS_Assemble";
	};
};