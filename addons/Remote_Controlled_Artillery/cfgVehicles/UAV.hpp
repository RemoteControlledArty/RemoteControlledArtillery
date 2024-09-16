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
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	RC_UAVBlurRange=2000;
};
class RC_UAV_AR1: RC_UAV_base
{
	displayName="RC AR-1 shortrange 2km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=2;
	scopeCurator=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag"
		};
	};

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
					range[]={3000,1500,750};
					resource="RscCustomInfoSensors";
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
					typeRecognitionDistance=1000;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

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
			showAllTargets="2 + 4";
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
							range[]={3000,1500,750};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";
					class components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
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
};
class RC_UAV_AR1_O: RC_UAV_AR1
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
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag_O"
		};
	};
};
class RC_UAV_AR1_I: RC_UAV_AR1
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
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR1_Bag_I"
		};
	};
};


class RC_UAV_FPV: RC_UAV_base
{
	displayName="RC FPV 4km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=2;
	scopeCurator=2;
	RC_UAVBlurRange=3000;
	fuelExplosionPower=25;
	showAllTargets="2 + 4";

	maxSpeed=200;
	liftForceCoef=2;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	backRotorForceCoef=10;
	fuelCapacity=200;
	mainRotorSpeed=-14;
	backRotorSpeed=14;

	camouflage=0.025;
	radarTargetSize=0.01;
	visualTargetSize=0.005;
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	weapons[]=
	{
		"RC_target_confirmer"
	};
	magazines[]=
	{
		"RC_target_confirmer_mag"
	};

	class ViewPilot: ViewPilot
	{
		showAllTargets="2 + 4";

		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};
	class Viewoptics: ViewOptics
	{
		showAllTargets="2 + 4";

		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

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
					range[]={4000,2000,1000,500};
					resource="RscCustomInfoSensors";
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
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=800;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=800;
						maxRange=800;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
			};
		};
	};

	//no turret camera
	class Turrets {};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_FPV_Bag"
		};
	};
};
class RC_UAV_FPV_O: RC_UAV_FPV
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
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_FPV_Bag_O"
		};
	};
};
class RC_UAV_FPV_I: RC_UAV_FPV
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
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_FPV_Bag_I"
		};
	};
};


//AR-3
class RC_UAV_AR3: RC_UAV_AR1
{
	displayName="RC AR-3 longrange";
	RC_UAVBlurRange=0;	//no blur

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR3_Bag"
		};
	};

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
					range[]={3000,1500,750};
					resource="RscCustomInfoSensors";
				};
			};
		};
		class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
		{
			defaultDisplay="EmptyDisplay";
			class components
			{
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
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
			showAllTargets="2 + 4";

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
							range[]={3000,1500,750};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";
					class components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
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
};
class RC_UAV_AR3_O: RC_UAV_AR3
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
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR3_Bag_O"
		};
	};
};
class RC_UAV_AR3_I: RC_UAV_AR3
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
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_AR3_Bag_I"
		};
	};
};


class Weapon_Bag_Base;
class RC_Weapon_Bag_Base: Weapon_Bag_Base
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_UAV_AR1_Bag: RC_Weapon_Bag_Base
{
	mapSize=0.60000002;
	_generalMacro="RC_UAV_AR1_Bag_Arid_Base";
	scope=2;
	scopeCurator=2;
	displayName="RC AR-1";
	editorCategory="EdCat_Equipment";
	editorSubcategory="EdSubcat_Backpacks";
	picture="\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_rgr";
	model="\A3\weapons_f\Ammoboxes\bags\Backpack_Fast";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_rgr_co.paa"
	};
	maximumLoad=0;
	mass=300;
	class assembleInfo: assembleInfo
	{
		base="";
		displayName="RC AR-1";
		assembleTo="RC_UAV_AR1";
	};
};
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


