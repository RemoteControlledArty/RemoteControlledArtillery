class TransportPylonsComponent: TransportPylonsComponent
{
	class pylons: pylons
	{
		//left outer
		class pylon1: pylon1
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

			attachment="RC_PylonM_8Rnd_DAGR";
		};
		//left inner
		class pylon2: pylon2
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
				"RC_Hardpoint_V4_Left"
			};

			attachment="RC_PylonM_250Rnd_30mm";
		};
		//right inner
		class pylon3: pylon3
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
				"RC_Hardpoint_V4_Right"
			};

			attachment="RC_PylonM_19Rnd_Hydra_MP_Proxy";
		};
		//right outer
		class pylon4: pylon4
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

			attachment="RC_PylonM_8Rnd_DAGR";
		};
	};
};