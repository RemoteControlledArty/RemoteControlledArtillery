class TransportPylonsComponent: TransportPylonsComponent
{
	class pylons: pylons
	{
		class pylon1: pylon1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",

				"RC_Hardpoint_O_V1",
				"RC_Hardpoint_O_V1_Right",
				"RC_Hardpoint_O_V2",
				"RC_Hardpoint_O_V2_Right",
				"RC_Hardpoint_O_V3",
				"RC_Hardpoint_O_V3_Right",
				"RC_Hardpoint_O_V4",
				"RC_Hardpoint_O_V4_Right"
			};

			attachment="RC_PylonM_300Rnd_25mm_O";
		};
		class pylon2: pylon2
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",
				
				"RC_Hardpoint_O_V1",
				"RC_Hardpoint_O_V1_Left",
				"RC_Hardpoint_O_V2",
				"RC_Hardpoint_O_V2_Left",
				"RC_Hardpoint_O_V3",
				"RC_Hardpoint_O_V3_Left",
				"RC_Hardpoint_O_V4",
				"RC_Hardpoint_O_V4_Left",
				"RC_Hardpoint_O_V5",
				"RC_Hardpoint_O_V5_Left",
				"RC_Hardpoint_O_V6",
				"RC_Hardpoint_O_V6_Left"
			};

			attachment="RC_PylonM_8Rnd_S8_G";	//RC_PylonM_12Rnd_S8_LG
		};
	};
};