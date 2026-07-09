class O_T_UAV_04_CAS_F;
class RC_FPV_Mothership_Core: O_T_UAV_04_CAS_F
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
class RC_FPV_Mothership_Base: RC_FPV_Mothership_Core
{
	class EventHandlers: EventHandlers
	{
		//defines default flyInHeight, preventing major problems like UAV dropping to 50m when changing locality between players, or to server when player has a disconnect
		class RC_FlyInHeight
		{
			//2000m = SOP for large fixed wing drones
			postInit="params ['_entity'];  if (!isServer) exitwith {};  _entity flyInHeight 2000;";
		};
		class RC_FPV_Deployer
		{
			#include "\Remote_Controlled_Artillery\includes_script\addToDeployerArray.hpp"
		};
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\DetectInterceptorEH.hpp"
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";

	camouflage=100;					//0.25 or 150
	radarTargetSize=0.33;			//0.5
	visualTargetSize=0.47;			//0.7
	irTargetSize=0.33;				//0.5

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
					range[]={6000,3000};
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
					range[]={3000,6000};
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
					typeRecognitionDistance=8000;

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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=3000;
					maxTrackableSpeed=600;
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
						minRange=2500;
						maxRange=2500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2500;
						maxRange=2500;
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

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
					minFov=0.03;
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
					//gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
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
							range[]={6000,3000};
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
							range[]={3000,6000};
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


class RC_FPV_Mothership: RC_FPV_Mothership_Base
{
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

	displayName="RC FPV Mothership";
	editorSubcategory="RC_UAV_Deployers_subcat";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_FPV_Mothership_O: RC_FPV_Mothership
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_FPV_Mothership_I: RC_FPV_Mothership
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_FPV_Mothership_NoCam: RC_FPV_Mothership
{
	displayName="RC FPV Mothership [no camera]";

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
						"NVG"
					};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
				};
			};
		};
	};

	class Viewoptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

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

					animDirection="mainGun";
					angleRangeHorizontal=120;
					angleRangeVertical=120;
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=8000;

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
};
class RC_FPV_Mothership_NoCam_O: RC_FPV_Mothership_NoCam
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_FPV_Mothership_NoCam_I: RC_FPV_Mothership_NoCam
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class B_UAV_02_CAS_F;
class RC_FPV_MothershipMQ_Core: B_UAV_02_CAS_F
{
	class Turrets;
	class MainTurret;
	class ViewOptics;
	class ViewPilot;
	class Components;
	class EventHandlers;
	scope=0;
	scopeCurator=0;
	//RC_UAVBlurRange=2000;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_FPV_MothershipMQ_Base: RC_FPV_MothershipMQ_Core
{
	class EventHandlers: EventHandlers
	{
		class RC_Detection
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_SourceIndicator.hpp"
		};
		class RC_AT_Warning
		{
			#include "\Remote_Controlled_Artillery\includes_script\AT_Warning.hpp"
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\Systems.hpp"
	#include "\Remote_Controlled_Artillery\includes_cfg\MissleApproachWarning.hpp"
	lockDetectionSystem="2+4+8";

	author="Ascent";
	editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_UAV_02_dynamicLoadout_F.jpg";

	camouflage=100;					//0.25 or 150
	radarTargetSize=0.33;			//0.5
	visualTargetSize=0.47;			//0.7
	irTargetSize=0.33;				//0.5

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
					range[]={6000,3000};
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
					range[]={3000,6000};
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
					typeRecognitionDistance=8000;

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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=3000;
					maxTrackableSpeed=600;
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
						minRange=2500;
						maxRange=2500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=2500;
						maxRange=2500;
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

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

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
					minFov=0.03;
					maxFov=1.0;
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
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
							range[]={6000,3000};
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
							range[]={3000,6000};
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


class RC_FPV_MothershipMQ: RC_FPV_MothershipMQ_Base
{
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

	displayName="RC FPV Mothership";
	editorSubcategory="RC_UAV_Deployers_subcat";
	//scope=2;	//until weapon in rc crocus config is put to main
	//scopeCurator=2;
	
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_FPV_MothershipMQ_O: RC_FPV_MothershipMQ
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_FPV_MothershipMQ_I: RC_FPV_MothershipMQ
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};



class RC_FPV_MothershipMQ_NoCam: RC_FPV_MothershipMQ
{
	displayName="RC FPV Mothership [no camera]";

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
						"NVG"
					};
					gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
				};
			};
		};
	};

	class Viewoptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};

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

					animDirection="mainGun";
					angleRangeHorizontal=120;
					angleRangeVertical=120;
				};
				class DataLinkSensorComponent: SensorTemplateDataLink
				{
					typeRecognitionDistance=8000;

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
};
class RC_FPV_MothershipMQ_NoCam_O: RC_FPV_MothershipMQ_NoCam
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_FPV_MothershipMQ_NoCam_I: RC_FPV_MothershipMQ_NoCam
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_Interceptor_Mothership_Base: RC_FPV_Mothership_Base
{
	class EventHandlers: EventHandlers
	{
		class RC_DeleteOutCrew
		{
			GetOut="params ['_vehicle', '_role', '_unit'];	if (vehicle _unit isEqualTo _unit) then {deleteVehicle _unit;};";
		};
		class RC_Interceptability
		{
			#include "\Remote_Controlled_Artillery\includes_script\firedInterceptorEH.hpp"
		};
	};

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
					typeRecognitionDistance=6000;

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
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=400;

					class AirTarget
					{
						minRange=400;
						maxRange=400;
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
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=360;
					angleRangeVertical=360;
					animDirection="";
				};
				class IRSensorComponent: SensorTemplateIR
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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;	//30
					angleRangeVertical=60;		//30
					animDirection="mainGun";
				};
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
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
				class ActiveRadarSensorComponent: SensorTemplateActiveRadar
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
					typeRecognitionDistance=4000;
					angleRangeHorizontal=360;
					angleRangeVertical=100;
					aimDown=-45;
					maxTrackableSpeed=694.44397;
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			weapons[]=
			{
				"Laserdesignator_mounted",
				"RC_InterceptorLauncher"
			};
			magazines[]=
			{
				"Laserbatteries",
				
				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m",

				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m",
				"RC_1Rnd_InterceptorDrop_Direct_1m"
			};
		};
	};

	displayName="RC AA-Interceptor Mothership";
	editorSubcategory="RC_AntiAir_subcat";
};
class RC_Interceptor_Mothership: RC_Interceptor_Mothership_Base
{
	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;

	scope=1;		//2
	scopeCurator=0;	//2
};
class RC_Interceptor_Mothership_O: RC_Interceptor_Mothership
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
};
class RC_Interceptor_Mothership_I: RC_Interceptor_Mothership
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
};


class RC_AI_Interceptor_Mothership: RC_Interceptor_Mothership
{
	displayName="AA-Interceptor Mothership";
	isUav=0;
	
	crew="RC_B_HeliPilot";
};
class RC_AI_Interceptor_Mothership_O: RC_AI_Interceptor_Mothership
{
	faction="RemoteControlled_O";
	crew="RC_B_HeliPilot";
	side=0;
};
class RC_AI_Interceptor_Mothership_I: RC_AI_Interceptor_Mothership
{
	faction="RemoteControlled_I";
	crew="RC_B_HeliPilot";
	side=2;
};