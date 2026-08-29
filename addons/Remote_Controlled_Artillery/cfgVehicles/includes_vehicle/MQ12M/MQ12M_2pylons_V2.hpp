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
				"RC_Hardpoint_V2_Right"
			};

			attachment="RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_R";
		};
		class PylonLeft1: PylonLeft1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",
				
				"RC_Hardpoint_V1",
				"RC_Hardpoint_V1_Left",

				"RC_Hardpoint_V2",
				"RC_Hardpoint_V2_Left"
			};

			attachment="RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_R";
		};
	};
};