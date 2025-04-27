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
				range[]={2000,1000,500,4000};
				resource="RscCustomInfoSensors";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			class CrewDisplay
			{
				componentType="CrewDisplayComponent";
			};
			/*
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			*/
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
			class VehicleDriverDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Driver";
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
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={2000,1000,500,4000};
				resource="RscCustomInfoSensors";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			/*
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			*/
		};
	};
};