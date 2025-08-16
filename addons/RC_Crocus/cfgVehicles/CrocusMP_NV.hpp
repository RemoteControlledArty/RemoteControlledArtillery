class B_Crocus_MP_NV_Base: B_Crocus_MP
{
	scope=0;
	scopeCurator=0;
	class EventHandlers;
	class ViewPilot;
	class Viewoptics;
	class Components;
};
class B_Crocus_MP_NV: B_Crocus_MP_NV_Base
{
	scope=2;
	scopeCurator=2;
	displayName="Crocus MP NV";
	cost=40000;

	class ViewPilot: ViewPilot
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
		thermalMode[]={0};
	};
	class Viewoptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
		thermalMode[]={0};
	};

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"B_Crocus_MP_NV_Bag"
		};
	};
};
class O_Crocus_MP_NV: B_Crocus_MP_NV
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_MP_NV_Bag"
		};
	};
};
class I_Crocus_MP_NV: B_Crocus_MP_NV
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_MP_NV_Bag"
		};
	};
};


class B_Crocus_MP_NV_Bag: B_Crocus_MP_Bag
{
	scope=2;
	scopeCurator=2;
	displayName="Crocus MP NV Bag";

	class assembleInfo: assembleInfo
	{
		assembleTo="B_Crocus_MP_NV";
		displayName="Crocus MP NV";
	};
};
class O_Crocus_MP_NV_Bag: B_Crocus_MP_NV_Bag
{
	displayName="Crocus MP NV Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_MP_NV";
		displayName="Crocus MP NV [Opf]";
	};
};
class I_Crocus_MP_NV_Bag: B_Crocus_MP_NV_Bag
{
	displayName="Crocus MP NV Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_MP_NV";
		displayName="Crocus MP NV [Ind]";
	};
};


class B_Crocus_MP_NV_Sens: B_Crocus_MP_NV
{
	displayName="Crocus MP NV Sens";

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
					nightRangeCoef=0.8;
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
				class NVSensorComponent: SensorTemplateNV
				{
					typeRecognitionDistance=3000;
					maxTrackableSpeed=450;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
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
					animDirection="";	//aligned with body
					aimDown=0;	//-1

					class AirTarget
					{
						minRange=60;
						maxRange=60;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=60;
						maxRange=60;
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
			"B_Crocus_MP_NV_Sens_Bag"
		};
	};
};
class O_Crocus_MP_NV_Sens: B_Crocus_MP_NV_Sens
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_MP_NV_Sens_Bag"
		};
	};
};
class I_Crocus_MP_NV_Sens: B_Crocus_MP_NV_Sens
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_MP_NV_Sens_Bag"
		};
	};
};


class B_Crocus_MP_NV_Sens_Bag: B_Crocus_MP_NV_Bag
{
	displayName="Crocus MP NV Sens Bag";

	class assembleInfo: assembleInfo
	{
		assembleTo="B_Crocus_MP_NV_Sens";
		displayName="Crocus MP NV Sens";
	};
};
class O_Crocus_MP_NV_Sens_Bag: B_Crocus_MP_NV_Sens_Bag
{
	displayName="Crocus MP NV Sens Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_MP_NV_Sens";
		displayName="Crocus MP NV Sens [Opf]";
	};
};
class I_Crocus_MP_NV_Sens_Bag: B_Crocus_MP_NV_Sens_Bag
{
	displayName="Crocus MP NV Sens Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_MP_NV_Sens";
		displayName="Crocus MP NV Sens [Ind]";
	};
};