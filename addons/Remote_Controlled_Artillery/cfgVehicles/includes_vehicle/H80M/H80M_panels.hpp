
class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
{
	defaultDisplay="SensorDisplay";

	class Components
	{
		class SensorDisplay
		{
			componentType="SensorsDisplayComponent";
			range[]={6000,4000,2000,1000,8000};
			resource="RscCustomInfoSensors";
		};
		class CrewDisplay
		{
			componentType="CrewDisplayComponent";
		};
		class SlingLoadDisplay
		{
			componentType="SlingLoadDisplayComponent";
			resource="RscCustomInfoSlingLoad";
		};
		class MinimapDisplay
		{
			componentType="MinimapDisplayComponent";
			resource="RscCustomInfoMiniMap";
		};
		class UAVFeedDisplay
		{
			componentType="UAVFeedDisplayComponent";
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
			range[]={2000,4000,6000,8000,1000};
			resource="RscCustomInfoSensors";
		};
		class CrewDisplay
		{
			componentType="CrewDisplayComponent";
		};
		class SlingLoadDisplay
		{
			componentType="SlingLoadDisplayComponent";
			resource="RscCustomInfoSlingLoad";
		};
		class MinimapDisplay
		{
			componentType="MinimapDisplayComponent";
			resource="RscCustomInfoMiniMap";
		};
		class UAVFeedDisplay
		{
			componentType="UAVFeedDisplayComponent";
		};
		class EmptyDisplay
		{
			componentType="EmptyDisplayComponent";
		};
	};
};