class B_Crocus_AT: B_Crocus_Base
{
	author="Ascent";
	displayName="Crocus MP";
	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=2;
	scopeCurator=2;
	side=1;
	forceInGarage=1;

	fuelCapacity=14;	//8.5

	enableGPS=1;
	//radartype=2;
	reportOwnPosition=1;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	showAllTargets="2 + 4";
	
	liftForceCoef=2;	//1
	/*
	maxSpeed=180;	//140
	cyclicAsideForceCoef=2;	//2
	cyclicForwardForceCoef=2.4;	//2
	mainRotorSpeed=-14;	//-7
	backRotorSpeed=14;	//7
	backRotorForceCoef=5;	//5
	*/

	/*
	//AL-6

	liftForceCoef=1.6;
	cyclicAsideForceCoef=2.75;
	cyclicForwardForceCoef=0.58999997;
	bodyFrictionCoef=0.57999998;
	backRotorForceCoef=4.5;
	epeImpulseDamageCoef=1.5;
	maxMainRotorDive=0;
	minMainRotorDive=0;
	neutralMainRotorDive=0;
	tailBladeVertical=0;
	gearRetracting=0;
	mainRotorSpeed=-7;
	backRotorSpeed=7;
	*/

	camouflage=0.025;	//0.5
	audible=0.025;	//0.1
	radarTargetSize=0.025;	//0.1
	visualTargetSize=0.025;	//0.1

	weapons[]=
	{
		"RC_target_confirmer_AB"
	};
	magazines[]=
	{
		"RC_target_confirmer_AB_mag"
	};

	class EventHandlers: EventHandlers
	{
		class RC_Artillery
		{
			//fired="(_this select 0) setDamage 1;";
			fired="_this call DB_fnc_fpv_onDestroy";
		};
	};

	/*
	class ViewPilot: ViewPilot
	{
		minFov=0.25;
		maxFov=1.25;
		initFov=1;
		initAngleX=0;
		minAngleX=-65;
		maxAngleX=85;
		initAngleY=0;
		minAngleY=-150;
		maxAngleY=150;
	};
	class Viewoptics: ViewOptics
	{
		initAngleX=0;
		minAngleX=0;
		maxAngleX=0;
		initAngleY=0;
		minAngleY=0;
		maxAngleY=0;
		minFov=1.25;
		maxFov=1.25;
		initFov=1.25;
		visionMode[]=
		{
			"Normal"
		};
		thermalMode[]={0,1};
	};
	*/
	class Viewoptics: ViewOptics
	{
		showAllTargets="2 + 4";
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
					typeRecognitionDistance=600;
					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
					aimDown=-0.5;

					class AirTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=600;
						maxRange=600;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};
			};
		};
	};

	class assembleInfo
	{
		assembleTo="";
		dissasembleTo[]=
		{
			"RC_Crocus_MP_Bag"
		};
		displayName="";
	};
};

class B_Crocus_AT_Bag;
class RC_Crocus_MP_Bag: B_Crocus_AT_Bag
{
	displayName="Crocus MP Bag";
	author="Ascent";

	class assembleInfo
	{
		assembleTo="B_Crocus_AT";
		base="";
		displayName="Crocus MP";
		dissasembleTo[]={};
		primary=1;
	};

	picture="\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_rgr";
	model="\A3\weapons_f\Ammoboxes\bags\Backpack_Fast";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_rgr_co.paa"
	};
};

/*
class Land_SatelliteAntenna_01_F;
	class FPV_Retranslator: Land_SatelliteAntenna_01_F
	{
		scope=2;
		scopeCurator=2;
		displayName="Signal Booster";
	};
*/
class B_CrocusRepeater_Bag: RC_Crocus_MP_Bag
{
	displayName="Crocus-Repeater Bag";

	class assembleInfo
	{
		assembleTo="FPV_Retranslator";
		base="";
		displayName="Crocus MP";
		dissasembleTo[]={};
		primary=1;
	};

	picture="\A3\Weapons_F\ammoboxes\bags\data\ui\icon_B_C_Kitbag_rgr";
	model="\A3\weapons_f\Ammoboxes\bags\Backpack_Fast";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_fast_rgr_co.paa"
	};
};