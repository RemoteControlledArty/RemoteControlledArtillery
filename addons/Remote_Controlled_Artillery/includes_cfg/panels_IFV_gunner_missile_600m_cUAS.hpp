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
				range[]={4000,2000,1000,600};
				resource="RscCustomInfoSensors";
			};
			class VehicleMissileDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Missile";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			class VehicleDriverDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Driver";
			};
			class VehicleCommanderDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Commander";
			};
			/*
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			*/
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
		defaultDisplay="SensorDisplay";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={600,1000,2000,4000};
				resource="RscCustomInfoSensors";
			};
			class VehicleMissileDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Missile";
			};
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			class VehicleDriverDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Driver";
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
			/*
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=50;
				resource="RscCustomInfoMineDetect";
			};
			*/
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
		};
	};
};