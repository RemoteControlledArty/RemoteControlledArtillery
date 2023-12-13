/*
	The Order is
	Normal -> Thermal -> Normal Bag -> Thermal Bag
*/

// Designator Arid
class B_Static_Designator_01_F;
class RC_Improved_FOV_Designator_Arid_base: B_Static_Designator_01_F
{
	class Turrets;
	class MainTurret;
	class viewOptics;
	class assembleInfo;
	class Components;
	scope=0;
	scopeCurator=0;
};
class RC_Improved_FOV_Designator_Arid: RC_Improved_FOV_Designator_Arid_base
{
	displayname="RC Improved Designator";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Spotting_subcat";

	scope=2;
	scopeCurator=2;

	threat[]={0.2,0.15,0.1};

	enableGPS=1;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=360;
					angleRangeVertical=360;

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

					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				minAngleX=-75;
				maxAngleX=75;

				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};

			showAllTargets="2 + 4";

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
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Arid"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_Arid: RC_Improved_FOV_Designator_Arid
{
	displayname="RC Improved Designator whTi";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Ti_Bag_Arid"
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
					angleRangeHorizontal=360;
					angleRangeVertical=360;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};

					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=500;

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
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};

					maxTrackableSpeed=15;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=1000;

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
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};
		};
	};
};


// Designator Bag Arid
class B_Static_Designator_01_weapon_F;
class RC_Improved_FOV_Designator_Bag_Arid_base: B_Static_Designator_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Improved_FOV_Designator_Bag_Arid: RC_Improved_FOV_Designator_Bag_Arid_base
{
	displayname="RC Improved Designator";
	scope=2;
	scopeCurator=2;
	
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_b_c_compact_rgr_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_rgr_co.paa"
	};
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator";
		assembleTo="RC_Improved_FOV_Designator_Arid";
	};
};
class RC_Improved_FOV_Designator_Ti_Bag_Arid: RC_Improved_FOV_Designator_Bag_Arid
{
	displayname="RC Improved Designator whTi";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi";
		assembleTo="RC_Improved_FOV_Designator_Ti_Arid";
	};
};


// Designator Woodland
class B_W_Static_Designator_01_F;
class RC_Improved_FOV_Designator_Woodland_base: B_W_Static_Designator_01_F
{
	class Turrets;
	class MainTurret;
	class viewOptics;
	class assembleInfo;
	class Components;
	scope=0;
	scopeCurator=0;
};
class RC_Improved_FOV_Designator_Woodland: RC_Improved_FOV_Designator_Woodland_base
{
	displayname="RC Improved Designator";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Spotting_subcat";

	scope=2;
	scopeCurator=2;

	threat[]={0.2,0.15,0.1};

	enableGPS=1;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;

	class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent: SensorTemplateLaser
				{
					angleRangeHorizontal=360;
					angleRangeVertical=360;

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

					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};

			showAllTargets="2 + 4";

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
			};
		};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Woodland"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_Woodland: RC_Improved_FOV_Designator_Woodland
{
	displayname="RC Improved Designator whTi";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Ti_Bag_Woodland"
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
					angleRangeHorizontal=360;
					angleRangeVertical=360;

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
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};

					maxTrackableSpeed=600;
					nightRangeCoef=0.80000001;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
				/*
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=500;

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
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};

					maxTrackableSpeed=15;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					//aimDown=-0.5;
				};
				*/
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=1000;

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
					maxTrackableSpeed=600;
					angleRangeHorizontal=60;
					angleRangeVertical=40;
					animDirection="mainGun";
					aimDown=-0.5;
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class ViewOptics: viewOptics
			{
				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;

				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
			};
		};
	};
};


