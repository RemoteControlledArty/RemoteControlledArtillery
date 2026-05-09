class CargoTurret_05: CargoTurret_04
{
	gunnerName="Middle Left";
	proxyIndex=5;
	memoryPointsGetInGunner="pos L2";
	memoryPointsGetInGunnerDir="pos L2 dir";
	minElev=-45;
	maxTurn=95;
	minTurn=-95;
	class dynamicViewLimits
	{
		CargoTurret_03[]={-30,95};
		CargoTurret_07[]={-95,50};
	};
};
class CargoTurret_06: CargoTurret_05
{
	gunnerName="Middle Right";
	proxyIndex=6;
	memoryPointsGetInGunner="pos R2";
	memoryPointsGetInGunnerDir="pos R2 dir";
	class dynamicViewLimits
	{
		CargoTurret_04[]={-95,30};
		CargoTurret_08[]={-50,95};
	};
};