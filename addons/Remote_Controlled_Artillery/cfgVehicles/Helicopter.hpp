class O_Heli_Transport_04_black_F;
class RC_OM_Heli_SkyCrane_Core: O_Heli_Transport_04_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_SkyCrane_Base: RC_OM_Heli_SkyCrane_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_SkyCrane_blk: RC_OM_Heli_SkyCrane_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - 'Skycrane'";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_SkyCrane_blk_O: RC_OM_Heli_SkyCrane_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_SkyCrane_blk_I: RC_OM_Heli_SkyCrane_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class O_Heli_Transport_04_bench_black_F;
class RC_OM_Heli_Bench_Core: O_Heli_Transport_04_bench_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"

	/*
	class CargoTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class CargoTurret_04;
	class CargoTurret_05;
	class CargoTurret_06;
	class CargoTurret_07;
	class CargoTurret_08;
	*/
};
class RC_OM_Heli_Bench_Base: RC_OM_Heli_Bench_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"

		/*
		class CargoTurret_01: CargoTurret_01 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_02: CargoTurret_02 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_03: CargoTurret_03 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_04: CargoTurret_04 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_05: CargoTurret_05 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_06: CargoTurret_06 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_07: CargoTurret_07 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_08: CargoTurret_08 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		*/
	};
};
class RC_OM_Heli_Bench_blk: RC_OM_Heli_Bench_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - Bench";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_Bench_blk_O: RC_OM_Heli_Bench_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_Bench_blk_I: RC_OM_Heli_Bench_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class O_Heli_Transport_04_covered_black_F;
class RC_OM_Heli_Transport_Core: O_Heli_Transport_04_covered_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_Transport_Base: RC_OM_Heli_Transport_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_Transport_blk: RC_OM_Heli_Transport_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - Transport";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_Transport_blk_O: RC_OM_Heli_Transport_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_Transport_blk_I: RC_OM_Heli_Transport_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class O_Heli_Transport_04_medevac_black_F;
class RC_OM_Heli_MedEvac_Core: O_Heli_Transport_04_medevac_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_MedEvac_Base: RC_OM_Heli_MedEvac_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_MedEvac_blk: RC_OM_Heli_MedEvac_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - MedEvac";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_MedEvac_blk_O: RC_OM_Heli_MedEvac_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_MedEvac_blk_I: RC_OM_Heli_MedEvac_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class O_Heli_Transport_04_box_black_F;
class RC_OM_Heli_Cargo_Core: O_Heli_Transport_04_box_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_Cargo_Base: RC_OM_Heli_Cargo_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_Cargo_blk: RC_OM_Heli_Cargo_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - Cargo";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_Cargo_blk_O: RC_OM_Heli_Cargo_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_Cargo_blk_I: RC_OM_Heli_Cargo_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class O_Heli_Transport_04_ammo_black_F;
class RC_OM_Heli_Ammo_Core: O_Heli_Transport_04_ammo_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_Ammo_Base: RC_OM_Heli_Ammo_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_Ammo_blk: RC_OM_Heli_Ammo_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - Ammo";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_Ammo_blk_O: RC_OM_Heli_Ammo_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_Ammo_blk_I: RC_OM_Heli_Ammo_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class O_Heli_Transport_04_fuel_black_F;
class RC_OM_Heli_Fuel_Core: O_Heli_Transport_04_fuel_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_Fuel_Base: RC_OM_Heli_Fuel_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_Fuel_blk: RC_OM_Heli_Fuel_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - Fuel";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_Fuel_blk_O: RC_OM_Heli_Fuel_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_Fuel_blk_I: RC_OM_Heli_Fuel_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class O_Heli_Transport_04_repair_black_F;
class RC_OM_Heli_Repair_Core: O_Heli_Transport_04_repair_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_Repair_Base: RC_OM_Heli_Repair_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_Repair_blk: RC_OM_Heli_Repair_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="OM-H - Repair";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_Repair_blk_O: RC_OM_Heli_Repair_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_Repair_blk_I: RC_OM_Heli_Repair_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


