class TransportPylonsComponent: TransportPylonsComponent
{
	class pylons: pylons
	{
		class pylon1: pylon1
		{
		};
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

			attachment="RC_PylonM_350Rnd_20mm";
		};
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
				"RC_Hardpoint_V4_Right",
				
				"RC_Hardpoint_V5",
				"RC_Hardpoint_V5_Right"
			};

			attachment="RC_PylonM_12Rnd_APKWS";
		};
		class pylon4: pylon4
		{
		};
	};
};