class TransportPylonsComponent: TransportPylonsComponent
{
	class pylons: pylons
	{
		//Right outer
		class pylon1: pylon1
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

				"RC_Hardpoint_V3_Green"
			};

			attachment="RC_PylonM_12Rnd_Hydra_MP_Proxy_Green";
		};
		//Right inner
		class pylon2: pylon2
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

				"RC_Hardpoint_V3_Green"
			};

			attachment="RC_PylonM_125Rnd_30mm";
		};
		//Left inner
		class pylon3: pylon3
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

				"RC_Hardpoint_V3_Green"
			};

			attachment="RC_PylonM_125Rnd_30mm";
		};
		//Left outer
		class pylon4: pylon4
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

				"RC_Hardpoint_V3_Green",

				"RC_Hardpoint_V3_Green"
			};

			attachment="RC_PylonM_12Rnd_Hydra_MP_Proxy_Green";
		};
	};
};