class RC_UAV_FPV_Bag: RC_UAV_AR1_Bag
{
	displayName="RC FPV";
	class assembleInfo: assembleInfo
	{
		displayName="RC FPV";
		assembleTo="RC_UAV_FPV";
	};
};
class RC_UAV_FPV_Bag_O: RC_UAV_AR1_Bag
{
	displayName="RC FPV [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC FPV [Opf]";
		assembleTo="RC_UAV_FPV_O";
	};
};
class RC_UAV_FPV_Bag_I: RC_UAV_AR1_Bag
{
	displayName="RC FPV [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC FPV [Ind]";
		assembleTo="RC_UAV_FPV_I";
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
class RC_UAV_AR3_Bag_O: RC_UAV_AR3_Bag
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


class C_IDAP_UAV_06_antimine_F;
class RC_GrenadeDropper_Base: C_IDAP_UAV_06_antimine_F
{
	class PilotCamera;
	class OpticsIn;
	class Wide;
	class ViewPilot;
	class ViewOptics;
	class assembleInfo;
	class Components;
	//class TransportPylonsComponent;
	//class pylons;
	//class pylons1;
	scope=0;
	scopeCurator=0;
	RC_UAVBlurRange=3000;
};
class RC_GrenadeDropper: RC_GrenadeDropper_Base
{
	displayName="RC Grenade Dropper 4km";
	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	crew="B_UAV_AI";
	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	camouflage=0.125;
	radarTargetSize=0.025;
	visualTargetSize=0.025;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Bag"
		};
	};

	class PilotCamera: PilotCamera
	{
		class OpticsIn: OpticsIn
		{
			class Wide: Wide
			{
				initFov=1;
				minFov=0.45;
				maxFov=1;

				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
		};
		pilotOpticsShowCursor=1;
		controllable=1;
	};
	class ViewPilot: ViewPilot
	{
		initFov=1;
		minFov=0.45;
		maxFov=1;
	};
	class Viewoptics: ViewOptics
	{
		initFov=1;
		minFov=0.45;
		maxFov=1;

		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

	class Components: Components
	{
		/*
		class TransportPylonsComponent: TransportPylonsComponent
		{
			class pylons: pylons
			{
				class pylons1: pylons1
				{
					hardpoints[]=
					{
						"ANTIMINE_DRONE_PYLON"
					};
					attachment="RC_PylonRack_4Rnd_BombDemine_01_F";
				};
			};
		};
		*/
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
			};
		};
		class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
		{
			defaultDisplay="SensorDisplay";
			class components
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
			defaultDisplay="EmptyDisplay";
			class components
			{
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
				};
				class MineDetectorDisplay
				{
					componentType="MineDetectorDisplayComponent";
					range=50;
					resource="RscCustomInfoMineDetect";
				};
			};
		};
	};
};
class RC_GrenadeDropper_O: RC_GrenadeDropper
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Bag_O"
		};
	};
};
class RC_GrenadeDropper_I: RC_GrenadeDropper
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Bag_I"
		};
	};
};


class RC_GrenadeDropper_Bag: RC_Weapon_Bag_Base
{
	mapSize=0.63999999;
	displayName="RC Grenade Dropper";
	scope=2;
	scopeCurator=2;

	DLC="Orange";
	editorCategory="EdCat_Equipment";
	editorSubcategory="EdSubcat_Backpacks";
	maximumLoad=0;
	mass=300;
	picture="\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_rgr";
	model="\A3\weapons_f\Ammoboxes\bags\Backpack_Fast";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_rgr_co.paa"
	};
	class assembleInfo: assembleInfo
	{
		base="";
		displayName="RC Grenade Dropper";
		assembleTo="RC_GrenadeDropper";
	};
};
class RC_GrenadeDropper_Bag_O: RC_GrenadeDropper_Bag
{
	displayName="RC Grenade Dropper [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Grenade Dropper [Opf]";
		assembleTo="RC_GrenadeDropper_O";
	};
};
class RC_GrenadeDropper_Bag_I: RC_GrenadeDropper_Bag
{
	displayName="RC Grenade Dropper [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Grenade Dropper [Ind]";
		assembleTo="RC_GrenadeDropper_I";
	};
};