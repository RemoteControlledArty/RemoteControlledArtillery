class TransportPylonsComponent: TransportPylonsComponent
{
	class pylons: pylons
	{
		//left outer
		class pylon1: pylon1
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank"
			};

			attachment="RC_PylonFuelTank_HalfFull";
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
				"RC_Hardpoint_V2_Left"
			};

			attachment="RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_R";
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
				"RC_Hardpoint_V2_Right"
			};

			attachment="RC_PylonM_Twin_1000Rnd_127mm_SLAP_T_R";
		};
		//right outer
		class pylon4: pylon4
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank"
			};

			attachment="RC_PylonFuelTank_HalfFull";
		};
		//center
		class camera: camera
		{
		};
		//left
		class wingtip1: wingtip1
		{
		};
		//right
		class wingtip2: wingtip2
		{
		};
	};
};