// Designator Bag Woodland
class B_W_Static_Designator_01_weapon_F;
class RC_Improved_FOV_Designator_Bag_Woodland_base: B_W_Static_Designator_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Improved_FOV_Designator_Bag_Woodland: RC_Improved_FOV_Designator_Bag_Woodland_base
{
	displayname="RC Improved Designator";
	scope=2;
	scopeCurator=2;
	
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_b_c_compact_sgg_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_sgg_co.paa"
	};
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator";
		assembleTo="RC_Improved_FOV_Designator_Woodland";
	};
};
class RC_Improved_FOV_Designator_Ti_Bag_Woodland: RC_Improved_FOV_Designator_Bag_Woodland
{
	displayname="RC Improved Designator whTi";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi";
		assembleTo="RC_Improved_FOV_Designator_Ti_Woodland";
	};
};



//Opfor
// Arid
class RC_Improved_FOV_Designator_Arid_O: RC_Improved_FOV_Designator_Arid
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Arid_O"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_Arid_O: RC_Improved_FOV_Designator_Ti_Arid
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Ti_Bag_Arid_O"
		};
	};
};
class RC_Improved_FOV_Designator_Bag_Arid_O: RC_Improved_FOV_Designator_Bag_Arid
{
	displayName="RC Improved Designator whTi [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Opf]";
		assembleTo="RC_Improved_FOV_Designator_Arid_O";
	};
};
class RC_Improved_FOV_Designator_Ti_Bag_Arid_O: RC_Improved_FOV_Designator_Ti_Bag_Arid
{
	displayName="RC Improved Designator whTi [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Opf]";
		assembleTo="RC_Improved_FOV_Designator_Ti_Arid_O";
	};
};

// Woodland
class RC_Improved_FOV_Designator_Woodland_O: RC_Improved_FOV_Designator_Woodland
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Woodland_O"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_Woodland_O: RC_Improved_FOV_Designator_Ti_Woodland
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Ti_Bag_Woodlan_O"
		};
	};
};
class RC_Improved_FOV_Designator_Bag_Woodland_O: RC_Improved_FOV_Designator_Bag_Woodland
{
	displayName="RC Improved Designator [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Opf]";
		assembleTo="RC_Improved_FOV_Designator_Woodland_O";
	};
};
class RC_Improved_FOV_Designator_Ti_Bag_Woodland_O: RC_Improved_FOV_Designator_Ti_Bag_Woodland
{
	displayName="RC Improved Designator whTi [Opf]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Opf]";
		assembleTo="RC_Improved_FOV_Designator_Woodland_O";
	};
};



//Independant
// Arid
class RC_Improved_FOV_Designator_Arid_I: RC_Improved_FOV_Designator_Arid
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Arid_I"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_Arid_I: RC_Improved_FOV_Designator_Ti_Arid
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Ti_Bag_Arid_I"
		};
	};
};
class RC_Improved_FOV_Designator_Bag_Arid_I: RC_Improved_FOV_Designator_Bag_Arid
{
	displayName="RC Improved Designator [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Ind]";
		assembleTo="RC_Improved_FOV_Designator_Arid_I";
	};
};
class RC_Improved_FOV_Designator_Ti_Bag_Arid_I: RC_Improved_FOV_Designator_Ti_Bag_Arid
{
	displayName="RC Improved Designator whTi [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Ind]";
		assembleTo="RC_Improved_FOV_Designator_Ti_Arid_I";
	};
};

// Woodland
class RC_Improved_FOV_Designator_Woodland_I: RC_Improved_FOV_Designator_Woodland
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Woodland_I"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_Woodland_I: RC_Improved_FOV_Designator_Ti_Woodland
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Ti_Bag_Woodland_I"
		};
	};
};
class RC_Improved_FOV_Designator_Bag_Woodland_I: RC_Improved_FOV_Designator_Bag_Woodland
{
	displayName="RC Improved Designator [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Ind]";
		assembleTo="RC_Improved_FOV_Designator_Woodland_I";
	};
};
class RC_Improved_FOV_Designator_Ti_Bag_Woodland_I: RC_Improved_FOV_Designator_Ti_Bag_Woodland
{
	displayName="RC Improved Designator whTi [Ind]";
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator whTi [Ind]";
		assembleTo="RC_Improved_FOV_Designator_Woodland_I";
	};
};

