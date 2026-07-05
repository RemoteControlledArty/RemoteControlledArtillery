class RC_UAV_FPV_Base: RC_UAV_base
{
	class EventHandlers: EventHandlers
	{
		//defines default flyInHeight, preventing major problems like UAV dropping to 50m when changing locality between players, or to server when player has a disconnect
		class RC_FlyInHeight
		{
			//200m = SOP for FPV drones (if no C-UAS in area)
			postInit="params ['_entity'];  if (!isServer) exitwith {};  _entity flyInHeight 200;";
		};
	};

	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

	displayName="RC FPV 4km";
	editorSubcategory="RC_UAV_Designator_subcat";

	RC_UAVBlurRange=3000;
	fuelExplosionPower=25;

	uavCameraGunnerPos="";
	uavCameraGunnerDir="";

	maxSpeed=200;
	liftForceCoef=1.5;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	backRotorForceCoef=5;	//10
	fuelCapacity=200;
	mainRotorSpeed=-7;	//14
	backRotorSpeed=7;	//14

	camouflage=0.1;	//0.5
	audible=0.1;	//0.1
	radarTargetSize=0.035;	//0.1
	visualTargetSize=0.1;	//0.1

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
		//#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
		initFov=1.25;

		visionMode[]=
		{
			"Normal",
			"NVG"
		};
	};
	class Viewoptics: ViewOptics
	{
		//#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
		initFov=1.25;

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
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//mainGun
					aimDown=0;	//-0.5

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
					typeRecognitionDistance=500;
					maxTrackableSpeed=600;
					nightRangeCoef=0.67;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//mainGun
					aimDown=0;	//-0.5

					class AirTarget
					{
						minRange=500;
						maxRange=500;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=500;
						maxRange=500;
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


class RC_UAV_FPV: RC_UAV_FPV_Base
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_UAV_FPV_B: RC_UAV_FPV
{
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_UAV_FPV_O: RC_UAV_FPV_B
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
			"RC_UAV_FPV_Bag_O"
		};
	};
	*/
};
class RC_UAV_FPV_I: RC_UAV_FPV_B
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
			"RC_UAV_FPV_Bag_I"
		};
	};
	*/
};


class RC_UAV_FPV_Bag: RC_UAV_AR1_Bag
{
	displayName="RC FPV";
	mass=60;
	
	class assembleInfo: assembleInfo
	{
		displayName="RC FPV";
		assembleTo="RC_UAV_FPV";
	};
};


/*
class RC_UAV_FPV_Bag: RC_UAV_AR1_Bag
{
	displayName="RC FPV";
	mass=180;	//>8kg
	class assembleInfo: assembleInfo
	{
		displayName="RC FPV";
		assembleTo="RC_UAV_FPV";
	};
};
class RC_UAV_FPV_Bag_O: RC_UAV_FPV_Bag
{
	displayName="RC FPV [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC FPV [Opf]";
		assembleTo="RC_UAV_FPV_O";
	};
};
class RC_UAV_FPV_Bag_I: RC_UAV_FPV_Bag
{
	displayName="RC FPV [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC FPV [Ind]";
		assembleTo="RC_UAV_FPV_I";
	};
};
*/