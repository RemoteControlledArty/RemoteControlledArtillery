//AR-1
class B_UAV_01_F;
class RC_UAV_base: B_UAV_01_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class ViewPilot;
	class assembleInfo;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	RC_UAVBlurRange=2000;	//connection starts getting blurry above this range
	RC_assembleSideSwitch=1;	//neutral side backpack assembled into drone of the assembling players side
	RC_assembleAutonomousOff=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_UAV_AR1_Base: RC_UAV_base
{
	class EventHandlers: EventHandlers
	{
		//defines default flyInHeight, preventing major problems like UAV dropping to 50m when changing locality between players, or to server when player has a disconnect
		class RC_FlyInHeight
		{
			//500m = SOP for recon drones
			postInit="params ['_entity'];  if (!isServer) exitwith {};  _entity flyInHeight 500;";
		};
	};

	displayName="RC AR-1 shortrange 2km";
	editorSubcategory="RC_UAV_Designator_subcat";

	camouflage=0.25;
	radarTargetSize=0.05;
	visualTargetSize=0.05;

	maxSpeed=200;
	liftForceCoef=2;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	backRotorForceCoef=10;
	fuelCapacity=200;
	mainRotorSpeed=-14;
	backRotorSpeed=14;

	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	class Components: Components
	{
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={4000,2000,1000,500,6000};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={2000,4000,6000,500,1000};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
				};
			};
		};
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					animDirection="mainGun";
					aimDown=-0.5;

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
				/*
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				*/
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
			};
		};
	};

	class ViewPilot: ViewPilot
	{
		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.075;
		maxFov=1.25;
		initFov=0.75;
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};
	class Viewoptics: ViewOptics
	{
		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=0.075;
		maxFov=1.25;
		initFov=0.75;
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//isCopilot=1; //0		//doesnt work yet
			//commanding=1; //-1	//doesnt work yet

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500,6000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={2000,4000,6000,500,1000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
						};
					};
				};
			};

			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="W";
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.8;
					minFov=0.05;
					maxFov=1.0;
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					//gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				};
			};
			class OpticsOut
			{
				class Monocular	//doesnt work...?
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=1.0;
					minFov=0.05;
					maxFov=1.0;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					gunnerOpticsModel="";
					gunnerOpticsEffect[]={};
				};
			};
		};
	};
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag"
		};
	};
};


class RC_UAV_AR1: RC_UAV_AR1_Base
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_UAV_AR1_B: RC_UAV_AR1
{
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_UAV_AR1_O: RC_UAV_AR1_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_UAV_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_OPFOR_CO.paa"
	};
	textureList[]=
	{
		"Opfor",
		1
	};
	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag_O"
		};
	};
	*/
};
class RC_UAV_AR1_I: RC_UAV_AR1_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_UAV_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_INDP_CO.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag_I"
		};
	};
	*/
};


class RC_UAV_AR1_5_Base: RC_UAV_AR1_Base
{
	displayName="RC AR-1.5 shortrange 3km";
	RC_UAVBlurRange=0;		//no blur
	RC_UAVCtrlRange=3000;	//3km of manual control range, beyond that terminal waypoints only

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					animDirection="mainGun";
					aimDown=-0.5;

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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2000;
						maxRange=2000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
			};
		};
	};

	class ViewPilot: ViewPilot
	{
		minFov=0.04;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};
	class Viewoptics: Viewoptics
	{
		minFov=0.04;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					minFov=0.04;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
				};
			};
			class OpticsOut: OpticsOut
			{
				class Monocular: Monocular
				{
					minFov=0.04;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
				};
			};
		};
	};
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_5_Bag"
		};
	};
};


class RC_UAV_AR1_5: RC_UAV_AR1_5_Base
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_UAV_AR1_5_B: RC_UAV_AR1_5
{
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_UAV_AR1_5_O: RC_UAV_AR1_5_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_UAV_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_OPFOR_CO.paa"
	};
	textureList[]=
	{
		"Opfor",
		1
	};
	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_5_Bag_O"
		};
	};
	*/
};
class RC_UAV_AR1_5_I: RC_UAV_AR1_5_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_UAV_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_INDP_CO.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_5_Bag_I"
		};
	};
	*/
};


//AR-3
class RC_UAV_AR3_Base: RC_UAV_AR1_Base
{
	displayName="RC AR-3 longrange";
	RC_UAVBlurRange=0;	//no blur

