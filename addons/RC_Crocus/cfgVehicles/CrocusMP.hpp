class B_Crocus_AT;
class B_Crocus_MP_Base: B_Crocus_AT
{
	scope=0;
	scopeCurator=0;
	class EventHandlers;
	class Components;
};
class B_Crocus_MP: B_Crocus_MP_Base
{
	author="Ascent";	//all credits to the original maker, this is only an edit and soft-depends on the original mod
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

	camouflage=0.025;	//0.5
	audible=0.075;	//0.1
	radarTargetSize=0.035;	//0.1
	visualTargetSize=0.075;	//0.1
	
	liftForceCoef=1.5;	//1
	maxSpeed=200;	//140

	/*
	//Crocus
	cyclicAsideForceCoef=2;	//2
	cyclicForwardForceCoef=2;	//2
	mainRotorSpeed=-7;	//-7
	backRotorSpeed=7;	//7
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

	weapons[]=
	{
		"RC_target_confirmer_AB_weapon"
	};
	magazines[]=
	{
		"RC_target_confirmer_AB_mag"
	};

	class EventHandlers: EventHandlers
	{
		class RC_Crocus
		{
			fired="_this call RC_fnc_fpv_onDestroy_MP";
			hit="_this call RC_fnc_fpv_onDestroy_MP";
			init="(_this # 0) spawn RC_fnc_fpv_droneInit_MP;";
		};
		class ArmaFPV {};
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
					animDirection="";	//aligned with body
					aimDown=0;	//-1

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
			};
		};
	};

	class assembleInfo
	{
		primary=0;
		base="";
		assembleTo="";
		dissasembleTo[]=
		{
			"B_Crocus_MP_Bag"
		};
		displayName="";
	};
};
class O_Crocus_MP: B_Crocus_MP
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_MP_Bag"
		};
	};
};
class I_Crocus_MP: B_Crocus_MP
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_MP_Bag"
		};
	};
};


class RC_UAV_AR1_Bag;
class B_Crocus_MP_Bag: RC_UAV_AR1_Bag
{
	scope=2;
	scopeCurator=2;
	displayName="Crocus MP Bag";
	mass=180;	//>8kg

	class assembleInfo
	{
		assembleTo="B_Crocus_MP";
		base="";
		displayName="Crocus MP";
		dissasembleTo[]={};
		primary=1;
	};
};
class O_Crocus_MP_Bag: B_Crocus_MP_Bag
{
	displayName="Crocus MP Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_MP";
		displayName="Crocus MP [Opf]";
	};
};
class I_Crocus_MP_Bag: B_Crocus_MP_Bag
{
	displayName="Crocus MP Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_MP";
		displayName="Crocus MP [Ind]";
	};
};


class B_Crocus_MP_Sens: B_Crocus_MP
{
	displayName="Crocus MP Sens";

	class Components: Components
	{
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
					animDirection="";	//aligned with body
					aimDown=0;	//-1

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
					typeRecognitionDistance=350;
					maxTrackableSpeed=600;
					nightRangeCoef=0.67;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//aligned with body
					aimDown=0;	//-1

					class AirTarget
					{
						minRange=500;
						maxRange=500;
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
				/*
				//cannot be limited in range, so it would be too op
				class ManSensorComponent: SensorTemplateMan
				{
					maxTrackableSpeed=15;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";
					aimDown=0;
				};
				*/
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"B_Crocus_MP_Sens_Bag"
		};
	};
};
class O_Crocus_MP_Sens: B_Crocus_MP_Sens
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_MP_Bag"
		};
	};
};
class I_Crocus_MP_Sens: B_Crocus_MP_Sens
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_MP_Bag"
		};
	};
};


class B_Crocus_MP_Sens_Bag: B_Crocus_MP_Bag
{
	displayName="Crocus MP Sens Bag";

	class assembleInfo: assembleInfo
	{
		assembleTo="B_Crocus_MP_Sens";
		displayName="Crocus MP Sens";
	};
};
class O_Crocus_MP_Sens_Bag: B_Crocus_MP_Sens_Bag
{
	displayName="Crocus MP Sens Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_MP_Sens";
		displayName="Crocus MP Sens [Opf]";
	};
};
class I_Crocus_MP_Sens_Bag: B_Crocus_MP_Sens_Bag
{
	displayName="Crocus MP Sens Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_MP_Sens";
		displayName="Crocus MP Sens [Ind]";
	};
};