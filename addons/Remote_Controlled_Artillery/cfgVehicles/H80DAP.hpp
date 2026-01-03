//OM-H - Optionally Manned Helicopter
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
class RC_OM_Heli_SkyCrane_blk_UV: RC_OM_Heli_SkyCrane_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_small.hpp"

	displayName="OM-H - 'Skycrane'";
};
class RC_OM_Heli_SkyCrane_blk: RC_OM_Heli_SkyCrane_blk_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OM_Heli_SkyCrane_blk_O: RC_OM_Heli_SkyCrane_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OM_Heli_SkyCrane_blk_I: RC_OM_Heli_SkyCrane_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};


class O_Heli_Transport_04_bench_black_F;
class RC_OM_Heli_Bench_Core: O_Heli_Transport_04_bench_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"

	class CargoTurret;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class CargoTurret_04;
	class CargoTurret_05;
	class CargoTurret_06;
	class CargoTurret_07;
	class CargoTurret_08;
};
class RC_OM_Heli_Bench_Base: RC_OM_Heli_Bench_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"

		class CargoTurret_01: CargoTurret_01 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_02: CargoTurret_02 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_03: CargoTurret_03 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_04: CargoTurret_04 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-60;};
		class CargoTurret_05: CargoTurret_05 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_06: CargoTurret_06 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_07: CargoTurret_07 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_08: CargoTurret_08 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-60;};
	};
};
class RC_OM_Heli_Bench_blk_UV: RC_OM_Heli_Bench_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_small.hpp"

	displayName="OM-H - Bench";
};
class RC_OM_Heli_Bench_blk: RC_OM_Heli_Bench_blk_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OM_Heli_Bench_blk_O: RC_OM_Heli_Bench_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OM_Heli_Bench_blk_I: RC_OM_Heli_Bench_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
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
class RC_OM_Heli_Transport_blk_UV: RC_OM_Heli_Transport_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_medium.hpp"

	displayName="OM-H - Transport";
};
class RC_OM_Heli_Transport_blk: RC_OM_Heli_Transport_blk_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OM_Heli_Transport_blk_O: RC_OM_Heli_Transport_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OM_Heli_Transport_blk_I: RC_OM_Heli_Transport_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
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
class RC_OM_Heli_MedEvac_blk_UV: RC_OM_Heli_MedEvac_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_medium.hpp"

	displayName="OM-H - MedEvac";
};
class RC_OM_Heli_MedEvac_blk: RC_OM_Heli_MedEvac_blk_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OM_Heli_MedEvac_blk_O: RC_OM_Heli_MedEvac_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OM_Heli_MedEvac_blk_I: RC_OM_Heli_MedEvac_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};


class O_Heli_Transport_04_ammo_black_F;
class RC_OM_Heli_MultiMission_Core: O_Heli_Transport_04_ammo_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_fetch.hpp"
};
class RC_OM_Heli_MultiMission_Base: RC_OM_Heli_MultiMission_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	//class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"
	};
};
class RC_OM_Heli_MultiMission_blk_UV: RC_OM_Heli_MultiMission_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UA.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_large.hpp"
	
	displayName="OM-H - Re-arm/pair/fuel/supply";
};
class RC_OM_Heli_MultiMission_blk: RC_OM_Heli_MultiMission_blk_UV
{
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OM_Heli_MultiMission_blk_O: RC_OM_Heli_MultiMission_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OM_Heli_MultiMission_blk_I: RC_OM_Heli_MultiMission_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};


//Pods
class Pod_Heli_Transport_04_crewed_base_F;
class RC_OMH_MultiMissionPod_blk_Core: Pod_Heli_Transport_04_crewed_base_F
{
	//object converted to vehicle
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_large.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_MultiMission_pod.hpp"

	author="Ascent";
	displayName="OM-H Re-arm/pair/fuel/supply Pod";
	editorSubcategory="RC_Heli_subcat";
};
class RC_OMH_MultiMissionPod_blk: RC_OMH_MultiMissionPod_blk_Core
{
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OMH_MultiMissionPod_blk_O: RC_OMH_MultiMissionPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OMH_MultiMissionPod_blk_I: RC_OMH_MultiMissionPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};


/*
//ReammoBox_F based instead of LandVehicle based
class Land_Pod_Heli_Transport_04_ammo_black_F;
class RC_OMH_MultiMissionPod_Object_blk: Land_Pod_Heli_Transport_04_ammo_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_large.hpp"

	displayName="OM-H Re-arm/pair/fuel/supply Pod (Object)";
	editorSubcategory="RC_Heli_subcat";
	scope=2;
	scopeCurator=2;
	side=3;
};
*/


class Land_Pod_Heli_Transport_04_bench_black_F;
class RC_OMH_BenchPod_blk_Core: Land_Pod_Heli_Transport_04_bench_black_F
{
	class Turrets;
	class CargoTurret_01;
	class CargoTurret_02;
	class CargoTurret_03;
	class CargoTurret_04;
	class CargoTurret_05;
	class CargoTurret_06;
	class CargoTurret_07;
	class CargoTurret_08;
};
class RC_OMH_BenchPod_blk_Base: RC_OMH_BenchPod_blk_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_small.hpp"

	author="Ascent";
	displayName="OM-H Bench Pod";
	editorSubcategory="RC_Heli_subcat";
	transportSoldier=1;	//1 required to show up in editor vehicle tab

	class Turrets: Turrets
	{
		class CargoTurret_01: CargoTurret_01 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_02: CargoTurret_02 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_03: CargoTurret_03 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_04: CargoTurret_04 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-60;};
		class CargoTurret_05: CargoTurret_05 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_06: CargoTurret_06 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_07: CargoTurret_07 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-52;};
		class CargoTurret_08: CargoTurret_08 {gunnerCompartments="Compartment2"; minElev=-60; maxTurn=60.5; minTurn=-60;};
	};
};
class RC_OMH_BenchPod_blk: RC_OMH_BenchPod_blk_Base
{
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OMH_BenchPod_blk_O: RC_OMH_BenchPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OMH_BenchPod_blk_I: RC_OMH_BenchPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};


class Land_Pod_Heli_Transport_04_covered_black_F;
class RC_OMH_TransportPod_blk_Core: Land_Pod_Heli_Transport_04_covered_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_medium.hpp"

	author="Ascent";
	displayName="OM-H Transport Pod";
	editorSubcategory="RC_Heli_subcat";
};
class RC_OMH_TransportPod_blk: RC_OMH_TransportPod_blk_Core
{
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OMH_TransportPod_blk_O: RC_OMH_TransportPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OMH_TransportPod_blk_I: RC_OMH_TransportPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};


class Land_Pod_Heli_Transport_04_medevac_black_F;
class RC_OMH_MedEvacPod_blk_Core: Land_Pod_Heli_Transport_04_medevac_black_F
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_logi_medium.hpp"

	author="Ascent";
	displayName="OM-H MedEvac Pod";
	editorSubcategory="RC_Heli_subcat";
};
class RC_OMH_MedEvacPod_blk: RC_OMH_MedEvacPod_blk_Core
{
	scope=2;
	scopeCurator=2;

	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideB.hpp"
};
class RC_OMH_MedEvacPod_blk_O: RC_OMH_MedEvacPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideO.hpp"
};
class RC_OMH_MedEvacPod_blk_I: RC_OMH_MedEvacPod_blk
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_sideI.hpp"
};