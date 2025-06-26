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
			class IRSensorComponent: SensorTemplateIR
			{
				typeRecognitionDistance=600;

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
				maxTrackableSpeed=600;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="";
			};
			class ManSensorComponent: SensorTemplateMan
			{
				typeRecognitionDistance=600;

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
				maxTrackableSpeed=15;
				angleRangeHorizontal=360;
				angleRangeVertical=360;
				animDirection="";
				aimDown=0;
			};
			#include "\Remote_Controlled_Artillery\includes_cfg\passiveRadar_far.hpp"
		};
	};

	class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
	{
		defaultDisplay="SensorDisplay";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={6000,3000,1500,600};
				resource="RscCustomInfoSensors";
			};
			class CrewDisplay
			{
				componentType="CrewDisplayComponent";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
		};
	};
	class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
	{
		defaultDisplay="SensorDisplay";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={600,1500,3000,6000};
				resource="RscCustomInfoSensors";
			};
			class CrewDisplay
			{
				componentType="CrewDisplayComponent";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
		};
	};
};