	class Components: Components
	{
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={4000,2000,1000,500,6000};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="SensorDisplay";
			class components
			{
				class SensorDisplay
				{
					componentType="SensorsDisplayComponent";
					range[]={2000,4000,6000,500,1000};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
				};
			};
		};
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					animDirection="mainGun";
					aimDown=-0.5;

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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;
					maxTrackableSpeed=600;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=1000;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				/*
				class ManSensorComponent: SensorTemplateMan
				{
					maxTrackableSpeed=15;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;
				};
				*/
			};
		};
	};

	class ViewPilot: ViewPilot
	{
		minFov=0.025;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};
	class Viewoptics: Viewoptics
	{
		minFov=0.025;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

			class Components: Components
			{
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500,6000};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="SensorDisplay";
					class components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={2000,4000,6000,500,1000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
						};
					};
				};
			};

			class OpticsIn: OpticsIn
			{
				class Wide: Wide
				{
					minFov=0.025;

					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
				};
			};
			class OpticsOut: OpticsOut
			{
				class Monocular: Monocular
				{
					minFov=0.025;

					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
				};
			};
		};
	};
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR3_Bag"
		};
	};
};


class RC_UAV_AR3: RC_UAV_AR3_Base
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_UAV_AR3_B: RC_UAV_AR3
{
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_UAV_AR3_O: RC_UAV_AR3_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_UAV_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_OPFOR_CO.paa"
	};
	textureList[]=
	{
		"Opfor",
		1
	};
	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR3_Bag_O"
		};
	};
	*/
};
class RC_UAV_AR3_I: RC_UAV_AR3_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\I_UAV_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_INDP_CO.paa"
	};
	textureList[]=
	{
		"Indep",
		1
	};
	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR3_Bag_I"
		};
	};
	*/
};


class Weapon_Bag_Base;
class RC_UAV_AR1_Bag: Weapon_Bag_Base
{
	scope=2;
	scopeCurator=2;

	displayName="RC AR-1";
	maximumLoad=0;
	mass=40;	//>1.4kg UAV + 0.4kg backpack
	mapSize=0.60000002;

	_generalMacro="RC_UAV_AR1_Bag_Arid_Base";
	editorCategory="EdCat_Equipment";
	editorSubcategory="EdSubcat_Backpacks";
	picture="\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_rgr";
	model="\A3\weapons_f\Ammoboxes\bags\Backpack_Fast";

	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_rgr_co.paa"
	};
	class assembleInfo
	{
		displayName="RC AR-1";
		assembleTo="RC_UAV_AR1";
		dissasembleTo[]={};
		base="";
		primary=1;
	};
};
class RC_UAV_AR1_5_Bag: RC_UAV_AR1_Bag
{
	displayName="RC AR-1.5";

	class assembleInfo: assembleInfo
	{
		displayName="RC AR-1.5";
		assembleTo="RC_UAV_AR1_5";
	};
};
class RC_UAV_AR3_Bag: RC_UAV_AR1_Bag
{
	displayName="RC AR-3";

	class assembleInfo: assembleInfo
	{
		displayName="RC AR-3";
		assembleTo="RC_UAV_AR3";
	};
};


/*
class RC_UAV_AR1_Bag_O: RC_UAV_AR1_Bag
{
	displayName="RC AR-1 [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-1 [Opf]";
		assembleTo="RC_UAV_AR1_O";
	};
};
class RC_UAV_AR1_Bag_I: RC_UAV_AR1_Bag
{
	displayName="RC AR-1 [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-1 [Ind]";
		assembleTo="RC_UAV_AR1_I";
	};
};


class RC_UAV_AR1_5_Bag: RC_UAV_AR1_Bag
{
	displayName="RC AR-1.5";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-1.5";
		assembleTo="RC_UAV_AR1_5";
	};
};
class RC_UAV_AR1_5_Bag_O: RC_UAV_AR1_Bag
{
	displayName="RC AR-1.5 [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-1.5 [Opf]";
		assembleTo="RC_UAV_AR1_5_O";
	};
};
class RC_UAV_AR1_5_Bag_I: RC_UAV_AR1_Bag
{
	displayName="RC AR-1.5 [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-1.5 [Ind]";
		assembleTo="RC_UAV_AR1_5_I";
	};
};


class RC_UAV_AR3_Bag: RC_UAV_AR1_Bag
{
	displayName="RC AR-3";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-3";
		assembleTo="RC_UAV_AR3";
	};
};
class RC_UAV_AR3_Bag_O: RC_UAV_AR1_Bag
{
	displayName="RC AR-3 [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-3 [Opf]";
		assembleTo="RC_UAV_AR3_O";
	};
};
class RC_UAV_AR3_Bag_I: RC_UAV_AR1_Bag
{
	displayName="RC AR-3 [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC AR-3 [Ind]";
		assembleTo="RC_UAV_AR3_I";
	};
};
*/