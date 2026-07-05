class B_Crocus_MP;
class B_Crocus_MP_TI_Base: B_Crocus_MP
{
	scope=0;
	scopeCurator=0;
	class EventHandlers;
	class ViewPilot;
	class Viewoptics;
	class Components;
};
class B_Crocus_MP_TI: B_Crocus_MP_TI_Base
{
	scope=2;
	scopeCurator=2;
	displayName="Crocus MP TI";
	cost=40000;

	class ViewPilot: ViewPilot
	{
		visionMode[]=
		{
			"Normal",
			"Ti"
		};
		thermalMode[]={0};
	};
	class Viewoptics: ViewOptics
	{
		visionMode[]=
		{
			"Normal",
			"Ti"
		};
		thermalMode[]={0};
	};

	class assembleInfo
	{
		primary=0;
		base="";
		assembleTo="";
		dissasembleTo[]=
		{
			"Crocus_MP_TI_Bag"
			//"B_Crocus_MP_TI_Bag"
		};
		displayName="";
	};
};
class O_Crocus_MP_TI: B_Crocus_MP_TI
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_MP_TI_Bag"
		};
	};
	*/
};
class I_Crocus_MP_TI: B_Crocus_MP_TI
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_MP_TI_Bag"
		};
	};
	*/
};


class Crocus_MP_TI: B_Crocus_MP_TI
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class Crocus_MP_Bag;
class Crocus_MP_TI_Bag: Crocus_MP_Bag
{
	displayName="Crocus MP TI Bag";

	class assembleInfo
	{
		displayName="Crocus MP TI";
		base="";
		assembleTo="Crocus_MP_TI";
		dissasembleTo[]={};
		primary=1;
	};
};


/*
class B_Crocus_MP_Bag;
class B_Crocus_MP_TI_Bag: B_Crocus_MP_Bag
{
	displayName="Crocus MP TI Bag";

	class assembleInfo
	{
		assembleTo="B_Crocus_MP_TI";
		base="";
		displayName="Crocus MP TI";
		dissasembleTo[]={};
		primary=1;
	};
};
class O_Crocus_MP_TI_Bag: B_Crocus_MP_TI_Bag
{
	displayName="Crocus MP TI Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_MP_TI";
		displayName="Crocus MP TI [Opf]";
	};
};
class I_Crocus_MP_TI_Bag: B_Crocus_MP_TI_Bag
{
	displayName="Crocus MP TI Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_MP_TI";
		displayName="Crocus MP TI [Ind]";
	};
};
*/


class B_Crocus_MP_TI_Sens: B_Crocus_MP_TI
{
	displayName="Crocus MP TI Sensor";

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
					nightRangeCoef=0.6;
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
				class IRSensorComponent: SensorTemplateIR
				{
					typeRecognitionDistance=350;
					maxTrackableSpeed=450;
					angleRangeHorizontal=45;
					angleRangeVertical=45;
					animDirection="";
					aimDown=0;

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
				class ManSensorComponent: SensorTemplateMan
				{
					typeRecognitionDistance=1;
					maxTrackableSpeed=15;
					nightRangeCoef=1;
					angleRangeHorizontal=45;
					angleRangeVertical=90;
					animDirection="";	//aligned with body
					aimDown=0;	//-1

					class AirTarget
					{
						minRange=150;
						maxRange=150;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=150;
						maxRange=150;
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
			"Crocus_MP_TI_Sens_Bag"
			//"B_Crocus_MP_TI_Sens_Bag"
		};
	};
};
class O_Crocus_MP_TI_Sens: B_Crocus_MP_TI_Sens
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"O_Crocus_MP_TI_Sens_Bag"
		};
	};
	*/
};
class I_Crocus_MP_TI_Sens: B_Crocus_MP_TI_Sens
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;

	/*
	class assembleInfo: assembleInfo
	{
		dissasembleTo[]=
		{
			"I_Crocus_MP_TI_Sens_Bag"
		};
	};
	*/
};


class Crocus_MP_TI_Sens: B_Crocus_MP_TI_Sens
{
	scope=1;
	scopeCurator=1;
	side=3;
	crew="C_UAV_AI_F";
	//faction="RemoteControlled_C";
};
class Crocus_MP_TI_Sens_Bag: Crocus_MP_TI_Bag
{
	displayName="Crocus MP TI Sensor Bag";

	class assembleInfo: assembleInfo
	{
		displayName="Crocus MP TI Sensor";
		assembleTo="Crocus_MP_TI_Sens";
	};
};


/*
class B_Crocus_MP_TI_Sens_Bag: B_Crocus_MP_TI_Bag
{
	displayName="Crocus MP TI Sens Bag";

	class assembleInfo: assembleInfo
	{
		assembleTo="B_Crocus_MP_TI_Sens";
		displayName="Crocus MP TI Sens";
	};
};
class O_Crocus_MP_TI_Sens_Bag: B_Crocus_MP_TI_Sens_Bag
{
	displayName="Crocus MP TI Sens Bag [Opf]";

	class assembleInfo: assembleInfo
	{
		assembleTo="O_Crocus_MP_TI_Sens";
		displayName="Crocus MP TI Sens [Opf]";
	};
};
class I_Crocus_MP_TI_Sens_Bag: B_Crocus_MP_TI_Sens_Bag
{
	displayName="Crocus MP TI Sens Bag [Ind]";

	class assembleInfo: assembleInfo
	{
		assembleTo="I_Crocus_MP_TI_Sens";
		displayName="Crocus MP TI Sens [Ind]";
	};
};
*/