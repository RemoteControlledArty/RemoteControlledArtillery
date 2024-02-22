/*
	//Author Ascent&Fluffy
	//Laser Designators with and without Thermal Imaging and Image Recognition
*/

//Arid Designator
class B_Static_Designator_01_F;
class RC_Improved_FOV_Designator_A_base: B_Static_Designator_01_F
{
	class Turrets;
	class MainTurret;
	class viewOptics;
	class assembleInfo;
	class Components;
	scope=0;
	scopeCurator=0;
};
class RC_Improved_FOV_Designator_A: RC_Improved_FOV_Designator_A_base
{
	displayname="RC Improved Designator";
	faction="RemoteControlled_B";
	editorSubcategory="RC_Designator_subcat";
	scope=2;
	scopeCurator=2;
	enableGPS=1;
	radartype=2;
	receiveRemoteTargets=1;
	reportRemoteTargets=1;
	laserScanner=1;
	threat[]={0.2,0.15,0.1};

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
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets=4;

			class ViewOptics: viewOptics
			{
				minAngleX=-75;
				maxAngleX=75;
				initFov=0.25;
				minFov=0.0099999998;
				maxFov=0.25;
				directionStabilized=1;

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
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					defaultDisplay="EmptyDisplay";

					class Components
					{
						class EmptyDisplay
						{
							componentType="EmptyDisplayComponent";
						};
						class MinimapDisplay
						{
							componentType="MinimapDisplayComponent";
							resource="RscCustomInfoMiniMap";
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
			"RC_Improved_FOV_Designator_Bag_A"
		};
	};
};
class RC_Improved_FOV_Designator_A_O: RC_Improved_FOV_Designator_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_A_O"
		};
	};
};
class RC_Improved_FOV_Designator_A_I: RC_Improved_FOV_Designator_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_A_I"
		};
	};
};


//Arid Bags
class B_Static_Designator_01_weapon_F;
class RC_Improved_FOV_Designator_Bag_A_base: B_Static_Designator_01_weapon_F
{
	class assembleInfo;
	scope=0;
	scopeCurator=0;
};
class RC_Improved_FOV_Designator_Bag_A: RC_Improved_FOV_Designator_Bag_A_base
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
		assembleTo="RC_Improved_FOV_Designator_A";
	};
};
class RC_Improved_FOV_Designator_Bag_A_O: RC_Improved_FOV_Designator_Bag_A
{
	displayname="RC Improved Designator [Opf]";
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Opf]";
		assembleTo="RC_Improved_FOV_Designator_A_O";
	};
};
class RC_Improved_FOV_Designator_Bag_A_I: RC_Improved_FOV_Designator_Bag_A
{
	displayname="RC Improved Designator [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Ind]";
		assembleTo="RC_Improved_FOV_Designator_A_I";
	};
};


//Woodland Designator
class RC_Improved_FOV_Designator_WD: RC_Improved_FOV_Designator_A
{
	DLC="Enoch";
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\B_W_Static_Designator_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\Static_F_Enoch\Designator_01\Data\ld01_remote_khk_co.paa",
		"a3\Weapons_F_Exp\Binocular\Data\Laserdesignator_01_khk_F_co.paa"
	};
};
class RC_Improved_FOV_Designator_WD_O: RC_Improved_FOV_Designator_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_WD_O"
		};
	};
};
class RC_Improved_FOV_Designator_WD_I: RC_Improved_FOV_Designator_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_WD_I"
		};
	};
};


//Woodland Bags
class RC_Improved_FOV_Designator_Bag_WD: RC_Improved_FOV_Designator_Bag_A
{
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_b_c_compact_sgg_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_sgg_co.paa"
	};
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator";
		assembleTo="RC_Improved_FOV_Designator_WD";
	};
};
class RC_Improved_FOV_Designator_Bag_WD_O: RC_Improved_FOV_Designator_Bag_WD
{
	displayname="RC Improved Designator [Opf]";
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Opf]";
		assembleTo="RC_Improved_FOV_Designator_WD_O";
	};
};
class RC_Improved_FOV_Designator_Bag_WD_I: RC_Improved_FOV_Designator_Bag_WD
{
	displayname="RC Improved Designator [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator [Ind]";
		assembleTo="RC_Improved_FOV_Designator_WD_I";
	};
};


