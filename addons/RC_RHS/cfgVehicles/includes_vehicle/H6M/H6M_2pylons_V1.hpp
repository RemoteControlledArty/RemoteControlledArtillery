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
				"RC_Hardpoint_V1_Left"
			};

			attachment="RC_RHS_PylonM_2500Rnd_338_SLAP_T_R";
		};
		class pylon3: pylon3
		{
			hardpoints[]=
			{
				"RC_Hardpoint_FuelTank",
				
				"RC_Hardpoint_V1",
				"RC_Hardpoint_V1_Right"
			};

			attachment="RC_RHS_PylonM_2500Rnd_338_SLAP_T_R";
		};
		class pylon4: pylon4
		{
		};
	};
};