class RC_OM_Heli_Multi_blk: RC_OM_Heli_Repair_blk
{
	displayName="OM-H - Re-arm/fuel/pair";

	ace_cargo_hasCargo=1;
	ace_cargo_space=5;

	ace_rearm_defaultSupply=1200;

	ace_refuel_hooks[]={{-1.52,1.14,-1.18}};
	ace_refuel_fuelCargo=3000;
	/*
	ace_refuel_canReceive=1;
	ace_refuel_flowRate=8;
	ace_refuel_fuelCapacity=3914;
	*/

	/*
	//supposedly script not cfg
	transportRepair = 0;	//vanilla 1e+12 ace 0
    ace_repair_canRepair = 1;
    ace_repair_engineerRepair = 1;
    ace_repair_repairCargo = 200;
	*/
};
class RC_OM_Heli_Multi_blk_O: RC_OM_Heli_Multi_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_Multi_blk_I: RC_OM_Heli_Multi_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};


//Pods
//vehicle simulation
//Land_Pod_Heli_Transport_04_bench_black_F
class Land_Pod_Heli_Transport_04_bench_black_F;
class RC_OMH_BenchPod_blk: Land_Pod_Heli_Transport_04_bench_black_F
{
	displayName="OM-H Bench Pod";
	transportSoldier=8;
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	side=1;
};
class RC_OMH_BenchPod_blk_O: RC_OMH_BenchPod_blk
{
	faction="RemoteControlled_O";
	side=0;
};
class RC_OMH_BenchPod_blk_I: RC_OMH_BenchPod_blk
{
	faction="RemoteControlled_I";
	side=2;
};

class Land_Pod_Heli_Transport_04_covered_black_F;
class RC_OMH_TransportPod_blk: Land_Pod_Heli_Transport_04_covered_black_F
{
	displayName="OM-H Transport Pod";
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	side=1;
};
class RC_OMH_TransportPod_blk_O: RC_OMH_TransportPod_blk
{
	faction="RemoteControlled_O";
	side=0;
};
class RC_OMH_TransportPod_blk_I: RC_OMH_TransportPod_blk
{
	faction="RemoteControlled_I";
	side=2;
};


class Land_Pod_Heli_Transport_04_medevac_black_F;
class RC_OMH_MedEvacPod_blk: Land_Pod_Heli_Transport_04_medevac_black_F
{
	displayName="OM-H MedEvac Pod";
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;

	faction="RemoteControlled_B";
	side=1;
};
class RC_OMH_MedEvacPod_blk_O: RC_OMH_MedEvacPod_blk
{
	faction="RemoteControlled_O";
	side=0;
};
class RC_OMH_MedEvacPod_blk_I: RC_OMH_MedEvacPod_blk
{
	faction="RemoteControlled_I";
	side=2;
};


//container simulation
class Land_Pod_Heli_Transport_04_ammo_black_F;
class RC_OMH_AmmoPod_blk: Land_Pod_Heli_Transport_04_ammo_black_F
{
	displayName="OM-H Ammo Pod";
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;
	side=3;
};
class RC_OMH_MultiPod_blk: RC_OMH_AmmoPod_blk
{
	displayName="OM-H Re-pair/fuel/arm Pod";
};
class Land_Pod_Heli_Transport_04_box_black_F;
class RC_OMH_CargoPod_blk: Land_Pod_Heli_Transport_04_box_black_F
{
	displayName="OM-H Cargo Pod";
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;
	side=3;
};
class Land_Pod_Heli_Transport_04_fuel_black_F;
class RC_OMH_FuelPod_blk: Land_Pod_Heli_Transport_04_fuel_black_F
{
	displayName="OM-H Fuel Pod";
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;
	side=3;
};
class Land_Pod_Heli_Transport_04_repair_black_F;
class RC_OMH_RepairPod_blk: Land_Pod_Heli_Transport_04_repair_black_F
{
	displayName="OM-H Repair Pod";
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;
	side=3;
};