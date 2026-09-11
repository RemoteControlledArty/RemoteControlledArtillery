class B_UAV_05_F;
class RC_UCAV_Fetch: B_UAV_05_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class UserActions;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_UCAV_Core: RC_UCAV_Fetch
{
	class EventHandlers: EventHandlers
	{
		class RC_FlyInHeight
		{
			//defines default flyInHeight, preventing major problems like UAV dropping to 50m when changing locality between players, or to server when player has a disconnect
			//4000m = SOP for large stealth fixed wing drones
			postInit="params ['_entity'];  if (!isServer) exitwith {};  _entity flyInHeight 4000;";
		};
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\DetectInterceptorEH.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator_EH.hpp"
		#include "\Remote_Controlled_Artillery\includes_script\AT_Warning_EH.hpp"
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	editorSubcategory="RC_UAV_Designator_subcat";

	unitInfoType="RC_RscOptics_AV_Heli";	//RC_RscOptics_AV_Heli
	unitInfoTypeRTD="RC_RscOptics_AV_Heli";	//RC_RscOptics_AV_Heli
	driverWeaponsInfoType="RscOptics_CAS_01_TGP";
	driverOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
	weapons[]+={"Laserdesignator_pilotCamera"};
	magazines[]+={"Laserbatteries"};

	class Viewoptics: ViewOptics
	{
		initFov=1.5;
		maxFov=1.5;
		minFov=0.125;

		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[]={0};
	};

	class pilotCamera
	{
		controllable=1;				//can turn camera
		pilotOpticsShowCursor=1;	//?
		//directionStabilized=1;
		stabilizedInAxes=3;

		minTurn=-360;
		maxTurn=360;
		initTurn=0;
		minElev=-45;
		maxElev=90;
		initElev=0;
		maxMouseXRotSpeed=0.25;		//0.5
		maxMouseYRotSpeed=0.25;		//0.5

		class OpticsIn
		{
			class Wide
			{
				opticsDisplayName="Cam";

				directionStabilized=1;
				stabilizedInAxes=3;

				minFov=0.02;
				maxFov=1.5;
				initFov=1.5;
				
				initAngleX=0;
				minAngleX=0;
				maxAngleX=0;
				initAngleY=0;
				minAngleY=0;
				maxAngleY=0;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={0};
				gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
			};
			showMiniMapInOptics=1;			//alterative to cTab to follow path
			showUAVViewpInOptics=1;			//remove for optionally manned version
			showSlingLoadManagerInOptics=1;
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
					range[]={16000,8000,4000};
					resource="RscCustomInfoSensors";
				};
				class MinimapDisplay
				{
					componentType="MinimapDisplayComponent";
					resource="RscCustomInfoAirborneMiniMap";
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
					range[]={4000,8000,16000};
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
							range[]={16000,8000,4000};
							resource="RscCustomInfoSensors";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoAirborneMiniMap";
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
							range[]={4000,8000,16000};
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
		};
	};
};


class RC_UCAV_Base: RC_UCAV_Core
{
	displayName="RC UCAV";

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
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=16000;

					class AirTarget
					{
						minRange=16000;
						maxRange=16000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=16000;
						maxRange=16000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=5000;
					maxTrackableSpeed=600;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=2500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
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
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
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
			maxElev=45;

			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="W";
					initAngleX=0;
					minAngleX=-35;
					maxAngleX=85;
					initAngleY=0;
					minAngleY=-130;
					maxAngleY=130;
					initFov=1.0;
					minFov=0.0125;
					maxFov=1.0;
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
			};
		};
	};
	/*
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"Laserdesignator_mounted",
				"RC_FPV_Deployer"
			};
			magazines[]=
			{
				"Laserbatteries",
				"RC_8xFPV_Deployer_Mag"
			};
		};
	};
	*/
};
class RC_UCAV_B: RC_UCAV_Base
{
	/*
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	*/

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_UCAV_O: RC_UCAV_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_UCAV_I: RC_UCAV_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};


class RC_UCAV_NoCam_Base: RC_UCAV_Core
{
	displayName="RC UCAV [no camera]";

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
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=6000;
						maxRange=6000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=16000;

					class AirTarget
					{
						minRange=16000;
						maxRange=16000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=16000;
						maxRange=16000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
			};
		};
	};

	class Viewoptics: ViewOptics
	{
		minFov=0.25;	//1x
	};
	class pilotCamera: pilotCamera
	{
		class OpticsIn: OpticsIn
		{
			class Wide: Wide
			{
				minFov=0.25;	//1x
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			/*
			weapons[]=
			{
				"RC_FPV_Deployer"
			};
			magazines[]=
			{
				"RC_8xFPV_Deployer_Mag"
			};
			*/

			stabilizedInAxes=0;
			minElev=-67.5;
			maxElev=-67.5;
			initElev=-67.5;
			minTurn=0;
			maxTurn=0;
			initTurn=0;
			gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
			turretInfoType="";

			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="W";
					initAngleX=0;
					minAngleX=-35;
					maxAngleX=85;
					initAngleY=0;
					minAngleY=-130;
					maxAngleY=130;
					initFov=1.0;
					minFov=1.0;
					maxFov=1.0;
					directionStabilized=0;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
				};
			};
		};
	};
};
class RC_UCAV_NoCam_B: RC_UCAV_NoCam_Base
{
	/*
	scope=2;
	scopeCurator=2;
	forceInGarage=1;
	*/

	#include "\Remote_Controlled_Artillery\includes_cfg\sideB_UV.hpp"
};
class RC_UCAV_NoCam_O: RC_UCAV_NoCam_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideO_UV.hpp"
};
class RC_UCAV_NoCam_I: RC_UCAV_NoCam_B
{
	#include "\Remote_Controlled_Artillery\includes_cfg\sideI_UV.hpp"
};
