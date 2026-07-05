class C_IDAP_UAV_06_antimine_F;
class RC_GrenadeDropper_Fetch: C_IDAP_UAV_06_antimine_F
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
	class EventHandlers;
	scope=0;
	scopeCurator=0;

	RC_UAVBlurRange=3000;
	RC_assembleSideSwitch=1;	//neutral side backpack assembled into drone of the assembling players side
	RC_assembleAutonomousOff=0;
	RC_Local=1; //1 = requires transfer of locality/ownership for full functionality
};
class RC_GrenadeDropper_Base: RC_GrenadeDropper_Fetch
{
	class EventHandlers: EventHandlers
	{
		//defines default flyInHeight, preventing major problems like UAV dropping to 50m when changing locality between players, or to server when player has a disconnect
		class RC_FlyInHeight
		{
			//test out what should be SOP height
			postInit="params ['_entity'];  if (!isServer) exitwith {};  _entity flyInHeight 200;";
		};
	};
			
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

	displayName="RC Grenade Dropper 4km";
	editorSubcategory="RC_UAV_Designator_subcat";

	radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	camouflage=0.1;
	audible=0.1;
	radarTargetSize=0.035;
	visualTargetSize=0.1;
	fuelCapacity=200;

	class PilotCamera: PilotCamera
	{
		#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"

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
					range[]={3000,1500,750,350};
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
					range[]={350,750,1500,3000};
					resource="RscCustomInfoSensors";
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
				class EmptyDisplay
				{
					componentType="EmptyDisplayComponent";
				};
			};
		};
	};
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Bag"
		};
	};
};


class RC_GrenadeDropper: RC_GrenadeDropper_Base
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_GrenadeDropper_B: RC_GrenadeDropper
{
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_GrenadeDropper_O: RC_GrenadeDropper_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Bag_O"
		};
	};
	*/
};
class RC_GrenadeDropper_I: RC_GrenadeDropper_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Bag_I"
		};
	};
	*/
};


//fitting larger neutral olive backpack
class B_UAV_06_backpack_F;
class RC_GrenadeDropper_Bag: B_UAV_06_backpack_F
{
	scope=2;
	scopeCurator=2;

	displayName="RC Grenade Dropper";
	maximumLoad=0;
	mass=120;

	class assembleInfo
	{
		displayName="RC Grenade Dropper";
		assembleTo="RC_GrenadeDropper";
		dissasembleTo[]={};
		base="";
		primary=1;
	};
};


/*
class RC_GrenadeDropper_Bag: RC_Weapon_Bag_Base
{
	scope=2;
	scopeCurator=2;
	DLC="Orange";

	displayName="RC Grenade Dropper";
	maximumLoad=0;
	mass=300;
	mapSize=0.63999999;

	editorCategory="EdCat_Equipment";
	editorSubcategory="EdSubcat_Backpacks";
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
*/


//with Sensor
class RC_GrenadeDropper_Sens_Base: RC_GrenadeDropper_Base
{
	displayName="RC Grenade Dropper Sensor 4km";

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
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
				class VisualSensorComponent: SensorTemplateVisual
				{
					typeRecognitionDistance=350;
					maxTrackableSpeed=600;
					nightRangeCoef=0.8;
					angleRangeHorizontal=45;
					angleRangeVertical=90;
					animDirection="";
					aimDown=0;	//-1

					class AirTarget
					{
						minRange=350;
						maxRange=350;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=350;
						maxRange=350;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
				class NVSensorComponent: SensorTemplateNV
				{
					typeRecognitionDistance=3000;
					maxTrackableSpeed=450;
					angleRangeHorizontal=45;
					angleRangeVertical=90;
					animDirection="";
					aimDown=0;

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
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=1;
					maxTrackableSpeed=15;
					nightRangeCoef=0.8;
					angleRangeHorizontal=45;
					angleRangeVertical=90;
					animDirection=""; //aligned with body	//pip_pilot_dir or pip_pilot_pos doesnt work
					aimDown=0;	//-1

					class AirTarget
					{
						minRange=200;
						maxRange=200;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=200;
						maxRange=200;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Sens_Bag"
		};
	};
};


class RC_GrenadeDropper_Sens: RC_GrenadeDropper_Sens_Base
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class RC_GrenadeDropper_Sens_B: RC_GrenadeDropper_Sens
{
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	crew="B_UAV_AI";
	side=1;
};
class RC_GrenadeDropper_Sens_O: RC_GrenadeDropper_Sens_B
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Sens_Bag_O"
		};
	};
	*/
};
class RC_GrenadeDropper_Sens_I: RC_GrenadeDropper_Sens_B
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_GrenadeDropper_Sens_Bag_I"
		};
	};
	*/
};


class RC_GrenadeDropper_Sens_Bag: RC_GrenadeDropper_Bag
{
	displayName="RC Grenade Dropper Sensor";

	class assembleInfo: assembleInfo
	{
		displayName="RC Grenade Dropper Sensor";
		assembleTo="RC_GrenadeDropper_Sens";
	};
};


/*
class RC_GrenadeDropper_Sens_Bag: RC_GrenadeDropper_Bag
{
	displayName="RC Grenade Dropper Sens";
	class assembleInfo: assembleInfo
	{
		displayName="RC Grenade Dropper Sens";
		assembleTo="RC_GrenadeDropper_Sens";
	};
};
class RC_GrenadeDropper_Sens_Bag_O: RC_GrenadeDropper_Sens_Bag
{
	displayName="RC Grenade Dropper Sens [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Grenade Dropper Sens [Opf]";
		assembleTo="RC_GrenadeDropper_Sens_O";
	};
};
class RC_GrenadeDropper_Sens_Bag_I: RC_GrenadeDropper_Sens_Bag
{
	displayName="RC Grenade Dropper Sens [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Grenade Dropper Sens [Ind]";
		assembleTo="RC_GrenadeDropper_Sens_I";
	};
};
*/