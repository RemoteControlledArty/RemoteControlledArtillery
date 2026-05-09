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
				range[]={4000,2000,400};
				resource="RscCustomInfoSensors";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
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
				range[]={400,2000,4000};
				resource="RscCustomInfoSensors";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
		};
	};
};