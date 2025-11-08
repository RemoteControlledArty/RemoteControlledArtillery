class Components: Components
{
	class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
	{
		defaultDisplay="UAVFeedDisplay";

		class Components
		{
			/*
			//not possible with deleted turret
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=60;
				resource="RscCustomInfoMineDetect";
			};
			*/
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
			/*
			//not possible with deleted turret
			class MineDetectorDisplay
			{
				componentType="MineDetectorDisplayComponent";
				range=60;
				resource="RscCustomInfoMineDetect";
			};
			*/
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
};