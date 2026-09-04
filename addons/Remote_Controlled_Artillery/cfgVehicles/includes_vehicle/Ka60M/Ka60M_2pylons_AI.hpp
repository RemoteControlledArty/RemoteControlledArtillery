class TransportPylonsComponent: TransportPylonsComponent
{
	class pylons: pylons
	{
		class pylon1: pylon1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",

				"RC_AI_Hardpoint_O_V1",
				"RC_AI_Hardpoint_O_V1_Right",
				"RC_AI_Hardpoint_O_V2",
				"RC_AI_Hardpoint_O_V2_Right",
				"RC_AI_Hardpoint_O_V3",
				"RC_AI_Hardpoint_O_V3_Right",
				"RC_AI_Hardpoint_O_V4",
				"RC_AI_Hardpoint_O_V4_Right"
			};

			attachment="RC_AI_PylonM_250Rnd_30mm_Proxy_O";
		};
		class pylon2: pylon2
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",
				
				"RC_AI_Hardpoint_O_V1",
				"RC_AI_Hardpoint_O_V1_Left",
				"RC_AI_Hardpoint_O_V2",
				"RC_AI_Hardpoint_O_V2_Left",
				"RC_AI_Hardpoint_O_V3",
				"RC_AI_Hardpoint_O_V3_Left",
				"RC_AI_Hardpoint_O_V4",
				"RC_AI_Hardpoint_O_V4_Left"
			};

			attachment="RC_AI_PylonM_19Rnd_S5_MP_Proxy";
		};
	};
};