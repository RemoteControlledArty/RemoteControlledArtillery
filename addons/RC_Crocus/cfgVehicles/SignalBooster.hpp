class SatelliteAntenna_01_Small_Olive_F;
class FPV_Retranslator: SatelliteAntenna_01_Small_Olive_F
{
	scope=2;
	scopeCurator=2;
	displayName="Crocus Signal Booster [Antenna]";

	class assembleInfo
	{
		primary=0;
		base="";
		assembleTo="";
		dissasembleTo[]=
		{
			"B_Crocus_SignalBooster_Bag"
		};
		displayName="";
	};
};
class B_Crocus_SignalBooster_Bag: B_Crocus_MP_Bag
{
	displayName="Crocus Signal Booster [Antenna]";
	mass=60;	//2.75kg

	class assembleInfo: assembleInfo
	{
		assembleTo="FPV_Retranslator";
		displayName="Crocus Signal Booster";
	};
};