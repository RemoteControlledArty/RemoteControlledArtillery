class Components: Components
{
	class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
	{
		defaultDisplay="MineDetectorDisplay";

		class Components
		{
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=75;
				resource="RscCustomInfoMineDetect";
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
		defaultDisplay="MinimapDisplay";

		class Components
		{
			class MinimapDisplay
			{
				componentType="MinimapDisplayComponent";
				resource="RscCustomInfoMiniMap";
			};
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=75;
				resource="RscCustomInfoMineDetect";
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
};