class RC_Improved_FOV_Designator_Ti_A: RC_Improved_FOV_Designator_A
{
	displayname="RC Improved Designator TI";

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Ti_Bag_A"
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
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
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
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
				};
				*/
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=2000;

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
					angleRangeHorizontal=51;
					angleRangeVertical=37;
					animDirection="mainGun";
				};
			};
		};
	};

	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			showAllTargets="2 + 4";
			
			class ViewOptics: viewOptics
			{
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
class RC_Improved_FOV_Designator_Ti_A_O: RC_Improved_FOV_Designator_Ti_A
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Ti_A_O"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_A_I: RC_Improved_FOV_Designator_Ti_A
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Ti_A_I"
		};
	};
};


//Arid Bags
class RC_Improved_FOV_Designator_Bag_Ti_A: RC_Improved_FOV_Designator_Bag_A_base
{
	displayname="RC Improved Designator TI";
	scope=2;
	scopeCurator=2;
	
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_b_c_compact_rgr_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_rgr_co.paa"
	};
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI";
		assembleTo="RC_Improved_FOV_Designator_Ti_A";
	};
};
class RC_Improved_FOV_Designator_Bag_Ti_A_O: RC_Improved_FOV_Designator_Bag_Ti_A
{
	displayname="RC Improved Designator TI [Opf]";
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Opf]";
		assembleTo="RC_Improved_FOV_Designator_Ti_A_O";
	};
};
class RC_Improved_FOV_Designator_Bag_Ti_A_I: RC_Improved_FOV_Designator_Bag_Ti_A
{
	displayname="RC Improved Designator TI [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Ind]";
		assembleTo="RC_Improved_FOV_Designator_Ti_A_I";
	};
};


//Woodland Designator Ti
class RC_Improved_FOV_Designator_Ti_WD: RC_Improved_FOV_Designator_Ti_A
{
	editorPreview="\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\B_W_Static_Designator_01_F.jpg";
	hiddenSelectionsTextures[]=
	{
		"a3\Static_F_Enoch\Designator_01\Data\ld01_remote_khk_co.paa",
		"a3\Weapons_F_Exp\Binocular\Data\Laserdesignator_01_khk_F_co.paa"
	};
};
class RC_Improved_FOV_Designator_Ti_WD_O: RC_Improved_FOV_Designator_Ti_WD
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Opf]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Ti_WD_O"
		};
	};
};
class RC_Improved_FOV_Designator_Ti_WD_I: RC_Improved_FOV_Designator_Ti_WD
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Ind]";
		dissasembleTo[]=
		{
			"RC_Improved_FOV_Designator_Bag_Ti_WD_I"
		};
	};
};


//Woodland Bags Ti
class RC_Improved_FOV_Designator_Bag_Ti_WD: RC_Improved_FOV_Designator_Bag_Ti_A
{
	picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_b_c_compact_sgg_ca.paa";
	hiddenSelectionsTextures[]=
	{
		"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_sgg_co.paa"
	};
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI";
		assembleTo="RC_Improved_FOV_Designator_Ti_WD";
	};
};
class RC_Improved_FOV_Designator_Bag_Ti_WD_O: RC_Improved_FOV_Designator_Bag_Ti_WD
{
	displayname="RC Improved Designator TI [Opf]";
	
	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Opf]";
		assembleTo="RC_Improved_FOV_Designator_Ti_WD_O";
	};
};
class RC_Improved_FOV_Designator_Bag_Ti_WD_I: RC_Improved_FOV_Designator_Bag_Ti_WD
{
	displayname="RC Improved Designator TI [Ind]";

	class assembleInfo: assembleInfo
	{
		displayName="RC Improved Designator TI [Ind]";
		assembleTo="RC_Improved_FOV_Designator_Ti_WD_I";
	};
};