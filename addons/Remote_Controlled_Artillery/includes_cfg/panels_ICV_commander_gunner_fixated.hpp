class Components: Components
{
	class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
	{
		defaultDisplay="EmptyDisplay";

		class Components
		{
			class EmptyDisplay
			{
				componentType="EmptyDisplayComponent";
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
			class UAVFeedDisplay
			{
				componentType="UAVFeedDisplayComponent";
			};
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
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