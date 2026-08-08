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
				range[]={4000,2000,1000,400};
				resource="RscCustomInfoSensors";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			class VehicleCommanderDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Commander";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class CrewDisplay
			{
				componentType="CrewDisplayComponent";
			};
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
		};
	};
	class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
	{
		defaultDisplay="EmptyDisplay";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={400,1000,2000,4000};
				resource="RscCustomInfoSensors";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			class VehicleCommanderDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Commander";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class CrewDisplay
			{
				componentType="CrewDisplayComponent";
			};
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
		};
	};
};