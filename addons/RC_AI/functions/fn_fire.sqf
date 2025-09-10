params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

if (local _unit && hasInterface) then {_gunner removeMagazine _magazine};