class TransportPylonsComponent: TransportPylonsComponent
{
	class pylons: pylons
	{
		class PylonRight1: PylonRight1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",

				"RC_Hardpoint_V1",
				"RC_Hardpoint_V1_Right",
				"RC_Hardpoint_V2",
				"RC_Hardpoint_V2_Right",
				"RC_Hardpoint_V3",
				"RC_Hardpoint_V3_Right",
				"RC_Hardpoint_V4",
				"RC_Hardpoint_V4_Right",		
				"RC_Hardpoint_V5",
				"RC_Hardpoint_V5_Right",

				"RC_Hardpoint_V6",
				"RC_Hardpoint_V6_Right"
			};

			attachment="RC_PylonM_300Rnd_25mm";
		};
		class PylonLeft1: PylonLeft1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",
				
				"RC_Hardpoint_V1",
				"RC_Hardpoint_V1_Left",
				"RC_Hardpoint_V2",
				"RC_Hardpoint_V2_Left",
				"RC_Hardpoint_V3",
				"RC_Hardpoint_V3_Left",
				"RC_Hardpoint_V4",
				"RC_Hardpoint_V4_Left",		
				"RC_Hardpoint_V5",
				"RC_Hardpoint_V5_Left",

				"RC_Hardpoint_V6",
				"RC_Hardpoint_V6_Left"
			};

			attachment="RC_PylonM_12Rnd_APKWS";
		};
	};
};