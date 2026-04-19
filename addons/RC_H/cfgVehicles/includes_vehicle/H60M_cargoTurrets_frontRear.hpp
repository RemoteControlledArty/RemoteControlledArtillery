class CargoTurret_03: CargoTurret
{
	gunnerCompartments="Compartment1";

	gunnerAction="passenger_bench_1";
	isPersonTurret=1;
	ejectDeadGunner=0;
	playerPosition=4;
	soundAttenuationTurret="";
	disableSoundAttenuation=1;
	gunnerGetInAction="GetInHeli_Light_01bench";
	class Hitpoints
	{
	};

	gunnerName="Front Left";
	proxyIndex=3;
	memoryPointsGetInGunner="pos L1";
	memoryPointsGetInGunnerDir="pos L1 dir";
	maxElev=45;
	minElev=-60;
	maxTurn=95;
	minTurn=-15;
};
class CargoTurret_04: CargoTurret_03
{
	gunnerName="Front Right";
	proxyIndex=4;
	memoryPointsGetInGunner="pos R1";
	memoryPointsGetInGunnerDir="pos R1 dir";
	maxTurn=15;
	minTurn=-95;
};
class CargoTurret_07: CargoTurret_04
{
	gunnerName="Rear Left";
	proxyIndex=7;
	memoryPointsGetInGunner="pos L3";
	memoryPointsGetInGunnerDir="pos L3 dir";
	minElev=-45;
	maxTurn=95;
	minTurn=-95;
	class dynamicViewLimits
	{
		CargoTurret_05[]={-50,95};
	};
};
class CargoTurret_08: CargoTurret_07
{
	gunnerName="Rear Right";
	proxyIndex=8;
	memoryPointsGetInGunner="pos R3";
	memoryPointsGetInGunnerDir="pos R3 dir";
	class dynamicViewLimits
	{
		CargoTurret_06[]={-95,50};
	};
};