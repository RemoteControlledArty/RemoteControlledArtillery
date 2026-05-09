class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
{
	defaultDisplay="SensorDisplay";

	class Components
	{
		class SensorDisplay
		{
			componentType="SensorsDisplayComponent";
			range[]={40000,20000,10000,4000,400};
			resource="RscCustomInfoSensors";
		};
		class MinimapDisplay
		{
			componentType="MinimapDisplayComponent";
			resource="RscCustomInfoMiniMap";
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
			range[]={400,4000,10000,20000,40000};
			resource="RscCustomInfoSensors";
		};
		class MinimapDisplay
		{
			componentType="MinimapDisplayComponent";
			resource="RscCustomInfoMiniMap";
		};
	};
};