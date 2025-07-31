class RC_UAV_FPV_Velocity_Base: RC_UAV_base
{
	scope=2;
	scopeCurator=2;

	class CargoTurret;
};
class RC_UAV_FPV_Velocity: RC_UAV_FPV_Velocity_Base
{
	#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
	displayName="Velocity FPV";
	faction="RemoteControlled_B";
	editorSubcategory="RC_UAV_Designator_subcat";
	scope=2;
	scopeCurator=2;
	RC_UAVBlurRange=3000;
	fuelExplosionPower=25;

	//detectSkill = 20;
	//maxDetectRange = 20;

	/*
	maxGForce = 2;
	minGForce = 0.2;	
	reversed = 1;
	sensitivity = 2.5;
	*/
	startDuration = 1;

	/*
	weaponsGroup1 = "1 + 		2";
	weaponsGroup2 = 4;	
	weaponsGroup3 = "8 + 	16 + 	32";
	weaponsGroup4 = "64 + 		128";
	weaponSlots = 0;
	*/

	/*
	airBrakeFrictionCoef = 3;
	brakeDistance = 200;
	airFrictionCoefs0[] = {0,0,0};
	airFrictionCoefs1[] = {0.1,0.05,0.006};	
	airFrictionCoefs2[] = {0.001,0.0005,6e-05};
	altFullForce = 1000;
	altNoForce = 2000;
	antiRollbarForceCoef = 0;
	antiRollbarForceLimit = 5;
	antiRollbarSpeedMax = 60;
	antiRollbarSpeedMin = 20;
	*/


	//USABLE FOR LIMITING SMALL UAV HEIGHT altFullForce = 200; altNoForce = 300;

	bodyFrictionCoef = 0.001;	//0.3
	acceleration = 350;
	airFrictionCoefs0[] = {0,0,0};
	airFrictionCoefs1[] = {0,0,0};
	airFrictionCoefs2[] = {0,0,0};
	//reversed = 1;
	//autocenter = 1;

	//envelope[] = { 1.7, 2.50, 3.50, 4.50, 5.50, 5.50, 5.15, 5.15, 5.15, 5.15, 4.15, 3.15, 2.15, 2.15, 1.15 };	//AH7

	//normalSpeedForwardCoef

	maxSpeed=1000;
	liftForceCoef=20;	//2 enough with low aifriction to reach 350km/h
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	backRotorForceCoef=5;	//10
	fuelCapacity=200;
	mainRotorSpeed=-7;	//14
	backRotorSpeed=7;	//14

	/*
	maxSpeed=400;
	liftForceCoef=6;
	cyclicAsideForceCoef=8;
	cyclicForwardForceCoef=4.8;
	backRotorForceCoef=20;	//10
	fuelCapacity=200;
	mainRotorSpeed=-28;	//14
	backRotorSpeed=28;	//14
	*/


	/*
	maxSpeed=200;
	liftForceCoef=1.5;
	cyclicAsideForceCoef=2;
	cyclicForwardForceCoef=1.2;
	backRotorForceCoef=5;	//10
	fuelCapacity=200;
	mainRotorSpeed=-7;	//14
	backRotorSpeed=7;	//14
	*/

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

	/*
	class ViewCargo: ViewCargo
	{

	};
	*/

	/*
	class CargoTurret: CargoTurret
	{
		maxCamElev = 180;	//90
		maxElev = 180;	//45
		maxTurn = 95;
		maxHorizontalRotSpeed = 1.2;
		maxVerticalRotSpeed = 1.2;
		minCamElev = -90;
		minElev = -45;
		minTurn = -95;
		turretFollowFreeLook = 0;
		stabilizedInAxes = 3;
		*/

		/*
		class ViewGunner: ViewGunner
		{
			
		};
		*/

		/*
		initAngleX=0;
		minAngleX=360;
		maxAngleX=-360;
		initAngleY=0;
		minAngleY=360;
		maxAngleY=-360;

		minFov=0.075;
		maxFov=1.25;
		initFov=1.25;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0};
		*/

		/*
	};
	*/

	class ViewPilot: ViewPilot
	{
		maxMoveX = 0.6;	//0.2
		maxMoveY = 0.3;	//0.1
		maxMoveZ = 0.6;	//0.2

		minMoveX = -0.6;	//-0.2
		minMoveY = -0.3;	//-0.1
		minMoveZ = -0.6;	//-0.1

		initAngleX=0;
		minAngleX=-360;
		maxAngleX=360;
		initAngleY=0;
		minAngleY=-360;
		maxAngleY=360;

		minFov=0.075;
		maxFov=1.25;
		initFov=1.25;

		
		class NewTurret
		{

		};
		

		class OpticsIn
		{
			class Wide
			{
				directionStabilized = 1;
				gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				initAngleX = 0;
				initAngleY = 0;
				initFov = 1;
				maxAngleX = 0;
				maxAngleY = 0;
				maxFov = 1.25;
				minAngleX = 0;
				minAngleY = 0;
				minFov = 0.25;
				opticsDisplayName = "WFOV";
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				thermalMode[] = {0};
				visionMode[] = {"Normal","NVG","TI"};
			};
		};

		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0};
	};
	class Viewoptics: ViewOptics
	{
		maxMoveX = 0.6;	//0.2
		maxMoveY = 0.3;	//0.1
		maxMoveZ = 0.6;	//0.2

		minMoveX = -0.6;	//-0.2
		minMoveY = -0.3;	//-0.1
		minMoveZ = -0.6;	//-0.1

		initAngleX=0;
		minAngleX=-360;
		maxAngleX=360;
		initAngleY=0;
		minAngleY=-360;
		maxAngleY=360;

		minFov=0.075;
		maxFov=1.25;
		initFov=1.25;

		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			#include "\Remote_Controlled_Artillery\includes_cfg\showTargets.hpp"
			//isCopilot=1; //0		//doesnt work yet
			//commanding=1; //-1	//doesnt work yet

			maxCamElev = 180;	//90
			maxElev = 180;	//45
			maxTurn = 180;
			minTurn = -180;
			/*
			maxHorizontalRotSpeed = 1.2;
			maxVerticalRotSpeed = 1.2;
			minCamElev = -90;
			minElev = -45;
			minTurn = -95;
			turretFollowFreeLook = 0;
			stabilizedInAxes = 3;
			*/

			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="W";
					initAngleX=0;
					minAngleX=-180;
					maxAngleX=180;
					initAngleY=0;
					minAngleY=-180;
					maxAngleY=180;
					initFov=1.0;
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
				//doesnt work...?
				class Monocular
				{
					initAngleX=0;
					minAngleX=-180;
					maxAngleX=180;
					initAngleY=0;
					minAngleY=-180;
					maxAngleY=180;
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

	/*
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
	*/

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
					typeRecognitionDistance=800;
					maxTrackableSpeed=600;
					nightRangeCoef=0.67;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";	//mainGun
					aimDown=0;	//-0.5

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
	//class Turrets {};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_UAV_FPV_Bag"
		};
	};
};