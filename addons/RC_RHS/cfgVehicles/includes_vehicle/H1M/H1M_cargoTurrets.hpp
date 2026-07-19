class CargoTurret_01: CargoTurret_01
{
	gunnerName="R1";
	gunnerCompartments="Compartment1";
};
class CargoTurret_02: CargoTurret_02
{
	gunnerName="R2";
	gunnerCompartments="Compartment1";
};
class CargoTurret_03: CargoTurret_03
{
	gunnerName="R3";
	gunnerCompartments="Compartment1";
};
class CargoTurret_04: CargoTurret_04
{
	gunnerName="L1";
	gunnerCompartments="Compartment1";
};
class CargoTurret_05: CargoTurret_05
{
	gunnerName="L2";
	gunnerCompartments="Compartment1";
};
class CargoTurret_06: CargoTurret_06
{
	gunnerName="L3";
	gunnerCompartments="Compartment1";
};
class MainTurret: MainTurret
{
	gunnerName="Left Door Gunner";
	gunnerCompartments="Compartment1";
	dontCreateAI=0;
	
	weapons[]={"RC_RHS_338_DoorMinigun_1"};
	magazines[]={"RC_2000Rnd_338_SLAP_T_R"};
	gunnerType="RC_RHS_B_DoorGunner";
	stabilizedInAxes=3;

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};
};
class RightDoorGun: RightDoorGun
{
	gunnerName="Right Door Gunner";
	gunnerCompartments="Compartment1";
	dontCreateAI=0;

	weapons[]={"RC_RHS_338_DoorMinigun_2"};
	magazines[]={"RC_2000Rnd_338_SLAP_T_R"};
	gunnerType="RC_RHS_B_DoorGunner";
	stabilizedInAxes=3;

	class Components: Components
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\H80M\H80M_panels.hpp"
	};
};