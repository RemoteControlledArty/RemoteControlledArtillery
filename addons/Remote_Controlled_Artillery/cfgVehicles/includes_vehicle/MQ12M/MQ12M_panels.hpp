
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
		class MinimapDisplay
		{
			componentType="MinimapDisplayComponent";
			resource="RscCustomInfoMiniMap";
		};
		class SlingLoadDisplay
		{
			componentType="SlingLoadDisplayComponent";
			resource="RscCustomInfoSlingLoad";
		};
		/*
		class EmptyDisplay
		{
			componentType="EmptyDisplayComponent";
		};
		*/
	};
};
class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
{
	defaultDisplay="MinimapDisplay";

	class Components
	{
		class SensorDisplay
		{
			componentType="SensorsDisplayComponent";
			range[]={1000,2000,4000,6000,8000};
			resource="RscCustomInfoSensors";
		};
		class MinimapDisplay
		{
			componentType="MinimapDisplayComponent";
			resource="RscCustomInfoMiniMap";
		};
		class SlingLoadDisplay
		{
			componentType="SlingLoadDisplayComponent";
			resource="RscCustomInfoSlingLoad";
		};
		/*
		class EmptyDisplay
		{
			componentType="EmptyDisplayComponent";
		};
		*/
	};
};