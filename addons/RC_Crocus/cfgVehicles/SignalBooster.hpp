class SatelliteAntenna_01_Small_Olive_F;
class FPV_Retranslator: SatelliteAntenna_01_Small_Olive_F
{
	scope=2;
	scopeCurator=2;
	displayName="Crocus Signal Booster [Static]";

	//no effect?
	armor=60;
	armorStructural=2;
	destrType="DestructBuilding";
	explosionShielding=0.5;
	class EventHandlers
	{
		init="(_this # 0) allowDamage true;";
	};

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
	displayName="Crocus Signal Booster [Static]";
	mass=60;	//2.75kg

	class assembleInfo: assembleInfo
	{
		assembleTo="FPV_Retranslator";
		displayName="Crocus Signal Booster";
	};
};