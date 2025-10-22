//O_Heli_Transport_04_black_F
class O_Heli_Transport_04_bench_black_F;
class RC_OM_Heli_InfTransport_Core: O_Heli_Transport_04_bench_black_F
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
class RC_OM_Heli_InfTransport_Base: RC_OM_Heli_InfTransport_Core
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_main.hpp"

	class CargoTurret;

	class Turrets: Turrets
	{
		#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_turrets.hpp"

		class CargoTurret_01: CargoTurret_01 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_02: CargoTurret_02 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_03: CargoTurret_03 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_04: CargoTurret_04 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_05: CargoTurret_05 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_06: CargoTurret_06 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_07: CargoTurret_07 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
		class CargoTurret_08: CargoTurret_08 {gunnerCompartments="Compartment2"; dontCreateAI=1;};
	};
};


class RC_OM_Heli_InfTransport_blk: RC_OM_Heli_InfTransport_Base
{
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_EH.hpp"
	#include "\Remote_Controlled_Artillery\cfgVehicles\includes_vehicle\heli_UV.hpp"

	displayName="RC-OM Helicopter [Inf]";
	scope=2;
	scopeCurator=2;
	forceInGarage=1;

	side=1;
	faction="RemoteControlled_B";
	crew="B_UAV_AI";

	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsB.hpp"
};
class RC_OM_Heli_InfTransport_blk_O: RC_OM_Heli_InfTransport_blk
{
	faction="RemoteControlled_O";
	crew="O_UAV_AI";
	side=0;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsO.hpp"
};
class RC_OM_Heli_InfTransport_blk_I: RC_OM_Heli_InfTransport_blk
{
	faction="RemoteControlled_I";
	crew="I_UAV_AI";
	side=2;
	#include "\Remote_Controlled_Artillery\loadouts\IFVitemsI.hpp"
};



/*
this addEventHandler ["Fired", {
	params ["_unit", "_weapon"];
	[getPos _unit, 180, "O_Crocus_MP_TI", east] call BIS_fnc_spawnVehicle;
}];

this addEventHandler ["Fired", {
	params ["_unit", "_weapon"];
	if (_weapon isNotEqualTo RC_Crocus_Deployer) exitWith {systemchat "nope";};
	[getPos _unit, 180, "O_Crocus_MP_TI", east] call BIS_fnc_spawnVehicle;
}];


this addEventHandler ["Fired", {
	params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
	[getPos _this, 180, "BMP3", east] call BIS_fnc_spawnVehicle;
}];

heli addEventHandler ["ControlsShifted", { 
	params ["_vehicle", "_activeCoPilot", "_oldController"]; 
	systemchat "EH";
	hint format ["active %1 old %2 copilot %3", _activeCoPilot, _oldController, gunner _vehicle]; 
}];

heli addEventHandler ["ControlsShifted", {
	params ["_vic"];

	systemchat str time;
	(gunner _vic) action ["TakeVehicleControl", _vic];
}];
*/
