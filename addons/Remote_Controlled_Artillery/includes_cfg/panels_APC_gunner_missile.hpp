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
				range[]={4000,2000,1000,500};
				resource="RscCustomInfoSensors";
			};
			class VehicleMissileDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Missile";
			};
			class VehicleDriverDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Driver";
			};
			/*
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			*/
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
		defaultDisplay="EmptyDisplay";

		class Components
		{
			class SensorDisplay
			{
				componentType="SensorsDisplayComponent";
				range[]={4000,2000,1000,500};
				resource="RscCustomInfoSensors";
			};
			class VehicleMissileDisplay
			{
				componentType="TransportFeedDisplayComponent";
				source="Missile";
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
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
			};
		};
	};
};